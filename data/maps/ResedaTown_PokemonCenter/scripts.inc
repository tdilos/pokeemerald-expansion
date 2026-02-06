.set LOCALID_NURSE, 1

ResedaTown_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ResedaTown_PokemonCenter_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

ResedaTown_PokemonCenter_OnTransition:
	setrespawn HEAL_LOCATION_RESEDA_TOWN
	end

ResedaTown_PokemonCenter_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

ResedaTown_PokemonCenter_EventScript_Teala::
	msgbox ResedaTown_PokemonCenter_Text_Unavailable, MSGBOX_NPC
	end

ResedaTown_PokemonCenter_Text_Unavailable:
	.string "Our services are currently\n"
	.string "unavailable.$"

ResedaTown_PokemonCenter_EventScript_BugCatcher::
	msgbox ResedaTown_PokemonCenter_Text_ResedaShrine, MSGBOX_NPC
	end

ResedaTown_PokemonCenter_EventScript_Girl::
	msgbox ResedaTown_PokemonCenter_Text_HMCutOutsideTown, MSGBOX_NPC
	end

ResedaTown_PokemonCenter_Text_ResedaShrine:
	.string "There's supposed to be a shrine\n"
	.string "somewhere in RESEDA WOODS.\p"
	.string "My grandpa told me that the guardian\n"
	.string "of the woods lives there.\p"
	.string "Or used to anyway. My grandpa only saw\n"
	.string "it once a long time ago.$"
	@.string "He was even younger than me!$"
	@.string "My grandpa told me a special POKéMON\n"
	@.string "used to live there.$"

ResedaTown_PokemonCenter_Text_HMCutOutsideTown:
	.string "There's a man on ROUTE 88 whose\n"
	.string "POKéMON can CUT down trees.\p"
	.string "They helped clear the area for my\n"
	.string "flower beds!$"
