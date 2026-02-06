.set LOCALID_NURSE, 1

CinerousTown_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinerousTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

CinerousTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_CINEROUS_TOWN
	end

CinerousTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

CinerousTown_PokemonCenter_1F_EventScript_Teala::
	msgbox CinerousTown_PokemonCenter_1F_Text_Unavailable, MSGBOX_NPC
	end

CinerousTown_PokemonCenter_1F_EventScript_Lass::
	lockall
	faceplayer
	msgbox CinerousTown_PokemonCenter_1F_Text_TimesOfDay, MSGBOX_NPC
	releaseall
	end

CinerousTown_PokemonCenter_1F_EventScript_Man::
	msgbox CinerousTown_PokemonCenter_1F_Text_HealOften, MSGBOX_NPC
	end

CinerousTown_PokemonCenter_1F_EventScript_Glameow::
	lockall
	faceplayer
	waitse
	playmoncry SPECIES_GLAMEOW, CRY_MODE_NORMAL
	msgbox CinerousTown_PokemonCenter_1F_Text_Glameow, MSGBOX_DEFAULT
	waitmoncry
	releaseall
	end

CinerousTown_PokemonCenter_1F_Text_Unavailable:
	.string "Our services are currently\n"
	.string "unavailable.$"

CinerousTown_PokemonCenter_1F_Text_TimesOfDay:
	.string "I heard that some POKéMON only\n"
	.string "appear at certain times of the day.$"

CinerousTown_PokemonCenter_1F_Text_HealOften:
	.string "You should heal your POKéMON\n"
	.string "often.\p"
	.string "I would be remiss if I didn't keep\n"
	.string "my darling GLAMEOW healthy.$"

CinerousTown_PokemonCenter_1F_Text_Glameow:
	.string "GLAMEOW: Nyaa{EMOJI_TILDE}$"
