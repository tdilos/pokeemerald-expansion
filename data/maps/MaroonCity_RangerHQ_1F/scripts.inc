MaroonCity_RangerHQ_1F_MapScripts::
	.byte 0

MaroonCity_RangerHQ_1F_EventScript_Greeter::
	msgbox MaroonCity_RangerHQ_1F_Text_Welcome, MSGBOX_NPC
	end

MaroonCity_RangerHQ_1F_Text_Welcome:
	.string "Welcome to POKéMON RANGER HQ.\p"
	.string "Unfortunately all our rangers\n"
	.string "are busy right now.\p"
	.string "If you need to ask a ranger for help,\n"
	.string "you can wait here or upstairs.$"

MaroonCity_RangerHQ_1F_EventScript_Ranger::
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_33
	goto_if_eq VAR_RESULT, TRUE, MaroonCity_RangerHQ_1F_EventScript_EVQuestComplete
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_33
	goto_if_eq VAR_RESULT, TRUE, MaroonCity_RangerHQ_1F_EventScript_CheckAtkEVs
	msgbox MaroonCity_RangerHQ_1F_Text_Strongmon, MSGBOX_DEFAULT
	startquest QUEST_33
	release
	end

MaroonCity_RangerHQ_1F_Text_Strongmon:
	.string "Training POKéMON takes time and effort,\n"
	.string "but it can really make a difference.\p"
	.string "Do you know about Effort Values?\p"
	.string "Also known as EVs, they're how we keep\n"
	.string "track of a POKéMON's training.\p"
	.string "An untrained stat has 0 EVs while a\n"
	.string "fully trained stat has 255 EVs.\p"
	.string "Your POKéMON gain EVs every time\n"
	.string "they win a battle.\p"
	.string "But the catch is that no POKéMON can\n"
	.string "have more than 510 total EVs.\p"
	.string "That means you need to specialize\n"
	.string "your training to be most effective.\p"
	.string "You'll get the hang of it as you\n"
	.string "train with your POKéMON more.\p"
	.string "In fact, if you can show me a POKéMON\n"
	.string "with a maximally trained Attack stat,\p"
	.string "I'll give you something that'll make\n"
	.string "training a whole lot easier for you!$"

MaroonCity_RangerHQ_1F_EventScript_CheckAtkEVs::
	bufferpartymonnick 0, 0
	specialvar VAR_RESULT, GetAtkEV
	buffernumberstring 1, VAR_RESULT
	goto_if_lt VAR_RESULT, 255, MaroonCity_RangerHQ_1F_EventScript_EVQuestInProgress
	msgbox MaroonCity_RangerHQ_1F_Text_StrongPokemon, MSGBOX_DEFAULT
	giveitem ITEM_POWER_BRACER, 6
	msgbox MaroonCity_RangerHQ_1F_Text_ExplainPowerItem, MSGBOX_DEFAULT
	completequest QUEST_33
	release
	end

MaroonCity_RangerHQ_1F_Text_StrongPokemon:
	.string "Oh, your {STR_VAR_1}...\p"
	.string "Yup, it's one strong looking POKéMON.\n"
	.string "Good job!\p"
	.string "Here, you can have this as promised.$"

MaroonCity_RangerHQ_1F_EventScript_EVQuestInProgress::
	msgbox MaroonCity_RangerHQ_1F_Text_NotStrongEnough, MSGBOX_DEFAULT
	release
	end

MaroonCity_RangerHQ_1F_Text_NotStrongEnough:
	.string "Oh, your {STR_VAR_1}...\p"
	.string "Looks good, but it could still\n"
	.string "train to be a bit stronger.$"

MaroonCity_RangerHQ_1F_EventScript_EVQuestComplete::
	msgbox MaroonCity_RangerHQ_1F_Text_ExplainPowerItem, MSGBOX_DEFAULT
	release
	end

MaroonCity_RangerHQ_1F_Text_ExplainPowerItem:
	.string "Give that POWER BRACER to one\n"
	.string "of your POKéMON to wear.\p"
	.string "It'll help train its Attack faster.$"








MaroonCity_RangerHQ_1F_EventScript_Rocker::
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_32
	goto_if_eq VAR_RESULT, TRUE, MaroonCity_RangerHQ_1F_EventScript_Quest2Complete
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_32
	goto_if_eq VAR_RESULT, TRUE, MaroonCity_RangerHQ_1F_EventScript_Quest2InProgress
	msgbox MaroonCity_RangerHQ_1F_Text_AnniversaryGift, MSGBOX_DEFAULT
	startquest QUEST_32
	release
	end

MaroonCity_RangerHQ_1F_Text_AnniversaryGift:
	.string "Hey there, little dude.\n"
	.string "Would you mind helping a brother out?\p"
	.string "I need a gift for my girlfriend.\p"
	.string "Our anniversary's coming up and I want\n"
	.string "to do something special, you know?\p"
	.string "So I thought, why not a pair of LUVDISC?\n"
	.string "She loves WATER type POKéMON.\p"
	.string "Ah, but that's the thing.\n"
	.string "I can't catch POKéMON.\l"
	.string "I'm not even a trainer!\p"
	.string "I tried asking the RANGERS here for\n"
	.string "help, but I guess they got more\l"
	.string "important stuff going on right now...\p"
	.string "You're a POKéMON trainer, right?\p"
	.string "You gotta help me find a pair\n"
	.string "of LUVDISC!\p"
	.string "Any two LUVDISC will work, as long as\n"
	.string "one's male and one's female.\p"
	.string "Help me, little dude.\n"
	.string "You're my only hope.$"

MaroonCity_RangerHQ_1F_EventScript_Quest2InProgress::
	special CheckForLuvdiscPair
	goto_if_eq VAR_RESULT, TRUE, MaroonCity_RangerHQ_1F_EventScript_FoundLuvdisc
	msgbox MaroonCity_RangerHQ_1F_Text_AnyLuck, MSGBOX_DEFAULT
	release
	end

MaroonCity_RangerHQ_1F_Text_AnyLuck:
	.string "Any luck with the LUVDISC, little dude?$"

MaroonCity_RangerHQ_1F_EventScript_FoundLuvdisc::
	msgbox MaroonCity_RangerHQ_1F_Text_YouFoundThem, MSGBOX_DEFAULT
	giveitem ITEM_DESTINY_KNOT
	completequest QUEST_32
	release
	end

MaroonCity_RangerHQ_1F_Text_YouFoundThem:
	.string "You got the LUVDISC!\n"
	.string "You're awesome, little dude!\p"
	.string "She's gonna be so happy when\n"
	.string "she sees these.\p"
	.string "Thanks a ton, little dude.\n"
	.string "Here, take this for your trouble.$"

MaroonCity_RangerHQ_1F_EventScript_Quest2Complete::
	msgbox MaroonCity_RangerHQ_1F_Text_ExplainDestinyKnot, MSGBOX_DEFAULT	
	release
	end

MaroonCity_RangerHQ_1F_Text_ExplainDestinyKnot:
	.string "Give that DESTINY KNOT to one of\n"
	.string "your POKéMON to hold.\p"
	.string "Whenever it becomes attracted,\n"
	.string "so will the other POKéMON.$"



