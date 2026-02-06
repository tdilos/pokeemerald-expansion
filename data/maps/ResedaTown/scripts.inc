ResedaTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ResedaTown_OnTransition
	.byte 0

ResedaTown_OnTransition:
	setflag FLAG_VISITED_RESEDA_TOWN
	end

ResedaTown_EventScript_GymSign::
	msgbox ResedaTown_Text_GymSign, MSGBOX_SIGN
	end

ResedaTown_EventScript_TownSign::
	msgbox ResedaTown_Text_TownSign, MSGBOX_SIGN
	end

ResedaTown_Text_GymSign:
	.string "RESEDA TOWN POKéMON GYM\n"
	.string "LEADER: ARTHUR\l"
	.string "“The master bug collector!”$"

ResedaTown_Text_TownSign:
	.string "RESEDA TOWN\n"
	.string "“A place where time stands still.”$"

ResedaTown_EventScript_Man::
	msgbox ResedaTown_Text_QuietCountryLife, MSGBOX_NPC
	end

ResedaTown_EventScript_Boy::
	msgbox ResedaTown_Text_Mushroom, MSGBOX_NPC
	end

ResedaTown_Text_QuietCountryLife:
	.string "Some people enjoy the hustle and bustle\n"
	.string "of the city.\p"
	.string "But for me, nothing beats the\n"
	.string "quiet country life.$"

ResedaTown_Text_Mushroom:
	.string "I found a mushroom on the ground!$"

ResedaTown_EventScript_Woman::
	msgbox ResedaTown_Text_Flowers, MSGBOX_NPC
	end

ResedaTown_Text_Flowers:
	.string "The flowers here are so beautiful.\n"
	.string "I could just stare at them forever...$"

ResedaTown_EventScript_TrainerTipsDisobedience::
	msgbox ResedaTown_Text_TrainerTipsDisobedience, MSGBOX_SIGN
	end

ResedaTown_Text_TrainerTipsDisobedience:
	.string "TRAINER TIPS\p"
	.string "An overleveled POKéMON might choose\n"
	.string "to disobey its trainer.\p"
	.string "By default, all POKéMON up to\n"
	.string "level 16 will naturally obey.$"



ResedaTown_EventScript_CheckSwarm::
	special BufferSwarmText
	msgbox ResedaTown_Text_SwarmSign, MSGBOX_SIGN
	end

ResedaTown_Text_SwarmSign:
	.string "Today a swarm of {STR_VAR_2}\n"
	.string "appeared on {STR_VAR_1}$"



ResedaTown_EventScript_GivePokemonDemo::
	lock
	faceplayer
	msgbox ResedaTown_Text_TakePokemon, MSGBOX_DEFAULT
	@getpartysize
	@compare VAR_RESULT, 6
	@goto_if_eq UmberTown_EventScript_PlayerHasFullParty
	@giveegg SPECIES_EEVEE
	@setmonability 1, 2
	givemon SPECIES_PLUX, 38, ITEM_DRASH_BERRY
	@setmonability 4, 1
	@setmonmove 4, 0, MOVE_WATERFALL
	@setmonmove 4, 1, MOVE_SMAZE
	@setmonmove 4, 2, MOVE_AEROBLAST
	@setmonmove 4, 3, MOVE_POWDER_PUNCH
	@givemon SPECIES_SLUGMA, 5, ITEM_PITCH_ROCK
	@setmonability 3, 1
	playfanfare MUS_LEVEL_UP
	msgbox ResedaTown_Text_ReceivedPokemon, MSGBOX_DEFAULT
	waitfanfare
	msgbox ResedaTown_Text_SeeYa, MSGBOX_DEFAULT
	release
	end

ResedaTown_Text_TakePokemon:
	.string "Please take this POKéMON.$"

ResedaTown_Text_ReceivedPokemon:
	.string "{PLAYER} received a POKéMON!$"

ResedaTown_Text_SeeYa:
	.string "See ya around, kid.$"

