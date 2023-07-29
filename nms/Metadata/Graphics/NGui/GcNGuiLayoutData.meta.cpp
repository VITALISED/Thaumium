#include "GcNGuiLayoutData.meta.h"

void cGcNGuiLayoutData::SetDefaults()
{
	this->mfWidth = 50;
	this->mfPositionX = 0;
	this->mfHeight = 50;
	this->mfConstrainAspect = 1065353216; // why this num?
	this->mbWidthPercentage = 0;
	this->mbAnchor = true;
}