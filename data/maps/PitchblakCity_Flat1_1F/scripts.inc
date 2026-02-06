.set LOCALID_MOVE_RELEARNER, 1

PitchblakCity_Flat1_1F_MapScripts::
	.byte 0

PitchblakCity_Flat1_1F_EventScript_FatMan::
	msgbox PitchblakCity_Flat1_1F_Text_SickOfThisProgram, MSGBOX_NPC
	end

PitchblakCity_Flat1_1F_Text_SickOfThisProgram:
	.string "I'm sick of this program.\n"
	.string "I wish they would air something else.$"

PitchblakCity_Flat1_1F_EventScript_Boy::
	lock
	faceplayer
	msgbox PitchblakCity_Flat1_1F_Text_AgainstGeneTherapy, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Flat1_1F_Text_AgainstGeneTherapy:
	.string "Did you that know some people are\n"
	.string "against gene therapy?\p"
	.string "I really don't get that.\p"
	.string "What's wrong with trying to\n"
	.string "make everyone better?$"








PitchblakCity_Flat1_1F_EventScript_MoveRelearner::
	lockall
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_1, PitchblakCity_Flat1_1F_EventScript_AskTeachMove
	msgbox PitchblakCity_Flat1_1F_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto PitchblakCity_Flat1_1F_EventScript_AskTeachMove
	end

PitchblakCity_Flat1_1F_EventScript_AskTeachMove::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, FALSE, PitchblakCity_Flat1_1F_EventScript_ComeBackWithHeartScale
	msgbox PitchblakCity_Flat1_1F_Text_ThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, PitchblakCity_Flat1_1F_EventScript_ComeBackWithHeartScale
	goto PitchblakCity_Flat1_1F_EventScript_ChooseMon
	end

PitchblakCity_Flat1_1F_EventScript_ChooseMon::
	msgbox PitchblakCity_Flat1_1F_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PitchblakCity_Flat1_1F_EventScript_ComeBackWithHeartScale
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, PitchblakCity_Flat1_1F_EventScript_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, PitchblakCity_Flat1_1F_EventScript_NoMoveToTeachMon
	goto PitchblakCity_Flat1_1F_EventScript_ChooseMove
	end

PitchblakCity_Flat1_1F_EventScript_ChooseMove::
	msgbox PitchblakCity_Flat1_1F_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, PitchblakCity_Flat1_1F_EventScript_ChooseMon
	msgbox PitchblakCity_Flat1_1F_Text_HandedOverHeartScale, MSGBOX_DEFAULT
	removeitem ITEM_HEART_SCALE
	goto PitchblakCity_Flat1_1F_EventScript_ComeBackWithHeartScale
	end

PitchblakCity_Flat1_1F_EventScript_NoMoveToTeachMon::
	msgbox PitchblakCity_Flat1_1F_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto PitchblakCity_Flat1_1F_EventScript_ChooseMon
	end

PitchblakCity_Flat1_1F_EventScript_CantTeachEgg::
	msgbox PitchblakCity_Flat1_1F_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto PitchblakCity_Flat1_1F_EventScript_ChooseMon
	end

PitchblakCity_Flat1_1F_EventScript_ComeBackWithHeartScale::
	msgbox PitchblakCity_Flat1_1F_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
	releaseall
	end

PitchblakCity_Flat1_1F_Text_ImTheMoveTutor:
	.string "I'm the MOVE REMINDER.\p"
	.string "I know all the moves that POKéMON\n"
	.string "learn--every one of them--and I can\l"
	.string "teach POKéMON those moves.\p"
	.string "I can teach a move to a POKéMON\n"
	.string "of yours if you'd like.\p"
	.string "I'll do it for a HEART SCALE.\n"
	.string "I'm collecting those now.$"

PitchblakCity_Flat1_1F_Text_ThatsAHeartScaleWantMeToTeachMove:
	.string "Oh! That's it! That's an honest to\n"
	.string "goodness HEART SCALE!\p"
	.string "Let me guess, you want me to teach\n"
	.string "a move?$"

PitchblakCity_Flat1_1F_Text_TutorWhichMon:
	.string "Which POKéMON needs tutoring?$"

PitchblakCity_Flat1_1F_Text_TeachWhichMove:
	.string "Which move should I teach?$"

PitchblakCity_Flat1_1F_Text_DontHaveMoveToTeachPokemon:
	.string "Sorry…\p"
	.string "It doesn't appear as if I have any move\n"
	.string "I can teach that POKéMON.$"

PitchblakCity_Flat1_1F_Text_HandedOverHeartScale:
	.string "{PLAYER} handed over one HEART SCALE\n"
	.string "in exchange.$"

PitchblakCity_Flat1_1F_Text_ComeBackWithHeartScale:
	.string "If your POKéMON need to learn a move,\n"
	.string "come back with a HEART SCALE.$"

PitchblakCity_Flat1_1F_Text_CantTeachEgg:
	.string "Hunh? There isn't a single move that\n"
	.string "I can teach an EGG.$"


