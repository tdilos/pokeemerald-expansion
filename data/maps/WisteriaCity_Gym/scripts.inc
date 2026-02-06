WisteriaCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, WisteriaCity_Gym_OnLoad
	@map_script MAP_SCRIPT_ON_FRAME_TABLE, WisteriaCity_Gym_OnFrame
	.byte 0

WisteriaCity_Gym_OnLoad:
	goto_if_eq VAR_WISTERIA_GYM_STATE, 0, WisteriaCity_Gym_InitializePuzzle
	call_if_ge VAR_WISTERIA_GYM_STATE, 2, WisteriaCity_Gym_EventScript_Activate2
	call_if_ge VAR_WISTERIA_GYM_STATE, 3, WisteriaCity_Gym_EventScript_Activate3
	call_if_ge VAR_WISTERIA_GYM_STATE, 4, WisteriaCity_Gym_EventScript_Activate4
	call_if_ge VAR_WISTERIA_GYM_STATE, 5, WisteriaCity_Gym_EventScript_Activate5
	call_if_ge VAR_WISTERIA_GYM_STATE, 6, WisteriaCity_Gym_EventScript_Activate6
	call_if_ge VAR_WISTERIA_GYM_STATE, 7, WisteriaCity_Gym_EventScript_Activate7
	call_if_set FLAG_WISTERIA_GYM_SWITCH_1, WisteriaCity_Gym_EventScript_PressSwitch1
	call_if_set FLAG_WISTERIA_GYM_SWITCH_2, WisteriaCity_Gym_EventScript_PressSwitch2
	call_if_set FLAG_WISTERIA_GYM_SWITCH_3, WisteriaCity_Gym_EventScript_PressSwitch3
	call_if_set FLAG_WISTERIA_GYM_SWITCH_4, WisteriaCity_Gym_EventScript_PressSwitch4
	call_if_set FLAG_WISTERIA_GYM_SWITCH_5, WisteriaCity_Gym_EventScript_PressSwitch5
	call_if_set FLAG_WISTERIA_GYM_SWITCH_6, WisteriaCity_Gym_EventScript_PressSwitch6
	@special DrawWholeMapView
	end

@WisteriaCity_Gym_OnFrame:
@	map_script_2 VAR_WISTERIA_GYM_STATE, 0, WisteriaCity_Gym_InitializePuzzle
@	map_script_2 VAR_WISTERIA_GYM_STATE, 1, WisteriaCity_Gym_WithinPuzzle
@	map_script_2 VAR_WISTERIA_GYM_STATE, 2, WisteriaCity_Gym_WithinPuzzle
@	map_script_2 VAR_WISTERIA_GYM_STATE, 3, WisteriaCity_Gym_WithinPuzzle
@	map_script_2 VAR_WISTERIA_GYM_STATE, 4, WisteriaCity_Gym_WithinPuzzle
@	map_script_2 VAR_WISTERIA_GYM_STATE, 5, WisteriaCity_Gym_WithinPuzzle
@	map_script_2 VAR_WISTERIA_GYM_STATE, 6, WisteriaCity_Gym_WithinPuzzle
@	map_script_2 VAR_WISTERIA_GYM_STATE, 7, WisteriaCity_Gym_WithinPuzzle
@	map_script_2 VAR_WISTERIA_GYM_STATE, 8, WisteriaCity_Gym_WithinPuzzle
@	.2byte 0

WisteriaCity_Gym_InitializePuzzle::
	setvar VAR_WISTERIA_GYM_STATE, 1
	end

@WisteriaCity_Gym_WithinPuzzle::
@	lockall
@	@bufferstring STR_VAR_1, 
@	msgbox WisteriaCity_Gym_Text_Debug, MSGBOX_DEFAULT
@	release
@	end

@WisteriaCity_Gym_Text_Debug:
@	.string "The current room is now 0.$"


WisteriaCity_Gym_EventScript_PressSwitch1::
	setmetatile 5, 18, METATILE_GymsIssho2_ButtonPressed, FALSE
	return

WisteriaCity_Gym_EventScript_PressSwitch2::
	setmetatile 15, 18, METATILE_GymsIssho2_ButtonPressed, FALSE
	return

WisteriaCity_Gym_EventScript_PressSwitch3::
	setmetatile 35, 18, METATILE_GymsIssho2_ButtonPressed, FALSE
	return

WisteriaCity_Gym_EventScript_PressSwitch4::
	setmetatile 5, 29, METATILE_GymsIssho2_ButtonPressed, FALSE
	return

WisteriaCity_Gym_EventScript_PressSwitch5::
	setmetatile 15, 29, METATILE_GymsIssho2_ButtonPressed, FALSE
	return

WisteriaCity_Gym_EventScript_PressSwitch6::
	setmetatile 5, 7, METATILE_GymsIssho2_ButtonPressed, FALSE
	return





WisteriaCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_WISTERIA_GYM_SWITCH_1, WisteriaCity_Gym_EventScript_SkipSwitch
	playse SE_CLICK
	addvar VAR_WISTERIA_GYM_STATE, 1
	delay 30
	setflag FLAG_WISTERIA_GYM_SWITCH_1
	call WisteriaCity_Gym_EventScript_PressSwitch1
	goto WisteriaCity_Gym_EventScript_UpdateTeleports
	end

WisteriaCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_WISTERIA_GYM_SWITCH_2, WisteriaCity_Gym_EventScript_SkipSwitch
	playse SE_CLICK
	addvar VAR_WISTERIA_GYM_STATE, 1
	delay 30
	setflag FLAG_WISTERIA_GYM_SWITCH_2
	call WisteriaCity_Gym_EventScript_PressSwitch2
	goto WisteriaCity_Gym_EventScript_UpdateTeleports
	end

WisteriaCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_WISTERIA_GYM_SWITCH_3, WisteriaCity_Gym_EventScript_SkipSwitch
	playse SE_CLICK
	addvar VAR_WISTERIA_GYM_STATE, 1
	delay 30
	setflag FLAG_WISTERIA_GYM_SWITCH_3
	call WisteriaCity_Gym_EventScript_PressSwitch3
	goto WisteriaCity_Gym_EventScript_UpdateTeleports
	end

WisteriaCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_WISTERIA_GYM_SWITCH_4, WisteriaCity_Gym_EventScript_SkipSwitch
	playse SE_CLICK
	addvar VAR_WISTERIA_GYM_STATE, 1
	delay 30
	setflag FLAG_WISTERIA_GYM_SWITCH_4
	call WisteriaCity_Gym_EventScript_PressSwitch4
	goto WisteriaCity_Gym_EventScript_UpdateTeleports
	end

WisteriaCity_Gym_EventScript_Switch5::
	lockall
	goto_if_set FLAG_WISTERIA_GYM_SWITCH_5, WisteriaCity_Gym_EventScript_SkipSwitch
	playse SE_CLICK
	addvar VAR_WISTERIA_GYM_STATE, 1
	delay 30
	setflag FLAG_WISTERIA_GYM_SWITCH_5
	call WisteriaCity_Gym_EventScript_PressSwitch5
	goto WisteriaCity_Gym_EventScript_UpdateTeleports
	end

WisteriaCity_Gym_EventScript_Switch6::
	lockall
	goto_if_set FLAG_WISTERIA_GYM_SWITCH_6, WisteriaCity_Gym_EventScript_SkipSwitch
	playse SE_CLICK
	addvar VAR_WISTERIA_GYM_STATE, 1
	delay 30
	setflag FLAG_WISTERIA_GYM_SWITCH_6
	call WisteriaCity_Gym_EventScript_PressSwitch6
	goto WisteriaCity_Gym_EventScript_UpdateTeleports
	end

WisteriaCity_Gym_EventScript_DrawMapAfterSwitchUsed::
	special DrawWholeMapView
	@playse SE_CLICK
	releaseall
	end

WisteriaCity_Gym_EventScript_SkipSwitch::
	releaseall
	end

WisteriaCity_Gym_EventScript_UpdateTeleports::
	call_if_eq VAR_WISTERIA_GYM_STATE, 2, WisteriaCity_Gym_EventScript_Activate2
	call_if_eq VAR_WISTERIA_GYM_STATE, 3, WisteriaCity_Gym_EventScript_Activate3
	call_if_eq VAR_WISTERIA_GYM_STATE, 4, WisteriaCity_Gym_EventScript_Activate4
	call_if_eq VAR_WISTERIA_GYM_STATE, 5, WisteriaCity_Gym_EventScript_Activate5
	call_if_eq VAR_WISTERIA_GYM_STATE, 6, WisteriaCity_Gym_EventScript_Activate6
	call_if_eq VAR_WISTERIA_GYM_STATE, 7, WisteriaCity_Gym_EventScript_Activate7
	goto WisteriaCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

WisteriaCity_Gym_EventScript_Activate2::
	setmetatile 1, 5, METATILE_GymsIssho2_Warp2_On, FALSE
	setmetatile 1, 16, METATILE_GymsIssho2_Warp2_On, FALSE
	setmetatile 1, 27, METATILE_GymsIssho2_Warp2_On, FALSE
	setmetatile 11, 5, METATILE_GymsIssho2_Warp2_On, FALSE
	setmetatile 11, 16, METATILE_GymsIssho2_Warp2_On, FALSE
	setmetatile 11, 27, METATILE_GymsIssho2_Warp2_On, FALSE
	setmetatile 21, 5, METATILE_GymsIssho2_Warp2_On, FALSE
	setmetatile 21, 16, METATILE_GymsIssho2_Warp2_On, FALSE
	setmetatile 21, 27, METATILE_GymsIssho2_Warp2_On, FALSE
	setmetatile 31, 5, METATILE_GymsIssho2_Warp2_On, FALSE
	setmetatile 31, 16, METATILE_GymsIssho2_Warp2_On, FALSE
	setmetatile 31, 27, METATILE_GymsIssho2_BlueWarp2_On, FALSE
	@goto WisteriaCity_Gym_EventScript_DrawMapAfterSwitchUsed
	return

WisteriaCity_Gym_EventScript_Activate3::
	setmetatile 3, 3, METATILE_GymsIssho2_Warp3_On, FALSE
	setmetatile 3, 14, METATILE_GymsIssho2_Warp3_On, FALSE
	setmetatile 3, 25, METATILE_GymsIssho2_Warp3_On, FALSE
	setmetatile 13, 3, METATILE_GymsIssho2_Warp3_On, FALSE
	setmetatile 13, 14, METATILE_GymsIssho2_Warp3_On, FALSE
	setmetatile 13, 25, METATILE_GymsIssho2_Warp3_On, FALSE
	setmetatile 23, 3, METATILE_GymsIssho2_Warp3_On, FALSE
	setmetatile 23, 14, METATILE_GymsIssho2_Warp3_On, FALSE
	setmetatile 23, 25, METATILE_GymsIssho2_Warp3_On, FALSE
	setmetatile 33, 3, METATILE_GymsIssho2_Warp3_On, FALSE
	setmetatile 33, 14, METATILE_GymsIssho2_Warp3_On, FALSE
	setmetatile 33, 25, METATILE_GymsIssho2_BlueWarp3_On, FALSE
	@goto WisteriaCity_Gym_EventScript_DrawMapAfterSwitchUsed
	return

WisteriaCity_Gym_EventScript_Activate4::
	setmetatile 7, 3, METATILE_GymsIssho2_Warp4_On, FALSE
	setmetatile 7, 14, METATILE_GymsIssho2_Warp4_On, FALSE
	setmetatile 7, 25, METATILE_GymsIssho2_Warp4_On, FALSE
	setmetatile 17, 3, METATILE_GymsIssho2_Warp4_On, FALSE
	setmetatile 17, 14, METATILE_GymsIssho2_Warp4_On, FALSE
	setmetatile 17, 25, METATILE_GymsIssho2_Warp4_On, FALSE
	setmetatile 27, 3, METATILE_GymsIssho2_Warp4_On, FALSE
	setmetatile 27, 14, METATILE_GymsIssho2_Warp4_On, FALSE
	setmetatile 27, 25, METATILE_GymsIssho2_Warp4_On, FALSE
	setmetatile 37, 3, METATILE_GymsIssho2_Warp4_On, FALSE
	setmetatile 37, 14, METATILE_GymsIssho2_Warp4_On, FALSE
	setmetatile 37, 25, METATILE_GymsIssho2_BlueWarp4_On, FALSE
	@goto WisteriaCity_Gym_EventScript_DrawMapAfterSwitchUsed
	return

WisteriaCity_Gym_EventScript_Activate5::
	setmetatile 9, 5, METATILE_GymsIssho2_Warp5_On, FALSE
	setmetatile 9, 16, METATILE_GymsIssho2_Warp5_On, FALSE
	setmetatile 9, 27, METATILE_GymsIssho2_Warp5_On, FALSE
	setmetatile 19, 5, METATILE_GymsIssho2_Warp5_On, FALSE
	setmetatile 19, 16, METATILE_GymsIssho2_Warp5_On, FALSE
	setmetatile 19, 27, METATILE_GymsIssho2_Warp5_On, FALSE
	setmetatile 29, 5, METATILE_GymsIssho2_Warp5_On, FALSE
	setmetatile 29, 16, METATILE_GymsIssho2_Warp5_On, FALSE
	setmetatile 29, 27, METATILE_GymsIssho2_Warp5_On, FALSE
	setmetatile 39, 5, METATILE_GymsIssho2_Warp5_On, FALSE
	setmetatile 39, 16, METATILE_GymsIssho2_Warp5_On, FALSE
	setmetatile 39, 27, METATILE_GymsIssho2_BlueWarp5_On, FALSE
	@goto WisteriaCity_Gym_EventScript_DrawMapAfterSwitchUsed
	return

WisteriaCity_Gym_EventScript_Activate6::
	setmetatile 9, 9, METATILE_GymsIssho2_Warp6_On, FALSE
	setmetatile 9, 20, METATILE_GymsIssho2_Warp6_On, FALSE
	setmetatile 9, 31, METATILE_GymsIssho2_Warp6_On, FALSE
	setmetatile 19, 9, METATILE_GymsIssho2_Warp6_On, FALSE
	setmetatile 19, 20, METATILE_GymsIssho2_Warp6_On, FALSE
	setmetatile 19, 31, METATILE_GymsIssho2_Warp6_On, FALSE
	setmetatile 29, 9, METATILE_GymsIssho2_Warp6_On, FALSE
	setmetatile 29, 20, METATILE_GymsIssho2_Warp6_On, FALSE
	setmetatile 29, 31, METATILE_GymsIssho2_Warp6_On, FALSE
	setmetatile 39, 9, METATILE_GymsIssho2_Warp6_On, FALSE
	setmetatile 39, 20, METATILE_GymsIssho2_Warp6_On, FALSE
	setmetatile 39, 31, METATILE_GymsIssho2_BlueWarp6_On, FALSE
	@goto WisteriaCity_Gym_EventScript_DrawMapAfterSwitchUsed
	return

WisteriaCity_Gym_EventScript_Activate7::
	setmetatile 7, 11, METATILE_GymsIssho2_Warp7_On, FALSE
	setmetatile 7, 22, METATILE_GymsIssho2_Warp7_On, FALSE
	setmetatile 7, 33, METATILE_GymsIssho2_Warp7_On, FALSE
	setmetatile 17, 11, METATILE_GymsIssho2_Warp7_On, FALSE
	setmetatile 17, 22, METATILE_GymsIssho2_Warp7_On, FALSE
	setmetatile 17, 33, METATILE_GymsIssho2_Warp7_On, FALSE
	setmetatile 27, 11, METATILE_GymsIssho2_Warp7_On, FALSE
	setmetatile 27, 22, METATILE_GymsIssho2_Warp7_On, FALSE
	setmetatile 27, 33, METATILE_GymsIssho2_Warp7_On, FALSE
	setmetatile 37, 11, METATILE_GymsIssho2_Warp7_On, FALSE
	setmetatile 37, 22, METATILE_GymsIssho2_Warp7_On, FALSE
	setmetatile 37, 33, METATILE_GymsIssho2_BlueWarp7_On, FALSE
	@goto WisteriaCity_Gym_EventScript_DrawMapAfterSwitchUsed
	return

WisteriaCity_Gym_EventScript_BlueWarp0::
	lockall
	setvar VAR_WISTERIA_GYM_ROOM, 0
	goto WisteriaCity_Gym_EventScript_WarpToRoom0
	end

WisteriaCity_Gym_EventScript_BlueWarp1::
	lockall
	setvar VAR_WISTERIA_GYM_ROOM, 1
	goto WisteriaCity_Gym_EventScript_WarpToRoom1
	end

WisteriaCity_Gym_EventScript_BlueWarp2::
	lockall
	goto_if_lt VAR_WISTERIA_GYM_STATE, 2, WisteriaCity_Gym_EventScript_SkipSwitch
	setvar VAR_WISTERIA_GYM_ROOM, 2
	goto WisteriaCity_Gym_EventScript_WarpToRoom2
	end

WisteriaCity_Gym_EventScript_BlueWarp3::
	lockall
	goto_if_lt VAR_WISTERIA_GYM_STATE, 3, WisteriaCity_Gym_EventScript_SkipSwitch
	setvar VAR_WISTERIA_GYM_ROOM, 3
	goto WisteriaCity_Gym_EventScript_WarpToRoom3
	end

WisteriaCity_Gym_EventScript_BlueWarp4::
	lockall
	goto_if_lt VAR_WISTERIA_GYM_STATE, 4, WisteriaCity_Gym_EventScript_SkipSwitch
	setvar VAR_WISTERIA_GYM_ROOM, 4
	goto WisteriaCity_Gym_EventScript_WarpToRoom4
	end

WisteriaCity_Gym_EventScript_BlueWarp5::
	lockall
	goto_if_lt VAR_WISTERIA_GYM_STATE, 5, WisteriaCity_Gym_EventScript_SkipSwitch
	setvar VAR_WISTERIA_GYM_ROOM, 5
	goto WisteriaCity_Gym_EventScript_WarpToRoom5
	end

WisteriaCity_Gym_EventScript_BlueWarp6::
	lockall
	goto_if_lt VAR_WISTERIA_GYM_STATE, 6, WisteriaCity_Gym_EventScript_SkipSwitch
	setvar VAR_WISTERIA_GYM_ROOM, 6
	goto WisteriaCity_Gym_EventScript_WarpToRoom6
	end

WisteriaCity_Gym_EventScript_BlueWarp7::
	lockall
	goto_if_lt VAR_WISTERIA_GYM_STATE, 7, WisteriaCity_Gym_EventScript_SkipSwitch
	setvar VAR_WISTERIA_GYM_ROOM, 7
	goto WisteriaCity_Gym_EventScript_WarpToRoom7
	end




WisteriaCity_Gym_EventScript_Warp0::
	lockall
	setvar VAR_WISTERIA_GYM_MULTIPLIER, 0
	@playse SE_CLICK
	@waitse
	goto WisteriaCity_Gym_EventScript_Warp
	end

WisteriaCity_Gym_EventScript_Warp1::
	lockall
	@setvar VAR_0x8004, 1
	setvar VAR_WISTERIA_GYM_MULTIPLIER, 1
	@playse SE_CLICK
	@waitse
	goto WisteriaCity_Gym_EventScript_Warp
	end

WisteriaCity_Gym_EventScript_Warp2::
	lockall
	goto_if_lt VAR_WISTERIA_GYM_STATE, 2, WisteriaCity_Gym_EventScript_SkipSwitch
	@setvar VAR_0x8004, 2
	setvar VAR_WISTERIA_GYM_MULTIPLIER, 2
	@playse SE_CLICK
	@waitse
	goto WisteriaCity_Gym_EventScript_Warp
	end

WisteriaCity_Gym_EventScript_Warp3::
	lockall
	goto_if_lt VAR_WISTERIA_GYM_STATE, 3, WisteriaCity_Gym_EventScript_SkipSwitch
	@setvar VAR_0x8004, 3
	setvar VAR_WISTERIA_GYM_MULTIPLIER, 3
	goto WisteriaCity_Gym_EventScript_Warp
	end

WisteriaCity_Gym_EventScript_Warp4::
	lockall
	goto_if_lt VAR_WISTERIA_GYM_STATE, 4, WisteriaCity_Gym_EventScript_SkipSwitch
	@setvar VAR_0x8004, 4
	setvar VAR_WISTERIA_GYM_MULTIPLIER, 4
	goto WisteriaCity_Gym_EventScript_Warp
	end

WisteriaCity_Gym_EventScript_Warp5::
	lockall
	goto_if_lt VAR_WISTERIA_GYM_STATE, 5, WisteriaCity_Gym_EventScript_SkipSwitch
	@setvar VAR_0x8004, 5
	setvar VAR_WISTERIA_GYM_MULTIPLIER, 5
	goto WisteriaCity_Gym_EventScript_Warp
	end

WisteriaCity_Gym_EventScript_Warp6::
	lockall
	goto_if_lt VAR_WISTERIA_GYM_STATE, 6, WisteriaCity_Gym_EventScript_SkipSwitch
	@setvar VAR_0x8004, 6
	setvar VAR_WISTERIA_GYM_MULTIPLIER, 6
	goto WisteriaCity_Gym_EventScript_Warp
	end

WisteriaCity_Gym_EventScript_Warp7::
	lockall
	goto_if_lt VAR_WISTERIA_GYM_STATE, 7, WisteriaCity_Gym_EventScript_SkipSwitch
	@setvar VAR_0x8004, 7
	setvar VAR_WISTERIA_GYM_MULTIPLIER, 7
	goto WisteriaCity_Gym_EventScript_Warp
	end

WisteriaCity_Gym_EventScript_Warp::
	special WisteriaGymWarp
	@delay 30
	@switch VAR_RESULT
	switch VAR_WISTERIA_GYM_ROOM
	case 0, WisteriaCity_Gym_EventScript_WarpToRoom0
	case 1, WisteriaCity_Gym_EventScript_WarpToRoom1
	case 2, WisteriaCity_Gym_EventScript_WarpToRoom2
	case 3, WisteriaCity_Gym_EventScript_WarpToRoom3
	case 4, WisteriaCity_Gym_EventScript_WarpToRoom4
	case 5, WisteriaCity_Gym_EventScript_WarpToRoom5
	case 6, WisteriaCity_Gym_EventScript_WarpToRoom6
	case 7, WisteriaCity_Gym_EventScript_WarpToRoom7
	case 8, WisteriaCity_Gym_EventScript_WarpToRoom8
	case 9, WisteriaCity_Gym_EventScript_WarpToRoom9
	case 10, WisteriaCity_Gym_EventScript_WarpToRoomA
	case 11, WisteriaCity_Gym_EventScript_WarpToRoomB
	end


WisteriaCity_Gym_EventScript_WarpToRoom1::
	warpmossdeepgym MAP_WISTERIA_CITY_GYM, 5, 3
	waitstate
	releaseall
	end

WisteriaCity_Gym_EventScript_WarpToRoom2::
	warpmossdeepgym MAP_WISTERIA_CITY_GYM, 15, 3
	waitstate
	releaseall
	end

WisteriaCity_Gym_EventScript_WarpToRoom3::
	warpmossdeepgym MAP_WISTERIA_CITY_GYM, 25, 3
	waitstate
	releaseall
	end

WisteriaCity_Gym_EventScript_WarpToRoom4::
	warpmossdeepgym MAP_WISTERIA_CITY_GYM, 35, 3
	waitstate
	releaseall
	end

WisteriaCity_Gym_EventScript_WarpToRoom5::
	warpmossdeepgym MAP_WISTERIA_CITY_GYM, 5, 14
	waitstate
	releaseall
	end

WisteriaCity_Gym_EventScript_WarpToRoom6::
	warpmossdeepgym MAP_WISTERIA_CITY_GYM, 15, 14
	waitstate
	releaseall
	end

WisteriaCity_Gym_EventScript_WarpToRoom7::
	warpmossdeepgym MAP_WISTERIA_CITY_GYM, 25, 14
	waitstate
	releaseall
	end

WisteriaCity_Gym_EventScript_WarpToRoom8::
	warpmossdeepgym MAP_WISTERIA_CITY_GYM, 35, 14
	waitstate
	releaseall
	end

WisteriaCity_Gym_EventScript_WarpToRoom9::
	warpmossdeepgym MAP_WISTERIA_CITY_GYM, 5, 25
	waitstate
	releaseall
	end

WisteriaCity_Gym_EventScript_WarpToRoomA::
	warpmossdeepgym MAP_WISTERIA_CITY_GYM, 15, 25
	waitstate
	releaseall
	end

WisteriaCity_Gym_EventScript_WarpToRoomB::
	warpmossdeepgym MAP_WISTERIA_CITY_GYM, 25, 25
	waitstate
	releaseall
	end

WisteriaCity_Gym_EventScript_WarpToRoom0::
	warpmossdeepgym MAP_WISTERIA_CITY_GYM, 35, 25
	waitstate
	releaseall
	end



WisteriaCity_Gym_EventScript_Erin::
	trainerbattle_single TRAINER_ERIN, WisteriaCity_Gym_Text_ErinIntro, WisteriaCity_Gym_Text_ErinDefeated
	msgbox WisteriaCity_Gym_Text_ErinPostBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, WisteriaCity_Gym_EventScript_ErinNope
	msgbox WisteriaCity_Gym_Text_ErinPostBattle3, MSGBOX_AUTOCLOSE
	end

WisteriaCity_Gym_EventScript_ErinNope::
	msgbox WisteriaCity_Gym_Text_ErinPostBattle2, MSGBOX_AUTOCLOSE
	end

WisteriaCity_Gym_EventScript_Zeke::
	trainerbattle_single TRAINER_ZEKE, WisteriaCity_Gym_Text_ZekeIntro, WisteriaCity_Gym_Text_ZekeDefeated
	msgbox WisteriaCity_Gym_Text_ZekePostBattle, MSGBOX_AUTOCLOSE
	end

WisteriaCity_Gym_EventScript_Ziggy::
	trainerbattle_single TRAINER_ZIGGY, WisteriaCity_Gym_Text_ZiggyIntro, WisteriaCity_Gym_Text_ZiggyDefeated
	msgbox WisteriaCity_Gym_Text_ZiggyPostBattle, MSGBOX_AUTOCLOSE
	end

WisteriaCity_Gym_EventScript_Alfred::
	trainerbattle_single TRAINER_ALFRED, WisteriaCity_Gym_Text_AlfredIntro, WisteriaCity_Gym_Text_AlfredDefeated
	msgbox WisteriaCity_Gym_Text_AlfredPostBattle, MSGBOX_AUTOCLOSE
	end

WisteriaCity_Gym_EventScript_Butch::
	trainerbattle_single TRAINER_BUTCH, WisteriaCity_Gym_Text_ButchIntro, WisteriaCity_Gym_Text_ButchDefeated
	msgbox WisteriaCity_Gym_Text_ButchPostBattle, MSGBOX_AUTOCLOSE
	end

WisteriaCity_Gym_EventScript_Chevy::
	trainerbattle_single TRAINER_CHEVY, WisteriaCity_Gym_Text_ChevyIntro, WisteriaCity_Gym_Text_ChevyDefeated
	msgbox WisteriaCity_Gym_Text_ChevyPostBattle, MSGBOX_AUTOCLOSE
	end

WisteriaCity_Gym_EventScript_Darwin::
	trainerbattle_single TRAINER_DARWIN, WisteriaCity_Gym_Text_DarwinIntro, WisteriaCity_Gym_Text_DarwinDefeated
	msgbox WisteriaCity_Gym_Text_DarwinPostBattle, MSGBOX_AUTOCLOSE
	end

WisteriaCity_Gym_EventScript_Werner::
	trainerbattle_single TRAINER_WERNER, WisteriaCity_Gym_Text_WernerIntro, WisteriaCity_Gym_Text_WernerDefeated
	msgbox WisteriaCity_Gym_Text_WernerPostBattle, MSGBOX_AUTOCLOSE
	end

WisteriaCity_Gym_Text_ErinIntro:
	.string "Need a hint?$"

WisteriaCity_Gym_Text_ErinDefeated:
	.string "Alright already!$"

WisteriaCity_Gym_Text_ErinPostBattle:
	.string "Three times four is twelve.\n"
	.string "Right?$"

WisteriaCity_Gym_Text_ErinPostBattle2:
	.string "Nope!\p"
	.string "In this gym, it's zero!$"

WisteriaCity_Gym_Text_ErinPostBattle3:
	.string "Hmmm, maybe you know more\n"
	.string "than I thought.$"

WisteriaCity_Gym_Text_ZekeIntro:
	.string "This place makes my head hurt.$"

WisteriaCity_Gym_Text_ZekeDefeated:
	.string "Ouch.$"

WisteriaCity_Gym_Text_ZekePostBattle:
	.string "What's with these numbers, anyway?$"

WisteriaCity_Gym_Text_ZiggyIntro:
	.string "We're lost again.$"

WisteriaCity_Gym_Text_ZiggyDefeated:
	.string "D'oh!$"

WisteriaCity_Gym_Text_ZiggyPostBattle:
	.string "I know we've been here before...$"

WisteriaCity_Gym_Text_AlfredIntro:
	.string "Uhuhuhuhuh.\n"
	.string "Check out my POKéMON.$"

WisteriaCity_Gym_Text_AlfredDefeated:
	.string "Uhuhuhuhuh.$"

WisteriaCity_Gym_Text_AlfredPostBattle:
	@.string "Far out, huh?$"
	.string "Bet you're jealous of\n"
	.string "my POKéMON, huh?$"

WisteriaCity_Gym_Text_ChevyIntro:
	.string "That's it!\n"
	.string "I've had it with this place!$"

WisteriaCity_Gym_Text_ChevyDefeated:
	.string "I'm totally lost.$"

WisteriaCity_Gym_Text_ChevyPostBattle:
	.string "This kooky scientist guy sure makes\n"
	.string "himself hard to find.$"

WisteriaCity_Gym_Text_ButchIntro:
	.string "Have you seen any switches?$"

WisteriaCity_Gym_Text_ButchDefeated:
	.string "Figures.$"

WisteriaCity_Gym_Text_ButchPostBattle:
	.string "Urgh, I'm going in circles here.$"

WisteriaCity_Gym_Text_DarwinIntro:
	@.string "Shall I explain what this machine does?$"
	.string "Ad hoc, ad loc, and quid pro quo!$"

WisteriaCity_Gym_Text_DarwinDefeated:
	@.string "Indeed.$"
	.string "So little time, haha!\n"
	.string "So much to know!$"

WisteriaCity_Gym_Text_DarwinPostBattle:
	@.string "This machine will take you to\n"
	@.string "DR. ADDERLY directly.\p"
	@.string "But you'll need a password to turn it on.$"
	.string "If I spoke prose, you'd all find out\n"
	.string "I don't know what I talk about!$"

WisteriaCity_Gym_Text_WernerIntro:
	.string "I'm running an experiment!\n"
	.string "You'll be my test subject!$"

WisteriaCity_Gym_Text_WernerDefeated:
	.string "Interesting.$"

WisteriaCity_Gym_Text_WernerPostBattle:
	@.string "There is so much to learn about POKéMON.$"
	.string "Looking for the password scroll?\p"
	.string "It's in ROOM B.\n"
	.string "I can tell you that much.$"


WisteriaCity_Gym_EventScript_Scroll::
	lockall
	goto_if_lt VAR_WISTERIA_GYM_STATE, 8, WisteriaCity_Gym_EventScript_FoundScroll
	msgbox WisteriaCity_Gym_Text_ReadScroll, MSGBOX_DEFAULT
	release
	end

WisteriaCity_Gym_EventScript_FoundScroll::
	setvar VAR_WISTERIA_GYM_STATE, 8
	msgbox WisteriaCity_Gym_Text_ReadScroll, MSGBOX_DEFAULT
	closemessage
	release
	end

WisteriaCity_Gym_Text_ReadScroll:
	.string "{PLAYER} memorized the password\n"
	.string "written on the scroll.$"

WisteriaCity_Gym_EventScript_Computer::
	lockall
	goto_if_eq VAR_WISTERIA_GYM_STATE, 8, WisteriaCity_Gym_EventScript_EnterPassword
	msgbox WisteriaCity_Gym_Text_NeedPassword, MSGBOX_DEFAULT
	releaseall
	end

WisteriaCity_Gym_Text_NeedPassword:
	.string "It's a computer terminal.\n"
	.string "It looks like it needs a password.$"

WisteriaCity_Gym_EventScript_EnterPassword::
	msgbox WisteriaCity_Gym_Text_EnteredPassword, MSGBOX_DEFAULT
	warpmossdeepgym MAP_WISTERIA_CITY_GYM, 53, 7
	waitstate
	releaseall
	end

WisteriaCity_Gym_Text_EnteredPassword:
	.string "{PLAYER} entered the password.\p"
	.string "“NIDOKING”$"



WisteriaCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WISTERIA_GYM, WisteriaCity_Gym_EventScript_GymGuidePostVictory
	msgbox WisteriaCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	goto_if_eq VAR_WISTERIA_GYM_GUIDE, 0, WisteriaCity_Gym_EventScript_GiveFreshWater
	release
	end

WisteriaCity_Gym_EventScript_GiveFreshWater::
	giveitem ITEM_FRESH_WATER
	setvar VAR_WISTERIA_GYM_GUIDE, 1
	release
	end

WisteriaCity_Gym_EventScript_GymGuidePostVictory::
	msgbox WisteriaCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	goto_if_le VAR_WISTERIA_GYM_GUIDE, 1, WisteriaCity_Gym_EventScript_GivePoisonGem
	release
	end

WisteriaCity_Gym_EventScript_GivePoisonGem::
	giveitem ITEM_POISON_GEM
	setvar VAR_WISTERIA_GYM_GUIDE, 2
	release
	end

WisteriaCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, WisteriaCity_Gym_EventScript_GymStatueCertified
	goto WisteriaCity_Gym_EventScript_GymStatue
	end

WisteriaCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, WisteriaCity_Gym_EventScript_GymStatueCertified
	goto WisteriaCity_Gym_EventScript_GymStatue
	end

WisteriaCity_Gym_EventScript_GymStatueCertified::
	msgbox WisteriaCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

WisteriaCity_Gym_EventScript_GymStatue::
	msgbox WisteriaCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

WisteriaCity_Gym_Text_GymStatue:
	.string "WISTERIA CITY POKéMON GYM$"

WisteriaCity_Gym_Text_GymStatueCertified:
	.string "WISTERIA CITY POKéMON GYM\p"
	.string "ADDERLY'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}, JACE$"


WisteriaCity_Gym_Text_GymGuideAdvice:
	.string "Hey there, cutie.\p"
	.string "This gym's leader is DR. ADDERLY.\n"
	.string "He's not exactly a people person.\p"
	.string "He's holed himself up in the back\n"
	.string "of this gym.\p"
	.string "The only way to reach him is through\n"
	.string "that white teleport.\p"
	.string "But you'll need to get the password\n"
	.string "from a scroll first.\p"
	.string "Those blue teleports will take you to\n"
	.string "the room with the same number.\p"
	.string "Don't ask me how the yellow teleports\n"
	.string "work though.\p"
	.string "All I know is that there are switches\n"
	.string "that will turn more of them on.\p"
	.string "Oh, and one more thing!\p"
	.string "DR. ADDERLY specializes in\n"
	.string "the POISON type.\p"
	.string "You can counter those with a\n"
	.string "GROUND or PSYCHIC type.\p"
	.string "Well, good luck, cutie!\n"
	.string "I know you can do this!$"

WisteriaCity_Gym_Text_GymGuidePostVictory:
	.string "Woohoo! You're on fire!\p"
	.string "Check your badge case.\p"
	.string "If you have eight badges, that means\n"
	.string "you're ready for the POKéMON LEAGUE!$"








WisteriaCity_Gym_EventScript_Adderly::
	trainerbattle_single TRAINER_ADDERLY_1, WisteriaCity_Gym_Text_AdderlyIntro, WisteriaCity_Gym_Text_AdderlyDefeated, WisteriaCity_Gym_EventScript_AdderlyPostBattle, NO_MUSIC
	goto_if_unset FLAG_DEFEATED_WISTERIA_GYM, WisteriaCity_Gym_EventScript_GiveOxidize
	msgbox WisteriaCity_Gym_Text_AdderlyPostBattle, MSGBOX_DEFAULT
	release
	end

WisteriaCity_Gym_EventScript_AdderlyPostBattle::
	message WisteriaCity_Gym_Text_ReceivedAtterBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special GetDifficulty
	switch VAR_RESULT
	case 0, WisteriaCity_Gym_EventScript_EventScript_ExplainBadgeNormal
	case 1, WisteriaCity_Gym_EventScript_EventScript_ExplainBadgeHardcore
	case 2, WisteriaCity_Gym_EventScript_EventScript_ExplainBadgeInsane
	end

WisteriaCity_Gym_EventScript_EventScript_ExplainBadgeNormal::
	goto_if_set FLAG_BADGE07_GET, WisteriaCity_Gym_EventScript_AlreadyBeatEthelNormal
	msgbox WisteriaCity_Gym_Text_AtterBadgeNormalInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_BADGE08_GET
	setvar VAR_0x8008, 16
	call Common_EventScript_SetGymTrainers
	goto WisteriaCity_Gym_EventScript_GiveOxidize
	end

WisteriaCity_Gym_EventScript_AlreadyBeatEthelNormal::
	msgbox WisteriaCity_Gym_Text_AtterBadgeNormalInfoTakeThis2, MSGBOX_DEFAULT
	setflag FLAG_BADGE08_GET
	setvar VAR_0x8008, 16
	call Common_EventScript_SetGymTrainers
	goto WisteriaCity_Gym_EventScript_GiveOxidize
	end

WisteriaCity_Gym_EventScript_EventScript_ExplainBadgeHardcore::
	goto_if_set FLAG_BADGE07_GET, WisteriaCity_Gym_EventScript_AlreadyBeatEthelHardcore
	msgbox WisteriaCity_Gym_Text_AtterBadgeHardcoreInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_BADGE08_GET
	setvar VAR_0x8008, 16
	call Common_EventScript_SetGymTrainers
	goto WisteriaCity_Gym_EventScript_GiveOxidize
	end

WisteriaCity_Gym_EventScript_AlreadyBeatEthelHardcore::
	msgbox WisteriaCity_Gym_Text_AtterBadgeHardcoreInfoTakeThis2, MSGBOX_DEFAULT
	setflag FLAG_BADGE08_GET
	setvar VAR_0x8008, 16
	call Common_EventScript_SetGymTrainers
	goto WisteriaCity_Gym_EventScript_GiveOxidize
	end

WisteriaCity_Gym_EventScript_EventScript_ExplainBadgeInsane::
	goto_if_set FLAG_BADGE07_GET, WisteriaCity_Gym_EventScript_AlreadyBeatEthelInsane
	msgbox WisteriaCity_Gym_Text_AtterBadgeInsaneInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_BADGE08_GET
	setvar VAR_0x8008, 16
	call Common_EventScript_SetGymTrainers
	goto WisteriaCity_Gym_EventScript_GiveOxidize
	end

WisteriaCity_Gym_EventScript_AlreadyBeatEthelInsane::
	msgbox WisteriaCity_Gym_Text_AtterBadgeInsaneInfoTakeThis2, MSGBOX_DEFAULT
	setflag FLAG_BADGE08_GET
	setvar VAR_0x8008, 16
	call Common_EventScript_SetGymTrainers
	goto WisteriaCity_Gym_EventScript_GiveOxidize
	end

WisteriaCity_Gym_EventScript_GiveOxidize::
	giveitem ITEM_TM36
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DEFEATED_WISTERIA_GYM
	msgbox WisteriaCity_Gym_Text_ExplainOxidize, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox WisteriaCity_Gym_Text_GiveLabKey, MSGBOX_DEFAULT
	giveitem ITEM_LAB_KEY
	msgbox WisteriaCity_Gym_Text_AdderlyPostBattle, MSGBOX_DEFAULT
	closemessage
	release
	end




WisteriaCity_Gym_Text_AdderlyIntro:
	.string "ADDERLY: Hmph!\n"
	.string "And what do we have here?\p"
	.string "Let me guess, you want to snoop\n"
	.string "around my old laboratory too?\p"
	.string "Are you another irresponsible trainer\n"
	.string "chasing power at all costs?\p"
	.string "Or perhaps you have noble intentions\n"
	.string "for my old work?\p"
	.string "Hmph! Doesn't everybody.\p"
	.string "\p"
	.string "The scientist seeks to understand.\n"
	.string "The technologist seeks to control.\p"
	.string "In my arrogance, I thought I\n"
	.string "could control it too.\p"
	.string "I thought I could create a perfect world.\n"
	.string "But all I did was doom my only world...\p"
	.string "\p"
	.string "Hmph! As will anyone else who tries to\n"
	.string "play god with my work!\p"
	.string "So what is it that YOU hope\n"
	.string "to gain from it, young trainer?\p"
	.string "You're here on behalf of the RANGERS,\n"
	.string "so I've heard.\p"
	.string "I wonder, is your love for the world\n"
	.string "of people and POKéMON genuine?\p"
	.string "Or are you just another silver-tongued\n"
	.string "charlatan?\p"
	.string "There's only one way to know for sure.\p"
	.string "I, the disgraced doctor, will learn just\n"
	.string "what kind of trainer you really are!{PAUSE_MUSIC}{PLAY_BGM MUS_RG_ENCOUNTER_GYM_LEADER}$"


WisteriaCity_Gym_Text_AdderlyIntroAlt:
	.string "Hmph!\n"
	.string "And what do we have here?\p"
	.string "Another ambitious young trainer\n"
	.string "chasing power at all costs?\p"
	.string "Or perhaps you just want to do a little\n"
	.string "sightseeing in my old laboratory?\p"
	.string "\p"
	.string "Hmph!\p"
	.string "No one comes here anymore except to\n"
	.string "badger me about that old place.\p"
	.string "I tell them all the same thing.\n"
	.string "See for yourself what's left up there.\p"
	.string "\p"
	.string "So you want to go looking for\n"
	.string "trouble too, I see.\p"
	.string "Hmph! Well I won't let a dumb kid\n"
	.string "throw their life away!\p"
	.string "If you want to go snooping around there,\n"
	.string "you need to prove you can handle yourself.\p"
	.string "The key to my old laboratory is none\n"
	.string "other than my official gym badge.\p"
	.string "If you want it, you'll have to defeat me\n"
	.string "in an official gym battle.\p"
	.string "Do you still wish to proceed?\p"
	.string "\p"
	.string "Very well.\p"
	.string "I, the former great DR. ADDERLY,\n"
	.string "shall put you to the test!{PAUSE_MUSIC}{PLAY_BGM MUS_RG_ENCOUNTER_GYM_LEADER}$"

WisteriaCity_Gym_Text_AdderlyDefeated:
	@.string "Hmph!\n"
	@.string "It seems you have some skill after all.\p"
	@.string "Very well. As agreed, I'm entrusting you\n"
	@.string "with this ATTER BADGE.$"
	.string "So that's how it is then.\p"
	.string "Very well, you've earned the right\n"
	.string "to carry this ATTER BADGE.$"

WisteriaCity_Gym_Text_ReceivedAtterBadge:
	.string "{PLAYER} received the ATTER BADGE\n"
	.string "from DR. ADDERLY.$"

WisteriaCity_Gym_Text_AtterBadgeNormalInfoTakeThis:
	.string "The ATTER BADGE makes all POKéMON up to\n"
	.string "Level 56 obey without question.\p"
	.string "It also lets you use the HM move\n"
	.string "DIVE outside of battle.\p"
	.string "Hmph!\n"
	.string "And this suits you too, I think.$"

WisteriaCity_Gym_Text_AtterBadgeNormalInfoTakeThis2:
	.string "The ATTER BADGE makes all POKéMON up to\n"
	.string "Level 60 obey without question.\p"
	.string "You'll also be able to use the HM move\n"
	.string "DIVE outside of battle.\p"
	.string "Hmph!\n"
	.string "And this suits you too, I think.$"

WisteriaCity_Gym_Text_AtterBadgeHardcoreInfoTakeThis:
	.string "The ATTER BADGE makes all POKéMON up to\n"
	.string "Level 52 obey without question.\p"
	.string "It also lets you use the HM move\n"
	.string "DIVE outside of battle.\p"
	.string "Hmph!\n"
	.string "And this suits you too, I think.$"

WisteriaCity_Gym_Text_AtterBadgeHardcoreInfoTakeThis2:
	.string "The ATTER BADGE makes all POKéMON up to\n"
	.string "Level 55 obey without question.\p"
	.string "You'll also be able to use the HM move\n"
	.string "DIVE outside of battle.\p"
	.string "Hmph!\n"
	.string "And this suits you too, I think.$"

WisteriaCity_Gym_Text_AtterBadgeInsaneInfoTakeThis:
	.string "The ATTER BADGE makes all POKéMON up to\n"
	.string "Level 49 obey without question.\p"
	.string "It also lets you use the HM move\n"
	.string "DIVE outside of battle.\p"
	.string "Hmph!\n"
	.string "And this suits you too, I think.$"

WisteriaCity_Gym_Text_AtterBadgeInsaneInfoTakeThis2:
	.string "The ATTER BADGE makes all POKéMON up to\n"
	.string "Level 52 obey without question.\p"
	.string "You'll also be able to use the HM move\n"
	.string "DIVE outside of battle.\p"
	.string "Hmph!\n"
	.string "And this suits you too, I think.$"

WisteriaCity_Gym_Text_ExplainOxidize:
	.string "That TM contains the move SLUDGE BOMB,\n"
	.string "a powerful POISON type move.$"


WisteriaCity_Gym_Text_GiveLabKey:
	.string "I can see now that your intentions are\n"
	.string "good if perhaps a bit naive.\p"
	.string "Your POKéMON trust you. JUSTIN and the\n"
	.string "POKéMON RANGERS trust you.\p"
	.string "Therefore, I will trust you.$"

WisteriaCity_Gym_Text_AdderlyPostBattle:
	.string "I don't know what clues related to\n"
	.string "TEAM GENESIS you're hoping to find.\p"
	.string "Only know this:\p"
	.string "The work we did there is better left to\n"
	.string "rot and never again see the light of day.\p"
	.string "Don't say I didn't warn you.$"

@WisteriaCity_Gym_Text_AdderlyPostBattleAlt:
	@.string "Hmph! If you're serious about entering\n"
	@.string "the laboratory, I won't stop you.\p"
	@.string "I don't know what stories you've heard.\n"
	@.string "But you need only know this.\p"
	@.string "The work we did there is better left\n"
	@.string "to rot and be forgotten.\p"
	@.string "Don't say I didn't warn you.$"



