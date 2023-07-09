#pragma once
#include "GcNGuiLayoutData.h"
#include "../ToolKit/TkID.h"
#include "../ToolKit/TkNGuiGraphicStyle.h"
#include "../ToolKit/TkFixedString.h"

class cGcNGuiPresetGraphic
{
	TkID<128> mPresetID;
	cGcNGuiLayoutData mLayout;
	cTkNGuiGraphicStyle mStyle;
	cTkFixedString<128, char> macImage;
};