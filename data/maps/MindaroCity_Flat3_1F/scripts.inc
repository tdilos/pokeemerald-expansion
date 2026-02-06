MindaroCity_Flat3_1F_MapScripts::
	.byte 0

MindaroCity_Flat3_1F_EventScript_OldMan::
	msgbox MindaroCity_Flat3_1F_Text_PrinceOfTheSea, MSGBOX_NPC
	end

MindaroCity_Flat3_1F_Text_PrinceOfTheSea:
	.string "That island's underwater now.\p"
	.string "But the prince is still there,\n"
	.string "I'm sure of it!$"

MindaroCity_Flat3_1F_EventScript_Lass::
	lock
	faceplayer
	msgbox MindaroCity_Flat3_1F_Text_Grandpa, MSGBOX_DEFAULT
	release
	end

MindaroCity_Flat3_1F_Text_Grandpa:
	.string "My grandpa used to be a sailor.\p"
	.string "He always tells this story about how he\n"
	.string "met the prince of the sea once.\p"
	.string "I think he might be going senile...$"


