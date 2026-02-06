CobaltCity_House1_MapScripts::
	.byte 0

CobaltCity_House1_EventScript_GoodRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_GOOD_ROD, CobaltCity_House1_EventScript_ReceivedGoodRod
	msgbox CobaltCity_House1_Text_YouAgreeGoodRodIsGood, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CobaltCity_House1_EventScript_ReceiveGoodRod
	goto_if_eq VAR_RESULT, NO, CobaltCity_House1_EventScript_DeclineGoodRod
	end

CobaltCity_House1_EventScript_ReceiveGoodRod::
	msgbox CobaltCity_House1_Text_IdenticalMindsTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GOOD_ROD
	setflag FLAG_RECEIVED_GOOD_ROD
	msgbox CobaltCity_House1_Text_TryYourLuckFishing, MSGBOX_DEFAULT
	release
	end

CobaltCity_House1_EventScript_DeclineGoodRod::
	msgbox CobaltCity_House1_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

CobaltCity_House1_EventScript_ReceivedGoodRod::
	msgbox CobaltCity_House1_Text_TryCatchingMonWithGoodRod, MSGBOX_DEFAULT
	release
	end

CobaltCity_House1_Text_YouAgreeGoodRodIsGood:
	.string "Hmm!\n"
	.string "A GOOD ROD is really good!\p"
	.string "Wouldn't you agree?$"

CobaltCity_House1_Text_IdenticalMindsTakeThis:
	.string "Hmm!\n"
	.string "We're of identical minds!\p"
	.string "Hmm!\n"
	.string "Take this GOOD ROD!$"

CobaltCity_House1_Text_TryYourLuckFishing:
	.string "Wherever there's water, try your luck\n"
	.string "at fishing.$"

CobaltCity_House1_Text_DontYouLikeToFish:
	.string "Don't you like to fish?$"

CobaltCity_House1_Text_TryCatchingMonWithGoodRod:
	.string "Try catching all sorts of POKéMON\n"
	.string "with your GOOD ROD.$"
