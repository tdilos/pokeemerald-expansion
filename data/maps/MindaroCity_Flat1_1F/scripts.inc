MindaroCity_Flat1_1F_MapScripts::
	.byte 0

MindaroCity_Flat1_1F_EventScript_Boy::
	msgbox MindaroCity_Flat1_1F_Text_TravelTheWorld, MSGBOX_NPC
	end

MindaroCity_Flat1_1F_Text_TravelTheWorld:
	.string "When I grow up, I want to travel the world\n"
	.string "and write a book about it!$"

MindaroCity_Flat1_1F_EventScript_Woman::
	lock
	faceplayer
	msgbox MindaroCity_Flat1_1F_Text_Bills, MSGBOX_DEFAULT
	release
	end

MindaroCity_Flat1_1F_Text_Bills:
	.string "Rent, food, electricity, taxes...\n"
	.string "All that adds up, you know.\p"
	.string "I have to work two jobs just to make\n"
	.string "ends meet!$"

MindaroCity_Flat1_1F_EventScript_LittleGirl::
	lock
	faceplayer
	msgbox MindaroCity_Flat1_1F_Text_IceSkating, MSGBOX_DEFAULT
	release
	end

MindaroCity_Flat1_1F_Text_IceSkating:
	.string "Sometimes EIRA lets us go ice-skating\n"
	.string "in her gym!$"
