.set LOCALID_OLDWOMAN, 1

BurgundyTown_House1_MapScripts::
	.byte 0

BurgundyTown_House1_EventScript_OldWoman::
	lock
	faceplayer
	msgbox BurgundyTown_House1_Text_RestUpHere, MSGBOX_NPC
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	applymovement LOCALID_OLDWOMAN, Common_Movement_FaceRight
	waitmovement 0
	release
	end

BurgundyTown_House1_Text_RestUpHere:
	.string "Goodness gracious!\n"
	.string "You look awfully tired.\p"
	.string "Why not rest up here a bit?$"


