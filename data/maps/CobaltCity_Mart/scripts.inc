CobaltCity_Mart_MapScripts::
	.byte 0

CobaltCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

CobaltCity_Mart_EventScript_BlackBelt::
	msgbox CobaltCity_Mart_Text_TooManyStatusMoves, MSGBOX_NPC
	end

CobaltCity_Mart_Text_TooManyStatusMoves:
	.string "Gah! Grass types learn too many\n"
	.string "status moves.\p"
	.string "I can't afford to buy remedies\n"
	.string "for them all!$"
