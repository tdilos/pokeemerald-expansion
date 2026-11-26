StationCity_Building1_B1_Hallway_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, StationCity_Building1_B1_Hallway_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, StationCity_Building1_B1_Hallway_OnFrame
	.byte 0

StationCity_Building1_B1_Hallway_OnTransition:
	call StationCity_Building1_B1_Hallway_EventScript_HideLooker
	@call_if_set FLAG_WORMHOLE_MPS, UltraWormhole_EventScript_DoMapPreview
	@call_if_set FLAG_WORMHOLE_MPS, UltraWormhole_EventScript_PauseMusicDuringMPS
	end

StationCity_Building1_B1_Hallway_EventScript_HideLooker:
	setflag FLAG_HIDE_LOOKER
	return

StationCity_Building1_B1_Hallway_OnFrame:
	map_script_2 VAR_X_COSMOPOLIS_STATE, 0, StationCity_Building1_B1_Hallway_EventScript_LookerIntro
	.2byte 0

StationCity_Building1_B1_Hallway_EventScript_LookerIntro::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	delay 60
	clearflag FLAG_HIDE_LOOKER
	addobject LOCALID_LOOKER_HALLWAY
	applymovement LOCALID_LOOKER_HALLWAY, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_LOOKER_HALLWAY, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox StationCity_Building1_B1_Hallway_Text_LookerIntro1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LOOKER_HALLWAY, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_LOOKER_HALLWAY, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCALID_LOOKER_HALLWAY, Common_Movement_FaceRight
	waitmovement 0
	msgbox StationCity_Building1_B1_Hallway_Text_LookerIntro1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft
	applymovement LOCALID_LOOKER_HALLWAY, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	applymovement LOCALID_LOOKER_HALLWAY, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	applymovement LOCALID_LOOKER_HALLWAY, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	applymovement LOCALID_LOOKER_HALLWAY, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	applymovement LOCALID_LOOKER_HALLWAY, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	applymovement LOCALID_LOOKER_HALLWAY, Common_Movement_WalkRight
	waitmovement 0
	removeobject LOCALID_LOOKER_HALLWAY
	applymovement LOCALID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 30
	warp MAP_STATION_CITY_BUILDING1_B1, 5, 1
	waitstate
	releaseall
	end

StationCity_Building1_B1_Hallway_Text_LookerIntro1:
	.string "A little disorienting, isn't it?\p"
	.string "You'll get used to it.$"

StationCity_Building1_B1_Hallway_Text_LookerIntro2:
	.string "Come, let's introduce you to everyone.$"





