PanoIsle_Interior_MapScripts::
	.byte 0



PanoIsle_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_PANO_ISLE_1, PanoIsle_Text_Grunt1Intro, PanoIsle_Text_Grunt1Defeated
	msgbox PanoIsle_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

PanoIsle_Text_Grunt1Intro:
	.string "Halt! This island is now under\n"
	.string "the control of TEAM MAGMA!$"

PanoIsle_Text_Grunt1Defeated:
	.string "I'm so getting fired for this.$"

PanoIsle_Text_Grunt1PostBattle:
	.string "TEAM MAGMA sent us here on an\n"
	.string "important mission.\p"
	.string "Something about retrieving a\n"
	.string "lost artifact, I think.$"


PanoIsle_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_PANO_ISLE_2, PanoIsle_Text_Grunt2Intro, PanoIsle_Text_Grunt2Defeated
	msgbox PanoIsle_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

PanoIsle_Text_Grunt2Intro:
	.string "There's too much water on this world!\n"
	.string "I can't stand it no more!$"

PanoIsle_Text_Grunt2Defeated:
	.string "I'm drowning here!$"

PanoIsle_Text_Grunt2PostBattle:
	.string "Can you believe it? A whole world\n"
	.string "covered in water!\p"
	.string "This is what those TEAM AQUA scoundrels\n"
	.string "want to do to our world!$"


PanoIsle_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_PANO_ISLE_3, PanoIsle_Text_Grunt3Intro, PanoIsle_Text_Grunt3Defeated
	msgbox PanoIsle_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

PanoIsle_Text_Grunt3Intro:
	.string "Where do you think you're going, huh?$"

PanoIsle_Text_Grunt3Defeated:
	.string "Alright, I give, I give!$"

PanoIsle_Text_Grunt3PostBattle:
	.string "The boss says we're supposed to find some\n"
	.string "weird-looking amulet.\p"
	.string "Have you seen anything like that?$"


PanoIsle_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_PANO_ISLE_4, PanoIsle_Text_Grunt4Intro, PanoIsle_Text_Grunt4Defeated
	msgbox PanoIsle_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

PanoIsle_Text_Grunt4Intro:
	.string "What's wrong with wanting more land?\n"
	.string "We all need somewhere to live.$"

PanoIsle_Text_Grunt4Defeated:
	.string "No good.$"

PanoIsle_Text_Grunt4PostBattle:
	.string "So you want HOENN to end up just\n"
	.string "like this place, huh?\p"
	.string "I see how you are.$"


PanoIsle_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_PANO_ISLE_5, PanoIsle_Text_Grunt5Intro, PanoIsle_Text_Grunt5Defeated
	msgbox PanoIsle_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

PanoIsle_Text_Grunt5Intro:
	.string "Hey! What's a kid like you doing\n"
	.string "in a place like this?$"

PanoIsle_Text_Grunt5Defeated:
	.string "Alright! Cool it, cool it!$"

PanoIsle_Text_Grunt5PostBattle:
	.string "I always thought life on other worlds\n"
	.string "was just a myth.\p"
	.string "I feel like I'm walking in a dream here.$"


PanoIsle_EventScript_AdminEncounter::
	lock
	delay 60
	msgbox PanoIsle_Text_AdminIntro1, MSGBOX_AUTOCLOSE
	applymovement LOCALID_MAGMA_ADMIN, Common_Movement_FaceDown
	waitmovement 0
	applymovement LOCALID_MAGMA_ADMIN, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox PanoIsle_Text_AdminIntro2, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_MAGMA_ADMIN_PANO_ISLE, PanoIsle_Text_AdminDefeated
	msgbox PanoIsle_Text_AdminPostBattle, MSGBOX_AUTOCLOSE
	fadescreen FADE_TO_BLACK
	setflag FLAG_RECEIVED_TALISMAN_PANO_ISLE
	delay 60
	fadescreen FADE_FROM_BLACK
	giveitem ITEM_TALISMAN_BLACK
	release
	end

PanoIsle_Text_AdminIntro1:
	.string "At last, the TALISMAN we've been\n"
	.string "searching for.\p"
	.string "Now we just need to find that...$"

PanoIsle_Text_AdminIntro2:
	.string "You! You're working with the\n"
	.string "INTERNATIONAL POLICE, aren't you?\p"
	.string "Why else would anyone follow us\n"
	.string "to a place like this?\p"
	.string "\p"
	.string "Then you must know about our plan\n"
	.string "to release the SEA DEMON.\p"
	.string "You came to stop us, isn't that right?\p"
	.string "Well, I don't know how a SEA DEMON\n"
	.string "is supposed to help TEAM MAGMA.\p"
	.string "To be honest, I still don't know what\n"
	.string "we're doing on a world like this...\p"
	.string "But if the boss says it's true,\n"
	.string "then it must be true.\p"
	.string "If the boss says FIRE is supereffective\n"
	.string "against WATER, then I believe it!\p"
	.string "If the boss says bring back this TALISMAN,\n"
	.string "then I'm gonna bring it to him!\p"
	.string "And no snot-nosed kid is gonna\n"
	.string "stand in my way!$"

PanoIsle_Text_AdminDefeated:
	.string "Hey, hey, cool it!$"

PanoIsle_Text_AdminPostBattle:
	.string "Alright, alright!\n"
	.string "You win already!\p"
	.string "Take the TALISMAN, it's yours!\p"
	.string "I'll just tell the boss we didn't\n"
	.string "find anything.\p"
	.string "I'm getting sick of this weird\n"
	.string "place anyway...$"


