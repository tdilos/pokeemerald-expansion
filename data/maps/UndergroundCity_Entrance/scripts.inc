.set LOCALID_AZAMI, 1
.set LOCALID_JUSTIN, 2

UndergroundCity_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, UndergroundCity_Entrance_OnFrame
	.byte 0

UndergroundCity_Entrance_OnFrame:
	map_script_2 VAR_RANGER_HQ_STATE, 4, UndergroundCity_Entrance_EventScript_AzamiIntro
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




@ The player steps out of the elevator to see Justin and the Rangers confronted by an old woman dressed in black.
@ The woman reveals herself as the Lady Azami, investor and board member of Kendoma Corporation and current head of a secret society, the Heuretic Society.
@ She speaks to everyone with the tone of someone scolding a child. 













UndergroundCity_Entrance_EventScript_AzamiIntro::
	lockall
	delay 30
	@opendoor 6, 1
	@waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, UndergroundCity_Entrance_Movement_PlayerEnter
	waitmovement 0
	@closedoor 6, 1
	@waitdooranim

	@warpsilent MAP_UNDERGROUND_CITY, 3, 45
	@waitstate

	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, UndergroundCity_Entrance_Movement_CameraPanDown
	waitmovement 0
	delay 50
	msgbox UndergroundCity_Entrance_Text_AzamiIntro, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JUSTIN, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox UndergroundCity_Entrance_Text_JustinLookingForTeamGenesis, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox UndergroundCity_Entrance_Text_AzamiTeamGenesis, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_JUSTIN, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox UndergroundCity_Entrance_Text_JustinYoureTeamGenesis, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox UndergroundCity_Entrance_Text_AzamiHeureticSociety, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JUSTIN, Common_Movement_WalkInPlaceDown
	waitmovement 0
	applymovement LOCALID_JUSTIN, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox UndergroundCity_Entrance_Text_JustinYoureCriminals, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox UndergroundCity_Entrance_Text_AzamiOverzealous, MSGBOX_DEFAULT
	closemessage
	delay 60
	@applymovement LOCALID_AZAMI, Common_Movement_WalkLeft
	@waitmovement 0
	@delay 30
	applymovement LOCALID_AZAMI, Common_Movement_WalkLeftSlow
	waitmovement 0
	delay 60
	applymovement LOCALID_AZAMI, Common_Movement_WalkRightSlow
	waitmovement 0
	delay 60
	msgbox UndergroundCity_Entrance_Text_AzamiPacing, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox UndergroundCity_Entrance_Text_JustinAllIKnow, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_AZAMI, Common_Movement_WalkRightSlow
	waitmovement 0
	delay 60
	applymovement LOCALID_AZAMI, Common_Movement_WalkLeftSlow
	waitmovement 0
	delay 60
	msgbox UndergroundCity_Entrance_Text_AzamiPacing2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JUSTIN, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox UndergroundCity_Entrance_Text_JustinDontPlayDumb, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_AZAMI, Common_Movement_WalkLeftSlow
	waitmovement 0
	delay 60
	applymovement LOCALID_AZAMI, Common_Movement_WalkRightSlow
	waitmovement 0
	delay 60
	msgbox UndergroundCity_Entrance_Text_AzamiPacing3, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox UndergroundCity_Entrance_Text_JustinDoesntMatter, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_AZAMI, Common_Movement_WalkRightSlow
	waitmovement 0
	delay 60
	applymovement LOCALID_AZAMI, Common_Movement_WalkLeftSlow
	waitmovement 0
	delay 60
	msgbox UndergroundCity_Entrance_Text_AzamiPacing4, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_AZAMI, Common_Movement_FaceUp
	waitmovement 0
	delay 60
	msgbox UndergroundCity_Entrance_Text_AzamiPacing5, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JUSTIN, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox UndergroundCity_Entrance_Text_JustinYouHaveNoRight, MSGBOX_DEFAULT
	closemessage
	delay 60
	@applymovement LOCALID_AZAMI, Common_Movement_FaceUp
	@waitmovement 0
	delay 60
	msgbox UndergroundCity_Entrance_Text_AzamiDontKnowYourPlace, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JUSTIN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_JUSTIN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	@applymovement LOCALID_JUSTIN, Common_Movement_WalkInPlaceFasterDown
	@waitmovement 0
	msgbox UndergroundCity_Entrance_Text_JustinYouExpectMe, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_AZAMI, Common_Movement_FaceDown
	waitmovement 0
	msgbox UndergroundCity_Entrance_Text_AzamiFarewell, MSGBOX_DEFAULT
	closemessage
	delay 30
	fadeoutbgm 0
	removeobject LOCALID_AZAMI
	playse SE_M_TELEPORT
	delay 60
	playse SE_PIN
	applymovement LOCALID_JUSTIN, Common_Movement_ExclamationMark
	waitmovement 0
	delay 30
	msgbox UndergroundCity_Entrance_Text_JustinHologram, MSGBOX_DEFAULT
	closemessage

	playse SE_M_EARTHQUAKE
	special DoSealedChamberShakingEffect_Short
	waitstate
	@delay 40

	applymovement OBJ_EVENT_ID_CAMERA, UndergroundCity_Entrance_Movement_CameraPanUp
	waitmovement 0
	special RemoveCameraObject
	applymovement LOCALID_JUSTIN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_JUSTIN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox UndergroundCity_Entrance_Text_JustinOutsideNow, MSGBOX_DEFAULT
	closemessage
	@fadescreen FADE_TO_BLACK
	@setvar VAR_RANGER_HQ_STATE, 5
	@call UndergroundCity_Entrance_EventScript_ExplosionSE
	@fadescreen FADE_FROM_BLACK
	@applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	@waitmovement 0
	fadeinbgm 0
	@warpsilent MAP_UNDERGROUND_CITY, 3, 45
	warpsilent MAP_MT_SHIRO_SUMMIT, 12, 9
	waitstate
	releaseall
	end

UndergroundCity_Entrance_EventScript_ExplosionSE:
	playse SE_M_EXPLOSION
	delay 6
	playse SE_M_EXPLOSION
	delay 6
	playse SE_M_EXPLOSION
	delay 6
	playse SE_M_EXPLOSION
	delay 6
	playse SE_M_EXPLOSION
	delay 6
	playse SE_M_EXPLOSION
	delay 6
	playse SE_M_EXPLOSION
	delay 6
	playse SE_M_EXPLOSION
	delay 6
	playse SE_M_EXPLOSION
	delay 6
	playse SE_M_EXPLOSION
	waitse
	return

UndergroundCity_Entrance_Movement_PlayerEnter:
	delay_16
	@delay_16
	@delay_16
	walk_down
	step_end

UndergroundCity_Entrance_Movement_CameraPanDown:
	@walk_down
	walk_down
	walk_down
	walk_down
	step_end

UndergroundCity_Entrance_Movement_CameraPanUp:
	@walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

UndergroundCity_Entrance_Text_AzamiIntro:
	.string "?????: Ufufufufufufufu.\n"
	.string "Well, isn't this a surprise.\p"
	.string "You're JUSTIN of the POKéMON RANGERS,\n"
	.string "aren't you?\p"
	.string "And it looks like you've brought a\n"
	.string "small army with you.\p"
	.string "What on earth are you all doing\n"
	.string "in a place like this?$"

UndergroundCity_Entrance_Text_JustinLookingForTeamGenesis:
	.string "JUSTIN: I could ask you the same thing.\p"
	.string "We're looking for TEAM GENESIS. We have\n"
	.string "reason to believe that their activities\l"
	.string "could jeopardize all of XANTHOS CITY.$"

UndergroundCity_Entrance_Text_AzamiTeamGenesis:
	.string "?????: Ufufufufufufufu.\n"
	.string "Of course you are.\p"
	.string "You've been hunting TEAM GENESIS for a\n"
	.string "long time now, haven't you?\p"
	.string "Perhaps you misunderstand Our mission.$"

UndergroundCity_Entrance_Text_JustinYoureTeamGenesis:
	.string "JUSTIN: You're TEAM GENESIS!?$"

UndergroundCity_Entrance_Text_AzamiHeureticSociety:
	.string "?????: Ufufufufufufufu.\n"
	.string "You truly don't know who I am, do you?\p"
	.string "You may address me as the LADY AZAMI.\n"
	.string "I speak for the Heuretic Society.\p"
	.string "For many years, We have worked\n"
	.string "for the advancement of mankind.\p"
	.string "Thanks to Our initiatives, Our species\n"
	.string "has come so far in such a short time.\p"
	.string "We only want what's best for all of Us.$"

UndergroundCity_Entrance_Text_JustinYoureCriminals:
	.string "JUSTIN: TEAM GENESIS are criminals\n"
	.string "who terrorize innocent people.\p"
	.string "You call that 'the best for all of us?'$"

UndergroundCity_Entrance_Text_AzamiOverzealous:
	.string "AZAMI: Ufufufufufufufu.\n"
	.string "I must apologize for my employees.\p"
	.string "They can be a bit overzealous sometimes,\n"
	.string "but their fervor is their strength.\p"
	.string "Our cause inspires much enthusiasm as\n"
	.string "We look forward to the world-to-come.$"

UndergroundCity_Entrance_Text_AzamiPacing:
	@.string "However, there are always those who are\n"
	@.string "reluctant to accept change.\p"
	.string "However, there are always those who\n"
	.string "stubbornly resist change.\p"
	@.string "Their stubbornness and superstitiousness makes\n"
	@.string "it difficult for them to understand.\p"
	@.string "Their parochiality makes it difficult\n"
	@.string "for them to understand.\p"
	@.string "Minds don't change overnight, you see.\n"
	@.string "And the law is even slower to change.\p"
	.string "Their shortsightedness blunts them\n"
	.string "to Our vision.\p"
	.string "Of fulfilling Our mission as a species.\p"
	@.string "To conquer the final frontier of Ultra Space!\p"
	.string "To transcend Our Earthly limitations.\p" 
	.string "A righteous cause as this must not be\n"
	.string "forestalled by the whims of fools.\p"
	.string "That is why it was necessary to form\n"
	.string "TEAM GENESIS.\p"
	@.string "To operate extralegally in the\n"
	@.string "name of progress!$"
	.string "To advance Our cause untethered\n"
	.string "by legal limitations.\p"
	@.string "Progress won't be delayed by\l"
	@.string "a few stubborn fools.$"
	.string "You may take my personnel\n"
	.string "for common criminals.\p"
	.string "But the fruit of their work is\n"
	.string "in all of Our best interests.\p"
	.string "Don't you see that this is\n"
	.string "for the good of Us all?$"

UndergroundCity_Entrance_Text_JustinAllIKnow:
	@.string "I don't know what this progress talk\n"
	@.string "is all about.\p"
	.string "I don't know what 'best interests'\n"
	.string "you're talking about.\p"
	.string "All I know is that TEAM GENESIS are\n"
	.string "scoundrels who need to be stopped\l"
	.string "before they hurt a lot of people.$"

UndergroundCity_Entrance_Text_AzamiPacing2:
	.string "AZAMI: Ufufufu. I assure you We've\n"
	.string "taken every conceivable precaution.\p"
	.string "Our activities are restricted here in\n"
	.string "the UNDERGROUND CITY.\p"
	.string "How could the people in XANTHOS CITY\n"
	.string "possibly be in any danger?$"

UndergroundCity_Entrance_Text_JustinDontPlayDumb:
	.string "JUSTIN: Don't play dumb! We know what\n"
	.string "you recovered from AB LABS.\p"
	.string "You're trying to repeat what happened\n"
	.string "in WISTERIA CITY!$"

UndergroundCity_Entrance_Text_AzamiPacing3:
	.string "AZAMI: Ufufu, I'm surprised you're old\n"
	.string "enough to know anything about that.\p"
	.string "Yes, We suffered a setback a long time\n"
	.string "ago in WISTERIA CITY.\p"
	.string "But Our designs have come a long way\n"
	.string "since then.\p"
	.string "And now We finally have the opportunity\n"
	.string "to correct Our past mistakes.\p"
	.string "I'm told it's thanks to your people that\n"
	.string "We managed to salvage the technology\l"
	.string "at AB LABS.\p"
	@.string "It's long been the missing piece\n"
	@.string "to our grand design.\p"
	.string "JACE and {PLAYER}, I believe it was.$"

UndergroundCity_Entrance_Text_JustinDoesntMatter:
	.string "JUSTIN: It doesn't matter how\n"
	.string "you got your hands on it.\p"
	.string "What matters is what you're\n"
	.string "doing with it right now.\p"
	.string "If you try to open another bridge,\n"
	.string "you'll endanger all of XANTHOS CITY!\p"
	.string "And all of ISSHO itself if it spirals\n"
	.string "out of control!$"

UndergroundCity_Entrance_Text_AzamiPacing4:
	.string "AZAMI: You know I knew your father.\n"
	.string "You sound very much like him.\p"
	.string "He could be close-minded about these\n"
	.string "sorts of things too.\p"
	.string "He could never be taught the value\n"
	.string "of Our work...$"
	@.string "Unfortunately, reeducating him was\n"
	@.string "never an option...$"
	@.string "Unfortunately, we could never educate\n"
	@.string "him properly on the value of our work...$"

UndergroundCity_Entrance_Text_AzamiPacing5:
	.string "And I'm afraid I don't have the time\n"
	.string "to lecture you RANGERS either.\p"
	.string "I will only say this.\p"
	.string "The great revolutions of the past never\n"
	.string "came about painlessly.\p"
	.string "Blood, sweat, and tears must be\n"
	.string "shed at times.\p"
	.string "We all must make sacrifices for Our\n"
	.string "great and glorious future!$"

UndergroundCity_Entrance_Text_JustinYouHaveNoRight:
	.string "JUSTIN: I don't know what kind\n"
	.string "of future you have in mind.\p"
	.string "But nothing gives you the right to\n"
	.string "sacrifice the lives of ordinary people!$"

UndergroundCity_Entrance_Text_AzamiDontKnowYourPlace:
	.string "AZAMI: Ufufufufufufu.\n"
	.string "It seems you don't know your place.\p"
	.string "There is a natural order to this world.\p"
	.string "It is the duty of the best and brightest\n"
	.string "to direct humanity toward its future.\p"
	.string "Just as livestock are yoked to the plow,\n"
	.string "the weak don't get to decide what\l"
	.string "happens to them.\p"
	.string "You're all just pawns to be used for\n"
	.string "the greater good!$"

UndergroundCity_Entrance_Text_JustinYouExpectMe:
	.string "JUSTIN: You expect me to swallow\n"
	.string "that load of crap!?$"

UndergroundCity_Entrance_Text_AzamiFarewell:
	.string "AZAMI: No, I see now that there\n"
	.string "will be no reasoning with you.\p"
	.string "It no longer matters. Soon life as We\n"
	.string "know it will change forever.\p"
	.string "It is regrettable that you won't\n"
	.string "be around to see it.\p"
	.string "But I'm afraid you've forced my hand.\n"
	.string "Farewell, POKéMON RANGERS.$"

UndergroundCity_Entrance_Text_JustinHologram:
	.string "JUSTIN: A hologram!?$"

UndergroundCity_Entrance_Text_JustinOutsideNow:
	.string "The ceiling's coming down!\n"
	.string "Everybody outside, now!$"




