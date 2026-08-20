Spring_FourfoldForest_NW_MapScripts::
	.byte 0


FourfoldForest_NW_EventScript_Tillie::
	trainerbattle_single TRAINER_TILLIE, FourfoldForest_NW_Text_TillieIntro, FourfoldForest_NW_Text_TillieDefeated
	msgbox FourfoldForest_NW_Text_TilliePostBattle, MSGBOX_AUTOCLOSE
	end

FourfoldForest_NW_Text_TillieIntro:
	.string "$"

FourfoldForest_NW_Text_TillieDefeated:
	.string "$"

FourfoldForest_NW_Text_TilliePostBattle:
	.string "$"


