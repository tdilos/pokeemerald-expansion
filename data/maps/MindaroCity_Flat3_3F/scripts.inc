MindaroCity_Flat3_3F_MapScripts::
	.byte 0

MindaroCity_Flat3_3F_EventScript_Painter::
	lock
	faceplayer
	goto_if_quest_complete QUEST_18, MindaroCity_Flat3_3F_EventScript_QuestComplete
	goto_if_quest_active QUEST_18, MindaroCity_Flat3_3F_EventScript_QuestInProgress
	msgbox MindaroCity_Flat3_3F_Text_Masterpiece, MSGBOX_DEFAULT
	startquest QUEST_18
	release
	end

MindaroCity_Flat3_3F_Text_Masterpiece:
	.string "To create a masterpiece!\n"
	.string "That is my desire!\p"
	.string "But I lack the materials to bring\n"
	.string "my vision to life.\p"
	.string "Perhaps you can help me.\p"
	.string "I need you to bring a SMEARGLE.\n"
	.string "But not just any will do.\p"
	.string "It must know the moves SOLARBEAM,\n"
	.string "FIRE BLAST, HYDRO PUMP, and THUNDER.\p"
	.string "Can you do that for me?$"

MindaroCity_Flat3_3F_EventScript_QuestInProgress::
	special SmeargleQuestCheck
	goto_if_eq VAR_RESULT, TRUE, MindaroCity_Flat3_3F_EventScript_FinishQuest
	msgbox MindaroCity_Flat3_3F_Text_Masterpiece2, MSGBOX_DEFAULT
	release
	end

MindaroCity_Flat3_3F_Text_Masterpiece2:
	.string "I need you to bring a SMEARGLE.\n"
	.string "But not just any will do.\p"
	.string "It must know the moves SOLARBEAM,\n"
	.string "FIRE BLAST, HYDRO PUMP, and THUNDER.\p"
	.string "In that order too!\n"
	.string "Yes, that's very important!\p"
	.string "You absolutely must show me\n"
	.string "such a SMEARGLE!\p"
	.string "You will be rewarded.\n"
	.string "But of course!$"

MindaroCity_Flat3_3F_EventScript_FinishQuest::
	msgbox MindaroCity_Flat3_3F_Text_Masterpiece3, MSGBOX_DEFAULT
	giveitem ITEM_HEART_SCALE, 99
	completequest QUEST_18
	release
	end

MindaroCity_Flat3_3F_Text_Masterpiece3:
	.string "Oh, your SMEARGLE.\n"
	.string "C'est magnifique!\p"
	.string "It's just what I always wanted to see!\p"
	.string "I must thank you for bedazzling me.\n"
	.string "Please, take these with you.$"

MindaroCity_Flat3_3F_EventScript_QuestComplete::
	msgbox MindaroCity_Flat3_3F_Text_ExplainHeartScales, MSGBOX_DEFAULT
	release
	end

MindaroCity_Flat3_3F_Text_ExplainHeartScales:
	.string "I hear there is a man in PITCHBLAK CITY\n"
	.string "who is quite fond of those HEART SCALES.\p"
	.string "Perhaps you should pay him a visit.$"

