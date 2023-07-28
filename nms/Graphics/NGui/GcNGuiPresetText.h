#pragma once
#include "../nms/Metadata/Graphics/NGui/GcNGuiLayoutData.meta.h"
#include "../nms/ToolKit/Metadata/TkID.h"
#include "../nms/Metadata/Graphics/NGui/TkNGuiGraphicStyle.meta.h"
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