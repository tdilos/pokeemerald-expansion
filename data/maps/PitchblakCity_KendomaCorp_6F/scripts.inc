PitchblakCity_KendomaCorp_6F_MapScripts::
	.byte 0

PitchblakCity_KendomaCorp_6F_EventScript_Man::
	msgbox PitchblakCity_KendomaCorp_6F_Text_Hiding, MSGBOX_NPC
	end

PitchblakCity_KendomaCorp_6F_Text_Hiding:
	.string "Shhhhh. Don't let them know\n"
	.string "I'm hiding here.$"

PitchblakCity_KendomaCorp_6F_EventScript_Woman::
	lock
	faceplayer
	msgbox PitchblakCity_KendomaCorp_6F_Text_LookALittleTired, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	release
	end

PitchblakCity_KendomaCorp_6F_Text_LookALittleTired:
	.string "Oh, you look a little tired.\p"
	.string "Why don't you take a rest?$"




