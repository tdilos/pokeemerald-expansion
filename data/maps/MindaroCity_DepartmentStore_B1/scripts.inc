MindaroCity_DepartmentStore_B1_MapScripts::
	.byte 0

MindaroCity_DepartmentStore_B1_EventScript_Man::
	msgbox MindaroCity_DepartmentStore_B1_Text_DontBreakAnything, MSGBOX_NPC
	end

MindaroCity_DepartmentStore_B1_Text_DontBreakAnything:
	.string "Hey, what are you doing down here?\p"
	.string "You think this is a playground\n"
	.string "or something?\p"
	.string "...\p"
	.string "Ah, forget it. They don't pay me\n"
	.string "enough to keep people out.\p"
	.string "Just don't break anything, okay?$"
	@.string "And no stealing.$"





@ VAR_0x8004 is the target Rotom form
@ VAR_0x8005 is the current Rotom form
MindaroCity_DepartmentStore_B1_EventScript_TryChangeRotomForm::
	playmoncry SPECIES_ROTOM, CRY_MODE_NORMAL
	waitmoncry
	@goto_if_eq VAR_0x8005, VAR_0x8004, MindaroCity_DepartmentStore_B1_EventScript_TryChangeRotomForm2
	msgbox MindaroCity_DepartmentStore_B1_Text_RotomWantsToGoInside, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, MindaroCity_DepartmentStore_B1_EventScript_Skip
	playmoncry SPECIES_ROTOM, CRY_MODE_NORMAL
	waitmoncry
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER Common_Movement_ExclamationMark
	waitmovement 0
	waitse
	special HandleRotomFormChange
	@special SetSpecies
	@call_if_lt VAR_0x8002, 4, MindaroCity_DepartmentStore_B1_EventScript_ChangeRotomMove
	msgbox MindaroCity_DepartmentStore_B1_Text_RotomsFormChanged, MSGBOX_DEFAULT
	closemessage
MindaroCity_DepartmentStore_B1_EventScript_Skip::
	release
     	end

@MindaroCity_DepartmentStore_B1_EventScript_TryChangeRotomForm2::
@	msgbox MindaroCity_DepartmentStore_B1_Text_RotomWantsToGoInside, MSGBOX_YESNO
@	goto_if_eq VAR_RESULT, FALSE, MindaroCity_DepartmentStore_B1_EventScript_Skip
@	setvar VAR_0x8004, SPECIES_ROTOM
@	setvar VAR_0x8007, MOVE_THUNDER_SHOCK
@	playmoncry SPECIES_ROTOM, CRY_MODE_NORMAL
@	waitmoncry
@	playse SE_PIN
@	applymovement OBJ_EVENT_ID_PLAYER Common_Movement_ExclamationMark
@	waitmovement 0
@	waitse
@	special SetSpecies
@	call_if_lt VAR_0x8002, 4, MindaroCity_DepartmentStore_B1_EventScript_ChangeRotomMove
@	msgbox MindaroCity_DepartmentStore_B1_Text_RotomsFormChanged, MSGBOX_DEFAULT
@	closemessage
@	release
@	end

MindaroCity_DepartmentStore_B1_Text_RotomWantsToGoInside:
	.string "ROTOM wants to enter the crate.\n"
	.string "Will you let it?$"

MindaroCity_DepartmentStore_B1_Text_RotomsFormChanged:
	.string "ROTOM'S form changed!$"


@ VAR_0x8007 is the new move to be learned
@ VAR_0x8002 is its index
@MindaroCity_DepartmentStore_B1_EventScript_ChangeRotomMove:
@	setmonmove 0, VAR_0x8002, VAR_0x8007
@	return


MindaroCity_DepartmentStore_B1_EventScript_Fan::
	lock
	setvar VAR_0x8004, SPECIES_ROTOM_FAN
	@setvar VAR_0x8007, MOVE_AIR_SLASH
	msgbox MindaroCity_DepartmentStore_B1_Text_Fan, MSGBOX_DEFAULT
	closemessage
	special CheckForRotom
	goto_if_eq VAR_RESULT, TRUE, MindaroCity_DepartmentStore_B1_EventScript_TryChangeRotomForm
	release
	end

MindaroCity_DepartmentStore_B1_Text_Fan:
	.string "{PLAYER} peaked into the crate.\p"
	.string "It looks like there's a fan inside.$"

MindaroCity_DepartmentStore_B1_EventScript_LawnMower::
	lock
	setvar VAR_0x8004, SPECIES_ROTOM_MOW
	@setvar VAR_0x8007, MOVE_LEAF_STORM
	msgbox MindaroCity_DepartmentStore_B1_Text_LawnMower, MSGBOX_DEFAULT
	closemessage
	special CheckForRotom
	goto_if_eq VAR_RESULT, TRUE, MindaroCity_DepartmentStore_B1_EventScript_TryChangeRotomForm
	release
	end

MindaroCity_DepartmentStore_B1_Text_LawnMower:
	.string "{PLAYER} peaked into the crate.\p"
	.string "It looks like there's a lawn\n"
	.string "mower inside.$"

MindaroCity_DepartmentStore_B1_EventScript_Oven::
	lock
	setvar VAR_0x8004, SPECIES_ROTOM_HEAT
	@setvar VAR_0x8007, MOVE_OVERHEAT
	msgbox MindaroCity_DepartmentStore_B1_Text_Oven, MSGBOX_DEFAULT
	closemessage
	special CheckForRotom
	goto_if_eq VAR_RESULT, TRUE, MindaroCity_DepartmentStore_B1_EventScript_TryChangeRotomForm
	release
	end

MindaroCity_DepartmentStore_B1_Text_Oven:
	.string "{PLAYER} peaked into the crate.\p"
	.string "It looks like there's an oven inside.$"

MindaroCity_DepartmentStore_B1_EventScript_Refrigerator::
	lock
	setvar VAR_0x8004, SPECIES_ROTOM_FROST
	@setvar VAR_0x8007, MOVE_BLIZZARD
	msgbox MindaroCity_DepartmentStore_B1_Text_Refrigerator, MSGBOX_DEFAULT
	closemessage
	special CheckForRotom
	goto_if_eq VAR_RESULT, TRUE, MindaroCity_DepartmentStore_B1_EventScript_TryChangeRotomForm
	release
	end

MindaroCity_DepartmentStore_B1_Text_Refrigerator:
	.string "{PLAYER} peaked into the crate.\p"
	.string "It looks like there's a\n"
	.string "refrigerator inside.$"

MindaroCity_DepartmentStore_B1_EventScript_WashingMachine::
	lock
	setvar VAR_0x8004, SPECIES_ROTOM_WASH
	@setvar VAR_0x8007, MOVE_HYDRO_PUMP
	msgbox MindaroCity_DepartmentStore_B1_Text_WashingMachine, MSGBOX_DEFAULT
	closemessage
	special CheckForRotom
	goto_if_eq VAR_RESULT, TRUE, MindaroCity_DepartmentStore_B1_EventScript_TryChangeRotomForm
	release
	end

MindaroCity_DepartmentStore_B1_Text_WashingMachine:
	.string "{PLAYER} peaked into the crate.\p"
	.string "It looks like there's a washing\n"
	.string "machine inside.$"

MindaroCity_DepartmentStore_B1_EventScript_Boombox::
	lock
	setvar VAR_0x8004, SPECIES_ROTOM_PLAY
	@setvar VAR_0x8007, MOVE_BOOMBURST
	msgbox MindaroCity_DepartmentStore_B1_Text_Boombox, MSGBOX_DEFAULT
	closemessage
	special CheckForRotom
	goto_if_eq VAR_RESULT, TRUE, MindaroCity_DepartmentStore_B1_EventScript_TryChangeRotomForm
	release
	end

MindaroCity_DepartmentStore_B1_Text_Boombox:
	.string "{PLAYER} peaked into the crate.\p"
	.string "It looks like there's a boombox inside.$"


