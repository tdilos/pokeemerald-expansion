QuartzCave_1F_MapScripts::
	.byte 0


QuartzCave_EventScript_Egbert::
	trainerbattle_single TRAINER_EGBERT, QuartzCave_Text_EgbertIntro, QuartzCave_Text_EgbertDefeated
	msgbox QuartzCave_Text_EgbertPostBattle, MSGBOX_AUTOCLOSE
	end
