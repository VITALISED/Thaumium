#include "pch.h"
#include "FrontendOptions.h"
#include "NMS/GcBooleanOption.h"

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

	cGcUIOptionListElement mainElem = cGcUIOptionListElement{};
	cGcUIOptionListElement* mainElem2 = &mainElem;

	cGcBooleanOption option = cGcBooleanOption();
	cGcBooleanOption::_cGcBooleanOption guh = (cGcBooleanOption::_cGcBooleanOption)OFFSET(0x631400);

	guh(&option, "UI_MULTIPLAYER", aPtr, "UI_MULTIPLAYER_D", false, 0, 0);

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

