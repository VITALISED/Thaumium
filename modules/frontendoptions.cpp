#include "../pch.h"
#include "FrontendOptions.h"

cGcFrontendPageOptions::PrepareBootScreenNetworkOptions fpPrepareBootScreenNetworkOptions = NULL;
bool called = false;

void FrontendOptions::Init()
{
	PatchSwitchMenuJZ();
	PatchOptionsHeaderSwitchStatement();

	ADDHOOK(OFFSET(0x651FC0), HookPrepareBootScreenOptions, reinterpret_cast<LPVOID*>(fpPrepareBootScreenNetworkOptions), cGcFrontendPageOptions::PrepareBootScreenNetworkOptions);
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

	cGcOptionsMenuState* state = (cGcOptionsMenuState*)malloc(sizeof(cGcOptionsMenuState));
	//state = new cGcOptionsMenuState()

	std::vector<cGcOptionsMenuState*,TkSTLAllocatorShim<cGcOptionsMenuState*>> coolVec = 
		*(std::vector<cGcOptionsMenuState*, TkSTLAllocatorShim<cGcOptionsMenuState*>>*)ptr;

	bool wire = true;
	bool wire2 = true;

	cGcBooleanOption* guhh = (cGcBooleanOption*)malloc(0x480u);
	cGcBooleanOption* guhh2 = (cGcBooleanOption*)malloc(0x480u);

	guhh = new cGcBooleanOption("UI_MULTIPLAYER", &wire, "UI_MULTIPLAYER_D", true, "kill", "kill");
	guhh2 = new cGcBooleanOption("UI_MULTIPLAYER", &wire2, "UI_MULTIPLAYER_D", true, "kill", "kill");
	state->mItems.push_back(guhh);

	cGcUIOptionListElement** ptrPtr = (cGcUIOptionListElement**)malloc(sizeof(uintptr_t));
	cGcUIOptionListElement** ptrPtr2 = (cGcUIOptionListElement**)malloc(sizeof(uintptr_t));
	ptrPtr = (cGcUIOptionListElement**)&guhh;
	ptrPtr2 = (cGcUIOptionListElement**)&guhh2;

	coolVec.push_back(state);

	spdlog::info(coolVec.size());

	return NULL;
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
