.set LOCALID_AZAMI, 1
.set LOCALID_RAYNER, 2
.set LOCALID_BRENDAN, 3
.set LOCALID_MAY, 4

UndergroundCity_FinalRoom_MapScripts::
	@map_script MAP_SCRIPT_ON_TRANSITION, UndergroundCity_FinalRoom_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, UndergroundCity_FinalRoom_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, UndergroundCity_FinalRoom_OnFrame
	.byte 0

UndergroundCity_FinalRoom_OnFrame:
	map_script_2 VAR_RANGER_HQ_STATE, 7, UndergroundCity_FinalRoom_EventScript_AzamiEncounter
	.2byte 0

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

@UndergroundCity_FinalRoom_OnTransition:
@	@call_if_ge VAR_RANGER_HQ_STATE, 8, UndergroundCity_FinalRoom_EventScript_RemoveAzamiRayner
@	end

UndergroundCity_FinalRoom_OnLoad:
	call_if_ge VAR_RANGER_HQ_STATE, 8, UndergroundCity_FinalRoom_EventScript_SetWaterTiles
	end

UndergroundCity_FinalRoom_EventScript_SetWaterTiles::
	setmetatile 7, 5, METATILE_Facility2_SewerWater_Wall_Shadow, TRUE
	setmetatile 8, 5, METATILE_Facility2_SewerWater_Wall, TRUE
	setmetatile 9, 5, METATILE_Facility2_SewerWater_Wall, TRUE
	setmetatile 10, 5, METATILE_Facility2_SewerWater_Wall, TRUE
	setmetatile 11, 5, METATILE_Facility2_SewerWater_Wall, TRUE
	setmetatile 12, 5, METATILE_Facility2_SewerWater_Wall, TRUE
	setmetatile 6, 6, METATILE_Facility2_SewerWater_Wall_Shadow, TRUE
	setmetatile 7, 6, METATILE_Facility2_SewerWater, TRUE
	setmetatile 8, 6, METATILE_Facility2_SewerWater, TRUE
	setmetatile 9, 6, METATILE_Facility2_SewerWater, TRUE
	setmetatile 10, 6, METATILE_Facility2_SewerWater, TRUE
	setmetatile 11, 6, METATILE_Facility2_SewerWater, TRUE
	setmetatile 12, 6, METATILE_Facility2_SewerWater, TRUE
	setmetatile 13, 6, METATILE_Facility2_SewerWater_Wall, TRUE
	setmetatile 6, 7, METATILE_Facility2_SewerWater_Shadow, TRUE
	setmetatile 7, 7, METATILE_Facility2_SewerWater, TRUE
	setmetatile 8, 7, METATILE_Facility2_SewerWater, TRUE
	setmetatile 9, 7, METATILE_Facility2_SewerWater, TRUE
	setmetatile 10, 7, METATILE_Facility2_SewerWater, TRUE
	setmetatile 11, 7, METATILE_Facility2_SewerWater, TRUE
	setmetatile 12, 7, METATILE_Facility2_SewerWater, TRUE
	setmetatile 13, 7, METATILE_Facility2_SewerWater, TRUE
	setmetatile 6, 8, METATILE_Facility2_SewerWater_Shadow, TRUE
	setmetatile 7, 8, METATILE_Facility2_SewerWater, TRUE
	setmetatile 8, 8, METATILE_Facility2_SewerWater, TRUE
	setmetatile 9, 8, METATILE_Facility2_SewerWater, TRUE
	setmetatile 10, 8, METATILE_Facility2_SewerWater, TRUE
	setmetatile 11, 8, METATILE_Facility2_SewerWater, TRUE
	setmetatile 12, 8, METATILE_Facility2_SewerWater, TRUE
	setmetatile 13, 8, METATILE_Facility2_SewerWater, TRUE
	setmetatile 6, 9, METATILE_Facility2_SewerWater_Shadow, TRUE
	setmetatile 7, 9, METATILE_Facility2_SewerWater, TRUE
	setmetatile 8, 9, METATILE_Facility2_SewerWater, TRUE
	setmetatile 9, 9, METATILE_Facility2_SewerWater, TRUE
	setmetatile 10, 9, METATILE_Facility2_SewerWater, TRUE
	setmetatile 11, 9, METATILE_Facility2_SewerWater, TRUE
	setmetatile 12, 9, METATILE_Facility2_SewerWater, TRUE
	setmetatile 13, 9, METATILE_Facility2_SewerWater, TRUE
	setmetatile 6, 10, METATILE_Facility2_SewerWater_Shadow, TRUE
	setmetatile 7, 10, METATILE_Facility2_SewerWater, TRUE
	setmetatile 8, 10, METATILE_Facility2_SewerWater, TRUE
	setmetatile 9, 10, METATILE_Facility2_SewerWater, TRUE
	setmetatile 10, 10, METATILE_Facility2_SewerWater, TRUE
	setmetatile 11, 10, METATILE_Facility2_SewerWater, TRUE
	setmetatile 12, 10, METATILE_Facility2_SewerWater, TRUE
	setmetatile 13, 10, METATILE_Facility2_SewerWater, TRUE
	setmetatile 6, 11, METATILE_Facility2_SewerWater_Shadow, TRUE
	setmetatile 7, 11, METATILE_Facility2_SewerWater, TRUE
	setmetatile 8, 11, METATILE_Facility2_SewerWater, TRUE
	setmetatile 9, 11, METATILE_Facility2_SewerWater, TRUE
	setmetatile 10, 11, METATILE_Facility2_SewerWater, TRUE
	setmetatile 11, 11, METATILE_Facility2_SewerWater, TRUE
	setmetatile 12, 11, METATILE_Facility2_SewerWater, TRUE
	setmetatile 13, 11, METATILE_Facility2_SewerWater, TRUE
	setmetatile 6, 12, METATILE_Facility2_SewerWater_Shadow, TRUE
	setmetatile 7, 12, METATILE_Facility2_SewerWater, TRUE
	setmetatile 8, 12, METATILE_Facility2_SewerWater, TRUE
	setmetatile 11, 12, METATILE_Facility2_SewerWater, TRUE
	setmetatile 12, 12, METATILE_Facility2_SewerWater, TRUE
	setmetatile 13, 12, METATILE_Facility2_SewerWater, TRUE
	setmetatile 6, 13, METATILE_Facility2_SewerWater_Shadow, TRUE
	setmetatile 7, 13, METATILE_Facility2_SewerWater, TRUE
	setmetatile 8, 13, METATILE_Facility2_SewerWater, TRUE
	setmetatile 11, 13, METATILE_Facility2_SewerWater, TRUE
	setmetatile 12, 13, METATILE_Facility2_SewerWater, TRUE
	setmetatile 13, 13, METATILE_Facility2_SewerWater, TRUE
	setmetatile 7, 14, METATILE_Facility2_SewerWater_Shadow, TRUE
	setmetatile 8, 14, METATILE_Facility2_SewerWater, TRUE
	setmetatile 11, 14, METATILE_Facility2_SewerWater, TRUE
	setmetatile 12, 14, METATILE_Facility2_SewerWater, TRUE
	setmetatile 9, 12, METATILE_Facility2_Bridge_NW, FALSE
	setmetatile 10, 12, METATILE_Facility2_Bridge_NE, FALSE
	setmetatile 9, 13, METATILE_Facility2_Bridge_W, FALSE
	setmetatile 10, 13, METATILE_Facility2_Bridge_E, FALSE
	setmetatile 9, 14, METATILE_Facility2_Bridge_SW, FALSE
	setmetatile 10, 14, METATILE_Facility2_Bridge_SE, FALSE
	return








UndergroundCity_FinalRoom_EventScript_AzamiEncounter::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, UndergroundCity_FinalRoom_Movement_PlayerEnters
	waitmovement 0
	delay 48
	applymovement LOCALID_AZAMI, Common_Movement_FaceDown
	waitmovement 0
	applymovement LOCALID_AZAMI, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	delay 60
	msgbox UndergroundCity_FinalRoom_Text_AzamiIntro, MSGBOX_DEFAULT
	closemessage
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, UndergroundCity_FinalRoom_EventScript_YoungMan
	goto_if_eq VAR_RESULT, FEMALE, UndergroundCity_FinalRoom_EventScript_YoungWoman
	end

UndergroundCity_FinalRoom_EventScript_YoungMan::
	msgbox UndergroundCity_FinalRoom_Text_AzamiYoungMan, MSGBOX_DEFAULT
	closemessage
	goto UndergroundCity_FinalRoom_EventScript_RaynerEncounter
	end

UndergroundCity_FinalRoom_EventScript_YoungWoman::
	msgbox UndergroundCity_FinalRoom_Text_AzamiYoungWoman, MSGBOX_DEFAULT
	closemessage
	goto UndergroundCity_FinalRoom_EventScript_RaynerEncounter
	end

UndergroundCity_FinalRoom_EventScript_RaynerEncounter::
	delay 60
	removeobject LOCALID_RAYNER
	clearflag FLAG_HIDE_RAYNER
	setobjectxyperm LOCALID_RAYNER, 9, 19
	setobjectmovementtype LOCALID_RAYNER, MOVEMENT_TYPE_FACE_UP
	addobject LOCALID_RAYNER
	applymovement LOCALID_RAYNER, Common_Movement_WalkUp
	waitmovement 0
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	waitse
	msgbox UndergroundCity_FinalRoom_Text_RaynerIntro, MSGBOX_DEFAULT
	closemessage
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, UndergroundCity_FinalRoom_EventScript_RaynerPushHim
	goto_if_eq VAR_RESULT, FEMALE, UndergroundCity_FinalRoom_EventScript_RaynerPushHer
	end

UndergroundCity_FinalRoom_EventScript_RaynerPushHim::
	msgbox UndergroundCity_FinalRoom_Text_RaynerPushHim, MSGBOX_DEFAULT
	closemessage
	goto UndergroundCity_FinalRoom_EventScript_PlayerPushed
	end

UndergroundCity_FinalRoom_EventScript_RaynerPushHer::
	msgbox UndergroundCity_FinalRoom_Text_RaynerPushHer, MSGBOX_DEFAULT
	closemessage
	goto UndergroundCity_FinalRoom_EventScript_PlayerPushed
	end

UndergroundCity_FinalRoom_EventScript_PlayerPushed::
	playse SE_WALL_HIT
	applymovement OBJ_EVENT_ID_PLAYER, UndergroundCity_FinalRoom_Movement_PlayerPushed
	waitmovement 0
	delay 10
	applymovement LOCALID_AZAMI, Common_Movement_FaceLeft
	waitmovement 0
	delay 60
	msgbox UndergroundCity_FinalRoom_Text_AzamiAhYes, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_AZAMI, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	msgbox UndergroundCity_FinalRoom_Text_AzamiPerfectSoldier, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_RAYNER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox UndergroundCity_FinalRoom_Text_RaynerDontThankMe, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_AZAMI, Common_Movement_FaceLeft
	waitmovement 0
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	delay 60
	msgbox UndergroundCity_FinalRoom_Text_AzamiTooLate, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_AZAMI, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox UndergroundCity_FinalRoom_Text_AzamiPerhapsYoullUnderstand, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_AZAMI, Common_Movement_FaceUp
	waitmovement 0
	delay 30
	applymovement LOCALID_AZAMI, Common_Movement_FaceLeft
	waitmovement 0
	delay 10
	msgbox UndergroundCity_FinalRoom_Text_AzamiUltraSpace, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_AZAMI, Common_Movement_FaceUp
	waitmovement 0
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	delay 60
	msgbox UndergroundCity_FinalRoom_Text_AzamiOvermind, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_AZAMI, Common_Movement_FaceLeft
	waitmovement 0
	delay 10
	msgbox UndergroundCity_FinalRoom_Text_AzamiCulmination, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	applymovement LOCALID_AZAMI, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_AZAMI, Common_Movement_FaceUp
	waitmovement 0
	delay 30
	applymovement LOCALID_AZAMI, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox UndergroundCity_FinalRoom_Text_AzamiUseless, MSGBOX_DEFAULT
	closemessage
	delay 30
	@applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUpSlow
	@waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUpSlow
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUpSlow
	waitmovement 0
	delay 60
	msgbox UndergroundCity_FinalRoom_Text_CrossOver, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, YES, UndergroundCity_FinalRoom_EventScript_GameOver
	goto_if_eq VAR_RESULT, NO, UndergroundCity_FinalRoom_EventScript_AzamiBattle
	end

UndergroundCity_FinalRoom_EventScript_GameOver::
	delay 60
	playse SE_M_WATERFALL
	fadescreen FADE_TO_WHITE
	fadeoutbgm 0
	waitstate
	releaseall
	end

UndergroundCity_FinalRoom_EventScript_AzamiBattle::
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 60
	applymovement LOCALID_AZAMI, Common_Movement_WalkUpSlow
	waitmovement 0
	@applymovement LOCALID_AZAMI, Common_Movement_WalkLeftSlow
	@waitmovement 0
	applymovement LOCALID_AZAMI, Common_Movement_WalkUpSlow
	waitmovement 0
	delay 60
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox UndergroundCity_FinalRoom_Text_AzamiPreBattle, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TERRAIN, 512
	trainerbattle_no_intro TRAINER_AZAMI_1, UndergroundCity_FinalRoom_Text_AzamiDefeated
	delay 10
	playbgm MUS_DUMMY, FALSE
	setvar VAR_TERRAIN, 0

	playse SE_M_EARTHQUAKE
	special DoSealedChamberShakingEffect_Long
	waitstate

	@delay 50
	applymovement LOCALID_AZAMI, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	waitse
	msgbox UndergroundCity_FinalRoom_Text_AzamiBridgeClosing, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_AZAMI, Common_Movement_WalkFastRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_AZAMI, Common_Movement_WalkFastUp
	waitmovement 0
	delay 30
	msgbox UndergroundCity_FinalRoom_Text_AzamiBridgeClosing2, MSGBOX_DEFAULT
	closemessage
	delay 30
	removeobject LOCALID_AZAMI
	setflag FLAG_DEFEATED_AZAMI
	playse SE_M_WATERFALL
	waitse
	delay 60
	applymovement LOCALID_RAYNER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_WalkUp
	waitmovement 0
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 60
	applymovement LOCALID_RAYNER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox UndergroundCity_FinalRoom_Text_RaynerJobWellDone, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_RAYNER, Common_Movement_WalkRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_RAYNER, Common_Movement_WalkUp
	waitmovement 0
	delay 60
	applymovement LOCALID_RAYNER, Common_Movement_FaceLeft
	waitmovement 0
	delay 30
	msgbox UndergroundCity_FinalRoom_Text_RaynerFarewell, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_RAYNER, Common_Movement_FaceUp
	waitmovement 0
	delay 60
	removeobject LOCALID_RAYNER
	setflag FLAG_HIDE_RAYNER
	playse SE_M_WATERFALL
	waitse

	delay 60
	special DoSealedChamberShakingEffect_Long
	waitstate


	playse SE_M_DETECT
	dofieldeffectsparkle 10, 11, 0
	@dofieldeffectsparkle 8, 12, 0
	waitfieldeffect FLDEFF_SPARKLE
	closemessage
	setvar VAR_RESULT, 1
	@playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	waitstate
	delay 60

	call UndergroundCity_FinalRoom_EventScript_SetWaterTiles
	special DrawWholeMapView
	setvar VAR_RANGER_HQ_STATE, 8
	special FadeOutOrbEffect
	waitstate

	delay 240
	goto UndergroundCity_FinalRoom_EventScript_BrendanMayEncounter
	end

UndergroundCity_FinalRoom_Movement_PlayerEnters:
	delay_16
	delay_16
	walk_slow_up
	walk_slow_up
	delay_16
	step_end

UndergroundCity_FinalRoom_Movement_PlayerPushed:
	lock_facing_direction
	walk_fast_up
	walk_fast_up
	unlock_facing_direction
	step_end

UndergroundCity_FinalRoom_Text_AzamiIntro:
	.string "AZAMI: Ufufufufufufufu.\n"
	.string "So one of you finally made it.$"

UndergroundCity_FinalRoom_Text_AzamiYoungMan:
	.string "Young man, what is your name?$"

UndergroundCity_FinalRoom_Text_AzamiYoungWoman:
	.string "Young woman, what is your name?$"

UndergroundCity_FinalRoom_Text_RaynerIntro:
	.string "RAYNER: This one's {PLAYER}.$"

UndergroundCity_FinalRoom_Text_RaynerPushHim:
	.string "You can push him around and he\n"
	.string "doesn't push back.\p"
	.string "See.$"

UndergroundCity_FinalRoom_Text_RaynerPushHer:
	.string "You can push her around and she\n"
	.string "doesn't push back.\p"
	.string "See.$"

UndergroundCity_FinalRoom_Text_AzamiAhYes:
	.string "AZAMI: Ufufufufu.\n"
	@.string "A pacifist, are you?\p"
	@.string "Is that why you came here, {PLAYER}?\n"
	@.string "To fight for peace?\p"
	@.string "How pathetically ironic.\p"
	@.string "\p"
	@.string "Do you realize what you've\n"
	@.string "helped Us achieve?\p"
	.string "Yes, I remember now.\p"
	.string "You assisted 006 in retrieving the\n"
	.string "LOST TECH from AB LABS.\p"
	.string "Apparently you've known each other\n"
	.string "for some time now.$"

UndergroundCity_FinalRoom_Text_AzamiPerfectSoldier:
	.string "He's Our perfect soldier, you know.\p"
	.string "His mission was the most critical\n"
	.string "to Our plan's success.\p"
	@.string "Our mission to return to the Other World!\n"
	@.string "And master all its secrets!\p"
	.string "Thanks to his work, We've finally managed\n"
	.string "to open another bridge to Ultra Space!$"

UndergroundCity_FinalRoom_Text_RaynerDontThankMe:
	.string "RAYNER: Don't thank me.\n"
	.string "It was all thanks to {PLAYER}.\p"
	.string "I couldn't have done it without you.$"

UndergroundCity_FinalRoom_Text_AzamiTooLate:
	.string "AZAMI: I'm afraid if you intend to\n"
	.string "stop Us, you're already too late.\p"
	.string "The bridge has been opened.\n"
	.string "Our footsoldiers are on the other side.\p"
	.string "And they've already confirmed Our target.$"
	@.string "And soon they will make contact\n"
	@.string "with Our target.$"

UndergroundCity_FinalRoom_Text_AzamiPerhapsYoullUnderstand:
	.string "As you can see, your leader greatly\n"
	.string "overstated the dangers involved.\p"
	.string "Perhaps you have a more open mind.\p"
	.string "Do you even know what it is We're\n"
	.string "searching for?$"

UndergroundCity_FinalRoom_Text_AzamiUltraSpace:
	.string "Some believe Ultra Space to be devoid\n"
	.string "of any and all life.\p"
	.string "But they are absolutely wrong!\p"
	.string "We weren't convinced Ourselves when We\n"
	.string "first tried all those years ago.\p"
	.string "But now We have undeniable proof!\p"
	.string "There are whole worlds out there with\n"
	.string "life unlike any We've ever seen!\p"
	.string "Even without the bridge, We've been able\n"
	.string "to learn so much about them.\p"
	.string "An infinite expanse of worlds, each one\n"
	.string "more exotic than the last!\p"
	.string "But Our target now is even\n"
	.string "more fascinating...$"

UndergroundCity_FinalRoom_Text_AzamiOvermind:
	.string "Our scientists have taken to calling\n"
	.string "it UB OVERMIND.\p"
	.string "To call it a lifeform is perhaps not\n"
	.string "strictly correct.\p"
	.string "Its awareness, if it ever had any,\n"
	.string "collapsed a long time ago.\p"
	.string "It is a vast amalgamation of data.\n"
	.string "A record of many unknown worlds.\p"
	@.string "We're not even sure how to\n"
	@.string "properly quantify it!\p"
	@.string "From studying it, We can learn so much\n"
	@.string "about Our beginnings.\p"
	@.string "And Our final destiny.$"
	.string "Think of all that we can learn from it!\n"
	.string "All the applications it will have!\p"
	.string "Disease, old age, infirmity.\n"
	.string "Pain and weakness of all kinds.\l"
	.string "All things of the past!\p"
	.string "You see, humanity is something\n"
	.string "that must be overcome.\p"
	.string "We must become more than what We are.\p"
	.string "And leave this world to live\n"
	.string "among the stars.\p"
	.string "That is Our destiny.$"

UndergroundCity_FinalRoom_Text_AzamiCulmination:
	.string "This is the culmination of Our work.\n"
	.string "The transcendence of Our species!\p"
	.string "WEAPON S, WEAPON D, and WEAPON A.\n"
	.string "They were the first step.\p"
	.string "And OVERMIND is the last.\p"
	.string "Perhaps you'd like to see for yourself\n"
	.string "what the future has in store.\p"
	.string "You've known pain.\n"
	.string "You've known weakness.\p"
	.string "Perhaps you'd like to transcend\n"
	.string "those things too.$"
	@.string "Imagine if you never had to\n"
	@.string "experience that ever again.$"
	@.string "Perhaps you'd like to see for yourself\n"
	@.string "what OVERMIND is capable of.\p"
	@.string "You must be tired, {PLAYER},\n"
	@.string "from all the fighting you did to get here.\p"
	@.string "Why continue struggling in vain?\p"
	@.string "OVERMIND can ease your suffering.\n"
	@.string "And give you a new body.\p"
	@.string "Surrender yourself to it, and you\n"
	@.string "will never know suffering again.\p"
	@.string "The ultimate release.\n"
	@.string "Cross over and be at peace.$"

UndergroundCity_FinalRoom_Text_AzamiUseless:
	.string "Fufufufu. {PLAYER}, I promise you'll\n"
	.string "find two things on the other side.\p"
	.string "Your body will know one short moment\n"
	.string "of agony before perishing.\p"
	.string "But your mind will know an eternity\n"
	.string "of the perfect world We desire.\p"
	.string "Fufufufufufu.\n"
	.string "Take your time and think it over.$"

	@.string "There is no use in holding on to an\n"
	@.string "ugly, primitive world like this one.\p"
	@.string "Not when We could have so much more.\n"
	@.string "Fufufu, you'll see what I mean.\p"
	@.string "The world-to-come is\n"
	@.string "perfect and eternal.\p"
	@.string "Fufufu, you'll see what I mean soon.\p"
	@.string "Go, cross over, and leave\n"
	@.string "this world behind.$"
	@.string "It is useless to fight for an ugly,\n"
	@.string "primitive world such as this.\p"
	@.string "Go and witness the world to come.$"
	@.string "And leave this world behind.$"
	@.string "Go now, cross into Ultra Space.\n"
	@.string "And witness perfection.$"

UndergroundCity_FinalRoom_Text_CrossOver:
	.string "Will you go to the other world?$"
	@.string "Will you cross over into the other world?$"
	@.string "Will you cross over into Ultra Space?$"

UndergroundCity_FinalRoom_Text_AzamiPreBattle:
	.string "AZAMI: Ufufufufu. So you stubbornly\n"
	.string "refuse to capitulate as well?\p"
	.string "In that case, I shall have to break\n"
	.string "your spirit myself.\p"
	.string "Such a shame. You could have\n"
	.string "aided Our cause willingly.\p"
	.string "But you have elected the way of pain!$"

UndergroundCity_FinalRoom_Text_AzamiDefeated:
	.string "AZAMI: Inconceivable!$"

UndergroundCity_FinalRoom_Text_AzamiBridgeClosing:
	.string "AZAMI: No!\n"
	.string "The bridge is unstable!$"

UndergroundCity_FinalRoom_Text_AzamiBridgeClosing2:
	.string "We can't lose contact with OVERMIND!\n"
	.string "I've waited too long for this moment!$"
	@.string " end this way!\n"
	@.string "Not again! Not now!$"

UndergroundCity_FinalRoom_Text_RaynerJobWellDone:
	.string "RAYNER: Hehehe.\n"
	.string "Well done, {PLAYER}.\p"
	.string "You saved me the trouble of dealing\n"
	.string "with her myself.\p"
	.string "You may not believe in the power of\n"
	.string "OVERMIND, but I certainly do.\p"
	.string "I'll use it to make a new body for myself.\n"
	.string "One without weaknesses.$"
	@.string "I'll finally be rid of this\n"
	@.string "contemptable weakness.\p"
	@.string "And then nothing will hold me\n"
	@.string "back anymore.$"

UndergroundCity_FinalRoom_Text_RaynerFarewell:
	.string "To be honest, I thought you were\n"
	.string "really going to jump earlier.\p"
	.string "I was hoping that you might come to\n"
	.string "Ultra Space with me.\p"
	@.string "It could get awfully lonely out there.\p"
	.string "But don't worry, I'll come back to\n"
	.string "play with you again someday.\p"
	.string "Who knows, maybe you'll learn a\n"
	.string "thing or two by then.\p"
	.string "Later, loser.$"








UndergroundCity_FinalRoom_EventScript_BrendanMayEncounter::
	clearflag FLAG_HIDE_BRENDAN
	removeobject LOCALID_BRENDAN
	setobjectxyperm LOCALID_BRENDAN, 9, 19
	setobjectmovementtype LOCALID_BRENDAN, MOVEMENT_TYPE_FACE_UP
	addobject LOCALID_BRENDAN
	playse SE_EXIT
	waitse
	removeobject LOCALID_MAY
	setobjectxyperm LOCALID_MAY, 10, 19
	setobjectmovementtype LOCALID_MAY, MOVEMENT_TYPE_FACE_UP
	addobject LOCALID_MAY
	playse SE_EXIT
	waitse
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	waitse
	delay 30
	applymovement LOCALID_BRENDAN, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox UndergroundCity_FinalRoom_Text_BrendanIntro, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_MAY, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox UndergroundCity_FinalRoom_Text_MayIntro, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_MAY, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_MAY, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_MAY, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_MAY, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_MAY, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_MAY, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_MAY, Common_Movement_WalkUp
	waitmovement 0
	delay 30
	msgbox UndergroundCity_FinalRoom_Text_MayIntro2, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_BRENDAN, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_BRENDAN, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_BRENDAN, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_BRENDAN, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_BRENDAN, Common_Movement_WalkUp
	waitmovement 0
	delay 30
	msgbox UndergroundCity_FinalRoom_Text_BrendanWhatBecameOf, MSGBOX_DEFAULT
	closemessage
	delay 90
	applymovement LOCALID_MAY, Common_Movement_FaceLeft
	waitmovement 0
	delay 30
	msgbox UndergroundCity_FinalRoom_Text_MayWhatDoYouThink, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_BRENDAN, Common_Movement_FaceLeft
	waitmovement 0
	delay 90
	msgbox UndergroundCity_FinalRoom_Text_BrendanWhoKnows, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_MAY, Common_Movement_WalkRight
	waitmovement 0
	delay 60
	msgbox UndergroundCity_FinalRoom_Text_MayLastOfTeamGenesis, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAY, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_MAY, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_MAY, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_MAY, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_MAY, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_MAY, Common_Movement_WalkDown
	waitmovement 0
	delay 30
	@removeobject LOCALID_MAY
	playse SE_EXIT
	waitse
	delay 60
	applymovement LOCALID_BRENDAN, Common_Movement_FaceUp
	waitmovement 0
	delay 60
	applymovement LOCALID_BRENDAN, Common_Movement_WalkUp
	waitmovement 0
	delay 30
	msgbox UndergroundCity_FinalRoom_Text_BrendanOneLastThing, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, UndergroundCity_FinalRoom_EventScript_DoIntend
	goto_if_eq VAR_RESULT, NO, UndergroundCity_FinalRoom_EventScript_DontIntend
	end

UndergroundCity_FinalRoom_EventScript_DoIntend::
	msgbox UndergroundCity_FinalRoom_Text_DoIntend, MSGBOX_DEFAULT
	closemessage
	goto UndergroundCity_FinalRoom_EventScript_BrendanFarewell
	end

UndergroundCity_FinalRoom_EventScript_DontIntend::
	msgbox UndergroundCity_FinalRoom_Text_DontIntend, MSGBOX_DEFAULT
	closemessage
	goto UndergroundCity_FinalRoom_EventScript_BrendanFarewell
	end

UndergroundCity_FinalRoom_EventScript_BrendanFarewell::
	delay 60
	applymovement LOCALID_BRENDAN, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_BRENDAN, Common_Movement_WalkDown
	waitmovement 0
	delay 30
	applymovement LOCALID_BRENDAN, Common_Movement_FaceUp
	waitmovement 0
	delay 30
	msgbox UndergroundCity_FinalRoom_Text_BrendanBestOfLuck, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BRENDAN, Common_Movement_WalkDown
	waitmovement 0	
	applymovement LOCALID_BRENDAN, Common_Movement_WalkDown
	waitmovement 0	
	applymovement LOCALID_BRENDAN, Common_Movement_WalkDown
	waitmovement 0	
	applymovement LOCALID_BRENDAN, Common_Movement_WalkDown
	waitmovement 0	
	removeobject LOCALID_MAY
	removeobject LOCALID_BRENDAN
	setflag FLAG_HIDE_BRENDAN
	setvar VAR_RANGER_HQ_STATE, 9
	playse SE_EXIT
	waitse
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	delay 240
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	delay 60
	warp MAP_XANTHOS_CITY, 42, 22 
	waitstate
	releaseall
	end

UndergroundCity_FinalRoom_Text_BrendanIntro:
	@.string "???????: Looks likes we made it\n"
	@.string "just in the nick of time.\p"
	@.string "But I could have gotten here faster\n"
	@.string "if I didn't have to wait on you.$"
	.string "???????: Looks like that did the trick.\p"
	.string "“Unplug all the machines”, huh?\p"
	.string "You know, you really didn't need to tag\n"
	.string "along if it was gonna be that simple...$"

UndergroundCity_FinalRoom_Text_MayIntro:
	.string "???: As if I'd sit back while they're\n"
	.string "wreaking havoc in my own city!$"


UndergroundCity_FinalRoom_Text_MayIntro2:
	.string "MAY: Hey there, {PLAYER}.\n"
	.string "It's been a while, hasn't it?\p"
	.string "You and your POKéMON look\n"
	.string "all grown up now.\p"
	.string "It feels like only yesterday when I first\n"
	.string "met you and JACE in UMBER TOWN.$"

UndergroundCity_FinalRoom_Text_BrendanWhatBecameOf:
	.string "BRENDAN: More importantly, {PLAYER}. What\n"
	.string "happened to AZAMI and her personnel?\p"
	.string "\p"
	.string "\p"
	.string "\p"
	@.string "I see. Trapped on the other\n"
	@.string "side of their own bridge.$"
	.string "I see. Trapped somewhere\n"
	.string "deep in Ultra Space.$"

UndergroundCity_FinalRoom_Text_MayWhatDoYouThink:
	@.string "MAY: What do you think was so important\n"
	@.string "to make them risk all of XANTHOS CITY?$"
	.string "MAY: All those years of planning,\n"
	.string "all those people and POKéMON they hurt.\p"
	.string "Just to end up marooned by their\n"
	.string "own invention...\p"
	.string "What do you think it was they\n"
	.string "were hoping to find out there?$"

UndergroundCity_FinalRoom_Text_BrendanWhoKnows:
	.string "BRENDAN: Who knows.\p"
	.string "Whatever it was, at least none of it\n"
	.string "got through to our side.$"

UndergroundCity_FinalRoom_Text_MayLastOfTeamGenesis:
	.string "MAY: Sigh. Well I guess that's\n"
	.string "the end of TEAM GENESIS.\p"
	.string "I'm going back to help JUSTIN\n"
	.string "and the others.$"

UndergroundCity_FinalRoom_Text_BrendanOneLastThing:
	.string "BRENDAN: This is the second time I'm\n"
	.string "grateful for your help, {PLAYER}.\p"
	.string "You've really matured as a trainer.\p"
	.string "\p"
	.string "By the way, you have 8 GYM BADGES now,\n"
	.string "isn't that right?\p"
	.string "Do you still intend to challenge the\n"
	.string "POKéMON LEAGUE in EVER GRANDE CITY?$"


UndergroundCity_FinalRoom_Text_DoIntend:
	.string "BRENDAN: I thought as much. I hear\n"
	.string "the CHAMPION's dying to meet you.\p"
	.string "In that case, you should visit\n"
	.string "an old friend of mine in DUN TOWN.\p"
	.string "He can take you to EVER GRANDE CITY\n"
	.string "in the HOENN REGION.\p"
	.string "I've already put in a good word\n"
	.string "for you and JACE.$"


UndergroundCity_FinalRoom_Text_DontIntend:
	.string "BRENDAN: Is that right?\p"
	.string "Well if you change your mind, you should\n"
	.string "visit an old friend of mine in DUN TOWN.\p"
	.string "He can take you to EVER GRANDE CITY\n"
	.string "in the HOENN REGION.\p"
	.string "I've already put in a good word\n"
	.string "for you and JACE.$"


UndergroundCity_FinalRoom_Text_BrendanBestOfLuck:
	.string "Well, best of luck {PLAYER}.\p"
	.string "Who knows, maybe we'll meet again\n"
	.string "in HOENN some day.$"





