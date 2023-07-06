#include "../pch.h"
#include "frontendoptions.h"

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

static_assert(sizeof(std::vector<cGcOptionsMenuState*, TkSTLAllocatorShim<cGcOptionsMenuState*>>) == 0x18, "");

cGcUIOptionListElement** FrontendOptions::HookPrepareBootScreenOptions()
{
	std::vector<cGcOptionsMenuState*, TkSTLAllocatorShim<cGcOptionsMenuState*>> mOpenMenus = *(std::vector<cGcOptionsMenuState*, TkSTLAllocatorShim<cGcOptionsMenuState*>>*)OFFSET(0x4AF14C8);

	spdlog::info("mOpenMenus size: {}", mOpenMenus.size());
	

	//wirelessss ptr2 = (wirelessss)OFFSET(0x630220);

	//cGcOptionsMenuState* state = (cGcOptionsMenuState*)malloc(sizeof(cGcOptionsMenuState));
	////state = new cGcOptionsMenuState()

	bool* check = (bool*)malloc(sizeof(bool));
	*check = false;

	bool* check2 = (bool*)malloc(sizeof(bool));
	*check2 = false;

	cGcBooleanOption* item = (cGcBooleanOption*)malloc(0x480u);
	cGcBooleanOption* item2 = (cGcBooleanOption*)malloc(0x480u);

	cGcBooleanOption* thing = new(item) cGcBooleanOption("UI_MULTIPLAYER", check, "UI_MULTIPLAYER_D", false, "wired", "wireless");
	cGcBooleanOption* thing2 = new(item2) cGcBooleanOption("UI_MULTIPLAYER", check, "UI_MULTIPLAYER_D", false, "wired", "wireless");

	mOpenMenus.back()->mItems.push_back(thing);
	mOpenMenus.back()->mItems.push_back(thing2);

	return &mOpenMenus.back()->mItems.back();
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
