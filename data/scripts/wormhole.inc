@UltraWormhole_EventScript_DoMapPreview::
@	mappreview 120
@	clearflag FLAG_WORMHOLE_MPS
@	return

@UltraWormhole_EventScript_PauseMusicDuringMPS::
@	playbgm MUS_DUMMY, TRUE
@	clearflag FLAG_WORMHOLE_MPS
@	@delay 120
@	@fadedefaultbgm
@	return

UltraWormhole_EventScript_XCosmopolis::
	lock
	msgbox UltraWormhole_Text_StepInside, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, UltraWormhole_EventScript_Skip
	@setflag FLAG_WORMHOLE_MPS
	warpsilent MAP_STATION_CITY_BUILDING1_B1_HALLWAY, 2, 5
	waitstate
	release
	end

UltraWormhole_EventScript_AlteringCave::
	lock
	msgbox UltraWormhole_Text_StepInside, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, UltraWormhole_EventScript_Skip
	warpsilent MAP_ALTERING_CAVE, 27, 14
	waitstate
	release
	end

UltraWormhole_EventScript_XPelago::
	lock
	msgbox UltraWormhole_Text_StepInside, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, UltraWormhole_EventScript_Skip
	warpsilent MAP_KIYAHA_ISLE_EXTERIOR, 3, 23
	waitstate
	release
	end

UltraWormhole_EventScript_Route109::
	lock
	msgbox UltraWormhole_Text_StepInside, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, UltraWormhole_EventScript_Skip
	warpsilent MAP_ROUTE109, 27, 46
	waitstate
	release
	end

UltraWormhole_EventScript_XHolt::
	lock
	msgbox UltraWormhole_Text_StepInside, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, UltraWormhole_EventScript_Skip
	switch VAR_SEASON
	case 0, UltraWormhole_EventScript_XHolt_Spring
	case 1, UltraWormhole_EventScript_XHolt_Summer
	case 2, UltraWormhole_EventScript_XHolt_Fall
	case 3, UltraWormhole_EventScript_XHolt_Winter
	end

UltraWormhole_EventScript_XHolt_Spring::
	warpsilent MAP_SPRING_FOURFOLD_FOREST_NW, 36, 20
	waitstate
	release
	end

UltraWormhole_EventScript_XHolt_Summer::
	warpsilent MAP_SUMMER_FOURFOLD_FOREST_NW, 36, 20
	waitstate
	release
	end

UltraWormhole_EventScript_XHolt_Fall::
	warpsilent MAP_FALL_FOURFOLD_FOREST_NW, 36, 20
	waitstate
	release
	end

UltraWormhole_EventScript_XHolt_Winter::
	warpsilent MAP_WINTER_FOURFOLD_FOREST_NW, 36, 20
	waitstate
	release
	end

UltraWormhole_EventScript_PetalburgWoods::
	lock
	msgbox UltraWormhole_Text_StepInside, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, UltraWormhole_EventScript_Skip
	warpsilent MAP_PETALBURG_WOODS, 35, 23
	waitstate
	release
	end





UltraWormhole_EventScript_XGreenhouse::
	end

UltraWormhole_EventScript_XStarfield::
UltraWormhole_EventScript_XSlough::
UltraWormhole_EventScript_XWaste::
UltraWormhole_EventScript_XLabyrinth::
UltraWormhole_EventScript_XMindscape::
UltraWormhole_EventScript_XCaldera::
UltraWormhole_EventScript_XJungle::
UltraWormhole_EventScript_XCloud::
UltraWormhole_EventScript_XTundra::
UltraWormhole_EventScript_XMere::
UltraWormhole_EventScript_XRuin::
UltraWormhole_EventScript_XSynestia::
	end

UltraWormhole_EventScript_Skip::
	release
	end

UltraWormhole_Text_StepInside:
	.string "It's a large wormhole.\n"
	.string "Step inside?$"






Wormhole_EventScript_Articuno::
	lock
	msgbox gText_ReachInsideWormhole, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Wormhole_EventScript_Skip
	msgbox gText_PutHandInWormhole, MSGBOX_DEFAULT
	closemessage
	delay 40
	playmoncry SPECIES_ARTICUNO, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_ARTICUNO, 40
	goto Wormhole_EventScript_BattlePokemon
	end

Wormhole_EventScript_Zapdos::
	lock
	msgbox gText_ReachInsideWormhole, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Wormhole_EventScript_Skip
	msgbox gText_PutHandInWormhole, MSGBOX_DEFAULT
	closemessage
	delay 40
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_ZAPDOS, 40
	goto Wormhole_EventScript_BattlePokemon
	end

Wormhole_EventScript_Moltres::
	lock
	msgbox gText_ReachInsideWormhole, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Wormhole_EventScript_Skip
	msgbox gText_PutHandInWormhole, MSGBOX_DEFAULT
	closemessage
	delay 40
	playmoncry SPECIES_MOLTRES, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_MOLTRES, 40
	goto Wormhole_EventScript_BattlePokemon
	end

Wormhole_EventScript_Raikou::
	lock
	msgbox gText_ReachInsideWormhole, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Wormhole_EventScript_Skip
	msgbox gText_PutHandInWormhole, MSGBOX_DEFAULT
	closemessage
	delay 40
	playmoncry SPECIES_RAIKOU, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_RAIKOU, 40
	goto Wormhole_EventScript_BattlePokemon
	end

Wormhole_EventScript_Entei::
	lock
	msgbox gText_ReachInsideWormhole, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Wormhole_EventScript_Skip
	msgbox gText_PutHandInWormhole, MSGBOX_DEFAULT
	closemessage
	delay 40
	playmoncry SPECIES_ENTEI, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_ENTEI, 40
	goto Wormhole_EventScript_BattlePokemon
	end

Wormhole_EventScript_Suicune::
	lock
	msgbox gText_ReachInsideWormhole, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Wormhole_EventScript_Skip
	msgbox gText_PutHandInWormhole, MSGBOX_DEFAULT
	closemessage
	delay 40
	playmoncry SPECIES_SUICUNE, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_SUICUNE, 40 
	goto Wormhole_EventScript_BattlePokemon
	end

Wormhole_EventScript_Regirock::
	lock
	msgbox gText_ReachInsideWormhole, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Wormhole_EventScript_Skip
	msgbox gText_PutHandInWormhole, MSGBOX_DEFAULT
	closemessage
	delay 40
	playmoncry SPECIES_REGIROCK, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_REGIROCK, 40
	goto Wormhole_EventScript_BattlePokemon
	end

Wormhole_EventScript_Regice::
	lock
	msgbox gText_ReachInsideWormhole, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Wormhole_EventScript_Skip
	msgbox gText_PutHandInWormhole, MSGBOX_DEFAULT
	closemessage
	delay 40
	playmoncry SPECIES_REGICE, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_REGICE, 40 
	goto Wormhole_EventScript_BattlePokemon
	end

Wormhole_EventScript_Registeel::
	lock
	msgbox gText_ReachInsideWormhole, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Wormhole_EventScript_Skip
	msgbox gText_PutHandInWormhole, MSGBOX_DEFAULT
	closemessage
	delay 40
	playmoncry SPECIES_REGISTEEL, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_REGISTEEL, 40 
	goto Wormhole_EventScript_BattlePokemon
	end

Wormhole_EventScript_Heatran::
	lock
	msgbox gText_ReachInsideWormhole, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Wormhole_EventScript_Skip
	msgbox gText_PutHandInWormhole, MSGBOX_DEFAULT
	closemessage
	delay 40
	playmoncry SPECIES_HEATRAN, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_HEATRAN, 50
	goto Wormhole_EventScript_BattlePokemon
	end

Wormhole_EventScript_Cresselia::
	lock
	msgbox gText_ReachInsideWormhole, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Wormhole_EventScript_Skip
	msgbox gText_PutHandInWormhole, MSGBOX_DEFAULT
	closemessage
	delay 40
	playmoncry SPECIES_CRESSELIA, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_CRESSELIA, 50
	goto Wormhole_EventScript_BattlePokemon
	end

Wormhole_EventScript_Darkrai::
	lock
	msgbox gText_ReachInsideWormhole, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Wormhole_EventScript_Skip
	msgbox gText_PutHandInWormhole, MSGBOX_DEFAULT
	closemessage
	delay 40
	playmoncry SPECIES_DARKRAI, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_DARKRAI, 50
	goto Wormhole_EventScript_BattlePokemon
	end

Wormhole_EventScript_Cobalion::
	lock
	msgbox gText_ReachInsideWormhole, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Wormhole_EventScript_Skip
	msgbox gText_PutHandInWormhole, MSGBOX_DEFAULT
	closemessage
	delay 40
	playmoncry SPECIES_COBALION, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_COBALION, 40
	goto Wormhole_EventScript_BattlePokemon
	end

Wormhole_EventScript_Virizion::
	lock
	msgbox gText_ReachInsideWormhole, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Wormhole_EventScript_Skip
	msgbox gText_PutHandInWormhole, MSGBOX_DEFAULT
	closemessage
	delay 40
	playmoncry SPECIES_VIRIZION, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_VIRIZION, 40
	goto Wormhole_EventScript_BattlePokemon
	end

Wormhole_EventScript_Terrakion::
	lock
	msgbox gText_ReachInsideWormhole, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Wormhole_EventScript_Skip
	msgbox gText_PutHandInWormhole, MSGBOX_DEFAULT
	closemessage
	delay 40
	playmoncry SPECIES_TERRAKION, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_TERRAKION, 40
	goto Wormhole_EventScript_BattlePokemon
	end

Wormhole_EventScript_Keldeo::
	lock
	msgbox gText_ReachInsideWormhole, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Wormhole_EventScript_Skip
	msgbox gText_PutHandInWormhole, MSGBOX_DEFAULT
	closemessage
	delay 40
	playmoncry SPECIES_KELDEO, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_KELDEO, 40
	goto Wormhole_EventScript_BattlePokemon
	end

Wormhole_EventScript_Reshiram::
	lock
	msgbox gText_ReachInsideWormhole, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Wormhole_EventScript_Skip
	msgbox gText_PutHandInWormhole, MSGBOX_DEFAULT
	closemessage
	delay 40
	playmoncry SPECIES_RESHIRAM, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_RESHIRAM, 60
	goto Wormhole_EventScript_BattlePokemon
	end

Wormhole_EventScript_Zekrom::
	lock
	msgbox gText_ReachInsideWormhole, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Wormhole_EventScript_Skip
	msgbox gText_PutHandInWormhole, MSGBOX_DEFAULT
	closemessage
	delay 40
	playmoncry SPECIES_ZEKROM, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_ZEKROM, 60
	goto Wormhole_EventScript_BattlePokemon
	end

Wormhole_EventScript_Kyurem::
	lock
	msgbox gText_ReachInsideWormhole, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Wormhole_EventScript_Skip
	msgbox gText_PutHandInWormhole, MSGBOX_DEFAULT
	closemessage
	delay 40
	playmoncry SPECIES_KYUREM, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_KYUREM, 60
	goto Wormhole_EventScript_BattlePokemon
	end

Wormhole_EventScript_Xerneas::
	lock
	msgbox gText_ReachInsideWormhole, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Wormhole_EventScript_Skip
	msgbox gText_PutHandInWormhole, MSGBOX_DEFAULT
	closemessage
	delay 40
	playmoncry SPECIES_XERNEAS, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_XERNEAS, 60
	goto Wormhole_EventScript_BattlePokemon
	end

Wormhole_EventScript_Yveltal::
	lock
	msgbox gText_ReachInsideWormhole, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Wormhole_EventScript_Skip
	msgbox gText_PutHandInWormhole, MSGBOX_DEFAULT
	closemessage
	delay 40
	playmoncry SPECIES_YVELTAL, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_YVELTAL, 60
	goto Wormhole_EventScript_BattlePokemon
	end

Wormhole_EventScript_Hoopa::
	lock
	msgbox gText_ReachInsideWormhole, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Wormhole_EventScript_Skip
	msgbox gText_PutHandInWormhole, MSGBOX_DEFAULT
	closemessage
	delay 40
	playmoncry SPECIES_HOOPA, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_HOOPA, 50
	goto Wormhole_EventScript_BattlePokemon
	end

Wormhole_EventScript_Volcanion::
	lock
	msgbox gText_ReachInsideWormhole, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Wormhole_EventScript_Skip
	msgbox gText_PutHandInWormhole, MSGBOX_DEFAULT
	closemessage
	delay 40
	playmoncry SPECIES_VOLCANION, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_VOLCANION, 50
	goto Wormhole_EventScript_BattlePokemon
	end

Wormhole_EventScript_TapuKoko::
	lock
	msgbox gText_ReachInsideWormhole, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Wormhole_EventScript_Skip
	msgbox gText_PutHandInWormhole, MSGBOX_DEFAULT
	closemessage
	delay 40
	playmoncry SPECIES_TAPU_KOKO, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_TAPU_KOKO, 40
	goto Wormhole_EventScript_BattlePokemon
	end

Wormhole_EventScript_TapuLele::
	lock
	msgbox gText_ReachInsideWormhole, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Wormhole_EventScript_Skip
	msgbox gText_PutHandInWormhole, MSGBOX_DEFAULT
	closemessage
	delay 40
	playmoncry SPECIES_TAPU_LELE, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_TAPU_LELE, 40
	goto Wormhole_EventScript_BattlePokemon
	end

Wormhole_EventScript_TapuBulu::
	lock
	msgbox gText_ReachInsideWormhole, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Wormhole_EventScript_Skip
	msgbox gText_PutHandInWormhole, MSGBOX_DEFAULT
	closemessage
	delay 40
	playmoncry SPECIES_TAPU_BULU, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_TAPU_BULU, 40
	goto Wormhole_EventScript_BattlePokemon
	end

Wormhole_EventScript_TapuFini::
	lock
	msgbox gText_ReachInsideWormhole, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Wormhole_EventScript_Skip
	msgbox gText_PutHandInWormhole, MSGBOX_DEFAULT
	closemessage
	delay 40
	playmoncry SPECIES_TAPU_FINI, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_TAPU_FINI, 40
	goto Wormhole_EventScript_BattlePokemon
	end









Wormhole_EventScript_BattlePokemon::
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	@waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Wormhole_EventScript_DefeatedPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Wormhole_EventScript_RanFromPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Wormhole_EventScript_RanFromPokemon
	@setflag FLAG_DEFEATED_REGICE
Wormhole_EventScript_Skip::
	release
	end

Wormhole_EventScript_DefeatedPokemon::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname STR_VAR_1, VAR_0x8004
	msgbox gText_PokemonDisappearedIntoWormhole, MSGBOX_DEFAULT
	release
	end

Wormhole_EventScript_RanFromPokemon::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname STR_VAR_1, VAR_0x8004
	msgbox gText_PokemonDisappearedIntoWormhole, MSGBOX_DEFAULT
	release
	end

gText_ReachInsideWormhole:
	.string "It's a small wormhole.\n"
	.string "Reach inside?$"

gText_PutHandInWormhole:
	.string "{PLAYER} put a hand through\n"
	.string "the wormhole.$"

gText_PokemonDisappearedIntoWormhole:
	.string "The {STR_VAR_1} disappeared back\n"
	.string" through the wormhole!$"



