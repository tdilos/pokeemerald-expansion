XanthosCity_Flat1_4F_MapScripts::
	.byte 0

XanthosCity_Flat1_4F_EventScript_RichBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_XANTHOS_CITY_DREAM_BALLS, XanthosCity_Flat1_4F_EventScript_RichBoyPostItem
	msgbox XanthosCity_Flat1_4F_Text_GiveDreamBalls, MSGBOX_DEFAULT
	giveitem ITEM_DREAM_BALL, 6
	setflag FLAG_RECEIVED_XANTHOS_CITY_DREAM_BALLS
XanthosCity_Flat1_4F_EventScript_RichBoyPostItem::
	msgbox XanthosCity_Flat1_4F_Text_FollowYourDreams, MSGBOX_DEFAULT
	closemessage
	release
	end

XanthosCity_Flat1_4F_Text_GiveDreamBalls:
	.string "Don't say a word, mon amie.\n"
	.string "Just take these.$"

XanthosCity_Flat1_4F_Text_FollowYourDreams:
	.string "Follow your dreams.\n"
	.string "That's what I do.$"


XanthosCity_Flat1_4F_EventScript_RichGirl::
	msgbox XanthosCity_Flat1_4F_Text_Placeholder, MSGBOX_NPC
	end

XanthosCity_Flat1_4F_Text_Placeholder:
	.string "You're a POKéMON trainer?\n"
	.string "How bourgeois!$"


