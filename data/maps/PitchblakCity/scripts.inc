.set LOCALID_JACE, 24
.set LOCALID_ROBIN, 25

PitchblakCity_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PitchblakCity_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, PitchblakCity_OnTransition
	.byte 0

PitchblakCity_OnTransition:
	setflag FLAG_VISITED_PITCHBLAK_CITY
	call_if_eq VAR_PITCHBLAK_CITY_STATE, 2, PitchblakCity_EventScript_AfterNedaBattle
	call_if_ge VAR_PITCHBLAK_CITY_STATE, 3, PitchblakCity_EventScript_HideJaceAndRobin
	end

PitchblakCity_OnFrame:
	map_script_2 VAR_PITCHBLAK_CITY_STATE, 2, PitchblakCity_EventScript_MeetJaceAndRobin
	.2byte 0

PitchblakCity_EventScript_AfterNedaBattle::
	clearflag FLAG_HIDE_PITCHBLAK_COPS
	clearflag FLAG_HIDE_JACE
	return

PitchblakCity_EventScript_HideJaceAndRobin::
	setflag FLAG_HIDE_JACE
	removeobject LOCALID_JACE
	removeobject LOCALID_ROBIN
	return

PitchblakCity_EventScript_MeetJaceAndRobin::
	@lockall
	@setvar VAR_PITCHBLAK_CITY_STATE, 3
	delay 120
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	delay 60
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox PitchblakCity_Text_YoureAwakeNow, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	delay 20
	fadescreen FADE_FROM_BLACK
	msgbox PitchblakCity_Text_TeamGenesisAgain, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_ROBIN, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox PitchblakCity_Text_YouHeardAVoice, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox PitchblakCity_Text_BeatsMe, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox PitchblakCity_Text_CouldBeAClue, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROBIN, Common_Movement_FaceRight
	waitmovement 0
	delay 40
	applymovement LOCALID_ROBIN, Common_Movement_FaceDown
	waitmovement 0
	delay 20
	msgbox PitchblakCity_Text_WellAnyway, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceDown
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox PitchblakCity_Text_WhatAboutMe, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_ROBIN, Common_Movement_FaceLeft
	waitmovement 0
	delay 10
	msgbox PitchblakCity_Text_IKnowYouDid, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceRight
	waitmovement 0
	delay 10
	msgbox PitchblakCity_Text_LetMeFinish, MSGBOX_DEFAULT
	closemessage
	delay 40
	applymovement LOCALID_ROBIN, Common_Movement_FaceDown
	waitmovement 0
	delay 20
	msgbox PitchblakCity_Text_TellMeLater, MSGBOX_DEFAULT
	closemessage
	delay 90
	msgbox PitchblakCity_Text_JaceWeirdTree, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox PitchblakCity_Text_RobinWeirdTree, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox PitchblakCity_Text_JaceWeirdTree2, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_ROBIN, Common_Movement_FaceLeft
	waitmovement 0
	delay 10
	msgbox PitchblakCity_Text_RobinWeirdTree2, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_ROBIN, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_ROBIN, Common_Movement_FaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	giveitem ITEM_ROAD_SALT
	waitfanfare
	msgbox PitchblakCity_Text_ExplainRoadSalt, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROBIN, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_ROBIN, Common_Movement_FaceLeft
	waitmovement 0
	delay 20
	msgbox PitchblakCity_Text_RobinBye, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROBIN, Common_Movement_FaceDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject LOCALID_ROBIN
	waitfieldeffect FLDEFF_NPCFLY_OUT
	delay 60
	applymovement LOCALID_JACE, Common_Movement_FaceDown
	waitmovement 0
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	delay 50
	msgbox PitchblakCity_Text_JaceBye, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JACE, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkUp
	waitmovement 0
	setvar VAR_PITCHBLAK_CITY_STATE, 3
	setflag FLAG_HIDE_JACE
	removeobject LOCALID_JACE
	releaseall
	end

PitchblakCity_Text_YoureAwakeNow:
	.string "JACE: Hey, you're awake now.\p"
	.string "We were just standing here talking\n"
	.string "and all of a sudden you\l"
	.string "appeared out of nowhere!\p"
	.string "What happened to you?$"

PitchblakCity_Text_TeamGenesisAgain:
	.string "JACE: TEAM GENESIS again, huh?\n"
	.string "Those guys really tick me off.\p"
	.string "Oh by the way, this is ROBIN.\n"
	.string "She's with the POKéMON RANGERS.$"

PitchblakCity_Text_YouHeardAVoice:
	.string "ROBIN: You said you a heard voice calling\n"
	.string "out to you? What did it say?\p"
	.string "\p"
	.string "Get help.\n"
	.string "AB LABS.\p"
	.string "What could that mean?$"

PitchblakCity_Text_BeatsMe: 
	.string "Beats me. Are you sure you weren't\n"
	.string "just dreaming that part, {PLAYER}?$"

PitchblakCity_Text_CouldBeAClue: 
	.string "ROBIN: Well, I think it's worth\n"
	.string "reporting to headquarters anyway.\p"
	.string "It might be a clue to where\n"
	.string "TEAM GENESIS is hiding.\p"
	.string "We've been trying to track them down\n"
	.string "for a while now.\p"
	.string "But they always manage to slip\n"
	.string "away from us.\p"
	.string "Not even JUSTIN could find\n"
	.string "their hideout.\p"
	.string "It's almost like they disappear\n"
	.string "into thin air...$"

PitchblakCity_Text_WellAnyway:
	.string "Well, anyway. I need to be getting\n"
	.string "back to headquarters.\p"
	.string "There's a big meeting coming up.\n"
	.string "Everyone's supposed to be there.\p"
	.string "By the way, {PLAYER}. JACE tells me\n"
	.string "you're looking for gym badges.\p"
	.string "There's a gym in MAROON CITY too.\p"
	.string "If you're in the area, you should\n"
	.string "stop by headquarters and\l"
	.string "tell everyone your story.\p"
	.string "It could be a big help in the\n"
	.string "search for TEAM GENESIS.$"

PitchblakCity_Text_WhatAboutMe:
	.string "Hey, what about me? I fought\n"
	.string "TEAM GENESIS too, you know.$"

PitchblakCity_Text_IKnowYouDid:
	.string "I know you did, JACE. You told me\n"
	.string "that story three times now...$"

PitchblakCity_Text_LetMeFinish:
	.string "That's because you never let me finish!\p"
	.string "I didn't even tell you the part where\n"
	.string "I stood up to the GENESIS boss!$"

PitchblakCity_Text_TellMeLater:
	.string "Sigh... Well, you can tell me\n"
	.string "back at headquarters.\p"
	.string "I'm sure they'll want to hear\n"
	.string "your story too.\p"
	.string "\p"
	.string "If you've never been to MAROON CITY,\n"
	.string "you'll have to go the long way.\p"
	.string "Through SCARLET WOODS, I mean.\p"
	.string "It's not the easiest place to\n"
	.string "navigate, just so you know.$"

PitchblakCity_Text_JaceWeirdTree:
	.string "JACE: Uh, actually I tried\n"
	.string "going there before.\p"
	.string "But there was this weird tree\n"
	.string "in the way.\p"
	.string "And it was in a cave for some reason.$"

PitchblakCity_Text_RobinWeirdTree:
	.string "ROBIN: Hmmm...\p"
	.string "Was it covered in ice?$"

PitchblakCity_Text_JaceWeirdTree2:
	.string "JACE: Yeah, but it wasn't like normal ice.\n"
	.string "My FIRE type couldn't even melt it!$"

PitchblakCity_Text_RobinWeirdTree2:
	.string "ROBIN: That's the abominable snowman.\p"
	.string "Or at least that's what the\n"
	.string "POKéMON RANGERS all call him.\p"
	.string "He lives on MT SHIRO.\p"
	.string "But sometimes he comes down\n"
	.string "and causes trouble for people.\p"
	.string "We're used to dealing with him\n"
	.string "all the time.\p"
	.string "Here, you two can have this.$"

PitchblakCity_Text_ExplainRoadSalt:
	.string "ROBIN: FIRE moves won't work on him.\p"
	.string "But that ROAD SALT should irritate him\n"
	.string "enough to get him moving.\p"
	.string "Be careful though, he might get angry\n"
	.string "and attack you.\p"
	.string "But I'm sure you can handle him.\n"
	.string "JACE told me you're pretty tough.$"

PitchblakCity_Text_RobinBye:
	.string "ROBIN: Well, goodbye for now.$"

PitchblakCity_Text_JaceBye:
	.string "JACE: Man, how is it you end up with\n"
	.string "these cool stories all the time?\p"
	.string "What's your secret?\p"
	.string "\p"
	.string "Well, I gotta hang around here\n"
	.string "for a bit longer.\p"
	.string "I still have to beat the gym leader.\p"
	.string "I guess I'll see you in MAROON CITY then.\p"
	.string "Just you wait. Next time, we'll show you\n"
	.string "how much stronger we've become!\p"
	.string "Later, {PLAYER}!$"























PitchblakCity_EventScript_GymSign::
	msgbox PitchblakCity_Text_GymSign, MSGBOX_SIGN
	end

PitchblakCity_EventScript_CitySign::
	msgbox PitchblakCity_Text_CitySign, MSGBOX_SIGN
	end

PitchblakCity_EventScript_KendomSign::
	msgbox PitchblakCity_Text_KendomSign, MSGBOX_SIGN
	end

PitchblakCity_Text_GymSign:
	.string "PITCHBLAK CITY POKéMON GYM\n"
	.string "LEADER: CADE\l"
	.string "“Rhythm and grooves.”$"

PitchblakCity_Text_CitySign:
	.string "PITCHBLAK CITY\n"
	.string "“Pitch black progress.”$"

PitchblakCity_Text_KendomSign:
	.string "KENDOM CORP HEADQUARTERS$"




PitchblakCity_EventScript_Woman2::
	lock
	faceplayer
	msgbox PitchblakCity_Text_DrugsOnStreets, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Text_DrugsOnStreets:
	.string "Be careful. There are some shady\n"
	.string "people in this city.\p"
	.string "Remember to make good decisions!$"

PitchblakCity_EventScript_Renter::
	lock
	faceplayer
	msgbox PitchblakCity_Text_RentWentUp, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Text_RentWentUp:
	.string "My rent went up for the third time\n"
	.string "this year. Can you believe that?$"

PitchblakCity_EventScript_Cyclist1::
	lock
	faceplayer
	msgbox PitchblakCity_Text_GonnaBeLate, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Text_GonnaBeLate:
	.string "Ugh, I'm gonna be late...$"


PitchblakCity_EventScript_Cyclist2::
	lock
	faceplayer
	msgbox PitchblakCity_Text_AskForDirections, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Text_AskForDirections:
	.string "Excuse me.\n"
	.string "Do you know where the plaza is?$"



PitchblakCity_EventScript_OldMan::
	lock
	faceplayer
	msgbox PitchblakCity_Text_KidsTheseDays, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Text_KidsTheseDays:
	.string "Kids these days and their\n"
	.string "video screens.\p"
	.string "When I was a kid, we used to go\n"
	.string "outside and play stickball!$"

PitchblakCity_EventScript_Rocker::
	lock
	faceplayer
	msgbox PitchblakCity_Text_BroadcastTower, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Text_BroadcastTower:
	.string "BROADCAST TOWER used to be the heart\n"
	.string "of the radio network here in ISSHO.\p"
	.string "Now it's a habitat for wild POKéMON.$"

PitchblakCity_EventScript_Rocker2::
	lock
	faceplayer
	msgbox PitchblakCity_Text_MusicGym, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Text_MusicGym:
	.string "The old radio stations shut down\n"
	.string "years ago.\p"
	.string "Now CADE broadcasts all the music\n"
	.string "from his gym.$"




PitchblakCity_EventScript_Policeman::
	msgbox PitchblakCity_Text_WereDoingEverythingWeCan, MSGBOX_NPC
	end

PitchblakCity_Text_WereDoingEverythingWeCan:
	.string "Please understand we're doing all\n"
	.string "we can to find the culprits.$"

PitchblakCity_EventScript_Protester1::
	msgbox PitchblakCity_Text_SwarmLaw, MSGBOX_NPC
	end

PitchblakCity_Text_SwarmLaw:
	.string "These POKéMON swarms have been getting\n"
	.string "out of control lately.\p"
	.string "The city needs to put together a task\n"
	.string "force to deal with it right away.$"

PitchblakCity_EventScript_Protester2::
	msgbox PitchblakCity_Text_Crime, MSGBOX_NPC
	end

PitchblakCity_Text_Crime:
	.string "When will the city finally\n"
	.string "address its crime problem?\p"
	.string "Last week, my store windows\n"
	.string "were completely smashed!$"

PitchblakCity_EventScript_Protester3::
	msgbox PitchblakCity_Text_RegulateMedicine, MSGBOX_NPC
	end

PitchblakCity_Text_RegulateMedicine:
	.string "I don't know how I feel about\n"
	.string "this gene therapy stuff.\p"
	.string "What if only the super rich will\n"
	.string "be able to afford it?$"

PitchblakCity_EventScript_Protester4::
	msgbox PitchblakCity_Text_CoolProducts, MSGBOX_NPC
	end

PitchblakCity_Text_CoolProducts:
	.string "Have you been to the plaza recently?\p"
	.string "They're showing off some cool new\n"
	.string "tech they've been working on.$"



PitchblakCity_EventScript_Boy2::
	lock
	faceplayer
	msgbox PitchblakCity_Text_OutsideCity, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Text_OutsideCity:
	.string "Have you ever been outside\n"
	.string "the city before?\p"
	.string "It's so quiet and empty and lonely.\n"
	.string "It makes me nervous.$"

PitchblakCity_EventScript_Burglar::
	msgbox PitchblakCity_Text_TrashDigger, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Text_TrashDigger:
	.string "Hey, don't judge.\p"
	.string "One man's trash is\n"
	.string "another man's treasure.$"






PitchblakCity_EventScript_Commie1::
	msgbox PitchblakCity_Text_CapitalistSystem, MSGBOX_NPC
	end

PitchblakCity_Text_CapitalistSystem:
	@.string "Property crime is not a crime!\p"
	@.string "The only victim is the\n"
	@.string "capitalist system!$"
	.string "Abolish private property!\n"
	.string "The earth belongs to everyone!$"





PitchblakCity_EventScript_Commie2::
	lock
	faceplayer
	msgbox PitchblakCity_Text_DoYouKnowAbout, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PitchblakCity_EventScript_OurJobToFixIt
	goto_if_eq VAR_RESULT, NO, PitchblakCity_EventScript_LongRant
	end

PitchblakCity_EventScript_LongRant::
	msgbox PitchblakCity_Text_LongRant, MSGBOX_DEFAULT
	release
	end

PitchblakCity_EventScript_OurJobToFixIt::
	msgbox PitchblakCity_Text_SmashCapitalism, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Text_DoYouKnowAbout:
	.string "Do you know about the\n"
	.string "capitalist hegemony?$"

PitchblakCity_Text_SmashCapitalism:
	.string "Then you know that we have to\n"
	.string "do everything we can to smash\l"
	.string "capitalism once and for all!$"

PitchblakCity_Text_LongRant:
	.string "Okay, so capitalism is the system\n"
	.string "we're all stuck in.\p"
	.string "It's supposed to be the greatest\n"
	.string "thing ever.\p"
	.string "Because freedom and opportunity, right?\p"
	.string "Yeah, except it's a giant scam.\p"
	.string "Capitalism is basically this system where\n"
	.string "a few people at the top get super rich\l"
	.string "while everyone else works their butts off\l"
	.string "and barely gets by.\p"
	.string "Guys like those bigwigs at KENDOM\n"
	.string "CORP make millions by doing\l"
	.string "basically nothing.\p"
	.string "And you know what else?\p"
	.string "They control everything!\n"
	.string "The politicians, the media, it's all rigged!\p" 
	.string "And don't get me started on what they do\n"
	.string "to the environment!\p"
	.string "Have you seen all the pollution\n"
	.string "on ROUTE 91?\p"
	.string "These guys will destroy the planet just\n"
	.string "to make a few extra bucks!\p"
	.string "Capitalism also wants us to believe\n"
	.string "it's the only way.\p"
	.string "That's why anytime someone suggests\n"
	.string "an alternative, like socialism,\p"
	.string "they're immediately labeled as crazy\n"
	.string "and unrealistic.\p"
	.string "The system HAS to make us think there's\n"
	.string "no better option.\p"
	.string "Because if people started realizing\n"
	.string "that it's all a giant scam,\l"
	.string "it would collapse.\p"
	.string "They've got us all thinking that\n"
	.string "working and barely making a living\l"
	.string "is just how life is supposed to be.\p"
	.string "They keep us divided too!\p"
	.string "It's like, instead of focusing\n"
	.string "on how messed up things are,\l"
	.string "we're taught to blame other people.\p"
	.string "Immigrants, minorities, poor people,\n"
	.string "whoever.\p"
	.string "The system makes us fight each other\n"
	.string "so we don't fight them.\p"
	.string "They make us think we're failing because\n"
	.string "we're not trying hard enough.\p"
	.string "Not because the system is\n"
	.string "stacked against us!\p"
	.string "So yeah, capitalism sucks.\p"
	.string "The working class needs to rise up and\n"
	.string "smash the system once and for all!$"


PitchblakCity_EventScript_Commie3::
	msgbox PitchblakCity_Text_PokeballOppression, MSGBOX_NPC
	end

PitchblakCity_Text_PokeballOppression:
	.string "You keep POKéMON in POKé BALLS?\n"
	.string "Don't you know that's oppressive?$"


PitchblakCity_EventScript_Girl::
	msgbox PitchblakCity_Text_WishTheydLeave, MSGBOX_NPC
	end

PitchblakCity_Text_WishTheydLeave:
	.string "I don't really understand anything\n"
	.string "they're talking about.\p"
	.string "I just want to play with my POKéMON.$"

PitchblakCity_EventScript_Boy::
	msgbox PitchblakCity_Text_ThoseProtestors, MSGBOX_NPC
	end

PitchblakCity_Text_ThoseProtestors:
	.string "Those guys show up here every time\n"
	.string "something big happens in this city.\p"
	.string "They're protesting against KENDOM CORP\n"
	.string "this time, I think.$"



PitchblakCity_EventScript_LittleBoy::
	msgbox PitchblakCity_Text_KeepForgettingInverseBattles, MSGBOX_NPC
	end

PitchblakCity_Text_KeepForgettingInverseBattles:
	.string "Man, it's hard to get used to\n"
	.string "inverse battles.\p"
	.string "I keep choosing moves like I'm\n"
	.string "in a regular battle.$"

PitchblakCity_EventScript_LittleGirl::
	lock
	faceplayer
	goto_if_quest_complete QUEST_24, PitchblakCity_EventScript_QuestComplete
	goto_if_defeated TRAINER_HABIBAH, PitchblakCity_EventScript_FinishQuest
	goto_if_quest_active QUEST_24, PitchblakCity_EventScript_QuestInProgress
	msgbox PitchblakCity_Text_InverseBattles, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PitchblakCity_EventScript_UnlockQuest
	msgbox PitchblakCity_Text_CantAppreciate, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Text_InverseBattles:
	.string "You're new to this neighborhood,\n"
	.string "I can tell.\p"
	.string "You might think you're pretty\n"
	.string "hot for a trainer.\p"
	.string "But we do things differently here.\p"
	.string "It's called inverse battling.\l"
	.string "It's like regular battles.\p"
	.string "Except the types are all\n"
	.string "backwards in how they work.\p"
	.string "You think you can handle that?$"

PitchblakCity_Text_CantAppreciate:
	.string "Hmm, guess I was wrong about you.\n"
	.string "You're just some poser after all.\p"
	.string "Just kidding, it's cool.\n"
	.string "Not everybody's cut out for it.$"

PitchblakCity_EventScript_UnlockQuest::
	msgbox PitchblakCity_Text_LikeYourStyle, MSGBOX_DEFAULT
	startquest QUEST_24
	release
	end

PitchblakCity_Text_LikeYourStyle:
	.string "I like your attitude.\p"
	.string "There's a house in the\n"
	.string "old radio district.\p"
	.string "That's where all the inverse\n"
	.string "trainers meet.\p"
	.string "Why don't you try taking them on?\p"
	.string "If you can beat them all, I'll give\n"
	.string "you something good.$"


PitchblakCity_EventScript_QuestInProgress::
	msgbox PitchblakCity_Text_TrainersRemain, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Text_TrainersRemain:
	.string "Like I said, go to the house in\n"
	.string "the old radio district.\p"
	.string "And make sure you heal up first, too.$"

PitchblakCity_EventScript_FinishQuest::
	msgbox PitchblakCity_Text_YouBeatMySister, MSGBOX_DEFAULT
	giveitem ITEM_ASSAULT_VEST
	completequest QUEST_24
	release
	end

PitchblakCity_Text_YouBeatMySister:
	.string "No way!\n"
	.string "You really beat my big sister?\p"
	.string "You must be tough after all.\p"
	.string "Here, you can have this as promised.$"

PitchblakCity_EventScript_QuestComplete::
	msgbox PitchblakCity_Text_ExplainAssaultVest, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Text_ExplainAssaultVest:
	.string "Give that ASSAULT VEST to one of\n"
	.string "your POKéMON to hold.\p"
	.string "It will make them even tougher\n"
	.string "against special hits.\p"
	.string "But the tradeoff is they won't be able to\n"
	.string "use nondamaging moves while wearing it.$"






PitchblakCity_EventScript_Woman::
	msgbox PitchblakCity_Text_NotRightNow, MSGBOX_NPC
	end

PitchblakCity_Text_NotRightNow:
	.string "Not right now.\n"
	.string "Can't you see that I'm busy?$"

PitchblakCity_EventScript_Roughneck::
	msgbox PitchblakCity_Text_WhatAreYouLookinAt, MSGBOX_NPC
	end

PitchblakCity_Text_WhatAreYouLookinAt:
	.string "What are you lookin' at, punk.$"

PitchblakCity_EventScript_FatMan::
	lockall
	msgbox PitchblakCity_Text_FeedingTheBirds, MSGBOX_DEFAULT
	releaseall
	end

PitchblakCity_Text_FeedingTheBirds:
	.string "Don't mind me.\n"
	.string "Just feeding the birds.$"

PitchblakCity_EventScript_Pokemon::
	lock
	faceplayer
	playmoncry SPECIES_SPEAROW, CRY_MODE_NORMAL
	msgbox PitchblakCity_Text_Pokemon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

PitchblakCity_Text_Pokemon:
	.string "SPEAROW: Piyu piiyuu$"











