.equ SMEARGLE_PRICE, 9999
.set LOCALID_JACE, 12
.set LOCALID_BRENDAN, 16
.set LOCALID_MILO, 17

TurquoiseCity_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TurquoiseCity_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, TurquoiseCity_OnTransition
	.byte 0

TurquoiseCity_OnTransition:
	setflag FLAG_VISITED_TURQUOISE_CITY
	call_if_le VAR_TURQUOISE_CITY_STATE, 2, TurquoiseCity_EventScript_ChangeMusic
	call_if_eq VAR_TURQUOISE_CITY_STATE, 0, TurquoiseCity_EventScript_InitializeCity
	call_if_eq VAR_TURQUOISE_CITY_STATE, 2, TurquoiseCity_EventScript_HideJace
	call_if_eq VAR_TURQUOISE_CITY_STATE, 3, TurquoiseCity_EventScript_MoveJaceToWarehouse
	@call_if_eq VAR_TURQUOISE_CITY_STATE, 3, TurquoiseCity_EventScript_InitializeBrendanAndMilo
	call_if_ge VAR_TURQUOISE_CITY_STATE, 4, TurquoiseCity_EventScript_HideJaceBrendanAndMilo
	end

TurquoiseCity_OnFrame:
	map_script_2 VAR_TURQUOISE_CITY_STATE, 3, TurquoiseCity_EventScript_PostRescueInitial
	.2byte 0

TurquoiseCity_EventScript_PostRescueInitial::
	lockall
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	goto TurquoiseCity_EventScript_PostRescue
	end








TurquoiseCity_EventScript_ChangeMusic:
	playbgm MUS_ABNORMAL_WEATHER, TRUE
	setweather WEATHER_RAIN_THUNDERSTORM
	return

TurquoiseCity_EventScript_InitializeCity:
	clearflag FLAG_HIDE_JACE
	setflag FLAG_HIDE_BRENDAN
	setflag FLAG_TURQUOISE_CITY_OCCUPIED
	return

TurquoiseCity_EventScript_HideJace:
	setflag FLAG_HIDE_JACE
	return

TurquoiseCity_EventScript_MoveJaceToWarehouse:
	clearflag FLAG_HIDE_JACE
	setobjectxyperm LOCALID_JACE, 8, 22
	setobjectmovementtype LOCALID_JACE, MOVEMENT_TYPE_FACE_UP
	addobject LOCALID_JACE
	return


@TurquoiseCity_EventScript_InitializeBrendanAndMilo
@	clearflag FLAG_HIDE_BRENDAN
@	return

TurquoiseCity_EventScript_HideJaceBrendanAndMilo:
	setflag FLAG_HIDE_JACE
	setflag FLAG_HIDE_BRENDAN
	return






















TurquoiseCity_EventScript_LockedGameCorner::
	msgbox TurquoiseCity_Text_LockedGameCorner, MSGBOX_SIGN
	end

TurquoiseCity_Text_LockedGameCorner:
	.string "Coming soon.\n"
	.string "--TDILOS$"

TurquoiseCity_EventScript_TownSign::
	msgbox TurquoiseCity_Text_TownSign, MSGBOX_SIGN
	end

TurquoiseCity_Text_TownSign:
	.string "TURQUOISE CITY\n"
	.string "“Port city as fickle as the sea.”$"
	@.string "“The freight harbor of ISSHO.”$"
	@.string "“The freight capitol of ISSHO.”$"
	@.string "“The grand harbor of ISSHO.”$"

TurquoiseCity_EventScript_GameCornerSign::
	msgbox TurquoiseCity_Text_GameCornerSign, MSGBOX_SIGN
	end

TurquoiseCity_Text_GameCornerSign:
	.string "TURQUOISE CITY GAME CORNER\p"
	.string "“Get hooked on our exciting new games!”$"

TurquoiseCity_EventScript_PledgeTutor::
	lock
	faceplayer
	msgbox TurquoiseCity_Text_PledgeTutor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TurquoiseCity_EventScript_CheckTeamFriendship
	goto_if_eq VAR_RESULT, NO, TurquoiseCity_EventScript_ExitTutorMoveSelect
	release
	end

TurquoiseCity_EventScript_CheckTeamFriendship::
	specialvar VAR_RESULT, CheckHighTeamFriendship
	goto_if_eq VAR_RESULT, TRUE, TurquoiseCity_EventScript_ChooseTutorMove
	msgbox TurquoiseCity_Text_CantTeachPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

TurquoiseCity_EventScript_ChooseTutorMove::
	message TurquoiseCity_Text_TeachWhichMove
	waitmessage
	scrollingmultichoice 11, 2, 0, 4, TRUE
	switch VAR_RESULT
	case 0, TurquoiseCity_EventScript_GrassPledge
	case 1, TurquoiseCity_EventScript_FirePledge
	case 2, TurquoiseCity_EventScript_WaterPledge
	case 3, TurquoiseCity_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, TurquoiseCity_EventScript_ExitTutorMoveSelect
	end

TurquoiseCity_EventScript_GrassPledge::
	setvar VAR_0x8005, MOVE_GRASS_PLEDGE
	goto TurquoiseCity_EventScript_TeachTutorMove
	end

TurquoiseCity_EventScript_FirePledge::
	setvar VAR_0x8005, MOVE_FIRE_PLEDGE
	goto TurquoiseCity_EventScript_TeachTutorMove
	end

TurquoiseCity_EventScript_WaterPledge::
	setvar VAR_0x8005, MOVE_WATER_PLEDGE
	goto TurquoiseCity_EventScript_TeachTutorMove
	end

TurquoiseCity_EventScript_TeachTutorMove::
	msgbox TurquoiseCity_Text_TeachWhichPokemon, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, FALSE, TurquoiseCity_EventScript_ChooseTutorMove
	release
	end

TurquoiseCity_EventScript_ExitTutorMoveSelect::
	msgbox TurquoiseCity_Text_ComeBack, MSGBOX_DEFAULT
	release
	end

TurquoiseCity_Text_PledgeTutor::
	.string "I can teach your POKéMON some\n"
	.string "special combo moves.\p"
	.string "How about it?$"

TurquoiseCity_Text_TeachWhichMove:
	.string "Which move should I teach?$"

TurquoiseCity_Text_TeachWhichPokemon:
	.string "Alright, and which POKéMON wants\n"
	.string "to learn it?$"

TurquoiseCity_Text_CantTeachPokemon:
	.string "Hmmm. It looks like your POKéMON\n"
	.string "don't trust you enough yet.\p"
	.string "My special combo moves won't work\n"
	.string "unless your bond is truly strong.$"

TurquoiseCity_Text_ComeBack:
	.string "Come back if you change your mind.$"


TurquoiseCity_EventScript_TMClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart TurquoiseCity_TMshop
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TurquoiseCity_TMshop:
	.2byte ITEM_TM57  @ Round
	.2byte ITEM_TM42  @ Facade
	.2byte ITEM_TM82  @ Dragon Tail
	.2byte ITEM_TM28  @ Dig
	.2byte ITEM_TM47  @ Steel Wing
	.2byte ITEM_TM86  @ Grass Knot
	.2byte ITEM_NONE
	release
	end

TurquoiseCity_EventScript_BerrySeller::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart TurquoiseCity_BerryShop
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TurquoiseCity_BerryShop:
	.2byte ITEM_FIGY_BERRY
	.2byte ITEM_MAGO_BERRY
	.2byte ITEM_BLUK_BERRY
	.2byte ITEM_WEPEAR_BERRY
	.2byte ITEM_RABUTA_BERRY
	.2byte ITEM_SPELON_BERRY
	.2byte ITEM_WATMEL_BERRY
	.2byte ITEM_BELUE_BERRY
	.2byte ITEM_NONE
	release
	end


TurquoiseCity_EventScript_CasinoMan::
	msgbox TurquoiseCity_Text_GameCorner, MSGBOX_NPC
	end

TurquoiseCity_Text_GameCorner:
	.string "The GAME CORNER draws a lot of customers\n"
	.string "here in TURQUOISE CITY.\p"
	.string "You'd be surprised how many sailors are\n"
	.string "eager to gamble their paychecks away.$"

TurquoiseCity_EventScript_Sailor::
	msgbox TurquoiseCity_Text_ShippingLane, MSGBOX_NPC
	end

TurquoiseCity_Text_ShippingLane:
	.string "This right here is the heart of\n"
	.string "an important shipping lane.\p"
	.string "We have goods come in from\n"
	.string "every corner of ISSHO!$"






TurquoiseCity_EventScript_JaceEncounter::
	lockall
	applymovement LOCALID_JACE, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	delay 60
	applymovement LOCALID_JACE, TurquoiseCity_Movement_JaceMeetsPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	@playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	msgbox TurquoiseCity_Text_MeetJace, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JACE, Common_Movement_FaceDown
	waitmovement 0
	delay 120
	applymovement LOCALID_JACE, Common_Movement_FaceRight
	waitmovement 0
	msgbox TurquoiseCity_Text_SomethingsNotRight, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TurquoiseCity_EventScript_HeardOf
	goto_if_eq VAR_RESULT, NO, TurquoiseCity_EventScript_NotHeardOf
	end

TurquoiseCity_EventScript_HeardOf::
	msgbox TurquoiseCity_Text_HeardOf, MSGBOX_DEFAULT
	goto TurquoiseCity_EventScript_JacesStory
	end


TurquoiseCity_EventScript_NotHeardOf::
	msgbox TurquoiseCity_Text_NotHeardOf, MSGBOX_DEFAULT
	goto TurquoiseCity_EventScript_JacesStory
	end

TurquoiseCity_EventScript_JacesStory::
	msgbox TurquoiseCity_Text_TrubbishBag, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JACE, Common_Movement_FaceLeft
	waitmovement 0
	delay 120
	applymovement LOCALID_JACE, Common_Movement_FaceRight
	waitmovement 0
	msgbox TurquoiseCity_Text_SawWarehouse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TurquoiseCity_EventScript_TeamUp
	goto_if_eq VAR_RESULT, NO, TurquoiseCity_EventScript_DontTeamUp
	end


TurquoiseCity_EventScript_TeamUp::
	msgbox TurquoiseCity_Text_TeamUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JACE, TurquoiseCity_Movement_JaceLeaves
	waitmovement 0
	setvar VAR_TURQUOISE_CITY_STATE, 1
	removeobject LOCALID_JACE
	setflag FLAG_HIDE_JACE
	@savebgm MUS_DUMMY
	@fadedefaultbgm
	releaseall
	end

TurquoiseCity_EventScript_DontTeamUp::
	msgbox TurquoiseCity_Text_DontTeamUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JACE, TurquoiseCity_Movement_JaceLeaves
	waitmovement 0
	setvar VAR_TURQUOISE_CITY_STATE, 1
	removeobject LOCALID_JACE
	setflag FLAG_HIDE_JACE
	@savebgm MUS_DUMMY
	@fadedefaultbgm
	releaseall
	end

TurquoiseCity_Movement_JaceLeaves:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

TurquoiseCity_Movement_JaceMeetsPlayer:
	walk_up
	walk_up
	face_right
	step_end

TurquoiseCity_Text_MeetJace:
	.string "JACE: Oh, {PLAYER}!\p"
	.string "I saw the ferry come in, but I didn't\n"
	.string "realize you were on it.\p"
	.string "Hey, check it out!\p"
	.string "With this HYACINTH BADGE, I have\n"
	.string "three badges now!\p"
	.string "...\p"
	.string "Huh? You beat the gym leader in\n"
	.string "COBALT CITY too?\p"
	.string "Darn, just when I thought I was\n"
	.string "finally ahead of you.$"

TurquoiseCity_Text_SomethingsNotRight:
	.string "Something's not right with this city.\p"
	.string "I haven't been here for long, but I\n"
	.string "noticed the houses.\p"
	.string "They're all boarded up.\n"
	.string "Every single one.\p"
	.string "And the streets are crawling with these\n"
	.string "guys calling themselves TEAM GENESIS.\p"
	.string "Have you heard of them?$"


TurquoiseCity_Text_HeardOf:
	.string "What's up with them anyway?$"

TurquoiseCity_Text_NotHeardOf:
	.string "Well, whoever they are, they\n"
	.string "don't seem like nice people.$"

TurquoiseCity_Text_TrubbishBag:
	.string "I tried asking them about the city,\n"
	.string "but they just brushed me off.\p"
	.string "Told me if I keep asking questions,\n"
	.string "they'll put me in a TRUBBISH bag\l"
	.string "or something like that...$"

TurquoiseCity_Text_SawWarehouse:
	.string "I also saw them leading some people\n"
	.string "into a warehouse.\p"
	.string "I wonder if the people here are\n"
	.string "being held hostage...\p"
	.string "\p"
	.string "I wanted to do something, but there's\n"
	.string "a lot of them and only one of me.\p"
	.string "But hey, you're strong!\p"
	.string "If we team up, I bet we could take 'em.\n"
	.string "What do you say?$"

TurquoiseCity_Text_TeamUp:
	.string "Alright! They won't know what hit 'em!\p"
	.string "The warehouse is just around\n"
	.string "the corner here.\p"
	@.string "I'll be waiting outside.\p" 
	.string "Meet me there when\n"
	.string "you're ready, okay?$"

TurquoiseCity_Text_DontTeamUp:
	.string "What are you, a scaredy cat?\p"
	.string "\p"
	.string "Well, I'm gonna check out\n"
	.string "the warehouse anyway.\p"
	@.string "I'll be waiting outside if\n"
	@.string "you change you're mind.\p"
	.string "Meet me there if you\n"
	.string "change your mind.\p"
	.string "Later, {PLAYER}.$"

TurquoiseCity_EventScript_DoorGrunt::
	msgbox TurquoiseCity_Text_NobodyGoesAnywhere, MSGBOX_NPC
	end

TurquoiseCity_Text_NobodyGoesAnywhere:
	.string "Nobody goes anywhere until\n"
	.string "we get what we want!$"

TurquoiseCity_EventScript_SouthExitGrunt1::
	lock
	msgbox TurquoiseCity_Text_IsThatAllYouGot, MSGBOX_DEFAULT
	release
	end

TurquoiseCity_Text_IsThatAllYouGot:
	.string "Hahaha, is that all you got?$"

TurquoiseCity_EventScript_PasserbyTrainer::
	lock
	msgbox TurquoiseCity_Text_ToughPokemon, MSGBOX_DEFAULT
	release
	end

TurquoiseCity_Text_ToughPokemon:
	.string "Grrr, these guys are tough.\p"
	.string "How can their POKéMON be so strong?$"
	@.string "Their POKéMON aren't like\n"
	@.string "anything I've seen before.\p"
	@.string "Where did they get such\n"
	@.string "powerful POKéMON?$"

TurquoiseCity_EventScript_SouthExitGrunt2::
	msgbox TurquoiseCity_Text_MindYourOwnBusiness, MSGBOX_NPC
	end

TurquoiseCity_Text_MindYourOwnBusiness:
	.string "Mind your own business if\n"
	.string "ya know what's good for ya!$"






TurquoiseCity_EventScript_PostRescue::
	applymovement LOCALID_MILO, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox TurquoiseCity_Text_ThankGoodness, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox TurquoiseCity_Text_JustInTime, MSGBOX_DEFAULT
	closemessage
	delay 20
	playse SE_PIN
	applymovement LOCALID_MILO, Common_Movement_ExclamationMark
	waitmovement 0
	delay 40
	msgbox TurquoiseCity_Text_KidnappedScientist, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox TurquoiseCity_Text_DontBeatYourselfUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MILO, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox TurquoiseCity_Text_CountOnMe, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_BRENDAN, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	msgbox TurquoiseCity_Text_WhoDoWeHaveHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox TurquoiseCity_Text_JaceIntroduction, MSGBOX_DEFAULT
	closemessage
	delay 40
	msgbox TurquoiseCity_Text_LoftyGoal, MSGBOX_DEFAULT
	closemessage
	delay 40
	msgbox TurquoiseCity_Text_StillWorkingOnIt, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox TurquoiseCity_Text_YouHaveMyThanks, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BRENDAN, Common_Movement_WalkRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_JACE, Common_Movement_FaceRight
	applymovement LOCALID_BRENDAN, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_BRENDAN, Common_Movement_WalkRight
	waitmovement 0
	delay 20
	applymovement LOCALID_BRENDAN, Common_Movement_FaceLeft
	waitmovement 0
	msgbox TurquoiseCity_Text_GoingAfterTeamGenesis, MSGBOX_DEFAULT
	closemessage

	@Brendan turns and uses Fly
	applymovement LOCALID_BRENDAN, Common_Movement_FaceDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject LOCALID_BRENDAN
	waitfieldeffect FLDEFF_NPCFLY_OUT
	delay 60
	goto TurquoiseCity_EventScript_MiloGivesDirections
	end

TurquoiseCity_Text_ThankGoodness:
	.string "Thank goodness my POKéMON are safe!\p"
	.string "I was so scared I was going to lose them...$"

TurquoiseCity_Text_JustInTime:
	.string "BRENDAN: Looks like I got here\n"
	.string "just in time.\p"
	.string "What were they doing here anyway?$"

TurquoiseCity_Text_KidnappedScientist:
	.string "Aah, that's right!\n"
	.string "They kidnapped that DEVON scientist!\p"
	.string "They wanted some kind of special\n"
	.string "POKé BALL from him.\p"
	.string "I was supposed to be his bodyguard,\n"
	.string "but I failed...$"

TurquoiseCity_Text_DontBeatYourselfUp:
	.string "BRENDAN: Don't beat yourself up\n"
	.string "about it.\p"
	.string "I'll rescue the scientist.\n"
	.string "I was going to follow them anyway.\p"
	.string "\p"
	.string "You're MILO, right?\n"
	.string "You're with the POKéMON RANGERS.\p"
	.string "Can you deliver a message\n"
	.string "to JUSTIN for me?\p"
	.string "Tell him that I'll meet him in\n"
	.string "MAROON CITY soon and be ready.\p"
	.string "We may find out where TEAM GENESIS\n"
	.string "has been hiding this whole time.$"

TurquoiseCity_Text_CountOnMe:
	.string "MILO: Yes, MR BRENDAN, sir!\n"
	.string "You can count on me!$"

TurquoiseCity_Text_WhoDoWeHaveHere:
	.string "BRENDAN: And who might you two be?$"

TurquoiseCity_Text_JaceIntroduction:
	.string "I'm JACE. I'm gonna be the\n"
	.string "next POKéMON LEAGUE CHAMPION!\p"
	.string "And this is my sidekick, {PLAYER}.$"

TurquoiseCity_Text_LoftyGoal:
	.string "BRENDAN: The champion, huh?\n"
	.string "That's a pretty lofty goal.\p"
	.string "You must have a lot of GYM BADGES,\n"
	.string "I take it?$"

TurquoiseCity_Text_StillWorkingOnIt:
	.string "JACE: Uh, actually I'm still\n"
	.string "working on that...\p"
	.string "\p"
	.string "We're from UMBER TOWN originally.\n"
	.string "We've never been to this part of ISSHO.\p"
	.string "We just got here and saw those\n"
	.string "TEAM GENESIS jerks up to no good...$"

TurquoiseCity_Text_YouHaveMyThanks:
	.string "BRENDAN: Well, it was very brave of you\n"
	.string "to stand up to them like that.\p"
	.string "If you hadn't held them off before I got\n"
	.string "here, who knows what would've happened.\p"
	.string "You have my thanks.$"

TurquoiseCity_Text_GoingAfterTeamGenesis:
	.string "BRENDAN: I'm going after TEAM GENESIS.\p"
	.string "If you're looking for gyms to challenge,\n"
	.string "I'm sure MILO here can help you find them.\p"
	.string "Well, best of luck!$"

TurquoiseCity_EventScript_MiloGivesDirections::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_JACE, Common_Movement_FaceUp
	applymovement LOCALID_MILO, Common_Movement_FaceDown
	waitmovement 0
	delay 20
	msgbox TurquoiseCity_Text_MiloGivesDirections, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MILO, Common_Movement_WalkRight
	applymovement LOCALID_JACE, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	applymovement LOCALID_MILO, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_MILO, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_MILO, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_MILO, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_MILO, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_MILO, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_MILO, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_MILO, Common_Movement_WalkRight
	waitmovement 0
	@delay 60
	removeobject LOCALID_MILO
	goto TurquoiseCity_EventScript_JaceExit
	end

TurquoiseCity_Text_MiloGivesDirections:
	.string "MILO: Thanks you guys for\n"
	.string "fighting TEAM GENESIS!\p"
	.string "I'm a POKéMON RANGER. I'm supposed\n"
	.string "to help people and POKéMON.\p"
	.string "But in the end, I needed other\n"
	.string "trainers to help me...\p"
	.string "\p"
	.string "Anyway, you guys are looking\n"
	.string "for POKéMON gyms, right?\p"
	.string "Around here, there are 3 gyms.\p"
	.string "They're in...\l"
	.string "MINDARO CITY...\l"
	.string "PITCHBLAK CITY...\p"
	.string "And MAROON CITY.\n"
	.string "That's where I'm headed now.\p"
	.string "Our headquarters is there. If you're\n"
	.string "going there, you should check it out.\p"
	.string "You guys would make great POKéMON\n"
	.string "RANGERS, I'll bet.\p"
	.string "Well anyway, thanks again!$"

TurquoiseCity_Movement_MiloLeaves:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

TurquoiseCity_EventScript_JaceExit::
	applymovement LOCALID_JACE, Common_Movement_FaceLeft
	waitmovement 0
	msgbox TurquoiseCity_Text_JaceGoodbye, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_JACE, TurquoiseCity_Movement_JaceLeaves
	waitmovement 0
	removeobject LOCALID_JACE
	setflag FLAG_HIDE_JACE
	setflag FLAG_HIDE_BRENDAN
	setvar VAR_TURQUOISE_CITY_STATE, 4
	delay 60
	releaseall
	end

TurquoiseCity_Text_JaceGoodbye:
	.string "JACE: MINDARO CITY, PITCHBLAK CITY,\n"
	.string "and MAROON CITY.\p"
	.string "So that's where the gyms are.\p"
	.string "I wonder which one we should\n"
	.string "challenge first...\p"
	.string "\p"
	.string "Well, I think we should split up here.\p"
	.string "Go off on our own adventures for a bit,\n"
	.string "you know?\p"
	.string "Just you wait. We'll be ten times stronger\n"
	.string "the next time you see us!\p"
	.string "See you around, {PLAYER}!$"


















TurquoiseCity_EventScript_Conman::
	lock
	faceplayer
	goto_if_set FLAG_BOUGHT_SMEARGLE, TurquoiseCity_EventScript_AlreadyBoughtSmeargle
	showmoneybox 0, 0

	msgbox TurquoiseCity_Text_SellRarePokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TurquoiseCity_EventScript_DeclineSmeargle
	checkmoney SMEARGLE_PRICE
	goto_if_eq VAR_RESULT, FALSE, TurquoiseCity_EventScript_NotEnoughMoney
	setvar VAR_TEMP_1, SPECIES_SMEARGLE
	givemon SPECIES_SMEARGLE, 20
	goto_if_eq VAR_RESULT, 0, TurquoiseCity_EventScript_BuySmeargleParty
	goto_if_eq VAR_RESULT, 1, TurquoiseCity_EventScript_BuySmearglePC
	goto_if_eq VAR_RESULT, 2, TurquoiseCity_EventScript_NoRoomForSmeargle
	end

TurquoiseCity_EventScript_BuySmeargleParty::
	call TurquoiseCity_EventScript_PayForSmeargle
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TurquoiseCity_EventScript_EndPurchaseSmeargle
	call Common_EventScript_GetGiftMonPartySlot
	fadescreen FADE_TO_BLACK
	hidemoneybox
	special ChangePokemonNickname
	waitstate
	goto TurquoiseCity_EventScript_BoughtSmeargle
	end

TurquoiseCity_EventScript_BuySmearglePC::
	call TurquoiseCity_EventScript_PayForSmeargle
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TurquoiseCity_EventScript_TransferSmeargleCloseMoneyBox
	fadescreen FADE_TO_BLACK
	hidemoneybox
	special ChangeBoxPokemonNickname
	waitstate
	lock
	faceplayer
	goto TurquoiseCity_EventScript_TransferSmeargle
	end

TurquoiseCity_EventScript_TransferSmeargleCloseMoneyBox::
	call Common_EventScript_TransferredToPC
	goto TurquoiseCity_EventScript_EndPurchaseSmeargle
	end

TurquoiseCity_EventScript_TransferSmeargle::
	call Common_EventScript_TransferredToPC
	goto TurquoiseCity_EventScript_BoughtSmeargle
	end

TurquoiseCity_EventScript_EndPurchaseSmeargle::
	hidemoneybox
	goto TurquoiseCity_EventScript_BoughtSmeargle
	end

TurquoiseCity_EventScript_BoughtSmeargle::
	setflag FLAG_BOUGHT_SMEARGLE
	release
	end

TurquoiseCity_EventScript_PayForSmeargle::
	removemoney SMEARGLE_PRICE
	updatemoneybox
	playfanfare MUS_LEVEL_UP
	message TurquoiseCity_Text_PaidOutrageousPrice
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_SMEARGLE
	return

TurquoiseCity_EventScript_DeclineSmeargle::
	msgbox TurquoiseCity_Text_NotEnoughMoney
	hidemoneybox
	release
	end

TurquoiseCity_EventScript_NotEnoughMoney::
	msgbox TurquoiseCity_Text_NotEnoughMoney
	hidemoneybox
	release
	end

TurquoiseCity_EventScript_AlreadyBoughtSmeargle::
	msgbox TurquoiseCity_Text_NoRefunds
	release
	end

TurquoiseCity_EventScript_NoRoomForSmeargle::
	msgbox gText_NoMoreRoomForPokemon
	hidemoneybox
	release
	end


TurquoiseCity_Text_SellRarePokemon:
	.string "Psst, hey kid!\p"
	.string "You look like a smart guy with an\n"
	.string "eye for something special.\p"
 	.string "Lucky for you, I've got just the thing.\n"
	.string "A super rare POKéMON!\l"
	.string "The likes of which you've never seen!\p"
	.string "It can learn powerful moves like\n"
	.string "Earthquake, Outrage, Dragon Dance,\l"
	.string "and even Extremespeed!\p" 
	.string "Trust me, this little beauty is worth\n"
	.string "its weight in gold.\p"
	.string "But keep it quiet, alright?\p"
	.string "We don't want everyone knowing about\n"
	.string "this incredible deal.\p"
	.string "For a small price, say ¥9999, this\n"
	.string "one-of-a-kind POKéMON could be yours.\p"
	.string "What do you say? A smart trainer like you\n"
	.string "can't pass up a steal like this, right?$"

TurquoiseCity_Text_NotEnoughMoney:
	.string "Oh, not enough cash on hand?\p"
	.string "I get it, times can be tough.\p"
	.string "Tell you what, since I like you,\n"
	.string "I'll hold onto this rare gem for you.\p"
	.string "Just come back when you've got the funds,\n"
	.string "and it'll be our little secret deal, okay?$"

TurquoiseCity_Text_PaidOutrageousPrice:
	.string "{PLAYER} paid the outrageous ¥9999.$"

TurquoiseCity_Text_NoRefunds:
	.string "Hey no refunds, kid. I gotta eat too.$"

