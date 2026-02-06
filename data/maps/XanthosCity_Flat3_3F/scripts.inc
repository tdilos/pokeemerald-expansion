XanthosCity_Flat3_3F_MapScripts::
	.byte 0

XanthosCity_Flat3_3F_EventScript_Guard::
	msgbox XanthosCity_Flat3_3F_Text_NoVisitors, MSGBOX_NPC
	end

XanthosCity_Flat3_3F_Text_NoVisitors:
	.string "Visitors are not allowed in the penthouse\n"
	.string "at this time.$"

XanthosCity_Flat3_3F_EventScript_ShinyHunter::
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_6
	goto_if_eq VAR_RESULT, TRUE, XanthosCity_Flat3_3F_EventScript_QuestComplete
	special CheckIfShinyLead
	goto_if_eq VAR_RESULT, TRUE, XanthosCity_Flat3_3F_EventScript_SeesShiny
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_6
	goto_if_eq VAR_RESULT, TRUE, XanthosCity_Flat3_3F_EventScript_QuestInProgress
	msgbox XanthosCity_Flat3_3F_Text_LookingForShinies, MSGBOX_DEFAULT
	@questmenu QUEST_MENU_UNLOCK_QUEST QUEST_6
	@openquestmenu
	startquest QUEST_6
	release
	end

XanthosCity_Flat3_3F_Text_LookingForShinies:
	.string "I really want see shiny POKéMON.\p"
	.string "But find them is so hard.\p"
	.string "You bring shiny POKéMON, I give\n"
	.string "you big reward, okay?$"

XanthosCity_Flat3_3F_EventScript_QuestInProgress::
	msgbox XanthosCity_Flat3_3F_Text_BringMeShinies, MSGBOX_DEFAULT
	release
	end

XanthosCity_Flat3_3F_Text_BringMeShinies:
	.string "You bring shiny POKéMON yet?$"

XanthosCity_Flat3_3F_EventScript_SeesShiny::
	msgbox XanthosCity_Flat3_3F_Text_SeesShiny, MSGBOX_DEFAULT
	giveitem ITEM_BIG_NUGGET
	@questmenu QUEST_MENU_COMPLETE_QUEST QUEST_6
	completequest QUEST_6
	release
	end

XanthosCity_Flat3_3F_Text_SeesShiny:
	.string "Oh yes! That's a shiny POKéMON!\p"
	.string "You don't know how long I wait\n"
	.string "see one.\p"
	.string "I give you big reward now like I promise.$"

XanthosCity_Flat3_3F_EventScript_QuestComplete::
	msgbox XanthosCity_Flat3_3F_Text_ShinyToo, MSGBOX_DEFAULT
	release
	end

XanthosCity_Flat3_3F_Text_ShinyToo:
	.string "That's a shiny too, see?$"

