.set LOCALID_TICKETMAN, 2
.set LOCALID_SS_TIDAL, 1

CobaltCity_Harbor_MapScripts::
	.byte 0

CobaltCity_Harbor_EventScript_BugCatcher::
	msgbox CobaltCity_Harbor_Text_ShamrockIsland, MSGBOX_NPC
	end

CobaltCity_Harbor_Text_ShamrockIsland:
	.string "I was hoping to take the ferry\n"
	.string "to SHAMROCK ISLE.\p"
	.string "But I guess they don't stop there...$"

CobaltCity_Harbor_EventScript_CheckTicket::
	lockall
	msgbox CobaltCity_Harbor_Text_DoYouHaveATicket, MSGBOX_NPC
	checkitem ITEM_TRI_PASS
	goto_if_eq VAR_RESULT, FALSE, CobaltCity_Harbor_EventScript_DontHaveTriPass
	message CobaltCity_Harbor_Text_FlashedTriPass
	waitmessage
	multichoicedefault 21, 6, MULTI_COBALT_FERRY, 2, FALSE
	switch VAR_RESULT
	case 0, CobaltCity_Harbor_EventScript_ChooseTurquoise
	case 1, CobaltCity_Harbor_EventScript_ChooseXanthos
	case 2, CobaltCity_Harbor_EventScript_CancelSailSelect
	case MULTI_B_PRESSED, CobaltCity_Harbor_EventScript_CancelSailSelect
	end

CobaltCity_Harbor_EventScript_ChooseXanthos::
	msgbox CobaltCity_Harbor_Text_AllAboard, MSGBOX_DEFAULT
	closemessage
	call CobaltCity_Harbor_EventScript_BoardFerryWithSailor
	warp MAP_XANTHOS_CITY_HARBOR, 8, 11
	waitstate
	releaseall
	end

CobaltCity_Harbor_EventScript_ChooseTurquoise::
	msgbox CobaltCity_Harbor_Text_AllAboard, MSGBOX_DEFAULT
	closemessage
	call CobaltCity_Harbor_EventScript_BoardFerryWithSailor
	warp MAP_TURQUOISE_CITY_HARBOR, 8, 11
	waitstate
	releaseall
	end

CobaltCity_Harbor_EventScript_CancelSailSelect::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CobaltCity_Harbor_Movement_WalkDown
	waitmovement 0
	releaseall
	end

CobaltCity_Harbor_EventScript_DontHaveTriPass::
	msgbox CobaltCity_Harbor_Text_NeedATicket, MSGBOX_NPC
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CobaltCity_Harbor_Movement_WalkDown
	waitmovement 0
	releaseall
	end

CobaltCity_Harbor_EventScript_BoardFerryWithSailor::
	applymovement LOCALID_TICKETMAN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 30
	removeobject LOCALID_TICKETMAN
	call_if_eq VAR_FACING, DIR_NORTH, CobaltCity_Harbor_EventScript_PlayerBoardFerryNorth
	call_if_eq VAR_FACING, DIR_EAST, CobaltCity_Harbor_EventScript_PlayerBoardFerryEast
	delay 30
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	playse SE_RG_SS_ANNE_HORN
	delay 30
	call Common_EventScript_FerryDepart
	return

CobaltCity_Harbor_EventScript_PlayerBoardFerryEast::
	applymovement OBJ_EVENT_ID_PLAYER, CobaltCity_Harbor_Movement_PlayerBoardFerryEast
	waitmovement 0
	return

CobaltCity_Harbor_EventScript_PlayerBoardFerryNorth::
	applymovement OBJ_EVENT_ID_PLAYER, CobaltCity_Harbor_Movement_PlayerBoardFerryNorth
	waitmovement 0
	return

CobaltCity_Harbor_Movement_PlayerBoardFerryEast:
	walk_right
	walk_in_place_faster_up
	step_end

CobaltCity_Harbor_Movement_PlayerBoardFerryNorth:
	walk_up
	step_end

CobaltCity_Harbor_Movement_WalkDown::
	walk_down
	step_end

CobaltCity_Harbor_Text_DoYouHaveATicket:
	.string "Ahoy there! The ferry will be departing\n"
	.string "shortly.\p"
	.string "Excuse me, do you have a ticket?$"

CobaltCity_Harbor_Text_NeedATicket:
	.string "…\p"
	.string "I'm sorry. You need a ticket\n"
	.string "to get aboard.$"

CobaltCity_Harbor_Text_FlashedTriPass:
	.string "{PLAYER} flashed the TRI PASS!\p"
	.string "Excellent. And what's\n"
	.string "your final destination?$"

CobaltCity_Harbor_Text_AllAboard:
	.string "Very good. Step right this way.\n"
	.string "The ferry will depart soon.\p"
	.string "All aboooaard!$"




