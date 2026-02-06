.set LOCALID_RIVAL, 1
.set LOCALID_BIRCH, 3
.set LOCALID_HAZEL, 6

.set LOCALID_CHESPIN, 2
.set LOCALID_TEPIG, 4
.set LOCALID_POPPLIO, 5

UmberTown_HazelsLab_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, UmberTown_HazelsLab_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, UmberTown_HazelsLab_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, UmberTown_HazelsLab_OnTransition
	.byte 0

UmberTown_HazelsLab_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, UmberTown_HazelsLab_EventScript_LabIntro
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, UmberTown_HazelsLab_EventScript_LabIntro2
	.2byte 0

UmberTown_HazelsLab_OnWarp:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, UmberTown_HazelsLab_EventScript_SetPlayerPosForReceiveStarter
	.2byte 0

UmberTown_HazelsLab_EventScript_SetPlayerPosForReceiveStarter::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

	@Reused variables

	@ State descriptions for VAR_LITTLEROOT_TOWN_STATE
	@ 1: First entered lab
	@ 2: Choosing a starter
	@ 3: Received starter
	@ 4: Battled Jace

	@ State descriptions for VAR_LITTLEROOT_INTRO_STATE
	@ 0: Before talking to mom
	@ 1: After talking to mom
	@ 2: If Jace stopped player and brought them directly to Hazel's Lab
	@ 3: Before battling Jace outside lab
	@ 4: Never used
	@ 5: Never used
	@ 6: Before showing mom your pokemon
	@ 7: After showing mom your pokemon


UmberTown_HazelsLab_OnTransition::
	@call_if_eq VAR_LITTLEROOT_INTRO_STATE, 1, UmberTown_HazelsLab_EventScript_HideHazel
	@call_if_eq VAR_LITTLEROOT_INTRO_STATE, 2, UmberTown_HazelsLab_EventScript_HideHazel
	call_if_ge VAR_LITTLEROOT_INTRO_STATE, 6, UmberTown_HazelsLab_EventScript_HideMayAndPokeballs
	@goto_if_eq VAR_LITTLEROOT_INTRO_STATE, 2, UmberTown_HazelsLab_EventScript_LabIntro
	@call_if_ge VAR_LITTLEROOT_INTRO_STATE, 3, UmberTown_HazelsLab_EventScript_HideJace
	call_if_set FLAG_DEFEATED_AMBER_GYM, UmberTown_HazelsLab_EventScript_RevealHazel
	end

@UmberTown_HazelsLab_EventScript_RevealJaceAndMay:
@	clearflag FLAG_HIDE_JACE
@	@addobject LOCALID_RIVAL
@	clearflag FLAG_HIDE_MAY
@	@addobject LOCALID_BIRCH
@	return

@UmberTown_HazelsLab_EventScript_HideJace:
@	removeobject LOCALID_JACE
@	return

UmberTown_HazelsLab_EventScript_HideHazel:
	removeobject LOCALID_HAZEL
	return

UmberTown_HazelsLab_EventScript_RevealHazel:
	clearflag FLAG_HIDE_UMBER_TOWN_HAZELS_LAB_HAZEL
	addobject LOCALID_HAZEL
	return

UmberTown_HazelsLab_EventScript_HideMayAndPokeballs::
	removeobject LOCALID_BIRCH
	@setflag FLAG_HIDE_UMBER_TOWN_HAZELS_LAB_POKEBALL_CHESPIN
	@setflag FLAG_HIDE_UMBER_TOWN_HAZELS_LAB_POKEBALL_TEPIG
	@setflag FLAG_HIDE_UMBER_TOWN_HAZELS_LAB_POKEBALL_POPPLIO
	removeobject LOCALID_CHESPIN
	removeobject LOCALID_TEPIG
	removeobject LOCALID_POPPLIO
	return

UmberTown_HazelsLab_EventScript_LabIntro2::
	lockall
	@call UmberTown_HazelsLab_EventScript_RevealJaceAndMay
	call UmberTown_HazelsLab_EventScript_HideHazel
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	goto UmberTown_HazelsLab_EventScript_MeetingMay
	end

UmberTown_HazelsLab_EventScript_LabIntro::
	lockall
	@call UmberTown_HazelsLab_EventScript_RevealJaceAndMay
	call UmberTown_HazelsLab_EventScript_HideHazel
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
	goto UmberTown_HazelsLab_EventScript_Slowpoke
	end


UmberTown_HazelsLab_EventScript_Slowpoke::
	applymovement LOCALID_RIVAL, Common_Movement_FaceDown
	waitmovement 0
	msgbox UmberTown_HazelsLab_Text_Slowpoke, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FaceUp
	waitmovement 0
	goto UmberTown_HazelsLab_EventScript_MeetingMay
	end

UmberTown_HazelsLab_Text_Slowpoke::
	.string "JACE: There you are, {PLAYER}.\p"
	.string "I told your mom to tell you to\n"
	.string "come over here like an hour ago.\p"
	.string "What are you, a SLOWPOKE?$"

UmberTown_HazelsLab_EventScript_MeetingMay::
	delay 20
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox UmberTown_HazelsLab_Text_MeetingMay, MSGBOX_DEFAULT
	closemessage
	delay 40
	applymovement LOCALID_RIVAL, Common_Movement_FaceLeft
	waitmovement 0
	delay 5
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox UmberTown_HazelsLab_Text_JaceRarePokemon, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_RIVAL, Common_Movement_FaceUp
	@waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	delay 60
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox UmberTown_HazelsLab_Text_MeetingMay2, MSGBOX_DEFAULT
	closemessage
	delay 40
	applymovement LOCALID_BIRCH, Common_Movement_FaceLeft
	waitmovement 0
	delay 40
	msgbox UmberTown_HazelsLab_Text_MayLookingForHazel, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceUp
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceUp
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox UmberTown_HazelsLab_Text_JaceHurryUp, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_BIRCH, Common_Movement_FaceDown
	waitmovement 0
	delay 20
	msgbox UmberTown_HazelsLab_Text_MayGettingToThat, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_BIRCH, Common_Movement_FaceUp
	waitmovement 0
	delay 60
	applymovement LOCALID_BIRCH, Common_Movement_FaceDown
	waitmovement 0
	delay 60
	applymovement LOCALID_BIRCH, Common_Movement_WalkDown
	waitmovement 0
	msgbox UmberTown_HazelsLab_Text_MayGivesPokedex, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_BIRCH, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_BIRCH, Common_Movement_FaceDown
	waitmovement 0
	playfanfare MUS_OBTAIN_ITEM
	message UmberTown_HazelsLab_Text_ReceivedPokedex
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setflag FLAG_ADVENTURE_STARTED
	@setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	@setvar VAR_LITTLEROOT_TOWN_STATE, 3
	delay 20
	msgbox UmberTown_HazelsLab_Text_MayTalksAboutPokedex, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BIRCH, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_BIRCH, Common_Movement_WalkUp
	waitmovement 0
	delay 30
	applymovement LOCALID_BIRCH, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_BIRCH, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_BIRCH, Common_Movement_FaceUp
	waitmovement 0
	delay 20
	@clearflag FLAG_HIDE_UMBER_TOWN_HAZELS_LAB_POKEBALL_CHESPIN
	@setflag FLAG_HIDE_UMBER_TOWN_HAZELS_LAB_POKEBALL_TEPIG
	@clearflag FLAG_HIDE_UMBER_TOWN_HAZELS_LAB_POKEBALL_POPPLIO
	addobject LOCALID_CHESPIN
	playse SE_BALL_OPEN
	waitse
	addobject LOCALID_TEPIG
	playse SE_BALL_OPEN
	waitse
	addobject LOCALID_POPPLIO
	playse SE_BALL_OPEN
	waitse
	applymovement LOCALID_BIRCH, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_BIRCH, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_BIRCH, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_BIRCH, Common_Movement_FaceDown
	waitmovement 0
	msgbox UmberTown_HazelsLab_Text_MayRevealsPokemon, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox UmberTown_HazelsLab_Text_JaceVolunteersPlayer, MSGBOX_DEFAULT
	closemessage
	delay 80
	msgbox UmberTown_HazelsLab_Text_MayReallyJace, MSGBOX_DEFAULT
	closemessage

	delay 30
	checkplayergender
	call_if_eq VAR_RESULT, MALE, UmberTown_HazelsLab_EventScript_HisBirthday
	call_if_eq VAR_RESULT, FEMALE, UmberTown_HazelsLab_EventScript_HerBirthday

	applymovement LOCALID_RIVAL, Common_Movement_FaceLeft
	waitmovement 0
	delay 5
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	delay 30
	msgbox UmberTown_HazelsLab_Text_JaceVolunteersPlayer2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, UmberTown_HazelsLab_EventScript_PlayerGoFirst
	goto_if_eq VAR_RESULT, NO, UmberTown_HazelsLab_EventScript_JaceGoFirst
	end

UmberTown_HazelsLab_Text_MeetingMay:
	.string "MAY: So this is your friend.\n"
	.string "{PLAYER}, was it?\p"
	.string "I'm MAY. I'm a POKéMON researcher\n"
	.string "from the HOENN region.\p"
	.string "Nice to meet you!$"

UmberTown_HazelsLab_Text_JaceRarePokemon:
	.string "JACE: MAY said she brought rare\n"
	.string "POKéMON with her.\p"
	.string "And she's going to let us have one!$"

UmberTown_HazelsLab_Text_MeetingMay2:
	.string "MAY: That's right. But first, I want to\n"
	.string "tell you a bit about my work.\p"
	.string "I'm here in ISSHO to learn about all the\n"
	.string "discoveries being reported.\p"
	.string "The researchers here have discovered\n"
	.string "so many new things about POKéMON.\p"
	.string "The scientific community is in a frenzy\n"
	.string "right now!$"

UmberTown_HazelsLab_Text_MayLookingForHazel:
	.string "I was also hoping to meet my dad's\n"
	.string "colleague in UMBER TOWN.\p"
	.string "But it seems she's not here right now...$"

UmberTown_HazelsLab_Text_JaceHurryUp:
	.string "JACE: C'mon, show us the POKéMON already!$"

UmberTown_HazelsLab_Text_MayGettingToThat:
	.string "MAY: I'm getting to that, JACE.\n"
	.string "Hold on.\p"
	.string "Anyway, I was hoping to meet\n"
	.string "new trainers like you.\p"
	.string "I can't be everywhere at once, so I'd like\n"
	.string "the two of you to help with my research.$"

UmberTown_HazelsLab_Text_MayGivesPokedex:
	.string "I brought these for my fieldwork, but I\n"
	.string "think the two of you should have them.$"


UmberTown_HazelsLab_Text_ReceivedPokedex:
	.string "{PLAYER} received a POKéDEX!$"

UmberTown_HazelsLab_Text_MayTalksAboutPokedex:
	.string "MAY: The POKéDEX is a virtual\n"
	.string "encyclopedia.\p"
	.string "It records species data for each\n"
	.string "POKéMON you encounter.\p"
	.string "But you'll need to catch the POKéMON\n"
	.string "to get its complete data.\p"
	.string "I'm hoping that the two of you will fill up\n"
	.string "that POKéDEX by catching many POKéMON.\p"
	.string "And to get you started, I've got three\n"
	.string "rare POKéMON here in my bag!$"


UmberTown_HazelsLab_Text_MayRevealsPokemon:
	.string "I'll let you both choose one to be\n"
	.string "your first partner.\p"
	.string "So, who wants to choose first?$"

UmberTown_HazelsLab_Text_JaceVolunteersPlayer:
	.string "JACE: I'll let {PLAYER} choose first.$"

UmberTown_HazelsLab_Text_MayReallyJace:
	.string "MAY: Really, JACE? Are you sure you\n"
	.string "don't want to go first?\p"
	.string "You were awfully impatient earlier...$"


UmberTown_HazelsLab_EventScript_HisBirthday::
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceUp
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox UmberTown_HazelsLab_Text_HisBirthday, MSGBOX_DEFAULT
	closemessage
	return

UmberTown_HazelsLab_EventScript_HerBirthday::
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceUp
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox UmberTown_HazelsLab_Text_HerBirthday, MSGBOX_DEFAULT
	closemessage
	return

UmberTown_HazelsLab_Text_HisBirthday:
	.string "JACE: That's because I wanted {PLAYER}\n"
	.string "to see them.\p"
	.string "It's his birthday, so he should have\n"
	.string "first dibs.\p"
	.string "I'm not picky, I don't mind going second.$"

UmberTown_HazelsLab_Text_HerBirthday:
	.string "JACE: That's because I wanted {PLAYER}\n"
	.string "to see them.\p"
	.string "It's her birthday, so she should have\n"
	.string "first dibs.\p"
	.string "I'm not picky, I don't mind going second.$"

UmberTown_HazelsLab_Text_JaceVolunteersPlayer2:
	.string "How about it, {PLAYER}?\n"
	.string "Why don't you choose first?$"

UmberTown_HazelsLab_EventScript_JaceGoFirst::
	msgbox UmberTown_HazelsLab_Text_JaceGoFirst, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox UmberTown_HazelsLab_Text_MayOhDear, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_RIVAL, Common_Movement_FaceDown
	waitmovement 0
	delay 20
	applymovement LOCALID_RIVAL, Common_Movement_FaceLeft
	waitmovement 0
	delay 20
	msgbox UmberTown_HazelsLab_Text_JaceCoinFlip, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, UmberTown_HazelsLab_EventScript_PlayerCallsHeads
	goto_if_eq VAR_RESULT, NO, UmberTown_HazelsLab_EventScript_PlayerCallsTails
	end

UmberTown_HazelsLab_Text_JaceGoFirst:
	.string "JACE: Huh? You want me to go first?\p"
	.string "Hey, I was just trying to be nice!\n"
	.string "You don't out-polite somebody!\p"
	.string "If I say you can go first, that means\n"
	.string "you go first!$"


UmberTown_HazelsLab_Text_MayOhDear:
	.string "MAY: Oh dear, what a strange situation.\p"
	.string "Neither of you wants to choose\n"
	.string "a POKéMON, huh?$"

UmberTown_HazelsLab_Text_JaceCoinFlip:
	.string "JACE: I've got it! I'll flip a coin, and\n"
	.string "the loser has to choose first, okay?\p"
	.string "...\p"
	.string "Alright, call it.\p"
	.string "And by the way, you should\n"
	.string "totally say heads.$"

UmberTown_HazelsLab_EventScript_PlayerCallsHeads::
	msgbox UmberTown_HazelsLab_Text_PlayerCallsHeads, MSGBOX_DEFAULT
	@closemessage
	goto UmberTown_HazelsLab_EventScript_PlayerGoFirst
	end

UmberTown_HazelsLab_EventScript_PlayerCallsTails::
	msgbox UmberTown_HazelsLab_Text_PlayerCallsTails, MSGBOX_DEFAULT
	@closemessage
	goto UmberTown_HazelsLab_EventScript_PlayerGoFirst
	end

UmberTown_HazelsLab_Text_PlayerCallsHeads:
	.string "Hah, wrong! It was tails!\p"
	.string "That means you have to pick first!\n"
	.string "Now hurry up and choose!$"

UmberTown_HazelsLab_Text_PlayerCallsTails:
	.string "Hah, it was heads!\n"
	.string "Got you with reverse psychology!\p"
	.string "That means you have to pick first!\n"
	.string "Now hurry up and choose!$"

	

UmberTown_HazelsLab_EventScript_PlayerGoFirst::
	closemessage
	applymovement LOCALID_RIVAL, Common_Movement_FaceUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
	releaseall
	end


UmberTown_HazelsLab_EventScript_May::
	goto_if_eq VAR_LITTLEROOT_TOWN_STATE, 2, UmberTown_HazelsLab_EventScript_MayDontBeNervous
	goto_if_eq VAR_LITTLEROOT_TOWN_STATE, 3, UmberTown_HazelsLab_EventScript_MayDontMindMe
	end


UmberTown_HazelsLab_EventScript_MayDontBeNervous::
	lockall
	faceplayer
	msgbox UmberTown_HazelsLab_Text_MayDontBeNervous, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

UmberTown_HazelsLab_EventScript_JaceTurnPlayerAround::
	lockall
	applymovement LOCALID_RIVAL, Common_Movement_FaceUp
	waitmovement 0
	msgbox UmberTown_HazelsLab_Text_JaceChooseAPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	releaseall
	end

UmberTown_HazelsLab_EventScript_JaceTurnPlayerAround2::
	lockall
	applymovement LOCALID_RIVAL, Common_Movement_FaceRight
	waitmovement 0
	msgbox UmberTown_HazelsLab_Text_JaceChooseAPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	releaseall
	end

UmberTown_HazelsLab_Text_JaceChooseAPokemon:
	.string "JACE: Hurry up and choose!$"

UmberTown_HazelsLab_Text_MayDontBeNervous:
	.string "MAY: Don't be nervous. Just choose\n"
	.string "the one you like the most.$"




UmberTown_HazelsLab_EventScript_Chespin::
	lockall
	goto_if_ge VAR_LITTLEROOT_TOWN_STATE, 3, UmberTown_HazelsLab_EventScript_AlreadyChoseStarter
	showmonpic SPECIES_CHESPIN, 10, 3
	playmoncry SPECIES_CHESPIN, CRY_MODE_NORMAL
	msgbox UmberTown_HazelsLab_Text_YoullTakeChespin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, UmberTown_HazelsLab_EventScript_GiveChespin
	hidemonpic
	releaseall
	end

UmberTown_HazelsLab_EventScript_GiveChespin::
	bufferspeciesname STR_VAR_1, SPECIES_CHESPIN
	setvar VAR_TEMP_1, SPECIES_CHESPIN
	message UmberTown_HazelsLab_Text_PlayerReceivesStarter
	givemon SPECIES_CHESPIN, 5
	playfanfare MUS_LEVEL_UP
	waitfanfare
	msgbox UmberTown_HazelsLab_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, UmberTown_HazelsLab_EventScript_NicknameStarter
	@setflag FLAG_HIDE_UMBER_TOWN_HAZELS_LAB_POKEBALL_CHESPIN
	removeobject LOCALID_CHESPIN
	setvar VAR_STARTER_MON, 0
	setflag FLAG_SYS_POKEMON_GET
	hidemonpic
	closemessage
	goto UmberTown_HazelsLab_EventScript_JaceChooses
	end

UmberTown_HazelsLab_EventScript_Tepig::
	lockall
	goto_if_ge VAR_LITTLEROOT_TOWN_STATE, 3, UmberTown_HazelsLab_EventScript_AlreadyChoseStarter
	showmonpic SPECIES_TEPIG, 10, 3
	playmoncry SPECIES_TEPIG, CRY_MODE_NORMAL
	msgbox UmberTown_HazelsLab_Text_YoullTakeTepig, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, UmberTown_HazelsLab_EventScript_GiveTepig
	hidemonpic
	releaseall
	end

UmberTown_HazelsLab_EventScript_GiveTepig::
	bufferspeciesname STR_VAR_1, SPECIES_TEPIG
	setvar VAR_TEMP_1, SPECIES_TEPIG
	message UmberTown_HazelsLab_Text_PlayerReceivesStarter
	givemon SPECIES_TEPIG, 5
	playfanfare MUS_LEVEL_UP
	waitfanfare
	msgbox UmberTown_HazelsLab_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, UmberTown_HazelsLab_EventScript_NicknameStarter
	@setflag FLAG_HIDE_UMBER_TOWN_HAZELS_LAB_POKEBALL_TEPIG
	removeobject LOCALID_TEPIG
	setvar VAR_STARTER_MON, 1
	setflag FLAG_SYS_POKEMON_GET
	hidemonpic
	closemessage
	goto UmberTown_HazelsLab_EventScript_JaceChooses
	end

UmberTown_HazelsLab_EventScript_Popplio::
	lockall
	goto_if_ge VAR_LITTLEROOT_TOWN_STATE, 3, UmberTown_HazelsLab_EventScript_AlreadyChoseStarter
	showmonpic SPECIES_POPPLIO, 10, 3
	playmoncry SPECIES_POPPLIO, CRY_MODE_NORMAL
	msgbox UmberTown_HazelsLab_Text_YoullTakePopplio, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, UmberTown_HazelsLab_EventScript_GivePopplio
	hidemonpic
	releaseall
	end

UmberTown_HazelsLab_EventScript_GivePopplio::
	bufferspeciesname STR_VAR_1, SPECIES_POPPLIO
	setvar VAR_TEMP_1, SPECIES_POPPLIO
	message UmberTown_HazelsLab_Text_PlayerReceivesStarter
	givemon SPECIES_POPPLIO, 5
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox UmberTown_HazelsLab_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, UmberTown_HazelsLab_EventScript_NicknameStarter
	@setflag FLAG_HIDE_UMBER_TOWN_HAZELS_LAB_POKEBALL_POPPLIO
	removeobject LOCALID_POPPLIO
	setvar VAR_STARTER_MON, 2
	setflag FLAG_SYS_POKEMON_GET
	hidemonpic
	closemessage
	goto UmberTown_HazelsLab_EventScript_JaceChooses
	end

UmberTown_HazelsLab_Text_WhyNotGiveNicknameToMon:
	.string "Would you like to give a nickname\n"
	.string "to this POKéMON?$"

UmberTown_HazelsLab_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	return

UmberTown_HazelsLab_Text_YoullTakeChespin:
	.string "The GRASS POKéMON,\n"
	.string "CHESPIN.\l"
	.string "Is that your choice?$"

UmberTown_HazelsLab_Text_YoullTakeTepig:
	.string "The FIRE POKéMON,\n"
	.string "TEPIG.\l"
	.string "Is that your choice?$"

UmberTown_HazelsLab_Text_YoullTakePopplio:
	.string "The WATER POKéMON,\n"
	.string "POPPLIO.\l"
	.string "Is that your choice?$"

UmberTown_HazelsLab_Text_PlayerReceivesStarter:
	.string "{PLAYER} received a {STR_VAR_1}!$"


UmberTown_HazelsLab_EventScript_JaceChooses::
	delay 60
	goto_if_eq VAR_TEMP_1, SPECIES_CHESPIN, UmberTown_HazelsLab_EventScript_JaceChoosesTepig
	goto_if_eq VAR_TEMP_1, SPECIES_TEPIG, UmberTown_HazelsLab_EventScript_JaceChoosesPopplio
	goto_if_eq VAR_TEMP_1, SPECIES_POPPLIO, UmberTown_HazelsLab_EventScript_JaceChoosesChespin
	end

UmberTown_HazelsLab_EventScript_JaceChoosesTepig::
	applymovement LOCALID_RIVAL, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkUp
	waitmovement 0
	@setflag FLAG_HIDE_UMBER_TOWN_HAZELS_LAB_POKEBALL_TEPIG
	msgbox UmberTown_HazelsLab_Text_JaceChoseThisOne, MSGBOX_DEFAULT
	closemessage
	removeobject LOCALID_TEPIG
	delay 40
	applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkLeft
	waitmovement 0
	goto UmberTown_HazelsLab_EventScript_JaceLeaves
	end

UmberTown_HazelsLab_EventScript_JaceChoosesPopplio::
	applymovement LOCALID_RIVAL, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkUp
	waitmovement 0
	@setflag FLAG_HIDE_UMBER_TOWN_HAZELS_LAB_POKEBALL_POPPLIO
	msgbox UmberTown_HazelsLab_Text_JaceChoseThisOne, MSGBOX_DEFAULT
	closemessage
	removeobject LOCALID_POPPLIO
	delay 40
	applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkLeft
	waitmovement 0
	goto UmberTown_HazelsLab_EventScript_JaceLeaves
	end

UmberTown_HazelsLab_EventScript_JaceChoosesChespin::
	applymovement LOCALID_RIVAL, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkUp
	waitmovement 0
	@setflag FLAG_HIDE_UMBER_TOWN_HAZELS_LAB_POKEBALL_CHESPIN
	msgbox UmberTown_HazelsLab_Text_JaceChoseThisOne, MSGBOX_DEFAULT
	closemessage
	removeobject LOCALID_CHESPIN
	delay 40
	applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkLeft
	waitmovement 0
	goto UmberTown_HazelsLab_EventScript_JaceLeaves
	end

UmberTown_HazelsLab_EventScript_JaceLeaves::
	@delay 40
	applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FaceUp
	@waitmovement 0
	applymovement LOCALID_BIRCH, Common_Movement_FaceDown
	@waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	msgbox UmberTown_HazelsLab_Text_JaceBye, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	waitmovement 0	
	applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	waitmovement 0	
	delay 40
	removeobject LOCALID_RIVAL
	playse SE_EXIT
	waitse
	delay 60
	goto UmberTown_HazelsLab_EventScript_MayGivesTownMap
	end

UmberTown_HazelsLab_Text_JaceChoseThisOne:
	.string "JACE: Okay, I choose this one.$"

UmberTown_HazelsLab_Text_JaceBye:
	.string "Finally, my own POKéMON!\p"
	.string "Time to start training!\n"
	.string "Thanks MAY!$"

UmberTown_HazelsLab_EventScript_MayGivesTownMap::
	applymovement LOCALID_BIRCH, Common_Movement_FaceRight
	waitmovement 0
	delay 5
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	delay 30
	msgbox UmberTown_HazelsLab_Text_MayGivesTownMap, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_STARTER_MON, 0, UmberTown_HazelsLab_EventScript_MayWalkToChespin
	call_if_eq VAR_STARTER_MON, 1, UmberTown_HazelsLab_EventScript_MayWalkToTepig
	call_if_eq VAR_STARTER_MON, 2, UmberTown_HazelsLab_EventScript_MayWalkToPopplio
	delay 20
	giveitem ITEM_TOWN_MAP
	@setvar VAR_LITTLEROOT_INTRO_STATE, 3
	setvar VAR_LITTLEROOT_TOWN_STATE, 3
	waitfanfare

	msgbox UmberTown_HazelsLab_Text_ExplainTownMap, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BIRCH, Common_Movement_FaceLeft
	waitmovement 0
	delay 40
	applymovement LOCALID_BIRCH, Common_Movement_FaceRight
	waitmovement 0
	msgbox UmberTown_HazelsLab_Text_MayNiceMeetingYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_STARTER_MON, 0, UmberTown_HazelsLab_EventScript_MayWalkFromChespin
	call_if_eq VAR_STARTER_MON, 1, UmberTown_HazelsLab_EventScript_MayWalkFromTepig
	call_if_eq VAR_STARTER_MON, 2, UmberTown_HazelsLab_EventScript_MayWalkFromPopplio
	@questmenu QUEST_MENU_UNLOCK_QUEST QUEST_3
	startquest QUEST_3
	releaseall
	end

UmberTown_HazelsLab_Text_MayGivesTownMap:
	.string "MAY: Well, your friend certainly doesn't\n"
	.string "believe in wasting time, does he?\p"
	.string "I had one more thing I wanted to give\n"
	.string "to both of you.\p"
	.string "So I'll have to ask you to give it\n"
	.string "to JACE the next time you see him.\p"
	.string "Can you do that for me?$"

UmberTown_HazelsLab_Text_ExplainTownMap:
	.string "That's a map of the ISSHO region.\p"
	.string "It should come in handy while\n"
	.string "you're traveling.$"


UmberTown_HazelsLab_Text_MayNiceMeetingYou:
	.string "Well, I just have a few more things\n"
	.string "to finish up here.\p"
	.string "It was nice meeting you, {PLAYER}!\n"
	.string "I'm sure you'll raise that POKéMON well!\p"
	.string "If you get a chance, you should stop by\n"
	.string "my house in XANTHOS CITY.\p"
	.string "I'm looking forward to seeing what\n"
	.string "you record in that POKéDEX!$"

UmberTown_HazelsLab_EventScript_MayWalkToPopplio::
	applymovement LOCALID_BIRCH, Common_Movement_WalkRight
	waitmovement 0
UmberTown_HazelsLab_EventScript_MayWalkToTepig::
	applymovement LOCALID_BIRCH, Common_Movement_WalkRight
	waitmovement 0
UmberTown_HazelsLab_EventScript_MayWalkToChespin::
	applymovement LOCALID_BIRCH, Common_Movement_WalkRight
	waitmovement 0
	return

UmberTown_HazelsLab_EventScript_MayWalkFromPopplio::
	applymovement LOCALID_BIRCH, Common_Movement_WalkLeft
	waitmovement 0
UmberTown_HazelsLab_EventScript_MayWalkFromTepig::
	applymovement LOCALID_BIRCH, Common_Movement_WalkLeft
	waitmovement 0
UmberTown_HazelsLab_EventScript_MayWalkFromChespin::
	applymovement LOCALID_BIRCH, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_BIRCH, Common_Movement_WalkUp
	waitmovement 0
	return




UmberTown_HazelsLab_EventScript_AlreadyChoseStarter::
	msgbox UmberTown_HazelsLab_Text_BetterLeaveLastAlone, MSGBOX_DEFAULT
	releaseall
	end

UmberTown_HazelsLab_Text_BetterLeaveLastAlone:
	.string "It's MAY's last POKéMON.\n"
	.string "Better leave it alone.$"

UmberTown_HazelsLab_EventScript_MayDontMindMe::
	lockall
	faceplayer
	msgbox UmberTown_HazelsLab_Text_MayDontMindMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BIRCH, Common_Movement_FaceUp
	waitmovement 0
	releaseall
	end

UmberTown_HazelsLab_Text_MayDontMindMe:
	.string "MAY: Don't mind me. I just have a few\n"
	.string "more things to finish up here.$"

UmberTown_HazelsLab_EventScript_MaysBag::
	msgbox UmberTown_HazelsLab_Text_MaysBag, MSGBOX_DEFAULT
	closemessage
	end

UmberTown_HazelsLab_Text_MaysBag:
	.string "It's MAY's bag.\n"
	.string "Better leave it alone.$"




UmberTown_HazelsLab_EventScript_Hazel::
	lock
	faceplayer
	goto_if_set FLAG_SYS_PC_LANETTE, UmberTown_HazelsLab_EventScript_ExplainItemfinder
	msgbox UmberTown_HazelsLab_Text_HazelIntro, MSGBOX_DEFAULT
	@giveitem ITEM_DOWSING_MACHINE
	giveitem ITEM_EXP_SHARE
	setflag FLAG_SYS_PC_LANETTE
	msgbox UmberTown_HazelsLab_Text_ExplainItemfinder, MSGBOX_DEFAULT
	release
	end

UmberTown_HazelsLab_EventScript_ExplainItemfinder::
	msgbox UmberTown_HazelsLab_Text_ExplainItemfinder, MSGBOX_DEFAULT
	release
	end

UmberTown_HazelsLab_Text_HazelIntro:
	.string "Oh hello. I don't think we've\n"
	.string "formally met.\p"
	.string "I'm HAZEL. I'm the resident\n"
	.string "POKéMON professor.\p"
	.string "Well, prospective professor actually.\p"
	.string "I mostly work on my POKéMON\n"
	.string "Storage System.\p"
	.string "I designed the version used\n"
	.string "in this region.\p"
	.string "I'm not one for fieldwork like\n"
	.string "PROF. BIRCH and his family.\p"
	.string "Here, you'll probably get more use\n"
	.string "out of this than me.$"

UmberTown_HazelsLab_Text_ExplainItemfinder:
	@.string "HAZEL: That's a DOWSING MACHINE.\p"
	@.string "If there is an item nearby that's\n"
	@.string "not visible, it emits a sound.$"
	.string "HAZEL: Give that EXP SHARE to one\n"
	.string "of your POKéMON to hold.\p"
	.string "It will gain experience even if it\n"
	.string "doesn't participate in battle.$"

	


