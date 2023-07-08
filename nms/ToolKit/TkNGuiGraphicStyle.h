#pragma once

#include "TkNGuiGraphicStyleData.h"
#include "TkVector2.h"
#include "TkCurveType.h"
#include "../NGui/eAnimate.h"
#include "../GameComponents/GcPlayerControlInput.h"

class cTkNGuiGraphicStyle
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