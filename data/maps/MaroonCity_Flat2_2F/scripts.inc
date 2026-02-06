MaroonCity_Flat2_2F_MapScripts::
	.byte 0

MaroonCity_Flat2_2F_EventScript_Maniac::
	msgbox MaroonCity_Flat2_2F_Text_Gulpin, MSGBOX_NPC
	end

MaroonCity_Flat2_2F_Text_Gulpin:
	.string "I love GULPIN. They're so round\n"
	.string "and adorable.\p"
	.string "But some people think they look\n"
	.string "ugly and smell bad.\p"
	.string "Can you believe that?$"

MaroonCity_Flat2_2F_EventScript_Pokemon::
	lock
	faceplayer
	playmoncry SPECIES_GULPIN, CRY_MODE_NORMAL
	msgbox MaroonCity_Flat2_2F_Text_Pokemon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MaroonCity_Flat2_2F_Text_Pokemon:
	.string "GULPIN: Urrrup.$"


