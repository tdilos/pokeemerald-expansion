DuskMountain_SouthMaze_MapScripts::
	.byte 0

DuskMountain_EventScript_Curt::
	trainerbattle_single TRAINER_CURT, DuskMountain_Text_CurtIntro, DuskMountain_Text_CurtDefeated
	msgbox DuskMountain_Text_CurtPostBattle, MSGBOX_AUTOCLOSE
	end

DuskMountain_EventScript_Olga::
	trainerbattle_single TRAINER_OLGA, DuskMountain_Text_OlgaIntro, DuskMountain_Text_OlgaDefeated
	msgbox DuskMountain_Text_OlgaPostBattle, MSGBOX_AUTOCLOSE
	end




