Route69_MapScripts::
	.byte 0

Route69_EventScript_Luanne::
	trainerbattle_single TRAINER_LUANNE, Route69_Text_LuanneIntro, Route69_Text_LuanneDefeated
	msgbox Route69_Text_LuannePostBattle, MSGBOX_AUTOCLOSE
	end

Route69_EventScript_Hiker::
	lock
	faceplayer
	msgbox Route69_Text_Detour, MSGBOX_DEFAULT
	release
	end

Route69_Text_Detour:
	.string "'Fraid there's no easy way\n"
	.string "over this river.\p"
	.string "If yer POKéMON can't swim it, ye'll have\n"
	.string "to take a detour through MT SHIRO.$"


Route69_EventScript_Man::
	lock
	faceplayer
	msgbox Route69_Text_Waterfall, MSGBOX_DEFAULT
	release
	end

Route69_Text_Waterfall:
	.string "This waterfall is amazing!\n"
	.string "I'm glad we came here.$"

Route69_EventScript_Woman::
	lock
	faceplayer
	msgbox Route69_Text_Rainbow, MSGBOX_DEFAULT
	release
	end

Route69_Text_Rainbow:
	.string "I see a rainbow!$"
