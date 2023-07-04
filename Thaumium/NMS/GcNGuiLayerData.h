#pragma once
#include "eAltMode.h"
#include "TkFixedString.h"
#include "TkDynamicArray.h"
#include "TkNGuiGraphicStyle.h"
#include "GcNGuiElementData.h"

#pragma pack(16)
class cGcNGuiLayerData
{
public:
	cGcNGuiElementData mElementData;
	cTkNGuiGraphicStyle mStyle;
	cTkFixedString<128, char> macImage;
	cTkDynamicArray</*cTkClassPointer*/char[0x50]> maChildren;
	cTkFixedString<128, char> macDataFilename;
	eAltMode meAltMode;
};