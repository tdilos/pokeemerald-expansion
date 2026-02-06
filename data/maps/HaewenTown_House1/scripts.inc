HaewenTown_House1_MapScripts::
	.byte 0

HaewenTown_EventScript_BlueShardTutor::
	lock
	faceplayer
	msgbox HaewenTown_Text_ImAMoveTutor, MSGBOX_DEFAULT
	goto HaewenTown_EventScript_ChooseBlueTutorMove
	end

HaewenTown_EventScript_ChooseBlueTutorMove::
	message HaewenTown_Text_TeachWhichMove
	waitmessage
	scrollingmultichoice 2, 2, 0, 6, TRUE
	switch VAR_RESULT
	case 0, HaewenTown_EventScript_Incinerate
	case 1, HaewenTown_EventScript_SandTomb
	case 2, HaewenTown_EventScript_Whirlpool
	case 3, HaewenTown_EventScript_IcyWind
	case 4, HaewenTown_EventScript_StruggleBug
	case 5, HaewenTown_EventScript_Swift
	case 6, HaewenTown_EventScript_VacuumWave
	case 7, HaewenTown_EventScript_GigaDrain
	case 8, HaewenTown_EventScript_SignalBeam
	case 9, HaewenTown_EventScript_PhrenoAttack
	case 10, HaewenTown_EventScript_SomaAttack
	case 11, HaewenTown_EventScript_TriAttack
	case 12, HaewenTown_EventScript_BlueNoise
	case 13, HaewenTown_EventScript_Psychosis
	case 14, HaewenTown_EventScript_DroneWave
	case 15, HaewenTown_EventScript_VoltSwitch
	case 16, HaewenTown_EventScript_DragonPulse
	case 17, HaewenTown_EventScript_EarthPower
	case 18, HaewenTown_EventScript_Psyshock
	case 19, HaewenTown_EventScript_HeatWave
	case 20, HaewenTown_EventScript_UVBurst
	case 21, HaewenTown_EventScript_ForceOfWill
	case 22, HaewenTown_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, HaewenTown_EventScript_ExitTutorMoveSelect
	end

HaewenTown_EventScript_Incinerate::
	setvar VAR_0x8008, 2
	setvar VAR_0x8005, MOVE_INCINERATE
	goto HaewenTown_EventScript_ConfirmMoveSelection
	end

HaewenTown_EventScript_SandTomb::
	setvar VAR_0x8008, 2
	setvar VAR_0x8005, MOVE_SAND_TOMB
	goto HaewenTown_EventScript_ConfirmMoveSelection
	end

HaewenTown_EventScript_Whirlpool::
	setvar VAR_0x8008, 2
	setvar VAR_0x8005, MOVE_WHIRLPOOL
	goto HaewenTown_EventScript_ConfirmMoveSelection
	end

HaewenTown_EventScript_IcyWind::
	setvar VAR_0x8008, 4
	setvar VAR_0x8005, MOVE_ICY_WIND
	goto HaewenTown_EventScript_ConfirmMoveSelection
	end

HaewenTown_EventScript_StruggleBug::
	setvar VAR_0x8008, 4
	setvar VAR_0x8005, MOVE_STRUGGLE_BUG
	goto HaewenTown_EventScript_ConfirmMoveSelection
	end

HaewenTown_EventScript_Swift::
	setvar VAR_0x8008, 4
	setvar VAR_0x8005, MOVE_SWIFT
	goto HaewenTown_EventScript_ConfirmMoveSelection
	end

HaewenTown_EventScript_VacuumWave::
	setvar VAR_0x8008, 4
	setvar VAR_0x8005, MOVE_VACUUM_WAVE
	goto HaewenTown_EventScript_ConfirmMoveSelection
	end

HaewenTown_EventScript_GigaDrain::
	setvar VAR_0x8008, 6
	setvar VAR_0x8005, MOVE_GIGA_DRAIN
	goto HaewenTown_EventScript_ConfirmMoveSelection
	end

HaewenTown_EventScript_SignalBeam::
	setvar VAR_0x8008, 6
	setvar VAR_0x8005, MOVE_SIGNAL_BEAM
	goto HaewenTown_EventScript_ConfirmMoveSelection
	end

HaewenTown_EventScript_PhrenoAttack::
	setvar VAR_0x8008, 6
	setvar VAR_0x8005, MOVE_PHRENO_ATTACK
	goto HaewenTown_EventScript_ConfirmMoveSelection
	end

HaewenTown_EventScript_SomaAttack::
	setvar VAR_0x8008, 6
	setvar VAR_0x8005, MOVE_SOMA_ATTACK
	goto HaewenTown_EventScript_ConfirmMoveSelection
	end

HaewenTown_EventScript_TriAttack::
	setvar VAR_0x8008, 6
	setvar VAR_0x8005, MOVE_TRI_ATTACK
	goto HaewenTown_EventScript_ConfirmMoveSelection
	end

HaewenTown_EventScript_BlueNoise::
	setvar VAR_0x8008, 8
	setvar VAR_0x8005, MOVE_BLUE_NOISE
	goto HaewenTown_EventScript_ConfirmMoveSelection
	end

HaewenTown_EventScript_DroneWave::
	setvar VAR_0x8008, 8
	setvar VAR_0x8005, MOVE_DRONE_WAVE
	goto HaewenTown_EventScript_ConfirmMoveSelection
	end

HaewenTown_EventScript_Psychosis::
	setvar VAR_0x8008, 8
	setvar VAR_0x8005, MOVE_PSYCHOSIS
	goto HaewenTown_EventScript_ConfirmMoveSelection
	end

HaewenTown_EventScript_VoltSwitch::
	setvar VAR_0x8008, 8
	setvar VAR_0x8005, MOVE_VOLT_SWITCH
	goto HaewenTown_EventScript_ConfirmMoveSelection
	end

HaewenTown_EventScript_DragonPulse::
	setvar VAR_0x8008, 10
	setvar VAR_0x8005, MOVE_DRAGON_PULSE
	goto HaewenTown_EventScript_ConfirmMoveSelection
	end

HaewenTown_EventScript_EarthPower::
	setvar VAR_0x8008, 10
	setvar VAR_0x8005, MOVE_EARTH_POWER
	goto HaewenTown_EventScript_ConfirmMoveSelection
	end

HaewenTown_EventScript_Psyshock::
	setvar VAR_0x8008, 10
	setvar VAR_0x8005, MOVE_PSYSHOCK
	goto HaewenTown_EventScript_ConfirmMoveSelection
	end

HaewenTown_EventScript_HeatWave::
	setvar VAR_0x8008, 12
	setvar VAR_0x8005, MOVE_HEAT_WAVE
	goto HaewenTown_EventScript_ConfirmMoveSelection
	end

HaewenTown_EventScript_UVBurst::
	setvar VAR_0x8008, 12
	setvar VAR_0x8005, MOVE_UV_BURST
	goto HaewenTown_EventScript_ConfirmMoveSelection
	end

HaewenTown_EventScript_ForceOfWill::
	setvar VAR_0x8008, 14
	setvar VAR_0x8005, MOVE_FORCE_OF_WILL
	goto HaewenTown_EventScript_ConfirmMoveSelection
	end

HaewenTown_EventScript_ExitTutorMoveSelect::
	msgbox HaewenTown_Text_ComeBack, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8005 is the move number
@ VAR_0x8008 is the price
HaewenTown_EventScript_ConfirmMoveSelection::
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	msgbox HaewenTown_Text_MoveWillBeXBlueShards, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, HaewenTown_EventScript_ChooseBlueTutorMove
	checkitem ITEM_BLUE_SHARD, VAR_0x8008
	goto_if_eq VAR_RESULT, TRUE, HaewenTown_EventScript_TeachTutorMove
	msgbox HaewenTown_Text_HaventGotEnoughBlueShards, MSGBOX_DEFAULT
	goto HaewenTown_EventScript_ChooseBlueTutorMove
	end

HaewenTown_EventScript_TeachTutorMove::
	msgbox HaewenTown_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, FALSE, HaewenTown_EventScript_CancelChooseMon
	msgbox HaewenTown_Text_HandedOverBlueShards, MSGBOX_DEFAULT
	removeitem ITEM_BLUE_SHARD, VAR_0x8008
	msgbox HaewenTown_Text_ComeBack, MSGBOX_DEFAULT
	release
	end

HaewenTown_EventScript_CancelChooseMon::
	msgbox HaewenTown_Text_ComeBack, MSGBOX_DEFAULT
	release
	end

HaewenTown_Text_ImAMoveTutor:
	.string "I'm a move tutor. My moves will leave\n"
	.string "your opponents dazzled and awestruck.\p"
	.string "But I'll only teach them in exchange\n"
	.string "for BLUE SHARDS.\p"
	.string "Well, how about it?$"
	@.string "Have you come to learn some elite moves?$"

HaewenTown_Text_TeachWhichMove:
	.string "Which move should I teach?$"

HaewenTown_Text_HaventGotEnoughBlueShards:
	.string "You don't have enough BLUE SHARDS!$"

HaewenTown_Text_MoveWillBeXBlueShards:
	.string "Great, that'll be {STR_VAR_2} BLUE SHARDS.$"

HaewenTown_Text_TeachMoveToWhichMon:
	.string "Which POKéMON should I teach?$"

HaewenTown_Text_HandedOverBlueShards:
	.string "{PLAYER} handed over the\n"
	.string "BLUE SHARDS in exchange.$"

HaewenTown_Text_ComeBack:
	.string "Come back if you want to learn\n"
	.string "some more elite moves.$"


