.set STARTER_PRICE, 10
.set STARTER_LEVEL, 10

BattleFrontier_Lounge1_MapScripts::
	.byte 0

BattleFrontier_Lounge1_EventScript_Woman::
	msgbox BattleFrontier_Lounge1_Text_Memorize, MSGBOX_NPC
	end

BattleFrontier_Lounge1_Text_Memorize:
	.string "This business about POKéMON battes\n"
	.string "is really something.\p"
	.string "I don't know how you kids\n"
	.string "memorize all this stuff.$"

BattleFrontier_Lounge1_EventScript_GameboyKid::
	lock
	faceplayer
	goto_if_set FLAG_FRONTIER_NPC_TRADE_2_COMPLETED, BattleFrontier_Lounge1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_GASTLY
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox BattleFrontier_Lounge1_Text_WillingToTradeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge1_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, BattleFrontier_Lounge1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	giveitem ITEM_COVENANT_ORB
	waitfanfare
	msgbox BattleFrontier_Lounge1_Text_UrAwesome, MSGBOX_DEFAULT
	setflag FLAG_FRONTIER_NPC_TRADE_2_COMPLETED
	release
	end

BattleFrontier_Lounge1_EventScript_DeclineTrade::
	release
	end

BattleFrontier_Lounge1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_Lounge1_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge1_EventScript_TradeCompleted::
	msgbox BattleFrontier_Lounge1_Text_TradeWithOthers, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge1_Text_WillingToTradeIt:
	.string "Hi! Do you have a {STR_VAR_1}!\p"
	.string "Would you trade it for my {STR_VAR_2}?$"

BattleFrontier_Lounge1_Text_UrAwesome:
	.string "You're awesome! Thanks!$"

BattleFrontier_Lounge1_Text_WontAcceptAnyLessThanRealMon:
	.string "No, no, no! I won't accept any\n"
	.string "less than a real {STR_VAR_1}!$"

BattleFrontier_Lounge1_Text_TradeWithOthers:
	.string "I trade with my friends in other\n"
	.string "cities all the time.$"











@ NPC that rates pokemon based on their IVs
BattleFrontier_Lounge1_EventScript_Breeder::
	lock
	faceplayer
	call_if_unset FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_BreederIntro
	call_if_set FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder
	setflag FLAG_MET_BATTLE_FRONTIER_BREEDER
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder::
	chooseboxmon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_ShowMonToBreeder
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_CancelMonSelect2
	end

BattleFrontier_Lounge1_EventScript_BreederIntro::
	msgbox BattleFrontier_Lounge1_Text_PokemonBreederIntro, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder::
	msgbox BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon, MSGBOX_DEFAULT
	return

@ BufferVarsForIVRater buffers the following values
@ VAR_0x8005: Sum of the mons IVs
@ VAR_0x8006: Stat id of highest IV stat
@ VAR_0x8007: IV of the highest IV stat
BattleFrontier_Lounge1_EventScript_ShowMonToBreeder::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge1_EventScript_ShowEggToBreeder
	special BufferVarsForIVRater
	goto_if_le VAR_0x8005, 90, BattleFrontier_Lounge1_EventScript_AverageTotalIVs       @ Average of 15
	goto_if_le VAR_0x8005, 120, BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs @ Average of 20
	goto_if_le VAR_0x8005, 150, BattleFrontier_Lounge1_EventScript_HighTotalIVs         @ Average of 25
	goto_if_ge VAR_0x8005, 151, BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs     @ Average of > 25
	end

BattleFrontier_Lounge1_EventScript_ShowEggToBreeder::
	msgbox BattleFrontier_Lounge1_Text_EvenICantTell, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

@ Comment on the highest IV stat
BattleFrontier_Lounge1_EventScript_HighestIVStat::
	goto_if_eq VAR_0x8006, STAT_HP, BattleFrontier_Lounge1_EventScript_HighestIVHP
	goto_if_eq VAR_0x8006, STAT_ATK, BattleFrontier_Lounge1_EventScript_HighestIVAtk
	goto_if_eq VAR_0x8006, STAT_DEF, BattleFrontier_Lounge1_EventScript_HighestIVDef
	goto_if_eq VAR_0x8006, STAT_SPEED, BattleFrontier_Lounge1_EventScript_HighestIVSpeed
	goto_if_eq VAR_0x8006, STAT_SPATK, BattleFrontier_Lounge1_EventScript_HighestIVSpAtk
	goto_if_eq VAR_0x8006, STAT_SPDEF, BattleFrontier_Lounge1_EventScript_HighestIVSpDef
	end

@ Comment on the highest IV value
BattleFrontier_Lounge1_EventScript_HighestIVValue::
	goto_if_le VAR_0x8007, 15, BattleFrontier_Lounge1_EventScript_HighestIVLow
	goto_if_le VAR_0x8007, 25, BattleFrontier_Lounge1_EventScript_HighestIVMid
	goto_if_le VAR_0x8007, 30, BattleFrontier_Lounge1_EventScript_HighestIVHigh
	goto_if_ge VAR_0x8007, 31, BattleFrontier_Lounge1_EventScript_HighestIVMax
	end

BattleFrontier_Lounge1_EventScript_EndBreederComments::
	release
	end

BattleFrontier_Lounge1_EventScript_AverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_AverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_BetterThanAverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_ImpressiveAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_OutstandingAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighestIVHP::
	msgbox BattleFrontier_Lounge1_Text_BestAspectHP, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpeed::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpeed, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVLow::
	msgbox BattleFrontier_Lounge1_Text_StatRelativelyGood, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMid::
	msgbox BattleFrontier_Lounge1_Text_StatImpressive, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVHigh::
	msgbox BattleFrontier_Lounge1_Text_StatOutstanding, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMax::
	msgbox BattleFrontier_Lounge1_Text_StatFlawless, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_CancelMonSelect2::
	msgbox BattleFrontier_Lounge1_Text_NoTimeForMyAdvice, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge1_EventScript_Boy1::
	msgbox BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding, MSGBOX_NPC
	end

BattleFrontier_Lounge1_EventScript_Boy2::
	msgbox BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt, MSGBOX_NPC
	end

BattleFrontier_Lounge1_Text_PokemonBreederIntro:
	.string "For 70 years I have raised POKéMON!\n"
	.string "I am the man they revere as\l"
	.string "the legendary top POKéMON BREEDER!\p"
	.string "If you ever become as seasoned as me,\n"
	.string "you'll see the abilities of POKéMON\l"
	.string "at a glance.\p"
	.string "You're a TRAINER. Doesn't it interest\n"
	.string "you to know your own POKéMON's\l"
	.string "abilities?\p"
	.string "Here!\n"
	.string "Let's have a look at your POKéMON!$"

BattleFrontier_Lounge1_Text_AverageAbility:
	.string "…Hmm…\p"
	.string "This one, overall, I would describe\n"
	.string "as being of average ability.$"

BattleFrontier_Lounge1_Text_BetterThanAverageAbility:
	.string "…Hmm…\p"
	.string "This one, overall, I would describe as\n"
	.string "having better-than-average ability.$"

BattleFrontier_Lounge1_Text_ImpressiveAbility:
	.string "…Hmm…\p"
	.string "This one, overall, I would say is\n"
	.string "quite impressive in ability!$"

BattleFrontier_Lounge1_Text_OutstandingAbility:
	.string "…Hmm…\p"
	.string "This one, overall, I would say is\n"
	.string "wonderfully outstanding in ability!$"

BattleFrontier_Lounge1_Text_BestAspectHP:
	.string "Incidentally, the best aspect of it,\n"
	.string "I would say, is its HP…$"

BattleFrontier_Lounge1_Text_BestAspectAtk:
	.string "Incidentally, the best aspect of it,\n"
	.string "I would say, is its ATTACK…$"

BattleFrontier_Lounge1_Text_BestAspectDef:
	.string "Incidentally, the best aspect of it,\n"
	.string "I would say, is its DEFENSE…$"

BattleFrontier_Lounge1_Text_BestAspectSpAtk:
	.string "Incidentally, the best aspect of it,\n"
	.string "I would say, is its SPECIAL ATTACK…$"

BattleFrontier_Lounge1_Text_BestAspectSpDef:
	.string "Incidentally, the best aspect of it,\n"
	.string "I would say, is its SPECIAL DEFENSE…$"

BattleFrontier_Lounge1_Text_BestAspectSpeed:
	.string "Incidentally, the best aspect of it,\n"
	.string "I would say, is its SPEED…$"

BattleFrontier_Lounge1_Text_StatRelativelyGood:
	.string "That stat is relatively good.\n"
	.string "…Hm… That's how I call it.$"

BattleFrontier_Lounge1_Text_StatImpressive:
	.string "That stat is quite impressive.\n"
	.string "…Hm… That's how I call it.$"

BattleFrontier_Lounge1_Text_StatOutstanding:
	.string "That stat is outstanding!\n"
	.string "…Hm… That's how I call it.$"

BattleFrontier_Lounge1_Text_StatFlawless:
	.string "It's flawless! A thing of perfection!\n"
	.string "…Hm… That's how I call it.$"

BattleFrontier_Lounge1_Text_NoTimeForMyAdvice:
	.string "What?\n"
	.string "You have no time for my advice?\p"
	.string "You should always be eager to learn\n"
	.string "from the experiences of your elders!$"

@ Unused
BattleFrontier_Lounge1_Text_HaveBusinessNeedsTending:
	.string "Yes, what is it now?\p"
	.string "I have business that needs tending!\n"
	.string "Save it for next time!$"

BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon:
	.string "Ah, youngster! Do your POKéMON's\n"
	.string "abilities intrigue you?\p"
	.string "Here, here!\n"
	.string "Let's have a look at your POKéMON!$"

BattleFrontier_Lounge1_Text_EvenICantTell:
	.string "An expert I am, but even I can't tell\n"
	.string "anything about an unhatched POKéMON!\p"
	.string "Show me a POKéMON!\n"
	.string "A POKéMON is what I need to see!$"

BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding:
	.string "He said my POKéMON is outstanding!\n"
	.string "I'm glad I raised it carefully!$"

BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt:
	.string "He said my POKéMON is outstanding!\n"
	.string "But I didn't do anything special\l"
	.string "raising it…$"











BattleFrontier_Lounge1_EventScript_GrassStarterSeller::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge1_Text_ExchangeCoinsForPrizes, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BattleFrontier_Lounge1_EventScript_ChooseMonPrizeMessage
	release
	end

BattleFrontier_Lounge1_Text_ExchangeCoinsForPrizes:
	.string "Looking for new POKéMON to raise?\n"
	.string "I've got some really rare ones here.\p"
	.string "I'll let you adopt one in exchange\n"
	.string "for 10 Battle Points.\p"
	.string "Have we got a deal?$"

BattleFrontier_Lounge1_EventScript_ChooseMonPrizeMessage::
	message BattleFrontier_Lounge1_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	special ShowBattlePointsWindow
	goto BattleFrontier_Lounge1_EventScript_ChooseMonPrize

BattleFrontier_Lounge1_Text_WhichPrize:
	.string "Which POKéMON would you like?$"

BattleFrontier_Lounge1_EventScript_ReturnToChooseMonPrize::
	message BattleFrontier_Lounge1_Text_WhichPrize
	waitmessage
	goto BattleFrontier_Lounge1_EventScript_ChooseMonPrize

BattleFrontier_Lounge1_EventScript_ChooseMonPrize::
	scrollingmultichoice 16, 22, 0, 6, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge1_EventScript_Bulbasaur
	case 1, BattleFrontier_Lounge1_EventScript_Chikorita
	case 2, BattleFrontier_Lounge1_EventScript_Treecko
	case 3, BattleFrontier_Lounge1_EventScript_Turtwig
	case 4, BattleFrontier_Lounge1_EventScript_Snivy
	case 5, BattleFrontier_Lounge1_EventScript_Chespin
	case 6, BattleFrontier_Lounge1_EventScript_Rowlet
	case 7, BattleFrontier_Lounge1_EventScript_Grookey
	case 8, BattleFrontier_Lounge1_EventScript_CancelMonSelect
	goto BattleFrontier_Lounge1_EventScript_CancelMonSelect
	end

BattleFrontier_Lounge1_EventScript_CancelMonSelect::
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge1_EventScript_Bulbasaur::
	setvar VAR_TEMP_1, SPECIES_BULBASAUR
	goto BattleFrontier_Lounge1_EventScript_ConfirmPrizeMon
	end

BattleFrontier_Lounge1_EventScript_Chikorita::
	setvar VAR_TEMP_1, SPECIES_CHIKORITA
	goto BattleFrontier_Lounge1_EventScript_ConfirmPrizeMon
	end

BattleFrontier_Lounge1_EventScript_Treecko::
	setvar VAR_TEMP_1, SPECIES_TREECKO
	goto BattleFrontier_Lounge1_EventScript_ConfirmPrizeMon
	end

BattleFrontier_Lounge1_EventScript_Turtwig::
	setvar VAR_TEMP_1, SPECIES_TURTWIG
	goto BattleFrontier_Lounge1_EventScript_ConfirmPrizeMon
	end

BattleFrontier_Lounge1_EventScript_Snivy::
	setvar VAR_TEMP_1, SPECIES_SNIVY
	goto BattleFrontier_Lounge1_EventScript_ConfirmPrizeMon
	end

BattleFrontier_Lounge1_EventScript_Chespin::
	setvar VAR_TEMP_1, SPECIES_CHESPIN
	goto BattleFrontier_Lounge1_EventScript_ConfirmPrizeMon
	end

BattleFrontier_Lounge1_EventScript_Rowlet::
	setvar VAR_TEMP_1, SPECIES_ROWLET
	goto BattleFrontier_Lounge1_EventScript_ConfirmPrizeMon
	end

BattleFrontier_Lounge1_EventScript_Grookey::
	setvar VAR_TEMP_1, SPECIES_GROOKEY
	goto BattleFrontier_Lounge1_EventScript_ConfirmPrizeMon
	end

BattleFrontier_Lounge1_EventScript_ConfirmPrizeMon::
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	msgbox BattleFrontier_Lounge1_Text_YouWantPrize, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge1_EventScript_CancelMonSelect
	specialvar VAR_TEMP_2, GetFrontierBattlePoints
	goto_if_lt VAR_TEMP_2, STARTER_PRICE, BattleFrontier_Lounge1_EventScript_NotEnoughCoinsForMon
	switch VAR_TEMP_1
	case SPECIES_BULBASAUR,     BattleFrontier_Lounge1_EventScript_GiveBulbasaur
	case SPECIES_CHIKORITA,     BattleFrontier_Lounge1_EventScript_GiveChikorita
	case SPECIES_TREECKO,       BattleFrontier_Lounge1_EventScript_GiveTreecko
	case SPECIES_TURTWIG,       BattleFrontier_Lounge1_EventScript_GiveTurtwig
	case SPECIES_SNIVY,         BattleFrontier_Lounge1_EventScript_GiveSnivy
	case SPECIES_CHESPIN,       BattleFrontier_Lounge1_EventScript_GiveChespin
	case SPECIES_ROWLET,        BattleFrontier_Lounge1_EventScript_GiveRowlet
	case SPECIES_GROOKEY,       BattleFrontier_Lounge1_EventScript_GiveGrookey
	end

BattleFrontier_Lounge1_Text_YouWantPrize::
	.string "So, you want the {STR_VAR_1}?$"

BattleFrontier_Lounge1_EventScript_GiveBulbasaur::
	givemon VAR_TEMP_1, STARTER_LEVEL
	goto BattleFrontier_Lounge1_EventScript_CheckReceivedMon
	end

BattleFrontier_Lounge1_EventScript_GiveChikorita::
	givemon VAR_TEMP_1, STARTER_LEVEL
	goto BattleFrontier_Lounge1_EventScript_CheckReceivedMon
	end

BattleFrontier_Lounge1_EventScript_GiveTreecko::
	givemon VAR_TEMP_1, STARTER_LEVEL
	goto BattleFrontier_Lounge1_EventScript_CheckReceivedMon
	end

BattleFrontier_Lounge1_EventScript_GiveTurtwig::
	givemon VAR_TEMP_1, STARTER_LEVEL
	goto BattleFrontier_Lounge1_EventScript_CheckReceivedMon
	end

BattleFrontier_Lounge1_EventScript_GiveSnivy::
	givemon VAR_TEMP_1, STARTER_LEVEL
	goto BattleFrontier_Lounge1_EventScript_CheckReceivedMon
	end

BattleFrontier_Lounge1_EventScript_GiveChespin::
	givemon VAR_TEMP_1, STARTER_LEVEL
	goto BattleFrontier_Lounge1_EventScript_CheckReceivedMon
	end

BattleFrontier_Lounge1_EventScript_GiveRowlet:
	givemon VAR_TEMP_1, STARTER_LEVEL
	goto BattleFrontier_Lounge1_EventScript_CheckReceivedMon
	end

BattleFrontier_Lounge1_EventScript_GiveGrookey::
	givemon VAR_TEMP_1, STARTER_LEVEL
	goto BattleFrontier_Lounge1_EventScript_CheckReceivedMon
	end

BattleFrontier_Lounge1_EventScript_CheckReceivedMon::
	goto_if_eq VAR_RESULT, 0, BattleFrontier_Lounge1_EventScript_ReceivedMonParty
	goto_if_eq VAR_RESULT, 1, BattleFrontier_Lounge1_EventScript_ReceivedMonPC
	goto_if_eq VAR_RESULT, 2, BattleFrontier_Lounge1_EventScript_PartyFull
	end

BattleFrontier_Lounge1_EventScript_PartyFull::
	msgbox BattleFrontier_Lounge1Text_NoMoreRoomForPokemon
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge1Text_NoMoreRoomForPokemon::
	.string "There's no more room for POKéMON!\p"
	.string "The POKéMON BOXES are full and\n"
	.string "can't accept any more!$"

BattleFrontier_Lounge1_EventScript_NicknamePartyMon::
	getpartysize
	subvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	call Common_EventScript_NameReceivedPartyMon
	goto BattleFrontier_Lounge1_EventScript_CancelMonSelect
	end

BattleFrontier_Lounge1_EventScript_NotEnoughCoinsForMon::
	msgbox BattleFrontier_Lounge1_Text_NotEnoughCoins
	goto BattleFrontier_Lounge1_EventScript_CancelMonSelect
	end

BattleFrontier_Lounge1_Text_NotEnoughCoins:
	.string "You don't have enough Battle Points.$"

BattleFrontier_Lounge1_EventScript_ReceivedMonParty::
	setvar VAR_0x8004, STARTER_PRICE
	special TakeFrontierBattlePoints
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	playfanfare MUS_LEVEL_UP
	message Text_PlayerObtainedTheMon
	waitmessage
	waitfanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BattleFrontier_Lounge1_EventScript_NicknamePartyMon
	goto BattleFrontier_Lounge1_EventScript_CancelMonSelect
	end

BattleFrontier_Lounge1_EventScript_ReceivedMonPC::
	setvar VAR_0x8004, STARTER_PRICE
	special TakeFrontierBattlePoints
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	playfanfare MUS_LEVEL_UP
	message Text_PlayerObtainedTheMon
	waitmessage
	waitfanfare
	special UpdateBattlePointsWindow
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge1_EventScript_TransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto BattleFrontier_Lounge1_EventScript_TransferredToPC
	end

BattleFrontier_Lounge1_EventScript_TransferredToPC::
	call Common_EventScript_TransferredToPC
	goto BattleFrontier_Lounge1_EventScript_CancelMonSelect
	end







