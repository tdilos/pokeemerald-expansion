EventScript_PC::
	lockall
	setvar VAR_0x8004, PC_LOCATION_OTHER
	special GetDifficulty
	goto_if_lt VAR_RESULT, 2, EventScript_PCWithoutFee
	showmoneybox 0, 0
	msgbox gText_PCWithFee, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_PCTryPayFee
	hidemoneybox
	releaseall
	end

EventScript_PCTryPayFee::
	checkmoney 300
	goto_if_eq VAR_RESULT, 0, EventScript_PCCantPay
	playse SE_SHOP
	removemoney 300        @ Dummy value until after further testing
	updatemoneybox
	delay 50
	hidemoneybox
	goto EventScript_PCWithoutFee
	end

EventScript_PCCantPay::
	msgbox gText_PCCantPay, MSGBOX_DEFAULT
	hidemoneybox
	releaseall
	end

EventScript_PCWithoutFee::
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox Text_BootUpPC, MSGBOX_DEFAULT
	goto EventScript_PCMainMenu
	end

EventScript_PCMainMenu::
	message gText_WhichPCShouldBeAccessed
	waitmessage
	special ScriptMenu_CreatePCMultichoice
	waitstate
	goto EventScript_AccessPC
	end

EventScript_AccessPC::
	switch VAR_RESULT
	case 0, EventScript_AccessPokemonStorage
	case 1, EventScript_AccessPlayersPC
	case 2, EventScript_SaveFromPC
	case 3, EventScript_AccessHallOfFame
	case 4, EventScript_TurnOffPC
	case MULTI_B_PRESSED, EventScript_TurnOffPC
	end

EventScript_SaveFromPC::
	special SaveGame
	waitstate
	goto EventScript_PCMainMenu
	end


EventScript_AccessPlayersPC::
	playse SE_PC_LOGIN
	msgbox gText_AccessedPlayersPC, MSGBOX_DEFAULT
	special PlayerPC
	waitstate
	goto EventScript_PCMainMenu
	end

EventScript_AccessPokemonStorage::
	playse SE_PC_LOGIN
	call_if_unset FLAG_SYS_PC_LANETTE, EventScript_AccessSomeonesPC
	call_if_set FLAG_SYS_PC_LANETTE, EventScript_AccessLanettesPC
	msgbox gText_StorageSystemOpened, MSGBOX_DEFAULT
	special ShowPokemonStorageSystemPC
	waitstate
	goto EventScript_PCMainMenu
	end

EventScript_AccessSomeonesPC::
	msgbox gText_AccessedSomeonesPC, MSGBOX_DEFAULT
	return

EventScript_AccessLanettesPC::
#if IS_FRLG
	msgbox gText_AccessedBillsPC, MSGBOX_DEFAULT
#else
	msgbox gText_AccessedLanettesPC, MSGBOX_DEFAULT
#endif
	return

EventScript_TurnOffPC::
	setvar VAR_0x8004, PC_LOCATION_OTHER
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

EventScript_AccessHallOfFame::
	goto_if_unset FLAG_SYS_GAME_CLEAR, EventScript_TurnOffPC
	playse SE_PC_LOGIN
	special AccessHallOfFamePC
	waitstate
	goto EventScript_AccessPC
	end

EventScript_AccessPokemonBoxLink::
	playse SE_PC_LOGIN
	msgbox gText_StorageSystemOpened, MSGBOX_DEFAULT
	special ShowPokemonStorageSystemPC
	waitstate
	goto EventScript_TurnOffPC
	end
