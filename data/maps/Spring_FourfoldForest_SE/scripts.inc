Spring_FourfoldForest_SE_MapScripts::
	.byte 0



FourfoldForest_SE_EventScript_Drogo::
	trainerbattle_single TRAINER_DROGO, FourfoldForest_SE_Text_DrogoIntro, FourfoldForest_SE_Text_DrogoDefeated
	msgbox FourfoldForest_SE_Text_DrogoPostBattle, MSGBOX_AUTOCLOSE
	end

FourfoldForest_SE_Text_DrogoIntro:
	.string "$"

FourfoldForest_SE_Text_DrogoDefeated:
	.string "$"

FourfoldForest_SE_Text_DrogoPostBattle:
	.string "$"


FourfoldForest_SE_EventScript_Barnaby::
	trainerbattle_single TRAINER_BARNABY, FourfoldForest_SE_Text_BarnabyIntro, FourfoldForest_SE_Text_BarnabyDefeated
	msgbox FourfoldForest_SE_Text_BarnabyPostBattle, MSGBOX_AUTOCLOSE
	end

FourfoldForest_SE_Text_BarnabyIntro:
	.string "$"

FourfoldForest_SE_Text_BarnabyDefeated:
	.string "$"

FourfoldForest_SE_Text_BarnabyPostBattle:
	.string "$"


