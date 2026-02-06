IsshoVictoryRoad_1F_Island3_MapScripts::
	.byte 0


IsshoVictoryRoad_1F_Island3_EventScript_Switch::
	lockall
	goto_if_eq VAR_TEMP_1, 100, IsshoVictoryRoad_EventScript_SwitchAlreadyPressed
	call IsshoVictoryRoad_EventScript_SwitchPressed
	setvar VAR_TEMP_1, 100
	setmetatile 19, 4, METATILE_Cave_RaisedFloor, FALSE
	setmetatile 19, 5, METATILE_Cave_RaisedFloor, FALSE
	special DrawWholeMapView
	playse SE_UNLOCK
	waitse
	releaseall
	end


