PitchblakCity_Flat4_2F_MapScripts::
	.byte 0

PitchblakCity_Flat4_2F_EventScript_Maniac::
	lock
	faceplayer
	msgbox PitchblakCity_Flat4_2F_Text_TechBoom, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Flat4_2F_Text_TechBoom:
	.string "The tech industry is booming right now!\p"
	.string "It's a great time to be working at\n"
	.string "a place like KENDOM CORP.$"

PitchblakCity_Flat4_2F_EventScript_Girl::
	lock
	faceplayer
	msgbox PitchblakCity_Flat4_2F_Text_KendomaTech, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Flat4_2F_Text_KendomaTech:
	.string "My brother works at KENDOM CORP.\p"
	.string "He tells me about all the cool new\n"
	.string "projects they're working on.\p"
	.string "Did you know that they have\n"
	.string "working teleporters?\p"
	.string "Someday they hope they can warp people\n"
	.string "to places around the world.\p"
	.string "Or even to other worlds!$"


