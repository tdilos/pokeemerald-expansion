SlateportCity_SternsShipyard_2F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_2F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_2F_Text_ShipDesignMoreLikeBuilding, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_2F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_2F_Text_FloatsBecauseBuoyancy, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_2F_Text_ShipDesignMoreLikeBuilding:
	.string "Designing a large ship is more like\n"
	.string "making a big building than putting\l"
	.string "together a transportation vehicle.$"

SlateportCity_SternsShipyard_2F_Text_FloatsBecauseBuoyancy:
	.string "Don't you think it's strange that\n"
	.string "a ship made of heavy iron floats?\p"
	.string "It floats because of a principle\n"
	.string "called buoyancy.$"










SlateportCity_SternsShipyard_2F_EventScript_SilasEncounter::
	lockall

	setvar VAR_SLATEPORT_CITY_STATE, 5
	releaseall
	end

SlateportCity_SternsShipyard_2F_Text_SilasIntro1:
	.string "?????: Not good!\n"
	.string "I've been discovered.\p"
	.string "Just when I was about to finish\n"
	.string "this copy and make my escape.\p"
	.string "This useless POKéDEX was not\n"
	.string "even worth the effort.\p"
	.string "At least I'll have something\n"
	.string "to show for this.$"
	
SlateportCity_SternsShipyard_2F_Text_SilasIntro2:
	.string "As for you, young CHAMPION.\n"
	.string "You might think you're pretty strong.\p"
	.string "But you're no match for the brains\n"
	.string "of SILAS the SIDEWINDER!\p"
	.string "I'll defeat you right here\n"
	.string "and make my escape!$"

SlateportCity_SternsShipyard_2F_Text_SilasDefeated:
	.string "Fufufufufu...$"

SlateportCity_SternsShipyard_2F_Text_SilasEscapes:
	.string "You think you've won. But the real\n"
	.string "battle was just stalling for time.\p"
	.string "I got everything I wanted here.\p"
	.string "Better luck next time, {PLAYER}.$"


SlateportCity_SternsShipyard_2F_Text_LookerEntrance1:
	.string "So SILAS was working with TEAM AQUA\n"
	.string "after all. And he got away too.$"

SlateportCity_SternsShipyard_2F_Text_LookerEntrance2:
	.string "But don't blame yourself for that.\p"
	.string "He manages to slip out from our grasp\n"
	.string "time and time again.\p"
	.string "The important thing is that the professor\n"
	.string "is safe.\p"
	.string "\p"
	.string "That's his bag, isn't it?$"


SlateportCity_SternsShipyard_2F_Text_LookerEntrance3:
	.string "Come. Let's talk outside.$"


