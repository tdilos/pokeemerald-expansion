IsshoVictoryRoad_1F_Island4_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, IsshoVictoryRoad_1F_Island4_OnWarp
	.byte 0

IsshoVictoryRoad_1F_Island4_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, IsshoVictoryRoad_1F_Island4_EventScript_SetForceOffscreenLoad
	.2byte 0

IsshoVictoryRoad_1F_Island4_EventScript_SetForceOffscreenLoad::
	setflag FLAG_FORCE_LOAD_OFFSCREEN_OBJEV
	end


IsshoVictoryRoad_1F_Island4_EventScript_Switch::
	lockall
	goto_if_eq VAR_TEMP_1, 100, IsshoVictoryRoad_EventScript_SwitchAlreadyPressed
	call IsshoVictoryRoad_EventScript_SwitchPressed
	setvar VAR_TEMP_1, 100
	setmetatile 5, 26, METATILE_Cave_Floor, FALSE
	setmetatile 5, 27, METATILE_Cave_Floor, FALSE
	special DrawWholeMapView
	playse SE_UNLOCK
	waitse
	releaseall
	end


