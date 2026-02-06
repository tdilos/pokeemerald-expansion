Route85_MapScripts::
	.byte 0

Route85_EventScript_Tyson::
	trainerbattle_single TRAINER_TYSON, Route85_Text_TysonIntro, Route85_Text_TysonDefeated
	msgbox Route85_Text_TysonPostBattle, MSGBOX_AUTOCLOSE
	end

Route85_EventScript_Maddy::
	trainerbattle_single TRAINER_MADDY, Route85_Text_MaddyIntro, Route85_Text_MaddyDefeated
	msgbox Route85_Text_MaddyPostBattle, MSGBOX_AUTOCLOSE
	end

Route85_EventScript_Cletus::
	trainerbattle_single TRAINER_CLETUS, Route85_Text_CletusIntro, Route85_Text_CletusDefeated
	msgbox Route85_Text_CletusPostBattle, MSGBOX_AUTOCLOSE
	end

Route85_EventScript_Avery::
	trainerbattle_single TRAINER_AVERY, Route85_Text_AveryIntro, Route85_Text_AveryDefeated
	msgbox Route85_Text_AveryPostBattle, MSGBOX_AUTOCLOSE
	end

Route85_EventScript_Liam::
	trainerbattle_single TRAINER_LIAM, Route85_Text_LiamIntro, Route85_Text_LiamDefeated
	msgbox Route85_Text_LiamPostBattle, MSGBOX_AUTOCLOSE
	end

Route85_EventScript_Olympia::
	trainerbattle_single TRAINER_OLYMPIA, Route85_Text_OlympiaIntro, Route85_Text_OlympiaDefeated
	msgbox Route85_Text_OlympiaPostBattle, MSGBOX_AUTOCLOSE
	end

Route85_EventScript_Daniel::
	trainerbattle_single TRAINER_DANIEL, Route85_Text_DanielIntro, Route85_Text_DanielDefeated
	msgbox Route85_Text_DanielPostBattle, MSGBOX_AUTOCLOSE
	end

Route85_EventScript_RouteSign::
	msgbox Route85_Text_RouteSign, MSGBOX_SIGN
	end

Route85_Text_RouteSign:
	.string "ROUTE 85\p"
	.string "{UP_ARROW} AMBER CITY$"


