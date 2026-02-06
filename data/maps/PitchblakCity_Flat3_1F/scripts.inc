PitchblakCity_Flat3_1F_MapScripts::
	.byte 0

PitchblakCity_Flat3_1F_EventScript_Breeder::
	lock
	faceplayer
	msgbox PitchblakCity_Flat3_1F_Text_PokemonCages, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Flat3_1F_Text_PokemonCages:
	.string "Do you think it's right to keep\n"
	.string "POKéMON in POKé BALLS?\p"
	.string "Some guy on the street told me it's\n"
	.string "like putting them in a cage.$"

PitchblakCity_Flat3_1F_EventScript_BladeMaster::
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_23
	goto_if_eq VAR_RESULT, TRUE, PitchblakCity_Flat3_1F_EventScript_QuestComplete
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_23
	goto_if_eq VAR_RESULT, TRUE, PitchblakCity_Flat3_1F_EventScript_QuestInProgress
	msgbox PitchblakCity_Flat3_1F_Text_StudyTheBlade, MSGBOX_DEFAULT
	@questmenu QUEST_MENU_UNLOCK_QUEST QUEST_23
	@openquestmenu
	startquest QUEST_23
	release
	end

PitchblakCity_Flat3_1F_Text_StudyTheBlade:
	.string "While others were out catching POKéMON,\n"
	.string "I studied the blade.\p"
	.string "My record now is 99 small trees.\n"
	.string "Think you can beat that?\p"
	.string "Heh. Just try it.$"

PitchblakCity_Flat3_1F_EventScript_QuestInProgress::
	buffernumberstring STR_VAR_3, VAR_CUT_COUNT
	goto_if_ge VAR_CUT_COUNT, 100, PitchblakCity_Flat3_1F_EventScript_GetReward
	msgbox PitchblakCity_Flat3_1F_Text_NotEnough, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Flat3_1F_Text_NotEnough:
	.string "Only {STR_VAR_3} small trees?\n"
	.string "Heh, looks like I'm still the master.$"

PitchblakCity_Flat3_1F_EventScript_GetReward::
	msgbox PitchblakCity_Flat3_1F_Text_Impossible, MSGBOX_DEFAULT
	giveitem ITEM_ZINC, 20
	@questmenu QUEST_MENU_COMPLETE_QUEST QUEST_23
	completequest QUEST_23
	release
	end	

PitchblakCity_Flat3_1F_Text_Impossible:
	.string "I-impossible!\n"
	.string "{STR_VAR_3} small trees?!\p"
	.string "Very well, I concede.\p"
	.string "Take these, you've earned them.$"

PitchblakCity_Flat3_1F_EventScript_QuestComplete::
	msgbox PitchblakCity_Flat3_1F_Text_MuchToLearn, MSGBOX_DEFAULT
	release
	end	

PitchblakCity_Flat3_1F_Text_MuchToLearn:
	.string "You've shown me I still have\n"
	.string "much to learn.\p"
	.string "But one day, I will surpass you!$"

