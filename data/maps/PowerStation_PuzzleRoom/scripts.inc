PowerStation_PuzzleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PowerStation_PuzzleRoom_OnTransition
	.byte 0

PowerStation_PuzzleRoom_OnTransition::
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	end



PowerStation_PuzzleRoom_EventScript_Switch1::
	lockall
	setvar VAR_TEMP_1, 100
	playse SE_SWITCH
	waitse
	setmetatile 1, 6, METATILE_BikeShop_MagnetSwitch_On, TRUE
	special DrawWholeMapView
	goto_if_eq VAR_TEMP_2, 100, PowerStation_PuzzleRoom_EventScript_CheckSwitch3
	releaseall
	end

PowerStation_PuzzleRoom_EventScript_CheckSwitch1::
	goto_if_eq VAR_TEMP_1, 100, PowerStation_PuzzleRoom_EventScript_PuzzleSolved
	releaseall
	end

PowerStation_PuzzleRoom_EventScript_Switch2::
	lockall
	setvar VAR_TEMP_2, 100
	playse SE_SWITCH
	waitse
	setmetatile 2, 7, METATILE_BikeShop_MagnetSwitch_On, TRUE
	special DrawWholeMapView
	goto_if_eq VAR_TEMP_3, 100, PowerStation_PuzzleRoom_EventScript_CheckSwitch1
	releaseall
	end

PowerStation_PuzzleRoom_EventScript_CheckSwitch2::
	goto_if_eq VAR_TEMP_2, 100, PowerStation_PuzzleRoom_EventScript_PuzzleSolved
	releaseall
	end

PowerStation_PuzzleRoom_EventScript_Switch3::
	lockall
	setvar VAR_TEMP_3, 100
	playse SE_SWITCH
	waitse
	setmetatile 3, 7, METATILE_BikeShop_MagnetSwitch_On, TRUE
	special DrawWholeMapView
	goto_if_eq VAR_TEMP_1, 100, PowerStation_PuzzleRoom_EventScript_CheckSwitch2
	releaseall
	end

PowerStation_PuzzleRoom_EventScript_CheckSwitch3::
	goto_if_eq VAR_TEMP_3, 100, PowerStation_PuzzleRoom_EventScript_PuzzleSolved
	releaseall
	end

PowerStation_PuzzleRoom_EventScript_PuzzleSolved::
	playse SE_SUCCESS
	waitse
	playse SE_TRUCK_DOOR
	setmetatile 3, 0, METATILE_BikeShop_StationDoor_Open_Top, TRUE
	setmetatile 3, 1, METATILE_BikeShop_StationDoor_Open, FALSE
	special DrawWholeMapView
	releaseall
	end

PowerStation_PuzzleRoom_EventScript_OffSwitch1::
	goto_if_lt VAR_TEMP_1, 99, PowerStation_PuzzleRoom_EventScript_Skip
	setvar VAR_TEMP_1, 0
	playse SE_PC_OFF
	waitse
	setmetatile 1, 6, METATILE_BikeShop_MagnetSwitch_Off, FALSE
	special DrawWholeMapView
	end

PowerStation_PuzzleRoom_EventScript_OffSwitch2::
	goto_if_lt VAR_TEMP_2, 99, PowerStation_PuzzleRoom_EventScript_Skip
	setvar VAR_TEMP_2, 0
	playse SE_PC_OFF
	waitse
	setmetatile 2, 7, METATILE_BikeShop_MagnetSwitch_Off, FALSE
	special DrawWholeMapView
	end

PowerStation_PuzzleRoom_EventScript_OffSwitch3::
	goto_if_lt VAR_TEMP_3, 99, PowerStation_PuzzleRoom_EventScript_Skip
	setvar VAR_TEMP_3, 0
	playse SE_PC_OFF
	waitse
	setmetatile 3, 7, METATILE_BikeShop_MagnetSwitch_Off, FALSE
	special DrawWholeMapView
	end

PowerStation_PuzzleRoom_EventScript_Skip::
	end


