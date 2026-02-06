AmberCity_Mart_MapScripts::
	.byte 0

AmberCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

AmberCity_Mart_EventScript_Girl::
	msgbox AmberCity_Mart_Text_StockUpOnPotions, MSGBOX_NPC
	end

AmberCity_Mart_Text_StockUpOnPotions:
	.string "Hmm, ROUTE 87 is supposed to have\n"
	.string "frequent sandstorms.\p"
	.string "I'd better stock up on potions.$"
