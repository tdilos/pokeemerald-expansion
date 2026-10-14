Spring_ShireTowne_Building1_2F_MapScripts::
	.byte 0




ShireTowne_Building1_2F_EventScript_Scientist1::
	lock
	faceplayer
	msgbox ShireTowne_Building1_2F_Text_ResearchTeam, MSGBOX_DEFAULT
	release
	end

ShireTowne_Building1_2F_Text_ResearchTeam:
	.string "We're part of DR. BETTERMAN'S\n"
	.string "research team.\p"
	.string "We brought this PORYGON with us to\n"
	.string "communicate with everyone back home.\p"
	.string "PORYGON can access your PC as well.\n"
	.string "Feel free to try it out!$"


ShireTowne_Building1_2F_EventScript_Scientist2::
	lock
	faceplayer
	msgbox ShireTowne_Building1_2F_Text_ChangingSeasons, MSGBOX_DEFAULT
	release
	end

ShireTowne_Building1_2F_Text_ChangingSeasons:
	.string "The seasons on this world change so rapidly.\n"
	.string "I should've brought a heavier coat...$"

