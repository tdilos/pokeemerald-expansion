Route94_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route94_OnTransition
	.byte 0

Route94_OnTransition:
	special GetWeekday
	goto_if_eq VAR_RESULT, 0, Route94_EventScript_RevealWeekdaySibling
	goto Route94_EventScript_HideWeekdaySibling
	end

Route94_EventScript_RevealWeekdaySibling:
	clearflag FLAG_HIDE_WEEKDAY_SIBLING
	end

Route94_EventScript_HideWeekdaySibling:
	setflag FLAG_HIDE_WEEKDAY_SIBLING
	end

Route94_EventScript_Sonny::
	lock
	faceplayer
	special GetWeekday
	goto_if_eq VAR_RESULT, 0, Route94_EventScript_TryGiveItem
	msgbox Route94_Text_WrongWeekday, MSGBOX_DEFAULT
	release
	end

Route94_EventScript_TryGiveItem::
	goto_if_set FLAG_DAILY_WEEKDAY_SIBLING_ITEM, Route94_EventScript_WeekdaySiblingPostItem
	msgbox Route94_Text_WeekdaySiblingItemGive, MSGBOX_DEFAULT
	giveitem ITEM_SHARP_BEAK
	setflag FLAG_DAILY_WEEKDAY_SIBLING_ITEM
	msgbox Route94_Text_WeekdaySiblingExplainItem, MSGBOX_DEFAULT
	release
	end

Route94_EventScript_WeekdaySiblingPostItem::
	msgbox Route94_Text_WeekdaySiblingPostItem, MSGBOX_DEFAULT
	release
	end	

Route94_Text_WrongWeekday:
	.string "Hey, today isn't Sunday!$"

Route94_Text_WeekdaySiblingItemGive:
	.string "Hiya!\n"
	.string "I'm Sonny of Sunday.\p"
	.string "Today is Sunday.\n"
	.string "You know what that means?\p"
	.string "You get this!$"

Route94_Text_WeekdaySiblingExplainItem:
	.string "That SHARP BEAK boosts the\n"
	.string "power of Flying type moves.\p"
	.string "Give it to a bird POKéMON!$"

Route94_Text_WeekdaySiblingPostItem:
	.string "Our family's really big. I have\n"
	.string "six brothers and sisters.\p"
	.string "And I'm the youngest one!$"








Route94_EventScript_Charlene::
	trainerbattle_single TRAINER_CHARLENE, Route94_Text_CharleneIntro, Route94_Text_CharleneDefeated
	msgbox Route94_Text_CharlenePostBattle, MSGBOX_AUTOCLOSE
	end

Route94_EventScript_Polly::
	trainerbattle_single TRAINER_POLLY, Route94_Text_PollyIntro, Route94_Text_PollyDefeated
	msgbox Route94_Text_PollyPostBattle, MSGBOX_AUTOCLOSE
	end

Route94_EventScript_Blossom::
	trainerbattle_single TRAINER_BLOSSOM, Route94_Text_BlossomIntro, Route94_Text_BlossomDefeated
	msgbox Route94_Text_BlossomPostBattle, MSGBOX_AUTOCLOSE
	end

