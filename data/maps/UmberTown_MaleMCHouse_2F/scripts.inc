UmberTown_MaleMCHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, UmberTown_MaleMCHouse_2F_OnTransition
	.byte 0

	@Reused variables

	@ State descriptions for VAR_LITTLEROOT_TOWN_STATE
	@ 0: Before setting clock
	@ 1: After setting clock
	@ 2: Choosing a starter
	@ 3: Received starter
	@ 4: Battled Jace

	@ State descriptions for VAR_LITTLEROOT_INTRO_STATE
	@ 0: Before talking to mom
	@ 1: Never used
	@ 2: Never used
	@ 3: Never used
	@ 4: Never used
	@ 5: After talking to mom
	@ 6: Before showing mom your pokemon
	@ 7: After showing mom your pokemon


UmberTown_MaleMCHouse_2F_OnTransition:
	setrespawn HEAL_LOCATION_UMBER_TOWN
	@call_if_unset 
	@call_if_eq VAR_LITTLEROOT_INTRO_STATE, 0, UmberTown_MaleMCHouse_2F_EventScript_SetIntroFlags
	end


@UmberTown_MaleMCHouse_2F_EventScript_SetIntroFlags:
@	setvar VAR_LITTLEROOT_INTRO_STATE, 4
@	releaseall
@	end

UmberTown_MaleMCHouse_2F_EventScript_TryUpdateSwarm::
	special TryUpdateSwarm
	playse SE_DING_DONG
	waitse
	special BufferSwarmText
	msgbox UmberTown_MaleMCHouse_2F_Text_SwarmChange, MSGBOX_DEFAULT
	closemessage
	end

UmberTown_MaleMCHouse_2F_Text_SwarmChange:
	.string "The current swarm is now {STR_VAR_2}.$"


UmberTown_MaleMCHouse_2F_EventScript_CheckDifficulty::
	special GetDifficulty
	@msgbox UmberTown_MaleMCHouse_2F_Text_Difficulty, MSGBOX_DEFAULT
	@closemessage
	
	switch VAR_RESULT
	case 0, UmberTown_MaleMCHouse_2F_EventScript_NormalDifficulty
	case 1, UmberTown_MaleMCHouse_2F_EventScript_HardcoreDifficulty
	case 2, UmberTown_MaleMCHouse_2F_EventScript_InsaneDifficulty
	end

UmberTown_MaleMCHouse_2F_Text_Difficulty:
	.string "The difficulty is set to {STR_VAR_1}.$"





UmberTown_MaleMCHouse_2F_EventScript_NormalDifficulty::
	msgbox UmberTown_MaleMCHouse_2F_Text_Normal, MSGBOX_DEFAULT
	closemessage
	end

UmberTown_MaleMCHouse_2F_Text_Normal:
	.string "The difficulty is set to NORMAL.$"



UmberTown_MaleMCHouse_2F_EventScript_HardcoreDifficulty::
	msgbox UmberTown_MaleMCHouse_2F_Text_Hardcore, MSGBOX_DEFAULT
	closemessage
	end

UmberTown_MaleMCHouse_2F_Text_Hardcore:
	.string "The difficulty is set to HARDCORE.$"




UmberTown_MaleMCHouse_2F_EventScript_InsaneDifficulty::
	msgbox UmberTown_MaleMCHouse_2F_Text_Insane, MSGBOX_DEFAULT
	closemessage
	end

UmberTown_MaleMCHouse_2F_Text_Insane:
	.string "The difficulty is set to INSANE.$"





UmberTown_MaleMCHouse_2F_EventScript_ClockTurnback::
	lockall
	msgbox UmberTown_MaleMCHouse_2F_Text_GoSetClock, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	releaseall
	end

UmberTown_MaleMCHouse_2F_Text_GoSetClock:
	.string "Whoops, I almost forgot to set\n"
	.string "the clock on the wall!$"

UmberTown_MaleMCHouse_2F_EventScript_WallClock::
	lockall
	goto_if_set FLAG_SET_WALL_CLOCK, PlayersHouse_2F_EventScript_CheckWallClock
	msgbox PlayersHouse_2F_Text_ClockIsStopped, MSGBOX_DEFAULT
	call PlayersHouse_2F_EventScript_SetWallClock
	delay 30
	goto UmberTown_MaleMCHouse_2F_EventScript_SetWeekday
	end

UmberTown_MaleMCHouse_2F_EventScript_WallClockFinish::
	closemessage
	special TryUpdateSwarm                           @Initial swarm randomizer
	special TryUpdateWonderTrades                    @Initial wonder trade randomizer
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	setflag FLAG_SET_WALL_CLOCK
	releaseall
	end







UmberTown_MaleMCHouse_2F_EventScript_SetWeekday::
	message UmberTown_MaleMCHouse_2F_Text_SetWeekday
	waitmessage
	multichoicedefault 21, 0, MULTI_WEEKDAY_SELECT, 0, TRUE
	switch VAR_RESULT
	case 0, UmberTown_MaleMCHouse_2F_EventScript_SetSunday
	case 1, UmberTown_MaleMCHouse_2F_EventScript_SetMonday
	case 2, UmberTown_MaleMCHouse_2F_EventScript_SetTuesday
	case 3, UmberTown_MaleMCHouse_2F_EventScript_SetWednesday
	case 4, UmberTown_MaleMCHouse_2F_EventScript_SetThursday
	case 5, UmberTown_MaleMCHouse_2F_EventScript_SetFriday
	case 6, UmberTown_MaleMCHouse_2F_EventScript_SetSaturday
	end

UmberTown_MaleMCHouse_2F_EventScript_SetSunday::
	bufferstring STR_VAR_2, gText_Sunday
	setvar VAR_0x8004, 0
	goto UmberTown_MaleMCHouse_2F_EventScript_WeekdayConfirm
	end

UmberTown_MaleMCHouse_2F_EventScript_SetMonday::
	bufferstring STR_VAR_2, gText_Monday
	setvar VAR_0x8004, 1
	goto UmberTown_MaleMCHouse_2F_EventScript_WeekdayConfirm
	end

UmberTown_MaleMCHouse_2F_EventScript_SetTuesday::
	bufferstring STR_VAR_2, gText_Tuesday
	setvar VAR_0x8004, 2
	goto UmberTown_MaleMCHouse_2F_EventScript_WeekdayConfirm
	end

UmberTown_MaleMCHouse_2F_EventScript_SetWednesday::
	bufferstring STR_VAR_2, gText_Wednesday
	setvar VAR_0x8004, 3
	goto UmberTown_MaleMCHouse_2F_EventScript_WeekdayConfirm
	end

UmberTown_MaleMCHouse_2F_EventScript_SetThursday::
	bufferstring STR_VAR_2, gText_Thursday
	setvar VAR_0x8004, 4
	goto UmberTown_MaleMCHouse_2F_EventScript_WeekdayConfirm
	end

UmberTown_MaleMCHouse_2F_EventScript_SetFriday::
	bufferstring STR_VAR_2, gText_Friday
	setvar VAR_0x8004, 5
	goto UmberTown_MaleMCHouse_2F_EventScript_WeekdayConfirm
	end

UmberTown_MaleMCHouse_2F_EventScript_SetSaturday::
	bufferstring STR_VAR_2, gText_Saturday
	setvar VAR_0x8004, 6
	goto UmberTown_MaleMCHouse_2F_EventScript_WeekdayConfirm
	end

UmberTown_MaleMCHouse_2F_EventScript_WeekdayConfirm::
	msgbox UmberTown_MaleMCHouse_2F_Text_WeekdayConfirm, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, UmberTown_MaleMCHouse_2F_EventScript_SetWeekday
	copyvar VAR_WEEKDAY, VAR_0x8004
	goto UmberTown_MaleMCHouse_2F_EventScript_WallClockFinish
	end

UmberTown_MaleMCHouse_2F_Text_SetWeekday:
	.string "And what is the current weekday?$"

UmberTown_MaleMCHouse_2F_Text_WeekdayConfirm:
	.string "Today is {STR_VAR_2}?$"








UmberTown_MaleMCHouse_2F_EventScript_CheckWeekday::
	special GetWeekday
	msgbox UmberTown_MaleMCHouse_2F_Text_TodayIs, MSGBOX_SIGN
	end

UmberTown_MaleMCHouse_2F_Text_TodayIs:
	.string "Today is {STR_VAR_1}.$"








UmberTown_MaleMCHouse_2F_EventScript_CheckPlayersPC::
	lockall
	@setvar VAR_0x8004, PC_LOCATION_OTHER
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end

UmberTown_MaleMCHousee_2F_EventScript_TurnOffPlayerPC::
	@setvar VAR_0x8004, PC_LOCATION_OTHER
	@setvar VAR_0x8004, PC_LOCATION_MAYS_HOUSE
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end




