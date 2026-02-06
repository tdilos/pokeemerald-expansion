Sandshraf_B1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Sandshraf_B1_OnTransition
	@map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	@map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	@map_script MAP_SCRIPT_ON_RESUME, Sandshraf_B1_SetHoleWarp
	.byte 0

Sandshraf_B1_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_SANDSHRAF_B2
	end


Sandshraf_B1_OnTransition:
	@from CaveHole_FixCrackedGround
	@copyvar VAR_ICE_STEP_COUNT, 1

	goto_if_eq VAR_CYCLING_CHALLENGE_STATE, 3, Sandshraf_B1_EventScript_RestartChallenge
	goto_if_eq VAR_CYCLING_CHALLENGE_STATE, 2, Sandshraf_B1_EventScript_RestartChallenge
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_38
	goto_if_eq VAR_RESULT, TRUE, Sandshraf_B1_EventScript_RestartChallenge	
	end

Sandshraf_B1_EventScript_RestartChallenge::
	setvar VAR_CYCLING_CHALLENGE_STATE, 1
	end








Sandshraf_EventScript_Wilma::
	trainerbattle_single TRAINER_WILMA, Sandshraf_Text_WilmaIntro, Sandshraf_Text_WilmaDefeated
	msgbox Sandshraf_Text_WilmaPostBattle, MSGBOX_AUTOCLOSE
	end

