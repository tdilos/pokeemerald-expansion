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

KiyahaIsle_Interior_EventScript_LittleGirl2::
	lock
	msgbox KiyahaIsle_Interior_Text_LittleGirl2, MSGBOX_DEFAULT
	closemessage
	release
	end

KiyahaIsle_Interior_Text_LittleGirl2:
	.string "Sit still, sand castle!$"

KiyahaIsle_Interior_EventScript_Youngster::
	lock
	faceplayer
	msgbox KiyahaIsle_Interior_Text_AncestorsBuiltAShrine, MSGBOX_DEFAULT
	closemessage
	release
	end

KiyahaIsle_Interior_Text_AncestorsBuiltAShrine:
	.string "There's a shrine on the other side\n"
	.string "of the lagoon.\p"
	.string "Our ancestors built it there to honor\n"
	.string "the ISLAND GUARDIAN.\p"
	.string "The elders say that the GUARDIANS have\n"
	.string "protected these islands for generations.\p"
	.string "But no one's seen them since the\n"
	.string "SEA DEMON attacked.$"

KiyahaIsle_Interior_EventScript_OldMan::
	lock
	faceplayer
	msgbox KiyahaIsle_Interior_Text_OldMan, MSGBOX_DEFAULT
	closemessage
	release
	end

KiyahaIsle_Interior_Text_OldMan:
	@.string "You defeated the wicked sea god\n"
	@.string "and brought the guardians back.\p"
	.string "For years, we have lived in harmony\n"
	.string "with the ISLAND GUARDIANS.\p"
	.string "But everything changed the day we were\n"
	.string "attacked by a monster from the sea.\p"
	.string "The SEA DEMON and the GUARDIANS fought\n"
	.string "in a great battle for five long days.\p"
	.string "The GUARDIANS managed to repel the\n"
	.string "SEA DEMON and imprison it underwater.\p"
	.string "But our victory came at great cost.\p"
	.string "And no one knows what became of\n"
	.string "the GUARDIANS.\p"
	.string "Some say they are still out there\n"
	.string "somewhere.\p"
	.string "Fighting to protect these islands\n"
	.string "even now.\p"
	.string "But it's been many years since anyone\n"
	.string "has seen them.\p"
	.string "And some people are beginning to lose hope.$"



KiyahaIsle_Interior_EventScript_Woman::
	lock
	faceplayer
	msgbox KiyahaIsle_Interior_Text_Woman, MSGBOX_DEFAULT
	closemessage
	release
	end

KiyahaIsle_Interior_Text_Woman:
	.string "Legends tell of great heroes in the past\n"
	.string "who earned the respect of the GUARDIANS\l"
	.string "and fought alongside them.\p"
	.string "If only we had a hero to bring\n"
	.string "the GUARDIANS back...$"
	







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


