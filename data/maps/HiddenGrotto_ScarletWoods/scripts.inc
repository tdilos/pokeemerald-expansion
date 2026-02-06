HiddenGrotto_ScarletWoods_MapScripts::
	.byte 0

HiddenGrotto_ScarletWoods_EventScript_GrottoBall::
	removeobject VAR_LAST_TALKED
	special HiddenGrottoWildEncounter
	goto_if_eq VAR_RESULT, FALSE, HiddenGrotto_ScarletWoods_EventScript_GiveGrottoItem
	waitstate
	setflag FLAG_DAILY_HIDDEN_GROTTO_SCARLET_WOODS
	releaseall
	end

HiddenGrotto_ScarletWoods_EventScript_GiveGrottoItem::
	special GetGrottoItem
	giveitem VAR_RESULT
	setflag FLAG_DAILY_HIDDEN_GROTTO_SCARLET_WOODS
	releaseall
	end


