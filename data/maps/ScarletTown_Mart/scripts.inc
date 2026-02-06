ScarletTown_Mart_MapScripts::
	.byte 0

ScarletTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

ScarletTown_Mart_EventScript_Breeder::
	msgbox ScarletTown_Mart_Text_PoisonMushrooms, MSGBOX_NPC
	end

ScarletTown_Mart_Text_PoisonMushrooms:
	.string "The mushrooms around here\n"
	.string "are poisonous.\p"
	.string "Maybe I should buy more ANTIDOTES.$"



