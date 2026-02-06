BurgundyTown_House4_MapScripts::
	.byte 0


BurgundyTown_House4_EventScript_Sensei::
	lock
	faceplayer
	goto_if_quest_active QUEST_42, BurgundyTown_House4_EventScript_CompleteQuest
	msgbox BurgundyTown_House4_Text_ExplainRainbowPass, MSGBOX_DEFAULT
	closemessage
	release
	end

BurgundyTown_House4_Text_ExplainRainbowPass:
	.string "I received that RAINBOW PASS long ago\n"
	.string "during my travels.\p"
	.string "Why don't you try showing it to\n"
	.string "a sailor in XANTHOS CITY?$"

BurgundyTown_House4_EventScript_CompleteQuest::
	msgbox BurgundyTown_House4_Text_GiveRainbowPass, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_RAINBOW_PASS
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	completequest QUEST_42
	release
	end

BurgundyTown_House4_Text_GiveRainbowPass:
	.string "Hmmm. So you're the trainer\n"
	.string "who beat all of my students.\p"
	.string "They're a lively bunch, aren't they?\p"
	.string "They take themselves a bit too\n"
	.string "seriously, I think...\p"
	@.string "Too lively for someone as old as me.\p"
	@.string "But thanks to you, they're all worn\n"
	@.string "out like I've never seen.\p"
	.string "It's about time someone young and\n"
	.string "energetic beat some sense into them.\p"
	.string "Why don't you take this\n"
	.string "for your trouble?$"


