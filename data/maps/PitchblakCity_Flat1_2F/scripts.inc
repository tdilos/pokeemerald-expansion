PitchblakCity_Flat1_2F_MapScripts::
	.byte 0

PitchblakCity_Flat1_2F_EventScript_Pokemon::
	lock
	faceplayer
	playmoncry SPECIES_GULPIN, CRY_MODE_NORMAL
	msgbox PitchblakCity_Flat1_2F_Text_Pokemon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

PitchblakCity_Flat1_2F_Text_Pokemon:
	.string "GULPIN: Gulp$"

PitchblakCity_Flat1_2F_EventScript_Man::
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_27
	goto_if_eq VAR_RESULT, TRUE, PitchblakCity_Flat1_2F_EventScript_TeachFrustration
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_27
	goto_if_eq VAR_RESULT, TRUE, PitchblakCity_Flat1_2F_EventScript_CheckFriendship
	msgbox PitchblakCity_Flat1_2F_Text_HateAndAnger, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PitchblakCity_Flat1_2F_EventScript_ProveIt
	goto_if_eq VAR_RESULT, NO, PitchblakCity_Flat1_2F_EventScript_MisjudgedYou
	release
	end

PitchblakCity_Flat1_2F_EventScript_MisjudgedYou::
	msgbox PitchblakCity_Flat1_2F_Text_MisjudgedYou, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Flat1_2F_EventScript_ProveIt::
	msgbox PitchblakCity_Flat1_2F_Text_ProveIt, MSGBOX_DEFAULT
	@questmenu QUEST_MENU_UNLOCK_QUEST QUEST_27
	@openquestmenu
	startquest QUEST_27
	release
	end	

PitchblakCity_Flat1_2F_EventScript_CheckFriendship::
	msgbox PitchblakCity_Flat1_2F_Text_SeeHowMuchPokemonLikesYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case FRIENDSHIP_NONE, PitchblakCity_Flat1_2F_EventScript_UnlockTutor
	case FRIENDSHIP_1_TO_49, PitchblakCity_Flat1_2F_EventScript_NotWhatImLookingFor
	case FRIENDSHIP_50_TO_99, PitchblakCity_Flat1_2F_EventScript_NotWhatImLookingFor
	case FRIENDSHIP_100_TO_149, PitchblakCity_Flat1_2F_EventScript_NotWhatImLookingFor
	case FRIENDSHIP_150_TO_199, PitchblakCity_Flat1_2F_EventScript_NotWhatImLookingFor
	case FRIENDSHIP_200_TO_254, PitchblakCity_Flat1_2F_EventScript_NotWhatImLookingFor
	case FRIENDSHIP_MAX, PitchblakCity_Flat1_2F_EventScript_NotWhatImLookingFor
	release
	end

PitchblakCity_Flat1_2F_EventScript_NotWhatImLookingFor::
	msgbox PitchblakCity_Flat1_2F_Text_NotWhatImLookingFor, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Flat1_2F_EventScript_UnlockTutor::
	msgbox PitchblakCity_Flat1_2F_Text_WellDone, MSGBOX_DEFAULT
	@questmenu QUEST_MENU_COMPLETE_QUEST QUEST_27
	@openquestmenu
	completequest QUEST_27
	@goto PitchblakCity_Flat1_2F_EventScript_TeachFrustration
	release
	end


PitchblakCity_Flat1_2F_EventScript_TeachFrustration::
	msgbox PitchblakCity_Flat1_2F_Text_TeachFrustration, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PitchblakCity_Flat1_2F_EventScript_ChooseMonForTutor
	goto_if_eq VAR_RESULT, NO, PitchblakCity_Flat1_2F_EventScript_ExitTutor
	release
	end

PitchblakCity_Flat1_2F_EventScript_ChooseMonForTutor::
	setvar VAR_0x8005, MOVE_FRUSTRATION
	msgbox PitchblakCity_Flat1_2F_Text_TeachWhichPokemon, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, FALSE, PitchblakCity_Flat1_2F_EventScript_ExitTutor
	release
	end

PitchblakCity_Flat1_2F_EventScript_ExitTutor::
	@msgbox TurquoiseCity_Text_ComeBack, MSGBOX_DEFAULT
	release
	end



PitchblakCity_Flat1_2F_Text_HateAndAnger:
	.string "Give POKéMON love and attention?\n"
	.string "Bleh! Who needs that hippy crap?\p"
	.string "Hate and anger give you focus, make\n"
	.string "you stronger!\p"
	.string "You know what I mean, right?$"

PitchblakCity_Flat1_2F_Text_ProveIt:
	.string "That's right! Now show me you mean it!\p"
	.string "If you bring me a POKéMON that's full\n"
	.string "of hate, I'll teach it a special move.$"

PitchblakCity_Flat1_2F_Text_MisjudgedYou:
	.string "Lame. You must one of those\n"
	.string "sentimental types.$"

PitchblakCity_Flat1_2F_Text_SeeHowMuchPokemonLikesYou:
	.string "Let me see your POKéMON.$"

PitchblakCity_Flat1_2F_Text_NotWhatImLookingFor:
	.string "Nope, that's not good enough.\p"
	.string "I need to see a POKéMON that's\n"
	.string "burning with anger!$"

PitchblakCity_Flat1_2F_Text_WellDone:
	.string "Woah, that's one scary looking POKéMON.\n"
	.string "Even I'm a little intimidated by it.\p"
	.string "As agreed, I'll offer to teach\n"
	.string "any of your POKéMON.$"

PitchblakCity_Flat1_2F_Text_TeachFrustration:
	.string "Would you like me to teach your POKéMON\n"
	.string "the move FRUSTRATION?$"

PitchblakCity_Flat1_2F_Text_TeachWhichPokemon:
	.string "Which POKéMON should I teach?$"
