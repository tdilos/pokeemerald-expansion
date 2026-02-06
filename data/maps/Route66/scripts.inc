Route66_MapScripts::
	.byte 0

Route66_EventScript_RouteSign::
	msgbox Route66_Text_RouteSign, MSGBOX_SIGN
	end

Route66_Text_RouteSign:
	.string "ROUTE 66\p"
	.string "{UP_ARROW} DUSK MOUNTAIN$"



Route66_EventScript_Glenn::
	trainerbattle_single TRAINER_GLENN, Route66_Text_GlennIntro, Route66_Text_GlennDefeated
	msgbox Route66_Text_GlennPostBattle, MSGBOX_AUTOCLOSE
	end

Route66_EventScript_Yvonne::
	trainerbattle_single TRAINER_YVONNE, Route66_Text_YvonneIntro, Route66_Text_YvonneDefeated
	msgbox Route66_Text_YvonnePostBattle, MSGBOX_AUTOCLOSE
	end

Route66_EventScript_Lester::
	trainerbattle_single TRAINER_LESTER, Route66_Text_LesterIntro, Route66_Text_LesterDefeated
	msgbox Route66_Text_LesterPostBattle, MSGBOX_AUTOCLOSE
	end

