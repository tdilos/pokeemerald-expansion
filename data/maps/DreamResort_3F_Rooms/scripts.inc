@.set LOCALID_TRIANGLE2, 1
.set LOCALID_TRIANGLE3, 1

DreamResort_3F_Rooms_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DreamResort_3F_Rooms_OnTransition
	.byte 0

DreamResort_3F_Rooms_OnTransition::
	goto_if_ge VAR_DREAM_RESORT_STATE, 7, DreamResort_3F_Rooms_Skip
	@goto_if_ge VAR_DREAM_RESORT_STATE, 3, DreamResort_3F_Rooms_HideShard3
	@goto_if_eq VAR_DREAM_RESORT_STATE, 2, DreamResort_3F_Rooms_RevealShard3
	@goto_if_le VAR_DREAM_RESORT_STATE, 1, DreamResort_3F_Rooms_HideShard3
	goto_if_ge VAR_DREAM_RESORT_STATE, 5, DreamResort_3F_Rooms_HideShard3
	goto_if_eq VAR_DREAM_RESORT_STATE, 4, DreamResort_3F_Rooms_RevealShard3
	goto_if_le VAR_DREAM_RESORT_STATE, 3, DreamResort_3F_Rooms_HideShard3
	end

DreamResort_3F_Rooms_Skip::
	end

DreamResort_3F_Rooms_HideShard3::
	removeobject LOCALID_TRIANGLE3
	setflag FLAG_BATTLED_SPIRITOMB
	end

DreamResort_3F_Rooms_RevealShard3::
	addobject LOCALID_TRIANGLE3
	clearflag FLAG_BATTLED_SPIRITOMB
	end

DreamResort_EventScript_Triangle3::
	lockall
	playse SE_RG_DEOXYS_MOVE
	waitse
	delay 20
	removeobject LOCALID_TRIANGLE3
	@setobjectxyperm LOCALID_TRIANGLE3, 56, 0
	@addobject LOCALID_TRIANGLE3
	addvar VAR_DREAM_RESORT_STATE, 1
	setflag FLAG_BATTLED_SPIRITOMB
	releaseall
	end


@DreamResort_EventScript_Triangle2::
@	lockall
@	playse SE_RG_DEOXYS_MOVE
@	waitse
@	delay 20
@	removeobject LOCALID_TRIANGLE2
@	setobjectxyperm LOCALID_TRIANGLE2, 28, 0
@	addvar VAR_DREAM_RESORT_STATE, 1
@	addobject LOCALID_TRIANGLE2
@	clearflag FLAG_BATTLED_SPIRITOMB
@	releaseall
@	end

