.set LOCALID_MANIAC, 7
.set LOCALID_CHALLENGE_BIKER, 11

Sandshraf_B2_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Sandshraf_B2_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Sandshraf_B2_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Sandshraf_B2_OnFrame
	.byte 0

Sandshraf_B2_OnResume:
	special UpdateCyclingRoadState
	end

Sandshraf_B2_OnTransition:
	call_if_eq VAR_CYCLING_CHALLENGE_STATE, 1, Sandshraf_B2_EventScript_SaveCyclingMusic
	end

Sandshraf_B2_EventScript_SaveCyclingMusic::
	savebgm MUS_CYCLING
	return

Sandshraf_B2_OnFrame:
	map_script_2 VAR_CYCLING_CHALLENGE_STATE, 1, Sandshraf_B2_EventScript_BeginCyclingRoadChallenge
	.2byte 0

Sandshraf_B2_EventScript_BeginCyclingRoadChallenge::
	special Special_BeginCyclingRoadChallenge
	setvar VAR_CYCLING_CHALLENGE_STATE, 2
	return








Sandshraf_B2_EventScript_Maniac::
	lock
	msgbox Sandshraf_B2_Text_HesStuck, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Sandshraf_B2_EventScript_HelpManiac
	release
	end

Sandshraf_B2_Text_HesStuck:
	.string "He appears to be stuck.\p"
	.string "Help him out?$"

Sandshraf_B2_EventScript_HelpManiac::
	closemessage
	delay 30
	playse SE_M_SWAGGER2
	waitse
	delay 30
	playse SE_LEDGE
	@applymovement OBJ_EVENT_ID_PLAYER, Sandshraf_B2_Movement_BackUp
	@waitmovement 0
	applymovement LOCALID_MANIAC, Sandshraf_B2_Movement_BackUp
	waitmovement 0
	delay 30
	applymovement LOCALID_MANIAC, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	applymovement LOCALID_MANIAC, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_MANIAC, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Sandshraf_B2_Text_ThanksTakeThis, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_XENORESIN
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_RECEIVED_XENORESIN
	removeobject LOCALID_MANIAC
	delay 30
	fadescreen FADE_FROM_BLACK
	release
	end

Sandshraf_B2_Movement_BackUp:
	lock_facing_direction
	jump_in_place_down
	unlock_facing_direction
	step_end

Sandshraf_B2_Text_ThanksTakeThis:
	.string "Oh, thank you so much! I was stuck trying\n"
	.string "to crawl through this crevice.\p"
	.string "I'd been here so long, I thought I\n"
	.string "was a goner for sure!\p"
	.string "But it was worth it. I finally found\n"
	.string "the rare fossil I'd been looking for!\p"
	@.string "You saved me, so I'll share one with you.\n"
	.string "Since you saved me, I'll even let\n"
	.string "you keep one too.\p"
	.string "Take it!\n"
	.string "It's very special.$"







Sandshraf_B2_EventScript_Biker::
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_38
	goto_if_eq VAR_RESULT, TRUE, Sandshraf_B2_EventScript_QuestComplete
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_38
	goto_if_eq VAR_RESULT, TRUE, Sandshraf_B2_EventScript_QuestInProgress
	msgbox Sandshraf_B2_Text_ObstacleCourse, MSGBOX_DEFAULT
	startquest QUEST_38
	release
	end

Sandshraf_B2_Text_ObstacleCourse:
	.string "This cave is my obstacle course.\n"
	.string "I designed it all by myself.\p"
	.string "Why don't you try it out?\p"
	.string "My best record is 45 seconds.\n"
	.string "See if you can beat that!$"

Sandshraf_B2_EventScript_QuestInProgress::
	msgbox Sandshraf_B2_Text_TimeYou, MSGBOX_DEFAULT
	release
	end

Sandshraf_B2_Text_TimeYou:
	.string "Once you come back through the exit,\n"
	.string "I'll start my watch again.$"

Sandshraf_B2_EventScript_GetReward::
	msgbox Sandshraf_B2_Text_WellDone, MSGBOX_DEFAULT
	giveitem ITEM_POWER_ANKLET, 6
	completequest QUEST_38
	release
	end	

Sandshraf_B2_Text_WellDone:
	.string "Great job! You sure are serious\n"
	.string "about biking.\p"
	.string "Here, take this with you.$"

Sandshraf_B2_EventScript_QuestComplete::
	msgbox Sandshraf_B2_Text_ExplainPowerItem, MSGBOX_DEFAULT
	release
	end	

Sandshraf_B2_Text_ExplainPowerItem:
	.string "Give that POWER ANKLET to one\n"
	.string "of your POKéMON to wear.\p"
	.string "It'll help train its Speed faster.$"
















Sandshraf_B2_EventScript_CyclingChallengeEnd::
	lockall
	specialvar VAR_RESULT, GetPlayerAvatarBike
	goto_if_eq VAR_RESULT, 0, Sandshraf_B2_EventScript_EndChallenge
	applymovement LOCALID_CHALLENGE_BIKER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	call Sandshraf_B2_EventScript_CyclingChallengeResults
	releaseall
	end

Sandshraf_B2_EventScript_CyclingChallengeResults::
	special FinishCyclingRoadChallenge
	msgbox Sandshraf_B2_Text_CyclingChallengeResultSummary, MSGBOX_DEFAULT
	switch VAR_RESULT
	case 10, Sandshraf_B2_EventScript_ChallengeReactionBest
	case 9, Sandshraf_B2_EventScript_ChallengeReactionGood
	case 8, Sandshraf_B2_EventScript_ChallengeReactionGood
	case 7, Sandshraf_B2_EventScript_ChallengeReactionGood
	case 6, Sandshraf_B2_EventScript_ChallengeReactionOk
	case 5, Sandshraf_B2_EventScript_ChallengeReactionOk
	case 4, Sandshraf_B2_EventScript_ChallengeReactionOk
	case 3, Sandshraf_B2_EventScript_ChallengeReactionBad
	case 2, Sandshraf_B2_EventScript_ChallengeReactionBad
	case 1, Sandshraf_B2_EventScript_ChallengeReactionBad
	case 0, Sandshraf_B2_EventScript_ChallengeReactionWorst
	end

Sandshraf_B2_EventScript_ChallengeReactionBest::
	msgbox Sandshraf_B2_Text_ChallengeReactionBest, MSGBOX_DEFAULT
	goto Sandshraf_B2_EventScript_GetReward
	@goto Sandshraf_B2_EventScript_EndChallenge
	end

Sandshraf_B2_EventScript_ChallengeReactionGood::
	msgbox Sandshraf_B2_Text_ChallengeReactionGood, MSGBOX_DEFAULT
	goto Sandshraf_B2_EventScript_EndChallenge
	end

Sandshraf_B2_EventScript_ChallengeReactionOk::
	msgbox Sandshraf_B2_Text_ChallengeReactionOk, MSGBOX_DEFAULT
	goto Sandshraf_B2_EventScript_EndChallenge
	end

Sandshraf_B2_EventScript_ChallengeReactionBad::
	msgbox Sandshraf_B2_Text_ChallengeReactionBad, MSGBOX_DEFAULT
	goto Sandshraf_B2_EventScript_EndChallenge
	end

Sandshraf_B2_EventScript_ChallengeReactionWorst::
	msgbox Sandshraf_B2_Text_ChallengeReactionWorst, MSGBOX_DEFAULT
	goto Sandshraf_B2_EventScript_EndChallenge
	end

Sandshraf_B2_EventScript_EndChallenge::
	setvar VAR_CYCLING_CHALLENGE_STATE, 3
	savebgm MUS_DUMMY
	fadedefaultbgm
	return

Sandshraf_B2_Text_CyclingChallengeResultSummary:
	.string "Number of collisions:\n"
	.string "… … {STR_VAR_1}!\p"
	.string "Total time:\n"
	.string "… … {STR_VAR_2}!$"

Sandshraf_B2_Text_ChallengeReactionBest:
	.string "Bravo! Splendid showing!\p"
	.string "Your love of cycling comes from deep\n"
	.string "within your heart.\l"
	.string "You've shaken me to my very soul!$"

Sandshraf_B2_Text_ChallengeReactionGood:
	.string "Your technique is remarkable.\p"
	.string "I suggest you speed up a bit while\n"
	.string "still avoiding collisions.$"

Sandshraf_B2_Text_ChallengeReactionOk:
	.string "I would consider you a work in\n"
	.string "progress.\p"
	.string "Still, I hope you don't forget the\n"
	.string "sheer pleasure of cycling.$"

Sandshraf_B2_Text_ChallengeReactionBad:
	.string "My word… Your cycling skills border\n"
	.string "on terrifying.\p"
	.string "Most certainly, you need much more\n"
	.string "practice riding.$"

Sandshraf_B2_Text_ChallengeReactionWorst:
	.string "…I am aghast…\p"
	.string "You're perhaps not cut out for this\n"
	.string "unfortunate cycling business.\p"
	.string "You ought to give serious thought to\n"
	.string "returning that BIKE.$"


