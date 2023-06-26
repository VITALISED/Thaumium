#include "pch.h"
#include "FrontendOptions.h"


void FrontendOptions::Init()
{
	PatchSwitchMenuJZ();
}

void FrontendOptions::PatchOptionsPrepareSwitchStatement()
{

}

void FrontendOptions::PatchOptionsHeaderSwitchStatement()
{

};

void FrontendOptions::PatchSwitchMenuJZ()
{
	uintptr_t ptr = (uintptr_t)(OFFSET(0x6585F0));
	Memory::PatchBytes(ptr, "FF 90 80 00 00 00 90 90 90 90");
};