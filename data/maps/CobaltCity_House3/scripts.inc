CobaltCity_House3_MapScripts::
	.byte 0

CobaltCity_House3_EventScript_Woman::
	msgbox CobaltCity_House3_Text_WhatILoveIssho, MSGBOX_NPC
	end

CobaltCity_House3_EventScript_Wynaut::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WYNAUT, CRY_MODE_NORMAL
	msgbox CobaltCity_House3_Text_Wynaut, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CobaltCity_House3_Text_WhatILoveIssho:
	.string "What do I love most about ISSHO?\p"
	.string "All the POKéMON you can't find\n"
	.string "anywhere else!$"

CobaltCity_House3_Text_Wynaut:
	.string "WYNAUT: Wyy wyy wyyyy?$"
