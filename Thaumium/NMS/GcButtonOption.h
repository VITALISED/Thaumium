#pragma once
#include "GcUIOptionListElement.h"

class cGcButtonOption : public cGcUIOptionListElement
{
	const char* mpacOptionName;
	cGcNGuiLayer* mpButton;
	bool mbRequireLongPress;
	const char* mpacDescription;
	void(__fastcall* mpOnClick)();
};

struct /*VFT*/ cGcButtonOption_vtbl
{
	void(__fastcall* UpdateUI)(cGcUIOptionListElement* _this);
	void(__fastcall* Initialize)(cGcUIOptionListElement* _this, cGcNGuiLayer*, void*);
	void(__fastcall* Apply)(cGcUIOptionListElement* _this);
	void(__fastcall* ResetToDefault)(cGcUIOptionListElement* _this);
	void(__fastcall* DiscardChanges)(cGcUIOptionListElement* _this);
	bool(__fastcall* HasChanges)(cGcUIOptionListElement* _this);
	bool(__fastcall* IsNonDefault)(cGcUIOptionListElement* _this);
	const char* (__fastcall* GetDescription)(cGcUIOptionListElement* _this);
	const char* (__fastcall* GetName)(cGcUIOptionListElement* _this);
	bool(__fastcall* IsHovering)(cGcUIOptionListElement* _this);
	void(__fastcall * __decon)(cGcUIOptionListElement* _this);
	void(__fastcall* TranslateDescription)(cGcUIOptionListElement* _this);
};