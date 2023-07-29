#include "TkNGuiGraphicStyleData.meta.h"

void cTkNGuiGraphicStyleData::SetDefaults()
{
	this->mColour = cTkColour(1, 0, 0, 0);
	this->mIconColour = cTkColour(1, 1, 1, 1);
	this->mStrokeColour = cTkColour(1, 1, 1, 1);
	this->mGradientColour = cTkColour(1, 0, 0, 0);
	this->mStrokeGradientColour = cTkColour(1, 1, 1, 1);
	this->mfPaddingX = NULL;
	this->mfMarginX = NULL;
	this->mfGradientStartOffset = NULL;
	this->mfCornerRadius = NULL;
	this->miImage = NULL;
	this->mfDesaturation = NULL;
	this->mfStrokeGradientFeather = NULL;
	this->meShape = (eShape)0x10000;
}