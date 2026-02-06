.set LOCALID_SHAYMIN, 1

ShamrockIsle_SecretHollow_MapScripts::
	.byte 0


ShamrockIsle_SecretHollow_EventScript_Shaymin::
	lock
	playmoncry SPECIES_SHAYMIN, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_SHAYMIN, 60
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 1, 1, 1, 1, 1, 1
	special BattleSetup_StartLegendaryBattle
	waitstate
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_SHAYMIN
	setflag FLAG_BATTLED_SHAYMIN
	fadescreen FADE_FROM_BLACK
	release
	end

