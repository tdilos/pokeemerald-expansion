ResedaTown_House2_MapScripts::
	.byte 0

ResedaTown_EventScript_GreenShardTutor::
	lock
	faceplayer
	msgbox ResedaTown_Text_ImAMoveTutor, MSGBOX_DEFAULT
	goto ResedaTown_EventScript_ChooseGreenTutorMove
	end

ResedaTown_EventScript_ChooseGreenTutorMove::
	message ResedaTown_Text_TeachWhichMove
	waitmessage
	scrollingmultichoice 0, 2, 0, 6, TRUE
	switch VAR_RESULT
	case 0, ResedaTown_EventScript_HelpingHand
	case 1, ResedaTown_EventScript_SonarWave
	case 2, ResedaTown_EventScript_Snore
	case 3, ResedaTown_EventScript_Charm
	case 4, ResedaTown_EventScript_Defog
	case 5, ResedaTown_EventScript_Endure
	case 6, ResedaTown_EventScript_GastroAcid
	case 7, ResedaTown_EventScript_DreamEater
	case 8, ResedaTown_EventScript_MagnetRise
	case 9, ResedaTown_EventScript_Petrify
	case 10, ResedaTown_EventScript_Recycle
	case 11, ResedaTown_EventScript_WorrySeed
	case 12, ResedaTown_EventScript_MagicRoom
	case 13, ResedaTown_EventScript_PainSplit
	case 14, ResedaTown_EventScript_SeismicToss
	case 15, ResedaTown_EventScript_WonderRoom
	case 16, ResedaTown_EventScript_Fling
	case 17, ResedaTown_EventScript_Gravity
	case 18, ResedaTown_EventScript_Tailwind
	case 19, ResedaTown_EventScript_LastResort
	case 20, ResedaTown_EventScript_SleepTalk
	case 21, ResedaTown_EventScript_FoulPlay
	case 22, ResedaTown_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, ResedaTown_EventScript_ExitTutorMoveSelect
	end

ResedaTown_EventScript_HelpingHand::
	setvar VAR_0x8008, 2
	setvar VAR_0x8005, MOVE_HELPING_HAND
	goto ResedaTown_EventScript_ConfirmMoveSelection
	end

ResedaTown_EventScript_SonarWave::
	setvar VAR_0x8008, 2
	setvar VAR_0x8005, MOVE_SONAR_WAVE
	goto ResedaTown_EventScript_ConfirmMoveSelection
	end

ResedaTown_EventScript_Snore::
	setvar VAR_0x8008, 2
	setvar VAR_0x8005, MOVE_SNORE
	goto ResedaTown_EventScript_ConfirmMoveSelection
	end

ResedaTown_EventScript_Charm::
	setvar VAR_0x8008, 4
	setvar VAR_0x8005, MOVE_CHARM
	goto ResedaTown_EventScript_ConfirmMoveSelection
	end

ResedaTown_EventScript_Defog::
	setvar VAR_0x8008, 4
	setvar VAR_0x8005, MOVE_DEFOG
	goto ResedaTown_EventScript_ConfirmMoveSelection
	end

ResedaTown_EventScript_Endure::
	setvar VAR_0x8008, 4
	setvar VAR_0x8005, MOVE_ENDURE
	goto ResedaTown_EventScript_ConfirmMoveSelection
	end

ResedaTown_EventScript_GastroAcid::
	setvar VAR_0x8008, 4
	setvar VAR_0x8005, MOVE_GASTRO_ACID
	goto ResedaTown_EventScript_ConfirmMoveSelection
	end

ResedaTown_EventScript_DreamEater::
	setvar VAR_0x8008, 6
	setvar VAR_0x8005, MOVE_DREAM_EATER
	goto ResedaTown_EventScript_ConfirmMoveSelection
	end

ResedaTown_EventScript_MagnetRise::
	setvar VAR_0x8008, 6
	setvar VAR_0x8005, MOVE_MAGNET_RISE
	goto ResedaTown_EventScript_ConfirmMoveSelection
	end

ResedaTown_EventScript_Petrify::
	setvar VAR_0x8008, 6
	setvar VAR_0x8005, MOVE_PETRIFY
	goto ResedaTown_EventScript_ConfirmMoveSelection
	end

ResedaTown_EventScript_Recycle::
	setvar VAR_0x8008, 6
	setvar VAR_0x8005, MOVE_RECYCLE
	goto ResedaTown_EventScript_ConfirmMoveSelection
	end

ResedaTown_EventScript_WorrySeed::
	setvar VAR_0x8008, 6
	setvar VAR_0x8005, MOVE_WORRY_SEED
	goto ResedaTown_EventScript_ConfirmMoveSelection
	end

ResedaTown_EventScript_MagicRoom::
	setvar VAR_0x8008, 8
	setvar VAR_0x8005, MOVE_MAGIC_ROOM
	goto ResedaTown_EventScript_ConfirmMoveSelection
	end

ResedaTown_EventScript_PainSplit::
	setvar VAR_0x8008, 8
	setvar VAR_0x8005, MOVE_PAIN_SPLIT
	goto ResedaTown_EventScript_ConfirmMoveSelection
	end

ResedaTown_EventScript_SeismicToss::
	setvar VAR_0x8008, 8
	setvar VAR_0x8005, MOVE_SEISMIC_TOSS
	goto ResedaTown_EventScript_ConfirmMoveSelection
	end

ResedaTown_EventScript_WonderRoom::
	setvar VAR_0x8008, 8
	setvar VAR_0x8005, MOVE_WONDER_ROOM
	goto ResedaTown_EventScript_ConfirmMoveSelection
	end

ResedaTown_EventScript_Fling::
	setvar VAR_0x8008, 10
	setvar VAR_0x8005, MOVE_FLING
	goto ResedaTown_EventScript_ConfirmMoveSelection
	end

ResedaTown_EventScript_Gravity::
	setvar VAR_0x8008, 10
	setvar VAR_0x8005, MOVE_GRAVITY
	goto ResedaTown_EventScript_ConfirmMoveSelection
	end

ResedaTown_EventScript_Tailwind::
	setvar VAR_0x8008, 10
	setvar VAR_0x8005, MOVE_TAILWIND
	goto ResedaTown_EventScript_ConfirmMoveSelection
	end

ResedaTown_EventScript_LastResort::
	setvar VAR_0x8008, 12
	setvar VAR_0x8005, MOVE_LAST_RESORT
	goto ResedaTown_EventScript_ConfirmMoveSelection
	end

ResedaTown_EventScript_SleepTalk::
	setvar VAR_0x8008, 12
	setvar VAR_0x8005, MOVE_SLEEP_TALK
	goto ResedaTown_EventScript_ConfirmMoveSelection
	end

ResedaTown_EventScript_FoulPlay::
	setvar VAR_0x8008, 14
	setvar VAR_0x8005, MOVE_FOUL_PLAY
	goto ResedaTown_EventScript_ConfirmMoveSelection
	end

ResedaTown_EventScript_ExitTutorMoveSelect::
	msgbox ResedaTown_Text_ComeBack, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8005 is the move number
@ VAR_0x8008 is the price
ResedaTown_EventScript_ConfirmMoveSelection::
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	msgbox ResedaTown_Text_MoveWillBeXGreenShards, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ResedaTown_EventScript_ChooseGreenTutorMove
	checkitem ITEM_GREEN_SHARD, VAR_0x8008
	goto_if_eq VAR_RESULT, TRUE, ResedaTown_EventScript_TeachTutorMove
	msgbox ResedaTown_Text_HaventGotEnoughGreenShards, MSGBOX_DEFAULT
	goto ResedaTown_EventScript_ChooseGreenTutorMove
	end

ResedaTown_EventScript_TeachTutorMove::
	msgbox ResedaTown_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, FALSE, ResedaTown_EventScript_CancelChooseMon
	msgbox ResedaTown_Text_HandedOverGreenShards, MSGBOX_DEFAULT
	removeitem ITEM_GREEN_SHARD, VAR_0x8008
	msgbox ResedaTown_Text_ComeBack, MSGBOX_DEFAULT
	release
	end

ResedaTown_EventScript_CancelChooseMon::
	msgbox ResedaTown_Text_ComeBack, MSGBOX_DEFAULT
	release
	end

ResedaTown_Text_ImAMoveTutor:
	.string "Hello, traveler.\p"
	.string "I am a humble move tutor.\p"
	.string "I teach your POKéMON moves\n"
	.string "for GREEN SHARDS.\p"
	.string "'Tis a fair trade, yea?$"

ResedaTown_Text_TeachWhichMove:
	.string "Which move should I teach?$"

ResedaTown_Text_HaventGotEnoughGreenShards:
	.string "You don't have enough GREEN SHARDS!$"

ResedaTown_Text_MoveWillBeXGreenShards:
	.string "That will be {STR_VAR_2} GREEN SHARDS, yea?$"

ResedaTown_Text_TeachMoveToWhichMon:
	.string "Which POKéMON should I teach?$"

ResedaTown_Text_HandedOverGreenShards:
	.string "{PLAYER} handed over the\n"
	.string "GREEN SHARDS in exchange.$"

ResedaTown_Text_ComeBack:
	.string "Farewell, traveler.$"
	@.string "Come back more GREEN SHARDS, yea?\n"
	@.string "GREEN SHARDS.$"



ResedaTown_House2_EventScript_Boy::
	msgbox ResedaTown_House2_Text_ThisTownIsBoring, MSGBOX_NPC
	end

ResedaTown_House2_Text_ThisTownIsBoring:
	.string "This town is so boring.\n"
	.string "I can't stand it.\p"
	.string "Once I get my own POKéMON,\n"
	.string "I'm leaving for somewhere else.$"
