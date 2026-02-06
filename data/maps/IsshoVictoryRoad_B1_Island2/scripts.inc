IsshoVictoryRoad_B1_Island2_MapScripts::
	.byte 0



IsshoVictoryRoad_B1_Island2_EventScript_Switch::
	lockall
	goto_if_eq VAR_TEMP_1, 100, IsshoVictoryRoad_EventScript_SwitchAlreadyPressed
	call IsshoVictoryRoad_EventScript_SwitchPressed
	setvar VAR_TEMP_1, 100
	setmetatile 17, 13, METATILE_Cave_RaisedFloor_Ledge, FALSE
	setmetatile 17, 14, METATILE_Cave_RaisedFloor, FALSE
	special DrawWholeMapView
	playse SE_UNLOCK
	waitse
	releaseall
	end


