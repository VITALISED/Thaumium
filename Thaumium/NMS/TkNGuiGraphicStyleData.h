#pragma once
#include "eShape.h"
#include "TkColour.h"
#include "eGradient.h"

class cTkNGuiGraphicStyleData
{
	cTkColour mColour;
	cTkColour mIconColour;
	cTkColour mStrokeColour;
	cTkColour mGradientColour;
	cTkColour mStrokeGradientColour;
	float mfPaddingX;
	float mfPaddingY;
	float mfMarginX;
	float mfMarginY;
	float mfGradientStartOffset;
	float mfGradientEndOffset;
	float mfCornerRadius;
	float mfStrokeSize;
	int miImage;
	int miIcon;
	float mfDesaturation;
	float mfStrokeGradientOffset;
	float mfStrokeGradientFeather;
	eShape meShape;
	eGradient meGradient;
	bool mbSolidColour;
	bool mbHasDropShadow;
	bool mbHasOuterGradient;
	bool mbHasInnerGradient;
	bool mbGradientOffsetPercent;
	bool mbStrokeGradient;
};