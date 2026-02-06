.set LOCALID_JACE, 2
.set LOCALID_RAYNER, 1

PokemonLaboratory_B1_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLaboratory_B1_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonLaboratory_B1_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, PokemonLaboratory_B1_OnLoad
	.byte 0

PokemonLaboratory_B1_OnLoad:
	call_if_ge VAR_WISTERIA_CITY_STATE, 6, PokemonLaboratory_B1_EventScript_Open1stDoor
	end

PokemonLaboratory_B1_EventScript_Open1stDoor:
	setmetatile 25, 0, METATILE_Facility2_LabDoor_Open_Top, TRUE
	setmetatile 25, 1, METATILE_Facility2_LabDoor_Open, FALSE
	@special DrawWholeMapView
	return






PokemonLaboratory_B1_OnTransition::
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	@setvar VAR_TEMP_3, 0
	@setvar VAR_TEMP_4, 0
	@setvar VAR_TEMP_5, 0
	@setvar VAR_TEMP_6, 0
	call_if_eq VAR_WISTERIA_CITY_STATE, 3, PokemonLaboratory_B1_EventScript_AddJace
	call_if_eq VAR_WISTERIA_CITY_STATE, 3, PokemonLaboratory_B1_EventScript_AddRayner
	call_if_ge VAR_WISTERIA_CITY_STATE, 4, PokemonLaboratory_B1_EventScript_MoveJaceToB2
	call_if_ge VAR_WISTERIA_CITY_STATE, 4, PokemonLaboratory_B1_EventScript_MoveRaynerToB2
	call_if_ge VAR_WISTERIA_CITY_STATE, 5, PokemonLaboratory_B1_EventScript_MoveJaceTo1stDoor
	call_if_ge VAR_WISTERIA_CITY_STATE, 5, PokemonLaboratory_B1_EventScript_MoveRaynerTo1stDoor
	call_if_ge VAR_WISTERIA_CITY_STATE, 6, PokemonLaboratory_B1_EventScript_RemoveJace
	call_if_ge VAR_WISTERIA_CITY_STATE, 6, PokemonLaboratory_B1_EventScript_RemoveRayner
	end

PokemonLaboratory_B1_EventScript_AddJace:
	clearflag FLAG_HIDE_JACE
	addobject LOCALID_JACE
	return

PokemonLaboratory_B1_EventScript_AddRayner:
	clearflag FLAG_HIDE_RAYNER
	addobject LOCALID_RAYNER
	return

PokemonLaboratory_B1_EventScript_MoveJaceToB2:
	@setflag FLAG_HIDE_JACE
	@removeobject LOCALID_JACE
	setobjectxyperm LOCALID_JACE, 11, 8
	setobjectmovementtype LOCALID_JACE, MOVEMENT_TYPE_FACE_DOWN
	clearflag FLAG_HIDE_JACE
	addobject LOCALID_JACE
	return

PokemonLaboratory_B1_EventScript_MoveRaynerToB2:
	@setflag FLAG_HIDE_RAYNER
	@removeobject LOCALID_RAYNER
	setobjectxyperm LOCALID_RAYNER, 12, 10
	setobjectmovementtype LOCALID_RAYNER, MOVEMENT_TYPE_FACE_DOWN
	clearflag FLAG_HIDE_RAYNER
	addobject LOCALID_RAYNER
	return

PokemonLaboratory_B1_EventScript_MoveJaceTo1stDoor:
	removeobject LOCALID_JACE
	setobjectxyperm LOCALID_JACE, 24, 5
	setobjectmovementtype LOCALID_JACE, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_JACE
	addobject LOCALID_JACE
	return

PokemonLaboratory_B1_EventScript_MoveRaynerTo1stDoor:
	removeobject LOCALID_RAYNER
	setobjectxyperm LOCALID_RAYNER, 23, 2
	setobjectmovementtype LOCALID_RAYNER, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_RAYNER
	addobject LOCALID_RAYNER
	return

PokemonLaboratory_B1_EventScript_RemoveJace:
	setflag FLAG_HIDE_JACE
	removeobject LOCALID_JACE
	return

PokemonLaboratory_B1_EventScript_RemoveRayner:
	setflag FLAG_HIDE_RAYNER
	removeobject LOCALID_RAYNER
	return






PokemonLaboratory_B1_OnFrame:
	map_script_2 VAR_WISTERIA_CITY_STATE, 3, PokemonLaboratory_B1_EventScript_RaynerEncounter
	.2byte 0















PokemonLaboratory_B1_EventScript_Switch1::
	lockall
	@addvar NUM_SWITCHES_PRESSED, 1
	setvar VAR_TEMP_1, 100
	playse SE_SWITCH
	waitse
	setmetatile 14, 37, METATILE_Facility2_MagnetSwitch_On, TRUE
	special DrawWholeMapView
	goto_if_eq VAR_TEMP_2, 100, PokemonLaboratory_B1_EventScript_PuzzleSolved
	releaseall
	end

PokemonLaboratory_B1_EventScript_Switch2::
	lockall
	setvar VAR_TEMP_2, 100
	playse SE_SWITCH
	waitse
	setmetatile 14, 39, METATILE_Facility2_MagnetSwitch_On, TRUE
	special DrawWholeMapView
	goto_if_eq VAR_TEMP_1, 100, PokemonLaboratory_B1_EventScript_PuzzleSolved
	releaseall
	end

PokemonLaboratory_B1_EventScript_PuzzleSolved::
	playse SE_SUCCESS
	waitse
	playse SE_TRUCK_DOOR
	setmetatile 12, 35, METATILE_Facility2_LabDoor_Open_Top, TRUE
	setmetatile 12, 36, METATILE_Facility2_LabDoor_Open, FALSE
	special DrawWholeMapView
	releaseall
	end

PokemonLaboratory_B1_EventScript_OffSwitch1::
	goto_if_lt VAR_TEMP_1, 99, PokemonLaboratory_B1_EventScript_Skip
	setvar VAR_TEMP_1, 0
	playse SE_PC_OFF
	waitse
	setmetatile 14, 37, METATILE_Facility2_MagnetSwitch_Off, FALSE
	special DrawWholeMapView
	end

PokemonLaboratory_B1_EventScript_OffSwitch2::
	goto_if_lt VAR_TEMP_2, 99, PokemonLaboratory_B1_EventScript_Skip
	setvar VAR_TEMP_2, 0
	playse SE_PC_OFF
	waitse
	setmetatile 14, 39, METATILE_Facility2_MagnetSwitch_Off, FALSE
	special DrawWholeMapView
	end

PokemonLaboratory_B1_EventScript_Skip::
	end



















PokemonLaboratory_B1_EventScript_RaynerEncounter::
	lockall
	@turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	@applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	@waitmovement 0
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	delay 120
	@applymovement LOCALID_RAYNER, Common_Movement_ExclamationMark
	@playse SE_PIN
	applymovement LOCALID_RAYNER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	@delay 120
	msgbox PokemonLaboratory_B1_Text_RaynerWelcome, MSGBOX_DEFAULT
	closemessage
	delay 40
	applymovement LOCALID_JACE, Common_Movement_FaceUp
	waitmovement 0
	@delay 10
	@playse SE_M_METRONOME
	@applymovement LOCALID_JACE, Common_Movement_QuestionMark
	@waitmovement 0
	delay 20
	msgbox PokemonLaboratory_B1_Text_DoYouKnowThisGuy, MSGBOX_DEFAULT
	closemessage
	delay 40
	applymovement LOCALID_RAYNER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_FaceRight
	waitmovement 0
	delay 20
	msgbox PokemonLaboratory_B1_Text_KeepRunningIntoEachOther, MSGBOX_DEFAULT
	closemessage
	delay 20
	playse SE_M_METRONOME
	applymovement LOCALID_JACE, Common_Movement_QuestionMark
	waitmovement 0
	delay 10
	msgbox PokemonLaboratory_B1_Text_WhatDoYouMeanIt, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox PokemonLaboratory_B1_Text_WayToTeamGenesis, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JACE, Common_Movement_ExclamationMark
	@waitmovement 0
	playse SE_PIN
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceRight
	@waitmovement 0
	msgbox PokemonLaboratory_B1_Text_YouKnowTeamGenesis, MSGBOX_DEFAULT
	closemessage
	delay 120
	msgbox PokemonLaboratory_B1_Text_ThatsRight, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_RAYNER, Common_Movement_FaceRight
	waitmovement 0
	delay 30
	msgbox PokemonLaboratory_B1_Text_LetsTalkAndWalk, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RAYNER, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_WalkRight
	waitmovement 0
	call PokemonLaboratory_B1_EventScript_RemoveRayner
	delay 30
	applymovement LOCALID_JACE, Common_Movement_FaceUp
	waitmovement 0
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 20
	msgbox PokemonLaboratory_B1_Text_TrustThisGuy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PokemonLaboratory_B1_EventScript_TrustRayner
	goto_if_eq VAR_RESULT, NO, PokemonLaboratory_B1_EventScript_DontTrustRayner
	end

PokemonLaboratory_B1_EventScript_TrustRayner::
	msgbox PokemonLaboratory_B1_Text_JaceYes, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	call PokemonLaboratory_B1_EventScript_RemoveJace
	setvar VAR_WISTERIA_CITY_STATE, 4
	delay 60
	release
	end

PokemonLaboratory_B1_EventScript_DontTrustRayner::
	msgbox PokemonLaboratory_B1_Text_JaceNo, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	call PokemonLaboratory_B1_EventScript_RemoveJace
	setvar VAR_WISTERIA_CITY_STATE, 4
	delay 60
	release
	end

PokemonLaboratory_B1_Text_RaynerWelcome:
	.string "??????: Well, well, well.\n"
	.string "Long time, no see, {PLAYER}.\p"
	.string "You guys got here just in time.$"

PokemonLaboratory_B1_Text_DoYouKnowThisGuy:
	.string "JACE: He knows your name?\p"
	.string "{PLAYER}, do you know this guy?$"

PokemonLaboratory_B1_Text_KeepRunningIntoEachOther:
	.string "??????: We keep running into\n"
	.string "each other somehow.\p"
	.string "\p"
	.string "So let me guess. You guys are here\n"
	.string "to find “it” too, right?$"

PokemonLaboratory_B1_Text_WhatDoYouMeanIt:
	.string "JACE: What do you mean “it”?$"

PokemonLaboratory_B1_Text_WayToTeamGenesis:
	.string "??????: The way to TEAM GENESIS,\n"
	.string "of course.$"

PokemonLaboratory_B1_Text_YouKnowTeamGenesis:
	.string "JACE: You know where TEAM GENESIS\n"
	.string "is hiding?!$"

PokemonLaboratory_B1_Text_ThatsRight:
	.string "??????: Hehehehehehehe.\n"
	.string "That's right.\p"
	.string "Only it's not an easy place to reach.\n"
	.string "You need special equipment to get there.$"

PokemonLaboratory_B1_Text_LetsTalkAndWalk:
	.string "It'll make more sense if I just show you.\n"
	.string "Let's talk as we walk.$"

PokemonLaboratory_B1_Text_TrustThisGuy:
	.string "JACE: Do you think we should\n"
	.string "trust this guy, {PLAYER}?$"

PokemonLaboratory_B1_Text_JaceYes:
	.string "JACE: Hmmm, maybe you're right.\p"
	.string "This could be our only chance to\n"
	.string "find TEAM GENESIS.$"

PokemonLaboratory_B1_Text_JaceNo:
	.string "JACE: Yeah, something's off about him...\p"
	.string "But this could be our only chance to\n"
	.string "find TEAM GENESIS.$"











PokemonLaboratory_B1_EventScript_RaynerEncounter2::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	delay 30
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, PokemonLaboratory_B1_Movement_CameraPanDown
	waitmovement 0
	delay 50
	msgbox PokemonLaboratory_B1_Text_RaynerExplainFacility, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox PokemonLaboratory_B1_Text_JaceWhatsThat, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_RAYNER, Common_Movement_FaceUp
	waitmovement 0
	delay 60
	msgbox PokemonLaboratory_B1_Text_RaynerExplainUltraSpace, MSGBOX_DEFAULT
	closemessage
	delay 90
	@applymovement LOCALID_JACE, Common_Movement_WalkInPlaceDown
	@waitmovement 0
	msgbox PokemonLaboratory_B1_Text_SleptThroughClass, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_RAYNER, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	msgbox PokemonLaboratory_B1_Text_RaynerFollowMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RAYNER, PokemonLaboratory_B1_Movement_RaynerExit2
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_FaceRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	delay 40
	applymovement LOCALID_JACE,  Common_Movement_WalkDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_JACE, PokemonLaboratory_B1_Movement_JaceExit2
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, PokemonLaboratory_B1_Movement_CameraPanUp
	waitmovement 0
	special RemoveCameraObject
	call PokemonLaboratory_B1_EventScript_MoveRaynerTo1stDoor
	call PokemonLaboratory_B1_EventScript_MoveJaceTo1stDoor
	setvar VAR_WISTERIA_CITY_STATE, 5
	delay 20
	release
	end

PokemonLaboratory_B1_Text_RaynerExplainFacility:
	.string "??????: This place was once\n"
	.string "a research facility.\p"
	.string "It was set up by the founders\n"
	.string "of TEAM GENESIS.\p"
	.string "They ran all kinds of experiments here.\p"
	.string "But their most ambitious work\n"
	.string "was Project Starwalk.\p"
	.string "You guys have heard of\n"
	.string "Ultra Space, right?$"

PokemonLaboratory_B1_Text_JaceWhatsThat:
	.string "JACE: No, what's that?$"

PokemonLaboratory_B1_Text_RaynerExplainUltraSpace:
	.string "??????: It's the void that surrounds\n"
	.string "our world. An endless black abyss.\p"
	.string "Hostile to all life as we know it.\n"
	.string "There's no light, no sound, no warmth.\p"
	.string "No feeling whatsoever.\p"
	.string "Not long ago, it was only poorly\n"
	.string "understood.\p"
	.string "But nowadays, even schoolchildren\n"
	.string "know about it.$"

PokemonLaboratory_B1_Text_SleptThroughClass:
	.string "JACE: Guess I slept through\n"
	.string "that class...\p"
	.string "So what does any of this have to do\n"
	.string "with TEAM GENESIS?$"

PokemonLaboratory_B1_Text_RaynerFollowMe:
	.string "??????: Follow me.$"

PokemonLaboratory_B1_Movement_CameraPanDown:
	@delay_16
	@delay_16
	@delay_16
	delay_16
	walk_down
	walk_down
	step_end

PokemonLaboratory_B1_Movement_RaynerExit2:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

PokemonLaboratory_B1_Movement_JaceExit2:
	walk_down
	walk_down
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
	step_end

PokemonLaboratory_B1_Movement_CameraPanUp:
	@delay_16
	@delay_16
	@delay_16
	delay_16
	walk_up
	walk_up
	step_end







PokemonLaboratory_B1_EventScript_RaynerEncounter3::
	lockall
	@turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	delay 60
	applymovement LOCALID_RAYNER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox PokemonLaboratory_B1_Text_ProjectStarwalk, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_RAYNER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox PokemonLaboratory_B1_Text_However, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_RAYNER, Common_Movement_FaceDown
	waitmovement 0
	delay 60
	msgbox PokemonLaboratory_B1_Text_Aftermath, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox PokemonLaboratory_B1_Text_JaceWhatHappened, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_RAYNER, Common_Movement_FaceUp
	waitmovement 0
	delay 60
	msgbox PokemonLaboratory_B1_Text_FewLeftToTell, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_RAYNER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox PokemonLaboratory_B1_Text_WhatIveGathered, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_RAYNER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox PokemonLaboratory_B1_Text_Eventually, MSGBOX_DEFAULT
	closemessage
	delay 30
	playse SE_SUCCESS
	waitse
	playse SE_TRUCK_DOOR
	call PokemonLaboratory_B1_EventScript_Open1stDoor
	special DrawWholeMapView
	delay 60
	applymovement LOCALID_RAYNER, Common_Movement_FaceDown
	waitmovement 0
	delay 60
	msgbox PokemonLaboratory_B1_Text_DoYouUnderstand, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox PokemonLaboratory_B1_Text_JaceWarpholes, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox PokemonLaboratory_B1_Text_RaynerMoreOrLess, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RAYNER, PokemonLaboratory_B1_Movement_RaynerExit3
	waitmovement 0
	playse SE_EXIT
	call PokemonLaboratory_B1_EventScript_RemoveRayner
	delay 30
	applymovement LOCALID_JACE, PokemonLaboratory_B1_Movement_JaceExit3
	waitmovement 0
	playse SE_EXIT
	call PokemonLaboratory_B1_EventScript_RemoveJace
	setvar VAR_WISTERIA_CITY_STATE, 6
	delay 60
	release
	end

PokemonLaboratory_B1_Movement_RaynerExit3:
	walk_right
	walk_right
	walk_up
	step_end

PokemonLaboratory_B1_Movement_JaceExit3:
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	step_end

PokemonLaboratory_B1_Text_ProjectStarwalk:
	.string "??????: The founders of TEAM GENESIS\n"
	@.string "wanted to explore this dark dimension.\p"
	.string "wanted to explore Ultra Space.\p"
	.string "They believed there were other worlds\n"
	.string "like ours suspended in the void.\p"
	.string "So they designed a warping device.\n"
	.string "The fruit of Project Starwalk.$"

PokemonLaboratory_B1_Text_However:
	.string "However, things didn't go\n"
	.string "according to plan.\p"
	.string "The “incident” started while they\n"
	.string "were probing Ultra Space.$"

PokemonLaboratory_B1_Text_Aftermath:
	.string "What you see here is the aftermath\n"
	.string "of that incident.$"

PokemonLaboratory_B1_Text_JaceWhatHappened:
	.string "JACE: What happened here...?$"

PokemonLaboratory_B1_Text_FewLeftToTell:
	.string "??????: Who knows.\p"
	.string "There aren't many left who\n"
	.string "saw it firsthand.\p"
	.string "And they don't very much like\n"
	.string "to talk about it...$"

PokemonLaboratory_B1_Text_WhatIveGathered:
	.string "From what I've gathered, something\n"
	.string "came out of Ultra Space that day.\p"
	.string "And it caused the destruction\n"
	.string "you see here.\p"
	.string "Eventually, the chaos spread to\n"
	.string "WISTERIA CITY.\p"
	.string "It took the combined effort of many\n"
	.string "powerful trainers to stop it.\p"
	.string "Even the LEAGUE itself was forced\n"
	.string "to step in.\p"
	.string "\p"
	.string "Naturally, the project was terminated\n"
	.string "after that.\p"

	@.string "In fact, the whole laboratory was abandoned.\p"
	@.string "The financiers, unhappy with the project\n"
	@.string "results, decided to reinvest elsewhere.\p"
	@.string "And so, WISTERIA CITY was ravaged and\n"
	@.string "abandoned by its biggest employer.\p"
	@.string "To this day, it remains a shadow of\n"
	@.string "its former self.\p"
	@.string "\p"
	@.string "Eventually, some of those financiers\n"
	@.string "went on to form TEAM GENESIS.\p"

	.string "This facility was closed off\n"
	.string "and abandoned.\p"
	.string "And what was left of WISTERIA CITY\n"
	.string "was left to rot.$"


PokemonLaboratory_B1_Text_Eventually:
	.string "Eventually, the people who set up this\n"
	.string "lab went on to form TEAM GENESIS.\p"
	.string "They salvaged what they could from\n"
	.string "their failure here.\p"
	.string "They use the same technology that was\n"
	.string "supposed to take them to Ultra Space.\p"
	.string "Although it's far weaker than the\n"
	.string "original design...$"

PokemonLaboratory_B1_Text_DoYouUnderstand:
	.string "??????: Do you understand?\p"
	.string "That's what makes TEAM GENESIS\n"
	.string "so hard to find.\p"
	.string "That's how they can disappear\n"
	.string "so easily.$"

PokemonLaboratory_B1_Text_JaceWarpholes:
	.string "JACE: So you're saying they\n"
	.string "make warpholes or something?$"

PokemonLaboratory_B1_Text_RaynerMoreOrLess:
	.string "??????: More or less.\p"
	.string "And the original machines they created\n"
	.string "are buried under this facility.\p"
	.string "If we can retrieve them, we can use them\n"
	.string "to go to TEAM GENESIS'S location.\p"
	.string "Let's keep moving.$"








PokemonLaboratory_B1_Text_RaynerTakesOffGlasses:
	.string "??????: Ahh, the lighting down here\n"
	.string "is much better.\p"
	.string "I don't need to wear these anymore.$"

PokemonLaboratory_B1_Text_JaceGlassesInTheDark:
	.string "JACE: Yeah, I was wondering who\n"
	.string "wears sunglasses in the dark.$"

PokemonLaboratory_B1_Text_RaynerSensitiveEyes:
	.string "??????: Hehehehehe.\n"
	.string "Sensitive eyes.\p"
	.string "Just something I was born with.$"

PokemonLaboratory_B1_Text_JaceWhyAreYouHere:
	.string "JACE: So why are you looking\n"
	.string "for TEAM GENESIS?\p"
	.string "And how do you know so much about them?$"

PokemonLaboratory_B1_Text_RaynerScoreToSettle:
	.string "??????: Let's just say we have a history.\n"
	.string "I have a score to settle with them.$"







PokemonLaboratory_B1_Text_JaceLetMeGetThisStraight:
	.string "JACE: So let me get this straight.\p"
	.string "You're here because TEAM GENESIS\n"
	.string "did something to you.\p"
	.string "And now you want to get revenge?$"

PokemonLaboratory_B1_Text_RaynerBasically:
	.string "??????: ...\p"
	.string "Basically, yeah.$"

PokemonLaboratory_B1_Text_JaceWhatDidTheyDo:
	.string "JACE: What did they do to you, anyway?$"

PokemonLaboratory_B1_Text_RaynerRatherNotTalk:
	.string "??????: ...\p"
	.string "I'd rather not talk about it.$"

PokemonLaboratory_B1_Text_JaceItsOkay:
	.string "JACE: Oh no, it's okay.\n"
	.string "I didn't realize it was like that...\p"
	.string "I'm just glad we're on the same page\n"
	.string "about TEAM GENESIS.\p"
	.string "Those guys are cruel and inhuman!$"







PokemonLaboratory_B1_Text_RaynerNextDoor:
	.string "??????: Alright, this door is\n"
	.string "a bit troublesome.\p"
	.string "This could take some time.\n"
	.string "Just sit back and relax for a bit.$"

PokemonLaboratory_B1_Text_GivesMeTheCreeps:
	.string "JACE: This place sure gives me the creeps.\p"
	.string "But this sounds like our best bet at\n"
	.string "tracking down TEAM GENESIS.$"






PokemonLaboratory_B1_Text_JaceWhatsYourName:
	.string "JACE: By the way, I never\n"
	.string "introduced myself.\p"
	.string "I'm JACE from UMBER TOWN.\n"
	.string "What's your name?$"

PokemonLaboratory_B1_Text_RaynerName:
	.string "??????: ...\p"
	.string "My name?\p"
	.string "Heh, don't really have one.\p"
	.string "\p"
	.string "I guess you can call me 6.\n"
	.string "That's what some people call me.$"

PokemonLaboratory_B1_Text_JaceThatsANumber:
	.string "JACE: 6?\n"
	.string "That's a number, not a name.\p"
	.string "I mean, like, what do your folks call you?$"

PokemonLaboratory_B1_Text_RaynerFolks:
	.string "\p"
	.string "Folks?$"

PokemonLaboratory_B1_Text_JaceMomAndDad:
	.string "You know, your mom and dad.\n"
	.string "Everybody has one of those.\p"
	.string "\p"
	.string "Do you not know who your parents are?$"

PokemonLaboratory_B1_Text_RaynerFatherAndBrothers:
	.string "\p"
	.string "I know a man who could be called my father.\p"
	.string "And the rest of us, I guess that\n"
	.string "makes us all brothers...$"

PokemonLaboratory_B1_Text_JaceBigFamily:
	.string "So you come from a really big family, huh?\n"
	.string "What do they call you?$"

PokemonLaboratory_B1_Text_RaynerOneOtherName:
	.string "\p"
	.string "There was one other thing he called us.\p"
	.string "For a while, he called each of us RAYNER.$"

PokemonLaboratory_B1_Text_JaceNiceToMeetYou:
	.string "You and your brothers all had the same name?\n"
	.string "That's really weird...\p"
	.string "But RAYNER, huh?\p"
	.string "Now that sounds like a person's name.\n"
	.string "Nice to meet you!$"

PokemonLaboratory_B1_Text_RaynerShallWeContinue:
	.string "RAYNER: Shall we continue?$"









PokemonLaboratory_B1_Text_RaynerHereWeAre:
	.string "RAYNER: And here we are.\p"
	.string "The machines we're after are\n"
	.string "just inside that room.\p"
	.string "Go ahead and grab one.\p"
	.string "If you think you can make it\n"
	.string "in time, that is.$"

PokemonLaboratory_B1_Text_JaceWhatsInThere:
	.string "JACE: What do you mean?\n"
	.string "What's in there?$"

PokemonLaboratory_B1_Text_CursedRoom1:
	.string "RAYNER: Who knows?\p"
	.string "Some say it's a trap left by the\n"
	.string "scientists who used to work here.\p"
	.string "Others say it's something they awakened\n"
	.string "from Ultra Space.\p"
	.string "And some even say it's the unfortunate souls\n"
	.string "themselves from that fateful day.$"

PokemonLaboratory_B1_Text_CursedRoom2:
	.string "Whatever's in there, it's guarding\n"
	.string "the machines we need.\p"
	.string "I've never been inside myself, but I've\n"
	.string "seen plenty of people swallowed up by it.\p"
	.string "\p"
	.string "Of course, they were all careless fools.\n"
	.string "Some of them couldn't even make it this far.\p"
	.string "It seems to react differently to\n"
	.string "different people...\p"
	.string "\p"
	.string "Well, why don't you try it?\n"
	.string "If you're brave enough, that is.$"

PokemonLaboratory_B1_Text_NotGoingInThere:
	.string "I'm not going in there!\n"
	.string "You go in there!$"

PokemonLaboratory_B1_Text_SomeoneMustGo:
	.string "RAYNER: Sigh. Well, one of us has\n"
	.string "to go for us to make any progress.$"

PokemonLaboratory_B1_Text_HowAboutYou:
	.string "How about you, {PLAYER}?\n"
	.string "You want to be useful, right?$"

PokemonLaboratory_B1_Text_IKnewYouWould:
	.string "RAYNER: Hehehehehehe.\n"
	.string "I knew you would.$"

PokemonLaboratory_B1_Text_AfterYou:
	.string "RAYNER: After you.$"

PokemonLaboratory_B1_Text_DrawLots:
	.string "RAYNER: Sigh. It looks like\n"
	.string "we'll have to draw lots.\p"
	.string "Short straw goes first.$"

PokemonLaboratory_B1_Text_ToughLuck:
	.string "RAYNER: Uh-oh.\p"
	.string "Tough luck, {PLAYER}.$"

PokemonLaboratory_B1_Text_BeCareful:
	.string "JACE: Be careful, {PLAYER}.\p"
	.string "Don't worry. If things look bad,\n"
	.string "I'll be here to pull you out.$"





