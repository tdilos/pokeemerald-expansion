QuartzCave_B1_MapScripts::
	.byte 0

QuartzCave_EventScript_Sean::
	trainerbattle_single TRAINER_SEAN, QuartzCave_Text_SeanIntro, QuartzCave_Text_SeanDefeated
	msgbox QuartzCave_Text_SeanPostBattle, MSGBOX_AUTOCLOSE
	end

QuartzCave_EventScript_Patric::
	trainerbattle_single TRAINER_PATRIC, QuartzCave_Text_PatricIntro, QuartzCave_Text_PatricDefeated
	msgbox QuartzCave_Text_PatricPostBattle, MSGBOX_AUTOCLOSE
	end

QuartzCave_EventScript_Chloe::
	trainerbattle_single TRAINER_CHLOE, QuartzCave_Text_ChloeIntro, QuartzCave_Text_ChloeDefeated
	msgbox QuartzCave_Text_ChloePostBattle, MSGBOX_AUTOCLOSE
	end
