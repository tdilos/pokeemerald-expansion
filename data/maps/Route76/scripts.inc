Route76_MapScripts::
	.byte 0

Route76_EventScript_Malachi::
	trainerbattle_single TRAINER_MALACHI, Route76_Text_MalachiIntro, Route76_Text_MalachiDefeated
	msgbox Route76_Text_MalachiPostBattle, MSGBOX_AUTOCLOSE
	end

Route76_EventScript_Veronica::
	trainerbattle_single TRAINER_VERONICA, Route76_Text_VeronicaIntro, Route76_Text_VeronicaDefeated
	msgbox Route76_Text_VeronicaPostBattle, MSGBOX_AUTOCLOSE
	end

Route76_EventScript_Swain::
	trainerbattle_single TRAINER_SWAIN, Route76_Text_SwainIntro, Route76_Text_SwainDefeated
	msgbox Route76_Text_SwainPostBattle, MSGBOX_AUTOCLOSE
	end

Route76_EventScript_Sasha::
	trainerbattle_single TRAINER_SASHA, Route76_Text_SashaIntro, Route76_Text_SashaDefeated
	msgbox Route76_Text_SashaPostBattle, MSGBOX_AUTOCLOSE
	end





Route76_EventScript_SuperRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, Route76_EventScript_ReceivedSuperRod
	msgbox Route76_Text_SuperRodIsSuper, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route76_EventScript_ReceiveSuperRod
	goto_if_eq VAR_RESULT, NO, Route76_EventScript_DeclineSuperRod
	end

Route76_EventScript_ReceiveSuperRod::
	msgbox Route76_Text_OfCourse, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox Route76_Text_TryYourLuckFishing, MSGBOX_DEFAULT
	release
	end

Route76_EventScript_DeclineSuperRod::
	msgbox Route76_Text_YourLoss, MSGBOX_DEFAULT
	release
	end

Route76_EventScript_ReceivedSuperRod::
	msgbox Route76_Text_TryCatchingMonWithSuperRod, MSGBOX_DEFAULT
	release
	end

Route76_Text_SuperRodIsSuper:
	.string "A SUPER ROD is super!\p"
	.string "This baby can reel in POKéMON from\n"
	.string "the ocean floor!\p" 
	.string "You want one, I'll bet.$"

Route76_Text_OfCourse:
	.string "Of course! Who wouldn't?\p"
	.string "Take this and fish, my friend.$"

Route76_Text_TryYourLuckFishing:
	.string "Wherever there's water, try\n"
	.string "your luck at fishing.$"

Route76_Text_YourLoss:
	.string "Aw well, your loss.$"

Route76_Text_TryCatchingMonWithSuperRod:
	.string "Try catching all sorts of POKéMON\n"
	.string "with your SUPER ROD.$"



