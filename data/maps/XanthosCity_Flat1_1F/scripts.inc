XanthosCity_Flat1_1F_MapScripts::
	.byte 0

XanthosCity_Flat1_1F_EventScript_Man::
	msgbox XanthosCity_Flat1_1F_Text_LifeInOneCity, MSGBOX_NPC
	end

XanthosCity_Flat1_1F_EventScript_Woman::
	msgbox XanthosCity_Flat1_1F_Text_FlyingPkmn, MSGBOX_NPC
	end

XanthosCity_Flat1_1F_Text_LifeInOneCity:
	.string "Some people spend their whole life\n"
	.string "in one city.\p"
	.string "Don't you think that's strange?$"

XanthosCity_Flat1_1F_Text_FlyingPkmn:
	.string "I wonder what it would be like\n"
	.string "to be a flying POKéMON…$"
