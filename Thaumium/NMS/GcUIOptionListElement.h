#pragma once
#include "GcNGuiLayer.h"
#include "GcOptionsInteractionContext.h"
#include "../memory.h"

class cGcUIOptionListElement
{
public:
	cGcUIOptionListElement()
	{ };
	cGcNGuiLayer* mpElement;
	cGcOptionsInteractionContext* mpContext;
	bool mbEnabled;
	bool mbVisible;

	virtual void UpdateUI()
	{ }
	virtual void Initialize(cGcNGuiLayer* layer, cGcOptionsInteractionContext* ctx)
	{ }
	virtual void Apply()
	{ }
	virtual void ResetToDefault()
	{ }
	virtual void DiscardChanges()
	{ }
	virtual bool HasChanges()
	{
		return false;
	}
	virtual bool IsNonDefault()
	{
		return false;
	}
	virtual const char* GetDescription()
	{ 
		return "";
	}
	virtual const char* GetName()
	{ 
		return "";
	}
	virtual bool IsHovering()
	{
		cGcNGuiElement::IsMouseInside IsMouseInside = (cGcNGuiElement::IsMouseInside)OFFSET(0x566FF0);
		return IsMouseInside(this->mpElement);
	};
	virtual ~cGcUIOptionListElement()
	{
		delete this;
	}
	virtual void TranslateDescription()
	{ }

	void SetEnabled(bool lbEnabled);
};
