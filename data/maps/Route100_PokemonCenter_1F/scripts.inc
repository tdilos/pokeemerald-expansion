.set LOCALID_NURSE, 1

Route100_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

Route100_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_ROUTE_100
	end

Route100_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

Route100_PokemonCenter_1F_EventScript_Teala::
	msgbox Route100_PokemonCenter_1F_Text_Unavailable, MSGBOX_NPC
	end

Route100_PokemonCenter_1F_Text_Unavailable:
	.string "Our services are currently\n"
	.string "unavailable.$"

Route100_PokeCenter_1F_EventScript_AceTrainer1::
	msgbox Route100_PokeCenter_1F_Text_VictoryRoad, MSGBOX_NPC
	end

Route100_PokeCenter_1F_Text_VictoryRoad:
	.string "The new VICTORY ROAD is actually\n"
	.string "a chain of islands.\p"
	.string "They're all connected by a\n"
	.string "common cave network.$"

Route100_PokeCenter_1F_EventScript_BattleGirl::
	msgbox Route100_PokeCenter_1F_Text_LongRoadAhead, MSGBOX_NPC
	end

Route100_PokeCenter_1F_Text_LongRoadAhead:
	.string "Don't be fooled by the pretty flowers.\n"
	.string "VICTORY ROAD is long and grueling.\p"
	.string "Make sure you're stocked up\n"
	.string "and well prepared.$"

Route100_PokeCenter_1F_EventScript_AceTrainer2::
	msgbox Route100_PokeCenter_1F_Text_EliteFour, MSGBOX_NPC
	end

Route100_PokeCenter_1F_Text_EliteFour:
	.string "I heard that each of the ELITE FOUR will\n"
	.string "force you to battle on their home turf.\p"
	.string "I wonder what that's supposed to mean.$"


