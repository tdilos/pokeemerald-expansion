.set LOCALID_NURSE, 1

TurquoiseCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TurquoiseCity_PokemonCenter_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

TurquoiseCity_PokemonCenter_OnTransition:
	setrespawn HEAL_LOCATION_TURQUOISE_CITY
	end

TurquoiseCity_PokemonCenter_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

TurquoiseCity_PokemonCenter_EventScript_Teala::
	msgbox TurquoiseCity_PokemonCenter_Text_Unavailable, MSGBOX_NPC
	end

TurquoiseCity_PokemonCenter_Text_Unavailable:
	.string "Our services are currently\n"
	.string "unavailable.$"

TurquoiseCity_PokemonCenter_EventScript_Fisherman::
	msgbox TurquoiseCity_PokemonCenter_Text_FishingCities, MSGBOX_NPC
	end

TurquoiseCity_PokemonCenter_Text_FishingCities:
	.string "Every port city here in ISSHO has\n"
	.string "its own aquatic life.\p"
	.string "Try fishing in another city!$"

TurquoiseCity_PokemonCenter_EventScript_FatMan::
	lockall
	goto_if_set FLAG_RECEIVED_TM44, TurquoiseCity_PokemonCenter_EventScript_FatManPostTM
	msgbox TurquoiseCity_PokemonCenter_Text_GiveRestTM, MSGBOX_NPC
	giveitem ITEM_TM44
	setflag FLAG_RECEIVED_TM44
	releaseall
	end

TurquoiseCity_PokemonCenter_Text_GiveRestTM:
	.string "Yaaawn...\n"
	.string "Leave me be.\p"
	.string "I'm bushed from that long\n"
	.string "ferry ride.\p"
	.string "Here you can have this.$"

TurquoiseCity_PokemonCenter_EventScript_FatManPostTM::
	msgbox TurquoiseCity_PokemonCenter_Text_FastAsleep, MSGBOX_DEFAULT	
	releaseall
	end

TurquoiseCity_PokemonCenter_Text_FastAsleep:
	.string "\p"
	.string "He's fast asleep.$"

