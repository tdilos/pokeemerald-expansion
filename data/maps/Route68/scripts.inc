Route68_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route68_OnTransition
	.byte 0

Route68_OnTransition:
	special GetWeekday
	goto_if_eq VAR_RESULT, 2, Route68_EventScript_RevealWeekdaySibling
	goto Route68_EventScript_HideWeekdaySibling
	end

Route68_EventScript_RevealWeekdaySibling:
	clearflag FLAG_HIDE_WEEKDAY_SIBLING
	end

Route68_EventScript_HideWeekdaySibling:
	setflag FLAG_HIDE_WEEKDAY_SIBLING
	end

Route68_EventScript_Tucker::
	lock
	faceplayer
	special GetWeekday
	goto_if_eq VAR_RESULT, 2, Route68_EventScript_TryGiveItem
	msgbox Route68_Text_WrongWeekday, MSGBOX_DEFAULT
	release
	end

Route68_EventScript_TryGiveItem::
	goto_if_set FLAG_DAILY_WEEKDAY_SIBLING_ITEM, Route68_EventScript_WeekdaySiblingPostItem
	msgbox Route68_Text_WeekdaySiblingItemGive, MSGBOX_DEFAULT
	giveitem ITEM_BLACK_BELT
	setflag FLAG_DAILY_WEEKDAY_SIBLING_ITEM
	msgbox Route68_Text_WeekdaySiblingExplainItem, MSGBOX_DEFAULT
	release
	end

Route68_EventScript_WeekdaySiblingPostItem::
	msgbox Route68_Text_WeekdaySiblingPostItem, MSGBOX_DEFAULT
	release
	end	

Route68_Text_WrongWeekday:
	.string "Hmm. Something's amiss.\n"
	.string "This isn't Tuesday.$"

Route68_Text_WeekdaySiblingItemGive:
	.string "Ho ha!\n"
	.string "I'm Tucker of Tuesday!\p"
	.string "I'm training beneath this waterfall.\p"
	.string "Here, you can train like me!$"

Route68_Text_WeekdaySiblingExplainItem:
	.string "A POKéMON holding that BLACK BELT\n"
	.string "will have its confidence boosted.\p"
	.string "Its FIGHTING type moves will deal\n"
	.string "even more damage!$"

Route68_Text_WeekdaySiblingPostItem:
	.string "My siblings and I have scattered\n"
	.string "ourselves around ISSHO.\p"
	.string "We give items to help each trainer\n"
	.string "we meet.$"









Route68_EventScript_Pokemon::
	lock
	faceplayer
	playmoncry SPECIES_DRIFLOON, CRY_MODE_NORMAL
	msgbox Route68_Text_Pokemon, MSGBOX_AUTOCLOSE
	waitmoncry
	fadescreen FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreen FADE_FROM_BLACK
	release
	end

Route68_Text_Pokemon:
	.string "DRIFLOON: Wuuwooowawawawiip$"







Route68_EventScript_Diane::
	trainerbattle_single TRAINER_DIANE, Route68_Text_DianeIntro, Route68_Text_DianeDefeated
	msgbox Route68_Text_DianePostBattle, MSGBOX_AUTOCLOSE
	end

Route68_EventScript_Lloyd::
	trainerbattle_single TRAINER_LLOYD, Route68_Text_LloydIntro, Route68_Text_LloydDefeated
	msgbox Route68_Text_LloydPostBattle, MSGBOX_AUTOCLOSE
	end

Route68_EventScript_Stacy::
	trainerbattle_single TRAINER_STACY, Route68_Text_StacyIntro, Route68_Text_StacyDefeated
	msgbox Route68_Text_StacyPostBattle, MSGBOX_AUTOCLOSE
	end

Route68_EventScript_Slade::
	trainerbattle_single TRAINER_SLADE, Route68_Text_SladeIntro, Route68_Text_SladeDefeated
	msgbox Route68_Text_SladePostBattle, MSGBOX_AUTOCLOSE
	end

Route68_EventScript_Tanner::
	trainerbattle_single TRAINER_TANNER, Route68_Text_TannerIntro, Route68_Text_TannerDefeated
	msgbox Route68_Text_TannerPostBattle, MSGBOX_AUTOCLOSE
	end

Route68_EventScript_Judith::
	trainerbattle_single TRAINER_JUDITH, Route68_Text_JudithIntro, Route68_Text_JudithDefeated
	msgbox Route68_Text_JudithPostBattle, MSGBOX_AUTOCLOSE
	end

Route68_EventScript_Woody::
	trainerbattle_single TRAINER_WOODY, Route68_Text_WoodyIntro, Route68_Text_WoodyDefeated
	msgbox Route68_Text_WoodyPostBattle, MSGBOX_AUTOCLOSE
	end

Route68_EventScript_Eoghan::
	trainerbattle_single TRAINER_EOGHAN, Route68_Text_EoghanIntro, Route68_Text_EoghanDefeated
	msgbox Route68_Text_EoghanPostBattle, MSGBOX_AUTOCLOSE
	end

Route68_EventScript_Cooper::
	trainerbattle_single TRAINER_COOPER, Route68_Text_CooperIntro, Route68_Text_CooperDefeated
	msgbox Route68_Text_CooperPostBattle, MSGBOX_AUTOCLOSE
	end

Route68_EventScript_Circe::
	trainerbattle_single TRAINER_CIRCE, Route68_Text_CirceIntro, Route68_Text_CirceDefeated
	msgbox Route68_Text_CircePostBattle, MSGBOX_AUTOCLOSE
	end

Route68_EventScript_Quillen::
	trainerbattle_single TRAINER_QUILLEN, Route68_Text_QuillenIntro, Route68_Text_QuillenDefeated
	msgbox Route68_Text_QuillenPostBattle, MSGBOX_AUTOCLOSE
	end


