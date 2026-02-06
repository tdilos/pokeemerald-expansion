Route90_House1_MapScripts::
	.byte 0

Route90_House1_EventScript_Numbskull::
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_22
	goto_if_eq VAR_RESULT, TRUE, Route90_House1_EventScript_QuestComplete
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_22
	goto_if_eq VAR_RESULT, TRUE, Route90_House1_EventScript_QuestInProgress
	msgbox Route90_House1_Text_HeadbuttTrees, MSGBOX_DEFAULT
	startquest QUEST_22
	release
	end

Route90_House1_Text_HeadbuttTrees:
	.string "Teach your POKéMON to use HEADBUTT\n"
	.string "on large trees.\p"
	.string "It'll make their head round and shiny\n"
	.string "like mine.\p"
	.string "Well, let's see you try it!\p"
	.string "Come back here once you've HEADBUTTED\n"
	.string "at least 100 trees.$"

Route90_House1_EventScript_QuestInProgress::
	buffernumberstring STR_VAR_3, VAR_HEADBUTT_COUNT
	goto_if_ge VAR_HEADBUTT_COUNT, 100, Route90_House1_EventScript_GetReward
	msgbox Route90_House1_Text_NotEnough, MSGBOX_DEFAULT
	release
	end

Route90_House1_Text_NotEnough:
	.string "You've only HEADBUTTED {STR_VAR_3} trees?\p"
	.string "Your POKéMON won't get beautiful\n"
	.string "bald heads like that!$"

Route90_House1_EventScript_GetReward::
	msgbox Route90_House1_Text_WellDone, MSGBOX_DEFAULT
	giveitem ITEM_IRON, 20
	completequest QUEST_22
	release
	end	

Route90_House1_Text_WellDone:
	.string "You've HEADBUTTED {STR_VAR_3}?\n"
	.string "Now that's impressive!\p"
	.string "Here, take these with you.$"

Route90_House1_EventScript_QuestComplete::
	msgbox Route90_House1_Text_BaldIsBeautiful, MSGBOX_DEFAULT
	release
	end	

Route90_House1_Text_BaldIsBeautiful:
	.string "Remember, bald is beautiful!$"


