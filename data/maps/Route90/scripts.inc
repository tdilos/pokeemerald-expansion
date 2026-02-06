.set LOCALID_BETTERMAN, 18
.set LOCALID_GRUNT1, 17
.set LOCALID_GRUNT2, 16

Route90_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route90_OnFrame
	.byte 0

Route90_OnFrame:
	map_script_2 VAR_PITCHBLAK_CITY_STATE, 9, Route90_EventScript_GenesisEncounterCont
	.2byte 0








Route90_EventScript_DarkraiDoor::
	msgbox Route90_Text_LockedDoor, MSGBOX_SIGN
	end

Route90_Text_LockedDoor:
	.string "The door appears to be locked.$"

Route90_EventScript_Kaisuke::
	trainerbattle_single TRAINER_KAISUKE, Route90_Text_KaisukeIntro, Route90_Text_KaisukeDefeated
	msgbox Route90_Text_KaisukePostBattle, MSGBOX_AUTOCLOSE
	end

Route90_EventScript_Kazuki::
	trainerbattle_single TRAINER_KAZUKI, Route90_Text_KazukiIntro, Route90_Text_KazukiDefeated
	msgbox Route90_Text_KazukiPostBattle, MSGBOX_AUTOCLOSE
	end

Route90_EventScript_Eunice::
	trainerbattle_single TRAINER_EUNICE, Route90_Text_EuniceIntro, Route90_Text_EuniceDefeated
	msgbox Route90_Text_EunicePostBattle, MSGBOX_AUTOCLOSE
	end

Route90_EventScript_Nedry::
	trainerbattle_single TRAINER_NEDRY, Route90_Text_NedryIntro, Route90_Text_NedryDefeated
	msgbox Route90_Text_NedryPostBattle, MSGBOX_AUTOCLOSE
	end

Route90_EventScript_Reese::
	trainerbattle_single TRAINER_REESE, Route90_Text_ReeseIntro, Route90_Text_ReeseDefeated
	msgbox Route90_Text_ReesePostBattle, MSGBOX_AUTOCLOSE
	end

Route90_EventScript_Dave::
	trainerbattle_single TRAINER_DAVE, Route90_Text_DaveIntro, Route90_Text_DaveDefeated
	msgbox Route90_Text_DavePostBattle, MSGBOX_AUTOCLOSE
	end

Route90_EventScript_Biff::
	trainerbattle_single TRAINER_BIFF, Route90_Text_BiffIntro, Route90_Text_BiffDefeated
	msgbox Route90_Text_BiffPostBattle, MSGBOX_AUTOCLOSE
	end

Route90_EventScript_Blayne::
	trainerbattle_single TRAINER_BLAYNE, Route90_Text_BlayneIntro, Route90_Text_BlayneDefeated
	msgbox Route90_Text_BlaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route90_EventScript_Corbin::
	trainerbattle_single TRAINER_CORBIN, Route90_Text_CorbinIntro, Route90_Text_CorbinDefeated
	msgbox Route90_Text_CorbinPostBattle, MSGBOX_AUTOCLOSE
	end




Route90_EventScript_GenesisEncounter1::
	lockall
	@special ForceReloadMap
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	goto Route90_EventScript_GenesisEncounter
	end

Route90_EventScript_GenesisEncounter2::
	lockall
	@special ForceReloadMap
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	goto Route90_EventScript_GenesisEncounter
	end

Route90_EventScript_GenesisEncounter3::
	lockall
	@addobject LOCALID_BETTERMAN
	@addobject LOCALID_GRUNT1
	@addobject LOCALID_GRUNT2
	@special ForceReloadMap
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	goto Route90_EventScript_GenesisEncounter
	end

Route90_EventScript_GenesisEncounter::
	setvar VAR_PITCHBLAK_CITY_STATE, 9
	@warpsilent MAP_ROUTE90, 10, 5
	@waitstate
	special ForceReloadMap
	end

Route90_EventScript_GenesisEncounterCont::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	fadeoutbgm 0
	delay 40
	playbgm MUS_ENCOUNTER_MAGMA, TRUE
	msgbox Route90_Text_AlrightDoc, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BETTERMAN, Common_Movement_FaceLeft
	waitmovement 0
	delay 10
	applymovement LOCALID_BETTERMAN, Common_Movement_FaceRight
	waitmovement 0
	delay 10
	applymovement LOCALID_BETTERMAN, Common_Movement_FaceLeft
	waitmovement 0
	delay 10
	applymovement LOCALID_BETTERMAN, Common_Movement_FaceRight
	waitmovement 0
	delay 10
	applymovement LOCALID_BETTERMAN, Common_Movement_FaceLeft
	waitmovement 0
	delay 10
	applymovement LOCALID_BETTERMAN, Common_Movement_FaceRight
	waitmovement 0
	delay 10
	msgbox Route90_Text_SomebodyHelp, MSGBOX_DEFAULT
	closemessage
	delay 20
	playse SE_PIN
	applymovement LOCALID_BETTERMAN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_BETTERMAN, Common_Movement_FaceDown
	waitmovement 0
	delay 40
	applymovement LOCALID_BETTERMAN, Route90_Movement_HideBehindPlayer
	applymovement LOCALID_GRUNT1, Common_Movement_FaceDown
	applymovement LOCALID_GRUNT2, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	applymovement LOCALID_GRUNT1, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_GRUNT1, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_GRUNT1, Common_Movement_WalkDown
	waitmovement 0
	msgbox Route90_Text_Grunt1PreBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_1_ROUTE_90, Route90_Text_Grunt1Defeated
	applymovement LOCALID_GRUNT1, Route90_Movement_Grunt1BackOff
	waitmovement 0
	delay 60
	applymovement LOCALID_GRUNT2, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_GRUNT2, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_GRUNT2, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_GRUNT2, Common_Movement_FaceDown
	waitmovement 0
	msgbox Route90_Text_Grunt2PreBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_2_ROUTE_90, Route90_Text_Grunt2Defeated
	applymovement LOCALID_GRUNT2, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox Route90_Text_YoullRegretThis, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT1, Common_Movement_WalkUp
	applymovement LOCALID_GRUNT2, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_GRUNT1, Common_Movement_WalkUp
	applymovement LOCALID_GRUNT2, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_GRUNT1, Common_Movement_WalkUp
	applymovement LOCALID_GRUNT2, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_GRUNT1, Common_Movement_WalkUp
	applymovement LOCALID_GRUNT2, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_GRUNT1, Common_Movement_WalkUp
	applymovement LOCALID_GRUNT2, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_GRUNT1, Common_Movement_WalkUp
	applymovement LOCALID_GRUNT2, Common_Movement_WalkUp
	waitmovement 0
	removeobject LOCALID_GRUNT1
	removeobject LOCALID_GRUNT2
	fadedefaultbgm
	delay 30
	applymovement LOCALID_BETTERMAN, Common_Movement_WalkInPlaceUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0	
	msgbox Route90_Text_ThanksForSavingMe, MSGBOX_DEFAULT
	closemessage
	delay 20
	playse SE_PIN
	applymovement LOCALID_BETTERMAN, Common_Movement_ExclamationMark
	waitmovement 0
	delay 40
	msgbox Route90_Text_ThankYouGoodbye, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BETTERMAN, Route90_Movement_BettermanRunsOff
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	delay 30
	removeobject LOCALID_BETTERMAN
	setvar VAR_PITCHBLAK_CITY_STATE, 1
	setflag FLAG_DEFEATED_GRUNTS_ROUTE_90
	releaseall
	end

Route90_Movement_HideBehindPlayer:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	face_up
	step_end

Route90_Movement_Grunt1BackOff:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

Route90_Movement_BettermanRunsOff:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route90_Text_AlrightDoc:
	.string "End of the line, doc.\n"
	.string "You're not getting away this time.$"

Route90_Text_SomebodyHelp:
	.string "Oh dear...\p"
	.string "Someone! Anyone!\n"
	.string "HEEEELP!$"

Route90_Text_Grunt1PreBattle:
	.string "Stay out of this, kid.\p"
	.string "You wouldn't want to get hurt\n"
	.string "now, would ya?$"

Route90_Text_Grunt1Defeated:
	.string "Wait. What just happened?$"

Route90_Text_Grunt2PreBattle:
	.string "You think you're tough, huh?\p"
	.string "My POKéMON will show you what\n"
	.string "real strength looks like!$"

Route90_Text_Grunt2Defeated:
	.string "Crap. That was my last POKéMON.$"

Route90_Text_YoullRegretThis:
	.string "Grrrrr...\n"
	.string "Just you wait, kid!\p"
	.string "You'll regret meddling with\n"
	.string "TEAM GENESIS!\p"
	.string "Come on, let's go regroup\n"
	.string "with the others.$"

Route90_Text_ThanksForSavingMe:
	.string "Oh thank heavens you came along.\n"
	.string "Who knows what they would do to me.\p"
	.string "Allow me to introduce myself.\n"
	.string "My name is DR. BETTERMAN.\p"
	.string "I'm a scientist at KENDOM CORP.\p"
	.string "You're a POKéMON trainer, yes?\p"
	.string "Those TEAM GENESIS scoundrels jumped me\n"
	.string "out of nowhere.\p"
	.string "I managed to shake them off a few times,\n"
	.string "but they chased me all the way out here.\p"
	.string "And there are more of them in the city.\n"
	.string "What could they all be doing here?\p"
	.string "They did say something about taking\n"
	.string "a closer look at my work....\p"
	.string "Could they mean...$"

Route90_Text_ThankYouGoodbye:
	.string "Oh dear! Something very urgent has come\n"
	.string "to my attention!\p"
	.string "I apologize for cutting this short, but\n"
	.string "I really must be going.\p"
	.string "Thank you and goodbye!$"









