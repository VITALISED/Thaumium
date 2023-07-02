#pragma once
#include "GcNGuiLayer.h"
#include "GcOptionsInteractionContext.h"

class cGcUIOptionListElement
{
public:
	cGcUIOptionListElement()
	{ };
	cGcNGuiLayer* mpElement;
	cGcOptionsInteractionContext* mpContext;
	bool mbEnabled;
	bool mbVisible;

	virtual void UpdateUI();
	virtual void Initialize(cGcNGuiLayer* layer, cGcOptionsInteractionContext* ctx);
	virtual void Apply();
	virtual void ResetToDefault();
	virtual void DiscardChanges();
	virtual bool HasChanges();
	virtual bool IsNonDefault();
	virtual const char* GetDescription();
	virtual const char* GetName();
	virtual bool IsHovering()
	{
		cGcNGuiElement::IsMouseInside IsMouseInside = (cGcNGuiElement::IsMouseInside)OFFSET(0x566FF0);
		return IsMouseInside(this->mpElement);
	};
	virtual ~cGcUIOptionListElement();
	virtual void TranslateDescription();
};
