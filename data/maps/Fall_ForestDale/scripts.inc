Fall_ForestDale_MapScripts::
	.byte 0


ForestDale_EventScript_AppleMerchant::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart ForestDale_AppleShop
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
ForestDale_AppleShop:
	.2byte ITEM_SWEET_APPLE
	.2byte ITEM_SYRUPY_APPLE
	.2byte ITEM_TART_APPLE
	.2byte ITEM_NONE
	release
	end

