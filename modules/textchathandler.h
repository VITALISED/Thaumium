#pragma once

#include "../pch.h"

#include "../nms/Application/GcApplication.h"
#include "../nms/Network/GcTextChatInput.h"
#include "../nms/Network/GcTextChatManager.h"
#include "../nms/version.h"

#define NEWCOMMAND(commandPtr) TextChatHandler::AddCommand(commandPtr)

namespace TextChatHandler
{
	void Init();
	void __fastcall ParseTextForCommandsHook(cGcTextChatInput* _this, const cTkFixedString<1023, char> lMessageText);
	void RegisterStockCommands();
};