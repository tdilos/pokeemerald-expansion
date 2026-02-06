.set LOCALID_BOULDER1, 1 
.set LOCALID_BOULDER2, 2
.set LOCALID_BOULDER3, 14
.set LOCALID_BOULDER4, 13

HaewenTown_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, HaewenTown_Gym_OnTransition
	.byte 0

HaewenTown_Gym_OnTransition::
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	@setvar VAR_TEMP_5, 0
	@setvar VAR_TEMP_6, 0
	@setvar VAR_TEMP_7, 0
	@setvar VAR_TEMP_8, 0
	end


@VAR_0x8004 is the x-coord of the trigger, VAR_0x8005 is the y-coord
@VAR_0x8006 is the local id of the boulder on the trigger

HaewenTown_Gym_EventScript_Bridge1::
	lockall
	goto_if_eq VAR_TEMP_1, 100, HaewenTown_Gym_EventScript_BridgeAlreadyMade
	setvar VAR_0x8004, 15
	setvar VAR_0x8005, 38
	@call HaewenTown_Gym_EventScript_RollBoulderIntoLava
	applymovement LOCALID_BOULDER1, Common_Movement_WalkUp
	playse SE_M_STRENGTH
	waitmovement 0
	setvar VAR_TEMP_1, 100
	setmetatile 15, 37, METATILE_GymsIssho2_LavaBoulder, FALSE
	removeobject LOCALID_BOULDER1
	special DrawWholeMapView
	playse SE_PIN
	releaseall
	end

HaewenTown_Gym_EventScript_Bridge2::
	lockall
	goto_if_eq VAR_TEMP_2, 100, HaewenTown_Gym_EventScript_BridgeAlreadyMade
	setvar VAR_0x8004, 15
	setvar VAR_0x8005, 29
	applymovement LOCALID_BOULDER2, Common_Movement_WalkUp
	playse SE_M_STRENGTH
	waitmovement 0
	setvar VAR_TEMP_2, 100
	setmetatile 15, 28, METATILE_GymsIssho2_LavaBoulder, FALSE
	removeobject LOCALID_BOULDER2
	special DrawWholeMapView
	playse SE_PIN
	releaseall
	end

HaewenTown_Gym_EventScript_Bridge3::
	lockall
	goto_if_eq VAR_TEMP_3, 100, HaewenTown_Gym_EventScript_BridgeAlreadyMade
	setvar VAR_0x8004, 15
	setvar VAR_0x8005, 22
	applymovement LOCALID_BOULDER3, Common_Movement_WalkUp
	playse SE_M_STRENGTH
	waitmovement 0
	setvar VAR_TEMP_3, 100
	setmetatile 15, 21, METATILE_GymsIssho2_LavaBoulder, FALSE
	removeobject LOCALID_BOULDER3
	special DrawWholeMapView
	playse SE_PIN
	releaseall
	end

HaewenTown_Gym_EventScript_Bridge4::
	lockall
	goto_if_eq VAR_TEMP_4, 100, HaewenTown_Gym_EventScript_BridgeAlreadyMade
	setvar VAR_0x8004, 27
	setvar VAR_0x8005, 14
	applymovement LOCALID_BOULDER4, Common_Movement_WalkUp
	playse SE_M_STRENGTH
	waitmovement 0
	setvar VAR_TEMP_4, 100
	setmetatile 27, 13, METATILE_GymsIssho2_LavaBoulder, FALSE
	removeobject LOCALID_BOULDER4
	special DrawWholeMapView
	playse SE_PIN
	releaseall
	end

HaewenTown_Gym_EventScript_BridgeAlreadyMade::
	releaseall
	end

@HaewenTown_Gym_EventScript_RollBoulderIntoLava::
@	special GetObjectEventLocalIdByXYCoords
@	applymovement 2, Common_Movement_WalkUp
@	playse SE_M_STRENGTH
@	waitmovement 0
@	@delay 20
@	@waitse
@	@removeobject 2
@	@special DrawWholeMapView
@	@playse SE_TRUCK_DOOR
@	@waitse
@	return










HaewenTown_Gym_EventScript_Sigeric::
	trainerbattle_single TRAINER_SIGERIC, HaewenTown_Gym_Text_SigericIntro, HaewenTown_Gym_Text_SigericDefeated
	msgbox HaewenTown_Gym_Text_SigericPostBattle, MSGBOX_AUTOCLOSE
	end

HaewenTown_Gym_EventScript_Thryth::
	trainerbattle_single TRAINER_THRYTH, HaewenTown_Gym_Text_ThrythIntro, HaewenTown_Gym_Text_ThrythDefeated
	msgbox HaewenTown_Gym_Text_ThrythPostBattle, MSGBOX_AUTOCLOSE
	end

HaewenTown_Gym_EventScript_Hygelac::
	trainerbattle_single TRAINER_HYGELAC, HaewenTown_Gym_Text_HygelacIntro, HaewenTown_Gym_Text_HygelacDefeated
	msgbox HaewenTown_Gym_Text_HygelacPostBattle, MSGBOX_AUTOCLOSE
	end

HaewenTown_Gym_EventScript_Haereth::
	trainerbattle_single TRAINER_HAERETH, HaewenTown_Gym_Text_HaerethIntro, HaewenTown_Gym_Text_HaerethDefeated
	msgbox HaewenTown_Gym_Text_HaerethPostBattle, MSGBOX_AUTOCLOSE
	end

HaewenTown_Gym_EventScript_Earendel::
	trainerbattle_single TRAINER_EARENDEL, HaewenTown_Gym_Text_EarendelIntro, HaewenTown_Gym_Text_EarendelDefeated
	msgbox HaewenTown_Gym_Text_EarendelPostBattle, MSGBOX_AUTOCLOSE
	end

HaewenTown_Gym_EventScript_Eawynn::
	trainerbattle_single TRAINER_EAWYNN, HaewenTown_Gym_Text_EawynnIntro, HaewenTown_Gym_Text_EawynnDefeated
	msgbox HaewenTown_Gym_Text_EawynnPostBattle, MSGBOX_AUTOCLOSE
	end

HaewenTown_Gym_EventScript_Domfrith::
	trainerbattle_single TRAINER_DOMFRITH, HaewenTown_Gym_Text_DomfrithIntro, HaewenTown_Gym_Text_DomfrithDefeated
	msgbox HaewenTown_Gym_Text_DomfrithPostBattle, MSGBOX_AUTOCLOSE
	end

HaewenTown_Gym_EventScript_Ricbert::
	trainerbattle_single TRAINER_RICBERT, HaewenTown_Gym_Text_RicbertIntro, HaewenTown_Gym_Text_RicbertDefeated
	msgbox HaewenTown_Gym_Text_RicbertPostBattle, MSGBOX_AUTOCLOSE
	end

HaewenTown_Gym_Text_SigericIntro:
	.string "We're gonna rock you like a hurricane!$"

HaewenTown_Gym_Text_SigericDefeated:
	.string "Blown away!$"

HaewenTown_Gym_Text_SigericPostBattle:
	.string "You're good, but you're still\n"
	.string "no match for MOTHER ETHEL.$"

HaewenTown_Gym_Text_ThrythIntro:
	.string "Show me your hidden potential!$"

HaewenTown_Gym_Text_ThrythDefeated:
	.string "Incredible!$"

HaewenTown_Gym_Text_ThrythPostBattle:
	.string "Take courage and keep moving forward.$"

HaewenTown_Gym_Text_HygelacIntro:
	.string "There's hot lava everywhere.\n"
	.string "Doesn't it make you nervous?$"

HaewenTown_Gym_Text_HygelacDefeated:
	.string "Yowch!$"

HaewenTown_Gym_Text_HygelacPostBattle:
	.string "Most bugs would hate lava.\p"
	.string "But MIASMITE is adapted to heat\n"
	.string "and chthonic gases.\p"
	.string "Isn't it neat?$"

HaewenTown_Gym_Text_HaerethIntro:
	.string "I want to hold you tight and\n"
	.string "never let go!$"

HaewenTown_Gym_Text_HaerethDefeated:
	.string "Hihihihihi.$"

HaewenTown_Gym_Text_HaerethPostBattle:
	.string "I may look like a little girl.\n"
	.string "But I can do adult things too.$"

HaewenTown_Gym_Text_EarendelIntro:
	.string "Witness our dragon ascent!$"

HaewenTown_Gym_Text_EarendelDefeated:
	.string "Now behold our quiet descent.$"

HaewenTown_Gym_Text_EarendelPostBattle:
	.string "Dragons are renowned for their\n"
	.string "ferocious power.\p"
	.string "Do not take the trainers here lightly.$"

HaewenTown_Gym_Text_EawynnIntro:
	.string "Watch yourself. You're in the lair\n"
	.string "of the Dragon Clan.$"
	@.string "Can you overcome our challenge?$"

HaewenTown_Gym_Text_EawynnDefeated:
	.string "Impressive.$"

HaewenTown_Gym_Text_EawynnPostBattle:
	@.string "This gym is also a test of wits.\p"
	@.string "If you can't solve it, MOTHER ETHEL\n"
	.string "This gym is a test of mental endurance.\p"
	.string "If you can't hold up, MOTHER ETHEL\n"
	.string "won't waste her time on you.$"

HaewenTown_Gym_Text_DomfrithIntro:
	.string "For the honor of the Dragon Clan,\n"
	.string "I will defeat you here and now!$"

HaewenTown_Gym_Text_DomfrithDefeated:
	.string "What a disgrace!$"

HaewenTown_Gym_Text_DomfrithPostBattle:
	.string "You've proven your worth, trainer.\n"
	.string "Go forth and face MOTHER ETHEL!$"

HaewenTown_Gym_Text_RicbertIntro:
	.string "Here is true power!$"

HaewenTown_Gym_Text_RicbertDefeated:
	.string "Woooaaaargh!$"

HaewenTown_Gym_Text_RicbertPostBattle:
	.string "Dragons may seem invincible.\n"
	.string "But even they taste defeat sometimes.$"








HaewenTown_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_HAEWEN_GYM, HaewenTown_Gym_EventScript_GymGuidePostVictory
	msgbox HaewenTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	goto_if_eq VAR_HAEWEN_GYM_GUIDE, 0, HaewenTown_Gym_EventScript_GiveFreshWater
	release
	end

HaewenTown_Gym_EventScript_GiveFreshWater::
	giveitem ITEM_FRESH_WATER
	setvar VAR_HAEWEN_GYM_GUIDE, 1
	release
	end

HaewenTown_Gym_EventScript_GymGuidePostVictory::
	msgbox HaewenTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	goto_if_le VAR_HAEWEN_GYM_GUIDE, 1, HaewenTown_Gym_EventScript_GiveDragonGem
	release
	end

HaewenTown_Gym_EventScript_GiveDragonGem::
	giveitem ITEM_DRAGON_GEM
	setvar VAR_HAEWEN_GYM_GUIDE, 2
	release
	end

HaewenTown_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, HaewenTown_Gym_EventScript_GymStatueCertified
	goto HaewenTown_Gym_EventScript_GymStatue
	end

HaewenTown_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, HaewenTown_Gym_EventScript_GymStatueCertified
	goto HaewenTown_Gym_EventScript_GymStatue
	end

HaewenTown_Gym_EventScript_GymStatueCertified::
	msgbox HaewenTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

HaewenTown_Gym_EventScript_GymStatue::
	msgbox HaewenTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

HaewenTown_Gym_Text_GymStatue:
	.string "HAEWEN TOWN POKéMON GYM\p"
	.string "ETHEL'S CERTIFIED TRAINERS:\n"
	.string "JACE$"

HaewenTown_Gym_Text_GymStatueCertified:
	.string "HAEWEN TOWN POKéMON GYM\p"
	.string "ETHEL'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}, JACE$"

HaewenTown_Gym_Text_GymGuideAdvice:
	.string "Hey, cutie.\n"
	.string "What's up?\p"
	.string "This gym's leader is MOTHER ETHEL.\p"
	.string "She's also the leader of this town's\n"
	.string "clan of dragon tamers.\p"
	.string "Dragons may seem invincible, but\n"
	.string "even they have weaknesses.\p"
	.string "A FAIRY or ICE type should do\n"
	.string "the trick.\p"
	.string "One more thing.\p"
	.string "To get to ETHEL, you'll need to get\n"
	.string "past molten pits like this one.\p"
	.string "Don't try walking on it!\n"
	.string "It's hot!\p"
	.string "Instead push those boulders over it\n"
	.string "to make a bridge.\p"
	.string "Well good luck, cutie.\p"
	.string "And remember to keep cool.$"

HaewenTown_Gym_Text_GymGuidePostVictory:
	.string "Woohoo! You're on fire!\p"
	.string "Check your badge case.\p"
	.string "If you have eight badges, that means\n"
	.string "you're ready for the POKéMON LEAGUE!$"








HaewenTown_Gym_EventScript_Ethel::
	trainerbattle_single TRAINER_ETHEL_1, HaewenTown_Gym_Text_EthelIntro, HaewenTown_Gym_Text_EthelDefeated, HaewenTown_Gym_EventScript_EthelPostBattle, NO_MUSIC
	goto_if_unset FLAG_DEFEATED_HAEWEN_GYM, HaewenTown_Gym_EventScript_GiveDragonClaw
	msgbox HaewenTown_Gym_Text_EthelPostBattle, MSGBOX_DEFAULT
	release
	end

HaewenTown_Gym_EventScript_EthelPostBattle::
	message HaewenTown_Gym_Text_ReceivedWyrmBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special GetDifficulty
	switch VAR_RESULT
	case 0, HaewenTown_Gym_EventScript_EventScript_ExplainBadgeNormal
	case 1, HaewenTown_Gym_EventScript_EventScript_ExplainBadgeHardcore
	case 2, HaewenTown_Gym_EventScript_EventScript_ExplainBadgeInsane
	end

HaewenTown_Gym_EventScript_EventScript_ExplainBadgeNormal::
	goto_if_set FLAG_BADGE08_GET, HaewenTown_Gym_EventScript_AlreadyBeatAdderlyNormal
	msgbox HaewenTown_Gym_Text_WyrmBadgeNormalInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_BADGE07_GET
	setvar VAR_0x8008, 15
	call Common_EventScript_SetGymTrainers
	goto HaewenTown_Gym_EventScript_GiveDragonClaw
	end

HaewenTown_Gym_EventScript_AlreadyBeatAdderlyNormal::
	msgbox HaewenTown_Gym_Text_WyrmBadgeNormalInfoTakeThis2, MSGBOX_DEFAULT
	setflag FLAG_BADGE07_GET
	setvar VAR_0x8008, 15
	call Common_EventScript_SetGymTrainers
	goto HaewenTown_Gym_EventScript_GiveDragonClaw
	end

HaewenTown_Gym_EventScript_EventScript_ExplainBadgeHardcore::
	goto_if_set FLAG_BADGE08_GET, HaewenTown_Gym_EventScript_AlreadyBeatAdderlyHardcore
	msgbox HaewenTown_Gym_Text_WyrmBadgeHardcoreInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_BADGE07_GET
	setvar VAR_0x8008, 15
	call Common_EventScript_SetGymTrainers
	goto HaewenTown_Gym_EventScript_GiveDragonClaw
	end

HaewenTown_Gym_EventScript_AlreadyBeatAdderlyHardcore::
	msgbox HaewenTown_Gym_Text_WyrmBadgeHardcoreInfoTakeThis2, MSGBOX_DEFAULT
	setflag FLAG_BADGE07_GET
	setvar VAR_0x8008, 15
	call Common_EventScript_SetGymTrainers
	goto HaewenTown_Gym_EventScript_GiveDragonClaw
	end

HaewenTown_Gym_EventScript_EventScript_ExplainBadgeInsane::
	goto_if_set FLAG_BADGE08_GET, HaewenTown_Gym_EventScript_AlreadyBeatAdderlyInsane
	msgbox HaewenTown_Gym_Text_WyrmBadgeInsaneInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_BADGE07_GET
	setvar VAR_0x8008, 15
	call Common_EventScript_SetGymTrainers
	goto HaewenTown_Gym_EventScript_GiveDragonClaw
	end

HaewenTown_Gym_EventScript_AlreadyBeatAdderlyInsane::
	msgbox HaewenTown_Gym_Text_WyrmBadgeInsaneInfoTakeThis2, MSGBOX_DEFAULT
	setflag FLAG_BADGE07_GET
	setvar VAR_0x8008, 15
	call Common_EventScript_SetGymTrainers
	goto HaewenTown_Gym_EventScript_GiveDragonClaw
	end

HaewenTown_Gym_EventScript_GiveDragonClaw::
	giveitem ITEM_TM02
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DEFEATED_HAEWEN_GYM
	msgbox HaewenTown_Gym_Text_ExplainDragonClaw, MSGBOX_DEFAULT
	@msgbox HaewenTown_Gym_Text_EthelPostBattle, MSGBOX_DEFAULT
	release
	end




HaewenTown_Gym_Text_EthelIntro:
	.string "Welcome, young trainer.\p"
	.string "I am MOTHER ETHEL, gym leader and\n"
	.string "matron of the dragon clan.\p"
	.string "To some, I am also known as\n"
	.string "the mythic hunter.\p"
	.string "But that was a long time ago...\p"
	.string "Now I have a duty to the dragon clan\n"
	.string "here in HAEWEN TOWN.\p"
	.string "Dragons are a proud type with many\n"
	.string "fearsome abilities.\p"
	.string "Only the most courageous trainers\n"
	.string "can stand up to them.\p"
	.string "Well then, I hope your getting here\n"
	.string "wasn't just some fluke.\p"
	.string "Show me what your POKéMON can do!{PAUSE_MUSIC}{PLAY_BGM MUS_RG_ENCOUNTER_GYM_LEADER}$"

HaewenTown_Gym_Text_EthelDefeated:
	.string "Courageous indeed.\p"
	.string "As proof of your valor, I hereby\n"
	.string "bestow upon you this WYRM BADGE.$"

HaewenTown_Gym_Text_ReceivedWyrmBadge:
	.string "{PLAYER} received the WYRM BADGE\n"
	.string "from MOTHER ETHEL.$"

HaewenTown_Gym_Text_WyrmBadgeNormalInfoTakeThis:
	.string "The WYRM BADGE makes all POKéMON up to\n"
	.string "Level 56 obey without question.\p"
	.string "It also lets you use the HM move\n"
	.string "MAGNET RISE outside of battle.\p"
	.string "And lastly, a gift from me.$"

HaewenTown_Gym_Text_WyrmBadgeNormalInfoTakeThis2:
	.string "The WYRM BADGE makes all POKéMON up to\n"
	.string "Level 60 obey without question.\p"
	.string "It also lets you use the HM move\n"
	.string "MAGNET RISE outside of battle.\p"
	.string "And lastly, a gift from me.$"

HaewenTown_Gym_Text_WyrmBadgeHardcoreInfoTakeThis:
	.string "The WYRM BADGE makes all POKéMON up to\n"
	.string "Level 52 obey without question.\p"
	.string "It also lets you use the HM move\n"
	.string "MAGNET RISE outside of battle.\p"
	.string "And lastly, a gift from me.$"

HaewenTown_Gym_Text_WyrmBadgeHardcoreInfoTakeThis2:
	.string "The WYRM BADGE makes all POKéMON up to\n"
	.string "Level 55 obey without question.\p"
	.string "It also lets you use the HM move\n"
	.string "MAGNET RISE outside of battle.\p"
	.string "And lastly, a gift from me.$"

HaewenTown_Gym_Text_WyrmBadgeInsaneInfoTakeThis:
	.string "The WYRM BADGE makes all POKéMON up to\n"
	.string "Level 49 obey without question.\p"
	.string "It also lets you use the HM move\n"
	.string "MAGNET RISE outside of battle.\p"
	.string "And lastly, a gift from me.$"

HaewenTown_Gym_Text_WyrmBadgeInsaneInfoTakeThis2:
	.string "The WYRM BADGE makes all POKéMON up to\n"
	.string "Level 52 obey without question.\p"
	.string "It also lets you use the HM move\n"
	.string "MAGNET RISE outside of battle.\p"
	.string "And lastly, a gift from me.$"

HaewenTown_Gym_Text_ExplainDragonClaw:
	.string "That TM contains DRAGON CLAW.\p"
	.string "A powerful move befitting a powerful\n"
	.string "DRAGON POKéMON.$"

HaewenTown_Gym_Text_EthelPostBattle:
	.string "Your bright young face full of\n"
	.string "hope and aspiration.\p"
	.string "You remind me of myself when I\n"
	.string "was your age.\p"
	.string "Take courage, young trainer, even in\n"
	.string "the face of overwhelming adversity.\p"
	.string "Your journey may be hard and\n"
	.string "you may suffer many failures.\l"
	.string "But do not give into despair.\p"
	.string "It is through knowing both victory and\n"
	.string "defeat that we truly become strong.$"




