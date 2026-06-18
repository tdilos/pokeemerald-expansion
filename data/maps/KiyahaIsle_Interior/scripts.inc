KiyahaIsle_Interior_MapScripts::
	.byte 0



KiyahaIsle_Interior_EventScript_LittleGirl1::
	lock
	faceplayer
	msgbox KiyahaIsle_Interior_Text_LittleGirl1, MSGBOX_DEFAULT
	closemessage
	release
	end

KiyahaIsle_Interior_Text_LittleGirl1:
	.string "My sand castle moved! Did you\n"
	.string "see where it went?$"



@ Each sand castle flag has a random chance to reset each day

KiyahaIsle_Interior_EventScript_SandCastle1::
	lockall
	call_if_unset FLAG_DAILY_KIYAHA_ISLE_SAND_CASTLE_1, KiyahaIsle_Interior_EventScript_SandygastEncounter
	setflag FLAG_DAILY_KIYAHA_ISLE_SAND_CASTLE_1
	releaseall
	end

KiyahaIsle_Interior_EventScript_SandCastle2::
	lockall
	call_if_unset FLAG_DAILY_KIYAHA_ISLE_SAND_CASTLE_2, KiyahaIsle_Interior_EventScript_SandygastEncounter
	setflag FLAG_DAILY_KIYAHA_ISLE_SAND_CASTLE_2
	releaseall
	end

KiyahaIsle_Interior_EventScript_SandCastle3::
	lockall
	call_if_unset FLAG_DAILY_KIYAHA_ISLE_SAND_CASTLE_3, KiyahaIsle_Interior_EventScript_SandygastEncounter
	setflag FLAG_DAILY_KIYAHA_ISLE_SAND_CASTLE_3
	releaseall
	end

KiyahaIsle_Interior_EventScript_SandCastle4::
	lockall
	call_if_unset FLAG_DAILY_KIYAHA_ISLE_SAND_CASTLE_4, KiyahaIsle_Interior_EventScript_SandygastEncounter
	setflag FLAG_DAILY_KIYAHA_ISLE_SAND_CASTLE_4
	releaseall
	end

KiyahaIsle_Interior_EventScript_SandCastle5::
	lockall
	call_if_unset FLAG_DAILY_KIYAHA_ISLE_SAND_CASTLE_5, KiyahaIsle_Interior_EventScript_SandygastEncounter
	setflag FLAG_DAILY_KIYAHA_ISLE_SAND_CASTLE_5
	releaseall
	end

KiyahaIsle_Interior_EventScript_SandygastEncounter:
	playmoncry SPECIES_SANDYGAST, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_SANDYGAST, 10
	dowildbattle
	return


