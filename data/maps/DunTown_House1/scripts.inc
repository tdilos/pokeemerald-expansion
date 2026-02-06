.set LOCALID_DRAKE, 1
.set LOCALID_OLDSEAMAP, 2

DunTown_House1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DunTown_House1_OnTransition
	.byte 0

DunTown_House1_OnTransition:
	call DunTown_House1_EventScript_HideDrake
	call DunTown_House1_EventScript_HideOldSeaMap
	call_if_set FLAG_DEFEATED_AZAMI, DunTown_House1_EventScript_RevealDrake
	call_if_set FLAG_LANDMARK_ROUTE_100, DunTown_House1_EventScript_HideDrake
	call_if_set FLAG_IS_CHAMPION, DunTown_House1_EventScript_RevealOldSeaMap
	call_if_set FLAG_RECEIVED_OLD_SEA_MAP, DunTown_House1_EventScript_HideOldSeaMap
	end

DunTown_House1_EventScript_HideDrake:
	setflag FLAG_HIDE_DUN_TOWN_BOATMAN
	removeobject LOCALID_DRAKE
	return

DunTown_House1_EventScript_HideOldSeaMap:
	setflag FLAG_HIDE_OLD_SEA_MAP
	removeobject LOCALID_OLDSEAMAP
	return

DunTown_House1_EventScript_RevealDrake:
	clearflag FLAG_HIDE_DUN_TOWN_BOATMAN
	addobject LOCALID_DRAKE
	return

DunTown_House1_EventScript_RevealOldSeaMap:
	clearflag FLAG_HIDE_OLD_SEA_MAP
	addobject LOCALID_OLDSEAMAP
	return







DunTown_House1_EventScript_Drake::
	lock
	faceplayer
	msgbox DunTown_House1_Text_DrakeIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DunTown_House1_EventScript_SetSail
	msgbox DunTown_House1_Text_NotReady, MSGBOX_DEFAULT
	closemessage
	release
	end

DunTown_House1_EventScript_SetSail::
	msgbox DunTown_House1_Text_ReadyToSail, MSGBOX_DEFAULT
	closemessage

	warpsilent MAP_MT_SHIRO_SUMMIT, 12, 9
	waitstate
	release
	end

@	fadeoutbgm 0
@	fadescreen FADE_TO_BLACK
@	playse SE_RG_SS_ANNE_HORN
@	@delay 30
@	waitse
@	@msgbox DunTown_House1_Text_Dummy, MSGBOX_DEFAULT
@	@closemessage
@	fadeinbgm 0

@	warpsilent MAP_ROUTE100, 84, 33
@	waitstate
@	release
@	end

DunTown_House1_Text_DrakeIntro:
	.string "Welcome.\n"
	.string "You must be {PLAYER}.\p"
	.string "BRENDAN already told me about you.\p"
	.string "So your goal is to challenge the\n"
	.string "POKéMON LEAGUE, eh?\p"
	.string "It's been a long time since there's been\n"
	.string "a new champion in EVER GRANDE CITY.\p"
	.string "I see you have all of ISSHO'S\n"
	.string "GYM BADGES now.\p"
	.string "Are you ready for the final road\n"
	.string "of your journey?$"

DunTown_House1_Text_NotReady:
	.string "Well, I'm always ready to sail.\n"
	.string "Let me know if you change your mind.$"

DunTown_House1_Text_ReadyToSail:
	.string "Splendid.\n"
	.string "We'll set sail at once.$"

DunTown_House1_Text_Dummy:
	.string "$"

DunTown_House1_EventScript_PostgameOldSeaMap::
	msgbox DunTown_House1_Text_DrakeNote, MSGBOX_DEFAULT
	finditem ITEM_OLD_SEA_MAP
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	end

DunTown_House1_Text_DrakeNote:
	.string "Congratulation, CHAMPION {PLAYER}.\p"
	.string "May this map lead you to more\n"
	.string "exciting adventures.$"
	@.string "--DRAKE$"








@@@@@ move to Xanthos/Cobalt/Turquoise harbors
@DunTown_House1_EventScript_DrakePostgame::
@	msgbox DunTown_House1_Text_DrakePostgame, MSGBOX_YESNO
@	goto_if_eq VAR_RESULT, YES, DunTown_House1_EventScript_ChoosePostgameIsland
@	release
@	end

@DunTown_House1_EventScript_ChoosePostgameIsland::
@	msgbox DunTown_House1_Text_Whitherto, MSGBOX_DEFAULT	
@	end

@DunTown_House1_Text_DrakePostgame:
@	.string "CHAMPION {PLAYER}, have you come\n"
@	.string "to sail with us again?$"

@DunTown_House1_Text_Whitherto:
@	.string "Splendid, and whither are we bound?$"


