DunTown_House2_MapScripts::
	.byte 0


DunTown_EventScript_YellowShardTutor::
	lock
	faceplayer
	msgbox DunTown_Text_ImAMoveTutor, MSGBOX_DEFAULT
	goto DunTown_EventScript_ChooseYellowTutorMove
	end

DunTown_EventScript_ChooseYellowTutorMove::
	message DunTown_Text_TeachWhichMove
	waitmessage
	scrollingmultichoice 3, 2, 0, 6, TRUE
	switch VAR_RESULT
	case 0, DunTown_EventScript_BabyDollEyes
	case 1, DunTown_EventScript_HealBell
	case 2, DunTown_EventScript_Confide
	case 3, DunTown_EventScript_Crystalize
	case 4, DunTown_EventScript_IronDefense
	case 5, DunTown_EventScript_Quash
	case 6, DunTown_EventScript_Spite
	case 7, DunTown_EventScript_AuroraVeil
	case 8, DunTown_EventScript_DarknessDream
	case 9, DunTown_EventScript_Embargo
	case 10, DunTown_EventScript_SuperFang
	case 11, DunTown_EventScript_RolePlay
	case 12, DunTown_EventScript_Roost
	case 13, DunTown_EventScript_Softboiled
	case 14, DunTown_EventScript_ShoreUp
	case 15, DunTown_EventScript_Synthesis
	case 16, DunTown_EventScript_Endeavor
	case 17, DunTown_EventScript_Snatch
	case 18, DunTown_EventScript_Trick
	case 19, DunTown_EventScript_FairyDust
	case 20, DunTown_EventScript_StealthRock
	case 21, DunTown_EventScript_BatonPass
	case 22, DunTown_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, DunTown_EventScript_ExitTutorMoveSelect
	end

DunTown_EventScript_BabyDollEyes::
	setvar VAR_0x8008, 2
	setvar VAR_0x8005, MOVE_BABY_DOLL_EYES
	goto DunTown_EventScript_ConfirmMoveSelection
	end

DunTown_EventScript_HealBell::
	setvar VAR_0x8008, 2
	setvar VAR_0x8005, MOVE_HEAL_BELL
	goto DunTown_EventScript_ConfirmMoveSelection
	end

DunTown_EventScript_Confide::
	setvar VAR_0x8008, 2
	setvar VAR_0x8005, MOVE_CONFIDE
	goto DunTown_EventScript_ConfirmMoveSelection
	end

DunTown_EventScript_Crystalize::
	setvar VAR_0x8008, 4
	setvar VAR_0x8005, MOVE_CRYSTALIZE
	goto DunTown_EventScript_ConfirmMoveSelection
	end

DunTown_EventScript_IronDefense::
	setvar VAR_0x8008, 4
	setvar VAR_0x8005, MOVE_IRON_DEFENSE
	goto DunTown_EventScript_ConfirmMoveSelection
	end

DunTown_EventScript_Quash::
	setvar VAR_0x8008, 4
	setvar VAR_0x8005, MOVE_QUASH
	goto DunTown_EventScript_ConfirmMoveSelection
	end

DunTown_EventScript_Spite::
	setvar VAR_0x8008, 4
	setvar VAR_0x8005, MOVE_SPITE
	goto DunTown_EventScript_ConfirmMoveSelection
	end

DunTown_EventScript_AuroraVeil::
	setvar VAR_0x8008, 6
	setvar VAR_0x8005, MOVE_AURORA_VEIL
	goto DunTown_EventScript_ConfirmMoveSelection
	end

DunTown_EventScript_DarknessDream::
	setvar VAR_0x8008, 6
	setvar VAR_0x8005, MOVE_DARKNESS_DREAM
	goto DunTown_EventScript_ConfirmMoveSelection
	end

DunTown_EventScript_Embargo::
	setvar VAR_0x8008, 6
	setvar VAR_0x8005, MOVE_EMBARGO
	goto DunTown_EventScript_ConfirmMoveSelection
	end

DunTown_EventScript_SuperFang::
	setvar VAR_0x8008, 6
	setvar VAR_0x8005, MOVE_SUPER_FANG
	goto DunTown_EventScript_ConfirmMoveSelection
	end

DunTown_EventScript_RolePlay::
	setvar VAR_0x8008, 6
	setvar VAR_0x8005, MOVE_ROLE_PLAY
	goto DunTown_EventScript_ConfirmMoveSelection
	end

DunTown_EventScript_Roost::
	setvar VAR_0x8008, 8
	setvar VAR_0x8005, MOVE_ROOST
	goto DunTown_EventScript_ConfirmMoveSelection
	end

DunTown_EventScript_ShoreUp::
	setvar VAR_0x8008, 8
	setvar VAR_0x8005, MOVE_SHORE_UP
	goto DunTown_EventScript_ConfirmMoveSelection
	end

DunTown_EventScript_Softboiled::
	setvar VAR_0x8008, 8
	setvar VAR_0x8005, MOVE_SOFT_BOILED
	goto DunTown_EventScript_ConfirmMoveSelection
	end

DunTown_EventScript_Synthesis::
	setvar VAR_0x8008, 8
	setvar VAR_0x8005, MOVE_SYNTHESIS
	goto DunTown_EventScript_ConfirmMoveSelection
	end

DunTown_EventScript_Endeavor::
	setvar VAR_0x8008, 10
	setvar VAR_0x8005, MOVE_ENDEAVOR
	goto DunTown_EventScript_ConfirmMoveSelection
	end

DunTown_EventScript_Snatch::
	setvar VAR_0x8008, 10
	setvar VAR_0x8005, MOVE_SNATCH
	goto DunTown_EventScript_ConfirmMoveSelection
	end

DunTown_EventScript_Trick::
	setvar VAR_0x8008, 10
	setvar VAR_0x8005, MOVE_TRICK
	goto DunTown_EventScript_ConfirmMoveSelection
	end

DunTown_EventScript_FairyDust::
	setvar VAR_0x8008, 12
	setvar VAR_0x8005, MOVE_FAIRY_DUST
	goto DunTown_EventScript_ConfirmMoveSelection
	end

DunTown_EventScript_StealthRock::
	setvar VAR_0x8008, 12
	setvar VAR_0x8005, MOVE_STEALTH_ROCK
	goto DunTown_EventScript_ConfirmMoveSelection
	end

DunTown_EventScript_BatonPass::
	setvar VAR_0x8008, 14
	setvar VAR_0x8005, MOVE_BATON_PASS
	goto DunTown_EventScript_ConfirmMoveSelection
	end

DunTown_EventScript_ExitTutorMoveSelect::
	msgbox DunTown_Text_ComeBack, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8005 is the move number
@ VAR_0x8008 is the price
DunTown_EventScript_ConfirmMoveSelection::
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	msgbox DunTown_Text_MoveWillBeXYellowShards, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, DunTown_EventScript_ChooseYellowTutorMove
	checkitem ITEM_YELLOW_SHARD, VAR_0x8008
	goto_if_eq VAR_RESULT, TRUE, DunTown_EventScript_TeachTutorMove
	msgbox DunTown_Text_HaventGotEnoughYellowShards, MSGBOX_DEFAULT
	goto DunTown_EventScript_ChooseYellowTutorMove
	end

DunTown_EventScript_TeachTutorMove::
	msgbox DunTown_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, FALSE, DunTown_EventScript_CancelChooseMon
	msgbox DunTown_Text_HandedOverYellowShards, MSGBOX_DEFAULT
	removeitem ITEM_YELLOW_SHARD, VAR_0x8008
	msgbox DunTown_Text_ComeBack, MSGBOX_DEFAULT
	release
	end

DunTown_EventScript_CancelChooseMon::
	msgbox DunTown_Text_ComeBack, MSGBOX_DEFAULT
	release
	end

DunTown_Text_ImAMoveTutor:
	.string "Hoho! I'm a move tutor.\n"
	.string "I absolutely adore YELLOW SHARDS!\p"
	.string "I'll teach your POKéMON moves in exchange\n"
	.string "for all your YELLOW SHARDS.$"
	@.string "Well, have we got a deal?$"

DunTown_Text_TeachWhichMove:
	.string "Which move should I teach?$"

DunTown_Text_HaventGotEnoughYellowShards:
	.string "You don't have enough YELLOW SHARDS!$"

DunTown_Text_MoveWillBeXYellowShards:
	.string "Great, that'll be {STR_VAR_2} YELLOW SHARDS.$"

DunTown_Text_TeachMoveToWhichMon:
	.string "Which POKéMON should I teach?$"

DunTown_Text_HandedOverYellowShards:
	.string "{PLAYER} handed over the\n"
	.string "YELLOW SHARDS in exchange.$"

DunTown_Text_ComeBack:
	.string "Come back with more YELLOW\n"
	.string "SHARDS, deary.\p"
	.string "Hohohohoho!$"



DunTown_House2_EventScript_Boy::
	lock
	faceplayer
	msgbox DunTown_House2_Text_Hoarders, MSGBOX_DEFAULT
	release
	end

DunTown_House2_Text_Hoarders:
	.string "I think grandma might be one of\n"
	.string "those hoarders.\p"
	.string "She's always stocking up on those\n"
	.string "weird shard pieces.\p"
	.string "What do you even use those for?$"

