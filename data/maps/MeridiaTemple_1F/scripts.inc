.set LOCALID_BOULDER1, 1
.set LOCALID_BOULDER2, 2
.set LOCALID_BOULDER3, 3
.set LOCALID_BOULDER4, 4
.set LOCALID_BOULDER5, 5
.set LOCALID_BOULDER6, 6
.set LOCALID_BOULDER7, 7
.set LOCALID_BOULDER8, 8

.equ NUM_SWITCHES_PRESSED, VAR_TEMP_9

MeridiaTemple_1F_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MeridiaTemple_1F_OnWarp
	map_script MAP_SCRIPT_ON_TRANSITION, MeridiaTemple_1F_OnTransition
	.byte 0

MeridiaTemple_1F_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, MeridiaTemple_1F_EventScript_SetForceOffscreenLoad
	.2byte 0

MeridiaTemple_1F_EventScript_SetForceOffscreenLoad::
	setflag FLAG_FORCE_LOAD_OFFSCREEN_OBJEV
	end


MeridiaTemple_1F_EventScript_BraileInscription::
	lockall
	braillemsgbox IsshoTemple_Braille_GatherTheStones
	releaseall
	end





MeridiaTemple_1F_OnTransition::
	@setworldmapflag FLAG_WORLD_MAP_SEVEN_ISLAND_SEVAULT_CANYON_TANOBY_KEY
	call_if_set FLAG_SYS_SOLVED_MERIDIA_TEMPLE, MeridiaTemple_1F_EventScript_MoveBouldersToSolvedPos
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

MeridiaTemple_1F_EventScript_MoveBouldersToSolvedPos::
	setobjectxyperm LOCALID_BOULDER1, 10, 10
	setobjectxyperm LOCALID_BOULDER2, 12, 10
	setobjectxyperm LOCALID_BOULDER3, 14, 10
	setobjectxyperm LOCALID_BOULDER4, 10, 12
	setobjectxyperm LOCALID_BOULDER5, 14, 12
	setobjectxyperm LOCALID_BOULDER6, 10, 14
	setobjectxyperm LOCALID_BOULDER7, 12, 14
	setobjectxyperm LOCALID_BOULDER8, 14, 14
	return

MeridiaTemple_1F_EventScript_Switch1::
	lockall
	goto_if_eq VAR_TEMP_1, 100, MeridiaTemple_1F_EventScript_SwitchAlreadyPressed
	call MeridiaTemple_1F_EventScript_SwitchPressed
	setvar VAR_TEMP_1, 100
	@setmetatile 10, 10, METATILE_MirageTower_MeridiaTempleSwitch, TRUE
	goto_if_eq NUM_SWITCHES_PRESSED, 8, MeridiaTemple_1F_EventScript_PuzzleSolved
	releaseall
	end

MeridiaTemple_1F_EventScript_Switch2::
	lockall
	goto_if_eq VAR_TEMP_2, 100, MeridiaTemple_1F_EventScript_SwitchAlreadyPressed
	call MeridiaTemple_1F_EventScript_SwitchPressed
	setvar VAR_TEMP_2, 100
	@setmetatile 12, 10, METATILE_MirageTower_MeridiaTempleSwitch, TRUE
	goto_if_eq NUM_SWITCHES_PRESSED, 8, MeridiaTemple_1F_EventScript_PuzzleSolved
	releaseall
	end

MeridiaTemple_1F_EventScript_Switch3::
	lockall
	goto_if_eq VAR_TEMP_3, 100, MeridiaTemple_1F_EventScript_SwitchAlreadyPressed
	call MeridiaTemple_1F_EventScript_SwitchPressed
	setvar VAR_TEMP_3, 100
	@setmetatile 14, 10, METATILE_MirageTower_MeridiaTempleSwitch, TRUE
	goto_if_eq NUM_SWITCHES_PRESSED, 8, MeridiaTemple_1F_EventScript_PuzzleSolved
	releaseall
	end

MeridiaTemple_1F_EventScript_Switch4::
	lockall
	goto_if_eq VAR_TEMP_4, 100, MeridiaTemple_1F_EventScript_SwitchAlreadyPressed
	call MeridiaTemple_1F_EventScript_SwitchPressed
	setvar VAR_TEMP_4, 100
	@setmetatile 10, 12, METATILE_MirageTower_MeridiaTempleSwitch, TRUE
	goto_if_eq NUM_SWITCHES_PRESSED, 8, MeridiaTemple_1F_EventScript_PuzzleSolved
	releaseall
	end

MeridiaTemple_1F_EventScript_Switch5::
	lockall
	goto_if_eq VAR_TEMP_5, 100, MeridiaTemple_1F_EventScript_SwitchAlreadyPressed
	call MeridiaTemple_1F_EventScript_SwitchPressed
	setvar VAR_TEMP_5, 100
	@setmetatile 14, 12, METATILE_MirageTower_MeridiaTempleSwitch, TRUE
	goto_if_eq NUM_SWITCHES_PRESSED, 8, MeridiaTemple_1F_EventScript_PuzzleSolved
	releaseall
	end

MeridiaTemple_1F_EventScript_Switch6::
	lockall
	goto_if_eq VAR_TEMP_6, 100, MeridiaTemple_1F_EventScript_SwitchAlreadyPressed
	call MeridiaTemple_1F_EventScript_SwitchPressed
	setvar VAR_TEMP_6, 100
	@setmetatile 10, 14, METATILE_MirageTower_MeridiaTempleSwitch, TRUE
	goto_if_eq NUM_SWITCHES_PRESSED, 8, MeridiaTemple_1F_EventScript_PuzzleSolved
	releaseall
	end

MeridiaTemple_1F_EventScript_Switch7::
	lockall
	goto_if_eq VAR_TEMP_7, 100, MeridiaTemple_1F_EventScript_SwitchAlreadyPressed
	call MeridiaTemple_1F_EventScript_SwitchPressed
	setvar VAR_TEMP_7, 100
	@setmetatile 12, 14, METATILE_MirageTower_MeridiaTempleSwitch, TRUE
	goto_if_eq NUM_SWITCHES_PRESSED, 8, MeridiaTemple_1F_EventScript_PuzzleSolved
	releaseall
	end

MeridiaTemple_1F_EventScript_Switch8::
	lockall
	goto_if_eq VAR_TEMP_8, 100, MeridiaTemple_1F_EventScript_SwitchAlreadyPressed
	call MeridiaTemple_1F_EventScript_SwitchPressed
	setvar VAR_TEMP_8, 100
	@setmetatile 14, 14, METATILE_MirageTower_MeridiaTempleSwitch, TRUE
	goto_if_eq NUM_SWITCHES_PRESSED, 8, MeridiaTemple_1F_EventScript_PuzzleSolved
	releaseall
	end

MeridiaTemple_1F_EventScript_SwitchPressed::
	addvar NUM_SWITCHES_PRESSED, 1
	@playse SE_SWITCH
	setvar VAR_0x8004, 1 @ vertical pan
	setvar VAR_0x8005, 1 @ horizontal pan
	setvar VAR_0x8006, 8 @ num shakes
	setvar VAR_0x8007, 3 @ shake delay
	special ShakeCamera
	delay 60
	return


	 
	

MeridiaTemple_1F_EventScript_SwitchAlreadyPressed::
	releaseall
	end

MeridiaTemple_1F_EventScript_PuzzleSolved::
	fadeoutbgm 0
	playse SE_M_CHARGE
	fadescreen FADE_TO_WHITE
	waitse
	playmoncry SPECIES_TORNADUS, CRY_MODE_NORMAL
	msgbox MeridiaTemple_1F_Text_MysteriousFlightFarAway, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 0 @Tornadus
	special InitRoamer
	setflag FLAG_SYS_SOLVED_MERIDIA_TEMPLE
	fadescreen FADE_FROM_WHITE
	delay 60
	fadeinbgm 0
	releaseall
	end

MeridiaTemple_1F_Text_MysteriousFlightFarAway:
	.string "It sounded like a POKéMON taking flight\n"
	.string "from somewhere far away.$"
