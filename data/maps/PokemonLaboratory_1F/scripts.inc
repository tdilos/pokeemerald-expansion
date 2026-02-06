.set LOCALID_JACE, 4

PokemonLaboratory_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonLaboratory_1F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLaboratory_1F_OnWarp
	.byte 0

PokemonLaboratory_1F_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, PokemonLaboratory_1F_EventScript_SetForceOffscreenLoad
	.2byte 0

PokemonLaboratory_1F_EventScript_SetForceOffscreenLoad::
	setflag FLAG_FORCE_LOAD_OFFSCREEN_OBJEV
	end



PokemonLaboratory_1F_OnTransition:
	call_if_eq VAR_WISTERIA_CITY_STATE, 2, PokemonLaboratory_1F_EventScript_AddJace
	call_if_ge VAR_WISTERIA_CITY_STATE, 3, PokemonLaboratory_1F_EventScript_RemoveJace
	end

PokemonLaboratory_1F_EventScript_AddJace:
	clearflag FLAG_HIDE_JACE
	addobject LOCALID_JACE
	return

PokemonLaboratory_1F_EventScript_RemoveJace:
	setflag FLAG_HIDE_JACE
	removeobject LOCALID_JACE
	return






PokemonLaboratory_1F_EventScript_Jace::
	lock
	faceplayer
	msgbox PokemonLaboratory_1F_Text_SearchForClues, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLaboratory_1F_Text_SearchForClues:
	.string "JACE: Keep an eye out for clues.\p"
	.string "I'm sure there's something here that\n"
	.string "we can bring back to JUSTIN.$"







PokemonLaboratory_1F_EventScript_CutsceneTrigger::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	delay 60
	call PokemonLaboratory_1F_EventScript_RemoveJace
	setobjectxyperm LOCALID_JACE, 10, 10
	clearflag FLAG_HIDE_JACE
	addobject LOCALID_JACE
	applymovement LOCALID_JACE, PokemonLaboratory_1F_Movement_JaceWalkToPlayer
	waitmovement 0
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	msgbox PokemonLaboratory_1F_Text_JaceGoodJob, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JACE, PokemonLaboratory_1F_Movement_JaceWalkToStairs
	@waitmovement 0
	delay 40
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	@waitmovement 0
	delay 40
	call PokemonLaboratory_1F_EventScript_RemoveJace
	playse SE_EXIT
	waitse
	setvar VAR_WISTERIA_CITY_STATE, 3
	delay 30
	release
	end

PokemonLaboratory_1F_Text_JaceGoodJob:
	.string "JACE: A hidden staircase.\n"
	.string "Good catch, {PLAYER}.\p"
	.string "I'll bet there's something important\n"
	.string "hidden down there.$"

PokemonLaboratory_1F_Movement_JaceWalkToPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLaboratory_1F_Movement_JaceWalkToStairs:
	walk_left
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	step_end












PokemonLaboratory_EventScript_Log1::
	msgbox PokemonLaboratory_Text_Log1, MSGBOX_DEFAULT
	closemessage
	end

PokemonLaboratory_Text_Log1:
	.string "PROJECT ALDMANN LOGBOOK\n" 
	.string "ENTRY 1\p" 
	.string "The POKéMON MEW was transferred\n"
	.string "to our facility today.\p"
	.string "Once thought to be only a myth, it\n"
	.string "will prove invaluable to our work.\p"
	.string "DNA samples have been collected\n"
	.string "and are undergoing analysis.$"


PokemonLaboratory_EventScript_Log2::
	msgbox PokemonLaboratory_Text_Log2, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_MEW, CRY_MODE_NORMAL
	@waitmoncry
	setvar VAR_0x8004, SPECIES_MEW
	special SetSeenMon
	showmonpic SPECIES_MEW, 10, 3
	@playmoncry SPECIES_MEW, CRY_MODE_NORMAL
	waitbuttonpress
	hidemonpic
	release
	end

PokemonLaboratory_Text_Log2:
	.string "PROJECT ALDMANN LOGBOOK\n" 
	.string "ENTRY 7\p" 
	.string "We have run a complete diagnostic\n"
	.string "of the POKéMON MEW.\p"
	.string "Our findings are summarized below.$"

@PokemonLaboratory_EventScript_Log3::
@	msgbox PokemonLaboratory_Text_Log3, MSGBOX_DEFAULT
@	closemessage
@	end

@PokemonLaboratory_Text_Log3:
@	.string "PROJECT ALDMANN LOGBOOK\n" 
@	.string "ENTRY 12\p" 
@	.string "MEW'S unique cells \p"
@	.string "We hypothesize that\p"
@	.string "Further testing is required to confirm this.$"




