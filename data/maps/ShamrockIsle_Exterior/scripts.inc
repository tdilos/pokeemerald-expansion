ShamrockIsle_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ShamrockIsle_Exterior_OnTransition
	.byte 0

ShamrockIsle_Exterior_OnTransition:
	special GetWeekday
	goto_if_eq VAR_RESULT, 1, ShamrockIsle_Exterior_EventScript_RevealWeekdaySibling
	goto ShamrockIsle_Exterior_EventScript_HideWeekdaySibling
	end

ShamrockIsle_Exterior_EventScript_RevealWeekdaySibling:
	clearflag FLAG_HIDE_WEEKDAY_SIBLING
	end

ShamrockIsle_Exterior_EventScript_HideWeekdaySibling:
	setflag FLAG_HIDE_WEEKDAY_SIBLING
	end

ShamrockIsle_Exterior_EventScript_Monty::
	lock
	faceplayer
	special GetWeekday
	goto_if_eq VAR_RESULT, 1, ShamrockIsle_Exterior_EventScript_TryGiveItem
	msgbox ShamrockIsle_Exterior_Text_WrongWeekday, MSGBOX_DEFAULT
	release
	end

ShamrockIsle_Exterior_EventScript_TryGiveItem::
	goto_if_set FLAG_DAILY_WEEKDAY_SIBLING_ITEM, ShamrockIsle_Exterior_EventScript_WeekdaySiblingPostItem
	msgbox ShamrockIsle_Exterior_Text_WeekdaySiblingItemGive, MSGBOX_DEFAULT
	giveitem ITEM_MYSTIC_WATER
	setflag FLAG_DAILY_WEEKDAY_SIBLING_ITEM
	msgbox ShamrockIsle_Exterior_Text_WeekdaySiblingExplainItem, MSGBOX_DEFAULT
	release
	end

ShamrockIsle_Exterior_EventScript_WeekdaySiblingPostItem::
	msgbox ShamrockIsle_Exterior_Text_WeekdaySiblingPostItem, MSGBOX_DEFAULT
	release
	end	

ShamrockIsle_Exterior_Text_WrongWeekday:
	.string "It's too bad every day can't be Monday.$"

ShamrockIsle_Exterior_Text_WeekdaySiblingItemGive:
	.string "Greetings trainer.\n"
	.string "I am Monty of Monday.\p"
	.string "As a symbol of our friendship,\n"
	.string "please accept this.$"

ShamrockIsle_Exterior_Text_WeekdaySiblingExplainItem:
	.string "That MYSTIC WATER boosts the\n"
	.string "power of Water type moves.\p"
	.string "Let a Water type POKéMON hold it,\n"
	.string "and it will feel right as rain!$"

ShamrockIsle_Exterior_Text_WeekdaySiblingPostItem:
	.string "My younger siblings and I are dedicated\n"
	.string "to helping every trainer we meet.\p"
	.string "Try to find us all!$"




ShamrockIsle_Exterior_EventScript_Dummy::
	lock
	seteventmon SPECIES_VICTINI, 50
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 1, 1, 1, 1, 1, 1
	special BattleSetup_StartLegendaryBattle
	waitstate
	@playse MUS_SLOTS_WIN
	@waitse
	release
	end	


