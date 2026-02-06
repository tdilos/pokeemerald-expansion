Route117_PokemonDayCare_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route117_PokemonDayCare_OnTransition
	.byte 0

Route117_PokemonDayCare_OnTransition:
	setflag FLAG_LANDMARK_POKEMON_DAYCARE
	end




Route117_PokemonDayCare_EventScript_Breeder::
	lock
	faceplayer
	goto_if_quest_complete QUEST_16, Route117_PokemonDayCare_EventScript_QuestComplete
	goto_if_quest_active QUEST_16, Route117_PokemonDayCare_EventScript_QuestInProgress
	msgbox Route117_PokemonDayCare_Text_BreederMaster, MSGBOX_DEFAULT
	startquest QUEST_16
	release
	end

Route117_PokemonDayCare_Text_BreederMaster:
	.string "Raising POKéMON isn't easy, but\n"
	.string "it's very rewarding.\p"
	.string "Not everybody can appreciate it though.\p"
	.string "What about you?\p"
	.string "If you can show me you're serious about\n"
	.string "breeding, I'll give you something good.\p"
	.string "Let's see... I think 15 eggs is enough\n"
	.string "to prove you're no novice.$"

Route117_PokemonDayCare_EventScript_QuestInProgress::
	buffernumberstring STR_VAR_3, VAR_EGG_HATCH_COUNT
	goto_if_ge VAR_EGG_HATCH_COUNT, 15, Route117_PokemonDayCare_EventScript_GetReward
	msgbox Route117_PokemonDayCare_Text_NotEnough, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_Text_NotEnough:
	.string "Hmmm. Looks like you've only\n"
	.string "hatched {STR_VAR_3} eggs.\p"
	.string "Keep on working at it!\p"
	.string "You'll be a master one day.$"

Route117_PokemonDayCare_EventScript_GetReward::
	msgbox Route117_PokemonDayCare_Text_YoureSerious, MSGBOX_DEFAULT
	giveitem ITEM_MACHO_BRACE
	msgbox Route117_PokemonDayCare_Text_ExplainMachoBrace, MSGBOX_DEFAULT
	completequest QUEST_16
	release
	end	

Route117_PokemonDayCare_Text_YoureSerious:
	.string "{STR_VAR_3} hatched eggs?\n"
	.string "Not bad. I guess I was right about you.\p"
	.string "Here, I think you'll make good use of this.$"

Route117_PokemonDayCare_EventScript_QuestComplete::
	msgbox Route117_PokemonDayCare_Text_ExplainMachoBrace, MSGBOX_DEFAULT
	release
	end	

Route117_PokemonDayCare_Text_ExplainMachoBrace:
	.string "Give that MACHO BRACE to one\n"
	.string "of your POKéMON to hold.\p"
	.string "That POKéMON will be slower in battle,\n"
	.string "but it will train up twice as fast.\p"
	.string "You're an expert in raising POKéMON,\n"
	.string "so I'm sure you'll make good use of it.$"



