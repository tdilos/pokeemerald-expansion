.set LOCALID_DAYCARE_MAN, 3

Route93_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route93_OnTransition
	.byte 0

Route93_OnTransition:
	call Route93_EventScript_TryMoveDayCareMan
	end

Route93_EventScript_TryMoveDayCareMan::
	goto_if_unset FLAG_PENDING_DAYCARE_EGG, Route93_EventScript_StopMoveDayCareMan
	setobjectxyperm LOCALID_DAYCARE_MAN, 60, 5
Route93_EventScript_StopMoveDayCareMan::
	return


Route93_EventScript_RouteSign::
	msgbox Route93_Text_RouteSign, MSGBOX_SIGN
	end

Route93_Text_RouteSign:
	.string "ROUTE 93\p"
	.string "{UP_ARROW} TURQUOISE CITY\n"
	.string "{LEFT_ARROW} MINDARO CITY\l"
	.string "{RIGHT_ARROW} MT SHIRO$"




Route93_EventScript_Dustin::
	trainerbattle_single TRAINER_DUSTIN, Route93_Text_DustinIntro, Route93_Text_DustinDefeated
	msgbox Route93_Text_DustinPostBattle, MSGBOX_AUTOCLOSE
	end

Route93_EventScript_Minerva::
	trainerbattle_single TRAINER_MINERVA, Route93_Text_MinervaIntro, Route93_Text_MinervaDefeated
	msgbox Route93_Text_MinervaPostBattle, MSGBOX_AUTOCLOSE
	end

Route93_EventScript_Enis::
	trainerbattle_single TRAINER_ENIS, Route93_Text_EnisIntro, Route93_Text_EnisDefeated
	msgbox Route93_Text_EnisPostBattle, MSGBOX_AUTOCLOSE
	end

Route93_EventScript_Harley::
	trainerbattle_single TRAINER_HARLEY, Route93_Text_HarleyIntro, Route93_Text_HarleyDefeated
	msgbox Route93_Text_HarleyPostBattle, MSGBOX_AUTOCLOSE
	end

Route93_EventScript_Duke::
	trainerbattle_single TRAINER_DUKE, Route93_Text_DukeIntro, Route93_Text_DukeDefeated
	msgbox Route93_Text_DukePostBattle, MSGBOX_AUTOCLOSE
	end

Route93_EventScript_Jim::
	trainerbattle_single TRAINER_JIM, Route93_Text_JimIntro, Route93_Text_JimDefeated
	msgbox Route93_Text_JimPostBattle, MSGBOX_AUTOCLOSE
	end

Route93_EventScript_Thompson::
	trainerbattle_single TRAINER_THOMPSON, Route93_Text_ThompsonIntro, Route93_Text_ThompsonDefeated
	msgbox Route93_Text_ThompsonPostBattle, MSGBOX_AUTOCLOSE
	end

Route93_EventScript_Sue::
	trainerbattle_single TRAINER_SUE, Route93_Text_SueIntro, Route93_Text_SueDefeated
	msgbox Route93_Text_SuePostBattle, MSGBOX_AUTOCLOSE
	end

Route93_EventScript_Mo::
	trainerbattle_single TRAINER_MO, Route93_Text_MoIntro, Route93_Text_MoDefeated
	msgbox Route93_Text_MoPostBattle, MSGBOX_AUTOCLOSE
	end

Route93_EventScript_Gideon::
	trainerbattle_single TRAINER_GIDEON, Route93_Text_GideonIntro, Route93_Text_GideonDefeated
	msgbox Route93_Text_GideonPostBattle, MSGBOX_AUTOCLOSE
	end

Route93_EventScript_Clyde::
	trainerbattle_single TRAINER_CLYDE, Route93_Text_ClydeIntro, Route93_Text_ClydeDefeated
	msgbox Route93_Text_ClydePostBattle, MSGBOX_AUTOCLOSE
	end

Route93_EventScript_Marcus::
	trainerbattle_single TRAINER_MARCUS, Route93_Text_MarcusIntro, Route93_Text_MarcusDefeated
	msgbox Route93_Text_MarcusPostBattle, MSGBOX_AUTOCLOSE
	end

Route93_EventScript_Keith::
	trainerbattle_single TRAINER_KEITH, Route93_Text_KeithIntro, Route93_Text_KeithDefeated
	msgbox Route93_Text_KeithPostBattle, MSGBOX_AUTOCLOSE
	end






Route93_EventScript_DayCareSign::
	msgbox Route93_Text_DayCareSign, MSGBOX_SIGN
	end

Route93_Text_DayCareSign:
	.string "POKéMON DAY CARE\n"
	.string "“Let us raise your POKéMON.”$"
