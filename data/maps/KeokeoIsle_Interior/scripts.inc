KeokeoIsle_Interior_MapScripts::
	.byte 0



KeokeoIsle_EventScript_Pali::
	trainerbattle_single TRAINER_PALI, KeokeoIsle_Text_PaliIntro, KeokeoIsle_Text_PaliDefeated
	msgbox KeokeoIsle_Text_PaliPostBattle, MSGBOX_AUTOCLOSE
	end

KeokeoIsle_Text_PaliIntro:
	.string "$"

KeokeoIsle_Text_PaliDefeated:
	.string "$"

KeokeoIsle_Text_PaliPostBattle:
	.string "$"

KeokeoIsle_EventScript_Makoa::
	trainerbattle_single TRAINER_MAKOA, KeokeoIsle_Text_MakoaIntro, KeokeoIsle_Text_MakoaDefeated
	msgbox KeokeoIsle_Text_MakoaPostBattle, MSGBOX_AUTOCLOSE
	end

KeokeoIsle_Text_MakoaIntro:
	.string "$"

KeokeoIsle_Text_MakoaDefeated:
	.string "$"

KeokeoIsle_Text_MakoaPostBattle:
	.string "$"

