DuskMountain_VoidMaze_MapScripts::
	.byte 0

DuskMountain_VoidMaze_EventScript_HexManiac::
	lock
	faceplayer
	msgbox DuskMountain_VoidMaze_Text_ExplainVoid, MSGBOX_DEFAULT
	release
	end

DuskMountain_VoidMaze_Text_ExplainVoid:
	.string "This place connects to the “outer world.”\p"
	.string "Look around if you want, but\n"
	.string "don't stray too far...$"



