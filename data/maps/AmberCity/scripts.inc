.set LOCALID_JACE, 6

AmberCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AmberCity_OnTransition
	.byte 0

AmberCity_OnTransition:
	setflag FLAG_VISITED_AMBER_CITY
	@removeobject LOCALID_JACE
	call_if_ge VAR_JACE_STATE, 1, AmberCity_EventScript_HideJace
	special GetWeekday
	goto_if_eq VAR_RESULT, 4, AmberCity_EventScript_RevealWeekdaySibling
	goto AmberCity_EventScript_HideWeekdaySibling
	end

AmberCity_EventScript_HideJace:
	setflag FLAG_HIDE_JACE
	return

AmberCity_EventScript_RevealWeekdaySibling:
	clearflag FLAG_HIDE_WEEKDAY_SIBLING
	end

AmberCity_EventScript_HideWeekdaySibling:
	setflag FLAG_HIDE_WEEKDAY_SIBLING
	end

AmberCity_EventScript_Thora::
	lock
	faceplayer
	special GetWeekday
	goto_if_eq VAR_RESULT, 4, AmberCity_EventScript_TryGiveItem
	msgbox AmberCity_Text_WrongWeekday, MSGBOX_DEFAULT
	release
	end

AmberCity_EventScript_TryGiveItem::
	goto_if_set FLAG_DAILY_WEEKDAY_SIBLING_ITEM, AmberCity_EventScript_WeekdaySiblingPostItem
	msgbox AmberCity_Text_WeekdaySiblingItemGive, MSGBOX_DEFAULT
	giveitem ITEM_POISON_BARB
	setflag FLAG_DAILY_WEEKDAY_SIBLING_ITEM
	msgbox AmberCity_Text_WeekdaySiblingExplainItem, MSGBOX_DEFAULT
	release
	end

AmberCity_EventScript_WeekdaySiblingPostItem::
	msgbox AmberCity_Text_WeekdaySiblingPostItem, MSGBOX_DEFAULT
	release
	end	

AmberCity_Text_WrongWeekday:
	.string "It seems Thursday's come and gone...$"

AmberCity_Text_WeekdaySiblingItemGive:
	.string "Hey there, trainer.\n"
	.string "I'm Thora of Thursday.\p"
	.string "I'd like you to take this with you.$"

AmberCity_Text_WeekdaySiblingExplainItem:
	.string "That POISON BARB boosts the\n"
	.string "power of Poison type moves.\p"
	.string "It will be a real thorn in\n"
	.string "your opponent's side!$"

AmberCity_Text_WeekdaySiblingPostItem:
	.string "Being the middle child can be\n"
	.string "a real thorn in your side too.\p"
	.string "You have younger siblings who nag you\n"
	.string "and older siblings who boss you around.$"











	






AmberCity_EventScript_GymSign::
	msgbox AmberCity_Text_GymSign, MSGBOX_SIGN
	end

AmberCity_Text_GymSign:
	.string "AMBER CITY POKéMON GYM\n"
	.string "LEADER: TARA\l"
	.string "“The ace archeologist!”$"

AmberCity_EventScript_TownSign::
	msgbox AmberCity_Text_TownSign, MSGBOX_SIGN
	end

AmberCity_Text_TownSign:
	.string "AMBER CITY\n"
	.string "“The city in a sea of sand.”$"

AmberCity_EventScript_BikeShopSign::
	msgbox AmberCity_Text_BikeShopSign, MSGBOX_SIGN
	end

AmberCity_Text_BikeShopSign:
	.string "AMBER CITY WHEELS\n"
	.string "“We'll help you get there!”$"

AmberCity_EventScript_MuseumSign::
	msgbox AmberCity_Text_MuseumSign, MSGBOX_SIGN
	end

AmberCity_Text_MuseumSign:
	.string "AMBER CITY MUSEUM\p"
	.string "“Come see wonders of the ancient world!”$"

AmberCity_EventScript_Salesman::
	msgbox AmberCity_Text_AskInside, MSGBOX_NPC
	end

AmberCity_Text_AskInside:
	.string "Welcome to AMBER CITY WHEELS!\p"
	.string "If you'd like to buy a bike,\n"
	.string "talk to our team member inside.$"


AmberCity_EventScript_Hiker::
	msgbox AmberCity_Text_LostInDesert, MSGBOX_NPC
	end

AmberCity_Text_LostInDesert:
	.string "What's this talk I hear of\n"
	.string "people lost in the desert?\p"
	.string "The desert ain't no beach resort,\n"
	.string "says I!\p"
	.string "If you go out there, you'd better\n"
	.string "make sure you're prepared!$"



AmberCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM05, AmberCity_EventScript_ExplainRoar
	msgbox AmberCity_Text_WildPokemonRunAmok, MSGBOX_DEFAULT
	giveitem ITEM_TM05
	setflag FLAG_RECEIVED_TM05
	waitfanfare
	goto AmberCity_EventScript_ExplainRoar
	end

AmberCity_EventScript_ExplainRoar::
	msgbox AmberCity_Text_ExplainRoar, MSGBOX_DEFAULT
	release
	end

AmberCity_EventScript_Pokemon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_GROWLITHE, CRY_MODE_NORMAL
	msgbox AmberCity_Text_Pokemon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

AmberCity_Text_WildPokemonRunAmok:
	.string "Wild POKéMON come out at night\n"
	.string "and run amok.\p"
	.string "I have my GROWLITHE here use ROAR\n"
	.string "to scare them off.\p"
	.string "Here, you can use it too!$"

AmberCity_Text_ExplainRoar:
	.string "That TM contains ROAR.\p"
	.string "It's a move that causes any POKéMON\n"
	.string "to flee instantly.\p"
	.string "Use it to scare off wild POKéMON!$"

AmberCity_Text_Pokemon:
	.string "GROWLITHE: Garr garrr!$"

AmberCity_EventScript_Boy::
	lockall
	faceplayer
	msgbox AmberCity_Text_BikePrices, MSGBOX_DEFAULT
	closemessage
	release
	end

AmberCity_Text_BikePrices:
	.string "I really wanted to buy a bike, but the\n"
	.string "the prices they showed me were insane.\p"
	.string "How does anyone afford these?$"


@AmberCity_EventScript_JaceTrigger::
@	goto_if_unset FLAG_RECEIVED_HM06, AmberCity_EventScript_JaceEncounter
@	end

AmberCity_EventScript_JaceEncounter::
	lockall
	clearflag FLAG_HIDE_JACE
	playse SE_SLIDING_DOOR
	setobjectxyperm LOCALID_JACE, 5, 12
	addobject LOCALID_JACE
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, AmberCity_Movement_PlayerBackOff
	applymovement LOCALID_JACE, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	delay 12
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	msgbox AmberCity_Text_JacePreBattle, MSGBOX_DEFAULT
	closemessage
	switch VAR_STARTER_MON
	case 0, AmberCity_EventScript_StartJaceBattleChespin
	case 1, AmberCity_EventScript_StartJaceBattleTepig
	case 2, AmberCity_EventScript_StartJaceBattlePopplio
	end

AmberCity_EventScript_StartJaceBattleChespin::
	trainerbattle_no_intro TRAINER_JACE_AMBER_CITY_CHESPIN, AmberCity_Text_JaceDefeated
	goto AmberCity_EventScript_JacePostBattle
	end

AmberCity_EventScript_StartJaceBattleTepig::
	trainerbattle_no_intro TRAINER_JACE_AMBER_CITY_TEPIG, AmberCity_Text_JaceDefeated
	goto AmberCity_EventScript_JacePostBattle
	end

AmberCity_EventScript_StartJaceBattlePopplio::
	trainerbattle_no_intro TRAINER_JACE_AMBER_CITY_POPPLIO, AmberCity_Text_JaceDefeated
	goto AmberCity_EventScript_JacePostBattle
	end


AmberCity_EventScript_JacePostBattle::
	@playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	delay 30
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox AmberCity_Text_JacePostBattle, MSGBOX_DEFAULT
	giveitem ITEM_HM06
	msgbox AmberCity_Text_ExplainRockSmash, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JACE, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_JACE, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	removeobject LOCALID_JACE
	@setflag FLAG_RECEIVED_HM06
	setvar VAR_JACE_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

AmberCity_Movement_PlayerBackOff:
	face_up
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

AmberCity_Text_JacePreBattle:
	.string "JACE: There you are, {PLAYER}.\n"
	.string "What took you so long?\p"
	.string "So you think you're ready to take\n"
	.string "on the gym here, huh?\p"
	.string "We'll see about that.\n"
	.string "Show me what your POKéMON can do!$"

AmberCity_Text_JaceDefeated:
	.string "Not bad.$"

AmberCity_Text_JacePostBattle:
	.string "JACE: With POKéMON like that,\n"
	.string "you just might stand a chance.\p"
	.string "The gym leader, TARA, is no slouch.\n"
	.string "She gave us a tough battle earlier.\p"
	@.string "We still need to train more.\p"
	.string "If you need to train more, there are\n"
	.string "a bunch of trainers just west of here.\l"
	.string "...\p"
	.string "Oh and by the way, {PLAYER}.\p"
	.string "Remember those rocks blocking the\n"
	.string "entrance to QUARTZ CAVE?\p"
	.string "I found a way to get past them using\n"
	.string "this HIDDEN MACHINE.\p"
	.string "Here, you can have one too!$"


AmberCity_Text_ExplainRockSmash:
	.string "JACE: That HM contains ROCK SMASH.\p"
	.string "Use it to remove rocks in your way,\n"
	.string "like the ones back in QUARTZ CAVE.\p"
	.string "But you'll need to get the SILICON\n"
	.string "BADGE from TARA first.\p"
	.string "Well, until next time, {PLAYER}.$"

