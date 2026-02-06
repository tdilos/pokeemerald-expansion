.set LOCALID_YETREE, 12

MtShiro_EastCave_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtShiro_EastCave_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MtShiro_EastCave_OnTransition
	.byte 0

MtShiro_EastCave_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MtShiro_EastCave_EventScript_TryRemoveYetree
	end

MtShiro_EastCave_EventScript_TryRemoveYetree::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

MtShiro_EastCave_OnTransition:
	call_if_unset FLAG_DEFEATED_SUDOWOODO, MtShiro_EastCave_EventScript_ShowYetree
	end

MtShiro_EastCave_EventScript_ShowYetree::
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return






MtShiro_EastCave_EventScript_Yetree::
	lock
	faceplayer
	checkitem ITEM_ROAD_SALT
	goto_if_eq VAR_RESULT, FALSE, MtShiro_EastCave_EventScript_YetreeNoRoadSalt
	msgbox MtShiro_EastCave_Text_WantToUseRoadSalt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MtShiro_EastCave_EventScript_SprinkleRoadSalt
	release
	end

MtShiro_EastCave_EventScript_YetreeNoRoadSalt::
	msgbox MtShiro_EastCave_Text_WeirdTree, MSGBOX_DEFAULT
	release
	end

MtShiro_EastCave_EventScript_SprinkleRoadSalt::
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitstate
	msgbox MtShiro_EastCave_Text_Yetree_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_YETREE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_YETREE
	setflag FLAG_SYS_CTRL_OBJ_DELETE

	seteventmon SPECIES_YETREE, 46
	totemboost_def2 B_POSITION_OPPONENT_LEFT
	special BattleSetup_StartLegendaryBattle
	waitstate

	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MtShiro_EastCave_EventScript_DefeatedYetree
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MtShiro_EastCave_EventScript_DefeatedYetree
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MtShiro_EastCave_EventScript_DefeatedYetree
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	end

MtShiro_EastCave_EventScript_DefeatedYetree::
	msgbox MtShiro_EastCave_Text_YetreeRetreatedIntoCave
	setflag FLAG_DEFEATED_SUDOWOODO
	goto Common_EventScript_RemoveStaticPokemon
	end

MtShiro_EastCave_Text_WeirdTree:
	.string "It looks like a giant tree is in the way.$"

MtShiro_EastCave_Text_WantToUseRoadSalt:
	.string "It looks like a giant tree is in the way.\p"
	.string "Want to sprinkle it with ROAD SALT?$"

MtShiro_EastCave_Text_Yetree_Attacked:
	.string "The tree is moving!\p"
	.string "It doesn't seem to like the ROAD SALT.$"

MtShiro_EastCave_Text_YetreeRetreatedIntoCave:
	.string "YETREE retreated deep into the cave.$"





MtShiro_EastCave_EventScript_Earl::
	trainerbattle_single TRAINER_EARL, MtShiro_EastCave_Text_EarlIntro, MtShiro_EastCave_Text_EarlDefeated
	msgbox MtShiro_EastCave_Text_EarlPostBattle, MSGBOX_AUTOCLOSE
	end




