.set LOCALID_NINJA_BOY, 5

BurgundyTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BurgundyTown_OnTransition
	.byte 0

BurgundyTown_OnTransition:
	setflag FLAG_VISITED_BURGUNDY_TOWN
	goto_if_not_defeated TRAINER_HINOE, BurgundyTown_EventScript_SetNinjasNotDefeated
	end

BurgundyTown_EventScript_SetNinjasNotDefeated::
	clearflag FLAG_HIDE_BURGUNDY_NINJA_BOYS
	cleartrainerflag TRAINER_KINOE
	cleartrainerflag TRAINER_KINOTO
	cleartrainerflag TRAINER_HINOTO
	cleartrainerflag TRAINER_TSUCHINOE
	cleartrainerflag TRAINER_TSUCHINOTO
	cleartrainerflag TRAINER_KANOE
	cleartrainerflag TRAINER_KANOTO
	cleartrainerflag TRAINER_MIZUNOE
	cleartrainerflag TRAINER_MIZUNOTO
	end

BurgundyTown_EventScript_NinjaBoy::
	lock
	faceplayer
	@questmenu QUEST_MENU_CHECK_COMPLETE QUEST_42
	@goto_if_eq VAR_RESULT, TRUE, BurgundyTown_EventScript_QuestComplete
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_42
	goto_if_eq VAR_RESULT, TRUE, BurgundyTown_EventScript_QuestInProgress
	msgbox BurgundyTown_Text_ExplainNinjaSchool, MSGBOX_DEFAULT
	closemessage
	startquest QUEST_42
	release
	end

BurgundyTown_EventScript_QuestInProgress::
	msgbox BurgundyTown_Text_BattleOurClass, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BurgundyTown_EventScript_BattleGauntlet
	goto_if_eq VAR_RESULT, NO, BurgundyTown_EventScript_RefuseToBattle
	end

BurgundyTown_Text_BattleOurClass:
	.string "Care to test your might against\n"
	.string "our ninja arts?$"

BurgundyTown_Text_ExplainNinjaSchool:
	.string "High above the ISSHO region,\n"
	.string "in the valley of DUSK MOUNTAIN,\p"
	.string "Lies the Hidden Village\n"
	.string "of BURGUNDY TOWN.\p"
	.string "And its famous Ninja Academy.\p"
	.string "This is the home of its master,\n"
	.string "the legendary BURGUNDY SAGE.\p"
	.string "And we are his students and disciples,\n"
	.string "the faithful JUUNIN.\p"
	.string "If you wish to see the sage,\n"
	.string "you'll have to get through us.$"

BurgundyTown_EventScript_RefuseToBattle::
	msgbox BurgundyTown_Text_RefuseToBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

BurgundyTown_Text_RefuseToBattle:
	.string "Yeah, that's what I thought.$"

BurgundyTown_EventScript_BattleGauntlet::
	msgbox BurgundyTown_Text_KinotoIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KINOTO, BurgundyTown_Text_KinotoDefeat
	call BurgundyTown_EventScript_CycleNinjaBoys

	msgbox BurgundyTown_Text_MizunotoIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MIZUNOTO, BurgundyTown_Text_MizunotoDefeat
	call BurgundyTown_EventScript_CycleNinjaBoys

	msgbox BurgundyTown_Text_HinotoIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_HINOTO, BurgundyTown_Text_HinotoDefeat
	call BurgundyTown_EventScript_CycleNinjaBoys

	msgbox BurgundyTown_Text_KanoeIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KANOE, BurgundyTown_Text_KanoeDefeat
	call BurgundyTown_EventScript_CycleNinjaBoys

	msgbox BurgundyTown_Text_MizunoeIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MIZUNOE, BurgundyTown_Text_MizunoeDefeat
	call BurgundyTown_EventScript_CycleNinjaBoys

	msgbox BurgundyTown_Text_KanotoIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KANOTO, BurgundyTown_Text_KanotoDefeat
	call BurgundyTown_EventScript_CycleNinjaBoys

	msgbox BurgundyTown_Text_TsuchinotoIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_TSUCHINOTO, BurgundyTown_Text_TsuchinotoDefeat
	call BurgundyTown_EventScript_CycleNinjaBoys

	msgbox BurgundyTown_Text_KinoeIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KINOE, BurgundyTown_Text_KinoeDefeat
	call BurgundyTown_EventScript_CycleNinjaBoys

	msgbox BurgundyTown_Text_TsuchinoeIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_TSUCHINOE, BurgundyTown_Text_TsuchinoeDefeat
	call BurgundyTown_EventScript_CycleNinjaBoys

	msgbox BurgundyTown_Text_HinoeIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_HINOE, BurgundyTown_Text_HinoeDefeat

	applymovement LOCALID_NINJA_BOY, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox BurgundyTown_Text_HinoePostBattle, MSGBOX_DEFAULT
	closemessage
	call BurgundyTown_EventScript_OpenWinstrateDoor
	applymovement LOCALID_NINJA_BOY, BurgundyTown_Movement_WinstrateEnterHouse
	waitmovement 0
	removeobject LOCALID_NINJA_BOY
	call BurgundyTown_EventScript_CloseWinstrateDoor
	setflag FLAG_HIDE_BURGUNDY_NINJA_BOYS
	release
	end

BurgundyTown_EventScript_CycleNinjaBoys:
	applymovement LOCALID_NINJA_BOY, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	call BurgundyTown_EventScript_OpenWinstrateDoor
	applymovement LOCALID_NINJA_BOY, BurgundyTown_Movement_WinstrateEnterHouse
	waitmovement 0
	removeobject LOCALID_NINJA_BOY
	call BurgundyTown_EventScript_CloseWinstrateDoor
	applymovement OBJ_EVENT_ID_PLAYER, BurgundyTown_Movement_WaitForNextWinstrate
	waitmovement 0
	call BurgundyTown_EventScript_OpenWinstrateDoor
	setobjectxyperm LOCALID_NINJA_BOY, 10, 9
	setobjectmovementtype LOCALID_NINJA_BOY, MOVEMENT_TYPE_FACE_DOWN
	addobject LOCALID_NINJA_BOY
	applymovement LOCALID_NINJA_BOY, BurgundyTown_Movement_WinstrateExitHouse
	waitmovement 0
	call BurgundyTown_EventScript_CloseWinstrateDoor
	return

BurgundyTown_EventScript_OpenWinstrateDoor::
	opendoor 10, 9
	waitdooranim
	return

BurgundyTown_EventScript_CloseWinstrateDoor::
	closedoor 10, 9
	waitdooranim
	return

BurgundyTown_Text_KinotoIntro:
	.string "So be it.\n"
	.string "Then I shall be your first opponent!$"

BurgundyTown_Text_MizunotoIntro:
	.string "Water Shuriken jutsu!$"

BurgundyTown_Text_HinotoIntro:
	.string "Grand Fireball jutsu!$"

BurgundyTown_Text_KanoeIntro:
	.string "Flying Thunder God jutsu!$"

BurgundyTown_Text_MizunoeIntro:
	.string "10,000 Ice Petals jutsu!$"

BurgundyTown_Text_KanotoIntro:
	.string "Mwahahaha!\n"
	.string "I'll deafen your senses!$"

BurgundyTown_Text_TsuchinotoIntro:
	.string "Are you getting tired yet?\n"
	.string "Why don't you go to sleep?$"

BurgundyTown_Text_KinoeIntro:
	@.string "Fufufufufu.\n"
	@.string "Light of the Moon style.$"
	.string "Secret technique:\n"
	.string "Dance of the Crescent Moon!$"

BurgundyTown_Text_TsuchinoeIntro:
	.string "Shadow Clone jutsu!$"

BurgundyTown_Text_HinoeIntro:
	.string "My fellow pupils were no match for you,\n"
	.string "but they're nothing compared to me.\p"
	.string "Fear my Dragon Sage jutsu!$"

BurgundyTown_Text_HinoePostBattle:
	.string "You may have defeated us...\p"
	.string "But you're still no match for\n"
	.string "the BURGUNDY SAGE himself!$"

BurgundyTown_Text_KinotoDefeat:
	.string "!!!$"

BurgundyTown_Text_MizunotoDefeat:
	.string "!!!$"

BurgundyTown_Text_HinotoDefeat:
	.string "!!!$"

BurgundyTown_Text_KanoeDefeat:
	.string "!!!$"

BurgundyTown_Text_MizunoeDefeat:
	.string "!!!$"

BurgundyTown_Text_KanotoDefeat:
	.string "!!!$"

BurgundyTown_Text_TsuchinotoDefeat:
	.string "!!!$"

BurgundyTown_Text_KinoeDefeat:
	.string "!!!$"

BurgundyTown_Text_TsuchinoeDefeat:
	.string "!!!$"

BurgundyTown_Text_HinoeDefeat:
	.string "!!!$"


BurgundyTown_Movement_WinstrateEnterHouse:
	walk_in_place_faster_up
	walk_up
	step_end

BurgundyTown_Movement_WinstrateExitHouse:
	walk_down
	step_end

BurgundyTown_Movement_WaitForNextWinstrate:
	delay_16
	delay_16
	delay_16
	step_end









BurgundyTown_EventScript_TownSign::
	msgbox BurgundyTown_Text_TownSign, MSGBOX_SIGN
	end

BurgundyTown_Text_TownSign:
	.string "BURGUNDY TOWN\n"
	.string "“A village in blissful solitude.”$"







BurgundyTown_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_BURGUNDY_TOWN_RECEIVED_FRIEND_BALLS, BurgundyTown_EventScript_ExplainFriendBalls
	msgbox BurgundyTown_Text_BeMyFriend, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, BurgundyTown_EventScript_NotFriendly
	msgbox BurgundyTown_Text_ILikeYou, MSGBOX_DEFAULT
	giveitem ITEM_FRIEND_BALL, 10
	setflag FLAG_BURGUNDY_TOWN_RECEIVED_FRIEND_BALLS
BurgundyTown_EventScript_ExplainFriendBalls::
	msgbox BurgundyTown_Text_ExplainFriendBalls, MSGBOX_DEFAULT
	release
	end

BurgundyTown_EventScript_NotFriendly::
	msgbox BurgundyTown_Text_Aww, MSGBOX_DEFAULT
	release
	end

BurgundyTown_Text_BeMyFriend:
	.string "Will you be my friend?$"

BurgundyTown_Text_Aww:
	.string "Aww...$"

BurgundyTown_Text_ILikeYou:
	.string "I like you.\n"
	.string "Here take these with you!$"

BurgundyTown_Text_ExplainFriendBalls:
	.string "FRIEND BALLS make POKéMON\n"
	.string "extra friendly.\p"
	.string "Try catching a POKéMON with it!$"

BurgundyTown_EventScript_Girl::
	msgbox BurgundyTown_Text_ChanseySanctuary, MSGBOX_NPC
	end

BurgundyTown_Text_ChanseySanctuary:
	.string "It's said that CHANSEY was once\n"
	.string "widespread throughout southern ISSHO.\p"
	.string "But it was hunted to near extinction.\p"
	.string "The CHANSEY here are the only ones\n"
	.string "that survived.\p"
	.string "It makes me happy to know that\n"
	.string "they have a sanctuary here.$"

BurgundyTown_EventScript_Pokemon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	msgbox BurgundyTown_Text_Pokemon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BurgundyTown_Text_Pokemon:
	.string "CHANSEY: Chan chan!$"

BurgundyTown_EventScript_Boy::
	msgbox BurgundyTown_Text_DuskMountain, MSGBOX_NPC
	end

BurgundyTown_Text_DuskMountain:
	.string "You came all the way here\n"
	.string "through DUSK MOUNTAIN?\p"
	.string "I can't even remember the last\n"
	.string "time someone did that!$"
	@.string "The last time someone did that,\n"
	@.string "I wasn't even born yet.$"






