IsshoVictoryRoad_B1_Island4_MapScripts::
	.byte 0

IsshoVictoryRoad_B1_Island4_EventScript_Switch1::
	lockall
	goto_if_eq VAR_TEMP_1, 100, IsshoVictoryRoad_EventScript_SwitchAlreadyPressed
	call IsshoVictoryRoad_EventScript_SwitchPressed
	setvar VAR_TEMP_1, 100
	setmetatile 19, 1, METATILE_Cave_Floor, FALSE
	setmetatile 19, 2, METATILE_Cave_Floor, FALSE
	special DrawWholeMapView
	playse SE_UNLOCK
	waitse
	releaseall
	end

IsshoVictoryRoad_B1_Island4_EventScript_Switch2::
	lockall
	goto_if_eq VAR_TEMP_2, 100, IsshoVictoryRoad_EventScript_SwitchAlreadyPressed
	call IsshoVictoryRoad_EventScript_SwitchPressed
	setvar VAR_TEMP_2, 100
	setmetatile 21, 1, METATILE_Cave_Floor, FALSE
	setmetatile 21, 2, METATILE_Cave_Floor, FALSE
	special DrawWholeMapView
	playse SE_UNLOCK
	waitse
	releaseall
	end

IsshoVictoryRoad_B1_Island4_EventScript_Switch3::
	lockall
	goto_if_eq VAR_TEMP_3, 100, IsshoVictoryRoad_EventScript_SwitchAlreadyPressed
	call IsshoVictoryRoad_EventScript_SwitchPressed
	setvar VAR_TEMP_3, 100
	setmetatile 15, 16, METATILE_Cave_Floor, FALSE
	setmetatile 15, 17, METATILE_Cave_Floor, FALSE
	special DrawWholeMapView
	playse SE_UNLOCK
	waitse
	releaseall
	end






