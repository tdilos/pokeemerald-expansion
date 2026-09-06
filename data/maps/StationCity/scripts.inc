StationCity_MapScripts::
	.byte 0






StationCity_EventScript_TownSign::
	msgbox StationCity_Text_TownSign, MSGBOX_SIGN
	end

StationCity_Text_TownSign:
	.string "STATION CITY\n"
	.string "“The threshhold of the cosmos.”$"





StationCity_EventScript_MapPreviewTest::
	lock
	faceplayer
	msgbox StationCity_Text_GoodLuck, MSGBOX_DEFAULT
	mappreview 60
	release
	end

StationCity_Text_GoodLuck:
	.string "Good luck.$"


StationCity_EventScript_Boy1::
	lock
	faceplayer
	msgbox StationCity_Text_SeeMyHouse, MSGBOX_DEFAULT
	release
	end

StationCity_Text_SeeMyHouse:
	.string "Hah! You can see our roof from here!$"
	@.string "Heh. If you look up, you can\n"
	@.string "see my room from here.$"


StationCity_EventScript_Boy2::
	lock
	faceplayer
	msgbox StationCity_Text_WeirdPlace, MSGBOX_DEFAULT
	release
	end

StationCity_Text_WeirdPlace:
	.string "This place is too weird, man.\n"
	.string "Everything goes in circles...$"

