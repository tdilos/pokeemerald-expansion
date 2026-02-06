.set LOCALID_NURSE, 1

HaewenTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, HaewenTown_PokemonCenter_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

HaewenTown_PokemonCenter_OnTransition:
	setrespawn HEAL_LOCATION_HAEWEN_TOWN
	end

HaewenTown_PokemonCenter_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

HaewenTown_PokemonCenter_EventScript_Teala::
	msgbox HaewenTown_PokemonCenter_Text_Unavailable, MSGBOX_NPC
	end

HaewenTown_PokemonCenter_Text_Unavailable:
	.string "Our services are currently\n"
	.string "unavailable.$"











HaewenTown_PokemonCenter_EventScript_Man::
	msgbox HaewenTown_PokemonCenter_Text_BackwaterVillage, MSGBOX_NPC
	end

HaewenTown_PokemonCenter_Text_BackwaterVillage:
	.string "HAEWEN TOWN isn't your usual\n"
	.string "tourist venue.\p"
	.string "It's remote and hard to get to, even\n"
	.string "for seasoned travelers like us.$"

HaewenTown_PokemonCenter_EventScript_Woman::
	msgbox HaewenTown_PokemonCenter_Text_CantUnderstandPeople, MSGBOX_NPC
	end

HaewenTown_PokemonCenter_Text_CantUnderstandPeople:
	.string "Everyone here talks so strangely.\n"
	.string "I can't understand a word they're saying.$"










