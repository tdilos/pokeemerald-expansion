#include "global.h"
#include "battle.h"
#include "event_data.h"
#include "field_player_avatar.h"
#include "overworld.h"
#include "main.h"
#include "pokeblock.h"
#include "mirage_palace.h"
#include "script.h"
#include "string_util.h"
#include "tv.h"
#include "constants/game_stat.h"
#include "field_screen_effect.h"

extern const u8 MiragePalace_EventScript_TimesUp[];
extern const u8 MiragePalace_EventScript_Warning[];

EWRAM_DATA static u16 sMiragePalaceStepCounter = 0;

bool32 GetMiragePalaceFlag(void)
{
    return FlagGet(FLAG_SYS_INSIDE_MIRAGE_PALACE);
}

void SetMiragePalaceFlag(void)
{
    FlagSet(FLAG_SYS_INSIDE_MIRAGE_PALACE);
}

void ResetMiragePalaceFlag(void)
{
    FlagClear(FLAG_SYS_INSIDE_MIRAGE_PALACE);
}

void EnterMiragePalace(void)
{
    //IncrementGameStat(GAME_STAT_ENTERED_MIRAGE_PALACE);
    SetMiragePalaceFlag();
    sMiragePalaceStepCounter = 560;
	//sSafariZoneStepCounter = 100;
}

void ExitMiragePalace(void)
{
    ResetMiragePalaceFlag();
    sMiragePalaceStepCounter = 0;
	//sSafariZoneStepCounter = 0;
}

bool8 MiragePalaceTakeStep(void)
{
    if (GetMiragePalaceFlag() == FALSE)
    {
        return FALSE;
    }

    sMiragePalaceStepCounter--;
	//sSafariZoneStepCounter--;
	
    if (sMiragePalaceStepCounter == 500) // 1st hour
    {
        ScriptContext_SetupScript(MiragePalace_EventScript_Warning);
        return FALSE;
    }
    if (sMiragePalaceStepCounter == 440) // 2nd hour
    {
        ScriptContext_SetupScript(MiragePalace_EventScript_Warning);
        return FALSE;
    }
    if (sMiragePalaceStepCounter == 380) // 3rd hour
    {
        ScriptContext_SetupScript(MiragePalace_EventScript_Warning);
        return FALSE;
    }	
    if (sMiragePalaceStepCounter == 320) // 4th hour
    {
        ScriptContext_SetupScript(MiragePalace_EventScript_Warning);
        return FALSE;
    }
    if (sMiragePalaceStepCounter == 260) // 5th hour
    {
        ScriptContext_SetupScript(MiragePalace_EventScript_Warning);
        return FALSE;
    }
    if (sMiragePalaceStepCounter == 200) // 6th hour
    {
        ScriptContext_SetupScript(MiragePalace_EventScript_Warning);
        return FALSE;
    }
    if (sMiragePalaceStepCounter == 140) // 7th hour
    {
        ScriptContext_SetupScript(MiragePalace_EventScript_Warning);
        return FALSE;
    }
    if (sMiragePalaceStepCounter == 80) // 8th hour
    {
        ScriptContext_SetupScript(MiragePalace_EventScript_Warning);
        return FALSE;
    }	
    if (sMiragePalaceStepCounter == 20) // 9th hour
    {
        ScriptContext_SetupScript(MiragePalace_EventScript_Warning);
        return FALSE;
    }
    if (sMiragePalaceStepCounter == 0)
    {
        ScriptContext_SetupScript(MiragePalace_EventScript_TimesUp);
        return TRUE;
    }
    return FALSE;
}

