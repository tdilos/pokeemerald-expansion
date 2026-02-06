.set LOCALID_TICKETMAN, 1
.set LOCALID_SS_TIDAL, 3

XanthosCity_Harbor_MapScripts::
	.byte 0

XanthosCity_Harbor_EventScript_Sailor::
	msgbox XanthosCity_Harbor_Text_SailThereMyself, MSGBOX_NPC
	end

XanthosCity_Harbor_Text_SailThereMyself:
	.string "Hmph. I don't have a TRI PASS to board\n"
	.string "the ferry.\p"
	.string "If my POKéMON knew SURF, I would just\n"
	.string "cross the sea to TURQUOISE CITY myself!$"

XanthosCity_Harbor_EventScript_CheckTicket::
	lockall
	msgbox XanthosCity_Harbor_Text_DoYouHaveATicket, MSGBOX_NPC
	checkitem ITEM_TRI_PASS
	goto_if_eq VAR_RESULT, FALSE, XanthosCity_Harbor_EventScript_DontHaveTriPass
	message XanthosCity_Harbor_Text_FlashedTriPass
	waitmessage
	multichoicedefault 21, 6, MULTI_XANTHOS_FERRY, 2, FALSE
	switch VAR_RESULT
	case 0, XanthosCity_Harbor_EventScript_ChooseCobalt
	case 1, XanthosCity_Harbor_EventScript_ChooseTurquoise
	case 2, XanthosCity_Harbor_EventScript_CancelSailSelect
	case MULTI_B_PRESSED, XanthosCity_Harbor_EventScript_CancelSailSelect
	end

XanthosCity_Harbor_EventScript_ChooseCobalt::
	msgbox XanthosCity_Harbor_Text_AllAboard, MSGBOX_DEFAULT
	closemessage
	@applymovement LOCALID_TICKETMAN, Common_Movement_WalkLeft
	@waitmovement 0
	@applymovement LOCALID_TICKETMAN, Common_Movement_FaceRight
	@waitmovement 0
	@applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	@waitmovement 0
	@fadescreen FADE_TO_BLACK
	@fadeoutbgm 0
	@delay 10
	@playse SE_RG_SS_ANNE_HORN
	@waitse
	call XanthosCity_Harbor_EventScript_BoardFerryWithSailor
	warp MAP_COBALT_CITY_HARBOR, 8, 11
	waitstate
	releaseall
	end

XanthosCity_Harbor_EventScript_ChooseTurquoise::
	msgbox XanthosCity_Harbor_Text_AllAboard, MSGBOX_DEFAULT
	closemessage
	@applymovement LOCALID_TICKETMAN, Common_Movement_WalkLeft
	@waitmovement 0
	@applymovement LOCALID_TICKETMAN, Common_Movement_FaceRight
	@waitmovement 0
	@applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	@waitmovement 0

	@fadescreen FADE_TO_BLACK
	@fadeoutbgm 0
	@delay 10
	@playse SE_RG_SS_ANNE_HORN
	@waitse
	
	call XanthosCity_Harbor_EventScript_BoardFerryWithSailor
	warp MAP_TURQUOISE_CITY_HARBOR, 8, 11
	@playse SE_EXIT
	waitstate
	releaseall
	end

XanthosCity_Harbor_EventScript_CancelSailSelect::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, XanthosCity_Harbor_Movement_WalkDown
	waitmovement 0
	releaseall
	end

XanthosCity_Harbor_EventScript_DontHaveTriPass::
	msgbox XanthosCity_Harbor_Text_NeedATicket, MSGBOX_NPC
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, XanthosCity_Harbor_Movement_WalkDown
	waitmovement 0
	releaseall
	end

XanthosCity_Harbor_Movement_WalkDown::
	walk_down
	step_end

XanthosCity_Harbor_Text_DoYouHaveATicket:
	.string "Ahoy there! The ferry will be departing\n"
	.string "shortly.\p"
	.string "Excuse me, do you have a ticket?$"

XanthosCity_Harbor_Text_NeedATicket:
	.string "…\p"
	.string "I'm sorry. You need a ticket\n"
	.string "to get aboard.$"

XanthosCity_Harbor_Text_FlashedTriPass:
	.string "{PLAYER} flashed the TRI PASS!\p"
	.string "Excellent. And what's\n"
	.string "your final destination?$"

XanthosCity_Harbor_Text_AllAboard:
	.string "Very good. Step right this way.\n"
	.string "The ferry will depart soon.\p"
	.string "All aboooaard!$"









XanthosCity_Harbor_EventScript_BoardFerryWithSailor::
	applymovement LOCALID_TICKETMAN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 30
	removeobject LOCALID_TICKETMAN
	call_if_eq VAR_FACING, DIR_NORTH, XanthosCity_Harbor_EventScript_PlayerBoardFerryNorth
	call_if_eq VAR_FACING, DIR_EAST, XanthosCity_Harbor_EventScript_PlayerBoardFerryEast
	delay 30
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	playse SE_RG_SS_ANNE_HORN
	delay 30
	@waitse
	call Common_EventScript_FerryDepart
	return

XanthosCity_Harbor_EventScript_PlayerBoardFerryEast::
	applymovement OBJ_EVENT_ID_PLAYER, XanthosCity_Harbor_Movement_PlayerBoardFerryEast
	waitmovement 0
	return

XanthosCity_Harbor_EventScript_PlayerBoardFerryNorth::
	applymovement OBJ_EVENT_ID_PLAYER, XanthosCity_Harbor_Movement_PlayerBoardFerryNorth
	waitmovement 0
	return

XanthosCity_Harbor_Movement_PlayerBoardFerryEast:
	walk_right
	walk_in_place_faster_up
	step_end

XanthosCity_Harbor_Movement_PlayerBoardFerryNorth:
	walk_up
	step_end

