MindaroCity_Flat1_3F_MapScripts::
	.byte 0

MindaroCity_Flat1_3F_EventScript_Pokemon::
	lock
	faceplayer
	playmoncry SPECIES_BELLSPROUT, CRY_MODE_NORMAL
	msgbox MindaroCity_Flat1_3F_Text_Pokemon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MindaroCity_Flat1_3F_Text_Pokemon:
	.string "BELLSPROUT: Beru beru.$"

MindaroCity_Flat1_3F_EventScript_Man::
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_17
	goto_if_eq VAR_RESULT, TRUE, MindaroCity_Flat1_3F_EventScript_TeachReturn
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_17
	goto_if_eq VAR_RESULT, TRUE, MindaroCity_Flat1_3F_EventScript_CheckFriendship
	msgbox MindaroCity_Flat1_3F_Text_LoveAndKindness, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MindaroCity_Flat1_3F_EventScript_ProveIt
	goto_if_eq VAR_RESULT, NO, MindaroCity_Flat1_3F_EventScript_MisjudgedYou
	release
	end

MindaroCity_Flat1_3F_EventScript_MisjudgedYou::
	msgbox MindaroCity_Flat1_3F_Text_MisjudgedYou, MSGBOX_DEFAULT
	release
	end

MindaroCity_Flat1_3F_EventScript_ProveIt::
	msgbox MindaroCity_Flat1_3F_Text_ProveIt, MSGBOX_DEFAULT
	@questmenu QUEST_MENU_UNLOCK_QUEST QUEST_17
	@openquestmenu
	startquest QUEST_17
	release
	end	

MindaroCity_Flat1_3F_EventScript_CheckFriendship::
	msgbox MindaroCity_Flat1_3F_Text_SeeHowMuchPokemonLikesYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case FRIENDSHIP_NONE, MindaroCity_Flat1_3F_EventScript_NotWhatImLookingFor
	case FRIENDSHIP_1_TO_49, MindaroCity_Flat1_3F_EventScript_NotWhatImLookingFor
	case FRIENDSHIP_50_TO_99, MindaroCity_Flat1_3F_EventScript_NotWhatImLookingFor
	case FRIENDSHIP_100_TO_149, MindaroCity_Flat1_3F_EventScript_NotWhatImLookingFor
	case FRIENDSHIP_150_TO_199, MindaroCity_Flat1_3F_EventScript_NotWhatImLookingFor
	case FRIENDSHIP_200_TO_254, MindaroCity_Flat1_3F_EventScript_NotWhatImLookingFor
	case FRIENDSHIP_MAX, MindaroCity_Flat1_3F_EventScript_UnlockTutor
	release
	end

MindaroCity_Flat1_3F_EventScript_NotWhatImLookingFor::
	msgbox MindaroCity_Flat1_3F_Text_NotWhatImLookingFor, MSGBOX_DEFAULT
	release
	end

MindaroCity_Flat1_3F_EventScript_UnlockTutor::
	msgbox MindaroCity_Flat1_3F_Text_WellDone, MSGBOX_DEFAULT
	@questmenu QUEST_MENU_COMPLETE_QUEST QUEST_17
	@openquestmenu
	completequest QUEST_17
	@goto MindaroCity_Flat1_3F_EventScript_TeachReturn
	release
	end


MindaroCity_Flat1_3F_EventScript_TeachReturn::
	msgbox MindaroCity_Flat1_3F_Text_TeachReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MindaroCity_Flat1_3F_EventScript_ChooseMonForTutor
	goto_if_eq VAR_RESULT, NO, MindaroCity_Flat1_3F_EventScript_ExitTutor
	release
	end

MindaroCity_Flat1_3F_EventScript_ChooseMonForTutor::
	setvar VAR_0x8005, MOVE_RETURN
	msgbox MindaroCity_Flat1_3F_Text_TeachWhichPokemon, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, FALSE, MindaroCity_Flat1_3F_EventScript_ExitTutor
	release
	end

MindaroCity_Flat1_3F_EventScript_ExitTutor::
	@msgbox TurquoiseCity_Text_ComeBack, MSGBOX_DEFAULT
	release
	end



MindaroCity_Flat1_3F_Text_LoveAndKindness:
	.string "A good trainer treats their POKéMON\n"
	.string "with love and kindness.\p"
	.string "When POKéMON return their trainer's\n"
	.string "affection, they become stronger.\p"
	.string "You agree, yes?$"

MindaroCity_Flat1_3F_Text_ProveIt:
	.string "Indeed.\p"
	.string "Why don't you show me how much\n"
	.string "you love your POKéMON?\p"
	.string "Show me a POKéMON that loves you\n"
	.string "dearly. I'll teach it a special move.$"

MindaroCity_Flat1_3F_Text_MisjudgedYou:
	.string "Hmmm. Perhaps I misjudged you.$"

MindaroCity_Flat1_3F_Text_SeeHowMuchPokemonLikesYou:
	.string "Let me see your POKéMON.$"

MindaroCity_Flat1_3F_Text_NotWhatImLookingFor:
	.string "Hmmm. I'm afraid this isn't what\n"
	.string "I'm looking for.\p"
	.string "I need to see a POKéMON whose trust\n"
	.string "in you is unshakeable.$"

MindaroCity_Flat1_3F_Text_WellDone:
	.string "Oh, your POKéMON.\n"
	.string "It couldn't possibly love you more.\p"
	.string "Well done. As agreed, I'll offer\n"
	.string "to teach any of your POKéMON.$"

MindaroCity_Flat1_3F_Text_TeachReturn:
	.string "Would you like me to teach your POKéMON\n"
	.string "the move RETURN?$"

MindaroCity_Flat1_3F_Text_TeachWhichPokemon:
	.string "Which POKéMON should I teach?$"


