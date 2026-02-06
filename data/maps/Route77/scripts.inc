Route77_MapScripts::
	.byte 0

Route77_EventScript_Zoe::
	trainerbattle_double TRAINER_ZOE_AND_ROSS, Route77_Text_ZoeAndRossIntro, Route77_Text_ZoeAndRossDefeated, Route77_Text_ZoeAndRossNotEnoughMons
	msgbox Route77_Text_ZoePostBattle, MSGBOX_AUTOCLOSE
	end

Route77_EventScript_Ross::
	trainerbattle_double TRAINER_ZOE_AND_ROSS, Route77_Text_ZoeAndRossIntro, Route77_Text_ZoeAndRossDefeated, Route77_Text_ZoeAndRossNotEnoughMons
	msgbox Route77_Text_RossPostBattle, MSGBOX_AUTOCLOSE
	end

Route77_EventScript_Ralph::
	trainerbattle_single TRAINER_RALPH, Route77_Text_RalphIntro, Route77_Text_RalphDefeated
	msgbox Route77_Text_RalphPostBattle, MSGBOX_AUTOCLOSE
	end

Route77_EventScript_Bonnie::
	trainerbattle_single TRAINER_BONNIE, Route77_Text_BonnieIntro, Route77_Text_BonnieDefeated
	msgbox Route77_Text_BonniePostBattle, MSGBOX_AUTOCLOSE
	end



