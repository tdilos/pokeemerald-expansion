.set LOCALID_JACE, 5
.set LOCALID_ROBIN, 6
.set LOCALID_DRAKE, 3
.set LOCALID_BOAT, 4

Route100_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route100_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route100_OnFrame
	.byte 0

Route100_OnFrame:
	map_script_2 VAR_JACE_STATE, 5, Route100_EventScript_DrakeGoodbye
	.2byte 0

Route100_OnTransition:
	setflag FLAG_LANDMARK_ROUTE_100
	setrespawn HEAL_LOCATION_ROUTE_100
	special GetDifficulty
	goto_if_eq VAR_RESULT, 0, Route100_EventScript_RevealDragonTamer
	setflag FLAG_HIDE_SHORTCUT_NPCS
	end

Route100_EventScript_RevealDragonTamer::
	clearflag FLAG_HIDE_SHORTCUT_NPCS
	end



Route100_EventScript_DragonTamer::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox Route100_Text_FlyToEverGrande, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route100_EventScript_TryToFlyToEverGrande
	hidemoneybox
	msgbox Route100_Text_DontFlyToEverGrande, MSGBOX_DEFAULT
	closemessage
	release
	end

Route100_EventScript_TryToFlyToEverGrande::
	checkmoney 50000
	goto_if_eq VAR_RESULT, FALSE, Route100_EventScript_NotEnoughMoney
	playse SE_SHOP
	removemoney 50000
	updatemoneybox
	msgbox Route100_Text_LetsFly, MSGBOX_DEFAULT
	hidemoneybox
	warpsilent MAP_MT_SHIRO_SUMMIT, 12, 9
	waitstate
	releaseall
	end
	

Route100_EventScript_NotEnoughMoney::
	msgbox Route100_Text_NotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route100_Text_FlyToEverGrande:
	.string "The road to EVER GRANDE CITY is\n"
	.string "long and challenging.\p"
	.string "Luckily for you, I've already\n"
	.string "been there.\p"
	.string "My dragon POKéMON can fly you\n"
	.string "all the way to the POKéMON LEAGUE.\p"
	.string "I only require ¥50,000 for my trouble.\n"
	.string "How about it?$"

Route100_Text_DontFlyToEverGrande:
	.string "Determined to take the long way,\n"
	.string "are you?\p"
	.string "I think that's most admirable.$"

Route100_Text_LetsFly:
	.string "Great! Let's fly!$"

Route100_Text_NotEnoughMoney:
	.string "Hmmm. Nope, a meager pittance\n"
	.string "like that shan't suffice.\p"
	.string "My service is in high demand,\n"
	.string "you know.\p"
	.string "If I settled for any less, I'd be\n"
	.string "giving rides to everyone I meet!$"




Route100_EventScript_MoveJaceAndRobinToBeach:
	@removeobject LOCALID_JACE
	@removeobject LOCALID_ROBIN
	clearflag FLAG_HIDE_JACE
	setobjectxyperm LOCALID_JACE, 75, 32
	setobjectmovementtype LOCALID_JACE, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm LOCALID_ROBIN, 75, 33
	setobjectmovementtype LOCALID_ROBIN, MOVEMENT_TYPE_FACE_LEFT
	addobject LOCALID_JACE
	addobject LOCALID_ROBIN
	return

Route100_EventScript_DrakeGoodbye::
	lockall
	delay 120
	msgbox Route100_Text_DrakeGoodbye, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DRAKE, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	removeobject LOCALID_DRAKE
	setobjectxyperm LOCALID_DRAKE, 0, 0
	addobject LOCALID_DRAKE
	delay 60
	applymovement LOCALID_BOAT, Route100_Movement_BoatExit
	waitmovement 0
	removeobject LOCALID_BOAT
	setrespawn HEAL_LOCATION_ROUTE_100
	setvar VAR_JACE_STATE, 6
	setvar VAR_RANGER_HQ_STATE, 10
	releaseall
	end

Route100_Text_DrakeGoodbye:
	.string "This is as far as I can take you.\p"
	.string "I'm sure you and your POKéMON\n"
	.string "can manage from here.\p"
	.string "It was nice sailing with you, {PLAYER}.\n"
	.string "I'm always eager for adventure,\n"
	.string "even in my old age.\p"
	.string "If ever manage to become the new champion,\n"
	.string "stop by my house in DUN TOWN again.\l"
	.string "I'll have a surprise for you.\p"
	.string "Best of luck, {PLAYER}.\n"
	.string "Give the champion my regards.$"

Route100_Movement_BoatExit:
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	step_end








Route100_EventScript_JaceTrigger1::
	lockall
	call Route100_EventScript_MoveJaceAndRobinToBeach
	msgbox Route100_Text_JaceCallsOutToPlayer, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 60
	applymovement LOCALID_JACE, Route100_Movement_JaceEnter
	waitmovement 0
	applymovement LOCALID_ROBIN, Route100_Movement_RobinEnter
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Route100_Movement_WalkToJace1
	waitmovement 0
	goto Route100_EventScript_JaceEncounter
	end

Route100_EventScript_JaceTrigger2::
	lockall
	call Route100_EventScript_MoveJaceAndRobinToBeach
	msgbox Route100_Text_JaceCallsOutToPlayer, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 60
	applymovement LOCALID_JACE, Route100_Movement_JaceEnter
	waitmovement 0
	applymovement LOCALID_ROBIN, Route100_Movement_RobinEnter
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Route100_Movement_WalkToJace2
	waitmovement 0
	goto Route100_EventScript_JaceEncounter
	end

Route100_EventScript_JaceEncounter::
	delay 60
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox Route100_Text_JacePreBattle, MSGBOX_DEFAULT
	closemessage

	switch VAR_STARTER_MON
	case 0, Route100_EventScript_StartJaceBattleChespin
	case 1, Route100_EventScript_StartJaceBattleTepig
	case 2, Route100_EventScript_StartJaceBattlePopplio
	end

Route100_EventScript_StartJaceBattleChespin::
	trainerbattle_no_intro TRAINER_JACE_ROUTE_100_CHESPIN, Route100_Text_JaceDefeated
	goto Route100_EventScript_JacePostBattle
	end

Route100_EventScript_StartJaceBattleTepig::
	trainerbattle_no_intro TRAINER_JACE_ROUTE_100_TEPIG, Route100_Text_JaceDefeated
	goto Route100_EventScript_JacePostBattle
	end

Route100_EventScript_StartJaceBattlePopplio::
	trainerbattle_no_intro TRAINER_JACE_ROUTE_100_POPPLIO, Route100_Text_JaceDefeated
	goto Route100_EventScript_JacePostBattle
	end

Route100_EventScript_JacePostBattle::
	delay 60
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 30
	msgbox Route100_Text_JacePostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROBIN, Common_Movement_WalkUp
	waitmovement 0
	@applymovement LOCALID_ROBIN, Common_Movement_WalkLeft
	@waitmovement 0
	applymovement LOCALID_ROBIN, Common_Movement_WalkLeft
	waitmovement 0
	delay 30
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox Route100_Text_JacePostBattle2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROBIN, Route100_Movement_RobinExit
	applymovement LOCALID_JACE, Route100_Movement_JaceExit
	waitmovement 0
	removeobject LOCALID_JACE
	removeobject LOCALID_ROBIN
	setflag FLAG_HIDE_JACE
	setvar VAR_JACE_STATE, 7
	releaseall
	end

Route100_Movement_JaceEnter:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route100_Movement_RobinEnter:
	walk_left
	walk_left
	walk_left
	step_end

Route100_Movement_WalkToJace1:
	@walk_right
	walk_right
	step_end

Route100_Movement_WalkToJace2:
	walk_right
	walk_up
	@walk_right
	face_right
	step_end

Route100_Movement_JaceExit:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

Route100_Movement_RobinExit:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

Route100_Text_JaceCallsOutToPlayer:
	.string "????: {PLAYER}!$"

Route100_Text_JacePreBattle:
	.string "JACE: Ha! I knew I'd find you here!\p"
	.string "Think you're ready for the\n"
	.string "POKéMON LEAGUE, huh?\p"
	.string "Well, you've got one more obstacle left!\n"
	.string "And that's me!$"

Route100_Text_JaceDefeated:
	.string "Can't say I expected anything less.$"

Route100_Text_JacePostBattle:
	.string "Guess I'm no match for you anymore.\n"
	.string "You've really become strong, {PLAYER}.\p"
	.string "So what will you do now? Are you gonna\n"
	.string "take on the POKéMON LEAGUE?\p"
	.string "VICTORY ROAD is supposed to be\n"
	.string "really tough to overcome.\p"
	.string "And the ELITE FOUR are even tougher!\p"
	.string "But I'm sure you'll manage\n"
	.string "to pull through.\p"
	@.string "Yeah,\p"
	.string "As for me, I've changed my mind about\n"
	.string "becoming the champion.\p"
	.string "I thought about what NORMAN said to us\n"
	.string "back in MAROON CITY.\p"
	.string "And I've decided I'm gonna stay with\n"
	.string "the POKéMON RANGERS for a while.\p"
	.string "Maybe work my way up the ranks someday.\p"
	.string "\p"
	.string "So anyway.\n"
	.string "Guess I'll see you around, {PLAYER}.\p"
	.string "If you get the chance, you should stop\n"
	.string "by MAROON CITY from time to time.\p"
	.string "Don't forget about us little people!$"

Route100_Text_JacePostBattle2:
	.string "JACE: Haha well, good luck with\n"
	.string "your POKéMON battles, {PLAYER}!$"







