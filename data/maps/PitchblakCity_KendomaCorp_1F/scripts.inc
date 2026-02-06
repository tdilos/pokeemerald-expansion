PitchblakCity_KendomaCorp_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PitchblakCity_KendomaCorp_1F_OnTransition
	.byte 0

PitchblakCity_KendomaCorp_1F_OnTransition:
	call_if_eq VAR_PITCHBLAK_CITY_STATE, 1, PitchblakCity_KendomaCorp_1F_EventScript_HidePolice
	call_if_eq VAR_PITCHBLAK_CITY_STATE, 2, PitchblakCity_KendomaCorp_1F_EventScript_AfterNedaBattle
	special GetDifficulty
	goto_if_eq VAR_RESULT, 0, PitchblakCity_KendomaCorp_1F_EventScript_RevealBurglar
	setflag FLAG_HIDE_SHORTCUT_NPCS
	end

PitchblakCity_KendomaCorp_1F_EventScript_RevealBurglar::
	clearflag FLAG_HIDE_SHORTCUT_NPCS
	end

PitchblakCity_KendomaCorp_1F_EventScript_HidePolice::
	setflag FLAG_HIDE_PITCHBLAK_COPS
	return

PitchblakCity_KendomaCorp_1F_EventScript_AfterNedaBattle::
	clearflag FLAG_HIDE_PITCHBLAK_COPS
	return




PitchblakCity_KendomaCorp_1F_EventScript_Burglar::
	lock
	faceplayer
	message PitchblakCity_KendomaCorp_1F_Text_BurglarIntro
	waitmessage
	showmoneybox 0, 0
	scrollingmultichoice 20, 16, 0, 4, TRUE
	switch VAR_RESULT
	case 0, PitchblakCity_KendomaCorp_1F_EventScript_BuyCardA
	case 1, PitchblakCity_KendomaCorp_1F_EventScript_BuyCardB
	case 2, PitchblakCity_KendomaCorp_1F_EventScript_CancelBuy
	case MULTI_B_PRESSED, PitchblakCity_KendomaCorp_1F_EventScript_CancelBuy
	end

PitchblakCity_KendomaCorp_1F_EventScript_BuyCardA::
	checkmoney 9999
	goto_if_eq VAR_RESULT, FALSE, PitchblakCity_KendomaCorp_1F_EventScript_NotEnoughMoney
	checkitemspace ITEM_CLEARANCE_A_CARD
	goto_if_eq VAR_RESULT, FALSE, PitchblakCity_KendomaCorp_1F_EventScript_NoRoomInBag
	playse SE_SHOP
	removemoney 9999
	additem ITEM_CLEARANCE_A_CARD
	updatemoneybox
	msgbox PitchblakCity_KendomaCorp_1F_Text_PutCardInBag, MSGBOX_DEFAULT
	hidemoneybox
	goto PitchblakCity_KendomaCorp_1F_EventScript_EndBuy
	end

PitchblakCity_KendomaCorp_1F_EventScript_BuyCardB::
	checkmoney 9999
	goto_if_eq VAR_RESULT, FALSE, PitchblakCity_KendomaCorp_1F_EventScript_NotEnoughMoney
	checkitemspace ITEM_CLEARANCE_B_CARD
	goto_if_eq VAR_RESULT, FALSE, PitchblakCity_KendomaCorp_1F_EventScript_NoRoomInBag
	playse SE_SHOP
	removemoney 9999
	additem ITEM_CLEARANCE_B_CARD
	updatemoneybox
	msgbox PitchblakCity_KendomaCorp_1F_Text_PutCardInBag, MSGBOX_DEFAULT
	hidemoneybox
	goto PitchblakCity_KendomaCorp_1F_EventScript_EndBuy
	end

PitchblakCity_KendomaCorp_1F_EventScript_NoRoomInBag::
	msgbox PitchblakCity_KendomaCorp_1F_Text_NoRoomInBag, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

PitchblakCity_KendomaCorp_1F_EventScript_NotEnoughMoney::
	msgbox PitchblakCity_KendomaCorp_1F_Text_NotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

PitchblakCity_KendomaCorp_1F_EventScript_CancelBuy::
	msgbox PitchblakCity_KendomaCorp_1F_Text_BurglarOutro, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

PitchblakCity_KendomaCorp_1F_EventScript_EndBuy::
	msgbox PitchblakCity_KendomaCorp_1F_Text_BurglarOutro, MSGBOX_DEFAULT
	release
	end

PitchblakCity_KendomaCorp_1F_Text_BurglarIntro:
	.string "Looking for a shortcut, my dear?\p"
	.string "Perhaps these might interest you.\n"
	.string "They weren't easy to find, you know.\p"
	.string "And only ¥9999 each.$"

PitchblakCity_KendomaCorp_1F_Text_NoRoomInBag:
	.string "But your bag is full, my dear.$"

PitchblakCity_KendomaCorp_1F_Text_NotEnoughMoney:
	.string "You're short on money.\n"
	.string "What do I look like a charity?$"

PitchblakCity_KendomaCorp_1F_Text_PutCardInBag:
	.string "{PLAYER} put the card in the bag.$"

PitchblakCity_KendomaCorp_1F_Text_BurglarOutro:
	.string "Pleasure doing business with you,\n"
	.string "my dear.$" 






PitchblakCity_KendomaCorp_1F_EventScript_Investigator::
	msgbox PitchblakCity_KendomaCorp_1F_Text_CrimeScene, MSGBOX_NPC
	end

PitchblakCity_KendomaCorp_1F_Text_CrimeScene:
	.string "This is a crime scene.\n"
	.string "Please stay back.$"

PitchblakCity_KendomaCorp_1F_EventScript_Pokemon::
	lock
	faceplayer
	playmoncry SPECIES_GROWLITHE, CRY_MODE_NORMAL
	msgbox PitchblakCity_KendomaCorp_1F_Text_Pokemon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

PitchblakCity_KendomaCorp_1F_Text_Pokemon:
	.string "GROWLITHE: Garr garrr!$"












PitchblakCity_KendomaCorp_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_KENDOMA_CORP_3, PitchblakCity_KendomaCorp_Text_GruntKendomaCorp3Intro, PitchblakCity_KendomaCorp_Text_GruntKendomaCorp3Defeated
	msgbox PitchblakCity_KendomaCorp_Text_GruntKendomaCorp3PostBattle, MSGBOX_AUTOCLOSE
	end

PitchblakCity_KendomaCorp_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_KENDOMA_CORP_4, PitchblakCity_KendomaCorp_Text_GruntKendomaCorp4Intro, PitchblakCity_KendomaCorp_Text_GruntKendomaCorp4Defeated
	msgbox PitchblakCity_KendomaCorp_Text_GruntKendomaCorp4PostBattle, MSGBOX_AUTOCLOSE
	end

PitchblakCity_KendomaCorp_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_KENDOMA_CORP_5, PitchblakCity_KendomaCorp_Text_GruntKendomaCorp5Intro, PitchblakCity_KendomaCorp_Text_GruntKendomaCorp5Defeated
	msgbox PitchblakCity_KendomaCorp_Text_GruntKendomaCorp5PostBattle, MSGBOX_AUTOCLOSE
	end

PitchblakCity_KendomaCorp_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_KENDOMA_CORP_6, PitchblakCity_KendomaCorp_Text_GruntKendomaCorp6Intro, PitchblakCity_KendomaCorp_Text_GruntKendomaCorp6Defeated
	msgbox PitchblakCity_KendomaCorp_Text_GruntKendomaCorp6PostBattle, MSGBOX_AUTOCLOSE
	end

PitchblakCity_KendomaCorp_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_KENDOMA_CORP_7, PitchblakCity_KendomaCorp_Text_GruntKendomaCorp7Intro, PitchblakCity_KendomaCorp_Text_GruntKendomaCorp7Defeated
	msgbox PitchblakCity_KendomaCorp_Text_GruntKendomaCorp7PostBattle, MSGBOX_AUTOCLOSE
	end

PitchblakCity_KendomaCorp_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_KENDOMA_CORP_8, PitchblakCity_KendomaCorp_Text_GruntKendomaCorp8Intro, PitchblakCity_KendomaCorp_Text_GruntKendomaCorp8Defeated
	msgbox PitchblakCity_KendomaCorp_Text_GruntKendomaCorp8PostBattle, MSGBOX_AUTOCLOSE
	end

PitchblakCity_KendomaCorp_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_KENDOMA_CORP_9, PitchblakCity_KendomaCorp_Text_GruntKendomaCorp9Intro, PitchblakCity_KendomaCorp_Text_GruntKendomaCorp9Defeated
	msgbox PitchblakCity_KendomaCorp_Text_GruntKendomaCorp9PostBattle, MSGBOX_AUTOCLOSE
	end

PitchblakCity_KendomaCorp_EventScript_Grunt10::
	trainerbattle_single TRAINER_GRUNT_KENDOMA_CORP_10, PitchblakCity_KendomaCorp_Text_GruntKendomaCorp10Intro, PitchblakCity_KendomaCorp_Text_GruntKendomaCorp10Defeated
	msgbox PitchblakCity_KendomaCorp_Text_GruntKendomaCorp10PostBattle, MSGBOX_AUTOCLOSE
	end

PitchblakCity_KendomaCorp_Text_GruntKendomaCorp3Intro:
	.string "I am one of the five GENESIS SISTERS.$"

PitchblakCity_KendomaCorp_Text_GruntKendomaCorp3Defeated:
	.string "Sisters! Avenge me!$"

PitchblakCity_KendomaCorp_Text_GruntKendomaCorp3PostBattle:
	.string "Not bad. But unfortunately for you, I am\n"
	.string "only the third strongest GENESIS SISTER.$"

PitchblakCity_KendomaCorp_Text_GruntKendomaCorp4Intro:
	.string "I am one of the five GENESIS SISTERS.$"

PitchblakCity_KendomaCorp_Text_GruntKendomaCorp4Defeated:
	.string "GENESIS SISTERS... We lost...$"

PitchblakCity_KendomaCorp_Text_GruntKendomaCorp4PostBattle:
	.string "Of the other GENESIS SISTERS, two are\n"
	.string "even stronger than me!$"

PitchblakCity_KendomaCorp_Text_GruntKendomaCorp5Intro:
	.string "I am one of the five GENESIS SISTERS.$"

PitchblakCity_KendomaCorp_Text_GruntKendomaCorp5Defeated:
	.string "You think you've won.\p"
	.string "But we've only just begun.$"

PitchblakCity_KendomaCorp_Text_GruntKendomaCorp5PostBattle:
	.string "My two older sisters will destroy you.\p"
	.string "You will regret meddling in our affairs!$"

PitchblakCity_KendomaCorp_Text_GruntKendomaCorp6Intro:
	.string "I am one of the five GENESIS SISTERS.$"

PitchblakCity_KendomaCorp_Text_GruntKendomaCorp6Defeated:
	.string "Do as you will, for I have already won.$"

PitchblakCity_KendomaCorp_Text_GruntKendomaCorp6PostBattle:
	.string "My sisters will finish you off.\p"
	.string "There are five of us altogether, but\n"
	.string "only two are weaker than me.$"

PitchblakCity_KendomaCorp_Text_GruntKendomaCorp7Intro:
	.string "I am one of the five GENESIS SISTERS.$"

PitchblakCity_KendomaCorp_Text_GruntKendomaCorp7Defeated:
	.string "Sisters...$"

PitchblakCity_KendomaCorp_Text_GruntKendomaCorp7PostBattle:
	.string "The oldest sister is the strongest,\n"
	.string "and the youngest is the weakest.\p"
	.string "As for me, I'm just the middle child.$"

PitchblakCity_KendomaCorp_Text_GruntKendomaCorp8Intro:
	.string "Have you seen any key cards?$"

PitchblakCity_KendomaCorp_Text_GruntKendomaCorp8Defeated:
	.string "Woah! Chill out!$"

PitchblakCity_KendomaCorp_Text_GruntKendomaCorp8PostBattle:
	.string "The security doors will open if you\n"
	.string "use a special key card.\p"
	.string "Too bad I haven't found one yet.$"

PitchblakCity_KendomaCorp_Text_GruntKendomaCorp9Intro:
	.string "Do as the commander says,\n"
	.string "or lose your very self!$"

PitchblakCity_KendomaCorp_Text_GruntKendomaCorp9Defeated:
	.string "It's over.$"

PitchblakCity_KendomaCorp_Text_GruntKendomaCorp9PostBattle:
	.string "What good is life without victory?$"

PitchblakCity_KendomaCorp_Text_GruntKendomaCorp10Intro:
	.string "Hey! What's a kid like you doing here?$"

PitchblakCity_KendomaCorp_Text_GruntKendomaCorp10Defeated:
	.string "I must be seeing things.$"

PitchblakCity_KendomaCorp_Text_GruntKendomaCorp10PostBattle:
	.string "You're not one of those serials these\n"
	.string "crazy scientists have been working on,\l"
	.string "are ya?$"




PitchblakCity_KendomaCorp_EventScript_Godard::
	trainerbattle_single TRAINER_GODARD, PitchblakCity_KendomaCorp_Text_GodardIntro, PitchblakCity_KendomaCorp_Text_GodardDefeated
	msgbox PitchblakCity_KendomaCorp_Text_GodardPostBattle, MSGBOX_AUTOCLOSE
	end

PitchblakCity_KendomaCorp_EventScript_Godfrey::
	trainerbattle_single TRAINER_GODFREY, PitchblakCity_KendomaCorp_Text_GodfreyIntro, PitchblakCity_KendomaCorp_Text_GodfreyDefeated
	msgbox PitchblakCity_KendomaCorp_Text_GodfreyPostBattle, MSGBOX_AUTOCLOSE
	end

PitchblakCity_KendomaCorp_EventScript_Godwin::
	trainerbattle_single TRAINER_GODWIN, PitchblakCity_KendomaCorp_Text_GodwinIntro, PitchblakCity_KendomaCorp_Text_GodwinDefeated
	msgbox PitchblakCity_KendomaCorp_Text_GodwinPostBattle, MSGBOX_AUTOCLOSE
	end

PitchblakCity_KendomaCorp_EventScript_Osborn::
	trainerbattle_single TRAINER_OSBORN, PitchblakCity_KendomaCorp_Text_OsbornIntro, PitchblakCity_KendomaCorp_Text_OsbornDefeated
	msgbox PitchblakCity_KendomaCorp_Text_OsbornPostBattle, MSGBOX_AUTOCLOSE
	end

PitchblakCity_KendomaCorp_EventScript_Oswald::
	trainerbattle_single TRAINER_OSWALD, PitchblakCity_KendomaCorp_Text_OswaldIntro, PitchblakCity_KendomaCorp_Text_OswaldDefeated
	msgbox PitchblakCity_KendomaCorp_Text_OswaldPostBattle, MSGBOX_AUTOCLOSE
	end

PitchblakCity_KendomaCorp_EventScript_Ishmael::
	trainerbattle_single TRAINER_ISHMAEL, PitchblakCity_KendomaCorp_Text_IshmaelIntro, PitchblakCity_KendomaCorp_Text_IshmaelDefeated
	msgbox PitchblakCity_KendomaCorp_Text_IshmaelPostBattle, MSGBOX_AUTOCLOSE
	end

PitchblakCity_KendomaCorp_Text_GodardIntro:
	.string "You couldn't possibly understand what\n"
	.string "TEAM GENESIS hopes to achieve!$"

PitchblakCity_KendomaCorp_Text_GodardDefeated:
	.string "Inconceivable!$"

PitchblakCity_KendomaCorp_Text_GodardPostBattle:
	.string "Our work here will continue in ways\n"
	.string "that those suits could never fathom!$" 

PitchblakCity_KendomaCorp_Text_GodwinIntro:
	.string "Fufufu. Let's run a little experiment.$"

PitchblakCity_KendomaCorp_Text_GodwinDefeated:
	.string "Interesting.$"

PitchblakCity_KendomaCorp_Text_GodwinPostBattle:
	.string "Our clones aren't perfect yet.\n"
	.string "But one day, they'll be superior\l"
	.string "to normal POKéMON in every way!$"

PitchblakCity_KendomaCorp_Text_GodfreyIntro:
	.string "The power of science is limitless!\p"
	.string "Soon, every POKéMON will be under\n"
	.string "our control.$"

PitchblakCity_KendomaCorp_Text_GodfreyDefeated:
	.string "Astounding!$"

PitchblakCity_KendomaCorp_Text_GodfreyPostBattle:
	.string "Some people worship POKéMON as gods.\n"
	.string "Mere superstition of course.\p"
	.string "After all, POKéMON are just\n"
	.string "lifeforms like humans.\p"
	.string "All life can be understood\n"
	.string "and mastered through science.$"

PitchblakCity_KendomaCorp_Text_OsbornIntro:
	.string "It's time to take the next step.$"

PitchblakCity_KendomaCorp_Text_OsbornDefeated:
	.string "The next stage of evolution.$"

PitchblakCity_KendomaCorp_Text_OsbornPostBattle:
	.string "As a species, we're stuck in a sort\n"
	.string "of adoloscent phase.\p"
	.string "Man is something that must be overcome.$"

PitchblakCity_KendomaCorp_Text_OswaldIntro:
	.string "This company is squandering\n"
	.string "our potential.\p"
	.string "I'm defecting to TEAM GENESIS!$"

PitchblakCity_KendomaCorp_Text_OswaldDefeated:
	.string "I've been had!$"

PitchblakCity_KendomaCorp_Text_OswaldPostBattle:
	.string "All those suits ever think of\n"
	.string "is money.\p"
	.string "Can't they see the impact this\n"
	.string "will have on the world itself?$"

PitchblakCity_KendomaCorp_Text_IshmaelIntro:
	.string "Behold the power of science!$"

PitchblakCity_KendomaCorp_Text_IshmaelDefeated:
	.string "By Darwin's beard!$"

PitchblakCity_KendomaCorp_Text_IshmaelPostBattle:
	.string "Evolution is the ultimate power.\p"
	.string "With our work, we'll be able to unlock the\n"
	.string "genetic potential of not just POKéMON\l"
	.string "but humans as well!$"



