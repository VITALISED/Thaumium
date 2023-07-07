#include "GcNGuiLayerData.h"

cGcNGuiLayerData::cGcNGuiLayerData()
{
	this->mElementData.mForcedStyle.meNGuiForcedStyle = ENGuiForcedStyle_None;
	this->mElementData.mLayout.maVROverrides.mArray.miOffset = NULL;
	this->mElementData.mLayout.maVROverrides.miSize = NULL;
	this->mElementData.mLayout.maVROverrides.mbAllocatedFromData = NULL;
	this->mElementData.mLayout.maAccessibleOverrides.mArray.miOffset = NULL;
	this->mElementData.mLayout.maAccessibleOverrides.miSize = NULL;
	this->mElementData.mLayout.maAccessibleOverrides.mbAllocatedFromData = NULL;
	this->mElementData.mLayout.mAlign.meHorizontal = (eHorizontal)NULL;
	this->mElementData.mLayout.mAlign.meVertical = (eVertical)NULL;
	this->mElementData.mLayout.SetDefaults();

	cGcNGuiSpacingData* p_this = (cGcNGuiSpacingData*)this;
	p_this->SetDefaults()
}