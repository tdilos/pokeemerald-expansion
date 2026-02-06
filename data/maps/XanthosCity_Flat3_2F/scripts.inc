XanthosCity_Flat3_2F_MapScripts::
	.byte 0

XanthosCity_Flat3_2F_EventScript_Man::
	msgbox XanthosCity_Flat3_2F_Text_OldCity, MSGBOX_NPC
	end

XanthosCity_Flat3_2F_Text_OldCity:
	.string "They say that XANTHOS CITY was ravaged\n"
	.string "by a natural disaster long ago,\p"
	.string "and much of the city was rebuilt on\n"
	.string "top of the ruins.\p"
	.string "I wonder how much of the old city\n"
	.string "remains today…$"

XanthosCity_Flat3_2F_EventScript_Pokemon::
	lock
	faceplayer
	playmoncry SPECIES_GLAMEOW, CRY_MODE_NORMAL
	msgbox XanthosCity_Flat3_2F_Text_Pokemon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

XanthosCity_Flat3_2F_Text_Pokemon:
	.string "GLAMEOW: Nyaa{EMOJI_TILDE}$"
