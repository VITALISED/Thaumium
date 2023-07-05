#pragma once

#include "../util/hooks.h"
#include "Core.h"

#include "../nms/GameComponents/GcTextChatInput.h"
#include "../nms/GameComponents/GcApplication.h"
#include "../nms/GameComponents/GcTextChatManager.h"

#define NEWCOMMAND(commandPtr) TextChatHandler::AddCommand(commandPtr)

namespace TextChatHandler
{
	void Init();
	void __fastcall ParseTextForCommandsHook(cGcTextChatInput* _this, const cTkFixedString<1023, char> lMessageText);
	void RegisterStockCommands();
};