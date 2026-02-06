.set LOCALID_NURSE, 1

AmberCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AmberCity_PokemonCenter_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

AmberCity_PokemonCenter_OnTransition:
	setrespawn HEAL_LOCATION_AMBER_CITY
	end

AmberCity_PokemonCenter_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

AmberCity_PokemonCenter_EventScript_Teala::
	msgbox AmberCity_PokemonCenter_Text_Unavailable, MSGBOX_NPC
	end

AmberCity_PokemonCenter_Text_Unavailable:
	.string "Our services are currently\n"
	.string "unavailable.$"

AmberCity_PokemonCenter_EventScript_Camper::
	msgbox AmberCity_PokemonCenter_Text_PokemonFainted, MSGBOX_NPC
	end

AmberCity_PokemonCenter_Text_PokemonFainted:
	.string "Gyah! All my POKéMON fainted and I\n"
	.string "lost half of my money!$"

AmberCity_PokemonCenter_EventScript_Girl::
	msgbox AmberCity_PokemonCenter_Text_IHateSand, MSGBOX_NPC
	end

AmberCity_PokemonCenter_Text_IHateSand:
	.string "I hate sand. It's course and rough,\n"
	.string "and it gets everywhere.$"
