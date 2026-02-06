EverGrandeCity_GlaciasRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_GlaciasRoom_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_GlaciasRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_GlaciasRoom_OnWarp
	.byte 0

EverGrandeCity_GlaciasRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_GlaciasRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_GlaciasRoom_EventScript_PlayerTurnNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_GlaciasRoom_OnFrame:
	@map_script_2 VAR_ELITE_4_STATE, 2, EverGrandeCity_GlaciasRoom_EventScript_WalkInCloseDoor
	map_script_2 VAR_ELITE_4_STATE, 0, EverGrandeCity_GlaciasRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_GlaciasRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	@setvar VAR_ELITE_4_STATE, 3
	setvar VAR_ELITE_4_STATE, 1
	releaseall
	end

EverGrandeCity_GlaciasRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_GLACIA, EverGrandeCity_GlaciasRoom_EventScript_TurnOffWeather
	call_if_set FLAG_DEFEATED_ELITE_4_GLACIA, EverGrandeCity_GlaciasRoom_EventScript_ResetAdvanceToNextRoom
	@call_if_eq VAR_ELITE_4_STATE, 3, EverGrandeCity_GlaciasRoom_EventScript_CloseDoor
	call_if_eq VAR_ELITE_4_STATE, 1, EverGrandeCity_GlaciasRoom_EventScript_CloseDoor
	end

EverGrandeCity_GlaciasRoom_EventScript_TurnOffWeather::
	setweather WEATHER_NONE
	doweather
	return

EverGrandeCity_GlaciasRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_GlaciasRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return






EverGrandeCity_GlaciasRoom_EventScript_Lisia::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_GLACIA, EverGrandeCity_GlaciasRoom_EventScript_LisiaPostBattle
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_GlaciasRoom_Text_LisiaIntro, MSGBOX_DEFAULT
	setvar VAR_MUGSHOT_ID, MUGSHOT_LISIA
	trainerbattle_no_intro TRAINER_LISIA_0, EverGrandeCity_GlaciasRoom_Text_LisiaDefeated
	goto EverGrandeCity_GlaciasRoom_EventScript_LisiaDefeated
	end

EverGrandeCity_GlaciasRoom_EventScript_LisiaPostBattle::
	msgbox EverGrandeCity_GlaciasRoom_Text_LisiaPostBattle, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_GlaciasRoom_EventScript_LisiaDefeated::
	setflag FLAG_DEFEATED_ELITE_4_GLACIA
	call EverGrandeCity_GlaciasRoom_EventScript_TurnOffWeather
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_GlaciasRoom_Text_LisiaPostBattle, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_GlaciasRoom_Text_LisiaIntro:
	.string "Welcome, challenger.\n"
	.string "I am LISIA of the ELITE FOUR.\p"
	.string "I was once a CONTEST IDOL before\n"
	.string "I became serious as a trainer.\p"
	.string "And now we've finally made it here,\n"
	.string "the POKéMON LEAGUE.\p"
	@.string "And how about you? Think you've got\n"
	@.string "what it takes to be a star trainer?\p"
	.string "Let's if you've got what it takes\n"
	.string "to be a superstar trainer.\p"
	.string "Show me how elegantly your POKéMON\n"
	.string "dance in the rain!$"
	@.string "My POKéMON and I are always\n"
	@.string "aiming for new heights.\p"
	@.string "And now we've finally made it here,\n"
	@.string "the POKéMON LEAGUE.\p"
	@.string "Don't think just because I'm new\n"
	@.string "that I'm a pushover though.\p"
	@.string "I'll show you what an elite battle\n"
	@.string "is really like!$"

EverGrandeCity_GlaciasRoom_Text_LisiaDefeated:
	.string "Looks like we couldn't rain\n"
	.string "on your parade.$"

EverGrandeCity_GlaciasRoom_Text_LisiaPostBattle:
	.string "Ah, yup. You've got grace, kid.\n"
	.string "I think you'll go pretty far.$"
	@.string "Welp, you're the real deal alright.\n"
	@.string "Go on ahead.\p"
	@.string "But be warned, you've only seen a small\n"
	@.string "taste of the LEAGUE's power!$"







EverGrandeCity_GlaciasRoom_EventScript_Glacia::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_GLACIA, EverGrandeCity_GlaciasRoom_EventScript_PostBattleSpeech
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_GlaciasRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GLACIA, EverGrandeCity_GlaciasRoom_Text_Defeat
	goto EverGrandeCity_GlaciasRoom_EventScript_Defeated
	end

EverGrandeCity_GlaciasRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_GlaciasRoom_EventScript_Defeated::
	setflag FLAG_DEFEATED_ELITE_4_GLACIA
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_GlaciasRoom_Text_IntroSpeech:
	.string "Welcome, my name is GLACIA\n"
	.string "of the ELITE FOUR.\p"
	.string "I've traveled from afar to HOENN\n"
	.string "so that I may hone my ice skills.\p"
	.string "But all I have seen are challenges by\n"
	.string "weak TRAINERS and their POKéMON.\p"
	.string "What about you?\p"
	.string "It would please me to no end if I could\n"
	.string "go all out against you!$"

EverGrandeCity_GlaciasRoom_Text_Defeat:
	.string "You and your POKéMON…\n"
	.string "How hot your spirits burn!\p"
	.string "The all-consuming heat overwhelms.\p"
	.string "It's no surprise that my icy skills\n"
	.string "failed to harm you.$"

EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech:
	.string "Advance to the next room.\p"
	.string "And there, confirm the truly fearsome\n"
	.string "side of the POKéMON LEAGUE.$"

