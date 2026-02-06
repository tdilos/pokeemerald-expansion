WisteriaCity_Flat2_1F_MapScripts::
	.byte 0

WisteriaCity_Flat2_1F_EventScript_Man::
	lock
	faceplayer
	msgbox WisteriaCity_Flat2_1F_Text_MoppingUp, MSGBOX_DEFAULT
	release
	end

WisteriaCity_Flat2_1F_Text_MoppingUp:
	.string "Phew...\p"
	.string "Have you ever tried mopping up a whole\n"
	.string "diner all by yourself?\p"
	.string "So much for getting off early...$"

WisteriaCity_Flat2_1F_EventScript_Maniac::
	lock
	faceplayer
	msgbox WisteriaCity_Flat2_1F_Text_MoveAlong, MSGBOX_DEFAULT
	release
	end

WisteriaCity_Flat2_1F_Text_MoveAlong:
	.string "Nothing to see here.\n"
	.string "Move along.$"


