#pragma once

#include "TkColour.h"
#include "../NGui/eGradient.h"
#include "../NGui/eShape.h"

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

	void SetDefaults();
};