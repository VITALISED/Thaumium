#pragma once
#include "GcNGuiElement.h"
#include "TkFixedString.h"

class __declspec(align(16)) cGcNGuiText : cGcNGuiElement
{
	cTkFixedString<128, char> mLocBlinkText;
	char mPreviousTextStyle[0x60];
	char mPreviousGraphicStyle[0x90];
	/*cGcNGuiTextData*/void* mpTextData;
	unsigned __int64 miLocTextBlinkBaseTime;
};

static_assert(sizeof(cGcNGuiText) == 0x1D0, "size of class is invalid.");