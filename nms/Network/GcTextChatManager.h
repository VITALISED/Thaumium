#pragma once
#include "../nms/ToolKit/Utilities/TkString.h"

class cGcTextChatManager
{
public:
	typedef void(__fastcall* Say)(cGcTextChatManager* _this, const cTkFixedString<1023, char>* lsMessageBody, bool lbSystemMessage);
};