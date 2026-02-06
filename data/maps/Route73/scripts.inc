Route73_MapScripts::
	.byte 0

Route73_EventScript_RouteSign::
	msgbox Route73_Text_RouteSign, MSGBOX_SIGN
	end

Route73_Text_RouteSign:
	.string "ROUTE 73\p"
	.string "{UP_ARROW} ROUTE 89\n"
	.string "{RIGHT_ARROW} PITCHBLAK CITY$"



Route73_EventScript_Boy::
	msgbox Route73_Text_NorthIssho, MSGBOX_NPC
	end

Route73_Text_NorthIssho:
	.string "On a clear day, you can see\n"
	.string "northern ISSHO from here.$"



Route73_EventScript_Nobuo::
	trainerbattle_single TRAINER_NOBUO, Route73_Text_NobuoIntro, Route73_Text_NobuoDefeated
	msgbox Route73_Text_NobuoPostBattle, MSGBOX_AUTOCLOSE
	end

Route73_EventScript_Peyton::
	trainerbattle_single TRAINER_PEYTON, Route73_Text_PeytonIntro, Route73_Text_PeytonDefeated
	msgbox Route73_Text_PeytonPostBattle, MSGBOX_AUTOCLOSE
	end




Route73_EventScript_Flynn::
	trainerbattle_single TRAINER_FLYNN, Route73_Text_FlynnIntro, Route73_Text_FlynnDefeated
	msgbox Route73_Text_FlynnPostBattle, MSGBOX_AUTOCLOSE
	end

Route73_EventScript_Coral::
	trainerbattle_single TRAINER_CORAL, Route73_Text_CoralIntro, Route73_Text_CoralDefeated
	msgbox Route73_Text_CoralPostBattle, MSGBOX_AUTOCLOSE
	end

Route73_EventScript_Ryden::
	trainerbattle_single TRAINER_RYDEN, Route73_Text_RydenIntro, Route73_Text_RydenDefeated
	msgbox Route73_Text_RydenPostBattle, MSGBOX_AUTOCLOSE
	end

Route73_EventScript_Howard::
	trainerbattle_single TRAINER_HOWARD, Route73_Text_HowardIntro, Route73_Text_HowardDefeated
	msgbox Route73_Text_HowardPostBattle, MSGBOX_AUTOCLOSE
	end

Route73_EventScript_Dallas::
	trainerbattle_single TRAINER_DALLAS, Route73_Text_DallasIntro, Route73_Text_DallasDefeated
	msgbox Route73_Text_DallasPostBattle, MSGBOX_AUTOCLOSE
	end

Route73_EventScript_Susan::
	trainerbattle_single TRAINER_SUSAN, Route73_Text_SusanIntro, Route73_Text_SusanDefeated
	msgbox Route73_Text_SusanPostBattle, MSGBOX_AUTOCLOSE
	end

Route73_EventScript_Leary::
	trainerbattle_single TRAINER_LEARY, Route73_Text_LearyIntro, Route73_Text_LearyDefeated
	msgbox Route73_Text_LearyPostBattle, MSGBOX_AUTOCLOSE
	end

Route73_EventScript_Seamus::
	trainerbattle_single TRAINER_SEAMUS, Route73_Text_SeamusIntro, Route73_Text_SeamusDefeated
	msgbox Route73_Text_SeamusPostBattle, MSGBOX_AUTOCLOSE
	end

Route73_EventScript_Roddy::
	trainerbattle_single TRAINER_RODDY, Route73_Text_RoddyIntro, Route73_Text_RoddyDefeated
	msgbox Route73_Text_RoddyPostBattle, MSGBOX_AUTOCLOSE
	end




