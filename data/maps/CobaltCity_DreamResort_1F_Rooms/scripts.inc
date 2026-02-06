CobaltCity_DreamResort_1F_Rooms_MapScripts::
	.byte 0

DreamResort_EventScript_Corey::
	trainerbattle_single TRAINER_COREY, DreamResort_Text_CoreyIntro, DreamResort_Text_CoreyDefeated
	msgbox DreamResort_Text_CoreyPostBattle, MSGBOX_AUTOCLOSE
	end

DreamResort_EventScript_Yolanda::
	trainerbattle_single TRAINER_YOLANDA, DreamResort_Text_YolandaIntro, DreamResort_Text_YolandaDefeated
	msgbox DreamResort_Text_YolandaPostBattle, MSGBOX_AUTOCLOSE
	end

DreamResort_EventScript_Gentleman::
	msgbox DreamResort_Text_RarePokemon, MSGBOX_NPC
	end

DreamResort_Text_RarePokemon:
	.string "ISSHO is supposedly home to some\n"
	.string "very special POKéMON.\p"
	.string "Not everyone believes they even exist!$"

DreamResort_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_COBALT_NPC_TRADE_COMPLETED, DreamResort_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_IMPIDIMP
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox DreamResort_Text_WillingToTradeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, DreamResort_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, DreamResort_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, DreamResort_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	giveitem ITEM_COVENANT_ORB
	waitfanfare
	msgbox DreamResort_Text_UrAwesome, MSGBOX_DEFAULT
	setflag FLAG_COBALT_NPC_TRADE_COMPLETED
	release
	end

DreamResort_EventScript_DeclineTrade::
	@msgbox DreamResort_Text_NotDesperateOrAnything, MSGBOX_DEFAULT
	release
	end

DreamResort_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox DreamResort_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
	release
	end

DreamResort_EventScript_TradeCompleted::
	msgbox DreamResort_Text_TradeWithOthers, MSGBOX_DEFAULT
	release
	end

DreamResort_Text_WillingToTradeIt:
	.string "Hi! Do you have a {STR_VAR_1}!\p"
	.string "Would you trade it for my {STR_VAR_2}?$"

DreamResort_Text_UrAwesome:
	.string "You're awesome! Thanks!$"

DreamResort_Text_WontAcceptAnyLessThanRealMon:
	.string "No, no, no! I won't accept any\n"
	.string "less than a real {STR_VAR_1}!$"

DreamResort_Text_NotDesperateOrAnything:
	.string "Oh, so you're not going to go through\n"
	.string "with this?\p"
	.string "That's cool. I'm not desperate to make\n"
	.string "a trade or anything.$"

DreamResort_Text_TradeWithOthers:
	.string "I trade with my friends in other\n"
	.string "cities all the time.$"

