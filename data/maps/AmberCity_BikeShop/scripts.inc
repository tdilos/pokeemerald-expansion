AmberCity_BikeShop_MapScripts::
	.byte 0

AmberCity_BikeShop_EventScript_Clerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, AmberCity_BikeShop_EventScript_AlreadyGotBicycle
	checkitem ITEM_BIKE_VOUCHER
	goto_if_eq VAR_RESULT, TRUE, AmberCity_BikeShop_EventScript_ExchangeBikeVoucher
	showmoneybox 0, 0
	msgbox AmberCity_BikeShop_Text_WelcomeToBikeShop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, AmberCity_BikeShop_EventScript_YouCantAffordIt
	goto_if_eq VAR_RESULT, NO, AmberCity_BikeShop_EventScript_YouCantAffordIt
	end

AmberCity_BikeShop_EventScript_YouCantAffordIt::
	msgbox AmberCity_BikeShop_Text_YouCantAffordIt
	hidemoneybox
	release
	end

AmberCity_BikeShop_EventScript_ExchangeBikeVoucher::
	msgbox AmberCity_BikeShop_Text_OhBikeVoucherHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	setflag FLAG_RECEIVED_BIKE
	removeitem ITEM_BIKE_VOUCHER
	release
	end

AmberCity_BikeShop_EventScript_AlreadyGotBicycle::
	msgbox AmberCity_BikeShop_Text_HowDoYouLikeNewBicycle
	release
	end

AmberCity_BikeShop_Text_WelcomeToBikeShop::
	.string "Hello and welcome to\n"
	.string "AMBER CITY WHEELS!\p"
	.string "Have we got just the deal\n"
	.string "for you!\p"
	.string "Our BIKES right now start\n"
	.string "from ¥1,000,000,\l"
	.string "does that sound good to you?$"

AmberCity_BikeShop_Text_YouCantAffordIt::
	.string "...\p"
	.string "Oh, it seems you can't afford it.\p"
	.string "We hope to see you again soon!$"

AmberCity_BikeShop_Text_OhBikeVoucherHereYouGo::
    .string "Oh, that's...\p"
    .string "A BIKE VOUCHER!\p"
    .string "In that case, here you go!$"

AmberCity_BikeShop_Text_ExchangedVoucherForBicycle::
    .string "{PLAYER} exchanged the\n"
    .string "BIKE VOUCHER for a BIKE.$"

AmberCity_BikeShop_Text_HowDoYouLikeNewBicycle::
    .string "How do you like your new BIKE?\n"
    .string "Do you like how it rides?\p"
    .string "You can take it out on ROUTE 87\n"
    .string "and even into caves!$"


