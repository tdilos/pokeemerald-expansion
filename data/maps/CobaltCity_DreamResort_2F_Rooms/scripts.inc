CobaltCity_DreamResort_2F_Rooms_MapScripts::
	.byte 0

DreamResort_EventScript_Eugene::
	trainerbattle_single TRAINER_EUGENE, DreamResort_Text_EugeneIntro, DreamResort_Text_EugeneDefeated
	msgbox DreamResort_Text_EugenePostBattle, MSGBOX_AUTOCLOSE
	end

DreamResort_EventScript_Mimi::
	trainerbattle_single TRAINER_MIMI, DreamResort_Text_MimiIntro, DreamResort_Text_MimiDefeated
	msgbox DreamResort_Text_MimiPostBattle, MSGBOX_AUTOCLOSE
	end

DreamResort_EventScript_Oscar::
	trainerbattle_single TRAINER_OSCAR, DreamResort_Text_OscarIntro, DreamResort_Text_OscarDefeated
	msgbox DreamResort_Text_OscarPostBattle, MSGBOX_AUTOCLOSE
	end

DreamResort_EventScript_Trisha::
	trainerbattle_single TRAINER_TRISHA, DreamResort_Text_TrishaIntro, DreamResort_Text_TrishaDefeated
	msgbox DreamResort_Text_TrishaPostBattle, MSGBOX_AUTOCLOSE
	end






DreamResort_EventScript_EggGentleman::
	lockall
	faceplayer
	goto_if_set FLAG_GOT_MELTAN_EGG, DreamResort_EventScript_PostEggComment
	goto_if_set FLAG_NO_ROOM_FOR_LARVESTA_EGG, DreamResort_EventScript_ReturnForEgg
	msgbox DreamResort_Text_LetMeTakeLookAtMons, MSGBOX_NPC
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_eq VAR_RESULT, FRIENDSHIP_200_TO_254, DreamResort_EventScript_LeadMonHighFriendship
	goto_if_eq VAR_RESULT, FRIENDSHIP_MAX, DreamResort_EventScript_LeadMonHighFriendship
	msgbox DreamResort_Text_HmmISeeIsee, MSGBOX_NPC
	releaseall
	end

DreamResort_EventScript_LeadMonHighFriendship::
	msgbox DreamResort_Text_TreatMonRightHaveThis, MSGBOX_NPC
	goto DreamResort_EventScript_TryGiveEgg
	end

DreamResort_EventScript_TryGiveEgg::
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, DreamResort_EventScript_NoRoomForEgg
	setflag FLAG_GOT_MELTAN_EGG
	giveegg SPECIES_MELTAN
	playfanfare MUS_LEVEL_UP
	message DreamResort_Text_ReceivedEggFromMan
	waitfanfare
	waitmessage
	goto DreamResort_EventScript_PostEggComment
	end

DreamResort_EventScript_PostEggComment::
	msgbox DreamResort_Text_GladIMetSomeoneLikeYou, MSGBOX_NPC
	release
	end

DreamResort_EventScript_NoRoomForEgg::
	setflag FLAG_NO_ROOM_FOR_LARVESTA_EGG
	msgbox DreamResort_Text_DontHaveSpaceInYourParty, MSGBOX_NPC
	release
	end

DreamResort_EventScript_ReturnForEgg::
	goto DreamResort_EventScript_TryGiveEgg
	end

DreamResort_Text_LetMeTakeLookAtMons::
    .string "You travel all over the place,\n"
    .string "don't you?\p"
    .string "You're not driving your POKéMON\n"
    .string "too harshly, are you?\p"
    .string "Let me take a look.\n"
    .string "… … …   … … …$"

DreamResort_Text_HmmISeeIsee::
    .string "Ah, hmm…\n"
    .string "I see, I see…$"

DreamResort_Text_TreatMonRightHaveThis::
    .string "Oh, impressive.\n"
    .string "You treat your POKéMON right.\p"
    .string "I think you can be entrusted with\n"
    .string "this.\p"
    .string "Please, I'd like you to have this.$"

DreamResort_Text_ReceivedEggFromMan::
    .string "{PLAYER} received an EGG\n"
    .string "from the man!$"

DreamResort_Text_DontHaveSpaceInYourParty::
    .string "…Unfortunately, you don't have\n"
    .string "space for this in your party.\p"
    .string "You'd better come back for it\n"
    .string "another time.$"

DreamResort_Text_GladIMetSomeoneLikeYou::
    .string "I received that EGG while I was\n"
    .string "traveling.\p"
    .string "I'm glad I met someone like you.$"


