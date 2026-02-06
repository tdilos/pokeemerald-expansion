WisteriaCity_House4_MapScripts::
	.byte 0

WisteriaCity_House4_EventScript_Man::
	lock
	faceplayer
	msgbox WisteriaCity_House4_Text_OldLaboratory, MSGBOX_DEFAULT
	release
	end

WisteriaCity_House4_Text_OldLaboratory:
	.string "Ever since the incident long ago,\n"
	.string "the old lab's been kept locked up.\p"
	.string "The only one who knows how to get\n"
	.string "in there now is DR. ADDERLY.$"


