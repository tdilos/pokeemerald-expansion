MindaroCity_Flat2_3F_MapScripts::
	.byte 0

MindaroCity_Flat2_3F_EventScript_Woman::
	msgbox MindaroCity_Flat2_3F_Text_LifeIsUnfair, MSGBOX_NPC
	end

MindaroCity_Flat2_3F_Text_LifeIsUnfair:
	.string "Some people work hard their whole lives\n"
	.string "just to barely scrape by.\p"
	.string "While others are born into luxury and\n"
	.string "never have to lift a finger.\p"
	.string "It's a cruel and random world,\n"
	.string "don't you think?$"

MindaroCity_Flat2_3F_EventScript_Pokemon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_GLAMEOW, CRY_MODE_NORMAL
	msgbox MindaroCity_Flat2_3F_Text_Pokemon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MindaroCity_Flat2_3F_Text_Pokemon:
	.string "GLAMEOW: Nyaa!$"


