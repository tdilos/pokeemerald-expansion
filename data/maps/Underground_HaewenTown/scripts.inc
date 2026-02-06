Underground_HaewenTown_MapScripts::
	.byte 0

HaewenTown_EventScript_Hiker::
	lock
	faceplayer
	msgbox HaewenTown_Text_Sandshraf, MSGBOX_DEFAULT
	release
	end

HaewenTown_Text_Sandshraf:
	.string "This cave leads to the SANDSHRAF.\p"
	.string "It's a tricky route, but it's the\n"
	.string "fastest way to AMBER CITY.$"


