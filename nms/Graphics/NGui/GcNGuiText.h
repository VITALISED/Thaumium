#pragma once

#include "../pch.h"
#include "../nms/Metadata/Graphics/NGui/GcNGuiTextData.meta.h"
#include "../nms/ToolKit/Utilities/TkString.h"
#include "GcNGuiElement.h"

class cGcNGuiText : public cGcNGuiElement
{
public:
	cTkFixedString<128, char> mLocBlinkText;
	cTkNGuiTextStyleData mPreviousTextStyle;
	cTkNGuiGraphicStyleData mPreviousGraphicStyle;
	cGcNGuiTextData* mpTextData;
	unsigned __int64 miLocTextBlinkBaseTime;


	void Render();
	~cGcNGuiText()
	{
		delete this;
	}
	void EditElement();
	void AttachMetadata(cTkClassPointer* lClass);
	eNGuiEditorIcons GetSceneTreeIcon();
	void GetSceneTreeText(cTkFixedString<128, char>* lOutResult);
	virtual void Convert();
	virtual void SetText(const char* lpacText);
};