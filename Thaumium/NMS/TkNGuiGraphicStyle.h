#pragma once
#include "TkNGuiGraphicStyleData.h"
#include "TkVector2.h"
#include "eAnimate.h"
#include "TkCurveType.h"

class cTkNGuiGraphicStyle
{
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
};