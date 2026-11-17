Route66_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route66_OnTransition
	.byte 0

Route66_OnTransition:
	goto_if_unset FLAG_IS_CHAMPION, Route66_EventScript_HideWormhole
	@goto_if_set FLAG_BATTLED_YVELTAL, Route66_EventScript_HideWormhole
	clearflag FLAG_HIDE_WORMHOLE_YVELTAL
	end

Route66_EventScript_HideWormhole:
	setflag FLAG_HIDE_WORMHOLE_YVELTAL
	end


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

