.set LOCALID_GUARD, 1
.set LOCALID_JUSTIN, 11
.set LOCALID_JACE, 12
.set LOCALID_ROBIN, 13
.set LOCALID_RANGER1, 14
.set LOCALID_RANGER2, 15
.set LOCALID_RANGER3, 16
.set LOCALID_RANGER4, 17
.set LOCALID_RANGER5, 18
.set LOCALID_RANGER6, 19

XanthosCity_XanthosUnderground_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, XanthosCity_XanthosUnderground_OnTransition
	@map_script MAP_SCRIPT_ON_FRAME_TABLE, XanthosCity_XanthosUnderground_OnFrame
	.byte 0

@XanthosCity_XanthosUnderground_OnFrame:
@	map_script_2 VAR_RANGER_HQ_STATE, 3, XanthosCity_XanthosUnderground_EventScript_PreRaid
@	.2byte 0

	@ State descriptions for VAR_RANGER_HQ_STATE
	@ 0: Before meeting Justin
	@ 1: After receiving mission from Justin
	@ 2: After returning from Pokemon Laboratory
	@ 3: Justin and rangers in Xanthos Underground shopping center
	@ 4: Justin and rangers talking to Azami
	@ 5: Before freeing Mew
	@ 6: Before encountering Zartosht/Neda
	@ 7: Before battling Azami
	@ 8: After clearing Underground City
	@ 9: After everyone leaves and Brendan directs you to Dun Town

XanthosCity_XanthosUnderground_OnTransition:
	call_if_eq VAR_RANGER_HQ_STATE, 3, XanthosCity_XanthosUnderground_EventScript_PreRaidSetup
	call_if_ge VAR_RANGER_HQ_STATE, 4, XanthosCity_XanthosUnderground_EventScript_MoveGuard
	end

XanthosCity_XanthosUnderground_EventScript_HideJaceAndRangers:
	setflag FLAG_HIDE_JACE
	removeobject LOCALID_JUSTIN
	removeobject LOCALID_JACE
	removeobject LOCALID_ROBIN
	removeobject LOCALID_RANGER1
	removeobject LOCALID_RANGER2
	removeobject LOCALID_RANGER3
	removeobject LOCALID_RANGER4
	removeobject LOCALID_RANGER5
	removeobject LOCALID_RANGER6
	return

XanthosCity_XanthosUnderground_EventScript_MoveGuard:
	removeobject LOCALID_GUARD
	setobjectxyperm LOCALID_GUARD, 18, 13
	setobjectmovementtype LOCALID_GUARD, MOVEMENT_TYPE_FACE_LEFT
	addobject LOCALID_GUARD
	return
	
XanthosCity_XanthosUnderground_EventScript_PreRaidSetup:
	clearflag FLAG_HIDE_JACE
	setobjectxyperm LOCALID_JUSTIN, 17, 16
	setobjectmovementtype LOCALID_JUSTIN, MOVEMENT_TYPE_FACE_UP
	addobject LOCALID_JUSTIN
	setobjectxyperm LOCALID_JACE, 18, 17
	setobjectmovementtype LOCALID_JACE, MOVEMENT_TYPE_FACE_UP
	setobjectxyperm LOCALID_ROBIN, 18, 16
	setobjectmovementtype LOCALID_ROBIN, MOVEMENT_TYPE_FACE_UP
	setobjectxyperm LOCALID_RANGER1, 18, 18
	setobjectmovementtype LOCALID_RANGER, MOVEMENT_TYPE_FACE_UP
	setobjectxyperm LOCALID_RANGER2, 17, 17
	setobjectmovementtype LOCALID_RANGER, MOVEMENT_TYPE_FACE_UP
	setobjectxyperm LOCALID_RANGER3, 17, 18
	setobjectmovementtype LOCALID_RANGER, MOVEMENT_TYPE_FACE_UP
	setobjectxyperm LOCALID_RANGER4, 16, 16
	setobjectmovementtype LOCALID_RANGER, MOVEMENT_TYPE_FACE_UP
	setobjectxyperm LOCALID_RANGER5, 16, 17
	setobjectmovementtype LOCALID_RANGER, MOVEMENT_TYPE_FACE_UP
	setobjectxyperm LOCALID_RANGER6, 16, 18
	setobjectmovementtype LOCALID_RANGER, MOVEMENT_TYPE_FACE_UP
	addobject LOCALID_JACE
	addobject LOCALID_ROBIN
	addobject LOCALID_RANGER1
	addobject LOCALID_RANGER2
	addobject LOCALID_RANGER3
	addobject LOCALID_RANGER4
	addobject LOCALID_RANGER5
	addobject LOCALID_RANGER6
	return




XanthosCity_XanthosUnderground_EventScript_PreRaid::
	lockall
	delay 60
	applymovement LOCALID_GUARD, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_GUARD, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_GUARD, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_GUARD, Common_Movement_FaceLeft
	waitmovement 0
	delay 30
	applymovement LOCALID_JUSTIN, XanthosCity_XanthosUnderground_Movement_JustinWalkToElevator
	delay 30
	applymovement LOCALID_RANGER4, XanthosCity_XanthosUnderground_Movement_Ranger4WalkToElevator
	delay 30
	applymovement LOCALID_ROBIN, XanthosCity_XanthosUnderground_Movement_RobinWalkToElevator
	delay 30
	applymovement LOCALID_JACE, XanthosCity_XanthosUnderground_Movement_JaceWalkToElevator
	delay 30
	applymovement LOCALID_RANGER2, XanthosCity_XanthosUnderground_Movement_Ranger2WalkToElevator
	delay 30
	applymovement LOCALID_RANGER3, XanthosCity_XanthosUnderground_Movement_Ranger3WalkToElevator
	delay 30
	applymovement LOCALID_RANGER1, XanthosCity_XanthosUnderground_Movement_Ranger1WalkToElevator
	delay 30
	applymovement LOCALID_RANGER5, XanthosCity_XanthosUnderground_Movement_Ranger5WalkToElevator
	delay 30
	applymovement LOCALID_RANGER6, XanthosCity_XanthosUnderground_Movement_Ranger6WalkToElevator
	delay 90
	setvar VAR_RANGER_HQ_STATE, 4
	call XanthosCity_XanthosUnderground_EventScript_HideJaceAndRangers
	releaseall
	end

XanthosCity_XanthosUnderground_Movement_JustinWalkToElevator:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

XanthosCity_XanthosUnderground_Movement_Ranger4WalkToElevator:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

XanthosCity_XanthosUnderground_Movement_RobinWalkToElevator:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

XanthosCity_XanthosUnderground_Movement_JaceWalkToElevator:
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

XanthosCity_XanthosUnderground_Movement_Ranger2WalkToElevator:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

XanthosCity_XanthosUnderground_Movement_Ranger3WalkToElevator:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

XanthosCity_XanthosUnderground_Movement_Ranger1WalkToElevator:
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

XanthosCity_XanthosUnderground_Movement_Ranger5WalkToElevator:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

XanthosCity_XanthosUnderground_Movement_Ranger6WalkToElevator:
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

XanthosCity_XanthosUnderground_EventScript_PlayerWalkToElevator::
	applymovement OBJ_EVENT_ID_PLAYER, XanthosCity_XanthosUnderground_Movement_PlayerWalkToElevator
	waitmovement 0
	opendoor 17, 2
	waitdooranim
	@applymovement OBJ_EVENT_ID_PLAYER, XanthosCity_XanthosUnderground_Movement_PlayerWalkIntoElevator
	@waitmovement 0
	@hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
	@closedoor 17, 2
	@waitdooranim

	warp MAP_UNDERGROUND_CITY_ENTRANCE, 6, 1
	waitstate
	releaseall
	end

XanthosCity_XanthosUnderground_Movement_PlayerWalkToElevator:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

XanthosCity_XanthosUnderground_Movement_PlayerWalkIntoElevator:
	walk_up
	face_down
	step_end






XanthosCity_XanthosUnderground_EventScript_Guard::
	goto_if_ge VAR_RANGER_HQ_STATE, 4, XanthosCity_XanthosUnderground_EventScript_GuardPostRaid
	msgbox XanthosCity_XanthosUnderground_Text_ClosedToPublic, MSGBOX_NPC
	end

XanthosCity_XanthosUnderground_Text_ClosedToPublic:
	.string "I'm sorry. This area is off limits\n"
	.string "to the general public.$"

XanthosCity_XanthosUnderground_EventScript_GuardPostRaid::
	msgbox XanthosCity_XanthosUnderground_Text_GuardPostRaid, MSGBOX_NPC
	end

XanthosCity_XanthosUnderground_Text_GuardPostRaid:
	.string "To think that TEAM GENESIS was hiding\n"
	.string "beneath the city the entire time!$"

XanthosCity_XanthosUnderground_EventScript_TMClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart XanthosCity_XanthosUnderground_TMshop
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
XanthosCity_XanthosUnderground_TMshop:
	.2byte ITEM_TM23  @ Mimic
	.2byte ITEM_TM45  @ Attract
	.2byte ITEM_TM77  @ Psych Up
	.2byte ITEM_TM97  @ Block
	.2byte ITEM_NONE
	release
	end

XanthosCity_XanthosUnderground_EventScript_HerbSeller::
	lock
	faceplayer
	goto_if_set FLAG_IS_CHAMPION, XanthosCity_XanthosUnderground_EventScript_HerbSellerPostgame
	message gText_HowMayIServeYou
	waitmessage
	pokemart XanthosCity_XanthosUnderground_HerbShop
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
XanthosCity_XanthosUnderground_HerbShop:
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_REVIVAL_HERB
	.2byte ITEM_NONE
	release
	end

XanthosCity_XanthosUnderground_EventScript_HerbSellerPostgame::
	message gText_HowMayIServeYou
	waitmessage
	pokemart XanthosCity_XanthosUnderground_HerbShopPostgame
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
XanthosCity_XanthosUnderground_HerbShopPostgame:
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_REVIVAL_HERB
	.2byte ITEM_WHITE_HERB
	.2byte ITEM_MENTAL_HERB
	.2byte ITEM_NONE
	release
	end



XanthosCity_XanthosUnderground_EventScript_Hairdresser::
	goto_if_set FLAG_DAILY_MASSAGE, XanthosCity_XanthosUnderground_EventScript_OnePokemonPerDay
	msgbox XanthosCity_XanthosUnderground_Text_LikeMeToGroomMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, XanthosCity_XanthosUnderground_EventScript_DeclineGrooming
	msgbox XanthosCity_XanthosUnderground_Text_GroomWhichOne, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	goto_if_ge VAR_0x8004, PARTY_SIZE, XanthosCity_XanthosUnderground_EventScript_DeclineGrooming
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, XanthosCity_XanthosUnderground_EventScript_CantGroomEgg
	msgbox XanthosCity_XanthosUnderground_Text_LookingNiceInNoTime, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special DailyMassageService
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox XanthosCity_XanthosUnderground_Text_ThereYouGoAllDone, MSGBOX_DEFAULT
	setflag FLAG_DAILY_MASSAGE
	release
	end

XanthosCity_XanthosUnderground_EventScript_CantGroomEgg::
	msgbox XanthosCity_XanthosUnderground_Text_CantGroomAnEgg, MSGBOX_DEFAULT
	release
	end

XanthosCity_XanthosUnderground_EventScript_DeclineGrooming::
	msgbox XanthosCity_XanthosUnderground_Text_DontNeedAnyGrooming, MSGBOX_DEFAULT
	release
	end

XanthosCity_XanthosUnderground_EventScript_OnePokemonPerDay::
	msgbox XanthosCity_XanthosUnderground_Text_OnePokemonPerDay, MSGBOX_DEFAULT
	release
	end

XanthosCity_XanthosUnderground_Text_LikeMeToGroomMon:
    .string "Hi, I'm a hair dresser.\p"
    .string "I can spruce up one of your\n"
    .string "POKéMON for just ¥500.\p"
    .string "Would you like me to groom one?$"

XanthosCity_XanthosUnderground_Text_DontNeedAnyGrooming:
    .string "Oh? But your POKéMON will love it!\n"
    .string "Trust me.$"

XanthosCity_XanthosUnderground_Text_GroomWhichOne:
    .string "Which one should I groom?$"

XanthosCity_XanthosUnderground_Text_LookingNiceInNoTime:
    .string "Okay, I'll get it looking\n"
    .string "nice in no time.$"

XanthosCity_XanthosUnderground_Text_ThereYouGoAllDone:
    .string "{STR_VAR_1} looks dreamily content…\p"
    .string "There you go! All done.\n"
    .string "See? Doesn't it look nice?\p"
    .string "Giggle…\n"
    .string "It's such a cute POKéMON.$"

XanthosCity_XanthosUnderground_Text_CantGroomAnEgg:
    .string "Oh, sorry. I honestly can't\n"
    .string "groom an EGG.$"

XanthosCity_XanthosUnderground_Text_OnePokemonPerDay:
    .string "I only groom one POKéMON per trainer\n"
    .string "per day.\p"
    .string "Come back tomorrow if you want me to\n"
    .string "beautify more of your POKéMON.$"







XanthosCity_XanthosUnderground_EventScript_Boy::
	lock
	faceplayer
	msgbox XanthosCity_XanthosUnderground_Text_TMs, MSGBOX_DEFAULT
	release
	end

XanthosCity_XanthosUnderground_Text_TMs:
    .string "There are lots of cool TMs that\n"
    .string "you can teach your POKéMON.\p"
    .string "It's too bad they can't learn more\n"
    .string "than four moves at a time.$"

XanthosCity_XanthosUnderground_EventScript_Man2::
	lock
	faceplayer
	msgbox XanthosCity_XanthosUnderground_Text_Plaza, MSGBOX_DEFAULT
	release
	end

XanthosCity_XanthosUnderground_Text_Plaza:
    .string "Believe it or not, this plaza used to be\n"
    .string "the top floor of an old building.\p"
    .string "A natural disaster caused it to sink\n"
    .string "into the sea a long time ago.$"


XanthosCity_XanthosUnderground_EventScript_Man::
	lock
	faceplayer
	msgbox XanthosCity_XanthosUnderground_Text_Friendship, MSGBOX_DEFAULT
	release
	end

XanthosCity_XanthosUnderground_Text_Friendship:
    .string "Your POKéMON will grow to love\n"
    .string "you if you raise them well.\p"
    .string "But treating them harshly will\n"
    .string "lower their trust in you.$"

XanthosCity_XanthosUnderground_EventScript_OldWoman::
	lock
	faceplayer
	msgbox XanthosCity_XanthosUnderground_Text_ThatMeansItsWorking, MSGBOX_DEFAULT
	release
	end

XanthosCity_XanthosUnderground_Text_ThatMeansItsWorking:
    .string "If it's bitter and hard to swallow,\n"
    .string "that means it's working.\p"
    .string "That herb seller over there is an expert.\n"
    .string "I'm sure he knows best.$"

XanthosCity_XanthosUnderground_EventScript_Wynaut::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WYNAUT, CRY_MODE_NORMAL
	msgbox XanthosCity_XanthosUnderground_Text_Wynaut, MSGBOX_DEFAULT
	waitmoncry
	release
	end

XanthosCity_XanthosUnderground_Text_Wynaut:
	.string "WYNAUT: Wyy wyyy...$"







XanthosCity_XanthosUnderground_EventScript_MushroomManiac::
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_7
	goto_if_eq VAR_RESULT, TRUE, XanthosCity_XanthosUnderground_EventScript_QuestComplete
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_7
	goto_if_eq VAR_RESULT, TRUE, XanthosCity_XanthosUnderground_EventScript_QuestInProgress
	msgbox XanthosCity_XanthosUnderground_Text_ExquisiteDish, MSGBOX_DEFAULT
	@questmenu QUEST_MENU_UNLOCK_QUEST QUEST_7
	@openquestmenu
	startquest QUEST_7
	release
	end

XanthosCity_XanthosUnderground_Text_ExquisiteDish:
	.string "An exquisite dish.\n"
	.string "That's what I desire to make.\p"
	.string "But alas, I don't have all the ingredients.\n"
	.string "I still need 10 BIG MUSHROOMS.\p"
	.string "Maybe you can help me?\p"
	.string "If you bring me 10 BIG MUSHROOMS,\n"
	.string "I'll share some with you.\p"
	.string "It's delicious and nutritious,\n"
	.string "I promise you.$"

XanthosCity_XanthosUnderground_EventScript_QuestInProgress::
	checkitem ITEM_BIG_MUSHROOM, 10
	goto_if_eq VAR_RESULT, TRUE, XanthosCity_XanthosUnderground_EventScript_GetReward
	msgbox XanthosCity_XanthosUnderground_Text_NotEnough, MSGBOX_DEFAULT
	release
	end

XanthosCity_XanthosUnderground_Text_NotEnough:
	.string "Ah, that's not enough!\p"
	.string "I need 10 BIG MUSHROOMS.\n"
	.string "No less will do!$"

XanthosCity_XanthosUnderground_EventScript_GetReward::
	msgbox XanthosCity_XanthosUnderground_Text_WellDone, MSGBOX_DEFAULT
	removeitem ITEM_BIG_MUSHROOM, 10
	giveitem ITEM_PROTEIN, 20
	@questmenu QUEST_MENU_COMPLETE_QUEST QUEST_7
	completequest QUEST_7
	release
	end	

XanthosCity_XanthosUnderground_Text_WellDone:
	.string "Ah, you've brought the mushrooms!\p"
	.string "Hold on, this will take just a few minutes.\p"
	.string "\p"
	.string "\p"
	.string "\p"
	.string "\p"
	.string "\p"
	.string "There, a delicious stew.\n"
	.string "A bowl for me, and a bowl for you.\p"
	.string "And take these for your POKéMON too.$"

XanthosCity_XanthosUnderground_EventScript_QuestComplete::
	msgbox XanthosCity_XanthosUnderground_Text_Nutrition, MSGBOX_DEFAULT
	release
	end	

XanthosCity_XanthosUnderground_Text_Nutrition:
	.string "Nutrition is important, I always say.\p"
	.string "Give those PROTEINS to your POKéMON,\n"
	.string "and they'll become much stronger!$"














XanthosCity_XanthosUnderground_EventScript_VendingMachine::
	lockall
	message XanthosCity_XanthosUnderground_Text_WhichDrinkWouldYouLike
	waitmessage
	showmoneybox 0, 0
	goto XanthosCity_XanthosUnderground_EventScript_ChooseDrink
	end

XanthosCity_XanthosUnderground_EventScript_ChooseDrink::
	multichoice 16, 0, MULTI_VENDING_MACHINE, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, XanthosCity_XanthosUnderground_EventScript_FreshWater
	case 1, XanthosCity_XanthosUnderground_EventScript_SodaPop
	case 2, XanthosCity_XanthosUnderground_EventScript_Lemonade
	msgbox XanthosCity_XanthosUnderground_Text_DecidedAgainstBuyingDrink, MSGBOX_DEFAULT
	goto XanthosCity_XanthosUnderground_EventScript_ExitVendingMachine
	end

XanthosCity_XanthosUnderground_EventScript_FreshWater::
	setvar VAR_TEMP_0, ITEM_FRESH_WATER
	goto XanthosCity_XanthosUnderground_EventScript_TryBuyDrink
	end

XanthosCity_XanthosUnderground_EventScript_SodaPop::
	setvar VAR_TEMP_0, ITEM_SODA_POP
	goto XanthosCity_XanthosUnderground_EventScript_TryBuyDrink
	end

XanthosCity_XanthosUnderground_EventScript_Lemonade::
	setvar VAR_TEMP_0, ITEM_LEMONADE
	goto XanthosCity_XanthosUnderground_EventScript_TryBuyDrink
	end

XanthosCity_XanthosUnderground_EventScript_CheckMoneyFreshWater::
	checkmoney 200
	return

XanthosCity_XanthosUnderground_EventScript_CheckMoneySodaPop::
	checkmoney 300
	return

XanthosCity_XanthosUnderground_EventScript_CheckMoneyLemonade::
	checkmoney 350
	return

XanthosCity_XanthosUnderground_EventScript_RemoveMoneyFreshWater::
	removemoney 200
	return

XanthosCity_XanthosUnderground_EventScript_RemoveMoneySodaPop::
	removemoney 300
	return

XanthosCity_XanthosUnderground_EventScript_RemoveMoneyLemonade::
	removemoney 350
	return

XanthosCity_XanthosUnderground_EventScript_TryBuyDrink::
	call_if_eq VAR_TEMP_1, 0, XanthosCity_XanthosUnderground_EventScript_CheckMoneyFreshWater
	call_if_eq VAR_TEMP_1, 1, XanthosCity_XanthosUnderground_EventScript_CheckMoneySodaPop
	call_if_eq VAR_TEMP_1, 2, XanthosCity_XanthosUnderground_EventScript_CheckMoneyLemonade
	goto_if_eq VAR_RESULT, FALSE, XanthosCity_XanthosUnderground_EventScript_NotEnoughMoneyForDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, FALSE, XanthosCity_XanthosUnderground_EventScript_NoRoomForDrink
	call_if_eq VAR_TEMP_1, 0, XanthosCity_XanthosUnderground_EventScript_RemoveMoneyFreshWater
	call_if_eq VAR_TEMP_1, 1, XanthosCity_XanthosUnderground_EventScript_RemoveMoneySodaPop
	call_if_eq VAR_TEMP_1, 2, XanthosCity_XanthosUnderground_EventScript_RemoveMoneyLemonade
	updatemoneybox
	bufferitemname STR_VAR_1, VAR_TEMP_0
	playse SE_VEND
	msgbox XanthosCity_XanthosUnderground_Text_CanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 64  @ 1/64 chance of an additional drink dropping
	goto_if_ne VAR_RESULT, 0, XanthosCity_XanthosUnderground_EventScript_ChooseNewDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, FALSE, XanthosCity_XanthosUnderground_EventScript_NoRoomForDrink
	playse SE_VEND
	msgbox XanthosCity_XanthosUnderground_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 64  @ 1/64 * the prev 1/64 chance of a third additional drink dropping, ~ 0.02% chance
	goto_if_ne VAR_RESULT, 0, XanthosCity_XanthosUnderground_EventScript_ChooseNewDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, 0, XanthosCity_XanthosUnderground_EventScript_NoRoomForDrink
	playse SE_VEND
	msgbox XanthosCity_XanthosUnderground_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	goto XanthosCity_XanthosUnderground_EventScript_ChooseNewDrink
	end

XanthosCity_XanthosUnderground_EventScript_ChooseNewDrink::
	message XanthosCity_XanthosUnderground_Text_WhichDrinkWouldYouLike
	waitmessage
	goto XanthosCity_XanthosUnderground_EventScript_ChooseDrink
	end

XanthosCity_XanthosUnderground_EventScript_NotEnoughMoneyForDrink::
	msgbox XanthosCity_XanthosUnderground_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto XanthosCity_XanthosUnderground_EventScript_ExitVendingMachine
	end

XanthosCity_XanthosUnderground_EventScript_NoRoomForDrink::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	goto XanthosCity_XanthosUnderground_EventScript_ExitVendingMachine
	end

XanthosCity_XanthosUnderground_EventScript_ExitVendingMachine::
	hidemoneybox
	releaseall
	end

XanthosCity_XanthosUnderground_Text_WhichDrinkWouldYouLike:
	.string "It's a VENDING MACHINE.\n"
	.string "Which drink would you like?$"

XanthosCity_XanthosUnderground_Text_CanOfDrinkDroppedDown:
	.string "Clang!\p"
	.string "A can of {STR_VAR_1} dropped down.$"

XanthosCity_XanthosUnderground_Text_ExtraCanOfDrinkDroppedDown:
	.string "Clang!\p"
	.string "Score! An extra can of {STR_VAR_1}\n"
	.string "dropped down!$"

XanthosCity_XanthosUnderground_Text_NotEnoughMoney:
	.string "Not enough money…$"

XanthosCity_XanthosUnderground_Text_DecidedAgainstBuyingDrink:
	.string "Decided against buying a drink.$"
