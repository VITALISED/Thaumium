#pragma once
#include "../common/utilities/TkString.h"

class cGcTextChatInput
{
public:
	typedef void (*ParseTextForCommands)(cGcTextChatInput *self, const cTkFixedString<1023, char> lMessageText);
};