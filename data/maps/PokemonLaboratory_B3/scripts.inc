.set LOCALID_BLACKBALL1, 1
.set LOCALID_BLACKBALL2, 2
.set LOCALID_JACE, 3
.set LOCALID_RAYNER, 4

PokemonLaboratory_B3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonLaboratory_B3_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLaboratory_B3_OnFrame
	.byte 0

PokemonLaboratory_B3_OnTransition:
	call_if_eq VAR_WISTERIA_CITY_STATE, 10, PokemonLaboratory_B3_EventScript_RevealBlackBalls
	call_if_ge VAR_WISTERIA_CITY_STATE, 11, PokemonLaboratory_B3_EventScript_HideJace
	call_if_ge VAR_WISTERIA_CITY_STATE, 11, PokemonLaboratory_B3_EventScript_HideRayner
	call_if_ge VAR_WISTERIA_CITY_STATE, 11, PokemonLaboratory_B3_EventScript_HideBlackBalls
	end

PokemonLaboratory_B3_EventScript_HideJace:
	removeobject LOCALID_JACE
	setflag FLAG_HIDE_JACE
	return

PokemonLaboratory_B3_EventScript_HideRayner:
	removeobject LOCALID_RAYNER
	setflag FLAG_HIDE_RAYNER
	return

PokemonLaboratory_B3_EventScript_RevealBlackBalls:
	clearflag FLAG_HIDE_BLACK_BALL_1
	addobject LOCALID_BLACKBALL1
	clearflag FLAG_HIDE_BLACK_BALL_2
	addobject LOCALID_BLACKBALL2
	return

PokemonLaboratory_B3_EventScript_HideBlackBalls:
	removeobject LOCALID_BLACKBALL1
	setflag FLAG_HIDE_BLACK_BALL_1
	removeobject LOCALID_BLACKBALL2
	setflag FLAG_HIDE_BLACK_BALL_2
	return

PokemonLaboratory_B3_EventScript_AddJace:
	removeobject LOCALID_JACE
	setobjectxyperm LOCALID_JACE, 10, 19
	setobjectmovementtype LOCALID_JACE, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_JACE
	addobject LOCALID_JACE
	return

PokemonLaboratory_B3_EventScript_AddRayner:
	removeobject LOCALID_RAYNER
	setobjectxyperm LOCALID_RAYNER, 9, 19
	setobjectmovementtype LOCALID_RAYNER, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_RAYNER
	addobject LOCALID_RAYNER
	return

PokemonLaboratory_B3_OnFrame:
	map_script_2 VAR_WISTERIA_CITY_STATE, 10, PokemonLaboratory_B3_EventScript_EntityEncounter
	.2byte 0



PokemonLaboratory_B3_EventScript_EntityEncounter::
	lockall
	fadeoutbgm 0
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLaboratory_B3_Movement_PlayerEnter
	waitmovement 0
	delay 120
	playse SE_M_NIGHTMARE
	waitse
	msgbox PokemonLaboratory_B3_Text_OminousPresence, MSGBOX_DEFAULT
	closemessage
	delay 60
	@playmoncry SPECIES_ETERNATUS, CRY_MODE_NORMAL
	@waitmoncry

	@trainerkarmabattle_no_intro TRAINER_POKEMON_LABORATORY_ENTITY, PokemonLaboratory_B2_Text_EntityDefeated
	@goto PokemonLaboratory_B3_EventScript_DefeatedEntity
	
	specialvar VAR_TEMP_0, GetBattleCountForKarmaBattle
	buffernumberstring STR_VAR_2, VAR_TEMP_0
	@msgbox UmberTown_Text_BattleCount, MSGBOX_DEFAULT
	@closemessage
	goto PokemonLaboratory_B3_EventScript_EntityLoop

	@trainerbattle_no_intro TRAINER_POKEMON_LABORATORY_ENTITY, PokemonLaboratory_B3_Text_EntityDefeated
	@goto PokemonLaboratory_B3_EventScript_DefeatedEntity
	end

PokemonLaboratory_B3_EventScript_EntityLoop::
	playmoncry SPECIES_ETERNATUS, CRY_MODE_WEAK
	waitmoncry
	buffernumberstring STR_VAR_3, VAR_TEMP_0
	msgbox PokemonLaboratory_B3_Text_WeightOfSin, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_POKEMON_LABORATORY_ENTITY, PokemonLaboratory_B3_Text_EntityDefeated
	subvar VAR_TEMP_0, 1
	goto_if_gt VAR_TEMP_0, 0, PokemonLaboratory_B3_EventScript_EntityLoop

	goto PokemonLaboratory_B3_EventScript_DefeatedEntity
	end

PokemonLaboratory_B3_Text_WeightOfSin:
	.string "You feel the weight of your sins.\p"
	.string "{STR_VAR_3} battle(s) remaining!$"

PokemonLaboratory_B3_Movement_PlayerEnter:
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

@ Rayner, mass-produced in a cold uncaring world
@ rejects morality and embraces the absurdity of existence

@ The ultimate fear we all have, being alone in an uncaring universe


PokemonLaboratory_B3_EventScript_DefeatedEntity::
	fadeoutbgm 0
	playmoncry SPECIES_ETERNATUS, CRY_MODE_FAINT
	waitmoncry
	playse SE_FLEE
	@playse SE_M_NIGHTMARE
	msgbox PokemonLaboratory_B3_Text_EntitiesVanished, MSGBOX_DEFAULT
	closemessage
	delay 60
	call PokemonLaboratory_B3_EventScript_AddJace
	applymovement LOCALID_JACE, PokemonLaboratory_B3_Movement_JaceEntersEntityRoom
	waitmovement 0
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox PokemonLaboratory_B3_Text_JaceHey, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JACE, Common_Movement_FaceRight
	waitmovement 0
	delay 60
	applymovement LOCALID_JACE, Common_Movement_FaceUp
	waitmovement 0
	msgbox PokemonLaboratory_B3_Text_JaceGreatWork, MSGBOX_DEFAULT
	closemessage
	call PokemonLaboratory_B3_EventScript_AddRayner
	applymovement LOCALID_RAYNER, PokemonLaboratory_B3_Movement_RaynerEntersEntityRoom
	waitmovement 0
	delay 60
	applymovement LOCALID_RAYNER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox PokemonLaboratory_B3_Text_RaynerTakesLostTech, MSGBOX_DEFAULT
	closemessage
	delay 20
	removeobject LOCALID_BLACKBALL1
	delay 40
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_JACE, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_FaceDown
	waitmovement 0
	msgbox PokemonLaboratory_B3_Text_RaynerTakesLostTech2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PokemonLaboratory_B3_Text_JaceWhatAreYouSaying, MSGBOX_DEFAULT
	closemessage
	delay 40
	applymovement LOCALID_RAYNER, Common_Movement_FaceRight
	waitmovement 0
	delay 20
	msgbox PokemonLaboratory_B3_Text_RaynerPlayedYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox PokemonLaboratory_B3_Text_JaceYoureWithTeamGenesis, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox PokemonLaboratory_B3_Text_RaynerYup, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_RAYNER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox PokemonLaboratory_B3_Text_RaynerTauntsPlayer, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, YES, PokemonLaboratory_B3_EventScript_RaynerBattle
	msgbox PokemonLaboratory_B3_Text_RaynerSkipBattle, MSGBOX_DEFAULT
	closemessage
	goto PokemonLaboratory_B3_EventScript_JaceArguesWithRayner
	end

PokemonLaboratory_B3_EventScript_RaynerBattle::
	msgbox PokemonLaboratory_B3_Text_RaynerPreBattle, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro_no_whiteout TRAINER_RAYNER_POKEMON_LABORATORY, PokemonLaboratory_B3_Text_RaynerDefeated
	special CheckIfTeamFainted
	goto_if_eq VAR_RESULT, FALSE, PokemonLaboratory_B3_EventScript_WonRaynerBattle
	goto_if_eq VAR_RESULT, TRUE, PokemonLaboratory_B3_EventScript_LostRaynerBattle
	end

PokemonLaboratory_B3_EventScript_WonRaynerBattle::
	fadeoutbgm 0
	msgbox PokemonLaboratory_B3_Text_RaynerVictory, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox PokemonLaboratory_B3_Text_RaynerBestTools, MSGBOX_DEFAULT
	closemessage
	msgbox PokemonLaboratory_B3_Text_RaynerOtherWorlds, MSGBOX_DEFAULT
	closemessage
	goto PokemonLaboratory_B3_EventScript_JaceArguesWithRayner
	end

PokemonLaboratory_B3_EventScript_LostRaynerBattle::
	fadeoutbgm 0
	msgbox PokemonLaboratory_B3_Text_RaynerLoss, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox PokemonLaboratory_B3_Text_RaynerLoss2, MSGBOX_DEFAULT
	closemessage
	delay 10
	msgbox PokemonLaboratory_B3_Text_RaynerBestTools, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_RAYNER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox PokemonLaboratory_B3_Text_RaynerOtherWorlds, MSGBOX_DEFAULT
	closemessage
	goto PokemonLaboratory_B3_EventScript_JaceArguesWithRayner
	end

PokemonLaboratory_B3_EventScript_JaceArguesWithRayner::
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox PokemonLaboratory_B3_Text_JaceScrewYou, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_RAYNER, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	applymovement LOCALID_RAYNER, Common_Movement_WalkDown
	waitmovement 0
	delay 10
	applymovement LOCALID_RAYNER, Common_Movement_FaceRight
	waitmovement 0
	delay 60
	msgbox PokemonLaboratory_B3_Text_RaynerNotLikeThat, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox PokemonLaboratory_B3_Text_JaceWorkingForTeamGenesis, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox PokemonLaboratory_B3_Text_RaynerDidntHaveChoice, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox PokemonLaboratory_B3_Text_JaceWhatsThat, MSGBOX_DEFAULT
	closemessage
	delay 10
	msgbox PokemonLaboratory_B3_Text_RaynerRetroviruses, MSGBOX_DEFAULT
	closemessage
	delay 10
	msgbox PokemonLaboratory_B3_Text_JaceWhat, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_RAYNER, Common_Movement_FaceLeft
	waitmovement 0
	delay 30
	msgbox PokemonLaboratory_B3_Text_RaynerExplainsVirus, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_RAYNER, Common_Movement_FaceRight
	waitmovement 0
	delay 30
	msgbox PokemonLaboratory_B3_Text_RaynerDoYouRemember, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_RAYNER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox PokemonLaboratory_B3_Text_RaynerIncomplete, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox PokemonLaboratory_B3_Text_RaynerIncomplete2, MSGBOX_DEFAULT
	closemessage
	delay 60
	@applymovement LOCALID_JACE, Common_Movement_WalkInPlaceLeft
	@waitmovement 0
	msgbox PokemonLaboratory_B3_Text_JaceQuestions, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox PokemonLaboratory_B3_Text_RaynerTooManyQuestions, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_JACE, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox PokemonLaboratory_B3_Text_JaceXanthosCity, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_RAYNER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox PokemonLaboratory_B3_Text_RaynerOops, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PokemonLaboratory_B3_Text_JaceWhatHappensToPeople, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox PokemonLaboratory_B3_Text_RaynerWhoCares, MSGBOX_DEFAULT
	closemessage
	delay 10
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PokemonLaboratory_B3_Text_JaceSoHeartless, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_RAYNER, Common_Movement_FaceRight
	waitmovement 0
	delay 60
	msgbox PokemonLaboratory_B3_Text_RaynerPhilosophy, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox PokemonLaboratory_B3_Text_JacePhilosophy, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_RAYNER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox PokemonLaboratory_B3_Text_RaynerPhilosophy2, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox PokemonLaboratory_B3_Text_JacePhilosophy2, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_RAYNER, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	msgbox PokemonLaboratory_B3_Text_RaynerWhatever, MSGBOX_DEFAULT
	closemessage
	@applymovement LOCALID_JACE, Common_Movement_WalkInPlaceFasterLeft
	@waitmovement 0
	delay 30
	msgbox PokemonLaboratory_B3_Text_JaceReally, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_RAYNER, Common_Movement_FaceRight
	waitmovement 0
	delay 60
	msgbox PokemonLaboratory_B3_Text_RaynerDoSomething, MSGBOX_DEFAULT
	closemessage
	delay 120
	msgbox PokemonLaboratory_B3_Text_JaceWontFight, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_RAYNER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox PokemonLaboratory_B3_Text_RaynerChickenOut, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox PokemonLaboratory_B3_Text_JaceComeWithUs, MSGBOX_DEFAULT
	closemessage
	delay 120
	msgbox PokemonLaboratory_B3_Text_RaynerWhat, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox PokemonLaboratory_B3_Text_JaceWayISeeIt, MSGBOX_DEFAULT
	closemessage
	delay 120
	msgbox PokemonLaboratory_B3_Text_RaynerNotNaive, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox PokemonLaboratory_B3_Text_JaceGoodPeople, MSGBOX_DEFAULT
	closemessage
	delay 120
	applymovement LOCALID_RAYNER, Common_Movement_WalkDown
	waitmovement 0
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_JACE, Common_Movement_FaceDown
	waitmovement 0
	delay 40
	msgbox PokemonLaboratory_B3_Text_RaynerDeclines, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox PokemonLaboratory_B3_Text_JaceRiskPeople, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_RAYNER, Common_Movement_FaceUp
	waitmovement 0
	delay 30
	msgbox PokemonLaboratory_B3_Text_RaynerThatsHowItWorks, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RAYNER, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_WalkDown
	waitmovement 0
	call PokemonLaboratory_B3_EventScript_HideRayner
	playse SE_EXIT
	waitse
	delay 60
	applymovement LOCALID_JACE, Common_Movement_FaceUp
	waitmovement 0
	delay 30
	msgbox PokemonLaboratory_B3_Text_JaceToPlayer, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JACE, Common_Movement_WalkLeftSlow
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_WalkUpSlow
	waitmovement 0
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	delay 60
	applymovement LOCALID_JACE, Common_Movement_WalkInPlaceUp
	waitmovement 0
	delay 20
	msgbox PokemonLaboratory_B3_Text_JaceToPlayer2, MSGBOX_DEFAULT
	closemessage
	fadeinbgm 0
	setvar VAR_WISTERIA_CITY_STATE, 11
	setvar VAR_RANGER_HQ_STATE, 2
	warp MAP_MAROON_CITY_RANGER_HQ_3F, 7, 7
	waitstate
	releaseall
	end

PokemonLaboratory_B3_Movement_JaceEntersEntityRoom:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLaboratory_B3_Movement_RaynerEntersEntityRoom:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLaboratory_B3_Text_OminousPresence:
	.string "An ominous presence surrounds you.$"

PokemonLaboratory_B3_Text_EntityDefeated:
	.string "...$"

PokemonLaboratory_B3_Text_EntitiesVanished:
	.string "The entities vanished!\p"
	.string "You feel something heavy\n"
	.string "leave your body.$"

PokemonLaboratory_B3_Text_JaceHey:
	.string "JACE: Hey {PLAYER}, you're alright!$"

PokemonLaboratory_B3_Text_JaceGreatWork:
	.string "That was intense whatever that was.\p"
	.string "But it looks like you managed to\n"
	.string "fight it off. Great work!$"

PokemonLaboratory_B3_Text_RaynerTakesLostTech:
	.string "RAYNER: Not bad, {PLAYER}.\p"
	@.string "I figured what it wanted was a\n"
	@.string "sentimental type like you.\p"
	@.string "Looks like I was right. And it looks like\n"
	@.string "you're good for something after all.$"
	.string "Guess you sentimentalists are good\n"
	.string "for something after all.$"

PokemonLaboratory_B3_Text_RaynerTakesLostTech2:
	.string "Now then, I'll be taking this one\n"
	.string "back to TEAM GENESIS.\p"
	.string "You're free to hold onto the other one,\n"
	.string "just so you know.$"

PokemonLaboratory_B3_Text_JaceWhatAreYouSaying:
	.string "JACE: Taking it back to TEAM GENESIS?\n"
	.string "What are you talking about?!$"

PokemonLaboratory_B3_Text_RaynerPlayedYou:
	.string "RAYNER: I'm saying I played you, idiot.\p"
	.string "TEAM GENESIS needs this LOST TECH\n"
	.string "to complete their plan.\p"
	.string "And I'm going to deliver it to them.\p"
	@.string "I just needed some sorry sap to take\n"
	@.string "care of whatever that thing was.\p"
	.string "I just needed the right guinea pigs\n"
	.string "to deal with whatever that was.$"
	@.string "And well, you two came along just in time.$"

PokemonLaboratory_B3_Text_JaceYoureWithTeamGenesis:
	.string "JACE: You've been working for\n"
	.string "TEAM GENESIS this whole time?!$"

PokemonLaboratory_B3_Text_RaynerYup:
	.string "RAYNER: Yup.\p"
	.string "Bet you feel pretty stupid now, huh?$"

PokemonLaboratory_B3_Text_RaynerTauntsPlayer:
	.string "What about you, {PLAYER}?\p"
	.string "Don't you hate being used?\n"
	.string "Wanna do something about it?$"

PokemonLaboratory_B3_Text_RaynerPreBattle:
	.string "That's what I wanted to hear.\n"
	.string "Let me see your pain!$"
	@.string "Show me all of your anger and pain!$"

PokemonLaboratory_B3_Text_RaynerDefeated:
	.string "...!?$"

PokemonLaboratory_B3_Text_RaynerSkipBattle:
	.string "No? And here I thought you were\n"
	.string "finally manning up for once.\p"
	.string "God, you're so pathetic.$"

PokemonLaboratory_B3_Text_RaynerVictory:
	.string "RAYNER: ...\p"
	.string "Hehehehehehehe.\n"
	.string "Still chasing power, are you?\p"
	.string "And yet your POKéMON are still so weak.$"

PokemonLaboratory_B3_Text_RaynerBestTools:
	.string "You need the best tools if you want\n"
	.string "to be the best trainer.\p"
	.string "I know I've told you that before.\p"
	@.string "Is it because you're still attached\n"
	@.string "to them somehow?\p"
	.string "Is it because you still can't\n"
	.string "let go of your POKéMON?\p"
	.string "Are you still letting your feelings\n"
	.string "become your weaknesses?\p"
	.string "Are you afraid to lose them?\p"
	.string "Are you afraid of being all alone?\p"
	.string "Hehehehe.\n"
	.string "But you will lose them one day.\p"
	.string "In the end, we're all on our own\n"
	.string "in this world.$" 

PokemonLaboratory_B3_Text_RaynerOtherWorlds:
	.string "Just like all those worlds\n"
	.string "in Ultra Space.\p"
	.string "Drifting forever farther apart in\n"
	.string "silent darkness.\p"
	.string "Which reminds me, I should be getting\n"
	.string "this back to TEAM GENESIS now.$"

PokemonLaboratory_B3_Text_RaynerLoss:
	.string "RAYNER: Hehehehehehehe.\p"
	.string "HAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHA\n"
	.string "HAHAHAHAHAHAHAHAHAHAHAHHAHA!\p"
	.string "So this is what all your\n"
	.string "training amounts to?\p"
	.string "God, you're so pathetic.$"

PokemonLaboratory_B3_Text_RaynerLoss2:
	.string "This is what I told you would happen\n"
	.string "if you kept relying on weak POKéMON.$"





PokemonLaboratory_B3_Text_JaceScrewYou:
	.string "JACE: Screw you, dude!\n"
	.string "You're not making any sense!\p"
	.string "First you say you hate TEAM GENESIS.\n"
	.string "And now you're working for them?!\p"
	.string "Was all that stuff from before\n"
	.string "just lies?$"

PokemonLaboratory_B3_Text_RaynerNotLikeThat:
	.string "RAYNER: Hehehe. I can tell a pretty\n"
	.string "good lie when I want to.\p"
	.string "But I never lied about anything.\p"
	.string "It's true that I hate TEAM GENESIS.\p"
	.string "It's true that I've been working\n"
	.string "for them for a long time now.\p"
	.string "And it's true that the device next to you\n"
	.string "can take you to their hideout.\p"
	.string "I'll even tell you where it is.\n"
	.string "But only if you ask me nicely.$"

PokemonLaboratory_B3_Text_JaceWorkingForTeamGenesis:
	.string "JACE: So you're working for TEAM GENESIS\n"
	.string "even though you hate them, huh?$"

PokemonLaboratory_B3_Text_RaynerDidntHaveChoice:
	.string "RAYNER: It's not like I wanted to.\n"
	.string "They have a certain leverage over me.$"

PokemonLaboratory_B3_Text_JaceWhatsThat:
	.string "JACE: And what's that?$"

PokemonLaboratory_B3_Text_RaynerRetroviruses:
	@.string "Ever heard of endogenous retroviruses?$"
	.string "RAYNER: Endogenous retroviruses.$"

PokemonLaboratory_B3_Text_JaceWhat:
	.string "JACE: Endogewhat?$"

PokemonLaboratory_B3_Text_RaynerExplainsVirus:
	@.string "Sigh. Think of it like a disease only\n"
	@.string "most people don't get sick from it.\p"
	.string "RAYNER: Sigh. Think of it like a disease\n"
	.string "that doesn't make you sick.\p"
	.string "Except for people like me.\p"
	.string "For us, it's constant and painful.\n"
	.string "And debilitating in the long term.\p"
	.string "There's no cure for it, only treatment.\n"
	.string "And TEAM GENESIS has the only supply.\p"
	.string "Well, they did anyway...$"
	@.string "I need constant medication to suppress it.\n"
	@.string "And TEAM GENESIS has the only supply.\p"
	@.string "Well, they did anyway...$"

PokemonLaboratory_B3_Text_RaynerDoYouRemember:
	@.string "Remember the last time we met, {PLAYER}?\n"
	@.string "At the mansion in MINDARO CITY.\p"
	@.string "It was then that I finally found\n"
	@.string "my own supply.\p"
	.string "Thanks to some other sentimentalists,\n"
	.string "I obtained an alternative supply.\p"
	.string "Now TEAM GENESIS only thinks that\n"
	.string "they control me.\p"
	.string "Now I'm just biding my time.$"

PokemonLaboratory_B3_Text_RaynerIncomplete:
	.string "You see, none of this is a\n"
	.string "permanent solution.\p"
	.string "I'm still fundamentally “incomplete.”\p"
	.string "My body simply isn't designed\n"
	.string "to last on its own...$"

PokemonLaboratory_B3_Text_RaynerIncomplete2:
	.string "What I need is the same thing\n"
	.string "TEAM GENESIS is after.\p"
	.string "And that's why I'm still helping\n"
	.string "them for now.$"

PokemonLaboratory_B3_Text_JaceQuestions:
	.string "JACE: So what is TEAM GENESIS\n"
	.string "after anyway?\p"
	.string "And how does it help with your disease?\p"
	.string "And why do you have to be such a jerk\n"
	.string "to everybody for no reason?$"

PokemonLaboratory_B3_Text_RaynerTooManyQuestions:
	.string "RAYNER: Tch!\n"
	.string "You ask too many questions!\p"
	.string "Bottom line is, I'm taking this thing\n"
	.string "back with me to TEAM GENESIS.\p"
	.string "It's not like I care what\n"
	.string "happens to XANTHOS CITY...$"

PokemonLaboratory_B3_Text_JaceXanthosCity:
	.string "JACE: XANTHOS CITY? What do you mean?\n"
	.string "What's gonna happen there?$"

PokemonLaboratory_B3_Text_RaynerOops:
	.string "RAYNER: Oops, didn't mean to say\n"
	.string "that part out loud{EMOJI_TILDE}\p"
	.string "Since you know now, I might as\n"
	.string "well tell you the rest.\p"
	.string "TEAM GENESIS is hiding beneath\n"
	.string "XANTHOS CITY.\p"
	.string "They've created another facility\n"
	.string "just like this one.\p"
	.string "And they're planning to make another\n"
	.string "bridge to Ultra Space.\p"
	.string "If it's anything like what happened\n"
	.string "last time...\p"
	.string "Hehehehehehehe.\n"
	.string "Well, you saw this place.$"

PokemonLaboratory_B3_Text_JaceWhatHappensToPeople:
	.string "JACE: But there are tons of innocent\n"
	.string "people in XANTHOS CITY!\p"
	.string "What's gonna happen to them?$"

PokemonLaboratory_B3_Text_RaynerWhoCares:
	.string "RAYNER: Who cares.\n"
	.string "There are no “innocent” people, anyway.$"

PokemonLaboratory_B3_Text_JaceSoHeartless:
	.string "JACE: How can you be so heartless?!\n"
	.string "What did they ever do to you?!$"

PokemonLaboratory_B3_Text_RaynerPhilosophy:
	.string "RAYNER: What do you mean? I'm just doing\n"
	.string "what everyone has always done to me.\p"
	.string "The only way to get what you want\n"
	.string "in this world is to take it.\p"
	.string "If some people get hurt that just means\n"
	.string "they didn't want it hard enough.\p"
	.string "And no matter how virtuous you think\n"
	.string "you are, you'll end up hurting people\l"
	.string "whether you want to or not.\p"
	.string "So why pretend like you won't?\p"
	.string "Embrace your want. Make your\n"
	.string "anger become your strength.\p"
	.string "Let go of your weaknesses.\n"
	.string "And then nothing can stop you!$"

PokemonLaboratory_B3_Text_JacePhilosophy:
	.string "JACE: Dude, you keep saying people\n"
	.string "and POKéMON are weaknesses, but\l"
	.string "that's just not true.\p"
	.string "We help and support each other.\n"
	.string "No one has to suffer all by themselves.$"

PokemonLaboratory_B3_Text_RaynerPhilosophy2:
	.string "RAYNER: Tch! What would you\n"
	.string "know about that anyway?\p"
	.string "You RANGERS and your lovey-dovey\n"
	.string "help groups.\p"
	.string "You're just setting yourselves up\n"
	.string "for even more pain.\p"
	.string "Aren't you afraid of losing\n"
	.string "them all someday?$"

PokemonLaboratory_B3_Text_JacePhilosophy2:
	.string "JACE: Well, I guess so.\n"
	.string "But that's why I want to help them.\p"
	.string "That's why I want to fight guys like\n"
	.string "TEAM GENESIS who try to hurt them.\p"
	.string "Because a true champion protects people\n"
	.string "who can't protect themselves.$"

PokemonLaboratory_B3_Text_RaynerWhatever:
	.string "RAYNER: Whatever.\n"
	.string "I'm not interested in empty titles.\p"
	.string "There's only one thing I want.\n"
	.string "And now I'm finally about to get it.\p"
	.string "I've waited so long for this...$"

PokemonLaboratory_B3_Text_JaceReally:
	.string "JACE: You're really gonna help them after\n"
	.string "everything you said about them, huh?\p"
	.string "For a guy who claims to hate TEAM GENESIS,\n"
	.string "you sound an awful lot like them.$"

PokemonLaboratory_B3_Text_RaynerDoSomething:
	.string "RAYNER: Why don't you do something\n"
	.string "about it, then?!\p"
	.string "Show me how much you want it.\n"
	.string "Just try and stop me!$"
	@.string "You know I'm still not satisfied\n"
	@.string "from that first battle.\p"
	@.string "Why don't you try and stop me?$"

PokemonLaboratory_B3_Text_JaceWontFight:
	.string "JACE: ...\p"
	.string "No, I'm not gonna fight you.$"

PokemonLaboratory_B3_Text_RaynerChickenOut:
	.string "RAYNER: Chickening out, huh?\n"
	.string "Come on, be a man.\p"
	.string "I thought you wanted to save those\n"
	.string "people in XANTHOS CITY.\p"
	.string "But I guess you don't really care\n"
	.string "about them, do you?$"

PokemonLaboratory_B3_Text_JaceComeWithUs:
	.string "JACE: No, actually I want to ask you\n"
	.string "if you want to come with us instead.$"

PokemonLaboratory_B3_Text_RaynerWhat:
	.string "RAYNER: Huh?\p"
	.string "What are you talking about?$"

PokemonLaboratory_B3_Text_JaceWayISeeIt:
	.string "JACE: Look the way I see it, you\n"
	.string "just need a good doctor, right?\p"
	.string "The POKéMON RANGERS can help.\n"
	.string "They know plenty of doctors.\p"
	.string "Well, POKéMON doctors mostly...\p"
	.string "But they have doctors for people too.\n"
	.string "I'm sure one of them could help you out.$"

PokemonLaboratory_B3_Text_RaynerNotNaive:
	.string "RAYNER: ...\p"
	.string "You seriously think I'm naive enough\n"
	.string "to trust a bunch of doctors?$"

PokemonLaboratory_B3_Text_JaceGoodPeople:
	.string "JACE: Hey, they're good people!\n"
	.string "I promise!\p"
	.string "They've helped TEAM GENESIS POKéMON\n"
	.string "before. I'll bet they can help you too.$"

PokemonLaboratory_B3_Text_RaynerDeclines:
	.string "RAYNER: I highly doubt it.\p"
	.string "And I'm not about to risk my one\n"
	.string "chance at a real solution.$"

PokemonLaboratory_B3_Text_JaceRiskPeople:
	.string "JACE: You'd rather risk everyone\n"
	.string "in XANTHOS CITY, is that it?$"

PokemonLaboratory_B3_Text_RaynerThatsHowItWorks:
	.string "RAYNER: Yup.\n"
	.string "That's just how the world works.\p"
	.string "The weak don't get to decide\n"
	.string "what happens to them.\p"
	.string "They'll adapt or perish.\n"
	.string "It's as simple as that.\p"
	.string "And if you care so much,\n"
	.string "then just try to stop us.\p"
	.string "We'll be waiting beneath XANTHOS CITY.\n"
	.string "Bring the whole RANGER crew\n"
	.string "with you too.\p"
	.string "Let's have a party for the\n"
	.string "end of the world!$"

PokemonLaboratory_B3_Text_JaceToPlayer:
	.string "JACE: That guy was really messed up.\p"
	.string "I can't believe he wants to help\n"
	.string "TEAM GENESIS hurt more people.$"
	.string "I don't know what kind of disease he has\n"
	.string "or what TEAM GENESIS put him through,\p"
	.string "That's no excuse to endanger the lives\n"
	.string "of innocent people!$"

PokemonLaboratory_B3_Text_JaceToPlayer2:
	.string "JACE: Well if what he said is true, then\n"
	.string "XANTHOS CITY could be in big danger.\p"
	.string "Let's take this back to RANGER HQ and\n"
	.string "explain everything to JUSTIN.$"





