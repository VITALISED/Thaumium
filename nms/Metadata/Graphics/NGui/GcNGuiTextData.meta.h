#pragma once

#include "GcNGuiElementData.meta.h"
#include "TkNGuiGraphicStyle.meta.h"
#include "TkNGuiTextStyle.meta.h"
#include "../nms/ToolKit/Metadata/TkClassPointer.h"
#include "../nms/ToolKit/Utilities/TkString.h"

class cGcNGuiTextData
{
public:
	cGcNGuiElementData mElementData;
	cTkNGuiTextStyle mStyle;
	cTkNGuiGraphicStyle mGraphicStyle;
	cTkFixedString<512, char> macText;
	cTkFixedString<128, char> macImage;
	float mfForcedOffset;
	cTkDynamicArray</*cGcVROverride_Text*/char[0x8]> maVROverrides;
	cTkDynamicArray</*cGcAccessibleOverride_Text*/char[0x8]> maAccessibleOverrides;
	bool mbSpecial;
	bool mbForcedAllowScroll;

	void WriteToClassPtr(cTkClassPointer* lClassPtr);
};