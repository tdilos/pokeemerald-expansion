.set LOCALID_OPC, 8

DunTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DunTown_OnTransition
	.byte 0

DunTown_OnTransition:
	setflag FLAG_VISITED_DUN_TOWN
	call Common_EventScript_SetupRivalGfxId
	end

DunTown_EventScript_TownSign::
	msgbox DunTown_Text_TownSign, MSGBOX_SIGN
	end

DunTown_Text_TownSign:
	.string "DUN TOWN\n"
	.string "“Carefree town at the end of the world.”$"

DunTown_EventScript_MotelSign::
	msgbox DunTown_Text_MotelSign, MSGBOX_SIGN
	end

DunTown_Text_MotelSign:
	.string "DUN TOWN MOTEL$"






DunTown_EventScript_Youngster::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_AZAMI, DunTown_EventScript_BoatmanReturned
	msgbox DunTown_Text_BoatmanGone, MSGBOX_DEFAULT
	release
	end

DunTown_EventScript_BoatmanReturned::
	msgbox DunTown_Text_BoatmanReturned, MSGBOX_DEFAULT
	release
	end

DunTown_Text_BoatmanGone:
	.string "The boatman hasn't come back yet.\n"
	.string "I wonder where he goes for so long.$"

DunTown_Text_BoatmanReturned:
	.string "The boatman has returned!$"

DunTown_EventScript_Triathlete::
	lock
	faceplayer
	msgbox DunTown_Text_MantykeSurfing, MSGBOX_DEFAULT
	release
	end

DunTown_Text_MantykeSurfing:
	.string "Check it out, little dude.\p"
	.string "Have you ever seen somebody surf\n"
	.string "on a MANTYKE before?$"

DunTown_EventScript_TuberM::
	lock
	faceplayer
	msgbox DunTown_Text_Seashells, MSGBOX_DEFAULT
	release
	end

DunTown_Text_Seashells:
	.string "I'm hunting for seashells.\n"
	.string "Have you seen any?$"

DunTown_EventScript_TuberF::
	lock
	faceplayer
	msgbox DunTown_Text_Sunburnt, MSGBOX_DEFAULT
	release
	end

DunTown_Text_Sunburnt:
	.string "Hehehe, Daddy's gonna get\n"
	.string "sunburnt again.$"

DunTown_EventScript_Man::
	msgbox DunTown_Text_Snooze, MSGBOX_DEFAULT
	closemessage
	end

DunTown_Text_Snooze:
	.string "Not now...\n"
	.string "Can't you see I'm busy...\p"
	.string "Zzzzzzzzzzzzzz.$"

DunTown_EventScript_Beauty::
	goto_if_set FLAG_DUN_TOWN_RECEIVED_UTILITY_UMBRELLA, DunTown_EventScript_BeautyPostItem
	msgbox DunTown_Text_Lotion, MSGBOX_NPC
	giveitem ITEM_UTILITY_UMBRELLA
	setflag FLAG_DUN_TOWN_RECEIVED_UTILITY_UMBRELLA
	end

DunTown_EventScript_BeautyPostItem::
	msgbox DunTown_Text_ExplainUtilityUmbrella, MSGBOX_NPC
	end

DunTown_Text_Lotion:
	.string "Hey there, cutie. Wanna help\n"
	.string "me with my suntan lotion?\p"
	.string "Teehee, just kidding!\p"
	.string "Here, you can keep out of\n"
	.string "the sun with this.$"

DunTown_Text_ExplainUtilityUmbrella:
	.string "Give that UTILITY UMBRELLA to one\n"
	.string "of your POKéMON to hold.\p"
	.string "It'll be protected from rain and sunlight.$"
	@.string "but not other kinds of weather.$"

DunTown_EventScript_Sailor::
	lock
	faceplayer
	msgbox DunTown_Text_YoHo, MSGBOX_DEFAULT
	release
	end

DunTown_Text_YoHo:
	.string "Yo-ho! Yo-ho!\n"
	.string "A sailor's life for me!$"















DunTown_EventScript_OPC::
	lockall
	faceplayer
	checkplayergender
	call_if_eq VAR_RESULT, MALE, DunTown_EventScript_GirlMusic
	call_if_eq VAR_RESULT, FEMALE, DunTown_EventScript_BoyMusic
	msgbox DunTown_Text_OPCEncounter, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DunTown_EventScript_BattleOPC
	msgbox DunTown_Text_DontBattleOPC, MSGBOX_DEFAULT
	closemessage
	goto DunTown_EventScript_OPCLeaves
	end

DunTown_EventScript_OPCLeaves::
	fadescreen FADE_TO_BLACK
	delay 30
	removeobject LOCALID_OPC
	setflag FLAG_BATTLED_OPC_DUN_TOWN	
	savebgm MUS_DUMMY
	fadedefaultbgm
	delay 30
	fadescreen FADE_FROM_BLACK
	releaseall
	end

DunTown_EventScript_BattleOPC::
	msgbox DunTown_Text_OPCPreBattle, MSGBOX_DEFAULT
	closemessage
	switch VAR_STARTER_MON
	case 0, DunTown_EventScript_StartOPCBattleChespin
	case 1, DunTown_EventScript_StartOPCBattleTepig
	case 2, DunTown_EventScript_StartOPCBattlePopplio
	end

DunTown_EventScript_BoyMusic:
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

DunTown_EventScript_GirlMusic:
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

DunTown_Text_OPCEncounter:
	.string "Oh, {PLAYER}!\n"
	.string "I didn't expect to see you here.\p"
	.string "\p"
	.string "Actually the truth is {PLAYER},\n"
	.string "I'm going to be going away somewhere.\p"
	.string "And I'm not sure when I'll be back.\p"
	.string "It could be a long time before I\n"
	.string "get to see ISSHO again.\p"
	.string "So...\n"
	.string "Will you have one more battle with me?$"

DunTown_Text_OPCPreBattle:
	.string "Great, let's both give it our best shot!$"

DunTown_Text_NotEnoughPokemon:
	.string "Oh sorry, I should have mentioned.\n"
	.string "I want to have a double battle this time.$"

DunTown_Text_DontBattleOPC:
	.string "$"

DunTown_EventScript_StartOPCBattleChespin::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, DunTown_EventScript_VioletBattleChespin
	goto_if_eq VAR_RESULT, FEMALE, DunTown_EventScript_VertBattleChespin
	end	

DunTown_EventScript_VioletBattleChespin::
	@trainerbattle_double TRAINER_VIOLET_DUN_TOWN_CHESPIN, DunTown_Text_OPCPreBattle, DunTown_Text_VioletDefeated, DunTown_Text_NotEnoughPokemon, DunTown_EventScript_AfterOPCBattle, TRUE
	trainerbattle_no_intro TRAINER_VIOLET_DUN_TOWN_CHESPIN, DunTown_Text_VioletDefeated
	goto DunTown_EventScript_AfterOPCBattle
	end

DunTown_EventScript_VertBattleChespin::
	@trainerbattle_double TRAINER_VERN_DUN_TOWN_CHESPIN, DunTown_Text_OPCPreBattle, DunTown_Text_VertDefeated, DunTown_Text_NotEnoughPokemon
	trainerbattle_no_intro TRAINER_VERN_DUN_TOWN_CHESPIN, DunTown_Text_VertDefeated
	goto DunTown_EventScript_AfterOPCBattle
	end



DunTown_EventScript_StartOPCBattleTepig::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, DunTown_EventScript_VioletBattleTepig
	goto_if_eq VAR_RESULT, FEMALE, DunTown_EventScript_VertBattleTepig
	end	

DunTown_EventScript_VioletBattleTepig::
	@trainerbattle_double TRAINER_VIOLET_DUN_TOWN_TEPIG, DunTown_Text_OPCPreBattle, DunTown_Text_VioletDefeated, DunTown_Text_NotEnoughPokemon
	trainerbattle_no_intro TRAINER_VIOLET_DUN_TOWN_TEPIG, DunTown_Text_VioletDefeated
	goto DunTown_EventScript_AfterOPCBattle
	end

DunTown_EventScript_VertBattleTepig::
	@trainerbattle_double TRAINER_VERN_DUN_TOWN_TEPIG, DunTown_Text_OPCPreBattle, DunTown_Text_VertDefeated, DunTown_Text_NotEnoughPokemon
	trainerbattle_no_intro TRAINER_VERN_DUN_TOWN_TEPIG, DunTown_Text_VertDefeated
	goto DunTown_EventScript_AfterOPCBattle
	end






DunTown_EventScript_StartOPCBattlePopplio::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, DunTown_EventScript_VioletBattlePopplio
	goto_if_eq VAR_RESULT, FEMALE, DunTown_EventScript_VertBattlePopplio
	end

DunTown_EventScript_VioletBattlePopplio::
	@trainerbattle_double TRAINER_VIOLET_DUN_TOWN_POPPLIO, DunTown_Text_OPCPreBattle, DunTown_Text_VioletDefeated, DunTown_Text_NotEnoughPokemon
	trainerbattle_no_intro TRAINER_VIOLET_DUN_TOWN_POPPLIO, DunTown_Text_VioletDefeated
	goto DunTown_EventScript_AfterOPCBattle
	end

DunTown_EventScript_VertBattlePopplio::
	@trainerbattle_double TRAINER_VERN_DUN_TOWN_POPPLIO, DunTown_Text_OPCPreBattle, DunTown_Text_VertDefeated, DunTown_Text_NotEnoughPokemon
	trainerbattle_no_intro TRAINER_VERN_DUN_TOWN_POPPLIO, DunTown_Text_VertDefeated
	goto DunTown_EventScript_AfterOPCBattle
	end

DunTown_Text_VioletDefeated:
	.string "You're amazing as always.$"

DunTown_Text_VertDefeated:
	.string "You're amazing as always.$"





DunTown_EventScript_AfterOPCBattle::
	@applymovement LOCALID_OPC, Common_Movement_WalkInPlaceRight
	@waitmovement 0
	delay 60
	msgbox DunTown_Text_AfterOPCBattle, MSGBOX_DEFAULT
	closemessage
	goto DunTown_EventScript_OPCLeaves
	end

DunTown_Text_AfterOPCBattle:
	.string "I'm glad I got to see you\n"
	.string "one last time, {PLAYER}.\p"
	.string "I have to be going now. But I hope\n"
	.string "we'll meet again some day.$"











