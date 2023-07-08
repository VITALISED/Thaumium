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
	reinterpret_cast<cGcNGuiSpacingData*>(this)->SetDefaults();
	this->mStyle.mDefault.SetDefaults();
	this->mStyle.mHighlight.SetDefaults();
	this->mStyle.mActive.SetDefaults();
	this->mStyle.mAnimCurve1.meCurve = ECurve_Linear;
	this->mStyle.SetDefaults();
	this->macImage = cTkFixedString<128, char>();
	this->maChildren = cTkDynamicArray<char[0x50]>();
	this->macDataFilename = cTkFixedString<128, char>();
	this->SetDefaults();
}

void cGcNGuiLayerData::SetDefaults()
{
	this->mElementData.mbIsHidden = false;
	reinterpret_cast<cGcFrigateFlybyType*>(&this->mElementData.mForcedStyle)->SetDefaults();
	this->mElementData.mLayout.mfWidth = 50;
	this->mElementData.mLayout.mfPositionX = 0;
	this->mElementData.mLayout.mfHeight = 50;
	this->mElementData.mLayout.mfConstrainAspect = 1065353216;
	reinterpret_cast<cTkNGuiAlignment*>(&this->mElementData.mLayout.mAlign)->SetDefaults();
	this->mElementData.mLayout.mbWidthPercentage = 0;
	this->mElementData.mLayout.mbAnchor = true;
	this->mStyle.SetDefaults();
	if (0 != (const char*)&this->macImage)
	{
		this->macImage.Copy(0);
	}
	if (0 != (const char*)&this->macImage)
	{
		this->macDataFilename.Copy(0);
	}
	this->meAltMode = EAltMode_None;
}