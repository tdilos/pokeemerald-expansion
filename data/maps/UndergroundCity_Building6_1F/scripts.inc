UndergroundCity_Building6_1F_MapScripts::
	.byte 0

UndergroundCity_Building6_1F_EventScript_ToBoss::
	msgbox UndergroundCity_Building6_1F_Text_ToBoss, MSGBOX_SIGN
	end

UndergroundCity_Building6_1F_Text_ToBoss:
	.string "TO BOSS$"



UndergroundCity_Building6_1F_EventScript_Switch1::
	lockall
	@addvar NUM_SWITCHES_PRESSED, 1
	setvar VAR_TEMP_1, 100
	playse SE_SWITCH
	waitse
	setmetatile 31, 3, METATILE_Facility2_MagnetSwitch_On, TRUE
	special DrawWholeMapView
	goto_if_eq VAR_TEMP_2, 100, UndergroundCity_Building6_1F_EventScript_PuzzleSolved
	releaseall
	end

UndergroundCity_Building6_1F_EventScript_Switch2::
	lockall
	setvar VAR_TEMP_2, 100
	playse SE_SWITCH
	waitse
	setmetatile 31, 5, METATILE_Facility2_MagnetSwitch_On, TRUE
	special DrawWholeMapView
	goto_if_eq VAR_TEMP_1, 100, UndergroundCity_Building6_1F_EventScript_PuzzleSolved
	releaseall
	end

UndergroundCity_Building6_1F_EventScript_PuzzleSolved::
	playse SE_SUCCESS
	waitse
	playse SE_TRUCK_DOOR
	setmetatile 29, 0, METATILE_Facility2_LabDoor_Open_Top, TRUE
	setmetatile 29, 1, METATILE_Facility2_LabDoor_Open, FALSE
	special DrawWholeMapView
	releaseall
	end

UndergroundCity_Building6_1F_EventScript_OffSwitch1::
	goto_if_lt VAR_TEMP_1, 99, UndergroundCity_Building6_1F_EventScript_Skip
	setvar VAR_TEMP_1, 0
	playse SE_PC_OFF
	waitse
	setmetatile 31, 3, METATILE_Facility2_MagnetSwitch_Off, FALSE
	special DrawWholeMapView
	end

UndergroundCity_Building6_1F_EventScript_OffSwitch2::
	goto_if_lt VAR_TEMP_2, 99, UndergroundCity_Building6_1F_EventScript_Skip
	setvar VAR_TEMP_2, 0
	playse SE_PC_OFF
	waitse
	setmetatile 31, 5, METATILE_Facility2_MagnetSwitch_Off, FALSE
	special DrawWholeMapView
	end

UndergroundCity_Building6_1F_EventScript_Skip::
	end


