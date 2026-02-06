Route89_MapScripts::
	.byte 0

Route89_EventScript_Angus::
	trainerbattle_single TRAINER_ANGUS, Route89_Text_AngusIntro, Route89_Text_AngusDefeated
	msgbox Route89_Text_AngusPostBattle, MSGBOX_AUTOCLOSE
	end

Route89_EventScript_Boy::
	msgbox Route89_Text_PowerStation, MSGBOX_NPC
	end

Route89_Text_PowerStation:
	.string "The ledges here are too steep\n"
	.string "to climb.\p"
	.string "The only way to AMBER CITY is\n"
	.string "through that building.\p"
	.string "You be my guest. There's no way\n"
	.string "I'm going in there...$"





Route89_EventScript_Arley::
	trainerbattle_single TRAINER_ARLEY, Route89_Text_ArleyIntro, Route89_Text_ArleyDefeated
	msgbox Route89_Text_ArleyPostBattle, MSGBOX_AUTOCLOSE
	end

Route89_EventScript_Millie::
	trainerbattle_single TRAINER_MILLIE, Route89_Text_MillieIntro, Route89_Text_MillieDefeated
	msgbox Route89_Text_MilliePostBattle, MSGBOX_AUTOCLOSE
	end


