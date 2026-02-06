.set LOCALID_BOY, 1
.set LOCALID_BUGCATCHER, 4

XanthosCity_Library_2F_MapScripts::
	.byte 0

XanthosCity_Library_EventScript_OldWoman::
	msgbox XanthosCity_Library_Text_Knowledge, MSGBOX_NPC
	end

XanthosCity_Library_Text_Knowledge:
	.string "Knowledge is power.\p"
	.string "And with great power comes\n"
	.string "great responsibility.\p"
	.string "How will you use your knowledge?$"

XanthosCity_Library_EventScript_Librarian2::
	lock
	faceplayer
	msgbox XanthosCity_Library_Text_PokemonMyths, MSGBOX_NPC
	release
	end

XanthosCity_Library_Text_PokemonMyths:
	.string "This section contains all kinds of\n"
	.string "books about POKéMON legends and myths.\p"
	.string "But no one seems to be interested in\n"
	.string "these anymore...$"



XanthosCity_Library_EventScript_Schoolgirl::
	msgbox XanthosCity_Library_Text_NumberOfBerries, MSGBOX_NPC
	end

XanthosCity_Library_Text_NumberOfBerries:
	.string "According to this encyclopedia, there\n"
	.string "are 70 different kinds of BERRIES.\p"
	.string "That's funny. I thought I read somewhere\n"
	.string "else that there were only 43 kinds...$"



XanthosCity_Library_EventScript_CancelStatusExplainer::
	msgbox XanthosCity_Library_Text_QuizMeAnytime, MSGBOX_NPC
	applymovement LOCALID_BOY, Common_Movement_FaceLeft
	waitmovement 0
	releaseall
	end

XanthosCity_Library_EventScript_CancelWeatherExplainer::
	msgbox XanthosCity_Library_Text_QuizMeAnytime, MSGBOX_NPC
	applymovement LOCALID_BUGCATCHER, Common_Movement_FaceRight
	waitmovement 0
	releaseall
	end

XanthosCity_Library_Text_QuizMeAnytime:
	.string "Feel free to quiz me anytime!$"





XanthosCity_Library_EventScript_WeatherExplainer::
	lockall
	faceplayer
XanthosCity_Library_EventScript_BookOnWeather::
	message XanthosCity_Library_Text_BookOnWeather
	waitmessage
	scrollingmultichoice 5, 2, 0, 6, TRUE
	switch VAR_RESULT
	case 0, XanthosCity_Library_EventScript_ExplainFullMoon
	case 1, XanthosCity_Library_EventScript_ExplainHail
	case 2, XanthosCity_Library_EventScript_ExplainRainDance
	case 3, XanthosCity_Library_EventScript_ExplainSandstorm
	case 4, XanthosCity_Library_EventScript_ExplainSmaze
	case 5, XanthosCity_Library_EventScript_ExplainSunnyDay
	case 6, XanthosCity_Library_EventScript_CancelWeatherExplainer
	case MULTI_B_PRESSED, XanthosCity_Library_EventScript_CancelWeatherExplainer
	end

XanthosCity_Library_Text_BookOnWeather:
	.string "I'm reading a book about weather\n"
	.string "effects in POKéMON battles.\p"
	.string "What do you want to know about?$"


XanthosCity_Library_EventScript_ExplainSunnyDay::
	msgbox XanthosCity_Library_Text_ExplainSunnyDay, MSGBOX_DEFAULT
	@goto XanthosCity_Library_EventScript_BookOnWeather
	applymovement LOCALID_BOY, Common_Movement_FaceLeft
	waitmovement 0
	releaseall
	end

XanthosCity_Library_EventScript_ExplainRainDance::
	msgbox XanthosCity_Library_Text_ExplainRainDance, MSGBOX_DEFAULT
	@goto XanthosCity_Library_EventScript_BookOnWeather
	applymovement LOCALID_BOY, Common_Movement_FaceLeft
	waitmovement 0
	releaseall
	end

XanthosCity_Library_EventScript_ExplainFullMoon::
	msgbox XanthosCity_Library_Text_ExplainFullMoon, MSGBOX_DEFAULT
	@goto XanthosCity_Library_EventScript_BookOnWeather
	applymovement LOCALID_BOY, Common_Movement_FaceLeft
	waitmovement 0
	releaseall
	end

XanthosCity_Library_EventScript_ExplainHail::
	msgbox XanthosCity_Library_Text_ExplainHail, MSGBOX_DEFAULT
	@goto XanthosCity_Library_EventScript_BookOnWeather
	applymovement LOCALID_BOY, Common_Movement_FaceLeft
	waitmovement 0
	releaseall
	end

XanthosCity_Library_EventScript_ExplainSmaze::
	msgbox XanthosCity_Library_Text_ExplainSmaze, MSGBOX_DEFAULT
	@goto XanthosCity_Library_EventScript_BookOnWeather
	applymovement LOCALID_BOY, Common_Movement_FaceLeft
	waitmovement 0
	releaseall
	end

XanthosCity_Library_EventScript_ExplainSandstorm::
	msgbox XanthosCity_Library_Text_ExplainSandstorm, MSGBOX_DEFAULT
	@goto XanthosCity_Library_EventScript_BookOnWeather
	applymovement LOCALID_BOY, Common_Movement_FaceLeft
	waitmovement 0
	releaseall
	end
	


XanthosCity_Library_Text_ExplainSunnyDay:
	.string "SUNNY DAY increases the power of\n"
	.string "FIRE type moves.\p"
	.string "And it reduces the power of WATER\n"
	.string "type moves.\p"
	.string "In addition, both SOLARBEAM and\n"
	.string "MOONBLAST will fire in one turn.\p"
	.string "And THUNDER and HURRICANE have\n"
	.string "reduced accuracy,\l"
	.string "but UV BURST will never miss.$"

XanthosCity_Library_Text_ExplainRainDance:
	.string "RAIN DANCE increases the power of\n"
	.string "WATER type moves.\p"
	.string "And it reduces the power of FIRE\n"
	.string "type moves.\p"
	.string "In addition, both SOLARBEAM and\n"
	.string "MOONBLAST will deal less damage.\p"
	.string "UV BURST has reduced accuracy, but\n"
	.string "THUNDER and HURRICANE will never miss.$"

XanthosCity_Library_Text_ExplainSandstorm:
	.string "SANDSTORM increases the Special\n"
	.string "Defense of all ROCK type POKéMON.\p"
	.string "It damages any POKéMON that aren't\n"
	.string "GROUND, ROCK, or STEEL type.$"

XanthosCity_Library_Text_ExplainHail:
	.string "HAIL increases the Defense of\n"
	.string "all ICE type POKéMON.\p"
	.string "And it damages any POKéMON\n"
	.string "that aren't ICE type.$"

XanthosCity_Library_Text_ExplainSmaze:
	.string "SMAZE restores the HP of all\n"
	.string "POISON type POKéMON.\p"
	.string "And it damages any POKéMON\n"
	.string "that aren't POISON type.$"

XanthosCity_Library_Text_ExplainFullMoon:
	.string "FULL MOON restores the HP of all\n"
	.string "DARK and FAIRY type POKéMON.\p"
	.string "In addition, both SOLARBEAM and\n"
	.string "MOONBLAST will fire in one turn.$"






XanthosCity_Library_EventScript_StatusExplainer::
	lockall
	faceplayer
XanthosCity_Library_EventScript_BookOnStatus::
	message XanthosCity_Library_Text_BookOnStatus
	waitmessage
	scrollingmultichoice 4, 2, 0, 6, TRUE
	switch VAR_RESULT
	case 0, XanthosCity_Library_EventScript_ExplainBRN
	case 1, XanthosCity_Library_EventScript_ExplainDAZ
	case 2, XanthosCity_Library_EventScript_ExplainEXH
	case 3, XanthosCity_Library_EventScript_ExplainFER
	case 4, XanthosCity_Library_EventScript_ExplainFRZ
	case 5, XanthosCity_Library_EventScript_ExplainINF
	case 6, XanthosCity_Library_EventScript_ExplainPAR
	case 7, XanthosCity_Library_EventScript_ExplainPSN
	case 8, XanthosCity_Library_EventScript_ExplainSLP
	case 9, XanthosCity_Library_EventScript_CancelStatusExplainer
	case MULTI_B_PRESSED, XanthosCity_Library_EventScript_CancelStatusExplainer
	end

XanthosCity_Library_Text_BookOnStatus:
	.string "I'm reading a book on POKéMON battle\n"
	.string "status conditions.\p"
	.string "What do you want to know about?$"


XanthosCity_Library_EventScript_ExplainBRN::
	msgbox XanthosCity_Library_Text_ExplainBRN, MSGBOX_DEFAULT
	@goto XanthosCity_Library_EventScript_BookOnStatus
	applymovement LOCALID_BUGCATCHER, Common_Movement_FaceRight
	waitmovement 0
	releaseall
	end

XanthosCity_Library_EventScript_ExplainDAZ::
	msgbox XanthosCity_Library_Text_ExplainDAZ, MSGBOX_DEFAULT
	@goto XanthosCity_Library_EventScript_BookOnStatus
	applymovement LOCALID_BUGCATCHER, Common_Movement_FaceRight
	waitmovement 0
	releaseall
	end

XanthosCity_Library_EventScript_ExplainEXH::
	msgbox XanthosCity_Library_Text_ExplainEXH, MSGBOX_DEFAULT
	@goto XanthosCity_Library_EventScript_BookOnStatus
	applymovement LOCALID_BUGCATCHER, Common_Movement_FaceRight
	waitmovement 0
	releaseall
	end

XanthosCity_Library_EventScript_ExplainFER::
	msgbox XanthosCity_Library_Text_ExplainFER, MSGBOX_DEFAULT
	@goto XanthosCity_Library_EventScript_BookOnStatus
	applymovement LOCALID_BUGCATCHER, Common_Movement_FaceRight
	waitmovement 0
	releaseall
	end

XanthosCity_Library_EventScript_ExplainFRZ::
	msgbox XanthosCity_Library_Text_ExplainFRZ, MSGBOX_DEFAULT
	@goto XanthosCity_Library_EventScript_BookOnStatus
	applymovement LOCALID_BUGCATCHER, Common_Movement_FaceRight
	waitmovement 0
	releaseall
	end

XanthosCity_Library_EventScript_ExplainINF::
	msgbox XanthosCity_Library_Text_ExplainINF, MSGBOX_DEFAULT
	@goto XanthosCity_Library_EventScript_BookOnStatus
	applymovement LOCALID_BUGCATCHER, Common_Movement_FaceRight
	waitmovement 0
	releaseall
	end

XanthosCity_Library_EventScript_ExplainPAR::
	msgbox XanthosCity_Library_Text_ExplainPAR, MSGBOX_DEFAULT
	@goto XanthosCity_Library_EventScript_BookOnStatus
	applymovement LOCALID_BUGCATCHER, Common_Movement_FaceRight
	waitmovement 0
	releaseall
	end

XanthosCity_Library_EventScript_ExplainPSN::
	msgbox XanthosCity_Library_Text_ExplainPSN, MSGBOX_DEFAULT
	@goto XanthosCity_Library_EventScript_BookOnStatus
	applymovement LOCALID_BUGCATCHER, Common_Movement_FaceRight
	waitmovement 0
	releaseall
	end

XanthosCity_Library_EventScript_ExplainSLP::
	msgbox XanthosCity_Library_Text_ExplainSLP, MSGBOX_DEFAULT
	@goto XanthosCity_Library_EventScript_BookOnStatus
	applymovement LOCALID_BUGCATCHER, Common_Movement_FaceRight
	waitmovement 0
	releaseall
	end







XanthosCity_Library_Text_ExplainBRN:
	.string "A burned POKéMON will have its Attack\n"
	.string "reduced.\p"
	.string "It will also take damage at the end of\n"
	.string "each turn.$"

XanthosCity_Library_Text_ExplainDAZ:
	.string "A dazed POKéMON will not respond\n"
	.string "to commands.\p"
	.string "It will instead act according\n"
	.string "to its nature.$"

XanthosCity_Library_Text_ExplainEXH:
	.string "An exhausted POKéMON will use up\n"
	.string "twice as much PP in battle.\p"
	.string "It will also have its Speed reduced.$"

XanthosCity_Library_Text_ExplainFER:
	.string "An afraid POKéMON will have its Special\n"
	.string "Attack reduced.\p"
	.string "It may also tense up in fear, and be\n"
	.string "unable to move.$"

XanthosCity_Library_Text_ExplainFRZ:
	.string "A frozen POKéMON will be unable to act\n"
	.string "at all, unless it uses or is hit\l"
	.string "by a FIRE type move.$"

XanthosCity_Library_Text_ExplainINF:
	.string "An infected POKéMON cannot recover HP\n"
	.string "on its own.\p"
	.string "It will also hurt itself each time\n"
	.string "it tries to attack.$"

XanthosCity_Library_Text_ExplainPAR:
	.string "A paralyzed POKéMON will have its Speed\n"
	.string "drastically reduced.\p"
	.string "It may also become fully paralyzed, and\n"
	.string "be unable to move.$"

XanthosCity_Library_Text_ExplainPSN:
	.string "A poisoned POKéMON will take damage at\n"
	.string "the end of each turn.\p"
	.string "Badly poisoned POKéMON will take\n"
	.string "progressively more damage.$"

XanthosCity_Library_Text_ExplainSLP:
	.string "An asleep POKéMON will be unable to act\n"
	.string "normally until it wakes up.$"

