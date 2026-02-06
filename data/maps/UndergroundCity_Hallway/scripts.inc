.set LOCALID_NEDA, 2
.set LOCALID_ZARTOSHT, 1
.set LOCALID_JACE, 3
.set LOCALID_ROBIN, 4
.set LOCALID_RANGER1, 6
.set LOCALID_RANGER2, 5

UndergroundCity_Hallway_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, UndergroundCity_Hallway_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, UndergroundCity_Hallway_OnFrame
	.byte 0

UndergroundCity_Hallway_OnFrame:
	map_script_2 VAR_RANGER_HQ_STATE, 6, UndergroundCity_Hallway_EventScript_GenesisBossEncounter
	.2byte 0

	@ State descriptions for VAR_RANGER_HQ_STATE
	@ 0: Before meeting Justin
	@ 1: After receiving mission from Justin
	@ 2: After returning from Pokemon Laboratory
	@ 3: Justin and rangers in Xanthos Underground shopping center
	@ 4: Justin and rangers talking to Azami
	@ 5: Before freeing Mew
	@ 6: Before encountering Zartosht/Neda
	@ 7: Before battling Azami
	@ 8: After clearing Underground City
	@ 9: After everyone leaves and Brendan directs you to Dun Town

UndergroundCity_Hallway_OnTransition:
	call_if_ge VAR_RANGER_HQ_STATE, 7, UndergroundCity_Hallway_EventScript_MoveEveryoneToBattlePos
	end

UndergroundCity_Hallway_EventScript_MoveEveryoneToBattlePos:
	@removeobject LOCALID_JACE
	@clearflag FLAG_HIDE_JACE
	setobjectxyperm LOCALID_JACE, 4, 13
	setobjectmovementtype LOCALID_JACE, MOVEMENT_TYPE_FACE_LEFT
	addobject LOCALID_JACE
	setobjectxyperm LOCALID_ROBIN, 3, 14
	setobjectmovementtype LOCALID_ROBIN, MOVEMENT_TYPE_FACE_UP
	addobject LOCALID_ROBIN
	setobjectxyperm LOCALID_RANGER1, 6, 13
	setobjectmovementtype LOCALID_RANGER1, MOVEMENT_TYPE_FACE_RIGHT
	addobject LOCALID_RANGER1
	setobjectxyperm LOCALID_RANGER2, 7, 14
	setobjectmovementtype LOCALID_RANGER2, MOVEMENT_TYPE_FACE_UP
	addobject LOCALID_RANGER2
	setobjectxyperm LOCALID_ZARTOSHT, 3, 13
	setobjectmovementtype LOCALID_ZARTOSHT, MOVEMENT_TYPE_FACE_RIGHT
	addobject LOCALID_ZARTOSHT
	setobjectxyperm LOCALID_NEDA, 7, 13
	setobjectmovementtype LOCALID_NEDA, MOVEMENT_TYPE_FACE_LEFT
	addobject LOCALID_NEDA
	return

UndergroundCity_Hallway_EventScript_RangersEnter:
	setobjectxyperm LOCALID_JACE, 4, 21
	addobject LOCALID_JACE
	setobjectxyperm LOCALID_ROBIN, 4, 22
	addobject LOCALID_ROBIN
	setobjectxyperm LOCALID_RANGER1, 6, 21
	addobject LOCALID_RANGER1
	setobjectxyperm LOCALID_RANGER2, 6, 22
	addobject LOCALID_RANGER2
	applymovement LOCALID_JACE, Common_Movement_WalkUp
	applymovement LOCALID_ROBIN, Common_Movement_WalkUp
	applymovement LOCALID_RANGER1, Common_Movement_WalkUp
	applymovement LOCALID_RANGER2, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkUp
	applymovement LOCALID_ROBIN, Common_Movement_WalkUp
	applymovement LOCALID_RANGER1, Common_Movement_WalkUp
	applymovement LOCALID_RANGER2, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkUp
	applymovement LOCALID_ROBIN, Common_Movement_WalkUp
	applymovement LOCALID_RANGER1, Common_Movement_WalkUp
	applymovement LOCALID_RANGER2, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkUp
	applymovement LOCALID_ROBIN, Common_Movement_WalkUp
	applymovement LOCALID_RANGER1, Common_Movement_WalkUp
	applymovement LOCALID_RANGER2, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkUp
	applymovement LOCALID_ROBIN, Common_Movement_WalkUp
	applymovement LOCALID_RANGER1, Common_Movement_WalkUp
	applymovement LOCALID_RANGER2, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkUp
	applymovement LOCALID_ROBIN, Common_Movement_WalkUp
	applymovement LOCALID_RANGER1, Common_Movement_WalkUp
	applymovement LOCALID_RANGER2, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkUp
	applymovement LOCALID_ROBIN, Common_Movement_WalkUp
	applymovement LOCALID_RANGER1, Common_Movement_WalkUp
	applymovement LOCALID_RANGER2, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_ZARTOSHT, UndergroundCity_Hallway_Movement_BackUpLeft
	applymovement LOCALID_NEDA, UndergroundCity_Hallway_Movement_BackUpRight
	applymovement LOCALID_JACE, Common_Movement_WalkUp
	applymovement LOCALID_ROBIN, Common_Movement_WalkLeft
	applymovement LOCALID_RANGER1, Common_Movement_WalkUp
	applymovement LOCALID_RANGER2, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_FaceLeft
	applymovement LOCALID_ROBIN, Common_Movement_WalkUp
	applymovement LOCALID_RANGER1, Common_Movement_FaceRight
	applymovement LOCALID_RANGER2, Common_Movement_WalkUp
	waitmovement 0
	return

UndergroundCity_Hallway_Movement_BackUpLeft:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

UndergroundCity_Hallway_Movement_BackUpRight:
	face_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end






UndergroundCity_Hallway_EventScript_GenesisBossEncounter::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, UndergroundCity_Hallway_Movement_PlayerEnters
	waitmovement 0
	fadeoutbgm 0
	delay 48
	applymovement LOCALID_NEDA, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox UndergroundCity_Hallway_Text_NedaIntro, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ZARTOSHT, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox UndergroundCity_Hallway_Text_ZartoshtIntro, MSGBOX_DEFAULT
	closemessage
	delay 60
	playbgm MUS_DUMMY, FALSE
	msgbox UndergroundCity_Hallway_Text_JaceIntro, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ZARTOSHT, Common_Movement_ExclamationMark
	applymovement LOCALID_NEDA, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	delay 60
	playbgm MUS_RG_TITLE, FALSE
	call UndergroundCity_Hallway_EventScript_RangersEnter
	delay 20
	applymovement LOCALID_JACE, Common_Movement_FaceDown
	waitmovement 0
	delay 20
	msgbox UndergroundCity_Hallway_Text_JaceMidBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JACE, Common_Movement_FaceLeft
	waitmovement 0
	delay 60
	setvar VAR_RANGER_HQ_STATE, 7
	playbgm MUS_DUMMY, FALSE
	@fadeinbgm 0
	fadedefaultbgm
	releaseall
	end

UndergroundCity_Hallway_Movement_PlayerEnters:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

UndergroundCity_Hallway_Text_NedaIntro:
	.string "NEDA: Well well.\n"
	.string "The dead can walk.\p"
	.string "You've been a thorn in my side\n"
	.string "for too long.\p"
	.string "This time I'll finish you for good.$"

UndergroundCity_Hallway_Text_ZartoshtIntro:
	.string "ZARTOSHT: And the same goes for me.\n"
	.string "I owe you for back in TURQUOISE CITY.\p"
	@.string "Let's see you fight 2 against 1!$"
	.string "I wonder, can you survive in\n"
	.string "fight that's 2 against 1?$"

UndergroundCity_Hallway_Text_JaceIntro:
	@.string "????: Right back at ya, TEAM GENESIS!$"
	.string "????: CAN YOU?$"








UndergroundCity_Hallway_EventScript_Jace::
	lock
	faceplayer
	msgbox UndergroundCity_Hallway_Text_JaceMidBattle, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

UndergroundCity_Hallway_Text_JaceMidBattle:
	.string "JACE: We'll handle these two, {PLAYER}.\n"
	.string "You go after their leader!$"

UndergroundCity_Hallway_EventScript_Rangers::
	lock
	msgbox UndergroundCity_Hallway_Text_RangersMidBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

UndergroundCity_Hallway_Text_RangersMidBattle:
	.string "Take this, TEAM GENESIS scoundrels!$"


UndergroundCity_Hallway_EventScript_Zartosht::
	lock
	msgbox UndergroundCity_Hallway_Text_ZartoshtMidBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

UndergroundCity_Hallway_Text_ZartoshtMidBattle:
	.string "ZARTOSHT: Tch! You meddlesome brats!$"


UndergroundCity_Hallway_EventScript_Neda::
	lock
	msgbox UndergroundCity_Hallway_Text_NedaMidBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

UndergroundCity_Hallway_Text_NedaMidBattle:
	.string "NEDA: Why you insolent little...$"




