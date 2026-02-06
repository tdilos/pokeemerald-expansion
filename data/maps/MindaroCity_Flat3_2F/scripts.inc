.set LOCALID_OLDWOMAN, 1

MindaroCity_Flat3_2F_MapScripts::
	.byte 0

MindaroCity_Flat3_2F_EventScript_Youngster::
	lock
	faceplayer
	msgbox MindaroCity_Flat3_2F_Text_EvolveByMoves, MSGBOX_DEFAULT
	release
	end

MindaroCity_Flat3_2F_Text_EvolveByMoves:
	.string "Some POKéMON only evolve when\n"
	.string "they know certain moves.\p"
	.string "For instance, ABOMASNOW needs to know\n"
	.string "HIDDEN POWER when it levels up.\p"
	.string "And CHIMECHO needs to know MANTRA.$"

MindaroCity_Flat3_2F_EventScript_OldWoman::
	lock
	faceplayer
	checkitem ITEM_CHERISH_BALL
	goto_if_eq VAR_RESULT, TRUE, MindaroCity_Flat3_2F_EventScript_GiveParcel
	msgbox MindaroCity_Flat3_2F_Text_Email, MSGBOX_DEFAULT
	release
	end

MindaroCity_Flat3_2F_Text_Email:
	.string "Nowadays, most folks use email to\n"
	.string "keep in touch with each other.\p"
	.string "As for me, I trust my SPEAROW more\n"
	.string "than some faceless computer hacker.$"

MindaroCity_Flat3_2F_EventScript_Pokemon::
	lock
	faceplayer
	playmoncry SPECIES_SPEAROW, CRY_MODE_NORMAL
	msgbox MindaroCity_Flat3_2F_Text_Pokemon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MindaroCity_Flat3_2F_Text_Pokemon:
	.string "SPEAROW: Piyu piiyuu!$"

MindaroCity_Flat3_2F_EventScript_GiveParcel::
	applymovement LOCALID_OLDWOMAN, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	delay 60
	msgbox MindaroCity_Flat3_2F_Text_ThanksTakeThis, MSGBOX_DEFAULT
	removeitem ITEM_CHERISH_BALL
	giveitem ITEM_OAKS_PARCEL
	msgbox MindaroCity_Flat3_2F_Text_SendMyRegards, MSGBOX_DEFAULT
	release
	end

MindaroCity_Flat3_2F_Text_ThanksTakeThis:
	.string "Oh, you have something for me?\p"
	.string "From the boy in RESEDA TOWN, you say?\p"
	.string "\p"
	.string "That old duff. He remembered after all\n"
	.string "these years.\p"
	.string "You've made an old woman very happy.\p"
	.string "If it's not too much trouble, I'd like\n"
	.string "to take this to him.$"

MindaroCity_Flat3_2F_Text_SendMyRegards:
	.string "That package is too heavy for SPEAROW\n"
	.string "to carry, so I'd like you to deliver it.\p"
	.string "Tell him the girl from the past\n"
	.string "sends her regards.$"
