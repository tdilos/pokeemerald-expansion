Spring_ShireTowne_Building1_1F_MapScripts::
	.byte 0


ShireTowne_Building1_1F_EventScript_OldMaid::
	lock
	faceplayer
	msgbox ShireTowne_Building1_1F_Text_StrangeGuests, MSGBOX_DEFAULT
	release
	end

ShireTowne_Building1_1F_Text_StrangeGuests:
	.string "Hmmm? What's this?\n"
	.string "Another strangely dressed guest.$"


ShireTowne_Building1_1F_EventScript_ShalourSableGuy::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox ShireTowne_Building1_1F_Text_ShalourSableJust200, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ShireTowne_Building1_1F_EventScript_DeclineShalourSable
	checkmoney 200
	goto_if_eq VAR_RESULT, FALSE, ShireTowne_Building1_1F_EventScript_NotEnoughMoney
	msgbox ShireTowne_Building1_1F_Text_ThankYouDear, MSGBOX_DEFAULT
	checkitemspace ITEM_SHALOUR_SABLE
	call_if_eq VAR_RESULT, TRUE, ShireTowne_Building1_1F_EventScript_RemoveMoney
.if OW_SHOW_ITEM_DESCRIPTIONS == OW_ITEM_DESCRIPTIONS_OFF
	giveitem ITEM_SHALOUR_SABLE
	goto_if_eq VAR_RESULT, FALSE, ShireTowne_Building1_1F_EventScript_BagIsFull
	hidemoneybox
	release
	end

ShireTowne_Building1_1F_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end
.else
	hidemoneybox
	giveitem ITEM_SHALOUR_SABLE
	goto_if_eq VAR_RESULT, FALSE, ShireTowne_Building1_1F_EventScript_BagIsFull
	release
	end

ShireTowne_Building1_1F_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	release
	end
.endif @ OW_SHOW_ITEM_DESCRIPTIONS


ShireTowne_Building1_1F_EventScript_RemoveMoney::
	removemoney 200
	updatemoneybox
	return

ShireTowne_Building1_1F_EventScript_DeclineShalourSable::
	msgbox ShireTowne_Building1_1F_Text_OhFineThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

ShireTowne_Building1_1F_EventScript_NotEnoughMoney::
	msgbox ShireTowne_Building1_1F_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

ShireTowne_Building1_1F_Text_ShalourSableJust200:
	.string "Greetings traveler. Would you like\n"
	.string "a SHALOUR SABLE for the road?\p"
	.string "It's a local speciality.\n"
	.string "Just ¥200.$"

ShireTowne_Building1_1F_Text_ThankYouDear:
	.string "Here you are. A slice of the\n"
	.string "finest shortbread in the valley.$"

ShireTowne_Building1_1F_Text_YouveNotGotTheMoney:
	.string "Hmm, what's this?\n"
	.string "You've got no money!$"

ShireTowne_Building1_1F_Text_OhFineThen:
	.string "Safe journies, traveler.$"

