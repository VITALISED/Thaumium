#pragma once

#include "GcNGuiElementData.h"
#include "GcNGuiSpacingData.h"
#include "../NGui/eAltMode.h"
#include "../ToolKit/TkFixedString.h"
#include "../ToolKit/TkDynamicArray.h"
#include "../ToolKit/TkNGuiGraphicStyle.h"

#pragma pack(16)
class cGcNGuiLayerData
{
public:
	cGcNGuiLayerData();

	cGcNGuiElementData mElementData;
	cTkNGuiGraphicStyle mStyle;
	cTkFixedString<128, char> macImage;
	cTkDynamicArray</*cTkClassPointer*/char[0x50]> maChildren;
	cTkFixedString<128, char> macDataFilename;
	eAltMode meAltMode;
};
#pragma pack()