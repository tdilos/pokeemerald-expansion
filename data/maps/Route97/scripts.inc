Route97_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route97_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route97_OnWarp
	.byte 0

Route97_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, Route97_EventScript_UnsetForceOffscreenLoad
	.2byte 0

Route97_EventScript_UnsetForceOffscreenLoad::
	clearflag FLAG_FORCE_LOAD_OFFSCREEN_OBJEV
	end

Route97_OnTransition:
	special GetWeekday
	goto_if_eq VAR_RESULT, 3, Route97_EventScript_RevealWeekdaySibling
	goto Route97_EventScript_HideWeekdaySibling
	end

Route97_EventScript_RevealWeekdaySibling:
	clearflag FLAG_HIDE_WEEKDAY_SIBLING
	end

Route97_EventScript_HideWeekdaySibling:
	setflag FLAG_HIDE_WEEKDAY_SIBLING
	end

Route97_EventScript_Wendy::
	lock
	faceplayer
	special GetWeekday
	goto_if_eq VAR_RESULT, 3, Route97_EventScript_TryGiveItem
	msgbox Route97_Text_WrongWeekday, MSGBOX_DEFAULT
	release
	end

Route97_EventScript_TryGiveItem::
	goto_if_set FLAG_DAILY_WEEKDAY_SIBLING_ITEM, Route97_EventScript_WeekdaySiblingPostItem
	msgbox Route97_Text_WeekdaySiblingItemGive, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	setflag FLAG_DAILY_WEEKDAY_SIBLING_ITEM
	msgbox Route97_Text_WeekdaySiblingExplainItem, MSGBOX_DEFAULT
	release
	end

Route97_EventScript_WeekdaySiblingPostItem::
	msgbox Route97_Text_WeekdaySiblingPostItem, MSGBOX_DEFAULT
	release
	end	

Route97_Text_WrongWeekday:
	.string "Oh dear. Wednesday's over already.\n"
	.string "Time sure flies.$"

Route97_Text_WeekdaySiblingItemGive:
	.string "Greetings, trainer.\n"
	.string "I am Wendy of Wednesday.\p"
	.string "You should really stay bundled\n"
	.string "up in weather like this.\p"
	.string "Here, I think this suits you.$"

Route97_Text_WeekdaySiblingExplainItem:
	.string "That SILK SCARF doesn't just\n"
	.string "keep your POKéMON warm.\p"
	.string "It also boosts the power of\n"
	.string "its NORMAL type moves.$"

Route97_Text_WeekdaySiblingPostItem:
	.string "My family is always giving out\n"
	.string "helpful items to trainers.\p"
	.string "Try to find us all!$"






Route97_EventScript_Ranger::
	lock
	faceplayer
	msgbox Route97_Text_PathThruMtShiro, MSGBOX_DEFAULT
	release
	end

Route97_Text_PathThruMtShiro:
	.string "Are you trying to get to MAROON CITY?\p"
	.string "This way's no good for most folks.\n"
	.string "Your best bet is by ROUTE 93.$"







Route97_EventScript_Gunda::
	trainerbattle_single TRAINER_GUNDA, Route97_Text_GundaIntro, Route97_Text_GundaDefeated
	msgbox Route97_Text_GundaPostBattle, MSGBOX_AUTOCLOSE
	end

Route97_EventScript_Frode::
	trainerbattle_single TRAINER_FRODE, Route97_Text_FrodeIntro, Route97_Text_FrodeDefeated
	msgbox Route97_Text_FrodePostBattle, MSGBOX_AUTOCLOSE
	end

Route97_EventScript_Benedict::
	trainerbattle_single TRAINER_BENEDICT, Route97_Text_BenedictIntro, Route97_Text_BenedictDefeated
	msgbox Route97_Text_BenedictPostBattle, MSGBOX_AUTOCLOSE
	end
