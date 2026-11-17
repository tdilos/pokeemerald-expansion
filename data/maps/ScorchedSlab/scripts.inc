ScorchedSlab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ScorchedSlab_OnTransition
	.byte 0

ScorchedSlab_OnTransition:
	setflag FLAG_LANDMARK_SCORCHED_SLAB

	goto_if_unset FLAG_IS_CHAMPION, ScorchedSlab_EventScript_HideWormhole
	@goto_if_set FLAG_BATTLED_HEATRAN, ScorchedSlab_EventScript_HideWormhole
	clearflag FLAG_HIDE_WORMHOLE_HEATRAN
	end

ScorchedSlab_EventScript_HideWormhole:
	setflag FLAG_HIDE_WORMHOLE_HEATRAN
	end

