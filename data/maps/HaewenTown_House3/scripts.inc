.set LOCALID_HEXMANIAC, 1

HaewenTown_House3_MapScripts::
	.byte 0

HaewenTown_House3_EventScript_HexManiac::
	lock
	faceplayer
	msgbox HaewenTown_House3_Text_FortuneTeller, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, HaewenTown_House3_EventScript_ReadFuture
	applymovement LOCALID_HEXMANIAC, Common_Movement_FaceRight
	waitmovement 0
	release
	end

HaewenTown_House3_EventScript_ReadFuture::
	delay 120
	@msgbox HaewenTown_House3_Text_ReadFuture, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetKarma
	goto_if_lt VAR_RESULT, 70, HaewenTown_House3_EventScript_WorstKarma
	goto_if_lt VAR_RESULT, 300, HaewenTown_House3_EventScript_BadKarma
	goto_if_lt VAR_RESULT, 400, HaewenTown_House3_EventScript_NeutralBadKarma
	goto_if_lt VAR_RESULT, 500, HaewenTown_House3_EventScript_NeutralGoodKarma
	goto_if_lt VAR_RESULT, 800, HaewenTown_House3_EventScript_GoodKarma
	goto_if_gt VAR_RESULT, 800, HaewenTown_House3_EventScript_BestKarma
	end

HaewenTown_House3_EventScript_WorstKarma::
	msgbox HaewenTown_House3_Text_WorstKarma, MSGBOX_DEFAULT
	goto HaewenTown_House3_EventScript_HexManiacEnd

HaewenTown_House3_EventScript_BadKarma::
	msgbox HaewenTown_House3_Text_BadKarma, MSGBOX_DEFAULT
	goto HaewenTown_House3_EventScript_HexManiacEnd

HaewenTown_House3_EventScript_NeutralBadKarma::
	msgbox HaewenTown_House3_Text_NeutralBadKarma, MSGBOX_DEFAULT
	goto HaewenTown_House3_EventScript_HexManiacEnd

HaewenTown_House3_EventScript_NeutralGoodKarma::
	msgbox HaewenTown_House3_Text_NeutralGoodKarma, MSGBOX_DEFAULT
	goto HaewenTown_House3_EventScript_HexManiacEnd

HaewenTown_House3_EventScript_GoodKarma::
	msgbox HaewenTown_House3_Text_GoodKarma, MSGBOX_DEFAULT
	goto HaewenTown_House3_EventScript_HexManiacEnd

HaewenTown_House3_EventScript_BestKarma::
	msgbox HaewenTown_House3_Text_BestKarma, MSGBOX_DEFAULT
	goto HaewenTown_House3_EventScript_HexManiacEnd

HaewenTown_House3_EventScript_HexManiacEnd::
	applymovement LOCALID_HEXMANIAC, Common_Movement_FaceRight
	waitmovement 0
	release
	end

HaewenTown_House3_Text_FortuneTeller:
	.string "Ooh hoo!\n"
	.string "You have a touch of destiny about you.\p"
	@.string "I'm a fortune teller.\p"
	.string "Shall I read your fortune?$"

HaewenTown_House3_Text_ReadFuture:
	.string "For your future, I see...$"
	@.string "A great battle!\n"
	@.string "The world at stake!\p"
	@.string "A great riddle that has never\n"
	@.string "been solved.\p"
	@.string "Two hearts beset in light and shadow.\p"
	@.string "Which will you choose?\n"
	@.string "That I cannot say.$"

HaewenTown_House3_Text_WorstKarma:
	.string "Ohh! What's this!?\p"
	.string "You have a curse hanging\n"
	.string "over your head!\p"
	.string "A terrible curse such as this can\n"
	.string "only mean certain death!\p"
	.string "You must repent before it is\n"
	.string "too late!$"

HaewenTown_House3_Text_BadKarma:
	.string "Hmmm, I see.\p"
	.string "Well I'll be frank with you, kiddo.\n"
	.string "Your future doesn't look so good.\p"
	.string "What goes around comes around,\n"
	.string "I'm afraid.\p"
	.string "That said, why don't you try doing\n"
	.string "something nice for others?$"

HaewenTown_House3_Text_NeutralBadKarma:
	.string "Hmmm, I see.\p"
	.string "It seems you walk a fine line\n"
	.string "between good and evil.\p"
	.string "Your future is a chaotic mix\n"
	.string "of light and shadow.\p"
	.string "More shadow than light to be\n"
	.string "perfectly honest.$"

HaewenTown_House3_Text_NeutralGoodKarma:
	.string "Hmmm, I see.\p"
	.string "It seems you walk a fine line\n"
	.string "between good and evil.\p"
	.string "Your future is a chaotic mix\n"
	.string "of light and shadow.\p"
	@.string "Which one will you choose?\n"
	@.string "That I cannot say.$"
	.string "More light than shadow to be\n"
	.string "perfectly honestly.$"

HaewenTown_House3_Text_GoodKarma:
	.string "Hmmm, I see.\p"
	.string "You seem like someone who tries\n"
	.string "to do the right thing.\p"
	.string "That's not an easy way to live,\n"
	.string "you know.\p"
	.string "But no good fortune can exist in\n"
	.string "a world without good.\p"
	.string "I predict your fortune will\n"
	.string "change very soon.$"

HaewenTown_House3_Text_BestKarma:
	.string "Oh my, what's this?\p"
	.string "You've been through a long and\n"
	.string "difficult journey, it seems.\p"
	.string "And you still have very far yet\n"
	.string "to go, I'm afraid.\p"
	.string "\p"
	.string "You have a good soul, kiddo.\n"
	.string "And I hate to give good people bad news.\p"
	.string "The future may look bleak sometimes,\n"
	.string "but don't you ever lose hope.\p"
	.string "Good things come to those who wait.$"








