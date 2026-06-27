StationCity_Building1_B1_Hallway_MapScripts::
	.byte 0


StationCity_Building1_B1_Hallway_EventScript_UltraWormhole::
	lock
	msgbox StationCity_Building1_B1_Hallway_Text_GoBackToHoenn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, StationCity_Building1_B1_Hallway_EventScript_Skip
	warp MAP_ALTERING_CAVE, 26, 13
	waitstate
	release
	end

StationCity_Building1_B1_Hallway_EventScript_Skip::
	release
	end

StationCity_Building1_B1_Hallway_Text_GoBackToHoenn:
	.string "Would you like to go back to\n"
	.string "the HOENN region?$"


