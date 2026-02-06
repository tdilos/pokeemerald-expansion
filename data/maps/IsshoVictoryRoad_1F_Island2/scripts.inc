IsshoVictoryRoad_1F_Island2_MapScripts::
	.byte 0

IsshoVictoryRoad_1F_Island2_EventScript_Switch1::
	lockall
	goto_if_eq VAR_TEMP_1, 100, IsshoVictoryRoad_EventScript_SwitchAlreadyPressed
	call IsshoVictoryRoad_EventScript_SwitchPressed
	setvar VAR_TEMP_1, 100
	setmetatile 8, 17, METATILE_Cave_Floor, FALSE
	setmetatile 8, 18, METATILE_Cave_Floor, FALSE
	special DrawWholeMapView
	playse SE_UNLOCK
	waitse
	releaseall
	end

IsshoVictoryRoad_1F_Island2_EventScript_Switch2::
	lockall
	goto_if_eq VAR_TEMP_2, 100, IsshoVictoryRoad_EventScript_SwitchAlreadyPressed
	call IsshoVictoryRoad_EventScript_SwitchPressed
	setvar VAR_TEMP_2, 100
	setmetatile 20, 1, METATILE_Cave_Floor, FALSE
	setmetatile 20, 2, METATILE_Cave_Floor, FALSE
	special DrawWholeMapView
	playse SE_UNLOCK
	waitse
	releaseall
	end

