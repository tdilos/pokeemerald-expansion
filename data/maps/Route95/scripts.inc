Route95_MapScripts::
	.byte 0

Route95_EventScript_Kris::
	trainerbattle_single TRAINER_KRIS, Route95_Text_KrisIntro, Route95_Text_KrisDefeated
	msgbox Route95_Text_KrisPostBattle, MSGBOX_AUTOCLOSE
	end

Route95_EventScript_Trevor::
	trainerbattle_single TRAINER_TREVOR, Route95_Text_TrevorIntro, Route95_Text_TrevorDefeated
	msgbox Route95_Text_TrevorPostBattle, MSGBOX_AUTOCLOSE
	end

Route95_EventScript_Wilson::
	trainerbattle_single TRAINER_WILSON, Route95_Text_WilsonIntro, Route95_Text_WilsonDefeated
	msgbox Route95_Text_WilsonPostBattle, MSGBOX_AUTOCLOSE
	end


Route95_EventScript_AromaLady::
	lock
	faceplayer
	msgbox Route95_Text_Nature, MSGBOX_DEFAULT
	release
	end

Route95_Text_Nature:
	.string "Nature is what gives us life.\p"
	.string "That's why I'm always grateful\n"
	.string "to Mother Nature.$"


