.set LOCALID_CADE, 6

PitchblakCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PitchblakCity_Gym_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PitchblakCity_Gym_OnResume
	map_script MAP_SCRIPT_ON_LOAD, PitchblakCity_Gym_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PitchblakCity_Gym_OnTransition
	.byte 0

PitchblakCity_Gym_OnTransition:
	@setvar VAR_DANCE_STEP_COUNT, 1
	setvar VAR_DANCE_STEP_COUNT, 0
	end

PitchblakCity_Gym_OnResume:
	setstepcallback STEP_CB_DANCE_FLOOR
	end

PitchblakCity_Gym_OnLoad:
	call PitchblakCity_Gym_EventScript_CheckSetStairMetatiles
	@special SetSootopolisGymCrackedIceMetatiles
	end

PitchblakCity_Gym_EventScript_CheckSetStairMetatiles::
	goto_if_lt VAR_DANCE_STEP_COUNT, 19, PitchblakCity_Gym_EventScript_StopCheckingStairs  @ All stairs hidden
	goto_if_lt VAR_DANCE_STEP_COUNT, 52, PitchblakCity_Gym_EventScript_OpenFirstStairs
	goto_if_lt VAR_DANCE_STEP_COUNT, 102, PitchblakCity_Gym_EventScript_OpenFirstAndSecondStairs
	setmetatile 9, 5, METATILE_GymsIssho_Pitchblak_Stairs, FALSE
	setmetatile 9, 6, METATILE_GymsIssho_Pitchblak_Stairs, FALSE
PitchblakCity_Gym_EventScript_OpenFirstAndSecondStairs::
	setmetatile 9, 12, METATILE_GymsIssho_Pitchblak_Stairs, FALSE
	setmetatile 9, 13, METATILE_GymsIssho_Pitchblak_Stairs, FALSE
PitchblakCity_Gym_EventScript_OpenFirstStairs::
	setmetatile 9, 18, METATILE_GymsIssho_Pitchblak_Stairs, FALSE
	setmetatile 9, 19, METATILE_GymsIssho_Pitchblak_Stairs, FALSE
PitchblakCity_Gym_EventScript_StopCheckingStairs::
	return

PitchblakCity_Gym_OnFrame:
	map_script_2 VAR_DANCE_STEP_COUNT, 19, PitchblakCity_Gym_EventScript_UnlockFirstStairs
	map_script_2 VAR_DANCE_STEP_COUNT, 52, PitchblakCity_Gym_EventScript_UnlockSecondStairs
	map_script_2 VAR_DANCE_STEP_COUNT, 102, PitchblakCity_Gym_EventScript_UnlockThirdStairs
	@map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_FallThroughIce
	.2byte 0

PitchblakCity_Gym_EventScript_UnlockFirstStairs::
	addvar VAR_DANCE_STEP_COUNT, 1
	delay 40
	@playse SE_ICE_STAIRS
	playse SE_SUCCESS
	waitse
	playse SE_TRUCK_DOOR
	call PitchblakCity_Gym_EventScript_CheckSetStairMetatiles
	call PitchblakCity_Gym_EventScript_SetSolvedFirstFloorMetatiles
	special DrawWholeMapView
	end

PitchblakCity_Gym_EventScript_UnlockSecondStairs::
	addvar VAR_DANCE_STEP_COUNT, 1
	delay 40
	@playse SE_ICE_STAIRS
	playse SE_SUCCESS
	waitse
	playse SE_TRUCK_DOOR
	call PitchblakCity_Gym_EventScript_CheckSetStairMetatiles
	call PitchblakCity_Gym_EventScript_SetSolvedSecondFloorMetatiles
	special DrawWholeMapView
	end

PitchblakCity_Gym_EventScript_UnlockThirdStairs::
	addvar VAR_DANCE_STEP_COUNT, 1
	delay 40
	@playse SE_ICE_STAIRS
	playse SE_SUCCESS
	waitse
	playse SE_TRUCK_DOOR
	call PitchblakCity_Gym_EventScript_CheckSetStairMetatiles
	call PitchblakCity_Gym_EventScript_SetSolvedThirdFloorMetatiles
	special DrawWholeMapView
	end

PitchblakCity_Gym_EventScript_SetSolvedFirstFloorMetatiles::
	setmetatile 6, 20, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 6, 21, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 6, 22, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 7, 20, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 7, 21, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 7, 22, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 8, 20, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE

	setmetatile 8, 22, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 9, 20, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 9, 21, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 9, 22, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 10, 20, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	
	setmetatile 10, 22, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 11, 20, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 11, 21, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 11, 22, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 12, 20, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 12, 21, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 12, 22, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	return

PitchblakCity_Gym_EventScript_SetSolvedSecondFloorMetatiles::
	setmetatile 5, 14, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 5, 15, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 5, 16, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 5, 17, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 6, 14, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 6, 15, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE

	setmetatile 6, 17, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 7, 14, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 7, 15, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 7, 16, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 7, 17, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 8, 14, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE

	setmetatile 8, 16, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 8, 17, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 9, 14, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 9, 15, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 9, 16, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 9, 17, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 10, 14, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 10, 15, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE

	setmetatile 10, 17, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 11, 14, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 11, 15, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 11, 16, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 11, 17, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 12, 14, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE

	setmetatile 12, 16, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 12, 17, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 13, 14, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 13, 15, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 13, 16, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 13, 17, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	return

PitchblakCity_Gym_EventScript_SetSolvedThirdFloorMetatiles::
	setmetatile 4, 7, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 4, 8, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 4, 9, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 4, 10, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 4, 11, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 5, 7, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE

	setmetatile 5, 9, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 5, 10, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 5, 11, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 6, 7, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 6, 8, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 6, 9, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE

	setmetatile 6, 11, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 7, 7, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 7, 8, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 7, 9, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 7, 10, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 7, 11, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 8, 7, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 8, 8, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE

	setmetatile 8, 10, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 8, 11, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 9, 7, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 9, 8, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 9, 9, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 9, 10, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 9, 11, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 10, 7, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE

	setmetatile 10, 9, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 10, 10, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 10, 11, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 11, 7, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 11, 8, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 11, 9, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE

	setmetatile 11, 11, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 12, 7, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 12, 8, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 12, 9, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 12, 10, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 12, 11, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 13, 7, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 13, 8, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE

	setmetatile 13, 10, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 13, 11, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 14, 7, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 14, 8, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 14, 9, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 14, 10, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	setmetatile 14, 11, METATILE_GymsIssho_Pitchblak_SolvedGreenFloor, FALSE
	return






PitchblakCity_Gym_EventScript_CheckStepCount::
	special GetDanceStepCount
	msgbox PitchblakCity_Gym_Text_StepCount, MSGBOX_DEFAULT
	closemessage
	end

PitchblakCity_Gym_Text_StepCount:
	.string "Current step count: {STR_VAR_1}.$"










PitchblakCity_Gym_EventScript_Kurt::
	trainerbattle_single TRAINER_KURT, PitchblakCity_Gym_Text_KurtIntro, PitchblakCity_Gym_Text_KurtDefeated
	msgbox PitchblakCity_Gym_Text_KurtPostBattle, MSGBOX_AUTOCLOSE
	end

PitchblakCity_Gym_EventScript_DeAaron::
	trainerbattle_single TRAINER_DEAARON, PitchblakCity_Gym_Text_DeAaronIntro, PitchblakCity_Gym_Text_DeAaronDefeated
	msgbox PitchblakCity_Gym_Text_DeAaronPostBattle, MSGBOX_AUTOCLOSE
	end

PitchblakCity_Gym_EventScript_Tyrone::
	trainerbattle_single TRAINER_TYRONE, PitchblakCity_Gym_Text_TyroneIntro, PitchblakCity_Gym_Text_TyroneDefeated
	msgbox PitchblakCity_Gym_Text_TyronePostBattle, MSGBOX_AUTOCLOSE
	end

PitchblakCity_Gym_EventScript_Jenny::
	trainerbattle_single TRAINER_JENNY, PitchblakCity_Gym_Text_JennyIntro, PitchblakCity_Gym_Text_JennyDefeated
	msgbox PitchblakCity_Gym_Text_JennyPostBattle, MSGBOX_AUTOCLOSE
	end

PitchblakCity_Gym_EventScript_Benito::
	trainerbattle_single TRAINER_BENITO, PitchblakCity_Gym_Text_BenitoIntro, PitchblakCity_Gym_Text_BenitoDefeated
	msgbox PitchblakCity_Gym_Text_BenitoPostBattle, MSGBOX_AUTOCLOSE
	end

PitchblakCity_Gym_EventScript_Malcolm::
	trainerbattle_single TRAINER_MALCOLM, PitchblakCity_Gym_Text_MalcolmIntro, PitchblakCity_Gym_Text_MalcolmDefeated
	msgbox PitchblakCity_Gym_Text_MalcolmPostBattle, MSGBOX_AUTOCLOSE
	end

PitchblakCity_Gym_Text_KurtIntro:
	.string "Hey! You're interupting my solo!$"

PitchblakCity_Gym_Text_KurtDefeated:
	.string "Out of tune.$"

PitchblakCity_Gym_Text_KurtPostBattle:
	.string "Aw yeah! Check out this next riff!$"

PitchblakCity_Gym_Text_DeAaronIntro:
	.string "Check out these grooves!$"

PitchblakCity_Gym_Text_DeAaronDefeated:
	.string "Nice one!$"

PitchblakCity_Gym_Text_DeAaronPostBattle:
	.string "You got great moves, kid!$"

PitchblakCity_Gym_Text_TyroneIntro:
	.string "One. Two. Three. Go!$"

PitchblakCity_Gym_Text_TyroneDefeated:
	.string "Out of time.$"

PitchblakCity_Gym_Text_TyronePostBattle:
	.string "Boots and cats and boots and cats and\n"
	.string "boots and cats and boots and cats and...$"

PitchblakCity_Gym_Text_JennyIntro:
	.string "Hey! Watch where you're going!$"

PitchblakCity_Gym_Text_JennyDefeated:
	.string "Aaaaah!$"

PitchblakCity_Gym_Text_JennyPostBattle:
	.string "Ugh. That creep over there keeps\n"
	.string "staring at me.$"

PitchblakCity_Gym_Text_BenitoIntro:
	.string "I don't really know how to dance.$"

PitchblakCity_Gym_Text_BenitoDefeated:
	.string "Uhuhuh.$"

PitchblakCity_Gym_Text_BenitoPostBattle:
	.string "I wanna ask that babe over there\n"
	.string "to dance with me.\p"
	.string "But I'm too nervous...$"

PitchblakCity_Gym_Text_MalcolmIntro:
	.string "Come on! Feel the rhythm!$"

PitchblakCity_Gym_Text_MalcolmDefeated:
	.string "That's what I'm talking about!$"

PitchblakCity_Gym_Text_MalcolmPostBattle:
	.string "Step this way! Then that!$"



PitchblakCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_PITCHBLAK_GYM, PitchblakCity_Gym_EventScript_GymGuidePostVictory
	msgbox PitchblakCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	goto_if_eq VAR_PITCHBLAK_GYM_GUIDE, 0, PitchblakCity_Gym_EventScript_GiveFreshWater
	release
	end

PitchblakCity_Gym_EventScript_GiveFreshWater::
	giveitem ITEM_FRESH_WATER
	setvar VAR_PITCHBLAK_GYM_GUIDE, 1
	release
	end

PitchblakCity_Gym_EventScript_GymGuidePostVictory::
	msgbox PitchblakCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	goto_if_le VAR_PITCHBLAK_GYM_GUIDE, 1, PitchblakCity_Gym_EventScript_GiveEchoGem
	release
	end

PitchblakCity_Gym_EventScript_GiveEchoGem::
	giveitem ITEM_ECHO_GEM
	setvar VAR_PITCHBLAK_GYM_GUIDE, 2
	release
	end

PitchblakCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE05_GET, PitchblakCity_Gym_EventScript_GymStatueCertified
	goto PitchblakCity_Gym_EventScript_GymStatue
	end

PitchblakCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE05_GET, PitchblakCity_Gym_EventScript_GymStatueCertified
	goto PitchblakCity_Gym_EventScript_GymStatue
	end

PitchblakCity_Gym_EventScript_GymStatueCertified::
	msgbox PitchblakCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

PitchblakCity_Gym_EventScript_GymStatue::
	msgbox PitchblakCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

PitchblakCity_Gym_Text_GymStatue:
	.string "PITCHBLAK CITY POKéMON GYM$"

PitchblakCity_Gym_Text_GymStatueCertified:
	.string "PITCHBLAK CITY POKéMON GYM\p"
	.string "CADE'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}, JACE$"

PitchblakCity_Gym_Text_GymGuideAdvice:
	.string "Hey cutie, long time no see.\p"
	.string "The GYM LEADER here is CADE.\n"
	.string "He specializes in ECHO-type POKéMON.\p"
	.string "You can counter those with an\n"
	.string "ICE-type or a PSYCHIC-type.\p"
	.string "And there's one more thing.\p"
	.string "You see that neon slide in the back?\p"
	.string "A staircase will come out of it if you\n"
	.string "set all the floor tiles to the same color.\p"
	.string "You'll need to clear all the dance floors\n"
	.string "to get to CADE in the back.\p"
	.string "Alright then, go for it!\n"
	.string "I know you can figure this out!$"

PitchblakCity_Gym_Text_GymGuidePostVictory:
	.string "You were awesome!\n"
	.string "You really lit up this place!$"










PitchblakCity_Gym_EventScript_Cade::
	trainerbattle_single TRAINER_CADE_1, PitchblakCity_Gym_Text_CadeIntro, PitchblakCity_Gym_Text_CadeDefeated, PitchblakCity_Gym_EventScript_CadePostBattle, NO_MUSIC
	goto_if_unset FLAG_DEFEATED_PITCHBLAK_GYM, PitchblakCity_Gym_EventScript_GiveAttune
	msgbox PitchblakCity_Gym_Text_CadePostBattle, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Gym_EventScript_CadePostBattle::
	message PitchblakCity_Gym_Text_ReceivedRhythmBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special GetDifficulty
	switch VAR_RESULT
	case 0, PitchblakCity_Gym_EventScript_EventScript_ExplainBadgeNormal
	case 1, PitchblakCity_Gym_EventScript_EventScript_ExplainBadgeHardcore
	case 2, PitchblakCity_Gym_EventScript_EventScript_ExplainBadgeInsane
	end


	@goto_if_set FLAG_BADGE04_GET, PitchblakCity_Gym_EventScript_AlreadyBeatEira
	@msgbox PitchblakCity_Gym_Text_RhythmBadgeInfoTakeThis, MSGBOX_DEFAULT
	@setflag FLAG_BADGE05_GET
	@setvar VAR_0x8008, 13
	@call Common_EventScript_SetGymTrainers
	@goto PitchblakCity_Gym_EventScript_GiveAttune
	@end

@PitchblakCity_Gym_EventScript_AlreadyBeatEira::


PitchblakCity_Gym_EventScript_EventScript_ExplainBadgeNormal::
	msgbox PitchblakCity_Gym_Text_RhythmBadgeNormalInfoTakeThis2, MSGBOX_DEFAULT
	setflag FLAG_BADGE05_GET
	setvar VAR_0x8008, 13
	call Common_EventScript_SetGymTrainers
	goto PitchblakCity_Gym_EventScript_GiveAttune
	end

PitchblakCity_Gym_EventScript_EventScript_ExplainBadgeHardcore::
	msgbox PitchblakCity_Gym_Text_RhythmBadgeHardcoreInfoTakeThis2, MSGBOX_DEFAULT
	setflag FLAG_BADGE05_GET
	setvar VAR_0x8008, 13
	call Common_EventScript_SetGymTrainers
	goto PitchblakCity_Gym_EventScript_GiveAttune
	end

PitchblakCity_Gym_EventScript_EventScript_ExplainBadgeInsane::
	msgbox PitchblakCity_Gym_Text_RhythmBadgeInsaneInfoTakeThis2, MSGBOX_DEFAULT
	setflag FLAG_BADGE05_GET
	setvar VAR_0x8008, 13
	call Common_EventScript_SetGymTrainers
	goto PitchblakCity_Gym_EventScript_GiveAttune
	end

PitchblakCity_Gym_EventScript_GiveAttune::
	giveitem ITEM_TM19
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DEFEATED_PITCHBLAK_GYM
	msgbox PitchblakCity_Gym_Text_ExplainAttune, MSGBOX_DEFAULT
	call PitchblakCity_EventScript_CadeExit
	release
	end

PitchblakCity_EventScript_CadeExit::
	applymovement LOCALID_CADE, Route110_TrickHouse_Movement_TrickMasterSpin
	waitmovement 0
	playse SE_M_EXPLOSION
	applymovement LOCALID_CADE, Route110_TrickHouse_Movement_TrickMasterJumpAway
	waitmovement 0
	removeobject LOCALID_CADE
	setobjectxyperm LOCALID_CADE, 19, 0
	addobject LOCALID_CADE
	return





PitchblakCity_Gym_Text_CadeIntro:
	.string "Yo, welcome.\n"
	.string "My name's CADE.\p"
	.string "Music and ECHO types,\n"
	.string "that's my trade.\p"
	.string "Let's not waste time\n"
	.string "or be delayed.\p"
	.string "Or leave the audience\n"
	.string "here dismayed.\p"
	.string "I'm sure you know how\n"
	.string "this game is played.\p"
	.string "We'll throw down here with\n"
	.string "the teams we made.\p"
	.string "Let's see you resist\n"
	.string "our fusillade.\p"
	.string "Will you break out?\n"
	.string "Or will you get slayed?{PAUSE_MUSIC}{PLAY_BGM MUS_RG_ENCOUNTER_GYM_LEADER}$"

PitchblakCity_Gym_Text_CadeDefeated:
	.string "Woah, I can't believe my eyes!\p"
	.string "This kid ran circles around my guys!\p"
	.string "And you know what that implies.\p"
	.string "Take it, you've earned this prize.$"

PitchblakCity_Gym_Text_ReceivedRhythmBadge:
	.string "{PLAYER} received the RHYTHM BADGE\n"
	.string "from CADE.$"

@PitchblakCity_Gym_Text_RhythmBadgeInfoTakeThis:
	@.string "With the RHYTHM BADGE, all POKéMON\n"
	@.string "up to Level 44 will obey you.\p"
	@.string "And you can THAW icy rocks\n"
	@.string "that might forestay you.\p"
@	.string "And I want you to have this,\n"
@	.string "you protégé, you.$"

PitchblakCity_Gym_Text_RhythmBadgeNormalInfoTakeThis2:
	.string "With the RHYTHM BADGE, all POKéMON\n"
	.string "up to Level 48 will comply.\p"
	.string "And you can revisit old places\n"
	.string "with HM FLY.\p"
	.string "And I'll give you this too,\n"
	.string "cuz I'm such a nice guy.$"

PitchblakCity_Gym_Text_RhythmBadgeHardcoreInfoTakeThis2:
	.string "With the RHYTHM BADGE, all POKéMON\n"
	.string "up to Level 44 will comply.\p"
	.string "And you can revisit old places\n"
	.string "with HM FLY.\p"
	.string "And I'll give you this too,\n"
	.string "cuz I'm such a nice guy.$"

PitchblakCity_Gym_Text_RhythmBadgeInsaneInfoTakeThis2:
	.string "With the RHYTHM BADGE, all POKéMON\n"
	.string "up to Level 42 will comply.\p"
	.string "And you can revisit old places\n"
	.string "with HM FLY.\p"
	.string "And I'll give you this too,\n"
	.string "cuz I'm such a nice guy.$"

PitchblakCity_Gym_Text_ExplainAttune:
	.string "ATTUNE is the move that TM\n"
	.string "will teach.\p"
	.string "It boosts Attack and Accuracy\n"
	.string "by one stage each.\p"
	.string "Well, that just about wraps up\n"
	.string "this gym bout.\p"
	.string "This is DJ CADE, signing out.$"

PitchblakCity_Gym_Text_CadePostBattle:
	.string "Tune in next time for more\n"
	.string "battles and grooves.$"
