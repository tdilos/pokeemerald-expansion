UndergroundCity_Building1_4F_MapScripts::
	.byte 0

UndergroundCity_Building1_4F_EventScript_Scientist::
	@msgbox UndergroundCity_Building1_4F_Text_CloneAntibodies, MSGBOX_NPC
	msgbox UndergroundCity_Building1_4F_Text_CloneFailsafe, MSGBOX_NPC
	end

@UndergroundCity_Building1_4F_Text_CloneAntibodies:
@	.string "Clones can be dangerous if left unchecked.\n"
@	.string "That's why we invented this.\p"
@	.string "This gas is harmless to us, but reacts with\n"
@	.string "antibodies in the clones.\p"
@	.string "The result is instant total organ failure.\n"
@	.string "A bit extreme, you might think.\p"
@	.string "But strict measures are necessary to ensure\n"
@	.string "the cloned species remain within our control.\p"
@	.string "It would be disasterous to imagine what the\n"
@	.string "clones might do or become in the wild.$"

UndergroundCity_Building1_4F_Text_CloneFailsafe:
	.string "Clones could be dangerous if\n"
	.string "left unchecked.\p"
	.string "That's why we invented a failsafe.\p"
	.string "A carefully engineered flaw in their\n"
	.string "genetic code.\p"
	.string "Our clones regularly receive medication\n"
	.string "to suppress its effects.\p"
	.string "Otherwise, it results in organ failure\n"
	.string "and loss of all biological function.\p"
	.string "A bit extreme, you might think.\p"
	.string "But control for error is important as\n"
	.string "any good scientist knows.$"
	@.string "Letting the clones live freely beyond\n"
	@.string "our control would be disastrous.$"
