.set LOCALID_LOTTERY_CLERK, 2

MindaroCity_DepartmentStore_1F_MapScripts::
	.byte 0

MindaroCity_DepartmentStore_1F_EventScript_FloorNamesSign::
	msgbox MindaroCity_DepartmentStore_1F_Text_FloorNamesSign, MSGBOX_SIGN
	end

MindaroCity_DepartmentStore_1F_Text_FloorNamesSign:
	.string "1F: SERVICE COUNTER\n"
	.string "    LOTTERY CORNER\p"
	.string "2F: TRAINER'S MARKET\p"
	.string "3F: JEWELRY STORE\p"
	.string "4F: DRUG STORE\p"
	.string "5F: MAILROOM\p"
	.string "ROOFTOP: ROOFTOP PLAZA$"




MindaroCity_EventScript_CheckDifficulty::
	lock
	faceplayer
	msgbox MindaroCity_Text_Difficulty, MSGBOX_DEFAULT
	closemessage
	special GetDifficulty
	switch VAR_RESULT
	case 0, MindaroCity_EventScript_NormalDifficulty
	case 1, MindaroCity_EventScript_HardcoreDifficulty
	case 2, MindaroCity_EventScript_InsaneDifficulty
	end

MindaroCity_EventScript_NormalDifficulty::
	msgbox MindaroCity_Text_NormalDifficulty, MSGBOX_DEFAULT
	closemessage
	release
	end

MindaroCity_EventScript_HardcoreDifficulty::
	msgbox MindaroCity_Text_HardcoreDifficulty, MSGBOX_DEFAULT
	closemessage
	release
	end

MindaroCity_EventScript_InsaneDifficulty::
	msgbox MindaroCity_Text_InsaneDifficulty, MSGBOX_DEFAULT
	closemessage
	release
	end

MindaroCity_Text_Difficulty:
	.string "This is a test.$"

MindaroCity_Text_NormalDifficulty:
	.string "The current difficulty is NORMAL.$"

MindaroCity_Text_HardcoreDifficulty:
	.string "The current difficulty is HARDCORE.$"

MindaroCity_Text_InsaneDifficulty:
	.string "The current difficulty is INSANE.$"




MindaroCity_DepartmentStore_1F_EventScript_Woman::
	lock
	faceplayer
	msgbox MindaroCity_DepartmentStore_1F_Text_ExcitedShopper, MSGBOX_DEFAULT
	release
	end

MindaroCity_DepartmentStore_1F_Text_ExcitedShopper::
	.string "There are so many things on sale!\n"
	.string "I wish I could buy them all!$"




MindaroCity_DepartmentStore_1F_EventScript_EggLady::
	lockall
	faceplayer
	goto_if_set FLAG_GOT_LARVESTA_EGG, MindaroCity_DepartmentStore_1F_EventScript_PostEggComment
	msgbox MindaroCity_DepartmentStore_1F_Text_PleaseTakeThisEgg, MSGBOX_NPC
	goto MindaroCity_DepartmentStore_1F_EventScript_TryGiveEgg
	end

MindaroCity_DepartmentStore_1F_EventScript_TryGiveEgg::
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, MindaroCity_DepartmentStore_1F_EventScript_NoRoomForEgg
	setflag FLAG_GOT_LARVESTA_EGG
	giveegg SPECIES_LARVESTA
	playfanfare MUS_LEVEL_UP
	message MindaroCity_DepartmentStore_1F_Text_ReceivedEggFromOldWoman
	waitfanfare
	waitmessage
	release
	end

MindaroCity_DepartmentStore_1F_EventScript_PostEggComment::
	msgbox MindaroCity_DepartmentStore_1F_Text_ReceivedEggWhile, MSGBOX_NPC
	release
	end

MindaroCity_DepartmentStore_1F_EventScript_NoRoomForEgg::
	msgbox MindaroCity_DepartmentStore_1F_Text_DontHaveSpaceInYourParty, MSGBOX_NPC
	release
	end

MindaroCity_DepartmentStore_1F_Text_PleaseTakeThisEgg::
    .string "Please, young trainer, look after\n"
    .string "this egg for me.$"

MindaroCity_DepartmentStore_1F_Text_ReceivedEggFromOldWoman::
    .string "{PLAYER} received an EGG\n"
    .string "from the old woman!$"

MindaroCity_DepartmentStore_1F_Text_DontHaveSpaceInYourParty::
    .string "Oh dear, your party is full.\n"
    .string "Whatever am I going to do…$"

MindaroCity_DepartmentStore_1F_Text_ReceivedEggWhile::
    .string "That egg's trainer came back for\n"
    .string "its parents but didn't want it.\p"
    .string "How horrible abandoning a child\n"
    .string "before it's even born!$"










MindaroCity_DepartmentStore_1F_EventScript_Greeter::
	msgbox MindaroCity_DepartmentStore_1F_Text_WelcomeToDeptStore, MSGBOX_NPC
	end

MindaroCity_DepartmentStore_1F_Text_WelcomeToDeptStore:
	.string "Welcome to MINDARO DEPARTMENT STORE.$"

MindaroCity_DepartmentStore_1F_EventScript_LotteryClerk::
	lock
	faceplayer
	dotimebasedevents
	goto_if_ne VAR_POKELOT_PRIZE_ITEM, ITEM_NONE, MindaroCity_DepartmentStore_1F_EventScript_GivePrizeFromEarlier
	goto_if_set FLAG_DAILY_PICKED_LOTO_TICKET, MindaroCity_DepartmentStore_1F_EventScript_ComeBackTomorrow
	msgbox LilycoveCity_DepartmentStore_1F_Text_LotteryCornerDrawTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MindaroCity_DepartmentStore_1F_EventScript_PleaseVisitAgain
	setflag FLAG_DAILY_PICKED_LOTO_TICKET
	message LilycoveCity_DepartmentStore_1F_Text_PleasePickTicket
	waitmessage
	special RetrieveLotteryNumber
	copyvar VAR_0x8008, VAR_RESULT
	special BufferLottoTicketNumber
	msgbox LilycoveCity_DepartmentStore_1F_Text_TicketNumberIsXPleaseWait, MSGBOX_DEFAULT
	applymovement LOCALID_LOTTERY_CLERK, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	playse SE_PC_ON
	special DoLotteryCornerComputerEffect
	special PickLotteryCornerTicket
	delay 220
	special EndLotteryCornerComputerEffect
	delay 10
	applymovement LOCALID_LOTTERY_CLERK, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_0x8004, 0, MindaroCity_DepartmentStore_1F_EventScript_NoMatch
	incrementgamestat GAME_STAT_WON_POKEMON_LOTTERY
	call_if_eq VAR_0x8006, 0, MindaroCity_DepartmentStore_1F_EventScript_TicketMatchPartyMon
	call_if_eq VAR_0x8006, 1, MindaroCity_DepartmentStore_1F_EventScript_TicketMatchPCMon
	bufferitemname STR_VAR_1, VAR_0x8005
	call_if_eq VAR_0x8004, 1, MindaroCity_DepartmentStore_1F_EventScript_TwoDigitMatch
	call_if_eq VAR_0x8004, 2, MindaroCity_DepartmentStore_1F_EventScript_ThreeDigitMatch
	call_if_eq VAR_0x8004, 3, MindaroCity_DepartmentStore_1F_EventScript_FourDigitMatch
	call_if_eq VAR_0x8004, 4, MindaroCity_DepartmentStore_1F_EventScript_FullMatch
	giveitem VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, MindaroCity_DepartmentStore_1F_EventScript_RecordPrizeNoRoom
	special TryPutLotteryWinnerReportOnAir
	goto MindaroCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2
	end

MindaroCity_DepartmentStore_1F_EventScript_TicketMatchPartyMon::
	msgbox LilycoveCity_DepartmentStore_1F_Text_TicketMatchesPartyMon, MSGBOX_DEFAULT
	return

MindaroCity_DepartmentStore_1F_EventScript_TicketMatchPCMon::
	msgbox LilycoveCity_DepartmentStore_1F_Text_TicketMatchesPCMon, MSGBOX_DEFAULT
	return

MindaroCity_DepartmentStore_1F_EventScript_ComeBackTomorrow::
	msgbox LilycoveCity_DepartmentStore_1F_Text_ComeBackTomorrow, MSGBOX_DEFAULT
	release
	end

MindaroCity_DepartmentStore_1F_EventScript_PleaseVisitAgain::
	msgbox LilycoveCity_DepartmentStore_1F_Text_PleaseVisitAgain, MSGBOX_DEFAULT
	release
	end

MindaroCity_DepartmentStore_1F_EventScript_NoMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_NoNumbersMatched, MSGBOX_DEFAULT
	goto MindaroCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2
	end

MindaroCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2::
	msgbox LilycoveCity_DepartmentStore_1F_Text_PleaseVisitAgain2, MSGBOX_DEFAULT
	release
	end

MindaroCity_DepartmentStore_1F_EventScript_TwoDigitMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_TwoDigitsMatched, MSGBOX_DEFAULT
	return

MindaroCity_DepartmentStore_1F_EventScript_ThreeDigitMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_ThreeDigitsMatched, MSGBOX_DEFAULT
	return

MindaroCity_DepartmentStore_1F_EventScript_FourDigitMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_FourDigitsMatched, MSGBOX_DEFAULT
	return

MindaroCity_DepartmentStore_1F_EventScript_FullMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_AllFiveDigitsMatched, MSGBOX_DEFAULT
	return

MindaroCity_DepartmentStore_1F_EventScript_RecordPrizeNoRoom::
	copyvar VAR_POKELOT_PRIZE_PLACE, VAR_0x8004
	copyvar VAR_POKELOT_PRIZE_ITEM, VAR_0x8005
	goto MindaroCity_DepartmentStore_1F_EventScript_NoRoomForPrize
	end

MindaroCity_DepartmentStore_1F_EventScript_NoRoomForPrize::
	msgbox LilycoveCity_DepartmentStore_1F_Text_NoRoomForThis, MSGBOX_DEFAULT
	release
	end

MindaroCity_DepartmentStore_1F_EventScript_GivePrizeFromEarlier::
	msgbox LilycoveCity_DepartmentStore_1F_Text_PrizeWeveBeenHolding, MSGBOX_DEFAULT
	giveitem VAR_POKELOT_PRIZE_ITEM
	goto_if_eq VAR_RESULT, FALSE, MindaroCity_DepartmentStore_1F_EventScript_NoRoomForPrize
	copyvar VAR_0x8004, VAR_POKELOT_PRIZE_PLACE
	copyvar VAR_0x8005, VAR_POKELOT_PRIZE_ITEM
	special TryPutLotteryWinnerReportOnAir
	setvar VAR_POKELOT_PRIZE_ITEM, ITEM_NONE
	setvar VAR_POKELOT_PRIZE_PLACE, 0
	release
	end

