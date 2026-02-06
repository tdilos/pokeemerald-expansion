CobaltCity_DreamResort_4F_Rooms_MapScripts::
	.byte 0

CobaltCity_DreamResort_4F_EventScript_OldMan::
	msgbox CobaltCity_DreamResort_4F_Text_WhoAreYou, MSGBOX_NPC
	end

CobaltCity_DreamResort_4F_Text_WhoAreYou:
	.string "Yes, hello.\n"
	.string "Er, who are you?\l"
	.string "Who am I?$"

CobaltCity_DreamResort_4F_EventScript_AquaGrunt::
	lockall
	faceplayer
	goto_if_set FLAG_RECEIVED_TM46, CobaltCity_DreamResort_4F_EventScript_YouDidntSeeMe
	msgbox CobaltCity_DreamResort_4F_Text_WrongIdea, MSGBOX_NPC
	giveitem ITEM_TM46
	setflag FLAG_RECEIVED_TM46
	msgbox CobaltCity_DreamResort_4F_Text_YouDidntSeeMe, MSGBOX_NPC
	releaseall
	end

CobaltCity_DreamResort_4F_EventScript_YouDidntSeeMe::
	msgbox CobaltCity_DreamResort_4F_Text_YouDidntSeeMe, MSGBOX_NPC
	releaseall
	end

CobaltCity_DreamResort_4F_Text_WrongIdea:
	.string "Hey, kid. You got the wrong idea.\n"
	.string "I'm not lookin for a fight.\p"
	.string "How about you take this TM, and we'll\n"
	.string "pretend we never saw each other, okay?$"

CobaltCity_DreamResort_4F_Text_YouDidntSeeMe:
	.string "If anyone asks, you didn't see me.$"
