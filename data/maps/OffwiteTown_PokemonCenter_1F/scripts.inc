.equ REQUIRED_SEEN_MONS, 60
.set LOCALID_MAY, 3
.set LOCALID_NURSE, 1

OffwiteTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OffwiteTown_PokemonCenter_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OffwiteTown_PokemonCenter_OnTransition:
	setrespawn HEAL_LOCATION_OFFWITE_TOWN
	goto_if_set FLAG_RECEIVED_HM05, OffwiteTown_PokemonCenter_EventScript_HideMay
	goto_if_unset FLAG_RECEIVED_HM04, OffwiteTown_PokemonCenter_EventScript_MayNotHereYet
	clearflag FLAG_HIDE_MAY
OffwiteTown_PokemonCenter_EventScript_MayNotHereYet:
	end

OffwiteTown_PokemonCenter_EventScript_HideMay:
	setflag FLAG_HIDE_MAY
	end

OffwiteTown_PokemonCenter_EventScript_MayPokedexCheck::
	lock
	faceplayer
	call OffwiteTown_PokemonCenter_EventScript_GetRequestInfo
	msgbox OffwiteTown_PokemonCenter_Text_CheckPokedex, MSGBOX_NPC
	specialvar VAR_RESULT, GetIsshoPokedexCount
	buffernumberstring STR_VAR_3, VAR_RESULT
	call OffwiteTown_PokemonCenter_EventScript_GetRequestInfo
	goto_if_lt VAR_RESULT, REQUIRED_SEEN_MONS, OffwiteTown_PokemonCenter_EventScript_NotEnoughEntries
	msgbox OffwiteTown_PokemonCenter_Text_WowGoodJob, MSGBOX_NPC
	giveitem ITEM_HM05
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	msgbox OffwiteTown_PokemonCenter_Text_ExplainMagnetRise, MSGBOX_NPC
	msgbox OffwiteTown_PokemonCenter_Text_ToBeContinued, MSGBOX_NPC
	closemessage
	delay 60
	msgbox OffwiteTown_PokemonCenter_Text_ErmAnyway, MSGBOX_NPC
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAY
	setflag FLAG_HIDE_MAY
	setflag FLAG_RECEIVED_HM05
	fadescreen FADE_FROM_BLACK
	release
	end

OffwiteTown_PokemonCenter_EventScript_NotEnoughEntries::
	msgbox OffwiteTown_PokemonCenter_Text_NotEnoughEntries, MSGBOX_NPC
	closemessage
	release
	end

OffwiteTown_PokemonCenter_EventScript_GetRequestInfo::
	buffernumberstring STR_VAR_1, REQUIRED_SEEN_MONS
	bufferitemname STR_VAR_2, ITEM_HM05
	return

OffwiteTown_PokemonCenter_Text_CheckPokedex:
	.string "Hey there, {PLAYER}.\n"
	.string "How's the POKéDEX coming along?\p"
	.string "If you can show me at least {STR_VAR_1} POKéDEX\n"
	.string "entries, I've got a reward for you.\l"
	.string "It's {STR_VAR_2} Magnet Rise.\p"
	.string "Let's see...$"

OffwiteTown_PokemonCenter_Text_NotEnoughEntries:
	.string "Nope, you've only found {STR_VAR_3} POKéMON.\n"
	.string "Come see me again once you find more.$"

OffwiteTown_PokemonCenter_Text_WowGoodJob:
	.string "Wow, you managed to find {STR_VAR_3} POKéMON!\p"
	.string "Great job! Here's your reward!$"

OffwiteTown_PokemonCenter_Text_ExplainMagnetRise:
	.string "With that HM, your POKéMON will be\n"
	.string "able to push metal objects around.\p"
	.string "You can also pull them by holding\n"
	.string "by holding the A BUTTON.\p"
	.string "One thing though, you'll need the badge\n"
	.string "from HAEWEN GYM before you can use it.$"

OffwiteTown_PokemonCenter_Text_ToBeContinued:
	.string "\p"
	.string "Have you tried the ski slopes here?\n"
	.string "It's really fun!\p"
	.string "But I'm not used to it being\n"
	.string "so cold all the time.\p"
	.string "I think I'll go somewhere warmer next.\n"
	.string "Maybe a beach resort...$"

OffwiteTown_PokemonCenter_Text_ErmAnyway:
	.string "Erm, anyway. Good work, {PLAYER}.\n"
	.string "I'm sure we'll meet again soon.\p"
	.string "Good luck with your adventure.\n"
	.string "And don't forget about that POKéDEX!$"













OffwiteTown_PokemonCenter_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OffwiteTown_PokemonCenter_EventScript_Teala::
	msgbox OffwiteTown_PokemonCenter_Text_Unavailable, MSGBOX_NPC
	end

OffwiteTown_PokemonCenter_Text_Unavailable:
	.string "Our services are currently\n"
	.string "unavailable.$"

OffwiteTown_PokemonCenter_EventScript_Boarder::
	msgbox OffwiteTown_PokemonCenter_Text_MtShiroCaves, MSGBOX_NPC
	end

OffwiteTown_PokemonCenter_Text_MtShiroCaves:
	.string "MT SHIRO has a vast network of caves.\p"
	.string "There are many entrances, but I heard\n"
	.string "they're all supposed to be contiguous.$"


