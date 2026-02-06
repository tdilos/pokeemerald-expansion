.set STARTER_PRICE, 10
.set STARTER_LEVEL, 10

BattleFrontier_Lounge6_MapScripts::
	.byte 0

BattleFrontier_Lounge6_EventScript_Beauty::
	lock
	faceplayer
	@goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_TradeCompleted
	@ingame_trade INGAME_TRADE_MEOWTH, BattleFrontier_Lounge6_Text_WouldYouLikeToTrade, BattleFrontier_Lounge6_EventScript_DeclineTrade, BattleFrontier_Lounge6_EventScript_NotRequestedMon, BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt
	@setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
	msgbox BattleFrontier_Lounge6_Text_SkittyOrMeowth, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_Text_SkittyOrMeowth:
	.string "Which POKéMON do you think is cuter?\n"
	.string "SKITTY or MEOWTH?$"

BattleFrontier_Lounge6_EventScript_GameboyKid::
	lock
	faceplayer
	goto_if_set FLAG_FRONTIER_NPC_TRADE_1_COMPLETED, BattleFrontier_Lounge6_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_TRUBBISH
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox BattleFrontier_Lounge6_Text_WillingToTradeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge6_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge6_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, BattleFrontier_Lounge6_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	giveitem ITEM_COVENANT_ORB
	waitfanfare
	msgbox BattleFrontier_Lounge6_Text_UrAwesome, MSGBOX_DEFAULT
	setflag FLAG_FRONTIER_NPC_TRADE_1_COMPLETED
	release
	end

BattleFrontier_Lounge6_EventScript_DeclineTrade::
	release
	end

BattleFrontier_Lounge6_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_Lounge6_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_TradeCompleted::
	msgbox BattleFrontier_Lounge6_Text_TradeWithOthers, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_Text_WillingToTradeIt:
	.string "Hi! Do you have a {STR_VAR_1}!\p"
	.string "Would you trade it for my {STR_VAR_2}?$"

BattleFrontier_Lounge6_Text_UrAwesome:
	.string "You're awesome! Thanks!$"

BattleFrontier_Lounge6_Text_WontAcceptAnyLessThanRealMon:
	.string "No, no, no! I won't accept any\n"
	.string "less than a real {STR_VAR_1}!$"

BattleFrontier_Lounge6_Text_TradeWithOthers:
	.string "I trade with my friends in other\n"
	.string "cities all the time.$"







BattleFrontier_Lounge6_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_TradeCompleted2
	setvar VAR_0x8008, INGAME_TRADE_MEOWTH
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox BattleFrontier_Lounge6_Text_WouldYouLikeToTrade, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge6_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge6_EventScript_DeclineTrade2
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, BattleFrontier_Lounge6_EventScript_NotRequestedMon2
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt, MSGBOX_DEFAULT
	setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
	release
	end

BattleFrontier_Lounge6_EventScript_DeclineTrade2::
	msgbox BattleFrontier_Lounge6_Text_WellThatsFineToo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_NotRequestedMon2::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_TradeCompleted2::
	msgbox BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_Text_WouldYouLikeToTrade:
	.string "My POKéMON is a {STR_VAR_2}.\n"
	.string "Do you know it?\l"
	.string "It's quite cute and rather nice.\p"
	.string "This little one, I could trade with\n"
	.string "pride!\p"
	.string "Would you like to trade me a {STR_VAR_1}\n"
	.string "for my {STR_VAR_2}?$"

BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt:
	.string "Oh, it's adorable!\n"
	.string "Thank you!\l"
	.string "I promise I'll be good to it!\p"
	.string "Oh! I hope you'll be good to\n"
	.string "my {STR_VAR_2}, too!$"

BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon:
	.string "Oh, I'm sorry!\n"
	.string "I don't intend to trade for anything\l"
	.string "but a {STR_VAR_1}.$"

BattleFrontier_Lounge6_Text_WellThatsFineToo:
	.string "Oh, you won't?\n"
	.string "Well, that's fine, too.\l"
	.string "Please come visit us again.$"

BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined:
	.string "Giggle!\n"
	.string "A SKITTY is so much cuter than I had\l"
	.string "imagined. I'm delighted!$"







BattleFrontier_Lounge6_EventScript_FireStarterSeller::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge6_Text_ExchangeCoinsForPrizes, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BattleFrontier_Lounge6_EventScript_ChooseMonPrizeMessage
	release
	end

BattleFrontier_Lounge6_Text_ExchangeCoinsForPrizes:
	.string "Looking for new POKéMON to raise?\n"
	.string "I've got some really rare ones here.\p"
	.string "I'll let you adopt one in exchange\n"
	.string "for 10 Battle Points.\p"
	.string "Have we got a deal?$"

BattleFrontier_Lounge6_EventScript_ChooseMonPrizeMessage::
	message BattleFrontier_Lounge6_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	special ShowBattlePointsWindow
	goto BattleFrontier_Lounge6_EventScript_ChooseMonPrize

BattleFrontier_Lounge6_Text_WhichPrize:
	.string "Which POKéMON would you like?$"

BattleFrontier_Lounge6_EventScript_ReturnToChooseMonPrize::
	message BattleFrontier_Lounge6_Text_WhichPrize
	waitmessage
	goto BattleFrontier_Lounge6_EventScript_ChooseMonPrize

BattleFrontier_Lounge6_EventScript_ChooseMonPrize::
	scrollingmultichoice 17, 22, 0, 6, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge6_EventScript_Charmander
	case 1, BattleFrontier_Lounge6_EventScript_Cyndaquil
	case 2, BattleFrontier_Lounge6_EventScript_Torchic
	case 3, BattleFrontier_Lounge6_EventScript_Chimchar
	case 4, BattleFrontier_Lounge6_EventScript_Tepig
	case 5, BattleFrontier_Lounge6_EventScript_Fennekin
	case 6, BattleFrontier_Lounge6_EventScript_Litten
	case 7, BattleFrontier_Lounge6_EventScript_Scorbunny
	case 8, BattleFrontier_Lounge6_EventScript_CancelMonSelect
	goto BattleFrontier_Lounge6_EventScript_CancelMonSelect
	end

BattleFrontier_Lounge6_EventScript_CancelMonSelect::
	@hidecoinsbox 0, 0
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge6_EventScript_Charmander::
	setvar VAR_TEMP_1, SPECIES_CHARMANDER
	@setvar VAR_TEMP_2, YAMASK_COINS
	goto BattleFrontier_Lounge6_EventScript_ConfirmPrizeMon
	end

BattleFrontier_Lounge6_EventScript_Cyndaquil::
	setvar VAR_TEMP_1, SPECIES_CYNDAQUIL
	@setvar VAR_TEMP_2, CRYOGONAL_COINS
	goto BattleFrontier_Lounge6_EventScript_ConfirmPrizeMon
	end

BattleFrontier_Lounge6_EventScript_Torchic::
	setvar VAR_TEMP_1, SPECIES_TORCHIC
	@setvar VAR_TEMP_2, KLEFKI_COINS
	goto BattleFrontier_Lounge6_EventScript_ConfirmPrizeMon
	end

BattleFrontier_Lounge6_EventScript_Chimchar::
	setvar VAR_TEMP_1, SPECIES_CHIMCHAR
	@setvar VAR_TEMP_2, LARVITAR_COINS
	goto BattleFrontier_Lounge6_EventScript_ConfirmPrizeMon
	end

BattleFrontier_Lounge6_EventScript_Tepig::
	setvar VAR_TEMP_1, SPECIES_TEPIG
	@setvar VAR_TEMP_2, BELDUM_COINS
	goto BattleFrontier_Lounge6_EventScript_ConfirmPrizeMon
	end

BattleFrontier_Lounge6_EventScript_Fennekin::
	setvar VAR_TEMP_1, SPECIES_FENNEKIN
	@setvar VAR_TEMP_2, DEINO_COINS
	goto BattleFrontier_Lounge6_EventScript_ConfirmPrizeMon
	end

BattleFrontier_Lounge6_EventScript_Litten::
	setvar VAR_TEMP_1, SPECIES_LITTEN
	@setvar VAR_TEMP_2, DREEPY_COINS
	goto BattleFrontier_Lounge6_EventScript_ConfirmPrizeMon
	end

BattleFrontier_Lounge6_EventScript_Scorbunny::
	setvar VAR_TEMP_1, SPECIES_SCORBUNNY
	@setvar VAR_TEMP_2, PORYGON_COINS
	goto BattleFrontier_Lounge6_EventScript_ConfirmPrizeMon
	end

BattleFrontier_Lounge6_EventScript_ConfirmPrizeMon::
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	msgbox BattleFrontier_Lounge6_Text_YouWantPrize, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge6_EventScript_CancelMonSelect
	@checkcoins VAR_RESULT
	@goto_if_lt VAR_RESULT, VAR_TEMP_2, BattleFrontier_Lounge6_EventScript_NotEnoughCoinsForMon
	specialvar VAR_TEMP_2, GetFrontierBattlePoints
	goto_if_lt VAR_TEMP_2, STARTER_PRICE, BattleFrontier_Lounge6_EventScript_NotEnoughCoinsForMon
	switch VAR_TEMP_1
	case SPECIES_CHARMANDER,      BattleFrontier_Lounge6_EventScript_GiveCharmander
	case SPECIES_CYNDAQUIL,       BattleFrontier_Lounge6_EventScript_GiveCyndaquil
	case SPECIES_TORCHIC,         BattleFrontier_Lounge6_EventScript_GiveTorchic
	case SPECIES_CHIMCHAR,        BattleFrontier_Lounge6_EventScript_GiveChimchar
	case SPECIES_TEPIG,           BattleFrontier_Lounge6_EventScript_GiveTepig
	case SPECIES_FENNEKIN,        BattleFrontier_Lounge6_EventScript_GiveFennekin
	case SPECIES_LITTEN,          BattleFrontier_Lounge6_EventScript_GiveLitten
	case SPECIES_SCORBUNNY,       BattleFrontier_Lounge6_EventScript_GiveScorbunny
	end

BattleFrontier_Lounge6_Text_YouWantPrize::
	.string "So, you want the {STR_VAR_1}?$"

BattleFrontier_Lounge6_EventScript_GiveCharmander::
	givemon VAR_TEMP_1, STARTER_LEVEL
	goto BattleFrontier_Lounge6_EventScript_CheckReceivedMon
	end

BattleFrontier_Lounge6_EventScript_GiveCyndaquil::
	givemon VAR_TEMP_1, STARTER_LEVEL
	goto BattleFrontier_Lounge6_EventScript_CheckReceivedMon
	end

BattleFrontier_Lounge6_EventScript_GiveTorchic::
	givemon VAR_TEMP_1, STARTER_LEVEL
	goto BattleFrontier_Lounge6_EventScript_CheckReceivedMon
	end

BattleFrontier_Lounge6_EventScript_GiveChimchar::
	givemon VAR_TEMP_1, STARTER_LEVEL
	goto BattleFrontier_Lounge6_EventScript_CheckReceivedMon
	end

BattleFrontier_Lounge6_EventScript_GiveTepig::
	givemon VAR_TEMP_1, STARTER_LEVEL
	goto BattleFrontier_Lounge6_EventScript_CheckReceivedMon
	end

BattleFrontier_Lounge6_EventScript_GiveFennekin::
	givemon VAR_TEMP_1, STARTER_LEVEL
	goto BattleFrontier_Lounge6_EventScript_CheckReceivedMon
	end

BattleFrontier_Lounge6_EventScript_GiveLitten:
	givemon VAR_TEMP_1, STARTER_LEVEL
	goto BattleFrontier_Lounge6_EventScript_CheckReceivedMon
	end

BattleFrontier_Lounge6_EventScript_GiveScorbunny::
	givemon VAR_TEMP_1, STARTER_LEVEL
	goto BattleFrontier_Lounge6_EventScript_CheckReceivedMon
	end

BattleFrontier_Lounge6_EventScript_CheckReceivedMon::
	goto_if_eq VAR_RESULT, 0, BattleFrontier_Lounge6_EventScript_ReceivedMonParty
	goto_if_eq VAR_RESULT, 1, BattleFrontier_Lounge6_EventScript_ReceivedMonPC
	goto_if_eq VAR_RESULT, 2, BattleFrontier_Lounge6_EventScript_PartyFull
	end

BattleFrontier_Lounge6_EventScript_PartyFull::
	msgbox BattleFrontier_Lounge6Text_NoMoreRoomForPokemon
	@hidecoinsbox 0, 0
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge6Text_NoMoreRoomForPokemon::
	.string "There's no more room for POKéMON!\p"
	.string "The POKéMON BOXES are full and\n"
	.string "can't accept any more!$"

BattleFrontier_Lounge6_EventScript_NicknamePartyMon::
	getpartysize
	subvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	call Common_EventScript_NameReceivedPartyMon
	goto BattleFrontier_Lounge6_EventScript_CancelMonSelect
	end

BattleFrontier_Lounge6_EventScript_NotEnoughCoinsForMon::
	msgbox BattleFrontier_Lounge6_Text_NotEnoughCoins
	goto BattleFrontier_Lounge6_EventScript_CancelMonSelect
	end

BattleFrontier_Lounge6_Text_NotEnoughCoins:
	.string "You don't have enough Battle Points.$"

BattleFrontier_Lounge6_EventScript_ReceivedMonParty::
	@removecoins VAR_TEMP_2
	@updatecoinsbox 0, 5
	setvar VAR_0x8004, STARTER_PRICE
	special TakeFrontierBattlePoints
	@special UpdateBattlePointsWindow
	@playse SE_SHOP
	@waitse
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	playfanfare MUS_LEVEL_UP
	message Text_PlayerObtainedTheMon
	waitmessage
	waitfanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BattleFrontier_Lounge6_EventScript_NicknamePartyMon
	goto BattleFrontier_Lounge6_EventScript_CancelMonSelect
	end

@Text_PlayerObtainedTheMon::
@    .string "{PLAYER} obtained\n"
@    .string "the {STR_VAR_1}!$"

BattleFrontier_Lounge6_EventScript_ReceivedMonPC::
	@removecoins VAR_TEMP_2
	@updatecoinsbox 0, 5
	setvar VAR_0x8004, STARTER_PRICE
	special TakeFrontierBattlePoints
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	playfanfare MUS_LEVEL_UP
	message Text_PlayerObtainedTheMon
	waitmessage
	waitfanfare
	special UpdateBattlePointsWindow
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge6_EventScript_TransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto BattleFrontier_Lounge6_EventScript_TransferredToPC
	end

BattleFrontier_Lounge6_EventScript_TransferredToPC::
	call Common_EventScript_TransferredToPC
	goto BattleFrontier_Lounge6_EventScript_CancelMonSelect
	end



