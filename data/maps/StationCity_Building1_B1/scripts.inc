StationCity_Building1_B1_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, StationCity_Building1_B1_OnFrame
	@map_script MAP_SCRIPT_ON_TRANSITION, StationCity_Building1_B1_OnTransition
	.byte 0

StationCity_Building1_B1_OnFrame:
	map_script_2 VAR_X_COSMOPOLIS_STATE, 0, StationCity_Building1_B1_EventScript_BettermanIntro
	.2byte 0


	@ State descriptions for VAR_X_COSMOPOLIS_STATE
	@ 0: First entering with Looker
	@ 1: While exploring Tier 1 worlds
	@ 2: Tier 2, before finding Tew
	@ 3: Tier 2, after finding Tew
	@ 4: During Xurkitree invasion


@StationCity_Building1_B1_OnTransition:
@	setrespawn HEAL_LOCATION_UMBER_TOWN_MALE_MCHOUSE_2F
@	end






StationCity_Building1_B1_EventScript_BettermanIntro2::
	@msgbox StationCity_Building1_B1_Text_WillYouHelpUs, MSGBOX_YESNO

	setvar VAR_X_COSMOPOLIS_STATE, 1
	releaseall
	end

@StationCity_Building1_B1_Text_WillYouHelpUs:
@	.string "$"




StationCity_Building1_B1_EventScript_BettermanIntro::
	lockall


	msgbox StationCity_Building1_B1_Text_BettermanJustAsWeFeared, MSGBOX_DEFAULT
	closemessage

	msgbox StationCity_Building1_B1_Text_BettermanTheSynderlings, MSGBOX_DEFAULT
	closemessage

	@msgbox StationCity_Building1_B1_Text_BettermanWhereToBegin, MSGBOX_DEFAULT
	@closemessage
	@goto StationCity_Building1_B1_EventScript_BettermanQuestions2

	releaseall
	end






StationCity_Building1_B1_Text_BettermanJustAsWeFeared:
	.string "BETTERMAN: I see.\n"
	.string "So it's just as we feared.\p"
	@.string "A small remnant of TEAM GENESIS really did\n"
	@.string "escape into ULTRA SPACE that day.\p"
	@.string "Including my renegade son.\n"
	@.string "The one you know as RAYNER.$"
	.string "TEAM GENESIS used the device from AB LABS\n"
	.string "to probe ULTRA SPACE again.\p"
	.string "And this time they may have attracted\n"
	.string "the attention of something far worse...$"

@StationCity_Building1_B1_Text_BettermanSomethingWorse:
@	.string "TEAM GENESIS'S plans were foiled,\n"
@	.string "but their activity in ULTRA SPACE\l"
@	.string "may have attracted the attention of\l"
@	.string "an even greater threat...$"

@StationCity_Building1_B1_Text_BettermanWhereToBegin:
@	.string "There is much to discuss and frankly\n"
@	.string "I'm not sure where to begin.\p"
@	.string "You must have a lot of questions, yes?\n"
@	.string "Why don't we start there.$"



StationCity_Building1_B1_Text_BettermanTheSynderlings:
	.string "They call themselves SYNDERLINGS.\n"
	.string "We don't yet know much about them.\p"
	.string "But so far, all encounters with them\n"
	.string "have been hostile.\p"
	.string "And their activities seem to be the cause\n"
	.string "of all these wormholes appearing.\p"
	.string "$"









StationCity_Building1_B1_EventScript_Betterman::
	lock
	faceplayer
StationCity_Building1_B1_EventScript_BettermanQuestions::
	msgbox StationCity_Building1_B1_Text_ICanExplain, MSGBOX_DEFAULT
StationCity_Building1_B1_EventScript_BettermanQuestions2::
	special ScriptMenu_CreateLilycoveSSTidalMultichoice
	@waitstate
	special GetLilycoveSSTidalSelection
	switch VAR_RESULT
	case 0, StationCity_Building1_B1_EventScript_WhereAreWe
	case 1, StationCity_Building1_B1_EventScript_WhatAreTheseWormholes
	case 2, StationCity_Building1_B1_EventScript_WhatIsAWormhole
	case 3, StationCity_Building1_B1_EventScript_WhoAreTheEnemy
	case 4, StationCity_Building1_B1_EventScript_WhatsSoDangerousAboutThem
	case 5, StationCity_Building1_B1_EventScript_WhatCanWeDoToStopThem
	case 6, StationCity_Building1_B1_EventScript_FinishQuestions
	case MULTI_B_PRESSED, StationCity_Building1_B1_EventScript_FinishQuestions
	release
	end

StationCity_Building1_B1_Text_ICanExplain:
	.string "BETTERMAN: If you need an explanation,\n"
	.string "I'm certainly capable of giving it.$"

StationCity_Building1_B1_EventScript_WhereAreWe::
	msgbox StationCity_Building1_B1_Text_WhereAreWe, MSGBOX_DEFAULT
	closemessage
	goto StationCity_Building1_B1_EventScript_BettermanQuestions

StationCity_Building1_B1_EventScript_WhatAreTheseWormholes::
	msgbox StationCity_Building1_B1_Text_BettermanWormholes, MSGBOX_DEFAULT
	closemessage
	goto StationCity_Building1_B1_EventScript_BettermanQuestions

StationCity_Building1_B1_EventScript_WhatIsAWormhole::
	msgbox StationCity_Building1_B1_Text_WhatIsAWormhole, MSGBOX_DEFAULT
	closemessage
	goto StationCity_Building1_B1_EventScript_BettermanQuestions

StationCity_Building1_B1_EventScript_WhoAreTheEnemy::
	msgbox StationCity_Building1_B1_Text_BettermanSynderlings, MSGBOX_DEFAULT
	closemessage
	goto StationCity_Building1_B1_EventScript_BettermanQuestions

StationCity_Building1_B1_EventScript_WhatsSoDangerousAboutThem::
	msgbox StationCity_Building1_B1_Text_BettermanDanger, MSGBOX_DEFAULT
	closemessage
	goto StationCity_Building1_B1_EventScript_BettermanQuestions

StationCity_Building1_B1_EventScript_WhatCanWeDoToStopThem::
	msgbox StationCity_Building1_B1_Text_BettermanWontLie, MSGBOX_DEFAULT
	closemessage
	goto StationCity_Building1_B1_EventScript_BettermanQuestions


StationCity_Building1_B1_Text_WhereAreWe:
	.string "Oh, this place? Believe it or not,\n"
	.string "it's an Ultra Space station!\p"
	.string "We're not sure who built it nor the why\n"
	.string "nor the how.\p"
	.string "Apparently it was abandoned when the\n"
	.string "International Police first found it.\p"
	.string "We've since converted it into our main\n"
	.string "base of operations.\p"
	.string "From here, we can more easily observe\n"
	.string "the enemy's constellation of worlds.$"
	@.string "From here, we can more easily\n"
	@.string "observe distant worlds.$"

StationCity_Building1_B1_Text_BettermanWormholes:
	.string "$"

StationCity_Building1_B1_Text_WhatIsAWormhole:
	.string "Well, uh...\p"
	.string "Imagine you attach a handle to a\n"
	.string "ball and...\p"
	.string "Oh, nevermind.\p"
	.string "Just know that stepping inside one will\n"
	.string "take you to a distant place.\p"
	.string "The smaller ones seem to connect only\n"
	.string "to regions of our own world.\p"
	.string "But the largest will take you to\n"
	.string "extraterrestrial worlds!\p"
	.string "From here, we've been monitoring wormhole\n"
	.string "activity in the HOENN and ISSHO regions.\p"
	.string "Feel free to ask SELWYN for more\n"
	.string "about that.$"

StationCity_Building1_B1_Text_BettermanSynderlings:
	.string "They call themselves SYNDERLINGS.\n"
	.string "We don't know where they come from.\p"
	.string "But they've managed to conquer a whole\n"
	.string "host of worlds.\p"
	.string "And we fear that they may come after\n"
	.string "our world next.\p"
	.string "So far we've tried to minimize our\n"
	.string "contact with them.\p"
	.string "But we'll need to face them eventually.\p"
	.string "$"

StationCity_Building1_B1_Text_BettermanDanger:
	.string "Somehow they've developed a way to\n"
	.string "assimilate outsiders.\p"
	.string "And force them to do their bidding.\p"
	.string "We don't fully understand it. But we've\n"
	.string "already lost some good people to it.\p"
	.string "And we're doing everything we can to\n"
	.string "avoid future losses.\p"
	.string "That is why we've elected to keep our\n"
	.string "team small and concentrate on sabotage\l"
	.string "rather than all-out war.$"

StationCity_Building1_B1_Text_BettermanWontLie:
	.string "I won't lie to you, {PLAYER}.\n"
	.string "Our odds of success are slim.\p"
	.string "The enemy is stronger than anything\n"
	.string "we've ever faced.\p"
	.string "And the more we fight them,\n"
	.string "the stronger they become.\p"
	.string "But we may be able to use the\n"
	.string "enemy's powers against them.\p"
	.string "Thanks to some new allies, we've learned\n"
	.string "about a device called a MEGA RING.\p"
	.string "$"

StationCity_Building1_B1_Text_WhatIsOvermind:
	.string "We're not sure. The files we've retrieved\n"
	.string "from TEAM GENESIS call it a POKéMON.\p"
	.string "But we have no data for it. And no one\n"
	.string "has ever seen it directly.\p"
	.string "What we do know is that it's\n"
	.string "a vast cosmic intelligence.\p"
	.string "And it's capable of manipulating\n"
	.string "entire worlds.\p"
	.string "It is the enemy's greatest weapon.\n"
	.string "One we must inevitably face.$"

StationCity_Building1_B1_Text_WhatAreArchons:
	.string "Conduits for OVERMIND'S power.\n"
	.string "They embody its hold on each world.$"

StationCity_Building1_B1_EventScript_FinishQuestions::
	goto_if_lt VAR_X_COSMOPOLIS_STATE, 1, StationCity_Building1_B1_EventScript_BettermanIntro2
	msgbox StationCity_Building1_B1_Text_AskMeAgain, MSGBOX_DEFAULT
	closemessage
	release
	end

StationCity_Building1_B1_Text_AskMeAgain:
	.string "This is all a lot to take in, I'm sure.\n"
	.string "Feel free to ask me again.$"








StationCity_Building1_B1_Text_NewWormholes:
	.string "We've detected new Ultra Wormholes\n"
	.string "around the HOENN region.\p"
	.string "They're in...$"

StationCity_Building1_B1_Text_Tier1Worlds:
	.string "ROUTE 109, PETALBURG WOODS,\n"
	.string "and DEWFORD MEADOW.$"

StationCity_Building1_B1_Text_Tier2Worlds:
	.string "ROUTE 110, ROUTE 111,\n"
	.string "and METEOR FALLS.$"

StationCity_Building1_B1_Text_Tier3Worlds:
	.string "JAGGED PASS, FORTREE CITY,\n"
	.string "and MT. PYRE.$"

StationCity_Building1_B1_Text_Tier4Worlds:
	.string "SHOAL CAVE, ROUTE 132,\n"
	.string "and OLD VICTORY ROAD.$"




