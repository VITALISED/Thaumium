#include "../pch.h"
#include "GcNGuiLayer.h"
#include "../memory.h"

typedef void(*__LoadFromMetadata)(cGcNGuiLayer* thiscall, const char* lpacFilename, bool lbUseCached);

void cGcNGuiLayer::LoadFromMetadata(const char* lpacFilename, bool lbUseCached)
{
	//TODO: implement MBIN, EXML and other VFS related things locally.

	DWORD oldprotection, newprotection;

	__LoadFromMetadata mxmlLoader = (__LoadFromMetadata)OFFSET(0x873930);
	VirtualProtect((LPVOID)this, 1, PAGE_EXECUTE_READWRITE, &oldprotection);

	mxmlLoader(this, lpacFilename, lbUseCached);

	VirtualProtect((LPVOID)this, 1, oldprotection, &newprotection);
}