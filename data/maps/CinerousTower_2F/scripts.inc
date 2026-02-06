CinerousTower_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	@map_script MAP_SCRIPT_ON_TRANSITION, CinerousTower_2F_OnTransition
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, CinerousTower_2F_SetHoleWarp
	.byte 0

@CinerousTower_2F_OnTransition:
@	copyvar VAR_ICE_STEP_COUNT, 1
@	end

CinerousTower_2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_CINEROUS_TOWER_1F
	end
