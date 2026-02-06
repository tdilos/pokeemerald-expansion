PitchblakCity_Flat2_1F_MapScripts::
	.byte 0

PitchblakCity_Flat2_1F_EventScript_Man::
	msgbox PitchblakCity_Flat2_1F_Text_MoreRestaurants, MSGBOX_NPC
	end

PitchblakCity_Flat2_1F_Text_MoreRestaurants:
	.string "You know what this city needs?\n"
	.string "More restaurants!\p"
	.string "Have you tried Kalosian food before?\n"
	.string "It's the best!$"


PitchblakCity_Flat2_1F_EventScript_GourmetHunter::
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_26
	goto_if_eq VAR_RESULT, TRUE, PitchblakCity_Flat2_1F_EventScript_QuestComplete
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_26
	goto_if_eq VAR_RESULT, TRUE, PitchblakCity_Flat2_1F_EventScript_QuestInProgress
	msgbox PitchblakCity_Flat2_1F_Text_GourmetRequest, MSGBOX_DEFAULT
	@questmenu QUEST_MENU_UNLOCK_QUEST QUEST_26
	startquest QUEST_26
	end

PitchblakCity_Flat2_1F_Text_GourmetRequest:
	.string "Have you heard of HANAMIDANGO?\n"
	.string "It's the ISSHO region's specialty.\p"
	.string "Oh, what I would give to try a\n"
	.string "HANAMIDANGO one day...$"

PitchblakCity_Flat2_1F_EventScript_QuestInProgress::
	checkitem ITEM_HANAMIDANGO
	goto_if_eq VAR_RESULT, TRUE, PitchblakCity_Flat2_1F_EventScript_CompleteQuest
	msgbox PitchblakCity_Flat2_1F_Text_TryLavaCookie, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Flat2_1F_Text_TryLavaCookie:
	.string "Oh, what I would give to try a\n"
	.string "HANAMIDANGO one day...$"

PitchblakCity_Flat2_1F_EventScript_CompleteQuest::
	msgbox PitchblakCity_Flat2_1F_Text_ThatsIt, MSGBOX_DEFAULT
	removeitem ITEM_HANAMIDANGO
	giveitem ITEM_MICLE_BERRY
	completequest QUEST_26
	release
	end

PitchblakCity_Flat2_1F_Text_ThatsIt:
	.string "Oh, you brought a HANAMIDANGO for me?\n"
	.string "You're so sweet!\p"	
	.string "Here, you can try one of these!$"

PitchblakCity_Flat2_1F_EventScript_QuestComplete::
	msgbox PitchblakCity_Flat2_1F_Text_ExplainMicleBerry, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Flat2_1F_Text_ExplainMicleBerry:
	.string "Feed that MICLE BERRY to\n"
	.string "one of your POKéMON.\p"
	.string "It'll raise their accuracy\n"
	.string "in a tight spot.$"

PitchblakCity_Flat2_1F_EventScript_LittleGirl::
	lock
	faceplayer
	msgbox PitchblakCity_Flat2_1F_Text_LuckyYou, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Flat2_1F_Text_LuckyYou:
	.string "You're a POKéMON trainer?\p"
	.string "Lucky.\n"
	.string "I wish I had POKéMON to play with.$"

PitchblakCity_Flat2_1F_EventScript_Youngster::
	lock
	faceplayer
	msgbox PitchblakCity_Flat2_1F_Text_FunnyCandy, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Flat2_1F_Text_FunnyCandy:
	.string "Some guy upstairs tried to sell me\n"
	.string "these funny candies.\p"
	.string "I don't know, it seemed kinda sketchy.$"


