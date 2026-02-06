.set LOCALID_ARCEUS, 1

PerennialPillar_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PerennialPillar_1F_OnLoad
	.byte 0

PerennialPillar_1F_OnLoad:
	goto_if_set FLAG_BATTLED_ARCEUS, PerennialPillar_1F_EventScript_Skip
	goto_if_unset FLAG_HIDE_DIALGA, PerennialPillar_1F_EventScript_Skip
	goto_if_unset FLAG_HIDE_PALKIA, PerennialPillar_1F_EventScript_Skip
	goto_if_unset FLAG_HIDE_GIRATINA, PerennialPillar_1F_EventScript_Skip
	setmetatile 20,  7, METATILE_PerennialPillar_Seal1, FALSE
	setmetatile 20,  8, METATILE_PerennialPillar_Seal5, FALSE
	setmetatile 20,  9, METATILE_PerennialPillar_Seal9, FALSE
	setmetatile 20, 10, METATILE_PerennialPillar_Seal13, FALSE
	setmetatile 21,  7, METATILE_PerennialPillar_Seal2, FALSE
	setmetatile 21,  8, METATILE_PerennialPillar_Seal6, FALSE
	setmetatile 21,  9, METATILE_PerennialPillar_Seal10, FALSE
	setmetatile 21, 10, METATILE_PerennialPillar_Seal14, FALSE
	setmetatile 22,  7, METATILE_PerennialPillar_Seal3, FALSE
	setmetatile 22,  8, METATILE_PerennialPillar_Seal7, FALSE
	setmetatile 22,  9, METATILE_PerennialPillar_Seal11, FALSE
	setmetatile 22, 10, METATILE_PerennialPillar_Seal15, FALSE
	setmetatile 23,  7, METATILE_PerennialPillar_Seal4, FALSE
	setmetatile 23,  8, METATILE_PerennialPillar_Seal8, FALSE
	setmetatile 23,  9, METATILE_PerennialPillar_Seal12, FALSE
	setmetatile 23, 10, METATILE_PerennialPillar_Seal16, FALSE
	end

PerennialPillar_1F_EventScript_Skip:
	end





PerennialPillar_EventScript_AzureFlutePrompt::
	lock
	special CheckArceusRequirements
	goto_if_eq VAR_RESULT, TRUE, PerennialPillar_EventScript_PlayAzureFlute
	msgbox PerennialPillar_Text_SomethingsMissing, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	release
	end

PerennialPillar_Text_SomethingsMissing:
	.string "It feels like something's missing.$"

PerennialPillar_EventScript_PlayAzureFlute::
	msgbox PerennialPillar_Text_PlayAzureFlute, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, NO, PerennialPillar_EventScript_DontPlayAzureFlute
	fadeoutbgm 1
	msgbox PerennialPillar_Text_PlayedAzureFlute, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_RG_POKE_FLUTE, FALSE
	delay 480
	msgbox PerennialPillar_Text_IncreasingPressure, MSGBOX_DEFAULT
	closemessage
	fadeoutbgm 1
	delay 60
	playse SE_M_CHARGE
	fadescreen FADE_TO_WHITE
	delay 120
	clearflag FLAG_HIDE_ARCEUS
	addobject LOCALID_ARCEUS
	playmoncry SPECIES_ARCEUS, CRY_MODE_NORMAL
	setvar VAR_TEMP_0, 1
	delay 60
	fadescreen FADE_FROM_WHITE
	delay 60
	fadeinbgm 1
	release
	end
	
PerennialPillar_Text_PlayAzureFlute:
	.string "The AZURE FLUTE seems to be reacting\n"
	.string "to the seal.\p"
	.string "Play the AZURE FLUTE?$"

PerennialPillar_Text_PlayedAzureFlute:
	.string "{PLAYER} played the AZURE FLUTE.$"

PerennialPillar_Text_IncreasingPressure:
	.string "You feel an increasing pressure.$"

PerennialPillar_EventScript_DontPlayAzureFlute::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	release
	end
	


PerennialPillar_EventScript_Arceus::
	lock
	playmoncry SPECIES_ARCEUS, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_ARCEUS, 80
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 1, 1, 1, 1, 1, 1
	special BattleSetup_StartLegendaryBattle
	waitstate
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ARCEUS
	setflag FLAG_HIDE_ARCEUS
	setflag FLAG_BATTLED_ARCEUS
	fadescreen FADE_FROM_BLACK
	release
	end


