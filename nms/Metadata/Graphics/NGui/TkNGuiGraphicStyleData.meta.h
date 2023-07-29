#pragma once

#include "../nms/Graphics/Gradient.h"
#include "../nms/Graphics/Shape.h"
#include "../nms/ToolKit/Graphics/TkColour.h"

class __declspec(align(16)) cTkNGuiGraphicStyleData
{
public:
	cTkNGuiGraphicStyleData()
	{ }

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