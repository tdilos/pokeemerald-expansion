.set LOCALID_JACE, 7
.set LOCALID_RAYNER, 8

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
	addobject LOCALID_JACE
	return

PokemonLaboratory_B2_EventScript_AddRayner:
	clearflag FLAG_HIDE_RAYNER
	addobject LOCALID_RAYNER
	return

PokemonLaboratory_B2_EventScript_MoveJaceToCatwalk:
	removeobject LOCALID_JACE
	setobjectxyperm LOCALID_JACE, 33, 31
	setobjectmovementtype LOCALID_JACE, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_JACE
	addobject LOCALID_JACE
	return

PokemonLaboratory_B2_EventScript_MoveRaynerToCatwalk:
	removeobject LOCALID_RAYNER
	setobjectxyperm LOCALID_RAYNER, 33, 28
	setobjectmovementtype LOCALID_RAYNER, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_RAYNER
	addobject LOCALID_RAYNER
	return

PokemonLaboratory_B2_EventScript_MoveJaceToLastDoor:
	removeobject LOCALID_JACE
	setobjectxyperm LOCALID_JACE, 36, 5
	setobjectmovementtype LOCALID_JACE, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_JACE
	addobject LOCALID_JACE
	return

PokemonLaboratory_B2_EventScript_MoveRaynerToLastDoor:
	removeobject LOCALID_RAYNER
	setobjectxyperm LOCALID_RAYNER, 37, 3
	setobjectmovementtype LOCALID_RAYNER, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_RAYNER
	addobject LOCALID_RAYNER
	return

PokemonLaboratory_B2_EventScript_MoveJaceToEntityRoom:
	removeobject LOCALID_JACE
	setobjectxyperm LOCALID_JACE, 9, 26
	setobjectmovementtype LOCALID_JACE, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_JACE
	addobject LOCALID_JACE
	return

PokemonLaboratory_B2_EventScript_MoveRaynerToEntityRoom:
	removeobject LOCALID_RAYNER
	setobjectxyperm LOCALID_RAYNER, 7, 26
	setobjectmovementtype LOCALID_RAYNER, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_RAYNER
	addobject LOCALID_RAYNER
	return

PokemonLaboratory_B2_EventScript_RemoveJace:
	setflag FLAG_HIDE_JACE
	removeobject LOCALID_JACE
	return

PokemonLaboratory_B2_EventScript_RemoveRayner:
	setflag FLAG_HIDE_RAYNER
	removeobject LOCALID_RAYNER
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
	applymovement LOCALID_RAYNER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	delay 30
	msgbox PokemonLaboratory_B2_Text_RaynerTakesOffGlasses, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox PokemonLaboratory_B2_Text_JaceGlassesInTheDark, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_RAYNER, Common_Movement_FaceLeft
	waitmovement 0
	delay 60
	msgbox PokemonLaboratory_B2_Text_RaynerSensitiveEyes, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox PokemonLaboratory_B2_Text_JaceWhyAreYouHere, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_RAYNER, Common_Movement_FaceRight
	waitmovement 0
	delay 60
	msgbox PokemonLaboratory_B2_Text_RaynerScoreToSettle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RAYNER, PokemonLaboratory_B2_Movement_RaynerExit
	waitmovement 0
	call PokemonLaboratory_B2_EventScript_RemoveRayner
	applymovement LOCALID_JACE, PokemonLaboratory_B2_Movement_JaceExit
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
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox PokemonLaboratory_B2_Text_JaceLetMeGetThisStraight, MSGBOX_DEFAULT
	closemessage
	delay 90
	msgbox PokemonLaboratory_B2_Text_RaynerBasically, MSGBOX_DEFAULT
	closemessage
	delay 30
	@applymovement LOCALID_JACE, Common_Movement_WalkInPlaceUp
	@waitmovement 0
	msgbox PokemonLaboratory_B2_Text_JaceWhatDidTheyDo, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_RAYNER, Common_Movement_FaceDown
	waitmovement 0
	delay 60
	msgbox PokemonLaboratory_B2_Text_RaynerReallyWantToKnow, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_RAYNER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox PokemonLaboratory_B2_Text_RaynerCantChange, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_RAYNER, Common_Movement_FaceUp
	waitmovement 0
	delay 60
	msgbox PokemonLaboratory_B2_Text_RaynerDangerous, MSGBOX_DEFAULT
	closemessage
	delay 120
	playse SE_M_METRONOME
	applymovement LOCALID_JACE, Common_Movement_QuestionMark
	delay 60
	msgbox PokemonLaboratory_B2_Text_JaceDontGetIt, MSGBOX_DEFAULT
	closemessage
	delay 90
	applymovement LOCALID_RAYNER, Common_Movement_FaceDown
	waitmovement 0
	delay 120
	applymovement LOCALID_RAYNER, Common_Movement_FaceUp
	waitmovement 0
	delay 30
	msgbox PokemonLaboratory_B2_Text_RaynerInhuman, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RAYNER, PokemonLaboratory_B2_Movement_RaynerExit2
	waitmovement 0
	call PokemonLaboratory_B2_EventScript_MoveRaynerToLastDoor
	delay 30
	applymovement LOCALID_JACE, PokemonLaboratory_B2_Movement_JaceExit2
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
	@.string "You're here because TEAM GENESIS\n"
	@.string "did something to you.\p"
	@.string "And now you want to get revenge?$"
	.string "You're looking for TEAM GENESIS\n"
	.string "because you want to get revenge?$"

PokemonLaboratory_B2_Text_RaynerBasically:
	.string "??????: ...\p"
	@.string "\p"
	.string "Basically, yeah.$"

PokemonLaboratory_B2_Text_JaceWhatDidTheyDo:
	.string "JACE: What did they do to you, anyway?$"

@PokemonLaboratory_B2_Text_RaynerRatherNotTalk:
@	.string "??????: ...\p"
@	.string "I'd rather not talk about it.$"

PokemonLaboratory_B2_Text_RaynerReallyWantToKnow:
	.string "You really want to know, huh?\p"
	.string "They took everything from me.\n"
	.string "My right to live itself.\p"
	.string "Those scientists and their\n"
	.string "insidious designs.\p"
	.string "Even after I left their stupid “daycare”,\n"
	.string "I could never get it back.\p"
	.string "I could never truly be free...$"


	@.string "They stole my right to exist.\p"
	@.string "They took everything from me.\n"
	@.string "My own existence is a sin to them.\p"
	@.string "First they said we were too costly.\n"
	@.string "Then they said we were dangerous.\p"
	@.string "Those scientists and their\n"
	@.string "wretched designs.\p"
	@.string "Thanks to them, I can never be free.\n"
	@.string "Thanks to them, I'm “incomplete.”$"
	@.string "I just wanted to live a normal life\n"
	@.string "like anybody else.\p"
	@.string "I just wanted to live life like\n"
	@.string "everybody else.\p"
	@.string "I just wanted to “graduate” from\n"
	@.string "their stupid daycare.\p"
	@.string "But they never intended on\n"
	@.string "letting us go.\p"
	@.string "Even after I escaped, I was\n"
	@.string "never truly free from them.\p"
	@.string "That's why I'm going to take\n"
	@.string "them apart in my own way.\p"
	@.string "With the same surgical precision\n"
	@.string "they used on me...$"


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



@PokemonLaboratory_B2_Text_JaceItsOkay:
@	.string "JACE: Oh no, it's okay.\n"
@	.string "I didn't realize it was like that...\p"
@	.string "I'm just glad we're on the same page\n"
@	.string "about TEAM GENESIS.\p"
@	.string "Those guys are cruel and inhuman!$"

PokemonLaboratory_B2_Text_JaceDontGetIt:
	.string "JACE: Well I don't really get it, but it\n"
	.string "sounds like they hurt you pretty bad.\p"
	.string "And it sounds like you don't like them\n"
	@.string "and what they do to people.\p"
	.string "or the methods they use.\p"
	@.string "or the things they do to people.\p"
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
	applymovement LOCALID_RAYNER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox PokemonLaboratory_B2_Text_RaynerNextDoor, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RAYNER, PokemonLaboratory_B2_Movement_RaynerWalkToDoor
	waitmovement 0
	delay 120
	applymovement LOCALID_JACE, Common_Movement_FaceRight
	waitmovement 0
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	delay 40
	msgbox PokemonLaboratory_B2_Text_GivesMeTheCreeps, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_JACE, Common_Movement_FaceUp
	waitmovement 0
	delay 40
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	delay 180
	applymovement LOCALID_JACE, Common_Movement_WalkUp
	waitmovement 0
	delay 60
	msgbox PokemonLaboratory_B2_Text_JaceWhatsYourName, MSGBOX_DEFAULT
	closemessage
	delay 120
	msgbox PokemonLaboratory_B2_Text_RaynerName, MSGBOX_DEFAULT
	closemessage
	delay 30
	@playse SE_M_METRONOME
	@applymovement LOCALID_JACE, Common_Movement_QuestionMark
	delay 60
	msgbox PokemonLaboratory_B2_Text_JaceThatsANumber, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox PokemonLaboratory_B2_Text_RaynerFolks, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox PokemonLaboratory_B2_Text_JaceMomAndDad, MSGBOX_DEFAULT
	closemessage
	delay 120
	msgbox PokemonLaboratory_B2_Text_RaynerFatherAndBrothers, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox PokemonLaboratory_B2_Text_JaceBigFamily, MSGBOX_DEFAULT
	closemessage
	delay 120
	msgbox PokemonLaboratory_B2_Text_RaynerOneOtherName, MSGBOX_DEFAULT
	closemessage
	delay 30
	@playse SE_M_METRONOME
	@applymovement LOCALID_JACE, Common_Movement_QuestionMark
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
	applymovement LOCALID_RAYNER, Common_Movement_FaceDown
	waitmovement 0
	delay 60
	msgbox PokemonLaboratory_B2_Text_RaynerShallWeContinue, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RAYNER, PokemonLaboratory_B2_Movement_RaynerExit3
	waitmovement 0
	call PokemonLaboratory_B2_EventScript_MoveRaynerToEntityRoom
	playse SE_EXIT
	waitse
	applymovement LOCALID_JACE, PokemonLaboratory_B2_Movement_JaceExit3
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
	@.string "But this sounds like our best bet at\n"
	@.string "tracking down TEAM GENESIS.$"
	.string "But it sounds like whatever's down here\n"
	.string "is our best shot at tracking down\l"
	.string "TEAM GENESIS.$"

PokemonLaboratory_B2_Text_JaceWhatsYourName:
	.string "JACE: By the way, I never\n"
	.string "introduced myself.\p"
	.string "I'm JACE from UMBER TOWN.\n"
	.string "What's your name?$"

PokemonLaboratory_B2_Text_RaynerName:
	@.string "\p"
	.string "??????: ...\p"
	.string "My name?\p"
	@.string "\p"
	.string "Heh, don't really have one.\p"
	.string "\p"
	.string "I guess you can call me 006.\n"
	.string "That's what some people call me.$"

PokemonLaboratory_B2_Text_JaceThatsANumber:
	.string "JACE: 006?\n"
	.string "That's a number, not a name.\p"
	.string "I mean, like, what do your folks call you?$"

PokemonLaboratory_B2_Text_RaynerFolks:
	@.string "\p"
	.string "??????: ...\p"
	.string "Folks?$"

PokemonLaboratory_B2_Text_JaceMomAndDad:
	.string "JACE: You know, your mom and dad.\n"
	.string "Everybody has one of those.\p"
	.string "\p"
	@.string "Do you not know who your parents are?$"
	.string "Do you not know your parents?\n"
	.string "Did something happen to them?$"

PokemonLaboratory_B2_Text_RaynerFatherAndBrothers:
	@.string "\p"
	.string "??????: ...\p"
	.string "I know a man who could be called\n"
	.string "my father.\p"
	@.string "And the rest of us, I guess that\n"
	@.string "makes us all brothers...$"
	.string "And I guess that would make the\n"
	.string "rest of us “brothers.”$"

PokemonLaboratory_B2_Text_JaceBigFamily:
	@.string "So you come from a really big family, huh?\n"
	@.string "So your family's really big, huh?\n"
	@.string "Sounds like you have a big family then.\n"
	@.string "JACE: Brothers, huh?\n"
	@.string "I have two little sisters myself.\p"
	@.string "\p"
	@.string "So that's your family then.\n"
	.string "JACE: So your family's really big, huh?\n"
	.string "What do they all call you?$"

PokemonLaboratory_B2_Text_RaynerOneOtherName:
	@.string "??????: ...\p"
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
	applymovement LOCALID_RAYNER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox PokemonLaboratory_B2_Text_RaynerHereWeAre, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_JACE, Common_Movement_FaceLeft
	waitmovement 0
	delay 30
	msgbox PokemonLaboratory_B2_Text_JaceWhatsInThere, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_RAYNER, Common_Movement_FaceRight
	waitmovement 0
	delay 60
	msgbox PokemonLaboratory_B2_Text_CursedRoom1, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_RAYNER, Common_Movement_FaceUp
	waitmovement 0
	delay 60
	msgbox PokemonLaboratory_B2_Text_CursedRoom2, MSGBOX_DEFAULT
	closemessage
	@applymovement LOCALID_JACE, Common_Movement_ExclamationMark
	@playse SE_PIN
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PokemonLaboratory_B2_Text_NotGoingInThere, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_RAYNER, Common_Movement_FaceRight
	waitmovement 0
	delay 60
	msgbox PokemonLaboratory_B2_Text_SomeoneMustGo, MSGBOX_DEFAULT
	closemessage
	delay 90
	applymovement LOCALID_RAYNER, Common_Movement_FaceDown
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
	applymovement LOCALID_RAYNER, Common_Movement_FaceUp
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
	applymovement LOCALID_RAYNER, Common_Movement_FaceRight
	waitmovement 0
	delay 30
	applymovement LOCALID_JACE, Common_Movement_WalkLeft
	waitmovement 0
	delay 30
	applymovement LOCALID_RAYNER, Common_Movement_FaceDown
	waitmovement 0
	delay 60
	msgbox PokemonLaboratory_B2_Text_ToughLuck, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_JACE, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_FaceLeft
	waitmovement 0
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	delay 30
	applymovement LOCALID_JACE, Common_Movement_WalkUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_JACE, Common_Movement_FaceLeft
	waitmovement 0
	delay 60
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceLeft
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
















@Rayner believes it's his destiny to usher in a new age,
@one where old lifeforms are obsolete.
@Committing genocide out of pure malice while justifying it with Darwinism



@PokemonLaboratory_B2_Text_RaynerVictorious:
@	.string "The sting of defeat.\p"
@	.string "Hurts doesn't it?\p"
@	.string "It's the pain we need to keep us going.\n"
@	.string "It drives us to surpass ourselves.\l"
@	.string "It makes us feel alive!\p"
@	.string "You know exactly what I mean,\n"
@	.string "don't you {PLAYER}?$"

@PokemonLaboratory_B2_Text_RaynerDefeated:
@	.string "The sting of defeat.\p"
@	.string "It hurts sooo gooood!\p"
@	.string "It's the pain we need to keep us going.\n"
@	.string "It drives us to surpass ourselves.\l"
@	.string "It makes us feel alive!\p"
@	.string "You know exactly what I mean,\n"
@	.string "don't you {PLAYER}?$"







@PokemonLaboratory_B2_Text_RaynerLostPostBattle:
@	.string "Gotta say, I'm impressed.\p"
@	.string "I didn't think you guys would be\n"
@	.string "able to get past this team.\p"
@	.string "Especially when you insist on\n"
@	.string "handicapping yourselves.$"

@PokemonLaboratory_B2_Text_JaceHandicap:
@	.string "Handicap? What are you talking about?$"

@PokemonLaboratory_B2_Text_RaynerSpellItOut:
@	.string "What, you need me to spell\n"
@	.string "it out to you?\p"
@	.string "$"

@PokemonLaboratory_B2_Text_RaynerIdk4:
@	.string "Love is a weakness I don't need.\p"
@	.string "I've learned to let go of things\n"
@	.string "like that.$"







@PokemonLaboratory_B2_Text_RaynerIdk1:
@	.string "You see, {PLAYER}. The last time we met,\n"
@	.string "I was able to sweettalk my way\l"
@	.string "into getting this.\p"
@	.string "The antibodies to the virus.\p"
@	.string "Now TEAM GENESIS has nothing on me.\n"
@	.string "Now I will show them who's really superior.$"

@PokemonLaboratory_B2_Text_JaceIdk1:
@	.string "$"

@PokemonLaboratory_B2_Text_RaynerIdk2:
@	.string "So what if they do?$"

@PokemonLaboratory_B2_Text_JaceIdk2:
@	.string "You can't just go around hurting innocent people!$"

@PokemonLaboratory_B2_Text_RaynerIdk3:
@	.string "Hehehe. The weak don't get to decide what\n"
@	.string "happens to them.$"






@PokemonLaboratory_B2_Text_JaceCantBelieve:
@	.string "Grrrrr! I can't believe you're\n"
@	.string "working for TEAM GENESIS!\p"
@	.string "I thought you hated them!$"

@PokemonLaboratory_B2_Text_RaynerPowerless:
@	.string "RAYNER: I do hate them.\p"
@	.string "For a long time, I didn't have a choice.\n"
@	.string "Back then, I was powerless...$"

@PokemonLaboratory_B2_Text_RaynerCured:
@	.string "But things are different now.\p"
@	.string "I finally found a way to cure myself\n"
@	.string "of the “curse” they gave me.\p"
@	.string "And soon, I'll be the one with\n"
@	.string "all the power in the world!$"
 
@PokemonLaboratory_B2_Text_JaceCallsOutRayner:
@	.string "I don't know what you're\n"
@	.string "talking about, dude.\p"
@	.string "But it sounds like the kind of thing\n"
@	.string "TEAM GENESIS would want too.\p"
@	.string "You said you want to get revenge on them,\n"
@	.string "but you're acting just like them!$"






@PokemonLaboratory_B2_Text_RaynerNotLikeThem:
@	.string "Hehehehehe. Don't think for a second\n"
@	.string "that I'm anything like them.\p"
@	.string "They're all fools who hide behind\n"
@	.string "threats and borrowed power.\p"
@	.string "I'm something else entirely.\n"
@	.string "Something more evolved, you could say.$"

@PokemonLaboratory_B2_Text_RaynerGoals:
@	.string "In any case, their goals happen to\n"
@	.string "align with mine right now.\p"
@	.string "Once I bring them this machine, they'll\n"
@	.string "be able to complete their master plan.\p"
@	.string "Hehehehehehe. Too bad for the people\n"
@	.string "in XANTHOS CITY.\p"
@	.string "I'm sure a lot of them will get hurt.$"

@PokemonLaboratory_B2_Text_JaceXanthosCity:
@	.string "XANTHOS CITY? What do you mean?\n"
@	.string "What's gonna happen there?$"

@PokemonLaboratory_B2_Text_RaynerOops:
@	.string "Oops, didn't mean to say\n"
@	.string "that part out loud.\p"
@	.string "Since you know now, I might as\n"
@	.string "well tell you the rest.\p"
@	.string "TEAM GENESIS is hiding beneath\n"
@	.string "XANTHOS CITY.\p"
@	.string "They've created another facility\n"
@	.string "just like this one.\p"
@	.string "And they're planning to make another\n"
@	.string "bridge to Ultra Space.\p"
@	.string "If it's anything like what happened\n"
@	.string "last time...\p"
@	.string "Hehehehehehehe.\n"
@	.string "Well, you saw this place.$"


@PokemonLaboratory_B2_Text_JaceWhy:
@	.string "So you're gonna take that to them\n"
@	.string "just so they can destroy the city?!\p"
@	.string "Why!? What do you get from\n"
@	.string "going after innocent people?!$"

@PokemonLaboratory_B2_Text_RaynerNotMyGoal:
@	.string "Oh no, that's not my goal at all.$"

@PokemonLaboratory_B2_Text_JaceWhatIsYourGoal:
@	.string "JACE: Then what is your goal?$"

@PokemonLaboratory_B2_Text_RaynerPower:
@	.string "Power.\n"
@	.string "True power.\p"
@	.string "Somewhere deep in Ultra Space is\n"
@	.string "the power I've been looking for.\p"
@	.string "The power to destroy to TEAM GENESIS.\n"
@	.string "And anyone else that displeases me.\p"
@	.string "I'll be the most powerful trainer\n"
@	.string "in the world!$"

@PokemonLaboratory_B2_Text_JaceChampion:
@	.string "JACE: And then what? You'll use it to\n"
@	.string "terrorize people like TEAM GENESIS?\p"
@	.string "Just because you're the strongest doesn't\n"
@	.string "give you the right to hurt other people!\p"
@	.string "A champion is somebody who fights for\n"
@	.string "people who can't fight for themselves!$"

@PokemonLaboratory_B2_Text_RaynerDoesntCare:
@	.string "Whatever. I don't care about\n"
@	.string "empty titles.\p"
@	.string "Action is all that matters.\p"
@	.string "I will destroy TEAM GENESIS myself.\n"
@	.string "The fate of XANTHOS CITY I leave to you.\p"
@	.string "Try to stop us first, if you can.\n"
@	.string "It should make things more fun.$"

@PokemonLaboratory_B2_Text_JaceCantBelieve2:
@	.string "\p"
@	.string "I can't believe you want to play with\n"
@	.string "innocent people's lives like this.\p"
@	.string "Don't you see you're hurting people\n"
@	.string "just like TEAM GENESIS hurt you?$"

@PokemonLaboratory_B2_Text_RaynerWeakDontDecide:
@	.string "That's just how the world works.\p"
@	.string "The weak don't get to decide\n"
@	.string "what happens to them.\p"
@	.string "They'll adapt or perish.\n"
@	.string "It's as simple as that.\p"
@	.string "And if you care that much,\n"
@	.string "then just try to stop us.$"





@PokemonLaboratory_B2_Text_JaceToPlayer:
@	.string "JACE: That guy was really messed up.\p"
@	.string "I can't believe he wants to help\n"
@	.string "TEAM GENESIS!$"

@PokemonLaboratory_B2_Text_JaceToPlayer2:
@	.string "Well if we're gonna go after them,\n"
@	.string "we're gonna need backup.\p"
@	.string "Let's take this machine back to\n"
@	.string "JUSTIN and the POKéMON RANGERS.$"






@PokemonLaboratory_B2_Text_RaynerOptionToFight:
@	.string "Well {PLAYER}?\n"
@	.string "Shall I remind you of the pain you felt that day?$"

@PokemonLaboratory_B2_Text_FightRayner:
@	.string "$"

@PokemonLaboratory_B2_Text_DontFightRayner:
@	.string "Yeah, that's what I thought.\p"
@	.string "God, you're so pathetic.$"

@PokemonLaboratory_B2_Text_JaceTriesToFight:
@	.string "$"

@PokemonLaboratory_B2_Text_RaynerRefuses:
@	.string "I'm afraid I must decline.\n"
@	.string "I've already lost my appetite to battle.\p"
@	.string "And I have more important things\n"
@	.string "to do right now.\p"
@	.string "If it's a fight you want, come join us\n"
@	.string "in XANTHOS CITY.$"











@PokemonLaboratory_B2_Text_Rayner8:
@	.string "I'm just doing to others what\n"
@	.string "they've done to me.\p"
@	.string "Isn't that justice?$"
	
@PokemonLaboratory_B2_Text_Jace8:
@	.string "Well, sure I guess. But a lot of innocent\n"
@	.string "people could get hurt too.$"



@PokemonLaboratory_B2_Text_Jace9:
@	.string "You know for someone who hates\n"
@	.string "TEAM GENESIS, you\l"
@	.string "sound a lot like them.$"

@PokemonLaboratory_B2_Text_Rayner9:
@	.string "Well if there's one thing I've\n"
@	.string "learned from them, it's this.\p"
@	.string "Might makes right.\p"
@	.string "The weak don't get to decide what\n"
@	.string "happens to them.\p"
@	.string "$"







@PokemonLaboratory_B2_EventScript_DoEntityBattle::
@	closemessage
@	setvar VAR_0x8004, SPECIAL_BATTLE_POKEMON_LABORATORY_ENTITY
@	setvar VAR_0x8005, 0
@	special DoSpecialTrainerBattle
@	waitstate
@	return

@PokemonLaboratory_B2_EventScript_OpponentEnter::
@	@tower_setopponent
@	addobject LOCALID_JACE
@	applymovement LOCALID_JACE, BattleFrontier_BattleTowerBattleRoom_Movement_OpponentEnter
@	waitmovement 0
@	tower_getopponentintro 0
@	msgbox PokemonLaboratory_B2_Text_OminousPresence, MSGBOX_DEFAULT
@	waitmessage
@	call PokemonLaboratory_B2_EventScript_DoEntityBattle
@	switch VAR_RESULT
@	case B_OUTCOME_WON, PokemonLaboratory_B2_EventScript_DefeatedEntity
@
@	@frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
@	@tower_set TOWER_DATA_LVL_MODE
@	end


PokemonLaboratory_B2_EventScript_EntityBattle::
	msgbox PokemonLaboratory_B2_Text_OminousPresence, MSGBOX_DEFAULT
	closemessage
	@trainerkarmabattle_no_intro TRAINER_POKEMON_LABORATORY_ENTITY, PokemonLaboratory_B2_Text_EntityDefeated
	trainerbattle_no_intro TRAINER_POKEMON_LABORATORY_ENTITY, PokemonLaboratory_B2_Text_EntityDefeated
	goto PokemonLaboratory_B2_EventScript_DefeatedEntity
	end

PokemonLaboratory_B2_EventScript_DefeatedEntity::
	msgbox PokemonLaboratory_B2_Text_EntitiesVanished, MSGBOX_DEFAULT
	waitmessage
	addobject LOCALID_JACE
	applymovement LOCALID_JACE, PokemonLaboratory_B2_Movement_JaceEntersEntityRoom
	waitmovement 0
	msgbox PokemonLaboratory_B2_Text_JaceHey, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JACE, Common_Movement_FaceRight
	waitmovement 0
	delay 60
	applymovement LOCALID_JACE, Common_Movement_FaceUp
	waitmovement 0
	msgbox PokemonLaboratory_B2_Text_JaceGreatWork, MSGBOX_DEFAULT
	addobject LOCALID_RAYNER
	applymovement LOCALID_RAYNER, PokemonLaboratory_B2_Movement_RaynerEntersEntityRoom
	waitmovement 0
	delay 60
	applymovement LOCALID_RAYNER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox PokemonLaboratory_B2_Text_RaynerTakesLostTech, MSGBOX_DEFAULT
	closemessage
	delay 20
	removeobject LOCALID_BLACKBALL1
	delay 40
	applymovement LOCALID_RAYNER, Common_Movement_FaceDown
	waitmovement 0

	end

PokemonLaboratory_B2_Movement_JaceEntersEntityRoom:
	walk_up
	walk_up
	walk_up
	step_end

PokemonLaboratory_B2_Movement_RaynerEntersEntityRoom:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLaboratory_B2_Text_OminousPresence:
	.string "An ominous presence surrounds you.$"

PokemonLaboratory_B2_Text_EntityDefeated:
	.string "...$"

PokemonLaboratory_B2_Text_EntitiesVanished:
	.string "The entities vanished!$"

PokemonLaboratory_B2_Text_JaceHey:
	.string "Hey {PLAYER}, you're alright!$"

PokemonLaboratory_B2_Text_JaceGreatWork:
	.string "That was intense whatever that was.\p"
	.string "But it looks like you managed to\n"
	.string "fight it off. Great work!$"

PokemonLaboratory_B2_Text_RaynerTakesLostTech:
	.string "RAYNER: Yes, well done.\p"
	.string "I figured a sentimental type like you\n"
	.string "would have the best chance against it.\p"
	.string "Looks like you are good for something\n"
	.string "after all.$"
	@.string "Gotta say, I'm impressed, {PLAYER}.\n"
	@.string "I didn't think you had it in you.$"

PokemonLaboratory_B2_Text_RaynerTakesLostTech2:
	.string "Now then, I'll be taking this with me\n"
	.string "back to TEAM GENESIS.\p"
	.string "You're free to hold onto the other part,\n"
	.string "just so you know.$"

PokemonLaboratory_B2_Text_JaceWhatAreYouSaying:
	.string "Taking it back to TEAM GENESIS?!\n"
	.string "What are you talking about?!$"

PokemonLaboratory_B2_Text_RaynerPlayedYou:
	.string "RAYNER: I'm saying I played you, idiot.\p"
	.string "TEAM GENESIS needs this LOST TECH\n"
	.string "to complete their plan.\p"
	.string "And I'm going to deliver to them.\p"
	.string "I just needed someone to remove that\n"
	.string "thing guarding this room.\p"
	.string "And you two came along just in time.$"

PokemonLaboratory_B2_Text_JaceYoureWithTeamGenesis:
	.string "You mean you've been working for\n"
	.string "TEAM GENESIS this whole time?!$"


PokemonLaboratory_B2_Text_RaynerYup:
	.string "Yup.\p"
	.string "Bet you feel pretty stupid now, huh?$"

PokemonLaboratory_B2_Text_JaceScrewYou:
	.string "Screw you, dude!\n"
	.string "You're not making any sense!\p"
	.string "First you say you hate TEAM GENESIS.\n"
	.string "And now you're working with them?!\p"
	.string "Was all that stuff from before\n"
	.string "just lies?$"

PokemonLaboratory_B2_Text_RaynerNotLikeThat:
	.string "Oh, don't get me wrong.\n"
	.string "I never lied about anything.\p"
	.string "It's true that I hate TEAM GENESIS.\p"
	.string "It's true that I've been working\n"
	.string "for them.\p"
	.string "And it's true that device next to you\n"
	.string "can take you to their hideout.\p"
	.string "I'll even tell you where it is.\n"
	.string "But only if you ask me nicely.$"

PokemonLaboratory_B2_Text_JaceWorkingForTeamGenesis:
	.string "JACE: So you're working for TEAM GENESIS\n"
	.string "even though you hate them, huh?$"

PokemonLaboratory_B2_Text_RaynerDidntHaveChoice:
	.string "RAYNER: It's not like I wanted to.\n"
	.string "They have a certain leverage over me.$"

PokemonLaboratory_B2_Text_JaceWhatsThat:
	.string "JACE: And what's that?$"

PokemonLaboratory_B2_Text_RaynerRetroviruses:
	.string "Ever heard of endogenous retroviruses?$"

PokemonLaboratory_B2_Text_JaceWhat:
	.string "JACE: Endogewhat?$"

PokemonLaboratory_B2_Text_RaynerExplainsVirus:
	@.string "Sigh. Think of it like a disease that\n"
	@.string "everyone is born with.\p"
	@.string "Only for most people, it's not\n"
	@.string "really a disease.\p"
	.string "Sigh. Think of it like a disease only\n"
	.string "you don't get sick from it.\p"
	.string "Except for people like me.\p"
	.string "For us, it's constant and painful.\n"
	.string "And debilitative in the long term.\p"
	.string "I need constant medication to suppress it.\n"
	.string "And TEAM GENESIS has the only supply.\p"
	.string "Well, they did anyway...$"

PokemonLaboratory_B2_Text_RaynerDoYouRemember:
	.string "Remember the last time we met, {PLAYER}?\n"
	.string "At the mansion in MINDARO CITY.\p"
	.string "It was then that I finally found\n"
	.string "my own supply.\p"
	.string "Now TEAM GENESIS only thinks that\n"
	.string "they control me.\p"
	.string "Now I'm just biding my time.$"

PokemonLaboratory_B2_Text_RaynerIncomplete:
	.string "You see, none of this is a\n"
	.string "permanent solution.\p"
	.string "I'm still fundamentally incomplete.\p"
	.string "\p"
	.string "What I need is the same thing\n"
	.string "TEAM GENESIS is after.\p"
	.string "And that's why I'm still helping\n"
	.string "them for now.$"

PokemonLaboratory_B2_Text_JaceQuestions:
	.string "So what is TEAM GENESIS after anyway?\p"
	.string "And how does it help with your disease?\p"
	.string "And why do you have to be such a jerk\n"
	.string "to everybody for no reason?$"

PokemonLaboratory_B2_Text_RaynerTooManyQuestions:
	.string "Tch!\n"
	.string "You ask too many questions!\p"
	.string "Bottom line is, I'm taking this thing\n"
	.string "with me back to TEAM GENESIS.\p"
	.string "It's not like I care what\n"
	.string "happens to XANTHOS CITY...$"

PokemonLaboratory_B2_Text_JaceXanthosCity:
	.string "XANTHOS CITY? What do you mean?\n"
	.string "What's gonna happen there?$"

PokemonLaboratory_B2_Text_RaynerOops:
	.string "Oops, didn't mean to say\n"
	.string "that part out loud.\p"
	.string "Since you know now, I might as\n"
	.string "well tell you the rest.\p"
	.string "TEAM GENESIS is hiding beneath\n"
	.string "XANTHOS CITY.\p"
	.string "They've created another facility\n"
	.string "just like this one.\p"
	.string "And they're planning to make another\n"
	.string "bridge to Ultra Space.\p"
	.string "If it's anything like what happened\n"
	.string "last time...\p"
	.string "Hehehehehehehe.\n"
	.string "Well, you saw this place.$"


PokemonLaboratory_B2_Text_JaceWhatHappensToPeople:
	.string "But there are tons of innocent people\n"
	.string "in XANTHOS CITY!\p"
	.string "What's gonna happen to them?$"

PokemonLaboratory_B2_Text_RaynerWhoCares:
	.string "Who cares.\n"
	.string "There are no 'innocent' people, anyway.$"

PokemonLaboratory_B2_Text_JaceSoHeartless:
	.string "How can you be so heartless?!\n"
	.string "What did they ever do to you?!$"

PokemonLaboratory_B2_Text_RaynerDoSomething:
	.string "Why don't you do something about it, then?\p"
	.string "I'm still not satisfed from that\n"
	.string "first battle, you know.\p"
	.string "Why don't you try and stop me?$"

PokemonLaboratory_B2_Text_JaceWontFight:
	.string "\p"
	.string "No, I'm not gonna fight you.$"

PokemonLaboratory_B2_Text_RaynerChickenOut:
	.string "Chickening out, huh?\p"
	.string "Guess you don't really care about those\n"
	.string "people in XANTHOS CITY, do you?$"

PokemonLaboratory_B2_Text_JaceComeWithUs:
	.string "No, actually I wanted to ask you if\n"
	.string "you wanted to come with us instead.$"

PokemonLaboratory_B2_Text_RaynerWhat:
	.string "Huh?\n"
	.string "What are you talking about?$"

PokemonLaboratory_B2_Text_JaceWayISeeIt:
	.string "Look the way I see it, you just\n"
	.string "need a good doctor, right?\p"
	.string "The POKéMON RANGERS might be able to help.\n"
	.string "They know plenty of doctors.\p"
	.string "Well, mostly POKéMON doctors...\p"
	.string "But they have doctors for people too.\n"
	.string "I'm sure one of them could help you out.$"

PokemonLaboratory_B2_Text_RaynerNotNaive:
	.string "\p"
	.string "You don't seriously think I'm naive enough\n"
	.string "to trust random doctors, do you?$"

PokemonLaboratory_B2_Text_JaceGoodPeople:
	.string "Hey, they're good people!\n"
	.string "I know some of them!\p"
	.string "They've helped former TEAM GENESIS POKéMON\n"
	.string "before. I'm sure they can help you too.$"

PokemonLaboratory_B2_Text_RaynerDeclines:
	.string "I highly doubt it. And I'm not about to\n"
	.string "risk my one chance at a real solution.$"

PokemonLaboratory_B2_Text_JaceRiskPeople:
	.string "You'd rather risk everyone in XANTHOS CITY,\n"
	.string "is that it?$"

PokemonLaboratory_B2_Text_RaynerThatsHowItWorks:
	.string "Yup.\n"
	.string "That's just how the world works.\p"
	.string "The weak don't get to decide\n"
	.string "what happens to them.\p"
	.string "They'll adapt or perish.\n"
	.string "It's as simple as that.\p"
	.string "And if you care so much,\n"
	.string "then just try to stop us.$"

PokemonLaboratory_B2_Text_JaceToPlayer:
	.string "JACE: That guy was really messed up.\p"
	.string "I can't believe he wants to help\n"
	.string "TEAM GENESIS terrorize people.$"

PokemonLaboratory_B2_Text_JaceToPlayer2:
	.string "Well if what he said is true, then\n"
	.string "XANTHOS CITY could be in big danger.\p"
	.string "Let's go back to RANGER HQ and\n"
	.string "explain everything to JUSTIN.$"














PokemonLaboratory_B2_Text_RaynerPhilosophy:
	.string "What do you mean? I'm just doing what\n"
	.string "everyone has always done to me.\p"
	.string "Humans are such contemptible creatures.\p"
	.string "They make all these plans to control\n"
	.string "everything and everyone.\p"
	.string "They claim to be doing good for the world.\n"
	.string "Some even think they can end suffering itself.\p"
	.string "But in the end, they just end up\n"
	.string "creating more suffering.\p"
	.string "You see, there's no point in living\n"
	.string "without striving.\p"
	.string "And striving inevitably creates losers.\n"
	.string "Life is a great big competition after all.\p"
	@.string "Only the strongest will survive.\p"
	.string "The weak are meat.\n"
	.string "And the strong do eat.\p"
	.string "The way I see it, we only keep them\n"
	.string "around to sustain and amuse us.\p"
	.string "Think about how humans have tamed\n"
	.string "and harnessed POKéMON for example.\p"
	.string "POKéMON are capable of many things.\p"
	.string "But in the end, they're no match\n"
	.string "for the ingenuity of man.\p"
	.string "Mankind is the superior species.\n"
	.string "We only keep them around because they\l"
	.string "amuse us or can be useful to us.$"

PokemonLaboratory_B2_Text_JacePhilosophy:
	.string "That's not true! POKéMON are our friends.\n"
	.string "We help and support each other.$"

PokemonLaboratory_B2_Text_RaynerPhilosophy2:
	.string "Hehehe. If that's what you want\n"
	.string "to call it, fine.\p"
	.string "But it doesn't change the fact that\n"
	.string "humans are on top of the food chain.\p"
	.string "And some humans are even higher up\n"
	.string "than others.\p"
	.string "That's just how the world works.$"



PokemonLaboratory_B2_Text_RaynerSin:
	.string "My existence itself is a sin.$"





