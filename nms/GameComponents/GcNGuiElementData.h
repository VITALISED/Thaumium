#pragma once

#include "GcNGuiLayoutData.h"
#include "../ToolKit/TkID.h"
#include "../ToolKit/TkNGuiForcedStyle.h"

class cGcNGuiElementData
{
public:
	TkID<128> mID;
	TkID<128> mPresetID;
	bool mbIsHidden;
	cTkNGuiForcedStyle mForcedStyle;
	cGcNGuiLayoutData mLayout;
};
