TurquoiseCity_GameCorner_MapScripts::
	.byte 0

    @ Game Corner prices
	.set DUBIOUS_DISC_COINS,  1000
	.set KINGS_ROCK_COINS,    1000
	.set ONI_MASK_COINS,      1000
	.set REAPER_CLOTH_COINS,  1000
	.set UPGRADE_COINS,       1000

	.set SOLOSIS_COINS,        800 
	.set CRYOGONAL_COINS,     1600
	.set KLEFKI_COINS,        3200
	.set LARVITAR_COINS,      4800
	.set BELDUM_COINS,        4800
	.set DEINO_COINS,         4800
	.set DREEPY_COINS,        4800
	.set PORYGON_COINS,       9999

	.set COINS_PRICE_50,   1000
	.set COINS_PRICE_500, 10000



TurquoiseCity_GameCorner_EventScript_CoinsClerk::
	lock
	faceplayer
	msgbox TurquoiseCity_GameCorner_Text_ThisIsTurquoiseGameCorner, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, TurquoiseCity_GameCorner_EventScript_NeedCoinCase
	message TurquoiseCity_GameCorner_Text_WereYouLookingForCoins
	waitmessage
	showmoneybox 0, 0
	showcoinsbox 1, 6
	goto TurquoiseCity_GameCorner_EventScript_ChooseCoinsDefault50

TurquoiseCity_GameCorner_EventScript_ChooseCoinsDefault50::
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 0, FALSE
	switch VAR_RESULT
	case 0, TurquoiseCity_GameCorner_EventScript_Buy50Coins
	case 1, TurquoiseCity_GameCorner_EventScript_Buy500Coins
	goto TurquoiseCity_GameCorner_EventScript_CancelBuyCoins
	end

TurquoiseCity_GameCorner_EventScript_Buy50Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 50), TurquoiseCity_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_50
	goto_if_eq VAR_RESULT, FALSE, TurquoiseCity_GameCorner_EventScript_NotEnoughMoney
	addcoins 50
	removemoney COINS_PRICE_50
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox TurquoiseCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

TurquoiseCity_GameCorner_EventScript_Buy500Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 500), TurquoiseCity_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_500
	goto_if_eq VAR_RESULT, FALSE, TurquoiseCity_GameCorner_EventScript_NotEnoughMoney
	addcoins 500
	removemoney COINS_PRICE_500
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox TurquoiseCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

TurquoiseCity_GameCorner_EventScript_NeedCoinCase::
	msgbox TurquoiseCity_GameCorner_Text_NeedCoinCaseForCoins, MSGBOX_DEFAULT
	giveitem ITEM_COIN_CASE
	setflag FLAG_RECEIVED_COIN_CASE
	release
	end

TurquoiseCity_GameCorner_EventScript_NotEnoughMoney::
	msgbox TurquoiseCity_GameCorner_Text_DontHaveEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

TurquoiseCity_GameCorner_EventScript_CancelBuyCoins::
	msgbox TurquoiseCity_GameCorner_Text_DontNeedCoinsThen, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

TurquoiseCity_GameCorner_EventScript_NoRoomForCoins::
	msgbox TurquoiseCity_GameCorner_Text_CoinCaseIsFull, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

TurquoiseCity_GameCorner_EventScript_NoCoinCase::
	msgbox TurquoiseCity_GameCorner_Text_CantPlayWithNoCoinCase, MSGBOX_DEFAULT
	releaseall
	end

TurquoiseCity_GameCorner_Text_ThisIsTurquoiseGameCorner:
	.string "This is TURQUOISE GAME CORNER.$"

TurquoiseCity_GameCorner_Text_NeedCoinCaseForCoins:
	.string "Okay, you wanted some COINS for\n"
	.string "the games?\p"
	.string "But you don't have a COIN CASE for\n"
	.string "stowing the COINS.\p"
	.string "Here, you can use this one.$"

TurquoiseCity_GameCorner_Text_WereYouLookingForCoins:
	.string "Were you looking for COINS?\p"
	.string "It's ¥1000 for 50 COINS.\n"
	.string "Would you like some?$"

TurquoiseCity_GameCorner_Text_ThankYouHereAreYourCoins:
	.string "Thank you very much!\n"
	.string "Here are your COINS!$"

TurquoiseCity_GameCorner_Text_DontHaveEnoughMoney:
	.string "Um… You don't appear to have\n"
	.string "enough money…$"

TurquoiseCity_GameCorner_Text_CoinCaseIsFull:
	.string "Oh?\n"
	.string "Your COIN CASE is full.$"

TurquoiseCity_GameCorner_Text_DontNeedCoinsThen:
	.string "Oh… You don't need COINS, then?\n"
	.string "Good luck on your adventure!$"

TurquoiseCity_GameCorner_Text_CoinsAreNeededToPlay:
	.string "COINS are needed to play here\n"
	.string "in the GAME CORNER.$"

TurquoiseCity_GameCorner_Text_CantPlayWithNoCoinCase:
	.string "You can't play if you don't have\n"
	.string "a COIN CASE.$"











TurquoiseCity_GameCorner_EventScript_PrizeCornerItems::
	lock
	faceplayer
	msgbox TurquoiseCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, TurquoiseCity_GameCorner_EventScript_ChooseItemPrizeMessage
	release
	end

TurquoiseCity_GameCorner_EventScript_ChooseItemPrizeMessage::
	message TurquoiseCity_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto TurquoiseCity_GameCorner_EventScript_ChooseItemPrize

TurquoiseCity_GameCorner_EventScript_ReturnToChooseItemPrize::
	message TurquoiseCity_GameCorner_Text_WhichPrize
	waitmessage
	goto TurquoiseCity_GameCorner_EventScript_ChooseItemPrize

TurquoiseCity_GameCorner_EventScript_ChooseItemPrize::
	scrollingmultichoice 14, 18, 0, 6, TRUE
	switch VAR_RESULT
	case 0, TurquoiseCity_GameCorner_EventScript_DubiousDisc
	case 1, TurquoiseCity_GameCorner_EventScript_KingsRock
	case 2, TurquoiseCity_GameCorner_EventScript_OniMask
	case 3, TurquoiseCity_GameCorner_EventScript_ReaperCloth
	case 4, TurquoiseCity_GameCorner_EventScript_Upgrade
	case 5, TurquoiseCity_GameCorner_EventScript_CancelItemSelect
	goto TurquoiseCity_GameCorner_EventScript_CancelItemSelect
	end

TurquoiseCity_GameCorner_EventScript_DubiousDisc::
	setvar VAR_TEMP_1, 1
	bufferitemname STR_VAR_1, ITEM_DUBIOUS_DISC
	setvar VAR_0x8004, ITEM_DUBIOUS_DISC
	goto TurquoiseCity_GameCorner_EventScript_ConfirmItemPrize

TurquoiseCity_GameCorner_EventScript_KingsRock::
	setvar VAR_TEMP_1, 2
	bufferitemname STR_VAR_1, ITEM_KINGS_ROCK
	setvar VAR_0x8004, ITEM_KINGS_ROCK
	goto TurquoiseCity_GameCorner_EventScript_ConfirmItemPrize

TurquoiseCity_GameCorner_EventScript_OniMask::
	setvar VAR_TEMP_1, 3
	bufferitemname STR_VAR_1, ITEM_ONI_MASK
	setvar VAR_0x8004, ITEM_ONI_MASK
	goto TurquoiseCity_GameCorner_EventScript_ConfirmItemPrize

TurquoiseCity_GameCorner_EventScript_ReaperCloth::
	setvar VAR_TEMP_1, 4
	bufferitemname STR_VAR_1, ITEM_REAPER_CLOTH
	setvar VAR_0x8004, ITEM_REAPER_CLOTH
	goto TurquoiseCity_GameCorner_EventScript_ConfirmItemPrize

TurquoiseCity_GameCorner_EventScript_Upgrade::
	setvar VAR_TEMP_1, 5
	bufferitemname STR_VAR_1, ITEM_UPGRADE
	setvar VAR_0x8004, ITEM_UPGRADE
	goto TurquoiseCity_GameCorner_EventScript_ConfirmItemPrize

TurquoiseCity_GameCorner_EventScript_ConfirmItemPrize::
	msgbox TurquoiseCity_GameCorner_Text_SoYourChoiceIsTheItemX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TurquoiseCity_GameCorner_EventScript_CancelItemSelect
	switch VAR_TEMP_1
	case 1, TurquoiseCity_GameCorner_EventScript_BuyDubiousDisc
	case 2, TurquoiseCity_GameCorner_EventScript_BuyKingsRock
	case 3, TurquoiseCity_GameCorner_EventScript_BuyOniMask
	case 4, TurquoiseCity_GameCorner_EventScript_BuyReaperCloth
	case 5, TurquoiseCity_GameCorner_EventScript_BuyUpgrade
	end

TurquoiseCity_GameCorner_EventScript_BuyDubiousDisc::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DUBIOUS_DISC_COINS, TurquoiseCity_GameCorner_EventScript_NotEnoughCoinsForItem
	checkitemspace ITEM_DUBIOUS_DISC
	goto_if_eq VAR_RESULT, FALSE, TurquoiseCity_GameCorner_EventScript_NoRoomForItem
	removecoins DUBIOUS_DISC_COINS
	additem ITEM_DUBIOUS_DISC
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox TurquoiseCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto TurquoiseCity_GameCorner_EventScript_ReturnToChooseItemPrize
	end

TurquoiseCity_GameCorner_EventScript_BuyKingsRock::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, KINGS_ROCK_COINS, TurquoiseCity_GameCorner_EventScript_NotEnoughCoinsForItem
	checkitemspace ITEM_KINGS_ROCK
	goto_if_eq VAR_RESULT, FALSE, TurquoiseCity_GameCorner_EventScript_NoRoomForItem
	removecoins KINGS_ROCK_COINS
	additem ITEM_KINGS_ROCK
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox TurquoiseCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto TurquoiseCity_GameCorner_EventScript_ReturnToChooseItemPrize
	end

TurquoiseCity_GameCorner_EventScript_BuyOniMask::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, ONI_MASK_COINS, TurquoiseCity_GameCorner_EventScript_NotEnoughCoinsForItem
	checkitemspace ITEM_ONI_MASK
	goto_if_eq VAR_RESULT, FALSE, TurquoiseCity_GameCorner_EventScript_NoRoomForItem
	removecoins ONI_MASK_COINS
	additem ITEM_ONI_MASK
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox TurquoiseCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto TurquoiseCity_GameCorner_EventScript_ReturnToChooseItemPrize
	end

TurquoiseCity_GameCorner_EventScript_BuyReaperCloth::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, REAPER_CLOTH_COINS, TurquoiseCity_GameCorner_EventScript_NotEnoughCoinsForItem
	checkitemspace ITEM_REAPER_CLOTH
	goto_if_eq VAR_RESULT, FALSE, TurquoiseCity_GameCorner_EventScript_NoRoomForItem
	removecoins REAPER_CLOTH_COINS
	additem ITEM_REAPER_CLOTH
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox TurquoiseCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto TurquoiseCity_GameCorner_EventScript_ReturnToChooseItemPrize
	end

TurquoiseCity_GameCorner_EventScript_BuyUpgrade::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, UPGRADE_COINS, TurquoiseCity_GameCorner_EventScript_NotEnoughCoinsForItem
	checkitemspace ITEM_UPGRADE
	goto_if_eq VAR_RESULT, FALSE, TurquoiseCity_GameCorner_EventScript_NoRoomForItem
	removecoins UPGRADE_COINS
	additem ITEM_UPGRADE
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox TurquoiseCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto TurquoiseCity_GameCorner_EventScript_ReturnToChooseItemPrize
	end

TurquoiseCity_GameCorner_EventScript_NotEnoughCoinsForItem::
	msgbox TurquoiseCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto TurquoiseCity_GameCorner_EventScript_ReturnToChooseItemPrize
	end

TurquoiseCity_GameCorner_EventScript_NoRoomForItem::
	call Common_EventScript_BagIsFull
	goto TurquoiseCity_GameCorner_EventScript_ReturnToChooseItemPrize
	end

TurquoiseCity_GameCorner_EventScript_CancelItemSelect::
	msgbox TurquoiseCity_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	release
	end

TurquoiseCity_GameCorner_Text_ExchangeCoinsForPrizes:
	.string "Welcome.\p"
	.string "You can exchange your COINS for\n"
	.string "prizes here.$"

TurquoiseCity_GameCorner_Text_WhichPrize:
	.string "Which prize would you like?$"

TurquoiseCity_GameCorner_Text_SoYourChoiceIsTheItemX:
	.string "So your choice is\n"
	.string "the {STR_VAR_1}?$"

TurquoiseCity_GameCorner_Text_OhIsThatSo:
	.string "Oh, is that so? \n"
	.string "You need to save some COINS before\l"
	.string "coming back here.$"

TurquoiseCity_GameCorner_Text_SoYourChoiceIsX:
	.string "So your choice is {STR_VAR_1}?$"

TurquoiseCity_GameCorner_Text_HereYouGo:
	.string "Here you go!$"














TurquoiseCity_GameCorner_EventScript_PrizeCornerMons::
	lock
	faceplayer
	msgbox TurquoiseCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, TurquoiseCity_GameCorner_EventScript_ChooseMonPrizeMessage
	release
	end

TurquoiseCity_GameCorner_EventScript_ChooseMonPrizeMessage::
	message TurquoiseCity_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto TurquoiseCity_GameCorner_EventScript_ChooseMonPrize

TurquoiseCity_GameCorner_EventScript_ReturnToChooseMonPrize::
	message TurquoiseCity_GameCorner_Text_WhichPrize
	waitmessage
	goto TurquoiseCity_GameCorner_EventScript_ChooseMonPrize

TurquoiseCity_GameCorner_EventScript_ChooseMonPrize::
	scrollingmultichoice 15, 22, 0, 6, TRUE
	switch VAR_RESULT
	case 0, TurquoiseCity_GameCorner_EventScript_Solosis
	case 1, TurquoiseCity_GameCorner_EventScript_Cryogonal
	case 2, TurquoiseCity_GameCorner_EventScript_Klefki
	case 3, TurquoiseCity_GameCorner_EventScript_Larvitar
	case 4, TurquoiseCity_GameCorner_EventScript_Beldum
	case 5, TurquoiseCity_GameCorner_EventScript_Deino
	case 6, TurquoiseCity_GameCorner_EventScript_Dreepy
	case 7, TurquoiseCity_GameCorner_EventScript_Porygon
	case 8, TurquoiseCity_GameCorner_EventScript_CancelMonSelect
	goto TurquoiseCity_GameCorner_EventScript_CancelMonSelect
	end

TurquoiseCity_GameCorner_EventScript_CancelMonSelect::
	hidecoinsbox 0, 0
	release
	end

TurquoiseCity_GameCorner_EventScript_Solosis::
	setvar VAR_TEMP_1, SPECIES_SOLOSIS
	setvar VAR_TEMP_2, SOLOSIS_COINS
	goto TurquoiseCity_GameCorner_EventScript_ConfirmPrizeMon
	end

TurquoiseCity_GameCorner_EventScript_Cryogonal::
	setvar VAR_TEMP_1, SPECIES_CRYOGONAL
	setvar VAR_TEMP_2, CRYOGONAL_COINS
	goto TurquoiseCity_GameCorner_EventScript_ConfirmPrizeMon
	end

TurquoiseCity_GameCorner_EventScript_Klefki::
	setvar VAR_TEMP_1, SPECIES_KLEFKI
	setvar VAR_TEMP_2, KLEFKI_COINS
	goto TurquoiseCity_GameCorner_EventScript_ConfirmPrizeMon
	end

TurquoiseCity_GameCorner_EventScript_Larvitar::
	setvar VAR_TEMP_1, SPECIES_LARVITAR
	setvar VAR_TEMP_2, LARVITAR_COINS
	goto TurquoiseCity_GameCorner_EventScript_ConfirmPrizeMon
	end

TurquoiseCity_GameCorner_EventScript_Beldum::
	setvar VAR_TEMP_1, SPECIES_BELDUM
	setvar VAR_TEMP_2, BELDUM_COINS
	goto TurquoiseCity_GameCorner_EventScript_ConfirmPrizeMon
	end

TurquoiseCity_GameCorner_EventScript_Deino::
	setvar VAR_TEMP_1, SPECIES_DEINO_ISSHOAN
	setvar VAR_TEMP_2, DEINO_COINS
	goto TurquoiseCity_GameCorner_EventScript_ConfirmPrizeMon
	end

TurquoiseCity_GameCorner_EventScript_Dreepy::
	setvar VAR_TEMP_1, SPECIES_DREEPY_ISSHOAN
	setvar VAR_TEMP_2, DREEPY_COINS
	goto TurquoiseCity_GameCorner_EventScript_ConfirmPrizeMon
	end

TurquoiseCity_GameCorner_EventScript_Porygon::
	setvar VAR_TEMP_1, SPECIES_PORYGON
	setvar VAR_TEMP_2, PORYGON_COINS
	goto TurquoiseCity_GameCorner_EventScript_ConfirmPrizeMon
	end

TurquoiseCity_GameCorner_EventScript_ConfirmPrizeMon::
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	msgbox TurquoiseCity_GameCorner_Text_YouWantPrize, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TurquoiseCity_GameCorner_EventScript_CancelMonSelect
	checkcoins VAR_RESULT
	goto_if_lt VAR_RESULT, VAR_TEMP_2, TurquoiseCity_GameCorner_EventScript_NotEnoughCoinsForMon
	switch VAR_TEMP_1
	case SPECIES_SOLOSIS,        TurquoiseCity_GameCorner_EventScript_GiveSolosis
	case SPECIES_CRYOGONAL,      TurquoiseCity_GameCorner_EventScript_GiveCryogonal
	case SPECIES_KLEFKI,         TurquoiseCity_GameCorner_EventScript_GiveKlefki
	case SPECIES_LARVITAR,       TurquoiseCity_GameCorner_EventScript_GiveLarvitar
	case SPECIES_BELDUM,         TurquoiseCity_GameCorner_EventScript_GiveBeldum
	case SPECIES_DEINO_ISSHOAN,  TurquoiseCity_GameCorner_EventScript_GiveDeino
	case SPECIES_DREEPY_ISSHOAN, TurquoiseCity_GameCorner_EventScript_GiveDreepy
	case SPECIES_PORYGON,        TurquoiseCity_GameCorner_EventScript_GivePorygon
	end

TurquoiseCity_GameCorner_Text_YouWantPrize::
	.string "So, you want the {STR_VAR_1}?$"

TurquoiseCity_GameCorner_EventScript_GiveSolosis::
	givemon VAR_TEMP_1, 30
	goto TurquoiseCity_GameCorner_EventScript_CheckReceivedMon
	end

TurquoiseCity_GameCorner_EventScript_GiveCryogonal::
	givemon VAR_TEMP_1, 33
	goto TurquoiseCity_GameCorner_EventScript_CheckReceivedMon
	end

TurquoiseCity_GameCorner_EventScript_GiveKlefki::
	givemon VAR_TEMP_1, 33
	goto TurquoiseCity_GameCorner_EventScript_CheckReceivedMon
	end

TurquoiseCity_GameCorner_EventScript_GiveLarvitar::
	givemon VAR_TEMP_1, 30
	goto TurquoiseCity_GameCorner_EventScript_CheckReceivedMon
	end

TurquoiseCity_GameCorner_EventScript_GiveBeldum::
	givemon VAR_TEMP_1, 30
	goto TurquoiseCity_GameCorner_EventScript_CheckReceivedMon
	end

TurquoiseCity_GameCorner_EventScript_GiveDeino::
	givemon VAR_TEMP_1, 30
	goto TurquoiseCity_GameCorner_EventScript_CheckReceivedMon
	end

TurquoiseCity_GameCorner_EventScript_GiveDreepy:
	givemon VAR_TEMP_1, 30
	goto TurquoiseCity_GameCorner_EventScript_CheckReceivedMon
	end

TurquoiseCity_GameCorner_EventScript_GivePorygon::
	givemon VAR_TEMP_1, 36
	goto TurquoiseCity_GameCorner_EventScript_CheckReceivedMon
	end

TurquoiseCity_GameCorner_EventScript_CheckReceivedMon::
	goto_if_eq VAR_RESULT, 0, TurquoiseCity_GameCorner_EventScript_ReceivedMonParty
	goto_if_eq VAR_RESULT, 1, TurquoiseCity_GameCorner_EventScript_ReceivedMonPC
	goto_if_eq VAR_RESULT, 2, TurquoiseCity_GameCorner_EventScript_PartyFull
	end

TurquoiseCity_GameCorner_EventScript_PartyFull::
	msgbox TurquoiseCity_GameCornerText_NoMoreRoomForPokemon
	hidecoinsbox 0, 0
	release
	end

TurquoiseCity_GameCornerText_NoMoreRoomForPokemon::
	.string "There's no more room for POKéMON!\p"
	.string "The POKéMON BOXES are full and\n"
	.string "can't accept any more!$"

TurquoiseCity_GameCorner_EventScript_NicknamePartyMon::
	getpartysize
	subvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	call Common_EventScript_NameReceivedPartyMon
	goto TurquoiseCity_GameCorner_EventScript_CancelMonSelect
	end

TurquoiseCity_GameCorner_EventScript_NotEnoughCoinsForMon::
	msgbox TurquoiseCity_GameCorner_Text_NotEnoughCoins
	goto TurquoiseCity_GameCorner_EventScript_CancelMonSelect
	end

TurquoiseCity_GameCorner_Text_NotEnoughCoins:
	.string "You don't have enough COINS.$"

TurquoiseCity_GameCorner_EventScript_ReceivedMonParty::
	removecoins VAR_TEMP_2
	updatecoinsbox 0, 5
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	playfanfare MUS_LEVEL_UP
	message Text_PlayerObtainedTheMon
	waitmessage
	waitfanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TurquoiseCity_GameCorner_EventScript_NicknamePartyMon
	goto TurquoiseCity_GameCorner_EventScript_CancelMonSelect
	end

Text_PlayerObtainedTheMon::
    .string "{PLAYER} obtained\n"
    .string "the {STR_VAR_1}!$"

TurquoiseCity_GameCorner_EventScript_ReceivedMonPC::
	removecoins VAR_TEMP_2
	updatecoinsbox 0, 5
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	playfanfare MUS_LEVEL_UP
	message Text_PlayerObtainedTheMon
	waitmessage
	waitfanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TurquoiseCity_GameCorner_EventScript_TransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto TurquoiseCity_GameCorner_EventScript_TransferredToPC
	end

TurquoiseCity_GameCorner_EventScript_TransferredToPC::
	call Common_EventScript_TransferredToPC
	goto TurquoiseCity_GameCorner_EventScript_CancelMonSelect
	end














TurquoiseCity_GameCorner_EventScript_Woman::
	lock
	faceplayer
	msgbox TurquoiseCity_GameCorner_Text_MachinesAreRigged, MSGBOX_DEFAULT
	goto TurquoiseCity_GameCorner_EventScript_NPCReturnToSlots
	end

TurquoiseCity_GameCorner_Text_MachinesAreRigged:
	.string "I swear these machines are rigged.\p"
	.string "I have much better luck when\n"
	.string "I'm sitting over here.$"

TurquoiseCity_GameCorner_EventScript_Gentleman::
	msgbox TurquoiseCity_GameCorner_Text_RouletteOnlyLuck, MSGBOX_NPC
	end

TurquoiseCity_GameCorner_Text_RouletteOnlyLuck:
	.string "This ROULETTE thing…\n"
	.string "It's rather demanding.\p"
	.string "Win or lose, it's only by luck.$"

TurquoiseCity_GameCorner_EventScript_Fisherman::
	lock
	faceplayer
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, TurquoiseCity_GameCorner_EventScript_TryGive20Coins
	msgbox TurquoiseCity_GameCorner_Text_NeedCoinCaseGoToDesk, MSGBOX_DEFAULT
	goto TurquoiseCity_GameCorner_EventScript_NPCReturnToSlots
	end

TurquoiseCity_GameCorner_EventScript_TryGive20Coins::
	goto_if_set FLAG_RECEIVED_20_COINS, TurquoiseCity_GameCorner_EventScript_FishermanNormal
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, 1, TurquoiseCity_GameCorner_EventScript_FishermanNormal @ Only give 20 coins if player has no coins
	msgbox TurquoiseCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_20_COINS
	addcoins 20
	message TurquoiseCity_GameCorner_Text_Received20Coins
	waitmessage
	playse SE_SHOP
	delay 60
	@waitmessage
	goto TurquoiseCity_GameCorner_EventScript_NPCReturnToSlots
	end

TurquoiseCity_GameCorner_EventScript_FishermanNormal::
	msgbox TurquoiseCity_GameCorner_Text_TurquoiseSomethingForEveryone, MSGBOX_DEFAULT
	goto TurquoiseCity_GameCorner_EventScript_NPCReturnToSlots
	end

TurquoiseCity_GameCorner_Text_NeedCoinCaseGoToDesk:
	.string "Hey, kid, if you want to play here,\n"
	.string "you need a COIN CASE.\p"
	.string "Talk to the nice ladies at\n"
	.string "the desk to get one.$"

TurquoiseCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins:
	.string "My luck can only last so long.\n"
	.string "This is too much for me.\l"
	.string "Here, take some COINS!$"

TurquoiseCity_GameCorner_Text_Received20Coins:
	.string "{PLAYER} received 20 COINS.$"

TurquoiseCity_GameCorner_Text_TurquoiseSomethingForEveryone:
	.string "TURQUOISE CITY has something for\n"
	.string "everyone.\p"
	.string "For me, it's the GAME CORNER.$"

TurquoiseCity_GameCorner_EventScript_Man2::
	lock
	faceplayer
	msgbox TurquoiseCity_GameCorner_Text_EasyToLoseTrackOfTime, MSGBOX_DEFAULT
	goto TurquoiseCity_GameCorner_EventScript_NPCReturnToSlots
	end

TurquoiseCity_GameCorner_Text_EasyToLoseTrackOfTime:
	.string "It's easy to lose track of time in here. \n"
	.string "I should really get back to work.$"

TurquoiseCity_GameCorner_EventScript_Maniac::
	lock
	faceplayer
	msgbox TurquoiseCity_GameCorner_Text_GameIsAddicting, MSGBOX_DEFAULT
	goto TurquoiseCity_GameCorner_EventScript_NPCReturnToSlots
	end

TurquoiseCity_GameCorner_Text_GameIsAddicting:
	.string "This game is so addicting.\n"
	.string "I just can't stop playing.$"

TurquoiseCity_GameCorner_EventScript_Man1::
	lock
	faceplayer
	msgbox TurquoiseCity_GameCorner_Text_HeresSomeSlotsInfo, MSGBOX_DEFAULT
	goto TurquoiseCity_GameCorner_EventScript_NPCReturnToSlots
	end

TurquoiseCity_GameCorner_Text_HeresSomeSlotsInfo:
	.string "Here's some information for you\n"
	.string "about the SLOTS.\p"
	.string "The more lightning bolts you stock,\n"
	.string "the more REEL TIME chances you get.\p"
	.string "In a game with the maximum five\n"
	.string "REEL TIME chances…\p"
	.string "It is possible to receive four regular\n"
	.string "bonuses, then a big bonus.\p"
	.string "That would total 660 COINS, but it's\n"
	.string "very difficult to get.$"

TurquoiseCity_GameCorner_EventScript_NPCReturnToSlots::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

TurquoiseCity_GameCorner_EventScript_Man4::
	lock
	faceplayer
	msgbox TurquoiseCity_GameCorner_Text_KidsGambling, MSGBOX_DEFAULT
	release
	end

TurquoiseCity_GameCorner_Text_KidsGambling:
	.string "Some people think kids shouldn't\n"
	.string "be allowed to gamble.\p"
	.string "But here in TURQUOISE CITY,\n"
	.string "we don't discriminate.\p"
	.string "They got money too, don't they?\p"
	.string "The more, the merrier.\n"
	.string "That's what I always say.$"

TurquoiseCity_GameCorner_EventScript_Youngster::
	lock
	faceplayer
	msgbox TurquoiseCity_GameCorner_Text_CantWinJackpot, MSGBOX_DEFAULT
	release
	end

TurquoiseCity_GameCorner_Text_CantWinJackpot:
	.string "There's a prize I really want, but\n"
	.string "I still don't have enough COINS.$"















TurquoiseCity_GameCorner_EventScript_Blackjack::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, TurquoiseCity_GameCorner_EventScript_NoCoinCase
	msgbox TurquoiseCity_GameCorner_Text_BlackJack, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, NO, TurquoiseCity_GameCorner_CancelBJ
	playbgm MUS_GAME_CORNER, FALSE
	special StartBlackJack
	waitstate
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

TurquoiseCity_GameCorner_CancelBJ::
	closemessage
	releaseall
	end

TurquoiseCity_GameCorner_Text_BlackJack:
	.string "It's a BLACKJACK TABLE!\n"
	.string "Want to play?$"






TurquoiseCity_GameCorner_EventScript_Snake::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, TurquoiseCity_GameCorner_EventScript_NoCoinCase
	checkcoins VAR_TEMP_2
	@goto_if_lt VAR_TEMP_2, 25, Onix_Not_Enough
	goto_if_lt VAR_TEMP_2, 5, Onix_Not_Enough
	showcoinsbox 1, 1
	msgbox TurquoiseCity_GameCorner_Text_Snake, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, NO, TurquoiseCity_GameCorner_CancelVF
	@removecoins 25
	removecoins 5
	updatecoinsbox 1, 1
	playse SE_SHOP
	delay 40
	hidecoinsbox 0, 5
	playbgm MUS_NONE, FALSE
	special StartSnake
	waitstate
	savebgm MUS_DUMMY
	fadedefaultbgm
	goto_if_eq VAR_FLIP_WINNINGS, 0, TurquoiseCity_GameCorner_NoWin
	showcoinsbox 1, 1
	buffernumberstring STR_VAR_1, VAR_FLIP_WINNINGS
	msgbox PB_YOU_WON_TEXT, MSGBOX_DEFAULT
	waitmessage
	addcoins VAR_FLIP_WINNINGS
	setvar VAR_FLIP_WINNINGS, 0
	updatecoinsbox 1, 1
	playse SE_SHOP
	delay 40
	hidecoinsbox 0, 5
	closemessage
	releaseall
	end	

TurquoiseCity_GameCorner_Text_Snake:
	.string "It's ONIX!\n"
	.string "It costs 5 COINS to play.$"	

Onix_Not_Enough::
	msgbox Snake_Not_Enough, MSGBOX_DEFAULT
	releaseall
	end

Snake_Not_Enough:
	.string "It's ONIX!\p"
	.string "You don't have enough COINS…$"	







TurquoiseCity_GameCorner_NoWin::
	releaseall
	end	






TurquoiseCity_GameCorner_EventScript_VoltorbFlip::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, TurquoiseCity_GameCorner_EventScript_NoCoinCase
	checkcoins VAR_TEMP_2
	@goto_if_lt VAR_TEMP_2, 50, VF_Not_Enough
	goto_if_lt VAR_TEMP_2, 10, VF_Not_Enough
	showcoinsbox 1, 1
	msgbox TurquoiseCity_GameCorner_Text_VF, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, NO, TurquoiseCity_GameCorner_CancelVF
	@removecoins 50
	removecoins 10
	updatecoinsbox 1, 1
	playse SE_SHOP
	delay 40
	hidecoinsbox 0, 5
	playbgm MUS_RG_OAK, FALSE
	setvar VAR_FLIP_WINNINGS, 0
	special Special_ViewVoltorbFlip
	waitstate
	goto_if_eq VAR_RESULT, 0, VF_Come_Again
	goto_if_eq VAR_RESULT, 1, VF_Go_On
	releaseall
	end
	
TurquoiseCity_GameCorner_Text_VF:
	.string "It's VOLTORB FLIP!\n"
	.string "It costs 10 COINS to play.$"

VF_Come_Again::
	savebgm MUS_DUMMY
	fadedefaultbgm
	msgbox VF_Come_Again_Text, MSGBOX_DEFAULT
	setvar VAR_FLIP_WINNINGS, 0
	releaseall
	end

VF_Come_Again_Text:
	.string "Too bad.\n"
	.string "Try again soon!$"
	
VF_Go_On::
	showcoinsbox 1, 1
	buffernumberstring STR_VAR_1, VAR_FLIP_WINNINGS	
	msgbox TurquoiseCity_GameCorner_Text_VF_Keep_Going, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, NO, VF_Cash_Out
	goto VF_Loop
	
VF_Loop::
	hidecoinsbox 0, 5
	special Special_ViewVoltorbFlip
	waitstate
	goto_if_eq VAR_RESULT, 0, VF_Come_Again
	goto_if_eq VAR_RESULT, 1, VF_Go_On
	releaseall
	end
	
VF_Cash_Out::	
	addcoins VAR_FLIP_WINNINGS
	setvar VAR_FLIP_WINNINGS, 0
	setvar VAR_FLIP_LEVEL, 0
	updatecoinsbox 1, 1
	playse SE_SHOP
	savebgm MUS_DUMMY
	fadedefaultbgm
	delay 40
	hidecoinsbox 0, 5
	releaseall
	end

TurquoiseCity_GameCorner_Text_VF_Keep_Going:
	.string "You've made {STR_VAR_1} COINS.\n"
	.string "Keep going?$"

VF_Not_Enough::
	msgbox Flip_Not_Enough, MSGBOX_DEFAULT
	releaseall
	end

Flip_Not_Enough:
	.string "It's VOLTORB FLIP!\p"
	.string "You don't have enough COINS…$"
	
TurquoiseCity_GameCorner_CancelVF::
	hidecoinsbox 0, 5
	closemessage
	releaseall
	end








TurquoiseCity_GameCorner_EventScript_PinballMeowth::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, TurquoiseCity_GameCorner_EventScript_NoCoinCase
	checkcoins VAR_TEMP_2
	@goto_if_lt VAR_TEMP_2, 25, Pinball_Not_Enough
	goto_if_lt VAR_TEMP_2, 5, Pinball_Not_Enough
	showcoinsbox 1, 1
	msgbox TurquoiseCity_GameCorner_Text_Pinball_Meowth, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, NO, TurquoiseCity_GameCorner_CancelVF	
	@removecoins 25
	removecoins 5
	updatecoinsbox 1, 1
	playse SE_SHOP
	delay 40
	hidecoinsbox 0, 5
	playbgm MUS_RG_POKE_CENTER, FALSE
	callnative PlayMeowthPinballGame
    waitstate
	savebgm MUS_DUMMY
	fadedefaultbgm
	goto_if_eq VAR_FLIP_WINNINGS, 0, TurquoiseCity_GameCorner_NoWin
	showcoinsbox 1, 1
	buffernumberstring STR_VAR_1, VAR_FLIP_WINNINGS
	msgbox PB_YOU_WON_TEXT, MSGBOX_DEFAULT
	waitmessage
	addcoins VAR_FLIP_WINNINGS
	setvar VAR_FLIP_WINNINGS, 0
	updatecoinsbox 1, 1
	playse SE_SHOP
	delay 40
	hidecoinsbox 0, 5
	closemessage
	releaseall
	end

TurquoiseCity_GameCorner_Text_Pinball_Meowth:
	.string "It's a PINBALL MACHINE!\n"
	.string "It costs 5 COINS to play.$"

Pinball_Not_Enough::
	msgbox PB_Not_Enough, MSGBOX_DEFAULT
	releaseall
	end	

PB_Not_Enough:
	.string "It's a PINBALL MACHINE!\p"
	.string "You don't have enough COINS…$"

PB_YOU_WON_TEXT:
	.string "You won\n"
	.string "{STR_VAR_1} COINS!$"








TurquoiseCity_GameCorner_EventScript_SlotMachine0::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, TurquoiseCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

TurquoiseCity_GameCorner_EventScript_SlotMachine1::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, TurquoiseCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

TurquoiseCity_GameCorner_EventScript_SlotMachine2::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, TurquoiseCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

TurquoiseCity_GameCorner_EventScript_SlotMachine3::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, TurquoiseCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 3
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

TurquoiseCity_GameCorner_EventScript_SlotMachine4::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, TurquoiseCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 4
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

TurquoiseCity_GameCorner_EventScript_SlotMachine5::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, TurquoiseCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 5
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

TurquoiseCity_GameCorner_EventScript_SlotMachine6::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, TurquoiseCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 6
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

TurquoiseCity_GameCorner_EventScript_SlotMachine7::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, TurquoiseCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 7
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

TurquoiseCity_GameCorner_EventScript_SlotMachine8::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, TurquoiseCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 8
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

TurquoiseCity_GameCorner_EventScript_SlotMachine9::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, TurquoiseCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 9
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

TurquoiseCity_GameCorner_EventScript_SlotMachine10::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, TurquoiseCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 10
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

TurquoiseCity_GameCorner_EventScript_SlotMachine11::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, TurquoiseCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 11
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end






























TurquoiseCity_GameCorner_EventScript_AceTrainer::
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_14
	goto_if_eq VAR_RESULT, TRUE, TurquoiseCity_GameCorner_EventScript_PostBlackjackQuest
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_14
	goto_if_eq VAR_RESULT, TRUE, TurquoiseCity_GameCorner_EventScript_BlackjackQuestInProgress
	msgbox TurquoiseCity_GameCorner_Text_BlackjackIntro1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TurquoiseCity_GameCorner_EventScript_SkipBlackjackQuest
	msgbox TurquoiseCity_GameCorner_Text_BlackjackIntro2, MSGBOX_DEFAULT
	startquest QUEST_14
	goto TurquoiseCity_GameCorner_EventScript_NPCReturnToSlots
	end	

TurquoiseCity_GameCorner_EventScript_BlackjackQuestInProgress::
	goto_if_set FLAG_BLACKJACK_HIGH_SCORE_ACHIEVED, TurquoiseCity_GameCorner_EventScript_CompleteBlackjackQuest
	msgbox TurquoiseCity_GameCorner_Text_BlackjackQuestInProgress, MSGBOX_DEFAULT
	goto TurquoiseCity_GameCorner_EventScript_NPCReturnToSlots
	end

TurquoiseCity_GameCorner_EventScript_SkipBlackjackQuest::
	msgbox TurquoiseCity_GameCorner_Text_SkipBlackjack, MSGBOX_DEFAULT
	goto TurquoiseCity_GameCorner_EventScript_NPCReturnToSlots
	end

TurquoiseCity_GameCorner_EventScript_CompleteBlackjackQuest::
	@applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	@playse SE_PIN
	@waitmovement 0
	@applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	@waitmovement 0
	msgbox TurquoiseCity_GameCorner_Text_CompleteBlackjackQuest, MSGBOX_DEFAULT
	giveitem ITEM_LOADED_DICE
	@msgbox TurquoiseCity_GameCorner_Text_ExplainLoadedDice, MSGBOX_DEFAULT
	completequest QUEST_14
	goto TurquoiseCity_GameCorner_EventScript_NPCReturnToSlots
	end

TurquoiseCity_GameCorner_EventScript_PostBlackjackQuest::
	msgbox TurquoiseCity_GameCorner_Text_ExplainLoadedDice, MSGBOX_DEFAULT
	goto TurquoiseCity_GameCorner_EventScript_NPCReturnToSlots
	end

TurquoiseCity_GameCorner_Text_BlackjackIntro1:
	.string "Gambling's not all luck.\p"
	.string "A good gambler ought to know how\n"
	.string "the odds work so he can\l"
	.string "tip 'em in his favor.\p"
	.string "You know what I mean, kid?$"


TurquoiseCity_GameCorner_Text_SkipBlackjack:
	.string "Yeah, I thought as much.$"


TurquoiseCity_GameCorner_Text_BlackjackIntro2:
	.string "Oh yeah? Well let's see you put your\n"
	.string "money wear your mouth is.\p"
	.string "I got just the kind of thing that\n"
	.string "every professional gambler needs.\p"
	.string "Only I gotta know you're worth it first.\n"
	.string "I ain't giving this to no amateur.\p"
	.string "So here's what I need you to do.\p"
	.string "Bet 1000 COINS in a single game of\n"
	.string "BLACKJACK and take home the pot.\p"
	.string "Think you can manage that, kid?$"


TurquoiseCity_GameCorner_Text_BlackjackQuestInProgress:
	.string "Come on, don't give up yet.\n"
	.string "Let's see you win those COINS.$"


TurquoiseCity_GameCorner_Text_CompleteBlackjackQuest:
	.string "That was a risky play, kid.\n"
	.string "But you pulled it off. Well done.\p"
	.string "As promised, I'm entrusting you\n"
	.string "with these babies.$"


TurquoiseCity_GameCorner_Text_ExplainLoadedDice:
	.string "Some POKéMON know moves that can\n"
	.string "hit more than once in a row.\p"
	.string "Give those LOADED DICE to 'em to hold.\n"
	.string "They'll tip the odds in your favor!$"









TurquoiseCity_GameCorner_EventScript_Bard::
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_15
	goto_if_eq VAR_RESULT, TRUE, TurquoiseCity_GameCorner_EventScript_PostOnixQuest
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_15
	goto_if_eq VAR_RESULT, TRUE, TurquoiseCity_GameCorner_EventScript_OnixQuestInProgress
	msgbox TurquoiseCity_GameCorner_Text_OnixHighScore, MSGBOX_DEFAULT
	startquest QUEST_15
	goto TurquoiseCity_GameCorner_EventScript_NPCReturnToSlots
	end	

TurquoiseCity_GameCorner_EventScript_OnixQuestInProgress::
	goto_if_set FLAG_ONIX_HIGH_SCORE_ACHIEVED, TurquoiseCity_GameCorner_EventScript_CompleteOnixQuest
	msgbox TurquoiseCity_GameCorner_Text_OnixQuestInProgress, MSGBOX_DEFAULT
	goto TurquoiseCity_GameCorner_EventScript_NPCReturnToSlots
	end

TurquoiseCity_GameCorner_EventScript_CompleteOnixQuest::
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox TurquoiseCity_GameCorner_Text_CompleteOnixQuest, MSGBOX_DEFAULT
	giveitem ITEM_LUCKY_EGG, 6
	msgbox TurquoiseCity_GameCorner_Text_ExplainLuckyEggs, MSGBOX_DEFAULT
	completequest QUEST_15
	goto TurquoiseCity_GameCorner_EventScript_NPCReturnToSlots
	end

TurquoiseCity_GameCorner_EventScript_PostOnixQuest::
	msgbox TurquoiseCity_GameCorner_Text_ExplainLuckyEggs, MSGBOX_DEFAULT
	goto TurquoiseCity_GameCorner_EventScript_NPCReturnToSlots
	end

TurquoiseCity_GameCorner_Text_OnixHighScore:
	.string "I just love playing ONIX.\n"
	.string "It's so addicting!\p"
	.string "My high score right now is 80 COINS.\n"
	.string "Do you think you can beat that?\p"
	.string "I'd like to see you try.$"


TurquoiseCity_GameCorner_Text_OnixQuestInProgress:
	.string "My high score is 80 COINS.\n"
	.string "Let's see you beat that.$"


TurquoiseCity_GameCorner_Text_CompleteOnixQuest:
	.string "Haha, I knew you could do it!\n"
	.string "You got the new ONIX high score!\p"
	.string "Well played, my friend.\n"
	.string "Say, why don't you hold onto these.$"


TurquoiseCity_GameCorner_Text_ExplainLuckyEggs:
	.string "Give those LUCKY EGGS to your\n"
	.string "POKéMON to hold.\p"
	.string "They'll earn twice as much\n"
	.string "experience in battle.$"













