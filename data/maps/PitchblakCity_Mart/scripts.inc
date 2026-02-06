PitchblakCity_Mart_MapScripts::
	.byte 0

PitchblakCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Mart_EventScript_Rocker::
	msgbox PitchblakCity_Mart_Text_WhyAmIHere, MSGBOX_NPC
	end

PitchblakCity_Mart_Text_WhyAmIHere:
	.string "I don't know why we're shopping here\n"
	.string "when we could be at the plaza.\p"
	.string "I heard KENDOM's research team\n"
	.string "is holding a new exhibition.$"

PitchblakCity_Mart_EventScript_Maniac::
	msgbox PitchblakCity_Mart_Text_MoreStimulants, MSGBOX_NPC
	end

PitchblakCity_Mart_Text_MoreStimulants:
	.string "I need more STIMULANTS.\n"
	.string "I need more STIMULANTS.\l"
	.string "I need more STIMULANTS.\l"
	.string "I need more STIMULANTS.\l"
	.string "I need more STIMULANTS.\l"
	.string "I need more STIMULANTS.\l"
	.string "I need more STIMULANTS.\l"
	.string "I need more STIMULANTS.\l"
	.string "I need more STIMULANTS.\l"
	.string "I need more STIMULANTS.$"


