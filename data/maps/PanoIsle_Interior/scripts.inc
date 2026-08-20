PanoIsle_Interior_MapScripts::
	.byte 0



PanoIsle_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_PANO_ISLE_1, PanoIsle_Text_Grunt1Intro, PanoIsle_Text_Grunt1Defeated
	msgbox PanoIsle_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

PanoIsle_Text_Grunt1Intro:
	.string "$"

PanoIsle_Text_Grunt1Defeated:
	.string "$"

PanoIsle_Text_Grunt1PostBattle:
	.string "$"


PanoIsle_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_PANO_ISLE_2, PanoIsle_Text_Grunt2Intro, PanoIsle_Text_Grunt2Defeated
	msgbox PanoIsle_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

PanoIsle_Text_Grunt2Intro:
	.string "$"

PanoIsle_Text_Grunt2Defeated:
	.string "$"

PanoIsle_Text_Grunt2PostBattle:
	.string "$"


PanoIsle_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_PANO_ISLE_3, PanoIsle_Text_Grunt3Intro, PanoIsle_Text_Grunt3Defeated
	msgbox PanoIsle_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

PanoIsle_Text_Grunt3Intro:
	.string "$"

PanoIsle_Text_Grunt3Defeated:
	.string "$"

PanoIsle_Text_Grunt3PostBattle:
	.string "$"


PanoIsle_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_PANO_ISLE_4, PanoIsle_Text_Grunt4Intro, PanoIsle_Text_Grunt4Defeated
	msgbox PanoIsle_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

PanoIsle_Text_Grunt4Intro:
	.string "$"

PanoIsle_Text_Grunt4Defeated:
	.string "$"

PanoIsle_Text_Grunt4PostBattle:
	.string "$"


PanoIsle_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_PANO_ISLE_5, PanoIsle_Text_Grunt5Intro, PanoIsle_Text_Grunt5Defeated
	msgbox PanoIsle_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

PanoIsle_Text_Grunt5Intro:
	.string "$"

PanoIsle_Text_Grunt5Defeated:
	.string "$"

PanoIsle_Text_Grunt5PostBattle:
	.string "$"


PanoIsle_EventScript_AdminEncounter::
	lock
	delay 60
	msgbox PanoIsle_Text_AdminIntro1, MSGBOX_AUTOCLOSE
	
	trainerbattle_no_intro TRAINER_MAGMA_ADMIN_PANO_ISLE, PanoIsle_Text_AdminDefeated

	end

PanoIsle_Text_AdminIntro1:
	.string "$"

PanoIsle_Text_AdminDefeated:
	.string "$"

PanoIsle_Text_AdminPostBattle:
	.string "$"


