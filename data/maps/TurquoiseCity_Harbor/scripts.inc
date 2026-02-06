.set LOCALID_TICKETMAN, 2
.set LOCALID_SS_TIDAL, 1

TurquoiseCity_Harbor_MapScripts::
	.byte 0

TurquoiseCity_Harbor_EventScript_Maniac::
	msgbox TurquoiseCity_Harbor_Text_Seasick, MSGBOX_NPC
	end

TurquoiseCity_Harbor_Text_Seasick:
	.string "Urrgh. I rode the ferry\n"
	.string "and got seasick...$"

TurquoiseCity_Harbor_EventScript_CheckTicket::
	lockall
	msgbox TurquoiseCity_Harbor_Text_DoYouHaveATicket, MSGBOX_NPC
	checkitem ITEM_TRI_PASS
	goto_if_eq VAR_RESULT, FALSE, TurquoiseCity_Harbor_EventScript_DontHaveTriPass
	message TurquoiseCity_Harbor_Text_FlashedTriPass
	waitmessage
	multichoicedefault 21, 6, MULTI_TURQUOISE_FERRY, 2, FALSE
	switch VAR_RESULT
	case 0, TurquoiseCity_Harbor_EventScript_ChooseCobalt
	case 1, TurquoiseCity_Harbor_EventScript_ChooseXanthos
	case 2, TurquoiseCity_Harbor_EventScript_CancelSailSelect
	case MULTI_B_PRESSED, TurquoiseCity_Harbor_EventScript_CancelSailSelect
	end

TurquoiseCity_Harbor_EventScript_ChooseXanthos::
	msgbox TurquoiseCity_Harbor_Text_AllAboard, MSGBOX_DEFAULT
	closemessage
	call TurquoiseCity_Harbor_EventScript_BoardFerryWithSailor
	warp MAP_XANTHOS_CITY_HARBOR, 8, 11
	waitstate
	releaseall
	end

TurquoiseCity_Harbor_EventScript_ChooseCobalt::
	msgbox TurquoiseCity_Harbor_Text_AllAboard, MSGBOX_DEFAULT
	closemessage
	call TurquoiseCity_Harbor_EventScript_BoardFerryWithSailor
	warp MAP_COBALT_CITY_HARBOR, 8, 11
	waitstate
	releaseall
	end

TurquoiseCity_Harbor_EventScript_CancelSailSelect::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TurquoiseCity_Harbor_Movement_WalkDown
	waitmovement 0
	releaseall
	end

TurquoiseCity_Harbor_EventScript_DontHaveTriPass::
	msgbox TurquoiseCity_Harbor_Text_NeedATicket, MSGBOX_NPC
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TurquoiseCity_Harbor_Movement_WalkDown
	waitmovement 0
	releaseall
	end

TurquoiseCity_Harbor_EventScript_BoardFerryWithSailor::
	applymovement LOCALID_TICKETMAN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 30
	removeobject LOCALID_TICKETMAN
	call_if_eq VAR_FACING, DIR_NORTH, TurquoiseCity_Harbor_EventScript_PlayerBoardFerryNorth
	call_if_eq VAR_FACING, DIR_EAST, TurquoiseCity_Harbor_EventScript_PlayerBoardFerryEast
	delay 30
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	playse SE_RG_SS_ANNE_HORN
	delay 30
	call Common_EventScript_FerryDepart
	return

TurquoiseCity_Harbor_EventScript_PlayerBoardFerryEast::
	applymovement OBJ_EVENT_ID_PLAYER, TurquoiseCity_Harbor_Movement_PlayerBoardFerryEast
	waitmovement 0
	return

TurquoiseCity_Harbor_EventScript_PlayerBoardFerryNorth::
	applymovement OBJ_EVENT_ID_PLAYER, TurquoiseCity_Harbor_Movement_PlayerBoardFerryNorth
	waitmovement 0
	return

TurquoiseCity_Harbor_Movement_PlayerBoardFerryEast:
	walk_right
	walk_in_place_faster_up
	step_end

TurquoiseCity_Harbor_Movement_PlayerBoardFerryNorth:
	walk_up
	step_end

TurquoiseCity_Harbor_Movement_WalkDown::
	walk_down
	step_end

TurquoiseCity_Harbor_Text_DoYouHaveATicket:
	.string "Ahoy there! The ferry will be departing\n"
	.string "shortly.\p"
	.string "Excuse me, do you have a ticket?$"

TurquoiseCity_Harbor_Text_NeedATicket:
	.string "…\p"
	.string "I'm sorry. You need a ticket\n"
	.string "to get aboard.$"

TurquoiseCity_Harbor_Text_FlashedTriPass:
	.string "{PLAYER} flashed the TRI PASS!\p"
	.string "Excellent. And what's\n"
	.string "your final destination?$"

TurquoiseCity_Harbor_Text_AllAboard:
	.string "Very good. Step right this way.\n"
	.string "The ferry will depart soon.\p"
	.string "All aboooaard!$"






