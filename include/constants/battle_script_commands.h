#ifndef GUARD_CONSTANTS_BATTLE_SCRIPT_COMMANDS_H
#define GUARD_CONSTANTS_BATTLE_SCRIPT_COMMANDS_H

enum BattleScriptOpcode
{
    B_SCR_OP_ATTACKCANCELER,
    B_SCR_OP_ACCURACYCHECK,
    B_SCR_OP_PRINTATTACKSTRING,
    B_SCR_OP_PRINTSELECTIONSTRINGFROMTABLE,
    B_SCR_OP_CRITCALC,
    B_SCR_OP_DAMAGECALC,
    B_SCR_OP_TYPECALC,
    B_SCR_OP_MULTIHITRESULTMESSAGE,
    B_SCR_OP_ATTACKANIMATION,
    B_SCR_OP_WAITANIMATION,
    B_SCR_OP_HEALTHBARUPDATE,
    B_SCR_OP_DATAHPUPDATE,
    B_SCR_OP_CRITMESSAGE,
    B_SCR_OP_EFFECTIVENESSSOUND,
    B_SCR_OP_RESULTMESSAGE,
    B_SCR_OP_PRINTSTRING,
    B_SCR_OP_PRINTSELECTIONSTRING,
    B_SCR_OP_WAITMESSAGE,
    B_SCR_OP_PRINTFROMTABLE,
    B_SCR_OP_SETPREATTACKADDITIONALEFFECT,
    B_SCR_OP_SETADDITIONALEFFECTS,
    B_SCR_OP_SETEFFECTPRIMARY,
    B_SCR_OP_SETEFFECTSECONDARY,
    B_SCR_OP_CLEARVOLATILE,
    B_SCR_OP_TRYFAINTMON,
    B_SCR_OP_DOFAINTANIMATION,
    B_SCR_OP_CLEAREFFECTSONFAINT,
    B_SCR_OP_JUMPIFSTATUS,
    B_SCR_OP_JUMPIFVOLATILE,
    B_SCR_OP_JUMPIFABILITY,
    B_SCR_OP_JUMPIFSIDEAFFECTING,
    B_SCR_OP_JUMPIFSTAT,
    B_SCR_OP_JUMPIFSTATIGNORECONTRARY,
    B_SCR_OP_JUMPBASEDONTYPE,
    B_SCR_OP_GETEXP,
    B_SCR_OP_CHECKTEAMSLOST,
    B_SCR_OP_MOVEVALUESCLEANUP,
    B_SCR_OP_SETMULTIHIT,
    B_SCR_OP_DECREMENTMULTIHIT,
    B_SCR_OP_GOTO,
    B_SCR_OP_JUMPIFBYTE,
    B_SCR_OP_JUMPIFHALFWORD,
    B_SCR_OP_JUMPIFWORD,
    B_SCR_OP_JUMPIFARRAYEQUAL,
    B_SCR_OP_JUMPIFARRAYNOTEQUAL,
    B_SCR_OP_SETBYTE,
    B_SCR_OP_ADDBYTE,
    B_SCR_OP_SUBBYTE,
    B_SCR_OP_COPYARRAY,
    B_SCR_OP_COPYARRAYWITHINDEX,
    B_SCR_OP_ORBYTE,
    B_SCR_OP_ORHALFWORD,
    B_SCR_OP_ORWORD,
    B_SCR_OP_BICBYTE,
    B_SCR_OP_BICHALFWORD,
    B_SCR_OP_BICWORD,
    B_SCR_OP_PAUSE,
    B_SCR_OP_WAITSTATE,
    B_SCR_OP_TRYSELFCONFUSIONDMGFORMCHANGE,
    B_SCR_OP_RETURN,
    B_SCR_OP_END,
    B_SCR_OP_END2,
    B_SCR_OP_END3,
    B_SCR_OP_SETCHARGINGTURN,
    B_SCR_OP_CALL,
    B_SCR_OP_SETROOST,
    B_SCR_OP_JUMPIFABILITYPRESENT,
    B_SCR_OP_ENDSELECTIONSCRIPT,
    B_SCR_OP_PLAYANIMATION,
    B_SCR_OP_PLAYANIMATION_VAR,
    B_SCR_OP_JUMPFIFSEMIINVULNERABLE,
    B_SCR_OP_TRAINERSLIDEIN,
    B_SCR_OP_MOVEEND,
    B_SCR_OP_SETHEALBLOCK,
    B_SCR_OP_RETURNATKTOBALL,
    B_SCR_OP_GETSWITCHEDMONDATA,
    B_SCR_OP_SWITCHINDATAUPDATE,
    B_SCR_OP_SWITCHINANIM,
    B_SCR_OP_JUMPIFCANTSWITCH,
    B_SCR_OP_OPENPARTYSCREEN,
    B_SCR_OP_SWITCHHANDLEORDER,
    B_SCR_OP_SWITCHINEFFECTS,
    B_SCR_OP_SWITCHINEVENTS,
    B_SCR_OP_PLAYSE,
    B_SCR_OP_FANFARE,
    B_SCR_OP_PLAYFAINTCRY,
    B_SCR_OP_ENDLINKBATTLE,
    B_SCR_OP_RETURNTOBALL,
    B_SCR_OP_HANDLELEARNNEWMOVE,
    B_SCR_OP_YESNOBOXLEARNMOVE,
    B_SCR_OP_YESNOBOXSTOPLEARNINGMOVE,
    B_SCR_OP_HITANIMATION,
    B_SCR_OP_GETMONEYREWARD,
    B_SCR_OP_UPDATEBATTLERMOVES,
    B_SCR_OP_SWAPATTACKERWITHTARGET,
    B_SCR_OP_INCREMENTGAMESTAT,
    B_SCR_OP_DRAWPARTYSTATUSSUMMARY,
    B_SCR_OP_HIDEPARTYSTATUSSUMMARY,
    B_SCR_OP_JUMPTOCALLEDMOVE,
    B_SCR_OP_STATUSANIMATION,
    B_SCR_OP_FUTURESIGHTTARGETFAILURE,
    B_SCR_OP_GETPOSSIBLENEXTTARGET,
    B_SCR_OP_YESNOBOX,
    B_SCR_OP_CANCELALLACTIONS,
    B_SCR_OP_SETGRAVITY,
    B_SCR_OP_REMOVEITEM,
    B_SCR_OP_ATKNAMEINBUFF1,
    B_SCR_OP_DRAWLVLUPBOX,
    B_SCR_OP_RESETSENTMONSVALUE,
    B_SCR_OP_SETATKTOPLAYER0,
    B_SCR_OP_MAKEVISIBLE,
    B_SCR_OP_RECORDABILITY,
    B_SCR_OP_BUFFERMOVETOLEARN,
    B_SCR_OP_JUMPIFPLAYERRAN,
    B_SCR_OP_HPTHRESHOLDS,
    B_SCR_OP_HPTHRESHOLDS2,
    B_SCR_OP_USEITEMONOPPONENT,
    B_SCR_OP_SETPROTECTLIKE,
    B_SCR_OP_TRYEXPLOSION,
    B_SCR_OP_SETATKHPTOZERO,
    B_SCR_OP_JUMPIFNEXTTARGETVALID,
    B_SCR_OP_TRYHEALHALFHEALTH,
    B_SCR_OP_SETFIELDWEATHER,
    B_SCR_OP_SETREFLECT,
    B_SCR_OP_SETSEEDED,
    B_SCR_OP_MANIPULATEDAMAGE,
    B_SCR_OP_TRYSETREST,
    B_SCR_OP_JUMPIFUPROARWAKES,
    B_SCR_OP_STOCKPILE,
    B_SCR_OP_STOCKPILETOBASEDAMAGE,
    B_SCR_OP_STOCKPILETOHPHEAL,
    B_SCR_OP_STATBUFFCHANGE,
    B_SCR_OP_NORMALISEBUFFS,
    B_SCR_OP_SETBIDE,
    B_SCR_OP_TWOTURNMOVESCHARGESTRINGANDANIMATION,
    B_SCR_OP_TRYNONVOLATILESTATUS,
    B_SCR_OP_INITMULTIHITSTRING,
    B_SCR_OP_FORCERANDOMSWITCH,
    B_SCR_OP_TRYCONVERSIONTYPECHANGE,
    B_SCR_OP_GIVEPAYDAYMONEY,
    B_SCR_OP_SETLIGHTSCREEN,
    B_SCR_OP_TRYKO,
    B_SCR_OP_CHECKNONVOLATILETRIGGER,
    B_SCR_OP_COPYBIDEDMG,
    B_SCR_OP_ANIMATEWILDPOKEMONAFTERFAILEDPOKEBALL,
    B_SCR_OP_TRYINFATUATING,
    B_SCR_OP_UPDATESTATUSICON,
    B_SCR_OP_SETMIST,
    B_SCR_OP_SETFOCUSENERGY,
    B_SCR_OP_TRANSFORMDATAEXECUTION,
    B_SCR_OP_SETSUBSTITUTE,
    B_SCR_OP_MIMICATTACKCOPY,
    B_SCR_OP_SETCALLEDMOVE,
    B_SCR_OP_DISABLELASTUSEDATTACK,
    B_SCR_OP_TRYSETENCORE,
    B_SCR_OP_PAINSPLITDMGCALC,
    B_SCR_OP_SETTYPETORANDOMRESISTANCE,
    B_SCR_OP_SETALWAYSHITFLAG,
    B_SCR_OP_COPYMOVEPERMANENTLY,
    B_SCR_OP_SETTAILWIND,
    B_SCR_OP_TRYSPITEPPREDUCE,
    B_SCR_OP_HEALPARTYSTATUS,
    B_SCR_OP_CURSETARGET,
    B_SCR_OP_TRYSETSPIKES,
    B_SCR_OP_SETVOLATILE,
    B_SCR_OP_TRYSETPERISHSONG,
    B_SCR_OP_JUMPIFCONFUSEDANDSTATMAXED,
    B_SCR_OP_SETEMBARGO,
    B_SCR_OP_PRESENTDAMAGECALCULATION,
    B_SCR_OP_SETSAFEGUARD,
    B_SCR_OP_JUMPIFNOPURSUITSWITCHDMG,
    B_SCR_OP_TRYACTIVATEITEM,
    B_SCR_OP_HALVEHP,
    B_SCR_OP_COPYFOESTATS,
    B_SCR_OP_RAPIDSPINFREE,
    B_SCR_OP_RECOVERBASEDONSUNLIGHT,
    B_SCR_OP_SETSTICKYWEB,
    B_SCR_OP_SELECTFIRSTVALIDTARGET,
    B_SCR_OP_SETFUTUREATTACK,
    B_SCR_OP_TRYDOBEATUP,
    B_SCR_OP_SETSEMIINVULNERABLEBIT,
    B_SCR_OP_TRYMEMENTO,
    B_SCR_OP_SETFORCEDTARGET,
    B_SCR_OP_CURESTATUSWITHMOVE,
    B_SCR_OP_SETTORMENT,
    B_SCR_OP_SETTAUNT,
    B_SCR_OP_TRYSETHELPINGHAND,
    B_SCR_OP_TRYSWAPITEMS,
    B_SCR_OP_TRYCOPYABILITY,
    B_SCR_OP_TRYWISH,
    B_SCR_OP_SETTOXICSPIKES,
    B_SCR_OP_SETGASTROACID,
    B_SCR_OP_SETYAWN,
    B_SCR_OP_SETROOM,
    B_SCR_OP_TRYSWAPABILITIES,
    B_SCR_OP_TRYIMPRISON,
    B_SCR_OP_SETSTEALTHROCK,
    B_SCR_OP_TRYSETVOLATILE,
    B_SCR_OP_TRYSETMAGICCOAT,
    B_SCR_OP_TRYSETSNATCH,
    B_SCR_OP_SWITCHOUTABILITIES,
    B_SCR_OP_JUMPIFHASNOHP,
    B_SCR_OP_PICKUP,
    B_SCR_OP_SETTYPEBASEDHALVERS,
    B_SCR_OP_JUMPIFSUBSTITUTEBLOCKS,
    B_SCR_OP_TRYRECYCLEITEM,
    B_SCR_OP_SETTYPETOENVIRONMENT,
    B_SCR_OP_PURSUITDOUBLES,
    B_SCR_OP_SNATCHSETBATTLERS,
    B_SCR_OP_HANDLEBALLTHROW,
    B_SCR_OP_GIVECAUGHTMON,
    B_SCR_OP_TRYSETCAUGHTMONDEXFLAGS,
    B_SCR_OP_DISPLAYDEXINFO,
    B_SCR_OP_TRYGIVECAUGHTMONNICK,
    B_SCR_OP_SORTBATTLERS,
    B_SCR_OP_REMOVEATTACKERSTATUS1,
    B_SCR_OP_FINISHACTION,
    B_SCR_OP_FINISHTURN,
    B_SCR_OP_TRAINERSLIDEOUT,
    B_SCR_OP_SETTELEKINESIS,
    B_SCR_OP_SWAPSTATSTAGES,
    B_SCR_OP_AVERAGESTATS,
    B_SCR_OP_JUMPIFCAPTIVATEAFFECTED,
    B_SCR_OP_SETNONVOLATILESTATUS,
    B_SCR_OP_TRYOVERWRITEABILITY,
    B_SCR_OP_SETFAIRYDUST,

    // Expansion users, please don't use any of the unused commands.
    // They are reserved for expansion usage.
    // Use callnatives instead.
    B_SCR_OP_UNUSED_1,
    B_SCR_OP_UNUSED_2,
    B_SCR_OP_UNUSED_3,
    B_SCR_OP_UNUSED_4,
    B_SCR_OP_UNUSED_5,
    B_SCR_OP_UNUSED_6,
    B_SCR_OP_UNUSED_7,
    B_SCR_OP_UNUSED_8,
    B_SCR_OP_UNUSED_9,
    B_SCR_OP_UNUSED_10,
    B_SCR_OP_UNUSED_11,
    B_SCR_OP_UNUSED_12,
    B_SCR_OP_UNUSED_13,
    B_SCR_OP_UNUSED_14,
    B_SCR_OP_UNUSED_15,
    B_SCR_OP_UNUSED_16,
    B_SCR_OP_UNUSED_17,
    B_SCR_OP_UNUSED_18,
    B_SCR_OP_UNUSED_19,
    B_SCR_OP_UNUSED_20,
    B_SCR_OP_UNUSED_21,
    B_SCR_OP_UNUSED_22,
    B_SCR_OP_UNUSED_23,
    B_SCR_OP_UNUSED_24,
    B_SCR_OP_UNUSED_25,
    B_SCR_OP_UNUSED_26,
    B_SCR_OP_UNUSED_27,
    B_SCR_OP_UNUSED_28,
    B_SCR_OP_UNUSED_29,
    B_SCR_OP_UNUSED_30,
    B_SCR_OP_CALLNATIVE,
};

// The following correspond to the struct members of BattleScripting by adding their offset
#define sUNUSED_0x00                 (gBattleScripting + 0x00) // unused_0x00
#define sUNUSED_0x04                 (gBattleScripting + 0x04) // unused_0x04
#define sMULTIHIT_STRING             (gBattleScripting + 0x08) // multihitString
#define sEXP_CATCH                   (gBattleScripting + 0x0E) // expOnCatch
#define sUNUSED                      (gBattleScripting + 0x0F) // unused
#define sB_ANIM_ARG1                 (gBattleScripting + 0x10) // animArg1
#define sB_ANIM_ARG2                 (gBattleScripting + 0x11) // animArg2
#define sSAVED_STRINID               (gBattleScripting + 0x12) // savedStringId
#define sMOVEEND_STATE               (gBattleScripting + 0x14) // moveendState
#define sSAVED_STAT_CHANGER          (gBattleScripting + 0x15) // savedStatChanger
#define sSHIFT_SWITCHED              (gBattleScripting + 0x16) // shiftSwitched
#define sBATTLER                     (gBattleScripting + 0x17) // battler
#define sB_ANIM_TURN                 (gBattleScripting + 0x18) // animTurn
#define sB_ANIM_TARGETS_HIT          (gBattleScripting + 0x19) // animTargetsHit
#define sSTATCHANGER                 (gBattleScripting + 0x1A) // statChanger
#define sSTAT_ANIM_PLAYED            (gBattleScripting + 0x1B) // statAnimPlayed
#define sGIVEEXP_STATE               (gBattleScripting + 0x1C) // getexpState
#define sBATTLE_STYLE                (gBattleScripting + 0x1D) // battleStyle
#define sLVLBOX_STATE                (gBattleScripting + 0x1E) // drawlvlupboxState
#define sLEARNMOVE_STATE             (gBattleScripting + 0x1F) // learnMoveState
#define sSAVED_BATTLER               (gBattleScripting + 0x20) // savedBattler
#define sRESHOW_MAIN_STATE           (gBattleScripting + 0x21) // reshowMainState
#define sRESHOW_HELPER_STATE         (gBattleScripting + 0x22) // reshowHelperState
#define sLVLUP_HP                    (gBattleScripting + 0x23) // levelUpHP
#define sWINDOWS_TYPE                (gBattleScripting + 0x24) // windowsType
#define sMULTIPLAYER_ID              (gBattleScripting + 0x25) // multiplayerId
#define sSPECIAL_TRAINER_BATTLE_TYPE (gBattleScripting + 0x26) // specialTrainerBattleType
#define sMON_CAUGHT                  (gBattleScripting + 0x27) // monCaught
#define sSAVED_DMG                   (gBattleScripting + 0x28) // savedDmg
#define sUNUSED_0x2C                 (gBattleScripting + 0x2C) // unused_0x2c
#define sMOVE_EFFECT                 (gBattleScripting + 0x2E) // moveEffect
#define sUNUSED_0x30                 (gBattleScripting + 0x30) // unused_0x30
#define sILLUSION_NICK_HACK          (gBattleScripting + 0x32) // illusionNickHack
#define sFIXED_ABILITY_POPUP         (gBattleScripting + 0x33) // fixedPopup
#define sABILITY_OVERWRITE           (gBattleScripting + 0x34) // abilityPopupOverwrite
#define sSWITCH_CASE                 (gBattleScripting + 0x36) // switchCase
#define sBERRY_OVERRIDE              (gBattleScripting + 0x37) // overrideBerryRequirements
#define sSTICKY_WEB_STAT_DROP        (gBattleScripting + 0x38) // stickyWebStatDrop

// Array entries for battle communication
#define MULTIUSE_STATE          0
#define CURSOR_POSITION         1
#define TASK_ID                 1 // task Id and cursor position share the same field
#define SPRITES_INIT_STATE1     1 // shares the Id as well
#define SPRITES_INIT_STATE2     2
#define MOVE_EFFECT_BYTE        3
#define ACTIONS_CONFIRMED_COUNT 4
#define MULTISTRING_CHOOSER     5
#define MISS_TYPE               6
#define MSG_DISPLAY             7
#define BATTLE_COMMUNICATION_ENTRIES_COUNT  8

#define cMULTISTRING_CHOOSER (gBattleCommunication + MULTISTRING_CHOOSER)
#define cMISS_TYPE           (gBattleCommunication + MISS_TYPE)

// Battle Script defines for getting the wanted battler
#define BS_TARGET                   0
#define BS_ATTACKER                 1
#define BS_EFFECT_BATTLER           2
#define BS_FAINTED                  3
#define BS_ATTACKER_WITH_PARTNER    4 // for Cmd_updatestatusicon
#define BS_FAINTED_MULTIPLE_1       5 // for openpartyscreen
#define BS_FAINTED_MULTIPLE_2       6 // for openpartyscreen
#define BS_BATTLER_0                7
#define BS_ATTACKER_SIDE            8 // for Cmd_jumpifability
#define BS_TARGET_SIDE              9 // for Cmd_jumpifability
#define BS_SCRIPTING                10
#define BS_PLAYER1                  11
#define BS_OPPONENT1                12
#define BS_PLAYER2                  13 // for Cmd_updatestatusicon
#define BS_OPPONENT2                14
#define BS_ABILITY_BATTLER          15
#define BS_ATTACKER_PARTNER         16

// compare operands
#define CMP_EQUAL               0
#define CMP_NOT_EQUAL           1
#define CMP_GREATER_THAN        2
#define CMP_LESS_THAN           3
#define CMP_COMMON_BITS         4
#define CMP_NO_COMMON_BITS      5

// Veriouses have been deprecated but the enum and function will be supported for one more release cycle
enum CmdVarious
{
    VARIOUS_NONE,
};
/*
// Cmd_various
#define VARIOUS_CANCEL_MULTI_TURN_MOVES             0
#define VARIOUS_SET_MAGIC_COAT_TARGET               1
#define VARIOUS_IS_RUNNING_IMPOSSIBLE               2
#define VARIOUS_GET_MOVE_TARGET                     3
#define VARIOUS_GET_BATTLER_FAINTED                 4
#define VARIOUS_RESET_SWITCH_IN_ABILITY_BITS        5
#define VARIOUS_UPDATE_CHOICE_MOVE_ON_LVL_UP        6
#define VARIOUS_RESET_PLAYER_FAINTED                7
#define VARIOUS_PALACE_FLAVOR_TEXT                  8
#define VARIOUS_ARENA_JUDGMENT_WINDOW               9
#define VARIOUS_ARENA_OPPONENT_MON_LOST             10
#define VARIOUS_ARENA_PLAYER_MON_LOST               11
#define VARIOUS_ARENA_BOTH_MONS_LOST                12
#define VARIOUS_EMIT_YESNOBOX                       13
#define VARIOUS_DRAW_ARENA_REF_TEXT_BOX             14
#define VARIOUS_ERASE_ARENA_REF_TEXT_BOX            15
#define VARIOUS_ARENA_JUDGMENT_STRING               16
#define VARIOUS_ARENA_WAIT_STRING                   17
#define VARIOUS_WAIT_CRY                            18
#define VARIOUS_RETURN_OPPONENT_MON1                19
#define VARIOUS_RETURN_OPPONENT_MON2                20
#define VARIOUS_VOLUME_DOWN                         21
#define VARIOUS_VOLUME_UP                           22
#define VARIOUS_SET_ALREADY_STATUS_MOVE_ATTEMPT     23
#define VARIOUS_PALACE_TRY_ESCAPE_STATUS            24
#define VARIOUS_SET_TELEPORT_OUTCOME                25
#define VARIOUS_PLAY_TRAINER_DEFEATED_MUSIC         26
#define VARIOUS_STAT_TEXT_BUFFER                    27
#define VARIOUS_SWITCHIN_ABILITIES                  28
#define VARIOUS_SAVE_TARGET                         29
#define VARIOUS_RESTORE_TARGET                      30
#define VARIOUS_INSTANT_HP_DROP                     31
#define VARIOUS_CLEAR_STATUS                        32
#define VARIOUS_RESTORE_PP                          33
#define VARIOUS_TRY_ACTIVATE_MOXIE                  34
#define VARIOUS_TRY_ACTIVATE_FELL_STINGER           35
#define VARIOUS_PLAY_MOVE_ANIMATION                 36
#define VARIOUS_SET_LUCKY_CHANT                     37
#define VARIOUS_SUCKER_PUNCH_CHECK                  38
#define VARIOUS_SET_SIMPLE_BEAM                     39
#define VARIOUS_TRY_ENTRAINMENT                     40
#define VARIOUS_SET_LAST_USED_ABILITY               41
#define VARIOUS_TRY_HEAL_PULSE                      42
#define VARIOUS_TRY_QUASH                           43
#define VARIOUS_INVERT_STAT_STAGES                  44
#define VARIOUS_SET_TERRAIN                         45
#define VARIOUS_TRY_ME_FIRST                        46
#define VARIOUS_JUMP_IF_BATTLE_END                  47
#define VARIOUS_TRY_ELECTRIFY                       48
#define VARIOUS_TRY_REFLECT_TYPE                    49
#define VARIOUS_TRY_SOAK                            50
#define VARIOUS_HANDLE_MEGA_EVO                     51
#define VARIOUS_TRY_LAST_RESORT                     52
#define VARIOUS_ARGUMENT_STATUS_EFFECT              53
#define VARIOUS_TRY_HIT_SWITCH_TARGET               54
#define VARIOUS_TRY_AUTOTOMIZE                      55
#define VARIOUS_TRY_COPYCAT                         56
#define VARIOUS_ABILITY_POPUP                       57
#define VARIOUS_DEFOG                               58
#define VARIOUS_JUMP_IF_TARGET_ALLY                 59
#define VARIOUS_TRY_SYNCHRONOISE                    60
#define VARIOUS_PSYCHO_SHIFT                        61
#define VARIOUS_CURE_STATUS                         62
#define VARIOUS_POWER_TRICK                         63
#define VARIOUS_AFTER_YOU                           64
#define VARIOUS_BESTOW                              65
#define VARIOUS_ARGUMENT_TO_MOVE_EFFECT             66
#define VARIOUS_JUMP_IF_NOT_GROUNDED                67
#define VARIOUS_HANDLE_TRAINER_SLIDE_MSG            68
#define VARIOUS_TRY_TRAINER_SLIDE_MSG_FIRST_OFF     69
#define VARIOUS_TRY_TRAINER_SLIDE_MSG_LAST_ON       70
#define VARIOUS_SET_AURORA_VEIL                     71
#define VARIOUS_TRY_THIRD_TYPE                      72
#define VARIOUS_ACUPRESSURE                         73
#define VARIOUS_SET_POWDER                          74
#define VARIOUS_SPECTRAL_THIEF                      75
#define VARIOUS_GRAVITY_ON_AIRBORNE_MONS            76
#define VARIOUS_CHECK_IF_GRASSY_TERRAIN_HEALS       77
#define VARIOUS_JUMP_IF_ROAR_FAILS                  78
#define VARIOUS_TRY_INSTRUCT                        79
#define VARIOUS_JUMP_IF_NOT_BERRY                   80
#define VARIOUS_TRACE_ABILITY                       81
#define VARIOUS_UPDATE_NICK                         82
#define VARIOUS_TRY_ILLUSION_OFF                    83
#define VARIOUS_SET_SPRITEIGNORE0HP                 84
#define VARIOUS_HANDLE_FORM_CHANGE                  85
#define VARIOUS_GET_STAT_VALUE                      86
#define VARIOUS_JUMP_IF_FULL_HP                     87
#define VARIOUS_LOSE_TYPE                           88
#define VARIOUS_TRY_ACTIVATE_SOULHEART              89
#define VARIOUS_TRY_ACTIVATE_RECEIVER               90
#define VARIOUS_TRY_ACTIVATE_BEAST_BOOST            91
#define VARIOUS_TRY_FRISK                           92
#define VARIOUS_JUMP_IF_SHIELDS_DOWN_PROTECTED      93
#define VARIOUS_TRY_FAIRY_LOCK                      94
#define VARIOUS_JUMP_IF_NO_ALLY                     95
#define VARIOUS_POISON_TYPE_IMMUNITY                96
#define VARIOUS_JUMP_IF_NO_HOLD_EFFECT              97
#define VARIOUS_INFATUATE_WITH_BATTLER              98
#define VARIOUS_SET_LAST_USED_ITEM                  99
#define VARIOUS_PARALYZE_TYPE_IMMUNITY              100
#define VARIOUS_JUMP_IF_ABSENT                      101
#define VARIOUS_DESTROY_ABILITY_POPUP               102
#define VARIOUS_TOTEM_BOOST                         103
#define VARIOUS_TRY_ACTIVATE_GRIM_NEIGH             104
#define VARIOUS_MOVEEND_ITEM_EFFECTS                105
#define VARIOUS_TERRAIN_SEED                        106
#define VARIOUS_MAKE_INVISIBLE                      107
#define VARIOUS_ROOM_SERVICE                        108
#define VARIOUS_JUMP_IF_TERRAIN_AFFECTED            109
#define VARIOUS_EERIE_SPELL_PP_REDUCE               110
#define VARIOUS_JUMP_IF_TEAM_HEALTHY                111
#define VARIOUS_TRY_HEAL_QUARTER_HP                 112
#define VARIOUS_REMOVE_TERRAIN                      113
#define VARIOUS_JUMP_IF_PRANKSTER_BLOCKED           114
#define VARIOUS_TRY_TO_CLEAR_PRIMAL_WEATHER         115
#define VARIOUS_GET_ROTOTILLER_TARGETS              116
#define VARIOUS_JUMP_IF_NOT_ROTOTILLER_AFFECTED     117
#define VARIOUS_TRY_ACTIVATE_BATTLE_BOND            118
#define VARIOUS_CONSUME_BERRY                       119
#define VARIOUS_JUMP_IF_CANT_REVERT_TO_PRIMAL       120
#define VARIOUS_HANDLE_PRIMAL_REVERSION             121
#define VARIOUS_APPLY_PLASMA_FISTS                  122
#define VARIOUS_JUMP_IF_SPECIES                     123
#define VARIOUS_UPDATE_ABILITY_POPUP                124
#define VARIOUS_JUMP_IF_WEATHER_AFFECTED            125
#define VARIOUS_JUMP_IF_LEAF_GUARD_PROTECTED        126
#define VARIOUS_SET_ATTACKER_STICKY_WEB_USER        127
#define VARIOUS_PHOTON_GEYSER_CHECK                 128
#define VARIOUS_SHELL_SIDE_ARM_CHECK                129
#define VARIOUS_TRY_NO_RETREAT                      130
#define VARIOUS_TRY_TAR_SHOT                        131
#define VARIOUS_CAN_TAR_SHOT_WORK                   132
#define VARIOUS_CHECK_POLTERGEIST                   133
#define VARIOUS_SET_OCTOLOCK                        134
#define VARIOUS_CUT_1_3_HP_RAISE_STATS              135
#define VARIOUS_TRY_END_NEUTRALIZING_GAS            136
#define VARIOUS_JUMP_IF_UNDER_200                   137
#define VARIOUS_SET_SKY_DROP                        138
#define VARIOUS_CLEAR_SKY_DROP                      139
#define VARIOUS_SKY_DROP_YAWN                       140
#define VARIOUS_JUMP_IF_CANT_FLING                  141
#define VARIOUS_JUMP_IF_HOLD_EFFECT                 142
#define VARIOUS_CURE_CERTAIN_STATUSES               143
#define VARIOUS_TRY_RESET_NEGATIVE_STAT_STAGES      144
#define VARIOUS_JUMP_IF_LAST_USED_ITEM_BERRY        145
#define VARIOUS_JUMP_IF_LAST_USED_ITEM_HOLD_EFFECT  146
#define VARIOUS_SAVE_BATTLER_ITEM                   147
#define VARIOUS_RESTORE_BATTLER_ITEM                148
#define VARIOUS_BATTLER_ITEM_TO_LAST_USED_ITEM      149
#define VARIOUS_SET_BEAK_BLAST                      150
#define VARIOUS_SWAP_SIDE_STATUSES                  151
#define VARIOUS_SET_Z_EFFECT                        152
#define VARIOUS_TRY_SYMBIOSIS                       153
#define VARIOUS_CAN_TELEPORT                        154
#define VARIOUS_GET_BATTLER_SIDE                    155
#define VARIOUS_CHECK_PARENTAL_BOND_COUNTER         156
#define VARIOUS_SWAP_STATS                          157
#define VARIOUS_JUMP_IF_ROD                         158
#define VARIOUS_JUMP_IF_ABSORB                      159
#define VARIOUS_JUMP_IF_MOTOR                       160
#define VARIOUS_TEATIME_INVUL                       161
#define VARIOUS_TEATIME_TARGETS                     162
#define VARIOUS_TRY_WIND_RIDER_POWER                163
#define VARIOUS_ACTIVATE_WEATHER_CHANGE_ABILITIES   164
#define VARIOUS_ACTIVATE_TERRAIN_CHANGE_ABILITIES   165
#define VARIOUS_JUMP_IF_EMERGENCY_EXITED            166
#define VARIOUS_STORE_HEALING_WISH                  167
#define VARIOUS_HIT_SWITCH_TARGET_FAILED            168
#define VARIOUS_JUMP_IF_SHELL_TRAP                  169
#define VARIOUS_TRY_SKIP_RECHARGE                   170
#define VARIOUS_SETACIDRAIN                         171
#define VARIOUS_SETFULLMOON                         172
#define VARIOUS_TRY_PETRIFY                         173
#define VARIOUS_CHITINIZE                           174
*/

// Cmd_manipulatedamage
#define DMG_1_8_TARGET_HP       0 // Used by bad dreams

// Cmd_jumpifcantswitch
#define SWITCH_IGNORE_ESCAPE_PREVENTION   (1 << 7)

// Cmd_statbuffchange
#define STAT_CHANGE_ALLOW_PTR               (1 << 0)   // If set, allow use of jumpptr. If not set and unable to raise/lower stats, jump to failInstr.
#define STAT_CHANGE_MIRROR_ARMOR            (1 << 1)   // Stat change redirection caused by Mirror Armor ability.
#define STAT_CHANGE_ONLY_CHECKING           (1 << 2)   // Checks if the stat change can occur. Does not change stats or play stat change animation.
#define STAT_CHANGE_NOT_PROTECT_AFFECTED    (1 << 3)
#define STAT_CHANGE_UPDATE_MOVE_EFFECT      (1 << 4)
#define STAT_CHANGE_CHECK_PREVENTION        (1 << 5)
#define STAT_CHANGE_CERTAIN                 (1 << 6)

// stat flags for TryPlayStatChangeAnimation
#define BIT_HP                      (1 << 0)
#define BIT_ATK                     (1 << 1)
#define BIT_DEF                     (1 << 2)
#define BIT_SPEED                   (1 << 3)
#define BIT_SPATK                   (1 << 4)
#define BIT_SPDEF                   (1 << 5)
#define BIT_ACC                     (1 << 6)
#define BIT_EVASION                 (1 << 7)

#define PARTY_SCREEN_OPTIONAL (1 << 7) // Flag for first argument to openpartyscreen

enum SetMoveEffectFlags
{
    NO_FLAGS          = 0,
    EFFECT_PRIMARY    = (1 << 0),
    EFFECT_CERTAIN    = (1 << 1),
};

enum FaintBlockStates
{
    FAINT_BLOCK_FINAL_GAMBIT,
    FAINT_BLOCK_CHECK_TARGET_FAINTED, // Exits if target is not fainted
    FAINT_BLOCK_END_NEUTRALIZING_GAS,
    // Destiny Bond and Grudge are tested first, but Faint Target's script plays first
    FAINT_BLOCK_TRY_DESTINY_BOND,
    FAINT_BLOCK_TRY_GRUDGE,
    FAINT_BLOCK_FAINT_TARGET,
    FAINT_BLOCK_DO_DESTINY_BOND,
    FAINT_BLOCK_DO_GRUDGE,
    FAINT_BLOCK_COUNT,
};
/*
// cases for Cmd_moveend
#define MOVEEND_SUM_DAMAGE                        0
#define MOVEEND_PROTECT_LIKE_EFFECT               1
#define MOVEEND_RAGE                              2
#define MOVEEND_SYNCHRONIZE_TARGET                3
#define MOVEEND_ABILITIES                         4
#define MOVEEND_ABILITIES_ATTACKER                5
#define MOVEEND_STATUS_IMMUNITY_ABILITIES         6
#define MOVEEND_SYNCHRONIZE_ATTACKER              7
#define MOVEEND_CHOICE_MOVE                       8
#define MOVEEND_ATTACKER_INVISIBLE                9
#define MOVEEND_ATTACKER_VISIBLE                  10
#define MOVEEND_TARGET_VISIBLE                    11
#define MOVEEND_ITEM_EFFECTS_TARGET               12
#define MOVEEND_ITEM_EFFECTS_ALL                  13
#define MOVEEND_KINGSROCK                         14    // These item effects will occur each strike of a multi-hit move
#define MOVEEND_SUBSTITUTE                        15
#define MOVEEND_SKY_DROP_CONFUSE                  16
#define MOVEEND_UPDATE_LAST_MOVES                 17
#define MOVEEND_MIRROR_MOVE                       18
#define MOVEEND_NEXT_TARGET                       19   // Everything up until here is handled for each strike of a multi-hit move
#define MOVEEND_MULTIHIT_MOVE                     20
#define MOVEEND_DEFROST                           21
#define MOVEEND_MOVE_EFFECTS2                     22
#define MOVEEND_RECOIL                            23
#define MOVEEND_MAGICIAN                          24    // Occurs after final multi-hit strike, and after other items/abilities would activate
#define MOVEEND_EJECT_BUTTON                      25
#define MOVEEND_RED_CARD                          26
#define MOVEEND_EJECT_PACK                        27
#define MOVEEND_LIFEORB_SHELLBELL                 28    // Includes shell bell, throat spray, etc
#define MOVEEND_CHANGED_ITEMS                     29
#define MOVEEND_PICKPOCKET                        30
#define MOVEEND_DANCER                            31
#define MOVEEND_EMERGENCY_EXIT                    32
#define MOVEEND_WEATHER_FORM                      33
#define MOVEEND_SYMBIOSIS                         34
#define MOVEEND_EXHAUST_PP_DROP                   35
#define MOVEEND_INFECT_HP_DROP                    36
#define MOVEEND_CLEAR_BITS                        37
#define MOVEEND_COUNT                             38
*/

enum SwitchInCases
{
    B_SWITCH_NORMAL,
    B_SWITCH_HIT, // dragon tail, circle throw
    B_SWITCH_RED_CARD,
};

enum StatusTrigger
{
    TRIGGER_ON_MOVE,
    TRIGGER_ON_ABILITY,
    TRIGGER_ON_PROTECT,
};

enum TriggerOnFieldStatus
{
    ON_ANY,
    ON_TERRAIN,
    ON_WEATHER,
};

enum HealthUpdate
{
    PASSIVE_HP_UPDATE,
    MOVE_DAMAGE_HP_UPDATE,
};

#endif // GUARD_CONSTANTS_BATTLE_SCRIPT_COMMANDS_H
