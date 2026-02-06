UmberTown_FemaleMCHouse_MapScripts::
	.byte 0

UmberTown_FemaleMCHouse_EventScript_OPCDad::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, UmberTown_FemaleMCHouse_EventScript_Daughter
	goto_if_eq VAR_RESULT, FEMALE, UmberTown_FemaleMCHouse_EventScript_Son
	end

UmberTown_FemaleMCHouse_EventScript_Son::
	msgbox UmberTown_FemaleMCHouse_Text_Son, MSGBOX_NPC
	end

UmberTown_FemaleMCHouse_EventScript_Daughter::
	msgbox UmberTown_FemaleMCHouse_Text_Daughter, MSGBOX_NPC
	end

UmberTown_FemaleMCHouse_Text_Son:
	.string "We have a son about the same\n"
	.string "age as you.\p"
	.string "I'm sure the two of you would make\n"
	.string "good friends.$"

UmberTown_FemaleMCHouse_Text_Daughter:
	.string "We have a daughter about the same\n"
	.string "age as you.\p"
	.string "I'm sure the two of you would make\n"
	.string "good friends.$"

UmberTown_FemaleMCHouse_EventScript_OPCMom::
	msgbox UmberTown_FemaleMCHouse_Text_MovingFarAway, MSGBOX_NPC
	end

UmberTown_FemaleMCHouse_Text_MovingFarAway:
	.string "Moving somewhere far away is\n"
	.string "never easy.\p"
	.string "But I think of it as a chance to\n"
	.string "make a fresh start.$"
