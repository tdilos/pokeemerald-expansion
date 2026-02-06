.set LOCALID_RANGER, 1
.set LOCALID_ARTHUR, 2
.set LOCALID_POACHER1, 3
.set LOCALID_POACHER2, 4
.set LOCALID_POACHER3, 5
.set LOCALID_POACHER4, 9

ShamrockIsle_Interior_MapScripts::
	@map_script MAP_SCRIPT_ON_FRAME_TABLE, ShamrockIsle_Interior_OnFrame
	@map_script MAP_SCRIPT_ON_TRANSITION, ShamrockIsle_Interior_OnTransition
	.byte 0

@ShamrockIsle_Interior_OnFrame:
@	map_script_2 VAR_SHAMROCK_ISLE_STATE, 0, ShamrockIsle_Interior_EventScript_ArthurEncounter
@	end

@ShamrockIsle_Interior_OnTransition:
@	call_if_ge VAR_SHAMROCK_ISLE_STATE, 1, ShamrockIsle_EventScript_HideArthur
@	end








ShamrockIsle_Interior_EventScript_Gale::
	trainerbattle_single TRAINER_GALE, ShamrockIsle_Interior_Text_GaleIntro, ShamrockIsle_Interior_Text_GaleDefeated
	msgbox ShamrockIsle_Interior_Text_GalePostBattle, MSGBOX_AUTOCLOSE
	end

ShamrockIsle_Interior_EventScript_Theo::
	trainerbattle_single TRAINER_THEO, ShamrockIsle_Interior_Text_TheoIntro, ShamrockIsle_Interior_Text_TheoDefeated
	msgbox ShamrockIsle_Interior_Text_TheoPostBattle, MSGBOX_AUTOCLOSE
	end

ShamrockIsle_Interior_EventScript_Joaquin::
	trainerbattle_single TRAINER_JOAQUIN, ShamrockIsle_Interior_Text_JoaquinIntro, ShamrockIsle_Interior_Text_JoaquinDefeated
	msgbox ShamrockIsle_Interior_Text_JoaquinPostBattle, MSGBOX_AUTOCLOSE
	end

ShamrockIsle_Interior_EventScript_Neville::
	trainerbattle_single TRAINER_NEVILLE, ShamrockIsle_Interior_Text_NevilleIntro, ShamrockIsle_Interior_Text_NevilleDefeated
	msgbox ShamrockIsle_Interior_Text_NevillePostBattle, MSGBOX_AUTOCLOSE
	end







ShamrockIsle_Interior_Movement_ArthurWalksToPlayer1:
	walk_down
	walk_left
	walk_down
	step_end

ShamrockIsle_Interior_Movement_ArthurWalksToPlayer2:
	walk_down
	walk_down
	step_end

ShamrockIsle_Interior_Movement_ArthurExit1:
	walk_right
	walk_down
	walk_down
	step_end

ShamrockIsle_Interior_Movement_ArthurExit2:
	walk_left
	walk_down
	walk_down
	step_end


ShamrockIsle_Interior_EventScript_ArthurEncounter1::
	lockall
	setvar VAR_SHAMROCK_ISLE_STATE, 1
	@delay 30
	applymovement LOCALID_ARTHUR, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_ARTHUR, Common_Movement_FaceDown
	waitmovement 0
	applymovement LOCALID_ARTHUR, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	waitse
	delay 30
	applymovement LOCALID_ARTHUR, ShamrockIsle_Interior_Movement_ArthurWalksToPlayer1
	waitmovement 0
	msgbox ShamrockIsle_Interior_Text_ArthurIntro, MSGBOX_YESNO
	msgbox ShamrockIsle_Interior_Text_ExplainShamrockIsle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARTHUR, Common_Movement_FaceUp
	waitmovement 0
	delay 60
	applymovement LOCALID_ARTHUR, Common_Movement_FaceDown
	waitmovement 0
	msgbox ShamrockIsle_Interior_Text_ExplainPoachers, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_ARTHUR, Common_Movement_FaceLeft
	waitmovement 0
	delay 30
	applymovement LOCALID_ARTHUR, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	msgbox ShamrockIsle_Interior_Text_ExplainRangerOutpost, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARTHUR, ShamrockIsle_Interior_Movement_ArthurExit1
	waitmovement 0
	delay 30
	removeobject LOCALID_ARTHUR
	playse SE_EXIT
	waitse
	@setflag FLAG_SHAMROCK_ISLE_HIDE_ARTHUR
	@setvar VAR_SHAMROCK_ISLE_STATE, 1
	releaseall
	end

ShamrockIsle_Interior_EventScript_ArthurEncounter2::
	lockall
	setvar VAR_SHAMROCK_ISLE_STATE, 1
	@delay 30
	applymovement LOCALID_ARTHUR, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_ARTHUR, Common_Movement_FaceDown
	waitmovement 0
	applymovement LOCALID_ARTHUR, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	waitse
	delay 30
	applymovement LOCALID_ARTHUR, ShamrockIsle_Interior_Movement_ArthurWalksToPlayer2
	waitmovement 0
	msgbox ShamrockIsle_Interior_Text_ArthurIntro, MSGBOX_YESNO
	msgbox ShamrockIsle_Interior_Text_ExplainShamrockIsle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARTHUR, Common_Movement_FaceUp
	waitmovement 0
	delay 60
	applymovement LOCALID_ARTHUR, Common_Movement_FaceDown
	waitmovement 0
	msgbox ShamrockIsle_Interior_Text_ExplainPoachers, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_ARTHUR, Common_Movement_FaceLeft
	waitmovement 0
	delay 30
	applymovement LOCALID_ARTHUR, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	msgbox ShamrockIsle_Interior_Text_ExplainRangerOutpost, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARTHUR, ShamrockIsle_Interior_Movement_ArthurExit2
	waitmovement 0
	delay 30
	removeobject LOCALID_ARTHUR
	playse SE_EXIT
	waitse
	@setflag FLAG_SHAMROCK_ISLE_HIDE_ARTHUR
	@setvar VAR_SHAMROCK_ISLE_STATE, 1
	releaseall
	end

ShamrockIsle_Interior_Text_ArthurIntro:
	.string "ARTHUR: Ah, {PLAYER}!\n"
	.string "What a surprise meeting you here!\p"
	.string "It's been a while since you\n"
	.string "challenged my gym, hasn't it?\p"
	.string "You and your POKéMON look like\n"
	.string "you've gotten much stronger.\p"
	.string "\p"
	.string "So you've come to SHAMROCK ISLE?\n"
	.string "Have you heard of it before?$"

ShamrockIsle_Interior_Text_ExplainShamrockIsle:
	.string "It's one of the POKéMON sanctuaries\n"
	.string "here in ISSHO.\p"
	.string "There are species here that you\n"
	.string "can't find anywhere else.\p"
	.string "Unfortunately, that makes it a prime\n"
	.string "target for POKéMON poachers...$"

ShamrockIsle_Interior_Text_ExplainPoachers:
	.string "The POKéMON RANGERS try to keep\n"
	.string "an eye out for them.\p"
	.string "But it seems they've had their\n"
	.string "hands full lately.\p"
	.string "They've been short on staff out here.\n"
	.string "And just when trouble strikes...$"

ShamrockIsle_Interior_Text_ExplainRangerOutpost:
	.string "Maybe you could help them out\n"
	.string "while you're here?\p"
	.string "There's a ranger outpost nearby.\n"
	.string "They can fill you in on the details.\p"
	.string "As for me, I have to get back to my gym.\n"
	.string "Best of luck, {PLAYER}!$"











ShamrockIsle_Interior_EventScript_Ranger::
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_35
	goto_if_eq VAR_RESULT, TRUE, ShamrockIsle_Interior_EventScript_Quest2Complete
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_35
	goto_if_eq VAR_RESULT, TRUE, ShamrockIsle_Interior_EventScript_Quest2InProgress
	msgbox ShamrockIsle_Interior_Text_Poachers, MSGBOX_DEFAULT
	startquest QUEST_35
	release
	end

ShamrockIsle_Interior_Text_Poachers:
	.string "When it rains it pours, as they say.\p"
	.string "There have been reports of poaching\n"
	.string "on the island again recently.\p"
	.string "And the folks at RANGER HQ have had\n"
	.string "their hands full with other things.\p"
	.string "I'm the only one left stationed\n"
	.string "out here.\p"
	.string "Under normal circumstances, that\n"
	.string "wouldn't be so bad.\p"
	.string "But I can't guard a whole island\n"
	.string "all by myself...\p"
	.string "\p"
	.string "Maybe you could help me out a bit?\p"
	.string "Just keep an eye out for any suspicous\n"
	.string "looking people around the island.\p"
	.string "Let me know if you see anything, okay?$"

ShamrockIsle_Interior_EventScript_Quest2InProgress::
	msgbox ShamrockIsle_Interior_Text_SuspiciousPeople, MSGBOX_DEFAULT
	release
	end

ShamrockIsle_Interior_Text_SuspiciousPeople:
	.string "Keep an eye out for suspicious people.\n"
	.string "Let me know if you see anything, okay?$"

ShamrockIsle_Interior_EventScript_Quest2Complete::
	msgbox ShamrockIsle_Interior_Text_Poaching, MSGBOX_DEFAULT
	release
	end

ShamrockIsle_Interior_Text_Poaching:
	.string "Poaching's a serious crime.\p"
	.string "SHAMROCK ISLE is full of\n"
	.string "endangered species.\p"
	.string "If left unchecked, poachers would hunt\n"
	.string "them all to extinction.$"














ShamrockIsle_Interior_EventScript_Maniac::
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_36
	goto_if_eq VAR_RESULT, TRUE, ShamrockIsle_Interior_EventScript_QuestComplete
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_36
	goto_if_eq VAR_RESULT, TRUE, ShamrockIsle_Interior_EventScript_QuestInProgress
	msgbox ShamrockIsle_Interior_Text_Request, MSGBOX_DEFAULT
	startquest QUEST_36
	release
	end

ShamrockIsle_Interior_Text_Request:
	.string "Do you know what the coolest bug is?\p"
	.string "That's right, it's YANMEGA!\p" 
	.string "I'd give anything to see a YANMEGA\n"
	.string "with the TINTED LENS ability.\p"
	.string "Please, if you ever find one,\n"
	.string "you have to show me.\p"
	.string "I'll make it worth your trouble,\n"
	.string "I promise!$"

ShamrockIsle_Interior_EventScript_QuestInProgress::
	msgbox ShamrockIsle_Interior_Text_FoundOneYet, MSGBOX_DEFAULT
	special CheckForTintedLensYanmega
	goto_if_eq VAR_RESULT, TRUE, ShamrockIsle_Interior_EventScript_CompleteQuest
	msgbox ShamrockIsle_Interior_Text_NotRightPokemon, MSGBOX_DEFAULT
	release
	end

ShamrockIsle_Interior_Text_FoundOneYet:
	.string "Have you found one yet?\n"
	.string "Let me see!$"

ShamrockIsle_Interior_Text_NotRightPokemon:
	.string "No, no, no! It HAS to be a\n"
	.string "YANMEGA with TINTED LENS!$"

ShamrockIsle_Interior_EventScript_CompleteQuest::
	msgbox ShamrockIsle_Interior_Text_ThatsIt, MSGBOX_DEFAULT
	giveitem ITEM_POWER_LENS, 6
	completequest QUEST_36
	release
	end

ShamrockIsle_Interior_Text_ThatsIt:
	.string "Oh, that's it!\n"
	.string "That's a YANMEGA with TINTED LENS!\p"
	.string "It's so cool!\n"
	.string "I envy you for catching one.\p"
	.string "As thanks for showing it me,\n"
	.string "I'd like you to have this.$"

ShamrockIsle_Interior_EventScript_QuestComplete::
	msgbox ShamrockIsle_Interior_Text_ExplainPowerItem, MSGBOX_DEFAULT
	release
	end

ShamrockIsle_Interior_Text_ExplainPowerItem:
	.string "Give that POWER LENS to one\n"
	.string "of your POKéMON to wear.\p"
	.string "It'll help train its Sp. Atk. faster.$"










ShamrockIsle_Interior_Movement_WalkToPoachers0:
	walk_up
	walk_up
	walk_right
	face_up
	step_end

ShamrockIsle_Interior_Movement_WalkToPoachers1:
	walk_up
	walk_up
	step_end

ShamrockIsle_Interior_Movement_WalkToPoachers2:
	walk_up
	walk_up
	walk_left
	face_up
	step_end

ShamrockIsle_Interior_Movement_Poacher1WalkToPlayer:
	walk_left
	walk_down
	step_end

ShamrockIsle_Interior_Movement_Poacher2WalkToPlayer:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	face_right
	step_end

ShamrockIsle_Interior_Movement_Poacher3WalkToPlayer:
	walk_left
	walk_down
	walk_down
	walk_down
	face_left
	step_end

ShamrockIsle_Interior_Movement_Poacher4Enters:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end


ShamrockIsle_Interior_Movement_Poacher1Cowers:
	walk_fast_left
	walk_fast_left
	face_right
	step_end

ShamrockIsle_Interior_Movement_Poacher2Cowers:
	walk_fast_left
	face_right
	step_end

ShamrockIsle_Interior_Movement_Poacher3Cowers:
	walk_fast_down
	walk_fast_left
	walk_fast_left
	face_right
	step_end

ShamrockIsle_Interior_Movement_Poacher4Cowers:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	face_right
	step_end

ShamrockIsle_Interior_Movement_RangerEnters:
	walk_up
	walk_up
	walk_up
	step_end

ShamrockIsle_Interior_Movement_BlownBack:
	lock_facing_direction
	walk_fast_up
	walk_fast_up
	unlock_facing_direction
	step_end

ShamrockIsle_Interior_Movement_BlownBack2:
	lock_facing_direction
	face_down
	unlock_facing_direction
	step_end

ShamrockIsle_Interior_Movement_RangerWalkToPlayer:
	walk_up
	walk_up
	face_right
	step_end

ShamrockIsle_Interior_EventScript_PoachersTrigger0::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, ShamrockIsle_Interior_Movement_WalkToPoachers0
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	goto ShamrockIsle_Interior_EventScript_BattlePoachers
	end

ShamrockIsle_Interior_EventScript_PoachersTrigger1::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, ShamrockIsle_Interior_Movement_WalkToPoachers1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	goto ShamrockIsle_Interior_EventScript_BattlePoachers
	end

ShamrockIsle_Interior_EventScript_PoachersTrigger2::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, ShamrockIsle_Interior_Movement_WalkToPoachers2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	goto ShamrockIsle_Interior_EventScript_BattlePoachers
	end

ShamrockIsle_Interior_EventScript_BattlePoachers::
	@setweather WEATHER_RAIN_THUNDERSTORM
	addobject LOCALID_POACHER1
	addobject LOCALID_POACHER2
	addobject LOCALID_POACHER3
	addobject LOCALID_POACHER4
	delay 60
	applymovement LOCALID_POACHER1, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox ShamrockIsle_Interior_Text_ThatsTheLastOne, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_POACHER3, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox ShamrockIsle_Interior_Text_WhatsTakingSoLong, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_POACHER2, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox ShamrockIsle_Interior_Text_HeadsUpGuys, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_POACHER1, Common_Movement_FaceDown
	applymovement LOCALID_POACHER3, Common_Movement_FaceDown
	waitmovement 0
	delay 60
	applymovement LOCALID_POACHER1, ShamrockIsle_Interior_Movement_Poacher1WalkToPlayer
	waitmovement 0
	delay 60
	applymovement LOCALID_POACHER1, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox ShamrockIsle_Interior_Text_ThisIsntWhatItLooksLike, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, ShamrockIsle_Interior_EventScript_LetPoachersGo
	msgbox ShamrockIsle_Interior_Text_Poacher1PreBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GUNTHER, ShamrockIsle_Interior_Text_Poacher1Defeated
	applymovement LOCALID_POACHER2, ShamrockIsle_Interior_Movement_Poacher2WalkToPlayer
	waitmovement 0
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox ShamrockIsle_Interior_Text_Poacher2PreBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_FLOYD, ShamrockIsle_Interior_Text_Poacher2Defeated
	applymovement LOCALID_POACHER3, ShamrockIsle_Interior_Movement_Poacher3WalkToPlayer
	waitmovement 0
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox ShamrockIsle_Interior_Text_Poacher3PreBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_DUVAL, ShamrockIsle_Interior_Text_Poacher3Defeated
	applymovement LOCALID_POACHER3, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox ShamrockIsle_Interior_Text_ThisKidsNoJoke, MSGBOX_DEFAULT
	closemessage
	fadeoutbgm 0
	delay 60
	msgbox ShamrockIsle_Interior_Text_Scream, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement LOCALID_POACHER1, Common_Movement_FaceRight
	applymovement LOCALID_POACHER2, Common_Movement_FaceRight
	applymovement LOCALID_POACHER3, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	applymovement LOCALID_POACHER1, Common_Movement_ExclamationMark
	applymovement LOCALID_POACHER2, Common_Movement_ExclamationMark
	applymovement LOCALID_POACHER3, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 60
	applymovement LOCALID_POACHER4, ShamrockIsle_Interior_Movement_Poacher4Enters
	waitmovement 0
	delay 30
	applymovement LOCALID_POACHER2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox ShamrockIsle_Interior_Text_JonesYoureBack, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_POACHER4, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox ShamrockIsle_Interior_Text_PokemonAmbush, MSGBOX_DEFAULT
	closemessage
	delay 30
	playmoncry SPECIES_PLUX, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_POACHER4, Common_Movement_FaceRight
	applymovement LOCALID_POACHER4, Common_Movement_ExclamationMark
	waitmovement 0
	delay 60
	msgbox ShamrockIsle_Interior_Text_Oops, MSGBOX_AUTOCLOSE
	applymovement LOCALID_POACHER1, ShamrockIsle_Interior_Movement_Poacher1Cowers
	applymovement LOCALID_POACHER2, ShamrockIsle_Interior_Movement_Poacher2Cowers
	applymovement LOCALID_POACHER3, ShamrockIsle_Interior_Movement_Poacher3Cowers
	applymovement LOCALID_POACHER4, ShamrockIsle_Interior_Movement_Poacher4Cowers
	waitmovement 0
	delay 30
	applymovement LOCALID_POACHER1, Common_Movement_WalkInPlaceRight
	waitmovement 0
	playbgm MUS_ENCOUNTER_MAGMA, FALSE	
	msgbox ShamrockIsle_Interior_Text_KidYouGottaDoSomething, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	delay 60
	playmoncry SPECIES_PLUX, CRY_MODE_ENCOUNTER
	waitmoncry
	@delay 20
	seteventmon SPECIES_PLUX, 49
	totemboost_speed2 B_POSITION_OPPONENT_LEFT
	special BattleSetup_StartLegendaryBattle
	waitstate
	playbgm MUS_DUMMY, FALSE
	@fadeoutbgm 0
	applymovement LOCALID_POACHER1, Common_Movement_WalkInPlaceRight
	waitmovement 0	
	msgbox ShamrockIsle_Interior_Text_GreatJobKid, MSGBOX_DEFAULT
	closemessage
	delay 30
	setobjectxyperm LOCALID_RANGER, 56, 14
	addobject LOCALID_RANGER
	applymovement LOCALID_RANGER, ShamrockIsle_Interior_Movement_RangerEnters
	waitmovement 0
	applymovement LOCALID_POACHER1, Common_Movement_FaceDown
	applymovement LOCALID_POACHER2, Common_Movement_FaceDown
	applymovement LOCALID_POACHER3, Common_Movement_FaceDown
	applymovement LOCALID_POACHER4, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_POACHER1, Common_Movement_ExclamationMark
	applymovement LOCALID_POACHER2, Common_Movement_ExclamationMark
	applymovement LOCALID_POACHER3, Common_Movement_ExclamationMark
	applymovement LOCALID_POACHER4, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox ShamrockIsle_Interior_Text_FinallyCaughtYou, MSGBOX_DEFAULT
	closemessage
	delay 30
	playmoncry SPECIES_ARIADOS, CRY_MODE_NORMAL
	waitmoncry
	playse SE_M_STRING_SHOT
	waitse
	applymovement LOCALID_POACHER4, ShamrockIsle_Interior_Movement_BlownBack2
	waitmovement 0
	playse SE_WALL_HIT
	applymovement LOCALID_POACHER1, ShamrockIsle_Interior_Movement_BlownBack
	waitmovement 0
	playse SE_WALL_HIT
	applymovement LOCALID_POACHER2, ShamrockIsle_Interior_Movement_BlownBack
	waitmovement 0
	playse SE_WALL_HIT
	applymovement LOCALID_POACHER3, ShamrockIsle_Interior_Movement_BlownBack
	waitmovement 0
	playse SE_WALL_HIT
	delay 60
	msgbox ShamrockIsle_Interior_Text_OneLiner, MSGBOX_AUTOCLOSE
	delay 60
	applymovement LOCALID_RANGER, ShamrockIsle_Interior_Movement_RangerWalkToPlayer
	waitmovement 0	
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	delay 20
	msgbox ShamrockIsle_Interior_Text_ThanksForTheHelp, MSGBOX_DEFAULT
	giveitem ITEM_POWER_BAND, 6
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_SHAMROCK_ISLE_POACHERS
	removeobject LOCALID_POACHER1
	removeobject LOCALID_POACHER2
	removeobject LOCALID_POACHER3
	removeobject LOCALID_POACHER4
	removeobject LOCALID_RANGER
	setobjectxyperm LOCALID_RANGER, 2, 96
	addobject LOCALID_RANGER
	setvar VAR_SHAMROCK_ISLE_STATE, 2
	fadescreen FADE_FROM_BLACK
	completequest QUEST_35
	fadedefaultbgm
	@setweather WEATHER_DOWNPOUR
	releaseall
	end


ShamrockIsle_Interior_EventScript_LetPoachersGo::
	msgbox ShamrockIsle_Interior_Text_LetPoachersGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_SHAMROCK_ISLE_POACHERS
	removeobject LOCALID_POACHER1
	removeobject LOCALID_POACHER2
	removeobject LOCALID_POACHER3
	removeobject LOCALID_POACHER4
	setvar VAR_SHAMROCK_ISLE_STATE, 2
	fadescreen FADE_FROM_BLACK
	setweather WEATHER_DOWNPOUR
	releaseall
	end

ShamrockIsle_Interior_Text_ThatsTheLastOne:
	.string "That's the last POKéMON loaded up.\p"
	.string "Once JONES gets back with the boat,\n"
	.string "we can leave this miserable island.\p"
	.string "Then we'll be rich, baby!$"

ShamrockIsle_Interior_Text_WhatsTakingSoLong:
	.string "What's taking JONES so long, anyway?$"

ShamrockIsle_Interior_Text_HeadsUpGuys:
	.string "Heads up, guys. We're not alone here.$"

ShamrockIsle_Interior_Text_ThisIsntWhatItLooksLike:
	.string "Hey look, kid!\n"
	.string "This isn't what it looks like!\l"
	.string "...\l"
	.string "Okay, so it is what it looks like.\p"
	.string "But hey, you're a trainer, aintcha?\n"
	.string "You catch POKéMON all the time.\p"
	.string "What we're doing here is essentially\n"
	.string "the same thing you do, right?\p"
	.string "So what if we don't use POKé BALLS?\n"
	.string "We prefer to be efficient.\p"
	.string "We're just guys trying to make a living\n"
	.string "like anybody else.\p"
	.string "So, uh, why don't you look\n"
	.string "the other way for a bit?\p"
	.string "We'll get our payload out of here soon,\n"
	.string "and you'll never see us again.\p"
	.string "Just like we were never here.\n"
	.string "How does that sound?$"

ShamrockIsle_Interior_Text_LetPoachersGo:
	.string "Hey great!\n"
	@.string "I knew you'd see reason.\p"
	.string "You're pretty cool, kid.\p"
	.string "Not like those stuck-up RANGERS.\p"
	.string "As soon as our guy gets back, we'll\n"
	.string "be out of here in no time.\p"
	.string "...\p"
	.string "Oh and, if anyone asks, you never\n"
	.string "saw nothing or nobody.$"

ShamrockIsle_Interior_Text_Poacher1PreBattle:
	.string "...\p"
	.string "I was afraid you'd say that.\p"
	.string "Looks like we're gonna have to do\n"
	.string "things the hard way.$"

ShamrockIsle_Interior_Text_Poacher1Defeated:
	.string "Hey, that's not what I meant!$"

ShamrockIsle_Interior_Text_Poacher2PreBattle:
	.string "Hehe. Don't think we'll give\n"
	.string "you a chance to rest.$"

ShamrockIsle_Interior_Text_Poacher2Defeated:
	.string "Hey now, that's not fair!$"

ShamrockIsle_Interior_Text_Poacher3PreBattle:
	.string "Three battles in a row.\n"
	.string "Think you can handle that?$"

ShamrockIsle_Interior_Text_Poacher3Defeated:
	.string "Why couldn't you just keep quiet?$"

ShamrockIsle_Interior_Text_ThisKidsNoJoke:
	.string "This kid's no joke!\p"
	.string "And just when we were this close\n"
	.string "to the biggest payday ever...$"

ShamrockIsle_Interior_Text_Scream:
	.string "?????: AAAAAAAAAHHH!$"

ShamrockIsle_Interior_Text_JonesYoureBack:
	.string "JONES, you're back!\n"
	.string "Did you get the boat?$"

ShamrockIsle_Interior_Text_PokemonAmbush:
	.string "I couldn't, I got ambushed by\n"
	.string "some freaky POKéMON.\p"
	.string "It chased me all the way back here.\n"
	.string "But I think I managed to shake it.$"

ShamrockIsle_Interior_Text_Oops:
	.string "Oops.$"

ShamrockIsle_Interior_Text_KidYouGottaDoSomething:
	.string "We're all out of POKéMON!\p"
	.string "Kid, you gotta do something!$"

ShamrockIsle_Interior_Text_GreatJobKid:
	.string "Great work, kid!\n"
	.string "I knew you could handle it.\p"
	.string "So I guess we'll be going now.\n"
	.string "No hard feelings, am I right?$"

ShamrockIsle_Interior_Text_FinallyCaughtYou:
	.string "Ah-ha!\n"
	.string "I finally caught you!\p"
	.string "ARIADOS, use STICKY WEB!$"

ShamrockIsle_Interior_Text_OneLiner:
	.string "Urgh...\n"
	.string "Talk about meeting a sticky end...$"

ShamrockIsle_Interior_Text_ThanksForTheHelp:
	.string "I'll take care of things from here.\p"
	.string "Thanks for stopping the poachers.\n"
	.string "I really owe you one.\p"
	.string "Here, you can have this for your trouble.$"






