#pragma once

#include "../pch.h"
#include <iostream>
#include <vector>

#ifdef FRACTAL
#define _BASE (uintptr_t)GetModuleHandleA("XGOG Release_x64.exe")
#else // FRACTAL
#define _BASE (uintptr_t)GetModuleHandleA(NULL)
#endif // UPSTREAM
#define OFFSET(offset) (LPVOID)(_BASE + (uintptr_t)offset)
#define SIGSCAN(pattern) (LPVOID)(Memory::ScanPattern(Memory::IdaPatternToByte(#pattern)))

#define JUMPIMM(addr) (__asm(jmp, addr))

#define ALIGN(_align) __declspec(align(_align))

#define MAKE_FUNCTION_TYPE(name, ret, ...) typedef ret (*name)(__VA_ARGS__)

#define DECLARE_METHOD_REDIR(addr, type, name, ...) type lpMethod = (type)addr; spdlog::debug("Calling method redirect for {}", #name); return lpMethod(__VA_ARGS__); 

namespace Memory
{
	void PatchBytes(uintptr_t ptr, const char* sig);
	std::vector<BYTE> IdaPatternToByte(const char* sig);
	uintptr_t ScanPattern(std::vector<BYTE> bytes);
}