XanthosCity_Library_1F_MapScripts::
	.byte 0


XanthosCity_Library_EventScript_Chalkboard1::
	msgbox XanthosCity_Library_Text_EchoTypePokemon, MSGBOX_SIGN
	end

XanthosCity_Library_EventScript_Chalkboard2::
	msgbox XanthosCity_Library_Text_EchoTypeMoves, MSGBOX_SIGN
	end

XanthosCity_Library_Text_EchoTypePokemon:
	.string "NOTES ON ECHO TYPE POKéMON\p"
	.string "STRONG AGAINST: FLYING, GHOST, FAIRY\p"
	.string "WEAK AGAINST: PSYCHIC, ICE\p"
	.string "NO EFFECT: ECHO$"

XanthosCity_Library_Text_EchoTypeMoves:
	.string "NOTES ON ECHO TYPE MOVES\p"
	.string "STRONG AGAINST: GHOST, WATER, FAIRY\p"
	.string "WEAK AGAINST: GRASS, PSYCHIC, ICE\p"
	.string "NO EFFECT: ECHO$"




XanthosCity_Library_EventScript_Pokemon::
	lock
	faceplayer
	playmoncry SPECIES_DRIFLOON, CRY_MODE_NORMAL
	msgbox XanthosCity_Library_Text_Pokemon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

XanthosCity_Library_Text_Pokemon:
	.string "DRIFLOON: Wuuwooowawawawiip$"



XanthosCity_Library_EventScript_Librarian::
	lock
	faceplayer
	msgbox XanthosCity_Library_Text_Welcome, MSGBOX_NPC
	release
	end

XanthosCity_Library_Text_Welcome:
	.string "Welcome to XANTHOS CITY\n"
	.string "PUBLIC LIBRARY.\p"
	.string "Please have a look at our large\n"
	.string "collection of books and other media.$"




XanthosCity_Library_EventScript_CoolTrainer::
	msgbox XanthosCity_Library_Text_GreatBooks, MSGBOX_NPC
	end

XanthosCity_Library_Text_GreatBooks:
	.string "The books here are great!\p"
	.string "Finally, I can learn everything there is\n"
	.string "to know about POKéMON battles.$"






XanthosCity_Library_EventScript_Schoolboy::
	msgbox XanthosCity_Library_Text_SoManyItems, MSGBOX_NPC
	end

XanthosCity_Library_Text_SoManyItems:
	.string "Gah! There are so many kinds of items.\n"
	.string "How can anyone memorize all of these?$"






XanthosCity_Library_EventScript_Lass::
	msgbox XanthosCity_Library_Text_Studying, MSGBOX_NPC
	end

XanthosCity_Library_Text_Studying:
	.string "We're studying for a test this week.\p"
	.string "You can look at the notes we\n"
	.string "made on the board over there.$"


XanthosCity_Library_EventScript_Youngster::
	msgbox XanthosCity_Library_Text_ElectricWeakToRock, MSGBOX_NPC
	end

XanthosCity_Library_Text_ElectricWeakToRock:
	.string "Let's see. Does ROCK resist ELECTRIC?\p"
	.string "I keep forgetting.$"





XanthosCity_Library_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, XanthosCity_Library_EventScript_ExplainQuickClaw
	message XanthosCity_Library_Text_PopQuiz1
	waitmessage
	scrollingmultichoice 6, 2, 0, 4, TRUE
	switch VAR_RESULT
	case 0, XanthosCity_Library_EventScript_QuizWrong
	case 1, XanthosCity_Library_EventScript_QuizWrong
	case 2, XanthosCity_Library_EventScript_PopQuiz2
	case 3, XanthosCity_Library_EventScript_QuizWrong
	end

XanthosCity_Library_EventScript_PopQuiz2::
	msgbox XanthosCity_Library_Text_Right, MSGBOX_DEFAULT
	message XanthosCity_Library_Text_PopQuiz2
	waitmessage
	scrollingmultichoice 7, 2, 0, 4, TRUE
	switch VAR_RESULT
	case 0, XanthosCity_Library_EventScript_QuizWrong
	case 1, XanthosCity_Library_EventScript_QuizWrong
	case 2, XanthosCity_Library_EventScript_PopQuiz3
	case 3, XanthosCity_Library_EventScript_QuizWrong
	end

XanthosCity_Library_EventScript_PopQuiz3::
	msgbox XanthosCity_Library_Text_Right, MSGBOX_DEFAULT
	message XanthosCity_Library_Text_PopQuiz3
	waitmessage
	scrollingmultichoice 8, 2, 0, 4, TRUE
	switch VAR_RESULT
	case 0, XanthosCity_Library_EventScript_QuizWrong
	case 1, XanthosCity_Library_EventScript_QuizWrong
	case 2, XanthosCity_Library_EventScript_QuizWrong
	case 3, XanthosCity_Library_EventScript_PopQuiz4
	end

XanthosCity_Library_EventScript_PopQuiz4::
	msgbox XanthosCity_Library_Text_Right, MSGBOX_DEFAULT
	message XanthosCity_Library_Text_PopQuiz4
	waitmessage
	scrollingmultichoice 9, 2, 0, 4, TRUE
	switch VAR_RESULT
	case 0, XanthosCity_Library_EventScript_QuizWrong
	case 1, XanthosCity_Library_EventScript_PopQuiz5
	case 2, XanthosCity_Library_EventScript_QuizWrong
	case 3, XanthosCity_Library_EventScript_QuizWrong
	end

XanthosCity_Library_EventScript_PopQuiz5::
	msgbox XanthosCity_Library_Text_Right, MSGBOX_DEFAULT
	message XanthosCity_Library_Text_PopQuiz5
	waitmessage
	scrollingmultichoice 10, 2, 0, 4, TRUE
	switch VAR_RESULT
	case 0, XanthosCity_Library_EventScript_QuizWrong
	case 1, XanthosCity_Library_EventScript_QuizWrong
	case 2, XanthosCity_Library_EventScript_QuizWrong
	case 3, XanthosCity_Library_EventScript_QuizPassed
	end





XanthosCity_Library_EventScript_QuizPassed::
	msgbox XanthosCity_Library_Text_QuizPassed, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	setflag FLAG_RECEIVED_QUICK_CLAW
	goto XanthosCity_Library_EventScript_ExplainQuickClaw
	end

XanthosCity_Library_Text_QuizPassed:
	.string "You're sharp! You won the\n"
	.string "grand prize!\p"
	.string "Here, take this with you!$"


XanthosCity_Library_EventScript_QuizWrong::
	msgbox XanthosCity_Library_Text_Wrong, MSGBOX_NPC
	closemessage
	release
	end

XanthosCity_Library_Text_Wrong:
	.string "Aaaannnt! Wrong!\n"
	.string "Better luck next time.$"

XanthosCity_Library_Text_Right:
	.string "Correct! Moving onto the\n"
	.string "next round.$"




XanthosCity_Library_Text_PopQuiz1:
	.string "Pop quiz!\p"
	.string "Which of these types is weak to ECHO?$"

XanthosCity_Library_Text_PopQuiz2:
	.string "Question number 2!\p"
	.string "Which of these types does not have\n"
	.string "a weakness to PSYCHIC?$"

XanthosCity_Library_Text_PopQuiz3:
	.string "Question number 3!\p"
	.string "Which of these types does\n"
	.string "ROCK resist?$"

XanthosCity_Library_Text_PopQuiz4:
	.string "Question number 4!\p"
	.string "Which of these types resists STEEL?$"

XanthosCity_Library_Text_PopQuiz5:
	.string "And the final question!\p"
	.string "Which of these types has no immunity?$"



XanthosCity_Library_EventScript_ExplainQuickClaw::
	msgbox XanthosCity_Library_Text_ExplainQuickClaw, MSGBOX_DEFAULT
	closemessage
	release
	end

XanthosCity_Library_Text_ExplainQuickClaw:
	.string "A POKéMON holding that QUICK CLAW\n"
	.string "has a chance to go first each turn.\p"
	.string "Use it to outspeed your opponent\n"
	.string "in critical moments.$"


