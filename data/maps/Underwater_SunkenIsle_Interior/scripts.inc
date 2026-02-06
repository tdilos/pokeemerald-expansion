.set LOCALID_MANAPHY, 1

Underwater_SunkenIsle_Interior_MapScripts::
	.byte 0

Underwater_SunkenIsle_Interior_EventScript_Manaphy::
	lock
	playmoncry SPECIES_MANAPHY, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_MANAPHY, 50
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 1, 1, 1, 1, 1, 1
	special BattleSetup_StartLegendaryBattle
	waitstate
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MANAPHY
	setflag FLAG_BATTLED_MANAPHY
	fadescreen FADE_FROM_BLACK
	release
	end

