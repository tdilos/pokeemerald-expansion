.set LOCALID_GRUNT1, 11
.set LOCALID_GRUNT2, 10

Route82_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route82_OnTransition
	.byte 0

Route82_OnTransition:
	special GetWeekday
	goto_if_eq VAR_RESULT, 6, Route82_EventScript_RevealWeekdaySibling
	goto Route82_EventScript_HideWeekdaySibling
	end

Route82_EventScript_RevealWeekdaySibling:
	clearflag FLAG_HIDE_WEEKDAY_SIBLING
	end

Route82_EventScript_HideWeekdaySibling:
	setflag FLAG_HIDE_WEEKDAY_SIBLING
	end

Route82_EventScript_Sadie::
	lock
	faceplayer
	special GetWeekday
	goto_if_eq VAR_RESULT, 6, Route82_EventScript_TryGiveItem
	msgbox Route82_Text_WrongWeekday, MSGBOX_DEFAULT
	release
	end

Route82_EventScript_TryGiveItem::
	goto_if_set FLAG_DAILY_WEEKDAY_SIBLING_ITEM, Route82_EventScript_WeekdaySiblingPostItem
	msgbox Route82_Text_WeekdaySiblingItemGive, MSGBOX_DEFAULT
	giveitem ITEM_PINK_BOW
	setflag FLAG_DAILY_WEEKDAY_SIBLING_ITEM
	msgbox Route82_Text_WeekdaySiblingExplainItem, MSGBOX_DEFAULT
	release
	end

Route82_EventScript_WeekdaySiblingPostItem::
	msgbox Route82_Text_WeekdaySiblingPostItem, MSGBOX_DEFAULT
	release
	end	

Route82_Text_WrongWeekday:
	.string "Oh no. Saturday's already over...$"

Route82_Text_WeekdaySiblingItemGive:
	.string "Yay! I'm Sadie of Saturday!\p"
	.string "Here you can have this as a symbol\n"
	.string "of our friendship.$"

Route82_Text_WeekdaySiblingExplainItem:
	.string "That PINK BOW will boost the power\n"
	.string "of Fairy type moves.\p"
	.string "And it will make your POKéMON\n"
	.string "look super cute!$"

Route82_Text_WeekdaySiblingPostItem:
	.string "My brothers and sisters will\n"
	.string "give you items too.\p"
	.string "Try to find them all!$"






Route82_EventScript_Kenny::
	trainerbattle_single TRAINER_KENNY, Route82_Text_KennyIntro, Route82_Text_KennyDefeated
	msgbox Route82_Text_KennyPostBattle, MSGBOX_AUTOCLOSE
	end

Route82_EventScript_Jane::
	trainerbattle_single TRAINER_JANE, Route82_Text_JaneIntro, Route82_Text_JaneDefeated
	msgbox Route82_Text_JanePostBattle, MSGBOX_AUTOCLOSE
	end

Route82_EventScript_Denzel::
	trainerbattle_single TRAINER_DENZEL, Route82_Text_DenzelIntro, Route82_Text_DenzelDefeated
	msgbox Route82_Text_DenzelPostBattle, MSGBOX_AUTOCLOSE
	end

Route82_EventScript_Reilly::
	trainerbattle_single TRAINER_REILLY, Route79_Text_ReillyIntro, Route79_Text_ReillyDefeated
	msgbox Route79_Text_ReillyPostBattle, MSGBOX_AUTOCLOSE
	end

Route82_EventScript_Hobo::
	lock
	faceplayer
	msgbox Route82_Text_SpareChange, MSGBOX_NPC
	@msgbox Route82_Text_SpareChange, MSGBOX_YESNO
	@goto_if_eq VAR_RESULT, YES, Route82_EventScript_GiveMoney
	@msgbox Route82_Text_KeepMoney, MSGBOX_NPC
	release
	end

Route82_EventScript_GiveMoney::
	msgbox Route82_Text_HandedOverMoney, MSGBOX_DEFAULT
	removemoney 1000
	msgbox Route82_Text_BlessYou, MSGBOX_NPC
	release
	end

Route82_Text_SpareChange:
	.string "Eh? You got any spare change, kid?$"
	@.string "I could really use ¥1000 right now.$"

Route82_Text_KeepMoney:
	.string "Ohhh...$"

Route82_Text_HandedOverMoney:
	.string "{PLAYER} gave the old man ¥1000.$"

Route82_Text_BlessYou:
	.string "Bless you, kid.$"

Route82_EventScript_RouteSign::
	msgbox Route82_Text_RouteSign, MSGBOX_SIGN
	end

Route82_Text_RouteSign:
	.string "ROUTE 82\p"
	.string "{UP_ARROW} CINEROUS TOWN\n"
	.string "{RIGHT_ARROW} ROUTE 83\l"
	.string "{DOWN_ARROW} XANTHOS CITY$"

Route82_EventScript_TrainerTipsToggleAutoRun::
	msgbox Route82_Text_TrainerTipsToggleAutoRun, MSGBOX_SIGN
	end

Route82_Text_TrainerTipsToggleAutoRun:
	.string "TRAINER TIPS\p"
	.string "Press B to toggle the RUNNING SHOES.$"

Route82_EventScript_Grunt1::
	lockall
	faceplayer
	msgbox Route82_Text_Scram, MSGBOX_NPC
	applymovement LOCALID_GRUNT2, Common_Movement_FaceDown
	waitmovement 0
	releaseall
	end

Route82_EventScript_Grunt2::
	lockall
	faceplayer
	msgbox Route82_Text_Scram, MSGBOX_NPC
	applymovement LOCALID_GRUNT1, Common_Movement_FaceUp
	waitmovement 0
	releaseall
	end

Route82_Text_Scram:
	.string "Hey scram, kid!\p"
	.string "Can't you see we're doing\n"
	.string "something important here?$"




Route82_EventScript_Runner::
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_5
	goto_if_eq VAR_RESULT, TRUE, Route82_EventScript_PostQuest
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_5
	goto_if_eq VAR_RESULT, TRUE, Route82_EventScript_QuestInProgress
	msgbox Route82_Text_Cardio, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route82_EventScript_UnlockQuest
	msgbox Route82_Text_CantAppreciate, MSGBOX_DEFAULT
	release
	end

Route82_EventScript_UnlockQuest::
	msgbox Route82_Text_ProveIt, MSGBOX_DEFAULT
	@questmenu QUEST_MENU_UNLOCK_QUEST QUEST_5
	@openquestmenu
	startquest QUEST_5
	release
	end

Route82_EventScript_QuestInProgress::
	buffernumberstring STR_VAR_3, VAR_CARDIO_STEP_COUNT
	goto_if_ge VAR_CARDIO_STEP_COUNT, 42195, Route82_EventScript_GetReward
	msgbox Route82_Text_MoreStepsToGo, MSGBOX_DEFAULT
	release
	end

Route82_EventScript_GetReward::
	msgbox Route82_Text_YouMadeIt, MSGBOX_DEFAULT
	giveitem ITEM_CARBOS, 20
	@questmenu QUEST_MENU_COMPLETE_QUEST QUEST_5
	completequest QUEST_5
	release
	end

Route82_EventScript_PostQuest::
	msgbox Route82_Text_NeverQuit, MSGBOX_DEFAULT
	release
	end

Route82_Text_Cardio:
	.string "Cardio is important.\n"
	.string "You agree, right?$"

Route82_Text_CantAppreciate:
	.string "Well, not everyone gets it.$"

Route82_Text_ProveIt:
	.string "That's the spirit!\p"
	.string "Why don't you prove your\n"
	.string "dedication to me?\p"
	.string "If you walk at least 42195 steps,\n"
	.string "I'll give you something good.$"

Route82_Text_MoreStepsToGo:
	.string "You have still have\n"
	.string "more steps to go.\p"
	.string "You're only at {STR_VAR_3} steps.\n"
	.string "Don't give up yet!$"

Route82_Text_YouMadeIt:
	.string "Hey, you did it!\n"
	.string "You're a regular marathoner!\p"
	.string "Great work, kid.\n"
	.string "Here, take these with you.$"

Route82_Text_NeverQuit:
	.string "Keep pushing yourself, kid.\p"
	.string "Believe in yourself and\n"
	.string "you will be unstoppable.$"





