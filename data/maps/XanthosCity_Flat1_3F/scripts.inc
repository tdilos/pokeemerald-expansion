XanthosCity_Flat1_3F_MapScripts::
	.byte 0

XanthosCity_Flat1_3F_EventScript_LittleGirl::
	msgbox XanthosCity_Flat1_3F_Text_MomIsReporter, MSGBOX_NPC
	end

XanthosCity_Flat1_3F_EventScript_Woman::
	msgbox XanthosCity_Flat1_3F_Text_Nicknames, MSGBOX_NPC
	end

XanthosCity_Flat1_3F_Text_MomIsReporter:
	.string "My mommy is a news reporter\n"
	.string "on TV!$"

XanthosCity_Flat1_3F_Text_Nicknames:
	.string "Do you nickname your POKéMON?\p"
	.string "I think it's more affectionate when\n"
	.string "you give them names.$"

XanthosCity_Flat1_3F_EventScript_Guard::
	msgbox XanthosCity_Flat1_3F_Text_NoVisitors, MSGBOX_NPC
	end

XanthosCity_Flat1_3F_Text_NoVisitors:
	.string "Visitors are not allowed in the penthouse\n"
	.string "at this time.$"


