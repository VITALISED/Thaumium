#include "pch.h"
#include "FrontendOptions.h"
#include "NMS/TkSTLAllocatorShim.h"
#include "NMS/GcOptionsMenuState.h"
#include "NMS/GcUIOptionListElement.h"
#include "NMS/GcBooleanOption.h"

cGcFrontendPageOptions::PrepareBootScreenNetworkOptions fpPrepareBootScreenNetworkOptions = NULL;

void FrontendOptions::Init()
{
	PatchSwitchMenuJZ();
	PatchOptionsHeaderSwitchStatement();

	ADDHOOK(OFFSET(0x651FC0), HookPrepareBootScreenOptions, fpPrepareBootScreenNetworkOptions, cGcFrontendPageOptions::PrepareBootScreenNetworkOptions);
}

void PrintShit()
{
	spdlog::info("button moment");
}

cGcUIOptionListElement** FrontendOptions::HookPrepareBootScreenOptions()
{
	LPVOID ptr = OFFSET(0x4AF14C8);

	std::vector<cGcOptionsMenuState*, TkSTLAllocatorShim<cGcOptionsMenuState*>> openMenus
		= reinterpret_cast<std::vector<cGcOptionsMenuState*, TkSTLAllocatorShim<cGcOptionsMenuState*>>&>(ptr);

	bool wire = true;

	//cGcButtonOption* v7 = (cGcButtonOption*)Memory::NMSMalloc(0x48ui64);
	//if(v7)
	//{
	//	v7->mbEnabled = 257;
	//	v7->mbEnabled = "UI_OPTIONS_GENERAL_L";
	//	v7->mpOnClick = PrintShit;
	//}
	//else
	//{
	//	v7 = NULL;
	//}

	cGcBooleanOption wire2 = cGcBooleanOption{};
	
	std::vector<cGcUIOptionListElement*, TkSTLAllocatorShim<cGcUIOptionListElement*> > items = std::vector<cGcUIOptionListElement*, TkSTLAllocatorShim<cGcUIOptionListElement*> >();
	//items.push_back(v7);

	cGcOptionsMenuState state = cGcOptionsMenuState(0xF, items);

	openMenus.push_back(&state);

	auto agahagag = (cGcUIOptionListElement*)NULL;

	return &agahagag;
}

void FrontendOptions::PatchOptionsHeaderSwitchStatement()
{
	uintptr_t ptr = (uintptr_t)(OFFSET(0x38A9DF8));
	Memory::PatchBytes(ptr, "77 69 72 65 73 20 69 6E 20 6D 79 20 64 65 76 69 63 65 00"); // patch .data segment
};

void FrontendOptions::PatchSwitchMenuJZ()
{
	uintptr_t ptr = (uintptr_t)(OFFSET(0x6585F0));
	Memory::PatchBytes(ptr, "FF 90 80 00 00 00 90 90 90 90"); // this NOPs AllowedMultiplayer() jz on Network header, letting us use it
};
