#include "GcNGuiLayer.h"
#include "../../util/memory.h"

typedef void(*__LoadFromMetadata)(cGcNGuiLayer* thiscall, const char* lpacFilename, bool lbUseCached);
typedef cGcNGuiText*(*__FindTextRecursive)(cGcNGuiLayer* thiscall, const TkID<128>* lID);
typedef cGcNGuiLayer* (*__FindLayerRecursive)(cGcNGuiLayer* thiscall, const TkID<128>* lID);

cGcNGuiLayer::cGcNGuiLayer()
{
	this->mAnim = cGcNGuiLayer::sGcNGuiElementAnimSettings{};
	short bwStuff = *reinterpret_cast<short*>(&this->mAnim) & 0xFC | 1;
	this->mAnim = *reinterpret_cast<cGcNGuiLayer::sGcNGuiElementAnimSettings*>(&bwStuff);
	this->mpParent = NULL;
	this->mbSelectedToEdit = NULL;
	this->meLayoutChangeEvent = ELayoutChange_Nothing;
	this->mpUndoMoveEvent = NULL;
	this->mpUndoResizeEvent = NULL;
	this->mpUndoLayoutEvent = NULL;
	this->mpElementData = NULL;
	this->mContentBBox = cTkBBox2d();
	this->mapElements = std::vector<cGcNGuiElement*, TkSTLAllocatorShim<cGcNGuiElement*> >();
	this->mapLayerElements = std::vector<cGcNGuiLayer*, TkSTLAllocatorShim<cGcNGuiLayer*> >();
	this->maPinnedPositions = std::vector<cTkVector2, TkSTLAllocatorShim<cTkVector2> >();
	this->mPreviousGraphicsStyle.SetDefaults();
	this->mpLayerData = new cGcNGuiLayerData();

}

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
	DWORD oldprotection, newprotection;
	__FindTextRecursive findTextRecursive = (__FindTextRecursive)OFFSET(0x873930);
	VirtualProtect((LPVOID)this, 1, PAGE_EXECUTE_READWRITE, &oldprotection);
	cGcNGuiText* retval = findTextRecursive(this, lID);
	VirtualProtect((LPVOID)this, 1, oldprotection, &newprotection);
	return retval;
}

cGcNGuiLayer* cGcNGuiLayer::FindLayerRecursive(const TkID<128>* lID)
{
	DWORD oldprotection, newprotection;
	__FindLayerRecursive findLayerRecursive = (__FindLayerRecursive)OFFSET(0x1BE870);
	VirtualProtect((LPVOID)this, 1, PAGE_EXECUTE_READWRITE, &oldprotection);
	cGcNGuiLayer* retval = findLayerRecursive(this, lID);
	VirtualProtect((LPVOID)this, 1, oldprotection, &newprotection);
	return retval;
}