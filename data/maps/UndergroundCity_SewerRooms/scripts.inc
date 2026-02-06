.set LOCALID_MELMETAL1, 5
.set LOCALID_MELMETAL2, 4
.set LOCALID_MELMETAL3, 6
.set LOCALID_TRIANGLE, 1
.set LOCALID_MEW, 2
.set LOCALID_ITEMBALL, 3

UndergroundCity_SewerRooms_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, UndergroundCity_SewerRooms_OnFrame
	@map_script MAP_SCRIPT_ON_TRANSITION, UndergroundCity_SewerRooms_OnTransition
	.byte 0

UndergroundCity_SewerRooms_OnFrame:
	map_script_2 VAR_RANGER_HQ_STATE, 5, UndergroundCity_SewerRooms_EventScript_MelmetalBattle
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

@UndergroundCity_SewerRooms_OnTransition::
@	call_if_ge VAR_RANGER_HQ_STATE, 6, PokemonLaboratory_B2_EventScript_AddJace
@	end

UndergroundCity_SewerRooms_EventScript_RemoveMelmetal1:
	removeobject LOCALID_MELMETAL1
	return

UndergroundCity_SewerRooms_EventScript_RemoveMelmetal2:
	removeobject LOCALID_MELMETAL2
	return

UndergroundCity_SewerRooms_EventScript_RemoveMelmetal3:
	removeobject LOCALID_MELMETAL3
	return

UndergroundCity_SewerRooms_EventScript_RemoveTriangle:
	removeobject LOCALID_TRIANGLE
	setobjectxyperm LOCALID_TRIANGLE, 0, 15
	@setobjectmovementtype LOCALID_JACE, MOVEMENT_TYPE_FACE_UP
	@clearflag FLAG_HIDE_JACE
	addobject LOCALID_TRIANGLE
	return

UndergroundCity_SewerRooms_EventScript_AddMew:
	removeobject LOCALID_MEW
	setobjectxyperm LOCALID_MEW, 17, 6
	@setobjectmovementtype LOCALID_JACE, MOVEMENT_TYPE_FACE_DOWN
	@clearflag FLAG_HIDE_JACE
	addobject LOCALID_MEW
	return

UndergroundCity_SewerRooms_EventScript_RemoveMew:
	removeobject LOCALID_MEW
	setobjectxyperm LOCALID_MEW, 0, 15
	addobject LOCALID_MEW
	return

UndergroundCity_SewerRooms_EventScript_AddItemBall:
	setobjectxyperm LOCALID_ITEMBALL, 17, 8
	addobject LOCALID_ITEMBALL
	return

UndergroundCity_SewerRooms_EventScript_RemoveItemBall:
	removeobject LOCALID_ITEMBALL
	return




UndergroundCity_SewerRooms_EventScript_MelmetalBattle::
	lockall
	setflag FLAG_TEMP_DISABLE_BAG
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	delay 60
	applymovement LOCALID_MELMETAL1, Common_Movement_FaceDown
	applymovement LOCALID_MELMETAL2, Common_Movement_FaceDown
	applymovement LOCALID_MELMETAL1, Common_Movement_ExclamationMark
	applymovement LOCALID_MELMETAL2, Common_Movement_ExclamationMark
	applymovement LOCALID_MELMETAL3, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	waitse
	applymovement LOCALID_MELMETAL1, UndergroundCity_SewerRooms_Movement_Melmetal1Approach
	waitmovement 0
	delay 30
	playmoncry SPECIES_MELMETAL, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 30
	seteventmon SPECIES_MELMETAL, 55
	totemboost_acc2 B_POSITION_OPPONENT_LEFT
	special BattleSetup_StartLegendaryBattle
	waitstate
	delay 30
	call UndergroundCity_SewerRooms_EventScript_RemoveMelmetal1
	playse SE_M_ACID_ARMOR
	waitse
	applymovement LOCALID_MELMETAL2, UndergroundCity_SewerRooms_Movement_Melmetal2Approach
	waitmovement 0
	delay 30
	playmoncry SPECIES_MELMETAL, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 30
	seteventmon SPECIES_MELMETAL, 55
	totemboost_acc2 B_POSITION_OPPONENT_LEFT
	special BattleSetup_StartLegendaryBattle
	waitstate
	delay 30
	call UndergroundCity_SewerRooms_EventScript_RemoveMelmetal2
	playse SE_M_ACID_ARMOR
	waitse
	applymovement LOCALID_MELMETAL3, UndergroundCity_SewerRooms_Movement_Melmetal3Approach
	waitmovement 0
	delay 30
	playmoncry SPECIES_MELMETAL, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 30
	seteventmon SPECIES_MELMETAL, 55
	totemboost_acc2 B_POSITION_OPPONENT_LEFT
	special BattleSetup_StartLegendaryBattle
	waitstate
	delay 30
	call UndergroundCity_SewerRooms_EventScript_RemoveMelmetal3
	playse SE_M_ACID_ARMOR
	waitse
	clearflag FLAG_TEMP_DISABLE_BAG
	goto UndergroundCity_SewerRooms_EventScript_MewRescued
	end

UndergroundCity_SewerRooms_Movement_Melmetal1Approach:
	walk_down
	walk_left
	walk_left
	walk_down
	@walk_down
	step_end

UndergroundCity_SewerRooms_Movement_Melmetal2Approach:
	walk_down
	walk_right
	walk_right
	walk_down
	@walk_down
	step_end

UndergroundCity_SewerRooms_Movement_Melmetal3Approach:
	walk_down
	walk_down
	walk_down
	step_end





UndergroundCity_SewerRooms_EventScript_MewRescued::
	playse SE_M_CHARGE
	fadescreen FADE_TO_WHITE
	waitse
	delay 30
	playse SE_M_BRICK_BREAK
	call UndergroundCity_SewerRooms_EventScript_RemoveTriangle
	call UndergroundCity_SewerRooms_EventScript_AddMew
	delay 30
	fadescreen FADE_FROM_WHITE
	delay 60
	playmoncry SPECIES_MEW, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_MEW, UndergroundCity_SewerRooms_Movement_MewRescued
	waitmovement 0
	playse SE_PIN
	delay 60

	playse SE_M_TELEPORT
	fadescreen FADE_TO_WHITE
	waitse
	delay 30
	call UndergroundCity_SewerRooms_EventScript_RemoveMew
	call UndergroundCity_SewerRooms_EventScript_AddItemBall
	delay 30
	fadescreen FADE_FROM_WHITE
	delay 60
	call UndergroundCity_SewerRooms_EventScript_AddItemBall
	giveitem ITEM_GENESIS_S_CARD
	call UndergroundCity_SewerRooms_EventScript_RemoveItemBall
	setflag FLAG_UNDERGROUND_CITY_RESCUED_MEW
	setvar VAR_RANGER_HQ_STATE, 6
	delay 60
	releaseall
	end

UndergroundCity_SewerRooms_Movement_MewRescued:
	delay_16
	delay_16
	walk_down
	walk_down
	delay_16
	@delay_16
	@delay_16
	delay_16
	emote_heart
	step_end



