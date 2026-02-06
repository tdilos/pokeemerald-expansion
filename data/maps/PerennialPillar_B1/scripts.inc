.set LOCALID_GIRATINA, 1

PerennialPillar_B1_MapScripts::
	.byte 0

PerennialPillar_EventScript_Giratina::
	lock
	playmoncry SPECIES_GIRATINA, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_GIRATINA, 70
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 1, 1, 1, 1, 1, 1
	special BattleSetup_StartLegendaryBattle
	waitstate
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_GIRATINA
	setflag FLAG_HIDE_GIRATINA
	fadescreen FADE_FROM_BLACK
	release
	end


