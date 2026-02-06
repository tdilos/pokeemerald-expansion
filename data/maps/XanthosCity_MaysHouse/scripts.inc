.equ ISSHO_DEX_SIZE, 386
.equ REQUIRED_SEEN_MONS, 20
.equ REQUIRED_SEEN_MONS_2, 100
.set LOCALID_MAY, 1

XanthosCity_MaysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, XanthosCity_MaysHouse_OnTransition
	.byte 0

XanthosCity_MaysHouse_OnTransition:
	goto_if_eq VAR_XANTHOS_CITY_STATE, 0, XanthosCity_MaysHouse_EventScript_HideMay
	goto_if_unset FLAG_RECEIVED_TM70, XanthosCity_MaysHouse_EventScript_RevealMay
	goto_if_set FLAG_RECEIVED_TM10, XanthosCity_MaysHouse_EventScript_RevealMay
	goto XanthosCity_MaysHouse_EventScript_HideMay
	end

XanthosCity_MaysHouse_EventScript_HideMay:
	setflag FLAG_HIDE_MAY
	end

XanthosCity_MaysHouse_EventScript_RevealMay:
	clearflag FLAG_HIDE_MAY
	end


XanthosCity_MaysHouse_EventScript_MayPokedexCheck::
	lock
	faceplayer
	goto_if_quest_complete QUEST_3, XanthosCity_MaysHouse_EventScript_PostIsshoDex
	goto_if_set FLAG_RECEIVED_TM70, XanthosCity_MaysHouse_EventScript_MayPokedexCheck2
	call XanthosCity_MaysHouse_EventScript_GetRequestInfo
	msgbox XanthosCity_MaysHouse_Text_CheckPokedex, MSGBOX_NPC
	specialvar VAR_RESULT, GetIsshoPokedexCount
	buffernumberstring STR_VAR_3, VAR_RESULT
	call XanthosCity_MaysHouse_EventScript_GetRequestInfo
	goto_if_lt VAR_RESULT, REQUIRED_SEEN_MONS, XanthosCity_MaysHouse_EventScript_NotEnoughEntries
	msgbox XanthosCity_MaysHouse_Text_WowGoodJob, MSGBOX_NPC
	giveitem ITEM_TM70
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	msgbox XanthosCity_MaysHouse_Text_ToBeContinued, MSGBOX_NPC
	closemessage
	delay 60
	msgbox XanthosCity_MaysHouse_Text_ErmAnyway, MSGBOX_NPC
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAY
	setflag FLAG_RECEIVED_TM70
	fadescreen FADE_FROM_BLACK
	release
	end

XanthosCity_MaysHouse_EventScript_NotEnoughEntries::
	msgbox XanthosCity_MaysHouse_Text_NotEnoughEntries, MSGBOX_NPC
	closemessage
	applymovement LOCALID_MAY, Common_Movement_FaceLeft
	waitmovement 0
	release
	end

XanthosCity_MaysHouse_EventScript_GetRequestInfo::
	buffernumberstring STR_VAR_1, REQUIRED_SEEN_MONS
	bufferitemname STR_VAR_2, ITEM_TM70
	return

XanthosCity_MaysHouse_Text_CheckPokedex:
	.string "So, {PLAYER}.\n"
	.string "How's the POKéDEX coming along?\p"
	.string "If you can show me at least {STR_VAR_1} POKéDEX\n"
	.string "entries, I've got a reward for you.\l"
	.string "It's {STR_VAR_2} FLASH.\p"
	.string "Let's see...$"

XanthosCity_MaysHouse_Text_NotEnoughEntries:
	.string "Nope, you've only found {STR_VAR_3} POKéMON.\n"
	.string "Come see me again once you find more.$"

XanthosCity_MaysHouse_Text_WowGoodJob:
	.string "Wow, you managed to find {STR_VAR_3} POKéMON!\p"
	.string "Great job! Here's your reward!$"

XanthosCity_MaysHouse_Text_ToBeContinued:
	.string "This is great! Thanks to you, my research\n"
	.string "has come a long way.\p"
	.string "I should take a vacation somewhere.\n"
	.string "A resort hotel maybe?\p"
	.string "How wonderful...$"

XanthosCity_MaysHouse_Text_ErmAnyway:
	.string "Erm, anyway. Good work, {PLAYER}.\n"
	.string "I'm sure we'll meet again soon.\p"
	.string "Good luck with your adventure.\n"
	.string "And don't forget about that POKéDEX!$"









XanthosCity_MaysHouse_EventScript_MayPokedexCheck2::
	goto_if_set FLAG_RECEIVED_EXP_ALL, XanthosCity_MaysHouse_EventScript_MayPostgame
	call XanthosCity_MaysHouse_EventScript_GetRequestInfo2
	msgbox XanthosCity_MaysHouse_Text_CheckPokedex2, MSGBOX_NPC
	specialvar VAR_RESULT, GetIsshoPokedexCount
	buffernumberstring STR_VAR_3, VAR_RESULT
	call XanthosCity_MaysHouse_EventScript_GetRequestInfo2
	goto_if_lt VAR_RESULT, REQUIRED_SEEN_MONS_2, XanthosCity_MaysHouse_EventScript_NotEnoughEntries
	msgbox XanthosCity_MaysHouse_Text_WowGoodJob, MSGBOX_NPC
	giveitem ITEM_EXP_ALL
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	msgbox XanthosCity_MaysHouse_Text_GoCompleteIsshoDex, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAY, Common_Movement_FaceLeft
	waitmovement 0
	setflag FLAG_RECEIVED_EXP_ALL
	release
	end

XanthosCity_MaysHouse_EventScript_GetRequestInfo2::
	buffernumberstring STR_VAR_1, REQUIRED_SEEN_MONS_2
	bufferitemname STR_VAR_2, ITEM_EXP_ALL
	return

XanthosCity_MaysHouse_Text_CheckPokedex2:
	.string "Hey there, {PLAYER}.\n"
	.string "How's the POKéDEX coming along?\p"
	.string "If you can show me at least {STR_VAR_1} POKéDEX\n"
	.string "entries, I've got a reward for you.\l"
	.string "It's an {STR_VAR_2} .\p"
	.string "Let's see...$"

XanthosCity_MaysHouse_Text_GoCompleteIsshoDex:
	.string "My research in ISSHO has really come\n"
	.string "a long way since I moved here.\p"
	.string "Thanks for all your help, {PLAYER}.\p"
	.string "If you ever manage to complete the\n"
	.string "ISSHO POKéDEX, come show me.\p"
	.string "I'd love to see it!$"

XanthosCity_MaysHouse_EventScript_MayPostgame::
	msgbox XanthosCity_MaysHouse_Text_GoCompleteIsshoDex, MSGBOX_DEFAULT
	closemessage

	specialvar VAR_RESULT, GetIsshoPokedexCount
	buffernumberstring STR_VAR_3, VAR_RESULT
	call XanthosCity_MaysHouse_EventScript_GetRequestInfo
	goto_if_ge VAR_RESULT, ISSHO_DEX_SIZE, XanthosCity_MaysHouse_EventScript_CompletedIsshoDex

	@msgbox XanthosCity_MaysHouse_Text_DexCount, MSGBOX_DEFAULT
	@closemessage

	applymovement LOCALID_MAY, Common_Movement_FaceLeft
	waitmovement 0
	release
	end

XanthosCity_MaysHouse_Text_DexCount:
	.string "Obtained: {STR_VAR_3} entries$"

XanthosCity_MaysHouse_EventScript_CompletedIsshoDex::
	applymovement LOCALID_MAY, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox XanthosCity_MaysHouse_Text_CompletedIsshoDex, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_EXP_CHARM
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	msgbox XanthosCity_MaysHouse_Text_ExplainExpCharm, MSGBOX_DEFAULT
	closemessage
	completequest QUEST_3
	release
	end

XanthosCity_MaysHouse_Text_CompletedIsshoDex:
	.string "Woah, I don't believe it!\p"
	.string "You've found data on every\n"
	.string "POKéMON in ISSHO!\p"
	.string "This calls for celebration!\n"
	.string "Here, you can wear this!$"

XanthosCity_MaysHouse_Text_ExplainExpCharm:
	.string "That EXP CHARM will boost the\n"
	.string "experience your POKéMON gain.\p"
	.string "Oh, to think my ISSHO research is\n"
	.string "actually complete!\p"
	.string "I can retire now!\p"
	.string "\p"
	.string "Sigh.\n"
	.string "If only it were that easy.$"

XanthosCity_MaysHouse_EventScript_PostIsshoDex::
	msgbox XanthosCity_MaysHouse_Text_TalkToBirch, MSGBOX_DEFAULT
	closemessage
	release
	end

XanthosCity_MaysHouse_Text_TalkToBirch:
	.string "My father works in LITTLEROOT TOWN\n"
	.string "in the HOENN region.\p"
	.string "You should pay him a visit sometime.\n"
	.string "I'm sure he'd love to meet you!$"




