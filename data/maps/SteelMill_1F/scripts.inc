.set LOCALID_WORKER, 13

SteelMill_1F_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SteelMill_1F_OnWarp
	.byte 0

SteelMill_1F_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, SteelMill_1F_EventScript_UnsetForceOffscreenLoad
	.2byte 0

SteelMill_1F_EventScript_UnsetForceOffscreenLoad::
	clearflag FLAG_FORCE_LOAD_OFFSCREEN_OBJEV
	end




SteelMill_EventScript_Hans::
	trainerbattle_single TRAINER_HANS, SteelMill_Text_HansIntro, SteelMill_Text_HansDefeated
	msgbox SteelMill_Text_HansPostBattle, MSGBOX_AUTOCLOSE
	end

SteelMill_EventScript_Bernard::
	trainerbattle_single TRAINER_BERNARD, SteelMill_Text_BernardIntro, SteelMill_Text_BernardDefeated
	msgbox SteelMill_Text_BernardPostBattle, MSGBOX_AUTOCLOSE
	end

SteelMill_EventScript_Klaus::
	trainerbattle_single TRAINER_KLAUS, SteelMill_Text_KlausIntro, SteelMill_Text_KlausDefeated
	msgbox SteelMill_Text_KlausPostBattle, MSGBOX_AUTOCLOSE
	end

SteelMill_EventScript_Otto::
	trainerbattle_single TRAINER_OTTO, SteelMill_Text_OttoIntro, SteelMill_Text_OttoDefeated
	msgbox SteelMill_Text_OttoPostBattle, MSGBOX_AUTOCLOSE
	end





SteelMill_EventScript_Worker::
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_34
	goto_if_eq VAR_RESULT, TRUE, SteelMill_EventScript_QuestComplete
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_34
	goto_if_eq VAR_RESULT, TRUE, SteelMill_EventScript_QuestInProgress
	msgbox SteelMill_Text_HeavyPokemon, MSGBOX_DEFAULT
	applymovement LOCALID_WORKER, Common_Movement_FaceUp
	waitmovement 0
	startquest QUEST_34
	release
	end

SteelMill_Text_HeavyPokemon:
	.string "I love heavyweight POKéMON.\p"
	.string "I want to see the heaviest team\n"
	.string "you can make.\p"
	.string "If you can show me a team that's at least\n"
	.string "3000lbs, I'll make it worth your while.$"

SteelMill_EventScript_QuestInProgress::
	msgbox SteelMill_Text_CheckWeight, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetTeamWeight
	buffernumberstring 0, VAR_RESULT
	goto_if_ge VAR_RESULT, 3000, SteelMill_EventScript_CompleteQuest
	msgbox SteelMill_Text_NotHeavyEnough, MSGBOX_DEFAULT
	applymovement LOCALID_WORKER, Common_Movement_FaceUp
	waitmovement 0
	release
	end
	
SteelMill_Text_CheckWeight:
	.string "Have you made a super heavyweight\n"
	.string "team yet?$"

SteelMill_Text_NotHeavyEnough:
	.string "Nope.\n"
	.string "Your team only weighs {STR_VAR_1}lbs.$"

SteelMill_EventScript_CompleteQuest::
	msgbox SteelMill_Text_ThatsWhatImTalkingAbout, MSGBOX_DEFAULT
	giveitem ITEM_POWER_WEIGHT, 6
	msgbox SteelMill_Text_ExplainPowerItem, MSGBOX_DEFAULT
	completequest QUEST_34
	applymovement LOCALID_WORKER, Common_Movement_FaceUp
	waitmovement 0
	release
	end

SteelMill_Text_ThatsWhatImTalkingAbout:
	.string "Wow, {STR_VAR_1}lbs.\n"
	.string "Now that's what I'm talking about!\p"
	.string "Thanks for showing me.\n"
	.string "Here, you can have this.$"

SteelMill_EventScript_QuestComplete::
	msgbox SteelMill_Text_ExplainPowerItem, MSGBOX_DEFAULT
	applymovement LOCALID_WORKER, Common_Movement_FaceUp
	waitmovement 0	
	release
	end

SteelMill_Text_ExplainPowerItem:
	.string "Give that POWER WEIGHT to one\n"
	.string "of your POKéMON to wear.\p"
	.string "It'll help train its HP faster.$"


