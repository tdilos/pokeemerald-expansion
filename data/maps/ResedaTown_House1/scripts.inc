ResedaTown_House1_MapScripts::
	.byte 0

ResedaTown_House1_EventScript_Woman::
	msgbox ResedaTown_House1_Text_BugGym, MSGBOX_NPC
	end

ResedaTown_House1_Text_BugGym:
	.string "The gym leader here uses BUG type\n"
	.string "POKéMON.\p"
	.string "I heard that FIRE and ROCK\n"
	.string "types do good against those.\p"
	.string "But they sure are awful hard\n"
	.string "to come by around here.$"

ResedaTown_House1_EventScript_Boy::
	msgbox ResedaTown_House1_Text_GymLeader, MSGBOX_NPC
	end

ResedaTown_House1_Text_GymLeader:
	.string "When I grow up, I want to be a\n"
	.string "gym leader just like ARTHUR!$"

ResedaTown_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_RESEDA_NPC_TRADE_COMPLETED, ResedaTown_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_TIMBURR
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox ResedaTown_House1_Text_WillingToTradeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ResedaTown_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, ResedaTown_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, ResedaTown_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	giveitem ITEM_COVENANT_ORB
	waitfanfare
	msgbox ResedaTown_House1_Text_UrAwesome, MSGBOX_DEFAULT
	setflag FLAG_RESEDA_NPC_TRADE_COMPLETED
	release
	end

ResedaTown_House1_EventScript_DeclineTrade::
	@msgbox ResedaTown_House1_Text_NotDesperateOrAnything, MSGBOX_DEFAULT
	release
	end

ResedaTown_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox ResedaTown_House1_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
	release
	end

ResedaTown_House1_EventScript_TradeCompleted::
	msgbox ResedaTown_House1_Text_TradeWithOthers, MSGBOX_DEFAULT
	release
	end

ResedaTown_House1_Text_WillingToTradeIt:
	.string "Hi! Do you have a {STR_VAR_1}?\p"
	.string "Would you trade it for my {STR_VAR_2}?$"

ResedaTown_House1_Text_UrAwesome:
	.string "You're awesome! Thanks!$"

ResedaTown_House1_Text_WontAcceptAnyLessThanRealMon:
	.string "No, no, no! I won't accept any\n"
	.string "less than a real {STR_VAR_1}!$"

ResedaTown_House1_Text_NotDesperateOrAnything:
	.string "Oh, so you're not going to go through\n"
	.string "with this?\p"
	.string "That's cool. I'm not desperate to make\n"
	.string "a trade or anything.$"

ResedaTown_House1_Text_TradeWithOthers:
	.string "I trade with my friends in other\n"
	.string "cities all the time.$"
