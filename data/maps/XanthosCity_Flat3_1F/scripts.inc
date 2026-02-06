XanthosCity_Flat3_1F_MapScripts::
	.byte 0

XanthosCity_Flat3_1F_EventScript_Kid1::
	msgbox XanthosCity_Flat3_1F_Text_TradeMe, MSGBOX_DEFAULT
	release
	end

XanthosCity_Flat3_1F_Text_TradeMe:
	.string "Okay, you trade your POKéMON over first,\n"
	.string "and I'll trade it back to you.$"

XanthosCity_Flat3_1F_EventScript_Kid2::
	msgbox XanthosCity_Flat3_1F_Text_NoWay, MSGBOX_DEFAULT
	release
	end

XanthosCity_Flat3_1F_Text_NoWay:
	.string "No way! How do I know you'll\n"
	.string "give it back?$"

XanthosCity_Flat3_1F_EventScript_Woman::
	lock
	faceplayer
	msgbox XanthosCity_Flat3_1F_Text_RaisingThreeBoys, MSGBOX_DEFAULT
	release
	end

XanthosCity_Flat3_1F_Text_RaisingThreeBoys:
	.string "Dishes, laundry, school…\p"
	.string "It's not easy raising three boys.$"

XanthosCity_Flat3_1F_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_XANTHOS_NPC_TRADE_COMPLETED, XanthosCity_Flat3_1F_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_KECLEON
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox XanthosCity_Flat3_1F_Text_WillingToTradeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, XanthosCity_Flat3_1F_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, XanthosCity_Flat3_1F_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, XanthosCity_Flat3_1F_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	giveitem ITEM_COVENANT_ORB
	waitfanfare
	msgbox XanthosCity_Flat3_1F_Text_UrAwesome, MSGBOX_DEFAULT
	setflag FLAG_XANTHOS_NPC_TRADE_COMPLETED
	release
	end

XanthosCity_Flat3_1F_EventScript_DeclineTrade::
	@msgbox XanthosCity_Flat3_1F_Text_NotDesperateOrAnything, MSGBOX_DEFAULT
	release
	end

XanthosCity_Flat3_1F_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox XanthosCity_Flat3_1F_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
	release
	end

XanthosCity_Flat3_1F_EventScript_TradeCompleted::
	msgbox XanthosCity_Flat3_1F_Text_TradeWithOthers, MSGBOX_DEFAULT
	release
	end

XanthosCity_Flat3_1F_Text_WillingToTradeIt:
	.string "Hi! Do you have an {STR_VAR_1}!\p"
	.string "Would you trade it for my {STR_VAR_2}?$"

XanthosCity_Flat3_1F_Text_UrAwesome:
	.string "You're awesome! Thanks!$"

XanthosCity_Flat3_1F_Text_WontAcceptAnyLessThanRealMon:
	.string "No, no, no! I won't accept any\n"
	.string "less than a real {STR_VAR_1}!$"

XanthosCity_Flat3_1F_Text_NotDesperateOrAnything:
	.string "Oh, so you're not going to go through\n"
	.string "with this?\p"
	.string "That's cool. I'm not desperate to make\n"
	.string "a trade or anything.$"

XanthosCity_Flat3_1F_Text_TradeWithOthers:
	.string "I trade with my friends in other\n"
	.string "cities all the time.$"
