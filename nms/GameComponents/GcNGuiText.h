#pragma once

#include "GcNGuiElement.h"
#include "GcNGuiTextData.h"
#include "../ToolKit/TkFixedString.h"

class cGcNGuiText : public cGcNGuiElement
{
public:
	cGcNGuiText();
	~cGcNGuiText()
	{
		if (this->mpTextData)
		{
			//delete it
		}
		else
		{
			//delete myself
		}
	}
	cTkFixedString<128, char> mLocBlinkText;
	cTkNGuiTextStyleData mPreviousTextStyle[0x60];
	char mPreviousGraphicStyle[0x90];
	cGcNGuiTextData* mpTextData;
	unsigned __int64 miLocTextBlinkBaseTime;

	void SetText(const char* lpacText);
};