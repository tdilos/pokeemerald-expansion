.set LOCALID_TOURIST_F, 9
.set LOCALID_TOURIST_M, 10
.set LOCALID_RANGER, 11

Route87_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route87_OnWarp
	.byte 0

Route87_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, Route87_EventScript_UnsetForceOffscreenLoad
	.2byte 0

Route87_EventScript_UnsetForceOffscreenLoad::
	clearflag FLAG_FORCE_LOAD_OFFSCREEN_OBJEV
	end



Route87_EventScript_TrainerTipsDefog::
	msgbox Route87_Text_TrainerTipsDefog, MSGBOX_SIGN
	end

Route87_Text_TrainerTipsDefog:
	.string "TRAINER TIPS\p"
	.string "A POKéMON knowing DEFOG can clear\n" 
	.string "adverse weather in the field.$"

Route87_EventScript_Seth::
	trainerbattle_single TRAINER_SETH, Route87_Text_SethIntro, Route87_Text_SethDefeated
	msgbox Route87_Text_SethPostBattle, MSGBOX_AUTOCLOSE
	end

Route87_EventScript_Megan::
	trainerbattle_single TRAINER_MEGAN, Route87_Text_MeganIntro, Route87_Text_MeganDefeated
	msgbox Route87_Text_MeganPostBattle, MSGBOX_AUTOCLOSE
	end

Route87_EventScript_Vince::
	trainerbattle_single TRAINER_VINCE, Route87_Text_VinceIntro, Route87_Text_VinceDefeated
	msgbox Route87_Text_VincePostBattle, MSGBOX_AUTOCLOSE
	end

Route87_EventScript_Nigel::
	trainerbattle_single TRAINER_NIGEL, Route87_Text_NigelIntro, Route87_Text_NigelDefeated
	msgbox Route87_Text_NigelPostBattle, MSGBOX_AUTOCLOSE
	end

Route87_EventScript_Rutherford::
	trainerbattle_single TRAINER_RUTHERFORD, Route87_Text_RutherfordIntro, Route87_Text_RutherfordDefeated
	msgbox Route87_Text_RutherfordPostBattle, MSGBOX_AUTOCLOSE
	end

Route87_EventScript_Gus::
	trainerbattle_single TRAINER_GUS, Route87_Text_GusIntro, Route87_Text_GusDefeated
	msgbox Route87_Text_GusPostBattle, MSGBOX_AUTOCLOSE
	end

Route87_EventScript_RescueCoupleLeft::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	@applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	@waitmovement 0
	goto Route87_EventScript_SteelixBattle
	end

Route87_EventScript_RescueCoupleRight::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	@applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	@waitmovement 0
	goto Route87_EventScript_SteelixBattle
	end

Route87_EventScript_SteelixBattle::
	applymovement LOCALID_TOURIST_M, Common_Movement_ExclamationMark
	@applymovement LOCALID_TOURIST_F, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	applymovement LOCALID_TOURIST_M, Common_Movement_FaceLeft
	@applymovement LOCALID_TOURIST_F, Common_Movement_FaceLeft
	waitmovement 0
	@applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	applymovement LOCALID_TOURIST_M, Common_Movement_Delay48
	@applymovement LOCALID_TOURIST_F, Common_Movement_Delay48
	waitmovement 0
	@applymovement LOCALID_TOURIST_M, Common_Movement_WalkInPlaceLeft
	@waitmovement 0
	msgbox Route87_Text_RescueCouplePreBattle, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 30
	playmoncry SPECIES_STEELIX, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 30
	seteventmon SPECIES_STEELIX, 20
	totemboost_spdef2 B_POSITION_OPPONENT_LEFT
	special BattleSetup_StartLegendaryBattle
	waitstate
	applymovement LOCALID_TOURIST_M, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_TOURIST_M, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_TOURIST_F, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_TOURIST_F, Common_Movement_WalkLeft
	waitmovement 0
	goto Route87_EventScript_CoupleRescued
	end

Route87_EventScript_RescueCouple::
	lockall
	applymovement LOCALID_TOURIST_M, Common_Movement_FaceLeft
	applymovement LOCALID_TOURIST_F, Common_Movement_FaceLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_TOURIST_M, Common_Movement_ExclamationMark
	applymovement LOCALID_TOURIST_F, Common_Movement_ExclamationMark
	waitmovement 0
	delay 60
	msgbox Route87_Text_RescueCouplePreBattle, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_STEELIX, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 30
	seteventmon SPECIES_STEELIX, 20
	totemboost_spdef1 B_POSITION_OPPONENT_LEFT
	special BattleSetup_StartLegendaryBattle
	waitstate
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	applymovement LOCALID_TOURIST_M, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_TOURIST_M, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_TOURIST_F, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_TOURIST_F, Common_Movement_WalkLeft
	waitmovement 0
	goto Route87_EventScript_CoupleRescued
	end

Route87_EventScript_CoupleRescued::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_TOURIST_M, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox Route87_Text_ManPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TOURIST_F, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox Route87_Text_WomanPostBattle, MSGBOX_DEFAULT
	giveitem ITEM_BIKE_VOUCHER
	waitfanfare
	msgbox Route87_Text_GoingToRentBike, MSGBOX_DEFAULT
	closemessage
	@applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	@waitmovement 0
	delay 30
	setobjectxyperm LOCALID_RANGER, 8, 26
	addobject LOCALID_RANGER
	applymovement LOCALID_RANGER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_RANGER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_RANGER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_RANGER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_RANGER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_RANGER, Common_Movement_WalkUp
	waitmovement 0
	@applymovement LOCALID_RANGER, Common_Movement_Delay48
	@waitmovement 0
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_TOURIST_M, Common_Movement_FaceDown
	applymovement LOCALID_TOURIST_F, Common_Movement_FaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement LOCALID_TOURIST_M, Common_Movement_ExclamationMark
	applymovement LOCALID_TOURIST_F, Common_Movement_ExclamationMark
	waitmovement 0
	@applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	@waitmovement 0
	delay 40
	msgbox Route87_Text_PokemonRanger1, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_RANGER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_TOURIST_M, Common_Movement_FaceLeft
	applymovement LOCALID_TOURIST_F, Common_Movement_FaceLeft
	applymovement LOCALID_RANGER, Common_Movement_FaceRight
	delay 40
	applymovement LOCALID_RANGER, Common_Movement_FaceUp
	waitmovement 0
	msgbox Route87_Text_PokemonRanger2, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	@setflag FLAG_RESCUED_DESERT_COUPLE
	removeobject LOCALID_RANGER
	removeobject LOCALID_TOURIST_M
	removeobject LOCALID_TOURIST_F
	@setobjectxyperm LOCALID_RANGER, 39, 37
	@setobjectxyperm LOCALID_TOURIST_M, 39, 37
	@setobjectxyperm LOCALID_TOURIST_F, 39, 37
	fadescreen FADE_FROM_BLACK
	setvar VAR_ROUTE87_STATE, 2
	@questmenu QUEST_MENU_COMPLETE_QUEST QUEST_10
	completequest QUEST_10
	release
	end
	
Route87_Text_RescueCouplePreBattle:
	.string "Honey look, someone's there!\p"
	.string "Hey, watch out!\n"
	.string "It's dangerous out here!\p"
	.string "...\p"
	.string "Oh no, I think it's coming back!$"

Route87_Text_ManPostBattle:
	.string "Oh, thank you. We were trapped here and\n"
	.string "that POKéMON wouldn't let us leave.$"

Route87_Text_WomanPostBattle:
	.string "We have to thank this trainer somehow.\p"
	.string "I know! You can have this!$"

Route87_Text_GoingToRentBike:
	.string "That BIKE VOUCHER can be traded in for\n"
	.string "a BIKE at the shop in AMBER CITY.\p"
	.string "We were planning to ride out to the\n"
	.string "sand dunes together.\p"
	.string "But I really just want to go home now...$"

Route87_Text_PokemonRanger1:
	.string "Ah-ha, I finally found you!\p"
	.string "...\p"
	.string "Oh, you're that trainer from before.\p"
	.string "...\p"
	.string "You took on a giant STEELIX all by\n"
	.string "yourself?\p"
	.string "Not bad, kid.\p"
	.string "You have the makings of a\n"
	.string "POKéMON RANGER in you.$"

Route87_Text_PokemonRanger2:		
	.string "I'll take things from here.\n"
	.string "Thanks for the help, kid.\p"
	.string "You should stop by our headquarters\n"
	.string "in MAROON CITY some time.$"


