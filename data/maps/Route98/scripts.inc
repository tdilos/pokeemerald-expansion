Route98_MapScripts::
	.byte 0

Route98_EventScript_Giselle::
	trainerbattle_single TRAINER_GISELLE, Route98_Text_GiselleIntro, Route98_Text_GiselleDefeated
	msgbox Route98_Text_GisellePostBattle, MSGBOX_AUTOCLOSE
	end

Route98_EventScript_Brett::
	trainerbattle_single TRAINER_BRETT, Route98_Text_BrettIntro, Route98_Text_BrettDefeated
	msgbox Route98_Text_BrettPostBattle, MSGBOX_AUTOCLOSE
	end

Route98_EventScript_Cody::
	trainerbattle_single TRAINER_CODY, Route98_Text_CodyIntro, Route98_Text_CodyDefeated
	msgbox Route98_Text_CodyPostBattle, MSGBOX_AUTOCLOSE
	end

Route98_EventScript_Tudy::
	trainerbattle_single TRAINER_TUDY, Route98_Text_TudyIntro, Route98_Text_TudyDefeated
	msgbox Route98_Text_TudyPostBattle, MSGBOX_AUTOCLOSE
	end

Route98_EventScript_Mick::
	trainerbattle_single TRAINER_MICK, Route98_Text_MickIntro, Route98_Text_MickDefeated
	msgbox Route98_Text_MickPostBattle, MSGBOX_AUTOCLOSE
	end

Route98_EventScript_Sailor::
	msgbox Route98_Text_HoennRegion, MSGBOX_NPC
	end

Route98_Text_HoennRegion:
	.string "Somewhere far across that sea\n"
	.string "is the HOENN region.\p"
	.string "You can't get there by swimming,\n"
	.string "even if your POKéMON know SURF.\p"
	.string "I sure wish I had a boat that\n"
	.string "would take me there.$"

Route98_EventScript_Man::
	msgbox Route98_Text_AncientHistory, MSGBOX_NPC
	end

Route98_Text_AncientHistory:
	.string "These rocks were once the site of\n"
	.string "an ancient lighthouse.\p"
	.string "But natural and manmade forces\n"
	.string "have worn it down to this.\p"
	.string "Now they're a fleeting reminder\n"
	.string "of the impermanence of all things.$"


