MaroonCity_Flat1_2F_MapScripts::
	.byte 0

MaroonCity_Flat1_2F_EventScript_BugCatcher::
	lock
	faceplayer
	msgbox MaroonCity_Flat1_2F_Text_PokemonRangers, MSGBOX_DEFAULT
	release
	end

MaroonCity_Flat1_2F_Text_PokemonRangers:
	.string "I heard the POKéMON RANGERS are having\n"
	.string "a big meeting.\p"
	.string "What could it mean?$"




MaroonCity_Flat1_2F_EventScript_FireMaster::
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_28
	goto_if_eq VAR_RESULT, TRUE, MaroonCity_Flat1_2F_EventScript_QuestComplete
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_28
	goto_if_eq VAR_RESULT, TRUE, MaroonCity_Flat1_2F_EventScript_QuestInProgress
	msgbox MaroonCity_Flat1_2F_Text_Pyrokinesis, MSGBOX_DEFAULT
	@questmenu QUEST_MENU_UNLOCK_QUEST QUEST_28
	@openquestmenu
	startquest QUEST_28
	release
	end

MaroonCity_Flat1_2F_Text_Pyrokinesis:
	.string "Have you heard of pyrokinesis?\p"
	.string "I used to perform in the circus years ago.\n"
	.string "I was a firebreather!\p"
	.string "I could melt huge blocks of ice\n"
	.string "in an instant!\p"
	.string "My best record was 99 ice blocks.\n"
	.string "I hope someone beats it one day.\p"
	.string "It's pretty boring being on top\n"
	.string "all the time, you know.\p"
	.string "Who knows, maybe that someone\n"
	.string "could be you.$"

MaroonCity_Flat1_2F_EventScript_QuestInProgress::
	buffernumberstring STR_VAR_3, VAR_THAW_COUNT
	goto_if_ge VAR_THAW_COUNT, 100, MaroonCity_Flat1_2F_EventScript_GetReward
	msgbox MaroonCity_Flat1_2F_Text_NotEnough, MSGBOX_DEFAULT
	release
	end

MaroonCity_Flat1_2F_Text_NotEnough:
	.string "You're trying to be a firebreather\n"
	.string "now too, huh?\p"
	.string "Well, looks like you've got a ways\n"
	.string "to go yet.\p"
	.string "You've only melted {STR_VAR_3} ice blocks.\p"
	.string "My record reigns supreme!$"

MaroonCity_Flat1_2F_EventScript_GetReward::
	msgbox MaroonCity_Flat1_2F_Text_Impossible, MSGBOX_DEFAULT
	giveitem ITEM_CALCIUM, 20
	@questmenu QUEST_MENU_COMPLETE_QUEST QUEST_28
	completequest QUEST_28
	release
	end	

MaroonCity_Flat1_2F_Text_Impossible:
	.string "Woah, no way!\p"
	.string "You melted {STR_VAR_3} ice blocks?!\p"
	.string "I couldn't do that even in my prime!\p"
	.string "Here, take these. You've earned them.$"

MaroonCity_Flat1_2F_EventScript_QuestComplete::
	msgbox MaroonCity_Flat1_2F_Text_MuchToLearn, MSGBOX_DEFAULT
	release
	end	

MaroonCity_Flat1_2F_Text_MuchToLearn:
	.string "In all my years performing,\n"
	.string "there's one thing I've learned.\p"
	.string "Nobody stays the best forever!$"
