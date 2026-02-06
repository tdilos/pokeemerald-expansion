.set LOCALID_RAYNER, 1
.set LOCALID_MAY, 15

Route79_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route79_OnTransition
	.byte 0

Route79_OnTransition:
	@goto_if_ge VAR_RAYNER_STATE, 1, Route79_EventScript_HideRaynerAndMay
	end


Route79_EventScript_HideRaynerAndMay:
	@setflag FLAG_HIDE_RAYNER
	@setflag FLAG_HIDE_MAY
	@setflag FLAG_BATTLED_RAYNER_ROUTE79
	removeobject LOCALID_RAYNER
	removeobject LOCALID_MAY
	end



Route79_EventScript_RouteSign::
	msgbox Route79_Text_RouteSign, MSGBOX_SIGN
	end

Route79_Text_RouteSign:
	.string "ROUTE 79\p"
	.string "{UP_ARROW} QUARTZ CAVE\n"
	.string "{LEFT_ARROW} COBALT CITY\l"
	.string "{RIGHT_ARROW} XANTHOS CITY$"




Route79_EventScript_Eoin::
	trainerbattle_single TRAINER_EOIN, Route79_Text_EoinIntro, Route79_Text_EoinDefeated
	msgbox Route79_Text_EoinPostBattle, MSGBOX_AUTOCLOSE
	end

Route79_EventScript_Amos::
	trainerbattle_single TRAINER_AMOS, Route79_Text_AmosIntro, Route79_Text_AmosDefeated
	msgbox Route79_Text_AmosPostBattle, MSGBOX_AUTOCLOSE
	end

Route79_EventScript_Layton::
	trainerbattle_single TRAINER_LAYTON, Route79_Text_LaytonIntro, Route79_Text_LaytonDefeated
	msgbox Route79_Text_LaytonPostBattle, MSGBOX_AUTOCLOSE
	end

Route79_EventScript_Marina::
	trainerbattle_single TRAINER_MARINA, Route79_Text_MarinaIntro, Route79_Text_MarinaDefeated
	msgbox Route79_Text_MarinaPostBattle, MSGBOX_AUTOCLOSE
	end

Route79_EventScript_Brittany::
	trainerbattle_single TRAINER_BRITTANY, Route79_Text_BrittanyIntro, Route79_Text_BrittanyDefeated
	msgbox Route79_Text_BrittanyPostBattle, MSGBOX_AUTOCLOSE
	end

Route79_EventScript_Lee::
	trainerbattle_single TRAINER_LEE, Route79_Text_LeeIntro, Route79_Text_LeeDefeated
	msgbox Route79_Text_LeePostBattle, MSGBOX_AUTOCLOSE
	end

Route79_EventScript_Delmus::
	trainerbattle_single TRAINER_DELMUS, Route79_Text_DelmusIntro, Route79_Text_DelmusDefeated
	msgbox Route79_Text_DelmusPostBattle, MSGBOX_AUTOCLOSE
	end

Route79_EventScript_Geddy::
	trainerbattle_single TRAINER_GEDDY, Route79_Text_GeddyIntro, Route79_Text_GeddyDefeated
	msgbox Route79_Text_GeddyPostBattle, MSGBOX_AUTOCLOSE
	end





Route79_EventScript_OldRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_OLD_ROD, Route79_EventScript_HowsFishing
	msgbox Route79_Text_LikeToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route79_EventScript_GiveOldRod
	goto_if_eq VAR_RESULT, NO, Route79_EventScript_NoLikeToFish
	end

Route79_EventScript_GiveOldRod::
	msgbox Route79_Text_GiveYouOneOfMyRods, MSGBOX_DEFAULT
	giveitem ITEM_OLD_ROD
	setflag FLAG_RECEIVED_OLD_ROD
	msgbox Route79_Text_ExplainOldRod, MSGBOX_DEFAULT
	release
	end

Route79_EventScript_NoLikeToFish::
	msgbox Route79_Text_ThatsTooBad, MSGBOX_DEFAULT
	release
	end

Route79_EventScript_HowsFishing::
	msgbox Route79_Text_HowsFishing, MSGBOX_DEFAULT
	release
	end

Route79_Text_HowsFishing:
	.string "How's fishing, kid?$"

Route79_Text_LikeToFish:
	.string "Hey, kid. Do you like to fish?$"

Route79_Text_ThatsTooBad:
	.string "Ah, too bad.$"

Route79_Text_GiveYouOneOfMyRods:
	.string "Ha, I knew it! Why don't you take one\n"
	.string "of my rods.$"

Route79_Text_ExplainOldRod:
	.string "To use that Old Rod, just stand next to\n"
	.string "water and use it from your BAG.$"

Route79_EventScript_TrainerTipsRegisterItems::
	msgbox Route79_Text_TrainerTipsRegisterItems, MSGBOX_SIGN
	end

Route79_Text_TrainerTipsRegisterItems:
	.string "TRAINER TIPS\p"
	.string "Register up to 3 KEY ITEMS to\n"
	.string "use in the field.\p"
	.string "A registered item can be used by\n"
	.string "pressing SELECT, L, or R.$"





Route79_EventScript_RaynerTrigger1::
	lockall
	setvar VAR_XANTHOS_CITY_STATE, 1
	applymovement LOCALID_RAYNER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	@applymovement LOCALID_RAYNER, Common_Movement_Delay48
	@waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_FaceUp
	waitmovement 0
	delay 60
	applymovement LOCALID_RAYNER, Route79_Movement_WalkToTrigger1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0

	msgbox Route79_Text_RaynerIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro_no_whiteout TRAINER_RAYNER_ROUTE_79, Route79_Text_RaynerDefeated
	special CheckIfTeamFainted
	call_if_eq VAR_RESULT, FALSE, Route79_EventScript_WonRaynerBattle
	call_if_eq VAR_RESULT, TRUE, Route79_EventScript_LostRaynerBattle
	
	applymovement OBJ_EVENT_ID_PLAYER, Route79_Movement_PlayerBackOff1
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_WalkRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0

	applymovement LOCALID_RAYNER, Route79_Movement_RaynerExit
	waitmovement 0

	@applymovement LOCALID_RAYNER, Common_Movement_WalkRight
	@waitmovement 0
	@applymovement LOCALID_RAYNER, Common_Movement_WalkRight
	@waitmovement 0
	@applymovement LOCALID_RAYNER, Common_Movement_WalkRight
	@waitmovement 0
	@applymovement LOCALID_RAYNER, Common_Movement_WalkRight
	@waitmovement 0
	@applymovement LOCALID_RAYNER, Common_Movement_WalkRight
	@waitmovement 0
	@applymovement LOCALID_RAYNER, Common_Movement_WalkRight
	@waitmovement 0
	@removeobject LOCALID_RAYNER
	
	delay 60
	msgbox Route79_Text_MayCallsPlayer, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 24
	@special SpawnCameraObject
	@applymovement OBJ_EVENT_ID_CAMERA, Route79_Movement_CameraPanDown1
	@waitmovement 0
	applymovement LOCALID_MAY, Route79_Movement_MayWalkToPlayer2
	waitmovement 0
	goto Route79_EventScript_MeetMay
	end
	
Route79_EventScript_RaynerTrigger2::
	lockall
	setvar VAR_XANTHOS_CITY_STATE, 1
	applymovement LOCALID_RAYNER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	@applymovement LOCALID_RAYNER, Common_Movement_Delay48
	@waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_FaceRight
	waitmovement 0
	delay 60
	applymovement LOCALID_RAYNER, Route79_Movement_WalkToTrigger2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0

	msgbox Route79_Text_RaynerIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro_no_whiteout TRAINER_RAYNER_ROUTE_79, Route79_Text_RaynerDefeated
	special CheckIfTeamFainted
	call_if_eq VAR_RESULT, FALSE, Route79_EventScript_WonRaynerBattle
	call_if_eq VAR_RESULT, TRUE, Route79_EventScript_LostRaynerBattle
	
	applymovement OBJ_EVENT_ID_PLAYER, Route79_Movement_PlayerBackOff2
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_WalkRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0

	applymovement LOCALID_RAYNER, Route79_Movement_RaynerExit
	waitmovement 0

	@applymovement LOCALID_RAYNER, Common_Movement_WalkRight
	@waitmovement 0
	@applymovement LOCALID_RAYNER, Common_Movement_WalkRight
	@waitmovement 0
	@applymovement LOCALID_RAYNER, Common_Movement_WalkRight
	@waitmovement 0
	@applymovement LOCALID_RAYNER, Common_Movement_WalkRight
	@waitmovement 0
	@applymovement LOCALID_RAYNER, Common_Movement_WalkRight
	@waitmovement 0
	@applymovement LOCALID_RAYNER, Common_Movement_WalkRight
	@waitmovement 0
	@applymovement LOCALID_RAYNER, Common_Movement_WalkRight
	@waitmovement 0
	@applymovement LOCALID_RAYNER, Common_Movement_WalkRight
	@waitmovement 0
	@removeobject LOCALID_RAYNER
	
	@delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	msgbox Route79_Text_MayCallsPlayer, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	@delay 24
	@special SpawnCameraObject
	@applymovement OBJ_EVENT_ID_CAMERA, Route79_Movement_CameraPanDown2
	@waitmovement 0
	applymovement LOCALID_MAY, Route79_Movement_MayWalkToPlayer2
	waitmovement 0
	goto Route79_EventScript_MeetMay
	end

Route79_EventScript_RaynerTrigger3::
	lockall
	setvar VAR_XANTHOS_CITY_STATE, 1
	applymovement LOCALID_RAYNER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	@applymovement LOCALID_RAYNER, Common_Movement_Delay48
	@waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_FaceDown
	waitmovement 0
	delay 60
	applymovement LOCALID_RAYNER, Route79_Movement_WalkToTrigger3
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0

	msgbox Route79_Text_RaynerIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro_no_whiteout TRAINER_RAYNER_ROUTE_79, Route79_Text_RaynerDefeated
	special CheckIfTeamFainted
	call_if_eq VAR_RESULT, FALSE, Route79_EventScript_WonRaynerBattle
	call_if_eq VAR_RESULT, TRUE, Route79_EventScript_LostRaynerBattle
	
	applymovement OBJ_EVENT_ID_PLAYER, Route79_Movement_PlayerBackOff2
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_WalkRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0

	applymovement LOCALID_RAYNER, Route79_Movement_RaynerExit
	waitmovement 0

	@applymovement LOCALID_RAYNER, Common_Movement_WalkRight
	@waitmovement 0
	@applymovement LOCALID_RAYNER, Common_Movement_WalkRight
	@waitmovement 0
	@applymovement LOCALID_RAYNER, Common_Movement_WalkRight
	@waitmovement 0
	@applymovement LOCALID_RAYNER, Common_Movement_WalkRight
	@waitmovement 0
	@applymovement LOCALID_RAYNER, Common_Movement_WalkRight
	@waitmovement 0
	@applymovement LOCALID_RAYNER, Common_Movement_WalkRight
	@waitmovement 0
	@applymovement LOCALID_RAYNER, Common_Movement_WalkRight
	@waitmovement 0
	@applymovement LOCALID_RAYNER, Common_Movement_WalkRight
	@waitmovement 0
	@removeobject LOCALID_RAYNER
	@setvar VAR_XANTHOS_CITY_STATE, 1
	
	@delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	msgbox Route79_Text_MayCallsPlayer, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	@delay 24
	@special SpawnCameraObject
	@applymovement OBJ_EVENT_ID_CAMERA, Route79_Movement_CameraPanDown3
	@waitmovement 0
	applymovement LOCALID_MAY, Route79_Movement_MayWalkToPlayer3
	waitmovement 0
	goto Route79_EventScript_MeetMay
	releaseall
	end

Route79_Movement_WalkToTrigger1:
	@walk_right
	@walk_right
	walk_up
	face_right
	step_end

Route79_Movement_WalkToTrigger2:
	@walk_right
	@walk_right
	step_end

Route79_Movement_WalkToTrigger3:
	@walk_right
	@walk_right
	walk_down
	face_right
	step_end

Route79_Text_RaynerIntro:
	.string "Hey, you! Let's battle!$"


Route79_EventScript_WonRaynerBattle::
	msgbox Route79_Text_WonVsRayner, MSGBOX_DEFAULT
	closemessage
	return

Route79_EventScript_LostRaynerBattle::
	msgbox Route79_Text_LostVsRayner, MSGBOX_DEFAULT
	closemessage
	return

Route79_Text_RaynerDefeated:
	.string "Hehe.$"

Route79_Text_WonVsRayner:
	.string "You seem like someone who really\n"
	.string "wants to win.\p"
	.string "Who knows, maybe we'll meet\n"
	.string "again some day.$" 

Route79_Text_LostVsRayner:
	.string "...\p"
	.string "How boring.\p"
	.string "I'm not interested in weak trainers.$"

Route79_Movement_PlayerBackOff1:
	face_up
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

Route79_Movement_PlayerBackOff2:
	face_down
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end




Route79_Text_MayCallsPlayer:
	.string "???: {PLAYER}!$"

Route79_Movement_CameraPanDown1:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route79_Movement_CameraPanDown2:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route79_Movement_CameraPanDown3:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
	
Route79_EventScript_MeetMay::
	@fadescreen FADE_TO_BLACK
	@setobjectxyperm OBJ_EVENT_ID_CAMERA, 72, 12
	@setobjectxyperm LOCALID_MAY, 71, 12
	@setobjectxyperm OBJ_EVENT_ID_PLAYER, 72, 12
	@applymovement LOCALID_MAY, Common_Movement_FaceRight
	@applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	@waitmovement 0
	@special RemoveCameraObject
	@fadescreen FADE_FROM_BLACK
	@delay 40
	applymovement LOCALID_MAY, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAY, Common_Movement_WalkInPlaceUp
	waitmovement 0
	@applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	@waitmovement 0
	msgbox Route79_Text_MeetMay, MSGBOX_DEFAULT
	giveitem ITEM_SHINY_CHARM
	msgbox Route79_Text_ExplainShinyCharm, MSGBOX_DEFAULT
	closemessage
	@setflag FLAG_HIDE_ROUTE_79_RAYNER_MAY
	@setflag FLAG_HIDE_MAY
	removeobject LOCALID_RAYNER
	removeobject LOCALID_MAY
	special HealPlayerParty
	warp MAP_XANTHOS_CITY_MAYS_HOUSE, 9, 4
	playse SE_EXIT
	@setflag FLAG_HIDE_ROUTE_79_RAYNER_MAY
	setvar VAR_RAYNER_STATE, 1
	setflag FLAG_BATTLED_RAYNER_ROUTE79
	waitstate
	releaseall
	end

Route79_Text_MeetMay:
	.string "MAY: I thought I recognized you. Who was\n"
	.string "that you were battling just now?\p"
	.string "...\p"
	.string "Oh, no matter.\n"
	.string "Hey, guess what?\p"
	.string "My father, PROF. BIRCH, stopped by here\n"
	.string "recently.\p"
	.string "When I told him about you and JACE,\n"
	.string "he wanted me to give you this.$"

Route79_Text_ExplainShinyCharm:
	.string "Sometimes you'll meet POKéMON that are\n"
	.string "differently colored than usual.\p"
	.string "That SHINY CHARM makes them more\n"
	.string "likely to appear.\n"
	.string "It should make your POKéDEX quest\n"
	.string "more interesting.\p"
	.string "By the way, how is that POKéMON that\n"
	.string "I gave you?\p"
	.string "...\p"
	.string "Oh, your POKéMON are hurt.\p"
	.string "Let's take them back to my house\n"
	.string "and fix them up there.$"

Route79_Movement_RaynerExit:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route79_Movement_MayWalkToPlayer2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route79_Movement_MayWalkToPlayer3:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
