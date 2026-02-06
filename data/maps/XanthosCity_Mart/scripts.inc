XanthosCity_Mart_MapScripts::
	.byte 0

XanthosCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

XanthosCity_Mart_EventScript_BugCatcher::
	msgbox XanthosCity_Mart_Text_WhatShouldIBuy, MSGBOX_NPC
	end

XanthosCity_Mart_EventScript_Lass::
	msgbox XanthosCity_Mart_Text_DontKnowWhatToBuy, MSGBOX_NPC
	end

XanthosCity_Mart_Text_DontKnowWhatToBuy:
	.string "I never know what to buy when\n"
	.string "I come in here.$"


XanthosCity_Mart_Text_WhatShouldIBuy:
	.string "Hmmm. Should I buy more Antidotes\n"
	.string "or Antibiotics?$"
