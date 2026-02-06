PitchblakCity_Flat5_1F_MapScripts::
	.byte 0

PitchblakCity_Flat5_1F_EventScript_Man::
	msgbox PitchblakCity_Flat5_1F_Text_LivingSoul, MSGBOX_NPC
	end

PitchblakCity_Flat5_1F_Text_LivingSoul:
	.string "When scientists study a thing,\n"
	.string "they strive to kill it first.\p"
	.string "They have all the parts\n"
	.string "but lack the whole.\p"
	.string "For what's missing is\n"
	.string "the living soul.$"

PitchblakCity_Flat5_1F_EventScript_Boy::
	lock
	faceplayer
	msgbox PitchblakCity_Flat5_1F_Text_EvolvedFromAipom, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Flat5_1F_Text_EvolvedFromAipom:
	.string "In school they taught us that people\n"
	.string "and POKéMON used to be the same.\p"
	.string "And at one point, people used to\n"
	.string "look kinda like an AMBIPOM.\p"
	.string "That's really weird to think about...$"


