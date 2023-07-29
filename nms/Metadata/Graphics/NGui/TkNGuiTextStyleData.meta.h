#pragma once

#include "TkNGuiAlignment.meta.h"
#include "../nms/ToolKit/Graphics/TkColour.h"

class cTkNGuiTextStyleData
{
public:
	cTkColour mColour;
	cTkColour mShadowColour;
	cTkColour mOutlineColour;
	float mfFontHeight;
	float mfFontSpacing;
	float mfDropShadowAngle;
	float mfDropShadowOffset;
	float mfOutlineSize;
	int miFontIndex;
	cTkNGuiAlignment mAlign;
	bool mbIsIndented;
	bool mbHasDropShadow;
	bool mbHasOutline;
	bool mbIsParagraph;
	bool mbAllowScroll;
	bool mbForceUpperCase;
	bool mbAutoAdjustHeight;
	bool mbAutoAdjustFontHeight;
	bool mbBlockAudio;

	void SetDefaults()
	{
		this->mColour = cTkColour(1, 1, 1, 1);
		this->mShadowColour = cTkColour(1, 0, 0, 0);
		this->mOutlineColour = cTkColour(1, 1, 1, 1);
		this->mfFontHeight = 1098907648; // is this generated somewhere?
		this->mfDropShadowAngle = 0.0;
		this->mfDropShadowOffset = 1.0;
		this->mfOutlineSize = 1065353216; // see above
		this->mAlign.meVertical = EVertical_Top;
		this->mbAutoAdjustHeight = 256;
		this->mbBlockAudio = false;
	}
};
