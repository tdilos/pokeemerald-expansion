.equ AMULET_PRICE, 9999

TurquoiseCity_House3_MapScripts::
	.byte 0

TurquoiseCity_House3_EventScript_Gentleman::
	lock
	faceplayer
	goto_if_set FLAG_BOUGHT_AMULET_COIN, TurquoiseCity_House3_EventScript_AlreadyBought
	showmoneybox 0, 0

	msgbox TurquoiseCity_House3_Text_SellRareItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TurquoiseCity_House3_EventScript_DeclineBuy
	checkmoney AMULET_PRICE
	goto_if_eq VAR_RESULT, FALSE, TurquoiseCity_House3_EventScript_NotEnoughMoney


	removemoney AMULET_PRICE
	updatemoneybox
	giveitem ITEM_AMULET_COIN
	setflag FLAG_BOUGHT_AMULET_COIN
	playfanfare MUS_LEVEL_UP
	message TurquoiseCity_House3_Text_PaidOutrageousPrice
	waitmessage
	waitfanfare
	hidemoneybox
	release
	end

TurquoiseCity_House3_EventScript_DeclineBuy::
	msgbox TurquoiseCity_House3_Text_NotEnoughMoney
	hidemoneybox
	release
	end

TurquoiseCity_House3_EventScript_NotEnoughMoney::
	msgbox TurquoiseCity_House3_Text_NotEnoughMoney
	hidemoneybox
	release
	end

TurquoiseCity_House3_EventScript_AlreadyBought::
	msgbox TurquoiseCity_House3_Text_SavvyTrainer
	release
	end


TurquoiseCity_House3_Text_SellRareItem:
	.string "Hmmm. You seem like a talented trainer\n"
	.string "with a promising future.\p"
	.string "I've got just the thing that\n"
	.string "will help you get there!\p"
	.string "I'll only part with it for ¥9999.\n"
	.string "But trust me, it's well worth it.\p"
	.string "What do you think?$"

TurquoiseCity_House3_Text_NotEnoughMoney:
	.string "Hmmm. Not enough money...\p"
	.string "That's alright, you're young\n"
	.string "and industrious.\p"
	.string "I'm sure you'll find a way to\n"
	.string "earn more.\p"
	.string "Come back then, alright?$"

TurquoiseCity_House3_Text_PaidOutrageousPrice:
	.string "{PLAYER} paid the outrageous ¥9999.$"

TurquoiseCity_House3_Text_SavvyTrainer:
	.string "You're a savvy trainer. I'm sure\n"
	.string "you'll put that to good use.$"



