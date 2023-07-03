#pragma once
#include "TkID.h"

class cGcNGuiElementData
{
	TkID<128> mID;
	TkID<128> mPresetID;
	bool mbIsHidden;
	cTkNGuiForcedStyle mForcedStyle;
	cGcNGuiLayoutData mLayout;
};