#include "GcNGuiLayer.h"
#include "../../util/memory.h"

typedef void(*__LoadFromMetadata)(cGcNGuiLayer* thiscall, const char* lpacFilename, bool lbUseCached);
typedef cGcNGuiText*(*__FindTextRecursive)(cGcNGuiLayer* thiscall, const TkID<128>* lID);


void cGcNGuiLayer::LoadFromMetadata(const char* lpacFilename, bool lbUseCached)
{
	//TODO: implement MBIN, EXML and other VFS related things locally.

	DWORD oldprotection, newprotection;

	__LoadFromMetadata mxmlLoader = (__LoadFromMetadata)OFFSET(0x873930);
	VirtualProtect((LPVOID)this, 1, PAGE_EXECUTE_READWRITE, &oldprotection);

	mxmlLoader(this, lpacFilename, lbUseCached);

	VirtualProtect((LPVOID)this, 1, oldprotection, &newprotection);
}

cGcNGuiText* cGcNGuiLayer::FindTextRecursive(const TkID<128>* lID)
{
	//TODO: understand how TkIDs work
	DWORD oldprotection, newprotection;
	__FindTextRecursive findTextRecursive = (__FindTextRecursive)OFFSET(0x873930);
	VirtualProtect((LPVOID)this, 1, PAGE_EXECUTE_READWRITE, &oldprotection);
	cGcNGuiText* retval = findTextRecursive(this, lID);
	VirtualProtect((LPVOID)this, 1, oldprotection, &newprotection);
	return retval;
}