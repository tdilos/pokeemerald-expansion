CobaltCity_House2_MapScripts::
	.byte 0

CobaltCity_House2_EventScript_OldWoman::
	msgbox CobaltCity_House2_Text_MyrtleLikesToTravel, MSGBOX_NPC
	end

CobaltCity_House2_Text_MyrtleLikesToTravel:
	.string "The gym leader of this city is MYRTLE.\p"
	.string "Apparently she loves to travel and is\n"
	.string "always away from her gym.\p"
	.string "Now that doesn't sound like a\n"
	.string "responsible thing to do.$"

CobaltCity_House2_EventScript_Woman::
	msgbox CobaltCity_House2_Text_HateDishes, MSGBOX_NPC
	end

CobaltCity_House2_Text_HateDishes:
	.string "I hate doing dishes.$"

CobaltCity_House2_EventScript_Girl::
	msgbox CobaltCity_House2_Text_MyrtlePokemon, MSGBOX_NPC
	end

CobaltCity_House2_Text_MyrtlePokemon:
	.string "MYRTLE has a TROPIUS.\n"
	.string "I want one!$"

