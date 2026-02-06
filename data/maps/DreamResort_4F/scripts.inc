DreamResort_4F_MapScripts::
	.byte 0

DreamResort_EventScript_ExitToHotel::
	lockall
	msgbox DreamResort_Text_ExitToHotel, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DreamResort_EventScript_ReturnToHotel
	releaseall
	end

DreamResort_Text_ExitToHotel:
	.string "Light is coming from beneath this door.\n"
	.string "Will you go inside?$"

DreamResort_EventScript_ReturnToHotel::
	warp MAP_COBALT_CITY_DREAM_RESORT_4F, 27, 4
	waitstate
	releaseall
	end

