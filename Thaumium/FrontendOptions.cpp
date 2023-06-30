#include "pch.h"
#include "FrontendOptions.h"
#include "NMS/GcBooleanOption.h"
#include "NMS/TkSTLAllocatorShim.h"
#include "NMS/GcOptionsMenuState.h"
#include "NMS/GcButtonOption.h"

//std::vector<void*, TkSTLAllocatorShim<void*>> mOpenMenus = OFFSET(0x4AF14C8);

extern "C" void OptionsHeaderHook(); //optionsheaderhook.asm
cGcFrontendPageOptions::PrepareBootScreenNetworkOptions fpPrepareBootScreenNetworkOptions = NULL;

void FrontendOptions::Init()
{
	PatchSwitchMenuJZ();
	PatchOptionsHeaderSwitchStatement();

	ADDHOOK(OFFSET(0x651FC0), HookPrepareBootScreenOptions, fpPrepareBootScreenNetworkOptions, cGcFrontendPageOptions::PrepareBootScreenNetworkOptions);
}

cGcUIOptionListElement** FrontendOptions::HookPrepareBootScreenOptions()
{
	LPVOID ptr = OFFSET(0x4AF14C8);

	std::vector<cGcOptionsMenuState*, TkSTLAllocatorShim<cGcOptionsMenuState*>> openMenus
		= reinterpret_cast<std::vector<cGcOptionsMenuState*, TkSTLAllocatorShim<cGcOptionsMenuState*>>&>(ptr);


	cGcUIOptionListElement* v7 = (cGcUIOptionListElement *)Memory::NMSMalloc(0x48ui64);
	if(v7)
	{
		//v7->mbEnabled = 257;
		//v7[1].__vftable = (cGcUIOptionListElement_vtbl*)"OPTION_CREDITS";
		//v7[2].__vftable = (cGcUIOptionListElement_vtbl*)spdlog::info("hello!");
		////v7->__vftable = cGcButtonOption_vtbl
		//v7[1].mpContext = 0;
		//v7[1].mbEnabled = 0i64;
		v7->mbEnabled = 257;
	}
	else
	{
		v7 = NULL;
	}

	
	std::vector<cGcUIOptionListElement*, TkSTLAllocatorShim<cGcUIOptionListElement*> > items = std::vector<cGcUIOptionListElement*, TkSTLAllocatorShim<cGcUIOptionListElement*> >();

	cGcOptionsMenuState state = cGcOptionsMenuState(0xF, items);

	openMenus.push_back(&state);

	return &v7;
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

