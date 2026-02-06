.set LOCALID_OPC, 28
.set LOCALID_RAYNER, 29

.set LOCALID_CHELSEA, 19
.set LOCALID_AMANDA, 18
.set LOCALID_AGNIS, 23
.set LOCALID_JOEL, 22
.set LOCALID_PIERRE, 31
.set LOCALID_CECILIA, 32
.set LOCALID_CASSEY, 27
.set LOCALID_WESLEY, 26
.set LOCALID_BEATRICE, 20
.set LOCALID_JEROMIE, 21

MindaroGardens_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MindaroGardens_OnTransition
	.byte 0

MindaroGardens_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	@call_if_unset FLAG_RECEIVED_HM02, MindaroGardens_EventScript_ResetMaze
	call_if_unset FLAG_REACHED_MINDARO_MANSION, MindaroGardens_EventScript_ResetMaze
	call_if_ge VAR_MINDARO_CITY_STATE, 2, MindaroGardens_EventScript_HideRayner
	end

MindaroGardens_EventScript_ResetMaze:
	setvar VAR_MINDARO_CITY_STATE, 0
	setvar VAR_MINDARO_GARDENS_STATE, 0
	return

MindaroGardens_EventScript_HideRayner:
	setflag FLAG_HIDE_RAYNER
	return

MindaroGardens_EventScript_SecretPassage::
	playse SE_M_SAND_ATTACK
	end

MindaroGardens_EventScript_Gordon::
	trainerbattle_single TRAINER_GORDON, MindaroGardens_Text_GordonIntro, MindaroGardens_Text_GordonDefeated
	msgbox MindaroGardens_Text_GordonPostBattle, MSGBOX_AUTOCLOSE
	end

MindaroGardens_EventScript_Holmes::
	trainerbattle_single TRAINER_HOLMES, MindaroGardens_Text_HolmesIntro, MindaroGardens_Text_HolmesDefeated
	msgbox MindaroGardens_Text_HolmesPostBattle, MSGBOX_AUTOCLOSE
	end

MindaroGardens_EventScript_Montgomery::
	trainerbattle_single TRAINER_MONTGOMERY, MindaroGardens_Text_MontgomeryIntro, MindaroGardens_Text_MontgomeryDefeated
	msgbox MindaroGardens_Text_MontgomeryPostBattle, MSGBOX_AUTOCLOSE
	end

MindaroGardens_Text_HolmesIntro:
	.string "Hey you! Stop!$"

MindaroGardens_Text_HolmesDefeated:
	.string "Nevermind, just some kid.$"

MindaroGardens_Text_HolmesPostBattle:
	.string "The gardens here are a popular\n"
	.string "attraction\p"
	.string "Unfortunately they also attract\n"
	.string "the wrong sorts of people.$"

MindaroGardens_Text_GordonIntro:
	.string "Aha! I caught you red-handed!$"

MindaroGardens_Text_GordonDefeated:
	.string "I've been bamboozled!$"

MindaroGardens_Text_GordonPostBattle:
	.string "Hmph. Thieves and delinquents.\p"
	.string "Why do they have to ruin\n"
	.string "a good time for everyone?$"

MindaroGardens_Text_MontgomeryIntro:
	.string "Yawn. These formal gatherings bore me.\n"
	.string "How about a battle instead?$"

MindaroGardens_Text_MontgomeryDefeated:
	.string "Most enlivening!$"

MindaroGardens_Text_MontgomeryPostBattle:
	.string "I haven't had a battle like that in ages.\p"
	.string "Thank you for giving a tired old man\n"
	.string "a bit of fun.$"









MindaroGardens_EventScript_OPCBattleSetup::
	switch VAR_STARTER_MON
	case 0, MindaroGardens_EventScript_SetOPCChespin
	case 1, MindaroGardens_EventScript_SetOPCTepig
	case 2, MindaroGardens_EventScript_SetOPCPopplio
	return

MindaroGardens_EventScript_SetOPCChespin::
	checkplayergender
	call_if_eq VAR_RESULT, FEMALE, MindaroGardens_EventScript_VertChespin
	call_if_eq VAR_RESULT, MALE, MindaroGardens_EventScript_VioletChespin
	return

MindaroGardens_EventScript_SetOPCTepig::
	checkplayergender
	call_if_eq VAR_RESULT, FEMALE, MindaroGardens_EventScript_VertTepig
	call_if_eq VAR_RESULT, MALE, MindaroGardens_EventScript_VioletTepig
	return

MindaroGardens_EventScript_SetOPCPopplio::
	checkplayergender
	call_if_eq VAR_RESULT, FEMALE, MindaroGardens_EventScript_VertPopplio
	call_if_eq VAR_RESULT, MALE, MindaroGardens_EventScript_VioletPopplio
	return

MindaroGardens_EventScript_VioletChespin::
	multi_do_fixed MULTI_BATTLE_2_VS_2, TRAINER_VIOLET_MINDARO_GARDENS_CHESPIN, TRAINER_BACK_PIC_MAY
	return

MindaroGardens_EventScript_VioletTepig::
	multi_do_fixed MULTI_BATTLE_2_VS_2, TRAINER_VIOLET_MINDARO_GARDENS_TEPIG, TRAINER_BACK_PIC_MAY
	return

MindaroGardens_EventScript_VioletPopplio::
	multi_do_fixed MULTI_BATTLE_2_VS_2, TRAINER_VIOLET_MINDARO_GARDENS_POPPLIO, TRAINER_BACK_PIC_MAY
	return

MindaroGardens_EventScript_VertChespin::
	multi_do_fixed MULTI_BATTLE_2_VS_2, TRAINER_VERN_MINDARO_GARDENS_CHESPIN, TRAINER_BACK_PIC_BRENDAN
	return

MindaroGardens_EventScript_VertTepig::
	multi_do_fixed MULTI_BATTLE_2_VS_2, TRAINER_VERN_MINDARO_GARDENS_TEPIG, TRAINER_BACK_PIC_BRENDAN
	return

MindaroGardens_EventScript_VertPopplio::
	multi_do_fixed MULTI_BATTLE_2_VS_2, TRAINER_VERN_MINDARO_GARDENS_POPPLIO, TRAINER_BACK_PIC_BRENDAN
	return





MindaroGardens_EventScript_VsChelseaAmanda::
	lock
	setvar VAR_MINDARO_GARDENS_STATE, 1
	playbgm MUS_ENCOUNTER_FEMALE, FALSE
	applymovement LOCALID_CHELSEA, Common_Movement_ExclamationMark
	waitmovement 0
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox MindaroGardens_Text_ChelseaIntro, MSGBOX_DEFAULT
	playbgm MUS_ENCOUNTER_FEMALE, FALSE
	applymovement LOCALID_AMANDA, Common_Movement_ExclamationMark
	waitmovement 0
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox MindaroGardens_Text_AmandaIntro, MSGBOX_DEFAULT
	special SavePlayerParty
	trainerbattle TRAINER_BATTLE_SET_TRAINER_A, TRAINER_CHELSEA, 0, NULL, MindaroGardens_Text_ChelseaDefeated
	trainerbattle TRAINER_BATTLE_SET_TRAINER_B, TRAINER_AMANDA, 0, NULL, MindaroGardens_Text_AmandaDefeated
	call MindaroGardens_EventScript_OPCBattleSetup
	special LoadPlayerParty
	special HealPlayerParty
	release
	end

MindaroGardens_EventScript_VsAgnisJoel::
	lock
	setvar VAR_MINDARO_GARDENS_STATE, 2
	playbgm MUS_ENCOUNTER_SUSPICIOUS, FALSE
	applymovement LOCALID_AGNIS, Common_Movement_ExclamationMark
	waitmovement 0
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox MindaroGardens_Text_AgnisIntro, MSGBOX_DEFAULT
	playbgm MUS_ENCOUNTER_SUSPICIOUS, FALSE
	applymovement LOCALID_JOEL, Common_Movement_ExclamationMark
	waitmovement 0
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox MindaroGardens_Text_JoelIntro, MSGBOX_DEFAULT
	special SavePlayerParty
	trainerbattle TRAINER_BATTLE_SET_TRAINER_A, TRAINER_AGNIS, 0, NULL, MindaroGardens_Text_AgnisDefeated
	trainerbattle TRAINER_BATTLE_SET_TRAINER_B, TRAINER_JOEL, 0, NULL, MindaroGardens_Text_JoelDefeated
	call MindaroGardens_EventScript_OPCBattleSetup
	@special HealPlayerParty
	special LoadPlayerParty
	special HealPlayerParty
	release
	end

MindaroGardens_EventScript_VsPierreCecilia::
	lock
	setvar VAR_MINDARO_GARDENS_STATE, 3
	playbgm MUS_ENCOUNTER_RICH, FALSE
	applymovement LOCALID_PIERRE, Common_Movement_ExclamationMark
	waitmovement 0
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox MindaroGardens_Text_PierreIntro, MSGBOX_DEFAULT
	playbgm MUS_ENCOUNTER_FEMALE, FALSE
	applymovement LOCALID_CECILIA, Common_Movement_ExclamationMark
	waitmovement 0
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	msgbox MindaroGardens_Text_CeciliaIntro, MSGBOX_DEFAULT
	special SavePlayerParty
	trainerbattle TRAINER_BATTLE_SET_TRAINER_A, TRAINER_PIERRE, 0, NULL, MindaroGardens_Text_PierreDefeated
	trainerbattle TRAINER_BATTLE_SET_TRAINER_B, TRAINER_CECILIA, 0, NULL, MindaroGardens_Text_CeciliaDefeated
	call MindaroGardens_EventScript_OPCBattleSetup
	@special HealPlayerParty
	special LoadPlayerParty
	special HealPlayerParty
	release
	end

MindaroGardens_EventScript_VsCasseyWesley::
	lock
	setvar VAR_MINDARO_GARDENS_STATE, 4
	playbgm MUS_ENCOUNTER_GIRL, FALSE
	applymovement LOCALID_CASSEY, Common_Movement_ExclamationMark
	waitmovement 0
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox MindaroGardens_Text_CasseyIntro, MSGBOX_DEFAULT
	playbgm MUS_ENCOUNTER_MALE, FALSE
	applymovement LOCALID_WESLEY, Common_Movement_ExclamationMark
	waitmovement 0
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	msgbox MindaroGardens_Text_WesleyIntro, MSGBOX_DEFAULT
	special SavePlayerParty
	trainerbattle TRAINER_BATTLE_SET_TRAINER_A, TRAINER_CASSEY, 0, NULL, MindaroGardens_Text_CasseyDefeated
	trainerbattle TRAINER_BATTLE_SET_TRAINER_B, TRAINER_WESLEY, 0, NULL, MindaroGardens_Text_WesleyDefeated
	call MindaroGardens_EventScript_OPCBattleSetup
	@special HealPlayerParty
	special LoadPlayerParty
	special HealPlayerParty
	release
	end

MindaroGardens_EventScript_VsBeatriceJeromie::
	lock
	setvar VAR_MINDARO_GARDENS_STATE, 5
	playbgm MUS_ENCOUNTER_FEMALE, FALSE
	applymovement LOCALID_BEATRICE, Common_Movement_ExclamationMark
	waitmovement 0
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox MindaroGardens_Text_BeatriceIntro, MSGBOX_DEFAULT
	playbgm MUS_ENCOUNTER_RICH, FALSE
	applymovement LOCALID_JEROMIE, Common_Movement_ExclamationMark
	waitmovement 0
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox MindaroGardens_Text_JeromieIntro, MSGBOX_DEFAULT
	special SavePlayerParty
	trainerbattle TRAINER_BATTLE_SET_TRAINER_A, TRAINER_BEATRICE, 0, NULL, MindaroGardens_Text_BeatriceDefeated
	trainerbattle TRAINER_BATTLE_SET_TRAINER_B, TRAINER_JEROMIE, 0, NULL, MindaroGardens_Text_JeromieDefeated
	call MindaroGardens_EventScript_OPCBattleSetup
	@special HealPlayerParty
	special LoadPlayerParty
	special HealPlayerParty
	release
	end












MindaroGardens_EventScript_Chelsea::
@	trainerbattle_single TRAINER_CHELSEA, MindaroGardens_Text_ChelseaIntro, MindaroGardens_Text_ChelseaDefeated
	msgbox MindaroGardens_Text_ChelseaPostBattle, MSGBOX_NPC
	end

MindaroGardens_EventScript_Amanda::
@	trainerbattle_single TRAINER_AMANDA, MindaroGardens_Text_AmandaIntro, MindaroGardens_Text_AmandaDefeated
	msgbox MindaroGardens_Text_AmandaPostBattle, MSGBOX_NPC
	end

MindaroGardens_EventScript_Jeromie::
@	trainerbattle_single TRAINER_JEROMIE, MindaroGardens_Text_JeromieIntro, MindaroGardens_Text_JeromieDefeated
	msgbox MindaroGardens_Text_JeromiePostBattle, MSGBOX_NPC
	end

MindaroGardens_EventScript_Beatrice::
@	trainerbattle_single TRAINER_BEATRICE, MindaroGardens_Text_BeatriceIntro, MindaroGardens_Text_BeatriceDefeated
	msgbox MindaroGardens_Text_BeatricePostBattle, MSGBOX_NPC
	end

MindaroGardens_EventScript_Cassey::
@	trainerbattle_single TRAINER_CASSEY, MindaroGardens_Text_CasseyIntro, MindaroGardens_Text_CasseyDefeated
	msgbox MindaroGardens_Text_CasseyPostBattle, MSGBOX_NPC
	end

MindaroGardens_EventScript_Wesley::
@	trainerbattle_single TRAINER_WESLEY, MindaroGardens_Text_WesleyIntro, MindaroGardens_Text_WesleyDefeated
	msgbox MindaroGardens_Text_WesleyPostBattle, MSGBOX_NPC
	end

MindaroGardens_EventScript_Agnis::
@	trainerbattle_single TRAINER_AGNIS, MindaroGardens_Text_AgnisIntro, MindaroGardens_Text_AgnisDefeated
	msgbox MindaroGardens_Text_AgnisPostBattle, MSGBOX_NPC
	end

MindaroGardens_EventScript_Joel::
@	trainerbattle_single TRAINER_JOEL, MindaroGardens_Text_JoelIntro, MindaroGardens_Text_JoelDefeated
	msgbox MindaroGardens_Text_JoelPostBattle, MSGBOX_NPC
	end

MindaroGardens_EventScript_Pierre::
@	trainerbattle_single TRAINER_PIERRE, MindaroGardens_Text_PierreIntro, MindaroGardens_Text_PierreDefeated
	msgbox MindaroGardens_Text_PierrePostBattle, MSGBOX_NPC
	end

MindaroGardens_EventScript_Cecilia::
@	trainerbattle_single TRAINER_CECILIA, MindaroGardens_Text_CeciliaIntro, MindaroGardens_Text_CeciliaDefeated
	msgbox MindaroGardens_Text_CeciliaPostBattle, MSGBOX_NPC
	end








MindaroGardens_Text_ChelseaIntro:
	.string "Hey, you're getting in the way\n"
	.string "of my painting!$"

MindaroGardens_Text_ChelseaDefeated:
	.string "Another painting ruined.$"

MindaroGardens_Text_ChelseaPostBattle:
	.string "The foliage is beautiful this time\n"
	.string "of the year.\p"
	.string "But all these visitors keep getting\n"
	.string "in the way.$"

MindaroGardens_Text_AmandaIntro:
	.string "Another couple of trainers, another\n"
	.string "chance to improve my winning record!$"

MindaroGardens_Text_AmandaDefeated:
	.string "Record broken.$"

MindaroGardens_Text_AmandaPostBattle:
	.string "There are a lot of people participating\n"
	.string "this year.\p"
	.string "It's no surprise that some of them\n"
	.string "are so strong.$"

MindaroGardens_Text_JeromieIntro:
	.string "Must we really mingle with\n"
	.string "the unwashed masses?$"

MindaroGardens_Text_JeromieDefeated:
	.string "Sacre bleu!$"

MindaroGardens_Text_JeromiePostBattle:
	.string "Ugh. Why can't she enjoy dancing and cake\n"
	.string "like a normal madmoiselle?$"

MindaroGardens_Text_BeatriceIntro:
	.string "You're almost to the end. I wonder can\n"
	.string "you make it past us?$"

MindaroGardens_Text_BeatriceDefeated:
	.string "Great job!$"

MindaroGardens_Text_BeatricePostBattle:
	.string "Most of the trainers have gotten\n"
	.string "through already.\p"
	.string "Someone has to stay out here and give\n"
	.string "the stragglers a bit of challenge.$"

MindaroGardens_Text_CasseyIntro:
	.string "Oh, you're both trainers? In that case,\n"
	.string "we'll take you on as a team!$"

MindaroGardens_Text_CasseyDefeated:
	.string "No good!$"

MindaroGardens_Text_CasseyPostBattle:
	.string "We're still working on our team combo.\p"
	.string "I heard the trainers here like\n"
	.string "double battles.$"

MindaroGardens_Text_WesleyIntro:
	.string "This maze is confusing. Do you guys\n"
	.string "know the way out?$"

MindaroGardens_Text_WesleyDefeated:
	.string "That figures.$"

MindaroGardens_Text_WesleyPostBattle:
	.string "I think you can walk through some of\n"
	.string "these hedges. I saw someone else do it.\p"
	.string "I hope that's not the way out of\n"
	.string "this maze...$"

MindaroGardens_Text_AgnisIntro:
	.string "What are you doing here?! No one\n"
	.string "should know about this place!$"

MindaroGardens_Text_AgnisDefeated:
	.string "Curses.$"

MindaroGardens_Text_AgnisPostBattle:
	.string "Intrusive spirits, begone!$"

MindaroGardens_Text_JoelIntro:
	.string "Uhuhuh. Check out my rare bug collection.$"

MindaroGardens_Text_JoelDefeated:
	.string "Not my prize bug!$"

MindaroGardens_Text_JoelPostBattle:
	.string "I thought there were supposed to be\n"
	.string "rare POKéMON here...$"

MindaroGardens_Text_PierreIntro:
	.string "Show me your esprit combattant.$"

MindaroGardens_Text_PierreDefeated:
	.string "I'm speechless!$"

MindaroGardens_Text_PierrePostBattle:
	.string "That battle was tres magnifique!$"

MindaroGardens_Text_CeciliaIntro:
	.string "Oh dear. If we stay out here too long,\n"
	.string "we'll miss the ball.$"

MindaroGardens_Text_CeciliaDefeated:
	.string "My word.$"

MindaroGardens_Text_CeciliaPostBattle:
	.string "Some occasions demand strict punctuality.\p"
	.string "But in other cases, it's better to be\n"
	.string "fashionably late.$"








MindaroGardens_EventScript_MeetOPC::
	lockall
	faceplayer
	applymovement LOCALID_OPC, Common_Movement_ExclamationMark
	waitmovement 0
	delay 30
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, MindaroGardens_EventScript_MeetViolet
	goto_if_eq VAR_RESULT, FEMALE, MindaroGardens_EventScript_MeetVert
	end

MindaroGardens_EventScript_MeetViolet::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	msgbox MindaroGardens_Text_VioletIntro, MSGBOX_DEFAULT
	goto MindaroGardens_EventScript_ExplainMaze
	end

MindaroGardens_EventScript_MeetVert::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	msgbox MindaroGardens_Text_VertIntro, MSGBOX_DEFAULT
	goto MindaroGardens_EventScript_ExplainMaze
	end

MindaroGardens_Text_VertIntro:
	.string "VERT: Oh, {PLAYER}!$"

MindaroGardens_Text_VioletIntro:
	.string "VIOLET: Oh, {PLAYER}!$"

MindaroGardens_EventScript_ExplainMaze::
	msgbox MindaroGardens_Text_OPCIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MindaroGardens_EventScript_TeamUp
	goto_if_eq VAR_RESULT, NO, MindaroGardens_EventScript_DontTeamUp
	end

MindaroGardens_EventScript_TeamUp::
	msgbox MindaroGardens_Text_TeamUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OPC, Common_Movement_WalkDown
	waitmovement 0
	removeobject LOCALID_OPC
	setobjectxyperm LOCALID_OPC, 39, 13
	@clearflag FLAG_RECEIVED_HM07
	clearflag FLAG_REACHED_MINDARO_MANSION
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	setvar VAR_MINDARO_CITY_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

MindaroGardens_EventScript_DontTeamUp::
	msgbox MindaroGardens_Text_DontTeamUp, MSGBOX_DEFAULT
	applymovement LOCALID_OPC, Common_Movement_FaceUp
	waitmovement 0
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

MindaroGardens_Text_OPCIntro:
	.string "I wasn't expecting to see you here.\p"
	.string "Are you here for the maze\n"
	.string "competition too?\p"
	.string "The prize they're offering this year\n"
	.string "is really good. It's HM02 FLY.\p"
	.string "You just have to reach the house\n"
	.string "at the end of the maze.\p"
	.string "But only the first people who\n"
	.string "make it will get a prize.\p"
	.string "And there are trainers in the maze\n"
	.string "who will want to fight for them.\p"
	.string "It would be easier to get to the end\n"
	.string "if we went in a group.\p"
	.string "So...\n"
	.string "Will you team up with me?$"

MindaroGardens_Text_TeamUp:
	.string "Great! I'll keep your POKéMON healthy.\n"
	.string "You just lead the way.$"

MindaroGardens_Text_DontTeamUp:
	.string "Oh...\p"
	.string "Well, if you need to time to get\n"
	.string "ready first, I understand.\p"
	.string "I'll be waiting here for you.$"







MindaroGardens_EventScript_Turnback::
	@goto_if_set FLAG_RESCUED_HEADBUTT_TUTOR, CinerousTower_Exterior_EventScript_SkipTurnback
	lockall
	setobjectxyperm LOCALID_OPC, 19, 51
	addobject LOCALID_OPC
	applymovement LOCALID_OPC, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_OPC, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	msgbox MindaroGardens_Text_OPCTurnback, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	removeobject LOCALID_OPC
	setobjectxyperm LOCALID_OPC, 39, 13
	@clearflag FLAG_RECEIVED_HM07
	clearflag FLAG_REACHED_MINDARO_MANSION
	releaseall
	end

MindaroGardens_EventScript_Turnback2::
	@goto_if_set FLAG_RESCUED_HEADBUTT_TUTOR, CinerousTower_Exterior_EventScript_SkipTurnback
	lockall
	setobjectxyperm LOCALID_OPC, 19, 25
	addobject LOCALID_OPC
	applymovement LOCALID_OPC, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_OPC, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	msgbox MindaroGardens_Text_OPCTurnback, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	removeobject LOCALID_OPC
	setobjectxyperm LOCALID_OPC, 39, 13
	@clearflag FLAG_RECEIVED_HM07
	clearflag FLAG_REACHED_MINDARO_MANSION
	releaseall
	end

MindaroGardens_Text_OPCTurnback:
	.string "Wait! We can't go back now.\n"
	.string "We won't make it in time!$"







MindaroGardens_EventScript_RaynerEncounter::
	lockall
	setvar VAR_MINDARO_CITY_STATE, 2
	setobjectxyperm LOCALID_OPC, 19, 24
	addobject LOCALID_OPC
	applymovement LOCALID_OPC, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_OPC, Common_Movement_WalkUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_OPC, Common_Movement_WalkUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_OPC, Common_Movement_WalkLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_OPC, Common_Movement_FaceUp
	waitmovement 0
	fadeoutbgm 0
	delay 40
	playmoncry SPECIES_EEVEE, CRY_MODE_NORMAL
	waitmoncry
	playse SE_PIN
	applymovement LOCALID_OPC, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 20
	applymovement LOCALID_OPC, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 20
	msgbox MindaroGardens_Text_OPCNoticeEevee, MSGBOX_DEFAULT
	closemessage
	delay 60
	clearflag FLAG_HIDE_RAYNER
	addobject LOCALID_RAYNER
	applymovement LOCALID_RAYNER, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_WalkDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_OPC, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_OPC, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 60
	playbgm MUS_WEATHER_GROUDON, FALSE

	checkplayergender
	call_if_eq VAR_RESULT, MALE, MindaroGardens_EventScript_RaynerIntroVert
	call_if_eq VAR_RESULT, FEMALE, MindaroGardens_EventScript_RaynerIntroViolet

	
	delay 60
	applymovement LOCALID_OPC, Common_Movement_FaceRight
	waitmovement 0
	msgbox MindaroGardens_Text_OPCConfused, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_OPC, Common_Movement_FaceUp
	waitmovement 0
	delay 30
	msgbox MindaroGardens_Text_RaynerContinues, MSGBOX_DEFAULT
	msgbox MindaroGardens_Text_RaynerSeesImperfectIVs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MindaroGardens_EventScript_HandOverPokemon
	goto_if_eq VAR_RESULT, NO, MindaroGardens_EventScript_DontHandOverPokemon
	end

MindaroGardens_EventScript_RaynerIntroViolet::
	msgbox MindaroGardens_Text_RaynerIntroViolet, MSGBOX_DEFAULT
	closemessage
	return

MindaroGardens_EventScript_RaynerIntroVert::
	msgbox MindaroGardens_Text_RaynerIntroVert, MSGBOX_DEFAULT
	closemessage
	return

MindaroGardens_Text_OPCNoticeEevee:
	.string "Oh, those were EEVEE. I wonder\n"
	.string "why they're running like that.$"

MindaroGardens_Text_RaynerIntroViolet:
	.string "??????: I don't believe it.\p"
	.string "{PLAYER}, babe.\n"
	.string "It's been too long!\p"
	.string "You made it through that cave\n"
	.string "in one piece, I see.\p"
	.string "I told you it would be dangerous.$"

MindaroGardens_Text_RaynerIntroVert:
	.string "??????: I don't believe it.\p"
	.string "{PLAYER}, my man.\n"
	.string "It's been too long!\p"
	.string "You made it through that cave\n"
	.string "in one piece, I see.\p"
	.string "I told you it would be dangerous.$"

MindaroGardens_Text_OPCConfused:
	.string "{PLAYER}, do you know this guy?$"

MindaroGardens_Text_RaynerContinues:
	.string "??????: We've run into each\n"
	.string "other a couple times.\p"
	.string "So tell me, are your POKéMON still\n"
	.string "weak like from before?\p"
	.string "Or did you upgrade to better ones?\n"
	.string "Let me see.$"
	@.string "So tell me, are you still using\n"
	@.string "weak POKéMON like before?$"

MindaroGardens_Text_RaynerSeesPerfectIVs:
	.string "\p"
	.string "Woah, I don't believe it!\n"
	.string "You actually figured it out.\p"
	.string "Where did you get POKéMON like that?\p"
	.string "You didn't happen to meet that\n"
	.string "old doctor, did you?$"

MindaroGardens_Text_RaynerSeesImperfectIVs:
	.string "\p"
	.string "Sigh... Looks like you haven't\n"
	.string "learned a thing.\p"
	.string "Listen, you're gonna need better POKéMON\n"
	.string "if you still want to be a trainer.\p"
	.string "You need the best tools if you want\n"
	.string "to be the best trainer.\p"
	.string "I can take those off your hands\n"
	.string "and give you better ones.\p"
	.string "How about it?$"

MindaroGardens_EventScript_HandOverPokemon::
	closemessage
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	delay 30
	msgbox MindaroGardens_Text_HandOverPokemon, MSGBOX_DEFAULT
	closemessage
	@specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	special DeleteUnselectedPartyMons
	applymovement LOCALID_OPC, Common_Movement_WalkInPlaceUp
	waitmovement 0
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, MindaroGardens_EventScript_VioletNo
	goto_if_eq VAR_RESULT, FEMALE, MindaroGardens_EventScript_VertNo
	end

MindaroGardens_EventScript_VioletNo::
	msgbox MindaroGardens_Text_VioletNo, MSGBOX_DEFAULT
	closemessage	
	goto MindaroGardens_EventScript_RaynerSike
	end

MindaroGardens_EventScript_VertNo::
	msgbox MindaroGardens_Text_VertNo, MSGBOX_DEFAULT
	closemessage	
	goto MindaroGardens_EventScript_RaynerSike
	end

MindaroGardens_EventScript_RaynerSike::
	message MindaroGardens_Text_RaynerSavesGame
	@delay 30
	@call Common_EventScript_SaveGame
	@special SaveGameNoPrompt
	@waitstate
	msgbox MindaroGardens_Text_RaynerTakesPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MindaroGardens_Movement_PushedBack
	waitmovement 0
	delay 60
	applymovement LOCALID_RAYNER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox MindaroGardens_Text_RaynerThankMe, MSGBOX_DEFAULT
	closemessage
	goto MindaroGardens_EventScript_OPCReacts
	end

MindaroGardens_Text_HandOverPokemon:
	.string "{PLAYER} handed over the POKéMON.$"

MindaroGardens_Text_VertNo:
	.string "VERT: {PLAYER}! What are you doing?!$"

MindaroGardens_Text_VioletNo:
	.string "VIOLET: {PLAYER}! What are you doing?!$"

MindaroGardens_Text_RaynerSavesGame:
	.string " Hehehe. Thanks a lot.\p"
	.string "Oh, hold on just one second.$"

MindaroGardens_Text_RaynerTakesPokemon:
	.string "There you go. Now you're all set\n"
	.string "for your new and improved POKéMON!\p"
	.string "\p"
	.string "Hey now, what's this?\p"
	.string "Uh-oh... Looks like I'm all out\n"
	.string "of free POKéMON.\p"
	.string "Tough luck...\p"
	.string "At least you won't have these\n"
	.string "dragging you down anymore.\p"
	.string "Hey, I'm not heartless.\p"
	.string "I left you with one POKéMON so\n"
	.string "you can still get out of here.\p"
	.string "You can manage that, right?\p"
	.string "You're not totally worthless, right?$"

MindaroGardens_Text_RaynerThankMe:
	.string "??????: You really should be\n"
	.string "thanking me, though.\p"
	@.string "I just helped you take the hardest step\n"
	@.string "on your road to recovery.\p"
	.string "Now you don't have to let that\n"
	.string "weakness drag you down anymore.$"
	@.string "That miserable old doctor knows a thing\n"
	@.string "or too about strong POKéMON.\p"
	@.string "Who knows? Maybe he could even help\n"
	@.string "a sad loser like you.$"


MindaroGardens_EventScript_DontHandOverPokemon::
	msgbox MindaroGardens_Text_RaynerDoesntTakePokemon, MSGBOX_DEFAULT
	closemessage
	goto MindaroGardens_EventScript_OPCReacts
	end

MindaroGardens_Text_RaynerDoesntTakePokemon:
	.string "Still the sentimental type, huh?\p"
	.string "I guess that's the difference between\n"
	.string "you and me.\p"
	.string "I'm not afraid to let go of weakness.\n"
	.string "To transcend limitations of the flesh...\p"
	.string "\p"
	.string "I just wanted to help you out a little,\n"
	.string "that's all.\p"
	@.string "\p"
	.string "Sigh... I have to say I'm\n"
	.string "disappointed, {PLAYER}.\p"
	.string "Don't you ever get tired of doing\n"
	.string "things the wrong way?$"

MindaroGardens_EventScript_OPCReacts::
	delay 60
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, MindaroGardens_EventScript_VioletReacts
	goto_if_eq VAR_RESULT, FEMALE, MindaroGardens_EventScript_VertReacts
	end

MindaroGardens_EventScript_VioletReacts::
	applymovement LOCALID_OPC, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox MindaroGardens_Text_VioletReaction, MSGBOX_DEFAULT
	closemessage
	goto MindaroGardens_EventScript_RaynerExit
	end

MindaroGardens_EventScript_VertReacts::
	applymovement LOCALID_OPC, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox MindaroGardens_Text_VertReaction, MSGBOX_DEFAULT
	closemessage
	goto MindaroGardens_EventScript_RaynerExit
	end

MindaroGardens_Text_VertReaction:
	.string "VERT: What are you talking about!?\p"
	.string "Helping people by taking their POKéMON?\p"
	.string "You're a real creep! That's what you are!$"

MindaroGardens_Text_VioletReaction:
	.string "VIOLET: What are you talking about!?\p"
	.string "Helping people by taking their POKéMON?\p"
	.string "You're a real creep! That's what you are!$"

MindaroGardens_EventScript_RaynerExit::
	delay 30
	msgbox MindaroGardens_Text_RaynerUnderstand, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RAYNER, Common_Movement_WalkDown
	waitmovement 0
	@applymovement LOCALID_RAYNER, Common_Movement_WalkDown
	@waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, MindaroGardens_Movement_ShovedAside
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_WalkDown
	applymovement LOCALID_OPC, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_WalkDown
	waitmovement 0
	removeobject LOCALID_RAYNER
	setflag FLAG_HIDE_RAYNER
	@delay 30
	@setvar VAR_MINDARO_CITY_STATE, 2
	fadedefaultbgm
	delay 60
	goto MindaroGardens_EventScript_ForgetAboutHim
	end

MindaroGardens_Text_RaynerUnderstand:
	.string "??????: ...\p"
	.string "Tch!\n"
	.string "You just don't get it, do you?\p"
	.string "Well, I'm not gonna waste my time\n"
	.string "on the likes of you.\p"
	.string "I got everything I came here for.\n"
	.string "Later, losers.$"

MindaroGardens_EventScript_ForgetAboutHim::
	applymovement LOCALID_OPC, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox MindaroGardens_Text_OPCForgetAboutHim, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OPC, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_OPC, Common_Movement_WalkRight
	waitmovement 0
	removeobject LOCALID_OPC
	setobjectxyperm LOCALID_OPC, 39, 13
	@clearflag FLAG_RECEIVED_HM07
	clearflag FLAG_REACHED_MINDARO_MANSION
	releaseall
	end

MindaroGardens_Text_OPCForgetAboutHim:
	.string "What a real piece of work that guy was.\p"
	.string "You met each other before?\n"
	.string "Who is he anyway?\p"
	.string "\p"
	.string "Well, let's forget about him.\p"
	.string "We still have to find that house and\n"
	.string "claim the prize.$"

MindaroGardens_Movement_PushedBack:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

MindaroGardens_Movement_ShovedAside:
	face_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end



MindaroGardens_EventScript_MansionInSight1::
	lockall
	setobjectxyperm LOCALID_OPC, 18, 13
	addobject LOCALID_OPC
	applymovement LOCALID_OPC, Common_Movement_WalkUp
	waitmovement 0
	delay 30
	msgbox MindaroGardens_Text_OPCSeesMansion, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_OPC, Common_Movement_FaceDown
	waitmovement 0
	msgbox MindaroGardens_Text_LetsGoInside, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OPC, Common_Movement_WalkRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_OPC, Common_Movement_WalkRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_OPC, Common_Movement_WalkRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	goto MindaroGardens_EventScript_WalkToMansion
	end

MindaroGardens_EventScript_MansionInSight2::
	lockall
	setobjectxyperm LOCALID_OPC, 19, 13
	addobject LOCALID_OPC
	applymovement LOCALID_OPC, Common_Movement_WalkUp
	waitmovement 0
	delay 30
	msgbox MindaroGardens_Text_OPCSeesMansion, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_OPC, Common_Movement_FaceDown
	waitmovement 0
	msgbox MindaroGardens_Text_LetsGoInside, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OPC, Common_Movement_WalkRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_OPC, Common_Movement_WalkRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	goto MindaroGardens_EventScript_WalkToMansion
	end

MindaroGardens_EventScript_MansionInSight3::
	lockall
	setobjectxyperm LOCALID_OPC, 20, 13
	addobject LOCALID_OPC
	applymovement LOCALID_OPC, Common_Movement_WalkUp
	waitmovement 0
	delay 30
	msgbox MindaroGardens_Text_OPCSeesMansion, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_OPC, Common_Movement_FaceDown
	waitmovement 0
	msgbox MindaroGardens_Text_LetsGoInside, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OPC, Common_Movement_WalkRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	goto MindaroGardens_EventScript_WalkToMansion
	end

MindaroGardens_Text_OPCSeesMansion:
	.string "This must be it.\n"
	.string "That's one fancy house!$"

MindaroGardens_Text_LetsGoInside:
	.string "Come on, let's go inside!$"

MindaroGardens_EventScript_WalkToMansion::
	applymovement LOCALID_OPC, Common_Movement_WalkUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_OPC, Common_Movement_WalkUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_OPC, Common_Movement_WalkUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_OPC, Common_Movement_WalkUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_OPC, Common_Movement_WalkLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_OPC, Common_Movement_WalkLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_OPC, Common_Movement_WalkUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_OPC, Common_Movement_WalkUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_OPC, Common_Movement_WalkUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	warp MAP_MINDARO_GARDENS_MANSION_LOBBY, 10, 10
	waitstate
	releaseall
	end

