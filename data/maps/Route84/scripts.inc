.set LOCALID_GRUNT, 3

Route84_MapScripts::
	.byte 0

Route84_EventScript_TrainerTipsHMEncounters::
	msgbox Route84_Text_TrainerTipsHMEncounters, MSGBOX_SIGN
	end

Route84_Text_TrainerTipsHMEncounters:
	.string "TRAINER TIPS\p"
	.string "Watch out for wild POKéMON when using\n"
	.string "CUT, ROCK SMASH, or THAW in the field.$"

Route84_EventScript_Maya::
	trainerbattle_double TRAINER_MAYA_AND_JOY, Route84_Text_MayaAndJoyIntro, Route84_Text_MayaAndJoyDefeated, Route84_Text_MayaAndJoyNotEnoughMons
	msgbox Route84_Text_MayaPostBattle, MSGBOX_AUTOCLOSE
	end

Route84_EventScript_Joy::
	trainerbattle_double TRAINER_MAYA_AND_JOY, Route84_Text_MayaAndJoyIntro, Route84_Text_MayaAndJoyDefeated, Route84_Text_MayaAndJoyNotEnoughMons
	msgbox Route84_Text_JoyPostBattle, MSGBOX_AUTOCLOSE
	end

Route84_EventScript_Todd::
	trainerbattle_single TRAINER_TODD, Route84_Text_ToddIntro, Route84_Text_ToddDefeated
	msgbox Route84_Text_ToddPostBattle, MSGBOX_AUTOCLOSE
	end

Route84_EventScript_Quentin::
	trainerbattle_single TRAINER_QUENTIN, Route84_Text_QuentinIntro, Route84_Text_QuentinDefeated
	msgbox Route84_Text_QuentinPostBattle, MSGBOX_AUTOCLOSE
	end

Route84_EventScript_Mason::
	trainerbattle_single TRAINER_MASON, Route84_Text_MasonIntro, Route84_Text_MasonDefeated
	msgbox Route84_Text_MasonPostBattle, MSGBOX_AUTOCLOSE
	end

Route84_EventScript_Kiersten::
	trainerbattle_single TRAINER_KIERSTEN, Route84_Text_KierstenIntro, Route84_Text_KierstenDefeated
	msgbox Route84_Text_KierstenPostBattle, MSGBOX_AUTOCLOSE
	end

Route84_EventScript_GenesisGrunt0::
	lockall
	setvar VAR_TEMP_1, 0
	applymovement LOCALID_GRUNT, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	delay 20
	goto Route84_EventScript_GenesisGrunt
	end	

Route84_EventScript_GenesisGrunt1::
	lockall
	setvar VAR_TEMP_1, 1
	applymovement LOCALID_GRUNT, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	delay 60
	applymovement LOCALID_GRUNT, Common_Movement_WalkDown
	waitmovement 0
	goto Route84_EventScript_GenesisGrunt
	end

Route84_EventScript_GenesisGrunt2::
	lockall
	setvar VAR_TEMP_1, 2
	applymovement LOCALID_GRUNT, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	delay 60
	applymovement LOCALID_GRUNT, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkDown
	waitmovement 0
	goto Route84_EventScript_GenesisGrunt
	end

Route84_EventScript_GenesisGrunt3::
	lockall
	setvar VAR_TEMP_1, 3
	applymovement LOCALID_GRUNT, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	delay 60
	applymovement LOCALID_GRUNT, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkDown
	waitmovement 0
	goto Route84_EventScript_GenesisGrunt
	end

Route84_EventScript_GenesisGrunt::
	msgbox Route84_Text_TollRoad, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route84_EventScript_PayToll
	goto_if_eq VAR_RESULT, NO, Route84_EventScript_DontPayToll
	end

Route84_EventScript_PayToll::
	checkmoney 1000
	goto_if_eq VAR_RESULT, FALSE, Route84_EventScript_NotEnoughMoney
	msgbox Route84_Text_PaidOutrageousToll, MSGBOX_DEFAULT
	removemoney 1000
	@closemessage
	msgbox Route84_Text_YoureGullible, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_TEMP_1, 0, Route84_EventScript_TurnPlayerAway0
	goto_if_eq VAR_TEMP_1, 1, Route84_EventScript_TurnPlayerAway1
	goto_if_eq VAR_TEMP_1, 2, Route84_EventScript_TurnPlayerAway2
	goto_if_eq VAR_TEMP_1, 3, Route84_EventScript_TurnPlayerAway3
	end

Route84_EventScript_NotEnoughMoney::
	msgbox Route84_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto Route84_EventScript_DontPayToll
	end

Route84_EventScript_DontPayToll::
	msgbox Route84_Text_CantPay, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_TEMP_1, 0, Route84_EventScript_TurnPlayerAway0
	goto_if_eq VAR_TEMP_1, 1, Route84_EventScript_TurnPlayerAway1
	goto_if_eq VAR_TEMP_1, 2, Route84_EventScript_TurnPlayerAway2
	goto_if_eq VAR_TEMP_1, 3, Route84_EventScript_TurnPlayerAway3
	end
	
Route84_EventScript_TurnPlayerAway0::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	applymovement LOCALID_GRUNT, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_FaceDown
	waitmovement 0
	releaseall
	end

Route84_EventScript_TurnPlayerAway1::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	applymovement LOCALID_GRUNT, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_FaceDown
	waitmovement 0
	releaseall
	end

Route84_EventScript_TurnPlayerAway2::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	applymovement LOCALID_GRUNT, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_FaceDown
	waitmovement 0
	releaseall
	end

Route84_EventScript_TurnPlayerAway3::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	applymovement LOCALID_GRUNT, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_FaceDown
	waitmovement 0
	releaseall
	end

Route84_Text_TollRoad:
	.string "Halt! This here's a toll road.\p"
	.string "It's ¥1,000 to cross.\p"
	.string "Now pay up.$"

Route84_Text_NotEnoughMoney:
	.string "You idiot, you don't have enough money.$"

Route84_Text_CantPay:
	.string "Can't pay? Then get lost.$"

Route84_Text_PaidOutrageousToll:
	.string "{PLAYER} paid the outrageous ¥1,000.$"

Route84_Text_YoureGullible:
	.string "...\p"
	.string "Wow, you're pretty gullible, kid.\p"
	.string "You really thought I was gonna let you\n"
	.string "through here, huh?\p"
	.string "No refunds, get lost!$"

Route84_EventScript_GruntBattle::
	lockall
	applymovement LOCALID_GRUNT, Common_Movement_FaceRight
	delay 4
	applymovement LOCALID_GRUNT, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	delay 60
	applymovement LOCALID_GRUNT, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkRight
	waitmovement 0
	@applymovement LOCALID_GRUNT, Common_Movement_Delay32
	@waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox Route84_Text_GruntPreBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_ROUTE_84, Route84_Text_HowdILose
	applymovement LOCALID_GRUNT, Route84_Movement_GruntBackOff
	waitmovement 0
	msgbox Route84_Text_GruntPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkRight
	waitmovement 0	
	applymovement LOCALID_GRUNT, Common_Movement_WalkRight
	waitmovement 0	
	applymovement LOCALID_GRUNT, Common_Movement_WalkRight
	waitmovement 0	
	removeobject LOCALID_GRUNT
	setvar VAR_ROUTE84_STATE, 1
	releaseall
	end

Route84_Movement_GruntBackOff:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

Route84_Text_GruntPreBattle:
	.string "Thought you were being cute trying to\n"
	.string "sneak around me, huh?\p"
	.string "That's it, I'm gonna beat you to a pulp!$"

Route84_Text_HowdILose:
	.string "Huh? How'd I lose?$"

Route84_Text_GruntPostBattle:
	.string "...\p"
	.string "Eh, that POKéMON was weak anyway.\p"
	.string "I'll just ask the commander\n"
	.string "for a better one.\p"
	.string "She should be finished at the\n"
	.string "POWER STATION by now.$"


