Route88_SecretHouse_MapScripts::
	.byte 0


Route88_SecretHouse_EventScript_EggMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_EEVEE_ROUTE88, Route88_SecretHouse_EventScript_PostEggComment
	@goto_if_set FLAG_NO_ROOM_FOR_EEVEE_EGG, Route88_SecretHouse_EventScript_ReturnForEgg
	msgbox Route88_SecretHouse_Text_FirstVisitor
	goto Route88_SecretHouse_EventScript_TryGiveEgg
	end

Route88_SecretHouse_EventScript_TryGiveEgg::
	getpartysize
	@addvar VAR_RESULT, 1
	@copyvar VAR_0x8004, VAR_RESULT
	goto_if_eq VAR_RESULT, PARTY_SIZE, Route88_SecretHouse_EventScript_NoRoomForEgg
	addvar VAR_RESULT, 1
	@setvar VAR_0x8004, VAR_RESULT
	@setvar VAR_0x8004, 5
	@giveegg SPECIES_EEVEE
	givemon SPECIES_EEVEE, 20, ITEM_SOOTHE_BELL
	setmonability VAR_RESULT, 2
	playfanfare MUS_LEVEL_UP
	message Route88_SecretHouse_Text_ReceivedEeveeFromMan
	waitmessage
	waitfanfare
	@setflag FLAG_GOT_EEVEE_EGG
	setflag FLAG_GOT_EEVEE_ROUTE88
	delay 60
	@goto Route88_SecretHouse_EventScript_PostEggComment
	release
	end

Route88_SecretHouse_EventScript_PostEggComment::
	msgbox Route88_SecretHouse_Text_RaiseItWell
	release
	end

Route88_SecretHouse_EventScript_NoRoomForEgg::
	@setflag FLAG_NO_ROOM_FOR_EEVEE_EGG
	msgbox Route88_SecretHouse_Text_DontHaveSpaceInYourParty
	release
	end

@Route88_SecretHouse_EventScript_ReturnForEgg::
@	goto Route88_SecretHouse_EventScript_TryGiveEgg
@	end

Route88_SecretHouse_Text_FirstVisitor::
    .string "Woah, you're the first visitor I've had\n"
    .string "in a long time.\p"
    .string "So you're a POKéMON trainer, huh?\p"
    .string "In that case, I'd like you to take\n"
    .string "this special POKéMON with you.$"

Route88_SecretHouse_Text_ReceivedEeveeFromMan::
    .string "{PLAYER} received a POKéMON\n"
    .string "from the man!$"

Route88_SecretHouse_Text_DontHaveSpaceInYourParty::
    .string "...\p"
    .string "Uh-oh. It looks like you don't have\n"
    .string "space for it in your party.\p"
    .string "That's too bad...$"
    @.string "You'd better come back for it\n"
    @.string "another time.$"

Route88_SecretHouse_Text_RaiseItWell::
    .string "You seem like a capable trainer.\n"
    .string "I'm sure you'll raise that POKéMON well.$"
