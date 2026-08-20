Spring_FourfoldForest_NE_MapScripts::
	.byte 0



FourfoldForest_NE_EventScript_Nelly::
	trainerbattle_single TRAINER_NELLY, FourfoldForest_NE_Text_NellyIntro, FourfoldForest_NE_Text_NellyDefeated
	msgbox FourfoldForest_NE_Text_NellyPostBattle, MSGBOX_AUTOCLOSE
	end

FourfoldForest_NE_Text_NellyIntro:
	.string "$"

FourfoldForest_NE_Text_NellyDefeated:
	.string "$"

FourfoldForest_NE_Text_NellyPostBattle:
	.string "$"


FourfoldForest_NE_EventScript_Hanne::
	trainerbattle_single TRAINER_HANNE, FourfoldForest_NE_Text_HanneIntro, FourfoldForest_NE_Text_HanneDefeated
	msgbox FourfoldForest_NE_Text_HannePostBattle, MSGBOX_AUTOCLOSE
	end

FourfoldForest_NE_Text_HanneIntro:
	.string "$"

FourfoldForest_NE_Text_HanneDefeated:
	.string "$"

FourfoldForest_NE_Text_HannePostBattle:
	.string "$"


FourfoldForest_NE_EventScript_Gep::
	trainerbattle_single TRAINER_GEP, FourfoldForest_NE_Text_GepIntro, FourfoldForest_NE_Text_GepDefeated
	msgbox FourfoldForest_NE_Text_GepPostBattle, MSGBOX_AUTOCLOSE
	end

FourfoldForest_NE_Text_GepIntro:
	.string "$"

FourfoldForest_NE_Text_GepDefeated:
	.string "$"

FourfoldForest_NE_Text_GepPostBattle:
	.string "$"


FourfoldForest_NE_EventScript_Tomkin::
	trainerbattle_single TRAINER_TOMKIN, FourfoldForest_NE_Text_TomkinIntro, FourfoldForest_NE_Text_TomkinDefeated
	msgbox FourfoldForest_NE_Text_TomkinPostBattle, MSGBOX_AUTOCLOSE
	end

FourfoldForest_NE_Text_TomkinIntro:
	.string "$"

FourfoldForest_NE_Text_TomkinDefeated:
	.string "$"

FourfoldForest_NE_Text_TomkinPostBattle:
	.string "$"


FourfoldForest_NE_EventScript_Hitch::
	trainerbattle_single TRAINER_HITCH, FourfoldForest_NE_Text_HitchIntro, FourfoldForest_NE_Text_HitchDefeated
	msgbox FourfoldForest_NE_Text_HitchPostBattle, MSGBOX_AUTOCLOSE
	end

FourfoldForest_NE_Text_HitchIntro:
	.string "$"

FourfoldForest_NE_Text_HitchDefeated:
	.string "$"

FourfoldForest_NE_Text_HitchPostBattle:
	.string "$"


