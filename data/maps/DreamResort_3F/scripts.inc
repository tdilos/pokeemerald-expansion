.set LOCALID_TRIANGLE2, 1

DreamResort_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DreamResort_3F_OnTransition
	.byte 0

DreamResort_3F_OnTransition::
	goto_if_ge VAR_DREAM_RESORT_STATE, 7, DreamResort_3F_Skip
	@goto_if_ge VAR_DREAM_RESORT_STATE, 2, DreamResort_3F_HideShard2
	@goto_if_eq VAR_DREAM_RESORT_STATE, 1, DreamResort_3F_RevealShard2
	@goto_if_le VAR_DREAM_RESORT_STATE, 0, DreamResort_3F_HideShard2
	goto_if_ge VAR_DREAM_RESORT_STATE, 4, DreamResort_3F_HideShard2
	goto_if_eq VAR_DREAM_RESORT_STATE, 3, DreamResort_3F_RevealShard2
	goto_if_le VAR_DREAM_RESORT_STATE, 2, DreamResort_3F_HideShard2
	end

DreamResort_3F_Skip::
	end

DreamResort_3F_RevealShard2::
	addobject LOCALID_TRIANGLE2
	clearflag FLAG_BATTLED_SPIRITOMB
	end

DreamResort_3F_HideShard2::
	removeobject LOCALID_TRIANGLE2
	setflag FLAG_BATTLED_SPIRITOMB
	end

DreamResort_EventScript_Triangle2::
	lockall
	playse SE_RG_DEOXYS_MOVE
	waitse
	delay 20
	removeobject LOCALID_TRIANGLE2
	@setobjectxyperm LOCALID_TRIANGLE2, 56, 0
	@addobject LOCALID_TRIANGLE2
	addvar VAR_DREAM_RESORT_STATE, 1
	setflag FLAG_BATTLED_SPIRITOMB
	releaseall
	end

