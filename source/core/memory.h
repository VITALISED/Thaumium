#pragma once

#include "../../pch.h"

#define _BASE (uintptr_t)GetModuleHandleA("NMS.exe")
#define OFFSET(offset) (LPVOID)(_BASE + (uintptr_t)offset)
#define SIGSCAN(pattern) (LPVOID)(Memory::ScanPattern(Memory::IdaPatternToByte(pattern)))

#define ALIGN(_align) __declspec(align(_align))

namespace Memory
{
	void PatchBytes(uintptr_t ptr, uint8_t bytes[]);
	std::vector<int> IdaPatternToByte(const char* sig);
	uintptr_t ScanPattern(std::vector<int> bytes);
}