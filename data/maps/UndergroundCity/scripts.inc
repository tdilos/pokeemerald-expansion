UndergroundCity_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, UndergroundCity_OnWarp
	map_script MAP_SCRIPT_ON_TRANSITION, UndergroundCity_OnTransition
	.byte 0

UndergroundCity_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, UndergroundCity_EventScript_SetForceOffscreenLoad
	.2byte 0

UndergroundCity_EventScript_SetForceOffscreenLoad::
	setflag FLAG_FORCE_LOAD_OFFSCREEN_OBJEV
	end

UndergroundCity_OnTransition:
	special GetDifficulty
	goto_if_eq VAR_RESULT, 0, UndergroundCity_EventScript_RevealBurglar
	setflag FLAG_HIDE_SHORTCUT_NPCS
	end

UndergroundCity_EventScript_RevealBurglar::
	clearflag FLAG_HIDE_SHORTCUT_NPCS
	end






UndergroundCity_EventScript_Burglar::
	lock
	faceplayer
	message UndergroundCity_Text_BurglarIntro
	waitmessage
	showmoneybox 0, 0
	scrollingmultichoice 21, 16, 0, 4, TRUE
	switch VAR_RESULT
	case 0, UndergroundCity_EventScript_BuyCardA
	case 1, UndergroundCity_EventScript_BuyCardB
	case 1, UndergroundCity_EventScript_BuyCardC
	case 3, UndergroundCity_EventScript_CancelBuy
	case MULTI_B_PRESSED, UndergroundCity_EventScript_CancelBuy
	end

UndergroundCity_EventScript_BuyCardA::
	checkmoney 9999
	goto_if_eq VAR_RESULT, FALSE, UndergroundCity_EventScript_NotEnoughMoney
	checkitemspace ITEM_GENESIS_A_CARD
	goto_if_eq VAR_RESULT, FALSE, UndergroundCity_EventScript_NoRoomInBag
	playse SE_SHOP
	removemoney 9999
	additem ITEM_GENESIS_A_CARD
	updatemoneybox
	msgbox UndergroundCity_Text_PutCardInBag, MSGBOX_DEFAULT
	hidemoneybox
	goto UndergroundCity_EventScript_EndBuy
	end

UndergroundCity_EventScript_BuyCardB::
	checkmoney 9999
	goto_if_eq VAR_RESULT, FALSE, UndergroundCity_EventScript_NotEnoughMoney
	checkitemspace ITEM_GENESIS_B_CARD
	goto_if_eq VAR_RESULT, FALSE, UndergroundCity_EventScript_NoRoomInBag
	playse SE_SHOP
	removemoney 9999
	additem ITEM_GENESIS_B_CARD
	updatemoneybox
	msgbox UndergroundCity_Text_PutCardInBag, MSGBOX_DEFAULT
	hidemoneybox
	goto UndergroundCity_EventScript_EndBuy
	end

UndergroundCity_EventScript_BuyCardC::
	checkmoney 9999
	goto_if_eq VAR_RESULT, FALSE, UndergroundCity_EventScript_NotEnoughMoney
	checkitemspace ITEM_GENESIS_C_CARD
	goto_if_eq VAR_RESULT, FALSE, UndergroundCity_EventScript_NoRoomInBag
	playse SE_SHOP
	removemoney 9999
	additem ITEM_GENESIS_C_CARD
	updatemoneybox
	msgbox UndergroundCity_Text_PutCardInBag, MSGBOX_DEFAULT
	hidemoneybox
	goto UndergroundCity_EventScript_EndBuy
	end

UndergroundCity_EventScript_NoRoomInBag::
	msgbox UndergroundCity_Text_NoRoomInBag, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

UndergroundCity_EventScript_NotEnoughMoney::
	msgbox UndergroundCity_Text_NotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

UndergroundCity_EventScript_CancelBuy::
	msgbox UndergroundCity_Text_BurglarOutro, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

UndergroundCity_EventScript_EndBuy::
	msgbox UndergroundCity_Text_BurglarOutro, MSGBOX_DEFAULT
	release
	end

UndergroundCity_Text_BurglarIntro:
	.string "Looking for a shortcut, my dear?\p"
	.string "Perhaps these might interest you.\n"
	.string "They weren't easy to find, you know.\p"
	.string "And only ¥9999 each.$"

UndergroundCity_Text_NoRoomInBag:
	.string "But your bag is full, my dear.$"

UndergroundCity_Text_NotEnoughMoney:
	.string "You're short on money.\n"
	.string "What do I look like a charity?$"

UndergroundCity_Text_PutCardInBag:
	.string "{PLAYER} put the card in the bag.$"

UndergroundCity_Text_BurglarOutro:
	.string "Pleasure doing business with you,\n"
	.string "my dear.$" 






UndergroundCity_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_XANTHOS_UNDERGROUND_1, UndergroundCity_Text_Grunt1Intro, UndergroundCity_Text_Grunt1Defeated
	msgbox UndergroundCity_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

UndergroundCity_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_XANTHOS_UNDERGROUND_2, UndergroundCity_Text_Grunt2Intro, UndergroundCity_Text_Grunt2Defeated
	msgbox UndergroundCity_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

UndergroundCity_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_XANTHOS_UNDERGROUND_3, UndergroundCity_Text_Grunt3Intro, UndergroundCity_Text_Grunt3Defeated
	msgbox UndergroundCity_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

UndergroundCity_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_XANTHOS_UNDERGROUND_4, UndergroundCity_Text_Grunt4Intro, UndergroundCity_Text_Grunt4Defeated
	msgbox UndergroundCity_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

UndergroundCity_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_XANTHOS_UNDERGROUND_5, UndergroundCity_Text_Grunt5Intro, UndergroundCity_Text_Grunt5Defeated
	msgbox UndergroundCity_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

UndergroundCity_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_XANTHOS_UNDERGROUND_6, UndergroundCity_Text_Grunt6Intro, UndergroundCity_Text_Grunt6Defeated
	msgbox UndergroundCity_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

UndergroundCity_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_XANTHOS_UNDERGROUND_7, UndergroundCity_Text_Grunt7Intro, UndergroundCity_Text_Grunt7Defeated
	msgbox UndergroundCity_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
	end

UndergroundCity_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_XANTHOS_UNDERGROUND_8, UndergroundCity_Text_Grunt8Intro, UndergroundCity_Text_Grunt8Defeated
	msgbox UndergroundCity_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

UndergroundCity_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_XANTHOS_UNDERGROUND_9, UndergroundCity_Text_Grunt9Intro, UndergroundCity_Text_Grunt9Defeated
	msgbox UndergroundCity_Text_Grunt9PostBattle, MSGBOX_AUTOCLOSE
	end

UndergroundCity_EventScript_Grunt10::
	trainerbattle_single TRAINER_GRUNT_XANTHOS_UNDERGROUND_10, UndergroundCity_Text_Grunt10Intro, UndergroundCity_Text_Grunt10Defeated
	msgbox UndergroundCity_Text_Grunt10PostBattle, MSGBOX_AUTOCLOSE
	end

UndergroundCity_EventScript_Grunt11::
	trainerbattle_single TRAINER_GRUNT_XANTHOS_UNDERGROUND_11, UndergroundCity_Text_Grunt11Intro, UndergroundCity_Text_Grunt11Defeated
	msgbox UndergroundCity_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
	end

UndergroundCity_EventScript_Grunt12::
	trainerbattle_single TRAINER_GRUNT_XANTHOS_UNDERGROUND_12, UndergroundCity_Text_Grunt12Intro, UndergroundCity_Text_Grunt12Defeated
	msgbox UndergroundCity_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
	end




UndergroundCity_Text_Grunt1Intro:
	.string "What do we have here?\n"
	.string "A straggler all alone?$"

UndergroundCity_Text_Grunt1Defeated:
	.string "Woah, you're no joke!$"

UndergroundCity_Text_Grunt1PostBattle:
	.string "You're good, I'll give you that.\n"
	.string "But the boss is much stronger!$"

UndergroundCity_Text_Grunt2Intro:
	.string "Who's this new meat?$"

UndergroundCity_Text_Grunt2Defeated:
	.string "Urgh...$"

UndergroundCity_Text_Grunt2PostBattle:
	.string "Hehehe, don't worry about your friends.\n"
	.string "We left a little welcoming party for them.$"


UndergroundCity_Text_Grunt3Intro:
	.string "I don't know what this future schmuture\n"
	.string "crap is all about.\p"
	.string "But hey, at least it pays well.$"

UndergroundCity_Text_Grunt3Defeated:
	.string "Ah not the face!$"

UndergroundCity_Text_Grunt3PostBattle:
	.string "I need a new line of work...$"

UndergroundCity_Text_Grunt4Intro:
	.string "Why do I have to be stationed\n"
	.string "in the sewer!?$"

UndergroundCity_Text_Grunt4Defeated:
	.string "This isn't what I signed up for.$"

UndergroundCity_Text_Grunt4PostBattle:
	.string "Those shakes are starting\n"
	.string "to get more violent.\p"
	.string "Maybe this wasn't as safe as\n"
	.string "they told us...$"

UndergroundCity_Text_Grunt5Intro:
	.string "We're all gonna be rich soon!\p"
	.string "Who cares if a few schmucks\n"
	.string "like you have to get hurt!$"

UndergroundCity_Text_Grunt5Defeated:
	.string "Hey wait! You don't have to do this!$"

UndergroundCity_Text_Grunt5PostBattle:
	.string "Ah forget what I just said!$"

UndergroundCity_Text_Grunt6Intro:
	.string "Hey! How'd you get in here?$"

UndergroundCity_Text_Grunt6Defeated:
	.string "Urggh!$"

UndergroundCity_Text_Grunt6PostBattle:
	.string "I just can't catch a break.$"

UndergroundCity_Text_Grunt7Intro:
	.string "Say good night, tree hugger.$"

UndergroundCity_Text_Grunt7Defeated:
	.string "Good night.$"

UndergroundCity_Text_Grunt7PostBattle:
	.string "Hang on, I need a minute...$"

UndergroundCity_Text_Grunt8Intro:
	.string "Hey now, what's the rush?$"

UndergroundCity_Text_Grunt8Defeated:
	.string "Hey, go easy on me.$"

UndergroundCity_Text_Grunt8PostBattle:
	.string "Don't tell the other guys I said this.\p"
	.string "But this whole new world order stuff\n"
	.string "creeps me out.$"

UndergroundCity_Text_Grunt9Intro:
	.string "You shouldn't go snooping around in\n"
	.string "places where you're not welcome.$"

UndergroundCity_Text_Grunt9Defeated:
	.string "That wasn't supposed to happen.$"

UndergroundCity_Text_Grunt9PostBattle:
	.string "Kids like you wouldn't understand\n"
	.string "how important our work is.$"

UndergroundCity_Text_Grunt10Intro:
	.string "Are you lost, little one?$"

UndergroundCity_Text_Grunt10Defeated:
	.string "Oooooh!$"

UndergroundCity_Text_Grunt10PostBattle:
	.string "To be honest, even I get turned\n"
	.string "around in this place.$"

UndergroundCity_Text_Grunt11Intro:
	.string "I'm gonna make you very unhappy.$"

UndergroundCity_Text_Grunt11Defeated:
	.string "Please don't...$"

UndergroundCity_Text_Grunt11PostBattle:
	.string "Why can't you stuck up RANGERS keep\n"
	.string "out of things that don't concern you?$"

UndergroundCity_Text_Grunt12Intro:
	.string "Halt! Intruder spotted!$"

UndergroundCity_Text_Grunt12Defeated:
	.string "Why me?$"

UndergroundCity_Text_Grunt12PostBattle:
	.string "My friend got to go to\n"
	.string "Ultra Space today.\p"
	.string "Why am I stuck guarding an\n"
	.string "empty building?$"












UndergroundCity_EventScript_Grimmod::
	trainerbattle_single TRAINER_GRIMMOD, UndergroundCity_Text_GrimmodIntro, UndergroundCity_Text_GrimmodDefeated
	msgbox UndergroundCity_Text_GrimmodPostBattle, MSGBOX_AUTOCLOSE
	end

UndergroundCity_EventScript_Grimric::
	trainerbattle_single TRAINER_GRIMRIC, UndergroundCity_Text_GrimricIntro, UndergroundCity_Text_GrimricDefeated
	msgbox UndergroundCity_Text_GrimricPostBattle, MSGBOX_AUTOCLOSE
	end

UndergroundCity_EventScript_Grimwald::
	trainerbattle_single TRAINER_GRIMWALD, UndergroundCity_Text_GrimwaldIntro, UndergroundCity_Text_GrimwaldDefeated
	msgbox UndergroundCity_Text_GrimwaldPostBattle, MSGBOX_AUTOCLOSE
	end

UndergroundCity_Text_GrimmodIntro:
	.string "You fools! You don't understand\n"
	.string "the significance of our work!$"

UndergroundCity_Text_GrimmodDefeated:
	.string "Enough!$"

UndergroundCity_Text_GrimmodPostBattle:
	.string "Once the gate is open, mankind\n"
	.string "will live among the stars!\p"
	.string "Do you really want to stop an\n"
	.string "historic moment such as this?$"

UndergroundCity_Text_GrimricIntro:
	.string "TEAM GENESIS has mastered life on Earth.\n"
	.string "Now we shall master life on new worlds!$"

UndergroundCity_Text_GrimricDefeated:
	.string "Indefatigable.$"

UndergroundCity_Text_GrimricPostBattle:
	.string "You may have defeated me.\n"
	.string "But you cannot defeat progress.$"

UndergroundCity_Text_GrimwaldIntro:
	.string "None shall stand in our way!$"

UndergroundCity_Text_GrimwaldDefeated:
	.string "This is absurd!$"

UndergroundCity_Text_GrimwaldPostBattle:
	.string "If we fail today, our successors will\n"
	.string "start again where we left off.\p"
	.string "TEAM GENESIS shall rise from the ashes.\n"
	.string "You're only delaying the inevitable.$"



