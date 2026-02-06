IsshoVictoryRoad_B2_MapScripts::
	.byte 0


IsshoVictoryRoad_B2_EventScript_Switch1::
	lockall
	goto_if_eq VAR_TEMP_1, 100, IsshoVictoryRoad_EventScript_SwitchAlreadyPressed
	call IsshoVictoryRoad_EventScript_SwitchPressed
	setvar VAR_TEMP_1, 100
	setmetatile 69, 23, METATILE_Cave_RaisedFloor_Ledge, FALSE
	setmetatile 69, 24, METATILE_Cave_RaisedFloor, FALSE
	special DrawWholeMapView
	playse SE_UNLOCK
	waitse
	releaseall
	end

IsshoVictoryRoad_B2_EventScript_Switch2::
	lockall
	goto_if_eq VAR_TEMP_2, 100, IsshoVictoryRoad_EventScript_SwitchAlreadyPressed
	call IsshoVictoryRoad_EventScript_SwitchPressed
	setvar VAR_TEMP_2, 100
	setmetatile 71, 23, METATILE_Cave_RaisedFloor_Ledge, FALSE
	setmetatile 71, 24, METATILE_Cave_RaisedFloor, FALSE
	special DrawWholeMapView
	playse SE_UNLOCK
	waitse
	releaseall
	end

IsshoVictoryRoad_B2_EventScript_Switch3::
	lockall
	goto_if_eq VAR_TEMP_3, 100, IsshoVictoryRoad_EventScript_SwitchAlreadyPressed
	call IsshoVictoryRoad_EventScript_SwitchPressed
	setvar VAR_TEMP_3, 100
	setmetatile 73, 23, METATILE_Cave_RaisedFloor_Ledge, FALSE
	setmetatile 73, 24, METATILE_Cave_RaisedFloor, FALSE
	special DrawWholeMapView
	playse SE_UNLOCK
	waitse
	releaseall
	end


IsshoVictoryRoad_B2_EventScript_Switch4::
	lockall
	goto_if_eq VAR_TEMP_4, 100, IsshoVictoryRoad_EventScript_SwitchAlreadyPressed
	call IsshoVictoryRoad_EventScript_SwitchPressed
	setvar VAR_TEMP_4, 100
	setmetatile 75, 23, METATILE_Cave_RaisedFloor, FALSE
	setmetatile 75, 24, METATILE_Cave_RaisedFloor, FALSE
	special DrawWholeMapView
	playse SE_UNLOCK
	waitse
	releaseall
	end

IsshoVictoryRoad_B2_EventScript_Switch5::
	lockall
	goto_if_eq VAR_TEMP_5, 100, IsshoVictoryRoad_EventScript_SwitchAlreadyPressed
	call IsshoVictoryRoad_EventScript_SwitchPressed
	setvar VAR_TEMP_5, 100
	setmetatile 77, 23, METATILE_Cave_RaisedFloor, FALSE
	setmetatile 77, 24, METATILE_Cave_RaisedFloor, FALSE
	special DrawWholeMapView
	playse SE_UNLOCK
	waitse
	releaseall
	end

IsshoVictoryRoad_B2_EventScript_Switch6::
	lockall
	goto_if_eq VAR_TEMP_6, 100, IsshoVictoryRoad_EventScript_SwitchAlreadyPressed
	call IsshoVictoryRoad_EventScript_SwitchPressed
	setvar VAR_TEMP_6, 100
	setmetatile 79, 23, METATILE_Cave_RaisedFloor, FALSE
	setmetatile 79, 24, METATILE_Cave_RaisedFloor, FALSE
	special DrawWholeMapView
	playse SE_UNLOCK
	waitse
	releaseall
	end

IsshoVictoryRoad_B2_EventScript_Switch7::
	lockall
	goto_if_eq VAR_TEMP_7, 100, IsshoVictoryRoad_EventScript_SwitchAlreadyPressed
	call IsshoVictoryRoad_EventScript_SwitchPressed
	setvar VAR_TEMP_7, 100
	setmetatile 80, 44, METATILE_Cave_Floor, FALSE
	setmetatile 80, 45, METATILE_Cave_Floor, FALSE
	special DrawWholeMapView
	playse SE_UNLOCK
	waitse
	releaseall
	end


