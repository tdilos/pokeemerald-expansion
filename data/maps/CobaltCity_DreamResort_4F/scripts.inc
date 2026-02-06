CobaltCity_DreamResort_4F_MapScripts::
	.byte 0

DreamResort_EventScript_LockedDoor::
	msgbox DreamResort_Text_LockedDoor, MSGBOX_DEFAULT
	closemessage
	end

DreamResort_Text_LockedDoor:
	.string "This door appears to be locked.$"

DreamResort_EventScript_CursedDoor::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox DreamResort_Text_CursedDoor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DreamResort_EventScript_GoToCursedRoom
	closemessage
	releaseall
	end

DreamResort_Text_CursedDoor:
	.string "Something's off about this door.\n"
	.string "Will you go inside?$"

DreamResort_EventScript_GoToCursedRoom::
	warp MAP_DREAM_RESORT_4F, 27, 4
	waitstate
	releaseall
	end

