Route67_MapScripts::
	.byte 0

Route67_EventScript_Buzz::
	trainerbattle_single TRAINER_BUZZ, Route67_Text_BuzzIntro, Route67_Text_BuzzDefeated
	msgbox Route67_Text_BuzzPostBattle, MSGBOX_AUTOCLOSE
	end

Route67_EventScript_Zed::
	trainerbattle_single TRAINER_ZED, Route67_Text_ZedIntro, Route67_Text_ZedDefeated
	msgbox Route67_Text_ZedPostBattle, MSGBOX_AUTOCLOSE
	end

Route67_EventScript_Yuri::
	trainerbattle_single TRAINER_YURI, Route67_Text_YuriIntro, Route67_Text_YuriDefeated
	msgbox Route67_Text_YuriPostBattle, MSGBOX_AUTOCLOSE
	end

Route67_EventScript_Velma::
	trainerbattle_single TRAINER_VELMA, Route67_Text_VelmaIntro, Route67_Text_VelmaDefeated
	msgbox Route67_Text_VelmaPostBattle, MSGBOX_AUTOCLOSE
	end

Route67_EventScript_Faye::
	trainerbattle_single TRAINER_FAYE, Route67_Text_FayeIntro, Route67_Text_FayeDefeated
	msgbox Route67_Text_FayePostBattle, MSGBOX_AUTOCLOSE
	end

