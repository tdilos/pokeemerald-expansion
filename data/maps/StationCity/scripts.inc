StationCity_MapScripts::
	.byte 0


StationCity_EventScript_TownSign::
	msgbox StationCity_Text_TownSign, MSGBOX_SIGN
	end

StationCity_Text_TownSign:
	.string "STATION CITY\n"
	.string "“The threshhold of the cosmos.”$"




StationCity_EventScript_Boy::
	lock
	faceplayer
	msgbox StationCity_Text_SeeMyHouse, MSGBOX_DEFAULT
	release
	end

StationCity_Text_SeeMyHouse:
	.string "Hehehe. If you look up, you can\n"
	.string "see my apartment from here.$"



