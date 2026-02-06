.set LOCALID_WOMAN, 1

Route80_RestStop_MapScripts::
	.byte 0

Route80_RestStop_EventScript_Woman::
	lock
	faceplayer
	msgbox Route80_RestStop_Text_RestUpHere, MSGBOX_NPC
	closemessage
	@fadescreen FADE_TO_BLACK
	call Common_EventScript_OutOfCenterPartyHeal
	applymovement LOCALID_WOMAN, Common_Movement_FaceLeft
	waitmovement 0
	@fadescreen FADE_FROM_BLACK
	release
	end

Route80_RestStop_Text_RestUpHere:
	.string "Oh, your POKéMON look tired.\n"
	.string "Here, let me see them.$"



