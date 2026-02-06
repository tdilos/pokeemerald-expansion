OffwiteTown_House3_MapScripts::
	.byte 0

OffwiteTown_House3_EventScript_OldMan::
	lock
	faceplayer
	@goto_if_set FLAG_RECEIVED_HM07, OffwiteTown_House3_EventScript_PostHM
	msgbox OffwiteTown_House3_Text_EarnedRespect, MSGBOX_DEFAULT
	@checkitemspace ITEM_HM07
	@call_if_eq VAR_RESULT, FALSE, OffwiteTown_House3_EventScript_NoRoomForHM
	giveitem ITEM_HM07
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_HM07
	msgbox OffwiteTown_House3_Text_ExplainThaw, MSGBOX_DEFAULT
	release
	end

OffwiteTown_House3_EventScript_NoRoomForHM::
	msgbox OffwiteTown_House3_Text_NoRoomForHM, MSGBOX_DEFAULT
	release
	end

OffwiteTown_House3_Text_NoRoomForHM:
	.string "Oh dear. You'd better make space\n"
	.string "in your BAG for it.$"

OffwiteTown_House3_EventScript_PostHM::
	msgbox OffwiteTown_House3_Text_ExplainThaw, MSGBOX_DEFAULT
	release
	end

OffwiteTown_House3_Text_EarnedRespect:
	.string "Hmmm...\n"
	.string "You bear the symbol of our clan.\p"
	.string "You also bear the gym badge from\n"
	.string "MINDARO CITY.\p"
	.string "You've obviously earned my\n"
	.string "granddaughter's respect.\p"
	.string "Why don't you take this with you as well?$"

OffwiteTown_House3_Text_ExplainThaw:
	.string "That HIDDEN MACHINE contains\n"
	.string "the move THAW.\p"
	.string "With it, your POKéMON will be able\n"
	.string "to melt icy obstacles in your path.\p"
	@.string "With it, your POKéMON can take you\n"
	@.string "to another city you've been to before.\p"
	.string "You'll be able to pass through to the\n"
	.string "other side of MT SHIRO.\p" 
	.string "You'll have your best chance if you\n"
	.string "go through the north cave.$"
	@.string "But you'll need the gym badge in\n"
	@.string "PITCHBLAK CITY to use it.$"

OffwiteTown_House3_EventScript_OldWoman::
	msgbox OffwiteTown_House3_Text_OurClan, MSGBOX_NPC
	end

OffwiteTown_House3_Text_OurClan:
	.string "Since time immemorial, our clan has\n"
	.string "lived here on MT SHIRO.\p"
	.string "Our ancestors built the temple on\n"
	.string "this mountain.\p"
	.string "It honors a great POKéMON that helped\n"
	.string "us in times of hardship.$"
