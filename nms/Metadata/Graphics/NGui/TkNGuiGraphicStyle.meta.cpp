#include "TkNGuiGraphicStyle.h"

void cTkNGuiGraphicStyle::SetDefaults()
{
	this->mDefault.mColour = cTkColour(1, 0, 0, 0);
	this->mDefault.mIconColour = cTkColour(1, 1, 1, 1);
	this->mDefault.mGradientColour = cTkColour(1, 0, 0, 0);
	this->mDefault.mStrokeGradientColour = cTkColour(1, 1, 1, 1);
	this->mDefault.mfPaddingX = NULL;
	this->mDefault.mfMarginX = NULL;
	this->mDefault.mfGradientStartOffset = NULL;
	this->mDefault.mfCornerRadius = NULL;
	this->mDefault.miImage = NULL;
	this->mDefault.mfDesaturation = NULL;
	this->mDefault.mfStrokeGradientFeather = NULL;
	this->mDefault.meShape = (eShape)0x10000;
	this->mHighlight.mColour = cTkColour(1, 0, 0, 0);
	this->mHighlight.mIconColour = cTkColour(1, 1, 1, 1);
	this->mHighlight.mStrokeColour = cTkColour(1, 1, 1, 1);
	this->mHighlight.mGradientColour = cTkColour(1, 0, 0, 0);
	this->mHighlight.mStrokeGradientColour = cTkColour(1, 0, 0, 0);
	this->mHighlight.mfPaddingX = NULL;
	this->mHighlight.mfMarginX = NULL;
	this->mHighlight.mfGradientStartOffset = NULL;
	this->mHighlight.mfCornerRadius = NULL;
	this->mHighlight.miImage = NULL;
	this->mHighlight.mfDesaturation = NULL;
	this->mHighlight.mfStrokeGradientFeather = NULL;
	this->mHighlight.meShape = (eShape)0x10000;
	this->mActive.mColour = cTkColour(1, 0, 0, 0);
	this->mActive.mIconColour = cTkColour(1, 1, 1, 1);
	this->mActive.mStrokeColour = cTkColour(1, 1, 1, 1);
	this->mActive.mGradientColour = cTkColour(1, 0, 0, 0);
	this->mActive.mStrokeGradientColour = cTkColour(1, 0, 0, 0);
	this->mActive.mfPaddingX = NULL;
	this->mActive.mfMarginX = NULL;
	this->mActive.mfGradientStartOffset = NULL;
	this->mActive.mfCornerRadius = NULL;
	this->mActive.miImage = NULL;
	this->mActive.mfDesaturation = NULL;
	this->mActive.mfStrokeGradientFeather = NULL;
	this->mActive.meShape = (eShape)0x10000;
	this->mCustomMinStart.mfX = 1.0;
	this->mCustomMinStart.mfY = 1.0;
	this->mCustomMaxStart.mfX = 1.0;
	this->mCustomMaxStart.mfY = 1.0;
	this->mfHighlightTime = 0.1;
	this->mfHighlightScale = 1.0;
	this->mfGlobalFade = 1.0;
	this->mfAnimTime = 0.5;
	this->mfAnimSplit = 0.40000001;
	reinterpret_cast<cGcPlayerControlInput*>(&this->mAnimCurve1)->SetDefaults();
	reinterpret_cast<cGcPlayerControlInput*>(&this->mAnimCurve2)->SetDefaults();
	this->meAnimate = EAnimate_None;
}