MindaroCity_DepartmentStore_4F_MapScripts::
	.byte 0


MindaroCity_Gym_EventScript_Runner::
	msgbox MindaroCity_Gym_Text_ExplainVitamins, MSGBOX_NPC
	end

MindaroCity_Gym_Text_ExplainVitamins:
	.string "Feed your POKéMON vitamins\n"
	.string "to raise their stats.\p"
	.string "But keep in mind that their stats\n"
	.string "don't go up forever.\p"
	.string "Let's see, I think an untrained POKéMON\n"
	.string "could eat about 26 PROTEINS.$"



MindaroCity_DepartmentStore_4F_EventScript_ClerkLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MindaroCity_DepartmentStore_4F_Pokemart_Vitamins
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MindaroCity_DepartmentStore_4F_Pokemart_Vitamins:
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	.2byte ITEM_NONE
	release
	end

MindaroCity_DepartmentStore_4F_EventScript_ClerkRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MindaroCity_DepartmentStore_4F_Pokemart_StatBoosters
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MindaroCity_DepartmentStore_4F_Pokemart_StatBoosters:
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_NONE
	release
	end

