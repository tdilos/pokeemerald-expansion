Route83_Hydroplant_1F_MapScripts::
	.byte 0

Route83_Hydroplant_EventScript_Worker::
	lock
	faceplayer
	msgbox Route83_Hydroplant_Text_ExplainTM72, MSGBOX_DEFAULT
	closemessage
	release
	end

Route83_Hydroplant_Text_ExplainTM72:
	.string "That TM I gave you contains\n"
	.string "CHARGE BEAM.\p"
	.string "It's a move that charges electrical power\n"
	.string "in order to attack.\p"
	.string "It also has a high chance of raising your\n"
	.string "POKéMON's SPECIAL ATTACK.$"

Route83_Hydroplant_EventScript_Man::
	lock
	faceplayer
	msgbox Route83_Hydroplant_Text_PowerToCity, MSGBOX_DEFAULT
	closemessage
	release
	end

Route83_Hydroplant_Text_PowerToCity:
	.string "This facility turns hydromotive energy\n"
	.string "from the dam into mechanical energy\l"
	.string "that moves a turbine that creates\l"
	.string "an alternating current that generates\l"
	.string "electrical energy.$"

Route83_Hydroplant_EventScript_FatMan::
	msgbox Route83_Hydroplant_Text_Fortran, MSGBOX_DEFAULT
	closemessage
	end

Route83_Hydroplant_Text_Fortran:
	.string "Back in my day we wrote in Fortran,\n"
	.string "babyy{EMOJI_TILDE}$"




