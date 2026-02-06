.set LOCALID_JIRACHI, 7

QuartzCave_B3_MapScripts::
	.byte 0

QuartzCave_EventScript_Wendel::
	trainerbattle_single TRAINER_WENDEL, QuartzCave_Text_WendelIntro, QuartzCave_Text_WendelDefeated
	msgbox QuartzCave_Text_WendelPostBattle, MSGBOX_AUTOCLOSE
	end

QuartzCave_EventScript_Aurora::
	trainerbattle_single TRAINER_AURORA, QuartzCave_Text_AuroraIntro, QuartzCave_Text_AuroraDefeated
	msgbox QuartzCave_Text_AuroraPostBattle, MSGBOX_AUTOCLOSE
	end



QuartzCave_EventScript_Jirachi::
	lock
	playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_JIRACHI, 50
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 1, 1, 1, 1, 1, 1
	special BattleSetup_StartLegendaryBattle
	waitstate
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_JIRACHI
	setflag FLAG_BATTLED_JIRACHI
	fadescreen FADE_FROM_BLACK
	release
	end
