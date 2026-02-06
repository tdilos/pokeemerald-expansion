BurgundyTown_House2_MapScripts::
	.byte 0

BurgundyTown_House2_EventScript_Boy::
	lock
	faceplayer
	msgbox BurgundyTown_House2_Text_SomeFolks, MSGBOX_DEFAULT
	release
	end

BurgundyTown_House2_Text_SomeFolks:
	.string "Some folks try to help people\n"
	.string "whatever ways they can.\p"
	.string "Other folks try to take advantage\n"
	.string "of people any way they can.\p"
	.string "Why is that, do you reckon?$"

