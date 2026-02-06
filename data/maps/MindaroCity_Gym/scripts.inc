MindaroCity_Gym_MapScripts::
	.byte 0

MindaroCity_Gym_EventScript_Bjorn::
	trainerbattle_single TRAINER_BJORN, MindaroCity_Gym_Text_BjornIntro, MindaroCity_Gym_Text_BjornDefeated
	msgbox MindaroCity_Gym_Text_BjornPostBattle, MSGBOX_AUTOCLOSE
	end

MindaroCity_Gym_EventScript_Einar::
	trainerbattle_single TRAINER_EINAR, MindaroCity_Gym_Text_EinarIntro, MindaroCity_Gym_Text_EinarDefeated
	msgbox MindaroCity_Gym_Text_EinarPostBattle, MSGBOX_AUTOCLOSE
	end

MindaroCity_Gym_EventScript_Sten::
	trainerbattle_single TRAINER_STEN, MindaroCity_Gym_Text_StenIntro, MindaroCity_Gym_Text_StenDefeated
	msgbox MindaroCity_Gym_Text_StenPostBattle, MSGBOX_AUTOCLOSE
	end

MindaroCity_Gym_EventScript_Freya::
	trainerbattle_single TRAINER_FREYA, MindaroCity_Gym_Text_FreyaIntro, MindaroCity_Gym_Text_FreyaDefeated
	msgbox MindaroCity_Gym_Text_FreyaPostBattle, MSGBOX_AUTOCLOSE
	end

MindaroCity_Gym_EventScript_Helga::
	trainerbattle_single TRAINER_HELGA, MindaroCity_Gym_Text_HelgaIntro, MindaroCity_Gym_Text_HelgaDefeated
	msgbox MindaroCity_Gym_Text_HelgaPostBattle, MSGBOX_AUTOCLOSE
	end

MindaroCity_Gym_EventScript_Bera::
	trainerbattle_single TRAINER_BERA, MindaroCity_Gym_Text_BeraIntro, MindaroCity_Gym_Text_BeraDefeated
	msgbox MindaroCity_Gym_Text_BeraPostBattle, MSGBOX_AUTOCLOSE
	end

MindaroCity_Gym_Text_BjornIntro:
	.string "Look who just slid on over.$"

MindaroCity_Gym_Text_BjornDefeated:
	.string "Wipeout!$"

MindaroCity_Gym_Text_BjornPostBattle:
	.string "How do you like the ice in this gym?\p"
	.string "You don't even need a board\n"
	.string "to slide on it!$"

MindaroCity_Gym_Text_EinarIntro:
	.string "I'm the princess's humble servant.\p"
	.string "I'll dispose of you for her.$"

MindaroCity_Gym_Text_EinarDefeated:
	.string "My lady, I've failed you.$"

MindaroCity_Gym_Text_EinarPostBattle:
	.string "I'm here to help the princess\n"
	.string "with whatever she needs!\p"
	.string "Though standing outside in the\n"
	.string "heat was pretty tough...$"

MindaroCity_Gym_Text_StenIntro:
	.string "I'm one cool dude.$"

MindaroCity_Gym_Text_StenDefeated:
	.string "Ice cold.$"

MindaroCity_Gym_Text_StenPostBattle:
	.string "Sometimes you just gotta relax and chill.$"

MindaroCity_Gym_Text_FreyaIntro:
	.string "You look lost. Are you sure\n"
	.string "you know where you're going?$"

MindaroCity_Gym_Text_FreyaDefeated:
	.string "Woah, you ran circles around us.$"

MindaroCity_Gym_Text_FreyaPostBattle:
	.string "You're getting warmer. The path\n"
	.string "to EIRA is on this side of the gym.$"

MindaroCity_Gym_Text_HelgaIntro:
	.string "Hey wait up! Check out this maneuver.$"

MindaroCity_Gym_Text_HelgaDefeated:
	.string "Far out!$"

MindaroCity_Gym_Text_HelgaPostBattle:
	.string "There's no skating over the rocks\n"
	.string "in this gym.\p"
	.string "But you can make it to EIRA without\n"
	.string "doing that. I promise!$"

MindaroCity_Gym_Text_BeraIntro:
	.string "Need a hint?$"

MindaroCity_Gym_Text_BeraDefeated:
	.string "Alright! Alright! I'll tell you!$"

MindaroCity_Gym_Text_BeraPostBattle:
	.string "Start in the top right corner.$"



MindaroCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MINDARO_GYM, MindaroCity_Gym_EventScript_GymGuidePostVictory
	msgbox MindaroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	goto_if_eq VAR_MINDARO_GYM_GUIDE, 0, MindaroCity_Gym_EventScript_GiveFreshWater
	release
	end

MindaroCity_Gym_EventScript_GiveFreshWater::
	giveitem ITEM_FRESH_WATER
	setvar VAR_MINDARO_GYM_GUIDE, 1
	release
	end

MindaroCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MindaroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	goto_if_le VAR_MINDARO_GYM_GUIDE, 1, MindaroCity_Gym_EventScript_GiveIceGem
	release
	end

MindaroCity_Gym_EventScript_GiveIceGem::
	giveitem ITEM_ICE_GEM
	setvar VAR_MINDARO_GYM_GUIDE, 2
	release
	end

MindaroCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, MindaroCity_Gym_EventScript_GymStatueCertified
	goto MindaroCity_Gym_EventScript_GymStatue
	end

MindaroCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, MindaroCity_Gym_EventScript_GymStatueCertified
	goto MindaroCity_Gym_EventScript_GymStatue
	end

MindaroCity_Gym_EventScript_GymStatueCertified::
	msgbox MindaroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MindaroCity_Gym_EventScript_GymStatue::
	msgbox MindaroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MindaroCity_Gym_Text_GymStatue:
	.string "MINDARO CITY POKéMON GYM$"

MindaroCity_Gym_Text_GymStatueCertified:
	.string "MINDARO CITY POKéMON GYM\p"
	.string "EIRA'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}, JACE$"

MindaroCity_Gym_Text_GymGuideAdvice:
	.string "Hey cutie.\n"
	.string "Brrrr, is it cold in here.\p"
	.string "This gym specializes in ICE types.\p"
	.string "Their freezing attacks can\n"
	.string "be devastating.\p"
	.string "But fortunately, they have a lot\n"
	.string "of weaknesses.\p"
	.string "FIRE, FIGHTING, ROCK, STEEL.\n"
	.string "Yup that's all of them!\p"
	.string "The leader, EIRA, is hiding in\n"
	.string "the back behind all this ice.\p"
	.string "You'll need to find a path to her\n"
	.string "by skating around on it.\p"
	.string "Alright, it may be tough to fight\n"
	.string "through all this snow and ice.\p"
	.string "But I know you'll push through!$"

MindaroCity_Gym_Text_GymGuidePostVictory:
	.string "You really heated things up in here!\p"
	.string "Not even the coldest snowstorm can\n"
	.string "douse the fire in your hearts!$"






MindaroCity_Gym_EventScript_Eira::
	trainerbattle_single TRAINER_EIRA_1, MindaroCity_Gym_Text_EiraIntro, MindaroCity_Gym_Text_EiraDefeated, MindaroCity_Gym_EventScript_EiraPostBattle, NO_MUSIC
	goto_if_unset FLAG_DEFEATED_MINDARO_GYM, MindaroCity_Gym_EventScript_GiveIceSkate
	msgbox MindaroCity_Gym_Text_EiraPostBattle, MSGBOX_DEFAULT
	release
	end

MindaroCity_Gym_EventScript_EiraPostBattle::
	message MindaroCity_Gym_Text_ReceivedRimeBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special GetDifficulty
	switch VAR_RESULT
	case 0, MindaroCity_Gym_EventScript_EventScript_ExplainBadgeNormal
	case 1, MindaroCity_Gym_EventScript_EventScript_ExplainBadgeHardcore
	case 2, MindaroCity_Gym_EventScript_EventScript_ExplainBadgeInsane
	end

MindaroCity_Gym_EventScript_EventScript_ExplainBadgeNormal::
	@goto_if_set FLAG_BADGE05_GET, MindaroCity_Gym_EventScript_AlreadyBeatCade
	msgbox MindaroCity_Gym_Text_RimeBadgeNormalInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_BADGE04_GET
	setvar VAR_0x8008, 12
	call Common_EventScript_SetGymTrainers
	goto MindaroCity_Gym_EventScript_GiveIceSkate
	end

MindaroCity_Gym_EventScript_EventScript_ExplainBadgeHardcore::
	msgbox MindaroCity_Gym_Text_RimeBadgeHardcoreInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_BADGE04_GET
	setvar VAR_0x8008, 12
	call Common_EventScript_SetGymTrainers
	goto MindaroCity_Gym_EventScript_GiveIceSkate
	end

MindaroCity_Gym_EventScript_EventScript_ExplainBadgeInsane::
	msgbox MindaroCity_Gym_Text_RimeBadgeInsaneInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_BADGE04_GET
	setvar VAR_0x8008, 12
	call Common_EventScript_SetGymTrainers
	goto MindaroCity_Gym_EventScript_GiveIceSkate
	end

@MindaroCity_Gym_EventScript_AlreadyBeatCade::
@	msgbox MindaroCity_Gym_Text_RimeBadgeInfoTakeThis2, MSGBOX_DEFAULT
@	setflag FLAG_BADGE04_GET
@	setvar VAR_0x8008, 12
@	call Common_EventScript_SetGymTrainers
@	goto MindaroCity_Gym_EventScript_GiveIceSkate
@	end

MindaroCity_Gym_EventScript_GiveIceSkate::
	giveitem ITEM_TM67
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	@setflag FLAG_RECEIVED_TM39
	msgbox MindaroCity_Gym_Text_ExplainIceSkate, MSGBOX_DEFAULT
	giveitem ITEM_WINTER_EMBLEM
	msgbox MindaroCity_Gym_Text_ExplainEmblem, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_MINDARO_GYM
	release
	end





MindaroCity_Gym_Text_EiraIntro:
	.string "{PLAYER}! You made it!\p"
	.string "I'm so excited, I've been looking forward\n"
	.string "to this all day!\p"
	.string "Ahem.\n"
	.string "As you know, I am EIRA,\l"
	.string "the leader of MINDARO GYM.\p"
	.string "I specialize in ICE type POKéMON.\p"
	.string "Don't let the warm weather\n"
	.string "outside fool you.\p"
	.string "We've trained in the bitter cold\n"
	.string "of MT SHIRO.\p"
	.string "My POKéMON and I thrive in\n"
	.string "harsh snowy weather.\p"
	.string "I hope you'll show me that you and\n"
	.string "your POKéMON can do the same!{PAUSE_MUSIC}{PLAY_BGM MUS_RG_ENCOUNTER_GYM_LEADER}$"

MindaroCity_Gym_Text_EiraDefeated:
	.string "Well done. You and your POKéMON\n"
	.string "broke through our snowstorm combo.\n"
	.string "You're now the proud owner\n"
	.string "of this RIME BADGE.$"

MindaroCity_Gym_Text_ReceivedRimeBadge:
	.string "{PLAYER} received the RIME BADGE\n"
	.string "from EIRA.$"

MindaroCity_Gym_Text_RimeBadgeNormalInfoTakeThis:
	.string "The RIME BADGE makes all POKéMON\n"
	.string "up to Level 44 obey without question.\p"
	.string "It also enables them to use the HM move\n"
	.string "THAW outside of battle.\p"
	.string "And since that battle was so much fun,\n"
	.string "I want you to take this too.$"

MindaroCity_Gym_Text_RimeBadgeHardcoreInfoTakeThis:
	.string "The RIME BADGE makes all POKéMON\n"
	.string "up to Level 40 obey without question.\p"
	.string "It also enables them to use the HM move\n"
	.string "THAW outside of battle.\p"
	.string "And since that battle was so much fun,\n"
	.string "I want you to take this too.$"

MindaroCity_Gym_Text_RimeBadgeInsaneInfoTakeThis:
	.string "The RIME BADGE makes all POKéMON\n"
	.string "up to Level 38 obey without question.\p"
	.string "It also enables them to use the HM move\n"
	.string "THAW outside of battle.\p"
	.string "And since that battle was so much fun,\n"
	.string "I want you to take this too.$"

@MindaroCity_Gym_Text_RimeBadgeInfoTakeThis2:
@	.string "The RIME BADGE makes all POKéMON\n"
@	.string "up to Level 48 obey without question.\p"
@	.string "It also enables them to use the HM move\n"
@	.string "THAW outside of battle.\p"
@	.string "And since that battle was so much fun,\n"
@	.string "I want you to take this too.$"

MindaroCity_Gym_Text_ExplainIceSkate:
	.string "That TM contains ICE SKATE.\p"
	.string "It's a move that gradually increases\n"
	.string "your Speed each turn.\p"
	.string "Use it to get the upper hand\n"
	.string "over your opponent.\p"
	.string "Now, where will you go next?\p"
	.string "Want to take the ski lift to\n"
	.string "the top of MT SHIRO?\p"
	.string "Just show the operators this emblem.$"

MindaroCity_Gym_Text_ExplainEmblem:
	.string "That emblem is carried by the clan\n"
	.string "on MT SHIRO.\p"
	.string "Normally, only they can take the\n"
	.string "ski lift to OFFWITE TOWN.\p"
	.string "But the operators will make an exception\n"
	.string "if you show them that SNOW EMBLEM.\p"
	.string "How do I know all this?\p"
	.string "Because the clan elder is my grandfather!\p"
	.string "Show him that badge I gave you.\n"
	.string "He'll give you something good, I promise!$"

MindaroCity_Gym_Text_EiraPostBattle:
	.string "That battle was really fun, {PLAYER}.\n"
	.string "We should do it again some time!$"

