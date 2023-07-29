#pragma once

#include "../pch.h"
#include "TkNGuiAlignment.meta.h"
#include "../nms/ToolKit/Utilities/TkArray.h"

class ALIGN(8) cGcNGuiLayoutData
{
public:
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

	void SetDefaults();
};