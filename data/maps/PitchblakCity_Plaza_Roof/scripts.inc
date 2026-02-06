PitchblakCity_Plaza_Roof_MapScripts::
	.byte 0

PitchblakCity_Plaza_Roof_EventScript_Woman::
	msgbox PitchblakCity_Plaza_Roof_Text_BanPokemon, MSGBOX_NPC
	end

PitchblakCity_Plaza_Roof_Text_BanPokemon:
	.string "Sometimes I think the city would feel a\n"
	.string "little safer if they just banned POKéMON.$"

PitchblakCity_Plaza_Roof_EventScript_Man::
	lock
	msgbox PitchblakCity_Plaza_Roof_Text_BanPokemon2, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Plaza_Roof_Text_BanPokemon2:
	.string "That's nonsense! Then only\n"
	.string "criminals would have POKéMON!$"

PitchblakCity_Plaza_Roof_EventScript_Boy::
	lock
	faceplayer
	msgbox PitchblakCity_Plaza_Roof_Text_BanPokemon3, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Plaza_Roof_Text_BanPokemon3:
	.string "I don't mind if they ban certain POKéMON.\p"
	.string "I mean, does the average person really\n"
	.string "need an ELECTRODE?$"

PitchblakCity_Plaza_Roof_EventScript_Youngster::
	msgbox PitchblakCity_Plaza_Roof_Text_BadIVs, MSGBOX_NPC
	end

PitchblakCity_Plaza_Roof_Text_BadIVs:
	.string "Those scientists downstairs told me that\n"
	.string "my GROWLITHE has really bad IVs.\p"
	.string "That's a bummer...\p"
	.string "Maybe I'll just get a new one.$"

PitchblakCity_Plaza_Roof_EventScript_Pokemon::
	lock
	@faceplayer
	@waitse
	playmoncry SPECIES_GROWLITHE, CRY_MODE_NORMAL
	msgbox PitchblakCity_Plaza_Roof_Text_Pokemon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

PitchblakCity_Plaza_Roof_Text_Pokemon:
	.string "GROWLITHE: Grow...$"







PitchblakCity_Plaza_Roof_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_PITCHBLAK_NPC_TRADE_COMPLETED, PitchblakCity_Plaza_Roof_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_LITWICK
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox PitchblakCity_Plaza_Roof_Text_WillingToTradeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PitchblakCity_Plaza_Roof_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PitchblakCity_Plaza_Roof_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, PitchblakCity_Plaza_Roof_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	giveitem ITEM_COVENANT_ORB
	waitfanfare
	msgbox PitchblakCity_Plaza_Roof_Text_UrAwesome, MSGBOX_DEFAULT
	setflag FLAG_PITCHBLAK_NPC_TRADE_COMPLETED
	release
	end

PitchblakCity_Plaza_Roof_EventScript_DeclineTrade::
	@msgbox PitchblakCity_Plaza_Roof_Text_NotDesperateOrAnything, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Plaza_Roof_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PitchblakCity_Plaza_Roof_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Plaza_Roof_EventScript_TradeCompleted::
	msgbox PitchblakCity_Plaza_Roof_Text_TradeWithOthers, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Plaza_Roof_Text_WillingToTradeIt:
	.string "Hi! Do you have a {STR_VAR_1}!\p"
	.string "Would you trade it for my {STR_VAR_2}?$"

PitchblakCity_Plaza_Roof_Text_UrAwesome:
	.string "You're awesome! Thanks!$"

PitchblakCity_Plaza_Roof_Text_WontAcceptAnyLessThanRealMon:
	.string "No, no, no! I won't accept any\n"
	.string "less than a real {STR_VAR_1}!$"

PitchblakCity_Plaza_Roof_Text_NotDesperateOrAnything:
	.string "Oh, so you're not going to go through\n"
	.string "with this?\p"
	.string "That's cool. I'm not desperate to make\n"
	.string "a trade or anything.$"

PitchblakCity_Plaza_Roof_Text_TradeWithOthers:
	.string "I trade with my friends in other\n"
	.string "cities all the time.$"




