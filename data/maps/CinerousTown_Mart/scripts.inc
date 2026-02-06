CinerousTown_Mart_MapScripts::
	.byte 0

CinerousTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

CinerousTown_Mart_EventScript_Boy::
	msgbox CinerousTown_Mart_Text_ImGoingToBuyPokeBalls, MSGBOX_NPC
	end

CinerousTown_Mart_EventScript_Youngster::
	lock
	faceplayer
	msgbox CinerousTown_Mart_Text_ItemsInBattle, MSGBOX_NPC
	release
	end

CinerousTown_Mart_Text_ImGoingToBuyPokeBalls:
	.string "I'm going to buy a bunch of POKéBALLs\n"
	.string "and catch a bunch of POKéMON!$"


CinerousTown_Mart_Text_ItemsInBattle:
	.string "Some items can be used in battle.\p"
	.string "And some items like BERRIES can\n"
	.string "be used by the POKéMON themselves!$"
