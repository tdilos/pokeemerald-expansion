.set LOCALID_NURSE, 1

MindaroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MindaroCity_PokemonCenter_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

MindaroCity_PokemonCenter_OnTransition:
	setrespawn HEAL_LOCATION_MINDARO_CITY
	end

MindaroCity_PokemonCenter_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MindaroCity_PokemonCenter_EventScript_Teala::
	msgbox MindaroCity_PokemonCenter_Text_Unavailable, MSGBOX_NPC
	end

MindaroCity_PokemonCenter_Text_Unavailable:
	.string "Our services are currently\n"
	.string "unavailable.$"

MindaroCity_PokemonCenter_EventScript_Skier::
	msgbox MindaroCity_PokemonCenter_Text_Skiing, MSGBOX_NPC
	end

MindaroCity_PokemonCenter_Text_Skiing:
	.string "I wanted to take the ski lift\n"
	.string "up to OFFWITE TOWN.\p"
	.string "But I guess you need special\n"
	.string "permission to go there.$"

MindaroCity_PokemonCenter_EventScript_Boy::
	msgbox MindaroCity_PokemonCenter_Text_PathThroughMountain, MSGBOX_NPC
	end

MindaroCity_PokemonCenter_Text_PathThroughMountain:
	.string "According to this map, there's a\n"
	.string "shortcut to MAROON CITY.\p"
	.string "You can get there by going\n"
	.string "over MT SHIRO.\p"
	.string "But not everyone's allowed to pass\n"
	.string "through OFFWITE TOWN.\p"
	.string "You could try asking the GYM LEADER.\n"
	.string "I heard she's orignally from there.$"





