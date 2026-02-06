DunTown_Motel_2F_MapScripts::
	.byte 0

DunTown_Motel_2F_EventScript_Pokemon::
	lock
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	applymovement VAR_LAST_TALKED, DunTown_Motel_2F_Movement_KecleonAppears
	waitmovement 0
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
	msgbox DunTown_Motel_2F_Text_Pokemon, MSGBOX_DEFAULT
	waitmoncry
	applymovement VAR_LAST_TALKED, DunTown_Motel_2F_Movement_KecleonDisappears
	waitmovement 0
	release
	end

DunTown_Motel_2F_Text_Pokemon:
	.string "KEC KEC KEC!$"

DunTown_Motel_2F_EventScript_Tdilos::
	lock
	faceplayer
	msgbox DunTown_Motel_2F_Text_Tdilos, MSGBOX_DEFAULT
	goto_if_unset FLAG_RECEIVED_CATCHING_CHARM, DunTown_Motel_2F_EventScript_GiveCharm
	release
	end

DunTown_Motel_2F_EventScript_GiveCharm::
	giveitem ITEM_CATCHING_CHARM
	setflag FLAG_RECEIVED_CATCHING_CHARM
	release
	end

DunTown_Motel_2F_Text_Tdilos:
	.string "Hi, I'm TDILOS.\n"
	.string "Hope you're enjoying the game.\p"
	.string "It might get tough out there,\n"
	.string "but don't give up.\p"
	.string "Become unshakable!$"

DunTown_Motel_2F_Movement_KecleonAppears:
	set_visible
	delay_4
	set_invisible
	delay_4
	set_visible
	delay_4
	set_invisible
	delay_4
	set_visible
	@delay_8
	@set_invisible
	@delay_8
	@set_visible
	@delay_8
	@set_invisible
	@delay_8
	@set_visible
	@delay_16
	@set_invisible
	@delay_16
	@set_visible
	step_end

DunTown_Motel_2F_Movement_KecleonDisappears:
	set_invisible
	delay_4
	set_visible
	delay_4
	set_invisible
	delay_4
	set_visible
	delay_4
	set_invisible
	@delay_8
	@set_visible
	@delay_8
	@set_invisible
	@delay_8
	@set_visible
	@delay_8
	@set_invisible
	@delay_16
	@set_visible
	@delay_16
	@set_invisible
	step_end




