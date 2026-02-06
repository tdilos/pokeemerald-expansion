.set LOCALID_BOY1, 4
.set LOCALID_BOY2, 7

ScarletWoods_South_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ScarletWoods_South_OnTransition
	.byte 0

ScarletWoods_South_OnTransition:
	call_if_eq VAR_SCARLET_WOODS_STATE, 1, ScarletWoods_South_EventScript_MoveBoysToHollow
	call_if_ge VAR_SCARLET_WOODS_STATE, 2, ScarletWoods_South_EventScript_MoveBoysOutOfSight
	end

ScarletWoods_South_EventScript_MoveBoysToHollow:
	setobjectxyperm LOCALID_BOY1, 52, 23
	addobject LOCALID_BOY1
	setobjectxyperm LOCALID_BOY2, 53, 23
	addobject LOCALID_BOY2
	return

ScarletWoods_South_EventScript_MoveBoysOutOfSight:
	setobjectxyperm LOCALID_BOY1, 0, 0
	addobject LOCALID_BOY1
	setobjectxyperm LOCALID_BOY2, 1, 0
	addobject LOCALID_BOY2
	return

ScarletWoods_South_EventScript_Ramie::
	trainerbattle_single TRAINER_RAMIE, ScarletWoods_South_Text_RamieIntro, ScarletWoods_South_Text_RamieDefeated
	msgbox ScarletWoods_South_Text_RamiePostBattle, MSGBOX_AUTOCLOSE
	end

ScarletWoods_South_EventScript_Bernice::
	trainerbattle_single TRAINER_BERNICE, ScarletWoods_South_Text_BerniceIntro, ScarletWoods_South_Text_BerniceDefeated
	msgbox ScarletWoods_South_Text_BernicePostBattle, MSGBOX_AUTOCLOSE
	end

ScarletWoods_South_EventScript_Gertrude::
	trainerbattle_single TRAINER_GERTRUDE, ScarletWoods_South_Text_GertrudeIntro, ScarletWoods_South_Text_GertrudeDefeated
	msgbox ScarletWoods_South_Text_GertrudePostBattle, MSGBOX_AUTOCLOSE
	end



ScarletWoods_South_EventScript_LostBoys::
	lock
	faceplayer
	goto_if_eq VAR_SCARLET_WOODS_STATE, 1, ScarletWoods_South_EventScript_RescueBoys
	msgbox ScarletWoods_South_Text_GoAway, MSGBOX_DEFAULT
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_29
	goto_if_eq VAR_RESULT, TRUE, Route96_EventScript_ZoroarkBattle
	release
	end

ScarletWoods_South_Text_GoAway:
	.string "This is our home.\n"
	.string "We live here now.\p"
	.string "Leave us alone.$"

Route96_EventScript_ZoroarkBattle::
	msgbox ScarletWoods_South_Text_GoAway2, MSGBOX_DEFAULT
	playmoncry SPECIES_ZOROARK, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 30
	seteventmon SPECIES_ZOROARK, 47
	totemboost_atk2 B_POSITION_OPPONENT_LEFT
	special BattleSetup_StartLegendaryBattle
	waitstate
	fadescreen FADE_TO_BLACK
	setvar VAR_SCARLET_WOODS_STATE, 1
	removeobject LOCALID_BOY1
	removeobject LOCALID_BOY2
	call ScarletWoods_South_EventScript_MoveBoysToHollow
	fadescreen FADE_FROM_BLACK
	release
	end

ScarletWoods_South_Text_GoAway2:
	.string "\p"
	.string "We said we don't wanna go home!\p"
	.string "\p"
	.string "Leave us alone.\p"
	.string "NOW!$"

ScarletWoods_South_EventScript_RescueBoys::
	msgbox ScarletWoods_South_Text_CouldntLeave, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setvar VAR_SCARLET_WOODS_STATE, 2
	clearflag FLAG_HIDE_LOST_BOYS
	removeobject LOCALID_BOY1
	removeobject LOCALID_BOY2
	call ScarletWoods_South_EventScript_MoveBoysOutOfSight
	fadescreen FADE_FROM_BLACK
	release
	end

ScarletWoods_South_Text_CouldntLeave:
	.string "That scary POKéMON wouldn't\n"
	.string "let us leave.\p"
	.string "But you fought it off!\n"
	.string "Your POKéMON were amazing!\p"
	.string "It was like GROW RAWR RAWR\n"
	.string "GRRRRRRRRRRRRR!\p"
	.string "But your POKéMON were like\n"
	.string "PEW PEW PEW KAPOOOW!\p"
	.string "\p"
	.string "Anyways, thanks for rescuing us!\p"
	.string "We know how to get home from here.$"
