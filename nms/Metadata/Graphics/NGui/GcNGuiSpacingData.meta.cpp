#include "GcNGuiSpacingData.h"

void cGcNGuiSpacingData::SetDefaults()
{
	this->mElementData.mID;
	this->mElementData.mPresetID;
	this->mElementData.mbIsHidden = false;
	reinterpret_cast<cGcFrigateFlybyType*>(&this->mElementData.mForcedStyle)->SetDefaults();
	this->mElementData.mLayout.mfWidth = 50;
	this->mElementData.mLayout.mfHeight = 50;
	this->mElementData.mLayout.mfConstrainAspect = 1065353216;
	reinterpret_cast<cTkNGuiAlignment*>(&this->mElementData.mLayout.mAlign)->SetDefaults();
	this->mElementData.mLayout.mbWidthPercentage = 0;
	this->mElementData.mLayout.mbAnchor = true;
}