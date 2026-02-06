PitchblakCity_Flat6_2F_MapScripts::
	.byte 0

PitchblakCity_Flat6_2F_EventScript_Hiker::
	lock
	faceplayer
	msgbox PitchblakCity_Flat6_2F_Text_CantThinkStraight, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Flat6_2F_Text_CantThinkStraight:
	.string "The way you battle had me\n"
	.string "all turned around.\p"
	.string "I couldn't even think straight.\n"
	.string "Wahahahaha!$"

PitchblakCity_Flat6_2F_EventScript_Youngster::
	lock
	faceplayer
	msgbox PitchblakCity_Flat6_2F_Text_HoennHouse, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Flat6_2F_Text_HoennHouse:
	.string "You should check out the\n"
	.string "battle house in HOENN.\p"
	.string "I hear their trainers are even\n"
	.string "stronger than our president!$"

PitchblakCity_Flat6_2F_EventScript_Lass::
	lock
	faceplayer
	msgbox PitchblakCity_Flat6_2F_Text_HoennHouse2, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Flat6_2F_Text_HoennHouse2:
	.string "The HOENN battle house has many\n"
	.string "different specialists.\p" 
	.string "They don't just do inverse battles\n"
	.string "like us.$"

PitchblakCity_Flat6_2F_EventScript_Psychic::
	lock
	faceplayer
	msgbox PitchblakCity_Flat6_2F_Text_President, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Flat6_2F_Text_President:
	.string "As president, it is my responsibility to\n"
	.string "be the battle house's ultimate test.\p"
	.string "You triumphed over us this time, but\n"
	.string "we won't give up so easily.\p"
	.string "May we meet again some day.$"



