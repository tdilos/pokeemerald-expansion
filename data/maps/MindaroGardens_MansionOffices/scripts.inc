.set LOCALID_EIRA, 2

MindaroGardens_MansionOffices_MapScripts::
	.byte 0

MindaroGardens_MansionOffices_EventScript_Gentleman::
	goto_if_set FLAG_MINDARO_GARDENS_RECEIVED_FULL_HEAL, MindaroGardens_MansionOffices_EventScript_Redemption
	msgbox MindaroGardens_MansionOffices_Text_Mistakes, MSGBOX_NPC
	giveitem ITEM_FULL_HEAL
	closemessage
	setflag FLAG_MINDARO_GARDENS_RECEIVED_FULL_HEAL
	end

MindaroGardens_MansionOffices_Text_Mistakes:
	.string "When you get older, you have more\n"
	.string "time to reflect on your life.\p"
	.string "Some things you can be proud of.\p"
	.string "But then there are some mistakes that\n"
	.string "you wish you could undo.\p"
	.string "Nothing can change the past, of course.\p"
	.string "But I've done what I can to make\n"
	.string "certain things right.\p"
	.string "\p"
	.string "Bah. Look at me. An old man rambling.\p"
	.string "Here, you can have this for your trouble.$"
	
MindaroGardens_MansionOffices_EventScript_Redemption::	
	msgbox MindaroGardens_MansionOffices_Text_Redemption, MSGBOX_NPC
	closemessage
	end

MindaroGardens_MansionOffices_Text_Redemption:
	@.string "Some wounds never fully heal.\p"
	.string "Some mistakes can never be undone.\p"
	.string "But I believe that we can all\n"
	.string "find redemption somehow.$"

MindaroGardens_MansionOffices_EventScript_Eira::
	lockall
	faceplayer
	msgbox MindaroGardens_MansionOffices_Text_GymLeaderFound, MSGBOX_NPC
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	waitse
	removeobject LOCALID_EIRA
	setflag FLAG_FOUND_EIRA
	fadescreen FADE_FROM_BLACK
	delay 60
	releaseall	
	end

MindaroGardens_MansionOffices_Text_GymLeaderFound:
	.string "Oh, hello. Who are you?\p"
	.string "\p"
	.string "{PLAYER}? Nice to meet you.\p"
	.string "I'm EIRA. I'm the gym leader\n"
	.string "of this city.\p"
	.string "\p"
	.string "You're a POKéMON trainer, huh?\n"
	.string "That's just what I was hoping to hear!\p"
	.string "I come to see the new maze every year.\n"
	.string "But all this rich people stuff bores me.\p"
	.string "The trainers here were nothing\n"
	.string "special either.\p"
	.string "But you have those gym badges on you.\p"
	.string "You must be committed to travel\n"
	.string "all over like that.\p" 
	.string "If you're here to challenge the gym,\n"
	.string "I'll head back right away!\p"
	.string "It's been so long since I've had\n"
	.string "a good battle. I can't wait!$"

