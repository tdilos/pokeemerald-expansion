AbandonedShip_CaptainsOffice_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AbandonedShip_CaptainsOffice_OnTransition
	.byte 0

AbandonedShip_CaptainsOffice_OnTransition:
	goto_if_unset FLAG_IS_CHAMPION, AbandonedShip_CaptainsOffice_EventScript_HideWormhole
	@goto_if_set FLAG_BATTLED_VOLCANION, AbandonedShip_CaptainsOffice_EventScript_HideWormhole
	clearflag FLAG_HIDE_WORMHOLE_VOLCANION
	end

AbandonedShip_CaptainsOffice_EventScript_HideWormhole:
	setflag FLAG_HIDE_WORMHOLE_VOLCANION
	end


AbandonedShip_CaptainsOffice_EventScript_CaptSternAide::
	lock
	faceplayer
	goto_if_set FLAG_EXCHANGED_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner
	goto_if_set FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_2_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	msgbox AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner::
	msgbox AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus::
	msgbox AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner:
	.string "I'm investigating this ship on behalf\n"
	.string "of CAPT. STERN.\p"
	.string "He also asked me to find a SCANNER,\n"
	.string "but I haven't had any success…$"

AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner:
	.string "Oh! That's a SCANNER!\p"
	.string "Listen, can I get you to deliver that\n"
	.string "to CAPT. STERN?\p"
	.string "I want to investigate this ship a\n"
	.string "little more.$"

AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus:
	.string "This ship is called S.S. CACTUS.\n"
	.string "It seems to be from an earlier era.$"

