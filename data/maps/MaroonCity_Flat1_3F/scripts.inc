MaroonCity_Flat1_3F_MapScripts::
	.byte 0

MaroonCity_Flat1_3F_EventScript_Woman::
	msgbox MaroonCity_Flat1_3F_Text_Selfishness, MSGBOX_NPC
	end

MaroonCity_Flat1_3F_Text_Selfishness:
	.string "Humans are selfish, don't you think?\p"
	.string "The more they strive, the more they\n"
	.string "hurt one another.\p"
	.string "That's why I choose to sit inside\n"
	.string "and do nothing at all...$"
	@.string "They say people are social and\n"
	@.string "cooperative by nature.\p"
	@.string "But the more people I meet, the more\n"
	@.string "I'm convinced that they're selfish.$"
	@.string "But I can't help feeling that we're\n"
	@.string "all selfish deep down.\p"
	@.string "Are we really friendly only out\n"
	@.string "of self-interest?$"

MaroonCity_Flat1_3F_EventScript_Pokemon::
	lock
	faceplayer
	playmoncry SPECIES_GLAMEOW, CRY_MODE_NORMAL
	msgbox MaroonCity_Flat1_3F_Text_Pokemon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MaroonCity_Flat1_3F_Text_Pokemon:
	.string "GLAMEOW: Nyaan.$"

