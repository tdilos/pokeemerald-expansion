.equ REQUIRED_SEEN_MONS, 40
.set LOCALID_MAY, 8

CobaltyCity_DreamResort_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CobaltyCity_DreamResort_OnTransition
	.byte 0

CobaltyCity_DreamResort_OnTransition:
	goto_if_set FLAG_RECEIVED_HM04, CobaltyCity_DreamResort_EventScript_HideMay
	goto_if_unset FLAG_RECEIVED_TM70, CobaltyCity_DreamResort_EventScript_MayNotHereYet
	clearflag FLAG_HIDE_MAY
CobaltyCity_DreamResort_EventScript_MayNotHereYet:
	end

CobaltyCity_DreamResort_EventScript_HideMay:
	@setflag FLAG_MAY_COBALT_CITY
	setflag FLAG_HIDE_MAY
	end

CobaltyCity_DreamResort_EventScript_MayPokedexCheck::
	lock
	faceplayer
	call CobaltyCity_DreamResort_EventScript_GetRequestInfo
	msgbox CobaltyCity_DreamResort_Text_CheckPokedex, MSGBOX_NPC
	specialvar VAR_RESULT, GetIsshoPokedexCount
	buffernumberstring STR_VAR_3, VAR_RESULT
	call CobaltyCity_DreamResort_EventScript_GetRequestInfo
	goto_if_lt VAR_RESULT, REQUIRED_SEEN_MONS, CobaltyCity_DreamResort_EventScript_NotEnoughEntries
	msgbox CobaltyCity_DreamResort_Text_WowGoodJob, MSGBOX_NPC
	giveitem ITEM_HM04
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	msgbox CobaltyCity_DreamResort_Text_ToBeContinued, MSGBOX_NPC
	closemessage
	delay 60
	msgbox CobaltyCity_DreamResort_Text_ErmAnyway, MSGBOX_NPC
	closemessage
	fadescreen FADE_TO_BLACK
	@setflag FLAG_MAY_COBALT_CITY
	removeobject LOCALID_MAY
	setflag FLAG_HIDE_MAY
	setflag FLAG_RECEIVED_HM04
	fadescreen FADE_FROM_BLACK
	release
	end

CobaltyCity_DreamResort_EventScript_NotEnoughEntries::
	msgbox CobaltyCity_DreamResort_Text_NotEnoughEntries, MSGBOX_NPC
	closemessage
	release
	end

CobaltyCity_DreamResort_EventScript_GetRequestInfo::
	buffernumberstring STR_VAR_1, REQUIRED_SEEN_MONS
	bufferitemname STR_VAR_2, ITEM_HM04
	return

CobaltyCity_DreamResort_Text_CheckPokedex:
	.string "Hey there, {PLAYER}.\n"
	.string "How's the POKéDEX coming along?\p"
	.string "If you can show me at least {STR_VAR_1} POKéDEX\n"
	.string "entries, I've got a reward for you.\l"
	.string "It's {STR_VAR_2} Strength.\p"
	.string "Let's see...$"

CobaltyCity_DreamResort_Text_NotEnoughEntries:
	.string "Nope, you've only found {STR_VAR_3} POKéMON.\n"
	.string "Come see me again once you find more.$"

CobaltyCity_DreamResort_Text_WowGoodJob:
	.string "Wow, you managed to find {STR_VAR_3} POKéMON!\p"
	.string "Great job! Here's your reward!$"

CobaltyCity_DreamResort_Text_ToBeContinued:
	.string "This hotel is nice and all, but the wait\n"
	.string "for a room here is ridiculous.\p"
	.string "They told me I should've booked a room\n"
	.string "three months ago!\p"
	.string "I think I'll go somewhere\n"
	.string "more modest next.\p"
	.string "Hmmm, I've always wanted\n"
	.string "to try skiing...$"

CobaltyCity_DreamResort_Text_ErmAnyway:
	.string "Erm, anyway. Good work, {PLAYER}.\n"
	.string "I'm sure we'll meet again soon.\p"
	.string "Good luck with your adventure.\n"
	.string "And don't forget about that POKéDEX!$"








CobaltyCity_DreamResort_EventScript_DeskClerk::
	msgbox CobaltyCity_DreamResort_Text_DeskClerk, MSGBOX_NPC
	end

CobaltyCity_DreamResort_Text_DeskClerk:
	.string "Welcome to the DREAM RESORT.\p"
	.string "Unfortunately, all of our rooms\n"
	.string "are currently booked.$"

CobaltyCity_DreamResort_EventScript_Gentleman::
	msgbox CobaltyCity_DreamResort_Text_SawMyrtle, MSGBOX_NPC
	end

CobaltyCity_DreamResort_Text_SawMyrtle:
	.string "Hmm, yes. Now that you mention it, I did\n"
	.string "see the gym leader pass through here.$"

CobaltyCity_DreamResort_EventScript_Father::
	msgbox CobaltyCity_DreamResort_Text_Father, MSGBOX_NPC
	end

CobaltyCity_DreamResort_Text_Father:
	.string "It's nothing. She's just upset because\n"
	.string "we had to change rooms.$"

CobaltyCity_DreamResort_EventScript_Daughter::
	msgbox CobaltyCity_DreamResort_Text_SawGhost, MSGBOX_NPC
	end

CobaltyCity_DreamResort_Text_SawGhost:
	.string "It's true! I saw a ghost! I really did!$"

CobaltyCity_DreamResort_EventScript_Maniac::
	msgbox CobaltyCity_DreamResort_Text_HauntedHotel, MSGBOX_NPC
	end

CobaltyCity_DreamResort_Text_HauntedHotel:
	.string "Rumors say this hotel is haunted.\p"
	.string "The staff do seem eager to change people\n"
	.string "to different rooms.$"

CobaltyCity_DreamResort_EventScript_Woman::
	msgbox CobaltyCity_DreamResort_Text_GoBackToRoom, MSGBOX_NPC
	end

CobaltyCity_DreamResort_Text_GoBackToRoom:
	.string "I tried to go back to my room and\n"
	.string "got challenged to a POKéMON battle!$"

CobaltyCity_DreamResort_EventScript_Lass::
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_13
	goto_if_eq VAR_RESULT, FALSE, CobaltyCity_DreamResort_EventScript_FindDoll
	@goto_if_unset FLAG_RECEIVED_TM90, CobaltyCity_DreamResort_EventScript_FindDoll
	msgbox CobaltyCity_DreamResort_EventScript_ExplainSubstitute, MSGBOX_DEFAULT
	release
	end

CobaltyCity_DreamResort_EventScript_FindDoll::
	msgbox CobaltyCity_DreamResort_Text_FindDoll, MSGBOX_DEFAULT
	closemessage
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_13
	goto_if_eq VAR_RESULT, FALSE, CobaltyCity_DreamResort_EventScript_QuestStart
	checkitem ITEM_POKE_DOLL
	call_if_eq VAR_RESULT, TRUE, CobaltyCity_DreamResort_EventScript_ReturnDoll
	release
	end

CobaltyCity_DreamResort_EventScript_QuestStart::
	@questmenu QUEST_MENU_UNLOCK_QUEST QUEST_13
	@openquestmenu
	startquest QUEST_13
	release
	end

CobaltyCity_DreamResort_Text_FindDoll:
	.string "I lost my doll in the room\n"
	.string "I was staying in.\p"
	.string "I told them to check room 17, and they\n"
	.string "said they didn't find anything.\p"
	.string "But I know I left it there!\n"
	.string "There's nowhere else it could be!$"

CobaltyCity_DreamResort_EventScript_ReturnDoll::
	applymovement LOCALID_LASS, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	msgbox CobaltyCity_DreamResort_Text_ThatsMyDoll, MSGBOX_DEFAULT
	removeitem ITEM_POKE_DOLL
	giveitem ITEM_TM90
	msgbox CobaltyCity_DreamResort_EventScript_ExplainSubstitute, MSGBOX_DEFAULT
	@setflag FLAG_RECEIVED_TM90
	@questmenu QUEST_MENU_COMPLETE_QUEST QUEST_13
	completequest QUEST_13
	release
	end

CobaltyCity_DreamResort_Text_ThatsMyDoll:
	.string "That's my doll! You found it for me!\n"
	.string "Oh my gosh, thank you so much!\p"
	.string "Here, you can take this TM with you.$"

CobaltyCity_DreamResort_EventScript_ExplainSubstitute:
	.string "That TM contains SUBSTITUTE.\p"
	.string "It protects your POKéMON with a decoy\n"
	.string "in exchange for 1/4 of its health.$"


@Route83_Hydroplant_EventScript_FossilScientist::
@	lock
@	faceplayer
@	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 2, Route83_Hydroplant_EventScript_FossilMonReady
@	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, Route83_Hydroplant_EventScript_StillRegenerating
@	msgbox Route83_Hydroplant_Text_DevelopDeviceToResurrectFossils, MSGBOX_DEFAULT
@	checkitem ITEM_ROOT_FOSSIL
@	goto_if_eq VAR_RESULT, TRUE, Route83_Hydroplant_EventScript_NoticeRootFossil
@	checkitem ITEM_HELIX_FOSSIL
@	goto_if_eq VAR_RESULT, TRUE, Route83_Hydroplant_EventScript_NoticeHelixFossil
@	release
@	end

