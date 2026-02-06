HaewenTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, HaewenTown_OnTransition
	.byte 0

HaewenTown_OnTransition:
	setflag FLAG_VISITED_HAEWEN_TOWN
	end

HaewenTown_EventScript_TownSign::
	msgbox HaewenTown_Text_TownSign, MSGBOX_SIGN
	end

HaewenTown_Text_TownSign:
	.string "HAEWEN TOWN\n"
	.string "“Where legends are made.”$"

HaewenTown_EventScript_GymSign::
	msgbox HaewenTown_Text_GymSign, MSGBOX_SIGN
	end

HaewenTown_Text_GymSign:
	.string "HAEWEN TOWN POKéMON GYM\n"
	.string "LEADER: ETHEL\l"
	.string "“The mythic hunter.”$"

HaewenTown_EventScript_Psychic::
	@msgbox HaewenTown_Text_SpaceAliens, MSGBOX_NPC
	msgbox HaewenTown_Text_StrangeSignals, MSGBOX_NPC
	end

HaewenTown_Text_StrangeSignals:
	.string "I keep hearing these strange voices\n"
	.string "out here, but it's probably nothing.\p"
	.string "It's perfectly normal to hear voices\n"
	.string "in your own head sometimes.$"

HaewenTown_Text_SpaceAliens:
	.string "Do you believe in space aliens?\p"
	.string "Some people think that's where some\n"
	.string "POKéMON species come from.\p"
	.string "There are even some that believe that\n"
	.string "all life was planted here long ago\l"
	.string "by advanced extraterrestrials.$"

HaewenTown_EventScript_AceTrainer::
	lock
	faceplayer
	msgbox HaewenTown_Text_DragonNotDRAGON, MSGBOX_DEFAULT
	release
	end

HaewenTown_Text_DragonNotDRAGON:
	.string "This gym specializes in dragons.\n"
	.string "Not DRAGONS.\p"
	.string "We all use dragon POKéMON.\n"
	.string "Not DRAGON POKéMON.\p"
	.string "Got that?$"

HaewenTown_EventScript_LittleBoy::
	lock
	faceplayer
	msgbox HaewenTown_Text_DragonsBigAndScary, MSGBOX_DEFAULT
	release
	end

HaewenTown_Text_DragonsBigAndScary:
	.string "Dragons sure are big and scary, huh?\p"
	.string "But I'm not afraid of nothing.$"

HaewenTown_EventScript_Expert::
	lock
	faceplayer
	msgbox HaewenTown_Text_MiragePalace, MSGBOX_DEFAULT
	release
	end

HaewenTown_Text_MiragePalace:
	.string "Did you happen to find a large\n"
	.string "palace on your way here?\p"
	.string "People tell stories claiming that\n"
	.string "it finds them.\p"
	.string "Legends say that it was once the\n"
	.string "palace of an ancient king.\p"
	.string "And that the king's great wealth\n"
	.string "still lies hidden there.\p"
	.string "But the palace is enchanted.\p"
	.string "Finding the treasure is not as\n"
	.string "easy as it seems.$"
	@.string "Searching for the treasure will not\n"
	@.string "be as easy as it at first seems.$"

HaewenTown_EventScript_AceTrainer2::
	lock
	faceplayer
	@msgbox HaewenTown_Text_FightForGlory, MSGBOX_DEFAULT
	msgbox HaewenTown_Text_SpaceAliens, MSGBOX_DEFAULT
	release
	end

HaewenTown_Text_FightForGlory:
	.string "Do you fight for glory?\n"
	.string "Or something else?$"








