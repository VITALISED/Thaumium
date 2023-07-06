#include "GcNGuiText.h"

cGcNGuiText::cGcNGuiText()
{
	this->mAnim = (cGcNGuiElement::sGcNGuiElementAnimSettings)(this->mAnim & 0xFC | 1);
	this->mvParallaxOffset = cTkVector2{};
	this->mpParent = NULL;
	this->mbSelectedToEdit = NULL;
	this->meLayoutChangeEvent = ELayoutChange_Nothing;
	this->mpUndoMoveEvent = NULL;
	this->mpUndoResizeEvent = NULL;
	this->mpUndoLayoutEvent = NULL;
	this->mContentBBox = cTkBBox2d{};
	this->mLocBlinkText = cTkFixedString<128, char>();
	this->mPreviousTextStyle->SetDefaults();
}

void cGcNGuiText::SetText(const char* lpacText)
{
	this->mpTextData->macText = cTkFixedString<512, char>(lpacText);
}