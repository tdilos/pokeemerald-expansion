StationRing_MapScripts::
	.byte 0


StationRing_EventScript_MewtwoGenesectEncounter::
	lockall
	playmoncry SPECIES_MEWTWO, CRY_MODE_NORMAL
	@waitmoncry
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	delay 30
	releaseall
	end





StationRing_EventScript_Boy::
	lock
	faceplayer
	msgbox StationRing_Text_GiantLightStrips, MSGBOX_DEFAULT
	release
	end

StationRing_Text_GiantLightStrips:
	.string "These giant light strips help to\n"
	.string "illuminate the whole station.$"

