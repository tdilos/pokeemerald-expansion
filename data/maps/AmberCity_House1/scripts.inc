AmberCity_House1_MapScripts::
	.byte 0

AmberCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_AMBER_NPC_TRADE_COMPLETED, AmberCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_SIGILYPH
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox AmberCity_House1_Text_WillingToTradeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, AmberCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, AmberCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, AmberCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	giveitem ITEM_COVENANT_ORB
	waitfanfare
	msgbox AmberCity_House1_Text_UrAwesome, MSGBOX_DEFAULT
	setflag FLAG_AMBER_NPC_TRADE_COMPLETED
	release
	end

AmberCity_House1_EventScript_DeclineTrade::
	@msgbox AmberCity_House1_Text_NotDesperateOrAnything, MSGBOX_DEFAULT
	release
	end

AmberCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox AmberCity_House1_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
	release
	end

AmberCity_House1_EventScript_TradeCompleted::
	msgbox AmberCity_House1_Text_TradeWithOthers, MSGBOX_DEFAULT
	release
	end

AmberCity_House1_Text_WillingToTradeIt:
	.string "Hi! Do you have a {STR_VAR_1}!\p"
	.string "Would you trade it for my {STR_VAR_2}?$"

AmberCity_House1_Text_UrAwesome:
	.string "You're awesome! Thanks!$"

AmberCity_House1_Text_WontAcceptAnyLessThanRealMon:
	.string "No, no, no! I won't accept any\n"
	.string "less than a real {STR_VAR_1}!$"

AmberCity_House1_Text_NotDesperateOrAnything:
	.string "Oh, so you're not going to go through\n"
	.string "with this?\p"
	.string "That's cool. I'm not desperate to make\n"
	.string "a trade or anything.$"

AmberCity_House1_Text_TradeWithOthers:
	.string "I trade with my friends in other\n"
	.string "cities all the time.$"
