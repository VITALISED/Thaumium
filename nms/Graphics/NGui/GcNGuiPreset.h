#pragma once

#include "GcNGuiPresetText.h"
#include "GcNGuiLayoutData.h"
#include "GcNGuiPresetGraphic.h"
#include "../ToolKit/TkFixedString.h"
#include "../ToolKit/TkFixedArray.h"

class cGcNGuiPreset
{
	cTkFixedString<128, char> macFont;
	cTkFixedArray<cGcNGuiPresetGraphic, 10> maLayer;
	cTkFixedArray<cGcNGuiPresetGraphic, 10> maGraphic;
	cTkFixedArray<cGcNGuiPresetText, 10> maText;
	cGcNGuiLayoutData mSpacingLayout;
};