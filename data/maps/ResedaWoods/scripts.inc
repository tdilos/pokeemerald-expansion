.set LOCALID_GRUNT, 16
.set LOCALID_CELEBI, 26

ResedaWoods_MapScripts::
	.byte 0

ResedaWoods_EventScript_ResedaShrine::
	lock
	msgbox ResedaWoods_Text_ResedaShrine, MSGBOX_DEFAULT
	goto_if_set FLAG_BATTLED_CELEBI, ResedaWoods_EventScript_DontPlaceGSBall
	checkitem ITEM_GS_BALL
	goto_if_eq VAR_RESULT, TRUE, ResedaWoods_EventScript_PlaceGSBall
	release
	end

ResedaWoods_Text_ResedaShrine:
	.string "It's an old wooden shrine.\p"
	.string "It looks like there's a slot\n"
	.string "for a POKé BALL.$"

ResedaWoods_EventScript_PlaceGSBall::
	msgbox ResedaWoods_Text_PlaceGSBall, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ResedaWoods_EventScript_DontPlaceGSBall
	msgbox ResedaWoods_Text_PlacedGSBall, MSGBOX_DEFAULT
	closemessage
	fadeoutbgm 0
	delay 60
	playse SE_M_CHARGE
	fadescreen FADE_TO_WHITE
	setobjectxyperm LOCALID_CELEBI, 34, 24
	addobject LOCALID_CELEBI
	delay 120
	fadescreen FADE_FROM_WHITE
	@fadeinbgm 0
	delay 40
	call ResedaWoods_EventScript_Celebi
	fadeinbgm 0
	release
	end

ResedaWoods_Text_PlaceGSBall:
	.string "Place the GS BALL inside?$"


ResedaWoods_EventScript_DontPlaceGSBall::
	release
	end

ResedaWoods_Text_PlacedGSBall:
	.string "{PLAYER} inserted the GS BALL.$"

ResedaWoods_EventScript_Celebi::
	@lock
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_CELEBI, 50
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 1, 1, 1, 1, 1, 1
	special BattleSetup_StartLegendaryBattle
	waitstate
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_CELEBI
	setflag FLAG_BATTLED_CELEBI
	fadescreen FADE_FROM_BLACK
	@release
	return




ResedaWoods_EventScript_Pedro::
	trainerbattle_single TRAINER_PEDRO, ResedaWoods_Text_PedroIntro, ResedaWoods_Text_PedroDefeated
	msgbox ResedaWoods_Text_PedroPostBattle, MSGBOX_AUTOCLOSE
	end


ResedaWoods_EventScript_Oliver::
	trainerbattle_single TRAINER_OLIVER, ResedaWoods_Text_OliverIntro, ResedaWoods_Text_OliverDefeated
	msgbox ResedaWoods_Text_OliverPostBattle, MSGBOX_AUTOCLOSE
	end

ResedaWoods_EventScript_Logan::
	trainerbattle_single TRAINER_LOGAN, ResedaWoods_Text_LoganIntro, ResedaWoods_Text_LoganDefeated
	msgbox ResedaWoods_Text_LoganPostBattle, MSGBOX_AUTOCLOSE
	end

ResedaWoods_EventScript_Gordie::
	trainerbattle_single TRAINER_GORDIE, ResedaWoods_Text_GordieIntro, ResedaWoods_Text_GordieDefeated
	msgbox ResedaWoods_Text_GordiePostBattle, MSGBOX_AUTOCLOSE
	end

ResedaWoods_EventScript_Irwin::
	trainerbattle_single TRAINER_IRWIN, ResedaWoods_Text_IrwinIntro, ResedaWoods_Text_IrwinDefeated
	msgbox ResedaWoods_Text_IrwinPostBattle, MSGBOX_AUTOCLOSE
	end

ResedaWoods_EventScript_Austin::
	trainerbattle_single TRAINER_AUSTIN, ResedaWoods_Text_AustinIntro, ResedaWoods_Text_AustinDefeated
	msgbox ResedaWoods_Text_AustinPostBattle, MSGBOX_AUTOCLOSE
	end

ResedaWoods_EventScript_GenesisGrunt::
	lockall
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, ResedaWoods_Movement_CameraPanDown
	waitmovement 0
	delay 50
	msgbox ResedaWoods_Text_LongerThanIThought, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_CAMERA, ResedaWoods_Movement_CameraPanUp
	waitmovement 0
	special RemoveCameraObject
	applymovement LOCALID_GRUNT, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	delay 60
	msgbox ResedaWoods_Text_WhatAreYouLookinAt, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_GRUNT, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkUp
	waitmovement 0
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox ResedaWoods_Text_GruntPreBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_RESEDA_WOODS, ResedaWoods_Text_YouGottaBeKiddingMe
	applymovement LOCALID_GRUNT, ResedaWoods_Movement_GruntBackOff
	msgbox ResedaWoods_Text_GruntPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkDown
	waitmovement 0
	removeobject LOCALID_GRUNT
	setvar VAR_RESEDA_WOODS_STATE, 1
	releaseall
	end

ResedaWoods_Text_LongerThanIThought:
	.string "Man, this forest was bigger\n"
	.string "than I thought.\p"
	.string "How am I gonna catch up to the\n"
	.string "rest of them now?$"

ResedaWoods_Text_WhatAreYouLookinAt:
	.string "Eh? What are you looking at, kid?$"

ResedaWoods_Text_GruntPreBattle:
	.string "Do you even know who you're talking to?\n"
	.string "We're TEAM GENESIS!\l"
	.string "Nobody messes with us!\p"
	.string "You know, between you and this forest,\n"
	.string "I'm feeling pretty mad.\p"
	.string "How's about I take it out on you?$"

ResedaWoods_Text_YouGottaBeKiddingMe:
	.string "You gotta be kidding me.$"


ResedaWoods_Text_GruntPostBattle:
	.string "Just my luck. Getting lost in the woods\n"
	.string "and losing to some stupid kid.\p"
	.string "...\p"
	.string "Eh? Machine part? I don't know anything\n"
	.string "about that.\p"
	.string "Maybe that's what those guys took\n"
	.string "back to the POWER STATION...\p"
	.string "Ah, I said too much!\n"
	.string "I gotta get outta here.\p"
	.string "But I'm warning you, kid.\n"
	.string "Don't mess with TEAM GENESIS!$"

ResedaWoods_Movement_CameraPanDown:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

ResedaWoods_Movement_CameraPanUp:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

ResedaWoods_Movement_GruntBackOff:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end









