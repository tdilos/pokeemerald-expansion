Route93_House1_MapScripts::
	.byte 0

Route93_House1_EventScript_Pokemon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_GROWLITHE, CRY_MODE_NORMAL
	msgbox Route93_House1_Text_Pokemon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route93_House1_Text_Pokemon:
	.string "GROWLITHE: Garr garrr!$"

Route93_House1_EventScript_Farmer::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_PLUCK, Route93_House1_EventScript_ExplainPluck
	msgbox Route93_House1_Text_BerryPickin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route93_House1_EventScript_GivePluckTM
	msgbox Route93_House1_Text_Misjudged, MSGBOX_DEFAULT
	release
	end

Route93_House1_EventScript_GivePluckTM::
	msgbox Route93_House1_Text_LikeMinded, MSGBOX_DEFAULT
	giveitem ITEM_TM88
	setflag FLAG_RECEIVED_TM_PLUCK
	waitfanfare
	goto Route93_House1_EventScript_ExplainPluck
	end

Route93_House1_EventScript_ExplainPluck::
	msgbox Route93_House1_Text_ExplainPluck, MSGBOX_DEFAULT
	release
	end


Route93_House1_Text_BerryPickin:
	.string "Whenever I see BERRIES, I just want\n"
	.string "to pick them. Don't you?$"

Route93_House1_Text_Misjudged:
	.string "Really? Guess I misjudged you.$"

Route93_House1_Text_LikeMinded:
	.string "We're like-minded. Why don't\n"
	.string "ya take this with ya?$"

Route93_House1_Text_ExplainPluck:
	.string "A POKéMON that knows PLUCK can\n"
	.string "eat the opponent's BERRY and\l"
	.string "steal its effect!$"

