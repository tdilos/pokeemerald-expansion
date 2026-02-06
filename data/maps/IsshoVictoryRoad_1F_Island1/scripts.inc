IsshoVictoryRoad_1F_Island1_MapScripts::
	.byte 0

IsshoVictoryRoad_EventScript_SwitchPressed::
	playse SE_SWITCH
	delay 60
	@playse SE_UNLOCK
	@waitse
	return

IsshoVictoryRoad_EventScript_SwitchAlreadyPressed::
	releaseall
	end

IsshoVictoryRoad_1F_Island1_EventScript_Switch::
	lockall
	goto_if_eq VAR_TEMP_1, 100, IsshoVictoryRoad_EventScript_SwitchAlreadyPressed
	call IsshoVictoryRoad_EventScript_SwitchPressed
	setvar VAR_TEMP_1, 100
	setmetatile 15, 7, METATILE_Cave_Floor, FALSE
	setmetatile 15, 8, METATILE_Cave_Floor, FALSE
	special DrawWholeMapView
	playse SE_UNLOCK
	waitse
	releaseall
	end


