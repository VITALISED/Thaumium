#pragma once

#include "../nms/ToolKit/Utilities/TkString.h"
#include "../nms/ToolKit/Utilities/TkArray.h"
#include "../nms/Metadata/Graphics/NGui/GcNGuiLayoutData.meta.h"
#include "GcNGuiPresetGraphic.h"
#include "GcNGuiPresetText.h"

class cGcNGuiPreset
{
	cTkFixedString<128, char> macFont;
	cTkFixedArray<cGcNGuiPresetGraphic, 10> maLayer;
	cTkFixedArray<cGcNGuiPresetGraphic, 10> maGraphic;
	cTkFixedArray<cGcNGuiPresetText, 10> maText;
	cGcNGuiLayoutData mSpacingLayout;
};