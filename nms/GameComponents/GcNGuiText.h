#pragma once

#include "GcNGuiElement.h"
#include "GcNGuiTextData.h"
#include "../ToolKit/TkFixedString.h"

class cGcNGuiText : public cGcNGuiElement
{
public:
	cTkFixedString<128, char> mLocBlinkText;
	cTkNGuiTextStyleData mPreviousTextStyle;
	cTkNGuiGraphicStyleData mPreviousGraphicStyle;
	cGcNGuiTextData* mpTextData;
	unsigned __int64 miLocTextBlinkBaseTime;

	void SetText(const char* lpacText);
};