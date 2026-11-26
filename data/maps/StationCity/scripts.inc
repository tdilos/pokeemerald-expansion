StationCity_MapScripts::
	.byte 0






StationCity_EventScript_TownSign::
	msgbox StationCity_Text_TownSign, MSGBOX_SIGN
	end

StationCity_Text_TownSign:
	.string "STATION CITY\n"
	.string "“The threshhold of the cosmos.”$"

StationCity_EventScript_LabSign::
	msgbox StationCity_Text_LabSign, MSGBOX_SIGN
	end

StationCity_Text_LabSign:
	.string "BETTERMAN'S LAB$"





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
	@.string "Hah! You can see our roof from here!$"
	.string "We're standing right underneath\n"
	.string "my house!$"
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


StationCity_EventScript_LittleBoy::
	lock
	faceplayer
	msgbox StationCity_Text_RocketScientist, MSGBOX_DEFAULT
	release
	end

StationCity_Text_RocketScientist:
	.string "My dad's a rocket scientist!\n"
	.string "How cool is that?$"


StationCity_EventScript_Man1::
	lock
	faceplayer
	msgbox StationCity_Text_Careful, MSGBOX_DEFAULT
	release
	end

StationCity_Text_Careful:
	.string "Be careful! This station is\n"
	.string "inhabited by wild Pokemon!$"

StationCity_EventScript_Scientist::
	lock
	faceplayer
	msgbox StationCity_Text_WildPokemon, MSGBOX_DEFAULT
	release
	end

StationCity_Text_WildPokemon:
	.string "No one knows where these wild\n"
	.string "Pokemon came from.\p"
	.string "It could be that the builders of this\n"
	.string "station intended it to be a\l"
	.string "seeder ship of sorts.$"


StationCity_EventScript_Man2::
	lock
	faceplayer
	msgbox StationCity_Text_FoundArift, MSGBOX_DEFAULT
	release
	end

StationCity_Text_FoundArift:
	.string "This station was adrift and derelict\n"
	.string "when we first got here.\p"
	.string "Some think it never had any pilots\n"
	.string "and malfunctioned on its own.\p"
	.string "Others believe the crew went crazy\n"
	.string "and abandoned everything here.\p"
	.string "And still other think the crew might\n"
	.string "have been wiped out by something.$"

