StationCity_Building1_B1_MapScripts::
	.byte 0







StationCity_Building1_B1_EventScript_Betterman::
	lock
	faceplayer
	msgbox StationCity_Building1_B1_Text_ICanExplain, MSGBOX_DEFAULT
	special ScriptMenu_CreateLilycoveSSTidalMultichoice
	waitstate
	special GetLilycoveSSTidalSelection
	switch VAR_RESULT
	case 0, StationCity_Building1_B1_EventScript_WhereAreWe
	case 1, StationCity_Building1_B1_EventScript_WhatIsOvermind
	case 2, StationCity_Building1_B1_EventScript_WhatAreArchons
	case 3, StationCity_Building1_B1_EventScript_WhatAreSynderlings
	case 4, StationCity_Building1_B1_EventScript_WhatAreWormholes
	case 5, StationCity_Building1_B1_EventScript_Exit
	case MULTI_B_PRESSED, StationCity_Building1_B1_EventScript_Exit
	release
	end

StationCity_Building1_B1_Text_ICanExplain:
	.string "BETTERMAN: If you need an explanation,\n"
	.string "I'm certainly capable of giving it.$"

StationCity_Building1_B1_EventScript_WhereAreWe::
	msgbox StationCity_Building1_B1_Text_WhereAreWe, MSGBOX_DEFAULT
	closemessage
	release
	end

StationCity_Building1_B1_EventScript_WhatIsOvermind::
	msgbox StationCity_Building1_B1_Text_WhatIsOvermind, MSGBOX_DEFAULT
	closemessage
	release
	end

StationCity_Building1_B1_EventScript_WhatAreArchons::
	msgbox StationCity_Building1_B1_Text_WhatAreArchons, MSGBOX_DEFAULT
	closemessage
	release
	end

StationCity_Building1_B1_EventScript_WhatAreSynderlings::
	msgbox StationCity_Building1_B1_Text_WhatAreSynderlings, MSGBOX_DEFAULT
	closemessage
	release
	end

StationCity_Building1_B1_EventScript_WhatAreWormholes::
	msgbox StationCity_Building1_B1_Text_WhatAreWormholes, MSGBOX_DEFAULT
	closemessage
	release
	end

StationCity_Building1_B1_Text_WhereAreWe:
	.string "Oh, this place? Believe it or not,\n"
	.string "it's a space station!\p"
	.string "We're not sure who built it nor the why\n"
	.string "nor the how.\p"
	.string "Apparently it was abandoned when the\n"
	.string "International Police first found it.\p"
	.string "We've since converted it into our main\n"
	.string "base of operations.\p"
	.string "From here, we can more easily observe\n"
	.string "the enemy's crucible of worlds.$"
	@.string "From here, we can more easily\n"
	@.string "observe distant worlds.$"

StationCity_Building1_B1_Text_WhatIsOvermind:
	.string "We're not sure. The files we've retrieved\n"
	.string "from TEAM GENESIS call it a POKéMON.\p"
	.string "But we have no data for it. And no one\n"
	.string "has ever seen it directly.\p"
	.string "What we do know is that it's\n"
	.string "a vast cosmic intelligence.\p"
	.string "And it's capable of manipulating\n"
	.string "entire worlds.\p"
	.string "It is the enemy's greatest weapon.\n"
	.string "One we must inevitably face.$"

StationCity_Building1_B1_Text_WhatAreArchons:
	.string "Conduits for OVERMIND'S power.\n"
	.string "They embody its hold on each world.$"

StationCity_Building1_B1_Text_WhatAreSynderlings:
	.string "A special kind of symbiote we've encountered\n"
	.string "with greatly enhanced abilities.\p"
	.string "This is only a theory, but I believe that\n"
	.string "somehow else has enhanced ordinary symbiotes.$"

StationCity_Building1_B1_Text_WhatAreWormholes:
	.string "Well, uh...\p"
	.string "Imagine you attach a handle to a\n"
	.string "ball and...\p"
	.string "Oh, nevermind.\p"
	.string "Just know that stepping inside one will\n"
	.string "take you to a distant place.\p"
	.string "The smaller ones seem to connect only\n"
	.string "to regions of our own world.\p"
	.string "But the largest will take you to\n"
	.string "extraterrestrial worlds!\p"
	.string "From here, we've been monitoring wormhole\n"
	.string "activity in the HOENN and ISSHO regions.\p"
	.string "Feel free to ask SELWYN for more\n"
	.string "about that.$"

StationCity_Building1_B1_EventScript_Exit::
	closemessage
	release
	end









StationCity_Building1_B1_Text_NewWormholes:
	.string "We've detected three new Ultra Wormholes\n"
	.string "around the HOENN region.\p"
	.string "They're in...$"

StationCity_Building1_B1_Text_Tier1Worlds:
	.string "ROUTE 109, PETALBURG WOODS,\n"
	.string "and DEWFORD MEADOW.$"

StationCity_Building1_B1_Text_Tier2Worlds:
	.string "ROUTE 110, ROUTE 111,\n"
	.string "and METEOR FALLS.$"

StationCity_Building1_B1_Text_Tier3Worlds:
	.string "MT. CHIMNEY, ROUTE 119,\n"
	.string "and MT. PYRE.$"

StationCity_Building1_B1_Text_Tier4Worlds:
	.string "SHOAL CAVE, ROUTE 132,\n"
	.string "and OLD VICTORY ROAD.$"




