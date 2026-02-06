ResedaTown_Mart_MapScripts::
	.byte 0

ResedaTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

ResedaTown_Mart_EventScript_BirdKeeper::
	msgbox ResedaTown_Mart_Text_MartBadges, MSGBOX_NPC
	end

ResedaTown_Mart_Text_MartBadges:
	.string "POKéMARTS will sell you better items\n"
	.string "the more gym badges you have.\p"
	.string "Check back here again if you manage\n"
	.string "to get a badge from ARTHUR.$"

ResedaTown_Mart_EventScript_Woman::
	@msgbox ResedaTown_Mart_Text_TMsHMs, MSGBOX_NPC
	msgbox ResedaTown_Mart_Text_PokeballEmporium, MSGBOX_NPC
	end

ResedaTown_Mart_Text_PokeballEmporium:
	.string "Have you heard of the POKé BALL\n"
	.string "EMPORIUM in MAROON CITY?\p"
	.string "A place like this couldn't even compare\n"
	.string "to the POKé BALLS they have.$"

ResedaTown_Mart_Text_TMsHMs:
	.string "TM moves can be forgotten naturally,\n"
	.string "but HM moves are harder to get rid of.\p"
	.string "I heard there's a man in SCARLET TOWN\n"
	.string "who can forget HM moves for you.$"
