Route88_MapScripts::
	.byte 0

Route88_EventScript_TrainerTipsDNS::
	msgbox Route88_Text_TrainerTipsDNS, MSGBOX_SIGN
	end

Route88_EventScript_RouteSign::
	msgbox Route88_Text_RouteSign, MSGBOX_SIGN
	end

Route88_Text_TrainerTipsDNS:
	.string "TRAINER TIPS\p"
	.string "NIGHT officially begins at 8 P.M.\n"
	.string "and lasts until 4 A.M.\p"
	.string "MORNING lasts until 10 A.M.$"

Route88_Text_RouteSign:
	.string "ROUTE 88\n"
	.string "{DOWN_ARROW} RESEDA TOWN$"

Route88_EventScript_Feliks::
	trainerbattle_single TRAINER_FELIKS, Route88_Text_FeliksIntro, Route88_Text_FeliksDefeated
	msgbox Route88_Text_FeliksPostBattle, MSGBOX_AUTOCLOSE
	end

Route88_EventScript_Sara::
	trainerbattle_double TRAINER_SARA_AND_MIA, Route88_Text_SaraAndMiaIntro, Route88_Text_SaraAndMiaDefeated, Route88_Text_SaraAndMiaNotEnoughMons
	msgbox Route88_Text_SaraPostBattle, MSGBOX_AUTOCLOSE
	end

Route88_EventScript_Mia::
	trainerbattle_double TRAINER_SARA_AND_MIA, Route88_Text_SaraAndMiaIntro, Route88_Text_SaraAndMiaDefeated, Route88_Text_SaraAndMiaNotEnoughMons
	msgbox Route88_Text_MiaPostBattle, MSGBOX_AUTOCLOSE
	end






Route88_EventScript_Ginny::
	trainerbattle_single TRAINER_GINNY, Route88_Text_GinnyIntro, Route88_Text_GinnyDefeated
	msgbox Route88_Text_GinnyPostBattle, MSGBOX_AUTOCLOSE
	end

Route88_EventScript_Farmer::
	lockall
	faceplayer
	msgbox Route88_Text_Pokeblocks, MSGBOX_NPC
	releaseall
	end

Route88_Text_Pokeblocks:
	.string "You can put BERRIES in a blender\n"
	.string "and make POKéBLOCKS.\p"
	.string "Some folks use them to spruce\n"
	.string "up their POKéMON for contests.$"


