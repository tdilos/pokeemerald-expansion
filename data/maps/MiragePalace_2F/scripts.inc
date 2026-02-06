MiragePalace_2F_MapScripts::
	.byte 0

MiragePalace_2F_EventScript_WarpToThirdFloor::
	lockall
	@warpsilent MAP_MIRAGE_PALACE_3F, 9, 12
	warpteleport MAP_MIRAGE_PALACE_3F, 9, 12
	waitstate
	releaseall
	end


