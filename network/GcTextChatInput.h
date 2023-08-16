#pragma once
#include "../common/utilities/TkString.h"

class cGcTextChatInput
{
public:
	typedef void(__fastcall *ParseTextForCommands)(cGcTextChatInput *_this, const cTkFixedString<1023, char> lMessageText);
};