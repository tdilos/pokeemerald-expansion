.set LOCALID_OLDWOMAN, 1

BurgundyTown_House5_MapScripts::
	.byte 0

BurgundyTown_House5_EventScript_OldWoman::
	lock
	faceplayer
	msgbox BurgundyTown_House5_Text_RestUpHere, MSGBOX_NPC
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	applymovement LOCALID_OLDWOMAN, Common_Movement_FaceRight
	waitmovement 0
	release
	end

BurgundyTown_House5_Text_RestUpHere:
	.string "Goodness gracious!\n"
	.string "You look awfully tired.\p"
	.string "Why not rest up here a bit?$"


BurgundyTown_House5_EventScript_FatMan::
	msgbox BurgundyTown_House5_Text_PCHookup, MSGBOX_NPC
	closemessage
	end

BurgundyTown_House5_Text_PCHookup:
	.string "We're pretty isolated here\n"
	.string "in BURGUNDY TOWN.\p"
	.string "It wasn't easy, but I managed\n"
	.string "to hook up that PC over there.\p"
	.string "Feel free to use it whenever\n"
	.string "you like.$"


