EverGrandeCity_SidneysRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_SidneysRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_SidneysRoom_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_SidneysRoom_OnFrame
	.byte 0

EverGrandeCity_SidneysRoom_OnTransition:
	@setflag FLAG_MET_SCOTT_IN_EVERGRANDE
	@setflag FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT
	end

EverGrandeCity_SidneysRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_SIDNEY, EverGrandeCity_SidneysRoom_EventScript_TurnOffWeather
	call_if_set FLAG_DEFEATED_ELITE_4_SIDNEY, EverGrandeCity_SidneysRoom_EventScript_ResetAdvanceToNextRoom
	@call_if_eq VAR_ELITE_4_STATE, 1, EverGrandeCity_SidneysRoom_EventScript_CloseDoor
	call_if_eq VAR_ELITE_4_STATE, 2, EverGrandeCity_SidneysRoom_EventScript_CloseDoor
	end


EverGrandeCity_SidneysRoom_EventScript_TurnOffWeather::
	setweather WEATHER_NONE
	doweather
	return

EverGrandeCity_SidneysRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_SidneysRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_SidneysRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_SidneysRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_SidneysRoom_EventScript_PlayerTurnNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_SidneysRoom_OnFrame:
	@map_script_2 VAR_ELITE_4_STATE, 0, EverGrandeCity_SidneysRoom_EventScript_WalkInCloseDoor
	map_script_2 VAR_ELITE_4_STATE, 1, EverGrandeCity_SidneysRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_SidneysRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	@setvar VAR_ELITE_4_STATE, 1
	setvar VAR_ELITE_4_STATE, 2
	releaseall
	end






EverGrandeCity_SidneysRoom_EventScript_Ian::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_SIDNEY, EverGrandeCity_SidneysRoom_EventScript_IanPostBattle
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_SidneysRoom_Text_IanIntro, MSGBOX_DEFAULT
	setvar VAR_MUGSHOT_ID, MUGSHOT_IAN
	trainerbattle_no_intro TRAINER_IAN_0, EverGrandeCity_SidneysRoom_Text_IanDefeated
	goto EverGrandeCity_SidneysRoom_EventScript_IanDefeated
	end

EverGrandeCity_SidneysRoom_EventScript_IanPostBattle::
	msgbox EverGrandeCity_SidneysRoom_Text_IanPostBattle, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_SidneysRoom_EventScript_IanDefeated::
	setflag FLAG_DEFEATED_ELITE_4_SIDNEY
	call EverGrandeCity_SidneysRoom_EventScript_TurnOffWeather
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_SidneysRoom_Text_IanPostBattle, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_SidneysRoom_Text_IanIntro:
	.string "Howdy! I'm IAN of the\n"
	.string "ELITE FOUR.\p"
	.string "So you're the latest hotshot trainer\n"
	.string "from ISSHO, huh?\p"
	.string "I heard about what you did back\n"
	.string "in XANTHOS CITY.\p"
	@.string "You're a real hero, kid!\n"
	.string "You got the champion all riled up\n"
	.string "and everything!\p"
	@.string "Betcha didn't know he's been waiting a long\n"
	@.string "time for someone to take his place.\p"
	.string "You got me riled up too. Been a while since\n"
	.string "we saw any new faces around here.\p"
	.string "But enough yappin'. \n"
	.string "Let's get down to business!\p"
	.string "Hope you brought the beef cuz\n"
	.string "we're bringin' the heat!$"


	@.string "Welcome, my name is IAN\n"
	@.string "of the ELITE FOUR.\p"
	@.string "JUSTIN\p"
	@.string "He's wrong.\n"
	@.string "POKéMON are for battling!\p"
	@.string "{PLAYER}, I'll show you how a\n"
	@.string "real trainer fights!$"

EverGrandeCity_SidneysRoom_Text_IanDefeated:
	.string "Well, I'll be.$"

EverGrandeCity_SidneysRoom_Text_IanPostBattle:
	.string "Yup, I think I see what the champion\n"
	.string "sees in you now.\p"
	.string "You go on right ahead.$"











EverGrandeCity_SidneysRoom_EventScript_Sidney::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_SIDNEY, EverGrandeCity_SidneysRoom_EventScript_PostBattleSpeech
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_SidneysRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SIDNEY, EverGrandeCity_SidneysRoom_Text_Defeat
	goto EverGrandeCity_SidneysRoom_EventScript_Defeated
	end

EverGrandeCity_SidneysRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_SidneysRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_SidneysRoom_EventScript_Defeated::
	setflag FLAG_DEFEATED_ELITE_4_SIDNEY
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_SidneysRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_SidneysRoom_Text_IntroSpeech:
	.string "Welcome, challenger!\n"
	.string "I'm SIDNEY of the ELITE FOUR.\p"
	.string "I like that look you're giving me.\n"
	.string "I guess you'll give me a good match.\l"
	.string "That's good! Looking real good!\p"
	.string "All right! You and me, let's enjoy\n"
	.string "a battle that can only be staged\l"
	.string "here in the POKéMON LEAGUE!$"

EverGrandeCity_SidneysRoom_Text_Defeat:
	.string "Well, how do you like that? I lost!\n"
	.string "Eh, it was fun, so it doesn't matter.$"

EverGrandeCity_SidneysRoom_Text_PostBattleSpeech:
	.string "Well, listen to what this loser has\n"
	.string "to say.\p"
	.string "You've got what it takes to go far.\n"
	.string "Now, go on to the next room and enjoy\l"
	.string "your next battle!$"

