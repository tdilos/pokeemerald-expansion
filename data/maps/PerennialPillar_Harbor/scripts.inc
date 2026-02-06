.set LOCALID_SAILOR, 1
.set LOCALID_SS_TIDAL, 2

PerennialPillar_Harbor_MapScripts::
	.byte 0

PerennialPillar_Harbor_EventScript_Sailor::
	lock
	faceplayer
	msgbox PerennialPillar_Harbor_Text_SailorReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PerennialPillar_Harbor_EventScript_AsYouLike
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_SAILOR, MAP_PERENNIAL_PILLAR_HARBOR
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	warp MAP_XANTHOS_CITY, 30, 32
	waitstate
	release
	end

PerennialPillar_Harbor_EventScript_AsYouLike::
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	release
	end



