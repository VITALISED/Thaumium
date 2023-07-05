#pragma once
#include "TkColour.h"
#include "TkNGuiAlignment.h"

#pragma pack(16)
class cTkNGuiTextStyleData
{
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
};
#pragma pack()