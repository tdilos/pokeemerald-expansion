.set LOCALID_NURSE, 1

WisteriaCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, WisteriaCity_PokemonCenter_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

WisteriaCity_PokemonCenter_OnTransition:
	setrespawn HEAL_LOCATION_WISTERIA_CITY
	end

WisteriaCity_PokemonCenter_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

WisteriaCity_PokemonCenter_EventScript_Teala::
	msgbox WisteriaCity_PokemonCenter_Text_Unavailable, MSGBOX_NPC
	end

WisteriaCity_PokemonCenter_Text_Unavailable:
	.string "Our services are currently\n"
	.string "unavailable.$"











WisteriaCity_PokemonCenter_EventScript_OldMan::
	msgbox WisteriaCity_PokemonCenter_Text_CityHistory, MSGBOX_NPC
	end

WisteriaCity_PokemonCenter_Text_CityHistory:
	.string "WISTERIA CITY wasn't always so gloomy.\p"
	.string "You wouldn't know it from\n"
	.string "how it looks today,\p"
	.string "But this was once a much\n"
	.string "livelier, friendlier place.\p"
	.string "Things haven't been the same since\n"
	.string "that incident at the LABORATORY.\p"
	.string "Now much of the city is abandoned\n"
	.string "and falling into ruin.$"



