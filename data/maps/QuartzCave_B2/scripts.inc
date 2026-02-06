.set LOCALID_RAYNER, 8

QuartzCave_B2_MapScripts::
	.byte 0

QuartzCave_EventScript_Cecil::
	trainerbattle_single TRAINER_CECIL, QuartzCave_Text_CecilIntro, QuartzCave_Text_CecilDefeated
	msgbox QuartzCave_Text_CecilPostBattle, MSGBOX_AUTOCLOSE
	end

QuartzCave_EventScript_Axel::
	trainerbattle_single TRAINER_AXEL, QuartzCave_Text_AxelIntro, QuartzCave_Text_AxelDefeated
	msgbox QuartzCave_Text_AxelPostBattle, MSGBOX_AUTOCLOSE
	end

QuartzCave_EventScript_Neil::
	trainerbattle_single TRAINER_NEIL, QuartzCave_Text_NeilIntro, QuartzCave_Text_NeilDefeated
	msgbox QuartzCave_Text_NeilPostBattle, MSGBOX_AUTOCLOSE
	end

QuartzCave_EventScript_Bruce::
	trainerbattle_single TRAINER_BRUCE, QuartzCave_Text_BruceIntro, QuartzCave_Text_BruceDefeated
	msgbox QuartzCave_Text_BrucePostBattle, MSGBOX_AUTOCLOSE
	end





@QuartzCave_EventScript_RaynerTrigger::
@	goto_if_unset FLAG_BATTLED_RAYNER_QUARTZ_CAVE, QuartzCave_EventScript_RaynerEncounter
@	end

QuartzCave_EventScript_RaynerEncounter::
	lockall
	playmoncry SPECIES_JIRACHI, CRY_MODE_NORMAL
	waitmoncry
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	msgbox QuartzCave_Text_SomethingNearby, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_RAYNER, Common_Movement_FaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	delay 60
	applymovement LOCALID_RAYNER, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_RAYNER, Common_Movement_WalkLeft
	waitmovement 0
	delay 60
	msgbox QuartzCave_Text_RaynerPreBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro_no_whiteout TRAINER_RAYNER_QUARTZ_CAVE, QuartzCave_Text_RaynerDefeated
	special CheckIfTeamFainted
	goto_if_eq VAR_RESULT, FALSE, QuartzCave_EventScript_WonRaynerBattle
	goto_if_eq VAR_RESULT, TRUE, QuartzCave_EventScript_LostRaynerBattle
	end

QuartzCave_Text_SomethingNearby:
	.string "It sounded like something nearby.$"

QuartzCave_Text_RaynerPreBattle:
	.string "??????: ...\p"
	.string "Hehehe. What do we have here?\p"
	.string "Wait. I remember you.\n"
	.string "You're that trainer from XANTHOS CITY.\p"
	.string "You're the last thing I was expecting\n"
	.string "to find here.\p"
	@.string "Hehehehe. I think I'll play\n"
	@.string "with you for a while.$"
	.string "Why don't you show me how much\n"
	.string "stronger you've become?$"
	@.string "Why don't we play a little game?\p"
	@.string "A POKéMON battle.\n"
	@.string "Right here. Right now.$"

QuartzCave_Text_RaynerDefeated:
	.string "That will do.$"

QuartzCave_EventScript_WonRaynerBattle::
	delay 60
	msgbox QuartzCave_Text_RaynerPostBattleVictory, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_RAYNER, Common_Movement_FaceUp
	delay 60
	msgbox QuartzCave_Text_WishingWell, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_RAYNER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox QuartzCave_Text_RaynerWishAndHeal, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, QuartzCave_EventScript_StillGotSomeFight
	call_if_eq VAR_RESULT, YES, QuartzCave_EventScript_NotTooProudToBeg
	delay 40
	msgbox QuartzCave_Text_DestinedToMeetAgain, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RAYNER, QuartzCave_Movement_RaynerExit
	waitmovement 0
	removeobject LOCALID_RAYNER
	setflag FLAG_BATTLED_RAYNER_QUARTZ_CAVE
	setvar VAR_RAYNER_STATE, 2
	releaseall
	end

QuartzCave_EventScript_LostRaynerBattle::
	delay 60
	msgbox QuartzCave_Text_RaynerPostBattleDefeat, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_RAYNER, Common_Movement_FaceUp
	delay 60
	msgbox QuartzCave_Text_WishingWell, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_RAYNER, Common_Movement_FaceLeft
	waitmovement 0
	delay 20
	msgbox QuartzCave_Text_RaynerWishAndHeal, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, QuartzCave_EventScript_StillGotSomeFight
	call_if_eq VAR_RESULT, YES, QuartzCave_EventScript_NotTooProudToBeg
	delay 120
	msgbox QuartzCave_Text_AllYourPokemonFainted, MSGBOX_DEFAULT
	closemessage
	@applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	@waitmovement 0
	applymovement LOCALID_RAYNER, QuartzCave_Movement_RaynerExit
	waitmovement 0
	fadeoutbgm 0
	delay 40
	msgbox QuartzCave_Text_KeepPlaying, MSGBOX_YESNO
	msgbox QuartzCave_Text_ResetSaveFile, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, QuartzCave_EventScript_ResetSaveFile
	msgbox QuartzCave_Text_DeterminedToPressOn, MSGBOX_DEFAULT
	closemessage
	delay 120
	playmoncry SPECIES_JIRACHI, CRY_MODE_NORMAL
	waitmoncry
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 10
	fadescreen FADE_TO_WHITE
	special HealPlayerParty
	delay 120
	fadescreen FADE_FROM_WHITE
	msgbox QuartzCave_Text_FullyHealed, MSGBOX_DEFAULT
	closemessage
	removeobject LOCALID_RAYNER
	setflag FLAG_BATTLED_RAYNER_QUARTZ_CAVE
	setvar VAR_RAYNER_STATE, 2
	fadeinbgm 0
	releaseall
	end

QuartzCave_Text_RaynerPostBattleVictory:
	.string "??????: ...\p"
	@.string "I gotta say, I'm impressed by\n"
	@.string "your determination.\p"
	@.string "You believe in winning no matter\n"
	@.string "the cost, right?\n"
	@.string "That's how you were able to push past\n"
	@.string "your limits.\p"
	@.string "...\p"
	@.string "How interesting. There are so many things\n"
	@.string "to learn about POKéMON.$"
	.string "Hehehe. Looks like you have improved\n"
	.string "since last time.\p"
	.string "I gotta say it's impressive how far\n"
	.string "you've gotten with such weak POKéMON.\p"
	.string "...\p"
	.string "What? Don't tell you didn't know.\p"
	.string "Hehehehe. Maybe you're not as smart\n"
	.string "as I thought.$"


QuartzCave_Text_RaynerPostBattleDefeat:
	.string "??????: ...\p"
	.string "Hehehehehe. Wow.\p"
	.string "I was hoping you had improved\n"
	.string "enough to beat these POKéMON.\p"
	.string "But you're just soooooo disappointing.\p"
	@.string "Look at your fainted POKéMON. Do you\n"
	@.string "think they're disappointed in you too?\p"
	.string "Do you think your POKéMON are\n"
	.string "disappointed too?\p"
	.string "It's your fault they're hurt right now.\p"
	.string "They put their trust in you, and\n"
	.string "you let them down.\p"
	.string "Maybe you should just give up on\n"
	.string "being a POKéMON trainer.\p"
	.string "Not everyone is cut out for it,\n"
	.string "you know.\p"
	.string "And you don't want to hurt your POKéMON\n"
	.string "anymore, riiight?$"

QuartzCave_Text_WishingWell:
	.string "This place is known by some as the\n"
	.string "WISHING WELL.\p"
	.string "There are stories of people who come\n"
	.string "here looking for miracles.\p"
	.string "Desperate people without any options.\p"
	.string "They come here to speak their wishes\n"
	.string "into the void.\p"
	.string "And some say they've seen those wishes\n"
	.string "come true.\p"
	@.string "They tell stories about people who spoke\n"
	@.string "their wishes into the darkness here,\l"
	@.string "and found that those wishes had come true.\p"
	@.string "and later those wishes came true.\p"
	.string "Some even say a POKéMON appears to them.\p"
	.string "But not everyone who comes here has\n"
	.string "their prayers answered...$"




QuartzCave_Text_RaynerWishAndHeal:
	.string "Do you know what I want to wish for?\p"
	.string "...\p"
	.string "Well, it would be a waste to tell\n"
	.string "you about it.\p"
	.string "...\p"
	.string "I feel kinda bad about leaving you here\n"
	.string "all weak and defenseless.\p"
	.string "I guess I could heal your POKéMON\n"
	.string "after that beating they took.\p"
	.string "Would you like to me to do that?$"

QuartzCave_EventScript_StillGotSomeFight::
	msgbox QuartzCave_Text_StillGotSomeFight, MSGBOX_NPC
	closemessage
	return

QuartzCave_Text_StillGotSomeFight:
	.string "Hehehe. Still got some fight left\n"
	.string "in you, huh?\p"
	.string "I'll let you keep trying then.$"

QuartzCave_EventScript_NotTooProudToBeg::
	msgbox QuartzCave_Text_NotTooProudToBeg, MSGBOX_NPC
	special ChoosePartyMon
	waitstate
	call_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, QuartzCave_EventScript_DeclineHealOffer
	call_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, QuartzCave_EventScript_SaveMon
	return

QuartzCave_Text_NotTooProudToBeg:
	.string "Hehehehehe. Not too proud to beg, huh?\p"
	.string "Why don't you choose the POKéMON\n"
	.string "you want to save the most,\l"
	.string "and leave the rest here in this cave.$"



QuartzCave_EventScript_DeclineHealOffer::
	msgbox QuartzCave_Text_AttachedToPokemon, MSGBOX_NPC
	return

QuartzCave_Text_AttachedToPokemon:
	.string "Hehehehe. Actually, I don't have any\n"
	.string "healing items.\p"
	.string "I just wanted to see if you'd really\n"
	.string "abandon your POKéMON.\p"
	.string "You're really attached to them all, huh?$"




QuartzCave_EventScript_SaveMon::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	call_if_eq VAR_RESULT, SPECIES_EGG, QuartzCave_EventScript_CantHealEgg
	call_if_ne VAR_RESULT, SPECIES_EGG, QuartzCave_EventScript_SadisticChoice
	return

QuartzCave_EventScript_CantHealEgg::
	msgbox QuartzCave_Text_CantHealEgg, MSGBOX_NPC
	return

QuartzCave_Text_CantHealEgg:
	.string "You want me to heal an egg?\n"
	.string "Are you stupid or something?\p"
	.string "Actually, I don't have any\n"
	.string "healing items.\p"
	.string "I just wanted to see if you'd really\n"
	.string "abandon your POKéMON.\p"
	.string "But you don't even know what you're doing.\n"
	.string "How boring.$"

QuartzCave_EventScript_SadisticChoice::
	special BufferMonNickname
	msgbox QuartzCave_Text_SadisticChoice, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, QuartzCave_EventScript_AbandonMons
	call_if_eq VAR_RESULT, NO, QuartzCave_EventScript_DeclineHealOffer
	return

QuartzCave_Text_SadisticChoice:
	.string "{STR_VAR_1}, so that's your favorite?\p"
	.string "Alright, drop your POKéBALLS into the\n"
	.string "pit over there.\p"
	.string "Then I'll heal your {STR_VAR_1}.$"



QuartzCave_EventScript_AbandonMons::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	delay 60
	msgbox QuartzCave_Text_AbandonMons, MSGBOX_DEFAULT
	closemessage
	special DeleteUnselectedPartyMons
	delay 80
	msgbox QuartzCave_Text_StartingToLikeYou, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	return
	

QuartzCave_Text_AbandonMons:
	.string "{PLAYER} dropped the other POKéMON\n"
	.string "into the void.$"

QuartzCave_Text_StartingToLikeYou:
	.string "??????: ...\p"
	.string "Hehehehe. Actually, I don't have any\n"
	.string "healing items.\p"
	.string "I just wanted to see if you'd really\n"
	.string "abandon your POKéMON.\p"
	.string "And you really did it!\p"
	.string "Hahahahahahahahahaha!\p"
	.string "I think I'm starting to like you.\p"
	.string "...\p"
	.string "Hey, don't feel bad. They were\n"
	.string "worthless POKéMON anyway.$"



QuartzCave_Text_DestinedToMeetAgain:
	@.string "To tell you the truth, you're the most interesting\n"
	@.string "trainer I've met so far.\p"
	@.string "It's funny how we keep running into each other. Could it be\n"
	@.string "that we're destined to do great things together?$"
	.string "This is the second time you've shown\n"
	.string "me your fighting resolve.\p"
	.string "I wonder just how far that spirit\n"
	.string "will take you.\p"
	.string "You'd better not disappoint me\n"
	.string "if we ever meet again.$"


QuartzCave_Text_AllYourPokemonFainted:
	.string "All your POKéMON are useless now.\p"
	.string "I wonder, is it even possible to make it\n"
	.string "out of this cave like that?\p"
	.string "But hey, you'll figure something out.\p"
	.string "Or just give up. I don't really care.$"

QuartzCave_Movement_RaynerExit:
	delay_8
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_down
	walk_down
	step_end

QuartzCave_Text_KeepPlaying:
	.string "CONTINUE?$"

QuartzCave_Text_ResetSaveFile:
	.string "WARNING!\p"
	.string "Without any usable POKéMON, a wild\n"
	.string "POKéMON encounter will crash the game.\p"
	.string "Do you want to reset to\n"
	.string "the last save file?$"

QuartzCave_Text_DeterminedToPressOn:
	.string "{PLAYER} is determined to keep going.$"

QuartzCave_Text_FullyHealed:
	.string "{PLAYER}'s team was fully healed!$"

QuartzCave_EventScript_ResetSaveFile::
	closemessage
	fadescreen FADE_TO_WHITE
	delay 120
	special DoSoftReset
	releaseall
	end
