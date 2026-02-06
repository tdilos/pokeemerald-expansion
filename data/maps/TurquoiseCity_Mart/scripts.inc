TurquoiseCity_Mart_MapScripts::
	.byte 0

TurquoiseCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

TurquoiseCity_Mart_EventScript_Fisherman::
	msgbox TurquoiseCity_Mart_Text_LureBallsRare, MSGBOX_NPC
	end

TurquoiseCity_Mart_Text_LureBallsRare:
	.string "Looks like they don't have\n"
	.string "LURE BALLS here.\p"
	.string "Maybe I should try the POKéBALL\n"
	.string "SHOP in MAROON CITY.$"

