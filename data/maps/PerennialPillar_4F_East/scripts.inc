.set LOCALID_PALKIA, 1

PerennialPillar_4F_East_MapScripts::
	.byte 0

PerennialPillar_EventScript_Palkia::
	lock
	playmoncry SPECIES_PALKIA, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_PALKIA, 70
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 1, 1, 1, 1, 1, 1
	special BattleSetup_StartLegendaryBattle
	waitstate
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_PALKIA
	setflag FLAG_HIDE_PALKIA
	fadescreen FADE_FROM_BLACK
	release
	end


