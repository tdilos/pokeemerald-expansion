Route72_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route72_OnTransition
	.byte 0

Route72_OnTransition:
	special GetWeekday
	goto_if_eq VAR_RESULT, 5, Route72_EventScript_RevealWeekdaySibling
	goto Route72_EventScript_HideWeekdaySibling
	end

Route72_EventScript_RevealWeekdaySibling:
	clearflag FLAG_HIDE_WEEKDAY_SIBLING
	end

Route72_EventScript_HideWeekdaySibling:
	setflag FLAG_HIDE_WEEKDAY_SIBLING
	end

Route72_EventScript_Fred::
	lock
	faceplayer
	special GetWeekday
	goto_if_eq VAR_RESULT, 5, Route72_EventScript_TryGiveItem
	msgbox Route72_Text_WrongWeekday, MSGBOX_DEFAULT
	release
	end

Route72_EventScript_TryGiveItem::
	goto_if_set FLAG_DAILY_WEEKDAY_SIBLING_ITEM, Route72_EventScript_WeekdaySiblingPostItem
	msgbox Route72_Text_WeekdaySiblingItemGive, MSGBOX_DEFAULT
	giveitem ITEM_BLACK_GLASSES
	setflag FLAG_DAILY_WEEKDAY_SIBLING_ITEM
	msgbox Route72_Text_WeekdaySiblingExplainItem, MSGBOX_DEFAULT
	release
	end

Route72_EventScript_WeekdaySiblingPostItem::
	msgbox Route72_Text_WeekdaySiblingPostItem, MSGBOX_DEFAULT
	release
	end	

Route72_Text_WrongWeekday:
	.string "Today isn't Friday.\n"
	.string "Not cool...$"

Route72_Text_WeekdaySiblingItemGive:
	.string "I'm Fred of Friday.\n"
	.string "I'm a cool guy.\p"
	.string "Here, you can be cool too.$"

Route72_Text_WeekdaySiblingExplainItem:
	.string "Give those BLACK GLASSES to one of\n"
	.string "your POKéMON to hold.\p"
	.string "It'll deal more damage with its\n"
	.string "Dark type moves.\p"
	.string "And it'll look super cool\n"
	.string "while doing it!$"

Route72_Text_WeekdaySiblingPostItem:
	.string "You should try to find all my\n"
	.string "brothers and sisters.\p"
	.string "That would be real cool.$"














Route72_EventScript_RouteSign::
	msgbox Route72_Text_RouteSign, MSGBOX_SIGN
	end

Route72_Text_RouteSign:
	.string "ROUTE 72\p"
	.string "{UP_ARROW} ROUTE 71\n"
	.string "{LEFT_ARROW} PITCHBLAK CITY$"

Route72_EventScript_Barbara::
	trainerbattle_single TRAINER_BARBARA, Route72_Text_BarbaraIntro, Route72_Text_BarbaraDefeated
	msgbox Route72_Text_BarbaraPostBattle, MSGBOX_AUTOCLOSE
	end

Route72_EventScript_Randy::
	trainerbattle_single TRAINER_RANDY, Route72_Text_RandyIntro, Route72_Text_RandyDefeated
	msgbox Route72_Text_RandyPostBattle, MSGBOX_AUTOCLOSE
	end






Route72_EventScript_Beauty::
	msgbox Route72_Text_BeautifulSea, MSGBOX_NPC
	end

Route72_Text_BeautifulSea:
	.string "The sea is really beautiful.\n"
	.string "Don't you think?$"

Route72_EventScript_Sailor::
	lock
	faceplayer
	msgbox Route72_Text_RoughWaters, MSGBOX_DEFAULT
	release
	end

Route72_Text_RoughWaters:
	.string "Take heed if ye mean\n"
	.string "to cross the sea!\p"
	.string "Thar be rough waters ahead!$"


