CobaltCity_Gym_MapScripts::
	.byte 0

CobaltCity_Gym_EventScript_SecretPassage::
	playse SE_M_SAND_ATTACK
	end


CobaltCity_Gym_EventScript_Myrtle::
	trainerbattle_single TRAINER_MYRTLE_1, CobaltCity_Gym_Text_MyrtleIntro, CobaltCity_Gym_Text_MyrtleDefeated, CobaltCity_Gym_EventScript_MyrtlePostBattle, NO_MUSIC
	goto_if_unset FLAG_DEFEATED_COBALT_GYM, CobaltCity_Gym_EventScript_GivePollenspray
	msgbox CobaltCity_Gym_Text_MyrtlePostBattle, MSGBOX_DEFAULT
	release
	end

CobaltCity_Gym_EventScript_MyrtlePostBattle::
	message CobaltCity_Gym_Text_ReceivedHyacinthBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special GetDifficulty
	switch VAR_RESULT
	case 0, CobaltCity_Gym_EventScript_EventScript_ExplainBadgeNormal
	case 1, CobaltCity_Gym_EventScript_EventScript_ExplainBadgeHardcore
	case 2, CobaltCity_Gym_EventScript_EventScript_ExplainBadgeInsane
	end

CobaltCity_Gym_EventScript_EventScript_ExplainBadgeNormal::
	msgbox CobaltCity_Gym_Text_HyacinthBadgeNormalInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_BADGE03_GET
	setvar VAR_0x8008, 11
	call Common_EventScript_SetGymTrainers
	goto CobaltCity_Gym_EventScript_GivePollenspray
	end

CobaltCity_Gym_EventScript_EventScript_ExplainBadgeHardcore::
	msgbox CobaltCity_Gym_Text_HyacinthBadgeHardcoreInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_BADGE03_GET
	setvar VAR_0x8008, 11
	call Common_EventScript_SetGymTrainers
	goto CobaltCity_Gym_EventScript_GivePollenspray
	end

CobaltCity_Gym_EventScript_EventScript_ExplainBadgeInsane::
	msgbox CobaltCity_Gym_Text_HyacinthBadgeInsaneInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_BADGE03_GET
	setvar VAR_0x8008, 11
	call Common_EventScript_SetGymTrainers
	goto CobaltCity_Gym_EventScript_GivePollenspray
	end

CobaltCity_Gym_EventScript_GivePollenspray::
	giveitem ITEM_TM59
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	@setflag FLAG_RECEIVED_TM39
	msgbox CobaltCity_Gym_Text_ExplainPollenspray, MSGBOX_DEFAULT
	@playse SE_DING_DONG
	@msgbox CobaltCity_Gym_Text_EndOfDemo, MSGBOX_DEFAULT
	giveitem ITEM_TRI_PASS
	msgbox CobaltCity_Gym_Text_ExplainTriPass, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_COBALT_GYM
	release
	end



@CobaltCity_Gym_Text_EndOfDemo:
@	.string "You've reached the end of the demo.\p"
@	.string "Thanks for playing!\n"
@	.string "--TDILOS$"

CobaltCity_Gym_Text_MyrtleIntro:
	.string "Hello again, {PLAYER}. I didn't formally\n"
	.string "introduce myself last time.\p"
	.string "I am MYRTLE, COBALT CITY'S GYM LEADER\n"
	.string "and GRASS type specialist.\p"
	.string "My POKéMON and I will dazzle you\n"
	.string "with our moves.\p"
	.string "Come, show us what you can do!{PAUSE_MUSIC}{PLAY_BGM MUS_RG_ENCOUNTER_GYM_LEADER}$"

CobaltCity_Gym_Text_MyrtleDefeated:
	.string "Amazing! Truly spectacular!\p"
	.string "You and your POKéMON put on a\n"
	.string "stunning display.\p"
	.string "Try as we might, we were unable to\n"
	.string "make you falter.\p"
	.string "This HYACINTH BADGE belongs to you now.$"

CobaltCity_Gym_Text_ReceivedHyacinthBadge:
	.string "{PLAYER} received the HYACINTH BADGE\n"
	.string "from MYRTLE.$"

CobaltCity_Gym_Text_HyacinthBadgeNormalInfoTakeThis:
	.string "The HYACINTH BADGE makes all POKéMON\n"
	.string "up to Level 40 obey without question.\p"
	.string "It also enables them to use the HM move\n"
	.string "STRENGTH outside of battle.\p"
	.string "And you can have this as well.$"

CobaltCity_Gym_Text_HyacinthBadgeHardcoreInfoTakeThis:
	.string "The HYACINTH BADGE makes all POKéMON\n"
	.string "up to Level 37 obey without question.\p"
	.string "It also enables them to use the HM move\n"
	.string "STRENGTH outside of battle.\p"
	.string "And you can have this as well.$"

CobaltCity_Gym_Text_HyacinthBadgeInsaneInfoTakeThis:
	.string "The HYACINTH BADGE makes all POKéMON\n"
	.string "up to Level 35 obey without question.\p"
	.string "It also enables them to use the HM move\n"
	.string "STRENGTH outside of battle.\p"
	.string "And you can have this as well.$"

CobaltCity_Gym_Text_ExplainPollenspray:
	.string "That TECHNICAL MACHINE, TM59,\n"
	.string "contains POLLENSPRAY.\p"
	.string "It sprays the opponent with seeds\n"
	.string "that may drain their health.\p"
	.string "...\p"
	.string "Well now, if you wish to continue your\n"
	.string "POKéMON LEAGUE challenge...\p"
	.string "I would suggest traveling to\n"
	.string "TURQUOISE CITY next.\p"
	.string "\p"
	.string "Oh, you don't have a TRI PASS, do you?\p"
	.string "Here, you can take one of mine.$"

CobaltCity_Gym_Text_ExplainTriPass:
	.string "That TRI PASS will let you board\n"
	.string "the ferry to TURQUOISE CITY.\p"
	.string "You'll meet all sorts of trainers\n"
	.string "in southern ISSHO.$"

CobaltCity_Gym_Text_MyrtlePostBattle:
	.string "Treat your POKéMON like they're\n"
	.string "your close friends.\p"
	.string "I know you'll help each through\n"
	.string "any adversity!$"






CobaltCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_COBALT_GYM, CobaltCity_Gym_EventScript_GymGuidePostVictory
	msgbox CobaltCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	goto_if_eq VAR_COBALT_GYM_GUIDE, 0, CobaltCity_Gym_EventScript_GiveFreshWater
	release
	end

CobaltCity_Gym_EventScript_GiveFreshWater::
	giveitem ITEM_FRESH_WATER
	setvar VAR_COBALT_GYM_GUIDE, 1
	release
	end

CobaltCity_Gym_EventScript_GymGuidePostVictory::
	msgbox CobaltCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	goto_if_le VAR_COBALT_GYM_GUIDE, 1, CobaltCity_Gym_EventScript_GiveGrassGem
	release
	end

CobaltCity_Gym_EventScript_GiveGrassGem::
	giveitem ITEM_GRASS_GEM
	setvar VAR_COBALT_GYM_GUIDE, 2
	release
	end

CobaltCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, CobaltCity_Gym_EventScript_GymStatueCertified
	goto CobaltCity_Gym_EventScript_GymStatue
	end

CobaltCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, CobaltCity_Gym_EventScript_GymStatueCertified
	goto CobaltCity_Gym_EventScript_GymStatue
	end

CobaltCity_Gym_EventScript_GymStatueCertified::
	msgbox CobaltCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

CobaltCity_Gym_EventScript_GymStatue::
	msgbox CobaltCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

CobaltCity_Gym_Text_GymStatue:
	.string "COBALT CITY POKéMON GYM\p"
	.string "MYRTLE'S CERTIFIED TRAINERS:\n"
	.string "JACE$"

CobaltCity_Gym_Text_GymStatueCertified:
	.string "COBALT CITY POKéMON GYM\p"
	.string "MYRTLE'S CERTIFIED TRAINERS:\n"
	.string "JACE, {PLAYER}$"

CobaltCity_Gym_Text_GymGuideAdvice:
	.string "Hey there, cutie. Long time, no see.\p"
	.string "This gym is filled with hedges, but I\n"
	.string "heard that there are secret passages\l"
	.string "to get from one side to the other.\p"
	.string "The leader of this gym is MYRTLE.\n"
	.string "She specializes in GRASS type POKéMON.\p"
	.string "The good news is that GRASS types have\n"
	.string "many weaknesses.\p"
	.string "FIRE... ICE... FLYING...\p"
	.string "BUG, and... POISON.\l"
	.string "Yup, that's all of them.\p"
	.string "If you bring any of those types,\n"
	.string "you'll have a much easier time.$"

CobaltCity_Gym_Text_GymGuidePostVictory:
	.string "That battle was astonishing! Your\n"
	.string "POKéMON put on a beautiful display.\p"
	.string "And you got the HYACINTH BADGE.\n"
	.string "Hurray!$"






CobaltCity_Gym_EventScript_Griffin::
	trainerbattle_single TRAINER_GRIFFIN, CobaltCity_Gym_Text_GriffinIntro, CobaltCity_Gym_Text_GriffinDefeated
	msgbox CobaltCity_Gym_Text_GriffinPostBattle, MSGBOX_AUTOCLOSE
	end

CobaltCity_Gym_EventScript_Emily::
	trainerbattle_single TRAINER_EMILY, CobaltCity_Gym_Text_EmilyIntro, CobaltCity_Gym_Text_EmilyDefeated
	msgbox CobaltCity_Gym_Text_EmilyPostBattle, MSGBOX_AUTOCLOSE
	end

CobaltCity_Gym_EventScript_Lluvia::
	trainerbattle_single TRAINER_LLUVIA, CobaltCity_Gym_Text_LluviaIntro, CobaltCity_Gym_Text_LluviaDefeated
	msgbox CobaltCity_Gym_Text_LluviaPostBattle, MSGBOX_AUTOCLOSE
	end

CobaltCity_Gym_EventScript_Heather::
	trainerbattle_single TRAINER_HEATHER, CobaltCity_Gym_Text_HeatherIntro, CobaltCity_Gym_Text_HeatherDefeated
	msgbox CobaltCity_Gym_Text_HeatherPostBattle, MSGBOX_AUTOCLOSE
	end

CobaltCity_Gym_Text_GriffinIntro:
	.string "Intruder alert! Trainer spotted!$"

CobaltCity_Gym_Text_GriffinDefeated:
	.string "Too strong!$"

CobaltCity_Gym_Text_GriffinPostBattle:
	.string "I'm the only boy in this gym.\p"
	.string "Hehehe. Isn't it great?$"

CobaltCity_Gym_Text_EmilyIntro:
	.string "If you can beat me, I'll tell you a\n"
	.string "secret about this gym.$"

CobaltCity_Gym_Text_EmilyDefeated:
	.string "Okay, okay, enough already!$"

CobaltCity_Gym_Text_EmilyPostBattle:
	.string "Each of the long hedges has a secret\n"
	.string "hole to get to the other side.\p"
	.string "You can find it by starting at the\n"
	.string "left and walking so many paces.\p"
	.string "The blues flowers are supposed to\n"
	.string "count how many paces.\p"
	.string "But I can't remember how it works...\p"
	.string "All I know is that these flowers\n"
	.string "behind me somehow mean 11.$"

CobaltCity_Gym_Text_LluviaIntro:
	.string "Oh my! A trainer came through the hedge.$"

CobaltCity_Gym_Text_LluviaDefeated:
	.string "A strong trainer too!$"

CobaltCity_Gym_Text_LluviaPostBattle:
	.string "I carry a parasol everywhere I go.\p"
	.string "It doesn't matter that we're indoors.$"

CobaltCity_Gym_Text_HeatherIntro:
	.string "You're the trainer who brought\n"
	.string "MYRTLE back.\p"
	.string "Thanks for finding her, but don't think\n"
	.string "that means I'll go easy on you!$"

CobaltCity_Gym_Text_HeatherDefeated:
	.string "Amazing!$"

CobaltCity_Gym_Text_HeatherPostBattle:
	.string "You went through QUARTZ CAVE to come\n"
	.string "all the way out here?\p"
	.string "No wonder you're so strong!$"
