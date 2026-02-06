.set LOCALID_NURSE, 1

MaroonCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MaroonCity_PokemonCenter_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

MaroonCity_PokemonCenter_OnTransition:
	setrespawn HEAL_LOCATION_MAROON_CITY
	end

MaroonCity_PokemonCenter_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MaroonCity_PokemonCenter_EventScript_Teala::
	msgbox MaroonCity_PokemonCenter_Text_Unavailable, MSGBOX_NPC
	end

MaroonCity_PokemonCenter_Text_Unavailable:
	.string "Our services are currently\n"
	.string "unavailable.$"

MaroonCity_PokemonCenter_EventScript_HexManiac::
	msgbox MaroonCity_PokemonCenter_Text_EvilSpirits, MSGBOX_NPC
	end

MaroonCity_PokemonCenter_Text_EvilSpirits:
	.string "I'm sensing something...\p"
	.string "A cry for help...\p"
	.string "Could it be?\n"
	.string "Lost souls in the woods?$"







MaroonCity_PokemonCenter_EventScript_FriendshipRater::
	lock
	faceplayer
	msgbox MaroonCity_PokemonCenter_Text_SeeHowMuchPokemonLikesYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case FRIENDSHIP_NONE, MaroonCity_PokemonCenter_EventScript_DetestsYou
	case FRIENDSHIP_1_TO_49, MaroonCity_PokemonCenter_EventScript_VeryWary
	case FRIENDSHIP_50_TO_99, MaroonCity_PokemonCenter_EventScript_NotUsedToYou
	case FRIENDSHIP_100_TO_149, MaroonCity_PokemonCenter_EventScript_GettingUsedToYou
	case FRIENDSHIP_150_TO_199, MaroonCity_PokemonCenter_EventScript_LikesYouQuiteALot
	case FRIENDSHIP_200_TO_254, MaroonCity_PokemonCenter_EventScript_VeryHappy
	case FRIENDSHIP_MAX, MaroonCity_PokemonCenter_EventScript_AdoresYou
	release
	end

MaroonCity_PokemonCenter_EventScript_DetestsYou::
	msgbox MaroonCity_PokemonCenter_Text_DetestsYou, MSGBOX_DEFAULT
	release
	end

MaroonCity_PokemonCenter_EventScript_VeryWary::
	msgbox MaroonCity_PokemonCenter_Text_VeryWary, MSGBOX_DEFAULT
	release
	end

MaroonCity_PokemonCenter_EventScript_NotUsedToYou::
	msgbox MaroonCity_PokemonCenter_Text_NotUsedToYou, MSGBOX_DEFAULT
	release
	end

MaroonCity_PokemonCenter_EventScript_GettingUsedToYou::
	msgbox MaroonCity_PokemonCenter_Text_GettingUsedToYou, MSGBOX_DEFAULT
	release
	end

MaroonCity_PokemonCenter_EventScript_LikesYouQuiteALot::
	msgbox MaroonCity_PokemonCenter_Text_LikesYouQuiteALot, MSGBOX_DEFAULT
	release
	end

MaroonCity_PokemonCenter_EventScript_VeryHappy::
	msgbox MaroonCity_PokemonCenter_Text_VeryHappy, MSGBOX_DEFAULT
	release
	end

MaroonCity_PokemonCenter_EventScript_AdoresYou::
	msgbox MaroonCity_PokemonCenter_Text_AdoresYou, MSGBOX_DEFAULT
	release
	end

MaroonCity_PokemonCenter_Text_SeeHowMuchPokemonLikesYou:
	.string "Let me see your POKéMON.\n"
	.string "I'll check to see how much it likes you.\p"
	.string "Oh.\n"
	.string "Your POKéMON…$"

MaroonCity_PokemonCenter_Text_AdoresYou:
	.string "It adores you.\n"
	.string "It can't possibly love you any more.\l"
	.string "I even feel happy seeing it.$"

MaroonCity_PokemonCenter_Text_VeryHappy:
	.string "It seems to be very happy.\n"
	.string "It obviously likes you a whole lot.$"

MaroonCity_PokemonCenter_Text_LikesYouQuiteALot:
	.string "It likes you quite a lot.\n"
	.string "It seems to want to be babied a little.$"

MaroonCity_PokemonCenter_Text_GettingUsedToYou:
	.string "It's getting used to you.\n"
	.string "It seems to believe in you.$"

MaroonCity_PokemonCenter_Text_NotUsedToYou:
	.string "It's not very used to you yet.\n"
	.string "It neither loves nor hates you.$"

MaroonCity_PokemonCenter_Text_VeryWary:
	.string "It's very wary.\n"
	.string "It has scary viciousness in its eyes.\l"
	.string "It doesn't like you much at all.$"

MaroonCity_PokemonCenter_Text_DetestsYou:
	.string "This is a little hard for me to say…\p"
	.string "Your POKéMON simply detests you.\n"
	.string "Doesn't that make you uncomfortable?$"



