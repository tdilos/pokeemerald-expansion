#ifndef GUARD_CONSTANTS_QUESTS_H
#define GUARD_CONSTANTS_QUESTS_H

//questmenu scripting command params
#define QUEST_MENU_OPEN                 0   //opens the quest menu (questId = 0)
#define QUEST_MENU_UNLOCK_QUEST         1   //questId = QUEST_X (0-indexed)
#define QUEST_MENU_SET_ACTIVE           2   //questId = QUEST_X (0-indexed)
#define QUEST_MENU_SET_REWARD           3   //questId = QUEST_X (0-indexed)
#define QUEST_MENU_COMPLETE_QUEST       4   //questId = QUEST_X (0-indexed)
#define QUEST_MENU_CHECK_UNLOCKED       5   //checks if questId has been unlocked. Returns result to gSpecialVar_Result
#define QUEST_MENU_CHECK_INACTIVE       6 //check if a questID is inactive. Returns result to gSpecialVar_Result
#define QUEST_MENU_CHECK_ACTIVE         7   //checks if questId has been unlocked. Returns result to gSpecialVar_Result
#define QUEST_MENU_CHECK_REWARD         8  //checks if questId is in Reward state. Returns result to gSpecialVar_Result
#define QUEST_MENU_CHECK_COMPLETE       9   //checks if questId has been completed. Returns result to gSpecialVar_Result
#define QUEST_MENU_BUFFER_QUEST_NAME    10   //buffers a quest name to gStringVar1

// quest number defines
#define QUEST_1          0
#define QUEST_2          1
#define QUEST_3          2
#define QUEST_4          3
#define QUEST_5          4
#define QUEST_6          5
#define QUEST_7          6
#define QUEST_8          7
#define QUEST_9          8
#define QUEST_10         9
#define QUEST_11        10
#define QUEST_12        11
#define QUEST_13        12
#define QUEST_14        13
#define QUEST_15        14
#define QUEST_16        15
#define QUEST_17        16
#define QUEST_18        17
#define QUEST_19        18
#define QUEST_20        19
#define QUEST_21        20
#define QUEST_22        21
#define QUEST_23        22
#define QUEST_24        23
#define QUEST_25        24
#define QUEST_26        25
#define QUEST_27        26
#define QUEST_28        27
#define QUEST_29        28
#define QUEST_30        29
#define QUEST_31        30
#define QUEST_32        31
#define QUEST_33        32
#define QUEST_34        33
#define QUEST_35        34
#define QUEST_36        35
#define QUEST_37        36
#define QUEST_38        37
#define QUEST_39        38
#define QUEST_40        39
#define QUEST_41        40
#define QUEST_42        41
#define QUEST_43        42
#define QUEST_44        43

// Postgame
#define QUEST_45        44
#define QUEST_46        45
#define QUEST_47        46
#define QUEST_48        47
#define QUEST_49        48
#define QUEST_50        49

#define QUEST_51        50
#define QUEST_52        51
#define QUEST_53        52
#define QUEST_54        53
#define QUEST_55        54
#define QUEST_56        55
#define QUEST_57        56
#define QUEST_58        57
#define QUEST_59        58
#define QUEST_60        59

#define QUEST_61        60
#define QUEST_62        61
#define QUEST_63        62
#define QUEST_64        63
#define QUEST_65        64
#define QUEST_66        65
#define QUEST_67        66
#define QUEST_68        67
#define QUEST_69        68
#define QUEST_70        69

#define QUEST_71        70
#define QUEST_72        71
#define QUEST_73        72
#define QUEST_74        73
#define QUEST_75        74
#define QUEST_76        75
#define QUEST_77        76
#define QUEST_78        77
#define QUEST_79        78
#define QUEST_80        79

#define QUEST_81        80
#define QUEST_82        81
#define QUEST_83        82
#define QUEST_84        83
#define QUEST_85        84
#define QUEST_86        85
#define QUEST_87        86
#define QUEST_88        87
#define QUEST_89        88
#define QUEST_90        89

#define QUEST_91        90
#define QUEST_92        91
#define QUEST_93        92
#define QUEST_94        93
#define QUEST_95        94
#define QUEST_96        95

#define QUEST_COUNT     (QUEST_96 + 1)

#define SUB_QUEST_1          0
#define SUB_QUEST_2          1
#define SUB_QUEST_3          2
#define SUB_QUEST_4          3
#define SUB_QUEST_5          4
#define SUB_QUEST_6          5
#define SUB_QUEST_7          6
#define SUB_QUEST_8          7
#define SUB_QUEST_9          8
#define SUB_QUEST_10         9
#define SUB_QUEST_11        10
#define SUB_QUEST_12        11
#define SUB_QUEST_13        12
#define SUB_QUEST_14        13
#define SUB_QUEST_15        14
#define SUB_QUEST_16        15
#define SUB_QUEST_17        16
#define SUB_QUEST_18        17
#define SUB_QUEST_19        18
#define SUB_QUEST_20        19
#define SUB_QUEST_21        20
#define SUB_QUEST_22        21
#define SUB_QUEST_23        22
#define SUB_QUEST_24        23
#define SUB_QUEST_25        24
#define SUB_QUEST_26        25
#define SUB_QUEST_27        26
#define SUB_QUEST_28        27
#define SUB_QUEST_29        28
#define SUB_QUEST_30        29

#define QUEST_1_SUB_COUNT 0 //10
#define QUEST_2_SUB_COUNT 0 //20
#define SUB_QUEST_COUNT (QUEST_1_SUB_COUNT + QUEST_2_SUB_COUNT)

#define QUEST_ARRAY_COUNT (SUB_QUEST_COUNT > QUEST_COUNT ? SUB_QUEST_COUNT : QUEST_COUNT)
#endif // GUARD_CONSTANTS_QUESTS_H
