ArtisanCave_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ArtisanCave_B1F_OnTransition
	.byte 0

ArtisanCave_B1F_OnTransition:
	setflag FLAG_LANDMARK_ARTISAN_CAVE
	end




ArtisanCave_B1F_EventScript_Camper::
	lock
	faceplayer
	msgbox ArtisanCave_B1F_Text_UnearthedChambers, MSGBOX_DEFAULT
	release
	end

ArtisanCave_B1F_Text_UnearthedChambers:
	.string "These chambers we unearthed contain\n"
	.string "shards of broken tablets.\p"
	.string "We believe each tablet was a portrait\n"
	.string "of an ancient POKéMON.$"


ArtisanCave_B1F_EventScript_Picknicker::
	lock
	faceplayer
	msgbox ArtisanCave_B1F_Text_SleepingInCave, MSGBOX_DEFAULT
	release
	end

ArtisanCave_B1F_Text_SleepingInCave:
	.string "Sleeping in a cave...\p"
	.string "Now that's something I don't\n"
	.string "think I'll ever get used to...$"

ArtisanCave_B1F_EventScript_Archaeologist2::
	lock
	faceplayer
	msgbox ArtisanCave_B1F_Text_StepLightly, MSGBOX_DEFAULT
	release
	end

ArtisanCave_B1F_Text_StepLightly:
	.string "Step lightly now. We're still\n"
	.string "digging in this area.$"

ArtisanCave_B1F_EventScript_Archaeologist::
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_44
	goto_if_eq VAR_RESULT, TRUE, ArtisanCave_B1F_EventScript_QuestComplete
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_44
	goto_if_eq VAR_RESULT, TRUE, ArtisanCave_B1F_EventScript_QuestInProgress

	msgbox ArtisanCave_B1F_Text_Discovery, MSGBOX_DEFAULT
	closemessage
	delay 60
	@msgbox ArtisanCave_B1F_Text_GiveUnownReport, MSGBOX_DEFAULT
	@giveitem ITEM_UNOWN_REPORT
	@msgbox ArtisanCave_B1F_Text_ExplainUnownReport, MSGBOX_DEFAULT
	msgbox ArtisanCave_B1F_Text_Discovery2, MSGBOX_DEFAULT
	startquest QUEST_44
	release
	end

ArtisanCave_B1F_EventScript_QuestComplete::
	msgbox ArtisanCave_B1F_Text_ExplainAzureFlute, MSGBOX_DEFAULT
	release
	end

ArtisanCave_B1F_EventScript_QuestInProgress::
	msgbox ArtisanCave_B1F_Text_ComeBackIfComplete, MSGBOX_DEFAULT
	@special CheckUnownReport
	goto_if_unset FLAG_SOLVED_UNOWN_PUZZLE_1, ArtisanCave_B1F_EventScript_Skip
	goto_if_unset FLAG_SOLVED_UNOWN_PUZZLE_2, ArtisanCave_B1F_EventScript_Skip
	goto_if_unset FLAG_SOLVED_UNOWN_PUZZLE_3, ArtisanCave_B1F_EventScript_Skip
	goto_if_unset FLAG_SOLVED_UNOWN_PUZZLE_4, ArtisanCave_B1F_EventScript_Skip
	goto_if_unset FLAG_SOLVED_UNOWN_PUZZLE_5, ArtisanCave_B1F_EventScript_Skip
	goto_if_unset FLAG_SOLVED_UNOWN_PUZZLE_6, ArtisanCave_B1F_EventScript_Skip
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox ArtisanCave_B1F_Text_CompleteReport, MSGBOX_DEFAULT
	giveitem ITEM_AZURE_FLUTE
	setflag FLAG_RECEIVED_AZURE_FLUTE
	completequest QUEST_44
	release
	end

ArtisanCave_B1F_EventScript_Skip::
	release
	end

ArtisanCave_B1F_Text_Discovery:
	.string "My colleagues and I have made\n"
	.string "an amazing discovery!\p"
	.string "These ruins we've excavated are\n"
	.string "perhaps more than 5,000 years old.\p"
	.string "Mankind, as we know it, was only in\n"
	.string "its infancy then.\p"
	.string "The makers of these monuments would've\n"
	.string "lived at the dawn of civilization itself.\p"
	.string "The glyphs carved here are perhaps the\n"
	.string "oldest written language in the world.\p"
	.string "Imagine the tales they could tell.\p"
	.string "If only we could fully decipher\n"
	.string "their language...$" 

ArtisanCave_B1F_Text_Discovery2:
	.string "We believe it may be connected to\n"
	.string "an ancient POKéMON called UNOWN.\p"
	.string "But we still need more data on them\n"
	.string "to build a complete cipher.\p"
	.string "If only we could get all the UNOWN\n"
	.string "forms to appear in this cave...$"

ArtisanCave_B1F_Text_ComeBackIfComplete:
	.string "If only we could get all the UNOWN\n"
	.string "forms to appear in this cave...$"

ArtisanCave_B1F_Text_CompleteReport:
	.string "By Jove, you've done it!\n"
	.string "You've released all the UNOWN!\p"
	.string "Who knew the secret was in those\n"
	.string "old broken tablets?\p"
	.string "This is a monumental breakthrough\n"
	.string "in our work.\p"
	.string "Please, do take this with you.\n"
	.string "I'd like you to carry it.$"


@ArtisanCave_B1F_Text_GiveUnownReport:
@	.string "We believe it may be connected to\n"
@	.string "an ancient POKéMON called UNOWN.\p"
@	.string "In fact, sights of it have been reported\n"
@	.string "here since we set up our campsite.\p"
@	.string "But we still need more data on them...\p"
@	.string "You're a POKéMON trainer, yes?\n"
@	.string "Perhaps this might interest you.$"

@ArtisanCave_B1F_Text_ExplainUnownReport:
@	.string "That UNOWN REPORT will record data on\n"
@	.string "each form of UNOWN you encounter.\p"
@	.string "But you'll need to catch each form\n"
@	.string "to get its complete data.\p"
@	.string "Come see me again if you manage to\n"
@	.string "gather a full report on the UNOWN.$"

@ArtisanCave_B1F_Text_ComeBackIfComplete:
@	.string "Come see me again if you manage to\n"
@	.string "gather a full report on the UNOWN.$"

ArtisanCave_B1F_Text_ExplainAzureFlute:
	.string "That old thing is an AZURE FLUTE.\p"
	.string "To be frank, no one knows who\n"
	.string "made them or for what purpose.\p"
	.string "According to legends, they respond to\n"
	.string "the will of strong POKéMON trainers.$"




