Spring_ShireTowne_Building3_MapScripts::
	.byte 0


ShireTowne_Building3_EventScript_OldMaid::
	lock
	faceplayer
	msgbox ShireTowne_Building3_Text_NoMoreGuests, MSGBOX_DEFAULT
	release
	end

ShireTowne_Building3_Text_NoMoreGuests:
	.string "No more beds here, dearie.\p"
	.string "You'll have to stay somewhere else,\n"
	.string "I'm afraid.$"

ShireTowne_Building3_EventScript_Girl::
	lock
	faceplayer
	msgbox ShireTowne_Building3_Text_Chores, MSGBOX_DEFAULT
	release
	end

ShireTowne_Building3_Text_Chores:
	.string "Wipe the table, clean the plate.\n"
	.string "Early morning, evening late.\p"
	.string "Step by step and stroke by stroke.\n"
	.string "Scrub the grease and sweep the smoke.$"

