.set LOCALID_MYRTLE, 4
.set LOCALID_MYRTLEFRIEND, 5

CobaltCity_DreamResort_3F_Rooms_MapScripts::
	.byte 0

DreamResort_EventScript_Celine::
	trainerbattle_single TRAINER_CELINE, DreamResort_Text_CelineIntro, DreamResort_Text_CelineDefeated
	msgbox DreamResort_Text_CelinePostBattle, MSGBOX_AUTOCLOSE
	end

DreamResort_EventScript_Jean::
	trainerbattle_single TRAINER_JEAN, DreamResort_Text_JeanIntro, DreamResort_Text_JeanDefeated
	msgbox DreamResort_Text_JeanPostBattle, MSGBOX_AUTOCLOSE
	end

DreamResort_EventScript_Elaine::
	trainerbattle_single TRAINER_ELAINE, DreamResort_Text_ElaineIntro, DreamResort_Text_ElaineDefeated
	msgbox DreamResort_Text_ElainePostBattle, MSGBOX_AUTOCLOSE
	end

DreamResort_EventScript_FoundMyrtle1::
	lockall
	delay 10
	playse SE_PIN
	applymovement LOCALID_MYRTLE, Common_Movement_FaceDown
	applymovement LOCALID_MYRTLEFRIEND, Common_Movement_FaceDown
	waitmovement 0
	applymovement LOCALID_MYRTLE, Common_Movement_ExclamationMark
	applymovement LOCALID_MYRTLEFRIEND, Common_Movement_ExclamationMark
	waitmovement 0
	delay 30
	applymovement LOCALID_MYRTLE, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_MYRTLE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_MYRTLE, Common_Movement_FaceDown
	waitmovement 0
	msgbox CobaltCity_DreamResort_Text_MeetMyrtle, MSGBOX_NPC
	closemessage
	applymovement LOCALID_MYRTLE, Common_Movement_FaceUp
	delay 40
	applymovement LOCALID_MYRTLE, Common_Movement_FaceDown
	delay 40
	msgbox CobaltCity_DreamResort_Text_CatchingUp, MSGBOX_NPC
	closemessage
	delay 40
	applymovement LOCALID_MYRTLE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_MYRTLE, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_MYRTLE, Common_Movement_WalkDown
	waitmovement 0
	removeobject LOCALID_MYRTLE
	setflag FLAG_FOUND_MYRTLE
	setvar VAR_COBALT_CITY_STATE, 1
	playse SE_EXIT
	releaseall
	end

DreamResort_EventScript_FoundMyrtle2::
	lockall
	delay 10
	playse SE_PIN
	applymovement LOCALID_MYRTLE, Common_Movement_FaceDown
	applymovement LOCALID_MYRTLEFRIEND, Common_Movement_FaceDown
	waitmovement 0
	applymovement LOCALID_MYRTLE, Common_Movement_ExclamationMark
	applymovement LOCALID_MYRTLEFRIEND, Common_Movement_ExclamationMark
	waitmovement 0
	delay 30
	applymovement LOCALID_MYRTLE, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_MYRTLE, Common_Movement_WalkDown
	waitmovement 0
	msgbox CobaltCity_DreamResort_Text_MeetMyrtle, MSGBOX_NPC
	closemessage
	applymovement LOCALID_MYRTLE, Common_Movement_FaceUp
	delay 40
	applymovement LOCALID_MYRTLE, Common_Movement_FaceDown
	delay 40
	msgbox CobaltCity_DreamResort_Text_CatchingUp, MSGBOX_NPC
	closemessage
	delay 40
	applymovement LOCALID_MYRTLE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_MYRTLE, Common_Movement_WalkDown
	waitmovement 0
	removeobject LOCALID_MYRTLE
	setflag FLAG_FOUND_MYRTLE
	setvar VAR_COBALT_CITY_STATE, 1
	playse SE_EXIT
	releaseall
	end

DreamResort_EventScript_FoundMyrtle3::
	lockall
	delay 10
	playse SE_PIN
	applymovement LOCALID_MYRTLE, Common_Movement_FaceDown
	applymovement LOCALID_MYRTLEFRIEND, Common_Movement_FaceDown
	waitmovement 0
	applymovement LOCALID_MYRTLE, Common_Movement_ExclamationMark
	applymovement LOCALID_MYRTLEFRIEND, Common_Movement_ExclamationMark
	waitmovement 0
	delay 30
	applymovement LOCALID_MYRTLE, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_MYRTLE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_MYRTLE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_MYRTLE, Common_Movement_WalkDown
	waitmovement 0
	msgbox CobaltCity_DreamResort_Text_MeetMyrtle, MSGBOX_NPC
	closemessage
	applymovement LOCALID_MYRTLE, Common_Movement_FaceUp
	delay 40
	applymovement LOCALID_MYRTLE, Common_Movement_FaceDown
	delay 40
	msgbox CobaltCity_DreamResort_Text_CatchingUp, MSGBOX_NPC
	closemessage
	delay 40
	applymovement LOCALID_MYRTLE, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_MYRTLE, Common_Movement_WalkDown
	waitmovement 0
	removeobject LOCALID_MYRTLE
	setflag FLAG_FOUND_MYRTLE
	setvar VAR_COBALT_CITY_STATE, 1
	playse SE_EXIT
	releaseall
	end

CobaltCity_DreamResort_Text_MeetMyrtle:
	.string "...\p"
	.string "Oh, you're looking for the gym leader?\p"
	.string "That would be me. My name is MYRTLE.\n"
	.string "And you're...\l"
	.string "...\p"
	.string "{PLAYER}, I see.\n"
	.string "What a lovely name.$"

CobaltCity_DreamResort_Text_CatchingUp:
	.string "I was just catching up with an\n"
	.string "old friend here.\p"
	.string "But I needed to be going soon anyway.\p"
	.string "If you're looking for a battle, come by\n"
	.string "the gym later.\p"
	.string "Farewell then.$"


DreamResort_EventScript_MyrtleFriend::
	msgbox CobaltCity_DreamResort_Text_MyrtleFriend, MSGBOX_NPC
	end

CobaltCity_DreamResort_Text_MyrtleFriend:
	.string "MYRTLE has traveled and met people all\n"
	.string "around the world.\p"
	.string "But nowadays, she prefers to stay here\n"
	.string "in COBALT CITY to focus on her gym.$"
