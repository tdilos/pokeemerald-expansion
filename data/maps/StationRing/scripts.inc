StationRing_MapScripts::
	.byte 0



StationRing_EventScript_Boy::
	lock
	faceplayer
	msgbox StationRing_Text_GiantLightStrips, MSGBOX_DEFAULT
	release
	end

StationRing_Text_GiantLightStrips:
	.string "These giant light strips help to\n"
	.string "illuminate the whole station.$"

