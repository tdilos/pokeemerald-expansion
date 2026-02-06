UmberTown_JaceHouse_MapScripts::
	.byte 0

UmberTown_JaceHouse_EventScript_Mom::
	msgbox UmberTown_MaleMCHouse_Text_JaceMom, MSGBOX_NPC
	end

UmberTown_JaceHouse_EventScript_Girl::
	msgbox UmberTown_MaleMCHouse_Text_JaceSister, MSGBOX_NPC
	end

@UmberTown_MaleMCHouse_Text_JaceMom:
@	.string "Hi, I'm JACE's mom.$"

UmberTown_MaleMCHouse_Text_JaceMom:
	.string "Keep an eye on JACE for me,\n"
	.string "would you {PLAYER}?\p"
	.string "He's a spirited kid, but he\n"
	.string "sometimes underestimates the\l"
	.string "things he gets himself into.$"

UmberTown_MaleMCHouse_Text_JaceSister:
	.string "The newslady said another kind\n"
	.string "of rare POKéMON appeared today!\p"
	.string "I wonder what she'll talk about\n"
	.string "tomorrow.$"
