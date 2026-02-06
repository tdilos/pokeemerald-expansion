.set LOCALID_NURSE, 1

XanthosCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, XanthosCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

XanthosCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_XANTHOS_CITY
	end

XanthosCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

XanthosCity_PokemonCenter_1F_EventScript_OldMan::
	msgbox XanthosCity_PokemonCenter_1F_Text_WhatKindOfTrainer, MSGBOX_NPC
	end

XanthosCity_PokemonCenter_1F_EventScript_Teala::
	msgbox XanthosCity_PokemonCenter_1F_Text_Unavailable, MSGBOX_NPC
	end

XanthosCity_PokemonCenter_1F_EventScript_Woman::
	msgbox XanthosCity_PokemonCenter_1F_Text_GoToLibrary, MSGBOX_NPC
	end

XanthosCity_PokemonCenter_1F_Text_GoToLibrary:
	.string "You should check out the XANTHOS\n"
	.string "PUBLIC LIBRARY if you haven't yet.\p"
	@.string "They have a large collection of\n"
	@.string "books and other media.\p"
	.string "You just might learn something new!$"

XanthosCity_PokemonCenter_1F_Text_Unavailable:
	.string "Our services are currently\n"
	.string "unavailable.$"

XanthosCity_PokemonCenter_1F_Text_WhatKindOfTrainer:
	.string "What kind of trainer are you?\p"
	.string "Some trainers want to win at all costs.\p"
	.string "Others don't care about winning as long\n"
	.string "as they have fun battling.$"
	@.string "Still others feel the need to make\n"
	@.string "a statement with their POKéMON.$"





