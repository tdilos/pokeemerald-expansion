MindaroCity_Flat2_2F_MapScripts::
	.byte 0

MindaroCity_Flat2_2F_EventScript_Gentleman::
	lock
	faceplayer
	goto_if_quest_complete QUEST_19, MindaroCity_Flat2_2F_EventScript_ExplainRevealGlass
	goto_if_quest_active QUEST_19, MindaroCity_Flat2_2F_EventScript_CheckForCrown
	msgbox MindaroCity_Flat2_2F_Text_TreasureHunter, MSGBOX_DEFAULT
	startquest QUEST_19
	release
	end

MindaroCity_Flat2_2F_Text_TreasureHunter:
	.string "Believe it or not, I was once a\n"
	.string "treasure hunter in my youth.\p"
	.string "But there was one treasure\n"
	.string "I could never find.\p"
	.string "A RELIC CROWN.\p"
	.string "I'd very much like to have\n"
	.string "one of those.\p"
	.string "And of course, the finder would\n"
	.string "be rewarded handsomely.$"

MindaroCity_Flat2_2F_EventScript_CheckForCrown::
	checkitem ITEM_RELIC_CROWN
	goto_if_eq VAR_RESULT, FALSE, MindaroCity_Flat2_2F_EventScript_QuestInProgress
	goto_if_unset FLAG_ITEM_MIRAGE_PALACE_RELIC_CROWN, MindaroCity_Flat2_2F_EventScript_QuestInProgress
	goto MindaroCity_Flat2_2F_EventScript_TradeCrown
	end

MindaroCity_Flat2_2F_EventScript_QuestInProgress::
	msgbox MindaroCity_Flat2_2F_Text_QuestInProgress, MSGBOX_DEFAULT
	release
	end

MindaroCity_Flat2_2F_Text_QuestInProgress:
	.string "A RELIC CROWN.\p"
	.string "I'd very much like to have\n"
	.string "one of those.\p"
	.string "And of course, the finder would\n"
	.string "be rewarded handsomely.$"

MindaroCity_Flat2_2F_EventScript_TradeCrown::
	msgbox MindaroCity_Flat2_2F_Text_TradeCrown, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, MindaroCity_Flat2_2F_EventScript_DontTradeCrown
	removeitem ITEM_RELIC_CROWN, 1
	msgbox MindaroCity_Flat2_2F_Text_HandedOverCrown, MSGBOX_DEFAULT
	delay 30
	msgbox MindaroCity_Flat2_2F_Text_HereTakeThis, MSGBOX_DEFAULT	
	giveitem ITEM_REVEAL_GLASS
	completequest QUEST_19
	release
	end

MindaroCity_Flat2_2F_Text_TradeCrown:
	.string "Oh my, that's a RELIC CROWN!\p"
	.string "Would you be willing to part with it\n"
	.string "for another kind of treasure?$"

MindaroCity_Flat2_2F_Text_HandedOverCrown:
	.string "{PLAYER} handed over the RELIC CROWN.$"

MindaroCity_Flat2_2F_Text_HereTakeThis:
	.string "My dream has finally come true.\n"
	.string "Bless you, youngster.\p"
	.string "As agreed, I'll give you this old thing\n"
	.string "I uncovered a long time ago.$"

MindaroCity_Flat2_2F_EventScript_DontTradeCrown::
	msgbox MindaroCity_Flat2_2F_Text_DontTradeCrown, MSGBOX_DEFAULT
	release
	end	

MindaroCity_Flat2_2F_Text_DontTradeCrown:
	.string "Oh, but I assure you that it's\n"
	.string "valuable in its own way.$"


MindaroCity_Flat2_2F_EventScript_ExplainRevealGlass::
	msgbox MindaroCity_Flat2_2F_Text_ExplainRevealGlass, MSGBOX_DEFAULT
	release
	end	

MindaroCity_Flat2_2F_Text_ExplainRevealGlass:
	.string "That REVEAL GLASS is said to react\n"
	.string "to the presence of certain POKéMON.\p"
	.string "I'm sure a POKéMON trainer like you\n"
	.string "will make more use of it than me.$"




