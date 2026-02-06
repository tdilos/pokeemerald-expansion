.set LOCALID_NURSE, 1

DunTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DunTown_PokemonCenter_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

DunTown_PokemonCenter_OnTransition:
	setrespawn HEAL_LOCATION_DUN_TOWN
	end

DunTown_PokemonCenter_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

DunTown_PokemonCenter_EventScript_Teala::
	msgbox DunTown_PokemonCenter_Text_Unavailable, MSGBOX_NPC
	end

DunTown_PokemonCenter_Text_Unavailable:
	.string "Our services are currently\n"
	.string "unavailable.$"






DunTown_PokemonCenter_EventScript_Boy::
	msgbox DunTown_PokemonCenter_Text_BoatToHoenn, MSGBOX_NPC
	end

DunTown_PokemonCenter_Text_BoatToHoenn:
	.string "The POKéMON LEAGUE is in\n"
	.string "EVER GRANDE CITY.\p"
	.string "It's not easy to get to.\p"
	.string "But the boatman goes there\n"
	.string "from time to time.\p"
	.string "He gives trainers a ride sometimes.\n"
	.string "Why don't you try asking him?$"
	@.string "He gives trainers a ride sometimes, but\n"
	@.string "only if you show him that you're ready.\p"
	@.string "Meaning he won't take you unless you've\n"
	@.string "gotten a badge from every gym in ISSHO.$"

DunTown_PokemonCenter_EventScript_Girl::
	msgbox DunTown_PokemonCenter_Text_BoatmanHistory, MSGBOX_NPC
	end

DunTown_PokemonCenter_Text_BoatmanHistory:
	.string "I heard that the boatman used to\n"
	.string "be one of the ELITE FOUR himself.\p"
	.string "But he retired here a while ago.$"






DunTown_PokemonCenter_EventScript_GameboyKid::
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_43
	goto_if_eq VAR_RESULT, TRUE, DunTown_PokemonCenter_EventScript_QuestComplete
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_43
	goto_if_eq VAR_RESULT, TRUE, DunTown_PokemonCenter_EventScript_QuestInProgress
	msgbox DunTown_PokemonCenter_Text_LikeToTrade, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, DunTown_PokemonCenter_EventScript_DontLikeToTrade
	msgbox DunTown_PokemonCenter_Text_MeToo, MSGBOX_DEFAULT
	startquest QUEST_43
	release
	end

DunTown_PokemonCenter_Text_LikeToTrade:
	.string "Hey, do you like trading for POKéMON?$"

DunTown_PokemonCenter_EventScript_DontLikeToTrade::
	msgbox DunTown_PokemonCenter_Text_Lame, MSGBOX_DEFAULT
	release
	end

DunTown_PokemonCenter_Text_MeToo:
	.string "Me too. I trade with my friends around\n"
	.string "ISSHO all the time.\p"
	.string "Come back here once you've traded\n"
	.string "with all of them.\p"
	.string "I'll give you a surprise!$"

DunTown_PokemonCenter_Text_Lame:
	.string "Whatever.\p"
	.string "You're lame.$"

DunTown_PokemonCenter_EventScript_QuestInProgress::
	goto_if_unset FLAG_XANTHOS_NPC_TRADE_COMPLETED, DunTown_PokemonCenter_EventScript_QuestIncomplete
	goto_if_unset FLAG_RESEDA_NPC_TRADE_COMPLETED, DunTown_PokemonCenter_EventScript_QuestIncomplete
	goto_if_unset FLAG_AMBER_NPC_TRADE_COMPLETED, DunTown_PokemonCenter_EventScript_QuestIncomplete
	goto_if_unset FLAG_COBALT_NPC_TRADE_COMPLETED, DunTown_PokemonCenter_EventScript_QuestIncomplete
	goto_if_unset FLAG_TURQUOISE_NPC_TRADE_COMPLETED, DunTown_PokemonCenter_EventScript_QuestIncomplete
	goto_if_unset FLAG_MINDARO_NPC_TRADE_COMPLETED, DunTown_PokemonCenter_EventScript_QuestIncomplete
	goto_if_unset FLAG_PITCHBLAK_NPC_TRADE_COMPLETED, DunTown_PokemonCenter_EventScript_QuestIncomplete
	msgbox DunTown_PokemonCenter_Text_YouFoundThem, MSGBOX_DEFAULT
	giveitem ITEM_COVENANT_ORB, 20
	completequest QUEST_43
	release
	end	

DunTown_PokemonCenter_EventScript_QuestIncomplete::
	msgbox DunTown_PokemonCenter_Text_StillNeedToTrade, MSGBOX_DEFAULT
	release
	end

DunTown_PokemonCenter_Text_StillNeedToTrade:
	.string "Nope. You still haven't traded\n"
	.string "with everyone yet.$"

DunTown_PokemonCenter_Text_YouFoundThem:
	.string "Wow, you actually traded\n"
	.string "with everybody. Great job!\p"
	.string "Here's the surprise I promised you!$"

DunTown_PokemonCenter_EventScript_QuestComplete::
	msgbox DunTown_PokemonCenter_Text_ExplainCovenantOrbs, MSGBOX_DEFAULT	
	release
	end

DunTown_PokemonCenter_Text_ExplainCovenantOrbs:
	.string "Some POKéMON evolve when you trade them.\p"
	.string "But you can use those COVENANT ORBS\n"
	.string "to make them evolve too.$"



