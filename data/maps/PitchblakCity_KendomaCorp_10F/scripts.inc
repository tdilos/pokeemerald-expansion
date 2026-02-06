.set LOCALID_OSRIC, 1
.set LOCALID_NEDA, 2

PitchblakCity_KendomaCorp_10F_MapScripts::
	.byte 0

PitchblakCity_KendomaCorp_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_KENDOMA_CORP_1, PitchblakCity_KendomaCorp_Text_GruntKendomaCorp1Intro, PitchblakCity_KendomaCorp_Text_GruntKendomaCorp1Defeated
	msgbox PitchblakCity_KendomaCorp_Text_GruntKendomaCorp1PostBattle, MSGBOX_AUTOCLOSE
	end

PitchblakCity_KendomaCorp_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_KENDOMA_CORP_2, PitchblakCity_KendomaCorp_Text_GruntKendomaCorp2Intro, PitchblakCity_KendomaCorp_Text_GruntKendomaCorp2Defeated
	msgbox PitchblakCity_KendomaCorp_Text_GruntKendomaCorp2PostBattle, MSGBOX_AUTOCLOSE
	end

PitchblakCity_KendomaCorp_Text_GruntKendomaCorp1Intro:
	.string "Halt! This area's off limits!$"

PitchblakCity_KendomaCorp_Text_GruntKendomaCorp1Defeated:
	.string "Nothing to see here.$"

PitchblakCity_KendomaCorp_Text_GruntKendomaCorp1PostBattle:
	.string "What's a kid like you doing in a place\n"
	.string "like this anyway?$"

PitchblakCity_KendomaCorp_Text_GruntKendomaCorp2Intro:
	.string "There's no need to bother the commander.\n"
	.string "I'll take you out myself.$"

PitchblakCity_KendomaCorp_Text_GruntKendomaCorp2Defeated:
	.string "I... lost...$"

PitchblakCity_KendomaCorp_Text_GruntKendomaCorp2PostBattle:
	.string "The commander's gonna be so\n"
	.string "angry with me...$"









PitchblakCity_KendomaCorp_EventScript_NedaEncounter::
	lockall
	fadeoutbgm 0
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, KendomaCorp_Movement_CameraPanUp
	waitmovement 0
	playbgm MUS_WEATHER_GROUDON, FALSE
	delay 50
	applymovement LOCALID_OSRIC, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox PitchblakCity_KendomaCorp_Text_YouGotTheWrongIdea, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox PitchblakCity_KendomaCorp_Text_WeKnowEverything, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_OSRIC, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox PitchblakCity_KendomaCorp_Text_WhatWasISupposedToDo, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox PitchblakCity_KendomaCorp_Text_SoThatsIt, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_OSRIC, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox PitchblakCity_KendomaCorp_Text_NotYourFriend, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox PitchblakCity_KendomaCorp_Text_BetterThanUs, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox PitchblakCity_KendomaCorp_Text_TakeWhatYouLike, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_NEDA, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox PitchblakCity_KendomaCorp_Text_YoureComingWithMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OSRIC, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	msgbox PitchblakCity_KendomaCorp_Text_WhyMe, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox PitchblakCity_KendomaCorp_Text_NotQuite, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox PitchblakCity_KendomaCorp_Text_YoureCrazy, MSGBOX_DEFAULT
	closemessage
	delay 120
	msgbox PitchblakCity_KendomaCorp_Text_YoureCrazy2, MSGBOX_DEFAULT
	closemessage
	@fadeoutbgm 0
	applymovement LOCALID_OSRIC, KendomaCorp_Movement_EscapeAttempt
	waitmovement 0
	playse SE_M_SUPERSONIC
	waitse
	applymovement LOCALID_OSRIC, Common_Movement_ExclamationMark
	waitmovement 0
	@delay 48
	fadeoutbgm 0
	applymovement LOCALID_NEDA, Common_Movement_FaceDown
	waitmovement 0
	delay 60
	msgbox PitchblakCity_KendomaCorp_Text_RestrainHim, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_DEOXYS, CRY_MODE_NORMAL
	delay 30
	applymovement LOCALID_OSRIC, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	msgbox PitchblakCity_KendomaCorp_Text_Gyah, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement OBJ_EVENT_ID_CAMERA, KendomaCorp_Movement_CameraPanDown
	waitmovement 0
	special RemoveCameraObject
	msgbox PitchblakCity_KendomaCorp_Text_OsricHelp, MSGBOX_DEFAULT
	closemessage
	delay 40
	applymovement LOCALID_NEDA, Common_Movement_WalkDown
	waitmovement 0
	delay 20
	playbgm MUS_ENCOUNTER_MAGMA, TRUE
	msgbox PitchblakCity_KendomaCorp_Text_NedaWhatsThis, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PitchblakCity_KendomaCorp_EventScript_NedaPreBattle
	closemessage
	delay 60
	msgbox PitchblakCity_KendomaCorp_Text_SmartChoice, MSGBOX_DEFAULT
	goto PitchblakCity_KendomaCorp_EventScript_NedaBattle
	end


PitchblakCity_KendomaCorp_EventScript_NedaPreBattle::
	closemessage
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	delay 60
	applymovement LOCALID_NEDA, Common_Movement_WalkInPlaceDown
	waitmovement 0
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, PitchblakCity_KendomaCorp_EventScript_BraveBoy
	goto_if_eq VAR_RESULT, FEMALE, PitchblakCity_KendomaCorp_EventScript_BraveGirl
	end

PitchblakCity_KendomaCorp_EventScript_BraveBoy::
	msgbox PitchblakCity_KendomaCorp_Text_BraveOfYouBoy, MSGBOX_DEFAULT
	closemessage
	goto PitchblakCity_KendomaCorp_EventScript_NedaBattle
	end

PitchblakCity_KendomaCorp_EventScript_BraveGirl::
	msgbox PitchblakCity_KendomaCorp_Text_BraveOfYouGirly, MSGBOX_DEFAULT
	closemessage
	goto PitchblakCity_KendomaCorp_EventScript_NedaBattle
	end

PitchblakCity_KendomaCorp_EventScript_NedaBattle::
	trainerbattle_no_intro TRAINER_NEDA_1, PitchblakCity_KendomaCorp_Text_NedaDefeated
	delay 30
	msgbox PitchblakCity_KendomaCorp_Text_NedaPostBattle, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_OSRIC, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	msgbox PitchblakCity_KendomaCorp_Text_WaitNeda, MSGBOX_DEFAULT
	closemessage
	@fadeoutbgm 0
	setvar VAR_PITCHBLAK_CITY_STATE, 2
	delay 10
	warpsilent MAP_MT_SHIRO_SUMMIT, 12, 9 	@portal and void sequence handled in MtShiroSummit
	@warpsilent MAP_PITCHBLAK_CITY, 46, 16
	waitstate
	releaseall
	end

PitchblakCity_KendomaCorp_Text_YouGotTheWrongIdea:
	.string "?????: Hey look, NEDA, you've got\n"
	.string "the wrong idea.\p"
	.string "This project you're talking about was\n"
	.string "for medical research.\p"
	.string "And anyway, it doesn't matter anymore.\n"
	.string "It's defunct. Check the records yourself.$"

PitchblakCity_KendomaCorp_Text_WeKnowEverything:
	.string "NEDA: Enough with the half-truths, OSRIC.\n"
	.string "We know everything.\p"
	.string "We know you wanted to replace us.\p"
	.string "We know you're the one who tipped off the\n"
	.string "authorities to our whereabouts.\p"
	.string "You tried to cut us out. And for what?\p"
	.string "We always upheld our end of the deal.\p"
	.string "Hasn't your company thrived\n"
	.string "because of us?$"

PitchblakCity_KendomaCorp_Text_WhatWasISupposedToDo:
	.string "Yeah, until you guys went picking a\n"
	.string "fight with the RANGERS.\p"
	.string "You got them looking into where TEAM\n"
	.string "GENESIS gets all their fancy tech.\p"
	.string "Now the LEAGUE itself is breathing down\n"
	.string "my neck. What was I supposed to do?$"

PitchblakCity_KendomaCorp_Text_SoThatsIt:
	.string "NEDA: So that's it then.\n"
	.string "You sold us out to save yourself.\p"
	.string "Get rich off our work and wash your\n"
	.string "hands of us when it's no longer\l"
	.string "convenient for you?\p"
	.string "Is that how you treat your friends?$"

PitchblakCity_KendomaCorp_Text_NotYourFriend:
	.string "Now look, don't start talking like\n"
	.string "we're friends. This was strictly business.\p"
	.string "You know I never liked your methods.\p"
	.string "I told you it would come back\n"
	.string "to bite you one day.\p"
	.string "You're a liability I can't afford\n"
	.string "to have anymore!$"

PitchblakCity_KendomaCorp_Text_BetterThanUs:
	.string "NEDA: You think you're better\n"
	.string "than us, do you?\p"
	.string "In that case, we'll be taking back all\n"
	.string "the samples we obtained for you.\p"
	.string "You're so pure and righteous.\p"
	.string "You wouldn't want the fruits of our\n"
	.string "dirty work to stain your moral legacy.\p"
	.string "The Kynnad Archives, Project Aldmann,\n"
	.string "and what's left of Project Rayner.\p"
	.string "All of it belongs to TEAM GENESIS now.$"

PitchblakCity_KendomaCorp_Text_TakeWhatYouLike:
	.string "OSRIC: Take whatever you like.\p"
	.string "You guys are living on borrowed time now,\n"
	.string "and you're nuts if you think otherwise.\p"
	.string "I'll report all of this as a loss\n"
	.string "and get it back later.$"

PitchblakCity_KendomaCorp_Text_YoureComingWithMe:
	.string "Who says you'll be in a position\n"
	.string "to report anything?\p"
	.string "You're coming with us too.$"

PitchblakCity_KendomaCorp_Text_WhyMe:
	.string "Eh, what do you want with me?!\n"
	.string "You think taking hostages will save you?$"

PitchblakCity_KendomaCorp_Text_NotQuite:
	.string "NEDA: Not quite. The boss wants to have\n"
	.string "a word with you directly.\p"
	.string "About the last project you two\n"
	.string "worked on together.$"

PitchblakCity_KendomaCorp_Text_YoureCrazy:
	.string "OSRIC: You mean...$"

PitchblakCity_KendomaCorp_Text_YoureCrazy2:
	.string "Heh. You guys really are crazy.\p"
	.string "And I'd be crazy to go with you.\n"
	.string "I'm getting out of here.$"

PitchblakCity_KendomaCorp_Text_RestrainHim:
	.string "NEDA: Nice try.\n"
	.string "Restrain him, WEAPON D.$"

PitchblakCity_KendomaCorp_Text_Gyah:
	.string "Gyaaaaaah!!\n"
	.string "That hurts!\p"
	.string "Is all this really necessary?\p"
	.string "The handcuffs should be enough, r-right?\n"
	.string "You know I'm not flexi-\p"
	.string "OOOOoooohh...$"

PitchblakCity_KendomaCorp_Text_OsricHelp:
	.string "OSRIC: H-hey, kid.\p"
	.string "I have no idea who you are and\n"
	.string "how you got here, but please help!\p"
	.string "You can't let 'em do me like this!$"

PitchblakCity_KendomaCorp_Text_NedaWhatsThis:
	.string "NEDA: What's this?\n"
	.string "Are you lost, little mouse?\l"
	.string "Or do you intend to get in my way?$"

PitchblakCity_KendomaCorp_Text_BraveOfYouBoy:
	@.string "Brave of you, boy.\p"
	.string "Brave of you.\n"
	.string "But foolish.\p"
	.string "You have no idea of the power\n"
	.string "that I now wield.\p"
	.string "Tremble before the might\n"
	.string "of TEAM GENESIS!$"

PitchblakCity_KendomaCorp_Text_BraveOfYouGirly:
	@.string "Brave of you, girly.\p"
	.string "Brave of you.\n"
	.string "But foolish.\p"
	.string "You have no idea what kind\n"
	.string "of power I now wield.\p"
	.string "Tremble before the might\n"
	.string "of TEAM GENESIS!$"

PitchblakCity_KendomaCorp_Text_SmartChoice:
	.string "A smart choice.\n"
	.string "But I can't just let you leave now.\p"
	.string "If you were really smart, you never\n"
	.string "would've come here.\p"
	.string "Tremble before the might\n"
	.string "of TEAM GENESIS!$"

PitchblakCity_KendomaCorp_Text_NedaDefeated:
	.string "Impossible!$"

PitchblakCity_KendomaCorp_Text_NedaPostBattle:
	.string "\p"
	.string "Tch! To think that you actually\n"
	.string "managed to defeat WEAPON D.\p"
	.string "No matter, the president and I\n"
	.string "are leaving.\p"
	.string "And you are going somewhere\n"
	.string "far from home.$"

PitchblakCity_KendomaCorp_Text_WaitNeda:
	.string "OSRIC: H-hey wait, NEDA!\n"
	.string "That thing is still experimenta-$"

KendomaCorp_Movement_EscapeAttempt:
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	step_end

KendomaCorp_Movement_CameraPanUp:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end


KendomaCorp_Movement_CameraPanDown:
	delay_16
	delay_16
	@delay_16
	@delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end





