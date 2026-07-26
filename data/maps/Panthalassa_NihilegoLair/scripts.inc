Panthalassa_NihilegoLair_MapScripts::
	.byte 0



Panthalassa_NihilegoLair_EventScript_GreenLock::
	lockall
	msgbox Panthalassa_NihilegoLair_Text_KeySlot, MSGBOX_DEFAULT
	releaseall
	end

Panthalassa_NihilegoLair_EventScript_TealLock::
	lockall
	msgbox Panthalassa_NihilegoLair_Text_KeySlot, MSGBOX_DEFAULT
	releaseall
	end

Panthalassa_NihilegoLair_EventScript_WhiteLock::
	lockall
	msgbox Panthalassa_NihilegoLair_Text_KeySlot, MSGBOX_DEFAULT
	releaseall
	end

Panthalassa_NihilegoLair_EventScript_BlackLock::
	lockall
	msgbox Panthalassa_NihilegoLair_Text_KeySlot, MSGBOX_DEFAULT
	releaseall
	end

Panthalassa_NihilegoLair_Text_KeySlot:
	.string "It looks like a slot for some\n"
	.string "kind of key.$"


