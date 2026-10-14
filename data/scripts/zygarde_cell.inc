Common_EventScript_ZygardeCell::
	lockall
	playse SE_SHINY
	message Text_CellWentIntoCube
	waitmessage
	addvar VAR_ZYGARDE_CELLS, 1
	removeobject VAR_LAST_TALKED
	buffernumberstring STR_VAR_3, VAR_ZYGARDE_CELLS
	message Text_CellsFound
	waitmessage
	releaseall
	end

Text_CellWentIntoCube:
	.string "The ZYGARDE CELL was sucked into the cube.$"

Text_CellsFound:
	.string "Total Cells Found: {STR_VAR_3}$"

