ScarletTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ScarletTown_OnTransition
	.byte 0

ScarletTown_OnTransition:
	setflag FLAG_VISITED_SCARLET_TOWN
	end

ScarletTown_EventScript_TownSign::
	msgbox ScarletTown_Text_TownSign, MSGBOX_SIGN
	end

ScarletTown_Text_TownSign:
	.string "SCARLET TOWN\n"
	.string "“Outpost town in rustic red.”$"

ScarletTown_EventScript_Hiker::
	msgbox ScarletTown_Text_Relax, MSGBOX_NPC
	end

ScarletTown_Text_Relax:
	.string "When you find yourself worrying\n"
	.string "about the future,\p"
	.string "Take some time to appreciate\n"
	.string "the little things you have.$"

ScarletTown_EventScript_Woman::
	msgbox ScarletTown_Text_RedLeaves, MSGBOX_NPC
	end

ScarletTown_Text_RedLeaves:
	.string "The leaves here are always red?\p"
	.string "What could that mean?$"

ScarletTown_EventScript_Farmer::
	msgbox ScarletTown_Text_OffTheGrid, MSGBOX_NPC
	end

ScarletTown_Text_OffTheGrid:
	.string "Do you know the best thing about\n"
	.string "living in SCARLET TOWN?\p"
	.string "It's far off the grid from places\n"
	.string "like PITCHBLAK CITY.\p"
	.string "Those KENDOM scientists with their\n"
	.string "mind reading rays and whatnot.\p"
	.string "Whatever secret projects they're doing,\n"
	.string "it's bad news for the rest of us.$" 





ScarletTown_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_WAILMER_PAIL, ScarletTown_EventScript_ExplainWailmerPail
	msgbox ScarletTown_Text_GiveBackToNature, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, ScarletTown_EventScript_GiveWailmerPail
	msgbox ScarletTown_Text_KidsTheseDays, MSGBOX_DEFAULT
	release
	end

ScarletTown_EventScript_GiveWailmerPail::
	msgbox ScarletTown_Text_ILikeYou, MSGBOX_DEFAULT
	giveitem ITEM_WAILMER_PAIL
	setflag FLAG_RECEIVED_WAILMER_PAIL
	waitfanfare
	goto ScarletTown_EventScript_ExplainWailmerPail
	end

ScarletTown_EventScript_ExplainWailmerPail::
	msgbox ScarletTown_Text_ExplainWailmerPail, MSGBOX_DEFAULT
	release
	end

ScarletTown_Text_GiveBackToNature:
	.string "It's important that we give\n"
	.string "back to the trees.\p"
	.string "Don't you agree?$"

ScarletTown_Text_KidsTheseDays:
	.string "Hmph. Children today have no\n"
	.string "respect for nature.$"

ScarletTown_Text_ILikeYou:
	.string "You're a good kid. Why don't\n"
	.string "you take this with you?$"

ScarletTown_Text_ExplainWailmerPail:
	.string "Use that WAILMER PAIL to\n"
	.string "water BERRY TREES.\p"
	.string "The tree will be so happy,\n"
	.string "it will grow twice as fast!$"



