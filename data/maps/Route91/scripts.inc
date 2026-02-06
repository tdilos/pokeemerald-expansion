@.set LOCALID_BATTLE_GIRL, 1

Route91_MapScripts::
	@map_script MAP_SCRIPT_ON_TRANSITION, Route91_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route91_OnWarp
	.byte 0

Route91_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, Route91_EventScript_UnsetForceOffscreenLoad
	.2byte 0

Route91_EventScript_UnsetForceOffscreenLoad::
	clearflag FLAG_FORCE_LOAD_OFFSCREEN_OBJEV
	end

@Route91_OnTransition:
@	playse SE_DOOR
@	special ForceReloadMap
@	end


@	special DrawWholeMapView
@	return

Route91_EventScript_ForcedReload1::
	@playse SE_EXIT
	@special ForceReloadMap
	@setvar VAR_TEMP_0, 1
	warpsilent MAP_ROUTE91, 0, 15
	waitstate
	end

Route91_EventScript_ForcedReload2::
	warpsilent MAP_ROUTE91, 0, 16
	waitstate
	end

Route91_EventScript_ForcedReload3::
	warpsilent MAP_ROUTE91, 0, 17
	waitstate
	end



Route91_EventScript_RouteSign::
	msgbox Route91_Text_RouteSign, MSGBOX_SIGN
	end

Route91_Text_RouteSign:
	.string "ROUTE 91\p"
	.string "{UP_ARROW} PITCHBLAK CITY\n"
	.string "{LEFT_ARROW} SCARLET TOWN$"

Route91_EventScript_Holly::
	trainerbattle_single TRAINER_HOLLY, Route91_Text_HollyIntro, Route91_Text_HollyDefeated
	msgbox Route91_Text_HollyPostBattle, MSGBOX_AUTOCLOSE
	end

Route91_EventScript_Sousuke::
	trainerbattle_single TRAINER_SOUSUKE, Route91_Text_SousukeIntro, Route91_Text_SousukeDefeated
	msgbox Route91_Text_SousukePostBattle, MSGBOX_AUTOCLOSE
	end

Route91_EventScript_Eiichiro::
	trainerbattle_single TRAINER_EIICHIRO, Route91_Text_EiichiroIntro, Route91_Text_EiichiroDefeated
	msgbox Route91_Text_EiichiroPostBattle, MSGBOX_AUTOCLOSE
	end

Route91_EventScript_Percival::
	trainerbattle_single TRAINER_PERCIVAL, Route91_Text_PercivalIntro, Route91_Text_PercivalDefeated
	msgbox Route91_Text_PercivalPostBattle, MSGBOX_AUTOCLOSE
	end

Route91_EventScript_Macy::
	trainerbattle_single TRAINER_MACY, Route91_Text_MacyIntro, Route91_Text_MacyDefeated
	msgbox Route91_Text_MacyPostBattle, MSGBOX_AUTOCLOSE
	end

Route91_EventScript_Hayao::
	trainerbattle_single TRAINER_HAYAO, Route91_Text_HayaoIntro, Route91_Text_HayaoDefeated
	msgbox Route91_Text_HayaoPostBattle, MSGBOX_AUTOCLOSE
	end

Route91_EventScript_Yoshi::
	trainerbattle_single TRAINER_YOSHI, Route91_Text_YoshiIntro, Route91_Text_YoshiDefeated
	msgbox Route91_Text_YoshiPostBattle, MSGBOX_AUTOCLOSE
	end

