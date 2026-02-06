.set LOCALID_JACE, 12
.set LOCALID_NORMAN, 13
.set LOCALID_RANGER, 1

MaroonCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MaroonCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MaroonCity_OnFrame
	.byte 0

MaroonCity_OnFrame:
	map_script_2 VAR_JACE_STATE, 4, MaroonCity_RangerHQ_3F_EventScript_JaceBeforeDeparture
	.2byte 0

MaroonCity_OnTransition:
	clearflag FLAG_FORCE_LOAD_OFFSCREEN_OBJEV
	setflag FLAG_VISITED_MAROON_CITY
	call_if_set FLAG_DEFEATED_MAROON_GYM, MaroonCity_EventScript_MoveJaceToRangerHQ
	call_if_ge VAR_JACE_STATE, 3, MaroonCity_EventScript_RemoveJace
	call_if_ge VAR_JACE_STATE, 4, MaroonCity_EventScript_MoveJaceToRangerHQ2
	call_if_ge VAR_JACE_STATE, 5, MaroonCity_EventScript_RemoveJace
	end

MaroonCity_EventScript_MoveJaceToRangerHQ:
	removeobject LOCALID_JACE
	clearflag FLAG_HIDE_JACE
	setobjectxyperm LOCALID_JACE, 22, 6
	setobjectmovementtype LOCALID_JACE, MOVEMENT_TYPE_FACE_UP
	addobject LOCALID_JACE
	return

MaroonCity_EventScript_MoveNormanToRangerHQ:
	removeobject LOCALID_NORMAN
	setobjectxyperm LOCALID_NORMAN, 22, 6
	setobjectmovementtype LOCALID_NORMAN, MOVEMENT_TYPE_FACE_DOWN
	addobject LOCALID_NORMAN
	return

MaroonCity_EventScript_MoveJaceToRangerHQ2:
	removeobject LOCALID_JACE
	clearflag FLAG_HIDE_JACE
	setobjectxyperm LOCALID_JACE, 22, 7
	setobjectmovementtype LOCALID_JACE, MOVEMENT_TYPE_FACE_DOWN
	addobject LOCALID_JACE
	return

MaroonCity_EventScript_RemoveNorman:
	removeobject LOCALID_NORMAN
	@setobjectxyperm LOCALID_NORMAN, 1, 32
	@setobjectmovementtype LOCALID_NORMAN, MOVEMENT_TYPE_FACE_DOWN
	@addobject LOCALID_NORMAN
	return

MaroonCity_EventScript_RemoveJace:
	removeobject LOCALID_JACE
	@setobjectxyperm LOCALID_JACE, 0, 32
	@setobjectmovementtype LOCALID_JACE, MOVEMENT_TYPE_FACE_DOWN
	@addobject LOCALID_JACE
	return








MaroonCity_EventScript_GymSign::
	msgbox MaroonCity_Text_GymSign, MSGBOX_SIGN
	end

MaroonCity_EventScript_CitySign::
	msgbox MaroonCity_Text_CitySign, MSGBOX_SIGN
	end

MaroonCity_EventScript_RangerHQSign::
	msgbox MaroonCity_Text_RangerHQSign, MSGBOX_SIGN
	end

MaroonCity_EventScript_PokeballFactorySign::
	msgbox MaroonCity_Text_PokeballFactorySign, MSGBOX_SIGN
	end

MaroonCity_Text_PokeballFactorySign:
	.string "POKé BALL EMPORIUM$"

MaroonCity_Text_RangerHQSign:
	.string "POKéMON RANGER HQ$"

MaroonCity_Text_GymSign:
	.string "MAROON CITY POKéMON GYM\n"
	.string "LEADER: NIKOLAUS\l"
	.string "“The steel werkmeister!”$"
	@.string "“The white-hot welder!”$"

MaroonCity_Text_CitySign:
	.string "MAROON CITY\n"
	.string "“The iron heart of ISSHO.”$"
	@.string "“Manufactury capital of ISSHO.”$"
	@.string "“The workshop of ISSHO.”$"






MaroonCity_EventScript_Dummy::
	giveitem ITEM_HEART_SCALE
	end

MaroonCity_EventScript_Man::
	msgbox MaroonCity_Text_HauntedWoods, MSGBOX_NPC
	end

MaroonCity_Text_HauntedWoods:
	.string "Some superstitious people around here\n"
	.string "say that the forest is haunted.\p"
	.string "There's definitely something strange\n"
	.string "about it, that's for sure.$"

MaroonCity_EventScript_Policeman::
	msgbox MaroonCity_Text_NoCrime, MSGBOX_NPC
	end

MaroonCity_Text_NoCrime:
	.string "Ah, don't you love a crime-free city?$"

MaroonCity_EventScript_RangerBlock::
	msgbox MaroonCity_Text_ImportantMeeting, MSGBOX_NPC
	end

MaroonCity_Text_ImportantMeeting:
	.string "There's a top secret meeting\n"
	.string "going on right now.\p"
	.string "You'll have to wait until\n"
	.string "it's done.$"

MaroonCity_EventScript_Woman::
	lock
	faceplayer
	msgbox MaroonCity_Text_IronHeartOfIssho, MSGBOX_DEFAULT
	release
	end

MaroonCity_Text_IronHeartOfIssho:
	.string "MAROON CITY exports wood and metal\n"
	.string "products to the rest of ISSHO.\p"
	.string "Our engineering is the lifeblood\n"
	.string "for all construction in ISSHO.\p"
	.string "Just like your heart pumps iron\n"
	.string "to the cells in your body.\p"
	.string "We deliver iron to every corner\n"
	.string "of the region.\p"
	.string "That's why we're known as the\n"
	.string "Iron Heart of ISSHO.$" 
	@.string "That's why we're known as the\n"
	@.string "Iron Heart of ISSHO, get it?$"

MaroonCity_EventScript_AceTrainer::
	lock
	faceplayer
	msgbox MaroonCity_Text_ExplainPokeballShop, MSGBOX_DEFAULT
	release
	end

MaroonCity_Text_ExplainPokeballShop:
	.string "POKé BALL EMPORIUM carries all kinds\n"
	.string "of POKé BALLS.\p"
	.string "I hope they sell DREAM BALLS again soon.$"

MaroonCity_EventScript_Engineer::
	lock
	faceplayer
	msgbox MaroonCity_Text_WatchYourStep, MSGBOX_DEFAULT
	release
	end

MaroonCity_Text_WatchYourStep:
	.string "Careful! There are livewires on\n"
	.string "the ground here.$"

MaroonCity_EventScript_OldMan::
	lock
	faceplayer
	msgbox MaroonCity_Text_NikolausAndHisMen, MSGBOX_DEFAULT
	release
	end

MaroonCity_Text_NikolausAndHisMen:
	.string "NIKOLAUS and his men handle all\n"
	.string "manufacturing in the POKéMON GYM.\p"
	.string "Before he came along, we used to\n"
	.string "work in the old STEEL MILL.\p"
	.string "But it was abandoned years ago.\n"
	.string "Now it's a habitat for wild POKéMON.$"

MaroonCity_EventScript_AceTrainer2::
	msgbox MaroonCity_Text_MountainsOfIssho, MSGBOX_NPC
	end

MaroonCity_Text_MountainsOfIssho:
	.string "There are two great mountains here\n"
	.string "in ISSHO.\p"
	.string "Of the two, MT SHIRO is taller and colder.\p"
	.string "But DUSK MOUNTAIN is even more vast and\n"
	.string "difficult to navigate.$"




MaroonCity_EventScript_MetalWorker::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_MAROON_CITY_METAL_COAT, MaroonCity_EventScript_ComeBackTomorrow
	showmoneybox 0, 0
	msgbox MaroonCity_Text_MetalCoat, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MaroonCity_EventScript_DeclineMetalCoat
	checkmoney 10000
	goto_if_eq VAR_RESULT, FALSE, MaroonCity_EventScript_NotEnoughMoney
	@msgbox MaroonCity_Text_HereYouGo, MSGBOX_DEFAULT
	checkitemspace ITEM_METAL_COAT
	call_if_eq VAR_RESULT, TRUE, MindaroCity_EventScript_RemoveMoney
	giveitem ITEM_METAL_COAT
	goto_if_eq VAR_RESULT, FALSE, MindaroCity_EventScript_BagIsFull
	hidemoneybox
	setflag FLAG_DAILY_MAROON_CITY_METAL_COAT
	release
	end

MaroonCity_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MaroonCity_EventScript_RemoveMoney::
	removemoney 10000
	updatemoneybox
	return

MaroonCity_EventScript_DeclineMetalCoat::
	msgbox MaroonCity_Text_OhFineThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MaroonCity_EventScript_NotEnoughMoney::
	msgbox MaroonCity_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MaroonCity_EventScript_ComeBackTomorrow::
	msgbox MaroonCity_Text_ComeBackTomorrow, MSGBOX_DEFAULT
	release
	end

MaroonCity_Text_MetalCoat:
	.string "How about a METAL COAT for\n"
	.string "your STEEL type POKéMON?\p"
	.string "It'll make them sleek and stunning.\p"
	.string "It's only ¥10,000 for a full coating.\n"
	.string "Would you like to buy some?$"

MaroonCity_Text_OhFineThen:
	.string "No worries!\n"
	.string "Come back if you change your mind!$"

MaroonCity_Text_YouveNotGotTheMoney:
	.string "You don't have enough money.\n"
	.string "Too bad.$"

MaroonCity_Text_ComeBackTomorrow:
	.string "I only do one order\n"
	.string "per customer per day.\p"
	.string "Come back tomorrow if you'd\n"
	.string "like another coating.$"










MaroonCity_EventScript_Worker::
	lock
	faceplayer
	msgbox MaroonCity_Text_OldFactory, MSGBOX_DEFAULT
	release
	end

MaroonCity_Text_OldFactory:
	.string "This used to be the site of\n"
	.string "the old factory.\p"
	.string "Nowadays, we just use it\n"
	.string "as a scrapyard.$"

MaroonCity_EventScript_BerrySeller::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MaroonCity_BerryShop
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MaroonCity_BerryShop:
	.2byte ITEM_POMEG_BERRY
	.2byte ITEM_KELPSY_BERRY
	.2byte ITEM_QUALOT_BERRY
	.2byte ITEM_HONDEW_BERRY
	.2byte ITEM_GREPA_BERRY
	.2byte ITEM_TAMATO_BERRY
	.2byte ITEM_NONE
	release
	end









MaroonCity_EventScript_Jace::
	lockall
	faceplayer
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	msgbox MaroonCity_Text_JaceEncounter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JACE, Common_Movement_FaceUp
	waitmovement 0
	delay 60
	applymovement LOCALID_JACE, Common_Movement_FaceDown
	waitmovement 0
	delay 20
	msgbox MaroonCity_Text_JaceEncounter2, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	applymovement LOCALID_JACE, Common_Movement_WalkDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	applymovement LOCALID_JACE, Common_Movement_WalkDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_FaceLeft
	waitmovement 0
	delay 60
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox MaroonCity_Text_JaceEncounter3, MSGBOX_DEFAULT
	closemessage
	call MaroonCity_EventScript_MoveNormanToRangerHQ
	switch VAR_STARTER_MON
	case 0, MaroonCity_EventScript_StartJaceBattleChespin
	case 1, MaroonCity_EventScript_StartJaceBattleTepig
	case 2, MaroonCity_EventScript_StartJaceBattlePopplio
	end

MaroonCity_EventScript_StartJaceBattleChespin::
	trainerbattle_no_intro TRAINER_JACE_MAROON_CITY_CHESPIN, MaroonCity_Text_JaceDefeated
	@trainerbattle_no_intro TRAINER_JACE_UMBER_TOWN_CHESPIN, MaroonCity_Text_JaceDefeated
	goto MaroonCity_EventScript_JacePostBattle
	end

MaroonCity_EventScript_StartJaceBattleTepig::
	trainerbattle_no_intro TRAINER_JACE_MAROON_CITY_TEPIG, MaroonCity_Text_JaceDefeated
	goto MaroonCity_EventScript_JacePostBattle
	end

MaroonCity_EventScript_StartJaceBattlePopplio::
	trainerbattle_no_intro TRAINER_JACE_MAROON_CITY_POPPLIO, MaroonCity_Text_JaceDefeated
	goto MaroonCity_EventScript_JacePostBattle
	end


MaroonCity_EventScript_JacePostBattle::
	@call MaroonCity_EventScript_MoveNormanToRangerHQ
	@fadedefaultbgm
	delay 30
	applymovement LOCALID_JACE, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkLeft
	waitmovement 0
	delay 30
	msgbox MaroonCity_Text_JacePostBattle, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_JACE, Common_Movement_FaceRight
	waitmovement 0
	delay 30
	msgbox MaroonCity_Text_JacePostBattle2, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox MaroonCity_Text_NormanIntro, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_JACE, Common_Movement_FaceUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement LOCALID_JACE, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceUp
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox MaroonCity_Text_JaceHeyYou, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox MaroonCity_Text_NormanIntro2, MSGBOX_DEFAULT
	closemessage
	delay 10
	playse SE_PIN
	applymovement LOCALID_JACE, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox MaroonCity_Text_JaceYouKnowBrendan, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox MaroonCity_Text_NormanIntro3, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox MaroonCity_Text_JaceIntro, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox MaroonCity_Text_NormanNiceToMeetYou, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox MaroonCity_Text_JaceBrendansDad, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox MaroonCity_Text_NormanIntro4, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox MaroonCity_Text_NormanIntro5, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox MaroonCity_Text_JaceButILost, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox MaroonCity_Text_NormanIntro6, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox MaroonCity_Text_JaceBecomeChampion, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox MaroonCity_Text_NormanIntro7, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox MaroonCity_Text_JaceChampion, MSGBOX_DEFAULT
	closemessage
	delay 90
	msgbox MaroonCity_Text_NormanIntro8, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 30
	msgbox MaroonCity_Text_NormanIntro9, MSGBOX_DEFAULT
	closemessage
	delay 120
	msgbox MaroonCity_Text_JaceNeverThoughtAboutThat, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox MaroonCity_Text_NormanIntro10, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox MaroonCity_Text_JaceDoTheRightThing, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox MaroonCity_Text_NormanIntro11, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox MaroonCity_Text_JaceWeCanGoIn, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox MaroonCity_Text_NormanIntro12, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_NORMAN, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_NORMAN, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_NORMAN, Common_Movement_WalkRight
	waitmovement 0
	delay 30
	applymovement LOCALID_NORMAN, Common_Movement_FaceLeft
	waitmovement 0
	delay 30
	msgbox MaroonCity_Text_NormanFarewell, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_NORMAN, Common_Movement_FaceDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject LOCALID_NORMAN
	waitfieldeffect FLDEFF_NPCFLY_OUT
	delay 60
	applymovement LOCALID_JACE, Common_Movement_FaceLeft
	waitmovement 0
	delay 60
	msgbox MaroonCity_Text_JaceSoThatsBrendansDad, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_JACE, Common_Movement_FaceUp
	waitmovement 0
	delay 30
	applymovement LOCALID_JACE, Common_Movement_FaceLeft
	waitmovement 0
	msgbox MaroonCity_Text_JaceLetsGoInside, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JACE, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkUp
	waitmovement 0
	playse SE_DOOR
	call MaroonCity_EventScript_RemoveJace
	setvar VAR_JACE_STATE, 3
	releaseall
	end



@MaroonCity_Text_JaceEncounter:
@	.string "JACE: There you are, {PLAYER}!\n"
@	.string "What took you so long?\p"
@	.string "Let me guess, you're looking\n"
@	.string "for RANGER HQ?\p"
@	.string "Well, tough luck. There's something going on\n"
@	.string "inside and they won't let me in.\p"



@	.string "I tried talking to the girl outside earlier.\n"
@	.string "I even told her it was about TEAM GENESIS.\p"
@	.string "But no matter what I said,\n"
@	.string "she wouldn't let me in!\p"
@	.string "Then some guy randomly flew\n"
@	.string "out of the sky behind me.\p"
@	.string "And he just walked right in!\p"
@	.string "She acted like she didn't even see him.\n"
@	.string "Can you believe that?\p"

@	.string "Even though I know JUSTIN, I'm not\n"
@	.string "technically a ranger yet.$"

MaroonCity_Text_JaceEncounter:
	.string "JACE: There you are, {PLAYER}!\n"
	.string "What took you so long?\p"
	.string "Let me guess, you're looking\n"
	.string "for RANGER HQ?\p"
	.string "Well, tough luck. There's something going\n"
	.string "on inside and they won't let anybody in.\p"


	.string "Except some guy who cut in front of me.\n"
	.string "Can you believe that?$"

MaroonCity_Text_JaceEncounter2:
	.string "\p"
	.string "Well, I guess we have no choice\n"
	.string "but to wait.\p"
	.string "\p"
	.string "Hey that's right!\n"
	.string "We supposed to battle again!\p"
	.string "You're not getting out of it this time!$"

@Jace and Player walk into battle positions

MaroonCity_Text_JaceEncounter3:
	.string "JACE: Alright, are you ready?\n"
	.string "We're much stronger than last time!$"

@battle sequence

MaroonCity_Text_JaceDefeated:
	.string "No way!$"

MaroonCity_Text_JacePostBattle:
	.string "\p"
	.string "Well, congratulations {PLAYER}.\n"
	.string "You won fair and square.$"

MaroonCity_Text_JacePostBattle2:
	.string "\p"
	.string "Aaaaargh! It's like you're always\n"
	.string "one step ahead of me!\p"
	.string "\p"
	.string "At this rate, you're gonna be\n"
	.string "the champion before me...$"

MaroonCity_Text_NormanIntro:
	.string "??????: Wahahahahaha!\n"
	.string "What an amazing battle that was!$"

@Jace and Player turn to notice Norman who's been standing at the door since the battle sequence ended.


MaroonCity_Text_JaceHeyYou:
	.string "JACE: Hey, you're that guy from before!\n"
	.string "You got in ahead of me!\p"
	.string "What gives, are you somebody important?$"

MaroonCity_Text_NormanIntro2:
	.string "Well, it's not like I come and\n"
	.string "go as I please.\p"
	.string "My son BRENDAN was supposed to be here.\n"
	.string "But it seems I just missed him.$"

MaroonCity_Text_JaceYouKnowBrendan:
	.string "Your son BRENDAN?\n"
	.string "That means...\p"
	.string "You're BRENDAN'S dad?!$"

MaroonCity_Text_NormanIntro3:
	.string "Hahaha! I guess he is pretty famous\n"
	.string "out here, afterall.\p"
	.string "That's right, I'm BRENDAN'S father.\n"
	.string "But you can call me NORMAN.\p"
	.string "And you are?$"

MaroonCity_Text_JaceIntro:
	.string "I'm JACE from UMBER TOWN.\n"
	@.string "And this is my sidekick, {PLAYER}.$"
	.string "And this is my sideki-\p"
	.string "\p"
	.string "This is my friend, {PLAYER}.$"


MaroonCity_Text_NormanNiceToMeetYou:
	.string "NORMAN: Nice to meet you both!$"

MaroonCity_Text_JaceBrendansDad:
	.string "JACE: I never thought I'd get\n"
	.string "to meet BRENDAN'S dad.\p"
	.string "Everybody talks about how strong he is,\n"
	.string "but you must be even stronger!$"

MaroonCity_Text_NormanIntro4:
	.string "NORMAN: Well, he's certainly younger\n"
	.string "and more energetic than I am.\p"
	.string "I didn't get around half as much as\n"
	.string "he does when I was his age.\p"
	.string "\p"
	.string "To be honest, I haven't had a good\n"
	.string "battle in a long time.\p"
	.string "And I'm afraid I might be a bit\n"
	.string "out of practice.\p"
	.string "Not too many young new challengers back\n"
	.string "in HOENN nowadays.$"

MaroonCity_Text_NormanIntro5:
	.string "NORMAN: But watching the two of you\n"
	.string "has really raised my spirits!\p"
	.string "You both put on a stunning battle\n"
	.string "earlier!\p"
	.string "You and your POKéMON had\n"
	.string "excellent teamwork!$"

MaroonCity_Text_JaceButILost:
	.string "JACE: Yeah, but I still lost...$"

MaroonCity_Text_NormanIntro6:
	.string "It's not always about winning or\n"
	.string "losing.\p"
	.string "You and your POKéMON did your best.\p"
	.string "You worked together and put up\n"
	.string "a great fight.\p"
	.string "As long as you had fun, that's all that\n"
	.string "matters in a friendly match like this one.$"

MaroonCity_Text_JaceBecomeChampion:
	.string "JACE: But how can I be the champion\n"
	.string "if I keep losing all the time?$"

MaroonCity_Text_NormanIntro7:
	.string "NORMAN: Hahahahahahaha!\p"
	.string "You want to be the next champion?\n"
	.string "You are an ambitious young man!\p"
	.string "And what do you plan on doing once\n"
	.string "you become champion?$"

MaroonCity_Text_JaceChampion:
	.string "If I become champion, that means\n"
	.string "I'm the best trainer in ISSHO!\p"
	.string "I'd never lose to nobody!\n"
	.string "I could do whatever I want.\p"
	.string "I could stop bad guys like TEAM\n"
	.string "GENESIS all by myself!$"


	@.string "When I'm champion, that means I'll be\n"
	@.string "stronger than everybody else!\p"
	@.string "I won't ever have to lose to anybody\n"
	@.string "ever again!\p"
	@.string "Bad guys like TEAM GENESIS would\n"
	@.string "tremble at the sight of me!\p"
	@.string "I could crush those guys all by myself!$"

MaroonCity_Text_NormanIntro8:
	.string "NORMAN: Hahahahaha! Well the champion\n"
	.string "can't do everything on his own.\p"
	.string "And he certainly does lose sometimes.$"

MaroonCity_Text_NormanIntro9:
	.string "What I'm saying is that it's not so\n"
	.string "much how strong you are.\p"
	.string "But rather, it's what you're fighting\n"
	.string "for that's important.\p"
	.string "You two are friends. You fight to help\n"
	.string "and support each other.\p"
	.string "And your POKéMON fight because they\n"
	.string "trust you and want to help you.\p"
	.string "We all have people we want to help.\n"
	.string "And who help us in our time of need.\p"
	@.string "\p"
	.string "Protecting those who can't protect\n"
	.string "themselves.\p"
	.string "That's what a true champion does!\p"
	.string "If you only pursue power at all costs,\n"
	.string "you'll lose sight of people and POKéMON.\p"
	.string "You'd be just like TEAM GENESIS.$"

MaroonCity_Text_JaceNeverThoughtAboutThat:
	.string "JACE: I guess you're right.\n"
	.string "I never thought about it like that.\p"
	.string "\p"
	.string "But still, there are some pretty tough\n"
	.string "bad guys out there.\p"
	.string "And I don't like the way they treat\n"
	.string "other people and their POKéMON.\p"
	.string "I want to be strong enough to kick them\n"
	.string "out of ISSHO once and for all.\p"
	.string "That's what I would do as champion!$"

MaroonCity_Text_NormanIntro10:
	.string "NORMAN: Hahaha! Well, I'm sure there's\n"
	.string "plenty you can do already.\p"
	.string "By the way, I heard about your\n"
	.string "standoff in TURQUOISE CITY.\p"
	.string "It seems you've become a little famous\n"
	.string "out here yourself.$"

MaroonCity_Text_JaceDoTheRightThing:
	.string "JACE: Ahhh, it was nothing. I was just\n"
	.string "trying to do the right thing.\p"
	.string "{PLAYER} here was the one who actually\n"
	.string "battled the GENESIS boss.$"

MaroonCity_Text_NormanIntro11:
	.string "Well, perhaps the two of you can\n"
	.string "shed more light on the tale.\p"
	.string "I'm sure the RANGERS would be eager\n"
	.string "to hear your side of the story.$" 

MaroonCity_Text_JaceWeCanGoIn:
	.string "You mean they'll let us in now?$"

MaroonCity_Text_NormanIntro12:
	.string "NORMAN: That's right. Their meeting\n"
	.string "ended just a short while ago.\p"
	.string "Which reminds me, I still need to\n"
	.string "track down BRENDAN...$"

MaroonCity_Text_NormanFarewell:
	.string "It was nice meeting you both.\p"
	.string "Good luck on your journey to\n"
	.string "EVER GRANDE CITY.$"
	@.string "POKéMON LEAGUE CHAMPIONSHIP!$"

MaroonCity_Text_JaceSoThatsBrendansDad:
	.string "So that's BRENDAN'S dad, huh?\p"
	.string "You know he's really not like\n"
	.string "I imagined he would be...$"
	@.string "Somehow he's not as impressive\n"
	@.string "as I thought he'd be.$"

MaroonCity_Text_JaceLetsGoInside:
	.string "Well, at least we can finally\n"
	.string "go inside now. C'mon!$"








MaroonCity_RangerHQ_3F_EventScript_JaceBeforeDeparture::
	lockall
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceDown
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox MaroonCity_Text_JaceFarewell, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_JACE, Common_Movement_FaceUp
	waitmovement 0
	delay 10
	msgbox MaroonCity_Text_JaceFarewell2, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox MaroonCity_Text_JaceFarewell3, MSGBOX_DEFAULT
	closemessage
@Jace turns and uses Fly
	applymovement LOCALID_JACE, Common_Movement_FaceDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject LOCALID_JACE
	waitfieldeffect FLDEFF_NPCFLY_OUT
	delay 60
	setvar VAR_JACE_STATE, 5
	releaseall
	end

MaroonCity_Text_JaceFarewell:
	.string "Alright! We're officially part of\n"
	.string "the POKéMON RANGERS now!$"
	@.string "We're official POKéMON RANGERS now!\p"
	@.string "Well, sort of official...\p"
	@.string "We're official RANGER recruits now!$"
	@.string "Anyway, let's do our best on\n"

MaroonCity_Text_JaceFarewell2:
	.string "Let's do our best on the\n"
	.string "mission JUSTIN gave us.\p"
	.string "Maybe we can put a stop to TEAM GENESIS\n"
	.string "once and for all.\p"
	.string "First we need to talk to this ADDERLY\n"
	.string "guy in WISTERIA CITY...$"

MaroonCity_Text_JaceFarewell3:
	.string "By the way {PLAYER}, I don't think I'm\n"
	.string "gonna go straight there just yet.\p"
	.string "I figure if we're really gonna go after\n"
	.string "TEAM GENESIS again, we should be\l"
	.string "at the top of our game first.\p"
	.string "Can't hurt to be too prepared, right?\p"
	.string "There's another gym in HAEWEN TOWN\n"
	.string "that I want to check out.\p"
	.string "I'll meet up with you afterwards\n"
	.string "in WISTERIA CITY.\p"
	.string "What are you gonna do, {PLAYER}?\p"
	.string "Are you gonna follow me to HAEWEN TOWN?\n"
	.string "Or go straight to WISTERIA CITY?\p"
	.string "\p"
	.string "Well, I guess we'll meet again soon\n"
	.string "either way.\p"
	.string "Catch you later, {PLAYER}!$"






