MaroonCity_Mart_MapScripts::
	.byte 0

MaroonCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

MaroonCity_Mart_EventScript_Ranger::
	msgbox MaroonCity_Mart_Text_WoodsAroundHere, MSGBOX_NPC
	end

MaroonCity_Mart_Text_WoodsAroundHere:
	.string "The woods around here are\n"
	.string "tricky to navigate.\p"
	.string "You'd better stock up in supplies\n"
	.string "if you're going in there.$"



