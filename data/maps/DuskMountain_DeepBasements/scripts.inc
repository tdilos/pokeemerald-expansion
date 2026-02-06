.set LOCALID_DIANCIE, 1
.set LOCALID_SCIENTIST, 2

DuskMountain_DeepBasements_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, DuskMountain_DeepBasements_OnLoad
	.byte 0

DuskMountain_DeepBasements_OnLoad:
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_41
	call_if_eq VAR_RESULT, FALSE, DuskMountain_DeepBasements_EventScript_HideDiancieEntrance
	end

DuskMountain_DeepBasements_EventScript_HideDiancieEntrance::
	setmetatile 24, 8, METATILE_Cave2_DuskWall, TRUE
	setmetatile 24, 9, METATILE_Cave2_DuskWall, TRUE
	return

DuskMountain_DeepBasements_EventScript_RevealDiancieEntrance::
	setmetatile 24, 8, METATILE_Cave2_DuskEntrance_Top, TRUE
	setmetatile 24, 9, METATILE_Cave2_DuskEntrance_Bottom, FALSE
	special DrawWholeMapView
	playse SE_BANG
	waitse
	return



DuskMountain_EventScript_Diancie::
	lock
	playmoncry SPECIES_DIANCIE, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_DIANCIE, 50
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 1, 1, 1, 1, 1, 1
	special BattleSetup_StartLegendaryBattle
	waitstate
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_DIANCIE
	setflag FLAG_BATTLED_DIANCIE
	fadescreen FADE_FROM_BLACK
	release
	end







DuskMountain_DeepBasements_EventScript_Scientist::
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_41
	goto_if_eq VAR_RESULT, TRUE, DuskMountain_DeepBasements_EventScript_QuestComplete
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_41
	goto_if_eq VAR_RESULT, TRUE, DuskMountain_DeepBasements_EventScript_QuestInProgress
	msgbox DuskMountain_DeepBasements_Text_Request, MSGBOX_DEFAULT
	startquest QUEST_41
	release
	end

DuskMountain_DeepBasements_Text_Request:
	.string "I'm here to research the POKéMON CARBINK.\n"
	.string "Have you heard of it?\p"
	.string "They're said to spawn deep underground\n"
	.string "in places like DUSK MOUNTAIN.\p"
	.string "But they're very rare!\n"
	.string "I've never seen one myself.\p"
	.string "If I only I could find just one CARBINK,\n"
	.string "there's so much we could learn from it!$"

DuskMountain_DeepBasements_EventScript_QuestInProgress::
	msgbox DuskMountain_DeepBasements_Text_FoundOneYet, MSGBOX_DEFAULT
	special CheckForCarbink
	goto_if_eq VAR_RESULT, TRUE, DuskMountain_DeepBasements_EventScript_CompleteQuest
	msgbox DuskMountain_DeepBasements_Text_NotRightPokemon, MSGBOX_DEFAULT
	release
	end

DuskMountain_DeepBasements_Text_FoundOneYet:
	.string "Have you brought me a CARBINK?$"

DuskMountain_DeepBasements_Text_NotRightPokemon:
	.string "No, I'm afraid that's not the\n"
	.string "POKéMON I'm looking for.$"

DuskMountain_DeepBasements_EventScript_CompleteQuest::
	msgbox DuskMountain_DeepBasements_Text_ThatsIt, MSGBOX_DEFAULT
	@giveitem ITEM_POWER_LENS
	delay 60
	call DuskMountain_DeepBasements_EventScript_RevealDiancieEntrance
	delay 30
	applymovement LOCALID_SCIENTIST, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCALID_SCIENTIST, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	delay 20
	msgbox DuskMountain_DeepBasements_Text_CaveDoorOpened, MSGBOX_DEFAULT
	completequest QUEST_41
	release
	end

DuskMountain_DeepBasements_Text_ThatsIt:
	.string "Oh, that's it!\n"
	.string "That's a CARBINK!\p"
	.string "Yes, I'll take notes right away!\n"
	.string "Thank you so much!\p"
	.string "\p"
	.string "Our geologists will be overjoyed\n"
	.string "when they see this new data...$"

DuskMountain_DeepBasements_EventScript_QuestComplete::
	msgbox DuskMountain_DeepBasements_Text_CaveDoorOpened, MSGBOX_DEFAULT
	release
	end

DuskMountain_DeepBasements_Text_CaveDoorOpened:
	.string "What's this? CARBINK seemed to react to\n"
	.string "the wall here and opened a hidden door!$"


