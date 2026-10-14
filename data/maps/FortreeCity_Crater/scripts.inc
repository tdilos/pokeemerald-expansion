FortreeCity_Crater_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Crater_OnTransition
	.byte 0

FortreeCity_Crater_OnTransition:
	setflag FLAG_VISITED_FORTREE_CITY
	end





FortreeCity_Crater_EventScript_CitySign::
	msgbox FortreeCity_Crater_Text_CitySign, MSGBOX_SIGN
	end

FortreeCity_Crater_Text_CitySign:
	.string "FORTREE CITY\n"
	.string "The rest has worn away.$"

FortreeCity_Crater_EventScript_ClosedSign::
	msgbox FortreeCity_Crater_Text_ClosedSign, MSGBOX_SIGN
	end

FortreeCity_Crater_Text_ClosedSign:
	.string "The whole building is closed off.$"

