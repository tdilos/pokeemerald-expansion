MtShiro_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MtShiro_Summit_OnFrame
	.byte 0

MtShiro_Summit_OnFrame:
	map_script_2 VAR_PITCHBLAK_CITY_STATE, 2, MtShiro_Summit_EventScript_VoidSequence
	map_script_2 VAR_RANGER_HQ_STATE, 4, MtShiro_Summit_EventScript_ExplosionTransition
	map_script_2 VAR_RANGER_HQ_STATE, 9, MtShiro_Summit_EventScript_BoatToHoenn
	map_script_2 VAR_RANGER_HQ_STATE, 10, MtShiro_Summit_EventScript_FlyToEverGrande
	.2byte 0

MtShiro_Summit_EventScript_FlyToEverGrande::
	lockall
	delay 20
	playse SE_M_FLY
	waitse
	delay 20
	warpsilent MAP_EVER_GRANDE_CITY, 18, 6
	waitstate
	releaseall
	end


MtShiro_Summit_EventScript_BoatToHoenn::
	lockall
	delay 30
	playse SE_RG_SS_ANNE_HORN
	waitse
	delay 60
	warpsilent MAP_ROUTE100, 84, 33
	waitstate
	releaseall
	end


MtShiro_Summit_EventScript_ExplosionTransition::
	setvar VAR_RANGER_HQ_STATE, 5
	call UndergroundCity_Entrance_EventScript_ExplosionSE
	@applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	@waitmovement 0
	delay 240
	warpsilent MAP_UNDERGROUND_CITY, 3, 45
	waitstate
	releaseall
	end


MtShiro_Summit_EventScript_VoidSequence::
	@portal and void sequence goes here
	lockall
	delay 240
	msgbox MtShiro_Summit_Text_TheresNothingHere, MSGBOX_DEFAULT
	closemessage
	delay 3600
	fadescreen FADE_TO_WHITE
	delay 30
	fadescreen FADE_FROM_WHITE
	playmoncry SPECIES_MEW, CRY_MODE_NORMAL
	@waitmoncry
	msgbox MtShiro_Summit_Text_GetHelp, MSGBOX_DEFAULT
	closemessage
	delay 30
	fadescreen FADE_TO_WHITE
	delay 30
	fadescreen FADE_FROM_WHITE
	delay 30
	msgbox MtShiro_Summit_Text_GetHelp2, MSGBOX_DEFAULT
	closemessage
	delay 60
	fadescreen FADE_TO_WHITE
	delay 30
	fadescreen FADE_FROM_WHITE
	delay 30
	fadescreen FADE_TO_WHITE
	delay 30
	fadescreen FADE_FROM_WHITE
	delay 30
	fadescreen FADE_TO_WHITE
	delay 20
	fadescreen FADE_FROM_WHITE
	delay 20
	fadescreen FADE_TO_WHITE
	delay 20
	fadescreen FADE_FROM_WHITE
	delay 20
	fadescreen FADE_TO_WHITE
	delay 20
	fadescreen FADE_FROM_WHITE
	delay 20
	fadescreen FADE_TO_WHITE
	delay 10
	fadescreen FADE_FROM_WHITE
	delay 10
	fadescreen FADE_TO_WHITE
	delay 10
	fadescreen FADE_FROM_WHITE
	delay 10
	fadescreen FADE_TO_WHITE
	delay 10
	fadescreen FADE_FROM_WHITE
	delay 10
	fadescreen FADE_TO_WHITE
	delay 10
	fadescreen FADE_FROM_WHITE
	delay 10
	fadescreen FADE_TO_WHITE
	delay 10
	fadescreen FADE_FROM_WHITE
	delay 10
	fadescreen FADE_TO_WHITE
	delay 10
	fadescreen FADE_FROM_WHITE
	delay 60
	msgbox MtShiro_Summit_Text_HeyWakeUp, MSGBOX_DEFAULT
	closemessage
	delay 60
	@warp MAP_ROUTE73, 69, 9
	warpsilent MAP_PITCHBLAK_CITY, 46, 18
	waitstate
	releaseall
	end

MtShiro_Summit_Text_TheresNothingHere:
	.string "It's pitch black in every direction.\p"
	.string "There's no sound or feeling.\p"
	.string "There's nothing.$"

MtShiro_Summit_Text_GetHelp:
	.string "There's a voice calling out to you.$"

MtShiro_Summit_Text_GetHelp2:
	.string "Get help.\n"
	.string "AB LABS.$"

MtShiro_Summit_Text_HeyWakeUp:
	.string "????: Hey {PLAYER}, are you okay?\p"
	.string "Hey, wake up!$"



