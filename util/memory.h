#pragma once

#include <iostream>
#include <vector>
#include "../framework.h"
#include "../nms/ToolKit/TkMemoryManager.h"

#define _BASE (uintptr_t)GetModuleHandleA(NULL)
#define OFFSET(offset) (LPVOID)(_BASE + (uintptr_t)offset)

#define TKMEMORYMANAGER (cTkMemoryManager*)OFFSET(0x45835D0)

namespace Memory
{
	void PatchBytes(uintptr_t ptr, const char* sig);
	std::vector<BYTE> IdaPatternToByte(const char* sig);
	uintptr_t NMSMalloc(long size);
}