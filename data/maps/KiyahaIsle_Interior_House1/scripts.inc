KiyahaIsle_Interior_House1_MapScripts::
	.byte 0



KiyahaIsle_Interior_House1_EventScript_LittleGirl::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_KIYAHA_ISLE_NECTAR, KiyahaIsle_Interior_House1_EventScript_ComeBackTomorrow
	msgbox KiyahaIsle_Interior_House1_Text_TakeThis, MSGBOX_DEFAULT
	special GetRandomInt
	switch VAR_RESULT
	case 0, KiyahaIsle_Interior_House1_EventScript_GiveRedNectar
	case 1, KiyahaIsle_Interior_House1_EventScript_GiveYellowNectar
	case 2, KiyahaIsle_Interior_House1_EventScript_GivePinkNectar
	case 3, KiyahaIsle_Interior_House1_EventScript_GivePurpleNectar
	case 4, KiyahaIsle_Interior_House1_EventScript_GiveRedNectar
	case 5, KiyahaIsle_Interior_House1_EventScript_GiveYellowNectar
	case 6, KiyahaIsle_Interior_House1_EventScript_GivePinkNectar
	case 7, KiyahaIsle_Interior_House1_EventScript_GivePurpleNectar
	case 8, KiyahaIsle_Interior_House1_EventScript_GiveRedNectar
	case 9, KiyahaIsle_Interior_House1_EventScript_GiveYellowNectar
	case 10, KiyahaIsle_Interior_House1_EventScript_GivePinkNectar
	case 11, KiyahaIsle_Interior_House1_EventScript_GivePurpleNectar
	case 12, KiyahaIsle_Interior_House1_EventScript_GiveRedNectar
	case 13, KiyahaIsle_Interior_House1_EventScript_GiveYellowNectar
	case 14, KiyahaIsle_Interior_House1_EventScript_GivePinkNectar
	case 15, KiyahaIsle_Interior_House1_EventScript_GivePurpleNectar
	end

KiyahaIsle_Interior_House1_EventScript_GiveRedNectar::
	giveitem ITEM_RED_NECTAR
	setflag FLAG_DAILY_KIYAHA_ISLE_NECTAR
	release
	end

KiyahaIsle_Interior_House1_EventScript_GiveYellowNectar::
	giveitem ITEM_YELLOW_NECTAR
	setflag FLAG_DAILY_KIYAHA_ISLE_NECTAR
	release
	end

KiyahaIsle_Interior_House1_EventScript_GivePinkNectar::
	giveitem ITEM_PINK_NECTAR
	setflag FLAG_DAILY_KIYAHA_ISLE_NECTAR
	release
	end

KiyahaIsle_Interior_House1_EventScript_GivePurpleNectar::
	giveitem ITEM_PURPLE_NECTAR
	setflag FLAG_DAILY_KIYAHA_ISLE_NECTAR
	release
	end

KiyahaIsle_Interior_House1_EventScript_ComeBackTomorrow::
	msgbox KiyahaIsle_Interior_House1_Text_ComeBackTomorrow, MSGBOX_DEFAULT
	release
	end

KiyahaIsle_Interior_House1_Text_TakeThis:
	.string "Here, take this with you!$"

KiyahaIsle_Interior_House1_Text_ComeBackTomorrow:
	.string "I collect different kinds of\n"
	.string "NECTAR every day.\p"
	.string "Come back tomorrow and I'll\n"
	.string "give you some more!$"




KiyahaIsle_Interior_House1_EventScript_OricorioQuest::
	end
