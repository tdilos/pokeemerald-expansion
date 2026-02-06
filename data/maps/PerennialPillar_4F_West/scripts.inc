.set LOCALID_DIALGA, 1

PerennialPillar_4F_West_MapScripts::
	.byte 0

PerennialPillar_EventScript_Dialga::
	lock
	playmoncry SPECIES_DIALGA, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_DIALGA, 70
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 1, 1, 1, 1, 1, 1
	special BattleSetup_StartLegendaryBattle
	waitstate
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_DIALGA
	setflag FLAG_HIDE_DIALGA
	fadescreen FADE_FROM_BLACK
	release
	end


