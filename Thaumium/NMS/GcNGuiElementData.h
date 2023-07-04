#pragma once
#include "TkID.h"
#include "TkNGuiForcedStyle.h"
#include "GcNGuiLayoutData.h"

class cGcNGuiElementData
{
public:
	TkID<128> mID;
	TkID<128> mPresetID;
	bool mbIsHidden;
	cTkNGuiForcedStyle mForcedStyle;
	cGcNGuiLayoutData mLayout;
};