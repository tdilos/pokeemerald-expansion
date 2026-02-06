AmberCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AmberCity_Gym_OnTransition
	.byte 0

@AmberCity_Gym_EventScript_Switch::
@	goto_if_eq VAR_AMBER_GYM_STATE, 0, AmberCity_Gym_EventScript_SetStairs1
@	goto_if_eq VAR_AMBER_GYM_STATE, 1, AmberCity_Gym_EventScript_SetStairs0
@	end

AmberCity_Gym_OnTransition:
	setvar VAR_AMBER_GYM_STATE, 0
	end

AmberCity_Gym_EventScript_SetStairs0::
	lockall
	@fadescreen FADE_TO_BLACK
	playse SE_SWITCH
	waitse
	delay 30
	setmetatile 1, 6, METATILE_GymsIssho_SandySlope_Stairs, FALSE
	setmetatile 1, 7, METATILE_GymsIssho_SandySlope_Stairs, FALSE
	setmetatile 10, 6, METATILE_GymsIssho_SandySlope_Stairs, FALSE
	setmetatile 10, 7, METATILE_GymsIssho_SandySlope_Stairs, FALSE
	setmetatile 19, 6, METATILE_GymsIssho_SandySlope_Frame0, FALSE
	setmetatile 19, 7, METATILE_GymsIssho_SandySlope_Frame0, FALSE
	setmetatile 2, 9, METATILE_GymsIssho_SandySlope_Frame0, FALSE
	setmetatile 2, 10, METATILE_GymsIssho_SandySlope_Frame0, FALSE
	setmetatile 7, 9, METATILE_GymsIssho_SandySlope_Stairs, FALSE
	setmetatile 7, 10, METATILE_GymsIssho_SandySlope_Stairs, FALSE
	setmetatile 10, 9, METATILE_GymsIssho_SandySlope_Frame0, FALSE
	setmetatile 10, 10, METATILE_GymsIssho_SandySlope_Frame0, FALSE
	setmetatile 15, 9, METATILE_GymsIssho_SandySlope_Stairs, FALSE
	setmetatile 15, 10, METATILE_GymsIssho_SandySlope_Stairs, FALSE
	setmetatile 19, 9, METATILE_GymsIssho_SandySlope_Frame0, FALSE
	setmetatile 19, 10, METATILE_GymsIssho_SandySlope_Frame0, FALSE
	setmetatile 1, 12, METATILE_GymsIssho_SandySlope_Stairs, FALSE
	setmetatile 1, 13, METATILE_GymsIssho_SandySlope_Stairs, FALSE
	setmetatile 5, 12, METATILE_GymsIssho_SandySlope_Frame0, FALSE
	setmetatile 5, 13, METATILE_GymsIssho_SandySlope_Frame0, FALSE
	setmetatile 10, 12, METATILE_GymsIssho_SandySlope_Stairs, FALSE
	setmetatile 10, 13, METATILE_GymsIssho_SandySlope_Stairs, FALSE
	setmetatile 15, 12, METATILE_GymsIssho_SandySlope_Frame0, FALSE
	setmetatile 15, 13, METATILE_GymsIssho_SandySlope_Frame0, FALSE
	setmetatile 18, 12, METATILE_GymsIssho_SandySlope_Frame0, FALSE
	setmetatile 18, 13, METATILE_GymsIssho_SandySlope_Frame0, FALSE
	setmetatile 2, 15, METATILE_GymsIssho_SandySlope_Stairs, FALSE
	setmetatile 2, 16, METATILE_GymsIssho_SandySlope_Stairs, FALSE
	setmetatile 10, 15, METATILE_GymsIssho_SandySlope_Frame0, FALSE
	setmetatile 10, 16, METATILE_GymsIssho_SandySlope_Frame0, FALSE
	setmetatile 18, 15, METATILE_GymsIssho_SandySlope_Stairs, FALSE
	setmetatile 18, 16, METATILE_GymsIssho_SandySlope_Stairs, FALSE
	special DrawWholeMapView
	playse SE_TRUCK_DOOR
	waitse
	setvar VAR_AMBER_GYM_STATE, 0
	@fadescreen FADE_FROM_BLACK
	releaseall
	end

AmberCity_Gym_EventScript_SetStairs1::
	lockall
	@fadescreen FADE_TO_BLACK
	playse SE_SWITCH
	waitse
	delay 30
	setmetatile 1, 6, METATILE_GymsIssho_SandySlope_Frame0, FALSE
	setmetatile 1, 7, METATILE_GymsIssho_SandySlope_Frame0, FALSE
	setmetatile 10, 6, METATILE_GymsIssho_SandySlope_Frame0, FALSE
	setmetatile 10, 7, METATILE_GymsIssho_SandySlope_Frame0, FALSE
	setmetatile 19, 6, METATILE_GymsIssho_SandySlope_Stairs, FALSE
	setmetatile 19, 7, METATILE_GymsIssho_SandySlope_Stairs, FALSE
	setmetatile 2, 9, METATILE_GymsIssho_SandySlope_Stairs, FALSE
	setmetatile 2, 10, METATILE_GymsIssho_SandySlope_Stairs, FALSE
	setmetatile 7, 9, METATILE_GymsIssho_SandySlope_Frame0, FALSE
	setmetatile 7, 10, METATILE_GymsIssho_SandySlope_Frame0, FALSE
	setmetatile 10, 9, METATILE_GymsIssho_SandySlope_Stairs, FALSE
	setmetatile 10, 10, METATILE_GymsIssho_SandySlope_Stairs, FALSE
	setmetatile 15, 9, METATILE_GymsIssho_SandySlope_Frame0, FALSE
	setmetatile 15, 10, METATILE_GymsIssho_SandySlope_Frame0, FALSE
	setmetatile 19, 9, METATILE_GymsIssho_SandySlope_Stairs, FALSE
	setmetatile 19, 10, METATILE_GymsIssho_SandySlope_Stairs, FALSE
	setmetatile 1, 12, METATILE_GymsIssho_SandySlope_Frame0, FALSE
	setmetatile 1, 13, METATILE_GymsIssho_SandySlope_Frame0, FALSE
	setmetatile 5, 12, METATILE_GymsIssho_SandySlope_Stairs, FALSE
	setmetatile 5, 13, METATILE_GymsIssho_SandySlope_Stairs, FALSE
	setmetatile 10, 12, METATILE_GymsIssho_SandySlope_Frame0, FALSE
	setmetatile 10, 13, METATILE_GymsIssho_SandySlope_Frame0, FALSE
	setmetatile 15, 12, METATILE_GymsIssho_SandySlope_Stairs, FALSE
	setmetatile 15, 13, METATILE_GymsIssho_SandySlope_Stairs, FALSE
	setmetatile 18, 12, METATILE_GymsIssho_SandySlope_Stairs, FALSE
	setmetatile 18, 13, METATILE_GymsIssho_SandySlope_Stairs, FALSE
	setmetatile 2, 15, METATILE_GymsIssho_SandySlope_Frame0, FALSE
	setmetatile 2, 16, METATILE_GymsIssho_SandySlope_Frame0, FALSE
	setmetatile 10, 15, METATILE_GymsIssho_SandySlope_Stairs, FALSE
	setmetatile 10, 16, METATILE_GymsIssho_SandySlope_Stairs, FALSE
	setmetatile 18, 15, METATILE_GymsIssho_SandySlope_Frame0, FALSE
	setmetatile 18, 16, METATILE_GymsIssho_SandySlope_Frame0, FALSE
	special DrawWholeMapView
	playse SE_TRUCK_DOOR
	waitse
	setvar VAR_AMBER_GYM_STATE, 1
	@fadescreen FADE_FROM_BLACK
	releaseall
	end


AmberCity_Gym_EventScript_Tara::
	trainerbattle_single TRAINER_TARAH_1, AmberCity_Gym_Text_TaraIntro, AmberCity_Gym_Text_TaraDefeated, AmberCity_Gym_EventScript_TaraPostBattle, NO_MUSIC
	goto_if_unset FLAG_DEFEATED_AMBER_GYM, AmberCity_Gym_EventScript_GiveDustDevil
	msgbox AmberCity_Gym_Text_TaraPostBattle, MSGBOX_DEFAULT
	release
	end

AmberCity_Gym_EventScript_TaraPostBattle::
	message AmberCity_Gym_Text_ReceivedSiliconBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special GetDifficulty
	switch VAR_RESULT
	case 0, AmberCity_Gym_EventScript_EventScript_ExplainBadgeNormal
	case 1, AmberCity_Gym_EventScript_EventScript_ExplainBadgeHardcore
	case 2, AmberCity_Gym_EventScript_EventScript_ExplainBadgeInsane
	end

AmberCity_Gym_EventScript_EventScript_ExplainBadgeNormal::
	msgbox AmberCity_Gym_Text_SiliconBadgeNormalInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_BADGE02_GET
	setvar VAR_0x8008, 10
	call Common_EventScript_SetGymTrainers
	goto AmberCity_Gym_EventScript_GiveDustDevil
	end

AmberCity_Gym_EventScript_EventScript_ExplainBadgeHardcore::
	msgbox AmberCity_Gym_Text_SiliconBadgeHardcoreInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_BADGE02_GET
	setvar VAR_0x8008, 10
	call Common_EventScript_SetGymTrainers
	goto AmberCity_Gym_EventScript_GiveDustDevil
	end

AmberCity_Gym_EventScript_EventScript_ExplainBadgeInsane::
	msgbox AmberCity_Gym_Text_SiliconBadgeInsaneInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_BADGE02_GET
	setvar VAR_0x8008, 10
	call Common_EventScript_SetGymTrainers
	goto AmberCity_Gym_EventScript_GiveDustDevil
	end

AmberCity_Gym_EventScript_GiveDustDevil::
	giveitem ITEM_TM78
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DEFEATED_AMBER_GYM
	@setflag FLAG_RECEIVED_TM39
	msgbox AmberCity_Gym_Text_ExplainDustDevil, MSGBOX_DEFAULT
	release
	end

AmberCity_Gym_Text_TaraIntro:
	.string "Hey there! I'm TARA, the AMBER\n"
	.string "CITY GYM LEADER.\p"
	.string "I specialize in the GROUND type.\p"
	.string "My POKéMON and I have traveled all over\n"
	.string "searching for relics of the past.\p"
	.string "Underground, underwater, and\n"
	.string "even in the air!\p"
	.string "There's no environment we can't handle!\p"
	.string "Well, I hope you and your POKéMON\n"
	.string "came prepared.\p"
	.string "The sandstorms outside are nothing\n"
	.string "compared to this!{PAUSE_MUSIC}{PLAY_BGM MUS_RG_ENCOUNTER_GYM_LEADER}$"

AmberCity_Gym_Text_TaraDefeated:
	.string "Wow! You and your POKéMON were\n"
	.string "incredible!\p"
	.string "You held together and pushed through\n"
	.string "in the face of adversity!\p"
	.string "I hereby present you with the official\n"
	.string "POKéMON LEAGUE SILICON BADGE.$"

AmberCity_Gym_Text_ReceivedSiliconBadge:
	.string "{PLAYER} received the SILICON BADGE\n"
	.string "from TARA.$"

AmberCity_Gym_Text_SiliconBadgeNormalInfoTakeThis:
	.string "The SILICON BADGE will make all\n"
	.string "POKéMON up to Level 32 obey you.\p"
	.string "It also enables them to use the HM move\n"
	.string "ROCK SMASH outside of battle.\p"
	.string "And I'd like you to take this too.$"

AmberCity_Gym_Text_SiliconBadgeHardcoreInfoTakeThis:
	.string "The SILICON BADGE will make all\n"
	.string "POKéMON up to Level 30 obey you.\p"
	.string "It also enables them to use the HM move\n"
	.string "ROCK SMASH outside of battle.\p"
	.string "And I'd like you to take this too.$"

AmberCity_Gym_Text_SiliconBadgeInsaneInfoTakeThis:
	.string "The SILICON BADGE will make all\n"
	.string "POKéMON up to Level 28 obey you.\p"
	.string "It also enables them to use the HM move\n"
	.string "ROCK SMASH outside of battle.\p"
	.string "And I'd like you to take this too.$"

AmberCity_Gym_Text_ExplainDustDevil:
	.string "That TECHNICAL MACHINE, TM78,\n"
	.string "contains DUST DEVIL.\p"
	.string "It whips up a sand tornado and has a\n"
	.string "chance to raise your Evasion.\p"
	.string "Use it to attack your foes while keeping\n"
	.string "your own POKéMON safe.$"

AmberCity_Gym_Text_TaraPostBattle:
	.string "Explore the world and discover new\n"
	.string "people and POKéMON.\p"
	.string "With each battle, we uncover more truths\n"
	.string "about each other.$"




AmberCity_Gym_EventScript_Beauford::
	trainerbattle_single TRAINER_BEAUFORD, AmberCity_Gym_Text_BeaufordIntro, AmberCity_Gym_Text_BeaufordDefeated
	msgbox AmberCity_Gym_Text_BeaufordPostBattle, MSGBOX_AUTOCLOSE
	end

AmberCity_Gym_EventScript_Gavin::
	trainerbattle_single TRAINER_GAVIN, AmberCity_Gym_Text_GavinIntro, AmberCity_Gym_Text_GavinDefeated
	msgbox AmberCity_Gym_Text_GavinPostBattle, MSGBOX_AUTOCLOSE
	end

AmberCity_Gym_EventScript_Josiah::
	trainerbattle_single TRAINER_JOSIAH, AmberCity_Gym_Text_JosiahIntro, AmberCity_Gym_Text_JosiahDefeated
	msgbox AmberCity_Gym_Text_JosiahPostBattle, MSGBOX_AUTOCLOSE
	end

AmberCity_Gym_Text_BeaufordIntro:
	.string "Wahaha! Another gym challenger, is it?$"

AmberCity_Gym_Text_BeaufordDefeated:
	.string "Wahaha! Another sound defeat.$"

AmberCity_Gym_Text_BeaufordPostBattle:
	.string "You've got guts, young'un.\p"
	.string "With that attitude, you'll go far.\n"
	.string "I'm sure of it.$"

AmberCity_Gym_Text_GavinIntro:
	.string "Careful now! These ledges are steep!$"

AmberCity_Gym_Text_GavinDefeated:
	.string "Ahh! I'm slipping...$"

AmberCity_Gym_Text_GavinPostBattle:
	.string "You see that white button?\p"
	.string "Pressing it will retract or extend\n"
	.string "the stairs beneath the sand slides\p"
	.string "Use it to make a path to TARA.$"

AmberCity_Gym_Text_JosiahIntro:
	.string "Let's heat things up!$"

AmberCity_Gym_Text_JosiahDefeated:
	.string "Woah now, simmer down a bit.$"

AmberCity_Gym_Text_JosiahPostBattle:
	.string "These steep ledges aren't good for\n"
	.string "starting a campfire, you know.$"







AmberCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_AMBER_GYM, AmberCity_Gym_EventScript_GymGuidePostVictory
	msgbox AmberCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	goto_if_eq VAR_AMBER_GYM_GUIDE, 0, AmberCity_Gym_EventScript_GiveFreshWater
	release
	end

AmberCity_Gym_EventScript_GiveFreshWater::
	giveitem ITEM_FRESH_WATER
	setvar VAR_AMBER_GYM_GUIDE, 1
	release
	end

AmberCity_Gym_EventScript_GymGuidePostVictory::
	msgbox AmberCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	goto_if_le VAR_AMBER_GYM_GUIDE, 1, AmberCity_Gym_EventScript_GiveGroundGem
	release
	end

AmberCity_Gym_EventScript_GiveGroundGem::
	giveitem ITEM_GROUND_GEM
	setvar VAR_AMBER_GYM_GUIDE, 2
	release
	end

AmberCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, AmberCity_Gym_EventScript_GymStatueCertified
	goto AmberCity_Gym_EventScript_GymStatue
	end

AmberCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, AmberCity_Gym_EventScript_GymStatueCertified
	goto AmberCity_Gym_EventScript_GymStatue
	end

AmberCity_Gym_EventScript_GymStatueCertified::
	msgbox AmberCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

AmberCity_Gym_EventScript_GymStatue::
	msgbox AmberCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

AmberCity_Gym_Text_GymStatue:
	.string "AMBER CITY POKéMON GYM$"

AmberCity_Gym_Text_GymStatueCertified:
	.string "AMBER CITY POKéMON GYM\p"
	.string "TARA'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}, JACE$"

AmberCity_Gym_Text_GymGuideAdvice:
	.string "Hey cutie, how's it going?\p"
	.string "TARA, the LEADER of AMBER GYM,\n"
	.string "uses GROUND-type POKéMON.\p"
	.string "Your best bet is to counter her with\n"
	.string "a GRASS-type or a WATER-type.\p"
	.string "FIRE-types will just get buried\n"
	.string "under all this sand.\p"
	.string "Speaking of sand, you'll need to scale\n"
	.string "these sand slides to reach TARA.\p"
	.string "I heard there's a switch somewhere\n"
	.string "that turns them off.\p" 
	.string "Alright then, go for it!\n"
	.string "I know you've got this!$"

AmberCity_Gym_Text_GymGuidePostVictory:
	.string "Whoa, you rocked this gym like\n"
	.string "a hurricane!\p"
	.string "Not even the fiercest sandstorm\n"
	.string "can stop you!$"

