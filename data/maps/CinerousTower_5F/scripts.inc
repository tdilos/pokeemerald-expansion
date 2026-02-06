.set LOCALID_VOLCARONA, 1

CinerousTower_5F_MapScripts::
	.byte 0

CinerousTower_5F_EventScript_Volcarona::
	lock
	playmoncry SPECIES_VOLCARONA, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_VOLCARONA, 25
	totemboost_spatk2 B_POSITION_OPPONENT_LEFT
	special BattleSetup_StartLegendaryBattle
	waitstate
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_VOLCARONA
	@setflag FLAG_BATTLED_VOLCARONA
	fadescreen FADE_FROM_BLACK
	release
	end

