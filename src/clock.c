#include "global.h"
#include "berry.h"
#include "clock.h"
#include "dewford_trend.h"
#include "event_data.h"
#include "field_specials.h"
#include "field_weather.h"
#include "lottery_corner.h"
#include "main.h"
#include "overworld.h"
#include "pokerus.h"
#include "random.h"
#include "rtc.h"
#include "time_events.h"
#include "tv.h"
#include "wallclock.h"
#include "constants/form_change_types.h"
#include "apricorn_tree.h"
#include "roamer.h"
#include "wild_encounter.h"
#include "shop.h"
#include "random.h"
#include "wonder_trade.h"

static void UpdatePerDay(struct Time *localTime);
static void UpdatePerMinute(struct Time *localTime);

void UpdateWeekday(u16 increment);
void UpdateEmporiumVendors();

void UpdateSeason(u16 increment);

void InitTimeBasedEvents(void)
{
    FlagSet(FLAG_SYS_CLOCK_SET);
    RtcCalcLocalTime();
    gSaveBlock2Ptr->lastBerryTreeUpdate = gLocalTime;
    VarSet(VAR_DAYS, gLocalTime.days);
}

void DoTimeBasedEvents(void)
{
    if (FlagGet(FLAG_SYS_CLOCK_SET) && !InPokemonCenter())
    {
        RtcCalcLocalTime();
        UpdatePerDay(&gLocalTime);
        UpdatePerMinute(&gLocalTime);
    }
}

void UpdateDailySeed(void)
{
    gSaveBlock1Ptr->dailySeed = Random32();
}

static void UpdatePerDay(struct Time *localTime)
{
    u16 *days = GetVarPointer(VAR_DAYS);
    u16 daysSince;

    if (*days != localTime->days && *days <= localTime->days)
    {
        daysSince = localTime->days - *days;
        ClearDailyFlags();
        UpdateDailySeed();
        UpdateDewfordTrendPerDay(daysSince);
        UpdateTVShowsPerDay(daysSince);
		TryUpdateWonderTrades();
		TryUpdateSwarm();
		UpdateWeekday(daysSince);
		UpdateEmporiumVendors();
		UpdateSeason(daysSince);
        UpdateWeatherPerDay(daysSince);
        UpdatePartyPokerusTime(daysSince);
        UpdateMirageRnd(daysSince);
        UpdateBirchState(daysSince);
        UpdateFrontierManiac(daysSince);
        UpdateFrontierGambler(daysSince);
        SetShoalItemFlag(daysSince);
        SetRandomLotteryNumber(daysSince);
        UpdateDaysPassedSinceFormChange(daysSince);
        DailyResetApricornTrees();
        *days = localTime->days;
    }
}

static void UpdatePerMinute(struct Time *localTime)
{
    struct Time difference;
    int minutes;

    CalcTimeDifference(&difference, &gSaveBlock2Ptr->lastBerryTreeUpdate, localTime);
    minutes = 24 * 60 * difference.days + 60 * difference.hours + difference.minutes;
    if (minutes != 0)
    {
        if (minutes >= 0)
        {
            BerryTreeTimeUpdate(minutes);
            gSaveBlock2Ptr->lastBerryTreeUpdate = *localTime;
        }
    }
}

void FormChangeTimeUpdate()
{
    s32 i;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        TryFormChange(&gParties[B_TRAINER_PLAYER][i], FORM_CHANGE_TIME_OF_DAY, B_TRAINER_PLAYER);
    }
}

void UpdateWeekday(u16 increment)
{
	u32 newDay;
	u32 oldDay = VarGet(VAR_WEEKDAY);
	
	newDay = oldDay + increment;
	newDay %= 7;
	VarSet(VAR_WEEKDAY, newDay);
}

void UpdateEmporiumVendors()
{
	u32 random1 = Random() % 16;
	u32 random2 = Random() % 16;
	u32 random3 = Random() % 16;
	
	VarSet(VAR_EMPORIUM_VENDOR_1, random1);
	VarSet(VAR_EMPORIUM_VENDOR_2, random2);
	VarSet(VAR_EMPORIUM_VENDOR_3, random3);
}

void UpdateSeason(u16 increment)
{
	u32 newSeason;
	u32 oldSeason = VarGet(VAR_SEASON);
	
	newSeason = oldSeason + increment / 7;
	newSeason %= 4;
	VarSet(VAR_SEASON, newSeason);
}

static void ReturnFromStartWallClock(void)
{
    InitTimeBasedEvents();
    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void StartWallClock(void)
{
    SetMainCallback2(CB2_StartWallClock);
    gMain.savedCallback = ReturnFromStartWallClock;
}
