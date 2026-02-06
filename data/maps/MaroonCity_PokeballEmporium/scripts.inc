MaroonCity_PokeballEmporium_MapScripts::
	.byte 0

PokeballEmporium_EventScript_Ranger::
	lock
	faceplayer
	msgbox PokeballEmporium_Text_DreamBalls, MSGBOX_DEFAULT
	release
	end

PokeballEmporium_Text_DreamBalls:
	.string "A DREAM BALL works differently\n"
	.string "from other POKé BALLS.\p"
	.string "A POKéMON caught in a DREAM BALL\n"
	.string "will have its rare ability.$"

PokeballEmporium_EventScript_Maniac1::
	lock
	faceplayer
	msgbox PokeballEmporium_Text_EmporiumPeople, MSGBOX_DEFAULT
	release
	end

PokeballEmporium_Text_EmporiumPeople:
	.string "Here at the EMPORIUM, they make POKé BALLS\n"
	.string "from apricorns that grow around here.\p"
	.string "And sometimes they get shipments of rare\n"
	.string "balls you can't find anywhere else.$"

PokeballEmporium_EventScript_Hiker::
	lock
	faceplayer
	msgbox PokeballEmporium_Text_BetterCheckTomorrow, MSGBOX_DEFAULT
	release
	end

PokeballEmporium_Text_BetterCheckTomorrow:
	.string "The shops here get new POKé BALLS\n"
	.string "every day.\p"
	.string "I'd better check again tomorrow.$"

PokeballEmporium_EventScript_Breeder::
	lock
	faceplayer
	msgbox PokeballEmporium_Text_LotsOfVariety, MSGBOX_DEFAULT
	release
	end

PokeballEmporium_Text_LotsOfVariety:
	.string "There's a lot of variety here, but I think\n"
	.string "some people can get carried away, ha ha.$"

PokeballEmporium_EventScript_Maniac2::
	lock
	faceplayer
	msgbox PokeballEmporium_Text_Balltism, MSGBOX_DEFAULT
	release
	end

PokeballEmporium_Text_Balltism:
	.string "You don't understand, I NEED to\n"
	.string "catch it in a FAST BALL!\p"
	.string "Otherwise it won't look right.$"






gText_Goofed:
	.string "Ya done goofed.$"

PokeballEmporium_EventScript_Vendor1::
	goto_if_eq VAR_EMPORIUM_VENDOR_1, 0, PokeballEmporium_EventScript_RareVendor
	goto_if_eq VAR_EMPORIUM_VENDOR_1, 1, PokeballEmporium_EventScript_UncommonVendor1
	goto_if_eq VAR_EMPORIUM_VENDOR_1, 2, PokeballEmporium_EventScript_UncommonVendor1
	goto_if_eq VAR_EMPORIUM_VENDOR_1, 3, PokeballEmporium_EventScript_UncommonVendor2
	goto_if_eq VAR_EMPORIUM_VENDOR_1, 4, PokeballEmporium_EventScript_UncommonVendor2
	goto_if_eq VAR_EMPORIUM_VENDOR_1, 5, PokeballEmporium_EventScript_CommonVendor1
	goto_if_eq VAR_EMPORIUM_VENDOR_1, 6, PokeballEmporium_EventScript_CommonVendor1
	goto_if_eq VAR_EMPORIUM_VENDOR_1, 7, PokeballEmporium_EventScript_CommonVendor1
	goto_if_eq VAR_EMPORIUM_VENDOR_1, 8, PokeballEmporium_EventScript_CommonVendor2
	goto_if_eq VAR_EMPORIUM_VENDOR_1, 9, PokeballEmporium_EventScript_CommonVendor2
	goto_if_eq VAR_EMPORIUM_VENDOR_1, 10, PokeballEmporium_EventScript_CommonVendor2
	goto_if_eq VAR_EMPORIUM_VENDOR_1, 11, PokeballEmporium_EventScript_BasicVendor
	goto_if_eq VAR_EMPORIUM_VENDOR_1, 12, PokeballEmporium_EventScript_BasicVendor
	goto_if_eq VAR_EMPORIUM_VENDOR_1, 13, PokeballEmporium_EventScript_BasicVendor
	goto_if_eq VAR_EMPORIUM_VENDOR_1, 14, PokeballEmporium_EventScript_BasicVendor
	goto_if_eq VAR_EMPORIUM_VENDOR_1, 15, PokeballEmporium_EventScript_BasicVendor
	msgbox gText_Goofed, MSGBOX_DEFAULT
	end

PokeballEmporium_EventScript_Vendor2::
	goto_if_eq VAR_EMPORIUM_VENDOR_2, 0, PokeballEmporium_EventScript_RareVendor
	goto_if_eq VAR_EMPORIUM_VENDOR_2, 1, PokeballEmporium_EventScript_UncommonVendor1
	goto_if_eq VAR_EMPORIUM_VENDOR_2, 2, PokeballEmporium_EventScript_UncommonVendor1
	goto_if_eq VAR_EMPORIUM_VENDOR_2, 3, PokeballEmporium_EventScript_UncommonVendor2
	goto_if_eq VAR_EMPORIUM_VENDOR_2, 4, PokeballEmporium_EventScript_UncommonVendor2
	goto_if_eq VAR_EMPORIUM_VENDOR_2, 5, PokeballEmporium_EventScript_CommonVendor1
	goto_if_eq VAR_EMPORIUM_VENDOR_2, 6, PokeballEmporium_EventScript_CommonVendor1
	goto_if_eq VAR_EMPORIUM_VENDOR_2, 7, PokeballEmporium_EventScript_CommonVendor1
	goto_if_eq VAR_EMPORIUM_VENDOR_2, 8, PokeballEmporium_EventScript_CommonVendor2
	goto_if_eq VAR_EMPORIUM_VENDOR_2, 9, PokeballEmporium_EventScript_CommonVendor2
	goto_if_eq VAR_EMPORIUM_VENDOR_2, 10, PokeballEmporium_EventScript_CommonVendor2
	goto_if_eq VAR_EMPORIUM_VENDOR_2, 11, PokeballEmporium_EventScript_BasicVendor
	goto_if_eq VAR_EMPORIUM_VENDOR_2, 12, PokeballEmporium_EventScript_BasicVendor
	goto_if_eq VAR_EMPORIUM_VENDOR_2, 13, PokeballEmporium_EventScript_BasicVendor
	goto_if_eq VAR_EMPORIUM_VENDOR_2, 14, PokeballEmporium_EventScript_BasicVendor
	goto_if_eq VAR_EMPORIUM_VENDOR_2, 15, PokeballEmporium_EventScript_BasicVendor
	msgbox gText_Goofed, MSGBOX_DEFAULT
	end

PokeballEmporium_EventScript_Vendor3::
	goto_if_eq VAR_EMPORIUM_VENDOR_3, 0, PokeballEmporium_EventScript_RareVendor
	goto_if_eq VAR_EMPORIUM_VENDOR_3, 1, PokeballEmporium_EventScript_UncommonVendor1
	goto_if_eq VAR_EMPORIUM_VENDOR_3, 2, PokeballEmporium_EventScript_UncommonVendor1
	goto_if_eq VAR_EMPORIUM_VENDOR_3, 3, PokeballEmporium_EventScript_UncommonVendor2
	goto_if_eq VAR_EMPORIUM_VENDOR_3, 4, PokeballEmporium_EventScript_UncommonVendor2
	goto_if_eq VAR_EMPORIUM_VENDOR_3, 5, PokeballEmporium_EventScript_CommonVendor1
	goto_if_eq VAR_EMPORIUM_VENDOR_3, 6, PokeballEmporium_EventScript_CommonVendor1
	goto_if_eq VAR_EMPORIUM_VENDOR_3, 7, PokeballEmporium_EventScript_CommonVendor1
	goto_if_eq VAR_EMPORIUM_VENDOR_3, 8, PokeballEmporium_EventScript_CommonVendor2
	goto_if_eq VAR_EMPORIUM_VENDOR_3, 9, PokeballEmporium_EventScript_CommonVendor2
	goto_if_eq VAR_EMPORIUM_VENDOR_3, 10, PokeballEmporium_EventScript_CommonVendor2
	goto_if_eq VAR_EMPORIUM_VENDOR_3, 11, PokeballEmporium_EventScript_BasicVendor
	goto_if_eq VAR_EMPORIUM_VENDOR_3, 12, PokeballEmporium_EventScript_BasicVendor
	goto_if_eq VAR_EMPORIUM_VENDOR_3, 13, PokeballEmporium_EventScript_BasicVendor
	goto_if_eq VAR_EMPORIUM_VENDOR_3, 14, PokeballEmporium_EventScript_BasicVendor
	goto_if_eq VAR_EMPORIUM_VENDOR_3, 15, PokeballEmporium_EventScript_BasicVendor
	msgbox gText_Goofed, MSGBOX_DEFAULT
	end

PokeballEmporium_EventScript_BasicVendor::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart PokeballEmporium_BasicShop
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PokeballEmporium_BasicShop:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_PREMIER_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HEAL_BALL
	.2byte ITEM_NONE
	release
	end

PokeballEmporium_EventScript_CommonVendor1::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart PokeballEmporium_CommonShop1
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PokeballEmporium_CommonShop1:
	.2byte ITEM_PREMIER_BALL
	.2byte ITEM_FRIEND_BALL
	.2byte ITEM_REPEAT_BALL
	.2byte ITEM_FAST_BALL
	.2byte ITEM_LOVE_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_NONE
	release
	end

PokeballEmporium_EventScript_CommonVendor2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart PokeballEmporium_CommonShop2
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PokeballEmporium_CommonShop2:
	.2byte ITEM_PREMIER_BALL
	.2byte ITEM_FRIEND_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_MOON_BALL
	.2byte ITEM_LURE_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_NONE
	release
	end

PokeballEmporium_EventScript_UncommonVendor1::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart PokeballEmporium_UncommonShop1
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PokeballEmporium_UncommonShop1:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_LOVE_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_LEVEL_BALL
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_NONE
	release
	end

PokeballEmporium_EventScript_UncommonVendor2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart PokeballEmporium_UncommonShop2
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PokeballEmporium_UncommonShop2:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_DUSK_BALL
	.2byte ITEM_FRIEND_BALL
	.2byte ITEM_LURE_BALL
	.2byte ITEM_HEAVY_BALL
	.2byte ITEM_LUXURY_BALL
	.2byte ITEM_NONE
	release
	end

PokeballEmporium_EventScript_RareVendor::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart PokeballEmporium_RareShop
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PokeballEmporium_RareShop:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_PREMIER_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_DREAM_BALL
	.2byte ITEM_NONE
	release
	end

PokeballEmporium_EventScript_RandomizeVendor::
	special GetRandomInt
	switch VAR_RESULT
	case 0, PokeballEmporium_EventScript_RareVendor
	case 1, PokeballEmporium_EventScript_UncommonVendor1
	case 2, PokeballEmporium_EventScript_UncommonVendor1
	case 3, PokeballEmporium_EventScript_UncommonVendor2
	case 4, PokeballEmporium_EventScript_UncommonVendor2
	case 5, PokeballEmporium_EventScript_CommonVendor1
	case 6, PokeballEmporium_EventScript_CommonVendor1
	case 7, PokeballEmporium_EventScript_CommonVendor1
	case 8, PokeballEmporium_EventScript_CommonVendor2
	case 9, PokeballEmporium_EventScript_CommonVendor2
	case 10, PokeballEmporium_EventScript_CommonVendor2
	case 11, PokeballEmporium_EventScript_BasicVendor
	case 12, PokeballEmporium_EventScript_BasicVendor
	case 13, PokeballEmporium_EventScript_BasicVendor
	case 14, PokeballEmporium_EventScript_BasicVendor
	case 15, PokeballEmporium_EventScript_BasicVendor
	end







