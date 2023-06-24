#pragma once

#include "ChatCommand.h"
#include "hooks.h"
#include "Core.h"

#include "NMS/GcTextChatInput.h"
#include "NMS/GcApplication.h"
#include "NMS/GcTextChatManager.h"

#define NEWCOMMAND(commandPtr) TextChatHandler::AddCommand(commandPtr)

namespace TextChatHandler
{
	void Init();
	void __fastcall ParseTextForCommandsHook(cGcTextChatInput* _this, const cTkFixedString<1023, char> lMessageText);
	void AddCommand(ChatCommand* commandPtr);
	void RegisterStockCommands();
};