PitchblakCity_Flat3_2F_MapScripts::
	.byte 0

PitchblakCity_Flat3_2F_EventScript_OldMan::
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_25
	goto_if_eq VAR_RESULT, TRUE, PitchblakCity_Flat3_2F_EventScript_QuestComplete
	checkitem ITEM_OAKS_PARCEL
	goto_if_eq VAR_RESULT, TRUE, PitchblakCity_Flat3_2F_EventScript_GiveParcel
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_25
	goto_if_eq VAR_RESULT, TRUE, PitchblakCity_Flat3_2F_EventScript_QuestInProgress
	msgbox PitchblakCity_Flat3_2F_Text_DeliveryRequest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PitchblakCity_Flat3_2F_EventScript_DeclineRequest
	goto_if_eq VAR_RESULT, YES, PitchblakCity_Flat3_2F_EventScript_AcceptRequest
	end

PitchblakCity_Flat3_2F_Text_DeliveryRequest:
	.string "I used to travel around quite a bit\n"
	.string "when I was your age.\p"
	.string "But now that I'm old, I can't get\n"
	.string "around like I used to.\p"
	.string "You look like you get around a lot.\n"
	.string "Would you mind doing an old man favor?$"

PitchblakCity_Flat3_2F_EventScript_DeclineRequest::
	msgbox PitchblakCity_Flat3_2F_Text_PromiseReward, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Flat3_2F_Text_PromiseReward:
	.string "I see. I hope you'll reconsider.\n"
	.string "I'll make it worth your while, I promise.$"

PitchblakCity_Flat3_2F_EventScript_AcceptRequest::
	msgbox PitchblakCity_Flat3_2F_Text_DeliverCherishBall, MSGBOX_DEFAULT
	giveitem ITEM_CHERISH_BALL
	@questmenu QUEST_MENU_UNLOCK_QUEST QUEST_25
	msgbox PitchblakCity_Flat3_2F_Text_OldFriend, MSGBOX_DEFAULT
	startquest QUEST_25
	release
	end

PitchblakCity_Flat3_2F_EventScript_QuestInProgress::
	msgbox PitchblakCity_Flat3_2F_Text_OldFriend, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Flat3_2F_Text_DeliverCherishBall:
	.string "Wonderful!\n"
	.string "I'd like you to deliver this for me.$"

PitchblakCity_Flat3_2F_Text_OldFriend:
	.string "That belongs to an old friend of mine,\n"
	.string "who I haven't seen for many years.\p"
	.string "She went to live in MINDARO CITY\n"
	.string "a long time ago.\p"
	.string "If you can find her, give that\n"
	.string "CHERISH BALL to her for me.\p"
	.string "Tell her the boy from RESEDA TOWN\n"
	.string "sends his regards.$"

PitchblakCity_Flat3_2F_EventScript_GiveParcel::
	msgbox PitchblakCity_Flat3_2F_Text_SomethingForMe, MSGBOX_DEFAULT
	removeitem ITEM_OAKS_PARCEL
	msgbox PitchblakCity_Flat3_2F_Text_HandOverParcel, MSGBOX_DEFAULT
	msgbox PitchblakCity_Flat3_2F_Text_OpenParcel, MSGBOX_DEFAULT
	giveitem ITEM_GS_BALL
	@questmenu QUEST_MENU_COMPLETE_QUEST QUEST_25
	msgbox PitchblakCity_Flat3_2F_Text_ExplainGSBall, MSGBOX_DEFAULT
	completequest QUEST_25
	release
	end

PitchblakCity_Flat3_2F_Text_SomethingForMe:
	.string "Hmm? You have something for me?$"

PitchblakCity_Flat3_2F_Text_HandOverParcel:
	.string "{PLAYER} handed over the PARCEL.$"

PitchblakCity_Flat3_2F_Text_OpenParcel:
	.string "\p"
	.string "Well now, that does bring back memories.\p"
	.string "You've been very kind to do this for me,\n"
	.string "and I'd like to thank you somehow.\p"
	.string "I think should take what was inside.$"

PitchblakCity_Flat3_2F_EventScript_QuestComplete::
	msgbox PitchblakCity_Flat3_2F_Text_ExplainGSBall, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Flat3_2F_Text_ExplainGSBall:
	.string "We found that ball in RESEDA WOODS\n"
	.string "a long time ago.\p"
	.string "We never could figure out how to open it.\p"
	.string "But I have a feeling that you'll make\n"
	.string "use of it somehow.$"



