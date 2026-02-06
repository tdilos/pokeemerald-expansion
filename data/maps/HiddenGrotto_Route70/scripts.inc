HiddenGrotto_Route70_MapScripts::
	.byte 0

HiddenGrotto_Route70_EventScript_GrottoBall::
	removeobject VAR_LAST_TALKED
	special HiddenGrottoWildEncounter
	goto_if_eq VAR_RESULT, FALSE, HiddenGrotto_Route70_EventScript_GiveGrottoItem
	waitstate
	setflag FLAG_DAILY_HIDDEN_GROTTO_ROUTE_70
	releaseall
	end

HiddenGrotto_Route70_EventScript_GiveGrottoItem::
	special GetGrottoItem
	giveitem VAR_RESULT
	setflag FLAG_DAILY_HIDDEN_GROTTO_ROUTE_70
	releaseall
	end
