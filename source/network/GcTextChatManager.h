#pragma once
#include "../common/utilities/TkString.h"

class cGcTextChatManager
{
public:
	typedef void (*Say)(cGcTextChatManager *self, const cTkFixedString<1023, char> *lsMessageBody, bool lbSystemMessage);
};