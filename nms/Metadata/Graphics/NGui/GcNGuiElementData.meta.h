#pragma once

#include "GcNGuiLayoutData.meta.h"
#include "TkNGuiForcedStyle.meta.h"
#include "../nms/ToolKit/Metadata/TkID.h"

class cGcNGuiElementData
{
public:
	cGcNGuiElementData()
	{ }
	TkID<128> mID;
	TkID<128> mPresetID;
	bool mbIsHidden;
	cTkNGuiForcedStyle mForcedStyle;
	cGcNGuiLayoutData mLayout;
};
