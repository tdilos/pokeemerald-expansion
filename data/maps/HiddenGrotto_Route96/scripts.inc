HiddenGrotto_Route96_MapScripts::
	.byte 0

HiddenGrotto_Route96_EventScript_GrottoBall::
	removeobject VAR_LAST_TALKED
	special HiddenGrottoWildEncounter
	goto_if_eq VAR_RESULT, FALSE, HiddenGrotto_Route96_EventScript_GiveGrottoItem
	waitstate
	setflag FLAG_DAILY_HIDDEN_GROTTO_ROUTE_96
	releaseall
	end

HiddenGrotto_Route96_EventScript_GiveGrottoItem::
	special GetGrottoItem
	giveitem VAR_RESULT
	setflag FLAG_DAILY_HIDDEN_GROTTO_ROUTE_96
	releaseall
	end
