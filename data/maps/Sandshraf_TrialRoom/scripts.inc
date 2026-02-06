Sandshraf_TrialRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	@map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_TRANSITION, Sandshraf_TrialRoom_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Sandshraf_TrialRoom_SetHoleWarp
	.byte 0

Sandshraf_TrialRoom_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_SANDSHRAF_B2
	end

Sandshraf_TrialRoom_OnTransition:
	setvar VAR_CYCLING_CHALLENGE_STATE, 0
	goto CaveHole_FixCrackedGround
	end


