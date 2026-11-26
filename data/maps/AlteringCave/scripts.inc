AlteringCave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AlteringCave_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AlteringCave_OnFrame
	.byte 0

AlteringCave_OnTransition:
	setflag FLAG_LANDMARK_ALTERING_CAVE
	call_if_gt VAR_X_COSMOPOLIS_STATE, 1, AlteringCave_EventScript_HideLooker
	end

AlteringCave_EventScript_HideLooker:
	setflag FLAG_HIDE_LOOKER
	return



AlteringCave_OnFrame:
	map_script_2 VAR_X_COSMOPOLIS_STATE, 0, AlteringCave_EventScript_LookerEncounter
	.2byte 0

AlteringCave_EventScript_LookerEncounter::
	lockall
	applymovement LOCALID_ROUTE103_LOOKER, AlteringCave_Movement_LookerWalkToWormhole
	applymovement LOCALID_PLAYER, AlteringCave_Movement_PlayerWalkToWormhole
	waitmovement 0
	delay 60
	applymovement LOCALID_ROUTE103_LOOKER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox AlteringCave_Text_PleaseEnter, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

AlteringCave_Text_PleaseEnter:
	.string "Hard to believe, isn't it?\p"
	.string "INTERPOL first found it here\n"
	.string "a few months ago.\p"
	.string "We're honestly not sure how long\n"
	.string "it's been here.\p"
	.string "This cave has been quiet\n"
	.string "for a long time.\n"
	.string "\p"
	.string "Well go on.\n"
	.string "Step inside.$"

AlteringCave_Movement_LookerWalkToWormhole:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_left
	delay_16
	walk_left
	walk_up
	step_end

AlteringCave_Movement_PlayerWalkToWormhole:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

