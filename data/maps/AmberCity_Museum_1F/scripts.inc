AmberCity_Museum_1F_MapScripts::
	.byte 0

AmberCity_Museum_1F_EventScript_Scientist::
	msgbox AmberCity_Museum_1F_Text_Welcome, MSGBOX_NPC
	end

AmberCity_Museum_1F_Text_Welcome:
	.string "Welcome to AMBER CITY MUSEUM!\p"
	.string "Please have a look at our\n"
	.string "fossil collection!$"

AmberCity_Museum_1F_EventScript_Woman::
	msgbox AmberCity_Museum_1F_Text_AncientAnorith, MSGBOX_NPC
	end

AmberCity_Museum_1F_Text_AncientAnorith:
	.string "This CLAW FOSSIL was once an\n"
	.string "ancient POKéMON species.\p"
	.string "Scientists estimate that it lived\n"
	.string "hundreds of millions of years ago.\p" 
	.string "Humans have only been around for a\n"
	.string "percent of a percent of that time.\p"
	.string "It boggles my mind just\n"
	.string "thinking about it!$" 

AmberCity_Museum_1F_EventScript_Man::
	lock
	faceplayer
	msgbox AmberCity_Museum_1F_Text_FossilPokemon, MSGBOX_DEFAULT
	release
	end

AmberCity_Museum_1F_Text_FossilPokemon:
	.string "My favorite POKéMON come from fossils.\n"
	.string "Aren't they fascinating?$"

AmberCity_Museum_1F_EventScript_Policeman::
	msgbox AmberCity_Museum_1F_Text_OffLimits, MSGBOX_NPC
	end

AmberCity_Museum_1F_Text_OffLimits:
	.string "I'm sorry, our special exhibits are\n"
	.string "off-limits for now.$"

AmberCity_Museum_1F_EventScript_OldMan::
	msgbox AmberCity_Museum_1F_Text_Granddaughter, MSGBOX_NPC
	end

AmberCity_Museum_1F_Text_Granddaughter:
	.string "I'm the curator of this museum.\p"
	.string "The gym leader here is\n"
	.string "my granddaughter.\p"
	.string "Half of the fossils on display\n"
	.string "were personally dug up by her!$"

AmberCity_Museum_1F_EventScript_HelixFossilDisplay::
	msgbox AmberCity_Museum_1F_Text_HelixFossilDisplay, MSGBOX_SIGN
	end

AmberCity_Museum_1F_Text_HelixFossilDisplay:
	.string "HELIX FOSSIL\p"
	.string "Found near CINEROUS TOWN.$"

AmberCity_Museum_1F_EventScript_DomeFossilDisplay::
	msgbox AmberCity_Museum_1F_Text_DomeFossilDisplay, MSGBOX_SIGN
	end

AmberCity_Museum_1F_Text_DomeFossilDisplay:
	.string "DOME FOSSIL\p"
	.string "“Donation from our HOENN patrons.$"

AmberCity_Museum_1F_EventScript_RootFossilDisplay::
	msgbox AmberCity_Museum_1F_Text_RootFossilDisplay, MSGBOX_SIGN
	end

AmberCity_Museum_1F_Text_RootFossilDisplay:
	.string "ROOT FOSSIL\p"
	.string "Found near CINEROUS TOWN.$"

AmberCity_Museum_1F_EventScript_ClawFossilDisplay::
	msgbox AmberCity_Museum_1F_Text_ClawFossilDisplay, MSGBOX_SIGN
	end

AmberCity_Museum_1F_Text_ClawFossilDisplay:
	.string "CLAW FOSSIL\p"
	.string "Donation from our HOENN patrons.$"

AmberCity_Museum_1F_EventScript_SkullFossilDisplay::
	msgbox AmberCity_Museum_1F_Text_SkullFossilDisplay, MSGBOX_SIGN
	end

AmberCity_Museum_1F_Text_SkullFossilDisplay:
	.string "SKULL FOSSIL\p"
	.string "Donation from our HOENN patrons.$"


AmberCity_Museum_1F_EventScript_ShieldFossilDisplay::
	msgbox AmberCity_Museum_1F_Text_ShieldFossilDisplay, MSGBOX_SIGN
	end

AmberCity_Museum_1F_Text_ShieldFossilDisplay:
	.string "SHIELD FOSSIL\p"
	.string "Found near OFFWITE TOWN.$"


AmberCity_Museum_1F_EventScript_CoverFossilDisplay::
	msgbox AmberCity_Museum_1F_Text_CoverFossilDisplay, MSGBOX_SIGN
	end

AmberCity_Museum_1F_Text_CoverFossilDisplay:
	.string "COVER FOSSIL\p"
	.string "Donation from our HOENN patrons.$"


AmberCity_Museum_1F_EventScript_PlumeFossilDisplay::
	msgbox AmberCity_Museum_1F_Text_PlumeFossilDisplay, MSGBOX_SIGN
	end

AmberCity_Museum_1F_Text_PlumeFossilDisplay:
	.string "PLUME FOSSIL\p"
	.string "Donation from our HOENN patrons.$"

AmberCity_Museum_1F_EventScript_JawFossilDisplay::
	msgbox AmberCity_Museum_1F_Text_JawFossilDisplay, MSGBOX_SIGN
	end

AmberCity_Museum_1F_Text_JawFossilDisplay:
	.string "JAW FOSSIL\p"
	.string "Found near OFFWITE TOWN.$"


AmberCity_Museum_1F_EventScript_SailFossilDisplay::
	msgbox AmberCity_Museum_1F_Text_SailFossilDisplay, MSGBOX_SIGN
	end

AmberCity_Museum_1F_Text_SailFossilDisplay:
	.string "SAIL FOSSIL\p"
	.string "Donation from our HOENN patrons.$"


AmberCity_Museum_1F_EventScript_OldAmberDisplay::
	msgbox AmberCity_Museum_1F_Text_OldAmberDisplay, MSGBOX_SIGN
	end

AmberCity_Museum_1F_Text_OldAmberDisplay:
	.string "OLD AMBER\p"
	.string "Donation from our patrons\n"
	.string "in MAROON CITY.$"
