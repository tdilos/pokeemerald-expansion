.set LOCALID_RANGER, 6

Route86_MapScripts::
	.byte 0

Route86_EventScript_Bree::
	trainerbattle_single TRAINER_BREE, Route86_Text_BreeIntro, Route86_Text_BreeDefeated
	msgbox Route86_Text_BreePostBattle, MSGBOX_AUTOCLOSE
	end

Route86_EventScript_Brook::
	trainerbattle_single TRAINER_BROOK, Route86_Text_BrookIntro, Route86_Text_BrookDefeated
	msgbox Route86_Text_BrookPostBattle, MSGBOX_AUTOCLOSE
	end

Route86_EventScript_Nick::
	trainerbattle_single TRAINER_NICK, Route86_Text_NickIntro, Route86_Text_NickDefeated
	msgbox Route86_Text_NickPostBattle, MSGBOX_AUTOCLOSE
	end

Route86_EventScript_Summer::
	trainerbattle_single TRAINER_SUMMER, Route86_Text_SummerIntro, Route86_Text_SummerDefeated
	msgbox Route86_Text_SummerPostBattle, MSGBOX_AUTOCLOSE
	end

Route86_EventScript_Hogan::
	trainerbattle_single TRAINER_HOGAN, Route86_Text_HoganIntro, Route86_Text_HoganDefeated
	msgbox Route86_Text_HoganPostBattle, MSGBOX_AUTOCLOSE
	end



Route86_EventScript_RangerTrigger::
	lockall
	playse SE_PIN
	applymovement LOCALID_RANGER, Common_Movement_FaceRight
	waitmovement 0
	applymovement LOCALID_RANGER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 60
	applymovement LOCALID_RANGER, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RANGER, Common_Movement_WalkRight
	waitmovement 0
	msgbox Route86_Text_MissingCouple, MSGBOX_NPC
	closemessage
	applymovement LOCALID_RANGER, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_RANGER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_RANGER, Common_Movement_FaceLeft
	waitmovement 0
	setvar VAR_ROUTE87_STATE, 1
	@questmenu QUEST_MENU_UNLOCK_QUEST QUEST_10
	@openquestmenu
	startquest QUEST_10
	releaseall
	end
	
Route86_EventScript_Ranger::
	lockall
	faceplayer
	msgbox Route86_Text_KeepAnEyeOut, MSGBOX_NPC
	closemessage
	applymovement LOCALID_RANGER, Common_Movement_FaceLeft
	waitmovement 0
	releaseall
	end

Route86_Text_MissingCouple:
	.string "Hey there, trainer.\p"
	.string "Have you seen a couple of tourists,\n"
	.string "both middle-aged?\p"
	.string "...\p"
	.string "I figured as much. I've been out here\n"
	.string "searching for them all day.\p"
	.string "There's a missing person's report\n"
	.string "out for them right now.\p"
	.string "And when people and POKéMON are\n"
	.string "in trouble, us POKéMON RANGERS\l"
	.string "are here to help them out.\p"
	.string "Keep an eye out for them, and\n"
	.string "tell me if you see anything, okay?$"

Route86_Text_KeepAnEyeOut:
	.string "Keep an eye out for those tourists,\n"
	.string "and tell me if you see anything.$"


