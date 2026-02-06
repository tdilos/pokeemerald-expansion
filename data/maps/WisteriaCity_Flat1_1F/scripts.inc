WisteriaCity_Flat1_1F_MapScripts::
	.byte 0

WisteriaCity_Flat1_1F_EventScript_Bartender::
	lock
	faceplayer
	msgbox WisteriaCity_Flat1_1F_Text_Lemonade, MSGBOX_DEFAULT
	release
	end

WisteriaCity_Flat1_1F_Text_Lemonade:
	.string "Hmmm. For someone your age, I could\n"
	.string "make LEMONADE.$"
	@.string "It's ??? a glass, how about that?$"

WisteriaCity_Flat1_1F_EventScript_Bouncer::
	msgbox WisteriaCity_Flat1_1F_Text_NoKidsAllowed, MSGBOX_NPC
	end

WisteriaCity_Flat1_1F_Text_NoKidsAllowed:
	.string "No kids allowed upstairs!$"

WisteriaCity_Flat1_1F_EventScript_Roughneck1::
	msgbox WisteriaCity_Flat1_1F_Text_TookTooManyPunches, MSGBOX_NPC
	end

WisteriaCity_Flat1_1F_Text_TookTooManyPunches:
	.string "Uuugh...\n"
	.string "I took too many punches to the gut...$"

WisteriaCity_Flat1_1F_EventScript_Roughneck2::
	msgbox WisteriaCity_Flat1_1F_Text_WhatsTheMatter, MSGBOX_NPC
	end

WisteriaCity_Flat1_1F_Text_WhatsTheMatter:
	.string "Hicc! What's the matter? You never seen\n"
	.string "grown-ups play grown-up games?$"





WisteriaCity_Flat1_1F_EventScript_EggRuffian::
	lockall
	faceplayer
	goto_if_set FLAG_GOT_ZORUA_EGG, WisteriaCity_Flat1_1F_EventScript_PostEggComment
	msgbox WisteriaCity_Flat1_1F_Text_DontWantThisEgg, MSGBOX_NPC
	goto WisteriaCity_Flat1_1F_EventScript_TryGiveEgg
	end

WisteriaCity_Flat1_1F_EventScript_TryGiveEgg::
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, WisteriaCity_Flat1_1F_EventScript_NoRoomForEgg
	setflag FLAG_GOT_ZORUA_EGG
	giveegg SPECIES_ZORUA
	playfanfare MUS_LEVEL_UP
	message WisteriaCity_Flat1_1F_Text_ReceivedEggFromMan
	waitfanfare
	waitmessage
	release
	end

WisteriaCity_Flat1_1F_EventScript_PostEggComment::
	msgbox WisteriaCity_Flat1_1F_Text_EggRecycling, MSGBOX_NPC
	release
	end

WisteriaCity_Flat1_1F_EventScript_NoRoomForEgg::
	msgbox WisteriaCity_Flat1_1F_Text_DontHaveSpaceInYourParty, MSGBOX_NPC
	release
	end

WisteriaCity_Flat1_1F_Text_DontWantThisEgg::
    .string "I got this egg from the daycare,\n"
    .string "but I don't really want it.\p"
    .string "So, here you go.$"

WisteriaCity_Flat1_1F_Text_ReceivedEggFromMan::
    .string "{PLAYER} received an EGG\n"
    .string "from the man!$"

WisteriaCity_Flat1_1F_Text_DontHaveSpaceInYourParty::
    .string "…What do you mean, you don't have\n"
    .string "space for this in your party!?\p"
    .string "Man, I'm never gonna get rid\n"
    .string "of this thing…$"

WisteriaCity_Flat1_1F_Text_EggRecycling::
    .string "POKéMON breeding is great and all.\p"
    .string "But sometimes I wish they had an\n"
    .string "egg recycling center somewhere.$"









WisteriaCity_Flat1_1F_EventScript_GameRoughneck::
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_39
	goto_if_eq VAR_RESULT, TRUE, WisteriaCity_Flat1_1F_EventScript_Quest1Complete
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_39
	goto_if_eq VAR_RESULT, TRUE, WisteriaCity_Flat1_1F_EventScript_Quest1InProgress
	msgbox WisteriaCity_Flat1_1F_Text_LetsPlayAGame, MSGBOX_DEFAULT
	startquest QUEST_39
	release
	end

WisteriaCity_Flat1_1F_Text_LetsPlayAGame:
	.string "Hey kid, you wanna play too?\n"
	.string "Drink-free version for you, though.\p"
	.string "Bring the toughest POKéMON you have,\n"
	.string "and I'll try to take it out in one hit.\p"
	.string "All you gotta do is survive, kapeesh?$"

WisteriaCity_Flat1_1F_EventScript_Quest1InProgress::
	msgbox WisteriaCity_Flat1_1F_Text_Ready, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, WisteriaCity_Flat1_1F_EventScript_SkipGame
	setflag FLAG_SYS_WISTERIA_GAME_IN_PROGRESS
	msgbox WisteriaCity_Flat1_1F_Text_HereICome, MSGBOX_DEFAULT

	@special StartWisteriaGame1
	@waitstate
	trainerbattle_no_intro_no_whiteout TRAINER_ZOLTAN_1, WisteriaCity_Flat1_1F_Text_ZoltanDefeated

	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, WisteriaCity_Flat1_1F_EventScript_CompleteQuest1

	goto WisteriaCity_Flat1_1F_EventScript_TryAgain
	end

WisteriaCity_Flat1_1F_EventScript_SkipGame::
	release
	end

WisteriaCity_Flat1_1F_Text_Ready:
	.string "Are you ready?$"

WisteriaCity_Flat1_1F_Text_HereICome:
	.string "Then here I come!$"

WisteriaCity_Flat1_1F_Text_ZoltanDefeated:
	.string "!!!$"

WisteriaCity_Flat1_1F_EventScript_CompleteQuest1::
	msgbox WisteriaCity_Flat1_1F_Text_NotBadKid, MSGBOX_DEFAULT
	giveitem ITEM_POWER_BELT
	special HealPlayerParty
	clearflag FLAG_SYS_WISTERIA_GAME_IN_PROGRESS
	setflag FLAG_CLEARED_WISTERIA_GAME_1
	completequest QUEST_39
	release
	end


WisteriaCity_Flat1_1F_Text_NotBadKid:
	.string "Not bad, kid.\n"
	.string "I didn't think you had it in ya.\p"
	.string "Here, this one's on the house.$"

WisteriaCity_Flat1_1F_EventScript_Quest1Complete::
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_40
	goto_if_eq VAR_RESULT, TRUE, WisteriaCity_Flat1_1F_EventScript_Quest2Complete
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_40
	goto_if_eq VAR_RESULT, TRUE, WisteriaCity_Flat1_1F_EventScript_Quest2InProgress
	msgbox WisteriaCity_Flat1_1F_Text_TougherThanYouLook, MSGBOX_DEFAULT
	startquest QUEST_40
	release
	end

WisteriaCity_Flat1_1F_Text_TougherThanYouLook:
	.string "Alright, you're tougher than you look.\n"
	.string "I'll give you that.\p"
	.string "But let's see you take down one of mine.\n"
	.string "Think you can do that?$"

WisteriaCity_Flat1_1F_EventScript_Quest2InProgress::
	msgbox WisteriaCity_Flat1_1F_Text_Ready, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, WisteriaCity_Flat1_1F_EventScript_SkipGame
	setflag FLAG_SYS_WISTERIA_GAME_IN_PROGRESS
	msgbox WisteriaCity_Flat1_1F_Text_HereICome, MSGBOX_DEFAULT

	@special StartWisteriaGame2
	@waitstate
	trainerbattle_no_intro_no_whiteout TRAINER_ZOLTAN_2, WisteriaCity_Flat1_1F_Text_ZoltanDefeated

	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, WisteriaCity_Flat1_1F_EventScript_CompleteQuest2
	goto WisteriaCity_Flat1_1F_EventScript_TryAgain
	end

WisteriaCity_Flat1_1F_EventScript_TryAgain::
	msgbox WisteriaCity_Flat1_1F_Text_BetterLuckNextTime, MSGBOX_DEFAULT
	closemessage
	special HealPlayerParty
	clearflag FLAG_SYS_WISTERIA_GAME_IN_PROGRESS
	release
	end

WisteriaCity_Flat1_1F_Text_BetterLuckNextTime:
	.string "Nope, that ain't gonna cut it.\n"
	.string "Better luck next time, kid.$"

WisteriaCity_Flat1_1F_EventScript_CompleteQuest2::
	msgbox WisteriaCity_Flat1_1F_Text_WoahKid, MSGBOX_DEFAULT
	giveitem ITEM_LIFE_ORB
	special HealPlayerParty
	clearflag FLAG_SYS_WISTERIA_GAME_IN_PROGRESS
	setflag FLAG_CLEARED_WISTERIA_GAME_2
	completequest QUEST_40
	release
	end

WisteriaCity_Flat1_1F_Text_WoahKid:
	.string "Woah, we got a real pint-sized\n"
	.string "powerhouse over here!\p"
	.string "Here another one, on the house!$"

WisteriaCity_Flat1_1F_EventScript_Quest2Complete::
	clearflag FLAG_SYS_WISTERIA_GAME_IN_PROGRESS
	msgbox WisteriaCity_Flat1_1F_Text_ExplainLifeOrb, MSGBOX_DEFAULT	
	release
	end

WisteriaCity_Flat1_1F_Text_ExplainLifeOrb:
	.string "Give that LIFE ORB to one of your\n"
	.string "POKéMON to hold.\p"
	.string "It'll make 'em hit harder, but don't\n"
	.string "overuse it, alright?$"




