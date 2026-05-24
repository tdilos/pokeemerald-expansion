AlteringCave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AlteringCave_OnTransition
	.byte 0

AlteringCave_OnTransition:
	setflag FLAG_LANDMARK_ALTERING_CAVE
	end



AlteringCave_EventScript_UltraWormhole::
	lock
	msgbox AlteringCave_Text_UltraWormhole, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, AlteringCave_EventScript_Skip
	warp MAP_STATION_CITY_BUILDING1_B1, 5, 4
	waitstate
	release
	end

AlteringCave_EventScript_Skip::
	release
	end

AlteringCave_Text_UltraWormhole:
	.string "It's a large wormhole.\n"
	.string "Step inside?$"

