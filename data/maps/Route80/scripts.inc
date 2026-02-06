.set LOCALID_RIVAL, 5

Route80_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route80_OnTransition
	.byte 0

Route80_OnTransition:
	@setflag FLAG_HIDE_ROUTE_80_JACE
	removeobject LOCALID_RIVAL
	end

Route80_EventScript_Hiker::
	lock
	faceplayer
	msgbox Route80_Text_Landslide, MSGBOX_DEFAULT
	release
	end

Route80_EventScript_RouteSign::
	msgbox Route80_Text_RouteSign, MSGBOX_SIGN
	end

Route80_Text_Landslide:
	.string "Bad news. The tunnel's been blocked\n"
	.string "by a landslide.\p"
	.string "If only there was a way to remove\n"
	.string "those rocks...$"

Route80_Text_RouteSign:
	.string "ROUTE 80\p"
	.string "{RIGHT_ARROW} QUARTZ CAVE$"




Route80_EventScript_Hiker2::
	lock
	faceplayer
	msgbox Route80_Text_TakeARest, MSGBOX_DEFAULT
	release
	end

Route80_Text_TakeARest:
	.string "It's still a ways to get to COBALT CITY.\p"
	.string "Why don't you stop inside and\n"
	.string "have a rest?$"




Route80_EventScript_Dahlia::
	trainerbattle_single TRAINER_DAHLIA, Route80_Text_DahliaIntro, Route80_Text_DahliaDefeated
	msgbox Route80_Text_DahliaPostBattle, MSGBOX_AUTOCLOSE
	end

Route80_EventScript_TrainerTipsBagSort::
	msgbox Route80_Text_TrainerTipsBagSort, MSGBOX_SIGN
	end

Route80_Text_TrainerTipsBagSort:
	.string "TRAINER TIPS\p"
	.string "Press START to sort items in the BAG.$"

Route80_EventScript_JaceStopsPlayer1::
	lockall
	msgbox Route80_Text_CallPlayerName, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	delay 60
	@setflag FLAG_HIDE_ROUTE_80_JACE
	clearflag FLAG_HIDE_JACE
	addobject LOCALID_RIVAL
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	applymovement LOCALID_RIVAL, Route80_Movement_JaceWalkToPlayer1
	waitmovement 0
	msgbox Route80_Text_YouDunce, MSGBOX_DEFAULT
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	warp MAP_UMBER_TOWN_HAZELS_LAB, 6, 5
	playse SE_EXIT
	waitstate
	releaseall
	end

Route80_EventScript_JaceStopsPlayer2::
	lockall
	msgbox Route80_Text_CallPlayerName, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	delay 60
	@setflag FLAG_HIDE_ROUTE_80_JACE
	clearflag FLAG_HIDE_JACE
	addobject LOCALID_RIVAL
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	applymovement LOCALID_RIVAL, Route80_Movement_JaceWalkToPlayer2
	waitmovement 0
	msgbox Route80_Text_YouDunce, MSGBOX_DEFAULT
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	warp MAP_UMBER_TOWN_HAZELS_LAB, 6, 5
	playse SE_EXIT
	waitstate
	releaseall
	end

Route80_EventScript_JaceStopsPlayer3::
	lockall
	msgbox Route80_Text_CallPlayerName, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	delay 60
	@setflag FLAG_HIDE_ROUTE_80_JACE
	clearflag FLAG_HIDE_JACE
	addobject LOCALID_RIVAL
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	applymovement LOCALID_RIVAL, Route80_Movement_JaceWalkToPlayer3
	waitmovement 0
	msgbox Route80_Text_YouDunce, MSGBOX_DEFAULT
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	warp MAP_UMBER_TOWN_HAZELS_LAB, 6, 5
	playse SE_EXIT
	waitstate
	releaseall
	end

Route80_Text_CallPlayerName:
	.string "????: {PLAYER}!$"

Route80_Text_YouDunce:
	.string "JACE: Leaving town already?\p"
	.string "You won't get far without any POKéMON,\n"
	.string "you dunce.\p"
	.string "C'mon, there's a girl in the lab\n"
	.string "who's giving away free POKéMON!$"

Route80_Movement_JaceWalkToPlayer1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	face_right
	delay_8
	step_end

Route80_Movement_JaceWalkToPlayer2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	face_right
	delay_8
	step_end

Route80_Movement_JaceWalkToPlayer3:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	face_right
	delay_8
	step_end

