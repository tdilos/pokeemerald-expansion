BurgundyTown_House3_MapScripts::
	.byte 0

BurgundyTown_House3_EventScript_Woman::
	msgbox BurgundyTown_Text_PinkTourmaline, MSGBOX_NPC
	end

BurgundyTown_Text_PinkTourmaline:
	.string "Tourmaline is a gemstone that comes\n"
	.string "in all sorts of different colors.\p"
	.string "But the most famous variety is\n"
	.string "the pink tourmaline stone.\p"
	.string "It stands for love, healing,\n"
	.string "and compassion.$"
	@.string "You could say it's the symbol\n"
	@.string "of BURGUNDY TOWN.$"

BurgundyTown_House3_EventScript_Man::
	lock
	faceplayer
	@dotimebasedevents
	goto_if_set FLAG_DAILY_BURGUNDY_TOWN_RECEIVED_GEM, BurgundyTown_House3_EventScript_ReceivedGemToday
	msgbox BurgundyTown_House3_Text_YoureDeservingOfGem, MSGBOX_DEFAULT
	random NUM_GEMS
	addvar VAR_RESULT, GEMS_START
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_BURGUNDY_TOWN_RECEIVED_GEM
	msgbox BurgundyTown_House3_Text_WhyBeStingyTakeAnother, MSGBOX_DEFAULT
	random NUM_GEMS
	addvar VAR_RESULT, GEMS_START
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	@msgbox BurgundyTown_House3_Text_VisitPrettyPetalFlowerShop, MSGBOX_DEFAULT
	release
	end

BurgundyTown_House3_EventScript_ReceivedGemToday::
	msgbox BurgundyTown_House3_Text_DoneForToday, MSGBOX_DEFAULT
	release
	end

BurgundyTown_House3_Text_YoureDeservingOfGem:
	.string "Hiya, I'm a gemstone collector.\n"
	.string "I find rare gems all the time.\p"
	.string "You look deserving of one.$"

BurgundyTown_House3_Text_WhyBeStingyTakeAnother:
	.string "Why be stingy?\n"
	.string "Take another!$"

BurgundyTown_House3_Text_DoneForToday:
	.string "I find rare gems all the time.\n"
	.string "I'll have even more tomorrow!$"





