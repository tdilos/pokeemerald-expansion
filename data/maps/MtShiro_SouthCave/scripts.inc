MtShiro_SouthCave_MapScripts::
	.byte 0

MtShiro_SouthCave_FossilGuy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_FOSSIL_MT_SHIRO, MtShiro_SouthCave_FossilGuyPostFossil
	message MtShiro_SouthCave_Text_MadeADiscovery
	waitmessage
	multichoicedefault 21, 6, MULTI_MT_SHIRO_FOSSIL, 2, FALSE
	switch VAR_RESULT
	case 0, MtShiro_SouthCave_EventScript_ChooseArmor
	case 1, MtShiro_SouthCave_EventScript_ChooseJaw
	case 2, MtShiro_SouthCave_EventScript_CancelFossilSelect
	case MULTI_B_PRESSED, MtShiro_SouthCave_EventScript_CancelFossilSelect
	end

MtShiro_SouthCave_EventScript_ChooseArmor::
	giveitem ITEM_ARMOR_FOSSIL
	setflag FLAG_RECEIVED_FOSSIL_MT_SHIRO
	release
	end

MtShiro_SouthCave_EventScript_ChooseJaw::
	giveitem ITEM_JAW_FOSSIL
	setflag FLAG_RECEIVED_FOSSIL_MT_SHIRO
	release
	end

MtShiro_SouthCave_EventScript_CancelFossilSelect::
	@closemessage
	release
	end

MtShiro_SouthCave_FossilGuyPostFossil::
	msgbox MtShiro_SouthCave_Text_FossilsInIce, MSGBOX_DEFAULT
	closemessage
	release
	end

MtShiro_SouthCave_Text_MadeADiscovery:
	.string "Hoo-hoo!\n"
	.string "I've made a discovery!\p"
	.string "There are fossils of prehistoric life\n"
	.string "all throughout this cave.\p"
	.string "I'll even let you have one!\p"
	.string "Which fossil would you like?$"

MtShiro_SouthCave_Text_FossilsInIce:
	.string "The fossils here are preserved in the ice.\p"
	.string "Try melting some to look for more!$"
