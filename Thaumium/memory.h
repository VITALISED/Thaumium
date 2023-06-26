#pragma once
#include <iostream>
#include "framework.h"
#include <vector>

namespace Memory
{
	void PatchBytes(uintptr_t ptr, const char* sig);
	std::vector<BYTE> IdaPatternToByte(const char* sig);
}