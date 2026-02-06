Route71_MapScripts::
	.byte 0

Route71_EventScript_Shanks::
	trainerbattle_single TRAINER_SHANKS, Route71_Text_ShanksIntro, Route71_Text_ShanksDefeated
	msgbox Route71_Text_ShanksPostBattle, MSGBOX_AUTOCLOSE
	end

Route71_EventScript_Cadmon::
	trainerbattle_single TRAINER_CADMON, Route71_Text_CadmonIntro, Route71_Text_CadmonDefeated
	msgbox Route71_Text_CadmonPostBattle, MSGBOX_AUTOCLOSE
	end

Route71_EventScript_Bailey::
	trainerbattle_single TRAINER_BAILEY, Route71_Text_BaileyIntro, Route71_Text_BaileyDefeated
	msgbox Route71_Text_BaileyPostBattle, MSGBOX_AUTOCLOSE
	end

Route71_EventScript_Kelly::
	trainerbattle_single TRAINER_KELLY, Route71_Text_KellyIntro, Route71_Text_KellyDefeated
	msgbox Route71_Text_KellyPostBattle, MSGBOX_AUTOCLOSE
	end

Route71_EventScript_Jake::
	trainerbattle_single TRAINER_JAKE, Route71_Text_JakeIntro, Route71_Text_JakeDefeated
	msgbox Route71_Text_JakePostBattle, MSGBOX_AUTOCLOSE
	end







