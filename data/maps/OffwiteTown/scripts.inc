OffwiteTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OffwiteTown_OnTransition
	.byte 0

OffwiteTown_OnTransition:
	setflag FLAG_VISITED_OFFWITE_TOWN
	setflag FLAG_HIDE_MAY
	end

OffwiteTown_EventScript_TownSign::
	msgbox OffwiteTown_Text_TownSign, MSGBOX_SIGN
	end

OffwiteTown_Text_TownSign:
	.string "OFFWITE TOWN\n"
	.string "“The lonely mountain town.”$"

OffwiteTown_EventScript_Hiker::
	msgbox OffwiteTown_Text_Traveler, MSGBOX_NPC
	end

OffwiteTown_Text_Traveler:
	.string "Hoho, a new face from down\n"
	.string "the mountain.\p"
	.string "Ya don't see many of those\n"
	.string "now'days, now do ya?$"

OffwiteTown_EventScript_Woman::
	msgbox OffwiteTown_Text_FreezeToDeath, MSGBOX_NPC
	end

OffwiteTown_Text_FreezeToDeath:
	.string "Goodness! You'll freeze to death\n"
	.string "out here dressed like that!$"

OffwiteTown_EventScript_Boy::
	lock
	faceplayer
	msgbox OffwiteTown_Text_MtShiroCaves, MSGBOX_DEFAULT
	release
	end

OffwiteTown_Text_MtShiroCaves:
	.string "MT SHIRO is home to a vast\n"
	.string "network of caves.\p"
	.string "It's easy for outsiders\n"
	.string "to get lost.$"

OffwiteTown_EventScript_Girl::
	lock
	msgbox OffwiteTown_Text_ClimateTraining, MSGBOX_DEFAULT
	release
	end

OffwiteTown_Text_ClimateTraining:
	.string "Our spirits are burning up!\n"
	.string "This cold is nothing to us!$"
