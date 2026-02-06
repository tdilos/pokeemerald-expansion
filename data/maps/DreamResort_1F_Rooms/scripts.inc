.set LOCALID_TRIANGLE6, 1

DreamResort_1F_Rooms_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DreamResort_1F_Rooms_OnTransition
	.byte 0

DreamResort_1F_Rooms_OnTransition::
	goto_if_ge VAR_DREAM_RESORT_STATE, 7, DreamResort_1F_Rooms_Skip
	@goto_if_ge VAR_DREAM_RESORT_STATE, 6, DreamResort_1F_Rooms_HideShard6
	@goto_if_eq VAR_DREAM_RESORT_STATE, 5, DreamResort_1F_Rooms_RevealShard6
	@goto_if_le VAR_DREAM_RESORT_STATE, 4, DreamResort_1F_Rooms_HideShard6
	goto_if_ge VAR_DREAM_RESORT_STATE, 1, DreamResort_1F_Rooms_HideShard6
	goto_if_eq VAR_DREAM_RESORT_STATE, 0, DreamResort_1F_Rooms_RevealShard6
	end

DreamResort_1F_Rooms_Skip::
	end

DreamResort_1F_Rooms_HideShard6::
	removeobject LOCALID_TRIANGLE6
	setflag FLAG_BATTLED_SPIRITOMB
	end

DreamResort_1F_Rooms_RevealShard6::
	addobject LOCALID_TRIANGLE6
	clearflag FLAG_BATTLED_SPIRITOMB
	end

DreamResort_EventScript_Triangle6::
	lockall
	playse SE_RG_DEOXYS_MOVE
	waitse
	delay 20
	removeobject LOCALID_TRIANGLE6
	@setobjectxyperm LOCALID_TRIANGLE6, 56, 0
	@addobject LOCALID_TRIANGLE6
	addvar VAR_DREAM_RESORT_STATE, 1
	setflag FLAG_BATTLED_SPIRITOMB
	releaseall
	end

