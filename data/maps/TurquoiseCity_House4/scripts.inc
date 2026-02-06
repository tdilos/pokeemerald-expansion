TurquoiseCity_House4_MapScripts::
	.byte 0

TurquoiseCity_House4_EventScript_FriendshipRater::
	lock
	faceplayer
	msgbox TurquoiseCity_House4_Text_SeeHowMuchPokemonLikesYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case FRIENDSHIP_NONE, TurquoiseCity_House4_EventScript_DetestsYou
	case FRIENDSHIP_1_TO_49, TurquoiseCity_House4_EventScript_VeryWary
	case FRIENDSHIP_50_TO_99, TurquoiseCity_House4_EventScript_NotUsedToYou
	case FRIENDSHIP_100_TO_149, TurquoiseCity_House4_EventScript_GettingUsedToYou
	case FRIENDSHIP_150_TO_199, TurquoiseCity_House4_EventScript_LikesYouQuiteALot
	case FRIENDSHIP_200_TO_254, TurquoiseCity_House4_EventScript_VeryHappy
	case FRIENDSHIP_MAX, TurquoiseCity_House4_EventScript_AdoresYou
	release
	end

TurquoiseCity_House4_EventScript_DetestsYou::
	msgbox TurquoiseCity_House4_Text_DetestsYou, MSGBOX_DEFAULT
	release
	end

TurquoiseCity_House4_EventScript_VeryWary::
	msgbox TurquoiseCity_House4_Text_VeryWary, MSGBOX_DEFAULT
	release
	end

TurquoiseCity_House4_EventScript_NotUsedToYou::
	msgbox TurquoiseCity_House4_Text_NotUsedToYou, MSGBOX_DEFAULT
	release
	end

TurquoiseCity_House4_EventScript_GettingUsedToYou::
	msgbox TurquoiseCity_House4_Text_GettingUsedToYou, MSGBOX_DEFAULT
	release
	end

TurquoiseCity_House4_EventScript_LikesYouQuiteALot::
	msgbox TurquoiseCity_House4_Text_LikesYouQuiteALot, MSGBOX_DEFAULT
	release
	end

TurquoiseCity_House4_EventScript_VeryHappy::
	msgbox TurquoiseCity_House4_Text_VeryHappy, MSGBOX_DEFAULT
	release
	end

TurquoiseCity_House4_EventScript_AdoresYou::
	msgbox TurquoiseCity_House4_Text_AdoresYou, MSGBOX_DEFAULT
	release
	end

TurquoiseCity_House4_EventScript_Glameow::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_GLAMEOW, CRY_MODE_NORMAL
	msgbox TurquoiseCity_House4_Text_Glameow, MSGBOX_DEFAULT
	waitmoncry
	release
	end

TurquoiseCity_House4_Text_SeeHowMuchPokemonLikesYou:
	.string "Let me see your POKéMON.\n"
	.string "I'll check to see how much it likes you.\p"
	.string "Oh.\n"
	.string "Your POKéMON…$"

TurquoiseCity_House4_Text_AdoresYou:
	.string "It adores you.\n"
	.string "It can't possibly love you any more.\l"
	.string "I even feel happy seeing it.$"

TurquoiseCity_House4_Text_VeryHappy:
	.string "It seems to be very happy.\n"
	.string "It obviously likes you a whole lot.$"

TurquoiseCity_House4_Text_LikesYouQuiteALot:
	.string "It likes you quite a lot.\n"
	.string "It seems to want to be babied a little.$"

TurquoiseCity_House4_Text_GettingUsedToYou:
	.string "It's getting used to you.\n"
	.string "It seems to believe in you.$"

TurquoiseCity_House4_Text_NotUsedToYou:
	.string "It's not very used to you yet.\n"
	.string "It neither loves nor hates you.$"

TurquoiseCity_House4_Text_VeryWary:
	.string "It's very wary.\n"
	.string "It has scary viciousness in its eyes.\l"
	.string "It doesn't like you much at all.$"

TurquoiseCity_House4_Text_DetestsYou:
	.string "This is a little hard for me to say…\p"
	.string "Your POKéMON simply detests you.\n"
	.string "Doesn't that make you uncomfortable?$"

TurquoiseCity_House4_Text_Glameow:
	.string "GLAMEOW: Meoww{EMOJI_TILDE}$"
