#include "global.h"
#include "battle_setup.h"
#include "battle_pike.h"
#include "battle_pyramid.h"
#include "event_data.h"
#include "fieldmap.h"
#include "fishing.h"
#include "follower_npc.h"
#include "random.h"
#include "field_player_avatar.h"
#include "link.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "ow_synchronize.h"
#include "pokeblock.h"
#include "pokemon.h"
#include "random.h"
#include "roamer.h"
#include "safari_zone.h"
#include "script.h"
#include "tv.h"
#include "wild_encounter.h"
#include "battle_debug.h"
#include "battle_pike.h"
#include "battle_pyramid.h"
#include "constants/abilities.h"
#include "constants/game_stat.h"
#include "constants/item.h"
#include "constants/items.h"
#include "constants/layouts.h"
#include "constants/weather.h"
#include "rtc.h" // needed for DNS encounter tables

extern const u8 EventScript_SprayWoreOff[];

//extern const struct SwarmData gSwarmTable[];
//extern const u16 gSwarmTableLength;

//extern const struct SwarmData gSwarmTable[];
//extern const u16 gSwarmTableLength;

#define MAX_ENCOUNTER_RATE 2880

#define NUM_FEEBAS_SPOTS 6

// Number of accessible fishing spots in each section of Route 119
// Each section is an area of the route between the y coordinates in sRoute119WaterTileData
#define NUM_FISHING_SPOTS_1 131
#define NUM_FISHING_SPOTS_2 167
#define NUM_FISHING_SPOTS_3 149
#define NUM_FISHING_SPOTS (NUM_FISHING_SPOTS_1 + NUM_FISHING_SPOTS_2 + NUM_FISHING_SPOTS_3)

#define WILD_CHECK_REPEL    (1 << 0)
#define WILD_CHECK_KEEN_EYE (1 << 1)

static u16 FeebasRandom(void);
static void FeebasSeedRng(u16 seed);
static bool8 IsWildLevelAllowedByRepel(u8 level);
static void ApplyFluteEncounterRateMod(u32 *encRate);
static void ApplyCleanseTagEncounterRateMod(u32 *encRate);
static u8 GetMaxLevelOfSpeciesInWildTable(const struct WildPokemon *wildMon, u16 species, enum WildPokemonArea area);
#ifdef BUGFIX
static bool8 TryGetAbilityInfluencedWildMonIndex(const struct WildPokemon *wildMon, enum Type type, enum Ability ability, u8 *monIndex, u32 size);
#else
static bool8 TryGetAbilityInfluencedWildMonIndex(const struct WildPokemon *wildMon, enum Type type, enum Ability ability, u8 *monIndex);
#endif
static bool8 IsAbilityAllowingEncounter(u8 level);

EWRAM_DATA static u8 sWildEncountersDisabled = 0;
EWRAM_DATA static u32 sFeebasRngValue = 0;
EWRAM_DATA bool8 gIsFishingEncounter = 0;
EWRAM_DATA bool8 gIsSurfingEncounter = 0;
EWRAM_DATA u8 gChainFishingDexNavStreak = 0;

static bool8 UnlockedUnownOrAreNotInUnown(void);
static u32 GenerateUnownPersonalityByLetter(u8 letter);
u8 GetUnownLetterByPersonalityLoByte(u32 personality);

static bool8 UnlockedUnownOrAreNotInUnown(void);
static u32 GenerateUnownPersonalityByLetter(u8 letter);
u8 GetUnownLetterByPersonalityLoByte(u32 personality);

#include "data/wild_encounters.h"

// unlike FRLG, these slots are chosen with uniform probability
/*static const u8 sUnownLetterSlots[][LAND_WILD_COUNT] = {
  //  A   A   A   A   A   A   A   A   A   A   A   ?
    { 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 27},
  //  C   C   C   D   D   D   H   H   H   U   U   O
    { 2,  2,  2,  3,  3,  3,  7,  7,  7, 20, 20, 14},
  //  N   N   N   N   S   S   S   S   I   I   E   E
    {13, 13, 13, 13, 18, 18, 18, 18,  8,  8,  4,  4},
  //  P   P   L   L   J   J   R   R   R   Q   Q   Q
    {15, 15, 11, 11,  9,  9, 17, 17, 17, 16, 16, 16},
  //  Y   Y   T   T   G   G   G   F   F   F   K   K
    {24, 24, 19, 19,  6,  6,  6,  5,  5,  5, 10, 10},
  //  V   V   V   W   W   W   X   X   M   M   B   B
    {21, 21, 21, 22, 22, 22, 23, 23, 12, 12,  1,  1},
  //  Z   Z   Z   Z   Z   Z   Z   Z   Z   Z   Z   !
    {25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 26},
};*/

static const struct WildPokemon sWildFeebas = {20, 25, SPECIES_FEEBAS};

static const u16 sRoute119WaterTileData[] =
{
//yMin, yMax, numSpots in previous sections
     0,  45,  0,
    46,  91,  NUM_FISHING_SPOTS_1,
    92, 139,  NUM_FISHING_SPOTS_1 + NUM_FISHING_SPOTS_2,
};

void DisableWildEncounters(bool8 disabled)
{
    sWildEncountersDisabled = disabled;
}

const struct SwarmData gSwarmTable[] =
{
	/*{
		.mapName = 0xFF,
		.species = 0xFFFF,
	},*/
	{
        .species = SPECIES_STARLY,
        .mapName = MAPSEC_ROUTE_81,
        //.mapName = MAP_NUM(ROUTE81),
    },
	{
        .species = SPECIES_PATRAT,
        .mapName = MAPSEC_ROUTE_82,
        //.mapName = MAP_NUM(ROUTE82),
    },
    {
        .species = SPECIES_GULPIN,
		.mapName = MAPSEC_ROUTE_83,
        //.mapName = MAP_NUM(ROUTE83),
    },
	{
        .species = SPECIES_EMOLGA,
		.mapName = MAPSEC_RESEDA_WOODS,
        //.mapName = MAP_NUM(ROUTE89),
    },
	{
        .species = SPECIES_BLITZLE,
		.mapName = MAPSEC_ROUTE_84,
        //.mapName = MAP_NUM(ROUTE84),
    },
    {
        .species = SPECIES_MARACTUS,
		.mapName = MAPSEC_ROUTE_86,
        //.mapName = MAP_NUM(ROUTE86),
    },
    {
        .species = SPECIES_SANDILE,
		.mapName = MAPSEC_ROUTE_87,
        //.mapName = MAP_NUM(ROUTE87),
    },
    {
        .species = SPECIES_YAMASK,
		.mapName = MAPSEC_ROUTE_88,
        //.mapName = MAP_NUM(ROUTE88),
    },
    {
		.species = SPECIES_DWEBBLE,
		.mapName = MAPSEC_ROUTE_79,
        //.mapName = MAP_NUM(ROUTE79),
    },
    {
        .species = SPECIES_SHELMET,
		.mapName = MAPSEC_ROUTE_78,
        //.mapName = MAP_NUM(ROUTE78),
    },

	{
        .species = SPECIES_LILLIPUP,
		.mapName = MAPSEC_ROUTE_94,
        //.mapName = MAP_NUM(ROUTE94),
    },
	{
        .species = SPECIES_LITLEO,
		.mapName = MAPSEC_ROUTE_93,
        //.mapName = MAP_NUM(ROUTE93),
    },
	{
        .species = SPECIES_RIOLU,
		.mapName = MAPSEC_MINDARO_GARDENS,
        //.mapName = MAP_NUM(ROUTE95),
    },
	{
        .species = SPECIES_GOTHITA,
		.mapName = MAPSEC_ROUTE_96,
        //.mapName = MAP_NUM(ROUTE96),
    },
	{
        .species = SPECIES_BERGMITE,
		.mapName = MAPSEC_MT_SHIRO,
        //.mapName = MAP_NUM(ROUTE97),
    },
	{
        .species = SPECIES_KARRABLAST,
		.mapName = MAPSEC_ROUTE_92,
        //.mapName = MAP_NUM(ROUTE92),
    },
	{
        .species = SPECIES_MIENFOO,
		.mapName = MAPSEC_ROUTE_91,
        //.mapName = MAP_NUM(ROUTE91),
    },
	{
        .species = SPECIES_SCRAGGY,
		.mapName = MAPSEC_ROUTE_90,
        //.mapName = MAP_NUM(ROUTE90),
    },	
	{
        .species = SPECIES_JOLTIK,
		.mapName = MAPSEC_SCARLET_WOODS,
        //.mapName = MAP_NUM(ROUTE69),
    },
	
    {
        .species = SPECIES_AXEW,
		.mapName = MAPSEC_SANDSHREAF,
        //.mapName = MAP_NUM(SANDSHREAF),
    },
	{
        .species = SPECIES_KLINK,
		.mapName = MAPSEC_STEEL_MILL,
        //.mapName = MAP_NUM(ROUTE89),
    },
	{
        .species = SPECIES_BRUXISH,
		.mapName = MAPSEC_ROUTE_77,
        //.mapName = MAP_NUM(ROUTE77),
    },
	{
        .species = SPECIES_CLAUNCHER,
		.mapName = MAPSEC_ROUTE_75,
        //.mapName = MAP_NUM(ROUTE75),
    },
	{
        .species = SPECIES_FRILLISH,
		.mapName = MAPSEC_ROUTE_74,
        //.mapName = MAP_NUM(ROUTE74),
    },
	{
        .species = SPECIES_ALOMOMOLA,
		.mapName = MAPSEC_ROUTE_73,
        //.mapName = MAP_NUM(ROUTE73),
    },
	{
        .species = SPECIES_DRUDDIGON,
		.mapName = MAPSEC_ROUTE_70,
        //.mapName = MAP_NUM(ROUTE70),
    },
	{
        .species = SPECIES_PAWNIARD,
		.mapName = MAPSEC_ROUTE_67,
        //.mapName = MAP_NUM(ROUTE67),
    },
	{
        .species = SPECIES_ABSOL,
		.mapName = MAPSEC_ROUTE_66,
        //.mapName = MAP_NUM(ROUTE66),
    },
	{
        .species = SPECIES_CARBINK,
		.mapName = MAPSEC_DUSK_MOUNTAIN,
        //.mapName = MAP_NUM(ROUTE65),
    }
};

const u16 gSwarmTableLength = NELEMS(gSwarmTable);

// Each fishing spot on Route 119 is given a number between 1 and NUM_FISHING_SPOTS inclusive.
// The number is determined by counting the valid fishing spots left to right top to bottom.
// The map is divided into three sections, with each section having a pre-counted number of
// fishing spots to start from to avoid counting a large number of spots at the bottom of the map.
// Note that a spot is considered valid if it is surfable and not a waterfall. To exclude all
// of the inaccessible water metatiles (so that they can't be selected as a Feebas spot) they
// use a different metatile that isn't actually surfable because it has MB_NORMAL instead.
// This function is given the coordinates and section of a fishing spot and returns which number it is.
static u16 GetFeebasFishingSpotId(s16 targetX, s16 targetY, u8 section)
{
    u16 x, y;
    u16 yMin = sRoute119WaterTileData[section * 3 + 0];
    u16 yMax = sRoute119WaterTileData[section * 3 + 1];
    u16 spotId = sRoute119WaterTileData[section * 3 + 2];

    for (y = yMin; y <= yMax; y++)
    {
        for (x = 0; x < gMapHeader.mapLayout->width; x++)
        {
            u8 behavior = MapGridGetMetatileBehaviorAt(x + MAP_OFFSET, y + MAP_OFFSET);
            if (MetatileBehavior_IsSurfableAndNotWaterfall(behavior) == TRUE)
            {
                spotId++;
                if (targetX == x && targetY == y)
                    return spotId;
            }
        }
    }
    return spotId + 1;
}

static bool8 CheckFeebas(void)
{
    u8 i;
    u16 feebasSpots[NUM_FEEBAS_SPOTS];
    s16 x, y;
    u8 route119Section = 0;
    u16 spotId;

    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_ROUTE119)
     && gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_ROUTE119))
    {
        GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
        x -= MAP_OFFSET;
        y -= MAP_OFFSET;

        // Get which third of the map the player is in
        if (y >= sRoute119WaterTileData[3 * 0 + 0] && y <= sRoute119WaterTileData[3 * 0 + 1])
            route119Section = 0;
        if (y >= sRoute119WaterTileData[3 * 1 + 0] && y <= sRoute119WaterTileData[3 * 1 + 1])
            route119Section = 1;
        if (y >= sRoute119WaterTileData[3 * 2 + 0] && y <= sRoute119WaterTileData[3 * 2 + 1])
            route119Section = 2;

        // 50% chance of encountering Feebas (assuming this is a Feebas spot)
        if (Random() % 100 > 49)
            return FALSE;

        FeebasSeedRng(gSaveBlock1Ptr->dewfordTrends[0].rand);

        // Assign each Feebas spot to a random fishing spot.
        // Randomness is fixed depending on the seed above.
        for (i = 0; i != NUM_FEEBAS_SPOTS;)
        {
            feebasSpots[i] = FeebasRandom() % NUM_FISHING_SPOTS;
            if (feebasSpots[i] == 0)
                feebasSpots[i] = NUM_FISHING_SPOTS;

            // < 1 below is a pointless check, it will never be TRUE.
            // >= 4 to skip fishing spots 1-3, because these are inaccessible
            // spots at the top of the map, at (9,7), (7,13), and (15,16).
            // The first accessible fishing spot is spot 4 at (18,18).
            if (feebasSpots[i] < 1 || feebasSpots[i] >= 4)
                i++;
        }

        // Check which fishing spot the player is at, and see if
        // it matches any of the Feebas spots.
        spotId = GetFeebasFishingSpotId(x, y, route119Section);
        for (i = 0; i < NUM_FEEBAS_SPOTS; i++)
        {
            if (spotId == feebasSpots[i])
                return TRUE;
        }
    }
    return FALSE;
}

static u16 FeebasRandom(void)
{
    sFeebasRngValue = ISO_RANDOMIZE2(sFeebasRngValue);
    return sFeebasRngValue >> 16;
}

static void FeebasSeedRng(u16 seed)
{
    sFeebasRngValue = seed;
}

// LAND_WILD_COUNT
u32 ChooseWildMonIndex_Land(void)
{
    u8 wildMonIndex = 0;
    bool8 swap = FALSE;
    u8 rand = Random() % ENCOUNTER_CHANCE_LAND_MONS_TOTAL;

    if (rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_0)
        wildMonIndex = 0;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_0 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_1)
        wildMonIndex = 1;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_1 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_2)
        wildMonIndex = 2;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_2 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_3)
        wildMonIndex = 3;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_3 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_4)
        wildMonIndex = 4;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_4 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_5)
        wildMonIndex = 5;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_5 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_6)
        wildMonIndex = 6;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_6 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_7)
        wildMonIndex = 7;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_7 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_8)
        wildMonIndex = 8;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_8 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_9)
        wildMonIndex = 9;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_9 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_10)
        wildMonIndex = 10;
    else
        wildMonIndex = 11;

    if (LURE_STEP_COUNT != 0 && (Random() % 10 < 2))
        swap = TRUE;

    if (swap)
        wildMonIndex = 11 - wildMonIndex;

    return wildMonIndex;
}

// WATER_WILD_COUNT
u32 ChooseWildMonIndex_Water(void)
{
    u32 wildMonIndex = 0;
    bool8 swap = FALSE;
    u8 rand = Random() % ENCOUNTER_CHANCE_WATER_MONS_TOTAL;

    if (rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_0)
        wildMonIndex = 0;
    else if (rand >= ENCOUNTER_CHANCE_WATER_MONS_SLOT_0 && rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_1)
        wildMonIndex = 1;
    else if (rand >= ENCOUNTER_CHANCE_WATER_MONS_SLOT_1 && rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_2)
        wildMonIndex = 2;
    else if (rand >= ENCOUNTER_CHANCE_WATER_MONS_SLOT_2 && rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_3)
        wildMonIndex = 3;
    else
        wildMonIndex = 4;

    if (LURE_STEP_COUNT != 0 && (Random() % 10 < 2))
        swap = TRUE;

    if (swap)
        wildMonIndex = 4 - wildMonIndex;

    return wildMonIndex;
}

// ROCK_WILD_COUNT
u32 ChooseWildMonIndex_Rocks(void)
{
    u32 wildMonIndex = 0;
    bool8 swap = FALSE;
    u8 rand = Random() % ENCOUNTER_CHANCE_ROCK_SMASH_MONS_TOTAL;

    if (rand < ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_0)
        wildMonIndex = 0;
    else if (rand >= ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_0 && rand < ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_1)
        wildMonIndex = 1;
    else if (rand >= ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_1 && rand < ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_2)
        wildMonIndex = 2;
    else if (rand >= ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_2 && rand < ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_3)
        wildMonIndex = 3;
    else
        wildMonIndex = 4;

    if (LURE_STEP_COUNT != 0 && (Random() % 10 < 2))
        swap = TRUE;

    if (swap)
        wildMonIndex = 4 - wildMonIndex;

    return wildMonIndex;
}

// FISH_WILD_COUNT
static u32 ChooseWildMonIndex_Fishing(u8 rod)
{
    u8 wildMonIndex = 0;
    bool8 swap = FALSE;
    u8 rand = Random() % max(max(ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_TOTAL, ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_TOTAL),
                             ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_TOTAL);

    if (LURE_STEP_COUNT != 0 && (Random() % 10 < 2))
        swap = TRUE;

    switch (rod)
    {
    case OLD_ROD:
        if (rand < ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_SLOT_0)
            wildMonIndex = 0;
        else
            wildMonIndex = 1;

        if (swap)
            wildMonIndex = 1 - wildMonIndex;
        break;
    case GOOD_ROD:
        if (rand < ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_2)
            wildMonIndex = 2;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_2 && rand < ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_3)
            wildMonIndex = 3;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_3 && rand < ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_4)
            wildMonIndex = 4;

        if (swap)
            wildMonIndex = 6 - wildMonIndex;
        break;
    case SUPER_ROD:
        if (rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_5)
            wildMonIndex = 5;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_5 && rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_6)
            wildMonIndex = 6;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_6 && rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_7)
            wildMonIndex = 7;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_7 && rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_8)
            wildMonIndex = 8;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_8 && rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_9)
            wildMonIndex = 9;

        if (swap)
            wildMonIndex = 14 - wildMonIndex;
        break;
    }
    return wildMonIndex;
}

static u8 ChooseWildMonLevel(const struct WildPokemon *wildPokemon, u8 wildMonIndex, enum WildPokemonArea area)
{
    u8 min;
    u8 max;
    u8 range;
    u8 rand;

    if (LURE_STEP_COUNT == 0)
    {
        // Make sure minimum level is less than maximum level
        if (wildPokemon[wildMonIndex].maxLevel >= wildPokemon[wildMonIndex].minLevel)
        {
            min = wildPokemon[wildMonIndex].minLevel;
            max = wildPokemon[wildMonIndex].maxLevel;
        }
        else
        {
            min = wildPokemon[wildMonIndex].maxLevel;
            max = wildPokemon[wildMonIndex].minLevel;
        }
        range = max - min + 1;
        rand = Random() % range;

        // check ability for max level mon
        if (!GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG))
        {
            enum Ability ability = GetMonAbility(&gPlayerParty[0]);
            if (ability == ABILITY_HUSTLE || ability == ABILITY_VITAL_SPIRIT || ability == ABILITY_PRESSURE || ability == ABILITY_AMPLIFY)
            {
                if (Random() % 2 == 0)
                    return max;

                if (rand != 0)
                    rand--;
            }
        }
        return min + rand;
    }
    else
    {
        // Looks for the max level of all slots that share the same species as the selected slot.
        max = GetMaxLevelOfSpeciesInWildTable(wildPokemon, wildPokemon[wildMonIndex].species, area);
        if (max > 0)
            return max + 1;
        else // Failsafe
            return wildPokemon[wildMonIndex].maxLevel + 1;
    }
}

u16 GetCurrentMapWildMonHeaderId(void)
{
    u16 i;

	if (!UnlockedUnownOrAreNotInUnown())
        return HEADER_NONE;

    for (i = 0; ; i++)
    {
        const struct WildPokemonHeader *wildHeader = &gWildMonHeaders[i];
        if (wildHeader->mapGroup == MAP_GROUP(MAP_UNDEFINED))
            break;
		
        //if (!UnlockedUnownOrAreNotInUnown())
        //    break;

        if (gWildMonHeaders[i].mapGroup == gSaveBlock1Ptr->location.mapGroup &&
            gWildMonHeaders[i].mapNum == gSaveBlock1Ptr->location.mapNum)
        {
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_ALTERING_CAVE) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_ALTERING_CAVE))
            {
                u16 alteringCaveId = VarGet(VAR_ALTERING_CAVE_WILD_SET);
                if (alteringCaveId >= NUM_ALTERING_CAVE_TABLES)
                    alteringCaveId = 0;

                i += alteringCaveId;
            }
			
			// current locations with DNS tables
			if ((gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE82) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE82))
				|| (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE83) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE83))
				|| (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(RESEDA_WOODS) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(RESEDA_WOODS))
				|| (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE84) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE84))
				|| (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE89) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE89))
				|| (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE86) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE86))
				|| (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE87) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE87))
				|| (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(CINEROUS_TOWER_EXTERIOR) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(CINEROUS_TOWER_EXTERIOR))
				|| (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE79) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE79))
				|| (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE78) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE78))
				|| (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE97) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE97))
				|| (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE95) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE95))
				|| (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE94) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE94))
				|| (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE93) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE93))
				|| (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE92) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE92))
				|| (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE91) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE91))
				|| (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE90) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE90))
				|| (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE69) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE69)))
            {
                u8 hour = gLocalTime.hours;
				if (hour < 4 || hour >= 20) // night
					i += 1;
				if (4 <= hour && hour < 10) // morning
					i += 2;
            }

            return i;
        }
    }

    return HEADER_NONE;
}

enum TimeOfDay GetTimeOfDayForEncounters(u32 headerId, enum WildPokemonArea area)
{
    const struct WildPokemonInfo *wildMonInfo;
    enum TimeOfDay timeOfDay = GetTimeOfDay();

    if (!OW_TIME_OF_DAY_ENCOUNTERS)
        return TIME_OF_DAY_DEFAULT;

    if (InBattlePike() || CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE)
        return OW_TIME_OF_DAY_FALLBACK;

    switch (area)
    {
    default:
    case WILD_AREA_LAND:
        wildMonInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo;
        break;
    case WILD_AREA_WATER:
        wildMonInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].waterMonsInfo;
        break;
    case WILD_AREA_ROCKS:
        wildMonInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].rockSmashMonsInfo;
        break;
    case WILD_AREA_FISHING:
        wildMonInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].fishingMonsInfo;
        break;
    case WILD_AREA_HIDDEN:
        wildMonInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].hiddenMonsInfo;
        break;
    }

    if (wildMonInfo == NULL && !OW_TIME_OF_DAY_DISABLE_FALLBACK)
        return OW_TIME_OF_DAY_FALLBACK;
    else
        return GenConfigTimeOfDay(timeOfDay);
}

static u8 PickWildMonNature(u32 species)
{
    u8 i;
    struct Pokeblock *safariPokeblock;
    u8 natures[NUM_NATURES];

    if (GetSafariZoneFlag() == TRUE && Random() % 100 < 80)
    {
        safariPokeblock = SafariZoneGetActivePokeblock();
        if (safariPokeblock != NULL)
        {
            for (i = 0; i < NUM_NATURES; i++)
                natures[i] = i;
            Shuffle(natures, NUM_NATURES, sizeof(natures[0]));
            for (i = 0; i < NUM_NATURES; i++)
            {
                if (PokeblockGetGain(natures[i], safariPokeblock) > 0)
                    return natures[i];
            }
        }
    }

    return GetSynchronizedNature(WILDMON_ORIGIN, species);
}

void CreateWildMon(u16 species, u8 level)
{
    bool32 checkCuteCharm = TRUE;
	u32 personality;
	u8 letter;

    ZeroEnemyPartyMons();

    switch (gSpeciesInfo[species].genderRatio)
    {
    case MON_MALE:
    case MON_FEMALE:
    case MON_GENDERLESS:
        checkCuteCharm = FALSE;
        break;
    }

    if (checkCuteCharm
        && !GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG)
        && GetMonAbility(&gPlayerParty[0]) == ABILITY_CUTE_CHARM
        && Random() % 3 != 0)
    {
        u16 leadingMonSpecies = GetMonData(&gPlayerParty[0], MON_DATA_SPECIES);
        u32 leadingMonPersonality = GetMonData(&gPlayerParty[0], MON_DATA_PERSONALITY);
        u8 gender = GetGenderFromSpeciesAndPersonality(leadingMonSpecies, leadingMonPersonality);

        // misses mon is genderless check, although no genderless mon can have cute charm as ability
        if (gender == MON_FEMALE)
            gender = MON_MALE;
        else
            gender = MON_FEMALE;

        CreateMonWithGenderNatureLetter(&gEnemyParty[0], species, level, USE_RANDOM_IVS, gender, PickWildMonNature(), 0);
        return;
    }

    //CreateMonWithNature(&gEnemyParty[0], species, level, USE_RANDOM_IVS, PickWildMonNature());
	// DJAX chamber requires special handling, since there is no separate UNOWN_A form
	if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ARTISAN_CAVE_PUZZLE_CHAMBER1)
		&& gSaveBlock1Ptr->location.mapNum == MAP_NUM(ARTISAN_CAVE_PUZZLE_CHAMBER1))
	{
		//do {
		//	letter = Random() % 28;
		//} while (letter != 0 || letter != 3 || letter != 9 || letter != 23);
		letter = 4;
		personality = GenerateUnownPersonalityByLetter(letter);
        CreateMon(&gEnemyParty[0], species, level, USE_RANDOM_IVS, TRUE, personality, FALSE, 0);
		//CreateMonWithGenderNatureLetter(&gEnemyParty[0], SPECIES_UNOWN, level, USE_RANDOM_IVS, MON_GENDERLESS, PickWildMonNature(), letter);
	}
	else
		CreateMonWithNature(&gEnemyParty[0], species, level, USE_RANDOM_IVS, PickWildMonNature());
    /*if (species != SPECIES_UNOWN)
    {
        CreateMonWithNature(&gEnemyParty[0], species, level, USE_RANDOM_IVS, PickWildMonNature());
    }
    else
    {
		slot = Random() % LAND_WILD_COUNT;
        chamber = gSaveBlock1Ptr->location.mapNum - MAP_NUM(ARTISAN_CAVE_PUZZLE_CHAMBER1);
        personality = GenerateUnownPersonalityByLetter(sUnownLetterSlots[chamber][slot]);
        CreateMon(&gEnemyParty[0], species, level, USE_RANDOM_IVS, TRUE, personality, FALSE, 0);
    }*/
}

static bool8 UnlockedUnownOrAreNotInUnown(void)
{
    if (gSaveBlock1Ptr->location.mapGroup != MAP_GROUP(ARTISAN_CAVE_PUZZLE_CHAMBER1))
        return TRUE;
    if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(ARTISAN_CAVE_PUZZLE_CHAMBER1)
		&& FlagGet(FLAG_SOLVED_UNOWN_PUZZLE_1))
		return TRUE;
    if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(ARTISAN_CAVE_PUZZLE_CHAMBER2)
		&& FlagGet(FLAG_SOLVED_UNOWN_PUZZLE_2))
		return TRUE;
    if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(ARTISAN_CAVE_PUZZLE_CHAMBER3)
		&& FlagGet(FLAG_SOLVED_UNOWN_PUZZLE_3))
		return TRUE;
    if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(ARTISAN_CAVE_PUZZLE_CHAMBER4)
		&& FlagGet(FLAG_SOLVED_UNOWN_PUZZLE_4))
		return TRUE;
    if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(ARTISAN_CAVE_PUZZLE_CHAMBER5)
		&& FlagGet(FLAG_SOLVED_UNOWN_PUZZLE_5))
		return TRUE;
    if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(ARTISAN_CAVE_PUZZLE_CHAMBER6)
		&& FlagGet(FLAG_SOLVED_UNOWN_PUZZLE_6))
        return TRUE;
    return FALSE;
}

/*static void GenerateWildMon(u16 species, u8 level, u8 slot)
{
    u32 personality;
    s8 chamber;
    ZeroEnemyPartyMons();
    if (species != SPECIES_UNOWN)
    {
        CreateMonWithNature(&gEnemyParty[0], species, level, USE_RANDOM_IVS, Random() % NUM_NATURES);
    }
    else
    {
        chamber = gSaveBlock1Ptr->location.mapNum - MAP_NUM(MAP_SEVEN_ISLAND_TANOBY_RUINS_MONEAN_CHAMBER);
        personality = GenerateUnownPersonalityByLetter(sUnownLetterSlots[chamber][slot]);
        CreateMon(&gEnemyParty[0], species, level, USE_RANDOM_IVS, TRUE, personality, FALSE, 0);
    }
}*/

static u32 GenerateUnownPersonalityByLetter(u8 letter)
{
    u32 personality;
    do
    {
        personality = (Random() << 16) | Random();
    } while (GetUnownLetterByPersonalityLoByte(personality) != letter);
    return personality;
}

u8 GetUnownLetterByPersonalityLoByte(u32 personality)
{
    return GET_UNOWN_LETTER(personality);
}

void TryUpdateSwarm(void)
{
	//#ifdef TIME_ENABLED //Otherwise causes lags
	//u32 backupVar = VarGet(VAR_SWARM_DAILY_EVENT) | (VarGet(VAR_SWARM_DAILY_EVENT + 1) << 16);

	//if (CheckAndSetDailyEvent(VAR_SWARM_DAILY_EVENT, TRUE))
	//{
		u16 index = Random() % gSwarmTableLength;
		VarSet(VAR_SWARM_INDEX, index);

		//u32 daysSince = GetDaysSinceTimeInValue(backupVar);
		//UpdatePartyPokerusTime(daysSince);
		//ClearDailyEventFlags();
	//}
	//#endif
}

#define SWARM_CHANCE 50 //Change this to the percentage that swarming Pokemon will appear if they can be found on the current route.

static bool8 TryGenerateSwarmMon(u8 level)
{
	//if (gSwarmTableLength == 0)
	//	return FALSE;

	//u16 index = 0;
	u16 index = VarGet(VAR_SWARM_INDEX);
	u8 mapName = gSwarmTable[index].mapName;
	u16 species = gSwarmTable[index].species;

	if (mapName == GetCurrentRegionMapSectionId()
	&&  Random() % 100 < SWARM_CHANCE)
	{
		CreateWildMon(species, level);
		return TRUE;
	}

	return FALSE;
}

static bool8 UnlockedUnownOrAreNotInUnown(void)
{
    if (gSaveBlock1Ptr->location.mapGroup != MAP_GROUP(ARTISAN_CAVE_PUZZLE_CHAMBER1))
        return TRUE;
    if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(ARTISAN_CAVE_PUZZLE_CHAMBER1)
		&& FlagGet(FLAG_SOLVED_UNOWN_PUZZLE_1))
		return TRUE;
    if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(ARTISAN_CAVE_PUZZLE_CHAMBER2)
		&& FlagGet(FLAG_SOLVED_UNOWN_PUZZLE_2))
		return TRUE;
    if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(ARTISAN_CAVE_PUZZLE_CHAMBER3)
		&& FlagGet(FLAG_SOLVED_UNOWN_PUZZLE_3))
		return TRUE;
    if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(ARTISAN_CAVE_PUZZLE_CHAMBER4)
		&& FlagGet(FLAG_SOLVED_UNOWN_PUZZLE_4))
		return TRUE;
    if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(ARTISAN_CAVE_PUZZLE_CHAMBER5)
		&& FlagGet(FLAG_SOLVED_UNOWN_PUZZLE_5))
		return TRUE;
    if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(ARTISAN_CAVE_PUZZLE_CHAMBER6)
		&& FlagGet(FLAG_SOLVED_UNOWN_PUZZLE_6))
        return TRUE;
    return FALSE;
}

/*static void GenerateWildMon(u16 species, u8 level, u8 slot)
{
    u32 personality;
    s8 chamber;
    ZeroEnemyPartyMons();
    if (species != SPECIES_UNOWN)
    {
        CreateMonWithNature(&gEnemyParty[0], species, level, USE_RANDOM_IVS, Random() % NUM_NATURES);
    }
    else
    {
        chamber = gSaveBlock1Ptr->location.mapNum - MAP_NUM(MAP_SEVEN_ISLAND_TANOBY_RUINS_MONEAN_CHAMBER);
        personality = GenerateUnownPersonalityByLetter(sUnownLetterSlots[chamber][slot]);
        CreateMon(&gEnemyParty[0], species, level, USE_RANDOM_IVS, TRUE, personality, FALSE, 0);
    }
}*/

static u32 GenerateUnownPersonalityByLetter(u8 letter)
{
    u32 personality;
    do
    {
        personality = (Random() << 16) | Random();
    } while (GetUnownLetterByPersonalityLoByte(personality) != letter);
    return personality;
}

u8 GetUnownLetterByPersonalityLoByte(u32 personality)
{
    return GET_UNOWN_LETTER(personality);
}

void TryUpdateSwarm(void)
{
	//#ifdef TIME_ENABLED //Otherwise causes lags
	//u32 backupVar = VarGet(VAR_SWARM_DAILY_EVENT) | (VarGet(VAR_SWARM_DAILY_EVENT + 1) << 16);

	//if (CheckAndSetDailyEvent(VAR_SWARM_DAILY_EVENT, TRUE))
	//{
		u16 index = Random() % gSwarmTableLength;
		VarSet(VAR_SWARM_INDEX, index);

		//u32 daysSince = GetDaysSinceTimeInValue(backupVar);
		//UpdatePartyPokerusTime(daysSince);
		//ClearDailyEventFlags();
	//}
	//#endif
}

#define SWARM_CHANCE 50 //Change this to the percentage that swarming Pokemon will appear if they can be found on the current route.

static bool8 TryGenerateSwarmMon(u8 level)
{
	//if (gSwarmTableLength == 0)
	//	return FALSE;

	//u16 index = 0;
	u16 index = VarGet(VAR_SWARM_INDEX);
	u8 mapName = gSwarmTable[index].mapName;
	u16 species = gSwarmTable[index].species;

	if (mapName == GetCurrentRegionMapSectionId()
	&&  Random() % 100 < SWARM_CHANCE)
	{
		CreateWildMon(species, level);
		return TRUE;
	}

	return FALSE;
}

#ifdef BUGFIX
#define TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildPokemon, type, ability, ptr, count) TryGetAbilityInfluencedWildMonIndex(wildPokemon, type, ability, ptr, count)
#else
#define TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildPokemon, type, ability, ptr, count) TryGetAbilityInfluencedWildMonIndex(wildPokemon, type, ability, ptr)
#endif

static bool8 TryGenerateWildMon(const struct WildPokemonInfo *wildMonInfo, enum WildPokemonArea area, u8 flags)
{
    u8 wildMonIndex = 0;
    u8 level;

    switch (area)
    {
    case WILD_AREA_LAND:
        if (TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TYPE_STEEL, ABILITY_MAGNET_PULL, &wildMonIndex, LAND_WILD_COUNT))
            break;
        if (TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TYPE_ELECTRIC, ABILITY_STATIC, &wildMonIndex, LAND_WILD_COUNT))
            break;
        if (OW_LIGHTNING_ROD >= GEN_8 && TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TYPE_ELECTRIC, ABILITY_LIGHTNING_ROD, &wildMonIndex, LAND_WILD_COUNT))
            break;
        if (OW_FLASH_FIRE >= GEN_8 && TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TYPE_FIRE, ABILITY_FLASH_FIRE, &wildMonIndex, LAND_WILD_COUNT))
            break;
        if (OW_HARVEST >= GEN_8 && TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TYPE_GRASS, ABILITY_HARVEST, &wildMonIndex, LAND_WILD_COUNT))
            break;
        if (OW_STORM_DRAIN >= GEN_8 && TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TYPE_WATER, ABILITY_STORM_DRAIN, &wildMonIndex, LAND_WILD_COUNT))
            break;

        wildMonIndex = ChooseWildMonIndex_Land();
        break;
    case WILD_AREA_WATER:
        if (TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TYPE_STEEL, ABILITY_MAGNET_PULL, &wildMonIndex, WATER_WILD_COUNT))
            break;
        if (TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TYPE_ELECTRIC, ABILITY_STATIC, &wildMonIndex, WATER_WILD_COUNT))
            break;
        if (OW_LIGHTNING_ROD >= GEN_8 && TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TYPE_ELECTRIC, ABILITY_LIGHTNING_ROD, &wildMonIndex, WATER_WILD_COUNT))
            break;
        if (OW_FLASH_FIRE >= GEN_8 && TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TYPE_FIRE, ABILITY_FLASH_FIRE, &wildMonIndex, WATER_WILD_COUNT))
            break;
        if (OW_HARVEST >= GEN_8 && TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TYPE_GRASS, ABILITY_HARVEST, &wildMonIndex, WATER_WILD_COUNT))
            break;
        if (OW_STORM_DRAIN >= GEN_8 && TRY_GET_ABILITY_INFLUENCED_WILD_MON_INDEX(wildMonInfo->wildPokemon, TYPE_WATER, ABILITY_STORM_DRAIN, &wildMonIndex, WATER_WILD_COUNT))
            break;

        wildMonIndex = ChooseWildMonIndex_Water();
        break;
    case WILD_AREA_ROCKS:
        wildMonIndex = ChooseWildMonIndex_Rocks();
        break;
    default:
    case WILD_AREA_FISHING:
    case WILD_AREA_HIDDEN:
        break;
    }

    level = ChooseWildMonLevel(wildMonInfo->wildPokemon, wildMonIndex, area);
    if (flags & WILD_CHECK_REPEL && !IsWildLevelAllowedByRepel(level))
        return FALSE;
    if (gMapHeader.mapLayoutId != LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS && flags & WILD_CHECK_KEEN_EYE && !IsAbilityAllowingEncounter(level))
        return FALSE;
	if (!TryGenerateSwarmMon(level))
		CreateWildMon(wildMonInfo->wildPokemon[wildMonIndex].species, level);
    //CreateWildMon(wildMonInfo->wildPokemon[wildMonIndex].species, level);
    return TRUE;
}

static u16 GenerateFishingWildMon(const struct WildPokemonInfo *wildMonInfo, u8 rod)
{
    u8 wildMonIndex = ChooseWildMonIndex_Fishing(rod);
    u16 wildMonSpecies = wildMonInfo->wildPokemon[wildMonIndex].species;
    u8 level = ChooseWildMonLevel(wildMonInfo->wildPokemon, wildMonIndex, WILD_AREA_FISHING);

    UpdateChainFishingStreak();
    CreateWildMon(wildMonSpecies, level);
    return wildMonSpecies;
}

static bool8 SetUpMassOutbreakEncounter(u8 flags)
{
    u16 i;

    if (flags & WILD_CHECK_REPEL && !IsWildLevelAllowedByRepel(gSaveBlock1Ptr->outbreakPokemonLevel))
        return FALSE;

    CreateWildMon(gSaveBlock1Ptr->outbreakPokemonSpecies, gSaveBlock1Ptr->outbreakPokemonLevel);
    for (i = 0; i < MAX_MON_MOVES; i++)
        SetMonMoveSlot(&gEnemyParty[0], gSaveBlock1Ptr->outbreakPokemonMoves[i], i);

    return TRUE;
}

static bool8 DoMassOutbreakEncounterTest(void)
{
    if (gSaveBlock1Ptr->outbreakPokemonSpecies != SPECIES_NONE
     && gSaveBlock1Ptr->location.mapNum == gSaveBlock1Ptr->outbreakLocationMapNum
     && gSaveBlock1Ptr->location.mapGroup == gSaveBlock1Ptr->outbreakLocationMapGroup)
    {
        if (Random() % 100 < gSaveBlock1Ptr->outbreakPokemonProbability)
            return TRUE;
    }
    return FALSE;
}

static bool8 EncounterOddsCheck(u16 encounterRate)
{
    if (Random() % MAX_ENCOUNTER_RATE < encounterRate)
        return TRUE;
    else
        return FALSE;
}

// Returns true if it will try to create a wild encounter.
static bool8 WildEncounterCheck(u32 encounterRate, bool8 ignoreAbility)
{
    encounterRate *= 16;
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE))
        encounterRate = encounterRate * 80 / 100;
    ApplyFluteEncounterRateMod(&encounterRate);
    ApplyCleanseTagEncounterRateMod(&encounterRate);
    if (LURE_STEP_COUNT != 0)
        encounterRate *= 2;
    if (!ignoreAbility && !GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG))
    {
        enum Ability ability = GetMonAbility(&gPlayerParty[0]);

        if (ability == ABILITY_STENCH && gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
            encounterRate = encounterRate * 3 / 4;
        else if (ability == ABILITY_STENCH)
            encounterRate /= 2;
        else if (ability == ABILITY_ILLUMINATE)
            encounterRate *= 2;
        else if (ability == ABILITY_WHITE_SMOKE)
            encounterRate /= 2;
        else if (ability == ABILITY_ARENA_TRAP)
            encounterRate *= 2;
        else if (ability == ABILITY_SAND_VEIL && gSaveBlock1Ptr->weather == WEATHER_SANDSTORM)
            encounterRate /= 2;
        else if (ability == ABILITY_SNOW_CLOAK && gSaveBlock1Ptr->weather == WEATHER_SNOW)
            encounterRate /= 2;
        else if (ability == ABILITY_QUICK_FEET)
            encounterRate /= 2;
        else if (ability == ABILITY_INFILTRATOR && OW_INFILTRATOR >= GEN_8)
            encounterRate /= 2;
        else if (ability == ABILITY_NO_GUARD)
            encounterRate *= 2;
    }
    if (encounterRate > MAX_ENCOUNTER_RATE)
        encounterRate = MAX_ENCOUNTER_RATE;
    return EncounterOddsCheck(encounterRate);
}

// When you first step on a different type of metatile, there's a 40% chance it
// skips the wild encounter check entirely.
static bool8 AllowWildCheckOnNewMetatile(void)
{
    if (Random() % 100 >= 60)
        return FALSE;
    else
        return TRUE;
}

static bool8 AreLegendariesInSootopolisPreventingEncounters(void)
{
    if (gSaveBlock1Ptr->location.mapGroup != MAP_GROUP(MAP_SOOTOPOLIS_CITY)
     || gSaveBlock1Ptr->location.mapNum != MAP_NUM(MAP_SOOTOPOLIS_CITY))
    {
        return FALSE;
    }

    return FlagGet(FLAG_LEGENDARIES_IN_SOOTOPOLIS);
}

bool8 StandardWildEncounter(u16 curMetatileBehavior, u16 prevMetatileBehavior)
{
    u32 headerId;
    enum TimeOfDay timeOfDay;
    struct Roamer *roamer;

    if (sWildEncountersDisabled == TRUE)
        return FALSE;

    headerId = GetCurrentMapWildMonHeaderId();
    if (headerId == HEADER_NONE)
    {
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS)
        {
            headerId = GetBattlePikeWildMonHeaderId();
            timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND);

            if (prevMetatileBehavior != curMetatileBehavior && !AllowWildCheckOnNewMetatile())
                return FALSE;
            else if (WildEncounterCheck(gBattlePikeWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo->encounterRate, FALSE) != TRUE)
                return FALSE;
            else if (TryGenerateWildMon(gBattlePikeWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo, WILD_AREA_LAND, WILD_CHECK_KEEN_EYE) != TRUE)
                return FALSE;
            else if (!TryGenerateBattlePikeWildMon(TRUE))
                return FALSE;

            BattleSetup_StartBattlePikeWildBattle();
            return TRUE;
        }
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
        {
            headerId = gSaveBlock2Ptr->frontier.curChallengeBattleNum;
            timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND);

            if (prevMetatileBehavior != curMetatileBehavior && !AllowWildCheckOnNewMetatile())
                return FALSE;
            else if (WildEncounterCheck(gBattlePyramidWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo->encounterRate, FALSE) != TRUE)
                return FALSE;
            else if (TryGenerateWildMon(gBattlePyramidWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo, WILD_AREA_LAND, WILD_CHECK_KEEN_EYE) != TRUE)
                return FALSE;

            GenerateBattlePyramidWildMon();
            BattleSetup_StartWildBattle();
            return TRUE;
        }
    }
    else
    {
        if (MetatileBehavior_IsLandWildEncounter(curMetatileBehavior) == TRUE)
        {
            timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND);

            if (gWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo == NULL)
                return FALSE;
            else if (prevMetatileBehavior != curMetatileBehavior && !AllowWildCheckOnNewMetatile())
                return FALSE;
            else if (WildEncounterCheck(gWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo->encounterRate, FALSE) != TRUE)
                return FALSE;

            if (TryStartRoamerEncounter())
            {
                roamer = &gSaveBlock1Ptr->roamer[gEncounteredRoamerIndex];
                if (!IsWildLevelAllowedByRepel(roamer->level))
                    return FALSE;

                BattleSetup_StartRoamerBattle();
                return TRUE;
            }
            else
            {
                if (DoMassOutbreakEncounterTest() == TRUE && SetUpMassOutbreakEncounter(WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE) == TRUE)
                {
                    BattleSetup_StartWildBattle();
                    return TRUE;
                }

                // try a regular wild land encounter
                if (TryGenerateWildMon(gWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo, WILD_AREA_LAND, WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE) == TRUE)
                {
                    if (TryDoDoubleWildBattle())
                    {
                        struct Pokemon mon1 = gEnemyParty[0];
                        TryGenerateWildMon(gWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo, WILD_AREA_LAND, WILD_CHECK_KEEN_EYE);
                        gEnemyParty[1] = mon1;
                        BattleSetup_StartDoubleWildBattle();
                    }
                    else
                    {
                        BattleSetup_StartWildBattle();
                    }
                    return TRUE;
                }

                return FALSE;
            }
        }
        else if (MetatileBehavior_IsWaterWildEncounter(curMetatileBehavior) == TRUE
                 || (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING) && MetatileBehavior_IsBridgeOverWater(curMetatileBehavior) == TRUE))
        {
            timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_WATER);

            if (AreLegendariesInSootopolisPreventingEncounters() == TRUE)
                return FALSE;
            else if (gWildMonHeaders[headerId].encounterTypes[timeOfDay].waterMonsInfo == NULL)
                return FALSE;
            else if (prevMetatileBehavior != curMetatileBehavior && !AllowWildCheckOnNewMetatile())
                return FALSE;
            else if (WildEncounterCheck(gWildMonHeaders[headerId].encounterTypes[timeOfDay].waterMonsInfo->encounterRate, FALSE) != TRUE)
                return FALSE;

            if (TryStartRoamerEncounter())
            {
                roamer = &gSaveBlock1Ptr->roamer[gEncounteredRoamerIndex];
                if (!IsWildLevelAllowedByRepel(roamer->level))
                    return FALSE;

                BattleSetup_StartRoamerBattle();
                return TRUE;
            }
            else // try a regular surfing encounter
            {
                if (TryGenerateWildMon(gWildMonHeaders[headerId].encounterTypes[timeOfDay].waterMonsInfo, WILD_AREA_WATER, WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE) == TRUE)
                {
                    gIsSurfingEncounter = TRUE;
                    if (TryDoDoubleWildBattle())
                    {
                        struct Pokemon mon1 = gEnemyParty[0];
                        TryGenerateWildMon(gWildMonHeaders[headerId].encounterTypes[timeOfDay].waterMonsInfo, WILD_AREA_WATER, WILD_CHECK_KEEN_EYE);
                        gEnemyParty[1] = mon1;
                        BattleSetup_StartDoubleWildBattle();
                    }
                    else
                    {
                        BattleSetup_StartWildBattle();
                    }
                    return TRUE;
                }

                return FALSE;
            }
        }
    }

    return FALSE;
}

void HiddenGrottoWildEncounter(void)
{
    u16 headerId = GetCurrentMapWildMonHeaderId();

    if (headerId != HEADER_NONE)
    {
        const struct WildPokemonInfo *wildPokemonInfo = gWildMonHeaders[headerId].landMonsInfo;

        if (wildPokemonInfo == NULL)
        {
            gSpecialVar_Result = FALSE;
        }
        else if (WildEncounterCheck(wildPokemonInfo->encounterRate, TRUE) == TRUE
         && TryGenerateWildMon(wildPokemonInfo, WILD_AREA_LAND, 0) == TRUE)
        {
			//gEnemyParty[0].hiddenAbility = TRUE;
			u8 value;
			value = 2;
			SetMonData(&gEnemyParty[0], MON_DATA_ABILITY_NUM, &value);
            BattleSetup_StartWildBattle();
            gSpecialVar_Result = TRUE;
        }
        else
        {
            gSpecialVar_Result = FALSE;
        }
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

void GetGrottoItem(void)
{
	u16 GrottoItems[] = 
	{
		ITEM_POKE_BALL,
		ITEM_REPEL,
		ITEM_POTION,
		ITEM_ENERGY_ROOT,
		ITEM_ETHER
		//ITEM_NONE
	};
	u16 GrottoUncommonItems[] = 
	{
		ITEM_GREAT_BALL,
		ITEM_SUPER_REPEL,
		ITEM_SUPER_POTION,
		ITEM_HP_UP,
		ITEM_PP_UP
		//ITEM_NONE
	};
	
	u16 GrottoRareItems[] = 
	{
		ITEM_ULTRA_BALL,
		ITEM_MAX_REPEL,
		ITEM_HYPER_POTION,
		ITEM_RARE_CANDY,
		ITEM_PP_MAX
		//ITEM_NONE
	};
	
	u16 GrottoGreenTreeItems[] = 
	{
		ITEM_LEAF_STONE,
		ITEM_ONI_MASK,
		
		ITEM_SUN_STONE,
		
		ITEM_SHINY_STONE,
		ITEM_DAWN_STONE
		//ITEM_NONE
	};
	
	u16 GrottoRedTreeItems[] = 
	{
		ITEM_LEAF_STONE,
		ITEM_ONI_MASK,
		
		ITEM_MOON_STONE,

		ITEM_DUSK_STONE,
		ITEM_DAWN_STONE
		//ITEM_NONE
	};
	
	u16 GrottoYellowCaveItems[] = 
	{
		ITEM_ZEPHYR_STONE,
		ITEM_FIRE_STONE,
		
		ITEM_SUN_STONE,
		
		ITEM_SHINY_STONE,
		ITEM_DAWN_STONE
		//ITEM_NONE
	};
	
	u16 GrottoBlueCaveItems[] = 
	{
		ITEM_ICE_STONE,
		ITEM_WATER_STONE,
		
		ITEM_MOON_STONE,
		
		ITEM_DUSK_STONE,
		ITEM_DAWN_STONE
		//ITEM_NONE
	};
	
	u8 itemId = Random() % (sizeof(GrottoItems)/sizeof(GrottoItems[0]));
	u8 uncommonitemId = Random() % (sizeof(GrottoUncommonItems)/sizeof(GrottoUncommonItems[0]));
	u8 rareitemId = Random() % (sizeof(GrottoRareItems)/sizeof(GrottoRareItems[0]));

	u8 greentreeitemId = Random() % (sizeof(GrottoGreenTreeItems)/sizeof(GrottoGreenTreeItems[0]));
	u8 redtreeitemId = Random() % (sizeof(GrottoRedTreeItems)/sizeof(GrottoRedTreeItems[0]));
	u8 yellowcaveitemId = Random() % (sizeof(GrottoYellowCaveItems)/sizeof(GrottoYellowCaveItems[0]));
	u8 bluecaveitemId = Random() % (sizeof(GrottoBlueCaveItems)/sizeof(GrottoBlueCaveItems[0]));
	
    if (GrottoItems[itemId] != ITEM_NONE && (Random() % 100) < 50) // 40% chance to get common item
    {
		gSpecialVar_Result = GrottoItems[itemId];
    }
	else if(GrottoItems[itemId] == ITEM_NONE && 
			GrottoUncommonItems[uncommonitemId] != ITEM_NONE &&
			(Random() % 100) < 50) // 20% chance to get uncommon item
	{
		gSpecialVar_Result = GrottoRareItems[uncommonitemId];
    }
	else if(GrottoItems[itemId] == ITEM_NONE && 
			GrottoRareItems[rareitemId] != ITEM_NONE &&
			(Random() % 100) < 50) // 10% chance to get rare item
	{
		gSpecialVar_Result = GrottoRareItems[rareitemId];
    }
	else // 10% chance to get a map specific rare item
	{
		if (GetCurrentRegionMapSectionId() == MAPSEC_ROUTE_85 || GetCurrentRegionMapSectionId() == MAPSEC_ROUTE_70 || GetCurrentRegionMapSectionId() == MAPSEC_ROUTE_87) // yellow cave grottos
			gSpecialVar_Result = GrottoYellowCaveItems[yellowcaveitemId];
		if (GetCurrentRegionMapSectionId() == MAPSEC_QUARTZ_CAVE || GetCurrentRegionMapSectionId() == MAPSEC_MT_SHIRO || GetCurrentRegionMapSectionId() == MAPSEC_ROUTE_66 || GetCurrentRegionMapSectionId() == MAPSEC_ROUTE_97) // blue cave grottos
			gSpecialVar_Result = GrottoBlueCaveItems[bluecaveitemId];
		if (GetCurrentRegionMapSectionId() == MAPSEC_ROUTE_92 || GetCurrentRegionMapSectionId() == MAPSEC_SCARLET_WOODS || GetCurrentRegionMapSectionId() == MAPSEC_ROUTE_91) // red tree grottos
			gSpecialVar_Result = GrottoRedTreeItems[redtreeitemId];
		else // green tree grottos
			gSpecialVar_Result = GrottoGreenTreeItems[greentreeitemId];
    }
}




void RockSmashWildEncounter(void)
{
    u16 headerId = GetCurrentMapWildMonHeaderId();

    if (headerId != HEADER_NONE)
    {
        const struct WildPokemonInfo *wildPokemonInfo = gWildMonHeaders[headerId].landMonsInfo;

        if (wildPokemonInfo == NULL)
        {
            gSpecialVar_Result = FALSE;
        }
        else if (WildEncounterCheck(wildPokemonInfo->encounterRate, TRUE) == TRUE
         && TryGenerateWildMon(wildPokemonInfo, WILD_AREA_LAND, 0) == TRUE)
        {
			//gEnemyParty[0].hiddenAbility = TRUE;
			u8 value;
			value = 2;
			SetMonData(&gEnemyParty[0], MON_DATA_ABILITY_NUM, &value);
            BattleSetup_StartWildBattle();
            gSpecialVar_Result = TRUE;
        }
        else
        {
            gSpecialVar_Result = FALSE;
        }
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

void GetGrottoItem(void)
{
	u16 GrottoItems[] = 
	{
		ITEM_POKE_BALL,
		ITEM_REPEL,
		ITEM_POTION,
		ITEM_ENERGY_ROOT,
		ITEM_ETHER
		//ITEM_NONE
	};
	u16 GrottoUncommonItems[] = 
	{
		ITEM_GREAT_BALL,
		ITEM_SUPER_REPEL,
		ITEM_SUPER_POTION,
		ITEM_HP_UP,
		ITEM_PP_UP
		//ITEM_NONE
	};
	
	u16 GrottoRareItems[] = 
	{
		ITEM_ULTRA_BALL,
		ITEM_MAX_REPEL,
		ITEM_HYPER_POTION,
		ITEM_RARE_CANDY,
		ITEM_PP_MAX
		//ITEM_NONE
	};
	
	u16 GrottoGreenTreeItems[] = 
	{
		ITEM_LEAF_STONE,
		ITEM_ONI_MASK,
		
		ITEM_SUN_STONE,
		
		ITEM_SHINY_STONE,
		ITEM_DAWN_STONE
		//ITEM_NONE
	};
	
	u16 GrottoRedTreeItems[] = 
	{
		ITEM_LEAF_STONE,
		ITEM_ONI_MASK,
		
		ITEM_MOON_STONE,

		ITEM_DUSK_STONE,
		ITEM_DAWN_STONE
		//ITEM_NONE
	};
	
	u16 GrottoYellowCaveItems[] = 
	{
		ITEM_ZEPHYR_STONE,
		ITEM_FIRE_STONE,
		
		ITEM_SUN_STONE,
		
		ITEM_SHINY_STONE,
		ITEM_DAWN_STONE
		//ITEM_NONE
	};
	
	u16 GrottoBlueCaveItems[] = 
	{
		ITEM_ICE_STONE,
		ITEM_WATER_STONE,
		
		ITEM_MOON_STONE,
		
		ITEM_DUSK_STONE,
		ITEM_DAWN_STONE
		//ITEM_NONE
	};
	
	u8 itemId = Random() % (sizeof(GrottoItems)/sizeof(GrottoItems[0]));
	u8 uncommonitemId = Random() % (sizeof(GrottoUncommonItems)/sizeof(GrottoUncommonItems[0]));
	u8 rareitemId = Random() % (sizeof(GrottoRareItems)/sizeof(GrottoRareItems[0]));

	u8 greentreeitemId = Random() % (sizeof(GrottoGreenTreeItems)/sizeof(GrottoGreenTreeItems[0]));
	u8 redtreeitemId = Random() % (sizeof(GrottoRedTreeItems)/sizeof(GrottoRedTreeItems[0]));
	u8 yellowcaveitemId = Random() % (sizeof(GrottoYellowCaveItems)/sizeof(GrottoYellowCaveItems[0]));
	u8 bluecaveitemId = Random() % (sizeof(GrottoBlueCaveItems)/sizeof(GrottoBlueCaveItems[0]));
	
    if (GrottoItems[itemId] != ITEM_NONE && (Random() % 100) < 50) // 40% chance to get common item
    {
		gSpecialVar_Result = GrottoItems[itemId];
    }
	else if(GrottoItems[itemId] == ITEM_NONE && 
			GrottoUncommonItems[uncommonitemId] != ITEM_NONE &&
			(Random() % 100) < 50) // 20% chance to get uncommon item
	{
		gSpecialVar_Result = GrottoRareItems[uncommonitemId];
    }
	else if(GrottoItems[itemId] == ITEM_NONE && 
			GrottoRareItems[rareitemId] != ITEM_NONE &&
			(Random() % 100) < 50) // 10% chance to get rare item
	{
		gSpecialVar_Result = GrottoRareItems[rareitemId];
    }
	else // 10% chance to get a map specific rare item
	{
		if (GetCurrentRegionMapSectionId() == MAPSEC_ROUTE_85 || GetCurrentRegionMapSectionId() == MAPSEC_ROUTE_70 || GetCurrentRegionMapSectionId() == MAPSEC_ROUTE_87) // yellow cave grottos
			gSpecialVar_Result = GrottoYellowCaveItems[yellowcaveitemId];
		if (GetCurrentRegionMapSectionId() == MAPSEC_QUARTZ_CAVE || GetCurrentRegionMapSectionId() == MAPSEC_MT_SHIRO || GetCurrentRegionMapSectionId() == MAPSEC_ROUTE_66 || GetCurrentRegionMapSectionId() == MAPSEC_ROUTE_97) // blue cave grottos
			gSpecialVar_Result = GrottoBlueCaveItems[bluecaveitemId];
		if (GetCurrentRegionMapSectionId() == MAPSEC_ROUTE_92 || GetCurrentRegionMapSectionId() == MAPSEC_SCARLET_WOODS || GetCurrentRegionMapSectionId() == MAPSEC_ROUTE_91) // red tree grottos
			gSpecialVar_Result = GrottoRedTreeItems[redtreeitemId];
		else // green tree grottos
			gSpecialVar_Result = GrottoGreenTreeItems[greentreeitemId];
    }
}




void RockSmashWildEncounter(void)
{
    u32 headerId = GetCurrentMapWildMonHeaderId();
    enum TimeOfDay timeOfDay;

    if (headerId != HEADER_NONE)
    {
        timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_ROCKS);

        const struct WildPokemonInfo *wildPokemonInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].rockSmashMonsInfo;

        if (wildPokemonInfo == NULL)
        {
            gSpecialVar_Result = FALSE;
        }
        else if (WildEncounterCheck(wildPokemonInfo->encounterRate, TRUE) == TRUE
         && TryGenerateWildMon(wildPokemonInfo, WILD_AREA_ROCKS, WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE) == TRUE)
        {
            if (TryDoDoubleWildBattle())
            {
                struct Pokemon mon1 = gEnemyParty[0];
                TryGenerateWildMon(wildPokemonInfo, WILD_AREA_ROCKS, WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE);
                gEnemyParty[1] = mon1;
                BattleSetup_StartDoubleWildBattle();
                gSpecialVar_Result = TRUE;
            }
            else {
                BattleSetup_StartWildBattle();
                gSpecialVar_Result = TRUE;
            }
        }
        else
        {
            gSpecialVar_Result = FALSE;
        }
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

void TryGetRockSmashItem(void)
{
	u16 RockSmashItems[] = 
	{
		/*ITEM_RED_SHARD,
		ITEM_BLUE_SHARD,
		ITEM_GREEN_SHARD,
		ITEM_HARD_STONE,
		ITEM_ICY_ROCK,
		ITEM_SMOOTH_ROCK,
		ITEM_HEAT_ROCK,
		ITEM_DAMP_ROCK,
		ITEM_LIGHT_CLAY,*/
		ITEM_RED_SHARD,
		ITEM_YELLOW_SHARD,
		ITEM_FLOAT_STONE,
		ITEM_NONE
	};

	u16 RockSmashRareItems[] = 
	{
		/*ITEM_ODD_KEYSTONE,
		ITEM_ARMOR_FOSSIL,
		ITEM_SKULL_FOSSIL,
		ITEM_HELIX_FOSSIL,
		ITEM_DOME_FOSSIL,
		ITEM_COVER_FOSSIL,
		ITEM_PLUME_FOSSIL,
		ITEM_JAW_FOSSIL,
		ITEM_SAIL_FOSSIL,
		ITEM_ROOT_FOSSIL,
		ITEM_CLAW_FOSSIL,
		ITEM_INSECT_PLATE,
		ITEM_DREAD_PLATE,
		ITEM_DRACO_PLATE,
		ITEM_ZAP_PLATE,
		ITEM_PIXIE_PLATE,
		ITEM_FIST_PLATE,
		ITEM_FLAME_PLATE,
		ITEM_SKY_PLATE,
		ITEM_SPOOKY_PLATE,
		ITEM_MEADOW_PLATE,
		ITEM_EARTH_PLATE,
		ITEM_ICICLE_PLATE,
		ITEM_TOXIC_PLATE,
		ITEM_MIND_PLATE,
		ITEM_STONE_PLATE,
		ITEM_IRON_PLATE,
		ITEM_SPLASH_PLATE,*/
		ITEM_STAR_PIECE,
		ITEM_ROCK_GEM,
		ITEM_HARD_STONE,
		ITEM_HELIX_FOSSIL,
		ITEM_ROOT_FOSSIL,
		ITEM_NONE
	};
	
	u8 itemId = Random() % (sizeof(RockSmashItems)/sizeof(RockSmashItems[0]));
	u8 rareitemId = Random() % (sizeof(RockSmashRareItems)/sizeof(RockSmashRareItems[0]));
	
    if (RockSmashItems[itemId] != ITEM_NONE && (Random() % 100) < 50)
    {
		gSpecialVar_Result = RockSmashItems[itemId];
    }
	else if(RockSmashItems[itemId] == ITEM_NONE && 
			RockSmashRareItems[rareitemId] != ITEM_NONE &&
			(Random() % 100) < 20)
	{
		gSpecialVar_Result = RockSmashRareItems[rareitemId];
    }
	else
	gSpecialVar_Result = FALSE;
}

void TryGetCutItem(void)
{
	u16 CutItems[] = 
	{
		ITEM_GREEN_SHARD,
		ITEM_TINY_MUSHROOM,
		ITEM_NONE
	};

	u16 CutRareItems[] = 
	{
		ITEM_BIG_MUSHROOM,
		ITEM_GRASS_GEM,
		ITEM_MIRACLE_SEED,
		ITEM_LEEK,
		ITEM_BIG_ROOT,
		ITEM_NONE
	};
	
	u8 itemId = Random() % (sizeof(CutItems)/sizeof(CutItems[0]));
	u8 rareitemId = Random() % (sizeof(CutRareItems)/sizeof(CutRareItems[0]));
	
    if (CutItems[itemId] != ITEM_NONE && (Random() % 100) < 50)
    {
		gSpecialVar_Result = CutItems[itemId];
    }
	else if(CutItems[itemId] == ITEM_NONE && 
			CutRareItems[rareitemId] != ITEM_NONE &&
			(Random() % 100) < 20)
	{
		gSpecialVar_Result = CutRareItems[rareitemId];
    }
	else
	gSpecialVar_Result = FALSE;
}


void TryGetThawItem(void)
{
	u16 ThawItems[] = 
	{
		ITEM_BLUE_SHARD,
		ITEM_PEARL,
		ITEM_NONE
	};

	u16 ThawRareItems[] = 
	{
		ITEM_BIG_PEARL,
		ITEM_ICE_GEM,
		ITEM_NEVER_MELT_ICE,
		ITEM_ARMOR_FOSSIL,
		ITEM_JAW_FOSSIL,
		ITEM_NONE
	};
	
	u8 itemId = Random() % (sizeof(ThawItems)/sizeof(ThawItems[0]));
	u8 rareitemId = Random() % (sizeof(ThawRareItems)/sizeof(ThawRareItems[0]));
	
    if (ThawItems[itemId] != ITEM_NONE && (Random() % 100) < 50)
    {
		gSpecialVar_Result = ThawItems[itemId];
    }
	else if(ThawItems[itemId] == ITEM_NONE && 
			ThawRareItems[rareitemId] != ITEM_NONE &&
			(Random() % 100) < 20)
	{
		gSpecialVar_Result = ThawRareItems[rareitemId];
    }
	else
	gSpecialVar_Result = FALSE;
}

bool8 SweetScentWildEncounter(void)
{
    s16 x, y;
    u32 headerId;
    enum TimeOfDay timeOfDay;

    PlayerGetDestCoords(&x, &y);
    headerId = GetCurrentMapWildMonHeaderId();
    if (headerId == HEADER_NONE)
    {
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS)
        {
            headerId = GetBattlePikeWildMonHeaderId();
            timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND);

            if (TryGenerateWildMon(gBattlePikeWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo, WILD_AREA_LAND, 0) != TRUE)
                return FALSE;

            TryGenerateBattlePikeWildMon(FALSE);
            BattleSetup_StartBattlePikeWildBattle();
            return TRUE;
        }
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
        {
            headerId = gSaveBlock2Ptr->frontier.curChallengeBattleNum;
            timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND);

            if (TryGenerateWildMon(gBattlePyramidWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo, WILD_AREA_LAND, 0) != TRUE)
                return FALSE;

            GenerateBattlePyramidWildMon();
            BattleSetup_StartWildBattle();
            return TRUE;
        }
    }
    else
    {
        if (MetatileBehavior_IsLandWildEncounter(MapGridGetMetatileBehaviorAt(x, y)) == TRUE)
        {
            timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND);

            if (gWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo == NULL)
                return FALSE;

            if (TryStartRoamerEncounter())
            {
                BattleSetup_StartRoamerBattle();
                return TRUE;
            }

            if (DoMassOutbreakEncounterTest() == TRUE)
                SetUpMassOutbreakEncounter(0);
            else
                TryGenerateWildMon(gWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo, WILD_AREA_LAND, 0);

            BattleSetup_StartWildBattle();
            return TRUE;
        }
        else if (MetatileBehavior_IsWaterWildEncounter(MapGridGetMetatileBehaviorAt(x, y)) == TRUE)
        {
            timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_WATER);

            if (AreLegendariesInSootopolisPreventingEncounters() == TRUE)
                return FALSE;
            if (gWildMonHeaders[headerId].encounterTypes[timeOfDay].waterMonsInfo == NULL)
                return FALSE;

            if (TryStartRoamerEncounter())
            {
                BattleSetup_StartRoamerBattle();
                return TRUE;
            }

            TryGenerateWildMon(gWildMonHeaders[headerId].encounterTypes[timeOfDay].waterMonsInfo, WILD_AREA_WATER, 0);
            BattleSetup_StartWildBattle();
            return TRUE;
        }
    }

    return FALSE;
}

bool8 DoesCurrentMapHaveFishingMons(void)
{
    u32 headerId = GetCurrentMapWildMonHeaderId();
    enum TimeOfDay timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_FISHING);

    if (headerId != HEADER_NONE && gWildMonHeaders[headerId].encounterTypes[timeOfDay].fishingMonsInfo != NULL)
        return TRUE;
    else
        return FALSE;
}

void FishingWildEncounter(u8 rod)
{
    u16 species;
    u32 headerId;
    enum TimeOfDay timeOfDay;

    gIsFishingEncounter = TRUE;
    if (CheckFeebas() == TRUE)
    {
        u8 level = ChooseWildMonLevel(&sWildFeebas, 0, WILD_AREA_FISHING);

        species = sWildFeebas.species;
        CreateWildMon(species, level);
    }
    else
    {
        headerId = GetCurrentMapWildMonHeaderId();
        timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_FISHING);
        species = GenerateFishingWildMon(gWildMonHeaders[headerId].encounterTypes[timeOfDay].fishingMonsInfo, rod);
    }

    IncrementGameStat(GAME_STAT_FISHING_ENCOUNTERS);
    SetPokemonAnglerSpecies(species);
    BattleSetup_StartWildBattle();
}

u16 GetLocalWildMon(bool8 *isWaterMon)
{
    u32 headerId;
    enum TimeOfDay timeOfDay;
    const struct WildPokemonInfo *landMonsInfo;
    const struct WildPokemonInfo *waterMonsInfo;

    *isWaterMon = FALSE;
    headerId = GetCurrentMapWildMonHeaderId();
    if (headerId == HEADER_NONE)
        return SPECIES_NONE;

    timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND);
    landMonsInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo;

    timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_WATER);
    waterMonsInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].waterMonsInfo;

    // Neither
    if (landMonsInfo == NULL && waterMonsInfo == NULL)
        return SPECIES_NONE;
    // Land Pokémon
    else if (landMonsInfo != NULL && waterMonsInfo == NULL)
        return landMonsInfo->wildPokemon[ChooseWildMonIndex_Land()].species;
    // Water Pokémon
    else if (landMonsInfo == NULL && waterMonsInfo != NULL)
    {
        *isWaterMon = TRUE;
        return waterMonsInfo->wildPokemon[ChooseWildMonIndex_Water()].species;
    }
    // Either land or water Pokémon
    if ((Random() % 100) < 80)
    {
        return landMonsInfo->wildPokemon[ChooseWildMonIndex_Land()].species;
    }
    else
    {
        *isWaterMon = TRUE;
        return waterMonsInfo->wildPokemon[ChooseWildMonIndex_Water()].species;
    }
}

u16 GetLocalWaterMon(void)
{
    u32 headerId = GetCurrentMapWildMonHeaderId();
    enum TimeOfDay timeOfDay;

    if (headerId != HEADER_NONE)
    {
        timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_WATER);

        const struct WildPokemonInfo *waterMonsInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].waterMonsInfo;

        if (waterMonsInfo)
            return waterMonsInfo->wildPokemon[ChooseWildMonIndex_Water()].species;
    }
    return SPECIES_NONE;
}

bool8 UpdateRepelCounter(void)
{
    u16 repelLureVar = VarGet(VAR_REPEL_STEP_COUNT);
    u16 steps = REPEL_LURE_STEPS(repelLureVar);
    bool32 isLure = IS_LAST_USED_LURE(repelLureVar);

    if (InBattlePike() || CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE)
        return FALSE;
    if (InUnionRoom() == TRUE)
        return FALSE;

    if (steps != 0)
    {
        steps--;
        if (!isLure)
        {
            VarSet(VAR_REPEL_STEP_COUNT, steps);
            if (steps == 0)
            {
                ScriptContext_SetupScript(EventScript_SprayWoreOff);
                return TRUE;
            }
        }
        else
        {
            VarSet(VAR_REPEL_STEP_COUNT, steps | REPEL_LURE_MASK);
            if (steps == 0)
            {
                ScriptContext_SetupScript(EventScript_SprayWoreOff);
                return TRUE;
            }
        }

    }
    return FALSE;
}

static bool8 IsWildLevelAllowedByRepel(u8 wildLevel)
{
    u8 i;

    if (!REPEL_STEP_COUNT)
        return TRUE;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (I_REPEL_INCLUDE_FAINTED == GEN_1 || I_REPEL_INCLUDE_FAINTED >= GEN_6 || GetMonData(&gPlayerParty[i], MON_DATA_HP))
        {
            if (!GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
                return wildLevel >= GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);
        }
    }

    return FALSE;
}

static bool8 IsAbilityAllowingEncounter(u8 level)
{
    enum Ability ability;

    if (GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG))
        return TRUE;

    ability = GetMonAbility(&gPlayerParty[0]);
    if (ability == ABILITY_KEEN_EYE || ability == ABILITY_INTIMIDATE)
    {
        u8 playerMonLevel = GetMonData(&gPlayerParty[0], MON_DATA_LEVEL);
        if (playerMonLevel > 5 && level <= playerMonLevel - 5 && !(Random() % 2))
            return FALSE;
    }

    return TRUE;
}

static bool8 TryGetRandomWildMonIndexByType(const struct WildPokemon *wildMon, enum Type type, u8 numMon, u8 *monIndex)
{
    u8 validIndexes[numMon]; // variable length array, an interesting feature
    u8 i, validMonCount;

    for (i = 0; i < numMon; i++)
        validIndexes[i] = 0;

    for (validMonCount = 0, i = 0; i < numMon; i++)
    {
        if (GetSpeciesType(wildMon[i].species, 0) == type || GetSpeciesType(wildMon[i].species, 1) == type)
            validIndexes[validMonCount++] = i;
    }

    if (validMonCount == 0 || validMonCount == numMon)
        return FALSE;

    *monIndex = validIndexes[Random() % validMonCount];
    return TRUE;
}

#include "data.h"

static u8 GetMaxLevelOfSpeciesInWildTable(const struct WildPokemon *wildMon, u16 species, enum WildPokemonArea area)
{
    u8 i, maxLevel = 0, numMon = 0;

    switch (area)
    {
    case WILD_AREA_LAND:
        numMon = LAND_WILD_COUNT;
        break;
    case WILD_AREA_WATER:
        numMon = WATER_WILD_COUNT;
        break;
    case WILD_AREA_ROCKS:
        numMon = ROCK_WILD_COUNT;
        break;
    default:
    case WILD_AREA_FISHING:
    case WILD_AREA_HIDDEN:
        break;
    }

    for (i = 0; i < numMon; i++)
    {
        if (wildMon[i].species == species && wildMon[i].maxLevel > maxLevel)
            maxLevel = wildMon[i].maxLevel;
    }

    return maxLevel;
}

#ifdef BUGFIX
static bool8 TryGetAbilityInfluencedWildMonIndex(const struct WildPokemon *wildMon, enum Type type, enum Ability ability, u8 *monIndex, u32 size)
#else
static bool8 TryGetAbilityInfluencedWildMonIndex(const struct WildPokemon *wildMon, enum Type type, enum Ability ability, u8 *monIndex)
#endif
{
    if (GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG))
        return FALSE;
    else if (GetMonAbility(&gPlayerParty[0]) != ability)
        return FALSE;
    else if (Random() % 2 != 0)
        return FALSE;

#ifdef BUGFIX
    return TryGetRandomWildMonIndexByType(wildMon, type, size, monIndex);
#else
    return TryGetRandomWildMonIndexByType(wildMon, type, LAND_WILD_COUNT, monIndex);
#endif
}

static void ApplyFluteEncounterRateMod(u32 *encRate)
{
    if (FlagGet(FLAG_SYS_ENC_UP_ITEM) == TRUE)
        *encRate += *encRate / 2;
    else if (FlagGet(FLAG_SYS_ENC_DOWN_ITEM) == TRUE)
        *encRate = *encRate / 2;
}

static void ApplyCleanseTagEncounterRateMod(u32 *encRate)
{
    if (GetMonData(&gPlayerParty[0], MON_DATA_HELD_ITEM) == ITEM_CLEANSE_TAG)
        *encRate = *encRate * 2 / 3;
}

void CutWildEncounter(void)
{
    u16 headerId = GetCurrentMapWildMonHeaderId();

    if (headerId != HEADER_NONE)
    {
        const struct WildPokemonInfo *wildPokemonInfo = gWildMonHeaders[headerId].cutMonsInfo;

        if (wildPokemonInfo == NULL)
        {
            gSpecialVar_Result = FALSE;
        }
        else if (WildEncounterCheck(wildPokemonInfo->encounterRate, TRUE) == TRUE
         //&& TryGenerateWildMon(wildPokemonInfo, WILD_AREA_LAND, WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE) == TRUE)
         && TryGenerateWildMon(wildPokemonInfo, 2, WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE) == TRUE)
        {
            BattleSetup_StartWildBattle();
            gSpecialVar_Result = TRUE;
        }
        else
        {
            gSpecialVar_Result = FALSE;
        }
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

void HeadbuttWildEncounter(void)
{
    u16 headerId = GetCurrentMapWildMonHeaderId();

    if (headerId != 0xFFFF)
    {
        const struct WildPokemonInfo *wildPokemonInfo = gWildMonHeaders[headerId].headbuttMonsInfo;

        if (wildPokemonInfo == NULL)
        {
            gSpecialVar_Result = FALSE;
        }
        else if (WildEncounterCheck(wildPokemonInfo->encounterRate, 1) == TRUE
         && TryGenerateWildMon(wildPokemonInfo, 2, WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE) == TRUE)
        {
            BattleSetup_StartWildBattle();
            gSpecialVar_Result = TRUE;
        }
        else
        {
            gSpecialVar_Result = FALSE;
        }
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

void ThawWildEncounter(void)
{
    u16 headerId = GetCurrentMapWildMonHeaderId();

    if (headerId != 0xFFFF)
    {
        const struct WildPokemonInfo *wildPokemonInfo = gWildMonHeaders[headerId].thawMonsInfo;

        if (wildPokemonInfo == NULL)
        {
            gSpecialVar_Result = FALSE;
        }
        else if (WildEncounterCheck(wildPokemonInfo->encounterRate, 1) == TRUE
         && TryGenerateWildMon(wildPokemonInfo, 2, WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE) == TRUE)
        {
            BattleSetup_StartWildBattle();
            gSpecialVar_Result = TRUE;
        }
        else
        {
            gSpecialVar_Result = FALSE;
        }
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

bool8 TryDoDoubleWildBattle(void)
{
    if (GetSafariZoneFlag()
      || (B_DOUBLE_WILD_REQUIRE_2_MONS == TRUE && GetMonsStateToDoubles() != PLAYER_HAS_TWO_USABLE_MONS))
        return FALSE;
    if (FollowerNPCIsBattlePartner() && FNPC_FLAG_PARTNER_WILD_BATTLES != 0
     && (FNPC_FLAG_PARTNER_WILD_BATTLES == FNPC_ALWAYS || FlagGet(FNPC_FLAG_PARTNER_WILD_BATTLES)) && FNPC_NPC_FOLLOWER_WILD_BATTLE_VS_2 == TRUE)
        return TRUE;
    else if (B_FLAG_FORCE_DOUBLE_WILD != 0 && FlagGet(B_FLAG_FORCE_DOUBLE_WILD))
        return TRUE;
    else if (B_DOUBLE_WILD_CHANCE != 0 && ((Random() % 100) + 1 <= B_DOUBLE_WILD_CHANCE))
        return TRUE;
    return FALSE;
}

bool8 StandardWildEncounter_Debug(void)
{
    u32 headerId = GetCurrentMapWildMonHeaderId();
    enum TimeOfDay timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND);

    if (TryGenerateWildMon(gWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo, WILD_AREA_LAND, 0) != TRUE)
        return FALSE;

    DoStandardWildBattle_Debug();
    return TRUE;
}

u32 ChooseHiddenMonIndex(void)
{
    #ifdef ENCOUNTER_CHANCE_HIDDEN_MONS_TOTAL
        u8 rand = Random() % ENCOUNTER_CHANCE_HIDDEN_MONS_TOTAL;

        if (rand < ENCOUNTER_CHANCE_HIDDEN_MONS_SLOT_0)
            return 0;
        else if (rand >= ENCOUNTER_CHANCE_HIDDEN_MONS_SLOT_0 && rand < ENCOUNTER_CHANCE_HIDDEN_MONS_SLOT_1)
            return 1;
        else
            return 2;
    #else
        return 0xFF;
    #endif
}

bool32 MapHasNoEncounterData(void)
{
    return (GetCurrentMapWildMonHeaderId() == HEADER_NONE);
}
