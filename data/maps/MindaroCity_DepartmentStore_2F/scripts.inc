MindaroCity_DepartmentStore_2F_MapScripts::
	.byte 0

MindaroCity_DepartmentStore_2F_EventScript_ClerkLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MindaroCity_DepartmentStore_2F_Pokemart1
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MindaroCity_DepartmentStore_2F_Pokemart1:
	.2byte ITEM_TM17 @Protect
	.2byte ITEM_TM20 @Safeguard
	.2byte ITEM_TM16 @Light Screen
	.2byte ITEM_TM33 @Reflect
	.2byte ITEM_TM14 @Blizzard
	.2byte ITEM_TM25 @Thunder
	.2byte ITEM_TM38 @Fire Blast
	.2byte ITEM_TM15 @Hyper Beam
	.2byte ITEM_TM68 @Giga Impact
	.2byte ITEM_NONE
	release
	end

MindaroCity_DepartmentStore_2F_EventScript_ClerkRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end




MindaroCity_DepartmentStore_2F_EventScript_AceTrainer::
	msgbox MindaroCity_DepartmentStore_2F_Text_ExplainHyperBeam, MSGBOX_NPC
	closemessage
	end

MindaroCity_DepartmentStore_2F_Text_ExplainHyperBeam:
	.string "The drawback of HYPER BEAM and GIGA IMPACT\n"
	.string "is that they take one turn to recharge.\p"
	.string "But did you know? If the target faints,\n"
	.string "then they don't have to recharge!$"





