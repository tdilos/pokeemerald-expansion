.equ LOCALID_ROOT_FOSSIL,  1
.equ LOCALID_HELIX_FOSSIL, 2
.equ LOCALID_MANUEL,       3

ShuckleSpring_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ShuckleSpring_B2F_OnTransition
	.byte 0

ShuckleSpring_B2F_OnTransition::
	call_if_unset FLAG_GOT_SHUCKLE_SPRING_FOSSIL, ShuckleSpring_B2F_EventScript_ShowFossils
	end

ShuckleSpring_B2F_EventScript_ShowFossils::
	clearflag FLAG_HIDE_MIRAGE_TOWER_ROOT_FOSSIL
	clearflag FLAG_HIDE_MIRAGE_TOWER_CLAW_FOSSIL
	return

ShuckleSpring_B2F_EventScript_ManuelTrigger::
	lockall
	goto_if_unset FLAG_GOT_SHUCKLE_SPRING_FOSSIL, ShuckleSpring_B2F_EventScript_ManuelEvent
	releaseall
	end
	

ShuckleSpring_B2F_EventScript_ManuelEvent::
	goto_if_defeated TRAINER_MANUEL, ShuckleSpring_B2F_EventScript_ManuelGoPickFossil
	@playse SE_PIN
	playbgm MUS_ENCOUNTER_SUSPICIOUS, FALSE
	applymovement LOCALID_MANUEL, Common_Movement_ExclamationMark
	waitmovement 0
	delay 60
	call ShuckleSpring_B2F_EventScript_BattleManuel
	releaseall
	end 

ShuckleSpring_B2F_EventScript_ManuelGoPickFossil::
	lockall
	msgbox ShuckleSpring_B2F_Text_HurryUp, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	releaseall
	end

ShuckleSpring_B2F_EventScript_Manuel::
	lock
	faceplayer
	msgbox ShuckleSpring_B2F_Text_HurryUp, MSGBOX_NPC
	closemessage
	@goto_if_set FLAG_GOT_FOSSIL_FROM_MT_MOON, MtMoon_B2F_EventScript_MiguelFossilPicked
	@goto_if_defeated TRAINER_MANUEL, ShuckleSpring_B2F_EventScript_ManuelGoPickFossil
	@call MtMoon_B2F_EventScript_BattleMiguel
	release
	end

ShuckleSpring_B2F_EventScript_BattleManuel::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	message ShuckleSpring_B2F_Text_ManuelIntro
	waitmessage
	waitbuttonpress
	setvar VAR_LAST_TALKED, LOCALID_MANUEL
	trainerbattle_no_intro TRAINER_MANUEL, ShuckleSpring_B2F_Text_ManuelDefeat
	@applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceDown
	@waitmovement 0
	delay 30
	msgbox ShuckleSpring_B2F_Text_WellEachTakeAFossil
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	return

ShuckleSpring_B2F_Text_ManuelIntro:
	.string "T-these are my fossils.\n"
	.string "They were made for me!$"

ShuckleSpring_B2F_Text_ManuelDefeat:
	.string "Okay fine, I'll let you have one.$"

ShuckleSpring_B2F_Text_WellEachTakeAFossil:
	.string "We'll each take a fossil.\n"
	.string "How does that sound?\p"
	.string "And since you won, I'll let you\n"
	.string "choose first.$"

ShuckleSpring_B2F_Text_HurryUp:
	.string "Hurry up and choose!$"

ShuckleSpring_B2F_Text_YouWantRootFossil:
	.string "You want the ROOT FOSSIL?$"

ShuckleSpring_B2F_Text_YouWantHelixFossil:
	.string "You want the HELIX FOSSIL?$"

ShuckleSpring_B2F_Text_ThenThisFossilIsMine:
	.string "Then this fossil is mine.$"

ShuckleSpring_B2F_EventScript_RootFossil::
	lock
	msgbox ShuckleSpring_B2F_Text_YouWantRootFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ShuckleSpring_B2F_EventScript_DontTakeFossil
	removeobject LOCALID_ROOT_FOSSIL
	giveitem ITEM_ROOT_FOSSIL
	@giveitem_msg MtMoon_B2F_Text_ObtainedDomeFossil, ITEM_ROOT_FOSSIL, 1, MUS_OBTAIN_KEY_ITEM
	closemessage
	@special QuestLog_CutRecording
	delay 60
	applymovement LOCALID_MANUEL, ShuckleSpring_B2F_Movement_ManuelToHelixFossil
	waitmovement 0
	@copyobjectxytoperm LOCALID_MIGUEL
	@textcolor NPC_TEXT_COLOR_MALE
	@playfanfare MUS_OBTAIN_KEY_ITEM
	msgbox ShuckleSpring_B2F_Text_ThenThisFossilIsMine, MSGBOX_DEFAULT
	closemessage
	@waitfanfare
	removeobject LOCALID_HELIX_FOSSIL
	delay 30
	fadescreen FADE_TO_BLACK
	@setflag FLAG_GOT_SHUCKLE_SPRING_FOSSIL
	removeobject LOCALID_MANUEL 
	delay 30
	fadescreen FADE_FROM_BLACK
	release
	end

ShuckleSpring_B2F_Movement_ManuelToHelixFossil::
	delay_16
	walk_left
	delay_16
	step_end

ShuckleSpring_B2F_EventScript_HelixFossil::
	lock
	msgbox ShuckleSpring_B2F_Text_YouWantHelixFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ShuckleSpring_B2F_EventScript_DontTakeFossil
	removeobject LOCALID_HELIX_FOSSIL
	giveitem ITEM_HELIX_FOSSIL
	@giveitem_msg MtMoon_B2F_Text_ObtainedHelixFossil, ITEM_HELIX_FOSSIL, 1, MUS_OBTAIN_KEY_ITEM
	closemessage
	@special QuestLog_CutRecording
	delay 60
	applymovement LOCALID_MANUEL, ShuckleSpring_B2F_Movement_ManuelToRootFossil
	waitmovement 0
	@copyobjectxytoperm LOCALID_MANUEL
	@textcolor NPC_TEXT_COLOR_MALE
	@playfanfare MUS_OBTAIN_KEY_ITEM
	msgbox ShuckleSpring_B2F_Text_ThenThisFossilIsMine, MSGBOX_DEFAULT
	closemessage
	@waitfanfare
	removeobject LOCALID_ROOT_FOSSIL
	delay 30
	fadescreen FADE_TO_BLACK
	@setflag FLAG_GOT_SHUCKLE_SPRING_FOSSIL
	removeobject LOCALID_MANUEL 
	delay 30
	fadescreen FADE_FROM_BLACK
	release
	end

ShuckleSpring_B2F_EventScript_DontTakeFossil::
	release
	end

ShuckleSpring_B2F_Movement_ManuelToRootFossil::
	delay_16
	walk_down
	walk_left
	delay_16
	step_end
