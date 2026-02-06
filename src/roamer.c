#include "global.h"
#include "event_data.h"
#include "ow_synchronize.h"
#include "pokemon.h"
#include "random.h"
#include "roamer.h"
#include "pokedex.h"
#include "battle_tower.h" // GetHighestLevelInPlayerParty declaration

//================= RoamersPlus Config =================\\
// Set to TRUE to allow roaming to every Route
#define ROAM_THE_ENTIRE_MAP TRUE
// 1 in 4 chance for a roamer to replace other encounters
#define ROAMER_ENCOUNTER_MODULO 4
// 1 in 6 chance for a stalker to replace other encounters
#define STALKER_ENCOUNTER_MODULO 6
// Scaling roamer level will be equal to your highest level pokemon's level plus this constant
#define SCALING_LEVEL_MODIFIER -5
// Self Explanatory
#define SCALED_LEVEL_CAP 70
// If TRUE, scaling roamers will evolve at appropriate levels
#define SCALING_ROAMER_EVOLUTION FALSE
//================= Config End =========================\\

// Despite having a variable to track it, the roamer is
// hard-coded to only ever be in map group 0
// Stalkers can move to other map groups
#define ROAMER_MAP_GROUP 0

/*enum
{
    MAP_GRP, // map group
    MAP_NUM, // map number
};*/

#define ROAMER(index) (&gSaveBlock1Ptr->roamer[index])
EWRAM_DATA static u8 sLocationHistory[ROAMER_COUNT][3][2] = {0};
EWRAM_DATA static u8 sRoamerLocation[ROAMER_COUNT][2] = {0};
EWRAM_DATA u8 gEncounteredRoamerIndex = 0;

#define ___ MAP_NUM(MAP_UNDEFINED) // For empty spots in the location table

// Note: There are two potential softlocks that can occur with this table if its maps are
//       changed in particular ways. They can be avoided by ensuring the following:
//       - There must be at least 2 location sets that start with a different map,
//         i.e. every location set cannot start with the same map. This is because of
//         the while loop in RoamerMoveToOtherLocationSet.
//       - Each location set must have at least 3 unique maps. This is because of
//         the while loop in RoamerMove. In this loop the first map in the set is
//         ignored, and an additional map is ignored if the roamer was there recently.
//       - Additionally, while not a softlock, it's worth noting that if for any
//         map in the location table there is not a location set that starts with
//         that map then the roamer will be significantly less likely to move away
//         from that map when it lands there.
static const u8 sRoamerLocations[][6] =
#if !ROAM_THE_ENTIRE_MAP
{
    { MAP_NUM(MAP_ROUTE110), MAP_NUM(MAP_ROUTE111), MAP_NUM(MAP_ROUTE117), MAP_NUM(MAP_ROUTE118), MAP_NUM(MAP_ROUTE134), ___ },
    { MAP_NUM(MAP_ROUTE111), MAP_NUM(MAP_ROUTE110), MAP_NUM(MAP_ROUTE117), MAP_NUM(MAP_ROUTE118), ___, ___ },
    { MAP_NUM(MAP_ROUTE117), MAP_NUM(MAP_ROUTE111), MAP_NUM(MAP_ROUTE110), MAP_NUM(MAP_ROUTE118), ___, ___ },
    { MAP_NUM(MAP_ROUTE118), MAP_NUM(MAP_ROUTE117), MAP_NUM(MAP_ROUTE110), MAP_NUM(MAP_ROUTE111), MAP_NUM(MAP_ROUTE119), MAP_NUM(MAP_ROUTE123) },
    { MAP_NUM(MAP_ROUTE119), MAP_NUM(MAP_ROUTE118), MAP_NUM(MAP_ROUTE120), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE120), MAP_NUM(MAP_ROUTE119), MAP_NUM(MAP_ROUTE121), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE121), MAP_NUM(MAP_ROUTE120), MAP_NUM(MAP_ROUTE122), MAP_NUM(MAP_ROUTE123), ___, ___ },
    { MAP_NUM(MAP_ROUTE122), MAP_NUM(MAP_ROUTE121), MAP_NUM(MAP_ROUTE123), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE123), MAP_NUM(MAP_ROUTE122), MAP_NUM(MAP_ROUTE118), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE124), MAP_NUM(MAP_ROUTE121), MAP_NUM(MAP_ROUTE125), MAP_NUM(MAP_ROUTE126), ___, ___ },
    { MAP_NUM(MAP_ROUTE125), MAP_NUM(MAP_ROUTE124), MAP_NUM(MAP_ROUTE127), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE126), MAP_NUM(MAP_ROUTE124), MAP_NUM(MAP_ROUTE127), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE127), MAP_NUM(MAP_ROUTE125), MAP_NUM(MAP_ROUTE126), MAP_NUM(MAP_ROUTE128), ___, ___ },
    { MAP_NUM(MAP_ROUTE128), MAP_NUM(MAP_ROUTE127), MAP_NUM(MAP_ROUTE129), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE129), MAP_NUM(MAP_ROUTE128), MAP_NUM(MAP_ROUTE130), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE130), MAP_NUM(MAP_ROUTE129), MAP_NUM(MAP_ROUTE131), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE131), MAP_NUM(MAP_ROUTE130), MAP_NUM(MAP_ROUTE132), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE132), MAP_NUM(MAP_ROUTE131), MAP_NUM(MAP_ROUTE133), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE133), MAP_NUM(MAP_ROUTE132), MAP_NUM(MAP_ROUTE134), ___, ___, ___ },
    { MAP_NUM(MAP_ROUTE134), MAP_NUM(MAP_ROUTE133), MAP_NUM(MAP_ROUTE110), ___, ___, ___ },
    { ___, ___, ___, ___, ___, ___ },
};
#else
{
    /*{ MAP_NUM(ROUTE98), MAP_NUM(ROUTE96), MAP_NUM(ROUTE95), ___, ___, ___ },
    { MAP_NUM(ROUTE97), MAP_NUM(ROUTE96), MAP_NUM(ROUTE69), MAP_NUM(ROUTE68), ___, ___ },
    { MAP_NUM(ROUTE96), MAP_NUM(ROUTE98), MAP_NUM(ROUTE97), MAP_NUM(ROUTE95), ___, ___ },
    { MAP_NUM(ROUTE95), MAP_NUM(ROUTE98), MAP_NUM(ROUTE96), MAP_NUM(ROUTE93), ___, ___ },
    { MAP_NUM(ROUTE94), MAP_NUM(ROUTE93), MAP_NUM(ROUTE76), MAP_NUM(ROUTE75), MAP_NUM(ROUTE74), ___ },
    { MAP_NUM(ROUTE93), MAP_NUM(ROUTE95), MAP_NUM(ROUTE94), MAP_NUM(ROUTE92), MAP_NUM(ROUTE69), ___ },
    { MAP_NUM(ROUTE92), MAP_NUM(ROUTE91), MAP_NUM(ROUTE90), MAP_NUM(ROUTE69), ___, ___ },
    { MAP_NUM(ROUTE91), MAP_NUM(ROUTE92), MAP_NUM(ROUTE90), ___, ___, ___ },
    { MAP_NUM(ROUTE90), MAP_NUM(ROUTE91), MAP_NUM(ROUTE89), MAP_NUM(ROUTE73), MAP_NUM(ROUTE72), ___ },
	{ MAP_NUM(ROUTE89), MAP_NUM(ROUTE90), MAP_NUM(ROUTE85), MAP_NUM(ROUTE84), MAP_NUM(ROUTE73), MAP_NUM(ROUTE72) },*/
    { MAP_NUM(ROUTE89), MAP_NUM(ROUTE89), MAP_NUM(ROUTE85), MAP_NUM(ROUTE84), ___, ___ },
	{ MAP_NUM(ROUTE89), MAP_NUM(ROUTE89), MAP_NUM(ROUTE85), MAP_NUM(ROUTE84), ___, ___ },
	{ MAP_NUM(ROUTE89), MAP_NUM(ROUTE89), MAP_NUM(ROUTE85), MAP_NUM(ROUTE84), ___, ___ },
	{ MAP_NUM(ROUTE89), MAP_NUM(ROUTE89), MAP_NUM(ROUTE85), MAP_NUM(ROUTE84), ___, ___ },
	{ MAP_NUM(ROUTE89), MAP_NUM(ROUTE89), MAP_NUM(ROUTE85), MAP_NUM(ROUTE84), ___, ___ },
	{ MAP_NUM(ROUTE89), MAP_NUM(ROUTE89), MAP_NUM(ROUTE85), MAP_NUM(ROUTE84), ___, ___ },
	{ MAP_NUM(ROUTE89), MAP_NUM(ROUTE89), MAP_NUM(ROUTE85), MAP_NUM(ROUTE84), ___, ___ },
	{ MAP_NUM(ROUTE89), MAP_NUM(ROUTE89), MAP_NUM(ROUTE85), MAP_NUM(ROUTE84), ___, ___ },
    { MAP_NUM(ROUTE89), MAP_NUM(ROUTE89), MAP_NUM(ROUTE85), MAP_NUM(ROUTE84), ___, ___ },
    { MAP_NUM(ROUTE88), MAP_NUM(ROUTE87), MAP_NUM(ROUTE86), MAP_NUM(ROUTE84), MAP_NUM(ROUTE83), ___ },
    { MAP_NUM(ROUTE87), MAP_NUM(ROUTE88), MAP_NUM(ROUTE86), ___, ___, ___ },
    { MAP_NUM(ROUTE86), MAP_NUM(ROUTE88), MAP_NUM(ROUTE87), MAP_NUM(ROUTE85), ___, ___ },
    { MAP_NUM(ROUTE85), MAP_NUM(ROUTE89), MAP_NUM(ROUTE86), MAP_NUM(ROUTE84), ___, ___ },
    { MAP_NUM(ROUTE84), MAP_NUM(ROUTE89), MAP_NUM(ROUTE88), MAP_NUM(ROUTE85), MAP_NUM(ROUTE83), ___ },
    { MAP_NUM(ROUTE83), MAP_NUM(ROUTE88), MAP_NUM(ROUTE84), MAP_NUM(ROUTE82), ___, ___ },
    //{ MAP_NUM(ROUTE82), MAP_NUM(ROUTE83), MAP_NUM(ROUTE81), MAP_NUM(ROUTE79), MAP_NUM(ROUTE75), ___ },
	{ MAP_NUM(ROUTE82), MAP_NUM(ROUTE83), MAP_NUM(ROUTE81), MAP_NUM(ROUTE79), ___, ___ },
    { MAP_NUM(ROUTE81), MAP_NUM(ROUTE82), MAP_NUM(ROUTE80), ___, ___, ___ },
    { MAP_NUM(ROUTE80), MAP_NUM(ROUTE81), MAP_NUM(ROUTE79), ___, ___, ___ },
   // { MAP_NUM(ROUTE79), MAP_NUM(ROUTE82), MAP_NUM(ROUTE80), MAP_NUM(ROUTE76), MAP_NUM(ROUTE75), ___ },
   { MAP_NUM(ROUTE79), MAP_NUM(ROUTE82), MAP_NUM(ROUTE80), ___, ___, ___ },
   { MAP_NUM(ROUTE78), MAP_NUM(ROUTE79), MAP_NUM(ROUTE84), ___, ___, ___ },
   { MAP_NUM(ROUTE78), MAP_NUM(ROUTE79), MAP_NUM(ROUTE84), ___, ___, ___ },
   { MAP_NUM(ROUTE78), MAP_NUM(ROUTE79), MAP_NUM(ROUTE84), ___, ___, ___ },
   { MAP_NUM(ROUTE78), MAP_NUM(ROUTE79), MAP_NUM(ROUTE84), ___, ___, ___ },
   { MAP_NUM(ROUTE78), MAP_NUM(ROUTE79), MAP_NUM(ROUTE84), ___, ___, ___ },
   { MAP_NUM(ROUTE78), MAP_NUM(ROUTE79), MAP_NUM(ROUTE84), ___, ___, ___ },
   { MAP_NUM(ROUTE78), MAP_NUM(ROUTE79), MAP_NUM(ROUTE84), ___, ___, ___ },
   { MAP_NUM(ROUTE78), MAP_NUM(ROUTE79), MAP_NUM(ROUTE84), ___, ___, ___ },
   { MAP_NUM(ROUTE78), MAP_NUM(ROUTE79), MAP_NUM(ROUTE84), ___, ___, ___ },
   { MAP_NUM(ROUTE78), MAP_NUM(ROUTE79), MAP_NUM(ROUTE84), ___, ___, ___ },
   { MAP_NUM(ROUTE78), MAP_NUM(ROUTE79), MAP_NUM(ROUTE84), ___, ___, ___ },
   { MAP_NUM(ROUTE78), MAP_NUM(ROUTE79), MAP_NUM(ROUTE84), ___, ___, ___ },
   { MAP_NUM(ROUTE78), MAP_NUM(ROUTE79), MAP_NUM(ROUTE84), ___, ___, ___ },
    /*{ MAP_NUM(ROUTE78), MAP_NUM(ROUTE79), MAP_NUM(ROUTE77), ___, ___, ___ },
    { MAP_NUM(ROUTE77), MAP_NUM(ROUTE78), MAP_NUM(ROUTE76), ___, ___, ___ },
    { MAP_NUM(ROUTE76), MAP_NUM(ROUTE77), MAP_NUM(ROUTE75), ___, ___, ___ },
    { MAP_NUM(ROUTE75), MAP_NUM(ROUTE94), MAP_NUM(ROUTE82), MAP_NUM(ROUTE79), MAP_NUM(ROUTE76), MAP_NUM(ROUTE74) },
    { MAP_NUM(ROUTE74), MAP_NUM(ROUTE94), MAP_NUM(ROUTE75), MAP_NUM(ROUTE73), ___, ___ },
    { MAP_NUM(ROUTE73), MAP_NUM(ROUTE90), MAP_NUM(ROUTE89), MAP_NUM(ROUTE74), MAP_NUM(ROUTE72), ___ },
    { MAP_NUM(ROUTE72), MAP_NUM(ROUTE90), MAP_NUM(ROUTE89), MAP_NUM(ROUTE73), MAP_NUM(ROUTE71), MAP_NUM(ROUTE65) },
    { MAP_NUM(ROUTE71), MAP_NUM(ROUTE72), MAP_NUM(ROUTE70), ___, ___, ___ },
    { MAP_NUM(ROUTE70), MAP_NUM(ROUTE72), MAP_NUM(ROUTE71), ___, ___, ___ },
    { MAP_NUM(ROUTE69), MAP_NUM(ROUTE97), MAP_NUM(ROUTE93), MAP_NUM(ROUTE92), MAP_NUM(ROUTE68), ___ },
    { MAP_NUM(ROUTE68), MAP_NUM(ROUTE97), MAP_NUM(ROUTE69), ___, ___, ___ },
    { MAP_NUM(ROUTE67), MAP_NUM(ROUTE131), MAP_NUM(ROUTE133), MAP_NUM(ROUTE67), ___, ___ },
    { MAP_NUM(ROUTE66), MAP_NUM(ROUTE67), MAP_NUM(ROUTE65), ___, ___, ___ },
    { MAP_NUM(ROUTE_65), MAP_NUM(ROUTE_66), MAP_NUM(ROUTE_72), ___, ___, ___ },*/
	
    { ___, ___, ___, ___, ___, ___ },
};
/*{
    { MAP_NUM(ROUTE101), MAP_NUM(ROUTE102), MAP_NUM(ROUTE103), ___, ___, ___ },
    { MAP_NUM(ROUTE102), MAP_NUM(ROUTE101), MAP_NUM(ROUTE103), MAP_NUM(ROUTE104), ___, ___ },
    { MAP_NUM(ROUTE103), MAP_NUM(ROUTE101), MAP_NUM(ROUTE102), MAP_NUM(ROUTE110), ___, ___ },
    { MAP_NUM(ROUTE104), MAP_NUM(ROUTE102), MAP_NUM(ROUTE105), MAP_NUM(ROUTE116), MAP_NUM(ROUTE115), ___ },
    { MAP_NUM(ROUTE105), MAP_NUM(ROUTE104), MAP_NUM(ROUTE106), ___, ___, ___ },
    { MAP_NUM(ROUTE106), MAP_NUM(ROUTE105), MAP_NUM(ROUTE107), ___, ___, ___ },
    { MAP_NUM(ROUTE107), MAP_NUM(ROUTE106), MAP_NUM(ROUTE108), ___, ___, ___ },
    { MAP_NUM(ROUTE108), MAP_NUM(ROUTE107), MAP_NUM(ROUTE109), ___, ___, ___ },
    { MAP_NUM(ROUTE109), MAP_NUM(ROUTE108), MAP_NUM(ROUTE110), MAP_NUM(ROUTE134), ___, ___ },
    { MAP_NUM(ROUTE110), MAP_NUM(ROUTE111), MAP_NUM(ROUTE117), MAP_NUM(ROUTE118), MAP_NUM(ROUTE109), MAP_NUM(ROUTE103) },
    { MAP_NUM(ROUTE111), MAP_NUM(ROUTE110), MAP_NUM(ROUTE117), MAP_NUM(ROUTE118), MAP_NUM(ROUTE113), MAP_NUM(ROUTE112) },
    { MAP_NUM(ROUTE112), MAP_NUM(ROUTE111), MAP_NUM(ROUTE113), ___, ___, ___ },
    { MAP_NUM(ROUTE113), MAP_NUM(ROUTE111), MAP_NUM(ROUTE114), MAP_NUM(ROUTE112), ___, ___ },
    { MAP_NUM(ROUTE114), MAP_NUM(ROUTE113), MAP_NUM(ROUTE115), ___, ___, ___ },
    { MAP_NUM(ROUTE115), MAP_NUM(ROUTE114), MAP_NUM(ROUTE116), MAP_NUM(ROUTE104), ___, ___ },
    { MAP_NUM(ROUTE116), MAP_NUM(ROUTE115), MAP_NUM(ROUTE117), MAP_NUM(ROUTE104), ___, ___ },
    { MAP_NUM(ROUTE117), MAP_NUM(ROUTE111), MAP_NUM(ROUTE110), MAP_NUM(ROUTE118), MAP_NUM(ROUTE116), ___ },
    { MAP_NUM(ROUTE118), MAP_NUM(ROUTE117), MAP_NUM(ROUTE110), MAP_NUM(ROUTE111), MAP_NUM(ROUTE119), MAP_NUM(ROUTE123) },
    { MAP_NUM(ROUTE119), MAP_NUM(ROUTE118), MAP_NUM(ROUTE120), ___, ___, ___ },
    { MAP_NUM(ROUTE120), MAP_NUM(ROUTE119), MAP_NUM(ROUTE121), ___, ___, ___ },
    { MAP_NUM(ROUTE121), MAP_NUM(ROUTE120), MAP_NUM(ROUTE122), MAP_NUM(ROUTE124), ___, ___ },
    { MAP_NUM(ROUTE122), MAP_NUM(ROUTE121), MAP_NUM(ROUTE123), ___, ___, ___ },
    { MAP_NUM(ROUTE123), MAP_NUM(ROUTE122), MAP_NUM(ROUTE118), ___, ___, ___ },
    { MAP_NUM(ROUTE124), MAP_NUM(ROUTE121), MAP_NUM(ROUTE125), MAP_NUM(ROUTE126), ___, ___ },
    { MAP_NUM(ROUTE125), MAP_NUM(ROUTE124), MAP_NUM(ROUTE127), ___, ___, ___ },
    { MAP_NUM(ROUTE126), MAP_NUM(ROUTE124), MAP_NUM(ROUTE127), ___, ___, ___ },
    { MAP_NUM(ROUTE127), MAP_NUM(ROUTE125), MAP_NUM(ROUTE126), MAP_NUM(ROUTE128), ___, ___ },
    { MAP_NUM(ROUTE128), MAP_NUM(ROUTE127), MAP_NUM(ROUTE129), ___, ___, ___ },
    { MAP_NUM(ROUTE129), MAP_NUM(ROUTE128), MAP_NUM(ROUTE130), ___, ___, ___ },
    { MAP_NUM(ROUTE130), MAP_NUM(ROUTE129), MAP_NUM(ROUTE131), ___, ___, ___ },
    { MAP_NUM(ROUTE131), MAP_NUM(ROUTE130), MAP_NUM(ROUTE132), ___, ___, ___ },
    { MAP_NUM(ROUTE132), MAP_NUM(ROUTE131), MAP_NUM(ROUTE133), ___, ___, ___ },
    { MAP_NUM(ROUTE133), MAP_NUM(ROUTE132), MAP_NUM(ROUTE134), ___, ___, ___ },
    { MAP_NUM(ROUTE134), MAP_NUM(ROUTE133), MAP_NUM(ROUTE110), MAP_NUM(ROUTE109), ___, ___ },
    { ___, ___, ___, ___, ___, ___ },
};*/
#endif

static const u8 sTerrestrialLocations[][6] =
{
    { MAP_NUM(ROUTE101), MAP_NUM(ROUTE102), MAP_NUM(ROUTE103), ___, ___, ___ },
    { MAP_NUM(ROUTE102), MAP_NUM(ROUTE101), MAP_NUM(ROUTE103), MAP_NUM(ROUTE104), ___, ___ },
    { MAP_NUM(ROUTE103), MAP_NUM(ROUTE101), MAP_NUM(ROUTE102), MAP_NUM(ROUTE110), ___, ___ },
    { MAP_NUM(ROUTE104), MAP_NUM(ROUTE102), MAP_NUM(ROUTE115), MAP_NUM(ROUTE116), ___, ___ },
    { MAP_NUM(ROUTE110), MAP_NUM(ROUTE111), MAP_NUM(ROUTE117), MAP_NUM(ROUTE118), MAP_NUM(ROUTE103), ___ },
    { MAP_NUM(ROUTE111), MAP_NUM(ROUTE110), MAP_NUM(ROUTE117), MAP_NUM(ROUTE118), MAP_NUM(ROUTE113), MAP_NUM(ROUTE112) },
    { MAP_NUM(ROUTE112), MAP_NUM(ROUTE111), MAP_NUM(ROUTE113), ___, ___, ___ },
    { MAP_NUM(ROUTE113), MAP_NUM(ROUTE111), MAP_NUM(ROUTE114), MAP_NUM(ROUTE112), ___, ___ },
    { MAP_NUM(ROUTE114), MAP_NUM(ROUTE113), MAP_NUM(ROUTE115), ___, ___, ___ },
    { MAP_NUM(ROUTE115), MAP_NUM(ROUTE114), MAP_NUM(ROUTE116), MAP_NUM(ROUTE104), ___, ___ },
    { MAP_NUM(ROUTE116), MAP_NUM(ROUTE115), MAP_NUM(ROUTE117), MAP_NUM(ROUTE104), ___, ___ },
    { MAP_NUM(ROUTE117), MAP_NUM(ROUTE111), MAP_NUM(ROUTE110), MAP_NUM(ROUTE118), MAP_NUM(ROUTE116), ___ },
    { MAP_NUM(ROUTE118), MAP_NUM(ROUTE117), MAP_NUM(ROUTE110), MAP_NUM(ROUTE111), MAP_NUM(ROUTE119), MAP_NUM(ROUTE123) },
    { MAP_NUM(ROUTE119), MAP_NUM(ROUTE118), MAP_NUM(ROUTE120), ___, ___, ___ },
    { MAP_NUM(ROUTE120), MAP_NUM(ROUTE119), MAP_NUM(ROUTE121), ___, ___, ___ },
    { MAP_NUM(ROUTE121), MAP_NUM(ROUTE120), MAP_NUM(ROUTE123), ___, ___, ___ },
    { MAP_NUM(ROUTE123), MAP_NUM(ROUTE121), MAP_NUM(ROUTE118), ___, ___, ___ },
    { ___, ___, ___, ___, ___, ___ },
};

#undef ___
#define NUM_LOCATION_SETS (ARRAY_COUNT(sRoamerLocations) - 1)
#define NUM_TERRESTRIAL_SETS (ARRAY_COUNT(sTerrestrialLocations) - 1)
#define NUM_LOCATIONS_PER_SET (ARRAY_COUNT(sRoamerLocations[0]))

void DeactivateAllRoamers(void)
{
    u32 i;

    for (i = 0; i < ROAMER_COUNT; i++)
        SetRoamerInactive(i);
}

static void ClearRoamerLocationHistory(u32 roamerIndex)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sLocationHistory[roamerIndex]); i++)
    {
        sLocationHistory[roamerIndex][i][MAP_GRP] = 0;
        sLocationHistory[roamerIndex][i][MAP_NUM] = 0;
    }
}

void MoveAllRoamersToOtherLocationSets(void)
{
    u32 i;

    for (i = 0; i < ROAMER_COUNT; i++)
        RoamerMoveToOtherLocationSet(i);
}

void MoveAllRoamers(void)
{
    u32 i;

    for (i = 0; i < ROAMER_COUNT; i++)
        RoamerMove(i);
}

static void CreateInitialRoamerMon(u8 index, u16 species, u8 level)
{
    ClearRoamerLocationHistory(index);
    u32 personality = GetMonPersonality(species,
        GetSynchronizedGender(ROAMER_ORIGIN, species),
        GetSynchronizedNature(ROAMER_ORIGIN, species),
        RANDOM_UNOWN_LETTER);
    CreateMonWithIVs(&gEnemyParty[0], species, level, personality, OTID_STRUCT_PLAYER_ID, USE_RANDOM_IVS);
    GiveMonInitialMoveset(&gEnemyParty[0]);
    ROAMER(index)->ivs = GetMonData(&gEnemyParty[0], MON_DATA_IVS);
    ROAMER(index)->personality = GetMonData(&gEnemyParty[0], MON_DATA_PERSONALITY);
    ROAMER(index)->species = species;
    ROAMER(index)->level = level;
    ROAMER(index)->statusA = 0;
    ROAMER(index)->statusB = 0;
    ROAMER(index)->hp = GetMonData(&gEnemyParty[0], MON_DATA_MAX_HP);
    ROAMER(index)->cool = GetMonData(&gEnemyParty[0], MON_DATA_COOL);
    ROAMER(index)->beauty = GetMonData(&gEnemyParty[0], MON_DATA_BEAUTY);
    ROAMER(index)->cute = GetMonData(&gEnemyParty[0], MON_DATA_CUTE);
    ROAMER(index)->smart = GetMonData(&gEnemyParty[0], MON_DATA_SMART);
    ROAMER(index)->tough = GetMonData(&gEnemyParty[0], MON_DATA_TOUGH);
    ROAMER(index)->shiny = GetMonData(&gEnemyParty[0], MON_DATA_IS_SHINY);
    ROAMER(index)->active = TRUE;
    sRoamerLocation[index][MAP_GRP] = ROAMER_MAP_GROUP;
    sRoamerLocation[index][MAP_NUM] = sRoamerLocations[Random() % NUM_LOCATION_SETS][0];
}

static u8 GetFirstInactiveRoamerIndex(void)
{
    u32 i;

    for (i = 0; i < ROAMER_COUNT; i++)
    {
        if (!ROAMER(i)->active)
            return i;
    }
    return ROAMER_COUNT;
}

bool8 TryAddRoamer(u16 species, u8 level)
{
    u8 index = GetFirstInactiveRoamerIndex();

    if (index < ROAMER_COUNT)
    {
        // Create the roamer and stop searching
        CreateInitialRoamerMon(index, species, level);
        return TRUE;
    }

    // Maximum active roamers found: do nothing and let the calling function know
    return FALSE;
}

// gSpecialVar_0x8004 here corresponds to the options in the multichoice MULTI_TV_LATI (0 for 'Red', 1 for 'Blue')
void InitRoamer(void)
{
   // if (gSpecialVar_0x8004 == 0) // Red
   //     TryAddRoamer(SPECIES_LATIAS, 40);
   // else
   //     TryAddRoamer(SPECIES_LATIOS, 40);
	if (gSpecialVar_0x8004 == 0)
        TryAddRoamer(SPECIES_TORNADUS, 40);
	else if (gSpecialVar_0x8004 == 1)
        TryAddRoamer(SPECIES_THUNDURUS, 40);
	else if (gSpecialVar_0x8004 == 2)
        TryAddRoamer(SPECIES_LANDORUS, 40);
	else if (gSpecialVar_0x8004 == 3)
        TryAddRoamer(SPECIES_ENAMORUS, 40);
	else
		TryAddRoamer(SPECIES_ARCEUS, 80);
}

void UpdateLocationHistoryForRoamer(void)
{
    u32 i;

    for (i = 0; i < ROAMER_COUNT; i++)
    {
        sLocationHistory[i][2][MAP_GRP] = sLocationHistory[i][1][MAP_GRP];
        sLocationHistory[i][2][MAP_NUM] = sLocationHistory[i][1][MAP_NUM];

        sLocationHistory[i][1][MAP_GRP] = sLocationHistory[i][0][MAP_GRP];
        sLocationHistory[i][1][MAP_NUM] = sLocationHistory[i][0][MAP_NUM];

        sLocationHistory[i][0][MAP_GRP] = gSaveBlock1Ptr->location.mapGroup;
        sLocationHistory[i][0][MAP_NUM] = gSaveBlock1Ptr->location.mapNum;
    }

    ROAMER(index)->locationMapGroup = ROAMER_MAP_GROUP;

    if (!ROAMER(index)->isTerrestrial)
    {
        locations = sRoamerLocations;
        LocationSetCount = NUM_LOCATION_SETS;
    }
	else
    {
        locations = sTerrestrialLocations;
        LocationSetCount = NUM_TERRESTRIAL_SETS;
    }
    // Choose a location set that starts with a map
    // different from the roamer's current map
    do {
        mapNum = locations[Random() % LocationSetCount][0];
    } while (ROAMER(index)->locationMapNum == mapNum);
    ROAMER(index)->locationMapNum = mapNum;
}

void RoamerMoveToOtherLocationSet(u32 roamerIndex)
{
    u8 mapNum = 0;

    if (!ROAMER(roamerIndex)->active)
        return;

    sRoamerLocation[roamerIndex][MAP_GRP] = ROAMER_MAP_GROUP;

    // Choose a location set that starts with a map
    // different from the roamer's current map
    do
    {
        mapNum = sRoamerLocations[Random() % NUM_LOCATION_SETS][0];
        if (sRoamerLocation[roamerIndex][MAP_NUM] != mapNum)
        {
            sRoamerLocation[roamerIndex][MAP_NUM] = mapNum;
            return;
        }
    } while (sRoamerLocation[roamerIndex][MAP_NUM] == mapNum);
    sRoamerLocation[roamerIndex][MAP_NUM] = mapNum;
}

void RoamerMove(u32 roamerIndex)
{
    u8 locSet = 0;

    //if ((Random() % 16) == 0)
	if ((Random() % 16) == 0 || ROAMER(index)->isStalker)
    {
        RoamerMoveToOtherLocationSet(roamerIndex);
    }
    else
    {
        if (!ROAMER(roamerIndex)->active)
            return;

        if (!ROAMER(index)->isTerrestrial)
        {
            locations = sRoamerLocations;
            LocationSetCount = NUM_LOCATION_SETS;
        }
        else
        {
            locations = sTerrestrialLocations;
            LocationSetCount = NUM_TERRESTRIAL_SETS;
        }

        //while (locSet < NUM_LOCATION_SETS)
		while (locSet < LocationSetCount)
        {
            // Find the location set that starts with the roamer's current map
            if (sRoamerLocation[roamerIndex][MAP_NUM] == sRoamerLocations[locSet][0])
            {
                u8 mapNum;
                // Choose a new map (excluding the first) within this set
                // Also exclude a map if the roamer was there 2 moves ago
                do
                {
                    mapNum = sRoamerLocations[locSet][(Random() % (NUM_LOCATIONS_PER_SET - 1)) + 1];
                } while ((sLocationHistory[roamerIndex][2][MAP_GRP] == ROAMER_MAP_GROUP
                        && sLocationHistory[roamerIndex][2][MAP_NUM] == mapNum)
                        || mapNum == MAP_NUM(MAP_UNDEFINED));
                sRoamerLocation[roamerIndex][MAP_NUM] = mapNum;
                return;
            }
            locSet++;
        }
    }
}

bool8 IsRoamerAt(u32 roamerIndex, u8 mapGroup, u8 mapNum)
{
    if (ROAMER(roamerIndex)->active && mapGroup == sRoamerLocation[roamerIndex][MAP_GRP] && mapNum == sRoamerLocation[roamerIndex][MAP_NUM])
        return TRUE;
    else
        return FALSE;
}

void CreateRoamerMonInstance(u32 roamerIndex)
{
    u32 status = ROAMER(roamerIndex)->statusA + (ROAMER(roamerIndex)->statusB << 8);
    struct Pokemon *mon = &gEnemyParty[0];
	
    ZeroEnemyPartyMons();
    CreateMonWithIVsPersonality(mon, ROAMER(roamerIndex)->species, ROAMER(roamerIndex)->level, ROAMER(roamerIndex)->ivs, ROAMER(roamerIndex)->personality);
    SetMonData(mon, MON_DATA_STATUS, &status);
    SetMonData(mon, MON_DATA_HP, &ROAMER(roamerIndex)->hp);
    SetMonData(mon, MON_DATA_COOL, &ROAMER(roamerIndex)->cool);
    SetMonData(mon, MON_DATA_BEAUTY, &ROAMER(roamerIndex)->beauty);
    SetMonData(mon, MON_DATA_CUTE, &ROAMER(roamerIndex)->cute);
    SetMonData(mon, MON_DATA_SMART, &ROAMER(roamerIndex)->smart);
    SetMonData(mon, MON_DATA_TOUGH, &ROAMER(roamerIndex)->tough);
    SetMonData(mon, MON_DATA_IS_SHINY, &ROAMER(roamerIndex)->shiny);
}

//bool8 TryStartRoamerEncounter(void)
bool8 TryStartRoamerEncounter(bool8 isWaterEncounter)
{
    u32 i;

    for (i = 0; i < ROAMER_COUNT; i++)
    {
        if (IsRoamerAt(i, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum) == TRUE && (Random() % 4) == 0)
        {
            CreateRoamerMonInstance(i);
            gEncounteredRoamerIndex = i;
            return TRUE;
        }
    }
    return FALSE;
}

void UpdateRoamerHPStatus(struct Pokemon *mon)
{
    u32 status = GetMonData(mon, MON_DATA_STATUS);

    ROAMER(gEncounteredRoamerIndex)->hp = GetMonData(mon, MON_DATA_HP);
    ROAMER(gEncounteredRoamerIndex)->statusA = status;
    ROAMER(gEncounteredRoamerIndex)->statusB = status >> 8;

    RoamerMoveToOtherLocationSet(gEncounteredRoamerIndex);
}

void SetRoamerInactive(u32 roamerIndex)
{
    ROAMER(roamerIndex)->active = FALSE;
}

void GetRoamerLocation(u32 roamerIndex, u8 *mapGroup, u8 *mapNum)
{
    *mapGroup = sRoamerLocation[roamerIndex][MAP_GRP];
    *mapNum = sRoamerLocation[roamerIndex][MAP_NUM];
}
