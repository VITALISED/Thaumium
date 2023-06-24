#pragma once
#include "pch.h"
#include "framework.h"

#define _BASE (uintptr_t)GetModuleHandleA(NULL)
#define OFFSET(offset) (LPVOID)(_BASE + (uintptr_t)offset)
#define ADDHOOK(pTarget, pDetour, ppOriginal, name) Hooks::AddHook(pTarget, pDetour, ppOriginal, #name)

namespace Hooks
{
	//void Init();
	void AddHook(LPVOID pTarget, LPVOID pDetour, void* ppOriginal, const char* name);

	//template<typename T>
	//struct Hook
	//{
	//	T *func;
	//	T **original;
	//	uintptr_t offset;
	//	const char *name;
	//};
}