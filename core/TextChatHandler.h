#pragma once

#include "../pch.h"

#include "../application/GcApplication.h"
#include "../network/GcTextChatInput.h"
#include "../network/GcTextChatManager.h"
#include "../signatures.h"

#define NEWCOMMAND(commandPtr) TextChatHandler::AddCommand(commandPtr)

namespace TextChatHandler
{
	void Init();
	void __fastcall ParseTextForCommandsHook(cGcTextChatInput* _this, const cTkFixedString<1023, char> lMessageText);
	void RegisterStockCommands();
};