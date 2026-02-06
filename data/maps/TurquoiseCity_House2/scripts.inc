TurquoiseCity_House2_MapScripts::
	.byte 0

TurquoiseCity_House2_EventScript_Man::
	msgbox TurquoiseCity_House2_Text_BrendanHelpUs, MSGBOX_NPC
	closemessage
	end

TurquoiseCity_House2_Text_BrendanHelpUs:
	.string "BRENDAN is a strong trainer from\n"
	.string "the HOENN region.\p"
	.string "I'm sure glad he came all the way out here\n"
	.string "to save us from those GENESIS thugs.$" 

TurquoiseCity_House2_EventScript_Woman::
	msgbox TurquoiseCity_House2_Text_BrendansDad, MSGBOX_NPC
	closemessage
	end

TurquoiseCity_House2_Text_BrendansDad:
	.string "BRENDAN'S father is also\n"
	.string "a strong trainer.\p"
	.string "I guess the apple doesn't\n"
	.string "fall far from the tree!$" 

TurquoiseCity_House2_EventScript_LittleBoy1::
	lock
	msgbox TurquoiseCity_House2_Text_PlayPretend, MSGBOX_DEFAULT
	closemessage
	release
	end

TurquoiseCity_House2_Text_PlayPretend:
	.string "Okay, you be those TEAM GENESIS\n"
	.string "guys and I'll be BRENDAN.$"

TurquoiseCity_House2_EventScript_LittleBoy2::
	lock
	msgbox TurquoiseCity_House2_Text_IWannaBeBrendan, MSGBOX_DEFAULT
	closemessage
	release
	end

TurquoiseCity_House2_Text_IWannaBeBrendan:
	.string "No I wanna be BRENDAN!$"

