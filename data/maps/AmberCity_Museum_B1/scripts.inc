.set LOCALID_SCIENTIST, 1

AmberCity_Museum_B1_MapScripts::
	.byte 0

AmberCity_Museum_B1_EventScript_XenoresinDisplay::
	msgbox AmberCity_Museum_B1_Text_XenoresinDisplay, MSGBOX_SIGN
	end

AmberCity_Museum_B1_Text_XenoresinDisplay:
	.string "XENORESIN\p"
	.string "Found beneath this very museum!$"

AmberCity_Museum_B1_EventScript_Scientist::
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_8
	goto_if_eq VAR_RESULT, TRUE, AmberCity_Museum_B1_EventScript_TeachPaleoWave
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_8
	goto_if_eq VAR_RESULT, TRUE, AmberCity_Museum_B1_EventScript_CheckForFossilMon
	msgbox AmberCity_Museum_B1_Text_AncientPokemon, MSGBOX_DEFAULT
	startquest QUEST_8
	release
	end	

AmberCity_Museum_B1_EventScript_CheckForFossilMon::
	msgbox AmberCity_Museum_B1_Text_AncientPokemon, MSGBOX_DEFAULT
	special CheckForSuperAncientPokemon
	goto_if_eq VAR_RESULT, TRUE, AmberCity_Museum_B1_EventScript_UnlockTutor
	release
	end

AmberCity_Museum_B1_EventScript_UnlockTutor::
	applymovement LOCALID_SCIENTIST, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	applymovement LOCALID_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox AmberCity_Museum_B1_Text_ThatsALivingFossil, MSGBOX_DEFAULT
	completequest QUEST_8
	release
	end


AmberCity_Museum_B1_EventScript_TeachPaleoWave::
	msgbox AmberCity_Museum_B1_Text_TeachPaleoWave, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, AmberCity_Museum_B1_EventScript_ChooseMonForTutor
	goto_if_eq VAR_RESULT, NO, AmberCity_Museum_B1_EventScript_ExitTutor
	release
	end

AmberCity_Museum_B1_EventScript_ChooseMonForTutor::
	setvar VAR_0x8005, MOVE_PALEO_WAVE
	msgbox AmberCity_Museum_B1_Text_TeachWhichPokemon, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, FALSE, AmberCity_Museum_B1_EventScript_ExitTutor
	release
	end

AmberCity_Museum_B1_EventScript_ExitTutor::
	release
	end




AmberCity_Museum_B1_Text_AncientPokemon:
	.string "In the distant past, not only\n"
	.string "were POKéMON different,\l"
	.string "their moves were too!\p"
	.string "Thanks to my research, we've been able\n"
	.string "to reconstruct one such move.\p"
	.string "Unfortunately, only super-ancient\n"
	.string "POKéMON are capable of learning it.\p"
	.string "If only there were super-ancient\n"
	.string "POKéMON still around today...$"

AmberCity_Museum_B1_Text_ThatsALivingFossil:
	.string "I don't believe it!\n"
	.string "That's a living fossil!\p"
	.string "How extraordinary!\n"
	.string "Now I can put our theories to the test.\p"
	.string "You simply must let me teach your\n"
	.string "POKéMON the move PALEO WAVE.\p"
	.string "I'll tutor as many as you want.\n"
	.string "Free of charge!$"

AmberCity_Museum_B1_Text_TeachPaleoWave:
	.string "Would you like me to teach your POKéMON\n"
	.string "the move PALEO WAVE?$"

AmberCity_Museum_B1_Text_TeachWhichPokemon:
	.string "Which POKéMON should I teach?$"


