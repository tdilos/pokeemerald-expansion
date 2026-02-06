.set LOCALID_SAILOR, 14

XanthosCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, XanthosCity_OnTransition
	.byte 0

XanthosCity_OnTransition:
	setflag FLAG_VISITED_XANTHOS_CITY
	setflag FLAG_HIDE_MAY
	setflag FLAG_HIDE_XANTHOS_POSTGAME_SAILOR
	call_if_set FLAG_IS_CHAMPION, XanthosCity_EventScript_RevealPostgameSailor
	end

XanthosCity_EventScript_RevealPostgameSailor:
	clearflag FLAG_HIDE_XANTHOS_POSTGAME_SAILOR
	addobject LOCALID_SAILOR
	return






XanthosCity_EventScript_LittleGirl::
	msgbox XanthosCity_Text_EenieMeenie, MSGBOX_NPC
	end

XanthosCity_Text_EenieMeenie:
	.string "Eenie meenie miney mo.\p"
	.string "Catch KOTORA by the toe.$"

XanthosCity_EventScript_Fisherman::
	msgbox XanthosCity_Text_FishingFromHere, MSGBOX_NPC
	end

XanthosCity_Text_FishingFromHere:
	.string "Fishing from here is not as easy\n"
	.string "as I thought...$"

XanthosCity_EventScript_Man::
	lock
	faceplayer
	msgbox XanthosCity_Text_GeneTherapy, MSGBOX_NPC
	release
	end

XanthosCity_Text_GeneTherapy:
	.string "DNA.\n"
	.string "Deoxyribonucleic acid.\p"
	.string "It's the blueprint for all life,\n"
	.string "including people and POKéMON.\p"
	.string "The doctors here in ISSHO claim that\n"
	.string "they've mapped the genome of\l"
	.string "almost every single POKéMON.\p"
	.string "In other words, they can tell you\n"
	.string "everything about a POKéMON\l"
	.string "before it's even born.\p"
	.string "They can even treat those POKéMON\n"
	.string "for genetic defects.\p"
	.string "It's amazing what modern medicine\n"
	.string "is capable of!$"

XanthosCity_EventScript_Lass::
	lock
	faceplayer
	msgbox XanthosCity_Text_HowManyKindsOfPokemon, MSGBOX_NPC
	release
	end

XanthosCity_Text_HowManyKindsOfPokemon:
	.string "How many kinds of POKéMON\n"
	.string "have you caught?\p"
	.string "I heard there are hundreds in total!$"

XanthosCity_EventScript_CoolTrainer::
	lock
	faceplayer
	msgbox XanthosCity_Text_TheSeaOfIssho, MSGBOX_NPC
	release
	end

XanthosCity_Text_TheSeaOfIssho:
	.string "The sea of ISSHO is known\n"
	.string "for its POKéMON diversity.\p"
	.string "You can find POKéMON here from HOENN,\n"
	.string "JOHTO, KANTO, and even SINNOH.$"

XanthosCity_EventScript_Policeman1::
	msgbox XanthosCity_Text_BeCareful, MSGBOX_NPC
	end

XanthosCity_Text_BeCareful:
	.string "Be careful. There have been reports of\n"
	.string "criminal gang activity around the city.$"

XanthosCity_EventScript_Policeman2::
	lock
	faceplayer
	msgbox XanthosCity_Text_Contraband, MSGBOX_NPC
	release
	end

XanthosCity_Text_Contraband:
	.string "You're not carrying any contraband\n"
	.string "items, are you?$"

XanthosCity_EventScript_Beauty::
	lock
	faceplayer
	msgbox XanthosCity_Text_FerryRuns, MSGBOX_NPC
	release
	end

XanthosCity_Text_FerryRuns:
	.string "The ferry service here runs to\n"
	.string "TURQUOISE CITY in the south\l"
	.string "and COBALT CITY in the west.\p"
	.string "It's convenient if you work and live in\n"
	.string "different cities like me.$"

XanthosCity_EventScript_Sailor::
	lock
	faceplayer
	msgbox XanthosCity_Text_BackBreakingWork, MSGBOX_NPC
	release
	end

XanthosCity_Text_BackBreakingWork:
	.string "Phew...\p"
	.string "Taking care of a ship is\n"
	.string "back-breaking work.$"

XanthosCity_EventScript_OldMan::
	msgbox XanthosCity_Text_WeatherBeautiful, MSGBOX_NPC
	end

XanthosCity_Text_WeatherBeautiful:
	.string "Ahhh! The weather here is always\n"
	.string "so beautiful.$"

XanthosCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox XanthosCity_Text_BeAnyPokemon, MSGBOX_NPC
	release
	end

XanthosCity_Text_BeAnyPokemon:
	.string "If you could be any POKéMON,\n"
	.string "what would you be?\p"
	.string "I'd be a SPEAROW!\n"
	.string "Piyu piiyuu!$"

XanthosCity_EventScript_TrainerTipsCovenantOrb::
	msgbox XanthosCity_Text_TrainerTipsCovenantOrb, MSGBOX_SIGN
	end

XanthosCity_Text_TrainerTipsCovenantOrb:
	.string "TRAINER TIPS\p"
	.string "POKéMON that evolve when traded can\n"
	.string "also evolve by using a COVENANT ORB.\p"
	.string "A COVENANT ORB manifests whenever\n"
	.string "a trainer receives a traded POKéMON.$"


XanthosCity_EventScript_CitySign::
	msgbox XanthosCity_Text_CitySign, MSGBOX_SIGN
	end

XanthosCity_EventScript_LibrarySign::
	msgbox XanthosCity_Text_LibrarySign, MSGBOX_SIGN
	end

XanthosCity_EventScript_MayHouseSign::
	msgbox XanthosCity_Text_MayHouseSign, MSGBOX_SIGN
	end

XanthosCity_Text_CitySign:
	.string "XANTHOS CITY\n"
	.string "“The sunshine metropolis.”$"

XanthosCity_Text_LibrarySign:
	.string "XANTHOS PUBLIC LIBRARY\n"
	.string "“Veritas sciscetur.”$"

XanthosCity_Text_MayHouseSign:
	.string "MAY'S HOUSE$"






XanthosCity_EventScript_PostgameSailor::
	lock
	faceplayer
	msgbox XanthosCity_Text_Ahoy, MSGBOX_DEFAULT
	@closemessage
	special ScriptMenu_CreateLilycoveSSTidalMultichoice
	waitstate
	special GetLilycoveSSTidalSelection
	switch VAR_RESULT
	case 0, XanthosCity_EventScript_ExitFirstTimeTicketSailSelect
	case 1, XanthosCity_EventScript_GoToBattleFrontierFirstTime
	case 2, XanthosCity_EventScript_GoToSouthernIslandFirstTime
	case 3, XanthosCity_EventScript_GoToNavelRockFirstTime
	@case 4, XanthosCity_EventScript_GoToBirthIslandFirstTime
	case 4, XanthosCity_EventScript_GoToPerennialPillarFirstTime
	case 5, XanthosCity_EventScript_GoToFarawayIslandFirstTime
	case 6, XanthosCity_EventScript_ExitFirstTimeTicketSailSelect
	case MULTI_B_PRESSED, XanthosCity_EventScript_ExitFirstTimeTicketSailSelect
	release
	end

XanthosCity_Text_Ahoy:
	.string "Ahoy! You came looking for\n"
	.string "more adventure, I presume.\p"
	.string "Whither are we bound?$"


XanthosCity_EventScript_GoToBattleFrontierFirstTime::
	closemessage
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 67
	waitstate
	release
	end

XanthosCity_EventScript_GoToSouthernIslandFirstTime::
	closemessage
	warp MAP_SOUTHERN_ISLAND_EXTERIOR, 13, 22
	waitstate
	release
	end

XanthosCity_EventScript_GoToNavelRockFirstTime::
	closemessage
	warp MAP_NAVEL_ROCK_HARBOR, 8, 4
	waitstate
	release
	end

XanthosCity_EventScript_GoToBirthIslandFirstTime::
	closemessage
	warp MAP_BIRTH_ISLAND_HARBOR, 8, 4
	waitstate
	release
	end

XanthosCity_EventScript_GoToFarawayIslandFirstTime::
	closemessage
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 13, 38
	waitstate
	release
	end

XanthosCity_EventScript_GoToPerennialPillarFirstTime::
	closemessage
	warp MAP_PERENNIAL_PILLAR_HARBOR, 8, 4
	waitstate
	release
	end

XanthosCity_EventScript_ExitFirstTimeTicketSailSelect::
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	closemessage
	release
	end


