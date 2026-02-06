CobaltCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CobaltCity_OnTransition
	.byte 0

CobaltCity_OnTransition:
	setflag FLAG_VISITED_COBALT_CITY
	setflag FLAG_HIDE_MAY
	end

CobaltCity_EventScript_GymSign::
	msgbox CobaltCity_Text_GymSign, MSGBOX_SIGN
	end

CobaltCity_EventScript_CitySign::
	msgbox CobaltCity_Text_CitySign, MSGBOX_SIGN
	end

CobaltCity_EventScript_DreamResortSign::
	msgbox CobaltCity_Text_DreamResortSign, MSGBOX_SIGN
	end

CobaltCity_EventScript_ContestHallSign::
	msgbox CobaltCity_Text_ContestHallSign, MSGBOX_SIGN
	end

CobaltCity_EventScript_NameRaterSign::
	msgbox CobaltCity_Text_NameRaterSign, MSGBOX_SIGN
	end

CobaltCity_Text_GymSign:
	.string "COBALT CITY POKéMON GYM\n"
	.string "LEADER: MYRTLE\l"
	.string "“Lover of unorthodox beauty.”$"
	@.string "“Lover of all things beautiful.”$"
	@.string "“Lover of beauty, botany, and battles!”$"

CobaltCity_Text_CitySign:
	.string "COBALT CITY\n"
	.string "“The city of natural wonder.”$"

CobaltCity_Text_DreamResortSign:
	.string "DREAM RESORT\n"
	.string "“Come stay in the hotel of your dreams!”$"

CobaltCity_Text_ContestHallSign:
	.string "POKéMON CONTEST HALL\n"
	.string "“The gathering place for TRAINERS!”$"

CobaltCity_Text_NameRaterSign:
	.string "NAME RATER'S HOUSE\n"
	.string "“POKéMON nicknames rated.”$"

CobaltCity_EventScript_TMClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CobaltCity_TMshop
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
CobaltCity_TMshop:
	.2byte ITEM_TM03  @ Water Pulse
	.2byte ITEM_TM09  @ Bullet Seed
	.2byte ITEM_TM43  @ Flame Charge
	.2byte ITEM_TM34  @ Shock Wave
	.2byte ITEM_TM48  @ Skill Swap
	.2byte ITEM_TM76  @ Body Slam
	.2byte ITEM_TM83  @ Work Up
	.2byte ITEM_TM55  @ Smack Down
	.2byte ITEM_NONE
	release
	end

CobaltCity_EventScript_BerryClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CobaltCity_BerryShop
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
CobaltCity_BerryShop:
	.2byte ITEM_WIKI_BERRY
	.2byte ITEM_AGUAV_BERRY
	.2byte ITEM_RAZZ_BERRY
	.2byte ITEM_NANAB_BERRY
	.2byte ITEM_PINAP_BERRY
	.2byte ITEM_MAGOST_BERRY
	.2byte ITEM_PAMTRE_BERRY
	.2byte ITEM_DURIN_BERRY
	.2byte ITEM_NONE
	release
	end

CobaltCity_EventScript_GymGirl::
	lockall
	faceplayer
	msgbox CobaltCity_Text_GymLeaderMissing, MSGBOX_NPC
	releaseall
	end

CobaltCity_Text_GymLeaderMissing:
	.string "Oh, you must be another trainer here\n"
	.string "to challenge the gym.\p"
	.string "Well, unfortunately our leader isn't\n"
	.string "here right now.\p"
	.string "We've been trying to find her all day.\p"
	.string "She was last seen going into town\n"
	.string "somewhere. Why don't you look there?\p"
	.string "I would join you, but I can't leave\n"
	.string "the gym unattended.$"

CobaltCity_EventScript_Man::
	msgbox CobaltCity_Text_WeHaveItAll, MSGBOX_NPC
	end

CobaltCity_Text_WeHaveItAll:
	.string "Forests, mountains, beaches,\n"
	.string "rivers, oceans.\p"
	.string "Here in COBALT CITY, we have it all!$"

CobaltCity_EventScript_Boy::
	msgbox CobaltCity_Text_SimpleGuy, MSGBOX_NPC
	end

CobaltCity_Text_SimpleGuy:
	.string "I'm just a simple guy following the\n"
	.string "path life has carved out for me.$"

CobaltCity_EventScript_Beauty::
	msgbox CobaltCity_Text_SoManyBerries, MSGBOX_NPC
	end

CobaltCity_Text_SoManyBerries:
	.string "There are so many different berries.\p"
	.string "Everything grows out here!\n"
	.string "I love it!$"

CobaltCity_EventScript_Sailor::
	msgbox CobaltCity_Text_FerryService, MSGBOX_NPC
	end

CobaltCity_Text_FerryService:
	.string "The ferry here runs to XANTHOS CITY\n"
	.string "and TURQUOISE CITY.\p"
	.string "It sure is convenient!$"


CobaltCity_EventScript_GivePokemonDemo::
	lock
	faceplayer
	msgbox CobaltCity_Text_TakePokemon, MSGBOX_DEFAULT
	@getpartysize
	@compare VAR_RESULT, 6
	@goto_if_eq UmberTown_EventScript_PlayerHasFullParty
	@giveegg SPECIES_EEVEE
	@setmonability 2, 2
	givemon SPECIES_CELEBI, 25, ITEM_NUGGET
	setmonmove 5, 0, MOVE_POLLENSPRAY
	@setmonmove 5, 1, MOVE_INGRAIN
	@setmonmove 5, 2, MOVE_HAIL
	@setmonmove 5, 3, MOVE_AQUA_RING
	@givemon SPECIES_SLUGMA, 5, ITEM_BLACK_SLUDGE
	@setmonability 3, 1
	@playfanfare MUS_LEVEL_UP
	@msgbox CobaltCity_Text_ReceivedPokemon, MSGBOX_DEFAULT
	@waitfanfare
	giveitem ITEM_HM04
	msgbox CobaltCity_Text_SeeYa, MSGBOX_DEFAULT
	release
	end

CobaltCity_Text_TakePokemon:
	.string "Please take this POKéMON.$"

CobaltCity_Text_ReceivedPokemon:
	.string "{PLAYER} received a POKéMON.$"

CobaltCity_Text_SeeYa:
	.string "See ya around, kid.$"


