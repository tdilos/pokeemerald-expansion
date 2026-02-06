.set LOCALID_RIVAL, 5
.set LOCALID_TUTOR, 6

CinerousTower_Exterior_MapScripts::
	@map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CinerousTower_Exterior_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CinerousTower_Exterior_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, CinerousTower_Exterior_OnTransition
	.byte 0

CinerousTower_Exterior_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	@setflag FLAG_VISITED_UMBER_TOWN
	@setflag FLAG_HIDE_UMBER_TOWN_MAY
	@setflag FLAG_HIDE_UMBER_TOWN_JACE
	@goto_if_eq VAR_CINEROUS_TOWER_STATE, 5, CinerousTower_Exterior_EventScript_PostRescue
	goto_if_eq VAR_CINEROUS_TOWN_STATE, 3, CinerousTower_Exterior_EventScript_PostRescue
	call_if_unset FLAG_RESCUED_HEADBUTT_TUTOR, CinerousTower_Exterior_EventScript_ResetHoundoom
	@call_if_le VAR_CINEROUS_TOWER_STATE, 3, CinerousTower_Exterior_EventScript_ResetHoundoom
	@call_if_eq VAR_CINEROUS_TOWER_STATE, 4, CinerousTower_Exterior_EventScript_MoveTutorAndOPC
	call_if_set FLAG_RESCUED_HEADBUTT_TUTOR, CinerousTower_Exterior_EventScript_MoveTutorAndOPC
	end

CinerousTower_Exterior_EventScript_PostRescue:
	@removeobject LOCALID_RIVAL
	@removeobject LOCALID_TUTOR
	@setflag FLAG_RESCUED_HEADBUTT_TUTOR
	setobjectxyperm LOCALID_RIVAL, 47, 0
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_UP
	setobjectxyperm LOCALID_TUTOR, 47, 0
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_UP
	end

@CinerousTower_Exterior_OnWarp:
@	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
@	end

CinerousTower_Exterior_OnFrame:
	map_script_2 VAR_CINEROUS_TOWER_STATE, 0, CinerousTower_Exterior_EventScript_RescueInitial
	map_script_2 VAR_CINEROUS_TOWER_STATE, 4, CinerousTower_Exterior_EventScript_RescueFinish
	.2byte 0

CinerousTower_Exterior_EventScript_RescueInitial::
	lockall
	@call UmberTown_HazelsLab_EventScript_HideHazel
	setvar VAR_CINEROUS_TOWER_STATE, 1
	@turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	goto CinerousTower_Exterior_EventScript_RescueIntro
	end

CinerousTower_Exterior_EventScript_ResetHoundoom::
	@clearflag FLAG_HIDE_UMBER_TOWN_JACE
	@turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	setobjectxyperm LOCALID_RIVAL, 16, 33
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_UP
	setvar VAR_CINEROUS_TOWER_STATE, 0
	return

CinerousTower_Exterior_EventScript_MoveTutorAndOPC::
	@removeobject LOCALID_RIVAL
	@removeobject LOCALID_TUTOR
	@setobjectxyperm OBJ_EVENT_ID_PLAYER, 15, 33
	@setobjectmovementtype OBJ_EVENT_ID_PLAYER, MOVEMENT_TYPE_FACE_DOWN
	setobjectxyperm LOCALID_RIVAL, 16, 33
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_DOWN
	setobjectxyperm LOCALID_TUTOR, 16, 34
	setobjectmovementtype LOCALID_TUTOR, MOVEMENT_TYPE_FACE_UP
	@addobject LOCALID_RIVAL
	@addobject LOCALID_TUTOR
	clearflag FLAG_RESCUED_HEADBUTT_TUTOR
	return










CinerousTower_EventScript_ReadyToGoPrompt::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox CinerousTower_Text_OPCAreYouReadyToGo, MSGBOX_YESNO
	@goto_if_eq VAR_RESULT, YES, CinerousTower_EventScript_ChoosePartyForMultiBattle
	goto_if_eq VAR_RESULT, YES, CinerousTower_EventScript_MultiTest
	applymovement VAR_LAST_TALKED, Common_Movement_FaceUp
	waitmovement 0
	releaseall
	end

CinerousTower_Text_OPCAreYouReadyToGo:
	.string "Ready to go?$"

CinerousTower_EventScript_MultiTest::
	choose_mons
	@compare VAR_RESULT, 0
	@goto_if_eq CinerousTower_EventScript_MultiTestEnd
	@setwildbattle SPECIES_HOUNDEVIL, 26
	setwildbattle SPECIES_HOUNDEVIL, 26, ITEM_KINGS_ROCK, SPECIES_HOUNDEVIL, 26, ITEM_KINGS_ROCK
	@multi_wild TRAINER_WALLACE, TRAINER_BACK_PIC_MAY
	multi_wild TRAINER_VIOLET_CINEROUS_TOWN_TEPIG, TRAINER_BACK_PIC_MAY
	@specialvar VAR_RESULT, B_OUTCOME_LOST
	@goto_if_eq CinerousTower_EventScript_MultiTestLost
	end

CinerousTower_EventScript_MultiTestLost::
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut
	end

CinerousTower_EventScript_MultiTestEnd::
	end









@CinerousTower_EventScript_ChoosePartyForMultiBattle::
@	lockall
@	@applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
@	@waitmovement 0
@	special SavePlayerParty
@	fadescreen FADE_TO_BLACK
@	special ChooseHalfPartyForBattle
@	waitstate
@	goto_if_ne VAR_RESULT, 0, CinerousTower_EventScript_DoPartnerOPCDoubleBattle
@	special LoadPlayerParty
@	goto CinerousTower_EventScript_ReadyToGoPrompt

@CinerousTower_EventScript_DoPartnerOPCDoubleBattle::
@	special ReducePlayerPartyToSelectedMons
@	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
@	@checkplayergender
@	@call_if_eq VAR_RESULT, MALE, CinerousTower_EventScript_SetOPCFemale
@	@call_if_eq VAR_RESULT, FEMALE, CinerousTower_EventScript_SetOPCMale
@	setvar VAR_0x8004, SPECIAL_BATTLE_MULTI
@	setvar VAR_0x8005, MULTI_BATTLE_2_VS_WILD
@	setvar VAR_0x8006, TRAINER_VIOLET_CINEROUS_TOWN_TEPIG @Partner trainer ID
@	setvar VAR_0x8007, TRAINER_VIOLET_CINEROUS_TOWN_TEPIG @Partner sprite ID
@	playmoncry SPECIES_HOUNDEVIL, CRY_MODE_ENCOUNTER
@	waitmoncry
@	setwildbattle SPECIES_HOUNDEVIL, 26, ITEM_KINGS_ROCK, SPECIES_HOUNDEVIL, 26, ITEM_KINGS_ROCK
@	@dowildbattle
@	special DoSpecialTrainerBattle
@	waitstate
@	frontier_saveparty
@	special LoadPlayerParty
@	switch VAR_RESULT
@	case 1, CinerousTower_EventScript_DoubleBattleVictory
@	fadescreen FADE_TO_BLACK
@	special SetCB2WhiteOut
@	waitstate

@CinerousTower_EventScript_DoubleBattleVictory::
@	releaseall
@	end

@CinerousTower_EventScript_SetOPCFemale::
@	setvar VAR_0x8004, SPECIAL_BATTLE_VIOLET
@	return

@CinerousTower_EventScript_SetOPCMale::
@	setvar VAR_0x8004, SPECIAL_BATTLE_VERT
@	return









CinerousTower_Exterior_EventScript_RescueIntro::
	@lockall
	@fadeoutbgm 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkUp
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, CinerousTower_Exterior_EventScript_SmokeyViolet
	call_if_eq VAR_RESULT, FEMALE, CinerousTower_Exterior_EventScript_SmokeyVert
	applymovement LOCALID_RIVAL, Common_Movement_FaceDown
	waitmovement 0
	msgbox CinerousTower_Exterior_Text_Danger, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	delay 60
	applymovement LOCALID_RIVAL, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkUp
	waitmovement 0
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FaceLeft
	waitmovement 0
	msgbox CinerousTower_Exterior_Text_HoundoomTracks, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, Common_Movement_FaceUp
	waitmovement 0
	msgbox CinerousTower_Exterior_Text_FreshTracks, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FaceLeft
	waitmovement 0
	msgbox CinerousTower_Exterior_Text_HumanFootprints, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FaceUp
	delay 10
	applymovement LOCALID_RIVAL, Common_Movement_FaceDown
	delay 30
	applymovement LOCALID_RIVAL, Common_Movement_WalkLeft
	waitmovement 0
	msgbox CinerousTower_Exterior_Text_SomeonesInDanger, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, Common_Movement_WalkLeft
	waitmovement 0
	removeobject LOCALID_RIVAL
	@setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_COPY_PLAYER
	@addobject LOCALID_RIVAL
	setobjectxyperm LOCALID_RIVAL, 47, 0
	clearflag FLAG_RESCUED_HEADBUTT_TUTOR
	@fadeinbgm 0
	@setvar VAR_CINEROUS_TOWER_STATE, 1
	releaseall
	end

CinerousTower_Exterior_EventScript_SmokeyViolet:
	msgbox CinerousTower_Exterior_Text_SmokeyViolet, MSGBOX_DEFAULT
	closemessage
	return

CinerousTower_Exterior_EventScript_SmokeyVert:
	msgbox CinerousTower_Exterior_Text_SmokeyVert, MSGBOX_DEFAULT
	closemessage
	return

CinerousTower_Exterior_Text_SmokeyViolet:
	.string "VIOLET: Cough… Cough…\n"
	.string "The smoke here is really thick.$"

CinerousTower_Exterior_Text_SmokeyVert:
	.string "VERT: Cough… Cough…\n"
	.string "The smoke here is really thick.$"

CinerousTower_Exterior_Text_Danger:
	.string "It may be dangerous for our\n"
	.string "POKéMON, but don't worry.\p"
	.string "I'll keep both of our POKéMON\n"
	.string "healthy.\p"
	.string "You just help me look for\n"
	.string "any sign of...$"

CinerousTower_Exterior_Text_HoundoomTracks:
	.string "These tracks, I recognize them.\p"
	.string "There are packs of HOUNDOOM that live\n"
	.string "in these mountains.\p"
	.string "Sometimes they get too close to humans\n"
	.string "and cause problems.$"

CinerousTower_Exterior_Text_FreshTracks:
	.string "From the looks of it, these tracks were\n"
	.string "made not that long ago.\p"
	.string "Could it be that...$"

CinerousTower_Exterior_Text_HumanFootprints:
	.string "There are human footprints here too!\p"
	.string "Does that mean that the missing person\n"
	.string "got chased by those HOUNDOOM?\p"
	.string "Ahh, we have to hurry!\p"
	.string "If they're still out there, they could be\n"
	.string "trapped somewhere or worse!\p"
	.string "HOUNDOOM have a notorious reputation.\p"
	.string "People tell all kinds of horror stories\n"
	.string "about them!$"

CinerousTower_Exterior_Text_SomeonesInDanger:
	.string "We have to hurry and find them.\n"
	.string "Someone's life could be in danger!$"




@CinerousTower_Exterior_EventScript_OPC::
@	msgbox CinerousTower_Exterior_Text_HangInThere, MSGBOX_NPC
@	end

@CinerousTower_Exterior_Text_HangInThere:
@	.string "Hang in there, {PLAYER}. They have to\n"
@	.string "be around here somewhere.$"










CinerousTower_Exterior_EventScript_FirstHoundoomEncounter1::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	setvar VAR_CINEROUS_TOWER_STATE, 2
	playmoncry SPECIES_HOUNDOOM, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	@setwildbattle SPECIES_HOUNDOOM, 20, ITEM_NONE, SPECIES_HOUNDOOM, 20, ITEM_NONE
	@dowildbattle
	setflag FLAG_TEMP_DISABLE_BAG
	@choose_mons
	special SavePlayerParty
	setwildbattle SPECIES_HOUNDOOM, 20, ITEM_NONE, SPECIES_HOUNDOOM, 20, ITEM_NONE
	@call_if_eq VAR_STARTER_MON, 0, CinerousTower_Exterior_EventScript_SetOPCChespin
	@call_if_eq VAR_STARTER_MON, 1, CinerousTower_Exterior_EventScript_SetOPCTepig
	@call_if_eq VAR_STARTER_MON, 2, CinerousTower_Exterior_EventScript_SetOPCPopplio
	call CinerousTower_Exterior_EventScript_OPCBattleSetup
	@special HealPlayerParty
	clearflag FLAG_TEMP_DISABLE_BAG
	special LoadPlayerParty
	special HealPlayerParty
	setobjectxyperm LOCALID_RIVAL, 32, 26
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FaceUp
	waitmovement 0
	@applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	@waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, CinerousTower_Exterior_EventScript_HoundoomNearbyViolet
	call_if_eq VAR_RESULT, FEMALE, CinerousTower_Exterior_EventScript_HoundoomNearbyVert
	applymovement LOCALID_RIVAL, Common_Movement_WalkUp
	waitmovement 0
	removeobject LOCALID_RIVAL
	setobjectxyperm LOCALID_RIVAL, 47, 0
	clearflag FLAG_RESCUED_HEADBUTT_TUTOR
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	releaseall
	end

CinerousTower_Exterior_EventScript_FirstHoundoomEncounter2::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	setvar VAR_CINEROUS_TOWER_STATE, 2
	playmoncry SPECIES_HOUNDOOM, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	@setwildbattle SPECIES_HOUNDOOM, 20, ITEM_NONE, SPECIES_HOUNDOOM, 20, ITEM_NONE
	@dowildbattle
	setflag FLAG_TEMP_DISABLE_BAG
	@choose_mons
	special SavePlayerParty
	setwildbattle SPECIES_HOUNDOOM, 20, ITEM_NONE, SPECIES_HOUNDOOM, 20, ITEM_NONE
	call CinerousTower_Exterior_EventScript_OPCBattleSetup
	@special HealPlayerParty
	clearflag FLAG_TEMP_DISABLE_BAG
	special LoadPlayerParty
	special HealPlayerParty
	setobjectxyperm LOCALID_RIVAL, 33, 26
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FaceUp
	waitmovement 0
	@applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	@waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, CinerousTower_Exterior_EventScript_HoundoomNearbyViolet
	call_if_eq VAR_RESULT, FEMALE, CinerousTower_Exterior_EventScript_HoundoomNearbyVert
	applymovement LOCALID_RIVAL, Common_Movement_WalkUp
	waitmovement 0
	removeobject LOCALID_RIVAL
	setobjectxyperm LOCALID_RIVAL, 47, 0
	clearflag FLAG_RESCUED_HEADBUTT_TUTOR
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	releaseall
	end

CinerousTower_EventScript_MultiBattleLost::
	special LoadPlayerParty
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut
	end

CinerousTower_Exterior_EventScript_HoundoomNearbyViolet:
	msgbox CinerousTower_Exterior_Text_HoundoomNearbyViolet, MSGBOX_NPC
	closemessage
	return

CinerousTower_Exterior_EventScript_HoundoomNearbyVert:
	msgbox CinerousTower_Exterior_Text_HoundoomNearbyVert, MSGBOX_NPC
	closemessage
	return

CinerousTower_Exterior_Text_HoundoomNearbyViolet:
	.string "VIOLET: The other HOUNDOOM can't be\n"
	.string "too far from here.\p"
	.string "But the missing person might be\n"
	.string "nearby too.\p"
	.string "C'mon, let's keep looking!$"

CinerousTower_Exterior_Text_HoundoomNearbyVert:
	.string "VERT: The other HOUNDOOM can't be\n"
	.string "too far from here.\p"
	.string "But the missing person might be\n"
	.string "nearby too.\p"
	.string "C'mon, let's keep looking!$"






CinerousTower_Exterior_EventScript_SecondHoundoomEncounter::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	setvar VAR_CINEROUS_TOWER_STATE, 3
	playmoncry SPECIES_HOUNDOOM, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	@setwildbattle SPECIES_HOUNDOOM, 22, ITEM_NONE, SPECIES_HOUNDOOM, 22, ITEM_NONE
	@dowildbattle
	setflag FLAG_TEMP_DISABLE_BAG
	@choose_mons
	special SavePlayerParty
	setwildbattle SPECIES_HOUNDOOM, 22, ITEM_NONE, SPECIES_HOUNDOOM, 22, ITEM_NONE
	call CinerousTower_Exterior_EventScript_OPCBattleSetup
	clearflag FLAG_TEMP_DISABLE_BAG
	special LoadPlayerParty
	special HealPlayerParty
	setobjectxyperm LOCALID_RIVAL, 34, 20
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FaceLeft
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, CinerousTower_Exterior_EventScript_CloseToTheTopViolet
	call_if_eq VAR_RESULT, FEMALE, CinerousTower_Exterior_EventScript_CloseToTheTopVert
	applymovement LOCALID_RIVAL, Common_Movement_WalkLeft
	waitmovement 0
	removeobject LOCALID_RIVAL
	setobjectxyperm LOCALID_RIVAL, 47, 0
	clearflag FLAG_RESCUED_HEADBUTT_TUTOR
	releaseall
	end

CinerousTower_Exterior_EventScript_CloseToTheTopViolet:
	msgbox CinerousTower_Exterior_Text_CloseToTheTopViolet, MSGBOX_NPC
	closemessage
	return

CinerousTower_Exterior_EventScript_CloseToTheTopVert:
	msgbox CinerousTower_Exterior_Text_CloseToTheTopVert, MSGBOX_NPC
	closemessage
	return

CinerousTower_Exterior_Text_CloseToTheTopViolet:
	.string "VIOLET: We're getting close to the top.\n"
	.string "I think I saw someone up there!$"

CinerousTower_Exterior_Text_CloseToTheTopVert:
	.string "VERT: We're getting close to the top.\n"
	.string "I think I saw someone up there!$"






CinerousTower_Exterior_EventScript_HoundevilEncounter::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	setobjectxyperm LOCALID_RIVAL, 31, 12
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_TUTOR, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	applymovement LOCALID_TUTOR, Common_Movement_FaceDown
	waitmovement 0
	delay 60
	applymovement LOCALID_TUTOR, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_TUTOR, Common_Movement_WalkDown
	waitmovement 0
	msgbox CinerousTower_Exterior_Text_FoundTutor, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, CinerousTower_Exterior_EventScript_SafeAfterAllViolet
	call_if_eq VAR_RESULT, FEMALE, CinerousTower_Exterior_EventScript_SafeAfterAllVert
	applymovement LOCALID_TUTOR, Common_Movement_FaceLeft
	delay 40
	applymovement LOCALID_TUTOR, Common_Movement_FaceRight
	delay 40
	msgbox CinerousTower_Exterior_Text_Shhh, MSGBOX_DEFAULT
	closemessage
	delay 60
	playmoncry SPECIES_HOUNDOOM, CRY_MODE_NORMAL
	delay 30	
	playmoncry SPECIES_HOUNDOOM, CRY_MODE_NORMAL
	delay 30
	playmoncry SPECIES_HOUNDOOM, CRY_MODE_NORMAL
	delay 30
	playmoncry SPECIES_HOUNDOOM, CRY_MODE_NORMAL
	delay 30
	@playmoncry SPECIES_HOUNDOOM, CRY_MODE_NORMAL
	@delay 20
	@playmoncry SPECIES_HOUNDOOM, CRY_MODE_NORMAL
	@delay 20
	applymovement LOCALID_TUTOR, Common_Movement_ExclamationMark
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	applymovement LOCALID_TUTOR, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_TUTOR, Common_Movement_FaceUp
	waitmovement 0
	msgbox CinerousTower_Exterior_Text_TooLate, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TUTOR, CinerousTower_Exterior_Movement_TutorHide
	waitmovement 0
	msgbox CinerousTower_Exterior_Text_WereSurrounded, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_RIVAL, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox CinerousTower_Exterior_Text_HaveToFight, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, CinerousTower_Exterior_EventScript_LetsDoThis
	call_if_eq VAR_RESULT, NO, CinerousTower_Exterior_EventScript_DontWorry
	delay 40
	applymovement LOCALID_RIVAL, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	delay 20
	playmoncry SPECIES_HOUNDEVIL, CRY_MODE_ENCOUNTER
	waitmoncry
	@setwildbattle SPECIES_HOUNDEVIL, 26, ITEM_KINGS_ROCK, SPECIES_HOUNDEVIL, 26, ITEM_KINGS_ROCK
	@dowildbattle
	setflag FLAG_TEMP_DISABLE_BAG
	@choose_mons
	special SavePlayerParty
	setwildbattle SPECIES_HOUNDEVIL, 26, ITEM_KINGS_ROCK, SPECIES_HOUNDEVIL, 26, ITEM_KINGS_ROCK
	call CinerousTower_Exterior_EventScript_OPCBattleSetup
	clearflag FLAG_TEMP_DISABLE_BAG
	special LoadPlayerParty
	special HealPlayerParty
	playse SE_FLEE
	setflag FLAG_RESCUED_HEADBUTT_TUTOR
	setvar VAR_CINEROUS_TOWER_STATE, 4
	msgbox CinerousTower_Exterior_Text_HoundoomFled, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_RIVAL, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, CinerousTower_Exterior_EventScript_WeDidItViolet
	call_if_eq VAR_RESULT, FEMALE, CinerousTower_Exterior_EventScript_WeDidItVert
	delay 50
	applymovement LOCALID_TUTOR, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 10
	msgbox CinerousTower_Exterior_Text_GottaGo, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_RIVAL, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	msgbox CinerousTower_Exterior_Text_RightLetsGo, MSGBOX_DEFAULT
	closemessage
	@fadescreen FADE_TO_BLACK
	@playse SE_EXIT
	@removeobject OBJ_EVENT_ID_PLAYER
	@removeobject LOCALID_RIVAL
	@removeobject LOCALID_TUTOR
	@setobjectxyperm OBJ_EVENT_ID_PLAYER, 15, 33
	@setobjectmovementtype OBJ_EVENT_ID_PLAYER, MOVEMENT_TYPE_FACE_DOWN
	@setobjectxyperm LOCALID_RIVAL, 16, 33
	@setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_DOWN
	@setobjectxyperm LOCALID_TUTOR, 16, 34
	@setobjectmovementtype LOCALID_TUTOR, MOVEMENT_TYPE_FACE_UP
	@addobject LOCALID_RIVAL
	@addobject LOCALID_TUTOR
	warp MAP_CINEROUS_TOWER_EXTERIOR, 15, 33
	waitstate
	releaseall
	end

CinerousTower_Exterior_EventScript_SafeAfterAllViolet:
	msgbox CinerousTower_Exterior_Text_SafeAfterAllViolet, MSGBOX_DEFAULT
	closemessage
	return

CinerousTower_Exterior_EventScript_SafeAfterAllVert:
	msgbox CinerousTower_Exterior_Text_SafeAfterAllVert, MSGBOX_DEFAULT
	closemessage
	return

CinerousTower_Exterior_EventScript_WeDidItViolet:
	msgbox CinerousTower_Exterior_Text_WeDidItViolet, MSGBOX_DEFAULT
	closemessage
	return

CinerousTower_Exterior_EventScript_WeDidItVert:
	msgbox CinerousTower_Exterior_Text_WeDidItVert, MSGBOX_DEFAULT
	closemessage
	return

CinerousTower_Exterior_EventScript_RescueFinish::
	lockall
	setvar VAR_CINEROUS_TOWER_STATE, 5
	@addobject OBJ_EVENT_ID_PLAYER
	@clearflag FLAG_RESCUED_HEADBUTT_TUTOR
	@delay 40
	@fadescreen FADE_FROM_BLACK
	delay 20
	applymovement LOCALID_TUTOR, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox CinerousTower_Exterior_Text_TutorExit, MSGBOX_DEFAULT
	closemessage
	@applymovement LOCALID_TUTOR, Common_Movement_WalkDown
	@waitmovement 0
	@applymovement LOCALID_TUTOR, Common_Movement_WalkDown
	@waitmovement 0
	@applymovement LOCALID_TUTOR, Common_Movement_WalkDown
	@waitmovement 0
	@applymovement LOCALID_TUTOR, Common_Movement_WalkDown
	@waitmovement 0
	applymovement LOCALID_TUTOR, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_TUTOR, Common_Movement_WalkDown
	delay 30
	playse SE_EXIT
	@setobjectxyperm LOCALID_TUTOR, 31, 9
	@addobject LOCALID_TUTOR
	removeobject LOCALID_TUTOR
	delay 60
	applymovement LOCALID_RIVAL, Common_Movement_FaceLeft
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, CinerousTower_Exterior_EventScript_VioletExit
	call_if_eq VAR_RESULT, FEMALE, CinerousTower_Exterior_EventScript_VertExit
	delay 30
	@applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	@waitmovement 0
	@applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	@waitmovement 0
	@applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	@waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	delay 30
	playse SE_EXIT
	removeobject LOCALID_RIVAL
	setflag FLAG_RESCUED_HEADBUTT_TUTOR
	setvar VAR_CINEROUS_TOWN_STATE, 3
	@questmenu QUEST_MENU_COMPLETE_QUEST QUEST_11
	completequest QUEST_11
	releaseall
	end

CinerousTower_Exterior_EventScript_VioletExit:
	msgbox CinerousTower_Exterior_Text_VioletExit, MSGBOX_DEFAULT
	closemessage
	return

CinerousTower_Exterior_EventScript_VertExit:
	msgbox CinerousTower_Exterior_Text_VertExit, MSGBOX_DEFAULT
	closemessage
	return

@CinerousTower_EventScript_HoundevilBattle::
@	choose_mons
@	setwildbattle SPECIES_HOUNDEVIL, 26, ITEM_KINGS_ROCK, SPECIES_HOUNDEVIL, 26, ITEM_KINGS_ROCK
@	multi_wild TRAINER_VIOLET_CINEROUS_TOWN_TEPIG, TRAINER_BACK_PIC_MAY
@	specialvar VAR_RESULT, B_OUTCOME_LOST
@	goto_if_eq CinerousTower_EventScript_MultiTestLost
@	return

CinerousTower_Exterior_Movement_TutorHide:
	walk_faster_left
	walk_faster_left
	walk_faster_down
	walk_faster_down
	walk_faster_right
	walk_faster_right
	face_up
	step_end

CinerousTower_Exterior_Text_FoundTutor:
	.string "Wew, am I glad to see POKéMON trainers\n"
	.string "like you guys.\p"
	.string "It's been a nightmare for me trying to\n"
	.string "get away from those monsters.$"


CinerousTower_Exterior_Text_SafeAfterAllViolet:
	.string "VIOLET: Oh, you're the missing person.\n"
	.string "You're safe after all!$"

CinerousTower_Exterior_Text_SafeAfterAllVert:
	.string "VERT: Oh, you're the missing person.\n"
	.string "You're safe after all!$"


CinerousTower_Exterior_Text_Shhh:
	.string "Shhhhhhh! Keep your voices down.\n"
	.string "Or those terrible POKéMON will come back.$"


CinerousTower_Exterior_Text_TooLate:
	.string "Aah! Too late!$"

CinerousTower_Exterior_Text_WereSurrounded: 
	.string "We're trapped up here!\p"
	.string "Aaaaah... You guys gotta do something!$"

CinerousTower_Exterior_Text_HaveToFight:
	.string "We have to beat them with our POKéMON.\n"
	.string "There's no other way.\p"
	.string "I'll take this side and you take that.\n"
	.string "Do you think you can handle them?$"

CinerousTower_Exterior_EventScript_LetsDoThis:
	msgbox CinerousTower_Exterior_Text_LetsDoThis, MSGBOX_DEFAULT
	closemessage
	return

CinerousTower_Exterior_Text_LetsDoThis:
	.string "Great. Let's do this!$"

CinerousTower_Exterior_EventScript_DontWorry::
	msgbox CinerousTower_Exterior_Text_DontWorry, MSGBOX_DEFAULT
	closemessage
	return

CinerousTower_Exterior_Text_DontWorry:
	.string "Don't worry, you got this!\n"
	.string "I'll be right here next to you.\p"
	.string "C'mon, let's do this!$"

CinerousTower_Exterior_Text_HoundoomFled:
	.string "The HOUNDOOM retreated!$"

CinerousTower_Exterior_Text_WeDidItViolet:
	.string "VIOLET: We did it!\n"
	.string "The HOUNDOOM all ran off!\p"
	.string "And {PLAYER}, you...\n"
	.string "You were really brave.\p"
	.string "The way you took on those\n"
	.string "frightening POKéMON...$"

CinerousTower_Exterior_Text_WeDidItVert:
	.string "VERT: We did it!\n"
	.string "The HOUNDOOM all ran off!\p"
	.string "And {PLAYER}, you...\n"
	.string "You were really brave.\p"
	.string "The way you took on those\n"
	.string "frightening POKéMON...$"

CinerousTower_Exterior_Text_GottaGo:
	.string "Hey, you kids! We gotta get outta here!\p"
	.string "Who knows if there are more\n"
	.string "HOUNDOOM out here!$"

CinerousTower_Exterior_Text_RightLetsGo:
	.string "Right, let's head back.$"

CinerousTower_Exterior_Text_TutorExit:
	.string "Thanks kids. You saved my life!\n"
	.string "I don't know how to repay you.\p"
	.string "I can teach your POKéMON new moves!\p"
	.string "I'll teach any POKéMON you want.\n"
	.string "Free of charge!\p"
	.string "I live just past the gate in\n"
	.string "CINEROUS TOWN.\p"
	.string "Come see me if you want to teach\n"
	.string "your POKéMON how to HEADBUTT.$"

CinerousTower_Exterior_Text_VioletExit:
	.string "VIOLET: Umm, I have to go now too.\p"
	.string "It was nice meeting you, {PLAYER}.\n"
	.string "I hope we meet again someday.$"

CinerousTower_Exterior_Text_VertExit:
	.string "VERT: Umm, I have to go now too.\p"
	.string "It was nice meeting you, {PLAYER}.\n"
	.string "I hope we meet again someday.$"








CinerousTower_Exterior_EventScript_SkipTurnback::
	end

CinerousTower_Exterior_EventScript_TowerTurnback1::
	goto_if_set FLAG_RESCUED_HEADBUTT_TUTOR, CinerousTower_Exterior_EventScript_SkipTurnback
	lockall
	setobjectxyperm LOCALID_RIVAL, 14, 18
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FaceUp
	waitmovement 0
	delay 30
	checkplayergender
	call_if_eq VAR_RESULT, MALE, CinerousTower_Exterior_EventScript_TowerTurnbackViolet
	call_if_eq VAR_RESULT, FEMALE, CinerousTower_Exterior_EventScript_TowerTurnbackVert
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	removeobject LOCALID_RIVAL
	setobjectxyperm LOCALID_RIVAL, 47, 0
	clearflag FLAG_RESCUED_HEADBUTT_TUTOR
	releaseall
	end

CinerousTower_Exterior_EventScript_TowerTurnback2::
	goto_if_set FLAG_RESCUED_HEADBUTT_TUTOR, CinerousTower_Exterior_EventScript_SkipTurnback
	lockall
	setobjectxyperm LOCALID_RIVAL, 15, 18
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FaceUp
	waitmovement 0
	delay 30
	checkplayergender
	call_if_eq VAR_RESULT, MALE, CinerousTower_Exterior_EventScript_TowerTurnbackViolet
	call_if_eq VAR_RESULT, FEMALE, CinerousTower_Exterior_EventScript_TowerTurnbackVert
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	removeobject LOCALID_RIVAL
	setobjectxyperm LOCALID_RIVAL, 47, 0
	clearflag FLAG_RESCUED_HEADBUTT_TUTOR
	releaseall
	end

CinerousTower_Exterior_EventScript_TowerTurnback3::
	goto_if_set FLAG_RESCUED_HEADBUTT_TUTOR, CinerousTower_Exterior_EventScript_SkipTurnback
	lockall
	setobjectxyperm LOCALID_RIVAL, 16, 18
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FaceUp
	waitmovement 0
	delay 30
	checkplayergender
	call_if_eq VAR_RESULT, MALE, CinerousTower_Exterior_EventScript_TowerTurnbackViolet
	call_if_eq VAR_RESULT, FEMALE, CinerousTower_Exterior_EventScript_TowerTurnbackVert
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	removeobject LOCALID_RIVAL
	setobjectxyperm LOCALID_RIVAL, 47, 0
	clearflag FLAG_RESCUED_HEADBUTT_TUTOR
	releaseall
	end

CinerousTower_Exterior_EventScript_TowerTurnback4::
	goto_if_set FLAG_RESCUED_HEADBUTT_TUTOR, CinerousTower_Exterior_EventScript_SkipTurnback
	lockall
	setobjectxyperm LOCALID_RIVAL, 17, 18
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FaceUp
	waitmovement 0
	delay 30
	checkplayergender
	call_if_eq VAR_RESULT, MALE, CinerousTower_Exterior_EventScript_TowerTurnbackViolet
	call_if_eq VAR_RESULT, FEMALE, CinerousTower_Exterior_EventScript_TowerTurnbackVert
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	removeobject LOCALID_RIVAL
	setobjectxyperm LOCALID_RIVAL, 47, 0
	clearflag FLAG_RESCUED_HEADBUTT_TUTOR
	releaseall
	end

CinerousTower_Exterior_EventScript_TowerTurnbackViolet:
	msgbox CinerousTower_Exterior_Text_TowerTurnbackViolet, MSGBOX_DEFAULT
	closemessage
	return

CinerousTower_Exterior_EventScript_TowerTurnbackVert:
	msgbox CinerousTower_Exterior_Text_TowerTurnbackVert, MSGBOX_DEFAULT
	closemessage
	return

CinerousTower_Exterior_Text_TowerTurnbackViolet:
	.string "VIOLET: That tower...\p"
	.string "...\p"
	.string "I heard this place burned down\n"
	.string "years ago in a big fire.\p"
	.string "The townspeople make up a whole bunch\n"
	.string "of stories about it.\p"
	.string "But anyway, I don't think the HOUNDOOM\n"
	.string "are in there.\p"
	.string "They make their homes in rough terrain.\p"
	.string "C'mon, let's check this way.$"

CinerousTower_Exterior_Text_TowerTurnbackVert:
	.string "VERT: That tower...\p"
	.string "...\p"
	.string "I heard this place burned down\n"
	.string "years ago in a big fire.\p"
	.string "The townspeople make up a whole bunch\n"
	.string "of stories about it.\p"
	.string "But anyway, I don't think the HOUNDOOM\n"
	.string "are in there.\p"
	.string "They make their homes in rough terrain.\p"
	.string "C'mon, let's check this way.$"



CinerousTower_Exterior_EventScript_GateTurnback1::
	goto_if_eq VAR_CINEROUS_TOWER_STATE, 4, CinerousTower_Exterior_EventScript_SkipTurnback
	goto_if_set FLAG_RESCUED_HEADBUTT_TUTOR, CinerousTower_Exterior_EventScript_SkipTurnback
	lockall
	setobjectxyperm LOCALID_RIVAL, 15, 35
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FaceDown
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, CinerousTower_Exterior_EventScript_GateTurnbackViolet
	call_if_eq VAR_RESULT, FEMALE, CinerousTower_Exterior_EventScript_GateTurnbackVert
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	removeobject LOCALID_RIVAL
	setobjectxyperm LOCALID_RIVAL, 47, 0
	clearflag FLAG_RESCUED_HEADBUTT_TUTOR
	releaseall
	end

CinerousTower_Exterior_EventScript_GateTurnback2::
	goto_if_eq VAR_CINEROUS_TOWER_STATE, 4, CinerousTower_Exterior_EventScript_SkipTurnback
	goto_if_set FLAG_RESCUED_HEADBUTT_TUTOR, CinerousTower_Exterior_EventScript_SkipTurnback
	lockall
	setobjectxyperm LOCALID_RIVAL, 16, 35
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FaceDown
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, CinerousTower_Exterior_EventScript_GateTurnbackViolet
	call_if_eq VAR_RESULT, FEMALE, CinerousTower_Exterior_EventScript_GateTurnbackVert
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	removeobject LOCALID_RIVAL
	setobjectxyperm LOCALID_RIVAL, 47, 0
	clearflag FLAG_RESCUED_HEADBUTT_TUTOR
	releaseall
	end

CinerousTower_Exterior_EventScript_GateTurnbackViolet:
	msgbox CinerousTower_Exterior_Text_GateTurnbackViolet, MSGBOX_DEFAULT
	closemessage
	return

CinerousTower_Exterior_EventScript_GateTurnbackVert:
	msgbox CinerousTower_Exterior_Text_GateTurnbackVert, MSGBOX_DEFAULT
	closemessage
	return

CinerousTower_Exterior_Text_GateTurnbackViolet:
	.string "VIOLET: We can't go back now!\n"
	.string "Someone's life could be in danger!$"

CinerousTower_Exterior_Text_GateTurnbackVert:
	.string "VERT: We can't go back now!\n"
	.string "Someone's life could be in danger!$"




CinerousTower_Exterior_EventScript_OPCBattleSetup::
	switch VAR_STARTER_MON
	case 0, CinerousTower_Exterior_EventScript_SetOPCChespin
	case 1, CinerousTower_Exterior_EventScript_SetOPCTepig
	case 2, CinerousTower_Exterior_EventScript_SetOPCPopplio
	return



CinerousTower_Exterior_EventScript_SetOPCChespin::
	checkplayergender
	call_if_eq VAR_RESULT, FEMALE, CinerousTower_Exterior_EventScript_VertChespin
	call_if_eq VAR_RESULT, MALE, CinerousTower_Exterior_EventScript_VioletChespin
	return

CinerousTower_Exterior_EventScript_SetOPCTepig::
	checkplayergender
	call_if_eq VAR_RESULT, FEMALE, CinerousTower_Exterior_EventScript_VertTepig
	call_if_eq VAR_RESULT, MALE, CinerousTower_Exterior_EventScript_VioletTepig
	return

CinerousTower_Exterior_EventScript_SetOPCPopplio::
	checkplayergender
	call_if_eq VAR_RESULT, FEMALE, CinerousTower_Exterior_EventScript_VertPopplio
	call_if_eq VAR_RESULT, MALE, CinerousTower_Exterior_EventScript_VioletPopplio
	return


CinerousTower_Exterior_EventScript_VioletChespin::
	@multi_wild TRAINER_VIOLET_CINEROUS_TOWN_CHESPIN, TRAINER_BACK_PIC_MAY
	multi_do_fixed MULTI_BATTLE_2_VS_WILD, TRAINER_VIOLET_CINEROUS_TOWN_CHESPIN, TRAINER_BACK_PIC_MAY
	return

CinerousTower_Exterior_EventScript_VioletTepig::
	@multi_wild TRAINER_VIOLET_CINEROUS_TOWN_TEPIG, TRAINER_BACK_PIC_MAY
	multi_do_fixed MULTI_BATTLE_2_VS_WILD, TRAINER_VIOLET_CINEROUS_TOWN_TEPIG, TRAINER_BACK_PIC_MAY
	return

CinerousTower_Exterior_EventScript_VioletPopplio::
	@multi_wild TRAINER_VIOLET_CINEROUS_TOWN_POPPLIO, TRAINER_BACK_PIC_MAY
	multi_do_fixed MULTI_BATTLE_2_VS_WILD, TRAINER_VIOLET_CINEROUS_TOWN_POPPLIO, TRAINER_BACK_PIC_MAY
	return

CinerousTower_Exterior_EventScript_VertChespin::
	@multi_wild TRAINER_VERN_CINEROUS_TOWN_CHESPIN, TRAINER_BACK_PIC_BRENDAN
	multi_do_fixed MULTI_BATTLE_2_VS_WILD, TRAINER_VERN_CINEROUS_TOWN_CHESPIN, TRAINER_BACK_PIC_BRENDAN
	return

CinerousTower_Exterior_EventScript_VertTepig::
	@multi_wild TRAINER_VERN_CINEROUS_TOWN_TEPIG, TRAINER_BACK_PIC_BRENDAN
	multi_do_fixed MULTI_BATTLE_2_VS_WILD, TRAINER_VERN_CINEROUS_TOWN_TEPIG, TRAINER_BACK_PIC_BRENDAN
	return

CinerousTower_Exterior_EventScript_VertPopplio::
	@multi_wild TRAINER_VERN_CINEROUS_TOWN_POPPLIO, TRAINER_BACK_PIC_BRENDAN
	multi_do_fixed MULTI_BATTLE_2_VS_WILD, TRAINER_VERN_CINEROUS_TOWN_POPPLIO, TRAINER_BACK_PIC_BRENDAN
	@specialvar VAR_RESULT, B_OUTCOME_LOST
	@goto_if_eq CinerousTower_EventScript_MultiTestLost
	return


