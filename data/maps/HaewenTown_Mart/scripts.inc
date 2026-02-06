HaewenTown_Mart_MapScripts::
	.byte 0

HaewenTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

HaewenTown_Mart_EventScript_Psychic::
	msgbox HaewenTown_Mart_Text_HeadRinging, MSGBOX_NPC
	end

HaewenTown_Mart_Text_HeadRinging:
	.string "Urgh...\n"
	.string "My head is ringing...$"


