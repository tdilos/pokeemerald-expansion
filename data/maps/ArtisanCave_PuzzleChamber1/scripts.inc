ArtisanCave_PuzzleChamber1_MapScripts::
	.byte 0

ArtisanCave_PuzzleChamber1_Puzzle::
	lockall
	msgbox ArtisanCave_Text_BrokenTablet1, MSGBOX_DEFAULT
	closemessage
	goto_if_set FLAG_SOLVED_UNOWN_PUZZLE_1, ArtisanCave_PuzzleChamber1_PuzzleSolved
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, SLIDING_PUZZLE_ANORITH
	setvar VAR_0x8005, FALSE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	goto_if_eq VAR_RESULT, TRUE, ArtisanCave_PuzzleChamber1_SolvePuzzle
	releaseall
	end

ArtisanCave_PuzzleChamber1_SolvePuzzle::
	@ Unlock wild encounters for this chamber
	playse SE_BANG
	waitse
	msgbox ArtisanCave_Text_SomethingHasChanged, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SOLVED_UNOWN_PUZZLE_1
	releaseall
	end

ArtisanCave_Text_SomethingHasChanged:
	.string "Something about this room has changed.$"

ArtisanCave_PuzzleChamber1_PuzzleSolved::
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, SLIDING_PUZZLE_ANORITH
	setvar VAR_0x8005, TRUE
	special DoSlidingPuzzle
	waitstate
	releaseall
	end

ArtisanCave_Text_BrokenTablet1:
	.string "It's a broken tablet.\p"
	.string "“An ancient arthropod that\n"
	.string "roamed the seafloor.”$"




ArtisanCave_PuzzleChamber2_Puzzle::
	lockall
	msgbox ArtisanCave_Text_BrokenTablet2, MSGBOX_DEFAULT
	closemessage
	goto_if_set FLAG_SOLVED_UNOWN_PUZZLE_2, ArtisanCave_PuzzleChamber2_PuzzleSolved
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, SLIDING_PUZZLE_LILEEP
	setvar VAR_0x8005, FALSE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	goto_if_eq VAR_RESULT, TRUE, ArtisanCave_PuzzleChamber2_SolvePuzzle
	releaseall
	end

ArtisanCave_PuzzleChamber2_SolvePuzzle::
	playse SE_BANG
	waitse
	msgbox ArtisanCave_Text_SomethingHasChanged, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SOLVED_UNOWN_PUZZLE_2
	releaseall
	end

ArtisanCave_PuzzleChamber2_PuzzleSolved::
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, SLIDING_PUZZLE_LILEEP
	setvar VAR_0x8005, TRUE
	special DoSlidingPuzzle
	waitstate
	releaseall
	end

ArtisanCave_Text_BrokenTablet2:
	.string "It's a broken tablet.\p"
	.string "“An ancient plant that\n"
	.string "lived on the seafloor.”$"


ArtisanCave_PuzzleChamber3_Puzzle::
	lockall
	msgbox ArtisanCave_Text_BrokenTablet3, MSGBOX_DEFAULT
	closemessage
	goto_if_set FLAG_SOLVED_UNOWN_PUZZLE_3, ArtisanCave_PuzzleChamber3_PuzzleSolved
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, SLIDING_PUZZLE_RELICANTH
	setvar VAR_0x8005, FALSE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	goto_if_eq VAR_RESULT, TRUE, ArtisanCave_PuzzleChamber3_SolvePuzzle
	releaseall
	end

ArtisanCave_PuzzleChamber3_SolvePuzzle::
	playse SE_BANG
	waitse
	msgbox ArtisanCave_Text_SomethingHasChanged, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SOLVED_UNOWN_PUZZLE_3
	releaseall
	end

ArtisanCave_PuzzleChamber3_PuzzleSolved::
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, SLIDING_PUZZLE_RELICANTH
	setvar VAR_0x8005, TRUE
	special DoSlidingPuzzle
	waitstate
	releaseall
	end

ArtisanCave_Text_BrokenTablet3:
	.string "It's a broken tablet.\p"
	.string "“Legends say that its body is\n"
	.string "a cryptic treasure map.”$"



ArtisanCave_PuzzleChamber4_Puzzle::
	lockall
	msgbox ArtisanCave_Text_BrokenTablet4, MSGBOX_DEFAULT
	closemessage
	goto_if_set FLAG_SOLVED_UNOWN_PUZZLE_4, ArtisanCave_PuzzleChamber4_PuzzleSolved
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, SLIDING_PUZZLE_ARCHEOPS
	setvar VAR_0x8005, FALSE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	goto_if_eq VAR_RESULT, TRUE, ArtisanCave_PuzzleChamber4_SolvePuzzle
	releaseall
	end

ArtisanCave_PuzzleChamber4_SolvePuzzle::
	playse SE_BANG
	waitse
	msgbox ArtisanCave_Text_SomethingHasChanged, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SOLVED_UNOWN_PUZZLE_4
	releaseall
	end

ArtisanCave_PuzzleChamber4_PuzzleSolved::
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, SLIDING_PUZZLE_ARCHEOPS
	setvar VAR_0x8005, TRUE
	special DoSlidingPuzzle
	waitstate
	releaseall
	end

ArtisanCave_Text_BrokenTablet4:
	.string "It's a broken tablet.\p"
	.string "“An ancient bird that took flight\n"
	.string "by first getting a running start.”$"



ArtisanCave_PuzzleChamber5_Puzzle::
	lockall
	msgbox ArtisanCave_Text_BrokenTablet5, MSGBOX_DEFAULT
	closemessage
	goto_if_set FLAG_SOLVED_UNOWN_PUZZLE_5, ArtisanCave_PuzzleChamber5_PuzzleSolved
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, SLIDING_PUZZLE_CARRACOSTA
	setvar VAR_0x8005, FALSE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	goto_if_eq VAR_RESULT, TRUE, ArtisanCave_PuzzleChamber5_SolvePuzzle
	releaseall
	end

ArtisanCave_PuzzleChamber5_SolvePuzzle::
	playse SE_BANG
	waitse
	msgbox ArtisanCave_Text_SomethingHasChanged, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SOLVED_UNOWN_PUZZLE_5
	releaseall
	end

ArtisanCave_PuzzleChamber5_PuzzleSolved::
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, SLIDING_PUZZLE_CARRACOSTA
	setvar VAR_0x8005, TRUE
	special DoSlidingPuzzle
	waitstate
	releaseall
	end

ArtisanCave_Text_BrokenTablet5:
	.string "It's a broken tablet.\p"
	.string "“An ancient turtle known for its\n"
	.string "incredible jaw strength.”$"



ArtisanCave_PuzzleChamber6_Puzzle::
	lockall
	msgbox ArtisanCave_Text_BrokenTablet6, MSGBOX_DEFAULT
	closemessage
	goto_if_set FLAG_SOLVED_UNOWN_PUZZLE_6, ArtisanCave_PuzzleChamber6_PuzzleSolved
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, SLIDING_PUZZLE_SIGILYPH
	setvar VAR_0x8005, FALSE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	goto_if_eq VAR_RESULT, TRUE, ArtisanCave_PuzzleChamber6_SolvePuzzle
	releaseall
	end

ArtisanCave_PuzzleChamber6_SolvePuzzle::
	playse SE_BANG
	waitse
	msgbox ArtisanCave_Text_SomethingHasChanged, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SOLVED_UNOWN_PUZZLE_6
	releaseall
	end

ArtisanCave_PuzzleChamber6_PuzzleSolved::
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, SLIDING_PUZZLE_SIGILYPH
	setvar VAR_0x8005, TRUE
	special DoSlidingPuzzle
	waitstate
	releaseall
	end

ArtisanCave_Text_BrokenTablet6:
	.string "It's a broken tablet.\p"
	.string "“The guardians of an ancient city said\n"
	.string "to take flight with their psychic power.”$"




