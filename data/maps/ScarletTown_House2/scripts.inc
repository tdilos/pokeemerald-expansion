ScarletTown_House2_MapScripts::
	.byte 0

ScarletTown_EventScript_RedShardTutor::
	lock
	faceplayer
	msgbox ScarletTown_Text_ImAMoveTutor, MSGBOX_DEFAULT
	goto ScarletTown_EventScript_ChooseRedTutorMove
	end

ScarletTown_EventScript_ChooseRedTutorMove::
	message ScarletTown_Text_TeachWhichMove
	waitmessage
	scrollingmultichoice 1, 2, 0, 6, TRUE
	switch VAR_RESULT
	case 0, ScarletTown_EventScript_Covet
	case 1, ScarletTown_EventScript_FuryCutter
	case 2, ScarletTown_EventScript_LowKick
	case 3, ScarletTown_EventScript_Counter
	case 4, ScarletTown_EventScript_KnockOff
	case 5, ScarletTown_EventScript_Retaliate
	case 6, ScarletTown_EventScript_SecretPower
	case 7, ScarletTown_EventScript_Bounce
	case 8, ScarletTown_EventScript_DrainPunch
	case 9, ScarletTown_EventScript_IronHead
	case 10, ScarletTown_EventScript_MegaPunch
	case 11, ScarletTown_EventScript_ZenHeadbutt
	case 12, ScarletTown_EventScript_FlipTurn
	case 13, ScarletTown_EventScript_GyroBall
	case 14, ScarletTown_EventScript_IronTail
	case 15, ScarletTown_EventScript_WildFrenzy
	case 16, ScarletTown_EventScript_FirePunch
	case 17, ScarletTown_EventScript_IcePunch
	case 18, ScarletTown_EventScript_ThunderPunch
	case 19, ScarletTown_EventScript_MegaKick
	case 20, ScarletTown_EventScript_Superpower
	case 21, ScarletTown_EventScript_BodyPress
	case 22, ScarletTown_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, ScarletTown_EventScript_ExitTutorMoveSelect
	end

ScarletTown_EventScript_Covet::
	setvar VAR_0x8008, 2
	setvar VAR_0x8005, MOVE_COVET
	goto ScarletTown_EventScript_ConfirmMoveSelection
	end

ScarletTown_EventScript_FuryCutter::
	setvar VAR_0x8008, 2
	setvar VAR_0x8005, MOVE_FURY_CUTTER
	goto ScarletTown_EventScript_ConfirmMoveSelection
	end

ScarletTown_EventScript_LowKick::
	setvar VAR_0x8008, 2
	setvar VAR_0x8005, MOVE_LOW_KICK
	goto ScarletTown_EventScript_ConfirmMoveSelection
	end

ScarletTown_EventScript_Counter::
	setvar VAR_0x8008, 4
	setvar VAR_0x8005, MOVE_COUNTER
	goto ScarletTown_EventScript_ConfirmMoveSelection
	end

ScarletTown_EventScript_KnockOff::
	setvar VAR_0x8008, 4
	setvar VAR_0x8005, MOVE_KNOCK_OFF
	goto ScarletTown_EventScript_ConfirmMoveSelection
	end

ScarletTown_EventScript_Retaliate::
	setvar VAR_0x8008, 4
	setvar VAR_0x8005, MOVE_RETALIATE
	goto ScarletTown_EventScript_ConfirmMoveSelection
	end

ScarletTown_EventScript_SecretPower::
	setvar VAR_0x8008, 4
	setvar VAR_0x8005, MOVE_SECRET_POWER
	goto ScarletTown_EventScript_ConfirmMoveSelection
	end

ScarletTown_EventScript_Bounce::
	setvar VAR_0x8008, 6
	setvar VAR_0x8005, MOVE_BOUNCE
	goto ScarletTown_EventScript_ConfirmMoveSelection
	end

ScarletTown_EventScript_DrainPunch::
	setvar VAR_0x8008, 6
	setvar VAR_0x8005, MOVE_DRAIN_PUNCH
	goto ScarletTown_EventScript_ConfirmMoveSelection
	end

ScarletTown_EventScript_IronHead::
	setvar VAR_0x8008, 6
	setvar VAR_0x8005, MOVE_IRON_HEAD
	goto ScarletTown_EventScript_ConfirmMoveSelection
	end

ScarletTown_EventScript_MegaPunch::
	setvar VAR_0x8008, 6
	setvar VAR_0x8005, MOVE_MEGA_PUNCH
	goto ScarletTown_EventScript_ConfirmMoveSelection
	end

ScarletTown_EventScript_ZenHeadbutt::
	setvar VAR_0x8008, 6
	setvar VAR_0x8005, MOVE_ZEN_HEADBUTT
	goto ScarletTown_EventScript_ConfirmMoveSelection
	end

ScarletTown_EventScript_FlipTurn::
	setvar VAR_0x8008, 8
	setvar VAR_0x8005, MOVE_FLIP_TURN
	goto ScarletTown_EventScript_ConfirmMoveSelection
	end

ScarletTown_EventScript_GyroBall::
	setvar VAR_0x8008, 8
	setvar VAR_0x8005, MOVE_GYRO_BALL
	goto ScarletTown_EventScript_ConfirmMoveSelection
	end

ScarletTown_EventScript_IronTail::
	setvar VAR_0x8008, 8
	setvar VAR_0x8005, MOVE_IRON_TAIL
	goto ScarletTown_EventScript_ConfirmMoveSelection
	end

ScarletTown_EventScript_WildFrenzy::
	setvar VAR_0x8008, 8
	setvar VAR_0x8005, MOVE_WILD_FRENZY
	goto ScarletTown_EventScript_ConfirmMoveSelection
	end

ScarletTown_EventScript_FirePunch::
	setvar VAR_0x8008, 10
	setvar VAR_0x8005, MOVE_FIRE_PUNCH
	goto ScarletTown_EventScript_ConfirmMoveSelection
	end

ScarletTown_EventScript_IcePunch::
	setvar VAR_0x8008, 10
	setvar VAR_0x8005, MOVE_ICE_PUNCH
	goto ScarletTown_EventScript_ConfirmMoveSelection
	end

ScarletTown_EventScript_ThunderPunch::
	setvar VAR_0x8008, 10
	setvar VAR_0x8005, MOVE_THUNDER_PUNCH
	goto ScarletTown_EventScript_ConfirmMoveSelection
	end

ScarletTown_EventScript_MegaKick::
	setvar VAR_0x8008, 12
	setvar VAR_0x8005, MOVE_MEGA_KICK
	goto ScarletTown_EventScript_ConfirmMoveSelection
	end

ScarletTown_EventScript_Superpower::
	setvar VAR_0x8008, 12
	setvar VAR_0x8005, MOVE_SUPERPOWER
	goto ScarletTown_EventScript_ConfirmMoveSelection
	end

ScarletTown_EventScript_BodyPress::
	setvar VAR_0x8008, 14
	setvar VAR_0x8005, MOVE_BODY_PRESS
	goto ScarletTown_EventScript_ConfirmMoveSelection
	end

ScarletTown_EventScript_ExitTutorMoveSelect::
	msgbox ScarletTown_Text_ComeBack, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8005 is the move number
@ VAR_0x8008 is the price
ScarletTown_EventScript_ConfirmMoveSelection::
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	msgbox ScarletTown_Text_MoveWillBeXRedShards, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ScarletTown_EventScript_ChooseRedTutorMove
	checkitem ITEM_RED_SHARD, VAR_0x8008
	goto_if_eq VAR_RESULT, TRUE, ScarletTown_EventScript_TeachTutorMove
	msgbox ScarletTown_Text_HaventGotEnoughRedShards, MSGBOX_DEFAULT
	goto ScarletTown_EventScript_ChooseRedTutorMove
	end

ScarletTown_EventScript_TeachTutorMove::
	msgbox ScarletTown_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, FALSE, ScarletTown_EventScript_CancelChooseMon
	msgbox ScarletTown_Text_HandedOverRedShards, MSGBOX_DEFAULT
	removeitem ITEM_RED_SHARD, VAR_0x8008
	msgbox ScarletTown_Text_ComeBack, MSGBOX_DEFAULT
	release
	end

ScarletTown_EventScript_CancelChooseMon::
	msgbox ScarletTown_Text_ComeBack, MSGBOX_DEFAULT
	release
	end

ScarletTown_Text_ImAMoveTutor:
	.string "Do you want your POKéMON to be\n"
	.string "as tough as nails?\p"
	.string "Well, you've come to the right place.\n"
	.string "I know all the toughest moves.\p"
	.string "I'll teach them to POKéMON, but I'll\n"
	.string "only do it in exchange for RED SHARDS.\p"
	.string "So how about it?$"

ScarletTown_Text_TeachWhichMove:
	.string "Which move should I teach?$"

ScarletTown_Text_HaventGotEnoughRedShards:
	.string "You don't have enough RED SHARDS!$"

ScarletTown_Text_MoveWillBeXRedShards:
	.string "Great, that'll be {STR_VAR_2} RED SHARDS.$"

ScarletTown_Text_TeachMoveToWhichMon:
	.string "Which POKéMON should I teach?$"

ScarletTown_Text_HandedOverRedShards:
	.string "{PLAYER} handed over the\n"
	.string "RED SHARDS in exchange.$"

ScarletTown_Text_ComeBack:
	.string "Come back if you want me to toughen\n"
	.string "up your POKéMON some more, alright?$"



ScarletTown_House2_EventScript_Girl::
	msgbox ScarletTown_House2_Text_WhyDoWeFight, MSGBOX_NPC
	end

ScarletTown_House2_Text_WhyDoWeFight:
	.string "Why do we fight each other?\p"
	.string "Some people think fighting will only\n"
	.string "cause problems.\p"
	.string "But bottling up your feelings can\n"
	.string "cause even worse problems.\p"
	.string "Sometimes fighting is the best way\n"
	.string "to understand each other.$"

