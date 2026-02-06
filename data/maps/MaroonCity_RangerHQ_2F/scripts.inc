MaroonCity_RangerHQ_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MaroonCity_RangerHQ_2F_OnTransition
	.byte 0

MaroonCity_RangerHQ_2F_OnTransition:
	call_if_unset FLAG_FOUND_DRIFLOON_1, MaroonCity_RangerHQ_2F_EventScript_HideDrifloon1
	call_if_unset FLAG_FOUND_DRIFLOON_2, MaroonCity_RangerHQ_2F_EventScript_HideDrifloon2
	call_if_unset FLAG_FOUND_DRIFLOON_3, MaroonCity_RangerHQ_2F_EventScript_HideDrifloon3
	call_if_unset FLAG_FOUND_DRIFLOON_4, MaroonCity_RangerHQ_2F_EventScript_HideDrifloon4
	call_if_unset FLAG_FOUND_DRIFLOON_5, MaroonCity_RangerHQ_2F_EventScript_HideDrifloon5
	call_if_unset FLAG_FOUND_DRIFLOON_6, MaroonCity_RangerHQ_2F_EventScript_HideDrifloon6
	call_if_unset FLAG_FOUND_DRIFLOON_7, MaroonCity_RangerHQ_2F_EventScript_HideDrifloon7
	call_if_unset FLAG_FOUND_DRIFLOON_8, MaroonCity_RangerHQ_2F_EventScript_HideDrifloon8
	call_if_unset FLAG_FOUND_DRIFLOON_9, MaroonCity_RangerHQ_2F_EventScript_HideDrifloon9	
	call_if_set FLAG_FOUND_DRIFLOON_1, MaroonCity_RangerHQ_2F_EventScript_RevealDrifloon1
	call_if_set FLAG_FOUND_DRIFLOON_2, MaroonCity_RangerHQ_2F_EventScript_RevealDrifloon2
	call_if_set FLAG_FOUND_DRIFLOON_3, MaroonCity_RangerHQ_2F_EventScript_RevealDrifloon3
	call_if_set FLAG_FOUND_DRIFLOON_4, MaroonCity_RangerHQ_2F_EventScript_RevealDrifloon4
	call_if_set FLAG_FOUND_DRIFLOON_5, MaroonCity_RangerHQ_2F_EventScript_RevealDrifloon5
	call_if_set FLAG_FOUND_DRIFLOON_6, MaroonCity_RangerHQ_2F_EventScript_RevealDrifloon6
	call_if_set FLAG_FOUND_DRIFLOON_7, MaroonCity_RangerHQ_2F_EventScript_RevealDrifloon7
	call_if_set FLAG_FOUND_DRIFLOON_8, MaroonCity_RangerHQ_2F_EventScript_RevealDrifloon8
	call_if_set FLAG_FOUND_DRIFLOON_9, MaroonCity_RangerHQ_2F_EventScript_RevealDrifloon9
	end

MaroonCity_RangerHQ_2F_EventScript_HideDrifloon1::
	setflag FLAG_MISSING_DRIFLOON_1
	return

MaroonCity_RangerHQ_2F_EventScript_HideDrifloon2::
	setflag FLAG_MISSING_DRIFLOON_2
	return

MaroonCity_RangerHQ_2F_EventScript_HideDrifloon3::
	setflag FLAG_MISSING_DRIFLOON_3
	return

MaroonCity_RangerHQ_2F_EventScript_HideDrifloon4::
	setflag FLAG_MISSING_DRIFLOON_4
	return

MaroonCity_RangerHQ_2F_EventScript_HideDrifloon5::
	setflag FLAG_MISSING_DRIFLOON_5
	return

MaroonCity_RangerHQ_2F_EventScript_HideDrifloon6::
	setflag FLAG_MISSING_DRIFLOON_6
	return

MaroonCity_RangerHQ_2F_EventScript_HideDrifloon7::
	setflag FLAG_MISSING_DRIFLOON_7
	return

MaroonCity_RangerHQ_2F_EventScript_HideDrifloon8::
	setflag FLAG_MISSING_DRIFLOON_8
	return

MaroonCity_RangerHQ_2F_EventScript_HideDrifloon9::
	setflag FLAG_MISSING_DRIFLOON_9
	return

MaroonCity_RangerHQ_2F_EventScript_RevealDrifloon1::
	clearflag FLAG_MISSING_DRIFLOON_1
	return

MaroonCity_RangerHQ_2F_EventScript_RevealDrifloon2::
	clearflag FLAG_MISSING_DRIFLOON_2
	return

MaroonCity_RangerHQ_2F_EventScript_RevealDrifloon3::
	clearflag FLAG_MISSING_DRIFLOON_3
	return

MaroonCity_RangerHQ_2F_EventScript_RevealDrifloon4::
	clearflag FLAG_MISSING_DRIFLOON_4
	return

MaroonCity_RangerHQ_2F_EventScript_RevealDrifloon5::
	clearflag FLAG_MISSING_DRIFLOON_5
	return

MaroonCity_RangerHQ_2F_EventScript_RevealDrifloon6::
	clearflag FLAG_MISSING_DRIFLOON_6
	return

MaroonCity_RangerHQ_2F_EventScript_RevealDrifloon7::
	clearflag FLAG_MISSING_DRIFLOON_7
	return

MaroonCity_RangerHQ_2F_EventScript_RevealDrifloon8::
	clearflag FLAG_MISSING_DRIFLOON_8
	return

MaroonCity_RangerHQ_2F_EventScript_RevealDrifloon9::
	clearflag FLAG_MISSING_DRIFLOON_9
	return











MaroonCity_RangerHQ_2F_EventScript_Ranger::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EON_TICKET, MaroonCity_RangerHQ_2F_EventScript_ExplainEonTicket
	specialvar VAR_RESULT, GetCompletedQuestCount
	goto_if_ge VAR_RESULT, 32, MaroonCity_RangerHQ_2F_EventScript_GiveEonTicket
	msgbox MaroonCity_RangerHQ_2F_Text_Help32People, MSGBOX_DEFAULT
	release
	end

MaroonCity_RangerHQ_2F_EventScript_GiveEonTicket::
	msgbox MaroonCity_RangerHQ_2F_Text_GreatWork, MSGBOX_DEFAULT
	giveitem ITEM_EON_TICKET
	setflag FLAG_RECEIVED_EON_TICKET
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
	release
	end

MaroonCity_RangerHQ_2F_EventScript_ExplainEonTicket::
	msgbox MaroonCity_RangerHQ_2F_Text_ExplainEonTicket, MSGBOX_DEFAULT
	closemessage
	release
	end

MaroonCity_RangerHQ_2F_Text_Help32People:
	@.string "Being a POKéMON RANGER isn't so easy.\n"
	.string "Have you been keeping up with\n"
	.string "your QUEST LOG?\p"
	.string "Come talk to me again after you've\n"
	.string "helped 32 people.$"

MaroonCity_RangerHQ_2F_Text_GreatWork:
	.string "Woah, you helped 32 people.\n"
	.string "Great work, agent {PLAYER}!\p"
	.string "You're really serious about being\n"
	.string "an upstanding POKéMON RANGER.\p"
	.string "Here you can have this strange\n"
	.string "ticket I found.$"


MaroonCity_RangerHQ_2F_Text_ExplainEonTicket:
	.string "Show that EON TICKET to a sailor\n"
	.string "in XANTHOS CITY.\p"
	.string "I'm sure they'll know what it means.$"

MaroonCity_RangerHQ_2F_EventScript_OldWoman::
	lock
	faceplayer
	msgbox MaroonCity_RangerHQ_2F_Text_HelpfulRangers, MSGBOX_DEFAULT
	release
	end

MaroonCity_RangerHQ_2F_Text_HelpfulRangers:
	.string "The POKéMON RANGERS are an all\n"
	.string "volunteer organization.\p"
	.string "But sponsors like me chip in sometimes\n"
	.string "to help them meet basic costs.\p"
	.string "They do our community a whole lot\n"
	.string "of good after all!$"

MaroonCity_RangerHQ_2F_EventScript_Twin::
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_31
	goto_if_eq VAR_RESULT, TRUE, MaroonCity_RangerHQ_2F_EventScript_QuestComplete
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_31
	goto_if_eq VAR_RESULT, TRUE, MaroonCity_RangerHQ_2F_EventScript_QuestInProgress
	msgbox MaroonCity_RangerHQ_2F_Text_LostBalloons, MSGBOX_DEFAULT
	startquest QUEST_31
	release
	end

MaroonCity_RangerHQ_2F_Text_LostBalloons:
	.string "Hi, can you help me?\p"
	.string "I was walking with my balloons on\n"
	.string "the beach, but the wind blew them away!\p"
	.string "I tried to get them back.\n"
	.string "But I can't swim that far.\p"
	.string "Can you go find them for me?\n"
	.string "They went towards ROUTE 68.$"

MaroonCity_RangerHQ_2F_EventScript_QuestInProgress::
	goto_if_set FLAG_MISSING_DRIFLOON_1, MaroonCity_RangerHQ_2F_EventScript_MissingDrifloon
	goto_if_set FLAG_MISSING_DRIFLOON_2, MaroonCity_RangerHQ_2F_EventScript_MissingDrifloon
	goto_if_set FLAG_MISSING_DRIFLOON_3, MaroonCity_RangerHQ_2F_EventScript_MissingDrifloon
	goto_if_set FLAG_MISSING_DRIFLOON_4, MaroonCity_RangerHQ_2F_EventScript_MissingDrifloon
	goto_if_set FLAG_MISSING_DRIFLOON_5, MaroonCity_RangerHQ_2F_EventScript_MissingDrifloon
	goto_if_set FLAG_MISSING_DRIFLOON_6, MaroonCity_RangerHQ_2F_EventScript_MissingDrifloon
	goto_if_set FLAG_MISSING_DRIFLOON_7, MaroonCity_RangerHQ_2F_EventScript_MissingDrifloon
	goto_if_set FLAG_MISSING_DRIFLOON_8, MaroonCity_RangerHQ_2F_EventScript_MissingDrifloon
	goto_if_set FLAG_MISSING_DRIFLOON_9, MaroonCity_RangerHQ_2F_EventScript_MissingDrifloon
	goto MaroonCity_RangerHQ_2F_EventScript_GetReward
	end

MaroonCity_RangerHQ_2F_EventScript_MissingDrifloon::
	msgbox MaroonCity_RangerHQ_2F_Text_QuestInProgress, MSGBOX_DEFAULT
	release
	end

MaroonCity_RangerHQ_2F_Text_QuestInProgress:
	.string "There are 9 DRIFLOON that blew away.\n"
	.string "I hope they're not stuck somewhere.$"

MaroonCity_RangerHQ_2F_EventScript_GetReward::
	msgbox MaroonCity_RangerHQ_2F_Text_YouFoundThem, MSGBOX_DEFAULT
	giveitem ITEM_AIR_BALLOON, 6
	@questmenu QUEST_MENU_COMPLETE_QUEST QUEST_31
	completequest QUEST_31
	release
	end	

MaroonCity_RangerHQ_2F_Text_YouFoundThem:
	.string "You found all my balloons!\n"
	.string "Thank you so much!\p"
	.string "Here, you can keep these balloons!$"

MaroonCity_RangerHQ_2F_EventScript_QuestComplete::
	msgbox MaroonCity_RangerHQ_2F_Text_QuestComplete, MSGBOX_DEFAULT
	release
	end	

MaroonCity_RangerHQ_2F_Text_QuestComplete:
	.string "Next time we go walking, I'll tie them\n"
	.string "to something heavy like daddy's go-kart!$"

MaroonCity_RangerHQ_2F_EventScript_Pokemon::
	lock
	faceplayer
	playmoncry SPECIES_DRIFLOON, CRY_MODE_NORMAL
	msgbox MaroonCity_RangerHQ_2F_Text_Pokemon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MaroonCity_RangerHQ_2F_Text_Pokemon:
	.string "DRIFLOON: Wuuwooowawawawiip$"






