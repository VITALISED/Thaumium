#pragma once
#include "eAltMode.h"
#include "TkFixedString.h"
#include "TkDynamicArray.h"
#include "TkNGuiGraphicStyle.h"

class cGcNGuiLayerData
{
	cGcNGuiElementData mElementData;
	cTkNGuiGraphicStyle mStyle;
	cTkFixedString<128, char> macImage;
	cTkDynamicArray</*cTkClassPointer*/char[0x50]> maChildren;
	cTkFixedString<128, char> macDataFilename;
	eAltMode meAltMode;
};