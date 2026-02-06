.set LOCALID_DEOXYS_BALL, 1

Route65_SecretHouse_MapScripts::
	.byte 0

Route65_SecretHouse_EventScript_DeoxysPokeball::
	lockall
	msgbox Route65_SecretHouse_Text_DeoxysLetter, MSGBOX_DEFAULT
	msgbox Route65_SecretHouse_Text_TakeBallContainingDeoxys, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route65_SecretHouse_EventScript_LeaveDeoxys
	goto Route65_SecretHouse_EventScript_GiveDeoxys
	end

Route65_SecretHouse_EventScript_LeaveDeoxys::
	msgbox Route65_SecretHouse_Text_LeftPokeBallWhereItWas, MSGBOX_DEFAULT
	releaseall
	end

Route65_SecretHouse_EventScript_GiveDeoxys::
	setvar VAR_TEMP_1, SPECIES_DEOXYS
	givemon SPECIES_DEOXYS, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route65_SecretHouse_EventScript_SendDeoxysParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route65_SecretHouse_EventScript_SendDeoxysPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Route65_SecretHouse_EventScript_SendDeoxysParty::
	call Route65_SecretHouse_EventScript_ReceivedDeoxysFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route65_SecretHouse_EventScript_ReceivedDeoxys
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route65_SecretHouse_EventScript_ReceivedDeoxys
	end

Route65_SecretHouse_EventScript_SendDeoxysPC::
	call Route65_SecretHouse_EventScript_ReceivedDeoxysFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route65_SecretHouse_EventScript_DeoxysTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Route65_SecretHouse_EventScript_DeoxysTransferredToPC
	end

Route65_SecretHouse_EventScript_DeoxysTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto Route65_SecretHouse_EventScript_ReceivedDeoxys
	end

Route65_SecretHouse_EventScript_ReceivedDeoxysFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_DEOXYS
	removeobject LOCALID_DEOXYS_BALL
	playfanfare MUS_OBTAIN_ITEM
	message Route65_SecretHouse_Text_ObtainedDeoxys
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_DEOXYS
	return

Route65_SecretHouse_EventScript_ReceivedDeoxys::
	setflag FLAG_RECEIVED_DEOXYS
	releaseall
	end

Route65_SecretHouse_Text_DeoxysLetter:
	.string "Until we meet again some day,\n"
	.string "somewhere beyond the horizon.\p"
	.string "--DR BETTERMAN$"

Route65_SecretHouse_Text_TakeBallContainingDeoxys:
	.string "Take the POKé BALL?$"

Route65_SecretHouse_Text_ObtainedDeoxys:
	.string "{PLAYER} obtained a DEOXYS.$"

Route65_SecretHouse_Text_LeftPokeBallWhereItWas:
	.string "{PLAYER} left the POKé BALL where\n"
	.string "it was.$"



