#include "pch.h"
#include "FrontendOptions.h"
#include "NMS/GcBooleanOption.h"
#include "NMS/TkSTLAllocatorShim.h"


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
//	std::vector<cGcUIOptionListElement*>* retVal = &std::vector<cGcUIOptionListElement*>();

	bool a = false;
	bool* aPtr = &a;

	cGcUIOptionListElement* mainElem2 = (cGcUIOptionListElement*)Memory::NMSMalloc(0x48ui64);


	cGcBooleanOption* option = (cGcBooleanOption*)Memory::NMSMalloc(0x480ui16);
	cGcBooleanOption::_cGcBooleanOption guh = (cGcBooleanOption::_cGcBooleanOption)OFFSET(0x631400);

	guh(option, "UI_MULTIPLAYER", aPtr, "UI_MULTIPLAYER_D", false, 0, 0);


	//if (mainElem2)
	//{
	//	mainElem2->mbEnabled = 257;
	//}
	//else
	//	mainElem2 = NULL;

	//std::vector<cGcUIOptionListElement*, TkSTLAllocatorShim<cGcUIOptionListElement*>>::_Emplace_one_at_back<cGcUIOptionListElement* const&>(
	//	*((std::vector<cGcUIOptionListElement*, TkSTLAllocatorShim<cGcUIOptionListElement*> **)mOpenMenus._Mypair._Myval2._Mylast
	//		- 1),
	//	&mainElem2);

	cGcUIOptionListElement** retVal = &mainElem2;
	return retVal;
}

void FrontendOptions::PatchOptionsHeaderSwitchStatement()
{
	uintptr_t ptr = (uintptr_t)(OFFSET(0x38A9DF8));
	Memory::PatchBytes(ptr, "77 69 72 65  73 20 69 6E 20 6D 79 20  64 65 76 69 63 65 00");
};

void FrontendOptions::PatchSwitchMenuJZ()
{
	uintptr_t ptr = (uintptr_t)(OFFSET(0x6585F0));
	Memory::PatchBytes(ptr, "FF 90 80 00 00 00 90 90 90 90"); // this NOPs AllowedMultiplayer() jz on Network header, letting us use it
};

