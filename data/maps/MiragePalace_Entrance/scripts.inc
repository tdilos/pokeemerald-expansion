MiragePalace_Entrance_MapScripts::
	@map_script MAP_SCRIPT_ON_TRANSITION, MiragePalace_Entrance_OnTransition
	.byte 0

@MiragePalace_Entrance_OnTransition:
@	@setflag FLAG_SYS_INSIDE_MIRAGE_PALACE
@	special EnterMiragePalace
@	end






MiragePalace_EventScript_BraileInscription::
	lockall
	braillemsgbox MiragePalace_Braille_Rhyme
	releaseall
	end

MiragePalace_Entrance_EventScript_Rhyme::
	lockall
	msgbox MiragePalace_Entrance_Text_Rhyme, MSGBOX_SIGN
	releaseall
	end

MiragePalace_Entrance_Text_Rhyme:
	@.string "WHEN THE DAYTELL IS TOLLED\n"
	.string "WHEN THE HOUR IS TOLLED\n"
	.string "FOR THE NINTH TIME TODAY,\p"
	.string "TWENTY STEPS WITHHOLD\n"
	.string "BEFORE TIME SLIPS AWAY.$"



