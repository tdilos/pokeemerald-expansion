PitchblakCity_Flat2_2F_MapScripts::
	.byte 0

PitchblakCity_Flat2_2F_EventScript_Woman::
	lock
	faceplayer
	msgbox PitchblakCity_Flat1_2F_Text_PublicTransportation, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Flat1_2F_Text_PublicTransportation:
	.string "Sigh. I wish we had more public\n"
	.string "transportation options in this city.\p"
	.string "Why is it that other cities have\n"
	.string "ferry services but not us?$"

PitchblakCity_Flat2_2F_EventScript_RareCandySeller::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_PITCHBLAK_CITY_RARE_CANDY, PitchblakCity_Flat2_2F_EventScript_ComeBackTomorrow
	showmoneybox 0, 0
	msgbox PitchblakCity_Flat2_2F_Text_RareCandy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PitchblakCity_Flat2_2F_EventScript_DeclineRareCandy
	checkmoney 5000
	goto_if_eq VAR_RESULT, FALSE, PitchblakCity_Flat2_2F_EventScript_NotEnoughMoney
	special GetWeekday
	switch VAR_RESULT
	case 0, PitchblakCity_Flat2_2F_EventScript_GiveCandyS
	case 1, PitchblakCity_Flat2_2F_EventScript_GiveCandyM
	case 2, PitchblakCity_Flat2_2F_EventScript_GiveCandyL
	case 3, PitchblakCity_Flat2_2F_EventScript_GiveCandyM
	case 4, PitchblakCity_Flat2_2F_EventScript_GiveCandyS
	case 5, PitchblakCity_Flat2_2F_EventScript_GiveCandyM
	case 6, PitchblakCity_Flat2_2F_EventScript_GiveCandyS
	end


PitchblakCity_Flat2_2F_EventScript_GiveCandyXS::
	checkitemspace ITEM_EXP_CANDY_XS
	call_if_eq VAR_RESULT, TRUE, MindaroCity_EventScript_RemoveMoney
	giveitem ITEM_EXP_CANDY_XS
	goto_if_eq VAR_RESULT, FALSE, MindaroCity_EventScript_BagIsFull
	hidemoneybox
	setflag FLAG_DAILY_PITCHBLAK_CITY_RARE_CANDY
	release
	end

PitchblakCity_Flat2_2F_EventScript_GiveCandyS::
	checkitemspace ITEM_EXP_CANDY_S
	call_if_eq VAR_RESULT, TRUE, MindaroCity_EventScript_RemoveMoney
	giveitem ITEM_EXP_CANDY_S
	goto_if_eq VAR_RESULT, FALSE, MindaroCity_EventScript_BagIsFull
	hidemoneybox
	setflag FLAG_DAILY_PITCHBLAK_CITY_RARE_CANDY
	release
	end

PitchblakCity_Flat2_2F_EventScript_GiveCandyM::
	checkitemspace ITEM_EXP_CANDY_M
	call_if_eq VAR_RESULT, TRUE, MindaroCity_EventScript_RemoveMoney
	giveitem ITEM_EXP_CANDY_M
	goto_if_eq VAR_RESULT, FALSE, MindaroCity_EventScript_BagIsFull
	hidemoneybox
	setflag FLAG_DAILY_PITCHBLAK_CITY_RARE_CANDY
	release
	end

PitchblakCity_Flat2_2F_EventScript_GiveCandyL::
	checkitemspace ITEM_EXP_CANDY_L
	call_if_eq VAR_RESULT, TRUE, MindaroCity_EventScript_RemoveMoney
	giveitem ITEM_EXP_CANDY_L
	goto_if_eq VAR_RESULT, FALSE, MindaroCity_EventScript_BagIsFull
	hidemoneybox
	setflag FLAG_DAILY_PITCHBLAK_CITY_RARE_CANDY
	release
	end

PitchblakCity_Flat2_2F_EventScript_GiveCandyXL::
	checkitemspace ITEM_EXP_CANDY_XL
	call_if_eq VAR_RESULT, TRUE, MindaroCity_EventScript_RemoveMoney
	giveitem ITEM_EXP_CANDY_XL
	goto_if_eq VAR_RESULT, FALSE, MindaroCity_EventScript_BagIsFull
	hidemoneybox
	setflag FLAG_DAILY_PITCHBLAK_CITY_RARE_CANDY
	release
	end

PitchblakCity_Flat2_2F_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

PitchblakCity_Flat2_2F_EventScript_RemoveMoney::
	removemoney 5000
	updatemoneybox
	return

PitchblakCity_Flat2_2F_EventScript_DeclineRareCandy::
	msgbox PitchblakCity_Flat2_2F_Text_OhFineThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

PitchblakCity_Flat2_2F_EventScript_NotEnoughMoney::
	msgbox PitchblakCity_Flat2_2F_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

PitchblakCity_Flat2_2F_EventScript_ComeBackTomorrow::
	msgbox PitchblakCity_Flat2_2F_Text_ComeBackTomorrow, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Flat2_2F_Text_RareCandy:
	.string "Psst. Hey, kid.\p"
	.string "You want tough POKéMON fast?\n"
	.string "I got just the thing.\p"
	.string "Just one of these babies will turn your\n"
	.string "POKéMON into a killer overnight.\p"
	.string "It's ¥5,000 a pop.\n"
	.string "How bout it?$"

PitchblakCity_Flat2_2F_Text_OhFineThen:
	.string "You sure?\n"
	.string "It really does work fast.$"

PitchblakCity_Flat2_2F_Text_YouveNotGotTheMoney:
	.string "Hey, what do I look like,\n"
	.string "a charity house?\p"
	.string "No money, no deal.$"

PitchblakCity_Flat2_2F_Text_ComeBackTomorrow:
	.string "That's all I got today, little g.\p"
	.string "If you want more, I can hook\n"
	.string "you up tomorrow.$"


