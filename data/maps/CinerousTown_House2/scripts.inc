CinerousTown_House2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinerousTown_House2_OnTransition
	.byte 0

CinerousTown_House2_OnTransition:
	setflag FLAG_HIDE_HEADBUTT_TUTOR
	call_if_set FLAG_RESCUED_HEADBUTT_TUTOR, CinerousTown_House2_EventScript_RevealTutor
	end

CinerousTown_House2_EventScript_RevealTutor::
	clearflag FLAG_HIDE_HEADBUTT_TUTOR
	return





CinerousTown_House2_EventScript_HeadbuttTutor::
	lock
	faceplayer
	msgbox CinerousTown_House2_Text_HeadbuttTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinerousTown_House2_EventScript_HeadbuttDeclined
	msgbox CinerousTown_House2_Text_HeadbuttWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_HEADBUTT
	call CinerousTown_House2_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, CinerousTown_House2_EventScript_HeadbuttDeclined
	msgbox CinerousTown_House2_Text_UseHeadbutt, MSGBOX_DEFAULT
	release
	end

CinerousTown_House2_EventScript_HeadbuttDeclined::
	msgbox CinerousTown_House2_Text_ComeBack, MSGBOX_DEFAULT
	release
	end

CinerousTown_House2_EventScript_OpenPartyMenu::
	special ChooseMonForMoveTutor
	waitstate
	lock
	faceplayer
	return




CinerousTown_House2_Text_HeadbuttTeach:
	.string "Hey, you're the trainer that saved me.\p"
	.string "Let me guess, you want me to teach\n"
	.string "HEADBUTT to your POKéMON, right?$" 

CinerousTown_House2_Text_ComeBack:
	.string "No worries, come back anytime!$" 

CinerousTown_House2_Text_HeadbuttWhichMon:
	.string "Which POKéMON needs tutoring?$"

CinerousTown_House2_Text_UseHeadbutt:
	.string "Use HEADBUTT in front of tall trees, and\n"
	.string "sometimes a POKéMON will fall out.$"



