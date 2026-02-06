MaroonCity_Flat1_1F_MapScripts::
	.byte 0

MaroonCity_Flat1_1F_EventScript_Boy1::
	lock
	faceplayer
	msgbox MaroonCity_Flat1_1F_Text_ScaryWoods, MSGBOX_DEFAULT
	release
	end

MaroonCity_Flat1_1F_Text_ScaryWoods:
	.string "That big black POKéMON was scary.\p"
	.string "It could change shape and copy\n"
	.string "our voices.\p"
	.string "I sure hope I never see one\n"
	.string "of those again.$"

MaroonCity_Flat1_1F_EventScript_Boy2::
	lock
	faceplayer
	msgbox MaroonCity_Flat1_1F_Text_CreepyWoods, MSGBOX_DEFAULT
	release
	end

MaroonCity_Flat1_1F_Text_CreepyWoods:
	.string "That forest was filled with\n"
	.string "creepy girls.\p"
	.string "What's their deal, anyway?$"

MaroonCity_Flat1_1F_EventScript_WorriedMom::
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_29
	goto_if_eq VAR_RESULT, TRUE, MaroonCity_Flat1_1F_EventScript_QuestComplete
	goto_if_unset FLAG_HIDE_LOST_BOYS, MaroonCity_Flat1_1F_EventScript_PostRescue
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_29
	goto_if_eq VAR_RESULT, TRUE, MaroonCity_Flat1_1F_EventScript_QuestInProgress
	msgbox MaroonCity_Flat1_1F_Text_WorriedAboutBoys, MSGBOX_DEFAULT
	@questmenu QUEST_MENU_UNLOCK_QUEST QUEST_29
	@openquestmenu
	startquest QUEST_29
	release
	end

MaroonCity_Flat1_1F_Text_WorriedAboutBoys:
	.string "My two boys went out to play\n"
	.string "by the woods.\p"
	.string "But it's been a long time now, and\n"
	.string "they still haven't come home.\p"
	.string "I hope they didn't get lost in\n"
	.string "the woods...\p"
	.string "You're a POKéMON trainer, right?\n"
	.string "Would you help me look for them?$"

MaroonCity_Flat1_1F_EventScript_QuestInProgress::
	msgbox MaroonCity_Flat1_1F_Text_BeenALongTime, MSGBOX_DEFAULT
	release
	end

MaroonCity_Flat1_1F_Text_BeenALongTime:
	.string "Any sign of my boys?\n"
	.string "It's been a long time now.\p"
	.string "Oh, I hope nothing's happened to them...$"

MaroonCity_Flat1_1F_EventScript_PostRescue::
	msgbox MaroonCity_Flat1_1F_Text_YouFoundThem, MSGBOX_DEFAULT
	giveitem ITEM_TM01
	@questmenu QUEST_MENU_COMPLETE_QUEST QUEST_29
	completequest QUEST_29
	release
	end

MaroonCity_Flat1_1F_Text_YouFoundThem:
	.string "The boys told me what happened.\p"
	.string "A shapeshifting POKéMON.\n"
	.string "How terrifying!\p"
	.string "I can't thank you enough for\n"
	.string "rescuing them.\p"
	.string "Maybe this will do. I don't have\n"
	.string "any use for it.$"

MaroonCity_Flat1_1F_EventScript_QuestComplete::
	msgbox MaroonCity_Flat1_1F_Text_NoMoreExploring, MSGBOX_DEFAULT	
	release
	end

MaroonCity_Flat1_1F_Text_NoMoreExploring:
	.string "Thank you so much for your help.\p"
	.string "I'm never letting them go into that woods\n"
	.string "by themselves ever again!$"



