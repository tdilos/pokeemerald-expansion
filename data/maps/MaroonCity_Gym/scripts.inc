MaroonCity_Gym_MapScripts::
	.byte 0



MaroonCity_Gym_EventScript_Switch1::
	lockall
	goto_if_eq VAR_TEMP_0, 20, MaroonCity_Gym_EventScript_SwitchEnd
	playse SE_SWITCH
	waitse
	setmetatile 17, 13, METATILE_GymsIssho_Switch_Set, TRUE
	delay 30
	setmetatile 16, 16, METATILE_GymsIssho_SwitchFloor_North, FALSE
	special DrawWholeMapView
	playse SE_ICE_STAIRS
	waitse
	setvar VAR_TEMP_0, 20
	goto MaroonCity_Gym_EventScript_SwitchEnd
	end

MaroonCity_Gym_EventScript_Switch2::
	lockall
	goto_if_eq VAR_TEMP_1, 20, MaroonCity_Gym_EventScript_SwitchEnd
	playse SE_SWITCH
	waitse
	setmetatile 13, 11, METATILE_GymsIssho_Switch_Set, TRUE
	delay 30
	setmetatile 14, 10, METATILE_GymsIssho_SwitchFloor_West, FALSE
	special DrawWholeMapView
	playse SE_ICE_STAIRS
	waitse
	setvar VAR_TEMP_1, 20
	goto MaroonCity_Gym_EventScript_SwitchEnd
	end

MaroonCity_Gym_EventScript_Switch3::
	lockall
	goto_if_eq VAR_TEMP_2, 20, MaroonCity_Gym_EventScript_SwitchEnd
	playse SE_SWITCH
	waitse
	setmetatile 4, 10, METATILE_GymsIssho_Switch_Set, TRUE
	delay 30
	setmetatile 3, 9, METATILE_GymsIssho_SwitchFloor_West, FALSE
	special DrawWholeMapView
	playse SE_ICE_STAIRS
	waitse
	setvar VAR_TEMP_2, 20
	goto MaroonCity_Gym_EventScript_SwitchEnd
	end

MaroonCity_Gym_EventScript_Switch4::
	lockall
	goto_if_eq VAR_TEMP_3, 20, MaroonCity_Gym_EventScript_SwitchEnd
	playse SE_SWITCH
	waitse
	setmetatile 8, 10, METATILE_GymsIssho_Switch_Set, TRUE
	delay 30
	setmetatile 9, 13, METATILE_GymsIssho_SwitchFloor_East, FALSE
	special DrawWholeMapView
	playse SE_ICE_STAIRS
	waitse
	setvar VAR_TEMP_3, 20
	goto MaroonCity_Gym_EventScript_SwitchEnd
	end

MaroonCity_Gym_EventScript_Switch5::
	lockall
	goto_if_eq VAR_TEMP_4, 20, MaroonCity_Gym_EventScript_SwitchEnd
	playse SE_SWITCH
	waitse
	setmetatile 9, 15, METATILE_GymsIssho_Switch_Set, TRUE
	delay 30
	setmetatile 6, 16, METATILE_GymsIssho_SwitchFloor_South, FALSE
	special DrawWholeMapView
	playse SE_ICE_STAIRS
	waitse
	setvar VAR_TEMP_4, 20
	goto MaroonCity_Gym_EventScript_SwitchEnd
	end

MaroonCity_Gym_EventScript_Switch6::
	lockall
	goto_if_eq VAR_TEMP_5, 20, MaroonCity_Gym_EventScript_SwitchEnd
	playse SE_SWITCH
	waitse
	setmetatile 1, 11, METATILE_GymsIssho_Switch_Set, TRUE
	delay 30
	setmetatile 1, 9, METATILE_GymsIssho_SwitchFloor_North, FALSE
	special DrawWholeMapView
	playse SE_ICE_STAIRS
	waitse
	setvar VAR_TEMP_5, 20
	goto MaroonCity_Gym_EventScript_SwitchEnd
	end

MaroonCity_Gym_EventScript_Switch7::
	lockall
	goto_if_eq VAR_TEMP_6, 20, MaroonCity_Gym_EventScript_SwitchEnd
	playse SE_SWITCH
	waitse
	setmetatile 5, 3, METATILE_GymsIssho_Switch_Set, TRUE
	delay 30
	setmetatile 6, 2, METATILE_GymsIssho_SwitchFloor_East, FALSE
	special DrawWholeMapView
	playse SE_ICE_STAIRS
	waitse
	setvar VAR_TEMP_6, 20
	goto MaroonCity_Gym_EventScript_SwitchEnd
	end

MaroonCity_Gym_EventScript_SwitchEnd::
	releaseall
	end




MaroonCity_Gym_EventScript_Jurgen::
	trainerbattle_single TRAINER_JURGEN, MaroonCity_Gym_Text_JurgenIntro, MaroonCity_Gym_Text_JurgenDefeated
	msgbox MaroonCity_Gym_Text_JurgenPostBattle, MSGBOX_AUTOCLOSE
	end

MaroonCity_Gym_EventScript_Arnold::
	trainerbattle_single TRAINER_ARNOLD, MaroonCity_Gym_Text_ArnoldIntro, MaroonCity_Gym_Text_ArnoldDefeated
	msgbox MaroonCity_Gym_Text_ArnoldPostBattle, MSGBOX_AUTOCLOSE
	end

MaroonCity_Gym_EventScript_Berthold::
	trainerbattle_single TRAINER_BERTHOLD, MaroonCity_Gym_Text_BertholdIntro, MaroonCity_Gym_Text_BertholdDefeated
	msgbox MaroonCity_Gym_Text_BertholdPostBattle, MSGBOX_AUTOCLOSE
	end

MaroonCity_Gym_EventScript_Karl::
	trainerbattle_single TRAINER_KARL, MaroonCity_Gym_Text_KarlIntro, MaroonCity_Gym_Text_KarlDefeated
	msgbox MaroonCity_Gym_Text_KarlPostBattle, MSGBOX_AUTOCLOSE
	end

MaroonCity_Gym_EventScript_Ashton::
	trainerbattle_single TRAINER_ASHTON, MaroonCity_Gym_Text_AshtonIntro, MaroonCity_Gym_Text_AshtonDefeated
	msgbox MaroonCity_Gym_Text_AshtonPostBattle, MSGBOX_AUTOCLOSE
	end

MaroonCity_Gym_EventScript_Lalo::
	trainerbattle_single TRAINER_LALO, MaroonCity_Gym_Text_LaloIntro, MaroonCity_Gym_Text_LaloDefeated
	msgbox MaroonCity_Gym_Text_LaloPostBattle, MSGBOX_AUTOCLOSE
	end

MaroonCity_Gym_EventScript_Jeb::
	trainerbattle_single TRAINER_JEB, MaroonCity_Gym_Text_JebIntro, MaroonCity_Gym_Text_JebDefeated
	msgbox MaroonCity_Gym_Text_JebPostBattle, MSGBOX_AUTOCLOSE
	end


MaroonCity_Gym_Text_JurgenIntro:
	.string "Need a hint?$"

MaroonCity_Gym_Text_JurgenDefeated:
	.string "Alright, alright already.$"

MaroonCity_Gym_Text_JurgenPostBattle:
	.string "Have you tried pulling the levers\n"
	.string "in a different order?$"

MaroonCity_Gym_Text_ArnoldIntro:
	.string "You won't get my switch that easily.$"

MaroonCity_Gym_Text_ArnoldDefeated:
	.string "Clink, clank, CLUNK...$"

MaroonCity_Gym_Text_ArnoldPostBattle:
	.string "Once you pull a switch, it sticks in place.\n"
	.string "Think carefully before pulling it.$"

MaroonCity_Gym_Text_BertholdIntro:
	.string "Feeling a little mixed up?$"

MaroonCity_Gym_Text_BertholdDefeated:
	.string "Nope.$"

MaroonCity_Gym_Text_BertholdPostBattle:
	.string "We take pride in our work\n"
	.string "as engineers.\p"
	.string "You won't get past those arrows\n"
	.string "through normal means.$"

MaroonCity_Gym_Text_KarlIntro:
	.string "How do you like these floors?\n"
	.string "I made them myself.$"

MaroonCity_Gym_Text_KarlDefeated:
	.string "Test run aborted!$"

MaroonCity_Gym_Text_KarlPostBattle:
	.string "Pulling that lever will switch\n"
	.string "the direction of the yellow arrows.$"

MaroonCity_Gym_Text_AshtonIntro:
	.string "Hohoho. Fancy running into you.$"

MaroonCity_Gym_Text_AshtonDefeated:
	.string "Timbeeeeeerrrr...$"

MaroonCity_Gym_Text_AshtonPostBattle:
	.string "You won't get to the boss by\n"
	.string "just sliding around, you know.$"

MaroonCity_Gym_Text_LaloIntro:
	.string "Watch my plate-spinning technique.$"

MaroonCity_Gym_Text_LaloDefeated:
	.string "Crash.$"

MaroonCity_Gym_Text_LaloPostBattle:
	.string "It's not easy to juggle flat objects.$"

MaroonCity_Gym_Text_JebIntro:
	.string "Where there's a whip, there's a way.$"

MaroonCity_Gym_Text_JebDefeated:
	.string "Crack!$"

MaroonCity_Gym_Text_JebPostBattle:
	.string "We don't want to go to work today!$"






MaroonCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAROON_GYM, MaroonCity_Gym_EventScript_GymGuidePostVictory
	msgbox MaroonCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	goto_if_eq VAR_MAROON_GYM_GUIDE, 0, MaroonCity_Gym_EventScript_GiveFreshWater
	release
	end

MaroonCity_Gym_EventScript_GiveFreshWater::
	giveitem ITEM_FRESH_WATER
	setvar VAR_MAROON_GYM_GUIDE, 1
	release
	end

MaroonCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MaroonCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	goto_if_le VAR_MAROON_GYM_GUIDE, 1, MaroonCity_Gym_EventScript_GiveSteelGem
	release
	end

MaroonCity_Gym_EventScript_GiveSteelGem::
	giveitem ITEM_STEEL_GEM
	setvar VAR_MAROON_GYM_GUIDE, 2
	release
	end

MaroonCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, MaroonCity_Gym_EventScript_GymStatueCertified
	goto MaroonCity_Gym_EventScript_GymStatue
	end

MaroonCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, MaroonCity_Gym_EventScript_GymStatueCertified
	goto MaroonCity_Gym_EventScript_GymStatue
	end

MaroonCity_Gym_EventScript_GymStatueCertified::
	msgbox MaroonCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MaroonCity_Gym_EventScript_GymStatue::
	msgbox MaroonCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MaroonCity_Gym_Text_GymStatue:
	.string "MAROON CITY POKéMON GYM$"

MaroonCity_Gym_Text_GymStatueCertified:
	.string "MAROON CITY POKéMON GYM\p"
	.string "NIKOLAUS'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}, JACE$"


MaroonCity_Gym_Text_GymGuideAdvice:
	.string "Woah, hey there, cutie.\n"
	.string "This gym makes me dizzy.\p"
	.string "The floors here force you to move\n"
	.string "in a certain direction.\p"
	.string "You'll need to find a way through\n"
	.string "them to get to NIKOLAUS.\p"
	.string "He's the GYM LEADER here.\n"
	.string "His specialty is the STEEL type.\p"
	.string "STEEL types are known for\n"
	.string "their durability.\p"
	.string "But you can break through their defense\n"
	.string "with a FIGHTING, FIRE, or GROUND type.\p"
	.string "Well, good luck! And try not to\n"
	.string "get turned around in here.$"

MaroonCity_Gym_Text_GymGuidePostVictory:
	.string "Hey, you did it! Great job!\p"
	.string "You're just two more badges away\n"
	.string "from challenging the POKéMON LEAGUE!$"




MaroonCity_Gym_EventScript_Nikolaus::
	trainerbattle_single TRAINER_NIKOLAUS_1, MaroonCity_Gym_Text_NikolausIntro, MaroonCity_Gym_Text_NikolausDefeated, MaroonCity_Gym_EventScript_NikolausPostBattle, NO_MUSIC
	goto_if_unset FLAG_DEFEATED_MAROON_GYM, MaroonCity_Gym_EventScript_GiveShieldStrike
	msgbox MaroonCity_Gym_Text_NikolausPostBattle, MSGBOX_DEFAULT
	release
	end

MaroonCity_Gym_EventScript_NikolausPostBattle::
	message MaroonCity_Gym_Text_ReceivedAlloyBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special GetDifficulty
	switch VAR_RESULT
	case 0, MaroonCity_Gym_EventScript_EventScript_ExplainBadgeNormal
	case 1, MaroonCity_Gym_EventScript_EventScript_ExplainBadgeHardcore
	case 2, MaroonCity_Gym_EventScript_EventScript_ExplainBadgeInsane
	end

MaroonCity_Gym_EventScript_EventScript_ExplainBadgeNormal::
	msgbox MaroonCity_Gym_Text_AlloyBadgeNormalInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 14
	call Common_EventScript_SetGymTrainers
	goto MaroonCity_Gym_EventScript_GiveShieldStrike
	end

MaroonCity_Gym_EventScript_EventScript_ExplainBadgeHardcore::
	msgbox MaroonCity_Gym_Text_AlloyBadgeHardcoreInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 14
	call Common_EventScript_SetGymTrainers
	goto MaroonCity_Gym_EventScript_GiveShieldStrike
	end

MaroonCity_Gym_EventScript_EventScript_ExplainBadgeInsane::
	msgbox MaroonCity_Gym_Text_AlloyBadgeInsaneInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 14
	call Common_EventScript_SetGymTrainers
	goto MaroonCity_Gym_EventScript_GiveShieldStrike
	end

MaroonCity_Gym_EventScript_GiveShieldStrike::
	giveitem ITEM_TM74
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DEFEATED_MAROON_GYM
	msgbox MaroonCity_Gym_Text_ExplainShieldStrike, MSGBOX_DEFAULT
	@playse SE_DING_DONG
	@msgbox MaroonCity_Gym_Text_EndOfDemo, MSGBOX_DEFAULT
	release
	end

MaroonCity_Gym_Text_EndOfDemo:
	.string "You've reached the end of the demo.\p"
	.string "Thanks for playing!\n"
	.string "--TDILOS$"




MaroonCity_Gym_Text_NikolausIntro:
	.string "Willkommen.\p"
	.string "I am NIKOLAUS.\n"
	.string "The STEEL werkmeister.\p"
	.string "You want my gym to challenge, ja?\p"
	.string "You made it all the way here, so\n"
	.string "you're clearly motivated.\p"
	.string "My men worked hard designing\n"
	.string "these floors, you know.\p"
	.string "Then we shall put you\n"
	.string "to the final test.\p"
	.string "Withstand our mighty defense!\p"
	.string "\p"
	.string "That's right. I said “withstand.”\p"
	.string "The best offense is a good defense,\n"
	.string "as you'll soon see!{PAUSE_MUSIC}{PLAY_BGM MUS_RG_ENCOUNTER_GYM_LEADER}$"

MaroonCity_Gym_Text_NikolausDefeated:
	.string "Wunderbar.\n"
	.string "A job well done.\p"
	.string "You've earned the right to carry\n"
	.string "this ALLOY BADGE.\p"
	.string "Take it, it's yours!$"

MaroonCity_Gym_Text_ReceivedAlloyBadge:
	.string "{PLAYER} received the ALLOY BADGE\n"
	.string "from NIKOLAUS.$"

MaroonCity_Gym_Text_AlloyBadgeNormalInfoTakeThis:
	.string "The ALLOY BADGE makes all POKéMON\n"
	.string "up to Level 52 obey your commands.\p"
	.string "It also lets you use the HM move\n"
	.string "SURF outside of battle.\p"
	.string "And I want you to take this too.$"

MaroonCity_Gym_Text_AlloyBadgeHardcoreInfoTakeThis:
	.string "The ALLOY BADGE makes all POKéMON\n"
	.string "up to Level 49 obey your commands.\p"
	.string "It also lets you use the HM move\n"
	.string "SURF outside of battle.\p"
	.string "And I want you to take this too.$"

MaroonCity_Gym_Text_AlloyBadgeInsaneInfoTakeThis:
	.string "The ALLOY BADGE makes all POKéMON\n"
	.string "up to Level 45 obey your commands.\p"
	.string "It also lets you use the HM move\n"
	.string "SURF outside of battle.\p"
	.string "And I want you to take this too.$"

MaroonCity_Gym_Text_ExplainShieldStrike:
	.string "That TM contains SHIELD STRIKE.\p"
	.string "Its power comes from your POKéMON's\n"
	.string "Defense instead of its Attack.\p"
	.string "It turns a strong defense into an\n"
	.string "overwhelming onslaught!$"

MaroonCity_Gym_Text_NikolausPostBattle:
	.string "With SURF you can reach many\n"
	.string "remote parts of ISSHO.\p"
	.string "I think those RANGERS in town\n"
	.string "carry spare SURF HMs.\p"
	.string "Why don't you try asking them?$"






