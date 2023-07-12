#pragma once

#include "GcNGuiElementData.h"
#include "GcNGuiSpacingData.h"
#include "../NGui/eAltMode.h"
#include "../ToolKit/TkFixedString.h"
#include "../ToolKit/TkDynamicArray.h"
#include "../ToolKit/TkNGuiGraphicStyle.h"
#include "../ToolKit/TkClassPointer.h"

class cGcNGuiLayerData
{
public:
	cGcNGuiLayerData();

	cGcNGuiElementData mElementData;
	cTkNGuiGraphicStyle mStyle;
	cTkFixedString<128, char> macImage;
	cTkDynamicArray<cTkClassPointer> maChildren;
	cTkFixedString<128, char> macDataFilename;
	eAltMode meAltMode;

	void SetDefaults();
};

constexpr int alignofafa = sizeof(cGcNGuiLayerData);