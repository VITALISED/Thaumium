#pragma once

#include "GcNGuiElementData.meta.h"
#include "GcNGuiSpacingData.meta.h"
#include "TkNGuiGraphicStyle.meta.h"
#include "../nms/Graphics/AltMode.h"
#include "../nms/ToolKit/Metadata/TkClassPointer.h"
#include "../nms/ToolKit/Utilities/TkString.h"
#include "../nms/ToolKit/Utilities/TkArray.h"

class cGcNGuiLayerData
{
public:
	cGcNGuiLayerData()
	{ };
	typedef bool(*Save)(cGcNGuiLayerData* thiscall, const char* lpacFileName, bool lbClearAllExistingData);

	cGcNGuiElementData mElementData;
	cTkNGuiGraphicStyle mStyle;
	cTkFixedString<128, char> macImage;
	cTkDynamicArray<cTkClassPointer> maChildren;
	cTkFixedString<128, char> macDataFilename;
	eAltMode meAltMode;

	void SetDefaults();
	~cGcNGuiLayerData()
	{
		delete this;
	}
};