.equ REQUIRED_SEEN_MONS, 80
.set LOCALID_MAY, 1

DunTown_Motel_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DunTown_Motel_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

DunTown_Motel_1F_OnTransition:
	setrespawn HEAL_LOCATION_OFFWITE_TOWN
	goto_if_set FLAG_RECEIVED_TM10, DunTown_Motel_1F_EventScript_HideMay
	goto_if_unset FLAG_RECEIVED_HM05, DunTown_Motel_1F_EventScript_MayNotHereYet
	clearflag FLAG_HIDE_MAY
DunTown_Motel_1F_EventScript_MayNotHereYet:
	end

DunTown_Motel_1F_EventScript_HideMay:
	setflag FLAG_HIDE_MAY
	end








DunTown_Motel_1F_EventScript_FatMan::
	lock
	msgbox DunTown_Motel_1F_Text_ChannelFlipping, MSGBOX_DEFAULT
	closemessage
	release
	end

DunTown_Motel_1F_Text_ChannelFlipping:
	.string "He's mindlessly flipping through channels.\n"
	.string "He doesn't seem to notice you.$"


DunTown_Motel_1F_EventScript_MayPokedexCheck::
	lock
	faceplayer
	call DunTown_Motel_1F_EventScript_GetRequestInfo
	msgbox DunTown_Motel_1F_Text_CheckPokedex, MSGBOX_NPC
	specialvar VAR_RESULT, GetIsshoPokedexCount
	buffernumberstring STR_VAR_3, VAR_RESULT
	call DunTown_Motel_1F_EventScript_GetRequestInfo
	goto_if_lt VAR_RESULT, REQUIRED_SEEN_MONS, DunTown_Motel_1F_EventScript_NotEnoughEntries
	msgbox DunTown_Motel_1F_Text_WowGoodJob, MSGBOX_NPC
	giveitem ITEM_TM10
	msgbox DunTown_Motel_1F_Text_ToBeContinued, MSGBOX_NPC
	closemessage
	delay 60
	msgbox DunTown_Motel_1F_Text_ErmAnyway, MSGBOX_NPC
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAY
	setflag FLAG_HIDE_MAY
	setflag FLAG_RECEIVED_TM10
	fadescreen FADE_FROM_BLACK
	release
	end

DunTown_Motel_1F_EventScript_NotEnoughEntries::
	msgbox DunTown_Motel_1F_Text_NotEnoughEntries, MSGBOX_NPC
	closemessage
	release
	end

DunTown_Motel_1F_EventScript_GetRequestInfo::
	buffernumberstring STR_VAR_1, REQUIRED_SEEN_MONS
	bufferitemname STR_VAR_2, ITEM_TM10
	return

DunTown_Motel_1F_Text_CheckPokedex:
	.string "Hey there, {PLAYER}.\n"
	.string "How's the POKéDEX coming along?\p"
	.string "If you can show me at least {STR_VAR_1} POKéDEX\n"
	.string "entries, I've got a reward for you.\l"
	.string "It's {STR_VAR_2} Hidden Power.\p"
	.string "Let's see...$"

DunTown_Motel_1F_Text_NotEnoughEntries:
	.string "Nope, you've only found {STR_VAR_3} POKéMON.\n"
	.string "Come see me again once you find more.$"

DunTown_Motel_1F_Text_WowGoodJob:
	.string "Wow, you managed to find {STR_VAR_3} POKéMON!\p"
	.string "Great job! Here's your reward!$"

DunTown_Motel_1F_Text_ToBeContinued:
	.string "This has been a great vacation!\p"
	.string "But I should be heading home now.\p"
	.string "If you get a chance, you should\n"
	.string "stop by my house again.\p"
	.string "I could use another day off\n"
	.string "in the future...$"


DunTown_Motel_1F_Text_ErmAnyway:
	.string "Erm, anyway. Good work, {PLAYER}.\n"
	.string "I'm sure we'll meet again soon.\p"
	.string "Good luck with your adventure.\n"
	.string "And don't forget about that POKéDEX!$"


