.set LOCALID_BOB, 1
.set LOCALID_IZZI, 3
.set LOCALID_NEVEN, 4
.set LOCALID_HABIBAH, 5

PitchblakCity_Flat6_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PitchblakCity_Flat6_1F_OnTransition
	.byte 0

PitchblakCity_Flat6_1F_OnTransition:
	goto_if_not_defeated TRAINER_HABIBAH, PitchblakCity_Flat6_1F_EventScript_SetInverseHouseNotDefeated
	end

PitchblakCity_Flat6_1F_EventScript_SetInverseHouseNotDefeated::
	clearflag FLAG_HIDE_ROUTE_111_VICTOR_WINSTRATE
	setflag FLAG_HIDE_ROUTE_111_VICTORIA_WINSTRATE
	setflag FLAG_HIDE_ROUTE_111_VIVI_WINSTRATE
	setflag FLAG_HIDE_ROUTE_111_VICKY_WINSTRATE
	cleartrainerflag TRAINER_BOB
	cleartrainerflag TRAINER_IZZI
	cleartrainerflag TRAINER_NEVEN
	end




PitchblakCity_Flat6_1F_EventScript_OldWoman::
	msgbox PitchblakCity_Flat6_1F_Text_Spectator, MSGBOX_NPC
	end

PitchblakCity_Flat6_1F_Text_Spectator:
	.string "Don't mind me. I'm just here to watch.\n"
	.string "Hohohoho!$"

PitchblakCity_Flat6_1F_EventScript_Bob::
	lock
	faceplayer
	@goto_if_quest_inactive QUEST_24, PitchblakCity_Flat6_1F_EventScript_RefuseToBattle
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_24
	goto_if_eq VAR_RESULT, FALSE, PitchblakCity_Flat6_1F_EventScript_RefuseToBattle
	msgbox PitchblakCity_Flat6_1F_Text_BattleOurFamily, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PitchblakCity_Flat6_1F_EventScript_BattleGauntlet
	goto_if_eq VAR_RESULT, NO, PitchblakCity_Flat6_1F_EventScript_RefuseToBattle
	end

PitchblakCity_Flat6_1F_Text_BattleOurFamily:
	.string "Hmmm. You came here looking for the\n"
	.string "inverse battle challenge?\p"
	.string "You have to beat all of us in a row.\n"
	.string "No breaks in between.\p"
	.string "You think you can handle that?$"

PitchblakCity_Flat6_1F_EventScript_RefuseToBattle::
	msgbox PitchblakCity_Flat6_1F_Text_IsThatSo, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Flat6_1F_Text_IsThatSo:
	.string "Hmmm. Perhaps you're not the right kind\n"
	.string "of trainer for this sort of thing.$"
	

PitchblakCity_Flat6_1F_EventScript_BattleGauntlet::
	setflag FLAG_INVERSE_BATTLE
	msgbox PitchblakCity_Flat6_1F_Text_BobIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BOB, PitchblakCity_Flat6_1F_Text_BobDefeat
	applymovement LOCALID_BOB, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	@call PitchblakCity_Flat6_1F_EventScript_OpenWinstrateDoor
	msgbox PitchblakCity_Flat6_1F_Text_BobPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BOB, PitchblakCity_Flat6_1F_Movement_WinstrateEnterHouse
	waitmovement 0
	removeobject LOCALID_BOB
	call PitchblakCity_Flat6_1F_EventScript_GoUpDownStairs
	@call PitchblakCity_Flat6_1F_EventScript_CloseWinstrateDoor
	applymovement OBJ_EVENT_ID_PLAYER, PitchblakCity_Flat6_1F_Movement_WaitForNextWinstrate
	waitmovement 0
	@call PitchblakCity_Flat6_1F_EventScript_OpenWinstrateDoor
	call PitchblakCity_Flat6_1F_EventScript_GoUpDownStairs
	addobject LOCALID_IZZI
	applymovement LOCALID_IZZI, PitchblakCity_Flat6_1F_Movement_WinstrateExitHouse
	waitmovement 0
	@call PitchblakCity_Flat6_1F_EventScript_CloseWinstrateDoor
	msgbox PitchblakCity_Flat6_1F_Text_IzziIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_IZZI, PitchblakCity_Flat6_1F_Text_IzziDefeat
	applymovement LOCALID_IZZI, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	@call PitchblakCity_Flat6_1F_EventScript_OpenWinstrateDoor
	msgbox PitchblakCity_Flat6_1F_Text_IzziPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_IZZI, PitchblakCity_Flat6_1F_Movement_WinstrateEnterHouse
	waitmovement 0
	removeobject LOCALID_IZZI
	call PitchblakCity_Flat6_1F_EventScript_GoUpDownStairs
	@call PitchblakCity_Flat6_1F_EventScript_CloseWinstrateDoor
	applymovement OBJ_EVENT_ID_PLAYER, PitchblakCity_Flat6_1F_Movement_WaitForNextWinstrate
	waitmovement 0
	@call PitchblakCity_Flat6_1F_EventScript_OpenWinstrateDoor
	call PitchblakCity_Flat6_1F_EventScript_GoUpDownStairs
	addobject LOCALID_NEVEN
	applymovement LOCALID_NEVEN, PitchblakCity_Flat6_1F_Movement_WinstrateExitHouse
	waitmovement 0
	@call PitchblakCity_Flat6_1F_EventScript_CloseWinstrateDoor
	msgbox PitchblakCity_Flat6_1F_Text_NevenIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_NEVEN, PitchblakCity_Flat6_1F_Text_NevenDefeat
	applymovement LOCALID_NEVEN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	@call PitchblakCity_Flat6_1F_EventScript_OpenWinstrateDoor
	msgbox PitchblakCity_Flat6_1F_Text_NevenPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_NEVEN, PitchblakCity_Flat6_1F_Movement_WinstrateEnterHouse
	waitmovement 0
	removeobject LOCALID_NEVEN
	call PitchblakCity_Flat6_1F_EventScript_GoUpDownStairs
	@call PitchblakCity_Flat6_1F_EventScript_CloseWinstrateDoor
	applymovement OBJ_EVENT_ID_PLAYER, PitchblakCity_Flat6_1F_Movement_WaitForNextWinstrate
	waitmovement 0
	@call PitchblakCity_Flat6_1F_EventScript_OpenWinstrateDoor
	call PitchblakCity_Flat6_1F_EventScript_GoUpDownStairs
	addobject LOCALID_HABIBAH
	applymovement LOCALID_HABIBAH, PitchblakCity_Flat6_1F_Movement_WinstrateExitHouse
	waitmovement 0
	@call PitchblakCity_Flat6_1F_EventScript_CloseWinstrateDoor
	msgbox PitchblakCity_Flat6_1F_Text_HabibahIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_HABIBAH, PitchblakCity_Flat6_1F_Text_HabibahDefeat
	msgbox PitchblakCity_Flat6_1F_Text_HabibahPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_HABIBAH, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	@call PitchblakCity_Flat6_1F_EventScript_OpenWinstrateDoor
	applymovement LOCALID_HABIBAH, PitchblakCity_Flat6_1F_Movement_WinstrateEnterHouse
	waitmovement 0
	removeobject LOCALID_HABIBAH
	call PitchblakCity_Flat6_1F_EventScript_GoUpDownStairs
	@call PitchblakCity_Flat6_1F_EventScript_CloseWinstrateDoor
	clearflag FLAG_INVERSE_BATTLE
	release
	end

PitchblakCity_Flat6_1F_EventScript_GoUpDownStairs::
	playse SE_EXIT
	waitse
	return

PitchblakCity_Flat6_1F_Movement_WinstrateEnterHouse:
	walk_in_place_faster_up
	walk_up
	step_end

PitchblakCity_Flat6_1F_Movement_WinstrateExitHouse:
	walk_down
	step_end

PitchblakCity_Flat6_1F_Movement_WaitForNextWinstrate:
	delay_16
	delay_16
	delay_16
	step_end

PitchblakCity_Flat6_1F_Text_BobIntro:
	.string "Wahaha! You got guts, I'll give\n"
	.string "you that!\p"
	.string "Very well. I'll be your first opponent!$"

PitchblakCity_Flat6_1F_Text_BobDefeat:
	.string "Wahaha! Not bad at all.$"

PitchblakCity_Flat6_1F_Text_BobPostBattle:
	.string "Oy everyone! Get down here!$"

PitchblakCity_Flat6_1F_Text_IzziIntro:
	.string "Next up is me!\n"
	.string "Don't think I'll go easy on you!$"

PitchblakCity_Flat6_1F_Text_IzziDefeat:
	.string "Hey now, take it easy!$"

PitchblakCity_Flat6_1F_Text_IzziPostBattle:
	.string "Hey, check it out!\n"
	.string "We got a strong trainer here!$"

PitchblakCity_Flat6_1F_Text_NevenIntro:
	.string "You're not so tough!\n"
	.string "I got just the thing to put you down!$"

PitchblakCity_Flat6_1F_Text_NevenDefeat:
	.string "Maybe you are pretty tough...$"

PitchblakCity_Flat6_1F_Text_NevenPostBattle:
	.string "Hey, this trainer's no joke!\n"
	.string "Come take a look!$"

PitchblakCity_Flat6_1F_Text_HabibahIntro:
	.string "You must be good to get past\n"
	.string "those other three.\p"
	.string "But your victory streak ends here.\p"
	.string "As the champion of this house,\n"
	.string "I have a reputation to uphold.$"

PitchblakCity_Flat6_1F_Text_HabibahDefeat:
	.string "No way!$"

PitchblakCity_Flat6_1F_Text_HabibahPostBattle:
	.string "\p"
	.string "It seems not even I could stop you.\p"
	.string "Very well, you're now officially the\n"
	.string "new champion of Inverse House.\p"
	.string "Feel free to join us upstairs.$"


