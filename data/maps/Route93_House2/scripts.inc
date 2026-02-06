Route93_House2_MapScripts::
	.byte 0

Route93_House2_EventScript_Pokemon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_GROWLITHE, CRY_MODE_NORMAL
	msgbox Route93_House2_Text_Pokemon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route93_House2_Text_Pokemon:
	.string "GROWLITHE: Garr garrr!$"

Route93_House2_EventScript_MilkSeller::
	lock
	faceplayer
	message Route93_House2_Text_TrySomeMilk
	waitmessage
	showmoneybox 0, 0
	multichoicedefault 21, 6, MULTI_MILK_SELLER, 3, FALSE
	switch VAR_RESULT
	case 0, Route93_House2_EventScript_BuyOne
	case 1, Route93_House2_EventScript_BuyDozen
	case 2, Route93_House2_EventScript_CancelBuy
	case MULTI_B_PRESSED, Route93_House2_EventScript_CancelBuy
	end

Route93_House2_EventScript_BuyOne::
	checkmoney 500
	goto_if_eq VAR_RESULT, FALSE, Route93_House2_EventScript_NotEnoughMoney
	checkitemspace ITEM_MOOMOO_MILK
	goto_if_eq VAR_RESULT, FALSE, Route93_House2_EventScript_NoRoomInBag
	playse SE_SHOP
	removemoney 500
	additem ITEM_MOOMOO_MILK
	updatemoneybox
	msgbox Route93_House2_Text_PutMilkInBag, MSGBOX_DEFAULT
	hidemoneybox
	goto Route93_House2_EventScript_EndBuy
	end

Route93_House2_EventScript_BuyDozen::
	checkmoney 6000
	goto_if_eq VAR_RESULT, FALSE, Route93_House2_EventScript_NotEnoughMoney
	checkitemspace ITEM_MOOMOO_MILK
	goto_if_eq VAR_RESULT, FALSE, Route93_House2_EventScript_NoRoomInBag
	playse SE_SHOP
	removemoney 6000
	additem ITEM_MOOMOO_MILK, 12
	updatemoneybox
	msgbox Route93_House2_Text_PutMilkInBag, MSGBOX_DEFAULT
	hidemoneybox
	goto Route93_House2_EventScript_EndBuy
	end

Route93_House2_EventScript_NoRoomInBag::
	msgbox Route93_House2_Text_NoRoomInBag, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route93_House2_EventScript_NotEnoughMoney::
	msgbox Route93_House2_Text_NotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route93_House2_EventScript_CancelBuy::
	msgbox Route93_House2_Text_PlentyMore, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route93_House2_EventScript_EndBuy::
	msgbox Route93_House2_Text_PlentyMore, MSGBOX_DEFAULT
	release
	end

Route93_House2_Text_TrySomeMilk:
	.string "How'd you like to try some\n"
	.string "fresh MOOMOO MILK?\p"
	.string "It's only ¥500 a bottle.\n"
	.string "What do you say?$"

Route93_House2_Text_NoRoomInBag:
	.string "Uh-oh. Your bag is full!$"

Route93_House2_Text_NotEnoughMoney:
	.string "Uh-oh. You don't have enough money!$"

Route93_House2_Text_PutMilkInBag:
	.string "{PLAYER} put the milk in the bag.$"

Route93_House2_Text_PlentyMore:
	.string "Don't be shy now. There's plenty more\n"
	.string "where that came from.$"

