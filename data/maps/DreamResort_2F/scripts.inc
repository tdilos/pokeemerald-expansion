.set LOCALID_TRIANGLE5, 1

DreamResort_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DreamResort_2F_OnTransition
	.byte 0

DreamResort_2F_OnTransition::
	goto_if_ge VAR_DREAM_RESORT_STATE, 7, DreamResort_2F_Skip
	@goto_if_ge VAR_DREAM_RESORT_STATE, 5, DreamResort_2F_HideShard5
	@goto_if_eq VAR_DREAM_RESORT_STATE, 4, DreamResort_2F_RevealShard5
	@goto_if_le VAR_DREAM_RESORT_STATE, 3, DreamResort_2F_HideShard5
	goto_if_ge VAR_DREAM_RESORT_STATE, 3, DreamResort_2F_HideShard5
	goto_if_eq VAR_DREAM_RESORT_STATE, 2, DreamResort_2F_RevealShard5
	goto_if_le VAR_DREAM_RESORT_STATE, 1, DreamResort_2F_HideShard5
	end

DreamResort_2F_Skip::
	end

DreamResort_2F_HideShard5::
	removeobject LOCALID_TRIANGLE5
	setflag FLAG_BATTLED_SPIRITOMB
	end

DreamResort_2F_RevealShard5::
	addobject LOCALID_TRIANGLE5
	clearflag FLAG_BATTLED_SPIRITOMB
	end

DreamResort_EventScript_Triangle5::
	lockall
	playse SE_RG_DEOXYS_MOVE
	waitse
	delay 20
	removeobject LOCALID_TRIANGLE5
	@setobjectxyperm LOCALID_TRIANGLE5, 56, 0
	@addobject LOCALID_TRIANGLE5
	addvar VAR_DREAM_RESORT_STATE, 1
	setflag FLAG_BATTLED_SPIRITOMB
	releaseall
	end
