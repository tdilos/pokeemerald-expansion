.set LOCALID_RAYNER, 1

Route65_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route65_OnTransition
	.byte 0

Route65_OnTransition:
	@call Route65_EventScript_RevealRayner
	@call_if_eq VAR_RAYNER_STATE, 2, Route65_EventScript_RevealRayner
	@call_if_ge VAR_RAYNER_STATE, 3, Route65_EventScript_HideRayner
	end

Route65_EventScript_RevealRayner:
	clearflag FLAG_HIDE_ROUTE65_RAYNER
	addobject LOCALID_RAYNER
	return

Route65_EventScript_HideRayner:
	removeobject LOCALID_RAYNER
	setflag FLAG_HIDE_ROUTE65_RAYNER
	return




Route65_EventScript_DeoxysNMeteor::
	lock
	setvar VAR_0x8004, SPECIES_DEOXYS
	msgbox Route65_Text_StrangeRock, MSGBOX_DEFAULT
	closemessage
	special CheckForDeoxys
	goto_if_eq VAR_RESULT, TRUE, Route65_EventScript_TryChangeDeoxysForm
	release
	end

Route65_EventScript_DeoxysAMeteor::
	lock
	setvar VAR_0x8004, SPECIES_DEOXYS_ATTACK
	msgbox Route65_Text_StrangeRock, MSGBOX_DEFAULT
	closemessage
	special CheckForDeoxys
	goto_if_eq VAR_RESULT, TRUE, Route65_EventScript_TryChangeDeoxysForm
	release
	end

Route65_EventScript_DeoxysDMeteor::
	lock
	setvar VAR_0x8004, SPECIES_DEOXYS_DEFENSE
	msgbox Route65_Text_StrangeRock, MSGBOX_DEFAULT
	closemessage
	special CheckForDeoxys
	goto_if_eq VAR_RESULT, TRUE, Route65_EventScript_TryChangeDeoxysForm
	release
	end

Route65_EventScript_DeoxysSMeteor::
	lock
	setvar VAR_0x8004, SPECIES_DEOXYS_SPEED
	msgbox Route65_Text_StrangeRock, MSGBOX_DEFAULT
	closemessage
	special CheckForDeoxys
	goto_if_eq VAR_RESULT, TRUE, Route65_EventScript_TryChangeDeoxysForm
	release
	end

Route65_Text_StrangeRock:
	.string "It's a strange rock glowing with\n"
	.string "otherworldly energy.$"

Route65_EventScript_TryChangeDeoxysForm::
	playmoncry SPECIES_DEOXYS, CRY_MODE_NORMAL
	waitmoncry
	msgbox Route65_Text_DeoxysWantsToTouchRock, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route65_EventScript_Skip
	playmoncry SPECIES_DEOXYS, CRY_MODE_NORMAL
	waitmoncry
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER Common_Movement_ExclamationMark
	waitmovement 0
	waitse
	special SetSpecies
	msgbox Route65_Text_DeoxysFormChanged, MSGBOX_DEFAULT
	closemessage
Route65_EventScript_Skip::
	release
     	end

Route65_Text_DeoxysWantsToTouchRock:
	.string "DEOXYS wants to touch the rock.\n"
	.string "Will you let it?$"

Route65_Text_DeoxysFormChanged:
	.string "DEOXYS'S form changed!$"







Route65_EventScript_Hiker::
	lock
	faceplayer
	msgbox Route65_Text_MeteorFell, MSGBOX_DEFAULT
	release
	end

Route65_Text_MeteorFell:
	.string "A meteor fell here a long time ago\n"
	.string "and left these funny pink rocks.\p"
	.string "I don't suppose you have any idea\n"
	@.string "what they could be, do you?$"
	.string "why they glow like that, do you?$"








Route65_EventScript_RaynerEncounter1::
	lockall
	applymovement LOCALID_RAYNER, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	waitse
	delay 48
	applymovement LOCALID_RAYNER, Route65_Movement_WalkToPlayer1
	waitmovement 0
	delay 30
	msgbox Route65_Text_RaynerEncounter, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_RAYNER, Common_Movement_FaceUp
	waitmovement 0
	delay 60
	msgbox Route65_Text_RaynerEncounter2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RAYNER, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_WalkLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	@waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_WalkLeft
	waitmovement 0
	delay 20
	applymovement LOCALID_RAYNER, Common_Movement_FaceRight
	waitmovement 0
	delay 60
	msgbox Route65_Text_RaynerEncounter3, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RAYNER, Route65_Movement_RaynerExit
	waitmovement 0
	call Route65_EventScript_HideRayner
	setvar VAR_RAYNER_STATE, 3
	releaseall
	end

Route65_EventScript_RaynerEncounter2::
	lockall
	applymovement LOCALID_RAYNER, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	waitse
	delay 48
	applymovement LOCALID_RAYNER, Route65_Movement_WalkToPlayer2
	waitmovement 0
	delay 30
	msgbox Route65_Text_RaynerEncounter, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_RAYNER, Common_Movement_FaceUp
	waitmovement 0
	delay 60
	msgbox Route65_Text_RaynerEncounter2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RAYNER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_WalkLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	@waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_WalkLeft
	waitmovement 0
	delay 20
	applymovement LOCALID_RAYNER, Common_Movement_FaceRight
	waitmovement 0
	delay 60
	msgbox Route65_Text_RaynerEncounter3, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RAYNER, Route65_Movement_RaynerExit
	waitmovement 0
	call Route65_EventScript_HideRayner
	setvar VAR_RAYNER_STATE, 3
	releaseall
	end

Route65_Movement_WalkToPlayer1:
	walk_left
	walk_left
	walk_left
	step_end

Route65_Movement_WalkToPlayer2:
	walk_left
	walk_left
	walk_down
	walk_left
	step_end

Route65_Movement_RaynerExit:
	@walk_left
	@walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route65_Text_RaynerEncounter:
	.string "??????: Oh, you're {PLAYER}.\p"
	.string "You probably don't recognize me,\n"
	.string "but I remember you.\p"
	.string "I was there when you helped\n"
	.string "the doctor in KENDOMA CORP.\p"
	.string "You also helped me.\p"
	.string "I wouldn't be here right now if not for\n"
	.string "your actions against TEAM GENESIS.\p"
	.string "\p"
	.string "This probably all seems really strange\n"
	.string "and sudden to you.\p"
	.string "But I'd like you to look after\n"
	.string "a special POKéMON for me.\p"
	.string "The doctor left it here with me to give\n"
	.string "to a trustworthy trainer one day.\p"
	.string "No, I'm no POKéMON trainer.\n"
	.string "That sort of thing doesn't interest me.\p"
	.string "But somehow it feels like fate that\n"
	.string "we crossed paths again here.\p"
	.string "I have no one else to leave it with.\n"
	.string "And I can't stay here much longer.\p"
	.string "So I'm going to entrust it to you.\p"
	.string "And trust that you'll treat it better\n"
	.string "than its former masters.$"

Route65_Text_RaynerEncounter2:
	.string "There's a cabin not far from here.\n"
	.string "You'll find a POKé BALL inside.$"
	@.string "\p"
	@.string "Well, best of luck {PLAYER}.\p"

Route65_Text_RaynerEncounter3:
	.string "I must be off now.\n"
	.string "Farewell, {PLAYER}.\p"
	.string "Who knows, maybe we'll meet\n"
	.string "again some day.$" 
	@.string "The doctor said you would come.\p"



Route65_Text_DeoxysLetter:
	@.string "To a new tomorrow and a brighter future\n"
	@.string "somewhere over the horizon.\p"
	@.string "--DR BETTERMAN$"
	.string "Until we meet again some day\n"
	.string "somewhere beyond the horizon.\p"
	.string "--DR BETTERMAN$"



