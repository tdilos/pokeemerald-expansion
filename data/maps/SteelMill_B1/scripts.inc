.set LOCALID_VICTINI, 3

SteelMill_B1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SteelMill_B1_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SteelMill_B1_OnWarp
	.byte 0

SteelMill_B1_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, SteelMill_B1_EventScript_SetForceOffscreenLoad
	.2byte 0

SteelMill_B1_EventScript_SetForceOffscreenLoad::
	setflag FLAG_FORCE_LOAD_OFFSCREEN_OBJEV
	end



SteelMill_B1_OnTransition::
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	setvar VAR_TEMP_5, 0
	setvar VAR_TEMP_6, 0
	setvar VAR_TEMP_7, 0
	end




SteelMill_B1_EventScript_OpenVictiniDoor::
	playse SE_SUCCESS
	waitse
	playse SE_TRUCK_DOOR
	setmetatile 4, 11, METATILE_Facility2_LabDoor_Open_Top, TRUE
	setmetatile 4, 12, METATILE_Facility2_LabDoor_Open, FALSE
	special DrawWholeMapView
	return







SteelMill_B1_EventScript_Switch1::
	lockall
	setvar VAR_TEMP_1, 100
	playse SE_SWITCH
	waitse
	setmetatile 12, 3, METATILE_Facility2_MagnetSwitch_On, TRUE
	special DrawWholeMapView
	goto_if_eq VAR_TEMP_1, 100, SteelMill_B1_EventScript_Puzzle1Solved
	releaseall
	end

SteelMill_B1_EventScript_Puzzle1Solved::
	playse SE_SUCCESS
	waitse
	playse SE_TRUCK_DOOR
	setmetatile 12, 0, METATILE_Facility2_LabDoor_Open_Top, TRUE
	setmetatile 12, 1, METATILE_Facility2_LabDoor_Open, FALSE
	special DrawWholeMapView
	releaseall
	end

SteelMill_B1_EventScript_OffSwitch1::
	goto_if_lt VAR_TEMP_1, 99, SteelMill_B1_EventScript_Skip
	setvar VAR_TEMP_1, 0
	playse SE_PC_OFF
	waitse
	setmetatile 12, 3, METATILE_Facility2_MagnetSwitch_Off, FALSE
	special DrawWholeMapView
	end








SteelMill_B1_EventScript_Switch2::
	lockall
	setvar VAR_TEMP_2, 100
	playse SE_SWITCH
	waitse
	setmetatile 48, 15, METATILE_Facility2_MagnetSwitch_On, TRUE
	special DrawWholeMapView
	goto_if_eq VAR_TEMP_3, 100, SteelMill_B1_EventScript_CheckSwitch4
	releaseall
	end

SteelMill_B1_EventScript_CheckSwitch2::
	goto_if_eq VAR_TEMP_2, 100, SteelMill_B1_EventScript_Puzzle2Solved
	releaseall
	end

SteelMill_B1_EventScript_Switch3::
	lockall
	setvar VAR_TEMP_3, 100
	playse SE_SWITCH
	waitse
	setmetatile 49, 16, METATILE_Facility2_MagnetSwitch_On, TRUE
	special DrawWholeMapView
	goto_if_eq VAR_TEMP_4, 100, SteelMill_B1_EventScript_CheckSwitch2
	releaseall
	end

SteelMill_B1_EventScript_CheckSwitch3::
	goto_if_eq VAR_TEMP_3, 100, SteelMill_B1_EventScript_Puzzle2Solved
	releaseall
	end

SteelMill_B1_EventScript_Switch4::
	lockall
	setvar VAR_TEMP_4, 100
	playse SE_SWITCH
	waitse
	setmetatile 50, 17, METATILE_Facility2_MagnetSwitch_On, TRUE
	special DrawWholeMapView
	goto_if_eq VAR_TEMP_2, 100, SteelMill_B1_EventScript_CheckSwitch3
	releaseall
	end

SteelMill_B1_EventScript_CheckSwitch4::
	goto_if_eq VAR_TEMP_4, 100, SteelMill_B1_EventScript_Puzzle2Solved
	releaseall
	end

SteelMill_B1_EventScript_Puzzle2Solved::
	playse SE_SUCCESS
	waitse
	playse SE_TRUCK_DOOR
	setmetatile 50, 11, METATILE_Facility2_LabDoor_Open_Top, TRUE
	setmetatile 50, 12, METATILE_Facility2_LabDoor_Open, FALSE
	special DrawWholeMapView
	releaseall
	end

SteelMill_B1_EventScript_OffSwitch2::
	goto_if_lt VAR_TEMP_2, 99, SteelMill_B1_EventScript_Skip
	setvar VAR_TEMP_2, 0
	playse SE_PC_OFF
	waitse
	setmetatile 48, 15, METATILE_Facility2_MagnetSwitch_Off, FALSE
	special DrawWholeMapView
	end

SteelMill_B1_EventScript_OffSwitch3::
	goto_if_lt VAR_TEMP_3, 99, SteelMill_B1_EventScript_Skip
	setvar VAR_TEMP_3, 0
	playse SE_PC_OFF
	waitse
	setmetatile 49, 16, METATILE_Facility2_MagnetSwitch_Off, FALSE
	special DrawWholeMapView
	end

SteelMill_B1_EventScript_OffSwitch4::
	goto_if_lt VAR_TEMP_4, 99, SteelMill_B1_EventScript_Skip
	setvar VAR_TEMP_4, 0
	playse SE_PC_OFF
	waitse
	setmetatile 50, 17, METATILE_Facility2_MagnetSwitch_Off, FALSE
	special DrawWholeMapView
	end










SteelMill_B1_EventScript_Switch5::
	lockall
	setvar VAR_TEMP_5, 100
	playse SE_SWITCH
	waitse
	setmetatile 40, 3, METATILE_Facility2_MagnetSwitch_On, TRUE
	special DrawWholeMapView
	goto_if_eq VAR_TEMP_6, 100, SteelMill_B1_EventScript_CheckSwitch7
	releaseall
	end

SteelMill_B1_EventScript_CheckSwitch5::
	goto_if_eq VAR_TEMP_5, 100, SteelMill_B1_EventScript_Puzzle3Solved
	releaseall
	end

SteelMill_B1_EventScript_Switch6::
	lockall
	setvar VAR_TEMP_6, 100
	playse SE_SWITCH
	waitse
	setmetatile 41, 4, METATILE_Facility2_MagnetSwitch_On, TRUE
	special DrawWholeMapView
	goto_if_eq VAR_TEMP_7, 100, SteelMill_B1_EventScript_CheckSwitch5
	releaseall
	end

SteelMill_B1_EventScript_CheckSwitch6::
	goto_if_eq VAR_TEMP_6, 100, SteelMill_B1_EventScript_Puzzle3Solved
	releaseall
	end

SteelMill_B1_EventScript_Switch7::
	lockall
	setvar VAR_TEMP_7, 100
	playse SE_SWITCH
	waitse
	setmetatile 42, 3, METATILE_Facility2_MagnetSwitch_On, TRUE
	special DrawWholeMapView
	goto_if_eq VAR_TEMP_5, 100, SteelMill_B1_EventScript_CheckSwitch6
	releaseall
	end

SteelMill_B1_EventScript_CheckSwitch7::
	goto_if_eq VAR_TEMP_7, 100, SteelMill_B1_EventScript_Puzzle3Solved
	releaseall
	end

SteelMill_B1_EventScript_Puzzle3Solved::
	playse SE_SUCCESS
	waitse
	playse SE_TRUCK_DOOR
	setmetatile 39, 0, METATILE_Facility2_LabDoor_Open_Top, TRUE
	setmetatile 39, 1, METATILE_Facility2_LabDoor_Open, FALSE
	special DrawWholeMapView
	releaseall
	end

SteelMill_B1_EventScript_OffSwitch5::
	goto_if_lt VAR_TEMP_5, 99, SteelMill_B1_EventScript_Skip
	setvar VAR_TEMP_5, 0
	playse SE_PC_OFF
	waitse
	setmetatile 40, 3, METATILE_Facility2_MagnetSwitch_Off, FALSE
	special DrawWholeMapView
	end

SteelMill_B1_EventScript_OffSwitch6::
	goto_if_lt VAR_TEMP_6, 99, SteelMill_B1_EventScript_Skip
	setvar VAR_TEMP_6, 0
	playse SE_PC_OFF
	waitse
	setmetatile 41, 4, METATILE_Facility2_MagnetSwitch_Off, FALSE
	special DrawWholeMapView
	end

SteelMill_B1_EventScript_OffSwitch7::
	goto_if_lt VAR_TEMP_7, 99, SteelMill_B1_EventScript_Skip
	setvar VAR_TEMP_7, 0
	playse SE_PC_OFF
	waitse
	setmetatile 42, 3, METATILE_Facility2_MagnetSwitch_Off, FALSE
	special DrawWholeMapView
	end

SteelMill_B1_EventScript_Skip::
	end











SteelMill_B1_EventScript_Scientist::
	lock
	faceplayer
	msgbox SteelMill_B1_Text_MagnetSwitch, MSGBOX_DEFAULT
	release
	end

SteelMill_B1_Text_MagnetSwitch:
	.string "That device on the floor over there\n"
	.string "is a magnetic switch.\p"
	.string "Try moving a piece of metal onto it!\p"
	.string "You can also disengage the switch\n"
	.string "by pressing the A BUTTON.$"







SteelMill_B1_EventScript_VictiniDoorLock::
	lock
	msgbox SteelMill_B1_Text_NeedsCardKey, MSGBOX_SIGN
	goto_if_set FLAG_ITEM_STEEL_MILL_V_CARD, SteelMill_B1_EventScript_UnlockDoor
	release
	end

SteelMill_B1_EventScript_UnlockDoor::
	msgbox SteelMill_B1_Text_SwipeVCard, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, FALSE, SteelMill_B1_EventScript_Skip
	msgbox SteelMill_B1_Text_ScannedVCard, MSGBOX_DEFAULT
	call SteelMill_B1_EventScript_OpenVictiniDoor
	release
	end

SteelMill_B1_Text_NeedsCardKey:
	.string "It looks like a scanning machine\n"
	.string "of some kind.\p"
	.string "“Authorization required”$"

SteelMill_B1_Text_SwipeVCard:
	.string "Try using the V CARD?$"

SteelMill_B1_Text_ScannedVCard:
	.string "{PLAYER} scanned the V CARD.$"





SteelMill_B1_EventScript_Victini::
	lock
	playmoncry SPECIES_VICTINI, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_VICTINI, 50
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 1, 1, 1, 1, 1, 1
	special BattleSetup_StartLegendaryBattle
	waitstate
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_VICTINI
	setflag FLAG_BATTLED_VICTINI
	fadescreen FADE_FROM_BLACK
	release
	end


