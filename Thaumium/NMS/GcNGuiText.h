#pragma once
#include "GcNGuiElement.h"
#include "TkFixedString.h"

class cGcNGuiText : cGcNGuiElement
{
	cTkFixedString<128, char> mLocBlinkText;
	char mPreviousTextStyle[0x60];
	char mPreviousGraphicStyle[0x90];
	/*cGcNGuiTextData*/void* mpTextData;
	unsigned __int64 miLocTextBlinkBaseTime;

	void SetText(const char* lpacText)
	{
		cTkFixedString<512, char> str = cTkFixedString<512, char>(lpacText);
	}
};