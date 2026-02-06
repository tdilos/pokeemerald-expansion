EventScript_NeedGenesisCardS::
	msgbox Text_ItNeedsCardKeyS, MSGBOX_DEFAULT
	releaseall
	end

EventScript_NeedGenesisCardA::
	msgbox Text_ItNeedsGenesisCardA, MSGBOX_DEFAULT
	releaseall
	end

EventScript_NeedGenesisCardB::
	msgbox Text_ItNeedsGenesisCardB, MSGBOX_DEFAULT
	releaseall
	end

EventScript_NeedGenesisCardC::
	msgbox Text_ItNeedsGenesisCardC, MSGBOX_DEFAULT
	releaseall
	end








EventScript_OpenUndergroundSDoor::
	setmetatile 18, 5, METATILE_Facility2_CorridorOpenDoor_Shadow, 0
	setmetatile 18, 6, METATILE_Facility2_CorridorOpenDoor_Shadow, 0
	setmetatile 19, 5, METATILE_Facility2_CorridorOpenDoor, 0
	setmetatile 19, 6, METATILE_Facility2_CorridorOpenDoor, 0
	return

EventScript_OpenUndergroundADoor::
	setmetatile 0, 35, METATILE_Facility2_SewerOpenDoor_Shadow, 0
	setmetatile 0, 36, METATILE_Facility2_SewerOpenDoor_Shadow, 0
	setmetatile 1, 35, METATILE_Facility2_SewerOpenDoor, 0
	setmetatile 1, 36, METATILE_Facility2_SewerOpenDoor, 0
	return

EventScript_OpenUndergroundBDoor1::
	setmetatile 11, 7, METATILE_Facility2_CorridorOpenDoor_Shadow, 0
	setmetatile 11, 8, METATILE_Facility2_CorridorOpenDoor_Shadow, 0
	setmetatile 12, 7, METATILE_Facility2_CorridorOpenDoor, 0
	setmetatile 12, 8, METATILE_Facility2_CorridorOpenDoor, 0
	return

EventScript_OpenUndergroundBDoor2::
	setmetatile 0, 7, METATILE_Facility2_CorridorOpenDoor_Shadow, 0
	setmetatile 0, 8, METATILE_Facility2_CorridorOpenDoor_Shadow, 0
	setmetatile 1, 7, METATILE_Facility2_CorridorOpenDoor, 0
	setmetatile 1, 8, METATILE_Facility2_CorridorOpenDoor, 0
	return

EventScript_OpenUndergroundCDoor1::
	setmetatile 16, 21, METATILE_Facility2_SewerOpenDoor_Shadow, 0
	setmetatile 16, 22, METATILE_Facility2_SewerOpenDoor_Shadow, 0
	setmetatile 17, 21, METATILE_Facility2_SewerOpenDoor, 0
	setmetatile 17, 22, METATILE_Facility2_SewerOpenDoor, 0
	return

EventScript_OpenUndergroundCDoor2::
	setmetatile 56, 4, METATILE_Facility2_SewerOpenDoor_Shadow, 0
	setmetatile 56, 5, METATILE_Facility2_SewerOpenDoor_Shadow, 0
	setmetatile 57, 4, METATILE_Facility2_SewerOpenDoor, 0
	setmetatile 57, 5, METATILE_Facility2_SewerOpenDoor, 0
	return


















UndergroundCity_EventScript_UndergroundSDoor::
	lockall
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_TEMP_10, EventScript_DoorUnlocked
	checkitem ITEM_GENESIS_S_CARD
	goto_if_eq VAR_RESULT, FALSE, EventScript_NeedGenesisCardS
	setflag FLAG_TEMP_10
	goto EventScript_UnlockUndergroundDoor
	end

UndergroundCity_EventScript_UndergroundADoor::
	lockall
	setvar VAR_TEMP_1, 2
	goto_if_set FLAG_TEMP_10, EventScript_DoorUnlocked
	checkitem ITEM_GENESIS_A_CARD
	goto_if_eq VAR_RESULT, FALSE, EventScript_NeedGenesisCardA
	setflag FLAG_TEMP_11
	goto EventScript_UnlockUndergroundDoor
	end

UndergroundCity_EventScript_UndergroundBDoor1::
	lockall
	setvar VAR_TEMP_1, 3
	goto_if_set FLAG_TEMP_10, EventScript_DoorUnlocked
	checkitem ITEM_GENESIS_B_CARD
	goto_if_eq VAR_RESULT, FALSE, EventScript_NeedGenesisCardB
	setflag FLAG_TEMP_12
	goto EventScript_UnlockUndergroundDoor
	end

UndergroundCity_EventScript_UndergroundBDoor2::
	lockall
	setvar VAR_TEMP_1, 4
	goto_if_set FLAG_TEMP_10, EventScript_DoorUnlocked
	checkitem ITEM_GENESIS_B_CARD
	goto_if_eq VAR_RESULT, FALSE, EventScript_NeedGenesisCardB
	setflag FLAG_TEMP_13
	goto EventScript_UnlockUndergroundDoor
	end

UndergroundCity_EventScript_UndergroundCDoor1::
	lockall
	setvar VAR_TEMP_1, 5
	goto_if_set FLAG_TEMP_10, EventScript_DoorUnlocked
	checkitem ITEM_GENESIS_C_CARD
	goto_if_eq VAR_RESULT, FALSE, EventScript_NeedGenesisCardC
	setflag FLAG_TEMP_14
	goto EventScript_UnlockUndergroundDoor
	end

UndergroundCity_EventScript_UndergroundCDoor2::
	lockall
	setvar VAR_TEMP_1, 6
	goto_if_set FLAG_TEMP_10, EventScript_DoorUnlocked
	checkitem ITEM_GENESIS_C_CARD
	goto_if_eq VAR_RESULT, FALSE, EventScript_NeedGenesisCardC
	setflag FLAG_TEMP_15
	goto EventScript_UnlockUndergroundDoor
	end

EventScript_UnlockUndergroundDoor::
	playfanfare MUS_LEVEL_UP
	msgbox Text_CardKeyOpenedDoor, MSGBOX_DEFAULT
	waitfanfare
	call_if_eq VAR_TEMP_1, 1, EventScript_OpenUndergroundSDoor
	call_if_eq VAR_TEMP_1, 2, EventScript_OpenUndergroundADoor
	call_if_eq VAR_TEMP_1, 3, EventScript_OpenUndergroundBDoor1
	call_if_eq VAR_TEMP_1, 4, EventScript_OpenUndergroundBDoor2
	call_if_eq VAR_TEMP_1, 5, EventScript_OpenUndergroundCDoor1
	call_if_eq VAR_TEMP_1, 6, EventScript_OpenUndergroundCDoor2
	waitse
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

Text_ItNeedsGenesisCardS:
	.string "Key card required.\n"
	.string "Clearance level S.$"

Text_ItNeedsGenesisCardA:
	.string "Key card required.\n"
	.string "Clearance level A.$"

Text_ItNeedsGenesisCardB:
	.string "Key card required.\n"
	.string "Clearance level B.$"

Text_ItNeedsGenesisCardC:
	.string "Key card required.\n"
	.string "Clearance level C.$"



