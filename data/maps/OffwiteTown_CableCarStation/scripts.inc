.set LOCALID_ATTENDANT, 1

OffwiteTown_CableCarStation_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OffwiteTown_CableCarStation_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OffwiteTown_CableCarStation_OnFrame
	.byte 0

OffwiteTown_CableCarStation_OnTransition:
	call_if_eq VAR_CABLE_CAR_STATION_STATE, 1, OffwiteTown_CableCarStation_EventScript_MoveAttendantAside
	end

OffwiteTown_CableCarStation_EventScript_MoveAttendantAside::
	setobjectxyperm LOCALID_ATTENDANT, 5, 4
	setobjectmovementtype LOCALID_ATTENDANT, MOVEMENT_TYPE_FACE_RIGHT
	return

OffwiteTown_CableCarStation_OnFrame:
	map_script_2 VAR_CABLE_CAR_STATION_STATE, 1, OffwiteTown_CableCarStation_EventScript_ExitCableCar
	.2byte 0

OffwiteTown_CableCarStation_EventScript_ExitCableCar::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, OffwiteTown_CableCarStation_Movement_ExitCableCar
	applymovement LOCALID_ATTENDANT, OffwiteTown_CableCarStation_Movement_FollowPlayerOutFromCableCar
	waitmovement 0
	setvar VAR_CABLE_CAR_STATION_STATE, 0
	setobjectxyperm LOCALID_ATTENDANT, 6, 7
	setobjectmovementtype LOCALID_ATTENDANT, MOVEMENT_TYPE_FACE_DOWN
	releaseall
	end






OffwiteTown_CableCarStation_EventScript_Attendant::
	lock
	faceplayer
	msgbox OffwiteTown_CableCarStation_Text_NeedPermission, MSGBOX_DEFAULT
	checkitem ITEM_WINTER_EMBLEM
	goto_if_eq VAR_RESULT, TRUE, OffwiteTown_CableCarStation_EventScript_OfferRide
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0	
	release
	end

OffwiteTown_CableCarStation_EventScript_OfferRide::
	playse SE_PIN
	applymovement LOCALID_ATTENDANT, Common_Movement_ExclamationMark
	waitmovement 0
	delay 30
	msgbox OffwiteTown_CableCarStation_Text_CableCarReadyGetOn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, OffwiteTown_CableCarStation_EventScript_RideCableCar
	goto_if_eq VAR_RESULT, NO, OffwiteTown_CableCarStation_EventScript_DeclineRide
	end

OffwiteTown_CableCarStation_EventScript_RideCableCar::
	msgbox OffwiteTown_CableCarStation_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ATTENDANT, OffwiteTown_CableCarStation_Movement_LeadPlayerToCableCar
	applymovement OBJ_EVENT_ID_PLAYER, OffwiteTown_CableCarStation_Movement_BoardCableCar
	waitmovement 0
	setvar VAR_0x8004, TRUE  @ Going down
	setvar VAR_CABLE_CAR_STATION_STATE, 2
	incrementgamestat GAME_STAT_RODE_CABLE_CAR
	special CableCarIsshoWarp
	special CableCar
	waitstate
	release
	end

OffwiteTown_CableCarStation_EventScript_DeclineRide::
	release
	end

OffwiteTown_CableCarStation_Movement_LeadPlayerToCableCar:
	walk_up
	walk_up
	walk_left
	walk_in_place_faster_right
	step_end

OffwiteTown_CableCarStation_Movement_FollowPlayerOutFromCableCar:
	delay_16
	walk_right
	walk_down
	walk_down
	step_end

OffwiteTown_CableCarStation_Movement_BoardCableCar:
	walk_up
	walk_up
	walk_up
	delay_16
	step_end

OffwiteTown_CableCarStation_Movement_ExitCableCar:
	walk_down
	walk_down
	walk_down
	delay_16
	step_end

OffwiteTown_CableCarStation_Text_NeedPermission:
	.string "I'm sorry. This lift is off limits\n"
	.string "to the general public.$" 

OffwiteTown_CableCarStation_Text_CableCarReadyGetOn:
	.string "Oh, that's a SNOW EMBLEM.\p"
	.string "In that case, would you like\n"
	.string "to ride the ski lift?$"

OffwiteTown_CableCarStation_Text_StepThisWay:
	.string "Please step this way.$"




