#include "pch.h"
#include "FrontendOptions.h"

typedef void(__fastcall* HackyFuncBullyshit)(cGcNGuiText* _this, const char* lpacText);

void __TextRecursiveHack()
{
	HackyFuncBullyshit setTextFunc = (HackyFuncBullyshit)OFFSET(0x87F0C0);

	const char* headerTextID = "HEADERTEXT";
}

void FrontendOptions::Init()
{
	PatchSwitchMenuJZ();
}

void FrontendOptions::PatchOptionsPrepareSwitchStatement()
{

}

void FrontendOptions::PatchOptionsHeaderSwitchStatement()
{
	uintptr_t table = (uintptr_t)OFFSET(0x650E76);
	ShadowVT shadowTable = ShadowVT(table, 7);

	//shadowTable.Hook(7, )
};

void FrontendOptions::PatchSwitchMenuJZ()
{
	uintptr_t ptr = (uintptr_t)(OFFSET(0x6585F0));
	Memory::PatchBytes(ptr, "FF 90 80 00 00 00 90 90 90 90"); // this NOPs AllowedMultiplayer() jz on Network header, letting us use it
};

