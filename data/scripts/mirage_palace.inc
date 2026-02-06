MiragePalace_EventScript_Exit::
	@setvar VAR_SAFARI_ZONE_STATE, 1
	clearflag FLAG_FORCE_LOAD_OFFSCREEN_OBJEV
	special ExitMiragePalace
	warpsilent MAP_ROUTE70, 38, 30
	waitstate
	end

MiragePalace_EventScript_Warning::
	lockall
	setvar VAR_0x8004, 1 @ vertical pan
	setvar VAR_0x8005, 1 @ horizontal pan
	setvar VAR_0x8006, 8 @ num shakes
	setvar VAR_0x8007, 3 @ shake delay
	special ShakeCamera
	delay 60
	@message MiragePalace_Text_Warning
	@waitmessage
	@waitbuttonpress
	releaseall
	end



MiragePalace_EventScript_TimesUp::
	lockall
	@playse SE_DING_DONG
	setvar VAR_0x8004, 1 @ vertical pan
	setvar VAR_0x8005, 2 @ horizontal pan
	setvar VAR_0x8006, 32 @ num shakes
	setvar VAR_0x8007, 5 @ shake delay
	special ShakeCamera
	message MiragePalace_Text_TimesUp
	waitmessage
	waitbuttonpress
	releaseall
	goto MiragePalace_EventScript_Exit


MiragePalace_Text_Warning:
	.string "Warning!\n"
	.string "Only 80 steps remaining!$"

MiragePalace_Text_TimesUp:
	.string "The walls are collapsing!$"




