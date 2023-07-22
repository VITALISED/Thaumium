#pragma once

#include "../pch.h"
#include "memory.h"

#define ADDHOOK(pTarget, pDetour, ppOriginal, name) Hooks::AddHook(pTarget, pDetour, ppOriginal, #name)

namespace Hooks
{
	void AddHook(LPVOID pTarget, LPVOID pDetour, void* ppOriginal, const char* name);
}