.set LOCALID_BUTLER, 5
.set LOCALID_OPC, 7

MindaroGardens_MansionLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MindaroGardens_MansionLobby_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, MindaroGardens_MansionLobby_OnTransition
	.byte 0

MindaroGardens_MansionLobby_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

MindaroGardens_MansionLobby_OnFrame:
	map_script_2 VAR_MINDARO_CITY_STATE, 2, MindaroGardens_MansionLobby_EventScript_ReceivePrize
	.2byte 0




MindaroGardens_MansionLobby_EventScript_Youngster::
	msgbox MindaroGardens_MansionLobby_Text_Mansion, MSGBOX_NPC
	end

MindaroGardens_MansionLobby_Text_Mansion:
	.string "This mansion is huge! Could you imagine\n"
	.string "living in a place like this?$"

MindaroGardens_MansionLobby_EventScript_Butler::
	msgbox MindaroGardens_MansionLobby_Text_InviteOnly, MSGBOX_NPC
	end

MindaroGardens_MansionLobby_Text_InviteOnly:
	.string "Sorry. The ballroom is only for guests\n"
	.string "with a special invitation.$"

MindaroGardens_MansionLobby_EventScript_Lady::
	msgbox MindaroGardens_MansionLobby_Text_Outrage, MSGBOX_NPC
	end

MindaroGardens_MansionLobby_Text_Outrage:
	.string "What does he mean, an invitation?\p"
	.string "My family have been honored guests\n"
	.string "here every year!$"

MindaroGardens_MansionLobby_EventScript_Maid::
	msgbox MindaroGardens_MansionLobby_Text_OffLimits, MSGBOX_NPC
	end

MindaroGardens_MansionLobby_Text_OffLimits:
	.string "This wing is off limits for guests.\p"
	.string "You're welcome to view the special\n"
	.string "display rooms upstairs.$"

MindaroGardens_MansionLobby_EventScript_Butler2::
	goto_if_unset FLAG_RECEIVED_HM02, MindaroGardens_MansionLobby_EventScript_TryToGiveFly
	msgbox MindaroGardens_MansionLobby_Text_ExplainFly, MSGBOX_NPC
	end

MindaroGardens_MansionLobby_Text_ExplainFly:
	.string "Teach that HM to one of your POKéMON.\p"
	.string "You'll be able to fly to any city or\n"
	.string "town you've been to before.\p"
	.string "Oh, but one more thing!\p"
	.string "You'll need the PITCHBLAK CITY\n"
	.string "gym badge to use it first.$"
	@.string "You'll be able to melt ice blocks\n"
	@.string "like the ones in MT SHIRO.\p"
	@.string "Oh, but one more thing!\p"
	@.string "You'll need the MINDARO CITY\n"
	@.string "gym badge to use it first.$"

MindaroGardens_MansionLobby_EventScript_TryToGiveFly::
	msgbox MindaroGardens_MansionLobby_Text_TryToGiveFly, MSGBOX_NPC
	giveitem ITEM_HM02
	goto_if_eq VAR_RESULT, 0, MindaroGardens_MansionLobby_EventScript_NoRoomForPrize2
	setflag FLAG_RECEIVED_HM02
	end
	
MindaroGardens_MansionLobby_Text_TryToGiveFly:
	.string "Please accept this prize we\n"
	.string "reserved for you.$"

MindaroGardens_MansionLobby_EventScript_NoRoomForPrize2::
	msgbox MindaroGardens_MansionLobby_Text_CantGiveFly, MSGBOX_DEFAULT
	closemessage
	end


MindaroGardens_MansionLobby_EventScript_ReceivePrize::
	lockall
	setvar VAR_MINDARO_CITY_STATE, 3	
	applymovement LOCALID_BUTLER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0	
	delay 40
	applymovement LOCALID_BUTLER, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_BUTLER, Common_Movement_FaceDown
	waitmovement 0
	msgbox MindaroGardens_MansionLobby_Text_GiveFly, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BUTLER, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_BUTLER, Common_Movement_FaceDown
	waitmovement 0
	giveitem ITEM_HM02
	goto_if_eq VAR_RESULT, 0, MindaroGardens_MansionLobby_EventScript_NoRoomForPrize
	@waitfanfare
	@closemessage
	setflag FLAG_RECEIVED_HM02
	applymovement LOCALID_BUTLER, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_BUTLER, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_BUTLER, Common_Movement_FaceRight
	waitmovement 0
	goto MindaroGardens_MansionLobby_EventScript_ExitOPC
	end

MindaroGardens_MansionLobby_Text_GiveFly:
	.string "Congratulations! You two made it just in\n"
	.string "time to claim the last prizes!\p"
	.string "Here, take these with you.$"

MindaroGardens_MansionLobby_EventScript_NoRoomForPrize::
	msgbox MindaroGardens_MansionLobby_Text_CantGiveFly, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BUTLER, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_BUTLER, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_BUTLER, Common_Movement_FaceRight
	waitmovement 0
	goto MindaroGardens_MansionLobby_EventScript_ExitOPC
	end

MindaroGardens_MansionLobby_Text_CantGiveFly:
	.string "Oh, but you can't possibly\n"
	.string "carry more in your bag!\p"
	.string "Please make room and come speak\n"
	.string "to me again.$"



MindaroGardens_MansionLobby_EventScript_ExitOPC::
	applymovement LOCALID_OPC, Common_Movement_WalkInPlaceUp
	waitmovement 0
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, MindaroGardens_MansionLobby_EventScript_ExitViolet
	goto_if_eq VAR_RESULT, FEMALE, MindaroGardens_MansionLobby_EventScript_ExitVert
	end

MindaroGardens_MansionLobby_EventScript_ExitViolet::
	msgbox MindaroGardens_MansionLobby_Text_VioletAwesome, MSGBOX_DEFAULT
	closemessage
	delay 60
	goto MindaroGardens_MansionLobby_EventScript_ExitOPC2
	end

MindaroGardens_MansionLobby_EventScript_ExitVert::
	msgbox MindaroGardens_MansionLobby_Text_VertAwesome, MSGBOX_DEFAULT
	closemessage
	delay 60
	goto MindaroGardens_MansionLobby_EventScript_ExitOPC2
	end

MindaroGardens_MansionLobby_EventScript_ExitOPC2::
	applymovement LOCALID_OPC, Common_Movement_FaceRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox MindaroGardens_MansionLobby_Text_OPCGoodbye, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OPC, Common_Movement_FaceDown
	waitmovement 0	
	delay 40
	removeobject LOCALID_OPC
	@setflag FLAG_RECEIVED_HM02
	setflag FLAG_REACHED_MINDARO_MANSION
	playse SE_EXIT
	waitse
	delay 60
	releaseall
	end

MindaroGardens_MansionLobby_Text_VioletAwesome:
	.string "VIOLET: Awesome! Now I won't have to\n"
	.string "backtrack anymore.$"
	@.string "VIOLET: Awesome! Now I can get through\n"
	@.string "MT SHIRO to SCARLET TOWN.$"

MindaroGardens_MansionLobby_Text_VertAwesome:
	.string "VERT: Awesome! Now I won't have to\n"
	.string "backtrack anymore.$"
	@.string "VERT: Awesome! Now I can get through\n"
	@.string "MT SHIRO to SCARLET TOWN.$"

MindaroGardens_MansionLobby_Text_OPCGoodbye:
	.string "Well, I should get going. I'm not one\n"
	.string "for this high society stuff.\p"
	.string "It was great to hang out\n"
	.string "with you again, {PLAYER}!\p"
	.string "I hope we meet again!$"



