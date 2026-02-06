.set LOCALID_SOULSHARD1, 1
.set LOCALID_SOULSHARD2, 2
.set LOCALID_SOULSHARD3, 3
.set LOCALID_SOULSHARD4, 4
.set LOCALID_SOULSHARD5, 5
.set LOCALID_SOULSHARD6, 6

DreamResort_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DreamResort_1F_OnTransition
	.byte 0

DreamResort_1F_OnTransition::
	goto_if_le VAR_DREAM_RESORT_STATE, 6, DreamResort_1F_RevealShards
	end


DreamResort_1F_RevealShards::
	clearflag FLAG_BATTLED_SPIRITOMB
	addobject LOCALID_SOULSHARD1
	addobject LOCALID_SOULSHARD2
	addobject LOCALID_SOULSHARD3
	addobject LOCALID_SOULSHARD4
	addobject LOCALID_SOULSHARD5
	addobject LOCALID_SOULSHARD6
	end

DreamResort_EventScript_Barrier::
	lock
	msgbox DreamResort_Text_Repeled, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	release
	end

DreamResort_Text_Repeled:
	.string "A strange force repels you.$"

DreamResort_EventScript_SpiritombBattle::
	lockall
	playse SE_RG_DEOXYS_MOVE
	waitse
	delay 20
	msgbox DreamResort_Text_EvilSpirits, MSGBOX_DEFAULT
	playmoncry SPECIES_SPIRITOMB, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_SPIRITOMB, 28
	totemboost_evas2 B_POSITION_OPPONENT_LEFT
	special BattleSetup_StartLegendaryBattle
	waitstate
	fadescreen FADE_TO_BLACK
	setflag FLAG_BATTLED_SPIRITOMB
	removeobject LOCALID_SOULSHARD1
	removeobject LOCALID_SOULSHARD2
	removeobject LOCALID_SOULSHARD3
	removeobject LOCALID_SOULSHARD4
	removeobject LOCALID_SOULSHARD5
	removeobject LOCALID_SOULSHARD6
	setvar VAR_DREAM_RESORT_STATE, 7
	fadescreen FADE_FROM_BLACK
	msgbox DreamResort_Text_EvilSpiritsVanished, MSGBOX_DEFAULT
	releaseall
	end

DreamResort_Text_EvilSpirits:
	.string "It feels like a dark presence\n"
	.string "is nearby.\p"
	.string "...\p"
	.string "No, dozens of them!$"

DreamResort_Text_EvilSpiritsVanished:
	.string "The evil spirits vanished.$"



