XanthosCity_BattleCafe_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, XanthosCity_BattleCafe_OnTransition
	.byte 0

XanthosCity_BattleCafe_OnTransition:
	goto_if_set FLAG_BADGE08_GET, XanthosCity_BattleCafe_EventScript_EnableRound3
	goto_if_set FLAG_BADGE07_GET, XanthosCity_BattleCafe_EventScript_EnableRound3
	goto_if_set FLAG_BADGE05_GET, XanthosCity_BattleCafe_EventScript_EnableRound2
	cleartrainerflag TRAINER_KENICHI_1
	settrainerflag TRAINER_KENICHI_2
	settrainerflag TRAINER_KENICHI_3
	cleartrainerflag TRAINER_GEORGETTE_1
	settrainerflag TRAINER_GEORGETTE_2
	settrainerflag TRAINER_GEORGETTE_3
	cleartrainerflag TRAINER_GARFIELD_1
	settrainerflag TRAINER_GARFIELD_2
	settrainerflag TRAINER_GARFIELD_3
	end

XanthosCity_BattleCafe_EventScript_EnableRound2:
	settrainerflag TRAINER_KENICHI_1
	cleartrainerflag TRAINER_KENICHI_2
	settrainerflag TRAINER_KENICHI_3
	settrainerflag TRAINER_GEORGETTE_1
	cleartrainerflag TRAINER_GEORGETTE_2
	settrainerflag TRAINER_GEORGETTE_3
	settrainerflag TRAINER_GARFIELD_1
	cleartrainerflag TRAINER_GARFIELD_2
	settrainerflag TRAINER_GARFIELD_3
	end

XanthosCity_BattleCafe_EventScript_EnableRound3:
	settrainerflag TRAINER_KENICHI_1
	settrainerflag TRAINER_KENICHI_2
	cleartrainerflag TRAINER_KENICHI_3
	settrainerflag TRAINER_GEORGETTE_1
	settrainerflag TRAINER_GEORGETTE_2
	cleartrainerflag TRAINER_GEORGETTE_3
	settrainerflag TRAINER_GARFIELD_1
	settrainerflag TRAINER_GARFIELD_2
	cleartrainerflag TRAINER_GARFIELD_3
	end


XanthosCity_BattleCafe_EventScript_Boy::
	lock
	faceplayer
	msgbox XanthosCity_BattleCafe_Text_EveryoneWantsToBattle, MSGBOX_DEFAULT
	release
	end

XanthosCity_BattleCafe_Text_EveryoneWantsToBattle:
	.string "I just came in here to buy some food, but\n"
	.string "everyone keeps trying to battle me...$" 

XanthosCity_BattleCafe_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart XanthosCity_BattleCafe_Shop
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
XanthosCity_BattleCafe_Shop:
	.2byte ITEM_SACHET
	.2byte ITEM_WHIPPED_DREAM
	.2byte ITEM_SWEET_APPLE
	.2byte ITEM_TART_APPLE
	.2byte ITEM_BERRY_SWEET
	.2byte ITEM_CLOVER_SWEET
	.2byte ITEM_FLOWER_SWEET
	.2byte ITEM_LOVE_SWEET
	.2byte ITEM_RIBBON_SWEET
	.2byte ITEM_STAR_SWEET
	.2byte ITEM_STRAWBERRY_SWEET
	.2byte ITEM_NONE
	release
	end


XanthosCity_BattleCafe_EventScript_Kenichi::
	trainerbattle_double TRAINER_KENICHI_1, XanthosCity_BattleCafe_Text_KenichiIntro, XanthosCity_BattleCafe_Text_KenichiDefeated, XanthosCity_BattleCafe_Text_NotEnoughMons
	trainerbattle_double TRAINER_KENICHI_2, XanthosCity_BattleCafe_Text_KenichiIntro, XanthosCity_BattleCafe_Text_KenichiDefeated, XanthosCity_BattleCafe_Text_NotEnoughMons
	trainerbattle_double TRAINER_KENICHI_3, XanthosCity_BattleCafe_Text_KenichiIntro, XanthosCity_BattleCafe_Text_KenichiDefeated, XanthosCity_BattleCafe_Text_NotEnoughMons
	msgbox XanthosCity_BattleCafe_Text_KenichiPostBattle, MSGBOX_AUTOCLOSE
	end

XanthosCity_BattleCafe_Text_KenichiIntro:
	.string "Help me practice my secret technique!$"

XanthosCity_BattleCafe_Text_KenichiDefeated:
	.string "No good!$"

XanthosCity_BattleCafe_Text_KenichiPostBattle:
	.string "This cafe is the perfect place\n"
	.string "to hone my technique.$"


XanthosCity_BattleCafe_EventScript_Georgette::
	trainerbattle_double TRAINER_GEORGETTE_1, XanthosCity_BattleCafe_Text_GeorgetteIntro, XanthosCity_BattleCafe_Text_GeorgetteDefeated, XanthosCity_BattleCafe_Text_NotEnoughMons
	trainerbattle_double TRAINER_GEORGETTE_2, XanthosCity_BattleCafe_Text_GeorgetteIntro, XanthosCity_BattleCafe_Text_GeorgetteDefeated, XanthosCity_BattleCafe_Text_NotEnoughMons
	trainerbattle_double TRAINER_GEORGETTE_3, XanthosCity_BattleCafe_Text_GeorgetteIntro, XanthosCity_BattleCafe_Text_GeorgetteDefeated, XanthosCity_BattleCafe_Text_NotEnoughMons
	msgbox XanthosCity_BattleCafe_Text_GeorgettePostBattle, MSGBOX_AUTOCLOSE
	end

XanthosCity_BattleCafe_Text_GeorgetteIntro:
	.string "Would you like to see\n"
	.string "my beautiful POKéMON?$"

XanthosCity_BattleCafe_Text_GeorgetteDefeated:
	.string "Bleh!$"

XanthosCity_BattleCafe_Text_GeorgettePostBattle:
	.string "Here at this cafe, we never\n"
	.string "get tired of battling.$"

XanthosCity_BattleCafe_Text_NotEnoughMons:
	.string "You can't battle me with only\n"
	.string "one POKéMON!$"

XanthosCity_BattleCafe_EventScript_Garfield::
	trainerbattle_double TRAINER_GARFIELD_1, XanthosCity_BattleCafe_Text_GarfieldIntro, XanthosCity_BattleCafe_Text_GarfieldDefeated, XanthosCity_BattleCafe_Text_NotEnoughMons
	trainerbattle_double TRAINER_GARFIELD_2, XanthosCity_BattleCafe_Text_GarfieldIntro, XanthosCity_BattleCafe_Text_GarfieldDefeated, XanthosCity_BattleCafe_Text_NotEnoughMons
	trainerbattle_double TRAINER_GARFIELD_3, XanthosCity_BattleCafe_Text_GarfieldIntro, XanthosCity_BattleCafe_Text_GarfieldDefeated, XanthosCity_BattleCafe_Text_NotEnoughMons
	msgbox XanthosCity_BattleCafe_Text_GarfieldPostBattle, MSGBOX_AUTOCLOSE
	end

XanthosCity_BattleCafe_Text_GarfieldIntro:
	.string "What's the rush? Why don't you\n"
	.string "stop and sit a spell?$"

XanthosCity_BattleCafe_Text_GarfieldDefeated:
	.string "Wahahahaha!$"

XanthosCity_BattleCafe_Text_GarfieldPostBattle:
	.string "Have you tried the food here?\n"
	.string "It's quite unique.\p"
	.string "I heard that certain POKéMON go\n"
	.string "crazy for it.$"






