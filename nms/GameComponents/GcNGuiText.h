#pragma once

#include "GcNGuiElement.h"
#include "GcNGuiTextData.h"
#include "../ToolKit/TkFixedString.h"

class cGcNGuiText : public cGcNGuiElement
{
public:
	cTkFixedString<128, char> mLocBlinkText;
	char mPreviousTextStyle[0x60];
	char mPreviousGraphicStyle[0x90];
	cGcNGuiTextData* mpTextData;
	unsigned __int64 miLocTextBlinkBaseTime;

	void SetText(const char* lpacText)
	{
		cTkFixedString<512, char> str = cTkFixedString<512, char>(lpacText);
		this->mpTextData->macText = str;
	}
};