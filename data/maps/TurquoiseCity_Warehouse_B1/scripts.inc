.set LOCALID_JACE, 6
.set LOCALID_LITTLEGIRL, 7
.set LOCALID_BRENDAN, 5
.set LOCALID_ZARTOSHT, 11
.set LOCALID_GRUNT1, 3
.set LOCALID_GRUNT2, 1
.set LOCALID_GRUNT3, 4
.set LOCALID_GRUNT4, 2
.set LOCALID_GRUNT5, 12
.set LOCALID_DEVON, 9
.set LOCALID_MILO, 10

TurquoiseCity_Warehouse_B1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TurquoiseCity_Warehouse_B1_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TurquoiseCity_Warehouse_B1_OnFrame
	.byte 0

TurquoiseCity_Warehouse_B1_OnFrame:
	map_script_2 VAR_TURQUOISE_CITY_STATE, 1, TurquoiseCity_Warehouse_B1_EventScript_MeetJaceAgain
	.2byte 0

TurquoiseCity_Warehouse_B1_OnTransition:
	@call_if_le VAR_TURQUOISE_CITY_STATE, 2, TurquoiseCity_Warehouse_B1_EventScript_RevealJace
	call_if_eq VAR_TURQUOISE_CITY_STATE, 2, TurquoiseCity_Warehouse_B1_EventScript_MoveJaceToBehindBeam
	end

@TurquoiseCity_Warehouse_B1_EventScript_RevealJace::
@	clearflag FLAG_HIDE_JACE
@	return

TurquoiseCity_Warehouse_B1_EventScript_MoveJaceToBehindBeam::
	setobjectxyperm LOCALID_JACE, 6, 13
	setobjectmovementtype LOCALID_JACE, MOVEMENT_TYPE_FACE_LEFT
	addobject LOCALID_JACE
	return

TurquoiseCity_Warehouse_B1_EventScript_MeetJaceAgain::
	lockall
	applymovement LOCALID_JACE, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	delay 60
	msgbox TurquoiseCity_Warehouse_B1_Text_JustAsIThought, MSGBOX_DEFAULT
	closemessage
	delay 10
	applymovement LOCALID_LITTLEGIRL, Common_Movement_FaceUp
	waitmovement 0
	delay 20
	msgbox TurquoiseCity_Warehouse_B1_Text_TookPokemonAway, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LITTLEGIRL, Common_Movement_FaceDown
	waitmovement 0
	delay 60
	applymovement LOCALID_JACE, Common_Movement_FaceRight
	waitmovement 0
	delay 40
	applymovement LOCALID_JACE, Common_Movement_FaceUp
	waitmovement 0
	delay 20
	msgbox TurquoiseCity_Warehouse_B1_Text_LetsGoCheckItOut, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JACE, TurquoiseCity_Warehouse_B1_Movement_JaceWalkDown
	waitmovement 0
	removeobject LOCALID_JACE
	call TurquoiseCity_Warehouse_B1_EventScript_MoveJaceToBehindBeam
	clearflag FLAG_TURQUOISE_CITY_FREED
	setvar VAR_TURQUOISE_CITY_STATE, 2
	releaseall
	end






TurquoiseCity_Warehouse_B1_Movement_JaceWalkDown:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

TurquoiseCity_Warehouse_B1_Text_JustAsIThought:
	.string "{PLAYER}!\n"
	.string "It's just as I thought.\p"
	.string "These people were captured and\n"
	.string "brought here by TEAM GENESIS!$"

TurquoiseCity_Warehouse_B1_Text_TookPokemonAway:
	.string "Sniff.\n"
	.string "They took my SKIPLOOM away...$"

TurquoiseCity_Warehouse_B1_Text_LetsGoCheckItOut:
	.string "I think something is going on\n"
	.string "over there.\p"
	.string "C'mon, let's check it out.$"

TurquoiseCity_Warehouse_B1_EventScript_LittleGirl::
	msgbox TurquoiseCity_Warehouse_B1_Text_LittleGirl, MSGBOX_NPC
	closemessage
	end

TurquoiseCity_Warehouse_B1_Text_LittleGirl:
	.string "Sniff.\n"
	.string "Where's SKIPPY?$"

TurquoiseCity_Warehouse_B1_EventScript_OldMan::
	msgbox TurquoiseCity_Warehouse_B1_Text_OldMan, MSGBOX_NPC
	closemessage
	end

TurquoiseCity_Warehouse_B1_Text_OldMan:
	.string "I tried to stop them.\n"
	.string "But they were too strong...\p"
	.string "Don't underestimate their leader.\p"
	.string "His POKéMON are like nothing\n"
	.string "I've ever seen before.$"

TurquoiseCity_Warehouse_B1_EventScript_TeamGenesisScene::
	lockall
	applymovement LOCALID_JACE, Common_Movement_FaceRight
	waitmovement 0
	delay 20
	applymovement LOCALID_JACE, Common_Movement_FaceLeft
	waitmovement 0
	fadeoutbgm 0
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, TurquoiseCity_Warehouse_B1_Movement_CameraPanUp
	waitmovement 0
	playbgm MUS_WEATHER_GROUDON, FALSE
	delay 60
	applymovement LOCALID_ZARTOSHT, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox TurquoiseCity_Warehouse_B1_Text_WhatAJoke, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_MILO, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox TurquoiseCity_Warehouse_B1_Text_Urgh, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ZARTOSHT, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_ZARTOSHT, Common_Movement_FaceDown
	waitmovement 0
	delay 20
	msgbox TurquoiseCity_Warehouse_B1_Text_WontNeedThose, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_ZARTOSHT, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_ZARTOSHT, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_ZARTOSHT, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	msgbox TurquoiseCity_Warehouse_B1_Text_ZartoshtInterrogates, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_DEVON, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_DEVON, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_DEVON, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox TurquoiseCity_Warehouse_B1_Text_OhDear, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_ZARTOSHT, Common_Movement_WalkRight
	waitmovement 0
	delay 60
	msgbox TurquoiseCity_Warehouse_B1_Text_NotGoodForMe, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_ZARTOSHT, Common_Movement_FaceUp
	waitmovement 0
	delay 30
	applymovement LOCALID_ZARTOSHT, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	msgbox TurquoiseCity_Warehouse_B1_Text_WeldPokeball, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_MILO, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox TurquoiseCity_Warehouse_B1_Text_AhWait, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox TurquoiseCity_Warehouse_B1_Text_DontDoThat, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox TurquoiseCity_Warehouse_B1_Text_StartTalking, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MILO, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_MILO, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox TurquoiseCity_Warehouse_B1_Text_MiloNo, MSGBOX_DEFAULT
	closemessage
	msgbox TurquoiseCity_Warehouse_B1_Text_JaceStopThat, MSGBOX_DEFAULT
	closemessage
	delay 30
	@fadeoutbgm 0
	applymovement LOCALID_GRUNT1, Common_Movement_FaceDown
	applymovement LOCALID_GRUNT2, Common_Movement_FaceDown
	applymovement LOCALID_GRUNT3, Common_Movement_FaceDown
	applymovement LOCALID_GRUNT4, Common_Movement_FaceDown
	applymovement LOCALID_GRUNT5, Common_Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_GRUNT5, Common_Movement_ExclamationMark
	applymovement LOCALID_GRUNT1, Common_Movement_ExclamationMark
	applymovement LOCALID_GRUNT2, Common_Movement_ExclamationMark
	applymovement LOCALID_GRUNT3, Common_Movement_ExclamationMark
	applymovement LOCALID_GRUNT4, Common_Movement_ExclamationMark
	applymovement LOCALID_ZARTOSHT, Common_Movement_ExclamationMark
	waitmovement 0
	@playbgm MUS_ENCOUNTER_MAGMA, FALSE
	applymovement LOCALID_JACE, TurquoiseCity_Warehouse_B1_Movement_JaceEntrance
	waitmovement 0
	delay 40
	msgbox TurquoiseCity_Warehouse_B1_Text_ZartoshtWhoAreYou, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceUp
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox TurquoiseCity_Warehouse_B1_Text_JaceIntro, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_JACE, Common_Movement_FaceDown
	waitmovement 0
	delay 20
	msgbox TurquoiseCity_Warehouse_B1_Text_JaceBackMeUp, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, TurquoiseCity_Warehouse_B1_Movement_PlayerEntrance
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_FaceUp
	waitmovement 0
	delay 30
	msgbox TurquoiseCity_Warehouse_B1_Text_ComingOutOfTheWoodwork, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ZARTOSHT, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCALID_ZARTOSHT, Common_Movement_FaceRight
	waitmovement 0
	msgbox TurquoiseCity_Warehouse_B1_Text_IThoughtIToldYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT3, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_GRUNT4, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox TurquoiseCity_Warehouse_B1_Text_WeDidBoss, MSGBOX_DEFAULT
	closemessage
	delay 40
	applymovement LOCALID_ZARTOSHT, Common_Movement_FaceDown
	waitmovement 0
	delay 80
	msgbox TurquoiseCity_Warehouse_B1_Text_BeenHereTooLong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT3, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox TurquoiseCity_Warehouse_B1_Text_WereSorryBoss, MSGBOX_DEFAULT
	closemessage
	delay 40
	applymovement LOCALID_ZARTOSHT, Common_Movement_FaceUp
	waitmovement 0
	delay 80
	applymovement LOCALID_ZARTOSHT, Common_Movement_FaceDown
	waitmovement 0
	msgbox TurquoiseCity_Warehouse_B1_Text_ChangeOfPlans, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_GRUNT2, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_GRUNT2, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_DEVON, Common_Movement_WalkUp
	applymovement LOCALID_GRUNT2, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_DEVON, Common_Movement_WalkUp
	applymovement LOCALID_GRUNT2, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_DEVON, Common_Movement_WalkUp
	applymovement LOCALID_GRUNT2, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_DEVON, Common_Movement_WalkUp
	applymovement LOCALID_GRUNT2, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_DEVON, Common_Movement_WalkUp
	applymovement LOCALID_GRUNT2, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_DEVON, Common_Movement_WalkUp
	applymovement LOCALID_GRUNT2, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_DEVON, Common_Movement_WalkUp
	applymovement LOCALID_GRUNT2, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_GRUNT1, Common_Movement_FaceRight
	waitmovement 0
	msgbox TurquoiseCity_Warehouse_B1_Text_WhatAboutPokeballs, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_ZARTOSHT, Common_Movement_FaceLeft
	waitmovement 0
	delay 40
	msgbox TurquoiseCity_Warehouse_B1_Text_DumpInBay, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_JACE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	msgbox TurquoiseCity_Warehouse_B1_Text_HowCanYouSayThat, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_ZARTOSHT, Common_Movement_FaceDown
	waitmovement 0
	delay 60
	msgbox TurquoiseCity_Warehouse_B1_Text_WhatAreYouGonnaDoAboutIt, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox TurquoiseCity_Warehouse_B1_Text_IDontCareWhoYouAre, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_JACE, Common_Movement_FaceLeft
	waitmovement 0
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox TurquoiseCity_Warehouse_B1_Text_ComeOnPlayer, MSGBOX_DEFAULT
	closemessage
	delay 40
	applymovement LOCALID_JACE, Common_Movement_FaceUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	delay 80
	msgbox TurquoiseCity_Warehouse_B1_Text_LessonOnPower, MSGBOX_DEFAULT
	closemessage
	@delay 20
	applymovement LOCALID_GRUNT1, Common_Movement_FaceDown
	applymovement LOCALID_GRUNT5, Common_Movement_FaceDown
	applymovement LOCALID_GRUNT3, Common_Movement_FaceDown
	applymovement LOCALID_GRUNT4, Common_Movement_FaceDown
	waitmovement 0
	playbgm MUS_ENCOUNTER_MAGMA, TRUE
	msgbox TurquoiseCity_Warehouse_B1_Text_YesSir, MSGBOX_DEFAULT
	closemessage
	@delay 40
	applymovement LOCALID_GRUNT1, Common_Movement_WalkDown
	applymovement LOCALID_GRUNT5, Common_Movement_WalkDown
	applymovement LOCALID_GRUNT3, Common_Movement_WalkDown
	applymovement LOCALID_GRUNT4, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_GRUNT1, Common_Movement_WalkDown
	applymovement LOCALID_GRUNT5, Common_Movement_WalkDown
	applymovement LOCALID_GRUNT3, Common_Movement_WalkDown
	applymovement LOCALID_GRUNT4, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_GRUNT1, Common_Movement_FaceRight
	applymovement LOCALID_GRUNT5, Common_Movement_FaceRight
	applymovement LOCALID_GRUNT3, Common_Movement_FaceLeft
	applymovement LOCALID_GRUNT4, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	delay 60
	applymovement LOCALID_GRUNT5, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox TurquoiseCity_Warehouse_B1_Text_Grunt1Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_TURQUOISE_CITY_1, TurquoiseCity_Warehouse_B1_Text_Grunt1Defeated
	@playbgm MUS_ENCOUNTER_MAGMA, FALSE
	applymovement LOCALID_GRUNT5, TurquoiseCity_Warehouse_B1_Movement_KnockedBackLeft
	waitmovement 0
	applymovement LOCALID_GRUNT1, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox TurquoiseCity_Warehouse_B1_Text_Grunt2Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_TURQUOISE_CITY_2, TurquoiseCity_Warehouse_B1_Text_Grunt2Defeated
	@playbgm MUS_ENCOUNTER_MAGMA, FALSE
	applymovement LOCALID_GRUNT1, TurquoiseCity_Warehouse_B1_Movement_KnockedBackLeft
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox TurquoiseCity_Warehouse_B1_Text_JaceHealPlayer, MSGBOX_DEFAULT
	closemessage
	special HealPlayerParty
	playse SE_USE_ITEM
	waitse
	msgbox TurquoiseCity_Warehouse_B1_Text_PlayerFullyHealed, MSGBOX_DEFAULT
	@playse SE_USE_ITEM
	@waitse
	closemessage
	msgbox TurquoiseCity_Warehouse_B1_Text_JaceGoForPokeballs, MSGBOX_DEFAULT
	closemessage
	@special SpawnCameraObject
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	delay 80
	applymovement LOCALID_ZARTOSHT, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox TurquoiseCity_Warehouse_B1_Text_ZartoshtIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ZARTOSHT_1, TurquoiseCity_Warehouse_B1_Text_ZartoshtDefeated
	@playbgm MUS_ENCOUNTER_MAGMA, FALSE
	applymovement LOCALID_GRUNT3, TurquoiseCity_Warehouse_B1_Movement_KnockedBackRight
	applymovement LOCALID_GRUNT4, TurquoiseCity_Warehouse_B1_Movement_KnockedBackRight
	waitmovement 0
	delay 30
	msgbox TurquoiseCity_Warehouse_B1_Text_WeaponS, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JACE, Common_Movement_WalkUp
	waitmovement 0
	delay 60
	msgbox TurquoiseCity_Warehouse_B1_Text_JaceGivePokemonBack, MSGBOX_DEFAULT
	closemessage
	delay 80
	msgbox TurquoiseCity_Warehouse_B1_Text_YouLittleBrat, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_BRENDAN
	addobject LOCALID_BRENDAN
	fadeoutbgm 0
	msgbox TurquoiseCity_Warehouse_B1_Text_StopRightThere, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_JACE, Common_Movement_FaceDown
	applymovement LOCALID_GRUNT1, Common_Movement_FaceDown
	applymovement LOCALID_GRUNT5, Common_Movement_FaceDown
	applymovement LOCALID_GRUNT3, Common_Movement_FaceDown
	applymovement LOCALID_GRUNT4, Common_Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement LOCALID_JACE, Common_Movement_ExclamationMark
	applymovement LOCALID_GRUNT1, Common_Movement_ExclamationMark
	applymovement LOCALID_GRUNT5, Common_Movement_ExclamationMark
	applymovement LOCALID_GRUNT3, Common_Movement_ExclamationMark
	applymovement LOCALID_GRUNT4, Common_Movement_ExclamationMark
	applymovement LOCALID_ZARTOSHT, Common_Movement_ExclamationMark
	waitmovement 0
	delay 80
	playbgm MUS_RG_TITLE, FALSE
	@special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, TurquoiseCity_Warehouse_B1_Movement_CameraPanDown
	waitmovement 0
	applymovement LOCALID_BRENDAN, TurquoiseCity_Warehouse_B1_Movement_BrendanEntrance
	waitmovement 0
	delay 40
	applymovement LOCALID_GRUNT1, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_GRUNT1, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox TurquoiseCity_Warehouse_B1_Text_GruntMasaka, MSGBOX_DEFAULT
	closemessage
	delay 40
	msgbox TurquoiseCity_Warehouse_B1_Text_ZartoshtMasaka, MSGBOX_DEFAULT
	closemessage
	delay 60
	fadedefaultbgm
	applymovement LOCALID_BRENDAN, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox TurquoiseCity_Warehouse_B1_Text_ItsAHat, MSGBOX_DEFAULT
	closemessage
	@fadedefaultbgm
	applymovement LOCALID_GRUNT1, Common_Movement_FaceRight
	applymovement LOCALID_GRUNT5, Common_Movement_FaceUp
	applymovement LOCALID_GRUNT3, Common_Movement_FaceUp
	applymovement LOCALID_GRUNT4, Common_Movement_FaceLeft
	waitmovement 0
	delay 30
	applymovement LOCALID_GRUNT1, Common_Movement_FaceDown
	applymovement LOCALID_GRUNT5, Common_Movement_FaceRight
	applymovement LOCALID_GRUNT3, Common_Movement_FaceLeft
	applymovement LOCALID_GRUNT4, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	applymovement LOCALID_GRUNT1, Common_Movement_FaceUp
	applymovement LOCALID_GRUNT5, Common_Movement_FaceUp
	applymovement LOCALID_GRUNT3, Common_Movement_FaceUp
	applymovement LOCALID_GRUNT4, Common_Movement_FaceUp
	waitmovement 0
	delay 60
	applymovement LOCALID_ZARTOSHT, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox TurquoiseCity_Warehouse_B1_Text_WasntPreparedForThis, MSGBOX_DEFAULT
	closemessage
	@fadescreen FADE_TO_BLACK
	@fadeoutbgm 0
	@delay 80
	setvar VAR_TURQUOISE_CITY_STATE, 3
	setflag FLAG_TURQUOISE_CITY_FREED
	clearflag FLAG_TURQUOISE_CITY_OCCUPIED
	@playse SE_EXIT
	warp MAP_TURQUOISE_CITY, 7, 22
	waitstate
	releaseall
	end









TurquoiseCity_Warehouse_B1_Text_WhatAJoke:
	.string "????????: Hahahahahahahaha!\p"
	.string "You thought you could protect anyone\n"
	.string "with pathetic POKéMON like that?\p"
	.string "What a joke.$"

TurquoiseCity_Warehouse_B1_Text_Urgh:
	.string "????: Urgh...\n"
	.string "My POKéMON...$"

TurquoiseCity_Warehouse_B1_Text_WontNeedThose:
	.string "You won't be needing those right now.\n"
	.string "We'll hold on to them for you.\p"
	.string "Now then, the man of the hour.$"

TurquoiseCity_Warehouse_B1_Text_ZartoshtInterrogates:
	.string "You're from DEVON, right?\p"
	.string "Word on the street is you guys have been\n"
	.string "working on special POKé BALLS lately.\p"
	.string "Why don't you tell us about the designs\n"
	.string "you were carrying?\p" 
	.string "We already checked your briefcase,\n"
	.string "and they weren't in there.\p"
	.string "So tell me, where'd you hide them?$"

TurquoiseCity_Warehouse_B1_Text_OhDear:
	.string "Oh dear, this is all\n"
	.string "a big misunderstanding!\p"
	.string "I'm not carrying anything like that!\p"
	.string "I just work on POKé BALLS.\n" 
	.string "I don't design them myself...$"

TurquoiseCity_Warehouse_B1_Text_NotGoodForMe:
	@.string "????????: See, that's not good for me.\p"
	.string "See, that's not good for me.\p"
	.string "You were supposed to be carrying\n"
	.string "designs for a new prototype.\p"
	.string "And you were supposed to hand\n"
	.string "those designs over to me.\p"
	.string "When I don't get what I want,\n"
	.string "it makes me angry.\p"
	@.string "I get a little tense.\p"
	.string "And then I need a little\n"
	.string "something for my nerves...$"
	@.string "to take the edge off.$"

TurquoiseCity_Warehouse_B1_Text_WeldPokeball:
	.string "You're a POKé BALL expert, right?\p"
	.string "What happens if you weld one\n"
	.string "of these shut?$"

TurquoiseCity_Warehouse_B1_Text_AhWait:
	.string "Ah wait, my POKéMON are in there!$"

TurquoiseCity_Warehouse_B1_Text_DontDoThat:
	.string "No please, don't do that!\p"
	.string "If you damage the central frame,\n"
	.string "the air can't circulate properly!$"

TurquoiseCity_Warehouse_B1_Text_StartTalking:
	.string "Then tell me something I like.\p"
	.string "Tell me everything you know about what\n"
	.string "DEVON has been working on lately.\p"
	.string "The BEAST BALL, I think\n"
	.string "you guys call it?\p"
	.string "If I like what I hear, I might let\n"
	@.string "this kid's POKéMON off the hook.\p"
	.string "you guys off the hook.\p"
	.string "But you'd better get to the\n"
	.string "good parts fast.\p"
	.string "Because I get bored pretty quickly...$"

TurquoiseCity_Warehouse_B1_Text_MiloNo:
	.string "No! My POKéMON!$"

TurquoiseCity_Warehouse_B1_Text_JaceStopThat:
	.string "JACE: Hey! Stop that!$"

TurquoiseCity_Warehouse_B1_Text_ZartoshtWhoAreYou:
	@.string "????????: Eh? Who are you?\n"
	.string "Eh? Who are you?\n"
	.string "And how'd you get in here?$"

TurquoiseCity_Warehouse_B1_Text_JaceIntro:
	.string "JACE: I'm JACE from UMBER TOWN.\p"
	.string "I'm gonna be the next\n"
	.string "POKéMON LEAGUE CHAMPION!$"

TurquoiseCity_Warehouse_B1_Text_JaceBackMeUp:
	.string "Hey, back me up here, {PLAYER}.$"

TurquoiseCity_Warehouse_B1_Text_ComingOutOfTheWoodwork:
	@.string "????????: More POKéMON trainers?\p"
	.string "More POKéMON trainers?\p"
	.string "You all just keep coming out\n"
	.string "of the woodwork.$"

TurquoiseCity_Warehouse_B1_Text_IThoughtIToldYou:
	.string "I thought I told you guys to round up\n"
	.string "all the POKéMON in this city.$"

TurquoiseCity_Warehouse_B1_Text_WeDidBoss:
	.string "We did, boss! We've never\n"
	.string "seen these kids before!\p"
	.string "They must've gotten here after\n"
	.string "we took over.$"

TurquoiseCity_Warehouse_B1_Text_BeenHereTooLong:
	@.string "????????: We've been here too long.\p"
	.string "We've been here too long...\p"
	.string "I could've made this guy talk hours ago.\p"
	.string "If you numbskulls hadn't taken so long\n"
	.string "to find him.$"

TurquoiseCity_Warehouse_B1_Text_WereSorryBoss:
	.string "We're sorry, boss!\p"
	.string "How could we know all these trainers\n"
	.string "would show up to help him?$"

TurquoiseCity_Warehouse_B1_Text_ChangeOfPlans:
	@.string "????????: Change of plans.\p"
	.string "Change of plans.\n"
	.string "We take the DEVON scientist with us.$"

TurquoiseCity_Warehouse_B1_Text_WhatAboutPokeballs:
	.string "What about the POKé BALLS we stole?$"

TurquoiseCity_Warehouse_B1_Text_DumpInBay:
	@.string "????????: The POKéMON inside are\n"
	.string "The POKéMON inside are\n"
	.string "all worthless.\p"
	.string "Just dump them in the bay.$"

TurquoiseCity_Warehouse_B1_Text_HowCanYouSayThat:
	.string "JACE: What!? How can you say that?\n"
	.string "Those POKéMON belong to people!\p"
	.string "You don't even want them!\n"
	.string "Just give them back!$"

TurquoiseCity_Warehouse_B1_Text_WhatAreYouGonnaDoAboutIt:
	@.string "????????: And what are you gonna\n"
	.string "And what are you gonna\n"
	.string "do about it, kid?\p"
	.string "You wanna play hero?\n"
	.string "You wanna save all the POKéMON?\p"
	.string "That's what this kid thought too.\n"
	.string "And now look at him.\l"
	.string "He can't even save his own POKéMON!\p"
	.string "You see, we don't have to listen\n"
	.string "to snot-nosed kids.\p" 
	.string "Or anybody else for that matter.\p"
	.string "We're TEAM GENESIS.\n"
	.string "Our POKéMON are a superior breed!\p"
	.string "You could say that we're like, the next\n"
	.string "stage of evolution or something.\p"
	.string "The people in this warehouse\n"
	.string "learned that the hard way.\p"
	.string "If you know what's good for you, you'll\n"
	.string "forget about this and get outta here.\p"
	.string "But hey, if you want to lose\n"
	.string "your POKéMON too, be my guest.$"

TurquoiseCity_Warehouse_B1_Text_IDontCareWhoYouAre:
	.string "JACE: I don't care who you think you are!\n"
	.string "What you're doing is cruel!\p"
	.string "I'm not gonna let you do get away with it.$"

TurquoiseCity_Warehouse_B1_Text_ComeOnPlayer:
	.string "JACE: Come on, {PLAYER}.\n"
	.string "It looks like we have to fight these guys.$"
	@.string "guys to get those POKéMON back.$"

TurquoiseCity_Warehouse_B1_Text_LessonOnPower:
	@.string "????????: Looks like you need a lesson\n"
	.string "Looks like you need a lesson\n"
	.string "on what power is.\p"
	.string "Boys, show these kids what I mean.$"

TurquoiseCity_Warehouse_B1_Text_YesSir:
	.string "Yes sir!$"

TurquoiseCity_Warehouse_B1_Text_Grunt1Intro:
	.string "TEAM GENESIS will take you apart\n"
	.string "piece by piece!$"

TurquoiseCity_Warehouse_B1_Text_Grunt1Defeated:
	.string "No way! My perfect POKéMON!$"

TurquoiseCity_Warehouse_B1_Text_Grunt2Intro:
	.string "I'm next! Don't think we'll give\n"
	.string "you kids a chance to rest!$"

TurquoiseCity_Warehouse_B1_Text_Grunt2Defeated:
	.string "Hey, that's not fair!$"



TurquoiseCity_Warehouse_B1_Text_JaceHealPlayer:
	.string "JACE: Man, these guys are tough.\p"
	.string "{PLAYER}, here take these.$"

TurquoiseCity_Warehouse_B1_Text_PlayerFullyHealed:
	.string "{PLAYER} and the POKéMON were fully healed.$"

TurquoiseCity_Warehouse_B1_Text_JaceGoForPokeballs:
	.string "JACE: See if you can get\n"
	.string "those POKé BALLS back.$"

TurquoiseCity_Warehouse_B1_Text_ZartoshtIntro:
	@.string "????????: You beat my grunts.\n"
	.string "You beat my grunts.\n"
	.string "I can see you're no pushover.\p"
	.string "But my POKéMON are on another level.\p"
	.string "I'll show you what makes\n"
	.string "TEAM GENESIS supreme!$"

TurquoiseCity_Warehouse_B1_Text_ZartoshtDefeated:
	.string "I don't believe it!$"

TurquoiseCity_Warehouse_B1_Text_WeaponS:
	.string "ZARTOSHT: WEAPON S is supposed\n"
	.string "to be invincible!\p"
	.string "How could it lose to a kid like you?$"

TurquoiseCity_Warehouse_B1_Text_JaceGivePokemonBack:
	.string "JACE: Alright, we beat you guys.\n"
	.string "Now give those POKéMON back!$"

TurquoiseCity_Warehouse_B1_Text_YouLittleBrat:
	.string "ZARTOSHT: You little brat.\n"
	.string "You think this is over?\p"
	.string "I've got plenty more POKéMON with me.\n"
	.string "I'll grind you both into dust.\p"
	.string "Let's see you stand up to this!$"

TurquoiseCity_Warehouse_B1_Text_StopRightThere:
	.string "???????: Stop right there, TEAM GENESIS!$"

TurquoiseCity_Warehouse_B1_Text_GruntMasaka:
	.string "B-boss! Is that...?!$"

TurquoiseCity_Warehouse_B1_Text_ZartoshtMasaka:
	.string "ZARTOSHT: It can't be...\p"
	.string "White hair...\n"
	.string "You must be BRENDAN!\p"
	.string "What's a powerful trainer from HOENN\n"
	.string "doing all the way out here?!$"

TurquoiseCity_Warehouse_B1_Text_ItsAHat:
	.string "BRENDAN: It's a hat, actually.\p"
	.string "And I'm here to stop you from\n"
	.string "terrorizing this city!\p"
	.string "I won't let you do as you please anymore!$"

TurquoiseCity_Warehouse_B1_Text_WasntPreparedForThis:
	.string "ZARTOSHT: I wasn't prepared for this...\p"
	.string "Alright, you win.\n"
	.string "We'll retreat, for now.$"

TurquoiseCity_Warehouse_B1_Movement_CameraPanUp:
	delay_16
	delay_16
	walk_left
	walk_up
	walk_left
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

TurquoiseCity_Warehouse_B1_Movement_CameraPanDown:
	@delay_16
	@delay_16
	walk_down
	walk_down
	step_end

TurquoiseCity_Warehouse_B1_Movement_JaceEntrance:
	walk_left
	@walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

TurquoiseCity_Warehouse_B1_Movement_PlayerEntrance:
	walk_left
	walk_left
	walk_left
	walk_left
	@walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

TurquoiseCity_Warehouse_B1_Movement_KnockedBackLeft:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

TurquoiseCity_Warehouse_B1_Movement_KnockedBackRight:
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

TurquoiseCity_Warehouse_B1_Movement_BrendanEntrance:
	@walk_up
	@walk_up
	@walk_up
	walk_up
	walk_up
	walk_up
	step_end










