ShuckleSpring_1F_MapScripts::
	.byte 0

ShuckleSpring_1F_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_SHUCKLE_SPRING_BERRY_JUICE, ShuckleSpring_1F_EventScript_ComeBackTomorrow
	msgbox ShuckleSpring_1F_Text_BerryJuice, MSGBOX_DEFAULT
	giveitem ITEM_BERRY_JUICE
	setflag FLAG_DAILY_SHUCKLE_SPRING_BERRY_JUICE
	@goto ShuckleSpring_1F_EventScript_ComeBackTomorrow
	msgbox ShuckleSpring_1F_Text_ComeBackTomorrow, MSGBOX_DEFAULT
	release
	end

ShuckleSpring_1F_EventScript_ComeBackTomorrow::
	lock
	faceplayer
	msgbox ShuckleSpring_1F_Text_ComeBackTomorrow, MSGBOX_DEFAULT
	release
	end

ShuckleSpring_1F_Text_BerryJuice:
	.string "SHUCKLE is a POKéMON that can\n"
	.string "ferment berries.\p"
	.string "One can make BERRY JUICE by storing\n"
	.string "berries in its shell.\p"
	.string "Here, why don't you try some.$"

ShuckleSpring_1F_Text_ComeBackTomorrow:
	.string "I come here to collect\n"
	.string "BERRY JUICE every day.\p"
	.string "Come back tomorrow if you'd\n"
	.string "like some more.$"
