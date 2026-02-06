.set LOCALID_MOM, 1

UmberTown_MaleMCHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, UmberTown_MaleMCHouse_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, UmberTown_MaleMCHouse_OnTransition
	.byte 0

UmberTown_MaleMCHouse_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 0, UmberTown_MaleMCHouse_EventScript_MomIntro
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 3, UmberTown_MaleMCHouse_EventScript_MomPostgame
	.2byte 0

	@Reused variables

	@ State descriptions for VAR_LITTLEROOT_TOWN_STATE
	@ 0: Before setting clock
	@ 1: After setting clock
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


UmberTown_MaleMCHouse_OnTransition:
	setrespawn HEAL_LOCATION_UMBER_TOWN
	end

UmberTown_MaleMCHouse_EventScript_DisableBagUse:
	setflag FLAG_DISABLE_BAG_IN_BATTLE      @No items in battle on Hardcore/Insane
	@setflag FLAG_HIDE_SHORTCUT_NPCS         @No shortcuts in later dungeons
	@playse SE_DING_DONG
	@waitse
	return

UmberTown_MaleMCHouse_EventScript_MomPostgame::
	lockall
	applymovement LOCALID_MOM, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	delay 48
	applymovement LOCALID_MOM, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_WalkUp
	waitmovement 0
	msgbox UmberTown_MaleMCHouse_Text_MomPostgame, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message UmberTown_MaleMCHouse_Text_ReceivedNationalPokedex
	waitmessage
	waitfanfare
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	delay 20
	msgbox UmberTown_MaleMCHouse_Text_MomPostgame2, MSGBOX_DEFAULT
	giveitem ITEM_HM10
	goto_if_eq VAR_RESULT, 0, UmberTown_MaleMCHouse_EventScript_NoRoomForWaterfall
	msgbox UmberTown_MaleMCHouse_Text_MomPostgame3, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOM, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_WalkRight
	waitmovement 0
	startquest QUEST_4
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 4
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 4
	releaseall
	end
	
UmberTown_MaleMCHouse_EventScript_NoRoomForWaterfall::
	msgbox UmberTown_MaleMCHouse_Text_NoRoomForWaterfall, MSGBOX_DEFAULT
	closemessage
	msgbox UmberTown_MaleMCHouse_Text_MomPostgame3, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOM, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_WalkRight
	waitmovement 0
	startquest QUEST_4
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 4
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 4
	releaseall
	end

UmberTown_MaleMCHouse_Text_NoRoomForWaterfall:
	.string "Oh! It looks like you'll need to\n"
	.string "make more room in your bag.\p"
	.string "No worries, I'll hold onto it\n"
	.string "for you in the meantime.$"

UmberTown_MaleMCHouse_Text_MomPostgame:
	.string "MOM: There you are, honey.\n"
	.string "How's my big, strong champion?\p"
	.string "I was just bragging about you\n"
	.string "to the neighbors.\p"
	.string "Here, PROF. HAZEL ordered this for you.\n"
	.string "It's a brand new POKéDEX.$"

UmberTown_MaleMCHouse_Text_ReceivedNationalPokedex:
	.string "{PLAYER} received a NATIONAL POKéDEX!$"

UmberTown_MaleMCHouse_Text_MomPostgame2:
	.string "Oh, and your friend JACE\n"
	.string "stopped by earlier.\p"
	.string "He wanted to give you this.$"

UmberTown_MaleMCHouse_Text_MomPostgame3:
	.string "JACE also said something about\n"
	.string "a sailor in XANTHOS CITY.\p"
	@.string "I think he was planning to\n"
	@.string "visit the HOENN region.\p"
	.string "\p"
	.string "Oh, to think my baby's already a\n"
	.string "world class POKéMON trainer!\p"
	.string "I'm so proud of you, sweetie!\p"
	.string "\p"
	.string "So what are your plans now?\p"
	.string "Are you gonna go galavanting\n"
	.string "around the world?\p"
	@.string "Well, just remember, even champions come\n"
	@.string "home to visit their mommas from time to time.\p"
	.string "Well just don't forget to visit your\n"
	.string "momma from time to time.\p"
	.string "Go get 'em, honey!$"

UmberTown_MaleMCHouse_EventScript_MomIntro::
	lockall
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
	@call_if_ge VAR_DIFFICULTY, 1, UmberTown_MaleMCHouse_EventScript_DisableBagUse
	special GetDifficulty
	call_if_ge VAR_RESULT, 1, UmberTown_MaleMCHouse_EventScript_DisableBagUse
	applymovement LOCALID_MOM, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	delay 48
	applymovement LOCALID_MOM, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_WalkUp
	waitmovement 0
	msgbox UmberTown_MaleMCHouse_Text_MomIntro, MSGBOX_NPC
	playfanfare MUS_OBTAIN_ITEM
	message UmberTown_MaleMCHouse_Text_ReceivedRunningShoes
	waitfanfare
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	setflag FLAG_SYS_TV_START
	setflag FLAG_HIDE_UMBER_TOWN_HAZELS_LAB_HAZEL
	@setflag FLAG_HIDE_JACE
	@setflag FLAG_HIDE_MAY
	msgbox UmberTown_MaleMCHouse_Text_AlsoGotYouThis, MSGBOX_NPC
	closemessage
	setflag FLAG_SYS_QUEST_MENU_GET
	msgbox UmberTown_MaleMCHouse_Text_MomIntro2, MSGBOX_NPC
	closemessage
	applymovement LOCALID_MOM, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_WalkRight
	waitmovement 0
	releaseall
	end

UmberTown_MaleMCHouse_Text_MomIntro:
	.string "MOM: Oh, there you are, honey.\n"
	.string "Happy birthday!\p"
	.string "...\p"
	.string "Hmm? You didn't even remember?\n"
	.string "It's your birthday today!\p"
	.string "...\p"
	.string "To think that you're already 13.\n"
	.string "Kids grow up so fast.\p"
	.string "Oh here! I got you this new pair\n"
	.string "of RUNNING SHOES.$"


UmberTown_MaleMCHouse_Text_ReceivedRunningShoes:
	.string "{PLAYER} obtained the RUNNING SHOES.$"

UmberTown_MaleMCHouse_Text_AlsoGotYouThis:
	.string "I also got you this QUEST LOG.\p"
	.string "It should come in handy while\n"
	.string "you're traveling around.\p"
	.string "You can access it from\n"
	.string "the START MENU.$"


UmberTown_MaleMCHouse_Text_MomIntro2:
	.string "Oh, by the way, your friend JACE\n"
	.string "stopped by earlier.\p"
	.string "He said to tell you that there was a girl\n"
	.string "giving away POKéMON in town today.\p"
	.string "Oh to think my baby is already going out\n"
	.string "into the big wide world!\p"
	.string "If you ever need anything, remember that\n"
	.string "you can come home any time.\p"
	.string "Go get 'em, honey!$"




UmberTown_MaleMCHouse_EventScript_Mom::
	goto_if_set FLAG_IS_CHAMPION, UmberTown_MaleMCHouse_EventScript_TryGiveWaterfall
	goto_if_eq VAR_LITTLEROOT_INTRO_STATE, 1, UmberTown_MaleMCHouse_EventScript_Mom1
	@goto_if_eq VAR_LITTLEROOT_INTRO_STATE, 6, UmberTown_MaleMCHouse_EventScript_Mom6
	goto_if_eq VAR_LITTLEROOT_INTRO_STATE, 6, UmberTown_MaleMCHouse_EventScript_Mom7
	end


UmberTown_MaleMCHouse_EventScript_Mom1::
	lockall
	faceplayer
	msgbox UmberTown_MaleMCHouse_Text_JaceStoppedBy, MSGBOX_NPC
	applymovement LOCALID_MOM, Common_Movement_FaceRight
	releaseall
	end

@UmberTown_MaleMCHouse_EventScript_Mom6::
@	lockall
@	faceplayer
@	msgbox UmberTown_MaleMCHouse_Text_CutePokemon, MSGBOX_NPC
@	applymovement LOCALID_MOM, Common_Movement_FaceRight
@	releaseall
@	end

UmberTown_MaleMCHouse_EventScript_Mom7::
	lockall
	faceplayer
	msgbox UmberTown_MaleMCHouse_Text_YouShouldRestABit, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	incrementgamestat GAME_STAT_RESTED_AT_HOME
	msgbox UmberTown_MaleMCHouse_Text_DontPushYourselfTooHard, MSGBOX_DEFAULT
	@giveitem ITEM_HM10
	applymovement LOCALID_MOM, Common_Movement_FaceRight
	releaseall
	end

UmberTown_MaleMCHouse_Text_JaceStoppedBy:
	.string "MOM: I think JACE said he was going\n"
	.string "to the lab next door.$"

UmberTown_MaleMCHouse_Text_YouShouldRestABit:
	.string "MOM: How are you doing, {PLAYER}?\n"
	.string "You look a little tired.\p"
	.string "I think you should rest a bit.$"

UmberTown_MaleMCHouse_Text_DontPushYourselfTooHard:
	.string "Don't push yourself too hard, dear.\n"
	.string "You can always rest here.\p"
	.string "Go for it, honey!$"

UmberTown_MaleMCHouse_EventScript_TryGiveWaterfall::
	goto_if_set FLAG_RECEIVED_HM10, UmberTown_MaleMCHouse_EventScript_Mom7
	lockall
	faceplayer
	msgbox UmberTown_MaleMCHouse_Text_TryGiveWaterfall, MSGBOX_DEFAULT
	giveitem ITEM_HM10
	goto_if_eq VAR_RESULT, 0, UmberTown_MaleMCHouse_EventScript_CantGiveWaterfall
	setflag FLAG_RECEIVED_HM10
	applymovement LOCALID_MOM, Common_Movement_FaceRight
	releaseall
	end

UmberTown_MaleMCHouse_EventScript_CantGiveWaterfall::
	msgbox UmberTown_MaleMCHouse_Text_NoRoomForWaterfall, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOM, Common_Movement_FaceRight
	releaseall
	end

UmberTown_MaleMCHouse_Text_TryGiveWaterfall:
	.string "MOM: Here you are, dear. It's the\n"
	.string "present JACE wanted to give you.$" 
	



