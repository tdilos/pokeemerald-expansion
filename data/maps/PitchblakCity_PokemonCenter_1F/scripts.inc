.set LOCALID_NURSE, 1

PitchblakCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PitchblakCity_PokemonCenter_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PitchblakCity_PokemonCenter_OnTransition:
	setrespawn HEAL_LOCATION_PITCHBLAK_CITY
	end

PitchblakCity_PokemonCenter_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PitchblakCity_PokemonCenter_EventScript_Teala::
	msgbox PitchblakCity_PokemonCenter_Text_Unavailable, MSGBOX_NPC
	end

PitchblakCity_PokemonCenter_Text_Unavailable:
	.string "Our services are currently\n"
	.string "unavailable.$"

PitchblakCity_PokemonCenter_EventScript_Woman::
	msgbox PitchblakCity_PokemonCenter_Text_Polution, MSGBOX_NPC
	end

PitchblakCity_PokemonCenter_Text_Polution:
	.string "Have you seen all the pollution\n"
	.string "on ROUTE 90?\p"
	.string "It's outrageous! What is the city\n"
	.string "going to do to address this?$"

PitchblakCity_PokemonCenter_EventScript_AceTrainer::
	msgbox PitchblakCity_PokemonCenter_Text_NorthToHaewenTown, MSGBOX_NPC
	end

PitchblakCity_PokemonCenter_Text_NorthToHaewenTown:
	.string "Hmmm. It looks like you can SURF north\n"
	.string "from here to get to HAEWEN TOWN.$"


