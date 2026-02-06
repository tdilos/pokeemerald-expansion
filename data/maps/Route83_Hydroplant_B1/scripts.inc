.set LOCALID_FOSSIL_SCIENTIST, 1

Route83_Hydroplant_B1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route83_Hydroplant_B1_OnTransition
	.byte 0

Route83_Hydroplant_B1_OnTransition:
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, Route83_Hydroplant_EventScript_SetFossilReady
	end

Route83_Hydroplant_EventScript_SetFossilReady::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 2
	return

Route83_Hydroplant_EventScript_MeetScientist::
	lock
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox Route83_Hydroplant_Text_DontTellTheOthers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_FaceRight
	waitmovement 0
	setvar VAR_XANTHOS_CITY_STATE, 5
	release
	end


Route83_Hydroplant_EventScript_FossilReviver::
	lock
	faceplayer
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 2, Route83_Hydroplant_EventScript_FossilMonReady
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, Route83_Hydroplant_EventScript_StillRegenerating
	msgbox Route83_Hydroplant_Text_ComeBackWithFossil, MSGBOX_DEFAULT
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route83_Hydroplant_EventScript_NoticeRootFossil
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route83_Hydroplant_EventScript_NoticeHelixFossil

	checkitem ITEM_ARMOR_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route83_Hydroplant_EventScript_NoticeShieldFossil
	checkitem ITEM_JAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route83_Hydroplant_EventScript_NoticeJawFossil
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, Route83_Hydroplant_EventScript_NoticeOldAmber
	checkitem ITEM_XENORESIN
	goto_if_eq VAR_RESULT, TRUE, Route83_Hydroplant_EventScript_NoticeXenoresin

	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_FaceRight
	waitmovement 0
	release
	end

@ This whole section has needless duplication and could be condensed considerably
Route83_Hydroplant_EventScript_NoticeRootFossil::
	closemessage
	playse SE_PIN
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox Route83_Hydroplant_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route83_Hydroplant_EventScript_DeclineGiveFossil
	@checkitem ITEM_HELIX_FOSSIL
	@goto_if_eq VAR_RESULT, TRUE, Route83_Hydroplant_EventScript_ChooseFossil
	goto Route83_Hydroplant_EventScript_GiveRootFossil
	end

Route83_Hydroplant_EventScript_GiveRootFossil::
	bufferitemname STR_VAR_1, ITEM_ROOT_FOSSIL
	msgbox Route83_Hydroplant_Text_HandedFossilToScientist, MSGBOX_DEFAULT
	removeitem ITEM_ROOT_FOSSIL
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 1
	release
	end

Route83_Hydroplant_EventScript_NoticeHelixFossil::
	closemessage
	playse SE_PIN
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox Route83_Hydroplant_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route83_Hydroplant_EventScript_DeclineGiveFossil
	@checkitem ITEM_ROOT_FOSSIL
	@goto_if_eq VAR_RESULT, TRUE, Route83_Hydroplant_EventScript_ChooseFossil
	goto Route83_Hydroplant_EventScript_GiveHelixFossil
	end

Route83_Hydroplant_EventScript_GiveHelixFossil::
	bufferitemname STR_VAR_1, ITEM_HELIX_FOSSIL
	msgbox Route83_Hydroplant_Text_HandedFossilToScientist, MSGBOX_DEFAULT
	removeitem ITEM_HELIX_FOSSIL
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 2
	release
	end



Route83_Hydroplant_EventScript_NoticeShieldFossil::
	closemessage
	playse SE_PIN
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox Route83_Hydroplant_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route83_Hydroplant_EventScript_DeclineGiveFossil
	goto Route83_Hydroplant_EventScript_GiveShieldFossil
	end

Route83_Hydroplant_EventScript_GiveShieldFossil::
	bufferitemname STR_VAR_1, ITEM_ARMOR_FOSSIL
	msgbox Route83_Hydroplant_Text_HandedFossilToScientist, MSGBOX_DEFAULT
	removeitem ITEM_ARMOR_FOSSIL
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 3
	release
	end

Route83_Hydroplant_EventScript_NoticeJawFossil::
	closemessage
	playse SE_PIN
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox Route83_Hydroplant_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route83_Hydroplant_EventScript_DeclineGiveFossil
	goto Route83_Hydroplant_EventScript_GiveJawFossil
	end

Route83_Hydroplant_EventScript_GiveJawFossil::
	bufferitemname STR_VAR_1, ITEM_JAW_FOSSIL
	msgbox Route83_Hydroplant_Text_HandedFossilToScientist, MSGBOX_DEFAULT
	removeitem ITEM_JAW_FOSSIL
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 4
	release
	end

Route83_Hydroplant_EventScript_NoticeOldAmber::
	closemessage
	playse SE_PIN
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox Route83_Hydroplant_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route83_Hydroplant_EventScript_DeclineGiveFossil
	goto Route83_Hydroplant_EventScript_GiveOldAmber
	end

Route83_Hydroplant_EventScript_GiveOldAmber::
	bufferitemname STR_VAR_1, ITEM_OLD_AMBER
	msgbox Route83_Hydroplant_Text_HandedFossilToScientist, MSGBOX_DEFAULT
	removeitem ITEM_OLD_AMBER
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 5
	release
	end

Route83_Hydroplant_EventScript_NoticeXenoresin::
	closemessage
	playse SE_PIN
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox Route83_Hydroplant_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route83_Hydroplant_EventScript_DeclineGiveFossil
	goto Route83_Hydroplant_EventScript_GiveXenoresin
	end

Route83_Hydroplant_EventScript_GiveXenoresin::
	bufferitemname STR_VAR_1, ITEM_XENORESIN
	msgbox Route83_Hydroplant_Text_HandedFossilToScientist, MSGBOX_DEFAULT
	removeitem ITEM_XENORESIN
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 6
	release
	end



Route83_Hydroplant_EventScript_DeclineGiveFossil::
	msgbox Route83_Hydroplant_Text_SafeIPromise, MSGBOX_DEFAULT
	release
	end

Route83_Hydroplant_EventScript_StillRegenerating::
	msgbox Route83_Hydroplant_Text_FossilRegeneratorTakesTime, MSGBOX_DEFAULT
	release
	end

Route83_Hydroplant_EventScript_FossilMonReady::
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 1, Route83_Hydroplant_EventScript_LileepReady
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 2, Route83_Hydroplant_EventScript_OmanyteReady
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 3, Route83_Hydroplant_EventScript_ShieldonReady
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 4, Route83_Hydroplant_EventScript_TyruntReady
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 5, Route83_Hydroplant_EventScript_AerodactylReady
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 6, Route83_Hydroplant_EventScript_OmendenzReady
	end

Route83_Hydroplant_EventScript_LileepReady::
	bufferspeciesname STR_VAR_2, SPECIES_LILEEP
	msgbox Route83_Hydroplant_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto Route83_Hydroplant_EventScript_ReceiveLileep
	end

Route83_Hydroplant_EventScript_OmanyteReady::
	bufferspeciesname STR_VAR_2, SPECIES_OMANYTE
	msgbox Route83_Hydroplant_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto Route83_Hydroplant_EventScript_ReceiveOmanyte
	end


Route83_Hydroplant_EventScript_ShieldonReady::
	bufferspeciesname STR_VAR_2, SPECIES_SHIELDON
	msgbox Route83_Hydroplant_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, SPECIES_SHIELDON
	givemon SPECIES_SHIELDON, 20
	goto Route83_Hydroplant_EventScript_ReceiveFossil
	end

Route83_Hydroplant_EventScript_TyruntReady::
	bufferspeciesname STR_VAR_2, SPECIES_TYRUNT
	msgbox Route83_Hydroplant_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, SPECIES_TYRUNT
	givemon SPECIES_TYRUNT, 20
	goto Route83_Hydroplant_EventScript_ReceiveFossil
	end

Route83_Hydroplant_EventScript_AerodactylReady::
	bufferspeciesname STR_VAR_2, SPECIES_AERODACTYL
	msgbox Route83_Hydroplant_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, SPECIES_AERODACTYL
	givemon SPECIES_AERODACTYL, 30
	goto Route83_Hydroplant_EventScript_ReceiveFossil
	end

Route83_Hydroplant_EventScript_OmendenzReady::
	bufferspeciesname STR_VAR_2, SPECIES_OMENDENZ
	msgbox Route83_Hydroplant_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, SPECIES_OMENDENZ
	givemon SPECIES_OMENDENZ, 30
	goto Route83_Hydroplant_EventScript_ReceiveFossil
	end

Route83_Hydroplant_EventScript_ReceiveFossil::
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route83_Hydroplant_EventScript_ReceiveFossilParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route83_Hydroplant_EventScript_ReceiveFossilPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Route83_Hydroplant_EventScript_ReceiveFossilParty::
	call Route83_Hydroplant_EventScript_ReceivedFossilFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route83_Hydroplant_EventScript_FinishReceivingFossil
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route83_Hydroplant_EventScript_FinishReceivingFossil
	end

Route83_Hydroplant_EventScript_ReceiveFossilPC::
	call Route83_Hydroplant_EventScript_ReceivedFossilFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route83_Hydroplant_EventScript_TransferFossilToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Route83_Hydroplant_EventScript_TransferFossilToPC
	end

Route83_Hydroplant_EventScript_TransferFossilToPC::
	call Common_EventScript_TransferredToPC
	goto Route83_Hydroplant_EventScript_FinishReceivingFossil
	end

Route83_Hydroplant_EventScript_ReceivedFossilFanfare::
	call_if_eq VAR_WHICH_FOSSIL_REVIVED, 3, Route83_Hydroplant_EventScript_ReceivedShieldonFanfare
	call_if_eq VAR_WHICH_FOSSIL_REVIVED, 4, Route83_Hydroplant_EventScript_ReceivedTyruntFanfare
	call_if_eq VAR_WHICH_FOSSIL_REVIVED, 5, Route83_Hydroplant_EventScript_ReceivedAerodactylFanfare
	call_if_eq VAR_WHICH_FOSSIL_REVIVED, 6, Route83_Hydroplant_EventScript_ReceivedOmendenzFanfare
	return

Route83_Hydroplant_EventScript_ReceivedShieldonFanfare:
	bufferspeciesname STR_VAR_2, SPECIES_SHIELDON
	playfanfare MUS_OBTAIN_ITEM
	message Route83_Hydroplant_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_SHIELDON
	return

Route83_Hydroplant_EventScript_ReceivedTyruntFanfare:
	bufferspeciesname STR_VAR_2, SPECIES_TYRUNT
	playfanfare MUS_OBTAIN_ITEM
	message Route83_Hydroplant_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_TYRUNT
	return

Route83_Hydroplant_EventScript_ReceivedAerodactylFanfare:
	bufferspeciesname STR_VAR_2, SPECIES_AERODACTYL
	playfanfare MUS_OBTAIN_ITEM
	message Route83_Hydroplant_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_AERODACTYL
	return

Route83_Hydroplant_EventScript_ReceivedOmendenzFanfare:
	bufferspeciesname STR_VAR_2, SPECIES_OMENDENZ
	playfanfare MUS_OBTAIN_ITEM
	message Route83_Hydroplant_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_OMENDENZ
	return

Route83_Hydroplant_EventScript_FinishReceivingFossil::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end







Route83_Hydroplant_EventScript_ReceiveLileep::
	setvar VAR_TEMP_1, SPECIES_LILEEP
	givemon SPECIES_LILEEP, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route83_Hydroplant_EventScript_ReceiveLileepParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route83_Hydroplant_EventScript_ReceiveLileepPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Route83_Hydroplant_EventScript_ReceiveLileepParty::
	call Route83_Hydroplant_EventScript_ReceivedLileepFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route83_Hydroplant_EventScript_FinishReceivingLileep
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route83_Hydroplant_EventScript_FinishReceivingLileep
	end

Route83_Hydroplant_EventScript_ReceiveLileepPC::
	call Route83_Hydroplant_EventScript_ReceivedLileepFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route83_Hydroplant_EventScript_TransferLileepToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Route83_Hydroplant_EventScript_TransferLileepToPC
	end

Route83_Hydroplant_EventScript_TransferLileepToPC::
	call Common_EventScript_TransferredToPC
	goto Route83_Hydroplant_EventScript_FinishReceivingLileep
	end

Route83_Hydroplant_EventScript_ReceivedLileepFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_LILEEP
	playfanfare MUS_OBTAIN_ITEM
	message Route83_Hydroplant_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_LILEEP
	return

Route83_Hydroplant_EventScript_FinishReceivingLileep::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end

Route83_Hydroplant_EventScript_ReceiveOmanyte::
	setvar VAR_TEMP_1, SPECIES_OMANYTE
	givemon SPECIES_OMANYTE, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route83_Hydroplant_EventScript_ReceiveOmanyteParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route83_Hydroplant_EventScript_ReceiveOmanytePC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Route83_Hydroplant_EventScript_ReceiveOmanyteParty::
	call Route83_Hydroplant_EventScript_ReceivedOmanyteFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route83_Hydroplant_EventScript_FinishReceivingOmanyte
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route83_Hydroplant_EventScript_FinishReceivingOmanyte
	end

Route83_Hydroplant_EventScript_ReceiveOmanytePC::
	call Route83_Hydroplant_EventScript_ReceivedOmanyteFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route83_Hydroplant_EventScript_TransferOmanyteToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Route83_Hydroplant_EventScript_TransferOmanyteToPC
	end

Route83_Hydroplant_EventScript_TransferOmanyteToPC::
	call Common_EventScript_TransferredToPC
	goto Route83_Hydroplant_EventScript_FinishReceivingOmanyte
	end

Route83_Hydroplant_EventScript_ReceivedOmanyteFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_OMANYTE
	playfanfare MUS_OBTAIN_ITEM
	message Route83_Hydroplant_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_OMANYTE
	return

Route83_Hydroplant_EventScript_FinishReceivingOmanyte::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end

Route83_Hydroplant_EventScript_ChooseFossil::
	message Route83_Hydroplant_Text_TwoFossilsPickOne
	waitmessage
	multichoice 17, 6, MULTI_FOSSIL, FALSE
	switch VAR_RESULT
	case 0, Route83_Hydroplant_EventScript_ChooseHelixFossil
	case 1, Route83_Hydroplant_EventScript_ChooseRootFossil
	case 2, Route83_Hydroplant_EventScript_CancelFossilSelect
	case MULTI_B_PRESSED, Route83_Hydroplant_EventScript_CancelFossilSelect
	end

Route83_Hydroplant_EventScript_ChooseHelixFossil::
	goto Route83_Hydroplant_EventScript_GiveHelixFossil
	end

Route83_Hydroplant_EventScript_ChooseRootFossil::
	goto Route83_Hydroplant_EventScript_GiveRootFossil
	end

Route83_Hydroplant_EventScript_CancelFossilSelect::
	release
	end

Route83_Hydroplant_Text_DontTellTheOthers:
	.string "Oh dear…\p"
	.string "You mustn't tell the others what\n"
	.string "I'm doing down here.\p"
	.string "I promise I'm not taking power\n"
	.string "from the city!\p"
	.string "Well, not much anyway…\p"
	.string "This machine I've made here will\n"
	.string "revive POKéMON from fossils.\p"
	.string "I can resurrect as many fossils\n"
	.string "as you'd like!\p"
	.string "Just keep it between the two of us…$"

Route83_Hydroplant_Text_ComeBackWithFossil:
	.string "Come back once you have fossils to te-,\n"
	.string "err, use this on.$"

Route83_Hydroplant_Text_WantToBringFossilBackToLife:
	.string "Wait! That thing you have there…\n"
	.string "Is that a POKéMON fossil?\p"
	.string "Would you like to bring that POKéMON\n"
	.string "back to life?$"

Route83_Hydroplant_Text_SafeIPromise:
	.string "Really? It's quite safe, I promise.$"

Route83_Hydroplant_Text_TwoFossilsPickOne:
	.string "Oh, now that's a surprise!\n"
	.string "You have not one, but two, fossils?\p"
	.string "Unfortunately, my machine can only\n"
	.string "regenerate one POKéMON at a time.\p"
	.string "Would you like to pick one of your\n"
	.string "fossils for regeneration?$"

Route83_Hydroplant_Text_HandedFossilToScientist:
	.string "Excellent!\n"
	.string "Let's do this right away.\p"
	.string "{PLAYER} handed the {STR_VAR_1} to\n"
	.string "the SCIENTIST.$"

Route83_Hydroplant_Text_FossilRegeneratorTakesTime:
	.string "The FOSSIL REGENERATOR, which I made,\n"
	.string "is incredible.\p"
	.string "But it has one drawback--it takes\n"
	.string "a long time to work.\p"
	.string "So, uh… How about you go for a stroll\n"
	.string "and look around for a while?$"

Route83_Hydroplant_Text_FossilizedMonBroughtBackToLife:
	.string "Ah, you're just in time.\p"
	.string "Your fossilized POKéMON has been\n"
	.string "brought back to life!\p"
	.string "The fossil was an ancient POKéMON.\n"
	.string "{STR_VAR_2}, it was!$"

Route83_Hydroplant_Text_ReceivedMonFromResearcher:
	.string "{PLAYER} received {STR_VAR_2} from\n"
	.string "the SCIENTIST.$"

Route83_Hydroplant_Text_DevelopDeviceToResurrectFossils:
	.string "$"

