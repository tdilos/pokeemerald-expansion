MaroonCity_Flat2_1F_MapScripts::
	.byte 0

MaroonCity_Flat2_1F_EventScript_Youngster::
	lock
	faceplayer
	msgbox MaroonCity_Flat2_1F_Text_SomethingStinks, MSGBOX_DEFAULT
	release
	end

MaroonCity_Flat2_1F_Text_SomethingStinks:
	.string "P-U! Something around here\n"
	.string "really stinks!$"

MaroonCity_Flat2_1F_EventScript_FatMan::
	msgbox MaroonCity_Flat2_1F_Text_PokemonRangers, MSGBOX_NPC
	end

MaroonCity_Flat2_1F_Text_PokemonRangers:
	.string "The POKéMON RANGERS are based here\n"
	.string "in MAROON CITY.\p"
	.string "It sure is nice living around\n"
	.string "a bunch of helpful trainers.$"

MaroonCity_Flat2_1F_EventScript_Woman::
	lock
	faceplayer
	msgbox MaroonCity_Flat2_1F_Text_LeaderOfRangers, MSGBOX_DEFAULT
	release
	end

MaroonCity_Flat2_1F_Text_LeaderOfRangers:
	.string "The leader of the POKéMON RANGERS\n"
	.string "is JUSTIN.\p"
	.string "He's a mysterious man. No one knows\n"
	.string "much about him.\p"
	.string "And he only comes here into the\n"
	.string "city on rare occasions.$"
