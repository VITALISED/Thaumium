#include "pch.h"
#include "FrontendOptions.h"
#include "NMS/TkSTLAllocatorShim.h"
#include "NMS/GcOptionsMenuState.h"
#include "NMS/GcUIOptionListElement.h"
#include "NMS/GcBooleanOption.h"

cGcFrontendPageOptions::PrepareBootScreenNetworkOptions fpPrepareBootScreenNetworkOptions = NULL;
bool called = false;

void FrontendOptions::Init()
{
	PatchSwitchMenuJZ();
	PatchOptionsHeaderSwitchStatement();

	ADDHOOK(OFFSET(0x651FC0), HookPrepareBootScreenOptions, NULL, cGcFrontendPageOptions::PrepareBootScreenNetworkOptions);
}

void PrintShit()
{
	spdlog::info("button moment");
}

typedef cGcUIOptionListElement** (__fastcall* wirelessss)(void* thiscall, cGcUIOptionListElement** thing);

cGcUIOptionListElement** FrontendOptions::HookPrepareBootScreenOptions()
{

	LPVOID ptr = OFFSET(0x4AF14C8);
	wirelessss ptr2 = (wirelessss)OFFSET(0x630220);

	

	DWORD oldprotection, newprotection;
	VirtualProtect((LPVOID)ptr, 1, PAGE_EXECUTE_READWRITE, &oldprotection);

	std::vector<cGcOptionsMenuState*, TkSTLAllocatorShim<cGcOptionsMenuState*>>* openMenusPtr
		= reinterpret_cast<std::vector<cGcOptionsMenuState*, TkSTLAllocatorShim<cGcOptionsMenuState*>>*>(ptr);

	std::vector<cGcOptionsMenuState*, TkSTLAllocatorShim<cGcOptionsMenuState*>> openMenus = *openMenusPtr;

	bool wire = true;

	cGcBooleanOption* thing = (cGcBooleanOption*)Memory::NMSMalloc(0x480ui64);

	thing = new cGcBooleanOption("UI_MULTIPLAYER", &wire, "UI_MULTIPLAYER_D", true, "kill", "kill");

	//std::vector<cGcUIOptionListElement*, TkSTLAllocatorShim<cGcUIOptionListElement*> > items = std::vector<cGcUIOptionListElement*, TkSTLAllocatorShim<cGcUIOptionListElement*> >();
	//items.push_back((cGcUIOptionListElement*)wire2);

	//cGcOptionsMenuState state = cGcOptionsMenuState(0xF, items);

	//openMenus.back()->mItems.push_back(wire2);

	auto agahagag = (cGcUIOptionListElement*)thing;

	VirtualProtect((LPVOID)ptr, 1, oldprotection, &newprotection);

	//auto guhhh = openMenus.back();
	//auto fortntie = guhhh->mItems.back();
	//return (cGcUIOptionListElement**)openMenus.back()->mItems.back();

	return ptr2(ptr, (cGcUIOptionListElement**)&thing);
}

void FrontendOptions::PatchOptionsHeaderSwitchStatement()
{
	//uintptr_t ptr = (uintptr_t)(OFFSET(0x38A9DF8));
	//Memory::PatchBytes(ptr, "77 69 72 65 73 20 69 6E 20 6D 79 20 64 65 76 69 63 65 00"); // patch .data segment
};

void FrontendOptions::PatchSwitchMenuJZ()
{
	uintptr_t ptr = (uintptr_t)(OFFSET(0x6585F0));
	Memory::PatchBytes(ptr, "FF 90 80 00 00 00 90 90 90 90"); // this NOPs AllowedMultiplayer() jz on Network header, letting us use it
};
