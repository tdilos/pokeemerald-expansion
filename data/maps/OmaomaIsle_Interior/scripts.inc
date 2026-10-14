OmaomaIsle_Interior_MapScripts::
	.byte 0



OmaomaIsle_EventScript_Maile::
	trainerbattle_single TRAINER_MAILE, OmaomaIsle_Text_MaileIntro, OmaomaIsle_Text_MaileDefeated
	msgbox OmaomaIsle_Text_MailePostBattle, MSGBOX_AUTOCLOSE
	end

OmaomaIsle_Text_MaileIntro:
	.string "$"

OmaomaIsle_Text_MaileDefeated:
	.string "$"

OmaomaIsle_Text_MailePostBattle:
	.string "$"


OmaomaIsle_EventScript_Hiapo::
	trainerbattle_single TRAINER_HIAPO, OmaomaIsle_Text_HiapoIntro, OmaomaIsle_Text_HiapoDefeated
	msgbox OmaomaIsle_Text_HiapoPostBattle, MSGBOX_AUTOCLOSE
	end

OmaomaIsle_Text_HiapoIntro:
	.string "$"

OmaomaIsle_Text_HiapoDefeated:
	.string "$"

OmaomaIsle_Text_HiapoPostBattle:
	.string "$"


OmaomaIsle_EventScript_Keanu::
	trainerbattle_single TRAINER_KEANU, OmaomaIsle_Text_KeanuIntro, OmaomaIsle_Text_KeanuDefeated
	msgbox OmaomaIsle_Text_KeanuPostBattle, MSGBOX_AUTOCLOSE
	end

OmaomaIsle_Text_KeanuIntro:
	.string "$"

OmaomaIsle_Text_KeanuDefeated:
	.string "$"

OmaomaIsle_Text_KeanuPostBattle:
	.string "$"






OmaomaIsle_EventScript_Momi::
	trainerbattle_single TRAINER_MOMI, OmaomaIsle_Text_MomiIntro, OmaomaIsle_Text_MomiDefeated
	msgbox OmaomaIsle_Text_MomiPostBattle, MSGBOX_AUTOCLOSE
	end

OmaomaIsle_Text_MomiIntro:
	.string "$"

OmaomaIsle_Text_MomiDefeated:
	.string "$"

OmaomaIsle_Text_MomiPostBattle:
	.string "$"


OmaomaIsle_EventScript_Lani::
	trainerbattle_single TRAINER_LANI, OmaomaIsle_Text_LaniIntro, OmaomaIsle_Text_LaniDefeated
	msgbox OmaomaIsle_Text_LaniPostBattle, MSGBOX_AUTOCLOSE
	end

OmaomaIsle_Text_LaniIntro:
	.string "$"

OmaomaIsle_Text_LaniDefeated:
	.string "$"

OmaomaIsle_Text_LaniPostBattle:
	.string "$"


OmaomaIsle_EventScript_Leihua::
	goto_if_set FLAG_RECEIVED_TALISMAN_OMAOMA_ISLE, OmaomaIsle_EventScript_LeihuaPostBattle
	trainerbattle_single TRAINER_LEIHUA, OmaomaIsle_Text_LeihuaIntro, OmaomaIsle_Text_LeihuaDefeated
	msgbox OmaomaIsle_Text_LeihuaPostBattle, MSGBOX_AUTOCLOSE
	giveitem ITEM_TALISMAN_GREEN
	setflag FLAG_RECEIVED_TALISMAN_OMAOMA_ISLE
	end

OmaomaIsle_EventScript_LeihuaPostBattle::
	msgbox OmaomaIsle_Text_LeihuaPostBattle2, MSGBOX_AUTOCLOSE
	end

OmaomaIsle_Text_LeihuaIntro:
	.string "Watch out! I'll use my magic\n"
	.string "talisman on you!$"

OmaomaIsle_Text_LeihuaDefeated:
	.string "Some talisman this is!$"

OmaomaIsle_Text_LeihuaPostBattle:
	.string "Alright! Since you won, you get to be\n"
	.string "the new wielder of the talisman!\p"
	.string "Just don't tell anyone that you beat me.\n"
	.string "I have a reputation to uphold...$"

OmaomaIsle_Text_LeihuaPostBattle2:
	@.string "That OMAOMA TALISMAN was $"
	.string "That talisman was supposedly left here\n"
	.string "by the GUARDIANS before they disappeared.\p"
	.string "They're said to be magical. But I could\n"
	.string "ever get it to do was dumb rock things.\p"
	.string "Maybe it will work its magic\n"
	.string "for you somehow.$"

