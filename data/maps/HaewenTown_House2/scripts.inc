HaewenTown_House2_MapScripts::
	.byte 0

HaewenTown_House2_EventScript_BattleGirl::
	lock
	faceplayer
	msgbox HaewenTown_House2_Text_EthelPast, MSGBOX_DEFAULT
	release
	end

HaewenTown_House2_Text_EthelPast:
	.string "The gym leader of this town\n"
	.string "is MOTHER ETHEL.\p"
	.string "I heard that she used to travel the whole\n"
	.string "world in search for mythical POKéMON.\p"
	.string "That is, POKéMON that aren't\n"
	.string "even proven to exist.\p"
	.string "That's how she became known as\n"
	.string "the mythic hunter.\p"
	.string "But then something happened that\n"
	.string "she'll never say a word about.\p"
	.string "Eventually she came back hear to lead\n"
	.string "our clan of dragon tamers.\p"
	.string "And she's been focused on her\n"
	.string "gym ever since.$"













HaewenTown_House2_EventScript_DracoMeteorTutor::
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_37
	goto_if_eq VAR_RESULT, TRUE, HaewenTown_House2_EventScript_TeachDracoMeteor
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_37
	goto_if_eq VAR_RESULT, TRUE, HaewenTown_House2_EventScript_QuestInProgress
	msgbox HaewenTown_House2_Text_BeatMySisterFirst, MSGBOX_DEFAULT
	@questmenu QUEST_MENU_UNLOCK_QUEST QUEST_37
	@openquestmenu
	startquest QUEST_37
	release
	end

HaewenTown_House2_Text_BeatMySisterFirst:
	.string "The gym leader in this town\n"
	.string "is my older sister.\p"
	.string "Give her a good whoppin' for me!\p"
	@.string "would ya?\p"
	.string "If you show me you did by bringing\n"
	.string "the gym badge back with you,\p"
	.string "I'll show you my secret art!$" 

	

HaewenTown_House2_EventScript_QuestInProgress::
	goto_if_set FLAG_BADGE07_GET, HaewenTown_House2_EventScript_UnlockTutor
	msgbox HaewenTown_House2_Text_BeatMySisterFirst, MSGBOX_DEFAULT
	release
	end

HaewenTown_House2_EventScript_UnlockTutor::
	msgbox HaewenTown_House2_Text_WellDone, MSGBOX_DEFAULT
	@questmenu QUEST_MENU_COMPLETE_QUEST QUEST_37
	@openquestmenu
	completequest QUEST_37
	@goto HaewenTown_House2_EventScript_TeachDracoMeteor
	release
	end


HaewenTown_House2_EventScript_TeachDracoMeteor::
	msgbox HaewenTown_House2_Text_TeachDracoMeteor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, HaewenTown_House2_EventScript_ChooseMonForTutor
	goto_if_eq VAR_RESULT, NO, HaewenTown_House2_EventScript_ExitTutor
	release
	end

HaewenTown_House2_EventScript_ChooseMonForTutor::
	setvar VAR_0x8005, MOVE_DRACO_METEOR
	msgbox HaewenTown_House2_Text_TeachWhichPokemon, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, FALSE, HaewenTown_House2_EventScript_ExitTutor
	release
	end

HaewenTown_House2_EventScript_ExitTutor::
	@msgbox TurquoiseCity_Text_ComeBack, MSGBOX_DEFAULT
	release
	end





HaewenTown_House2_Text_WellDone:
	.string "That's it!\n"
	.string "That's the WYRM BADGE all right!\p"
	.string "Congratulations on beatin' ETHEL!\n"
	.string "I hope you did her in good for me.\p"
	.string "She never gets challengers out here.\n"
	.string "Much less loses to 'em!\p"
	.string "She thinks she can just come back\n"
	.string "here and take over,\p"
	.string "After galavantin' all o'er the world\n"
	.string "for years with no contact!\p"
	.string "She's always been the strongest.\n"
	.string "That's how she gets her way!\p"
	.string "But I got the brains of the family,\n"
	.string "that I did!\p"
	.string "I'm the only one who inherited the\n"
	.string "clan's secret technique!\p"
	.string "I'll teach it to as many POKéMON\n" 
	.string "as you want.\p"
	.string "Just come whoop on my sister every\n"
	.string "once in a while, will ya?$"


HaewenTown_House2_Text_TeachDracoMeteor:
	.string "Would you like me to teach your POKéMON\n"
	.string "the move DRACO METEOR?$"

HaewenTown_House2_Text_TeachWhichPokemon:
	.string "Which POKéMON should I teach?$"



