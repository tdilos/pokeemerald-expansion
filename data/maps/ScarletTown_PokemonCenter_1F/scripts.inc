.set LOCALID_NURSE, 1

ScarletTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ScarletTown_PokemonCenter_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

ScarletTown_PokemonCenter_OnTransition:
	setrespawn HEAL_LOCATION_SCARLET_TOWN
	end

ScarletTown_PokemonCenter_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

ScarletTown_PokemonCenter_EventScript_Teala::
	msgbox ScarletTown_PokemonCenter_Text_Unavailable, MSGBOX_NPC
	end

ScarletTown_PokemonCenter_Text_Unavailable:
	.string "Our services are currently\n"
	.string "unavailable.$"

ScarletTown_PokemonCenter_EventScript_Breeder::
	msgbox ScarletTown_PokemonCenter_Text_RoadToMaroonCity, MSGBOX_NPC
	end

ScarletTown_PokemonCenter_Text_RoadToMaroonCity:
	.string "You can get to MAROON CITY by going\n"
	.string "south through SCARLET WOODS.\p"
	.string "But I heard you won't make it\n"
	.string "unless you have HM07 THAW.\p"
	.string "How does that make any sense?$"

ScarletTown_PokemonCenter_EventScript_BlackBelt::
	msgbox ScarletTown_PokemonCenter_Text_StrongMoves, MSGBOX_NPC
	end

ScarletTown_PokemonCenter_Text_StrongMoves:
	.string "I came here to learn\n"
	.string "the strongest techniques.\p"
	.string "But alas, I have no RED SHARDS.\p"
	.string "I don't suppose you know where\n"
	.string "to find any, do you?$"


