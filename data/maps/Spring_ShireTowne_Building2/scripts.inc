Spring_ShireTowne_Building2_MapScripts::
	.byte 0


ShireTowne_Building2_EventScript_Blacksmith::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart ShireTowne_Building2_ArmorShop
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
ShireTowne_Building2_ArmorShop:
	.2byte ITEM_AUSPICIOUS_ARMOR
	.2byte ITEM_MALICIOUS_ARMOR
	.2byte ITEM_NONE
	release
	end

