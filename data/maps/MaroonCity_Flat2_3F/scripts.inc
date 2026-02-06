MaroonCity_Flat2_3F_MapScripts::
	.byte 0

MaroonCity_Flat2_3F_EventScript_RuinManiac::
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_30
	goto_if_eq VAR_RESULT, TRUE, MaroonCity_Flat2_3F_EventScript_QuestComplete
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_30
	goto_if_eq VAR_RESULT, TRUE, MaroonCity_Flat2_3F_EventScript_CheckTempleFlags
	msgbox MaroonCity_Flat2_3F_Text_TempleMystery, MSGBOX_DEFAULT
	@questmenu QUEST_MENU_UNLOCK_QUEST QUEST_30
	@openquestmenu
	startquest QUEST_30
	release
	end

MaroonCity_Flat2_3F_Text_TempleMystery:
	.string "Hello, how do you do?\p"
	.string "I am an archaeologist.\n"
	.string "I specialise in anthropology.\p"
	.string "Have you heard about the temples\n"
	.string "of ISSHO?\p"
	.string "They're monuments built here long ago to\n"
	.string "honor local deities.\p"
	.string "My colleagues and I are here to learn\n"
	.string "more about their history.\p"
	.string "Who built them? And for what purpose?\p"
	.string "We believe the answers may be contained\n"
	.string "in the inscriptions within the temples.\p"
	.string "But so far, we haven't had any luck\n"
	.string "deciphering them.\p"
	.string "By chance, you wouldn't happen to know\n"
	.string "anything about them?\p"
	.string "\p"
	.string "Well, if you learn anything, I do hope\n"
	.string "you'll share it with us.\p"
	.string "You'll receive ample credit, I assure you.$"

MaroonCity_Flat2_3F_EventScript_CheckTempleFlags::
	goto_if_unset FLAG_SYS_SOLVED_AURORA_TEMPLE, MaroonCity_Flat2_3F_EventScript_QuestInProgress
	goto_if_unset FLAG_SYS_SOLVED_MERIDIA_TEMPLE, MaroonCity_Flat2_3F_EventScript_QuestInProgress
	goto_if_unset FLAG_SYS_SOLVED_VESPER_TEMPLE, MaroonCity_Flat2_3F_EventScript_QuestInProgress
	goto_if_unset FLAG_SYS_SOLVED_MEDIANOX_TEMPLE, MaroonCity_Flat2_3F_EventScript_QuestInProgress
	msgbox MaroonCity_Flat2_3F_Text_SolvedMystery, MSGBOX_DEFAULT
	@questmenu QUEST_MENU_COMPLETE_QUEST QUEST_30
	giveitem ITEM_OLD_AMBER
	msgbox MaroonCity_Flat2_3F_Text_ExplainOldAmber, MSGBOX_DEFAULT
	completequest QUEST_30
	release
	end

MaroonCity_Flat2_3F_Text_SolvedMystery:
	.string "By Jove! You've done it!\p"
	.string "As I suspected, each temple acts as a\n"
	.string "beacon for a certain POKéMON.\p"
	.string "THUNDURUS, TORNADUS,\n"
	.string "LANDORUS, ENAMORUS...\p"
	.string "So these POKéMON lived in ISSHO long ago.\n"
	.string "What a discovery this is!\p"
	.string "Here, you can have this. It's the least\n"
	.string "I can do to thank you for help.$"

MaroonCity_Flat2_3F_EventScript_QuestInProgress::
	msgbox MaroonCity_Flat2_3F_Text_MysteryUnsolved, MSGBOX_DEFAULT
	release
	end

MaroonCity_Flat2_3F_Text_MysteryUnsolved:
	.string "Rumours say the ancient scripts encode\n"
	.string "some sort of instructions.\p"
	.string "The ancients were said to call upon\n"
	.string "their deities in times of hardship.\p"
	.string "I wonder if each temple acts as\n"
	.string "a sort of beacon...$"

MaroonCity_Flat2_3F_EventScript_QuestComplete::
	msgbox MaroonCity_Flat2_3F_Text_ExplainOldAmber, MSGBOX_DEFAULT
	release
	end

MaroonCity_Flat2_3F_Text_ExplainOldAmber:
	.string "That OLD AMBER contains a DNA sample\n"
	.string "of an ancient POKéMON.\p"
	.string "It's quite beautiful, isn't it?$"

