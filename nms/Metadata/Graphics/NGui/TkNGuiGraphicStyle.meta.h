#pragma once

#include "TkNGuiGraphicStyleData.h"
#include "../nms/ToolKit/Maths/TkVector2.h"
#include "../TkCurveType.h"
#include "../nms/NGui/Animate.h"
#include "../nms/GameComponents/GcPlayerControlInput.h"

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
