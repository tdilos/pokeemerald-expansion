.set LOCALID_NURSE, 1

CobaltCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CobaltCity_PokemonCenter_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

CobaltCity_PokemonCenter_OnTransition:
	setrespawn HEAL_LOCATION_COBALT_CITY
	end

CobaltCity_PokemonCenter_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

CobaltCity_PokemonCenter_EventScript_Teala::
	msgbox CobaltCity_PokemonCenter_Text_Unavailable, MSGBOX_NPC
	end

CobaltCity_PokemonCenter_Text_Unavailable:
	.string "Our services are currently\n"
	.string "unavailable.$"

CobaltCity_PokemonCenter_EventScript_Schizo::
	msgbox CobaltCity_PokemonCenter_Text_Reality, MSGBOX_NPC
	end

CobaltCity_PokemonCenter_Text_Reality:
	.string "I keep thinking, what if this reality\n"
	.string "is part of some larger reality?$"

CobaltCity_PokemonCenter_EventScript_BugCatcher::
	msgbox CobaltCity_PokemonCenter_Text_ShamrockIsland, MSGBOX_NPC
	end

CobaltCity_PokemonCenter_Text_ShamrockIsland:
	.string "SHAMROCK ISLE is supposed to be home\n"
	.string "to rare BUG POKéMON.\p"
	.string "I would go, but I don't have a POKéMON\n"
	.string "that can SURF.$"
