@.set LOCALID_PLATFORM, 5

ResedaTown_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ResedaTown_Gym_OnTransition
	.byte 0




ResedaTown_Gym_OnTransition:
	@removeobject LOCALID_PLATFORM
	end



ResedaTown_Gym_EventScript_Arthur::
	trainerbattle_single TRAINER_ARTHUR_1, ResedaTown_Gym_Text_ArthurIntro, ResedaTown_Gym_Text_ArthurDefeated, ResedaTown_Gym_EventScript_ArthurPostBattle, NO_MUSIC
	@specialvar VAR_RESULT, ShouldTryRematchBattle
	@goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_RoxanneRematch
	goto_if_unset FLAG_DEFEATED_RESEDA_GYM, ResedaTown_Gym_EventScript_GiveInfestation
	msgbox ResedaTown_Gym_Text_ArthurPostBattle, MSGBOX_DEFAULT
	release
	end

ResedaTown_Gym_EventScript_ArthurPostBattle::
	message ResedaTown_Gym_Text_ReceivedMandibleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special GetDifficulty
	switch VAR_RESULT
	case 0, ResedaTown_Gym_EventScript_EventScript_ExplainBadgeNormal
	case 1, ResedaTown_Gym_EventScript_EventScript_ExplainBadgeHardcore
	case 2, ResedaTown_Gym_EventScript_EventScript_ExplainBadgeInsane
	end

ResedaTown_Gym_EventScript_EventScript_ExplainBadgeNormal::
	msgbox ResedaTown_Gym_Text_MandibleBadgeNormalInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_BADGE01_GET
	setvar VAR_0x8008, 9
	call Common_EventScript_SetGymTrainers
	goto ResedaTown_Gym_EventScript_GiveInfestation
	end

ResedaTown_Gym_EventScript_EventScript_ExplainBadgeHardcore::
	msgbox ResedaTown_Gym_Text_MandibleBadgeHardcoreInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_BADGE01_GET
	setvar VAR_0x8008, 9
	call Common_EventScript_SetGymTrainers
	goto ResedaTown_Gym_EventScript_GiveInfestation
	end

ResedaTown_Gym_EventScript_EventScript_ExplainBadgeInsane::
	msgbox ResedaTown_Gym_Text_MandibleBadgeInsaneInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_BADGE01_GET
	setvar VAR_0x8008, 9
	call Common_EventScript_SetGymTrainers
	goto ResedaTown_Gym_EventScript_GiveInfestation
	end

ResedaTown_Gym_EventScript_GiveInfestation::
	giveitem ITEM_TM96
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DEFEATED_RESEDA_GYM
	@setflag FLAG_RECEIVED_TM39
	msgbox ResedaTown_Gym_Text_ExplainInfestation, MSGBOX_DEFAULT
	release
	end

ResedaTown_Gym_Text_ArthurIntro:
	.string "Hey there, trainer. I'm ARTHUR,\n"
	.string "the RESEDA POKéMON GYM LEADER.\p"
	.string "I'm also the ISSHO region's\n"
	.string "foremost BUG collector.\p"
	.string "I know everything when it comes\n"
	.string "to BUG type POKéMON.\p"
	.string "Bugs are full of surprises,\n"
	.string "as you'll soon find out!{PAUSE_MUSIC}{PLAY_BGM MUS_RG_ENCOUNTER_GYM_LEADER}$"

ResedaTown_Gym_Text_ArthurDefeated:
	.string "Ahahaha! That battle was amazing!\p"
	.string "You and your POKéMON worked hard\n"
	.string "to earn this badge.\p"
	.string "Take it! It's the official POKéMON\n"
	.string "LEAGUE MANDIBLE BADGE.$"

ResedaTown_Gym_Text_ReceivedMandibleBadge:
	.string "{PLAYER} received the MANDIBLE BADGE\n"
	.string "from ARTHUR.$"

ResedaTown_Gym_Text_MandibleBadgeNormalInfoTakeThis:
	.string "The MANDIBLE BADGE makes all POKéMON\n"
	.string "up to Level 24, even those you get in\l"
	.string "trades, obey without question.\p"
	.string "It also enables them to use the HM move\n"
	.string "CUT outside of battle.\p"
	.string "And you can have this too.$"

ResedaTown_Gym_Text_MandibleBadgeHardcoreInfoTakeThis:
	.string "The MANDIBLE BADGE makes all POKéMON\n"
	.string "up to Level 22, even those you get in\l"
	.string "trades, obey without question.\p"
	.string "It also enables them to use the HM move\n"
	.string "CUT outside of battle.\p"
	.string "And you can have this too.$"

ResedaTown_Gym_Text_MandibleBadgeInsaneInfoTakeThis:
	.string "The MANDIBLE BADGE makes all POKéMON\n"
	.string "up to Level 21, even those you get in\l"
	.string "trades, obey without question.\p"
	.string "It also enables them to use the HM move\n"
	.string "CUT outside of battle.\p"
	.string "And you can have this too.$"

ResedaTown_Gym_Text_ExplainInfestation:
	.string "That TECHNICAL MACHINE, TM96,\n"
	.string "contains INFESTATION.\p"
	.string "It traps the enemy and inflicts damage\n"
	.string "every turn.\p"
	.string "If you use a TM, it instantly teaches\n"
	.string "the move to a POKéMON.\p"
	.string "And one TM can be used to teach as many\n"
	.string "POKéMON as you want.\p"
	.string "Now then. Will you continue your\n"
	.string "gym challenge?\p"
	.string "In that case, I'd recommend heading to\n"
	.string "AMBER CITY next.$"

ResedaTown_Gym_Text_ArthurPostBattle:
	.string "If you want to get stronger, you should\n"
	.string "challenge other GYM LEADERS.\p"
	.string "By battling many TRAINERS, you can\n"
	.string "learn many things.$"




ResedaTown_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RESEDA_GYM, ResedaTown_Gym_EventScript_GymGuidePostVictory
	msgbox ResedaTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	goto_if_eq VAR_RESEDA_GYM_GUIDE, 0, ResedaTown_Gym_EventScript_GiveFreshWater
	release
	end

ResedaTown_Gym_EventScript_GiveFreshWater::
	giveitem ITEM_FRESH_WATER
	setvar VAR_RESEDA_GYM_GUIDE, 1
	release
	end

ResedaTown_Gym_EventScript_GymGuidePostVictory::
	msgbox ResedaTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	goto_if_le VAR_RESEDA_GYM_GUIDE, 1, ResedaTown_Gym_EventScript_GiveBugGem
	release
	end

ResedaTown_Gym_EventScript_GiveBugGem::
	giveitem ITEM_BUG_GEM
	setvar VAR_RESEDA_GYM_GUIDE, 2
	release
	end

ResedaTown_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, ResedaTown_Gym_EventScript_GymStatueCertified
	goto ResedaTown_Gym_EventScript_GymStatue
	end

ResedaTown_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, ResedaTown_Gym_EventScript_GymStatueCertified
	goto ResedaTown_Gym_EventScript_GymStatue
	end

ResedaTown_Gym_EventScript_GymStatueCertified::
	msgbox ResedaTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

ResedaTown_Gym_EventScript_GymStatue::
	msgbox ResedaTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

ResedaTown_Gym_Text_GymStatue:
	.string "RESEDA TOWN POKéMON GYM\p"
	.string "ARTHUR'S CERTIFIED TRAINERS:\n"
	.string "JACE$"

ResedaTown_Gym_Text_GymStatueCertified:
	.string "RESEDA TOWN POKéMON GYM\p"
	.string "ARTHUR'S CERTIFIED TRAINERS:\n"
	.string "JACE, {PLAYER}$"

ResedaTown_Gym_Text_GymGuideAdvice:
	.string "Hey there, cutie.\n"
	.string "Wanna team up?\p"
	.string "I'm no trainer, but I do know a thing\n"
	.string "or two about POKéMON battles.\p"
	.string "I'll get you to the POKéMON LEAGUE\n"
	.string "with my winning advice!\p"
	.string "Let's see. The gym leader here is ARTHUR\n"
	.string "who specializes in BUG type POKéMON.\p"
	.string "BUG types are usually weak against\n"
	.string "FIRE and FLYING types.\p"
	.string "And both BUG and STEEL types are\n"
	.string "immune to their status moves.\p"
	.string "Well, good luck, cutie!\n"
	.string "I'll be cheering for you!$"


ResedaTown_Gym_Text_GymGuidePostVictory:
	.string "Whoa! You did it!\n"
	.string "You got the MANDIBLE BADGE!\p"
	.string "My cheering must've worked!\p"
	.string "Great job! You just climbed your first\n"
	.string "step on the stairs to the CHAMPIONSHIP!$"





ResedaTown_Gym_EventScript_Tim::
	trainerbattle_single TRAINER_TIM, ResedaTown_Gym_Text_TimIntro, ResedaTown_Gym_Text_TimDefeated
	msgbox ResedaTown_Gym_Text_TimPostBattle, MSGBOX_AUTOCLOSE
	end

ResedaTown_Gym_EventScript_Erik::
	trainerbattle_single TRAINER_ERIK, ResedaTown_Gym_Text_ErikIntro, ResedaTown_Gym_Text_ErikDefeated
	msgbox ResedaTown_Gym_Text_ErikPostBattle, MSGBOX_AUTOCLOSE
	end

ResedaTown_Gym_Text_TimIntro:
	.string "Have you figured out how\n"
	.string "the spiderwebs work?$"

ResedaTown_Gym_Text_TimDefeated:
	.string "I guess I can give you a hint.$"

ResedaTown_Gym_Text_TimPostBattle:
	.string "SPINARAK like to crawl in a\n"
	.string "straight line.\p"
	.string "But when they get confused,\n"
	.string "they spin clockwise.$"

ResedaTown_Gym_Text_ErikIntro:
	.string "You'll never reach ARTHUR.\n"
	.string "I'll take you down right here!$"

ResedaTown_Gym_Text_ErikDefeated:
	.string "Uwwaaaaahhh!$"

ResedaTown_Gym_Text_ErikPostBattle:
	.string "Not bad, trainer.\n"
	.string "You just might stand a chance.\p"
	.string "A little one, but still, a chance.$"

ResedaTown_Gym_EventScript_WebSouth1::
	lockall
	setvar VAR_RESEDA_GYM_STATE, 1
	@playse SE_M_SWAGGER2
	@setobjectxyperm LOCALID_PLATFORM, 3, 17
	@setobjectmovementtype LOCALID_PLATFORM, MOVEMENT_TYPE_FACE_UP
	applymovement OBJ_EVENT_ID_PLAYER, ResedaTown_Gym_Movement_PlayerWebSouth1
	playse SE_M_SWAGGER2
	waitse
	playse SE_M_SWAGGER2
	@waitse
	@playse SE_M_SWAGGER2
	@delay 56
	@setobjectxyperm LOCALID_PLATFORM, 3, 18
	@addobject LOCALID_PLATFORM
	@setobjectxyperm LOCALID_PLATFORM, 3, 17
	@setobjectmovementtype LOCALID_PLATFORM, MOVEMENT_TYPE_NONE
	@applymovement LOCALID_PLATFORM, ResedaTown_Gym_Movement_PlatformWebSouth1
	waitmovement 0
	@removeobject LOCALID_PLATFORM
	@applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	@waitmovement 0
	setvar VAR_RESEDA_GYM_STATE, 0
	releaseall
	end

ResedaTown_Gym_EventScript_WebSouth2::
	lockall
	setvar VAR_RESEDA_GYM_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, ResedaTown_Gym_Movement_PlayerWebSouth2
	playse SE_M_SWAGGER2
	waitse
	playse SE_M_SWAGGER2
	waitmovement 0
	setvar VAR_RESEDA_GYM_STATE, 0
	releaseall
	end

ResedaTown_Gym_EventScript_WebSouth3::
	lockall
	setvar VAR_RESEDA_GYM_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, ResedaTown_Gym_Movement_PlayerWebSouth3
	playse SE_M_SWAGGER2
	waitse
	playse SE_M_SWAGGER2
	waitmovement 0
	setvar VAR_RESEDA_GYM_STATE, 0
	releaseall
	end

ResedaTown_Gym_EventScript_WebSouth4::
	lockall
	setvar VAR_RESEDA_GYM_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, ResedaTown_Gym_Movement_PlayerWebSouth4
	playse SE_M_SWAGGER2
	waitse
	playse SE_M_SWAGGER2
	waitmovement 0
	setvar VAR_RESEDA_GYM_STATE, 0
	releaseall
	end




ResedaTown_Gym_EventScript_WebNorth1::
	lockall
	setvar VAR_RESEDA_GYM_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, ResedaTown_Gym_Movement_PlayerWebNorth1
	playse SE_M_SWAGGER2
	waitse
	playse SE_M_SWAGGER2
	waitmovement 0
	setvar VAR_RESEDA_GYM_STATE, 0
	releaseall
	end

ResedaTown_Gym_EventScript_WebNorth2::
	lockall
	setvar VAR_RESEDA_GYM_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, ResedaTown_Gym_Movement_PlayerWebNorth2
	playse SE_M_SWAGGER2
	waitse
	playse SE_M_SWAGGER2
	waitmovement 0
	setvar VAR_RESEDA_GYM_STATE, 0
	releaseall
	end

ResedaTown_Gym_EventScript_WebNorth3::
	lockall
	setvar VAR_RESEDA_GYM_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, ResedaTown_Gym_Movement_PlayerWebNorth3
	playse SE_M_SWAGGER2
	waitse
	playse SE_M_SWAGGER2
	waitmovement 0
	setvar VAR_RESEDA_GYM_STATE, 0
	releaseall
	end

ResedaTown_Gym_EventScript_WebNorth4::
	lockall
	setvar VAR_RESEDA_GYM_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, ResedaTown_Gym_Movement_PlayerWebNorth4
	playse SE_M_SWAGGER2
	waitse
	playse SE_M_SWAGGER2
	waitmovement 0
	setvar VAR_RESEDA_GYM_STATE, 0
	releaseall
	end




ResedaTown_Gym_EventScript_WebWest1::
	lockall
	setvar VAR_RESEDA_GYM_STATE, 1
	@playse SE_M_SWAGGER2
	@setobjectxyperm LOCALID_PLATFORM, 2, 16
	@setobjectmovementtype LOCALID_PLATFORM, MOVEMENT_TYPE_FACE_UP
	applymovement OBJ_EVENT_ID_PLAYER, ResedaTown_Gym_Movement_PlayerWebWest1
	playse SE_M_SWAGGER2
	waitse
	playse SE_M_SWAGGER2
	@waitse
	@playse SE_M_SWAGGER2
	@delay 56
	@setobjectxyperm LOCALID_PLATFORM, 1, 16
	@addobject LOCALID_PLATFORM
	@setobjectxyperm LOCALID_PLATFORM, 2, 16
	@setobjectmovementtype LOCALID_PLATFORM, MOVEMENT_TYPE_NONE
	@applymovement LOCALID_PLATFORM, ResedaTown_Gym_Movement_PlatformWebWest1
	waitmovement 0
	@removeobject LOCALID_PLATFORM
	@applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	@waitmovement 0
	setvar VAR_RESEDA_GYM_STATE, 0
	releaseall
	end

ResedaTown_Gym_EventScript_WebWest2::
	lockall
	setvar VAR_RESEDA_GYM_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, ResedaTown_Gym_Movement_PlayerWebWest2
	playse SE_M_SWAGGER2
	waitse
	playse SE_M_SWAGGER2
	waitmovement 0
	setvar VAR_RESEDA_GYM_STATE, 0
	releaseall
	end

ResedaTown_Gym_EventScript_WebWest3::
	lockall
	setvar VAR_RESEDA_GYM_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, ResedaTown_Gym_Movement_PlayerWebWest3
	playse SE_M_SWAGGER2
	waitse
	playse SE_M_SWAGGER2
	waitmovement 0
	setvar VAR_RESEDA_GYM_STATE, 0
	releaseall
	end

ResedaTown_Gym_EventScript_WebWest4::
	lockall
	setvar VAR_RESEDA_GYM_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, ResedaTown_Gym_Movement_PlayerWebWest4
	playse SE_M_SWAGGER2
	waitse
	playse SE_M_SWAGGER2
	waitmovement 0
	setvar VAR_RESEDA_GYM_STATE, 0
	releaseall
	end

ResedaTown_Gym_EventScript_WebWest5::
	lockall
	setvar VAR_RESEDA_GYM_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, ResedaTown_Gym_Movement_PlayerWebWest5
	playse SE_M_SWAGGER2
	waitse
	playse SE_M_SWAGGER2
	waitmovement 0
	setvar VAR_RESEDA_GYM_STATE, 0
	releaseall
	end





ResedaTown_Gym_EventScript_WebEast1::
	lockall
	setvar VAR_RESEDA_GYM_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, ResedaTown_Gym_Movement_PlayerWebEast1
	playse SE_M_SWAGGER2
	waitse
	playse SE_M_SWAGGER2
	waitmovement 0
	setvar VAR_RESEDA_GYM_STATE, 0
	releaseall
	end

ResedaTown_Gym_EventScript_WebEast2::
	lockall
	setvar VAR_RESEDA_GYM_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, ResedaTown_Gym_Movement_PlayerWebEast2
	playse SE_M_SWAGGER2
	waitse
	playse SE_M_SWAGGER2
	waitmovement 0
	setvar VAR_RESEDA_GYM_STATE, 0
	releaseall
	end

ResedaTown_Gym_EventScript_WebEast3::
	lockall
	setvar VAR_RESEDA_GYM_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, ResedaTown_Gym_Movement_PlayerWebEast3
	playse SE_M_SWAGGER2
	waitse
	playse SE_M_SWAGGER2
	waitmovement 0
	setvar VAR_RESEDA_GYM_STATE, 0
	releaseall
	end

ResedaTown_Gym_EventScript_WebEast4::
	lockall
	setvar VAR_RESEDA_GYM_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, ResedaTown_Gym_Movement_PlayerWebEast4
	playse SE_M_SWAGGER2
	waitse
	playse SE_M_SWAGGER2
	waitmovement 0
	setvar VAR_RESEDA_GYM_STATE, 0
	releaseall
	end

ResedaTown_Gym_EventScript_WebEast5::
	lockall
	setvar VAR_RESEDA_GYM_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, ResedaTown_Gym_Movement_PlayerWebEast5
	playse SE_M_SWAGGER2
	waitse
	playse SE_M_SWAGGER2
	waitmovement 0
	setvar VAR_RESEDA_GYM_STATE, 0
	releaseall
	end






ResedaTown_Gym_Movement_PlatformWebSouth1:
	walk_slow_up
	walk_slow_left
	step_end

ResedaTown_Gym_Movement_PlatformWebWest1:
	walk_slow_right
	walk_slow_down
	step_end





ResedaTown_Gym_Movement_PlayerWebSouth1:
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_right
	slide_right
	slide_right
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_left
	slide_left
	slide_left
	slide_left
	walk_left
	step_end

ResedaTown_Gym_Movement_PlayerWebSouth2:
	slide_up
	slide_right
	slide_right
	slide_right
	slide_down
	walk_down
	step_end

ResedaTown_Gym_Movement_PlayerWebSouth3:
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_right
	slide_right
	slide_right
	slide_right
	walk_right
	step_end

ResedaTown_Gym_Movement_PlayerWebSouth4:
	slide_up
	slide_up
	slide_up
	slide_right
	walk_right
	step_end






ResedaTown_Gym_Movement_PlayerWebWest1:
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_down
	walk_down
	step_end

ResedaTown_Gym_Movement_PlayerWebWest2:
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	walk_right
	step_end

ResedaTown_Gym_Movement_PlayerWebWest3:
	slide_right
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	walk_down
	step_end

ResedaTown_Gym_Movement_PlayerWebWest4:
	slide_right
	slide_right
	slide_right
	slide_right
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_left
	slide_left
	slide_left
	slide_left
	walk_left
	step_end

ResedaTown_Gym_Movement_PlayerWebWest5:
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	walk_right
	step_end




ResedaTown_Gym_Movement_PlayerWebNorth1:
	slide_down
	slide_left
	walk_left
	step_end

ResedaTown_Gym_Movement_PlayerWebNorth2:
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_left
	slide_left
	slide_left
	slide_left
	walk_left
	step_end

ResedaTown_Gym_Movement_PlayerWebNorth3:
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	walk_left
	step_end

ResedaTown_Gym_Movement_PlayerWebNorth4:
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	walk_up
	step_end





ResedaTown_Gym_Movement_PlayerWebEast1:
	slide_left
	slide_up
	slide_up
	slide_right
	walk_right
	step_end

ResedaTown_Gym_Movement_PlayerWebEast2:
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	walk_left
	step_end

ResedaTown_Gym_Movement_PlayerWebEast3:
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	walk_up
	step_end

ResedaTown_Gym_Movement_PlayerWebEast4:
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_up
	slide_up
	slide_up
	walk_up
	step_end

ResedaTown_Gym_Movement_PlayerWebEast5:
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	walk_left
	step_end


