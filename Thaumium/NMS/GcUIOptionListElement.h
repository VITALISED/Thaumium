#pragma once
#include "GcNGuiLayer.h"

struct /*VFT*/ cGcUIOptionListElement_vtbl
{
	void(__fastcall* UpdateUI)(void* _this);
	void(__fastcall* Initialize)(void* _this, cGcNGuiLayer*, /*cGcOptionsInteractionContext*/void*);
	void(__fastcall* Apply)(void* _this);
	void(__fastcall* ResetToDefault)(void* _this);
	void(__fastcall* DiscardChanges)(void* _this);
	bool(__fastcall* HasChanges)(void* _this);
	bool(__fastcall* IsNonDefault)(void* _this);
	const char* (__fastcall* GetDescription)(void* _this);
	const char* (__fastcall* GetName)(void* _this);
	bool(__fastcall* IsHovering)(void* _this);
	void(__fastcall* destructor)(void* _this);
	void(__fastcall* TranslateDescription)(void* _this);
};

#pragma pack(8)
class cGcUIOptionListElement
{
public:
	cGcUIOptionListElement()
	{ };
	cGcUIOptionListElement_vtbl* __vftable /*VFT*/;
	cGcNGuiLayer* mpElement;
	/*cGcOptionsInteractionContext*/void* mpContext;
	bool mbEnabled;
	bool mbVisible;
};

static_assert(sizeof(cGcUIOptionListElement) == 0x20, "wires");

