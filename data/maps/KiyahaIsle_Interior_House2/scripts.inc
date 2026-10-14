KiyahaIsle_Interior_House2_MapScripts::
	.byte 0



KiyahaIsle_Interior_House2_EventScript_Fisherman::
	lock
	faceplayer
	@questmenu QUEST_MENU_CHECK_COMPLETE QUEST_
	goto_if_eq VAR_RESULT, TRUE, KiyahaIsle_Interior_House2_EventScript_QuestComplete
	@questmenu QUEST_MENU_CHECK_ACTIVE QUEST_
	goto_if_eq VAR_RESULT, TRUE, KiyahaIsle_Interior_House2_EventScript_QuestInProgress
	msgbox KiyahaIsle_Interior_House2_Text_FishingForPincurchin, MSGBOX_DEFAULT
	@startquest QUEST_
	release
	end

KiyahaIsle_Interior_House2_Text_FishingForPincurchin:
	.string "$"

KiyahaIsle_Interior_House2_EventScript_QuestInProgress::
	msgbox KiyahaIsle_Interior_House2_Text_QuestInProgress, MSGBOX_DEFAULT

	@ Check party for Pincurchin
	@goto_if_eq VAR_RESULT, TRUE, KiyahaIsle_Interior_House2_EventScript_CompleteQuest

	release
	end

KiyahaIsle_Interior_House2_Text_QuestInProgress:
	.string "What I'd give to catch a PINCURCHIN...$"

KiyahaIsle_Interior_House2_EventScript_GetReward::
	msgbox KiyahaIsle_Interior_House2_Text_YouFoundThem, MSGBOX_DEFAULT
	giveitem ITEM_TALISMAN_TEAL
	@questmenu QUEST_MENU_COMPLETE_QUEST QUEST_
	@completequest QUEST_
	release
	end	

KiyahaIsle_Interior_House2_Text_YouFoundThem:
	.string "$"

KiyahaIsle_Interior_House2_EventScript_QuestComplete::
	msgbox KiyahaIsle_Interior_House2_Text_QuestComplete, MSGBOX_DEFAULT
	release
	end	

KiyahaIsle_Interior_House2_Text_QuestComplete:
	.string "$"

