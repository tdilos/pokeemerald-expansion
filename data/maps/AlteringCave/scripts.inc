AlteringCave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AlteringCave_OnTransition
	.byte 0

AlteringCave_OnTransition:
	setflag FLAG_LANDMARK_ALTERING_CAVE
	call_if_gt VAR_SLATEPORT_CITY_STATE, 7, AlteringCave_EventScript_HideLooker
	end

AlteringCave_EventScript_HideLooker:
	setflag FLAG_HIDE_LOOKER
	return

