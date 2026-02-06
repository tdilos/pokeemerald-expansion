XanthosCity_Flat2_3F_MapScripts::
	.byte 0

XanthosCity_Flat2_3F_EventScript_Man::
	msgbox XanthosCity_Flat2_3F_Text_KendomaCorp, MSGBOX_NPC
	end

XanthosCity_Flat2_3F_Text_KendomaCorp:
	.string "My brother works at KENDOM CORP\n"
	.string "in PITCHBLAK CITY.\p"
	.string "He told me they're planning to open a new\n"
	.string "branch soon, here in XANTHOS CITY.\p"
	.string "I sure hope so. Their products\n"
	.string "are amazing!$"

XanthosCity_Flat2_3F_EventScript_Guard::
	msgbox XanthosCity_Flat2_3F_Text_NoVisitors, MSGBOX_NPC
	end

XanthosCity_Flat2_3F_Text_NoVisitors:
	.string "Visitors are not allowed in the penthouse\n"
	.string "at this time.$"
