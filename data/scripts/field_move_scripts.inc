@ Bulldozable sand placeholder script
EventScript_BulldozeSand::
	msgbox Text_CantBulldoze, MSGBOX_DEFAULT
	releaseall
	end

Text_CantBulldoze:
	.string "A mound of sand blocks the way.$"

@ Interact with cuttable tree
EventScript_CutTree::
	lockall
	checkfieldmove FIELD_MOVE_CUT, TRUE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CheckTreeCantCut
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_CUT
	msgbox Text_WantToCut, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelCut
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
EventScript_CutTreeCommon:
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if so
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
<<<<<<< Updated upstream
EventScript_CutTreeDown:: @ fallthrough
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
=======
	goto EventScript_CutTreeDown
	end

@ Use cut from party menu
EventScript_UseCut::
	lockall
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
	goto EventScript_CutTreeDown
	end

EventScript_CutTreeDown::
	addvar VAR_CUT_COUNT, 1
>>>>>>> Stashed changes
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
	waitmovement 0
	removeobject VAR_LAST_TALKED
	special CutWildEncounter
	@goto_if_eq VAR_RESULT, FALSE, EventScript_EndCut
	goto_if_eq VAR_RESULT, FALSE, EventScript_TryCutItem
	waitstate
	releaseall
	end

EventScript_EndCut:
	releaseall
	end

EventScript_TryCutItem::
	special TryGetCutItem
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_EndCut
	giveitem VAR_RESULT
	releaseall
	end

@ Use cut from party menu
EventScript_UseCut::
	lockall
	goto EventScript_CutTreeCommon

Movement_CutTreeDown:
	cut_tree
	step_end

EventScript_CheckTreeCantCut::
	msgbox Text_CantCut, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelCut::
	closemessage
	releaseall
	end

Text_WantToCut:
	.string "This tree looks like it can be\n"
	.string "CUT down!\p"
	.string "Would you like to CUT it?$"

Text_MonUsedFieldMove:
	.string "{STR_VAR_1} used {STR_VAR_2}!$"

Text_CantCut:
	.string "This tree looks like it can be\n"
	.string "CUT down!$"

@ Use rock smash from party menu
EventScript_UseRockSmash::
	lockall
	goto EventScript_RockSmashCommon

@ Interact with smashable rock
EventScript_RockSmash::
	lockall
<<<<<<< Updated upstream
	checkfieldmove FIELD_MOVE_ROCK_SMASH, TRUE
=======
	goto_if_unset FLAG_BADGE02_GET, EventScript_CantSmashRock
	checkpartymove MOVE_ROCK_SMASH
>>>>>>> Stashed changes
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSmashRock
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_ROCK_SMASH
	msgbox Text_WantToSmash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelSmash
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
EventScript_RockSmashCommon:
	@ check if follower should use the field move
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if so
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
<<<<<<< Updated upstream
EventScript_SmashRock:: @ fallthrough
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
=======
	goto EventScript_SmashRock
	end

@ Use rock smash from party menu
EventScript_UseRockSmash::
	lockall
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	goto EventScript_SmashRock
	end

EventScript_SmashRock::
	addvar VAR_ROCK_SMASH_COUNT, 1
>>>>>>> Stashed changes
	applymovement VAR_LAST_TALKED, Movement_SmashRock
	waitmovement 0
	removeobject VAR_LAST_TALKED
	@specialvar VAR_RESULT, TryUpdateRusturfTunnelState
	@goto_if_eq VAR_RESULT, TRUE, EventScript_EndSmash
	special RockSmashWildEncounter
	@goto_if_eq VAR_RESULT, FALSE, EventScript_EndSmash
	goto_if_eq VAR_RESULT, FALSE, EventScript_TryRockSmashItem
	waitstate
	releaseall
	end

<<<<<<< Updated upstream
EventScript_FollowerFieldMove:
	getdirectiontoface VAR_0x8005, OBJ_EVENT_ID_FOLLOWER, OBJ_EVENT_ID_PLAYER
	specialvar VAR_0x8006, GetPlayerFacingDirection
	goto_if_eq VAR_0x8005, DIR_NONE, EventScript_FollowerFieldMoveEnd
	@ Swap follower and player
	call EventScript_FollowerSwap
	@ Face follower in direction and jump
	switch VAR_0x8006
	case DIR_NORTH, EventScript_FollowerJumpNorth
	case DIR_EAST, EventScript_FollowerJumpEast
	case DIR_SOUTH, EventScript_FollowerJumpSouth
	case DIR_WEST, EventScript_FollowerJumpWest
EventScript_FollowerFieldMoveEnd:
	return

EventScript_FollowerSwap:
	switch VAR_0x8005
	case DIR_NORTH, EventScript_FollowerMoveNorth
	case DIR_EAST, EventScript_FollowerMoveEast
	case DIR_SOUTH, EventScript_FollowerMoveSouth
	case DIR_WEST, EventScript_FollowerMoveWest
	return

EventScript_FollowerMoveNorth:
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	return

EventScript_FollowerMoveEast:
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	return

EventScript_FollowerMoveSouth:
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	return

EventScript_FollowerMoveWest:
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	return

EventScript_FollowerJumpNorth:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpUp
	waitmovement 0
	return

EventScript_FollowerJumpEast:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpRight
	waitmovement 0
	return

EventScript_FollowerJumpSouth:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpDown
	waitmovement 0
	return

EventScript_FollowerJumpWest:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpLeft
	waitmovement 0
	return
=======
EventScript_TryRockSmashItem::
	special TryGetRockSmashItem
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_EndSmash
	giveitem VAR_RESULT
	releaseall
	end
>>>>>>> Stashed changes

EventScript_EndSmash::
	releaseall
	end

Movement_WalkUp:
	walk_up
	step_end

Movement_JumpUp:
	jump_in_place_up
	step_end

Movement_WalkRight:
	walk_right
	step_end

Movement_JumpRight:
	jump_in_place_right
	step_end

Movement_WalkDown:
	walk_down
	step_end

Movement_JumpDown:
	jump_in_place_down
	step_end

Movement_WalkLeft:
	walk_left
	step_end

Movement_JumpLeft:
	jump_in_place_left
	step_end

Movement_SmashRock:
	rock_smash_break
	step_end

EventScript_CantSmashRock::
	msgbox Text_CantSmash, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelSmash::
	closemessage
	releaseall
	end

Text_WantToSmash:
	.string "This rock appears to be breakable.\n"
	.string "Would you like to use ROCK SMASH?$"

Text_CantSmash:
	.string "It's a rugged rock, but a POKéMON\n"
	.string "may be able to smash it.$"

@ Interact with meltable ice
EventScript_Thaw::
	lockall
	goto_if_unset FLAG_BADGE04_GET, EventScript_CantThawIce
	checkpartymove MOVE_THAW
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantThawIce
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_THAW
	msgbox Text_WantToThaw, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelThaw
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_THAW
	waitstate
	goto EventScript_ThawIce
	end

@ Use thaw from party menu
EventScript_UseThaw::
	lockall
	dofieldeffect FLDEFF_USE_THAW
	waitstate
	goto EventScript_ThawIce
	end

EventScript_ThawIce::
	addvar VAR_THAW_COUNT, 1
	applymovement VAR_LAST_TALKED, Movement_ThawIce
	waitmovement 0
	removeobject VAR_LAST_TALKED
	special ThawWildEncounter
	@goto_if_eq VAR_RESULT, FALSE, EventScript_EndThaw
	goto_if_eq VAR_RESULT, FALSE, EventScript_TryThawItem
	waitstate
	releaseall
	end

EventScript_EndThaw::
	releaseall
	end

EventScript_TryThawItem::
	special TryGetThawItem
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_EndThaw
	giveitem VAR_RESULT
	releaseall
	end

Movement_ThawIce:
	thaw_ice
	step_end

EventScript_CantThawIce::
	msgbox Text_CantThaw, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelThaw::
	closemessage
	releaseall
	end

Text_WantToThaw:
	.string "This ice appears to be meltable.\n"
	.string "Would you like to use THAW?$"

Text_CantThaw:
	.string "It's a block of ice, but a POKéMON\n"
	.string "may be able to melt it.$"







EventScript_StrengthBoulder::
	lockall
<<<<<<< Updated upstream
=======
	goto_if_unset FLAG_BADGE03_GET, EventScript_CantStrength
>>>>>>> Stashed changes
	goto_if_set FLAG_SYS_USE_STRENGTH, EventScript_CheckActivatedBoulder
	checkfieldmove FIELD_MOVE_STRENGTH, TRUE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantStrength
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_WantToStrength, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelStrength
	closemessage
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_ActivateStrength
	end

EventScript_UseStrength::
	lockall
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_ActivateStrength
	end

EventScript_ActivateStrength::
	setflag FLAG_SYS_USE_STRENGTH
	msgbox Text_MonUsedStrength, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CantStrength::
	msgbox Text_CantStrength, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CheckActivatedBoulder::
	msgbox Text_StrengthActivated, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelStrength::
	closemessage
	releaseall
	end

Text_WantToStrength:
	.string "It's a big boulder, but a POKéMON\n"
	.string "may be able to push it aside.\p"
	.string "Would you like to use STRENGTH?$"

Text_MonUsedStrength:
	.string "{STR_VAR_1} used STRENGTH!\p"
	.string "{STR_VAR_1}'s STRENGTH made it\n"
	.string "possible to move boulders around!$"

Text_CantStrength:
	.string "It's a big boulder, but a POKéMON\n"
	.string "may be able to push it aside.$"

Text_StrengthActivated:
	.string "STRENGTH made it possible to move\n"
	.string "boulders around.$"

EventScript_MagnetRiseMetal::
	lockall
	goto_if_unset FLAG_BADGE07_GET, EventScript_CantMagnetRise
	goto_if_set FLAG_SYS_USE_MAGNET_RISE, EventScript_CheckActivatedMetal
	checkpartymove MOVE_MAGNET_RISE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantMagnetRise
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_WantToMagnetRise, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelMagnetRise
	closemessage
	dofieldeffect FLDEFF_USE_MAGNET_RISE
	waitstate
	goto EventScript_ActivateMagnetRise
	end

EventScript_UseMagnetRise::
	lockall
	dofieldeffect FLDEFF_USE_MAGNET_RISE
	waitstate
	goto EventScript_ActivateMagnetRise
	end

EventScript_ActivateMagnetRise::
	setflag FLAG_SYS_USE_MAGNET_RISE
	msgbox Text_MonUsedMagnetRise, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CantMagnetRise::
	msgbox Text_CantMagnetRise, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CheckActivatedMetal::
	msgbox Text_MagnetRiseActivated, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelMagnetRise::
	closemessage
	releaseall
	end

Text_WantToMagnetRise:
	.string "It's a piece of scrap metal, but\n"
	.string "a POKéMON may be able to move it.\p"
	.string "Would you like to use MAGNET RISE?$"

Text_MonUsedMagnetRise:
	.string "{STR_VAR_1} used MAGNET RISE!\p"
	.string "{STR_VAR_1}'s MAGNET RISE made it\n"
	.string "possible to move metal objects!$"

Text_CantMagnetRise:
	.string "It's a piece of scrap metal, but\n"
	.string "a POKéMON may be able to move it.$"

Text_MagnetRiseActivated:
	.string "MAGNET RISE made it possible\n"
	.string "to move metal objects around.$"







EventScript_UseWaterfall::
	lockall
<<<<<<< Updated upstream
	checkfieldmove FIELD_MOVE_WATERFALL
=======
	goto_if_unset FLAG_IS_CHAMPION, EventScript_CantWaterfall
	checkpartymove MOVE_WATERFALL
>>>>>>> Stashed changes
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantWaterfall
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_WantToWaterfall, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndWaterfall
	msgbox Text_MonUsedWaterfall, MSGBOX_DEFAULT
	hidefollowernpc
	dofieldeffect FLDEFF_USE_WATERFALL
	callnative FollowerNPC_WarpSetEnd
	goto EventScript_EndWaterfall

EventScript_CannotUseWaterfall::
	lockall

EventScript_CantWaterfall::
	msgbox Text_CantWaterfall, MSGBOX_DEFAULT

EventScript_EndWaterfall::
	releaseall
	end

Text_CantWaterfall:
	.string "A wall of water is crashing down with\n"
	.string "a mighty roar.$"

Text_WantToWaterfall:
	.string "It's a large waterfall.\n"
	.string "Would you like to use WATERFALL?$"

Text_MonUsedWaterfall:
	.string "{STR_VAR_1} used WATERFALL.$"

EventScript_UseDive::
	lockall
<<<<<<< Updated upstream
	checkfieldmove FIELD_MOVE_DIVE
=======
	goto_if_unset FLAG_BADGE08_GET, EventScript_CantDive
	checkpartymove MOVE_DIVE
>>>>>>> Stashed changes
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantDive
	copyvar 0x8004 VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	msgbox Text_WantToDive, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndDive
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
	hidefollowernpc
	setfieldeffectargument 0, VAR_0x8004
	setfieldeffectargument 1, 1
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndDive
	end

EventScript_CantDive::
	msgbox Text_CantDive, MSGBOX_DEFAULT
	releaseall
	end

EventScript_EndDive::
	releaseall
	end

EventScript_UseDiveUnderwater::
	lockall
	checkfieldmove FIELD_MOVE_DIVE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSurface
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	msgbox Text_WantToSurface, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_NoSurface
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
	hidefollowernpc
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndSurface
	end

EventScript_CantSurface::
	lockall
	msgbox Text_CantSurface, MSGBOX_DEFAULT
	goto EventScript_EndSurface
	end

EventScript_EndSurface::
	callnative SetFollowerNPCSurfSpriteAfterDive
EventScript_NoSurface::
	releaseall
	end

<<<<<<< Updated upstream
EventScript_DigCommon:
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if true
	dofieldeffect FLDEFF_USE_DIG
	waitstate
EventScript_DigSealedChamber:: @ fallthrough
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
	callnative DoBrailleDigEffect
	releaseall
	end

@ Use Dig from party menu
EventScript_UseDig::
	lockall
	goto EventScript_DigCommon


EventScript_CutGrassCommon:
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if true
	dofieldeffect FLDEFF_USE_CUT_ON_GRASS
	waitstate

@ Use Cut grass from party menu
EventScript_UseCutGrass::
	lockall
	goto EventScript_CutGrassCommon
=======
@ Interact with a tree a Pokémon can use headbutt on
EventScript_Headbutt::
	lockall
	checkpartymove MOVE_HEADBUTT
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_CantHeadbuttTree
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick 0, VAR_RESULT
	buffermovename 1, MOVE_HEADBUTT
	msgbox Text_WantToHeadbutt, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CancelHeadbutt
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_HEADBUTT
	waitstate
	goto EventScript_HeadbuttTree
	end

EventScript_CantHeadbuttTree::
	msgbox Text_CantHeadbuttTree, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelHeadbutt::
	closemessage
	releaseall
	end

@ Use headbutt from party menu
EventScript_UseHeadbutt::
	lockall
	dofieldeffect FLDEFF_USE_HEADBUTT
	waitstate
EventScript_HeadbuttTree:
	addvar VAR_HEADBUTT_COUNT, 1
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	special HeadbuttWildEncounter
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_EndHeadbutt
	waitstate
EventScript_EndHeadbutt:
	releaseall
	end

@ Use defog from party menu
EventScript_UseDefog::
	lockall
	dofieldeffect FLDEFF_USE_DEFOG
	waitstate
	playse SE_M_TWISTER
	setweather WEATHER_NONE
	doweather
	waitse
	releaseall
	end
>>>>>>> Stashed changes

Text_CantDive:
	.string "The sea is deep here. A POKéMON\n"
	.string "may be able to go underwater.$"

Text_WantToDive:
	.string "The sea is deep here.\n"
	.string "Would you like to use DIVE?$"

Text_MonUsedDive:
	.string "{STR_VAR_1} used DIVE.$"

Text_CantSurface:
	.string "Light is filtering down from above.\n"
	.string "A POKéMON may be able to surface.$"

Text_WantToSurface:
	.string "Light is filtering down from above.\n"
	.string "Would you like to use DIVE?$"

Text_WantToHeadbutt:
	.string "It's a moderated sized tree.\n"
	.string "Would you like to use HEADBUTT?$"

Text_CantHeadbuttTree:
	.string "There's a large, formidable tree.\n"
	.string "It looks like it can be headbutted!$"

EventScript_FailSweetScent::
	msgbox Text_FailSweetScent, MSGBOX_SIGN
	end

Text_FailSweetScent:
	.string "Looks like there's nothing here…$"

EventScript_UseDefog::
	lockall
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_DEFOG
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if so
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
	waitmovement 0
	setfieldeffectargument 0, VAR_RESULT
	dofieldeffect FLDEFF_DEFOG
	waitstate
	releaseall
	end

EventScript_UseRockClimb::
	lockall
	checkfieldmove FIELD_MOVE_ROCK_CLIMB
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantRockClimb
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_WantToRockClimb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndRockClimb
	msgbox Text_MonUsedRockClimb, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_ROCK_CLIMB
	waitstate
	goto EventScript_EndRockClimb
	end

EventScript_CantRockClimb::
	msgbox Text_CantRockClimb, MSGBOX_DEFAULT

EventScript_EndRockClimb::
	releaseall
	end

Text_WantToRockClimb:
	.string "The cliff is steep.\n"
	.string "Would you like to use Rock Climb?$"

Text_MonUsedRockClimb:
	.string "{STR_VAR_1} used Rock Climb!$"

Text_CantRockClimb:
	.string "The cliff is steep.\n"
	.string "A Pokémon may be able to climb it.$"
