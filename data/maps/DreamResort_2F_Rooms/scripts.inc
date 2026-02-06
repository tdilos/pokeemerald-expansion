.set LOCALID_TRIANGLE4, 1
@.set LOCALID_TRIANGLE5, 2

DreamResort_2F_Rooms_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DreamResort_2F_Rooms_OnTransition
	.byte 0

DreamResort_2F_Rooms_OnTransition::
	goto_if_ge VAR_DREAM_RESORT_STATE, 7, DreamResort_2F_Rooms_Skip
	@goto_if_ge VAR_DREAM_RESORT_STATE, 4, DreamResort_2F_Rooms_HideShard4
	@goto_if_eq VAR_DREAM_RESORT_STATE, 3, DreamResort_2F_Rooms_RevealShard4
	@goto_if_le VAR_DREAM_RESORT_STATE, 2, DreamResort_2F_Rooms_HideShard4
	goto_if_ge VAR_DREAM_RESORT_STATE, 6, DreamResort_2F_Rooms_HideShard4
	goto_if_eq VAR_DREAM_RESORT_STATE, 5, DreamResort_2F_Rooms_RevealShard4
	goto_if_le VAR_DREAM_RESORT_STATE, 4, DreamResort_2F_Rooms_HideShard4
	end

DreamResort_2F_Rooms_Skip::
	end

DreamResort_2F_Rooms_HideShard4::
	removeobject LOCALID_TRIANGLE4
	setflag FLAG_BATTLED_SPIRITOMB
	end

DreamResort_2F_Rooms_RevealShard4::
	addobject LOCALID_TRIANGLE4
	clearflag FLAG_BATTLED_SPIRITOMB
	end

DreamResort_EventScript_Triangle4::
	lockall
	playse SE_RG_DEOXYS_MOVE
	waitse
	delay 20
	removeobject LOCALID_TRIANGLE4
	@setobjectxyperm LOCALID_TRIANGLE4, 56, 0
	@addobject LOCALID_TRIANGLE4
	addvar VAR_DREAM_RESORT_STATE, 1
	setflag FLAG_BATTLED_SPIRITOMB
	releaseall
	end

@DreamResort_EventScript_Triangle5::
@	lockall
@	playse SE_RG_DEOXYS_MOVE
@	waitse
@	delay 20
@	removeobject LOCALID_TRIANGLE5
@	@setobjectxyperm LOCALID_TRIANGLE5, 56, 0
@	@addobject LOCALID_TRIANGLE5
@	addvar VAR_DREAM_RESORT_STATE, 1
@	clearflag FLAG_BATTLED_SPIRITOMB
@	releaseall
@	end




