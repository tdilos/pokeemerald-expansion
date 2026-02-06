MindaroCity_DepartmentStore_3F_MapScripts::
	.byte 0





MindaroCity_DepartmentStore_3F_EventScript_Breeder::
	lock
	faceplayer
	msgbox MindaroCity_DepartmentStore_3F_Text_EvolveEevee, MSGBOX_DEFAULT
	release
	end

MindaroCity_DepartmentStore_3F_Text_EvolveEevee:
	.string "Hmm...\n"
	.string "What do I want my EEVEE to evolve into?$"





MindaroCity_DepartmentStore_3F_EventScript_ClerkLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MindaroCity_DepartmentStore_3F_Pokemart_EvoStones1
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MindaroCity_DepartmentStore_3F_Pokemart_EvoStones1:
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_WATER_STONE
	.2byte ITEM_LEAF_STONE
	@.2byte ITEM_MOON_STONE
	.2byte ITEM_NONE
	release
	end

MindaroCity_DepartmentStore_3F_EventScript_ClerkRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MindaroCity_DepartmentStore_3F_Pokemart_EvoStones2
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MindaroCity_DepartmentStore_3F_Pokemart_EvoStones2:
	.2byte ITEM_SUN_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_ICE_STONE
	.2byte ITEM_ZEPHYR_STONE
	@.2byte ITEM_DUSK_STONE
	@.2byte ITEM_SHINY_STONE
	@.2byte ITEM_ICE_STONE
	@.2byte ITEM_ZEPHYR_STONE
	.2byte ITEM_NONE
	release
	end

