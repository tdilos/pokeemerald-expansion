TurquoiseCity_Warehouse_MapScripts::
@	map_script MAP_SCRIPT_ON_TRANSITION, TurquoiseCity_Warehouse_OnTransition
	.byte 0

@TurquoiseCity_Warehouse_OnTransition:
@	call TurquoiseCity_Warehouse_EventScript_HideJace
@	end

@TurquoiseCity_Warehouse_EventScript_RevealJace:
@	setflag FLAG_HIDE_JACE
@	return

TurquoiseCity_Warehouse_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_TURQUOISE_CITY_5, TurquoiseCity_Warehouse_Text_GruntTurquoiseCity5Intro, TurquoiseCity_Warehouse_Text_GruntTurquoiseCity5Defeated
	msgbox TurquoiseCity_Warehouse_Text_GruntTurquoiseCity5PostBattle, MSGBOX_AUTOCLOSE
	end

TurquoiseCity_Warehouse_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_TURQUOISE_CITY_6, TurquoiseCity_Warehouse_Text_GruntTurquoiseCity6Intro, TurquoiseCity_Warehouse_Text_GruntTurquoiseCity6Defeated
	msgbox TurquoiseCity_Warehouse_Text_GruntTurquoiseCity6PostBattle, MSGBOX_AUTOCLOSE
	end

TurquoiseCity_Warehouse_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_TURQUOISE_CITY_3, TurquoiseCity_Warehouse_Text_GruntTurquoiseCity3Intro, TurquoiseCity_Warehouse_Text_GruntTurquoiseCity3Defeated
	msgbox TurquoiseCity_Warehouse_Text_GruntTurquoiseCity3PostBattle, MSGBOX_AUTOCLOSE
	end

TurquoiseCity_Warehouse_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_TURQUOISE_CITY_4, TurquoiseCity_Warehouse_Text_GruntTurquoiseCity4Intro, TurquoiseCity_Warehouse_Text_GruntTurquoiseCity4Defeated
	msgbox TurquoiseCity_Warehouse_Text_GruntTurquoiseCity4PostBattle, MSGBOX_AUTOCLOSE
	end



TurquoiseCity_Warehouse_Text_GruntTurquoiseCity6Intro:
	.string "Hold it!\n"
	.string "Where do you think you're going?$"

TurquoiseCity_Warehouse_Text_GruntTurquoiseCity6Defeated:
	.string "What's going on!?$"

TurquoiseCity_Warehouse_Text_GruntTurquoiseCity6PostBattle:
	.string "Losing makes me angry.\p"
	.string "My POKéMON are supposed to be perfect!$"

TurquoiseCity_Warehouse_Text_GruntTurquoiseCity5Intro:
	.string "Hahahaha! I'll blow you away!$"

TurquoiseCity_Warehouse_Text_GruntTurquoiseCity5Defeated:
	.string "Oops.$"

TurquoiseCity_Warehouse_Text_GruntTurquoiseCity5PostBattle:
	.string "I knew I shoulda brought more POKéMON...$"

TurquoiseCity_Warehouse_Text_GruntTurquoiseCity3Intro:
	.string "Hey! How'd you get in here?$"

TurquoiseCity_Warehouse_Text_GruntTurquoiseCity3Defeated:
	.string "No way!$"

TurquoiseCity_Warehouse_Text_GruntTurquoiseCity3PostBattle:
	.string "Wipe that smug look off your face!\p"
	.string "The boss will make quick work of you.$"

TurquoiseCity_Warehouse_Text_GruntTurquoiseCity4Intro:
	.string "Another one? Don't you all know\n"
	.string "when to give up?$"

TurquoiseCity_Warehouse_Text_GruntTurquoiseCity4Defeated:
	.string "Not again...$"

TurquoiseCity_Warehouse_Text_GruntTurquoiseCity4PostBattle:
	.string "You ain't so tough, kid.\n"
	.string "You're nothing compared to the boss.$"


