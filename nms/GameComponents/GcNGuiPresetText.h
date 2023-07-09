#pragma once
#include "GcNGuiLayoutData.h"
#include "../ToolKit/TkID.h"
#include "../ToolKit/TkNGuiTextStyle.h"
#include "../ToolKit/TkNGuiGraphicStyle.h"
#include "../ToolKit/TkFixedString.h"

class cGcNGuiPresetText
{
	TkID<128> mPresetID;
	cGcNGuiLayoutData mLayout;
	cTkNGuiTextStyle mStyle;
	cTkNGuiGraphicStyle mGraphicStyle;
	cTkFixedString<128, char> macImage;
};