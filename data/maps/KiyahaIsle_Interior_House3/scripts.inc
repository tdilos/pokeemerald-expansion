KiyahaIsle_Interior_House3_MapScripts::
	.byte 0

KiyahaIsle_Interior_House3_EventScript_BigMalasadaLady::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox KiyahaIsle_Interior_House3_Text_BigMalasadaJust200, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, KiyahaIsle_Interior_House3_EventScript_DeclineBigMalasada
	checkmoney 200
	goto_if_eq VAR_RESULT, FALSE, KiyahaIsle_Interior_House3_EventScript_NotEnoughMoney
	msgbox KiyahaIsle_Interior_House3_Text_ThankYouDear, MSGBOX_DEFAULT
	checkitemspace ITEM_BIG_MALASADA
	call_if_eq VAR_RESULT, TRUE, KiyahaIsle_Interior_House3_EventScript_RemoveMoney
.if OW_SHOW_ITEM_DESCRIPTIONS == OW_ITEM_DESCRIPTIONS_OFF
	giveitem ITEM_BIG_MALASADA
	goto_if_eq VAR_RESULT, FALSE, KiyahaIsle_Interior_House3_EventScript_BagIsFull
	hidemoneybox
	release
	end

KiyahaIsle_Interior_House3_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end
.else
	hidemoneybox
	giveitem ITEM_BIG_MALASADA
	goto_if_eq VAR_RESULT, FALSE, KiyahaIsle_Interior_House3_EventScript_BagIsFull
	release
	end

KiyahaIsle_Interior_House3_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	release
	end
.endif @ OW_SHOW_ITEM_DESCRIPTIONS


KiyahaIsle_Interior_House3_EventScript_RemoveMoney::
	removemoney 200
	updatemoneybox
	return

KiyahaIsle_Interior_House3_EventScript_DeclineBigMalasada::
	msgbox KiyahaIsle_Interior_House3_Text_OhFineThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

KiyahaIsle_Interior_House3_EventScript_NotEnoughMoney::
	msgbox KiyahaIsle_Interior_House3_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

KiyahaIsle_Interior_House3_Text_BigMalasadaJust200:
	.string "Don't let your POKéMON go hungry.\n"
	.string "Try our local specialty!\p"
	.string "One BIG MALASADA.\n"
	.string "Just ¥200.$"

KiyahaIsle_Interior_House3_Text_ThankYouDear:
	.string "Here's one freshly baked!$"

KiyahaIsle_Interior_House3_Text_YouveNotGotTheMoney:
	.string "Hmm, what's this?\n"
	.string "You've got no money!$"

KiyahaIsle_Interior_House3_Text_OhFineThen:
	.string "Oh? But your POKéMON look\n"
	.string "positively famished!$"

