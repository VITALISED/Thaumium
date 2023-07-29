#pragma once

#include "TkNGuiGraphicStyleData.meta.h"
#include "../nms/ToolKit/Maths/TkVector2.h"
#include "../nms/ToolKit/Graphics/TkCurveType.h"
#include "../nms/Graphics/Animate.h"
#include "../nms/Simulation/GcPlayerControlInput.h"

class __declspec(align(16))cTkNGuiGraphicStyle
{
public:
	cTkNGuiGraphicStyleData mDefault;
	cTkNGuiGraphicStyleData mHighlight;
	cTkNGuiGraphicStyleData mActive;
	cTkVector2 mCustomMinStart;
	cTkVector2 mCustomMaxStart;
	float mfHighlightTime;
	float mfHighlightScale;
	float mfGlobalFade;
	float mfAnimTime;
	float mfAnimSplit;
	cTkCurveType mAnimCurve1;
	cTkCurveType mAnimCurve2;
	eAnimate meAnimate;
	bool mbInheritStyleFromParentLayer;

	void SetDefaults();
};
