Route81_MapScripts::
	.byte 0

Route81_EventScript_RouteSign::
	msgbox Route81_Text_RouteSign, MSGBOX_SIGN
	end

Route81_EventScript_Boy::
	msgbox Route81_Text_NotATrainer, MSGBOX_NPC
	end

Route81_EventScript_Hiker::
	msgbox Route81_Text_BreatheAir, MSGBOX_NPC
	end

Route81_EventScript_TrainerTipsFastRun::
	msgbox Route81_Text_TrainerTipsFastRun, MSGBOX_SIGN
	end

Route81_Text_TrainerTipsFastRun:
	.string "TRAINER TIPS\p"
	.string "Press R to quickly flee from a\n"
	.string "wild POKéMON battle.$"

Route81_Text_RouteSign:
	.string "ROUTE 81\p"
	.string "{LEFT_ARROW} UMBER TOWN\n"
	.string "{RIGHT_ARROW} CINEROUS TOWN$"

Route81_Text_BreatheAir:
	.string "Ahh...\n"
	.string "Breathe in the fresh mountain air.$"

Route81_Text_NotATrainer:
	.string "Oh no, I'm not a trainer.\p"
	.string "But that's right, trainers will want\n"
	.string "to battle if they see you.\p"
	.string "If you don't want to battle, you should\n"
	.string "stay out of their line of sight.$"
