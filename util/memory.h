#pragma once

#include "../pch.h"
#include <iostream>
#include <vector>

#ifdef FRACTAL
#define _BASE (uintptr_t)GetModuleHandleA("XGOG Release_x64.exe")
#else
#define _BASE (uintptr_t)GetModuleHandleA(NULL)
#endif
#define OFFSET(offset) (LPVOID)(_BASE + (uintptr_t)offset)
#define SIGSCAN(pattern) (LPVOID)(Memory::ScanPattern(Memory::IdaPatternToByte(#pattern)))

#define JUMPIMM(addr) (__asm(jmp, addr))

#define ALIGN(_align) __declspec(align(_align))

namespace Memory
{
	void PatchBytes(uintptr_t ptr, const char* sig);
	std::vector<BYTE> IdaPatternToByte(const char* sig);
	uintptr_t ScanPattern(std::vector<BYTE> bytes);
}