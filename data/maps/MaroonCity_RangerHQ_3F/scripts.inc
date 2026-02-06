.set LOCALID_GLAMEOW, 5
.set LOCALID_GROWLITHE, 7
.set LOCALID_JACE, 8
.set LOCALID_JUSTIN, 2
.set LOCALID_ROBIN, 10
.set LOCALID_RANGER1, 1
.set LOCALID_RANGER2, 3
.set LOCALID_RANGER3, 4
.set LOCALID_RANGER4, 6
.set LOCALID_BLACKBALL, 9

MaroonCity_RangerHQ_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MaroonCity_RangerHQ_3F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MaroonCity_RangerHQ_3F_OnFrame
	.byte 0

MaroonCity_RangerHQ_3F_OnFrame:
	map_script_2 VAR_RANGER_HQ_STATE, 2, MaroonCity_RangerHQ_3F_EventScript_BlackBallMeeting
	.2byte 0

	@ State descriptions for VAR_RANGER_HQ_STATE
	@ 0: Before meeting Justin
	@ 1: After receiving mission from Justin
	@ 2: After returning from Pokemon Laboratory
	@ 3: Justin and rangers in Xanthos Underground shopping center
	@ 4: Justin and rangers talking to Azami
	@ 5: Before freeing Mew
	@ 6: Before encountering Zartosht/Neda
	@ 7: Before battling Azami
	@ 8: After clearing Underground City
	@ 9: After everyone leaves and Brendan directs you to Dun Town

MaroonCity_RangerHQ_3F_OnTransition:
	call_if_eq VAR_JACE_STATE, 3, MaroonCity_RangerHQ_3F_EventScript_JaceMeetsJustin
	call_if_ge VAR_JACE_STATE, 4, MaroonCity_RangerHQ_3F_EventScript_HideJace
	call_if_le VAR_RANGER_HQ_STATE, 1, MaroonCity_RangerHQ_3F_EventScript_HideBlackBall
	call_if_eq VAR_RANGER_HQ_STATE, 1, MaroonCity_RangerHQ_3F_EventScript_HideJustin
	call_if_eq VAR_RANGER_HQ_STATE, 2, MaroonCity_RangerHQ_3F_EventScript_SetUpBlackBallMeeting
	call_if_ge VAR_RANGER_HQ_STATE, 3, MaroonCity_RangerHQ_3F_EventScript_HideJustin
	call_if_ge VAR_RANGER_HQ_STATE, 3, MaroonCity_RangerHQ_3F_EventScript_HideMisc
	call_if_set FLAG_DEFEATED_AZAMI, MaroonCity_RangerHQ_3F_EventScript_RevealMisc
	end

MaroonCity_RangerHQ_3F_EventScript_JaceMeetsJustin:
	@removeobject LOCALID_JACE
	clearflag FLAG_HIDE_JACE
	@setobjectxyperm LOCALID_JACE, 22, 6
	@setobjectmovementtype LOCALID_JACE, MOVEMENT_TYPE_FACE_UP
	addobject LOCALID_JACE
	return


MaroonCity_RangerHQ_3F_EventScript_HideJace:
	setflag FLAG_HIDE_JACE
	removeobject LOCALID_JACE
	removeobject LOCALID_ROBIN
	return

MaroonCity_RangerHQ_3F_EventScript_HideJustin:
	setflag FLAG_HIDE_JUSTIN_RANGER_HQ
	removeobject LOCALID_JUSTIN
	return

MaroonCity_RangerHQ_3F_EventScript_HideBlackBall:
	setflag FLAG_HIDE_BLACK_BALL_2
	removeobject LOCALID_BLACKBALL
	return

MaroonCity_RangerHQ_3F_EventScript_HideMisc:
	setflag FLAG_HIDE_MISC_RANGER_HQ
	removeobject LOCALID_RANGER1
	removeobject LOCALID_RANGER2
	removeobject LOCALID_RANGER3
	removeobject LOCALID_RANGER4
	removeobject LOCALID_GLAMEOW
	removeobject LOCALID_GROWLITHE
	return

MaroonCity_RangerHQ_3F_EventScript_RevealMisc:
	clearflag FLAG_HIDE_MISC_RANGER_HQ
	addobject LOCALID_RANGER1
	addobject LOCALID_RANGER2
	addobject LOCALID_RANGER3
	addobject LOCALID_RANGER4
	addobject LOCALID_GLAMEOW
	addobject LOCALID_GROWLITHE
	return

MaroonCity_RangerHQ_3F_EventScript_SetUpBlackBallMeeting:
	playbgm MUS_DP_VICTORY_ROAD, TRUE
	clearflag FLAG_HIDE_BLACK_BALL_2
	removeobject LOCALID_JACE
	clearflag FLAG_HIDE_JACE
	setobjectxyperm LOCALID_JACE, 8, 7
	setobjectmovementtype LOCALID_JACE, MOVEMENT_TYPE_FACE_DOWN
	setobjectxyperm LOCALID_ROBIN, 8, 10
	setobjectmovementtype LOCALID_ROBIN, MOVEMENT_TYPE_FACE_UP
	addobject LOCALID_JACE
	addobject LOCALID_ROBIN
	removeobject LOCALID_JUSTIN
	clearflag FLAG_HIDE_JUSTIN_RANGER_HQ
	setobjectxyperm LOCALID_JUSTIN, 7, 10
	setobjectmovementtype LOCALID_JUSTIN, MOVEMENT_TYPE_FACE_UP
	addobject LOCALID_JUSTIN
	clearflag FLAG_HIDE_MISC_RANGER_HQ
	setobjectxyperm LOCALID_RANGER1, 10, 8
	setobjectxyperm LOCALID_RANGER2, 10, 9
	setobjectxyperm LOCALID_RANGER3, 5, 8
	setobjectxyperm LOCALID_RANGER4, 5, 9
	setobjectmovementtype LOCALID_RANGER1, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype LOCALID_RANGER2, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype LOCALID_RANGER3, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype LOCALID_RANGER4, MOVEMENT_TYPE_FACE_RIGHT
	addobject LOCALID_RANGER1
	addobject LOCALID_RANGER2
	addobject LOCALID_RANGER3
	addobject LOCALID_RANGER4
	return

	














MaroonCity_RangerHQ_3F_EventScript_Pokemon1::
	lock
	faceplayer
	playmoncry SPECIES_PURUGLY, CRY_MODE_NORMAL
	msgbox MaroonCity_RangerHQ_3F_Text_Pokemon1, MSGBOX_DEFAULT
	waitmoncry
	applymovement LOCALID_GLAMEOW, Common_Movement_FaceUp
	waitmovement 0
	release
	end

MaroonCity_RangerHQ_3F_Text_Pokemon1:
	.string "PURUGLY: Hissss!$"

MaroonCity_RangerHQ_3F_EventScript_Pokemon2::
	lock
	faceplayer
	playmoncry SPECIES_GROWLITHE, CRY_MODE_NORMAL
	msgbox MaroonCity_RangerHQ_3F_Text_Pokemon2, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MaroonCity_RangerHQ_3F_Text_Pokemon2:
	.string "GROWLITHE: Growrrrr...$"

MaroonCity_RangerHQ_3F_EventScript_Camper1::
	lock
	faceplayer
	msgbox MaroonCity_RangerHQ_3F_Text_GenesisPokemon1, MSGBOX_DEFAULT
	release
	end

MaroonCity_RangerHQ_3F_Text_GenesisPokemon1:
	.string "Believe it or not, some of these POKéMON\n"
	.string "used to belong to TEAM GENESIS.\p"
	.string "They were our enemies until they were\n"
	.string "abandoned for being “too weak.”\p"
	.string "We decided to take them back with us.\p"
	@.string "to rehabilitate it.\p"
	.string "TEAM GENESIS'S POKéMON are strong, but\n"
	.string "they're in constant pain.\p"
	.string "Their eyes are really sensitive\n"
	.string "and always bloodshot.\p"
	.string "At least the ones that have blood...\p"
	.string "\p"
	.string "We've slowly been trying to acclimate\n"
	.string "PURUGLY here to more natural light.\p"
	.string "It's been making progress, but still\n"
	.string "seems to prefer darker places.$"

MaroonCity_RangerHQ_3F_EventScript_Picnicker1::
	msgbox MaroonCity_RangerHQ_3F_Text_GenesisPokemon2, MSGBOX_NPC
	end

MaroonCity_RangerHQ_3F_Text_GenesisPokemon2:
	@.string "Rehabilitating these POKéMON isn't easy.\p"
	@.string "Treating these POKéMON isn't easy.\p"
	.string "Caring for these POKéMON isn't easy.\p"
	.string "They're really aggressive and used to\n"
	.string "TEAM GENESIS treating them harshly.\p"
	.string "But I believe everybody can make\n"
	.string "a change for the better.\p"
	.string "You should've seen how vicious\n"
	.string "they were when we found them!$"



MaroonCity_RangerHQ_3F_EventScript_Camper2::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_HM03, MaroonCity_RangerHQ_3F_EventScript_TryGiveSurf
	msgbox MaroonCity_RangerHQ_3F_Text_Deskwork, MSGBOX_DEFAULT
	release
	end

MaroonCity_RangerHQ_3F_Text_Deskwork:
	.string "Sigh. Why do I have to be the one\n"
	.string "stuck with boring desk work?$"

MaroonCity_RangerHQ_3F_EventScript_Picnicker2::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_HM03, MaroonCity_RangerHQ_3F_EventScript_TryGiveSurf
	msgbox MaroonCity_RangerHQ_3F_Text_JustinsFamily, MSGBOX_DEFAULT
	release
	end

MaroonCity_RangerHQ_3F_Text_JustinsFamily:
	.string "Don't tell JUSTIN, but I heard\n"
	.string "that his brother is actually\l"
	.string "one of the ELITE FOUR!$"

MaroonCity_RangerHQ_3F_EventScript_TryGiveSurf::
	msgbox MaroonCity_RangerHQ_3F_Text_TryGiveSurf, MSGBOX_DEFAULT
	giveitem ITEM_HM03
	goto_if_eq VAR_RESULT, 0, MaroonCity_RangerHQ_3F_EventScript_CantGiveSurf
	setflag FLAG_RECEIVED_HM03
	release
	end

MaroonCity_RangerHQ_3F_EventScript_CantGiveSurf::
	msgbox MaroonCity_RangerHQ_3F_Text_CantGiveSurf, MSGBOX_DEFAULT
	release
	end

MaroonCity_RangerHQ_3F_Text_TryGiveSurf:
	.string "You came back for this, didn't you?$"

MaroonCity_RangerHQ_3F_Text_CantGiveSurf:
	.string "Ah, but you still don't have\n"
	.string "enough room for it!$"







MaroonCity_RangerHQ_3F_EventScript_JustinIntro1::
	lockall
	setvar VAR_RANGER_HQ_STATE, 1
	applymovement LOCALID_JACE, Common_Movement_FaceUp
	waitmovement 0
	msgbox MaroonCity_RangerHQ_3F_Text_JaceNoticesPlayer, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	goto MaroonCity_RangerHQ_3F_EventScript_MeetingJustin
	end

MaroonCity_RangerHQ_3F_EventScript_JustinIntro2::
	lockall
	setvar VAR_RANGER_HQ_STATE, 1
	applymovement LOCALID_JACE, Common_Movement_FaceUp
	waitmovement 0
	msgbox MaroonCity_RangerHQ_3F_Text_JaceNoticesPlayer, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	goto MaroonCity_RangerHQ_3F_EventScript_MeetingJustin
	end

MaroonCity_RangerHQ_3F_EventScript_MeetingJustin::
	delay 30
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox MaroonCity_RangerHQ_3F_Text_JaceIntroducesPlayer, MSGBOX_DEFAULT
	closemessage
	delay 40
	applymovement LOCALID_JUSTIN, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox MaroonCity_RangerHQ_3F_Text_JustinIntro, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox MaroonCity_RangerHQ_3F_Text_JaceTellUsYourStory, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	delay 30
	fadescreen FADE_FROM_BLACK
	delay 60
	msgbox MaroonCity_RangerHQ_3F_Text_JustinHearsStory, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_ROBIN, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox MaroonCity_RangerHQ_3F_Text_RobinMentionsLab, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_JUSTIN, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox MaroonCity_RangerHQ_3F_Text_JustinExplainsLab, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JUSTIN, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_ROBIN, Common_Movement_FaceRight
	applymovement LOCALID_JACE, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	delay 120
	msgbox MaroonCity_RangerHQ_3F_Text_JustinWorthLookingInto, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_ROBIN, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox MaroonCity_RangerHQ_3F_Text_RobinVolunteersJace, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_JUSTIN, Common_Movement_FaceLeft
	waitmovement 0
	delay 60
	msgbox MaroonCity_RangerHQ_3F_Text_JustinHowConvenient, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox MaroonCity_RangerHQ_3F_Text_JaceNope, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox MaroonCity_RangerHQ_3F_Text_JustinExplainsAdderly, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_JUSTIN, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox MaroonCity_RangerHQ_3F_Text_JustinDeputizesJaceAndPlayer, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox MaroonCity_RangerHQ_3F_Text_JaceOoh, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox MaroonCity_RangerHQ_3F_Text_JustinDeputizesJaceAndPlayer2, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_HM03
	goto_if_eq VAR_RESULT, 0, MaroonCity_RangerHQ_3F_EventScript_NoRoomForSurf
	setflag FLAG_RECEIVED_HM03
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MaroonCity_RangerHQ_3F_Text_JaceCool, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_JUSTIN, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox MaroonCity_RangerHQ_3F_Text_PleaseCallMeJustin, MSGBOX_DEFAULT
	closemessage
	setvar VAR_JACE_STATE, 4
	warp MAP_MAROON_CITY, 22, 6
	waitstate
	releaseall
	end

MaroonCity_RangerHQ_3F_EventScript_NoRoomForSurf::
	msgbox MaroonCity_RangerHQ_3F_Text_NoRoomForSurf, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MaroonCity_RangerHQ_3F_Text_JaceCool, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_JUSTIN, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox MaroonCity_RangerHQ_3F_Text_PleaseCallMeJustin, MSGBOX_DEFAULT
	closemessage
	setvar VAR_JACE_STATE, 4
	warp MAP_MAROON_CITY, 22, 6
	waitstate
	releaseall
	end

MaroonCity_RangerHQ_3F_Text_NoRoomForSurf:
	.string "Oh {PLAYER}, it seems your bag is full.\n"
	.string "You'll need to make room for it first.\p"
	.string "One of my assistants here will give\n"
	.string "it to you when you're ready.$"


MaroonCity_RangerHQ_3F_Text_JaceNoticesPlayer:
	.string "JACE: {PLAYER}, there you are!\n"
	.string "What took you so long?$"

MaroonCity_RangerHQ_3F_Text_JaceIntroducesPlayer:
	.string "This is my friend, {PLAYER}.\p"
	.string "{PLAYER}, this is JUSTIN,\n"
	.string "the captain of the RANGERS.$"

MaroonCity_RangerHQ_3F_Text_JustinIntro:
	.string "Howdy, {PLAYER}. JACE told me about\n"
	.string "your run-in with TEAM GENESIS.\p"
	.string "Said you met them in PITCHBLAK CITY too.$"

MaroonCity_RangerHQ_3F_Text_JaceTellUsYourStory:
	.string "Yeah, tell us your story again, {PLAYER}.$"

MaroonCity_RangerHQ_3F_Text_JustinHearsStory:
	.string "JUSTIN: Hmmm...\n"
	.string "You said you heard a voice?\p"
	.string "And the next thing you knew, you were\n"
	.string "on the street with ROBIN and JACE.\p"
	.string "That is peculiar...$"

MaroonCity_RangerHQ_3F_Text_RobinMentionsLab:
	.string "{PLAYER} also said something about\n"
	.string "a place called AB LABS.\p"
	.string "It sounded familiar, but I couldn't\n"
	.string "remember where I heard it.\p"
	.string "Any idea what it could be?$"

MaroonCity_RangerHQ_3F_Text_JustinExplainsLab:
	.string "You probably heard some grownups talkin'\n"
	.string "about it. It was before your time.\p"
	.string "ADDERLY-BETTERMAN LABORATORIES\n"
	.string "or AB LABS.\p"
	.string "It's a research facility in\n"
	.string "WISTERIA CITY.\p"
	.string "But it was abandoned a long time ago.\n"
	.string "Now it's nothing but ruins.\p"
	.string "Could it have some connection to\n"
	.string "TEAM GENESIS...$"

MaroonCity_RangerHQ_3F_Text_JustinWorthLookingInto:
	.string "It might be worth looking into.\n"
	.string "There could be some clues left there.\p"
	.string "Unfortunately, we don't have people\n"
	.string "to spare right now...$"

MaroonCity_RangerHQ_3F_Text_RobinVolunteersJace:
	.string "How about JACE and {PLAYER}?\p"
	.string "They're capable trainers. And they're\n"
	.string "hunting for gym badges right now.$"

MaroonCity_RangerHQ_3F_Text_JustinHowConvenient:
	.string "Hunting for gym badges, you say?\n"
	.string "That is mighty convenient!\p"
	.string "You two ever been to WISTERIA CITY?$"

MaroonCity_RangerHQ_3F_Text_JaceNope:
	.string "No, is there a gym there?$"

MaroonCity_RangerHQ_3F_Text_JustinExplainsAdderly:
	.string "JUSTIN: There sure is.\p"
	.string "DR. ADDERLY, the WISTERIA gym leader,\n"
	.string "was once a researcher at AB LABS.\p"
	.string "The facility is partly named after him.\p"
	.string "If you want to get inside the lab,\n"
	.string "he's the man to talk to.\p"
	.string "But I should warn you, he's not the\n"
	.string "friendliest guy in the world.\p"
	.string "You might need to strong-arm\n"
	.string "him a bit.\p"
	.string "Figuratively speaking, that is.$"

MaroonCity_RangerHQ_3F_Text_JustinDeputizesJaceAndPlayer:
	.string "JUSTIN: Alright, JACE and {PLAYER}.\n"
	.string "Your mission is to find DR. ADDERLY.\p"
	.string "Get him to let you inside AB LABS.\p"
	.string "And look for any clues as to the\n"
	.string "whereabouts of TEAM GENESIS.\p"
	.string "You can tell him that JUSTIN of\n"
	.string "the POKéMON RANGERS sent you.$"

MaroonCity_RangerHQ_3F_Text_JaceOoh:
	.string "JACE: Ooh, so is this like an\n"
	.string "official POKéMON RANGER mission?$"

MaroonCity_RangerHQ_3F_Text_JustinDeputizesJaceAndPlayer2:
	.string "JUSTIN: Yup. As of right now,\n"
	.string "you can consider yourselves\l"
	.string "deputy POKéMON RANGERS.\p"
	.string "Here, this oughta help you\n"
	.string "get around a bit.$"

MaroonCity_RangerHQ_3F_Text_JaceCool:
	.string "JACE: Thank you, CAPTAIN JUSTIN sir!\n"
	.string "We won't let you down, I promise!$"

MaroonCity_RangerHQ_3F_Text_PleaseCallMeJustin:
	.string "Please, just call me JUSTIN.\p"
	.string "Now then, I need to get back to work.\n"
	.string "ROBIN can show you the way out.$"









MaroonCity_RangerHQ_3F_EventScript_BlackBallMeeting::
	lockall
	delay 120
	applymovement LOCALID_JUSTIN, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox MaroonCity_RangerHQ_3F_Text_JustinBlackBall, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox MaroonCity_RangerHQ_3F_Text_JaceYeah, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox MaroonCity_RangerHQ_3F_Text_JustinISee, MSGBOX_DEFAULT
	closemessage
	delay 40
	applymovement LOCALID_ROBIN, Common_Movement_FaceLeft
	waitmovement 0
	delay 20
	msgbox MaroonCity_RangerHQ_3F_Text_RobinDoesThatMean, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox MaroonCity_RangerHQ_3F_Text_JustinTooDangerous, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_JUSTIN, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox MaroonCity_RangerHQ_3F_Text_JustinScrambleTheRangers, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	call MaroonCity_RangerHQ_3F_EventScript_HideJustin
	call MaroonCity_RangerHQ_3F_EventScript_HideJace
	call MaroonCity_RangerHQ_3F_EventScript_HideMisc
	call MaroonCity_RangerHQ_3F_EventScript_HideBlackBall
	special HealPlayerParty
	setvar VAR_RANGER_HQ_STATE, 3
	fadescreen FADE_FROM_BLACK
	fadedefaultbgm
	releaseall
	end

MaroonCity_RangerHQ_3F_Text_JustinBlackBall:
	.string "JUSTIN: So this machine was recovered\n"
	.string "from the lab in WISTERIA CITY?\p"
	.string "And you say that it can create\n"
	.string "bridges across Ultra Space?$"

MaroonCity_RangerHQ_3F_Text_JaceYeah:
	.string "JACE: Yeah, and that guy took another\n"
	.string "one back to TEAM GENESIS!\p"
	.string "He said they were planning on doing\n"
	.string "something to XANTHOS CITY!$"

MaroonCity_RangerHQ_3F_Text_JustinISee:
	.string "JUSTIN: I see...\p"
	.string "So TEAM GENESIS was hiding beneath\n"
	.string "XANTHOS CITY this whole time.\p"
	.string "The UNDERGROUND CITY...\p"
	.string "There's only one way down there,\n"
	.string "and it's always closed to the public.\p"
	.string "It would be impossible to come and go\n"
	.string "through there without being noticed.\p"
	.string "But if what you told me is true, they\n"
	.string "could slip in and out from anywhere.\p"
	.string "It all makes sense why we could\n"
	.string "never find them before.$"

MaroonCity_RangerHQ_3F_Text_RobinDoesThatMean:
	.string "ROBIN: Does that mean we could go after\n"
	.string "them with this machine?$"

MaroonCity_RangerHQ_3F_Text_JustinTooDangerous:
	.string "JUSTIN: No. If this really is what caused\n"
	.string "the incident in WISTERIA CITY,\l"
	.string "then it's too dangerous to use.\p"
	.string "And it would be dangerous to let TEAM\n"
	.string "GENESIS use it themselves,\l"
	.string "whatever they plan to do with it.$"

MaroonCity_RangerHQ_3F_Text_JustinScrambleTheRangers:
	.string "JUSTIN: We have no choice.\p"
	.string "We have to stop them before they create\n"
	.string "another tragedy.\p"
	.string "We can't use this machine ourselves, but\n"
	.string "I know another way we can reach them.\p"
	.string "Everyone meet me at the shopping\n"
	.string "district in XANTHOS CITY.$"

