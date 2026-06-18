KiyahaIsle_Exterior_MapScripts::
	.byte 0



KiyahaIsle_EventScript_Nalu::
	trainerbattle_single TRAINER_NALU, KiyahaIsle_Text_NaluIntro, KiyahaIsle_Text_NaluDefeated
	msgbox KiyahaIsle_Text_NaluPostBattle, MSGBOX_AUTOCLOSE
	end

KiyahaIsle_Text_NaluIntro:
	.string "Hey! Did you just come from the sea?$"

KiyahaIsle_Text_NaluDefeated:
	.string "Uh-oh.$"

KiyahaIsle_Text_NaluPostBattle:
	.string "My mom always says not to go\n"
	.string "in the seawater.\p"
	.string "Otherwise the sea demons will get you.$"

KiyahaIsle_EventScript_Nanea::
	trainerbattle_single TRAINER_NANEA, KiyahaIsle_Text_NaneaIntro, KiyahaIsle_Text_NaneaDefeated
	msgbox KiyahaIsle_Text_NaneaPostBattle, MSGBOX_AUTOCLOSE
	end

KiyahaIsle_Text_NaneaIntro:
	.string "$"

KiyahaIsle_Text_NaneaDefeated:
	.string "$"

KiyahaIsle_Text_NaneaPostBattle:
	.string "$"


