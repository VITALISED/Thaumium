#pragma once

#include "../ToolKit/TkDynamicArray.h"
#include "../ToolKit/TkNGuiAlignment.h"

#pragma pack(8)
class cGcNGuiLayoutData
{
	cTkDynamicArray</*cGcVROverride_Layout*/char[0x8]> maVROverrides;
	cTkDynamicArray</*cGcAccessibleOverride_Layout*/char[0x8]> maAccessibleOverrides;
	float mfPositionX;
	float mfPositionY;
	float mfWidth;
	float mfHeight;
	float mfConstrainAspect;
	float mfMaxWidth;
	cTkNGuiAlignment mAlign;
	bool mbWidthPercentage;
	bool mbHeightPercentage;
	bool mbConstrainProportions;
	bool mbForceAspect;
	bool mbAnchor;
	bool mbAnchorPercent;
	bool mbSameLine;
	bool mbSlowCursorOnHover;
};