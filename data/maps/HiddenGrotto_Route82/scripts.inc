HiddenGrotto_Route82_MapScripts::
	.byte 0


HiddenGrotto_Route82_EventScript_GrottoBall::
	removeobject VAR_LAST_TALKED
	special HiddenGrottoWildEncounter
	goto_if_eq VAR_RESULT, FALSE, HiddenGrotto_Route82_EventScript_GiveGrottoItem
	waitstate
	setflag FLAG_DAILY_HIDDEN_GROTTO_ROUTE_82
	releaseall
	end

HiddenGrotto_Route82_EventScript_GiveGrottoItem::
	special GetGrottoItem
	@compare VAR_RESULT, FALSE
	@goto_if_eq EventScript_EndSmash
	giveitem VAR_RESULT
	setflag FLAG_DAILY_HIDDEN_GROTTO_ROUTE_82
	releaseall
	end
