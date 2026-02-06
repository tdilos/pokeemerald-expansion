.set STARTER_PRICE, 10
.set STARTER_LEVEL, 10

BattleFrontier_Lounge4_MapScripts::
	.byte 0

BattleFrontier_Lounge4_EventScript_Woman::
	msgbox BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Cook::
	msgbox BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Man::
	msgbox BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles, MSGBOX_NPC
	end

BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring:
	.string "I wonder if they'll be airing interviews\n"
	.string "with tough TRAINERS today?$"

BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere:
	.string "If I opened a restaurant here,\n"
	.string "it'd make money for sure.$"

BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles:
	.string "Whew…\p"
	.string "I need to take a breather after\n"
	.string "some intense battles…\p"
	.string "But even now, I never take a break\n"
	.string "from plotting strategy and combos.$"






BattleFrontier_Lounge4_EventScript_WaterStarterSeller::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge4_Text_ExchangeCoinsForPrizes, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BattleFrontier_Lounge4_EventScript_ChooseMonPrizeMessage
	release
	end

BattleFrontier_Lounge4_Text_ExchangeCoinsForPrizes:
	.string "Looking for new POKéMON to raise?\n"
	.string "I've got some really rare ones here.\p"
	.string "I'll let you adopt one in exchange\n"
	.string "for 10 Battle Points.\p"
	.string "Have we got a deal?$"

BattleFrontier_Lounge4_EventScript_ChooseMonPrizeMessage::
	message BattleFrontier_Lounge4_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	special ShowBattlePointsWindow
	goto BattleFrontier_Lounge4_EventScript_ChooseMonPrize

BattleFrontier_Lounge4_Text_WhichPrize:
	.string "Which POKéMON would you like?$"

BattleFrontier_Lounge4_EventScript_ReturnToChooseMonPrize::
	message BattleFrontier_Lounge4_Text_WhichPrize
	waitmessage
	goto BattleFrontier_Lounge4_EventScript_ChooseMonPrize

BattleFrontier_Lounge4_EventScript_ChooseMonPrize::
	scrollingmultichoice 18, 22, 0, 6, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge4_EventScript_Squirtle
	case 1, BattleFrontier_Lounge4_EventScript_Totodile
	case 2, BattleFrontier_Lounge4_EventScript_Mudkip
	case 3, BattleFrontier_Lounge4_EventScript_Piplup
	case 4, BattleFrontier_Lounge4_EventScript_Oshawott
	case 5, BattleFrontier_Lounge4_EventScript_Froakie
	case 6, BattleFrontier_Lounge4_EventScript_Popplio
	case 7, BattleFrontier_Lounge4_EventScript_Sobble
	case 8, BattleFrontier_Lounge4_EventScript_CancelMonSelect
	goto BattleFrontier_Lounge4_EventScript_CancelMonSelect
	end

BattleFrontier_Lounge4_EventScript_CancelMonSelect::
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge4_EventScript_Squirtle::
	setvar VAR_TEMP_1, SPECIES_SQUIRTLE
	goto BattleFrontier_Lounge4_EventScript_ConfirmPrizeMon
	end

BattleFrontier_Lounge4_EventScript_Totodile::
	setvar VAR_TEMP_1, SPECIES_TOTODILE
	goto BattleFrontier_Lounge4_EventScript_ConfirmPrizeMon
	end

BattleFrontier_Lounge4_EventScript_Mudkip::
	setvar VAR_TEMP_1, SPECIES_MUDKIP
	goto BattleFrontier_Lounge4_EventScript_ConfirmPrizeMon
	end

BattleFrontier_Lounge4_EventScript_Piplup::
	setvar VAR_TEMP_1, SPECIES_PIPLUP
	goto BattleFrontier_Lounge4_EventScript_ConfirmPrizeMon
	end

BattleFrontier_Lounge4_EventScript_Oshawott::
	setvar VAR_TEMP_1, SPECIES_OSHAWOTT
	goto BattleFrontier_Lounge4_EventScript_ConfirmPrizeMon
	end

BattleFrontier_Lounge4_EventScript_Froakie::
	setvar VAR_TEMP_1, SPECIES_FROAKIE
	goto BattleFrontier_Lounge4_EventScript_ConfirmPrizeMon
	end

BattleFrontier_Lounge4_EventScript_Popplio::
	setvar VAR_TEMP_1, SPECIES_POPPLIO
	goto BattleFrontier_Lounge4_EventScript_ConfirmPrizeMon
	end

BattleFrontier_Lounge4_EventScript_Sobble::
	setvar VAR_TEMP_1, SPECIES_SOBBLE
	goto BattleFrontier_Lounge4_EventScript_ConfirmPrizeMon
	end

BattleFrontier_Lounge4_EventScript_ConfirmPrizeMon::
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	msgbox BattleFrontier_Lounge4_Text_YouWantPrize, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge4_EventScript_CancelMonSelect
	specialvar VAR_TEMP_2, GetFrontierBattlePoints
	goto_if_lt VAR_TEMP_2, STARTER_PRICE, BattleFrontier_Lounge4_EventScript_NotEnoughCoinsForMon
	switch VAR_TEMP_1
	case SPECIES_SQUIRTLE,     BattleFrontier_Lounge4_EventScript_GiveSquirtle
	case SPECIES_TOTODILE,     BattleFrontier_Lounge4_EventScript_GiveTotodile
	case SPECIES_MUDKIP,       BattleFrontier_Lounge4_EventScript_GiveMudkip
	case SPECIES_PIPLUP,       BattleFrontier_Lounge4_EventScript_GivePiplup
	case SPECIES_OSHAWOTT,     BattleFrontier_Lounge4_EventScript_GiveOshawott
	case SPECIES_FROAKIE,      BattleFrontier_Lounge4_EventScript_GiveFroakie
	case SPECIES_POPPLIO,      BattleFrontier_Lounge4_EventScript_GivePopplio
	case SPECIES_SOBBLE,       BattleFrontier_Lounge4_EventScript_GiveSobble
	end

BattleFrontier_Lounge4_Text_YouWantPrize::
	.string "So, you want the {STR_VAR_1}?$"

BattleFrontier_Lounge4_EventScript_GiveSquirtle::
	givemon VAR_TEMP_1, STARTER_LEVEL
	goto BattleFrontier_Lounge4_EventScript_CheckReceivedMon
	end

BattleFrontier_Lounge4_EventScript_GiveTotodile::
	givemon VAR_TEMP_1, STARTER_LEVEL
	goto BattleFrontier_Lounge4_EventScript_CheckReceivedMon
	end

BattleFrontier_Lounge4_EventScript_GiveMudkip::
	givemon VAR_TEMP_1, STARTER_LEVEL
	goto BattleFrontier_Lounge4_EventScript_CheckReceivedMon
	end

BattleFrontier_Lounge4_EventScript_GivePiplup::
	givemon VAR_TEMP_1, STARTER_LEVEL
	goto BattleFrontier_Lounge4_EventScript_CheckReceivedMon
	end

BattleFrontier_Lounge4_EventScript_GiveOshawott::
	givemon VAR_TEMP_1, STARTER_LEVEL
	goto BattleFrontier_Lounge4_EventScript_CheckReceivedMon
	end

BattleFrontier_Lounge4_EventScript_GiveFroakie::
	givemon VAR_TEMP_1, STARTER_LEVEL
	goto BattleFrontier_Lounge4_EventScript_CheckReceivedMon
	end

BattleFrontier_Lounge4_EventScript_GivePopplio:
	givemon VAR_TEMP_1, STARTER_LEVEL
	goto BattleFrontier_Lounge4_EventScript_CheckReceivedMon
	end

BattleFrontier_Lounge4_EventScript_GiveSobble::
	givemon VAR_TEMP_1, STARTER_LEVEL
	goto BattleFrontier_Lounge4_EventScript_CheckReceivedMon
	end

BattleFrontier_Lounge4_EventScript_CheckReceivedMon::
	goto_if_eq VAR_RESULT, 0, BattleFrontier_Lounge4_EventScript_ReceivedMonParty
	goto_if_eq VAR_RESULT, 1, BattleFrontier_Lounge4_EventScript_ReceivedMonPC
	goto_if_eq VAR_RESULT, 2, BattleFrontier_Lounge4_EventScript_PartyFull
	end

BattleFrontier_Lounge4_EventScript_PartyFull::
	msgbox BattleFrontier_Lounge4Text_NoMoreRoomForPokemon
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge4Text_NoMoreRoomForPokemon::
	.string "There's no more room for POKéMON!\p"
	.string "The POKéMON BOXES are full and\n"
	.string "can't accept any more!$"

BattleFrontier_Lounge4_EventScript_NicknamePartyMon::
	getpartysize
	subvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	call Common_EventScript_NameReceivedPartyMon
	goto BattleFrontier_Lounge4_EventScript_CancelMonSelect
	end

BattleFrontier_Lounge4_EventScript_NotEnoughCoinsForMon::
	msgbox BattleFrontier_Lounge4_Text_NotEnoughCoins
	goto BattleFrontier_Lounge4_EventScript_CancelMonSelect
	end

BattleFrontier_Lounge4_Text_NotEnoughCoins:
	.string "You don't have enough Battle Points.$"

BattleFrontier_Lounge4_EventScript_ReceivedMonParty::
	setvar VAR_0x8004, STARTER_PRICE
	special TakeFrontierBattlePoints
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	playfanfare MUS_LEVEL_UP
	message Text_PlayerObtainedTheMon
	waitmessage
	waitfanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BattleFrontier_Lounge4_EventScript_NicknamePartyMon
	goto BattleFrontier_Lounge4_EventScript_CancelMonSelect
	end

BattleFrontier_Lounge4_EventScript_ReceivedMonPC::
	setvar VAR_0x8004, STARTER_PRICE
	special TakeFrontierBattlePoints
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	playfanfare MUS_LEVEL_UP
	message Text_PlayerObtainedTheMon
	waitmessage
	waitfanfare
	special UpdateBattlePointsWindow
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge4_EventScript_TransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto BattleFrontier_Lounge4_EventScript_TransferredToPC
	end

BattleFrontier_Lounge4_EventScript_TransferredToPC::
	call Common_EventScript_TransferredToPC
	goto BattleFrontier_Lounge4_EventScript_CancelMonSelect
	end


