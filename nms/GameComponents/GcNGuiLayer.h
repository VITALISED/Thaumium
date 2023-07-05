#pragma once
#include "GcNGuiElement.h"
#include "GcNGuiLayerData.h"
#include "GcNGuiText.h"

#pragma pack(16)
class cGcNGuiLayer : public cGcNGuiElement
{
public:
	typedef cGcNGuiLayer* (*FindLayerRecursive)(cGcNGuiLayer* thiscall, const TkID<128>* lID);

	char mapElements[0x18];
	char mapLayerElements[0x18];
	char maPinnedPositions[0x18];
	//TODO: figure out why this doesn't size properly
	//std::vector<cGcNGuiElement*, TkSTLAllocatorShim<cGcNGuiElement*> > mapElements;
	//std::vector<cGcNGuiLayer*, TkSTLAllocatorShim<cGcNGuiLayer*> > mapLayerElements;
	//std::vector<cTkVector2, TkSTLAllocatorShim<cTkVector2> > maPinnedPositions;
	char mPreviousGraphicsStyle[0x90];
	void(__fastcall* mpRenderFunction)(void*);
	void* mpRenderFunctionData;
	cGcNGuiLayerData* mpLayerData;
	void* mpElementHashTable;
	unsigned __int64 muUniqueID;
	bool mbExpanded;

	void LoadFromMetadata(const char* lpacFilename, bool lbUseCached);
	cGcNGuiText* FindTextRecursive(const TkID<128>* lID);
};