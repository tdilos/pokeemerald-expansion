MiragePalace_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MiragePalace_1F_OnTransition
	.byte 0

MiragePalace_1F_OnTransition:
	@setflag FLAG_SYS_INSIDE_MIRAGE_PALACE
	special EnterMiragePalace
	end





MiragePalace_1F_EventScript_WarpToSecondFloor::
	lockall
	@warpsilent MAP_MIRAGE_PALACE_2F, 12, 17
	warpteleport MAP_MIRAGE_PALACE_2F, 12, 17
	waitstate
	releaseall
	end

