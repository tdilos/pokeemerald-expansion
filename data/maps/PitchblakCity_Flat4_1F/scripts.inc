PitchblakCity_Flat4_1F_MapScripts::
	.byte 0

PitchblakCity_Flat4_1F_EventScript_OldMan::
	lock
	faceplayer
	msgbox PitchblakCity_Flat4_1F_Text_SpendingCuts, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Flat4_1F_Text_SpendingCuts:
	.string "Do you have any idea how much\n"
	.string "I pay in taxes?\p"
	.string "And the city keeps demanding that\n"
	.string "I pay more!\p"
	.string "Another housing project?\n"
	.string "More handouts to jobless bums?\p"
	.string "Bah! We need spending reform,\n"
	.string "that's what I think!$"

PitchblakCity_Flat4_1F_EventScript_OldLady::
	lock
	faceplayer
	msgbox PitchblakCity_Flat4_1F_Text_ThingsChange, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Flat4_1F_Text_ThingsChange:
	.string "Here in PITCHBLAK CITY, things\n"
	.string "change all the time.\p"
	.string "Sometimes I wish they'd stay the same\n"
	.string "for a little longer...$"


