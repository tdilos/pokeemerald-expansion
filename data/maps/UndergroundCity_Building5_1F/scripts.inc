UndergroundCity_Building5_1F_MapScripts::
	.byte 0

UndergroundCity_Building5_1F_EventScript_Justin::
	lock
	faceplayer
	msgbox UndergroundCity_Building5_1F_Text_Justin, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

UndergroundCity_Building5_1F_Text_Justin:
	.string "JUSTIN: I'll handle these guys, {PLAYER}.\p"
	.string "Stop that Ultra Space bridge\n"
	.string "from opening!$"





UndergroundCity_Building5_1F_EventScript_GruntsVsJustin::
	lock
	msgbox UndergroundCity_Building5_1F_Text_GruntsVsJustin, MSGBOX_DEFAULT
	release
	end

UndergroundCity_Building5_1F_Text_GruntsVsJustin:
	.string "He's winning even though it's 3 vs 1?\n"
	.string "This ain't fair!!$"



UndergroundCity_Building5_1F_EventScript_Pokemon::
	lock
	@faceplayer
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_NORMAL
	msgbox UndergroundCity_Building5_1F_Text_Pokemon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

UndergroundCity_Building5_1F_Text_Pokemon:
	.string "!!!$"



