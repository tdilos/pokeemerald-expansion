PerennialPillar_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PerennialPillar_Exterior_OnTransition
	.byte 0

PerennialPillar_Exterior_OnTransition:
	setflag FLAG_ARRIVED_AT_PERENNIAL_PILLAR
	setflag FLAG_HIDE_ARCEUS
	end


