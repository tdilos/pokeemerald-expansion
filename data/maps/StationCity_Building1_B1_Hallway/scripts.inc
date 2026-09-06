StationCity_Building1_B1_Hallway_MapScripts::
	@map_script MAP_SCRIPT_ON_TRANSITION, StationCity_Building1_B1_Hallway_OnTransition
	.byte 0

StationCity_Building1_B1_Hallway_OnTransition:
	@call_if_set FLAG_WORMHOLE_MPS, UltraWormhole_EventScript_DoMapPreview
	@call_if_set FLAG_WORMHOLE_MPS, UltraWormhole_EventScript_PauseMusicDuringMPS
	end







