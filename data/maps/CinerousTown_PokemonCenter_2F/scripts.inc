CinerousTown_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0



Common_EventScript_TestNPC::
	lock
	faceplayer
	special TryUpdateWonderTrades
	playse SE_DING_DONG
	waitse
	release
	end

Common_EventScript_WonderTradeNPC::
	lock
	faceplayer
	msgbox CableClub_Text_WonderTrading, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Common_EventScript_TryWonderTrade
	release
	end

Common_EventScript_TryWonderTrade::
	goto_if_ne VAR_WONDER_TRADE_1, 0, Common_EventScript_WonderTrade1
	goto_if_ne VAR_WONDER_TRADE_2, 0, Common_EventScript_WonderTrade2
	goto_if_ne VAR_WONDER_TRADE_3, 0, Common_EventScript_WonderTrade3
	goto_if_ne VAR_WONDER_TRADE_4, 0, Common_EventScript_WonderTrade4
	goto_if_ne VAR_WONDER_TRADE_5, 0, Common_EventScript_WonderTrade5
	goto_if_ne VAR_WONDER_TRADE_6, 0, Common_EventScript_WonderTrade6
	msgbox CableClub_Text_WonderTradingLimitReached, MSGBOX_DEFAULT
	closemessage
	release
	end

Common_EventScript_WonderTrade1::
	@copyvar VAR_0x8000, VAR_WONDER_TRADE_1
	@setvar VAR_WONDER_TRADE_1, 0
	goto EventScript_DoWonderTrade
	release
	end

Common_EventScript_WonderTrade2::
	@copyvar VAR_0x8000, VAR_WONDER_TRADE_2
	@setvar VAR_WONDER_TRADE_2, 0
	goto EventScript_DoWonderTrade
	release
	end

Common_EventScript_WonderTrade3::
	@copyvar VAR_0x8000, VAR_WONDER_TRADE_3
	@setvar VAR_WONDER_TRADE_3, 0
	goto EventScript_DoWonderTrade
	release
	end

Common_EventScript_WonderTrade4::
	@copyvar VAR_0x8000, VAR_WONDER_TRADE_4
	@setvar VAR_WONDER_TRADE_4, 0
	goto EventScript_DoWonderTrade
	release
	end

Common_EventScript_WonderTrade5::
	@copyvar VAR_0x8000, VAR_WONDER_TRADE_5
	@setvar VAR_WONDER_TRADE_5, 0
	goto EventScript_DoWonderTrade
	release
	end

Common_EventScript_WonderTrade6::
	@copyvar VAR_0x8000, VAR_WONDER_TRADE_6
	@setvar VAR_WONDER_TRADE_6, 0
	goto EventScript_DoWonderTrade
	release
	end

CinerousTown_PokemonCenter_2F_EventScript_ExplainWonderTrading::
	msgbox CableClub_Text_WonderTrading, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_DoWonderTrade
	release
	end

CableClub_Text_WonderTrading:
	.string "This is the WONDER TRADE CORNER.\p"
	.string "You can trade up to 6 POKéMON\n"
	.string "here every day.\p"
	.string "Would like to trade with\n"
	.string "another TRAINER?$"

CableClub_Text_WonderTradingLimitReached:
	.string "It appears there are no more TRAINERS\n"
	.string "willing to trade today.\p"
	.string "Please check again tomorrow.$"







Common_EventScript_DifficultyChecker::
	lock
	faceplayer
	special GetDifficulty
	switch VAR_RESULT
	case 0, Common_EventScript_NormalDifficultyCheck
	case 1, Common_EventScript_HardcoreDifficultyCheck
	case 2, Common_EventScript_InsaneDifficultyCheck
	end

Common_EventScript_InsaneDifficultyCheck::
	msgbox Common_Text_InsaneDifficulty, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Common_EventScript_DontChangeDifficulty
	msgbox Common_Text_ChangeToHardcore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Common_EventScript_DontChangeDifficulty
	closemessage
	special DecreaseDifficulty
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	msgbox Common_Text_ChangedToHardcore, MSGBOX_DEFAULT
	release
	end

Common_EventScript_HardcoreDifficultyCheck::
	msgbox Common_Text_HardcoreDifficulty, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Common_EventScript_DontChangeDifficulty
	msgbox Common_Text_ChangeToNormal, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Common_EventScript_DontChangeDifficulty
	closemessage
	special DecreaseDifficulty
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	msgbox Common_Text_ChangedToNormal, MSGBOX_DEFAULT
	release
	end

Common_EventScript_NormalDifficultyCheck::
	msgbox Common_Text_NormalDifficulty, MSGBOX_DEFAULT
	release
	end

Common_Text_InsaneDifficulty:
	.string "You're an INSANE adventurer, huh?\p"
	.string "You must be crazy to sign up\n"
	.string "for something like that.\p"
	.string "Or maybe you don't think you're\n"
	.string "cut out for this anymore?$"

Common_Text_HardcoreDifficulty:
	.string "You're a HARDCORE adventurer, huh?\p"
	.string "You must be pretty brave then.\p"
	.string "Or maybe you don't think you're\n"
	.string "cut out for this anymore?$"

Common_Text_NormalDifficulty:
	.string "You're a NORMAL adventurer, huh?\p"
	.string "Meh, you're boring.$"

Common_Text_ChangeToHardcore:
	.string "I see. So would you rather be\n"
	.string "a HARDCORE adventurer instead?$"

Common_Text_ChangeToNormal:
	.string "I see. So would you rather be\n"
	.string "a NORMAL adventurer instead?$"

Common_Text_ChangedToHardcore:
	.string "Done. From now on, you'll be\n"
	.string "known as a HARDCORE adventurer.$"

Common_Text_ChangedToNormal:
	.string "Done. From now on, you'll be\n"
	.string "known as a NORMAL adventurer.$"

Common_EventScript_DontChangeDifficulty::
	msgbox Common_Text_DontChangeDifficulty, MSGBOX_DEFAULT
	release
	end

Common_Text_DontChangeDifficulty:
	.string "You refuse to give up.\n"
	.string "I like your attitude.$"
	


