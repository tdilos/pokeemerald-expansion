OffwiteTown_House2_MapScripts::
	.byte 0

OffwiteTown_House2_EventScript_OldWoman::
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_21
	goto_if_eq VAR_RESULT, TRUE, OffwiteTown_House2_EventScript_QuestComplete
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_21
	goto_if_eq VAR_RESULT, TRUE, OffwiteTown_House2_EventScript_CheckForBerries
	msgbox OffwiteTown_House2_Text_Errand, MSGBOX_DEFAULT
	@questmenu QUEST_MENU_UNLOCK_QUEST QUEST_21
	@openquestmenu
	startquest QUEST_21
	release
	end

OffwiteTown_House2_Text_Errand:
	.string "Excuse me, youngster.\n"
	.string "Would you do an old woman a favor?\p"
	.string "I'll make it worth your while,\n"
	.string "I promise.\p"
	.string "Here's list of groceries I need.\p"
	.string "It's not easy to get BERRIES\n"
	.string "out here, you know.$"

OffwiteTown_House2_EventScript_CheckForBerries::
	checkitem ITEM_PINAP_BERRY
	goto_if_eq VAR_RESULT, FALSE, OffwiteTown_House2_EventScript_QuestInProgress
	checkitem ITEM_NANAB_BERRY
	goto_if_eq VAR_RESULT, FALSE, OffwiteTown_House2_EventScript_QuestInProgress
	checkitem ITEM_BLUK_BERRY
	goto_if_eq VAR_RESULT, FALSE, OffwiteTown_House2_EventScript_QuestInProgress
	checkitem ITEM_WEPEAR_BERRY
	goto_if_eq VAR_RESULT, FALSE, OffwiteTown_House2_EventScript_QuestInProgress
	msgbox OffwiteTown_House2_Text_ThanksForBerries, MSGBOX_DEFAULT
	removeitem ITEM_PINAP_BERRY, 1
	removeitem ITEM_NANAB_BERRY, 1
	removeitem ITEM_BLUK_BERRY, 1
	removeitem ITEM_WEPEAR_BERRY, 1
	giveitem ITEM_TM22
	@questmenu QUEST_MENU_COMPLETE_QUEST QUEST_21
	completequest QUEST_21
	release
	end

OffwiteTown_House2_Text_ThanksForBerries:
	.string "Oh, wonderful!\n"
	.string "You got everything I asked for.\p"
	.string "Thank you much, youngster.\p"
	.string "Here, take this for your trouble.$"

OffwiteTown_House2_EventScript_QuestInProgress::
	msgbox OffwiteTown_House2_Text_InProgress, MSGBOX_DEFAULT
	release
	end

OffwiteTown_House2_Text_InProgress:
	.string "Check the markets down the mountain.\n"
	.string "I know they have them.$"

OffwiteTown_House2_EventScript_QuestComplete::
	msgbox OffwiteTown_House2_Text_BrightenedMyDay, MSGBOX_DEFAULT
	release
	end

OffwiteTown_House2_Text_BrightenedMyDay:
	.string "It's hard to grow your own berries\n"
	.string "up here.\p"
	.string "We don't get much sunny weather,\n"
	.string "you know.\p"
	.string "But nonetheless, you've\n"
	.string "brightened my day.$"

