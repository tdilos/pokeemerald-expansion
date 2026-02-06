.set LOCALID_ADDERLY, 3
.set LOCALID_JACE, 2

WisteriaCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, WisteriaCity_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, WisteriaCity_OnWarp
	.byte 0

WisteriaCity_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, WisteriaCity_EventScript_UnsetForceOffscreenLoad
	.2byte 0

WisteriaCity_EventScript_UnsetForceOffscreenLoad::
	clearflag FLAG_FORCE_LOAD_OFFSCREEN_OBJEV
	end



WisteriaCity_OnTransition:
	setflag FLAG_VISITED_WISTERIA_CITY
	setvar VAR_WISTERIA_GYM_STATE, 0
	@setvar VAR_WISTERIA_GYM_ROOM, 0
	clearflag FLAG_WISTERIA_GYM_SWITCH_1
	clearflag FLAG_WISTERIA_GYM_SWITCH_2
	clearflag FLAG_WISTERIA_GYM_SWITCH_3
	clearflag FLAG_WISTERIA_GYM_SWITCH_4
	clearflag FLAG_WISTERIA_GYM_SWITCH_5
	clearflag FLAG_WISTERIA_GYM_SWITCH_6
	call_if_eq VAR_WISTERIA_CITY_STATE, 0, WisteriaCity_EventScript_RevealJaceAndAdderly
	call_if_eq VAR_WISTERIA_CITY_STATE, 1, WisteriaCity_EventScript_MoveJaceToLab
	call_if_ge VAR_WISTERIA_CITY_STATE, 1, WisteriaCity_EventScript_RemoveAdderly
	call_if_ge VAR_WISTERIA_CITY_STATE, 2, WisteriaCity_EventScript_RemoveJace
	end


	@ State descriptions for VAR_WISTERIA_CITY_STATE
	@ 0: Before meeting Adderly
	@ 1: Before unlocking door to Pokemon Laboratory
	@ 2: Before going into basement with Jace
	@ 3: Before walking with Rayner
	@ 4:




WisteriaCity_EventScript_RevealJaceAndAdderly:
	clearflag FLAG_HIDE_JACE
	return

WisteriaCity_EventScript_MoveJaceToLab:
	clearflag FLAG_HIDE_JACE
	setobjectxyperm LOCALID_JACE, 8, 14
	setobjectmovementtype LOCALID_JACE, MOVEMENT_TYPE_FACE_UP
	addobject LOCALID_JACE
	return

WisteriaCity_EventScript_RemoveAdderly:
	setobjectxyperm LOCALID_ADDERLY, 0, 0
	addobject LOCALID_ADDERLY
	return

WisteriaCity_EventScript_RemoveJace:
	setflag FLAG_HIDE_JACE
	removeobject LOCALID_JACE
	return










WisteriaCity_EventScript_TownSign::
	msgbox WisteriaCity_Text_TownSign, MSGBOX_SIGN
	end

WisteriaCity_Text_TownSign:
	.string "WISTERIA CITY\n"
	.string "“The forgotten city.”$"



WisteriaCity_EventScript_GymSign::
	msgbox WisteriaCity_Text_GymSign, MSGBOX_SIGN
	end

WisteriaCity_Text_GymSign:
	.string "WISTERIA CITY POKéMON GYM\n"
	.string "LEADER: ADDERLY\p"
	.string "There's some text scratched out\n"
	.string "at the bottom.$"



WisteriaCity_EventScript_BoardedUpDoor::
	msgbox WisteriaCity_Text_BoardedUpDoor, MSGBOX_SIGN
	end

WisteriaCity_Text_BoardedUpDoor:
	.string "The door is boarded up.$"




WisteriaCity_EventScript_Roughneck::
	msgbox WisteriaCity_Text_ToughGuy, MSGBOX_NPC
	end

WisteriaCity_Text_ToughGuy:
	.string "How tough are ya?$"








WisteriaCity_EventScript_CutsceneTrigger::
	lockall
	@applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	@waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	delay 30
	applymovement LOCALID_ADDERLY, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_ADDERLY, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_ADDERLY, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_ADDERLY, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_ADDERLY, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_ADDERLY, Common_Movement_WalkUp
	waitmovement 0
	removeobject LOCALID_ADDERLY
	call WisteriaCity_EventScript_RemoveAdderly
	delay 30
	@applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	@waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	delay 30
	applymovement LOCALID_JACE, Common_Movement_FaceLeft
	waitmovement 0
	delay 30
	msgbox WisteriaCity_Text_JaceIntro, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JACE, Common_Movement_FaceUp
	waitmovement 0
	delay 60
	applymovement LOCALID_JACE, Common_Movement_FaceLeft
	waitmovement 0
	delay 10
	msgbox WisteriaCity_Text_JaceIntro2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JACE, Common_Movement_FaceRight
	waitmovement 0
	delay 20
	applymovement LOCALID_JACE, Common_Movement_FaceLeft
	waitmovement 0
	delay 60
	msgbox WisteriaCity_Text_JaceIntro3, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_JACE, Common_Movement_FaceUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	delay 30
	msgbox WisteriaCity_Text_JaceIntro4, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_JACE, Common_Movement_FaceLeft
	waitmovement 0
	delay 10
	msgbox WisteriaCity_Text_JaceIntro5, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	removeobject LOCALID_JACE
	call WisteriaCity_EventScript_MoveJaceToLab
	setvar VAR_WISTERIA_CITY_STATE, 1
	releaseall
	end


@WisteriaCity_Text_JaceIntro:
@	.string "JACE: Oh hey, {PLAYER}.\n"
@	.string "You finally made it.\p"
@	.string "The good news is I met DR ADDERLY.\n"
@	.string "That was him just a second ago.\p"
@	.string "The bad news is he doesn't seem\n"
@	.string "interested in helping us.\p"
@	.string "He told me about the lab when I asked,\n"
@	.string "but he said it's locked up now.\p"
@	.string "And he won't let anybody else inside\n"
@	.string "ever again.\p"
@	.string "I told him about TEAM GENESIS\n"
@	.string "and the lab.\p"
@	.string "$"

WisteriaCity_Text_JaceIntro:
	.string "JACE: Oh hey, {PLAYER}.\n"
	.string "You finally made it.\p"
	.string "Hey, good news! I found DR. ADDERLY.\n"
	.string "That was him just now.\p"
	.string "Bad news is he doesn't seem\n"
	.string "interested in helping us.\p"
	.string "I guess he keeps the lab locked up\n"
	.string "and won't let anyone go inside.\p"
	.string "I tried telling him about JUSTIN and\n"
	.string "TEAM GENESIS and everything.\p"
	.string "But nothing changed his mind.$"

WisteriaCity_Text_JaceIntro2:
	.string "I don't think he trusts anybody.\p"
	.string "I guess bad people tried to get\n"
	.string "into the lab before.\p"
	.string "But hey, if we beat him in a gym battle,\n"
	.string "that might change his mind.\p"
	.string "If we show him we're good trainers and\n"
	.string "explain what we're looking for,\l"
	.string "I'm sure he'll want to help us then.$"

WisteriaCity_Text_JaceIntro3:
	.string "Anyway, I'm gonna go check out the lab\n"
	.string "before trying to talk him again.\p"
	.string "There could be clues on the outside too.\p"
	.string "In the meantime, you should try talking\n"
	.string "to him yourself.\p"
	.string "Who knows, maybe he'll listen to you.$"

WisteriaCity_Text_JaceIntro4:
	.string "See that waterfall?\n"
	.string "The lab is just beyond it.$"

WisteriaCity_Text_JaceIntro5:
	.string "I'll be up there if you need me.\n"
	.string "Best of luck, {PLAYER}.$"












WisteriaCity_EventScript_Jace::
	lock
	@faceplayer
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox WisteriaCity_Text_LockedDoor, MSGBOX_DEFAULT
	closemessage
	goto_if_unset FLAG_BADGE08_GET, WisteriaCity_EventScript_NoKeyYet
	checkitem ITEM_LAB_KEY
	goto_if_eq VAR_RESULT, FALSE, WisteriaCity_EventScript_NoKeyYet
	goto WisteriaCity_EventScript_JaceUnlocksDoor
	end

WisteriaCity_EventScript_NoKeyYet::
	@applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	@waitmovement 0
	@applymovement LOCALID_JACE, Common_Movement_FaceUp
	@waitmovement 0
	release
	end

WisteriaCity_Text_LockedDoor:
	.string "Darn! I was hoping there might be another\n"
	.string "way in, but it's really bolted up tight.\p"
	.string "If only we had the key...$"

WisteriaCity_EventScript_JaceUnlocksDoor::
	@applymovement LOCALID_JACE, Common_Movement_FaceDown
	@waitmovement 0
	delay 20
	faceplayer
	playse SE_PIN
	applymovement LOCALID_JACE, Common_Movement_ExclamationMark
	waitmovement 0
	delay 40
	msgbox WisteriaCity_Text_YouGotTheKey, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JACE, Common_Movement_FaceUp
	waitmovement 0
	delay 60
	msgbox WisteriaCity_Text_Bingo, MSGBOX_DEFAULT
	closemessage
	opendoor 8, 13
	waitdooranim
	applymovement LOCALID_JACE, Common_Movement_WalkUp
	waitmovement 0
	call WisteriaCity_EventScript_RemoveJace
	closedoor 8, 13
	waitdooranim
	setvar VAR_WISTERIA_CITY_STATE, 2
	release
	end

WisteriaCity_Text_YouGotTheKey:
	.string "Oh, you did it!\n"
	.string "You got the LAB KEY!\p"
	.string "Alright, let's try it.$"

WisteriaCity_Text_Bingo:
	.string "\p"
	.string "\p"
	.string "Bingo!\n"
	.string "Now let's have a look inside.$"





