.set LOCALID_TRIANGLE1, 1

DreamResort_4F_Rooms_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DreamResort_4F_Rooms_OnTransition
	.byte 0

DreamResort_4F_Rooms_OnTransition::
	goto_if_ge VAR_DREAM_RESORT_STATE, 7, DreamResort_4F_Rooms_Skip
	@goto_if_ge VAR_DREAM_RESORT_STATE, 1, DreamResort_4F_Rooms_HideShard1
	@goto_if_eq VAR_DREAM_RESORT_STATE, 0, DreamResort_4F_Rooms_RevealShard1
	goto_if_ge VAR_DREAM_RESORT_STATE, 2, DreamResort_4F_Rooms_HideShard1
	goto_if_eq VAR_DREAM_RESORT_STATE, 1, DreamResort_4F_Rooms_RevealShard1
	goto_if_le VAR_DREAM_RESORT_STATE, 0, DreamResort_4F_Rooms_HideShard1
	end

DreamResort_4F_Rooms_Skip::
	end

DreamResort_4F_Rooms_RevealShard1::
	addobject LOCALID_TRIANGLE1
	clearflag FLAG_BATTLED_SPIRITOMB
	end

DreamResort_4F_Rooms_HideShard1::
	removeobject LOCALID_TRIANGLE1
	setflag FLAG_BATTLED_SPIRITOMB
	end

DreamResort_EventScript_Triangle1::
	lockall
	playse SE_RG_DEOXYS_MOVE
	waitse
	delay 20
	removeobject LOCALID_TRIANGLE1
	@setobjectxyperm LOCALID_TRIANGLE1, 56, 0
	@addobject LOCALID_TRIANGLE1
	addvar VAR_DREAM_RESORT_STATE, 1
	setflag FLAG_BATTLED_SPIRITOMB
	releaseall
	end
