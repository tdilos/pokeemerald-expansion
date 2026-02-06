Route88_BerryHouse_MapScripts::
	.byte 0

Route88_BerryHouse_EventScript_Beauty::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_BERRY_MASTER_RECEIVED_BERRY, Route88_BerryHouse_EventScript_PostBerry
	msgbox Route88_BerryHouse_Text_MyGrandfather, MSGBOX_DEFAULT
	giveitem ITEM_CHILAN_BERRY
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_BERRY_MASTER_RECEIVED_BERRY
	msgbox Route88_BerryHouse_Text_LetFlowersFillTheWorld, MSGBOX_DEFAULT
	release
	end

Route88_BerryHouse_EventScript_PostBerry::
	msgbox Route88_BerryHouse_Text_LetFlowersFillTheWorld, MSGBOX_DEFAULT
	release
	end

Route88_BerryHouse_Text_MyGrandfather:
	.string "My grandfather would want you\n"
	.string "to have this.$"

Route88_BerryHouse_Text_LetFlowersFillTheWorld:
	.string "Let flowers fill the world!$"

Route88_BerryHouse_EventScript_Farmer::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM01, Route88_BerryHouse_EventScript_PostHM
	msgbox Route88_BerryHouse_Text_IClearedThisLand, MSGBOX_DEFAULT
	giveitem ITEM_HM01
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_HM01
	msgbox Route88_BerryHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

Route88_BerryHouse_EventScript_PostHM::
	msgbox Route88_BerryHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

Route88_BerryHouse_Text_IClearedThisLand:
	.string "I cleared the land here all by myself.\p"
	.string "I taught my POKéMON how to CUT down\n"
	.string "trees with this HIDDEN MACHINE.\p"
	.string "I don't really have a use for it\n"
	.string "anymore...\p"
	.string "You know what, why don't you take it?$"

Route88_BerryHouse_Text_ExplainCut:
	.string "With that HIDDEN MACHINE, your POKéMON\n"
	.string "can learn how to CUT down trees.\p"
	.string "But you'll need the gym badge in\n"
	.string "RESEDA TOWN to use it.$"
	@.string "But be warned, HM moves can't be\n"
	@.string "forgotten like ordinary moves.$"

