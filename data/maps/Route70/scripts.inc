Route70_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route70_OnTransition
	.byte 0

Route70_OnTransition:
	@clearflag FLAG_SYS_INSIDE_MIRAGE_PALACE
	special ExitMiragePalace
	end





Route70_EventScript_Sigmund::
	trainerbattle_single TRAINER_SIGMUND, Route70_Text_SigmundIntro, Route70_Text_SigmundDefeated
	msgbox Route70_Text_SigmundPostBattle, MSGBOX_AUTOCLOSE
	end

Route70_EventScript_Eustace::
	trainerbattle_single TRAINER_EUSTACE, Route70_Text_EustaceIntro, Route70_Text_EustaceDefeated
	msgbox Route70_Text_EustacePostBattle, MSGBOX_AUTOCLOSE
	end

Route70_EventScript_Adrian::
	trainerbattle_single TRAINER_ADRIAN, Route70_Text_AdrianIntro, Route70_Text_AdrianDefeated
	msgbox Route70_Text_AdrianPostBattle, MSGBOX_AUTOCLOSE
	end

Route70_EventScript_Xena::
	trainerbattle_single TRAINER_XENA, Route70_Text_XenaIntro, Route70_Text_XenaDefeated
	msgbox Route70_Text_XenaPostBattle, MSGBOX_AUTOCLOSE
	end

Route70_EventScript_Casper::
	trainerbattle_single TRAINER_CASPER, Route70_Text_CasperIntro, Route70_Text_CasperDefeated
	msgbox Route70_Text_CasperPostBattle, MSGBOX_AUTOCLOSE
	end

Route70_EventScript_Wren::
	trainerbattle_single TRAINER_WREN, Route70_Text_WrenIntro, Route70_Text_WrenDefeated
	msgbox Route70_Text_WrenPostBattle, MSGBOX_AUTOCLOSE
	end

Route70_EventScript_Ashmund::
	trainerbattle_single TRAINER_ASHMUND, Route70_Text_AshmundIntro, Route70_Text_AshmundDefeated
	msgbox Route70_Text_AshmundPostBattle, MSGBOX_AUTOCLOSE
	end

Route70_EventScript_Edith::
	trainerbattle_single TRAINER_EDITH, Route70_Text_EdithIntro, Route70_Text_EdithDefeated
	msgbox Route70_Text_EdithPostBattle, MSGBOX_AUTOCLOSE
	end

Route70_EventScript_Alphonse::
	trainerbattle_single TRAINER_ALPHONSE, Route70_Text_AlphonseIntro, Route70_Text_AlphonseDefeated
	msgbox Route70_Text_AlphonsePostBattle, MSGBOX_AUTOCLOSE
	end



