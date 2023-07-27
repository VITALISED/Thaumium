#pragma once

#include <iostream>
#include <vector>
#include "../pch.h"
#include "../nms/ToolKit/TkMemoryManager.h"

#define _BASE (uintptr_t)GetModuleHandleA(NULL)
#define OFFSET(offset) (LPVOID)(_BASE + (uintptr_t)offset)
#define SIGSCAN(pattern) (LPVOID)(Memory::ScanPattern(Memory::IdaPatternToByte(#pattern)))

#define JUMPIMM(addr) (__asm(jmp, addr))

#define ALIGN(_align) __declspec(align(_align))

#define TKMEMORYMANAGER (cTkMemoryManager*)OFFSET(0x45835D0)

namespace Memory
{
	void PatchBytes(uintptr_t ptr, const char* sig);
	std::vector<BYTE> IdaPatternToByte(const char* sig);
	uintptr_t ScanPattern(std::vector<BYTE> bytes);
}