#pragma once

#include "../nms/Metadata/Graphics/NGui/GcNGuiLayoutData.meta.h"
#include "../nms/Metadata/Graphics/NGui/TkNGuiGraphicStyle.meta.h"
#include "../nms/ToolKit/Metadata/TkID.h"
#include "../nms/ToolKit/Utilities/TkString.h"

class cGcNGuiPresetGraphic
{
	TkID<128> mPresetID;
	cGcNGuiLayoutData mLayout;
	cTkNGuiGraphicStyle mStyle;
	cTkFixedString<128, char> macImage;
};