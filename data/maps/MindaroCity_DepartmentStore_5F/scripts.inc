MindaroCity_DepartmentStore_5F_MapScripts::
	.byte 0

MindaroCity_DepartmentStore_5F_EventScript_Youngster::
	msgbox MindaroCity_DepartmentStore_5F_Text_StupidMail, MSGBOX_NPC
	end

MindaroCity_DepartmentStore_5F_Text_StupidMail:
	.string "I was hoping they would have a bunch\n"
	.string "of cool stuff on the top floor.\p"
	.string "But all they sell here is stupid mail.$"

MindaroCity_DepartmentStore_5F_EventScript_ClerkLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MindaroCity_DepartmentStore_5F_Pokemart1
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MindaroCity_DepartmentStore_5F_Pokemart1:
	.2byte ITEM_BEAD_MAIL
	.2byte ITEM_TROPIC_MAIL
	.2byte ITEM_HARBOR_MAIL
	.2byte ITEM_SHADOW_MAIL
	.2byte ITEM_DREAM_MAIL
	.2byte ITEM_RETRO_MAIL
	.2byte ITEM_NONE
	release
	end

MindaroCity_DepartmentStore_5F_EventScript_ClerkRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MindaroCity_DepartmentStore_5F_Pokemart2
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MindaroCity_DepartmentStore_5F_Pokemart2:
	.2byte ITEM_WOOD_MAIL
	.2byte ITEM_ORANGE_MAIL
	.2byte ITEM_FAB_MAIL
	.2byte ITEM_GLITTER_MAIL
	.2byte ITEM_WAVE_MAIL
	.2byte ITEM_MECH_MAIL
	.2byte ITEM_NONE
	release
	end

