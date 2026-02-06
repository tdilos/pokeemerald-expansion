PitchblakCity_Plaza_MapScripts::
	.byte 0

PitchblakCity_Plaza_EventScript_Greeter::
	msgbox PitchblakCity_Plaza_Text_Welcome, MSGBOX_NPC
	end

PitchblakCity_Plaza_Text_Welcome:
	.string "Welcome to PITCHBLAK CITY PLAZA.$"

PitchblakCity_Plaza_EventScript_Man::
	lock
	faceplayer
	msgbox PitchblakCity_Plaza_Text_KendomaSponsors, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Plaza_Text_KendomaSponsors:
	.string "This plaza was funded in part by our\n"
	.string "sponsors from KENDOM CORP.\p"
	.string "It wouldn't be here today without\n"
	.string "their generous endowments.$"
	@.string "It's very generous of them to give\n"
	@.string "back to the city like this.$"

PitchblakCity_Plaza_EventScript_Scientist::
	lock
	faceplayer
	msgbox PitchblakCity_Plaza_Text_KnowAboutEVsIVs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PitchblakCity_Plaza_EventScript_LearnMore
	goto_if_eq VAR_RESULT, NO, PitchblakCity_Plaza_EventScript_ExplainEVsIVs
	end

PitchblakCity_Plaza_EventScript_ExplainEVsIVs::
	msgbox PitchblakCity_Plaza_Text_ExplainEVsIVs, MSGBOX_DEFAULT
	goto PitchblakCity_Plaza_EventScript_LearnMore
	end

PitchblakCity_Plaza_EventScript_LearnMore::
	msgbox PitchblakCity_Plaza_Text_LearnMore, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Plaza_Text_KnowAboutEVsIVs:
	.string "Do you know about EVs and IVs?$"

PitchblakCity_Plaza_Text_ExplainEVsIVs:
	.string "EV is an abbreviation for effort value.\p"
	.string "They are the metric by which we quantify\n"
	.string "how well-trained a POKéMON is.\p"
	.string "The more EVs a POKéMON has for a given\n"
	.string "stat, the higher that stat will be.\p"
	.string "EVs can be increased via training\n"
	.string "or other artificial means.\p"
	.string "But not without limit, you see.\p"
	.string "An individual stat cannot be trained\n"
	.string "beyond the threshhold of 255 EVs.\p"
	.string "And an individual POKéMON can only have a\n"
	.string "maximum of 510 EVs in total.\p"
	.string "This is the nature of EVs.\p"
	.string "IVs, on the other hand, are\n"
	.string "individual values.\p"
	.string "They quantify a POKéMON's innate\n"
	.string "potential, ranging between 0 and 31.\p"
	.string "Each of a POKéMON's stats is a function\n"
	.string "of its IVs, just as with EVs.\p"
	.string "But unlike EVs, IVs are immeliorable.\p"
	.string "They are determined by the POKéMON's\n"
	.string "genetics and remain constant\l"
	.string "throughout its life.$"
	
PitchblakCity_Plaza_Text_LearnMore:
	.string "If you wish to learn more, speak to our\n"
	.string "colleagues on the third floor.$"

PitchblakCity_Plaza_EventScript_Reporter::
	lock
	faceplayer
	msgbox PitchblakCity_Plaza_Text_CityOfProgress, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Plaza_Text_CityOfProgress:
	.string "In PITCHBLAK CITY, we're always on the\n"
	.string "cutting edge of technology and progress!$"

PitchblakCity_Plaza_EventScript_Policeman::
	msgbox PitchblakCity_Plaza_Text_RestrictedAccess, MSGBOX_NPC
	end

PitchblakCity_Plaza_Text_RestrictedAccess:
	.string "I'm sorry, this elevator is\n"
	.string "restricted access only.$"








PitchblakCity_Plaza_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart PitchblakCity_Plaza_Pokemart1
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PitchblakCity_Plaza_Pokemart1:
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_SP_DEF
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_ABILITY_CAPSULE
	.2byte ITEM_ABILITY_PATCH 
	.2byte ITEM_NONE
	release
	end











PitchblakCity_Plaza_EventScript_NatureChangerPlaceholder::
	lock
	faceplayer
	msgbox PitchblakCity_Plaza_Text_NotAvailableYet, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Plaza_Text_NotAvailableYet:
	.string "Our services are currently unavailable.\n"
	.string "Please check back later.$"

PitchblakCity_Plaza_EventScript_NatureChanger::
	lock
	faceplayer
	msgbox PitchblakCity_Plaza_Text_LikeMeToChangeNature, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PitchblakCity_Plaza_EventScript_DeclineChangeNature
	msgbox PitchblakCity_Plaza_Text_ChangeWhichOne, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	@lock
	@faceplayer
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_ge VAR_0x8004, PARTY_SIZE, PitchblakCity_Plaza_EventScript_DeclineChangeNature
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, PitchblakCity_Plaza_EventScript_CantChangeEgg
	goto PitchblakCity_Plaza_EventScript_ChooseNature
	end

PitchblakCity_Plaza_EventScript_CantChangeEgg::
	msgbox PitchblakCity_Plaza_Text_CantChangeAnEgg, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Plaza_EventScript_DeclineChangeNature::
	msgbox PitchblakCity_Plaza_Text_DontNeedNatureChange, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Plaza_Text_LikeMeToChangeNature:
    .string "Hello, I'm a psychiatrist.\p"
    .string "I can do cognitive therapy on your\n"
    .string "POKéMON to change its nature.\p"
    @.string "It's quite safe, I assure you.\p"
    .string "And it's only just ¥10000.\p"
    .string "Would you like me to treat one\n"
    .string "of your POKéMON?$"

PitchblakCity_Plaza_Text_DontNeedNatureChange:
    .string "Oh, really?\n"
    .string "It's quite safe, I assure you.$"

PitchblakCity_Plaza_Text_ChangeWhichOne:
    .string "Which one should I treat?$"

PitchblakCity_Plaza_Text_WhatNewNature:
    .string "And what shall its new nature be?$"

PitchblakCity_Plaza_Text_LookingNiceInNoTime:
    .string "Alright, let me see your POKéMON.\n"
    .string "This will take just a few minutes.$"

PitchblakCity_Plaza_Text_ThereYouGoAllDone:
    .string "There we are! All done.\p"
    .string "Another POKéMON successfully\n"
    .string "rehabilitated!\p"
    .string "{STR_VAR_1} looks like it doesn't\n"
    .string "recognize you at all.$"

PitchblakCity_Plaza_Text_CantChangeAnEgg:
    .string "Hmmm. I'm afraid I can treat\n"
    .string "a POKéMON inside an EGG.$"







@PitchblakCity_Plaza_EventScript_NatureChanger::
@	lock
@	faceplayer
@	msgbox PitchblakCity_Plaza_Text_ImAPsychiatrist, MSGBOX_DEFAULT
@	goto PitchblakCity_Plaza_EventScript_ChooseNature
@	end

PitchblakCity_Plaza_EventScript_ChooseNature::
	message PitchblakCity_Plaza_Text_WhatNewNature
	waitmessage
	scrollingmultichoice 13, 2, 0, 6, TRUE
	switch VAR_RESULT
	case 0, PitchblakCity_Plaza_EventScript_Hardy
	case 1, PitchblakCity_Plaza_EventScript_Lonely
	case 2, PitchblakCity_Plaza_EventScript_Brave
	case 3, PitchblakCity_Plaza_EventScript_Adamant
	case 4, PitchblakCity_Plaza_EventScript_Naughty
	case 5, PitchblakCity_Plaza_EventScript_Bold
	case 6, PitchblakCity_Plaza_EventScript_Docile
	case 7, PitchblakCity_Plaza_EventScript_Relaxed
	case 8, PitchblakCity_Plaza_EventScript_Impish
	case 9, PitchblakCity_Plaza_EventScript_Lax
	case 10, PitchblakCity_Plaza_EventScript_Timid
	case 11, PitchblakCity_Plaza_EventScript_Hasty
	case 12, PitchblakCity_Plaza_EventScript_Serious
	case 13, PitchblakCity_Plaza_EventScript_Jolly
	case 14, PitchblakCity_Plaza_EventScript_Naive
	case 15, PitchblakCity_Plaza_EventScript_Modest
	case 16, PitchblakCity_Plaza_EventScript_Mild
	case 17, PitchblakCity_Plaza_EventScript_Quiet
	case 18, PitchblakCity_Plaza_EventScript_Bashful
	case 19, PitchblakCity_Plaza_EventScript_Rash
	case 20, PitchblakCity_Plaza_EventScript_Calm
	case 21, PitchblakCity_Plaza_EventScript_Gentle
	case 22, PitchblakCity_Plaza_EventScript_Sassy
	case 23, PitchblakCity_Plaza_EventScript_Careful
	case 24, PitchblakCity_Plaza_EventScript_Quirky
	case 25, PitchblakCity_Plaza_EventScript_CancelNatureChange
	case MULTI_B_PRESSED, PitchblakCity_Plaza_EventScript_CancelNatureChange
	end

PitchblakCity_Plaza_EventScript_Hardy::
	setvar VAR_0x8005, NATURE_HARDY
	goto PitchblakCity_Plaza_EventScript_ConfirmNatureSelection
	end

PitchblakCity_Plaza_EventScript_Lonely::
	setvar VAR_0x8005, NATURE_LONELY
	goto PitchblakCity_Plaza_EventScript_ConfirmNatureSelection
	end

PitchblakCity_Plaza_EventScript_Brave::
	setvar VAR_0x8005, NATURE_BRAVE
	goto PitchblakCity_Plaza_EventScript_ConfirmNatureSelection
	end

PitchblakCity_Plaza_EventScript_Adamant::
	setvar VAR_0x8005, NATURE_ADAMANT
	goto PitchblakCity_Plaza_EventScript_ConfirmNatureSelection
	end

PitchblakCity_Plaza_EventScript_Naughty::
	setvar VAR_0x8005, NATURE_NAUGHTY
	goto PitchblakCity_Plaza_EventScript_ConfirmNatureSelection
	end

PitchblakCity_Plaza_EventScript_Bold::
	setvar VAR_0x8005, NATURE_BOLD
	goto PitchblakCity_Plaza_EventScript_ConfirmNatureSelection
	end

PitchblakCity_Plaza_EventScript_Docile::
	setvar VAR_0x8005, NATURE_DOCILE
	goto PitchblakCity_Plaza_EventScript_ConfirmNatureSelection
	end

PitchblakCity_Plaza_EventScript_Relaxed::
	setvar VAR_0x8005, NATURE_RELAXED
	goto PitchblakCity_Plaza_EventScript_ConfirmNatureSelection
	end

PitchblakCity_Plaza_EventScript_Impish::
	setvar VAR_0x8005, NATURE_IMPISH
	goto PitchblakCity_Plaza_EventScript_ConfirmNatureSelection
	end

PitchblakCity_Plaza_EventScript_Lax::
	setvar VAR_0x8005, NATURE_LAX
	goto PitchblakCity_Plaza_EventScript_ConfirmNatureSelection
	end

PitchblakCity_Plaza_EventScript_Timid::
	setvar VAR_0x8005, NATURE_TIMID
	goto PitchblakCity_Plaza_EventScript_ConfirmNatureSelection
	end

PitchblakCity_Plaza_EventScript_Hasty::
	setvar VAR_0x8005, NATURE_HASTY
	goto PitchblakCity_Plaza_EventScript_ConfirmNatureSelection
	end

PitchblakCity_Plaza_EventScript_Serious::
	setvar VAR_0x8005, NATURE_SERIOUS
	goto PitchblakCity_Plaza_EventScript_ConfirmNatureSelection
	end

PitchblakCity_Plaza_EventScript_Jolly::
	setvar VAR_0x8005, NATURE_JOLLY
	goto PitchblakCity_Plaza_EventScript_ConfirmNatureSelection
	end

PitchblakCity_Plaza_EventScript_Naive::
	setvar VAR_0x8005, NATURE_NAIVE
	goto PitchblakCity_Plaza_EventScript_ConfirmNatureSelection
	end

PitchblakCity_Plaza_EventScript_Modest::
	setvar VAR_0x8005, NATURE_MODEST
	goto PitchblakCity_Plaza_EventScript_ConfirmNatureSelection
	end

PitchblakCity_Plaza_EventScript_Mild::
	setvar VAR_0x8005, NATURE_MILD
	goto PitchblakCity_Plaza_EventScript_ConfirmNatureSelection
	end

PitchblakCity_Plaza_EventScript_Quiet::
	setvar VAR_0x8005, NATURE_QUIET
	goto PitchblakCity_Plaza_EventScript_ConfirmNatureSelection
	end

PitchblakCity_Plaza_EventScript_Bashful::
	setvar VAR_0x8005, NATURE_BASHFUL
	goto PitchblakCity_Plaza_EventScript_ConfirmNatureSelection
	end

PitchblakCity_Plaza_EventScript_Rash::
	setvar VAR_0x8005, NATURE_RASH
	goto PitchblakCity_Plaza_EventScript_ConfirmNatureSelection
	end

PitchblakCity_Plaza_EventScript_Calm::
	setvar VAR_0x8005, NATURE_CALM
	goto PitchblakCity_Plaza_EventScript_ConfirmNatureSelection
	end

PitchblakCity_Plaza_EventScript_Gentle::
	setvar VAR_0x8005, NATURE_GENTLE
	goto PitchblakCity_Plaza_EventScript_ConfirmNatureSelection
	end

PitchblakCity_Plaza_EventScript_Sassy::
	setvar VAR_0x8005, NATURE_SASSY
	goto PitchblakCity_Plaza_EventScript_ConfirmNatureSelection
	end

PitchblakCity_Plaza_EventScript_Careful::
	setvar VAR_0x8005, NATURE_CAREFUL
	goto PitchblakCity_Plaza_EventScript_ConfirmNatureSelection
	end

PitchblakCity_Plaza_EventScript_Quirky::
	setvar VAR_0x8005, NATURE_QUIRKY
	goto PitchblakCity_Plaza_EventScript_ConfirmNatureSelection
	end

@ VAR_0x8004 is the party member to be changed
@ VAR_0x8005 is the new nature
PitchblakCity_Plaza_EventScript_ConfirmNatureSelection::
	@msgbox PitchblakCity_Plaza_Text_NatureChangeConfirm, MSGBOX_YESNO
	@goto_if_eq VAR_RESULT, NO, PitchblakCity_Plaza_EventScript_ChooseNature
	checkmoney 10000
	goto_if_eq VAR_RESULT, TRUE, PitchblakCity_Plaza_EventScript_ChangeNature
	msgbox PitchblakCity_Plaza_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto PitchblakCity_Plaza_EventScript_CancelNatureChange
	end

PitchblakCity_Plaza_EventScript_ChangeNature::
	copyvar VAR_0x8004, VAR_0x800A
	msgbox PitchblakCity_Plaza_Text_LookingNiceInNoTime, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	special ChangePartyMonNature
	delay 60
	playse SE_USE_ITEM
	waitse
	fadescreen FADE_FROM_BLACK
	removemoney 10000
	special BufferMonNickname
	msgbox PitchblakCity_Plaza_Text_ThereYouGoAllDone, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Plaza_EventScript_CancelNatureChange::
	msgbox PitchblakCity_Plaza_Text_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Plaza_Text_NotEnoughMoney:
    .string "Oh? It appears you don't have\n"
    .string "enough money.$"

PitchblakCity_Plaza_Text_PleaseComeAgain:
	.string "I hope you'll consider my services\n"
	.string "some other time.$"















PitchblakCity_Plaza_EventScript_EVChecker::
	lock
	faceplayer
	msgbox PitchblakCity_Plaza_Text_MachineThatChecksEVs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PitchblakCity_Plaza_EventScript_CheckEVs
	goto_if_eq VAR_RESULT, NO, PitchblakCity_Plaza_EventScript_RefuseCheck
	end

PitchblakCity_Plaza_Text_MachineThatChecksEVs:
	.string "Hello. I'm working on a new prototype.\n"
	.string "A device that reads your POKéMON's EVs.\p"
	.string "You're a trainer, yes? Would you like\n"
	.string "me to try it on your POKéMON?$"

PitchblakCity_Plaza_EventScript_CheckEVs::
	bufferpartymonnick 0, 0
	msgbox PitchblakCity_Plaza_Text_HoldStill, MSGBOX_DEFAULT
	playse SE_DEX_SEARCH
	waitse
	msgbox PitchblakCity_Plaza_Text_EVChecker_1, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetHpEV
	buffernumberstring 0, VAR_RESULT
	specialvar VAR_RESULT, GetAtkEV
	buffernumberstring 1, VAR_RESULT
	specialvar VAR_RESULT, GetDefEV
	buffernumberstring 2, VAR_RESULT
	msgbox PitchblakCity_Plaza_Text_EVChecker_2, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetSpAtkEV
	buffernumberstring 0, VAR_RESULT
	specialvar VAR_RESULT, GetSpDefEV
	buffernumberstring 1, VAR_RESULT
	specialvar VAR_RESULT, GetSpeedEV
	buffernumberstring 2, VAR_RESULT
	msgbox PitchblakCity_Plaza_Text_EVChecker_3, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Plaza_Text_HoldStill:
	.string "Excellent. Now hold your {STR_VAR_1} still\n"
	.string "for me. This will only take a few seconds.$"
	
PitchblakCity_Plaza_Text_EVChecker_1:
	.string "Hmmm, yes. Your {STR_VAR_1}...$"

PitchblakCity_Plaza_Text_EVChecker_2:
	.string "Its HP EV is {STR_VAR_1}.\p"
	.string "Its Attack EV is {STR_VAR_2}.\p"
	.string "Its Defense EV is {STR_VAR_3}.$"

PitchblakCity_Plaza_Text_EVChecker_3:
	.string "Its Special Attack EV is {STR_VAR_1}.\p"
	.string "Its Special Defense EV is {STR_VAR_2}.\p"
	.string "Its Speed EV is {STR_VAR_3}.\p"
	.string "I'd be more than happy to try it on\n"
	.string "another POKéMON, if you'd like.$"




PitchblakCity_Plaza_EventScript_RefuseCheck::
	msgbox PitchblakCity_Plaza_Text_QuiteSafe, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Plaza_Text_QuiteSafe:
	.string "Really? It's quite safe, I assure you.$"


PitchblakCity_Plaza_EventScript_IVChecker::
	lock
	faceplayer
	msgbox PitchblakCity_Plaza_Text_MachineThatChecksIVs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PitchblakCity_Plaza_EventScript_CheckIVs
	goto_if_eq VAR_RESULT, NO, PitchblakCity_Plaza_EventScript_RefuseCheck
	end

PitchblakCity_Plaza_Text_MachineThatChecksIVs:
	.string "Hello. I'm working on a new prototype.\n"
	.string "A device that reads your POKéMON's IVs.\p"
	.string "You're a trainer, yes? Would you like\n"
	.string "me to try it on your POKéMON?$"

PitchblakCity_Plaza_EventScript_CheckIVs::
	bufferpartymonnick 0, 0
	msgbox PitchblakCity_Plaza_Text_HoldStill, MSGBOX_DEFAULT
	playse SE_DEX_SEARCH
	waitse
	msgbox PitchblakCity_Plaza_Text_IVChecker_1, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetHpIV
	buffernumberstring 0, VAR_RESULT
	specialvar VAR_RESULT, GetAtkIV
	buffernumberstring 1, VAR_RESULT
	specialvar VAR_RESULT, GetDefIV
	buffernumberstring 2, VAR_RESULT
	msgbox PitchblakCity_Plaza_Text_IVChecker_2, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetSpAtkIV
	buffernumberstring 0, VAR_RESULT
	specialvar VAR_RESULT, GetSpDefIV
	buffernumberstring 1, VAR_RESULT
	specialvar VAR_RESULT, GetSpeedIV
	buffernumberstring 2, VAR_RESULT
	msgbox PitchblakCity_Plaza_Text_IVChecker_3, MSGBOX_DEFAULT
	release
	end
	
PitchblakCity_Plaza_Text_IVChecker_1:
	.string "Hmmm, yes. Your {STR_VAR_1}...$"

PitchblakCity_Plaza_Text_IVChecker_2:
	.string "Its HP IV is {STR_VAR_1}.\p"
	.string "Its Attack IV is {STR_VAR_2}.\p"
	.string "Its Defense IV is {STR_VAR_3}.$"

PitchblakCity_Plaza_Text_IVChecker_3:
	.string "Its Special Attack IV is {STR_VAR_1}.\p"
	.string "Its Special Defense IV is {STR_VAR_2}.\p"
	.string "Its Speed IV is {STR_VAR_3}.\p"
	.string "I'd be more than happy to try it on\n"
	.string "another POKéMON, if you'd like.$"
