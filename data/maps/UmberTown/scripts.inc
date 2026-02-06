.set LOCALID_RIVAL, 4
.set LOCALID_BIRCH, 5

UmberTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, UmberTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, UmberTown_OnFrame
	.byte 0


UmberTown_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, UmberTown_EventScript_JaceBattle
	.2byte 0

	@Reused variables

	@ State descriptions for VAR_LITTLEROOT_TOWN_STATE
	@ 1: Never used
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
	@ 6: After battling Jace, before showing mom your pokemon
	@ 7: After showing mom your pokemon


UmberTown_OnTransition:
	setflag FLAG_VISITED_UMBER_TOWN
	@setflag FLAG_HIDE_UMBER_TOWN_MAY
	@setflag FLAG_HIDE_UMBER_TOWN_JACE
	@setflag FLAG_HIDE_JACE
	@setflag FLAG_HIDE_MAY
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 1, UmberTown_EventScript_HideJaceAndMay
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, UmberTown_EventScript_MoveJaceToLab
	call_if_ge VAR_LITTLEROOT_INTRO_STATE, 6, UmberTown_EventScript_HideLabMayAndPokeballs
	@call_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, UmberTown_EventScript_JaceBattle
	end

UmberTown_EventScript_HideJaceAndMay:
	setflag FLAG_HIDE_JACE
	setflag FLAG_HIDE_MAY
	@removeobject LOCALID_RIVAL
	@removeobject LOCALID_BIRCH
	return

UmberTown_EventScript_HideLabMayAndPokeballs:
	setflag FLAG_HIDE_UMBER_TOWN_HAZELS_LAB_MAY
	@setflag FLAG_HIDE_MAY
	setflag FLAG_HIDE_UMBER_TOWN_HAZELS_LAB_POKEBALL_CHESPIN
	setflag FLAG_HIDE_UMBER_TOWN_HAZELS_LAB_POKEBALL_TEPIG
	setflag FLAG_HIDE_UMBER_TOWN_HAZELS_LAB_POKEBALL_POPPLIO
	return


UmberTown_EventScript_MoveJaceToLab::
	@clearflag FLAG_HIDE_UMBER_TOWN_JACE
	clearflag FLAG_HIDE_JACE
	setobjectxyperm LOCALID_RIVAL, 4, 21
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_UP
	addobject LOCALID_RIVAL
	return

UmberTown_EventScript_JaceBattle::
	lockall
	@playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	delay 20
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	msgbox UmberTown_Text_Surprised, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, UmberTown_Movement_JaceGetReady
	@waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, UmberTown_Movement_PlayerGetReady
	waitmovement 0
	delay 50
	switch VAR_STARTER_MON
	case 0, UmberTown_EventScript_StartJaceBattleChespin
	case 1, UmberTown_EventScript_StartJaceBattleTepig
	case 2, UmberTown_EventScript_StartJaceBattlePopplio
	end

UmberTown_Text_Surprised:
	.string "Surprised to see me again?\p"
	.string "I figured we should warm up with a\n"
	.string "POKéMON battle before we leave town.\p"
	.string "C'mon, show me what you've got!$"

UmberTown_Movement_JaceGetReady:
	delay_8
	walk_down
	walk_down
	walk_down
	walk_down
	face_up
	step_end

UmberTown_Movement_PlayerGetReady:
	delay_8
	delay_8
	walk_down
	walk_down
	step_end

UmberTown_EventScript_StartJaceBattleChespin::
	trainerbattle_no_intro_no_whiteout TRAINER_JACE_UMBER_TOWN_CHESPIN, UmberTown_Text_JaceDefeated
	goto UmberTown_EventScript_AfterJaceBattle
	end

UmberTown_EventScript_StartJaceBattleTepig::
	trainerbattle_no_intro_no_whiteout TRAINER_JACE_UMBER_TOWN_TEPIG, UmberTown_Text_JaceDefeated
	goto UmberTown_EventScript_AfterJaceBattle
	end

UmberTown_EventScript_StartJaceBattlePopplio::
	trainerbattle_no_intro_no_whiteout TRAINER_JACE_UMBER_TOWN_POPPLIO, UmberTown_Text_JaceDefeated
	goto UmberTown_EventScript_AfterJaceBattle
	end

UmberTown_Text_JaceDefeated:
	.string "Huh? But I thought I picked\n"
	.string "the right one.$"


UmberTown_EventScript_AfterJaceBattle::
	special CheckIfTeamFainted
	goto_if_eq VAR_RESULT, FALSE, UmberTown_EventScript_WonJaceBattle
	goto_if_eq VAR_RESULT, TRUE, UmberTown_EventScript_LostJaceBattle
	end


UmberTown_EventScript_WonJaceBattle::
	@playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	applymovement LOCALID_RIVAL, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkUp
	waitmovement 0
	delay 20
	msgbox UmberTown_Text_WonJaceBattle, MSGBOX_DEFAULT
	playfanfare MUS_LEVEL_UP
	msgbox UmberTown_Text_GaveJacePokedex, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	delay 30
	goto UmberTown_EventScript_MayExitsLab
	end

UmberTown_EventScript_LostJaceBattle::
	@playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	applymovement LOCALID_RIVAL, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkUp
	waitmovement 0
	delay 20
	msgbox UmberTown_Text_LostJaceBattle, MSGBOX_DEFAULT
	playfanfare MUS_LEVEL_UP
	msgbox UmberTown_Text_GaveJacePokedex, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	fadedefaultbgm
	delay 30
	goto UmberTown_EventScript_MayExitsLab
	end

UmberTown_Text_WonJaceBattle:
	.string "JACE: Hey now! Don't get cocky just\n"
	.string "because you beat me once!\p"
	.string "We're both still beginners, remember?\p"
	.string "...\p"
	.string "Oh, is that for me?$"

UmberTown_Text_LostJaceBattle:
	.string "JACE: It's okay, {PLAYER}. You just\n"
	.string "need to practice more.\p"
	.string "I'm sure you'll get better.\p"
	.string "...\p"
	.string "Oh, is that for me?$"

UmberTown_Text_GaveJacePokedex:
	.string "{PLAYER} gave JACE the TOWN MAP.$"

UmberTown_EventScript_MayExitsLab::
	playse SE_DOOR
	@clearflag FLAG_HIDE_UMBER_TOWN_MAY
	clearflag FLAG_HIDE_MAY
	addobject LOCALID_BIRCH
	delay 30
	applymovement LOCALID_BIRCH, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	delay 60


	@applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	@waitmovement 0
	@applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	@playse SE_PIN
	@waitmovement 0
	@applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	@waitmovement 0
	@delay 40


	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	applymovement LOCALID_RIVAL, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkUp
	waitmovement 0
	delay 20
	msgbox UmberTown_Text_MaySigh, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	delay 30
	playse SE_USE_ITEM
	special HealPlayerParty
	delay 40
	fadescreen FADE_FROM_BLACK
	delay 30
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceUp
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox UmberTown_Text_YouBet, MSGBOX_DEFAULT
	applymovement LOCALID_RIVAL, Common_Movement_FaceLeft
	waitmovement 0
	delay 5
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox UmberTown_Text_TakeOnLeague, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox UmberTown_Text_JaceNewChamp, MSGBOX_DEFAULT
	closemessage
	delay 40

	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox UmberTown_Text_TakeCare, MSGBOX_DEFAULT
	closemessage
	delay 40
	applymovement LOCALID_BIRCH, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_BIRCH, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_BIRCH, Common_Movement_WalkRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_RIVAL, Common_Movement_FaceRight
	waitmovement 0
	applymovement LOCALID_BIRCH, Common_Movement_FaceLeft
	waitmovement 0
	delay 20
	msgbox UmberTown_Text_MayBye, MSGBOX_DEFAULT

	@May turns and uses fly
	closemessage
	applymovement LOCALID_BIRCH, Common_Movement_FaceDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject LOCALID_BIRCH
	waitfieldeffect FLDEFF_NPCFLY_OUT
	call UmberTown_EventScript_HideLabMayAndPokeballs
	delay 60

	@Jace talks to player
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox UmberTown_Text_JaceBye, MSGBOX_DEFAULT
	closemessage
	@applymovement LOCALID_RIVAL, Common_Movement_WalkRight
	@waitmovement 0
	@applymovement LOCALID_RIVAL, Common_Movement_WalkRight
	@waitmovement 0
	@applymovement LOCALID_RIVAL, Common_Movement_WalkRight
	@waitmovement 0
	@applymovement LOCALID_RIVAL, Common_Movement_WalkRight
	@waitmovement 0
	@applymovement LOCALID_RIVAL, Common_Movement_WalkRight
	@waitmovement 0
	@applymovement LOCALID_RIVAL, Common_Movement_WalkRight
	applymovement LOCALID_RIVAL, UmberTown_Movement_JaceExit1
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	delay 60
	@applymovement LOCALID_RIVAL, Common_Movement_WalkLeft
	@waitmovement 0
	@applymovement LOCALID_RIVAL, Common_Movement_WalkLeft
	@waitmovement 0
	@applymovement LOCALID_RIVAL, Common_Movement_WalkLeft
	@waitmovement 0
	@applymovement LOCALID_RIVAL, Common_Movement_WalkLeft
	@waitmovement 0
	@applymovement LOCALID_RIVAL, Common_Movement_WalkLeft
	@waitmovement 0
	@applymovement LOCALID_RIVAL, Common_Movement_WalkLeft
	applymovement LOCALID_RIVAL, UmberTown_Movement_JaceExit2
	waitmovement 0
	delay 20
	msgbox UmberTown_Text_JaceBye2
	giveitem ITEM_POKE_BALL, 10
	waitfanfare
	msgbox UmberTown_Text_JaceBye3, MSGBOX_DEFAULT
	closemessage
	@applymovement LOCALID_RIVAL, Common_Movement_WalkRight
	@waitmovement 0
	@applymovement LOCALID_RIVAL, Common_Movement_WalkRight
	@waitmovement 0
	@applymovement LOCALID_RIVAL, Common_Movement_WalkRight
	@waitmovement 0
	@applymovement LOCALID_RIVAL, Common_Movement_WalkRight
	@waitmovement 0
	@applymovement LOCALID_RIVAL, Common_Movement_WalkRight
	@waitmovement 0
	@applymovement LOCALID_RIVAL, Common_Movement_WalkRight
	applymovement LOCALID_RIVAL, UmberTown_Movement_JaceExit3
	waitmovement 0
	removeobject LOCALID_RIVAL
	@setvar VAR_LITTLEROOT_TOWN_STATE, 4
	setvar VAR_LITTLEROOT_INTRO_STATE, 6
	@savebgm MUS_DUMMY
	@fadedefaultbgm
	@questmenu QUEST_MENU_UNLOCK_QUEST QUEST_1
	startquest QUEST_1
	releaseall
	end

UmberTown_Movement_JaceExit1:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

UmberTown_Movement_JaceExit2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

UmberTown_Movement_JaceExit3:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end


UmberTown_Text_MaySigh:
	@.string "MAY: Sigh... You two are as eager as ever.\p"
	@.string "Not five minutes after I gave you those POKéMON,\n"
	@.string "and you're already battling with them.\p"
	.string "MAY: Sigh... Already getting into fights,\n"
	.string "are we?\p"
	.string "Here, let me see your POKéMON.$"

UmberTown_Text_YouBet:
	.string "JACE: That's right! We have to get\n"
	.string "stronger!$"

UmberTown_Text_TakeOnLeague:
	.string "{PLAYER} and I are gonna take on the\n"
	.string "POKéMON LEAGUE together!\l"
	.string "Isn't that right, {PLAYER}?$"

UmberTown_Text_JaceNewChamp:
	.string "JACE: Of course, I'm the one who's\n"
	.string "gonna be the next champion.$"

UmberTown_Text_TakeCare:
	.string "MAY: Well, as long as you take care of\n"
	.string "yourselves and your POKéMON.$"

UmberTown_Text_MayBye:
	.string "MAY: There's a POKéMON gym not too\n"
	.string "far from here. It's in RESEDA TOWN.\p"
	.string "You can find it on that TOWN MAP\n"
	.string "I gave you.\p"
	@.string "...\p"
	.string "I'm going back to XANTHOS CITY.\n"
	.string "It's on the way to RESEDA TOWN.\p"
	.string "The two of you should stop by\n"
	.string "my house there.\p"
	.string "...\p"
	.string "Well, goodbye for now.$"

UmberTown_Text_JaceBye:
	.string "JACE: You hear that? There's a gym\n"
	.string "in RESEDA TOWN.\p"
	.string "I'm gonna be the first one to beat it!\n"
	.string "You just try to keep up.$"

UmberTown_Text_JaceBye2:
	.string "JACE: Oh, by the way, I wanted\n"
	.string "to give you these.\p"
	.string "It is your birthday and all.$"

@UmberTown_Text_ReceivedPokeballs:
@	.string "{PLAYER} received POKéBALLS from JACE!$"

UmberTown_Text_JaceBye3:
	.string "JACE: Wild POKéMON appear in places\n"
	.string "like caves and tall grass.\p"
	.string "Use your POKéMON to weaken them, then\n"
	.string "catch them with those POKéBALLS.\p"
	.string "Well, see you around {PLAYER}!\n"
	.string "Don't keep me waiting too long!$"









@UmberTown_EventScript_PCHouseEntrance::
@	lockall
@	setmetatile 16, 9, METATILE_Petalburg_Door_Littleroot, FALSE
@	special DrawWholeMapView
@	delay 20
@	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
@	waitmovement 0
@	applymovement OBJ_EVENT_ID_PLAYER, UmberTown_Movement_EnterRoom
@	waitmovement 0
@	checkplayergender
@	goto_if_eq VAR_RESULT, MALE, UmberTown_EventScript_EnterMalePCHouse
@	goto_if_eq VAR_RESULT, FEMALE, UmberTown_EventScript_EnterFemalePCHouse
@	end

@UmberTown_Movement_EnterRoom:
@	set_invisible
@	step_end

@UmberTown_EventScript_EnterMalePCHouse::
@	warp MAP_UMBER_TOWN_MALE_MCHOUSE, 1, 8
@	waitstate
@	releaseall
@	end

@UmberTown_EventScript_EnterFemalePCHouse::
@	warp MAP_UMBER_TOWN_FEMALE_MCHOUSE, 1, 8
@	waitstate
@	releaseall
@	end	

UmberTown_EventScript_Boy::
	msgbox UmberTown_Text_HazelProfessor, MSGBOX_NPC
	end

UmberTown_EventScript_FatMan::
	msgbox UmberTown_Text_Technology, MSGBOX_NPC
	end

UmberTown_EventScript_LittleGirl::
	msgbox UmberTown_Text_MommySays, MSGBOX_NPC
	end

UmberTown_EventScript_LabSign::
	msgbox UmberTown_Text_LabSign, MSGBOX_SIGN
	end

UmberTown_EventScript_JacesHouseSign::
	msgbox UmberTown_Text_JacesHouse, MSGBOX_SIGN
	end

UmberTown_Text_JacesHouse:
	.string "JACE'S HOUSE$"

UmberTown_EventScript_PlayersHouseSign::
	msgbox UmberTown_Text_PlayersHouse, MSGBOX_SIGN
	end

UmberTown_EventScript_TownSign::
	msgbox UmberTown_Text_TownSign, MSGBOX_SIGN
	end



UmberTown_Text_HazelProfessor:
	.string "HAZEL's not a full fledged\n"
	.string "POKéMON professor yet.\p"
	.string "She works with PROF. BIRCH\n"
	.string "from the HOENN region.$"

UmberTown_Text_MommySays:
	.string "My mommy says I'm not allowed to\n"
	.string "leave town by myself.\p"
	.string "It's dangerous without a POKéMON\n"
	.string "to protect you.$"

UmberTown_Text_Technology:
	.string "Technology is incredible!\p"
	.string "...\p"
	.string "At least, that's what some people say.\p"
	.string "I think too much can be a bad thing.$"
	@.string "I'm not so sure it's always\n"
	@.string "a good thing.$"

UmberTown_Text_LabSign:
	.string "HAZEL'S LAB$"

UmberTown_Text_PlayersHouse:
	.string "{PLAYER}'S HOUSE$"

UmberTown_Text_TownSign:
	.string "UMBER TOWN\n"
	.string "“Where things start out small.”$"









UmberTown_EventScript_JaceStopsPlayer::
	lockall
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	msgbox UmberTown_Text_CallPlayerName, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	delay 60
	@setflag FLAG_HIDE_UMBER_TOWN_JACE
	@clearflag FLAG_HIDE_JACE
	addobject LOCALID_RIVAL
	@delay 60
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	applymovement LOCALID_RIVAL, UmberTown_Movement_JaceWalkToPlayer
	waitmovement 0
	msgbox UmberTown_Text_YouDunce, MSGBOX_DEFAULT
	warp MAP_UMBER_TOWN_HAZELS_LAB, 6, 5
	@applymovement OBJ_EVENT_ID_PLAYER,  Common_Movement_FaceUp
	@waitmovement 0
	playse SE_EXIT
	waitstate
	releaseall
	end

UmberTown_Text_CallPlayerName:
	.string "????: {PLAYER}!$"

UmberTown_Text_YouDunce:
	.string "JACE: Leaving town already?\p"
	.string "You won't get far without any POKéMON,\n"
	.string "you dunce.\p"
	.string "C'mon, there's a girl in the lab\n"
	.string "who's giving away free POKéMON!$"

UmberTown_Movement_JaceWalkToPlayer:
	delay_8
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

UmberTown_EventScript_Pokemon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SPEAROW, CRY_MODE_NORMAL
	msgbox UmberTown_Text_Pokemon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

UmberTown_Text_Pokemon:
	.string "SPEAROW: Piyu piiyuu.$"














UmberTown_EventScript_WonderTradeDemo::
	faceplayer
	goto EventScript_DoWonderTrade
	end





UmberTown_EventScript_GiveEggDemo::
	lock
	faceplayer
	msgbox UmberTown_Text_TakePokemon, MSGBOX_DEFAULT
	@getpartysize
	@compare VAR_RESULT, 6
	@goto_if_eq UmberTown_EventScript_PlayerHasFullParty
	@giveegg SPECIES_EEVEE
	@setmonability 2, 2
	givemon SPECIES_SHUCKLE, 10, ITEM_TOUGA_BERRY
	setmonmove 2, 0, MOVE_SOMA_ATTACK
	setmonmove 2, 1, MOVE_PHRENO_ATTACK
	setmonmove 2, 2, MOVE_REBOUND_ARMOR
	setmonmove 2, 3, MOVE_TRI_ATTACK
	@givemon SPECIES_JOLTEON, 16, ITEM_LEFTOVERS
	@setmonability 3, 2
	playfanfare MUS_LEVEL_UP
	msgbox UmberTown_Text_ReceivedPokemon, MSGBOX_DEFAULT
	waitfanfare
	msgbox UmberTown_Text_SeeYa, MSGBOX_DEFAULT
	release
	end

UmberTown_EventScript_PlayerHasFullParty::
	msgbox UmberTown_Text_PlayerHasFullParty, MSGBOX_DEFAULT
	release
	end

UmberTown_Text_TakePokemon:
	.string "Please, take this EGG.$"

UmberTown_Text_ReceivedPokemon:
	.string "{PLAYER} received an EGG!$"

UmberTown_Text_PlayerHasFullParty:
	.string "Ah, your party is full.$"

UmberTown_Text_SeeYa:
	.string "See ya around, kid.$"

UmberTown_Movement_Dummy:
	@walk_down
	@walk_down
	delay_16
	@delay_16
	@delay_16
	delay_16
	emote_heart
	step_end


UmberTown_EventScript_GiveStuff2::
	lock
	faceplayer
	playse SE_DING_DONG
	waitse
	setwildbattle SPECIES_NIHILEGO, 120
	dowildbattle
	release
	end

UmberTown_EventScript_GiveStuffDemo::
	lock
	faceplayer
	@setflag FLAG_BATTLED_OPC_CINEROUS_TOWN
	@setflag FLAG_BADGE02_GET
	@setflag FLAG_IS_CHAMPION
	@setflag FLAG_SYS_NATIONAL_DEX
	@special EnableNationalPokedex
	@playse SE_DING_DONG
	@waitse

	@call UmberTown_EventScript_GiveTMs

	@setflag FLAG_SYS_TOWER_SILVER
	@setflag FLAG_SYS_DOME_SILVER
	@setflag FLAG_SYS_PALACE_SILVER
	@setflag FLAG_SYS_ARENA_SILVER
	@setflag FLAG_SYS_FACTORY_SILVER
	@setflag FLAG_SYS_PIKE_SILVER
	@setflag FLAG_SYS_PYRAMID_SILVER

	@giveitem ITEM_MASTER_BALL, 10
	@giveitem ITEM_AZURE_FLUTE
	@setflag FLAG_RECEIVED_AZURE_FLUTE

	@giveitem ITEM_APEX_TICKET
	@setflag FLAG_ENABLE_SHIP_PERENNIAL_PILLAR
	@giveitem ITEM_RAINBOW_PASS
	@setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	@giveitem ITEM_OLD_SEA_MAP
	@setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	@giveitem ITEM_EON_TICKET
	@setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND

	setvar VAR_0x8004, 777
	special GiveFrontierBattlePoints

	@applymovement 8, UmberTown_Movement_Dummy
	@waitmovement 0

	playmoncry SPECIES_TORNADUS, CRY_MODE_NORMAL
	setvar VAR_0x8004, SPECIES_TORNADUS
	special SetSeenMon
	showmonpic SPECIES_TORNADUS, 10, 3
	waitbuttonpress
	hidemonpic

	playmoncry SPECIES_THUNDURUS, CRY_MODE_NORMAL
	setvar VAR_0x8004, SPECIES_THUNDURUS
	special SetSeenMon
	showmonpic SPECIES_THUNDURUS, 10, 3
	waitbuttonpress
	hidemonpic

	playmoncry SPECIES_LANDORUS, CRY_MODE_NORMAL
	setvar VAR_0x8004, SPECIES_LANDORUS
	special SetSeenMon
	showmonpic SPECIES_LANDORUS, 10, 3
	waitbuttonpress
	hidemonpic

	playmoncry SPECIES_ENAMORUS, CRY_MODE_NORMAL
	setvar VAR_0x8004, SPECIES_ENAMORUS
	special SetSeenMon
	showmonpic SPECIES_ENAMORUS, 10, 3
	waitbuttonpress
	hidemonpic

	@cleartrainerflag TRAINER_ARTHUR_1
	@goto ResedaTown_Gym_EventScript_Arthur

	@clearflag FLAG_RESCUED_HEADBUTT_TUTOR
	@setvar VAR_CINEROUS_TOWN_STATE, 2
	@setvar VAR_CINEROUS_TOWER_STATE, 0

	@msgbox UmberTown_Text_TakeThis, MSGBOX_DEFAULT
	givemon SPECIES_WOBBUFFET, 80, ITEM_LEFTOVERS
	@givemon SPECIES_GRAVELER, 28, ITEM_ORAN_BERRY
	@givemon SPECIES_MUMBAO, 30, ITEM_ORAN_BERRY
	@setmonmove 5, 0, MOVE_BLOCK
	@setmonmove 5, 1, MOVE_SOLAR_BEAM
	@setmonmove 5, 2, MOVE_MOONLIGHT
	@setmonmove 5, 3, MOVE_FULL_MOON
	
	@special SavePlayerParty
	@setwildbattle SPECIES_TYRANITAR, 100, ITEM_KINGS_ROCK, SPECIES_MIENSHAO, 100, ITEM_KINGS_ROCK
	@call CinerousTower_Exterior_EventScript_OPCBattleSetup

	@msgbox UmberTown_Text_AndThese, MSGBOX_DEFAULT
	@giveitem ITEM_ULTRA_BALL, 20
	@giveitem ITEM_POTION, 20


	@msgbox UmberTown_Text_ZartoshtIntro, MSGBOX_DEFAULT
	@trainerbattle_no_intro TRAINER_GRUNT_RESEDA_WOODS, UmberTown_Text_ZartoshtDefeated
	@trainerbattle_no_intro TRAINER_GRUNT_ROUTE_84, UmberTown_Text_ZartoshtDefeated
	@trainerbattle_no_intro TRAINER_ZARTOSHT_1, UmberTown_Text_ZartoshtDefeated
	@trainerbattle_no_intro TRAINER_NEDA_1, UmberTown_Text_ZartoshtDefeated
	@trainerbattle_no_intro TRAINER_RAYNER_QUARTZ_CAVE, UmberTown_Text_ZartoshtDefeated

	@trainerbattle_no_intro TRAINER_ARTHUR_1, UmberTown_Text_ZartoshtDefeated
	@trainerbattle_no_intro TRAINER_TARAH_1, UmberTown_Text_ZartoshtDefeated
	@trainerbattle_no_intro TRAINER_MYRTLE_1, UmberTown_Text_ZartoshtDefeated
	@trainerbattle_no_intro TRAINER_EIRA_1, UmberTown_Text_ZartoshtDefeated
	@trainerbattle_no_intro TRAINER_CADE_1, UmberTown_Text_ZartoshtDefeated
	@trainerbattle_no_intro TRAINER_NIKOLAUS_1, UmberTown_Text_ZartoshtDefeated
	@trainerbattle_no_intro TRAINER_ETHEL_1, UmberTown_Text_ZartoshtDefeated
	@trainerbattle_no_intro TRAINER_ADDERLY_1, UmberTown_Text_ZartoshtDefeated

	@setvar VAR_TERRAIN, 64         @ Grassy terrain
	@setvar VAR_TERRAIN, 128        @ Misty terrain
	@setvar VAR_TERRAIN, 256        @ Electric terrain
	@setvar VAR_TERRAIN, 512        @ Psychic terrain
	@trainerbattle_no_intro TRAINER_AZAMI_1, UmberTown_Text_ZartoshtDefeated
	@setvar VAR_TERRAIN, 0

	@trainerbattle_double TRAINER_ANNA_AND_MEG_1, Route117_Text_AnnaIntro, Route117_Text_AnnaDefeat, Route117_Text_AnnaNotEnoughMons, Route117_EventScript_RegisterAnna
	@trainerbattle_no_intro_no_whiteout TRAINER_NEDA_1, UmberTown_Text_ZartoshtDefeated
	@setwildbattle SPECIES_FEAROW, 50
	@dowildbattle

	msgbox UmberTown_Text_SeeYa, MSGBOX_DEFAULT
	@special SaveGameNoPrompt
	@waitstate
	@removeobject 9
	release
	end

UmberTown_EventScript_HowNow::
	msgbox UmberTown_Text_ZartoshtDefeated, MSGBOX_DEFAULT
	release
	end

UmberTown_Text_TakeThis:
	.string "Please, take this.$"

UmberTown_Text_AndThese:
	.string "And these as well.$"

UmberTown_Text_ReceivedBalls:
	.string "{PLAYER} received 20 POKéBALLs!$"

UmberTown_Text_ZartoshtIntro:
	.string "Now you must die.$"

UmberTown_Text_ZartoshtDefeated:
	.string "How now, brown cow?$"


UmberTown_EventScript_GiveTMs::
	giveitem ITEM_TM01
	giveitem ITEM_TM02
	giveitem ITEM_TM03
	giveitem ITEM_TM04
	giveitem ITEM_TM05
	giveitem ITEM_TM06
	giveitem ITEM_TM07
	giveitem ITEM_TM08
	giveitem ITEM_TM09
	giveitem ITEM_TM10
	giveitem ITEM_TM11
	giveitem ITEM_TM12
	giveitem ITEM_TM13
	giveitem ITEM_TM14
	giveitem ITEM_TM15
	giveitem ITEM_TM16
	giveitem ITEM_TM17
	giveitem ITEM_TM18
	giveitem ITEM_TM19
	giveitem ITEM_TM20
	giveitem ITEM_TM21
	giveitem ITEM_TM22
	giveitem ITEM_TM23
	giveitem ITEM_TM24
	giveitem ITEM_TM25
	giveitem ITEM_TM26
	giveitem ITEM_TM27
	giveitem ITEM_TM28
	giveitem ITEM_TM29
	giveitem ITEM_TM30
	giveitem ITEM_TM31
	giveitem ITEM_TM32
	giveitem ITEM_TM33
	giveitem ITEM_TM34
	giveitem ITEM_TM35
	giveitem ITEM_TM36
	giveitem ITEM_TM37
	giveitem ITEM_TM38
	giveitem ITEM_TM39
	giveitem ITEM_TM40
	giveitem ITEM_TM41
	giveitem ITEM_TM42
	giveitem ITEM_TM43
	giveitem ITEM_TM44
	giveitem ITEM_TM45
	giveitem ITEM_TM46
	giveitem ITEM_TM47
	giveitem ITEM_TM48
	giveitem ITEM_TM49
	giveitem ITEM_TM50
	giveitem ITEM_TM51
	giveitem ITEM_TM52
	giveitem ITEM_TM53
	giveitem ITEM_TM54
	giveitem ITEM_TM55
	giveitem ITEM_TM56
	giveitem ITEM_TM57
	giveitem ITEM_TM58
	giveitem ITEM_TM59
	giveitem ITEM_TM60
	giveitem ITEM_TM61
	giveitem ITEM_TM62
	giveitem ITEM_TM63
	giveitem ITEM_TM64
	giveitem ITEM_TM65
	giveitem ITEM_TM66
	giveitem ITEM_TM67
	giveitem ITEM_TM68
	giveitem ITEM_TM69
	giveitem ITEM_TM70
	giveitem ITEM_TM71
	giveitem ITEM_TM72
	giveitem ITEM_TM73
	giveitem ITEM_TM74
	giveitem ITEM_TM75
	giveitem ITEM_TM76
	giveitem ITEM_TM77
	giveitem ITEM_TM78
	giveitem ITEM_TM79
	return

UmberTown_EventScript_StartAllQuests::
	startquest QUEST_1
	startquest QUEST_2
	startquest QUEST_3
	startquest QUEST_4
	startquest QUEST_5
	startquest QUEST_6
	startquest QUEST_7
	startquest QUEST_8
	startquest QUEST_9
	startquest QUEST_10
	startquest QUEST_11
	startquest QUEST_12
	startquest QUEST_13
	startquest QUEST_14
	startquest QUEST_15
	startquest QUEST_16
	startquest QUEST_17
	startquest QUEST_18
	startquest QUEST_19
	startquest QUEST_21
	startquest QUEST_22
	startquest QUEST_23
	startquest QUEST_24
	startquest QUEST_25
	startquest QUEST_26
	startquest QUEST_27
	startquest QUEST_28
	startquest QUEST_29
	startquest QUEST_30
	startquest QUEST_31
	startquest QUEST_32
	startquest QUEST_33
	startquest QUEST_34
	startquest QUEST_35
	startquest QUEST_36
	startquest QUEST_37
	startquest QUEST_38
	startquest QUEST_39
	startquest QUEST_40
	startquest QUEST_41
	startquest QUEST_42
	startquest QUEST_43
	startquest QUEST_44
	return







