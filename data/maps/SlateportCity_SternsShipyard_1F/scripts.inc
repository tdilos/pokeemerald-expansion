SlateportCity_SternsShipyard_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_SternsShipyard_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_SternsShipyard_1F_OnFrame
	.byte 0

SlateportCity_SternsShipyard_1F_OnTransition:
	call_if_eq VAR_SLATEPORT_CITY_STATE, 4, SlateportCity_SternsShipyard_1F_EventScript_SetPostBirchScene
	end

SlateportCity_SternsShipyard_1F_EventScript_SetPostBirchScene:
@	setobjectxyperm LOCALID_SHIPYARD_GRUNT1, 69, 69
@	setobjectmovementtype LOCALID_SHIPYARD_GRUNT1, MOVEMENT_TYPE_FACE_DOWN
	
	return

SlateportCity_SternsShipyard_1F_OnFrame:
	map_script_2 VAR_SLATEPORT_CITY_STATE, 3, SlateportCity_SternsShipyard_1F_EventScript_BirchScene
	.2byte 0




SlateportCity_SternsShipyard_1F_EventScript_BirchScene::
	lockall
	playbgm MUS_DUMMY, 0
	playse SE_PIN
	applymovement LOCALID_SHIPYARD_GRUNT1, Common_Movement_FaceDown
	applymovement LOCALID_SHIPYARD_GRUNT2, Common_Movement_FaceDown
	applymovement LOCALID_SHIPYARD_GRUNT3, Common_Movement_FaceDown
	applymovement LOCALID_SHIPYARD_GRUNT1, Common_Movement_ExclamationMark
	applymovement LOCALID_SHIPYARD_GRUNT2, Common_Movement_ExclamationMark
	applymovement LOCALID_SHIPYARD_GRUNT3, Common_Movement_ExclamationMark
	waitmovement 60

	msgbox SlateportCity_SternsShipyard_1F_Text_NotWhatItLooksLike1, MSGBOX_DEFAULT
	closemessage
	delay 60

	playbgm MUS_ENCOUNTER_MAGMA, 0
	msgbox SlateportCity_SternsShipyard_1F_Text_NotWhatItLooksLike2, MSGBOX_DEFAULT
	closemessage

	@trainerbattle_two_trainers TRAINER_SHIPYARD_GRUNT1, SlateportCity_SternsShipyard_1F_Text_Grunt1Defeated, TRAINER_SHIPYARD_GRUNT2, SlateportCity_SternsShipyard_1F_Text_Grunt2Defeated
	@playbgm MUS_ENCOUNTER_MAGMA, FALSE

	applymovement LOCALID_SHIPYARD_GRUNT1, Common_Movement_FaceUp
	playse SE_M_VITAL_THROW2
	waitse
	applymovement LOCALID_SHIPYARD_GRUNT2, Common_Movement_FaceUp
	playse SE_M_VITAL_THROW2
	waitse
	applymovement LOCALID_SHIPYARD_GRUNT3, Common_Movement_FaceUp
	playse SE_M_VITAL_THROW2
	waitse

	msgbox SlateportCity_SternsShipyard_1F_Text_MyHead, MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_LOOKER_SHIPYARD, Common_Movement_FaceLeft
	waitmovement 10
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0

	msgbox SlateportCity_SternsShipyard_1F_Text_NiceWork, MSGBOX_DEFAULT
	closemessage

	setvar VAR_SLATEPORT_CITY_STATE, 4
	releaseall
	end

SlateportCity_SternsShipyard_1F_Text_NotWhatItLooksLike1:
	.string "Hey wait!\n"
	.string "This isn't what it looks like!$"

SlateportCity_SternsShipyard_1F_Text_NotWhatItLooksLike2:
	.string "Okay, it is what it looks like.\p"
	.string "TEAM AQUA attack!$"

SlateportCity_SternsShipyard_1F_Text_Grunt1Defeated:
	.string "This wasn't supposed to happen!$"

SlateportCity_SternsShipyard_1F_Text_Grunt2Defeated:
	.string "I'm out of my depth here...$"

SlateportCity_SternsShipyard_1F_Text_MyHead:
	.string "Ughh...\n"
	.string "Time to say goodnight...$"

SlateportCity_SternsShipyard_1F_Text_NiceWork:
	.string "LOOKER: Nice work, {PLAYER}.\p"
	.string "I'll deal with these two and\n"
	.string "the professor.\p"
	.string "You check for anyone else hiding upstairs.$"



SlateportCity_SternsShipyard_1F_EventScript_AquaGrunt::
	lock
	msgbox SlateportCity_SternsShipyard_1F_Text_KnockedOut, MSGBOX_DEFAULT
	release
	end

SlateportCity_SternsShipyard_1F_Text_KnockedOut:
	.string "He's knocked unconscious.$"





SlateportCity_SternsShipyard_1F_EventScript_Dock::
	lockall
	@goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_SternsShipyard_1F_EventScript_FerryReady
	@goto_if_set FLAG_BADGE07_GET, SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined
	@goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran
	@goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_GoFindStern
	msgbox SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails, MSGBOX_DEFAULT
	@applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	@waitmovement 0
	@msgbox SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	@setflag FLAG_DOCK_REJECTED_DEVON_GOODS
	@setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	releaseall
	end

@SlateportCity_SternsShipyard_1F_EventScript_FerryReady::
@	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
@	waitmovement 0
@	msgbox SlateportCity_SternsShipyard_1F_Text_FerryIsReady, MSGBOX_DEFAULT
@	releaseall
@	end

@SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined::
@	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
@	waitmovement 0
@	msgbox SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs, MSGBOX_DEFAULT
@	releaseall
@	end

@SlateportCity_SternsShipyard_1F_EventScript_GoFindStern::
@	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
@	waitmovement 0
@	msgbox SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern, MSGBOX_DEFAULT
@	closemessage
@	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
@	waitmovement 0
@	releaseall
@	end

@SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran::
@	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
@	waitmovement 0
@	msgbox SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran, MSGBOX_DEFAULT
@	releaseall
@	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Briney::
	@msgbox SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails:
	.string "Umm… If this goes here, and that\n"
	.string "goes over there…\p"
	.string "Then where does this thing go?\n"
	.string "And what about that doohickey?\p"
	.string "Aaargh! I can't make heads or tails\n"
	.string "of this!$"

@SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern:
@	.string "Hm?\n"
@	.string "Hi, I'm DOCK.\p"
@	.string "CAPT. STERN commissioned me to\n"
@	.string "design a ferry.\p"
@	.string "Oh! That there…\n"
@	.string "Are they DEVON GOODS?\p"
@	.string "But, hmm…\n"
@	.string "This won't do…\p"
@	.string "CAPT. STERN went off somewhere.\n"
@	.string "He said he had some work to do.\p"
@	.string "Could I get you to go find CAPT.\n"
@	.string "STERN and deliver that to him?$"

@SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern:
@	.string "DOCK: Where could CAPT. STERN have\n"
@	.string "gone off to?\p"
@	.string "Could you go find CAPT. STERN and\n"
@	.string "deliver that parcel to him?$"

@SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran:
@	.string "DOCK: Shipbuilding is an art.\p"
@	.string "A lot of things can't be figured out\n"
@	.string "just by calculating.\p"
@	.string "I really could use advice from a veteran\n"
@	.string "who knows the seas…$"

@SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs:
@	.string "DOCK: Hi! MR. BRINEY's joined us to\n"
@	.string "lend us his help.\p"
@	.string "Thanks to the veteran sailor, the\n"
@	.string "ferry is steadily coming together.$"

@SlateportCity_SternsShipyard_1F_Text_FerryIsReady:
@	.string "DOCK: The ferry is finally ready!\p"
@	.string "The new S.S. TIDAL is truly a marvel\n"
@	.string "of technology!\p"
@	.string "But, I get the feeling that we can\n"
@	.string "make something even better.\p"
@	.string "You know, there's never an end to\n"
@	.string "technology's march.$"

@SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock:
@	.string "MR. BRINEY: Ah, {PLAYER}{KUN}!\n"
@	.string "It's been too long!\p"
@	.string "Aye, since I met you, this old sea dog's\n"
@	.string "been feeling frisky!\p"
@	.string "So I've decided to help DOCK make\n"
@	.string "a ferry.\p"
@	.string "Aye, after all, a ferry would be able\n"
@	.string "to carry a lot of people.\p"
@	.string "But, you know, that DOCK is really\n"
@	.string "something special.\p"
@	.string "With his knack for technology and\n"
@	.string "my experience, I'm sure that we can\l"
@	.string "build one great ship, aye!$"

SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing:
	.string "The seasons, the weather, where\n"
	.string "the moon sits in the sky…\p"
	.string "These and other conditions make\n"
	.string "the sea change its expression.\p"
	.string "That's right!\n"
	.string "The sea is like a living thing!$"

SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily:
	.string "I get seasick real easily.\n"
	.string "So I get to help out here instead.$"

