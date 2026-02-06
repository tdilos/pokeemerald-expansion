Route75_MapScripts::
	.byte 0

Route75_EventScript_Audrey::
	trainerbattle_single TRAINER_AUDREY, Route75_Text_AudreyIntro, Route75_Text_AudreyDefeated
	msgbox Route75_Text_AudreyPostBattle, MSGBOX_AUTOCLOSE
	end

Route75_EventScript_Anders::
	trainerbattle_single TRAINER_ANDERS, Route75_Text_AndersIntro, Route75_Text_AndersDefeated
	msgbox Route75_Text_AndersPostBattle, MSGBOX_AUTOCLOSE
	end

Route75_EventScript_Muriel::
	trainerbattle_single TRAINER_MURIEL, Route75_Text_MurielIntro, Route75_Text_MurielDefeated
	msgbox Route75_Text_MurielPostBattle, MSGBOX_AUTOCLOSE
	end
