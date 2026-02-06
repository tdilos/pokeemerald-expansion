Route84_House_MapScripts::
	.byte 0

Route84_House_EventScript_Farmer::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_ROTOTILL, Route84_House_EventScript_ExplainRototill
	msgbox Route84_House_Text_DoYouLikeFarming, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route84_House_EventScript_GiveRototillTM
	msgbox Route84_House_Text_NotCutOut, MSGBOX_DEFAULT
	release
	end

Route84_House_EventScript_GiveRototillTM::
	msgbox Route84_House_Text_ILikeYou, MSGBOX_DEFAULT
	giveitem ITEM_TM56
	setflag FLAG_RECEIVED_TM_ROTOTILL
	waitfanfare
	goto Route84_House_EventScript_ExplainRototill
	end

Route84_House_EventScript_ExplainRototill::
	msgbox Route84_House_Text_ExplainRototill, MSGBOX_DEFAULT
	release
	end

Route84_House_EventScript_Pokemon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BELLSPROUT, CRY_MODE_NORMAL
	msgbox Route84_House_Text_Pokemon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route84_House_Text_DoYouLikeFarming:
	.string "Farmwork ain't easy, I tell ya.\p"
	.string "What about you, young'un.\p"
	.string "You think you have what it takes\n"
	.string "to be a farmer?$"

Route84_House_Text_NotCutOut:
	.string "Like I said, not everyone's cut out\n"
	.string "for it.$"

Route84_House_Text_ILikeYou:
	.string "I like your spirit, kid. Why don't\n"
	.string "ya take this TM?$"

Route84_House_Text_ExplainRototill:
	.string "That TM contains ROTOTILL.\p"
	.string "It's a move that razes the ground\n"
	.string "around ya in an instant.\p"
	.string "Teach it to a GRASS POKéMON!$"

Route84_House_Text_Pokemon:
	.string "BELLSPROUT: Puruppuu!$"


