.set STARTER_PRICE, 10
.set STARTER_LEVEL, 10

BattleFrontier_Lounge8_MapScripts::
	.byte 0

BattleFrontier_Lounge8_EventScript_Man::
	msgbox BattleFrontier_Lounge8_Text_WhatATrainerNeeds, MSGBOX_NPC
	end

BattleFrontier_Lounge8_EventScript_Woman::
	msgbox BattleFrontier_Lounge8_Text_KnowAboutFrontierBrains, MSGBOX_NPC
	end

BattleFrontier_Lounge8_EventScript_NinjaBoy::
	msgbox BattleFrontier_Lounge8_Text_ToldMeIHaveTalentForBattling, MSGBOX_NPC
	end

BattleFrontier_Lounge8_Text_WhatATrainerNeeds:
	.string "What a TRAINER needs…\p"
	.string "Knowledge…\n"
	.string "Strategy…\l"
	.string "Luck…\l"
	.string "Guts…\l"
	.string "Spirit…\l"
	.string "Bravery…\l"
	.string "And ability…\p"
	.string "Well, I'm all set in every way!\n"
	.string "I'll be unstoppable at every building!\p"
	.string "Huh? POKéMON?\n"
	.string "What's that?$"

BattleFrontier_Lounge8_Text_KnowAboutFrontierBrains:
	.string "Do you know about the FRONTIER\n"
	.string "BRAINS?\p"
	.string "That's what SCOTT calls the seven\n"
	.string "special TRAINERS that run the seven\l"
	.string "facilities in the BATTLE FRONTIER.$"

BattleFrontier_Lounge8_Text_ToldMeIHaveTalentForBattling:
	.string "At the BATTLE TOWER, an older girl\n"
	.string "told me that I have a lot of talent\l"
	.string "for battling!\p"
	.string "I like POKéMON CONTESTS more!\p"
	.string "But I'm no good at CONTESTS!\p"
	.string "I guess having talent and liking\n"
	.string "something aren't the same.$"












BattleFrontier_Lounge8_EventScript_ElectricStarterSeller::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge8_Text_ExchangeCoinsForPrizes, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BattleFrontier_Lounge8_EventScript_ChooseMonPrizeMessage
	release
	end

BattleFrontier_Lounge8_Text_ExchangeCoinsForPrizes:
	.string "Looking for new POKéMON to raise?\n"
	.string "I've got some really rare ones here.\p"
	.string "I'll let you adopt one in exchange\n"
	.string "for 10 Battle Points.\p"
	.string "Have we got a deal?$"

BattleFrontier_Lounge8_EventScript_ChooseMonPrizeMessage::
	message BattleFrontier_Lounge8_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	special ShowBattlePointsWindow
	goto BattleFrontier_Lounge8_EventScript_ChooseMonPrize

BattleFrontier_Lounge8_Text_WhichPrize:
	.string "Which POKéMON would you like?$"

BattleFrontier_Lounge8_EventScript_ReturnToChooseMonPrize::
	message BattleFrontier_Lounge8_Text_WhichPrize
	waitmessage
	goto BattleFrontier_Lounge8_EventScript_ChooseMonPrize

BattleFrontier_Lounge8_EventScript_ChooseMonPrize::
	scrollingmultichoice 19, 22, 0, 6, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge8_EventScript_Pikachu
	case 1, BattleFrontier_Lounge8_EventScript_Plusle
	case 2, BattleFrontier_Lounge8_EventScript_Minun
	case 3, BattleFrontier_Lounge8_EventScript_Pachirisu
	case 4, BattleFrontier_Lounge8_EventScript_Emolga
	case 5, BattleFrontier_Lounge8_EventScript_Dedenne
	case 6, BattleFrontier_Lounge8_EventScript_Togedemaru
	case 7, BattleFrontier_Lounge8_EventScript_Morpeko
	case 8, BattleFrontier_Lounge8_EventScript_CancelMonSelect
	goto BattleFrontier_Lounge8_EventScript_CancelMonSelect
	end

BattleFrontier_Lounge8_EventScript_CancelMonSelect::
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge8_EventScript_Pikachu::
	setvar VAR_TEMP_1, SPECIES_PIKACHU
	goto BattleFrontier_Lounge8_EventScript_ConfirmPrizeMon
	end

BattleFrontier_Lounge8_EventScript_Plusle::
	setvar VAR_TEMP_1, SPECIES_PLUSLE
	goto BattleFrontier_Lounge8_EventScript_ConfirmPrizeMon
	end

BattleFrontier_Lounge8_EventScript_Minun::
	setvar VAR_TEMP_1, SPECIES_MINUN
	goto BattleFrontier_Lounge8_EventScript_ConfirmPrizeMon
	end

BattleFrontier_Lounge8_EventScript_Pachirisu::
	setvar VAR_TEMP_1, SPECIES_PACHIRISU
	goto BattleFrontier_Lounge8_EventScript_ConfirmPrizeMon
	end

BattleFrontier_Lounge8_EventScript_Emolga::
	setvar VAR_TEMP_1, SPECIES_EMOLGA
	goto BattleFrontier_Lounge8_EventScript_ConfirmPrizeMon
	end

BattleFrontier_Lounge8_EventScript_Dedenne::
	setvar VAR_TEMP_1, SPECIES_DEDENNE
	goto BattleFrontier_Lounge8_EventScript_ConfirmPrizeMon
	end

BattleFrontier_Lounge8_EventScript_Togedemaru::
	setvar VAR_TEMP_1, SPECIES_TOGEDEMARU
	goto BattleFrontier_Lounge8_EventScript_ConfirmPrizeMon
	end

BattleFrontier_Lounge8_EventScript_Morpeko::
	setvar VAR_TEMP_1, SPECIES_MORPEKO
	goto BattleFrontier_Lounge8_EventScript_ConfirmPrizeMon
	end

BattleFrontier_Lounge8_EventScript_ConfirmPrizeMon::
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	msgbox BattleFrontier_Lounge8_Text_YouWantPrize, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge8_EventScript_CancelMonSelect
	specialvar VAR_TEMP_2, GetFrontierBattlePoints
	goto_if_lt VAR_TEMP_2, STARTER_PRICE, BattleFrontier_Lounge8_EventScript_NotEnoughCoinsForMon
	switch VAR_TEMP_1
	case SPECIES_PIKACHU,       BattleFrontier_Lounge8_EventScript_GivePikachu
	case SPECIES_PLUSLE,        BattleFrontier_Lounge8_EventScript_GivePlusle
	case SPECIES_MINUN,         BattleFrontier_Lounge8_EventScript_GiveMinun
	case SPECIES_PACHIRISU,     BattleFrontier_Lounge8_EventScript_GivePachirisu
	case SPECIES_EMOLGA,        BattleFrontier_Lounge8_EventScript_GiveEmolga
	case SPECIES_DEDENNE,       BattleFrontier_Lounge8_EventScript_GiveDedenne
	case SPECIES_TOGEDEMARU,    BattleFrontier_Lounge8_EventScript_GiveTogedemaru
	case SPECIES_MORPEKO,       BattleFrontier_Lounge8_EventScript_GiveMorpeko
	end

BattleFrontier_Lounge8_Text_YouWantPrize::
	.string "So, you want the {STR_VAR_1}?$"

BattleFrontier_Lounge8_EventScript_GivePikachu::
	givemon VAR_TEMP_1, STARTER_LEVEL
	goto BattleFrontier_Lounge8_EventScript_CheckReceivedMon
	end

BattleFrontier_Lounge8_EventScript_GivePlusle::
	givemon VAR_TEMP_1, STARTER_LEVEL
	goto BattleFrontier_Lounge8_EventScript_CheckReceivedMon
	end

BattleFrontier_Lounge8_EventScript_GiveMinun::
	givemon VAR_TEMP_1, STARTER_LEVEL
	goto BattleFrontier_Lounge8_EventScript_CheckReceivedMon
	end

BattleFrontier_Lounge8_EventScript_GivePachirisu::
	givemon VAR_TEMP_1, STARTER_LEVEL
	goto BattleFrontier_Lounge8_EventScript_CheckReceivedMon
	end

BattleFrontier_Lounge8_EventScript_GiveEmolga::
	givemon VAR_TEMP_1, STARTER_LEVEL
	goto BattleFrontier_Lounge8_EventScript_CheckReceivedMon
	end

BattleFrontier_Lounge8_EventScript_GiveDedenne::
	givemon VAR_TEMP_1, STARTER_LEVEL
	goto BattleFrontier_Lounge8_EventScript_CheckReceivedMon
	end

BattleFrontier_Lounge8_EventScript_GiveTogedemaru:
	givemon VAR_TEMP_1, STARTER_LEVEL
	goto BattleFrontier_Lounge8_EventScript_CheckReceivedMon
	end

BattleFrontier_Lounge8_EventScript_GiveMorpeko::
	givemon VAR_TEMP_1, STARTER_LEVEL
	goto BattleFrontier_Lounge8_EventScript_CheckReceivedMon
	end

BattleFrontier_Lounge8_EventScript_CheckReceivedMon::
	goto_if_eq VAR_RESULT, 0, BattleFrontier_Lounge8_EventScript_ReceivedMonParty
	goto_if_eq VAR_RESULT, 1, BattleFrontier_Lounge8_EventScript_ReceivedMonPC
	goto_if_eq VAR_RESULT, 2, BattleFrontier_Lounge8_EventScript_PartyFull
	end

BattleFrontier_Lounge8_EventScript_PartyFull::
	msgbox BattleFrontier_Lounge8Text_NoMoreRoomForPokemon
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge8Text_NoMoreRoomForPokemon::
	.string "There's no more room for POKéMON!\p"
	.string "The POKéMON BOXES are full and\n"
	.string "can't accept any more!$"

BattleFrontier_Lounge8_EventScript_NicknamePartyMon::
	getpartysize
	subvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	call Common_EventScript_NameReceivedPartyMon
	goto BattleFrontier_Lounge8_EventScript_CancelMonSelect
	end

BattleFrontier_Lounge8_EventScript_NotEnoughCoinsForMon::
	msgbox BattleFrontier_Lounge8_Text_NotEnoughCoins
	goto BattleFrontier_Lounge8_EventScript_CancelMonSelect
	end

BattleFrontier_Lounge8_Text_NotEnoughCoins:
	.string "You don't have enough Battle Points.$"

BattleFrontier_Lounge8_EventScript_ReceivedMonParty::
	setvar VAR_0x8004, STARTER_PRICE
	special TakeFrontierBattlePoints
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	playfanfare MUS_LEVEL_UP
	message Text_PlayerObtainedTheMon
	waitmessage
	waitfanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BattleFrontier_Lounge8_EventScript_NicknamePartyMon
	goto BattleFrontier_Lounge8_EventScript_CancelMonSelect
	end

BattleFrontier_Lounge8_EventScript_ReceivedMonPC::
	setvar VAR_0x8004, STARTER_PRICE
	special TakeFrontierBattlePoints
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	playfanfare MUS_LEVEL_UP
	message Text_PlayerObtainedTheMon
	waitmessage
	waitfanfare
	special UpdateBattlePointsWindow
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge8_EventScript_TransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto BattleFrontier_Lounge8_EventScript_TransferredToPC
	end

BattleFrontier_Lounge8_EventScript_TransferredToPC::
	call Common_EventScript_TransferredToPC
	goto BattleFrontier_Lounge8_EventScript_CancelMonSelect
	end




