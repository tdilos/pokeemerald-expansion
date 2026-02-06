DuskMountain_WaterfallRoom_MapScripts::
	.byte 0

DuskMountain_EventScript_Tristan::
	trainerbattle_single TRAINER_TRISTAN, DuskMountain_Text_TristanIntro, DuskMountain_Text_TristanDefeated
	msgbox DuskMountain_Text_TristanPostBattle, MSGBOX_AUTOCLOSE
	end





DuskMountain_WaterfallRoom_EventScript_Scientist::
	lock
	faceplayer
	msgbox DuskMountain_WaterfallRoom_Text_PureCrystals, MSGBOX_DEFAULT
	release
	end

DuskMountain_WaterfallRoom_Text_PureCrystals:
	.string "Watch your step!\p"
	@.string "Some of the crystals in this cave are\n"
	@.string "so pure that you see right through them.$"
	.string "Some of these crystals are so pure\n"
	.string "that you see right through them!$"

