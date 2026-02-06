PokemonLaboratory_PuzzleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonLaboratory_PuzzleRoom_OnTransition
	.byte 0

PokemonLaboratory_PuzzleRoom_OnTransition::
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	setvar VAR_TEMP_5, 0
	setvar VAR_TEMP_6, 0
	end



PokemonLaboratory_PuzzleRoom_EventScript_Switch3::
	lockall
	@addvar NUM_SWITCHES_PRESSED, 1
	setvar VAR_TEMP_3, 100
	playse SE_SWITCH
	waitse
	setmetatile 1, 4, METATILE_Facility2_MagnetSwitch_On, TRUE
	special DrawWholeMapView
	goto_if_lt VAR_TEMP_4, 100, PokemonLaboratory_PuzzleRoom_EventScript_PuzzleIncomplete
	goto_if_lt VAR_TEMP_5, 100, PokemonLaboratory_PuzzleRoom_EventScript_PuzzleIncomplete
	goto_if_lt VAR_TEMP_6, 100, PokemonLaboratory_PuzzleRoom_EventScript_PuzzleIncomplete
	goto PokemonLaboratory_PuzzleRoom_EventScript_PuzzleSolved
	releaseall
	end

PokemonLaboratory_PuzzleRoom_EventScript_Switch4::
	lockall
	setvar VAR_TEMP_4, 100
	playse SE_SWITCH
	waitse
	setmetatile 1, 6, METATILE_Facility2_MagnetSwitch_On, TRUE
	special DrawWholeMapView
	goto_if_lt VAR_TEMP_3, 100, PokemonLaboratory_PuzzleRoom_EventScript_PuzzleIncomplete
	goto_if_lt VAR_TEMP_5, 100, PokemonLaboratory_PuzzleRoom_EventScript_PuzzleIncomplete
	goto_if_lt VAR_TEMP_6, 100, PokemonLaboratory_PuzzleRoom_EventScript_PuzzleIncomplete
	goto PokemonLaboratory_PuzzleRoom_EventScript_PuzzleSolved
	releaseall
	end

PokemonLaboratory_PuzzleRoom_EventScript_Switch5::
	lockall
	setvar VAR_TEMP_5, 100
	playse SE_SWITCH
	waitse
	setmetatile 2, 7, METATILE_Facility2_MagnetSwitch_On, TRUE
	special DrawWholeMapView
	goto_if_lt VAR_TEMP_3, 100, PokemonLaboratory_PuzzleRoom_EventScript_PuzzleIncomplete
	goto_if_lt VAR_TEMP_4, 100, PokemonLaboratory_PuzzleRoom_EventScript_PuzzleIncomplete
	goto_if_lt VAR_TEMP_6, 100, PokemonLaboratory_PuzzleRoom_EventScript_PuzzleIncomplete
	goto PokemonLaboratory_PuzzleRoom_EventScript_PuzzleSolved
	releaseall
	end

PokemonLaboratory_PuzzleRoom_EventScript_Switch6::
	lockall
	setvar VAR_TEMP_6, 100
	playse SE_SWITCH
	waitse
	setmetatile 3, 8, METATILE_Facility2_MagnetSwitch_On, TRUE
	special DrawWholeMapView
	goto_if_lt VAR_TEMP_3, 100, PokemonLaboratory_PuzzleRoom_EventScript_PuzzleIncomplete
	goto_if_lt VAR_TEMP_4, 100, PokemonLaboratory_PuzzleRoom_EventScript_PuzzleIncomplete
	goto_if_lt VAR_TEMP_5, 100, PokemonLaboratory_PuzzleRoom_EventScript_PuzzleIncomplete
	goto PokemonLaboratory_PuzzleRoom_EventScript_PuzzleSolved
	releaseall
	end

PokemonLaboratory_PuzzleRoom_EventScript_PuzzleIncomplete::
	releaseall
	end

PokemonLaboratory_PuzzleRoom_EventScript_PuzzleSolved::
	playse SE_SUCCESS
	waitse
	playse SE_TRUCK_DOOR
	setmetatile 3, 0, METATILE_Facility2_LabDoor_Open_Top, TRUE
	setmetatile 3, 1, METATILE_Facility2_LabDoor_Open, FALSE
	special DrawWholeMapView
	releaseall
	end

PokemonLaboratory_PuzzleRoom_EventScript_OffSwitch3::
	goto_if_lt VAR_TEMP_3, 99, PokemonLaboratory_PuzzleRoom_EventScript_Skip
	setvar VAR_TEMP_3, 0
	playse SE_PC_OFF
	waitse
	setmetatile 1, 4, METATILE_Facility2_MagnetSwitch_Off, FALSE
	special DrawWholeMapView
	end

PokemonLaboratory_PuzzleRoom_EventScript_OffSwitch4::
	goto_if_lt VAR_TEMP_4, 99, PokemonLaboratory_PuzzleRoom_EventScript_Skip
	setvar VAR_TEMP_4, 0
	playse SE_PC_OFF
	waitse
	setmetatile 1, 6, METATILE_Facility2_MagnetSwitch_Off, FALSE
	special DrawWholeMapView
	end

PokemonLaboratory_PuzzleRoom_EventScript_OffSwitch5::
	goto_if_lt VAR_TEMP_5, 99, PokemonLaboratory_PuzzleRoom_EventScript_Skip
	setvar VAR_TEMP_5, 0
	playse SE_PC_OFF
	waitse
	setmetatile 2, 7, METATILE_Facility2_MagnetSwitch_Off, FALSE
	special DrawWholeMapView
	end

PokemonLaboratory_PuzzleRoom_EventScript_OffSwitch6::
	goto_if_lt VAR_TEMP_6, 99, PokemonLaboratory_PuzzleRoom_EventScript_Skip
	setvar VAR_TEMP_6, 0
	playse SE_PC_OFF
	waitse
	setmetatile 3, 8, METATILE_Facility2_MagnetSwitch_Off, FALSE
	special DrawWholeMapView
	end

PokemonLaboratory_PuzzleRoom_EventScript_Skip::
	end



