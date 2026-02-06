MindaroCity_DepartmentStoreRoof_MapScripts::
	.byte 0




MindaroCity_DepartmentStoreRoof_EventScript_LittleGirl::
	lock
	faceplayer
	msgbox MindaroCity_DepartmentStoreRoof_Text_HotelPool, MSGBOX_DEFAULT
	release
	end

MindaroCity_DepartmentStoreRoof_Text_HotelPool:
	.string "Did you know our hotel has a pool?$"


MindaroCity_DepartmentStoreRoof_EventScript_Man::
	lock
	faceplayer
	msgbox MindaroCity_DepartmentStoreRoof_Text_KidsVacations, MSGBOX_DEFAULT
	release
	end

MindaroCity_DepartmentStoreRoof_Text_KidsVacations:
	.string "Kids, am I right?\p"
	.string "Take them on vacation and all they think\n"
	.string "about is stuff they could do at home.$"




MindaroCity_DepartmentStoreRoof_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_MINDARO_NPC_TRADE_COMPLETED, MindaroCity_DepartmentStoreRoof_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_ROGGENROLA
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox MindaroCity_DepartmentStoreRoof_Text_WillingToTradeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MindaroCity_DepartmentStoreRoof_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, MindaroCity_DepartmentStoreRoof_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, MindaroCity_DepartmentStoreRoof_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	giveitem ITEM_COVENANT_ORB
	waitfanfare
	msgbox MindaroCity_DepartmentStoreRoof_Text_UrAwesome, MSGBOX_DEFAULT
	setflag FLAG_MINDARO_NPC_TRADE_COMPLETED
	release
	end

MindaroCity_DepartmentStoreRoof_EventScript_DeclineTrade::
	@msgbox MindaroCity_DepartmentStoreRoof_Text_NotDesperateOrAnything, MSGBOX_DEFAULT
	release
	end

MindaroCity_DepartmentStoreRoof_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox MindaroCity_DepartmentStoreRoof_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
	release
	end

MindaroCity_DepartmentStoreRoof_EventScript_TradeCompleted::
	msgbox MindaroCity_DepartmentStoreRoof_Text_TradeWithOthers, MSGBOX_DEFAULT
	release
	end

MindaroCity_DepartmentStoreRoof_Text_WillingToTradeIt:
	.string "Hi! Do you have a {STR_VAR_1}!\p"
	.string "Would you trade it for my {STR_VAR_2}?$"

MindaroCity_DepartmentStoreRoof_Text_UrAwesome:
	.string "You're awesome! Thanks!$"

MindaroCity_DepartmentStoreRoof_Text_WontAcceptAnyLessThanRealMon:
	.string "No, no, no! I won't accept any\n"
	.string "less than a real {STR_VAR_1}!$"

MindaroCity_DepartmentStoreRoof_Text_NotDesperateOrAnything:
	.string "Oh, so you're not going to go through\n"
	.string "with this?\p"
	.string "That's cool. I'm not desperate to make\n"
	.string "a trade or anything.$"

MindaroCity_DepartmentStoreRoof_Text_TradeWithOthers:
	.string "I trade with my friends in other\n"
	.string "cities all the time.$"

MindaroCity_DepartmentStoreRoof_EventScript_VendingMachine::
	lockall
	message MindaroCity_DepartmentStoreRoof_Text_WhichDrinkWouldYouLike
	waitmessage
	showmoneybox 0, 0
	goto MindaroCity_DepartmentStoreRoof_EventScript_ChooseDrink
	end

MindaroCity_DepartmentStoreRoof_EventScript_ChooseDrink::
	multichoice 16, 0, MULTI_VENDING_MACHINE, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, MindaroCity_DepartmentStoreRoof_EventScript_FreshWater
	case 1, MindaroCity_DepartmentStoreRoof_EventScript_SodaPop
	case 2, MindaroCity_DepartmentStoreRoof_EventScript_Lemonade
	msgbox MindaroCity_DepartmentStoreRoof_Text_DecidedAgainstBuyingDrink, MSGBOX_DEFAULT
	goto MindaroCity_DepartmentStoreRoof_EventScript_ExitVendingMachine
	end

MindaroCity_DepartmentStoreRoof_EventScript_FreshWater::
	setvar VAR_TEMP_0, ITEM_FRESH_WATER
	goto MindaroCity_DepartmentStoreRoof_EventScript_TryBuyDrink
	end

MindaroCity_DepartmentStoreRoof_EventScript_SodaPop::
	setvar VAR_TEMP_0, ITEM_SODA_POP
	goto MindaroCity_DepartmentStoreRoof_EventScript_TryBuyDrink
	end

MindaroCity_DepartmentStoreRoof_EventScript_Lemonade::
	setvar VAR_TEMP_0, ITEM_LEMONADE
	goto MindaroCity_DepartmentStoreRoof_EventScript_TryBuyDrink
	end

MindaroCity_DepartmentStoreRoof_EventScript_CheckMoneyFreshWater::
	checkmoney 200
	return

MindaroCity_DepartmentStoreRoof_EventScript_CheckMoneySodaPop::
	checkmoney 300
	return

MindaroCity_DepartmentStoreRoof_EventScript_CheckMoneyLemonade::
	checkmoney 350
	return

MindaroCity_DepartmentStoreRoof_EventScript_RemoveMoneyFreshWater::
	removemoney 200
	return

MindaroCity_DepartmentStoreRoof_EventScript_RemoveMoneySodaPop::
	removemoney 300
	return

MindaroCity_DepartmentStoreRoof_EventScript_RemoveMoneyLemonade::
	removemoney 350
	return

MindaroCity_DepartmentStoreRoof_EventScript_TryBuyDrink::
	call_if_eq VAR_TEMP_1, 0, MindaroCity_DepartmentStoreRoof_EventScript_CheckMoneyFreshWater
	call_if_eq VAR_TEMP_1, 1, MindaroCity_DepartmentStoreRoof_EventScript_CheckMoneySodaPop
	call_if_eq VAR_TEMP_1, 2, MindaroCity_DepartmentStoreRoof_EventScript_CheckMoneyLemonade
	goto_if_eq VAR_RESULT, FALSE, MindaroCity_DepartmentStoreRoof_EventScript_NotEnoughMoneyForDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, FALSE, MindaroCity_DepartmentStoreRoof_EventScript_NoRoomForDrink
	call_if_eq VAR_TEMP_1, 0, MindaroCity_DepartmentStoreRoof_EventScript_RemoveMoneyFreshWater
	call_if_eq VAR_TEMP_1, 1, MindaroCity_DepartmentStoreRoof_EventScript_RemoveMoneySodaPop
	call_if_eq VAR_TEMP_1, 2, MindaroCity_DepartmentStoreRoof_EventScript_RemoveMoneyLemonade
	updatemoneybox
	bufferitemname STR_VAR_1, VAR_TEMP_0
	playse SE_VEND
	msgbox MindaroCity_DepartmentStoreRoof_Text_CanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 64  @ 1/64 chance of an additional drink dropping
	goto_if_ne VAR_RESULT, 0, MindaroCity_DepartmentStoreRoof_EventScript_ChooseNewDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, FALSE, MindaroCity_DepartmentStoreRoof_EventScript_NoRoomForDrink
	playse SE_VEND
	msgbox MindaroCity_DepartmentStoreRoof_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 64  @ 1/64 * the prev 1/64 chance of a third additional drink dropping, ~ 0.02% chance
	goto_if_ne VAR_RESULT, 0, MindaroCity_DepartmentStoreRoof_EventScript_ChooseNewDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, 0, MindaroCity_DepartmentStoreRoof_EventScript_NoRoomForDrink
	playse SE_VEND
	msgbox MindaroCity_DepartmentStoreRoof_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	goto MindaroCity_DepartmentStoreRoof_EventScript_ChooseNewDrink
	end

MindaroCity_DepartmentStoreRoof_EventScript_ChooseNewDrink::
	message MindaroCity_DepartmentStoreRoof_Text_WhichDrinkWouldYouLike
	waitmessage
	goto MindaroCity_DepartmentStoreRoof_EventScript_ChooseDrink
	end

MindaroCity_DepartmentStoreRoof_EventScript_NotEnoughMoneyForDrink::
	msgbox MindaroCity_DepartmentStoreRoof_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto MindaroCity_DepartmentStoreRoof_EventScript_ExitVendingMachine
	end

MindaroCity_DepartmentStoreRoof_EventScript_NoRoomForDrink::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	goto MindaroCity_DepartmentStoreRoof_EventScript_ExitVendingMachine
	end

MindaroCity_DepartmentStoreRoof_EventScript_ExitVendingMachine::
	hidemoneybox
	releaseall
	end

MindaroCity_DepartmentStoreRoof_Text_WhichDrinkWouldYouLike:
	.string "It's a VENDING MACHINE.\n"
	.string "Which drink would you like?$"

MindaroCity_DepartmentStoreRoof_Text_CanOfDrinkDroppedDown:
	.string "Clang!\p"
	.string "A can of {STR_VAR_1} dropped down.$"

MindaroCity_DepartmentStoreRoof_Text_ExtraCanOfDrinkDroppedDown:
	.string "Clang!\p"
	.string "Score! An extra can of {STR_VAR_1}\n"
	.string "dropped down!$"

MindaroCity_DepartmentStoreRoof_Text_NotEnoughMoney:
	.string "Not enough money…$"

MindaroCity_DepartmentStoreRoof_Text_DecidedAgainstBuyingDrink:
	.string "Decided against buying a drink.$"


