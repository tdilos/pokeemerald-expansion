Route96_MapScripts::
	.byte 0

Route96_EventScript_RouteSign::
	msgbox Route96_Text_RouteSign, MSGBOX_SIGN
	end

Route96_Text_RouteSign:
	.string "ROUTE 96\p"
	.string "{LEFT_ARROW} MINDARO CITY\n"
	.string "{RIGHT_ARROW} MT SHIRO$"

Route96_EventScript_Man::
	msgbox Route96_Text_IceCream, MSGBOX_NPC
	end

Route96_Text_IceCream:
	.string "The VANILLITE around here look like\n"
	.string "they're made of tasty ice cream.\p"
	.string "But their heads are actually\n"
	.string "covered in rock salts.\p"
	@.string "covered in dry ice.\p"
	.string "You wouldn't want to lick one of those...$"

Route96_EventScript_Kyle::
	trainerbattle_single TRAINER_KYLE, Route96_Text_KyleIntro, Route96_Text_KyleDefeated
	msgbox Route96_Text_KylePostBattle, MSGBOX_AUTOCLOSE
	end

Route96_EventScript_Goro::
	trainerbattle_single TRAINER_GORO, Route96_Text_GoroIntro, Route96_Text_GoroDefeated
	msgbox Route96_Text_GoroPostBattle, MSGBOX_AUTOCLOSE
	end



Route96_EventScript_FistMaster::
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_20
	goto_if_eq VAR_RESULT, TRUE, Route96_EventScript_QuestComplete
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_20
	goto_if_eq VAR_RESULT, TRUE, Route96_EventScript_QuestInProgress
	msgbox Route96_Text_FistsOfSteel, MSGBOX_DEFAULT
	@questmenu QUEST_MENU_UNLOCK_QUEST QUEST_20
	@openquestmenu
	startquest QUEST_20
	release
	end

Route96_Text_FistsOfSteel:
	.string "I train here every day, smashing rocks\n"
	.string "with my bare hands!\p"
	.string "I've smashed 99 rocks now.\n"
	.string "My fists are like steel!\p"
	.string "Impressive, right?\p"
	.string "\p"
	.string "No?\p"
	.string "Then become my rival and\n"
	.string "try to surpass me!$"

Route96_EventScript_QuestInProgress::
	buffernumberstring STR_VAR_3, VAR_ROCK_SMASH_COUNT
	goto_if_ge VAR_ROCK_SMASH_COUNT, 100, Route96_EventScript_GetReward
	msgbox Route96_Text_NotEnough, MSGBOX_DEFAULT
	release
	end

Route96_Text_NotEnough:
	.string "Despite your best efforts, you've\n"
	.string "only smashed {STR_VAR_3} rocks.\p"
	.string "Looks like I'm still the master!$"

Route96_EventScript_GetReward::
	msgbox Route96_Text_Impossible, MSGBOX_DEFAULT
	giveitem ITEM_TM31
	@questmenu QUEST_MENU_COMPLETE_QUEST QUEST_20
	completequest QUEST_20
	release
	end	

Route96_Text_Impossible:
	.string "What's this?\p"
	.string "You've managed to smash {STR_VAR_3} rocks?!\p"
	.string "I can't believe it! After all my training,\n"
	.string "I've been defeated by a novice!\p"
	.string "But a true warrior bows gracefully\n"
	.string "even in defeat.\p"
	.string "Here, take this with you.$"

Route96_EventScript_QuestComplete::
	msgbox Route96_Text_MuchToLearn, MSGBOX_DEFAULT
	release
	end	

Route96_Text_MuchToLearn:
	.string "My record may be broken,\n"
	.string "but my resolve is not!\p"
	.string "I will continue pushing my\n"
	.string "body to the limit!$"

