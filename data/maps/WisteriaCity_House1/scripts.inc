.set LOCALID_FISHERMAN, 1

WisteriaCity_House1_MapScripts::
	.byte 0

WisteriaCity_House1_EventScript_DiveNPC::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM08, WisteriaCity_House1_EventScript_PostHM
	msgbox WisteriaCity_House1_Text_LikeToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, WisteriaCity_House1_EventScript_GiveDive
	msgbox WisteriaCity_House1_Text_Figures, MSGBOX_DEFAULT
	applymovement LOCALID_FISHERMAN, Common_Movement_FaceRight
	waitmovement 0
	release
	end

WisteriaCity_House1_EventScript_GiveDive::
	msgbox WisteriaCity_House1_Text_MeNeither, MSGBOX_DEFAULT
	giveitem ITEM_HM08
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	msgbox WisteriaCity_House1_Text_ExplainDive, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_HM08
	applymovement LOCALID_FISHERMAN, Common_Movement_FaceRight
	waitmovement 0
	release
	end

WisteriaCity_House1_EventScript_PostHM::
	msgbox WisteriaCity_House1_Text_ExplainDive, MSGBOX_DEFAULT
	applymovement LOCALID_FISHERMAN, Common_Movement_FaceRight
	waitmovement 0
	release
	end

WisteriaCity_House1_Text_LikeToFish:
	.string "Hey kid, do you like to fish?$"

WisteriaCity_House1_Text_Figures:
	.string "Yeah, yeah.\n"
	.string "Just like everybody else.$"
	@.string "Heh, you're just like everybody else.$"
	@.string "You do, huh?\p"
	@.string "Well, best of luck, my friend.\p"
	@.string "Those days are behind me.$"

WisteriaCity_House1_Text_MeNeither:
	.string "Me neither.\p"
	.string "You can find way better things\n"
	.string "just going underwater yourself.\p"
	.string "Here, take one of these with you.$"

WisteriaCity_House1_Text_ExplainDive:
	.string "That HM contains DIVE.\p"
	.string "Use it over dark patches of water\n"
	.string "to DIVE down to the seafloor.\p"
	.string "Then you can catch all\n"
	.string "the fish you want!\p"
	.string "Ah, one more thing.\p"
	.string "You'll need to get the gym badge from\n"
	.string "DR. ADDERLY before you can use it.$"

