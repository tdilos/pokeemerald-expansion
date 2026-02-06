MindaroCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MindaroCity_OnTransition
	.byte 0

MindaroCity_OnTransition:
	setflag FLAG_VISITED_MINDARO_CITY
	end

MindaroCity_EventScript_GymSign::
	msgbox MindaroCity_Text_GymSign, MSGBOX_SIGN
	end

MindaroCity_EventScript_CitySign::
	msgbox MindaroCity_Text_CitySign, MSGBOX_SIGN
	end

MindaroCity_Text_GymSign:
	.string "MINDARO CITY POKéMON GYM\n"
	.string "LEADER: EIRA\l"
	.string "“The snow princess.”$"

MindaroCity_Text_CitySign:
	.string "MINDARO CITY\n"
	.string "“The evergreen city.”$"

MindaroCity_EventScript_DepartmentStoreSign::
	msgbox MindaroCity_Text_DepartmentStoreSign, MSGBOX_SIGN
	end

MindaroCity_Text_DepartmentStoreSign:
	.string "MINDARO DEPARTMENT STORE$"






MindaroCity_EventScript_Breeder::
	lock
	faceplayer
	msgbox MindaroCity_Text_BirdPokemon, MSGBOX_DEFAULT
	release
	end

MindaroCity_Text_BirdPokemon:
	.string "The wind here is strong but gentle.\p"
	.string "It's perfect for bird POKéMON!$"

MindaroCity_EventScript_Pokemon1::
	lock
	faceplayer
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox MindaroCity_Text_Pokemon1, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MindaroCity_Text_Pokemon1:
	.string "WINGULL: Pirii$"

MindaroCity_EventScript_Pokemon2::
	lock
	faceplayer
	playmoncry SPECIES_SPEAROW, CRY_MODE_NORMAL
	msgbox MindaroCity_Text_Pokemon2, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MindaroCity_Text_Pokemon2:
	.string "SPEAROW: Piyu piiyuu$"

MindaroCity_EventScript_Lass::
	msgbox MindaroCity_Text_WaitingOnDate, MSGBOX_NPC
	end

MindaroCity_Text_WaitingOnDate:
	.string "Hmph! I'm supposed to be on a\n"
	.string "romantic tour of the garden.\p"
	.string "But my Prince Charming is late.$"

MindaroCity_EventScript_ParasolLady::
	msgbox MindaroCity_Text_MazeCompetition, MSGBOX_NPC
	end

MindaroCity_Text_MazeCompetition:
	.string "MINDARO GARDENS is a popular\n"
	.string "tourist attraction.\p"
	.string "They're even more popular during\n"
	.string "their annual maze competition.$"

MindaroCity_EventScript_Sailor::
	lock
	msgbox MindaroCity_Text_NotResponding, MSGBOX_DEFAULT
	release
	end

MindaroCity_Text_NotResponding:
	.string "...\p"
	.string "...\p"
	.string "He's focused and unresponsive.$"

MindaroCity_EventScript_OldWoman::
	msgbox MindaroCity_Text_HandsomeBeach, MSGBOX_NPC
	end

MindaroCity_Text_HandsomeBeach:
	.string "Hoho, this beach is great!\p"
	.string "It's full of handsome\n"
	.string "young men.$"

MindaroCity_EventScript_Runner::
	lock
	msgbox MindaroCity_Text_FeelTheBurn, MSGBOX_DEFAULT
	release
	end

MindaroCity_Text_FeelTheBurn:
	.string "Alright, come on.\p"
	.string "That's right.\n"
	.string "Feel the burn!$"

MindaroCity_EventScript_Birdkeeper::
	msgbox MindaroCity_Text_RareFlyingTypes, MSGBOX_NPC
	end

MindaroCity_Text_RareFlyingTypes:
	.string "I heard you could find rare\n"
	.string "FLYING types around here.\p"
	.string "Where could they be?$"



MindaroCity_EventScript_Boarder::
	msgbox MindaroCity_Text_GymLeadersGone, MSGBOX_NPC
	end

MindaroCity_Text_GymLeadersGone:
	.string "Our gym leader's not here right now.\p"
	.string "She went to MINDARO GARDENS to see\n"
	.string "the maze they made this year.\p"
	.string "Boy, is it hot out here...$"

MindaroCity_EventScript_Youngster::
	msgbox MindaroCity_Text_HotDays, MSGBOX_NPC
	end

MindaroCity_Text_HotDays:
	.string "Sometimes on a hot day, I'll sneak into\n"
	.string "EIRA's gym just to cool off.$"


MindaroCity_EventScript_Woman2::
	msgbox MindaroCity_Text_SoManyThingsToBuy, MSGBOX_NPC
	end

MindaroCity_Text_SoMuchToOffer:
	.string "MINDARO CITY has so much to offer!\p"
	.string "Skiing, surfing, shopping.\n$"
	.string "What should I try first?\p"

MindaroCity_EventScript_Camper::
	lock
	faceplayer
	msgbox MindaroCity_Text_UpsAndDowns, MSGBOX_DEFAULT
	release
	end

MindaroCity_Text_UpsAndDowns:
	.string "Life's full of ups and downs.\p"
	.string "It's not always easy, but that's\n"
	.string "no reason to give up.\p"
	.string "Make every challenge a new opportunity.$"

MindaroCity_EventScript_OldMan::
	lock
	faceplayer
	msgbox MindaroCity_Text_WingullDroppings, MSGBOX_DEFAULT
	release
	end

MindaroCity_Text_WingullDroppings:
	.string "Bah!\n"
	.string "WINGULL droppings everywhere.\p"
	.string "Such nasty birds...$"


MindaroCity_EventScript_Artist::
	msgbox MindaroCity_Text_PaintingTheTrees, MSGBOX_NPC
	end

MindaroCity_Text_PaintingTheTrees:
	.string "I'm painting the wildlife here.\n"
	.string "The trees are just gorgeous!$"

MindaroCity_EventScript_Woman::
	msgbox MindaroCity_Text_SoManyThingsToBuy, MSGBOX_NPC
	end

MindaroCity_Text_SoManyThingsToBuy:
	.string "There are so many things to buy\n"
	.string "in this city.\p"
	.string "It's easy to get carried away!$"

MindaroCity_EventScript_LittleBoy::
	lock
	msgbox MindaroCity_Text_IWant, MSGBOX_DEFAULT
	release
	end

MindaroCity_Text_IWant:
	.string "I want a HANAMINDANO!\n"
	.string "I want a HANAMINDANO!$"

MindaroCity_EventScript_HanamidangoSeller::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox MindaroCity_Text_HanamidangoJust200, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MindaroCity_EventScript_DeclineHanamidango
	checkmoney 400
	goto_if_eq VAR_RESULT, FALSE, MindaroCity_EventScript_NotEnoughMoney
	msgbox MindaroCity_Text_ThankYouDear, MSGBOX_DEFAULT
	checkitemspace ITEM_HANAMIDANGO
	call_if_eq VAR_RESULT, TRUE, MindaroCity_EventScript_RemoveMoney
	giveitem ITEM_HANAMIDANGO
	goto_if_eq VAR_RESULT, FALSE, MindaroCity_EventScript_BagIsFull
	hidemoneybox
	release
	end

MindaroCity_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MindaroCity_EventScript_RemoveMoney::
	removemoney 400
	updatemoneybox
	return

MindaroCity_EventScript_DeclineHanamidango::
	msgbox MindaroCity_Text_OhFineThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MindaroCity_EventScript_NotEnoughMoney::
	msgbox MindaroCity_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MindaroCity_Text_HanamidangoJust200:
	.string "Try a HANAMIDANGO.\n"
	.string "It's a local specialty.\p"
	.string "Just ¥400. How about it?$"

MindaroCity_Text_ThankYouDear:
	.string "Here you go, kid.\n"
	.string "Enjoy!$"

MindaroCity_Text_YouveNotGotTheMoney:
	.string "Hey, kid. You can't buy anything\n"
	.string "with that kind of money.$"

MindaroCity_Text_OhFineThen:
	.string "Are you sure? It's the perfect\n"
	.string "treat for a sunny day.$"




MindaroCity_EventScript_IncenseSeller::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MindaroCity_IncenseShop
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MindaroCity_IncenseShop:
	.2byte ITEM_ODD_INCENSE
	.2byte ITEM_ROCK_INCENSE
	.2byte ITEM_ROSE_INCENSE
	.2byte ITEM_SEA_INCENSE
	.2byte ITEM_SILVER_INCENSE
	.2byte ITEM_WAVE_INCENSE
	.2byte ITEM_FULL_INCENSE
	.2byte ITEM_LAX_INCENSE
	.2byte ITEM_PURE_INCENSE
	.2byte ITEM_LUCK_INCENSE
	.2byte ITEM_NONE
	release
	end


