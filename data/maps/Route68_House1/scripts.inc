Route68_House1_MapScripts::
	.byte 0

Route68_House1_EventScript_ElementalHBTutor::
	lock
	faceplayer
	msgbox Route68_House1_Text_ElementalHBTutor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route68_House1_EventScript_CheckTeamFriendship
	goto_if_eq VAR_RESULT, NO, Route68_House1_EventScript_ExitTutorMoveSelect
	release
	end

Route68_House1_EventScript_CheckTeamFriendship::
	specialvar VAR_RESULT, CheckHighTeamFriendship
	goto_if_eq VAR_RESULT, TRUE, Route68_House1_EventScript_ChooseTutorMove
	msgbox Route68_House1_Text_CantTeachPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

Route68_House1_EventScript_ChooseTutorMove::
	message Route68_House1_Text_TeachWhichMove
	waitmessage
	scrollingmultichoice 12, 2, 0, 4, TRUE
	switch VAR_RESULT
	case 0, Route68_House1_EventScript_FrenzyPlant
	case 1, Route68_House1_EventScript_BlastBurn
	case 2, Route68_House1_EventScript_HydroCannon
	case 3, Route68_House1_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, Route68_House1_EventScript_ExitTutorMoveSelect
	end

Route68_House1_EventScript_FrenzyPlant::
	setvar VAR_0x8005, MOVE_FRENZY_PLANT
	goto Route68_House1_EventScript_TeachTutorMove
	end

Route68_House1_EventScript_BlastBurn::
	setvar VAR_0x8005, MOVE_BLAST_BURN
	goto Route68_House1_EventScript_TeachTutorMove
	end

Route68_House1_EventScript_HydroCannon::
	setvar VAR_0x8005, MOVE_HYDRO_CANNON
	goto Route68_House1_EventScript_TeachTutorMove
	end

Route68_House1_EventScript_TeachTutorMove::
	msgbox Route68_House1_Text_TeachWhichPokemon, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, FALSE, Route68_House1_EventScript_ChooseTutorMove
	release
	end

Route68_House1_EventScript_ExitTutorMoveSelect::
	msgbox Route68_House1_Text_ISee, MSGBOX_DEFAULT
	release
	end

Route68_House1_Text_ElementalHBTutor::
	.string "Hmmm? Another young trainer, is it?\p"
	.string "Have you also come to learn my\n"
	.string "powerful techniques?$"

Route68_House1_Text_TeachWhichMove:
	.string "Which move should I teach?$"

Route68_House1_Text_TeachWhichPokemon:
	.string "Alright, and which POKéMON wants\n"
	.string "to learn it?$"

Route68_House1_Text_CantTeachPokemon:
	.string "Hmmm, what's this? Your POKéMON\n"
	.string "still don't trust you enough.\p"
	.string "I don't impart my wisdom\n"
	.string "to just anyone, you know.\p"
	.string "Come back when your bond\n"
	.string "is stronger.$"

Route68_House1_Text_ISee:
	.string "I see. Perhaps you're not ready\n"
	.string "for it yet.$"

