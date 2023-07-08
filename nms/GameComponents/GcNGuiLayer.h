#pragma once

#include <vector>

#include "GcNGuiElement.h"
#include "GcNGuiLayerData.h"
#include "GcNGuiText.h"
#include "../ToolKit/TkSTLAllocatorShim.h"
#include "../ToolKit/TkLinearHashTable.h"
#include "../ToolKit/TkHashedNGuiElement.h"

#pragma pack(16)
class cGcNGuiLayer : public cGcNGuiElement
{
public:
	cGcNGuiLayer();

	std::vector<cGcNGuiElement*, TkSTLAllocatorShim<cGcNGuiElement*> > mapElements;
	std::vector<cGcNGuiLayer*, TkSTLAllocatorShim<cGcNGuiLayer*> > mapLayerElements;
	std::vector<cTkVector2, TkSTLAllocatorShim<cTkVector2> > maPinnedPositions;
	cTkNGuiGraphicStyleData mPreviousGraphicsStyle;
	void(__fastcall* mpRenderFunction)(void*);
	void* mpRenderFunctionData;
	cGcNGuiLayerData* mpLayerData;
	void* mpElementHashTable;
	unsigned __int64 muUniqueID;
	bool mbExpanded;

	void LoadFromMetadata(const char* lpacFilename, bool lbUseCached);
	cGcNGuiText* FindTextRecursive(const TkID<128>* lID);
	cGcNGuiLayer* FindLayerRecursive(const TkID<128>* lID);
};