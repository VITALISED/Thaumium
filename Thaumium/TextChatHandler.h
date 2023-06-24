#pragma once
#include "pch.h"
#include "hooks.h"
#include "Core.h"

#include "NMS/GcTextChatInput.h"
#include "NMS/GcApplication.h"
#include "NMS/GcTextChatManager.h"

namespace TextChatHandler
{
	void Init();
	bool IsStockCommandHack(std::string* sCheck);
	void __fastcall ParseTextForCommandsHook(cGcTextChatInput* _this, const cTkFixedString<1023, char> lMessageText);
};