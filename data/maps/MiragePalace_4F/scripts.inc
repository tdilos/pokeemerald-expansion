.equ NUM_SWITCHES_PRESSED, VAR_TEMP_9

MiragePalace_4F_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MiragePalace_4F_OnWarp
	map_script MAP_SCRIPT_ON_TRANSITION, MiragePalace_4F_OnTransition
	.byte 0

MiragePalace_4F_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, MiragePalace_4F_EventScript_SetForceOffscreenLoad
	.2byte 0

MiragePalace_4F_EventScript_SetForceOffscreenLoad::
	setflag FLAG_FORCE_LOAD_OFFSCREEN_OBJEV
	end

MiragePalace_4F_OnTransition::
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	setvar VAR_TEMP_5, 0
	setvar VAR_TEMP_6, 0
	setvar VAR_TEMP_7, 0
	setvar VAR_TEMP_8, 0
	setvar NUM_SWITCHES_PRESSED, 0
	end

MiragePalace_4F_EventScript_Switch1::
	lockall
	goto_if_eq VAR_TEMP_1, 100, MiragePalace_4F_EventScript_SwitchAlreadyPressed
	call MiragePalace_4F_EventScript_SwitchPressed
	setvar VAR_TEMP_1, 100
	goto_if_eq NUM_SWITCHES_PRESSED, 8, MiragePalace_4F_EventScript_PuzzleSolved
	releaseall
	end

MiragePalace_4F_EventScript_Switch2::
	lockall
	goto_if_eq VAR_TEMP_2, 100, MiragePalace_4F_EventScript_SwitchAlreadyPressed
	call MiragePalace_4F_EventScript_SwitchPressed
	setvar VAR_TEMP_2, 100
	goto_if_eq NUM_SWITCHES_PRESSED, 8, MiragePalace_4F_EventScript_PuzzleSolved
	releaseall
	end

MiragePalace_4F_EventScript_Switch3::
	lockall
	goto_if_eq VAR_TEMP_3, 100, MiragePalace_4F_EventScript_SwitchAlreadyPressed
	call MiragePalace_4F_EventScript_SwitchPressed
	setvar VAR_TEMP_3, 100
	goto_if_eq NUM_SWITCHES_PRESSED, 8, MiragePalace_4F_EventScript_PuzzleSolved
	releaseall
	end

MiragePalace_4F_EventScript_Switch4::
	lockall
	goto_if_eq VAR_TEMP_4, 100, MiragePalace_4F_EventScript_SwitchAlreadyPressed
	call MiragePalace_4F_EventScript_SwitchPressed
	setvar VAR_TEMP_4, 100
	goto_if_eq NUM_SWITCHES_PRESSED, 8, MiragePalace_4F_EventScript_PuzzleSolved
	releaseall
	end

MiragePalace_4F_EventScript_Switch5::
	lockall
	goto_if_eq VAR_TEMP_5, 100, MiragePalace_4F_EventScript_SwitchAlreadyPressed
	call MiragePalace_4F_EventScript_SwitchPressed
	setvar VAR_TEMP_5, 100
	goto_if_eq NUM_SWITCHES_PRESSED, 8, MiragePalace_4F_EventScript_PuzzleSolved
	releaseall
	end

MiragePalace_4F_EventScript_Switch6::
	lockall
	goto_if_eq VAR_TEMP_6, 100, MiragePalace_4F_EventScript_SwitchAlreadyPressed
	call MiragePalace_4F_EventScript_SwitchPressed
	setvar VAR_TEMP_6, 100
	goto_if_eq NUM_SWITCHES_PRESSED, 8, MiragePalace_4F_EventScript_PuzzleSolved
	releaseall
	end

MiragePalace_4F_EventScript_Switch7::
	lockall
	goto_if_eq VAR_TEMP_7, 100, MiragePalace_4F_EventScript_SwitchAlreadyPressed
	call MiragePalace_4F_EventScript_SwitchPressed
	setvar VAR_TEMP_7, 100
	goto_if_eq NUM_SWITCHES_PRESSED, 8, MiragePalace_4F_EventScript_PuzzleSolved
	releaseall
	end

MiragePalace_4F_EventScript_Switch8::
	lockall
	goto_if_eq VAR_TEMP_8, 100, MiragePalace_4F_EventScript_SwitchAlreadyPressed
	call MiragePalace_4F_EventScript_SwitchPressed
	setvar VAR_TEMP_8, 100
	goto_if_eq NUM_SWITCHES_PRESSED, 8, MiragePalace_4F_EventScript_PuzzleSolved
	releaseall
	end





MiragePalace_4F_EventScript_SwitchPressed::
	addvar NUM_SWITCHES_PRESSED, 1
	setvar VAR_0x8004, 1 @ vertical pan
	setvar VAR_0x8005, 1 @ horizontal pan
	setvar VAR_0x8006, 8 @ num shakes
	setvar VAR_0x8007, 3 @ shake delay
	special ShakeCamera
	delay 60
	return

MiragePalace_4F_EventScript_SwitchAlreadyPressed::
	releaseall
	end

MiragePalace_4F_EventScript_PuzzleSolved::
	playse SE_ORB
	fadescreen FADE_TO_WHITE
	waitse
	fadescreen FADE_FROM_WHITE
	delay 60
	goto MiragePalace_4F_EventScript_WarpToFifthFloor
	releaseall
	end

MiragePalace_4F_EventScript_WarpToFifthFloor::
	warpsilent MAP_MIRAGE_PALACE_5F, 3, 6
	waitstate
	releaseall
	end
