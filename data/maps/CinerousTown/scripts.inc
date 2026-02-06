.set LOCALID_RIVAL, 4

CinerousTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinerousTown_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, CinerousTown_OnLoad
	.byte 0

CinerousTown_OnTransition:
	setflag FLAG_VISITED_CINEROUS_TOWN
	call Common_EventScript_SetupRivalGfxId
	goto_if_eq VAR_CINEROUS_TOWN_STATE, 3, CinerousTown_EventScript_PostTutorRescue
	@goto_if_set FLAG_RESCUED_HEADBUTT_TUTOR, CinerousTown_EventScript_PostTutorRescue
	goto_if_set FLAG_BATTLED_OPC_CINEROUS_TOWN, CinerousTown_EventScript_MoveOPCToGate
	goto_if_set FLAG_BADGE02_GET, CinerousTown_EventScript_MoveOPCToTown
	end

CinerousTown_EventScript_MoveOPCToTown::
	setvar VAR_CINEROUS_TOWN_STATE, 1
	setobjectxyperm LOCALID_RIVAL, 10, 13
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_UP
	end

CinerousTown_EventScript_MoveOPCToGate::
	setvar VAR_CINEROUS_TOWN_STATE, 2
	setobjectxyperm LOCALID_RIVAL, 10, 6
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_UP
	end

CinerousTown_EventScript_PostTutorRescue::
	end

CinerousTown_OnLoad:
	call_if_set FLAG_RESCUED_HEADBUTT_TUTOR, CinerousTown_EventScript_OpenGateAfterRescue
	end

CinerousTown_EventScript_OpenGateAfterRescue::
	@setvar VAR_CINEROUS_TOWN_STATE, 3
	@setflag FLAG_HIDE_OPC_CINEROUS_TOWN
	setmetatile 10, 5, METATILE_Petalburg_GateEntrance, FALSE
	setmetatile 11, 5, METATILE_Petalburg_GateEntrance, FALSE
	setmetatile 10, 6, METATILE_General_Grass, FALSE
	setmetatile 11, 6, METATILE_General_Grass, FALSE
	@special DrawWholeMapView
	return




CinerousTown_EventScript_OPCHouseSign::
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, CinerousTown_EventScript_VioletsHouseSign
	call_if_eq VAR_RESULT, FEMALE, CinerousTown_EventScript_VertsHouseSign
	releaseall
	end

CinerousTown_EventScript_VertsHouseSign::
	msgbox CinerousTown_Text_VertsHouse, MSGBOX_SIGN
	end

CinerousTown_EventScript_VioletsHouseSign::
	msgbox CinerousTown_Text_VioletsHouse, MSGBOX_SIGN
	end

CinerousTown_EventScript_TownSign::
	msgbox CinerousTown_Text_TownSign, MSGBOX_SIGN
	end

CinerousTown_Text_VertsHouse:
	.string "VERT'S HOUSE$"

CinerousTown_Text_VioletsHouse:
	.string "VIOLET'S HOUSE$"

CinerousTown_Text_TownSign:
	.string "CINEROUS TOWN\n"
	.string "“Historic village in nostalgia gray.”$"




CinerousTown_EventScript_Boy::
	lock
	faceplayer
	msgbox CinerousTown_Text_CinerousTownLame, MSGBOX_DEFAULT
	closemessage
	release
	end

CinerousTown_EventScript_OldWoman::
	lock
	faceplayer
	msgbox CinerousTown_Text_NoOneKnows, MSGBOX_DEFAULT
	closemessage
	release
	end

CinerousTown_EventScript_Woman::
	lock
	faceplayer
	msgbox CinerousTown_Text_ForestFires, MSGBOX_DEFAULT
	closemessage
	release
	end

CinerousTown_Text_ForestFires:
	.string "The mountains around here often\n"
	.string "get forest fires in the summer.\p"
	.string "But nothing like that great fire\n"
	.string "a few years ago!$"

CinerousTown_Text_CinerousTownLame:
	.string "You're from UMBER TOWN?\p"
	.string "That place is lame. It doesn't\n"
	.string "even have a POKéMON CENTER.$"

CinerousTown_Text_NoOneKnows:
	.string "No one knows what started the fire that\n"
	.string "destroyed CINEROUS TOWER.\p"
	.string "But it desolated the forest around it\n"
	.string "and nearly wiped out this town too.$"







CinerousTown_EventScript_OPCTrigger1::
	lockall
	applymovement LOCALID_RIVAL, Common_Movement_FaceDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	delay 60
	applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	waitmovement 0
	goto CinerousTown_EventScript_OPCEncounter
	end

CinerousTown_EventScript_OPCTrigger2::
	lockall
	applymovement LOCALID_RIVAL, Common_Movement_FaceDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	delay 60
	applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	waitmovement 0
	goto CinerousTown_EventScript_OPCEncounter
	end

CinerousTown_EventScript_OPCTrigger3::
	lockall
	applymovement LOCALID_RIVAL, Common_Movement_FaceDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	delay 60
	applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	waitmovement 0
	goto CinerousTown_EventScript_OPCEncounter
	end

CinerousTown_EventScript_OPCEncounter::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, CinerousTown_EventScript_GirlMusic
	call_if_eq VAR_RESULT, FEMALE, CinerousTown_EventScript_BoyMusic
	msgbox CinerousTown_Text_OPCPreBattle, MSGBOX_DEFAULT
	closemessage
	switch VAR_STARTER_MON
	case 0, CinerousTown_EventScript_StartOPCBattleChespin
	case 1, CinerousTown_EventScript_StartOPCBattleTepig
	case 2, CinerousTown_EventScript_StartOPCBattlePopplio
	end

CinerousTown_EventScript_BoyMusic:
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

CinerousTown_EventScript_GirlMusic:
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

CinerousTown_Text_OPCPreBattle:
	.string "...\p"
	.string "I knew it! You're a POKéMON trainer!\n"
	.string "Your gym badges confirm it!\p"
	.string "Since our eyes met, you can't refuse me.\n"
	.string "I challenge you to a POKéMON battle!$"



CinerousTown_EventScript_StartOPCBattleChespin::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, CinerousTown_EventScript_VioletBattleChespin
	goto_if_eq VAR_RESULT, FEMALE, CinerousTown_EventScript_VertBattleChespin
	end	

CinerousTown_EventScript_VioletBattleChespin::
	trainerbattle_no_intro_no_whiteout TRAINER_VIOLET_CINEROUS_TOWN_CHESPIN, CinerousTown_Text_VioletDefeated
	goto CinerousTown_EventScript_AfterOPCBattle
	end

CinerousTown_EventScript_VertBattleChespin::
	trainerbattle_no_intro_no_whiteout TRAINER_VERN_CINEROUS_TOWN_CHESPIN, CinerousTown_Text_VertDefeated
	goto CinerousTown_EventScript_AfterOPCBattle
	end



CinerousTown_EventScript_StartOPCBattleTepig::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, CinerousTown_EventScript_VioletBattleTepig
	goto_if_eq VAR_RESULT, FEMALE, CinerousTown_EventScript_VertBattleTepig
	end	

CinerousTown_EventScript_VioletBattleTepig::
	trainerbattle_no_intro_no_whiteout TRAINER_VIOLET_CINEROUS_TOWN_TEPIG, CinerousTown_Text_VioletDefeated
	goto CinerousTown_EventScript_AfterOPCBattle
	end

CinerousTown_EventScript_VertBattleTepig::
	trainerbattle_no_intro_no_whiteout TRAINER_VERN_CINEROUS_TOWN_TEPIG, CinerousTown_Text_VertDefeated
	goto CinerousTown_EventScript_AfterOPCBattle
	end






CinerousTown_EventScript_StartOPCBattlePopplio::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, CinerousTown_EventScript_VioletBattlePopplio
	goto_if_eq VAR_RESULT, FEMALE, CinerousTown_EventScript_VertBattlePopplio
	end

CinerousTown_EventScript_VioletBattlePopplio::
	trainerbattle_no_intro_no_whiteout TRAINER_VIOLET_CINEROUS_TOWN_POPPLIO, CinerousTown_Text_VioletDefeated
	goto CinerousTown_EventScript_AfterOPCBattle
	end

CinerousTown_EventScript_VertBattlePopplio::
	trainerbattle_no_intro_no_whiteout TRAINER_VERN_CINEROUS_TOWN_POPPLIO, CinerousTown_Text_VertDefeated
	goto CinerousTown_EventScript_AfterOPCBattle
	end

CinerousTown_Text_VioletDefeated:
	.string "You're pretty good, boy.\n"
	.string "What's your name?$"

CinerousTown_Text_VertDefeated:
	.string "You're pretty good, girl.\n"
	.string "What's your name?$"





CinerousTown_EventScript_AfterOPCBattle::
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceDown
	waitmovement 0
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, CinerousTown_EventScript_ImViolet
	goto_if_eq VAR_RESULT, FEMALE, CinerousTown_EventScript_ImVert
	end

CinerousTown_EventScript_ImViolet::
	msgbox CinerousTown_Text_ImViolet, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	delay 30
	playse SE_USE_ITEM
	delay 30
	special HealPlayerParty
	fadescreen FADE_FROM_BLACK
	msgbox CinerousTown_Text_VioletPostBattle, MSGBOX_YESNO	
	goto_if_eq VAR_RESULT, YES, CinerousTown_EventScript_HelpOPC
	goto_if_eq VAR_RESULT, NO, CinerousTown_EventScript_RejectOPC
	end


CinerousTown_Text_ImViolet:
	.string "...\p"
	.string "So you're {PLAYER}?\n"
	.string "I'm VIOLET, nice to meet you!\p"
	.string "Here, let me heal your POKéMON.$"

CinerousTown_Text_VioletPostBattle:
	.string "VIOLET: I was hoping to meet another\n"
	.string "trainer like you.\p"
	.string "There's a missing person's report\n"
	.string "going around right now.\l"
	.string "I'm organizing a search party.\l"
	.string "...\l"
	.string "Well actually, it's just me right now.\p"
	.string "But you could come with me. Won't you?$"

CinerousTown_EventScript_ImVert::
	msgbox CinerousTown_Text_ImVert, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	delay 30
	playse SE_USE_ITEM
	delay 30
	special HealPlayerParty
	fadescreen FADE_FROM_BLACK
	msgbox CinerousTown_Text_VertPostBattle, MSGBOX_YESNO	
	goto_if_eq VAR_RESULT, YES, CinerousTown_EventScript_HelpOPC
	goto_if_eq VAR_RESULT, NO, CinerousTown_EventScript_RejectOPC
	end

CinerousTown_Text_ImVert:
	.string "...\p"
	.string "So you're {PLAYER}?\n"
	.string "I'm VERT, nice to meet you!\p"
	.string "Here, let me heal your POKéMON.$"

CinerousTown_Text_VertPostBattle:
	.string "VERT: I was hoping to meet another\n"
	.string "trainer like you.\p"
	.string "There's a missing person's report\n"
	.string "going around right now.\l"
	.string "I'm organizing a search party.\l"
	.string "...\l"
	.string "Well actually, it's just me right now.\p"
	.string "But you could come with me. Won't you?$"


CinerousTown_EventScript_HelpOPC::
	msgbox CinerousTown_Text_HelpOPC, MSGBOX_DEFAULT
	closemessage
	goto CinerousTown_EventScript_OPCExit
	end

CinerousTown_Text_HelpOPC:
	.string "Great! You're awesome, {PLAYER}!\p"
	.string "I'll wait by the gate at the\n"
	.string "north end of town.\p"
	.string "Meet me there once you and\n"
	.string "your POKéMON are ready.$"

CinerousTown_EventScript_RejectOPC::
	msgbox CinerousTown_Text_RejectOPC, MSGBOX_DEFAULT
	closemessage
	goto CinerousTown_EventScript_OPCExit
	end

CinerousTown_Text_RejectOPC:
	.string "Oh. Well I guess I didn't ask if you\n"
	.string "had other things to do.\p"
	.string "...\p"
	.string "I'm going to the gate at edge of town.\n"
	.string "If you change your mind, meet me there.$"

CinerousTown_EventScript_OPCExit::
	applymovement LOCALID_RIVAL, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkUp
	waitmovement 0
	removeobject LOCALID_RIVAL
	setflag FLAG_BATTLED_OPC_CINEROUS_TOWN	
	setvar VAR_CINEROUS_TOWN_STATE, 2
	setobjectxyperm LOCALID_RIVAL, 10, 6
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_UP
	@special DrawWholeMapView
	addobject LOCALID_RIVAL
	clearflag FLAG_RESCUED_HEADBUTT_TUTOR
	savebgm MUS_DUMMY
	fadedefaultbgm
	@questmenu QUEST_MENU_UNLOCK_QUEST QUEST_11
	@openquestmenu
	startquest QUEST_11
	releaseall
	end






CinerousTown_EventScript_OpenGate::
	lockall
	faceplayer
	msgbox CinerousTown_Text_ThereYouAre, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, Common_Movement_FaceUp
	waitmovement 0
	delay 60
	msgbox CinerousTown_Text_DoorJammed, MSGBOX_DEFAULT
	closemessage
	playse SE_BALL_OPEN
	waitse
	delay 60
	switch VAR_STARTER_MON
	case 0, CinerousTown_EventScript_BrionneUseHeadbutt
	case 1, CinerousTown_EventScript_QuilladinUseHeadbutt
	case 2, CinerousTown_EventScript_PigniteUseHeadbutt
	end

CinerousTown_EventScript_QuilladinUseHeadbutt:
	msgbox CinerousTown_Text_QuilladinUseHeadbutt, MSGBOX_DEFAULT
	playmoncry SPECIES_QUILLADIN, CRY_MODE_NORMAL
	waitmoncry
	goto CinerousTown_EventScript_GateOpened
	end

CinerousTown_EventScript_PigniteUseHeadbutt:
	msgbox CinerousTown_Text_PigniteUseHeadbutt, MSGBOX_DEFAULT
	playmoncry SPECIES_PIGNITE, CRY_MODE_NORMAL
	waitmoncry
	goto CinerousTown_EventScript_GateOpened
	end

CinerousTown_EventScript_BrionneUseHeadbutt:
	msgbox CinerousTown_Text_BrionneUseHeadbutt, MSGBOX_DEFAULT
	playmoncry SPECIES_BRIONNE, CRY_MODE_NORMAL
	waitmoncry
	goto CinerousTown_EventScript_GateOpened
	end

CinerousTown_EventScript_GateOpened::
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	@special ShakeScreen
	delay 30
	setmetatile 10, 5, METATILE_Petalburg_GateEntrance, FALSE
	setmetatile 11, 5, METATILE_Petalburg_GateEntrance, FALSE
	setmetatile 10, 6, METATILE_General_Grass, FALSE
	setmetatile 11, 6, METATILE_General_Grass, FALSE
	special DrawWholeMapView
	playse SE_DOOR
	waitse
	faceplayer
	msgbox CinerousTown_Text_LetsGo, MSGBOX_DEFAULT
	closemessage
	@warpdoor MAP_CINEROUS_TOWER_EXTERIOR, 9, 30
	warp MAP_CINEROUS_TOWER_EXTERIOR, 15, 33
	waitstate
	end

CinerousTown_Text_ThereYouAre:
	.string "Oh, {PLAYER}! There you are.\p"
	.string "The report said someone went missing\n"
	.string "in the woods beyond this gate.$"

 CinerousTown_Text_DoorJammed:
	.string "This door is really beat up though.\n"
	.string "It looks like it's jammed.\p"
	.string "No worries, I know another way in!$"

CinerousTown_Text_QuilladinUseHeadbutt:
	.string "QUILLADIN, use HEADBUTT!$"

CinerousTown_Text_PigniteUseHeadbutt:
	.string "PIGNITE, use HEADBUTT!$"

CinerousTown_Text_BrionneUseHeadbutt:
	.string "BRIONNE, use HEADBUTT!$"

CinerousTown_Text_LetsGo:
	.string "C'mon, let's go look for\n"
	.string "the missing person.$"



