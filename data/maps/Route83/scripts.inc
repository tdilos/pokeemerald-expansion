.set LOCALID_GRUNT, 4
.set LOCALID_WORKER, 5
.set LOCALID_JACE, 6

Route83_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route83_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route83_OnLoad
	.byte 0

Route83_OnLoad:
	call_if_eq VAR_XANTHOS_CITY_STATE, 2, Route83_EventScript_InitializeWorker
	end




Route83_OnTransition:
	@removeobject LOCALID_JACE
	@removeobject LOCALID_WORKER
	@removeobject LOCALID_GRUNT
	@setflag FLAG_HIDE_JACE
	@setflag FLAG_ROUTE83_HIDE_WORKER
	@setflag FLAG_ROUTE83_HIDE_GRUNT
	call_if_eq VAR_XANTHOS_CITY_STATE, 1, Route83_EventScript_InitializeRobbery
	@goto_if_set FLAG_RESCUED_HEADBUTT_TUTOR, CinerousTown_EventScript_PostTutorRescue
	@goto_if_set FLAG_BATTLED_OPC_CINEROUS_TOWN, CinerousTown_EventScript_MoveOPCToGate
	call_if_eq VAR_XANTHOS_CITY_STATE, 2, Route83_EventScript_InitializeWorker
	call_if_eq VAR_XANTHOS_CITY_STATE, 3, Route83_EventScript_InitializeWorker
	@call_if_ge VAR_XANTHOS_CITY_STATE, 3, Route83_EventScript_HideWorker
	call_if_set FLAG_BADGE02_GET, Route83_EventScript_InitializeJace
	call_if_ge VAR_JACE_STATE, 2, Route83_EventScript_HideJace
	end

Route83_EventScript_InitializeRobbery:
	setflag FLAG_HIDE_JACE
	setflag FLAG_ROUTE83_HIDE_WORKER
	setflag FLAG_ROUTE83_HIDE_GRUNT
	return

Route83_EventScript_InitializeJace:
	@setobjectxyperm LOCALID_WORKER, 6, 8
	@setobjectmovementtype LOCALID_WORKER, MOVEMENT_TYPE_FACE_DOWN
	@addobject LOCALID_JACE
	clearflag FLAG_HIDE_JACE
	return

Route83_EventScript_HideJace:
	@removeobject LOCALID_JACE
	setflag FLAG_HIDE_JACE
	return

Route83_EventScript_InitializeWorker:
	@setvar VAR_CINEROUS_TOWN_STATE, 1
	setobjectxyperm LOCALID_WORKER, 8, 9
	setobjectmovementtype LOCALID_WORKER, MOVEMENT_TYPE_FACE_DOWN
	@removeobject LOCALID_WORKER
	clearflag FLAG_ROUTE83_HIDE_WORKER
	addobject LOCALID_WORKER
	return

Route83_EventScript_HideWorker:
	@removeobject LOCALID_JACE
	setflag FLAG_ROUTE83_HIDE_WORKER
	return



Route83_EventScript_Caitlyn::
	trainerbattle_single TRAINER_CAITLYN, Route83_Text_CaitlynIntro, Route83_Text_CaitlynDefeated
	msgbox Route83_Text_CaitlynPostBattle, MSGBOX_AUTOCLOSE
	end

Route83_EventScript_RouteSign::
	msgbox Route83_Text_RouteSign, MSGBOX_SIGN
	end

Route83_Text_RouteSign:
	.string "ROUTE 83\p"
	.string "{LEFT_ARROW} XANTHOS CITY\n"
	.string "{RIGHT_ARROW} RESEDA WOODS$"

Route83_EventScript_TrainerTipsEXP::
	msgbox Route83_Text_TrainerTipsEXP, MSGBOX_SIGN
	end

Route83_Text_TrainerTipsEXP:
	.string "TRAINER TIPS\p"
	.string "POKéMON earn more experience from\n"
	.string "battling higher leveled foes.$"





Route83_Movement_GruntRunsAway:
	@delay_16
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route83_Movement_WalkToWorker0:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route83_EventScript_Robbery0::
	lockall
	playse SE_DOOR
	@call Route83_EventScript_MoveGruntToDoor
	@waitse
	@applymovement LOCALID_GRUNT, Route83_Movement_GruntRunsAway
	@waitmovement 0
	@setobjectxyperm LOCALID_GRUNT, 10, 0
	@setobjectmovementtype LOCALID_GRUNT, MOVEMENT_TYPE_FACE_DOWN
	addobject LOCALID_GRUNT
	delay 16
	applymovement LOCALID_GRUNT, Route83_Movement_GruntRunsAway
	delay 60
	playse SE_DOOR
	@call Route83_EventScript_MoveWorkerToDoor
	setobjectxyperm LOCALID_WORKER, 8, 8
	setobjectmovementtype LOCALID_WORKER, MOVEMENT_TYPE_FACE_DOWN
	addobject LOCALID_WORKER
	@waitse
	delay 16
	applymovement LOCALID_WORKER, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_WORKER, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_WORKER, Common_Movement_FaceRight
	waitmovement 0
	@delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Route83_Movement_WalkToWorker0
	waitmovement 0
	@applymovement LOCALID_WORKER, Common_Movement_FaceDown
	@waitmovement 0
	removeobject LOCALID_GRUNT
	goto Route83_EventScript_DuringRobbery
	end

Route83_Movement_WalkToWorker1:
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

Route83_EventScript_Robbery1::
	lockall
	playse SE_DOOR
	@call Route83_EventScript_MoveGruntToDoor
	@waitse
	@applymovement LOCALID_GRUNT, Route83_Movement_GruntRunsAway
	@waitmovement 0
	@setobjectxyperm LOCALID_GRUNT, 10, 0
	@setobjectmovementtype LOCALID_GRUNT, MOVEMENT_TYPE_FACE_DOWN
	addobject LOCALID_GRUNT
	delay 16
	applymovement LOCALID_GRUNT, Route83_Movement_GruntRunsAway
	delay 60
	playse SE_DOOR
	@call Route83_EventScript_MoveWorkerToDoor
	setobjectxyperm LOCALID_WORKER, 8, 8
	setobjectmovementtype LOCALID_WORKER, MOVEMENT_TYPE_FACE_DOWN
	addobject LOCALID_WORKER
	@waitse
	delay 16
	applymovement LOCALID_WORKER, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_WORKER, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_WORKER, Common_Movement_FaceRight
	waitmovement 0
	@delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Route83_Movement_WalkToWorker1
	waitmovement 0
	@applymovement LOCALID_WORKER, Common_Movement_FaceDown
	@waitmovement 0
	@removeobject LOCALID_GRUNT
	goto Route83_EventScript_DuringRobbery
	end


Route83_EventScript_Worker::
	lockall
	faceplayer
	checkitem ITEM_MACHINE_PART
	goto_if_eq VAR_RESULT, TRUE, Route83_EventScript_ReturnMachinePart
	@goto_if_eq VAR_XANTHOS_CITY_STATE, 1, Route83_EventScript_DuringRobbery
	goto_if_ge VAR_XANTHOS_CITY_STATE, 2, Route83_EventScript_AfterRobbery
	end

Route83_EventScript_DuringRobbery::
	applymovement LOCALID_WORKER, Common_Movement_FaceLeft
	waitmovement 0
	delay 20
	msgbox Route83_Text_Terrible, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WORKER, Common_Movement_FaceRight
	waitmovement 0
	delay 48
	applymovement LOCALID_WORKER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox Route83_Text_HeadedToResedaWoods, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_WORKER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_WORKER, Common_Movement_FaceDown
	waitmovement 0
	msgbox Route83_Text_PleaseHelp, MSGBOX_DEFAULT
	closemessage
	setvar VAR_XANTHOS_CITY_STATE, 2
	removeobject LOCALID_GRUNT
	call Route83_EventScript_InitializeWorker
	@questmenu QUEST_MENU_UNLOCK_QUEST QUEST_9
	@openquestmenu
	startquest QUEST_9
	releaseall
	end

Route83_EventScript_AfterRobbery::
	msgbox Route83_Text_PleaseHelp, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Route83_Text_Terrible:
	.string "Oh, it's terrible. Those thugs stole a\n"
	.string "part we need for the generators.\l"
	.string "We can't produce electricity without it!\p"
	.string "You're a trainer, right? You have to help\n"
	.string "us get that machine part back!\p"
	.string "I would go myself if I had any POKéMON.$"

Route83_Text_HeadedToResedaWoods:
	.string "Those men looked like they were\n"
	.string "heading for RESEDA WOODS.$"

Route83_Text_PleaseHelp:
	.string "Please help!\p"
	.string "If we don't get that part back, all of\n"
	.string "XANTHOS CITY will be without power!$"

Route83_EventScript_ReturnMachinePart::
	applymovement LOCALID_WORKER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	delay 60
	msgbox Route83_Text_OhThatsTheMachinePart, MSGBOX_DEFAULT
	removeitem ITEM_MACHINE_PART
	msgbox Route83_Text_HandedOverTheMachinePart, MSGBOX_DEFAULT
	waitfanfare
	delay 40
	msgbox Route83_Text_ThanksToYou, MSGBOX_NPC
	giveitem ITEM_TM72
	closemessage
	applymovement LOCALID_WORKER, Common_Movement_FaceUp
	waitmovement 0
	playse SE_DOOR
	@setflag FLAG_RECEIVED_TM72
	@removeobject LOCALID_WORKER
	delay 32
	removeobject LOCALID_WORKER
	setvar VAR_XANTHOS_CITY_STATE, 4
	@questmenu QUEST_MENU_COMPLETE_QUEST QUEST_9
	completequest QUEST_9
	release
	end

Route83_Text_OhThatsTheMachinePart:
	.string "Oh! That's the MACHINE PART that\n"
	.string "was stolen!\p"
	.string "You found it! How wonderful!$"
	
Route83_Text_HandedOverTheMachinePart:
	.string "{PLAYER} handed over the MACHINE PART.$"

Route83_Text_ThanksToYou:
	.string "Thanks to you, we'll be able to\n"
	.string "provide power to the city!\p"
	.string "I have to thank you somehow.\p"
	.string "Here, you can have this.$"




Route83_EventScript_SkipJaceTrigger::
	releaseall
	end

Route83_EventScript_JaceTrigger1::
	lockall
	goto_if_unset FLAG_DEFEATED_AMBER_GYM, Route83_EventScript_SkipJaceTrigger
	@goto_if_unset FLAG_BATTLED_JACE_ROUTE_83, Route83_EventScript_JaceEncounter
	@goto_if_unset FLAG_RECEIVED_POKEBLOCK_CASE, Route83_EventScript_JaceEncounter
	@addobject LOCALID_JACE
	playse SE_PIN
	applymovement LOCALID_JACE, Common_Movement_FaceRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	goto Route83_EventScript_JaceEncounter
	end

Route83_EventScript_JaceTrigger2::
	lockall
	goto_if_unset FLAG_DEFEATED_AMBER_GYM, Route83_EventScript_SkipJaceTrigger
	@goto_if_unset FLAG_BATTLED_JACE_ROUTE_83, Route83_EventScript_JaceEncounter
	@goto_if_unset FLAG_RECEIVED_POKEBLOCK_CASE, Route83_EventScript_JaceEncounter
	@addobject LOCALID_JACE
	playse SE_PIN
	applymovement LOCALID_JACE, Common_Movement_FaceRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	goto Route83_EventScript_JaceEncounter
	end

Route83_EventScript_JaceTrigger3::
	lockall
	goto_if_unset FLAG_DEFEATED_AMBER_GYM, Route83_EventScript_SkipJaceTrigger
	@goto_if_unset FLAG_BATTLED_JACE_ROUTE_83, Route83_EventScript_JaceEncounter
	@goto_if_unset FLAG_RECEIVED_POKEBLOCK_CASE, Route83_EventScript_JaceEncounter
	@addobject LOCALID_JACE
	playse SE_PIN
	applymovement LOCALID_JACE, Common_Movement_FaceRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	goto Route83_EventScript_JaceEncounter
	end

Route83_EventScript_JaceEncounter::
	@lockall
	@msgbox Route83_Text_CallPlayerName, MSGBOX_DEFAULT
	@closemessage
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	msgbox Route83_Text_JacePreBattle, MSGBOX_DEFAULT
	closemessage
	switch VAR_STARTER_MON
	case 0, Route83_EventScript_StartJaceBattleChespin
	case 1, Route83_EventScript_StartJaceBattleTepig
	case 2, Route83_EventScript_StartJaceBattlePopplio
	end

Route83_EventScript_StartJaceBattleChespin::
	trainerbattle_no_intro TRAINER_JACE_ROUTE_83_CHESPIN, Route83_Text_JaceDefeated
	goto Route83_EventScript_JacePostBattle
	end

Route83_EventScript_StartJaceBattleTepig::
	trainerbattle_no_intro TRAINER_JACE_ROUTE_83_TEPIG, Route83_Text_JaceDefeated
	goto Route83_EventScript_JacePostBattle
	end

Route83_EventScript_StartJaceBattlePopplio::
	trainerbattle_no_intro TRAINER_JACE_ROUTE_83_POPPLIO, Route83_Text_JaceDefeated
	goto Route83_EventScript_JacePostBattle
	end


Route83_EventScript_JacePostBattle::
	@playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox Route83_Text_JacePostBattle, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_JACE, Common_Movement_FaceLeft
	waitmovement 0
	delay 30
	applymovement LOCALID_JACE, Common_Movement_FaceRight
	waitmovement 0
	delay 30
	@msgbox Route83_Text_JacePostBattle2, MSGBOX_DEFAULT
	@closemessage
	@applymovement LOCALID_JACE, Common_Movement_WalkRight
	@waitmovement 0
	@delay 40
	@giveitem ITEM_POKEBLOCK_CASE


	msgbox Route83_Text_JacePostBattle3, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JACE, Route83_Movement_JaceLeaves
	waitmovement 0
	@setflag FLAG_BATTLED_JACE_ROUTE_83
	@setflag FLAG_RECEIVED_POKEBLOCK_CASE
	setflag FLAG_HIDE_JACE
	removeobject LOCALID_JACE
	setvar VAR_JACE_STATE, 2
	setflag FLAG_HIDE_JACE
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route83_Movement_JaceLeaves:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@Route83_Text_CallPlayerName:
@	.string "????: {PLAYER}!$"

Route83_Text_JacePreBattle:
	.string "JACE: {PLAYER}!\p"
	.string "We both have the SILICON BADGE now.\p"
	.string "Come on, let's see who's stronger!$"

Route83_Text_JaceDefeated:
	.string "Awww man.$"

Route83_Text_JacePostBattle:
	.string "JACE: You got the better of us this time,\n"
	.string "but we're still not giving up!\p"
	.string "There's another gym in COBALT CITY.\n"
	.string "That's where I'm headed now.\p"
	.string "You can get there by going through\n"
	.string "QUARTZ CAVE.\p"
	.string "Although you'll probably want to get\n"
	.string "the TM for FLASH first.\p"
	.string "I think MAY had a FLASH TM she was\n"
	.string "giving away...$"

@Route83_Text_JacePostBattle2:
	@.string "JACE: Oh, and one more thing.\n"
	@.string "COBALT CITY has a CONTEST HALL.\p"
	@.string "You and your POKéMON compete for prizes\n"
	@.string "POKéMON CONTESTS and compete for prizes.\p"
	@.string "Personally, that's too girly for me...\p"
	@.string "But hey, if that's your thing you can\p"
	@.string "enter as long as you have one of these.$"

Route83_Text_JacePostBattle3:
	@.string "That {POKEBLOCK} CASE lets you make and\n"
	@.string "store {POKEBLOCK}s\p"
	@.string "The people at the CONTEST HALL will explain\n"
	@.string "it to you.\p"
	.string "Well, I'm off to COBALT CITY. I guess I'll\n"
	.string "see you there.\p"
	.string "Don't forget to say hi to everyone back\n"
	.string "in UMBER TOWN.\p"
	.string "Until next time, {PLAYER}!$"

