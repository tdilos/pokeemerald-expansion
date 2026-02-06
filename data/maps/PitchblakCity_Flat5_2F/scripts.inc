PitchblakCity_Flat5_2F_MapScripts::
	.byte 0

PitchblakCity_Flat5_2F_EventScript_Father::
	lock
	faceplayer
	msgbox PitchblakCity_Flat5_2F_Text_AddictedToScreens, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Flat5_2F_Text_AddictedToScreens:
	.string "Kids these days.\p"
	.string "They sit inside with their faces\n"
	.string "glued to screens all day.\p"
	.string "It's frying their attention spans,\n"
	.string "I tell you what!$"


PitchblakCity_Flat5_2F_EventScript_Mother::
	msgbox PitchblakCity_Flat5_2F_Text_ThingsChange, MSGBOX_NPC
	end

PitchblakCity_Flat5_2F_Text_ThingsChange:
	.string "Everything changes so quickly\n"
	.string "here in PITCHBLAK CITY.\p"
	.string "Kids today are nothing like I\n"
	.string "remember being at their age.\p" 
	.string "But I'm sure it'll all work\n"
	.string "out for the best somehow.$"

PitchblakCity_Flat5_2F_EventScript_Girl::
	lock
	msgbox PitchblakCity_Flat5_2F_Text_GluedToTV, MSGBOX_DEFAULT
	release
	end

PitchblakCity_Flat5_2F_Text_GluedToTV:
	.string "\p"
	.string "Her gaze is fixed on the TV.\n"
	.string "She won't look away.$"


