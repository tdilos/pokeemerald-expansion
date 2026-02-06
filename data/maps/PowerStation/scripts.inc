.set LOCALID_GRUNT1, 6
.set LOCALID_GRUNT2, 7

PowerStation_MapScripts::
	.byte 0

PowerStation_EventScript_TV::
	lock
	faceplayer
	special GetWeekday
	goto_if_eq VAR_RESULT, 4, PowerStation_EventScript_TryRotomEncounter
	msgbox PowerStation_Text_BrokenTV, MSGBOX_DEFAULT
	closemessage
	release
	end

PowerStation_EventScript_TryRotomEncounter::
	goto_if_unset FLAG_DAILY_POWER_STATION_ROTOM, PowerStation_EventScript_RotomEncounter
	release
	end

PowerStation_EventScript_RotomEncounter::
	msgbox PowerStation_Text_BrokenTV, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 30	
	msgbox PowerStation_Text_PokemonInside, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_ROTOM, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_ROTOM, 15
	special BattleSetup_StartLegendaryBattle
	waitstate
	setflag FLAG_DAILY_POWER_STATION_ROTOM
	release
	end

PowerStation_Text_BrokenTV:
	.string "It's a broken television set.$"

PowerStation_Text_PokemonInside:
	.string "There's a POKéMON inside!\p"
	.string "The wild POKéMON attacked!$"

















PowerStation_EventScript_Hiram::
	trainerbattle_single TRAINER_HIRAM, PowerStation_Text_HiramIntro, PowerStation_Text_HiramDefeated
	msgbox PowerStation_Text_HiramPostBattle, MSGBOX_AUTOCLOSE
	end

PowerStation_EventScript_Chaim::
	trainerbattle_single TRAINER_CHAIM, PowerStation_Text_ChaimIntro, PowerStation_Text_ChaimDefeated
	msgbox PowerStation_Text_ChaimPostBattle, MSGBOX_AUTOCLOSE
	end

PowerStation_EventScript_Voltorb1::
	lock
	faceplayer
	setwildbattle SPECIES_VOLTORB, 10
	waitse
	playmoncry SPECIES_VOLTORB, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PowerStation_EventScript_DefeatedVoltorb1
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PowerStation_EventScript_DefeatedVoltorb1
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, PowerStation_EventScript_DefeatedVoltorb1
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PowerStation_EventScript_DefeatedVoltorb1
	setflag FLAG_HIDE_POWER_STATION_VOLTORB_1
	release
	end

PowerStation_EventScript_DefeatedVoltorb1::
	setflag FLAG_HIDE_POWER_STATION_VOLTORB_1
	goto Common_EventScript_RemoveStaticPokemon
	end

PowerStation_EventScript_Voltorb2::
	lock
	faceplayer
	setwildbattle SPECIES_VOLTORB, 10
	waitse
	playmoncry SPECIES_VOLTORB, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PowerStation_EventScript_DefeatedVoltorb2
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PowerStation_EventScript_DefeatedVoltorb2
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, PowerStation_EventScript_DefeatedVoltorb2
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PowerStation_EventScript_DefeatedVoltorb2
	setflag FLAG_HIDE_POWER_STATION_VOLTORB_2
	release
	end

PowerStation_EventScript_DefeatedVoltorb2::
	setflag FLAG_HIDE_POWER_STATION_VOLTORB_2
	goto Common_EventScript_RemoveStaticPokemon
	end

PowerStation_EventScript_Voltorb3::
	lock
	faceplayer
	setwildbattle SPECIES_VOLTORB, 10
	waitse
	playmoncry SPECIES_VOLTORB, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PowerStation_EventScript_DefeatedVoltorb3
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PowerStation_EventScript_DefeatedVoltorb3
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, PowerStation_EventScript_DefeatedVoltorb3
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PowerStation_EventScript_DefeatedVoltorb3
	setflag FLAG_HIDE_POWER_STATION_VOLTORB_3
	release
	end

PowerStation_EventScript_DefeatedVoltorb3::
	setflag FLAG_HIDE_POWER_STATION_VOLTORB_3
	goto Common_EventScript_RemoveStaticPokemon
	end

PowerStation_EventScript_Voltorb4::
	lock
	faceplayer
	setwildbattle SPECIES_VOLTORB, 10
	waitse
	playmoncry SPECIES_VOLTORB, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PowerStation_EventScript_DefeatedVoltorb4
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PowerStation_EventScript_DefeatedVoltorb4
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, PowerStation_EventScript_DefeatedVoltorb4
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PowerStation_EventScript_DefeatedVoltorb4
	setflag FLAG_HIDE_POWER_STATION_VOLTORB_4
	release
	end

PowerStation_EventScript_DefeatedVoltorb4::
	setflag FLAG_HIDE_POWER_STATION_VOLTORB_4
	goto Common_EventScript_RemoveStaticPokemon
	end











PowerStation_EventScript_GruntEncounter1::
	lockall
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, PowerStation_Movement_CameraPanUp
	waitmovement 0
	delay 50
	msgbox PowerStation_Text_Grunt1PreBattle1, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_GRUNT1, Common_Movement_FaceDown
	waitmovement 0
	applymovement LOCALID_GRUNT1, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	delay 30
	playbgm MUS_ENCOUNTER_MAGMA, TRUE
	msgbox PowerStation_Text_Grunt1PreBattle2, MSGBOX_DEFAULT
	closemessage
	setobjectxyperm LOCALID_GRUNT2, 18, 31
	setobjectmovementtype LOCALID_GRUNT2, MOVEMENT_TYPE_FACE_UP
	addobject LOCALID_GRUNT2
	applymovement OBJ_EVENT_ID_CAMERA, PowerStation_Movement_CameraPanDown
	waitmovement 0
	special RemoveCameraObject
	delay 30
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 30
	msgbox PowerStation_Text_Grunt2PreBattle, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_POWER_STATION_1, PowerStation_Text_Grunt1Defeated
	@playbgm MUS_ENCOUNTER_MAGMA, FALSE
	applymovement LOCALID_GRUNT1, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_GRUNT1, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_GRUNT1, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_GRUNT1, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_GRUNT1, Common_Movement_WalkDown
	waitmovement 0
	msgbox PowerStation_Text_YouIdiot, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_POWER_STATION_2, PowerStation_Text_Grunt2Defeated
	@playbgm MUS_ENCOUNTER_MAGMA, FALSE
	applymovement LOCALID_GRUNT1, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox PowerStation_Text_ScrewYouKid, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	@setflag FLAG_RECOVERED_MACHINE_PART
	removeobject LOCALID_GRUNT1
	removeobject LOCALID_GRUNT2
	savebgm MUS_DUMMY
	fadedefaultbgm
	fadescreen FADE_FROM_BLACK
	giveitem ITEM_MACHINE_PART
	setvar VAR_XANTHOS_CITY_STATE, 3
	releaseall
	end

PowerStation_EventScript_GruntEncounter2::
	lockall
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, PowerStation_Movement_CameraPanUp
	waitmovement 0
	delay 50
	msgbox PowerStation_Text_Grunt1PreBattle1, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_GRUNT1, Common_Movement_FaceDown
	waitmovement 0
	applymovement LOCALID_GRUNT1, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	delay 30
	playbgm MUS_ENCOUNTER_MAGMA, TRUE
	msgbox PowerStation_Text_Grunt1PreBattle2, MSGBOX_DEFAULT
	closemessage
	setobjectxyperm LOCALID_GRUNT2, 19, 31
	setobjectmovementtype LOCALID_GRUNT2, MOVEMENT_TYPE_FACE_UP
	addobject LOCALID_GRUNT2
	applymovement OBJ_EVENT_ID_CAMERA, PowerStation_Movement_CameraPanDown
	waitmovement 0
	special RemoveCameraObject
	delay 30
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 30
	msgbox PowerStation_Text_Grunt2PreBattle, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_POWER_STATION_1, PowerStation_Text_Grunt1Defeated
	@playbgm MUS_ENCOUNTER_MAGMA, FALSE
	applymovement LOCALID_GRUNT1, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_GRUNT1, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_GRUNT1, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_GRUNT1, Common_Movement_WalkDown
	waitmovement 0
	msgbox PowerStation_Text_YouIdiot, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_POWER_STATION_2, PowerStation_Text_Grunt2Defeated
	@playbgm MUS_ENCOUNTER_MAGMA, FALSE
	applymovement LOCALID_GRUNT1, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox PowerStation_Text_ScrewYouKid, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	@setflag FLAG_RECOVERED_MACHINE_PART
	removeobject LOCALID_GRUNT1
	removeobject LOCALID_GRUNT2
	savebgm MUS_DUMMY
	fadedefaultbgm
	fadescreen FADE_FROM_BLACK
	giveitem ITEM_MACHINE_PART
	setvar VAR_XANTHOS_CITY_STATE, 3
	releaseall
	end

PowerStation_EventScript_GruntEncounter3::
	lockall
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, PowerStation_Movement_CameraPanUp
	waitmovement 0
	delay 50
	msgbox PowerStation_Text_Grunt1PreBattle1, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_GRUNT1, Common_Movement_FaceDown
	waitmovement 0
	applymovement LOCALID_GRUNT1, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	delay 30
	playbgm MUS_ENCOUNTER_MAGMA, TRUE
	msgbox PowerStation_Text_Grunt1PreBattle2, MSGBOX_DEFAULT
	closemessage
	setobjectxyperm LOCALID_GRUNT2, 20, 31
	setobjectmovementtype LOCALID_GRUNT2, MOVEMENT_TYPE_FACE_UP
	addobject LOCALID_GRUNT2
	applymovement OBJ_EVENT_ID_CAMERA, PowerStation_Movement_CameraPanDown
	waitmovement 0
	special RemoveCameraObject
	delay 30
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 30
	msgbox PowerStation_Text_Grunt2PreBattle, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_POWER_STATION_1, PowerStation_Text_Grunt1Defeated
	@playbgm MUS_ENCOUNTER_MAGMA, FALSE
	applymovement LOCALID_GRUNT1, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_GRUNT1, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_GRUNT1, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_GRUNT1, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_GRUNT1, Common_Movement_WalkDown
	waitmovement 0
	msgbox PowerStation_Text_YouIdiot, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_POWER_STATION_2, PowerStation_Text_Grunt2Defeated
	@playbgm MUS_ENCOUNTER_MAGMA, FALSE
	applymovement LOCALID_GRUNT1, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox PowerStation_Text_ScrewYouKid, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	@setflag FLAG_RECOVERED_MACHINE_PART
	removeobject LOCALID_GRUNT1
	removeobject LOCALID_GRUNT2
	savebgm MUS_DUMMY
	fadedefaultbgm
	fadescreen FADE_FROM_BLACK
	giveitem ITEM_MACHINE_PART
	setvar VAR_XANTHOS_CITY_STATE, 3
	releaseall
	end

PowerStation_Movement_CameraPanDown:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PowerStation_Movement_CameraPanUp:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PowerStation_Text_Grunt1PreBattle1:
	.string "Let's see, the commander already left\n"
	.string "with the rare POKéMON.\p"
	.string "I just need to power these down and\n"
	.string "take out the MACHINE PART.\p"
	.string "That should be everything...$"

PowerStation_Text_Grunt1PreBattle2:
	.string "Where'd you come from? Nobody's supposed\n"
	.string "to know about this place but us!$"

PowerStation_Text_Grunt2PreBattle:
	.string "Hehe, you shouldn't have wandered\n"
	.string "in here all by yourself, kid.\p"
	.string "Did you really think we'd let you\n"
	.string "leave in one piece?$"

PowerStation_Text_Grunt1Defeated:
	.string "What?!$"

PowerStation_Text_YouIdiot:
	.string "You idiot! You can't even beat a kid?!\p"
	.string "Oh well, I'll just have to\n"
	.string "handle you myself.$"

PowerStation_Text_Grunt2Defeated:
	.string "No way!$"

PowerStation_Text_ScrewYouKid:
	.string "Ah screw you, kid!\p"
	.string "You want this MACHINE PART so bad,\n"
	.string "you can have it.\p"
	.string "We got everything we wanted here\n"
	.string "anyway.$"





