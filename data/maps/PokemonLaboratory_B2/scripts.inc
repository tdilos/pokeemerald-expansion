.set LOCALID_JACE_LAB2, 7
.set LOCALID_RAYNER_LAB2, 8

PokemonLaboratory_B2_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLaboratory_B2_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonLaboratory_B2_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, PokemonLaboratory_B2_OnLoad
	.byte 0

PokemonLaboratory_B2_OnLoad:
	call_if_ge VAR_WISTERIA_CITY_STATE, 9, PokemonLaboratory_B2_EventScript_OpenLastDoor
	end

PokemonLaboratory_B2_EventScript_OpenLastDoor:
	setmetatile 37, 0, METATILE_Facility2_DarkLabDoor_Open_Top, TRUE
	setmetatile 37, 1, METATILE_Facility2_DarkLabDoor_Open, FALSE
	@special DrawWholeMapView
	return






PokemonLaboratory_B2_OnTransition::
	call_if_eq VAR_WISTERIA_CITY_STATE, 6, PokemonLaboratory_B2_EventScript_AddJace
	call_if_eq VAR_WISTERIA_CITY_STATE, 6, PokemonLaboratory_B2_EventScript_AddRayner
	call_if_eq VAR_WISTERIA_CITY_STATE, 7, PokemonLaboratory_B2_EventScript_MoveJaceToCatwalk
	call_if_eq VAR_WISTERIA_CITY_STATE, 7, PokemonLaboratory_B2_EventScript_MoveRaynerToCatwalk
	call_if_eq VAR_WISTERIA_CITY_STATE, 8, PokemonLaboratory_B2_EventScript_MoveJaceToLastDoor
	call_if_eq VAR_WISTERIA_CITY_STATE, 8, PokemonLaboratory_B2_EventScript_MoveRaynerToLastDoor
	call_if_ge VAR_WISTERIA_CITY_STATE, 9, PokemonLaboratory_B2_EventScript_MoveJaceToEntityRoom
	call_if_ge VAR_WISTERIA_CITY_STATE, 9, PokemonLaboratory_B2_EventScript_MoveRaynerToEntityRoom
	call_if_ge VAR_WISTERIA_CITY_STATE, 11, PokemonLaboratory_B2_EventScript_RemoveJace
	call_if_ge VAR_WISTERIA_CITY_STATE, 11, PokemonLaboratory_B2_EventScript_RemoveRayner
	end

PokemonLaboratory_B2_EventScript_AddJace:
	clearflag FLAG_HIDE_JACE
	addobject LOCALID_JACE_LAB2
	return

PokemonLaboratory_B2_EventScript_AddRayner:
	clearflag FLAG_HIDE_RAYNER
	addobject LOCALID_RAYNER_LAB2
	return

PokemonLaboratory_B2_EventScript_MoveJaceToCatwalk:
	removeobject LOCALID_JACE_LAB2
	setobjectxyperm LOCALID_JACE_LAB2, 33, 31
	setobjectmovementtype LOCALID_JACE_LAB2, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_JACE
	addobject LOCALID_JACE_LAB2
	return

PokemonLaboratory_B2_EventScript_MoveRaynerToCatwalk:
	removeobject LOCALID_RAYNER_LAB2
	setobjectxyperm LOCALID_RAYNER_LAB2, 33, 28
	setobjectmovementtype LOCALID_RAYNER_LAB2, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_RAYNER
	addobject LOCALID_RAYNER_LAB2
	return

PokemonLaboratory_B2_EventScript_MoveJaceToLastDoor:
	removeobject LOCALID_JACE_LAB2
	setobjectxyperm LOCALID_JACE_LAB2, 36, 5
	setobjectmovementtype LOCALID_JACE_LAB2, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_JACE
	addobject LOCALID_JACE_LAB2
	return

PokemonLaboratory_B2_EventScript_MoveRaynerToLastDoor:
	removeobject LOCALID_RAYNER_LAB2
	setobjectxyperm LOCALID_RAYNER_LAB2, 37, 3
	setobjectmovementtype LOCALID_RAYNER_LAB2, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_RAYNER
	addobject LOCALID_RAYNER_LAB2
	return

PokemonLaboratory_B2_EventScript_MoveJaceToEntityRoom:
	removeobject LOCALID_JACE_LAB2
	setobjectxyperm LOCALID_JACE_LAB2, 9, 26
	setobjectmovementtype LOCALID_JACE_LAB2, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_JACE
	addobject LOCALID_JACE_LAB2
	return

PokemonLaboratory_B2_EventScript_MoveRaynerToEntityRoom:
	removeobject LOCALID_RAYNER_LAB2
	setobjectxyperm LOCALID_RAYNER_LAB2, 7, 26
	setobjectmovementtype LOCALID_RAYNER_LAB2, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_RAYNER
	addobject LOCALID_RAYNER_LAB2
	return

PokemonLaboratory_B2_EventScript_RemoveJace:
	setflag FLAG_HIDE_JACE
	removeobject LOCALID_JACE_LAB2
	return

PokemonLaboratory_B2_EventScript_RemoveRayner:
	setflag FLAG_HIDE_RAYNER
	removeobject LOCALID_RAYNER_LAB2
	return



PokemonLaboratory_B2_OnFrame:
	map_script_2 VAR_WISTERIA_CITY_STATE, 6, PokemonLaboratory_B2_EventScript_RaynerEncounter4
	.2byte 0







PokemonLaboratory_B2_EventScript_RaynerEncounter4::
	lockall
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLaboratory_B2_Movement_PlayerEnter
	waitmovement 0
	delay 120
	applymovement LOCALID_RAYNER_LAB2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	delay 30
	msgbox PokemonLaboratory_B2_Text_RaynerTakesOffGlasses, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox PokemonLaboratory_B2_Text_JaceGlassesInTheDark, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_RAYNER_LAB2, Common_Movement_FaceLeft
	waitmovement 0
	delay 60
	msgbox PokemonLaboratory_B2_Text_RaynerSensitiveEyes, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_JACE_LAB2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox PokemonLaboratory_B2_Text_JaceWhyAreYouHere, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_RAYNER_LAB2, Common_Movement_FaceRight
	waitmovement 0
	delay 60
	msgbox PokemonLaboratory_B2_Text_RaynerScoreToSettle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RAYNER_LAB2, PokemonLaboratory_B2_Movement_RaynerExit
	waitmovement 0
	call PokemonLaboratory_B2_EventScript_RemoveRayner
	applymovement LOCALID_JACE_LAB2, PokemonLaboratory_B2_Movement_JaceExit
	waitmovement 0
	call PokemonLaboratory_B2_EventScript_RemoveJace
	delay 60
	setvar VAR_WISTERIA_CITY_STATE, 7
	releaseall
	end

PokemonLaboratory_B2_Movement_PlayerEnter:
	walk_slow_down
	walk_slow_right
	walk_slow_right
	walk_slow_right
	step_end

PokemonLaboratory_B2_Movement_RaynerExit:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

PokemonLaboratory_B2_Movement_JaceExit:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

PokemonLaboratory_B2_Text_RaynerTakesOffGlasses:
	.string "??????: Ahh, the lighting down here\n"
	.string "is much better.\p"
	.string "I don't need to wear these anymore.$"

PokemonLaboratory_B2_Text_JaceGlassesInTheDark:
	.string "JACE: Yeah, I was wondering who\n"
	.string "wears sunglasses in the dark.$"

PokemonLaboratory_B2_Text_RaynerSensitiveEyes:
	.string "??????: Hehehehehe.\n"
	.string "Sensitive eyes.\p"
	.string "Just something I was born with.$"

PokemonLaboratory_B2_Text_JaceWhyAreYouHere:
	.string "JACE: So why are you looking\n"
	.string "for TEAM GENESIS?\p"
	.string "And how do you know so much about them?$"

PokemonLaboratory_B2_Text_RaynerScoreToSettle:
	.string "??????: Let's just say we have a history.\n"
	.string "I have a score to settle with them.$"













PokemonLaboratory_B2_EventScript_RaynerEncounter5::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLaboratory_B2_Movement_PlayerEnter2
	waitmovement 0
	delay 30
	applymovement LOCALID_JACE_LAB2, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox PokemonLaboratory_B2_Text_JaceLetMeGetThisStraight, MSGBOX_DEFAULT
	closemessage
	delay 90
	msgbox PokemonLaboratory_B2_Text_RaynerBasically, MSGBOX_DEFAULT
	closemessage
	delay 30
	@applymovement LOCALID_JACE_LAB2, Common_Movement_WalkInPlaceUp
	@waitmovement 0
	msgbox PokemonLaboratory_B2_Text_JaceWhatDidTheyDo, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_RAYNER_LAB2, Common_Movement_FaceDown
	waitmovement 0
	delay 60
	msgbox PokemonLaboratory_B2_Text_RaynerReallyWantToKnow, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_RAYNER_LAB2, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox PokemonLaboratory_B2_Text_RaynerCantChange, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_RAYNER_LAB2, Common_Movement_FaceUp
	waitmovement 0
	delay 60
	msgbox PokemonLaboratory_B2_Text_RaynerDangerous, MSGBOX_DEFAULT
	closemessage
	delay 120
	playse SE_M_METRONOME
	applymovement LOCALID_JACE_LAB2, Common_Movement_QuestionMark
	delay 60
	msgbox PokemonLaboratory_B2_Text_JaceDontGetIt, MSGBOX_DEFAULT
	closemessage
	delay 90
	applymovement LOCALID_RAYNER_LAB2, Common_Movement_FaceDown
	waitmovement 0
	delay 120
	applymovement LOCALID_RAYNER_LAB2, Common_Movement_FaceUp
	waitmovement 0
	delay 30
	msgbox PokemonLaboratory_B2_Text_RaynerInhuman, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RAYNER_LAB2, PokemonLaboratory_B2_Movement_RaynerExit2
	waitmovement 0
	call PokemonLaboratory_B2_EventScript_MoveRaynerToLastDoor
	delay 30
	applymovement LOCALID_JACE_LAB2, PokemonLaboratory_B2_Movement_JaceExit2
	waitmovement 0
	call PokemonLaboratory_B2_EventScript_MoveJaceToLastDoor
	delay 60
	setvar VAR_WISTERIA_CITY_STATE, 8
	releaseall
	end

PokemonLaboratory_B2_Movement_PlayerEnter2:
	walk_up
	walk_up
	step_end

PokemonLaboratory_B2_Movement_RaynerExit2:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLaboratory_B2_Movement_JaceExit2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLaboratory_B2_Text_JaceLetMeGetThisStraight:
	.string "JACE: So let me get this straight.\p"
	.string "You're looking for TEAM GENESIS\n"
	.string "because you want to get revenge?$"

PokemonLaboratory_B2_Text_RaynerBasically:
	.string "??????: ...\p"
	.string "Basically, yeah.$"

PokemonLaboratory_B2_Text_JaceWhatDidTheyDo:
	.string "JACE: What did they do to you, anyway?$"

PokemonLaboratory_B2_Text_RaynerReallyWantToKnow:
	.string "You really want to know, huh?\p"
	.string "They took everything from me.\n"
	.string "My right to live itself.\p"
	.string "Those scientists and their\n"
	.string "insidious designs.\p"
	.string "Even after I left their stupid “daycare”,\n"
	.string "I could never get it back.\p"
	.string "I could never truly be free...$"

PokemonLaboratory_B2_Text_RaynerCantChange:
	.string "You see, there are some things\n"
	.string "that you just can't change.\p"
	.string "Not in this world anyway...\p"
	.string "But I will find a way to get\n"
	.string "back what I've lost.\p"
	.string "I'll burn TEAM GENESIS to the\n"
	.string "ground if I have to.$"

PokemonLaboratory_B2_Text_RaynerDangerous:
	.string "They always said we were too dangerous\n"
	.string "to be left to our own ends.\p"
	.string "Well, I'll show them just how\n"
	.string "dangerous I can be...\p"
	.string "I'll show them they had every\n"
	.string "right to be afraid of us...$"

PokemonLaboratory_B2_Text_JaceDontGetIt:
	.string "JACE: Well I don't really get it, but it\n"
	.string "sounds like they hurt you pretty bad.\p"
	.string "And it sounds like you don't like them\n"
	.string "or the methods they use.\p"
	.string "So I'm glad we're on the same page there.\p"
	.string "Those guys are cruel and inhuman.$"

PokemonLaboratory_B2_Text_RaynerInhuman:
	.string "??????: Heh, you know nothing\n"
	.string "about being inhuman.$"













PokemonLaboratory_B2_EventScript_RaynerEncounter6::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLaboratory_B2_Movement_PlayerEnter3
	waitmovement 0
	delay 30
	applymovement LOCALID_RAYNER_LAB2, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox PokemonLaboratory_B2_Text_RaynerNextDoor, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RAYNER_LAB2, PokemonLaboratory_B2_Movement_RaynerWalkToDoor
	waitmovement 0
	delay 120
	applymovement LOCALID_JACE_LAB2, Common_Movement_FaceRight
	waitmovement 0
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	delay 40
	msgbox PokemonLaboratory_B2_Text_GivesMeTheCreeps, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_JACE_LAB2, Common_Movement_FaceUp
	waitmovement 0
	delay 40
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	delay 180
	applymovement LOCALID_JACE_LAB2, Common_Movement_WalkUp
	waitmovement 0
	delay 60
	msgbox PokemonLaboratory_B2_Text_JaceWhatsYourName, MSGBOX_DEFAULT
	closemessage
	delay 120
	msgbox PokemonLaboratory_B2_Text_RaynerName, MSGBOX_DEFAULT
	closemessage
	delay 30
	@playse SE_M_METRONOME
	@applymovement LOCALID_JACE_LAB2, Common_Movement_QuestionMark
	delay 60
	msgbox PokemonLaboratory_B2_Text_JaceThatsANumber, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox PokemonLaboratory_B2_Text_RaynerFolks, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_JACE_LAB2, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox PokemonLaboratory_B2_Text_JaceMomAndDad, MSGBOX_DEFAULT
	closemessage
	delay 120
	msgbox PokemonLaboratory_B2_Text_RaynerFatherAndBrothers, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_JACE_LAB2, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox PokemonLaboratory_B2_Text_JaceBigFamily, MSGBOX_DEFAULT
	closemessage
	delay 120
	msgbox PokemonLaboratory_B2_Text_RaynerOneOtherName, MSGBOX_DEFAULT
	closemessage
	delay 30
	@playse SE_M_METRONOME
	@applymovement LOCALID_JACE_LAB2, Common_Movement_QuestionMark
	waitmovement 0
	delay 30
	msgbox PokemonLaboratory_B2_Text_JaceNiceToMeetYou, MSGBOX_DEFAULT
	closemessage
	delay 60
	playse SE_SUCCESS
	waitse
	playse SE_TRUCK_DOOR
	call PokemonLaboratory_B2_EventScript_OpenLastDoor
	special DrawWholeMapView
	delay 60
	applymovement LOCALID_RAYNER_LAB2, Common_Movement_FaceDown
	waitmovement 0
	delay 60
	msgbox PokemonLaboratory_B2_Text_RaynerShallWeContinue, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RAYNER_LAB2, PokemonLaboratory_B2_Movement_RaynerExit3
	waitmovement 0
	call PokemonLaboratory_B2_EventScript_MoveRaynerToEntityRoom
	playse SE_EXIT
	waitse
	applymovement LOCALID_JACE_LAB2, PokemonLaboratory_B2_Movement_JaceExit3
	waitmovement 0
	call PokemonLaboratory_B2_EventScript_MoveJaceToEntityRoom
	playse SE_EXIT
	@waitse
	delay 60
	setvar VAR_WISTERIA_CITY_STATE, 9
	releaseall
	end

PokemonLaboratory_B2_Movement_PlayerEnter3:
	walk_right
	walk_up
	walk_up
	step_end

PokemonLaboratory_B2_Movement_RaynerWalkToDoor:
	walk_left
	walk_left
	walk_up
	step_end

PokemonLaboratory_B2_Movement_RaynerExit3:
	walk_right
	walk_right
	walk_up
	step_end

PokemonLaboratory_B2_Movement_JaceExit3:
	walk_up
	walk_right
	walk_up
	walk_up
	step_end

PokemonLaboratory_B2_Text_RaynerNextDoor:
	.string "??????: Alright, this next door\n"
	.string "is a bit troublesome.\p"
	.string "It could take a while to get it open.\n"
	.string "Just sit back and relax for a bit.$"

PokemonLaboratory_B2_Text_GivesMeTheCreeps:
	.string "JACE: Man, this place really\n"
	.string "gives me the creeps.\p"
	.string "But it sounds like whatever's down here\n"
	.string "is our best shot at tracking down\l"
	.string "TEAM GENESIS.$"

PokemonLaboratory_B2_Text_JaceWhatsYourName:
	.string "JACE: By the way, I never\n"
	.string "introduced myself.\p"
	.string "I'm JACE from UMBER TOWN.\n"
	.string "What's your name?$"

PokemonLaboratory_B2_Text_RaynerName:
	.string "??????: ...\p"
	.string "My name?\p"
	.string "Heh, don't really have one.\p"
	.string "\p"
	.string "I guess you can call me 006.\n"
	.string "That's what some people call me.$"

PokemonLaboratory_B2_Text_JaceThatsANumber:
	.string "JACE: 006?\n"
	.string "That's a number, not a name.\p"
	.string "I mean, like, what do your folks call you?$"

PokemonLaboratory_B2_Text_RaynerFolks:
	.string "??????: ...\p"
	.string "Folks?$"

PokemonLaboratory_B2_Text_JaceMomAndDad:
	.string "JACE: You know, your mom and dad.\n"
	.string "Everybody has one of those.\p"
	.string "\p"
	.string "Do you not know your parents?\n"
	.string "Did something happen to them?$"

PokemonLaboratory_B2_Text_RaynerFatherAndBrothers:
	.string "??????: ...\p"
	.string "I know a man who could be called\n"
	.string "my father.\p"
	.string "And I guess that would make the\n"
	.string "rest of us “brothers.”$"

PokemonLaboratory_B2_Text_JaceBigFamily:
	.string "JACE: So your family's really big, huh?\n"
	.string "What do they all call you?$"

PokemonLaboratory_B2_Text_RaynerOneOtherName:
	.string "??????: There was one other thing\n"
	.string "my “father” called us.\p"
	.string "For a while, he called each of us RAYNER.$"

PokemonLaboratory_B2_Text_JaceNiceToMeetYou:
	.string "JACE: You and your brothers\n"
	.string "all had the same name?\p"
	.string "That's really weird...\p"
	.string "\p"
	.string "But RAYNER, huh?\p"
	.string "Now that sounds like a person's name.\n"
	.string "Nice to meet you!$"

PokemonLaboratory_B2_Text_RaynerShallWeContinue:
	.string "RAYNER: Shall we continue?$"










PokemonLaboratory_B2_EventScript_RaynerEncounter7::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLaboratory_B2_Movement_PlayerEnter4
	waitmovement 0
	delay 90
	applymovement LOCALID_RAYNER_LAB2, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox PokemonLaboratory_B2_Text_RaynerHereWeAre, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_JACE_LAB2, Common_Movement_FaceLeft
	waitmovement 0
	delay 30
	msgbox PokemonLaboratory_B2_Text_JaceWhatsInThere, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_RAYNER_LAB2, Common_Movement_FaceRight
	waitmovement 0
	delay 60
	msgbox PokemonLaboratory_B2_Text_CursedRoom1, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_RAYNER_LAB2, Common_Movement_FaceUp
	waitmovement 0
	delay 60
	msgbox PokemonLaboratory_B2_Text_CursedRoom2, MSGBOX_DEFAULT
	closemessage
	@applymovement LOCALID_JACE_LAB2, Common_Movement_ExclamationMark
	@playse SE_PIN
	applymovement LOCALID_JACE_LAB2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_JACE_LAB2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PokemonLaboratory_B2_Text_NotGoingInThere, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_RAYNER_LAB2, Common_Movement_FaceRight
	waitmovement 0
	delay 60
	msgbox PokemonLaboratory_B2_Text_SomeoneMustGo, MSGBOX_DEFAULT
	closemessage
	delay 90
	applymovement LOCALID_RAYNER_LAB2, Common_Movement_FaceDown
	waitmovement 0
	delay 60
	msgbox PokemonLaboratory_B2_Text_HowAboutYou, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, YES, PokemonLaboratory_B2_EventScript_PlayerWantsToGo
	goto_if_eq VAR_RESULT, NO, PokemonLaboratory_B2_EventScript_PlayerDoesntWantToGo
	end



PokemonLaboratory_B2_EventScript_PlayerWantsToGo::
	msgbox PokemonLaboratory_B2_Text_IKnewYouWould, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_RAYNER_LAB2, Common_Movement_FaceUp
	waitmovement 0
	delay 30
	msgbox PokemonLaboratory_B2_Text_AfterYou, MSGBOX_DEFAULT
	closemessage
	delay 30
	setvar VAR_WISTERIA_CITY_STATE, 10
	releaseall
	end

PokemonLaboratory_B2_EventScript_PlayerDoesntWantToGo::
	msgbox PokemonLaboratory_B2_Text_DrawLots, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	delay 30
	applymovement LOCALID_RAYNER_LAB2, Common_Movement_FaceRight
	waitmovement 0
	delay 30
	applymovement LOCALID_JACE_LAB2, Common_Movement_WalkLeft
	waitmovement 0
	delay 30
	applymovement LOCALID_RAYNER_LAB2, Common_Movement_FaceDown
	waitmovement 0
	delay 60
	msgbox PokemonLaboratory_B2_Text_ToughLuck, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_JACE_LAB2, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_JACE_LAB2, Common_Movement_FaceLeft
	waitmovement 0
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	delay 30
	applymovement LOCALID_JACE_LAB2, Common_Movement_WalkUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_JACE_LAB2, Common_Movement_WalkRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_RAYNER_LAB2, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_JACE_LAB2, Common_Movement_FaceLeft
	waitmovement 0
	delay 60
	applymovement LOCALID_JACE_LAB2, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox PokemonLaboratory_B2_Text_BeCareful, MSGBOX_DEFAULT
	closemessage
	delay 60
	setvar VAR_WISTERIA_CITY_STATE, 10
	releaseall
	end

PokemonLaboratory_B2_EventScript_Rayner::
	msgbox PokemonLaboratory_B2_Text_AfterYou, MSGBOX_NPC
	closemessage
	end

PokemonLaboratory_B2_EventScript_Jace::
	msgbox PokemonLaboratory_B2_Text_BeCareful, MSGBOX_NPC
	closemessage
	end

PokemonLaboratory_B2_Movement_PlayerEnter4:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLaboratory_B2_Text_RaynerHereWeAre:
	.string "RAYNER: And here we are.\p"
	.string "The machines we're after are\n"
	.string "just inside that room.\p"
	.string "Go ahead and grab one.\p"
	.string "If you think you can make it\n"
	.string "in time, that is.$"

PokemonLaboratory_B2_Text_JaceWhatsInThere:
	.string "JACE: What do you mean?\n"
	.string "What's in there?$"

PokemonLaboratory_B2_Text_CursedRoom1:
	.string "RAYNER: Who knows.\p"
	.string "Some say it's a trap left by the\n"
	.string "scientists who used to work here.\p"
	.string "Others say it's something they awakened\n"
	.string "from deep in Ultra Space.\p"
	.string "And some say it's the unfortunate souls\n"
	.string "themselves from that fateful day.$"

PokemonLaboratory_B2_Text_CursedRoom2:
	.string "RAYNER: Whatever's in there, it's\n"
	.string "guarding the machines we need.\p"
	.string "I've never been inside myself, but I've\n"
	.string "seen plenty of people try before...\p"
	.string "\p"
	.string "Of course, they were all careless fools.\p"
	.string "Some of them couldn't even\n"
	.string "make it this far.\p"
	.string "It seems to react differently to\n"
	.string "different people.\p"
	.string "\p"
	.string "Well, why don't you try it?\n"
	.string "If you're brave enough, that is.$"

PokemonLaboratory_B2_Text_NotGoingInThere:
	.string "JACE: I'm not going in there!\n"
	.string "You go in there!$"

PokemonLaboratory_B2_Text_SomeoneMustGo:
	.string "RAYNER: Sigh. Well, one of us has to go\n"
	.string "for us to make any progress...$"

PokemonLaboratory_B2_Text_HowAboutYou:
	.string "How about you, {PLAYER}?\n"
	.string "You want to be useful, right?$"

PokemonLaboratory_B2_Text_IKnewYouWould:
	.string "RAYNER: Hehehehehehe.\n"
	.string "I knew you would.$"

PokemonLaboratory_B2_Text_AfterYou:
	.string "RAYNER: After you.$"

PokemonLaboratory_B2_Text_DrawLots:
	.string "RAYNER: Sigh. It looks like\n"
	.string "we'll have to draw lots.\p"
	.string "Short straw goes first.$"

PokemonLaboratory_B2_Text_ToughLuck:
	.string "RAYNER: Uh-oh.\p"
	.string "Tough luck, {PLAYER}.$"

PokemonLaboratory_B2_Text_BeCareful:
	.string "JACE: Be careful, {PLAYER}.\p"
	.string "Don't worry. If things look bad,\n"
	.string "I'll be here to pull you out.$"




