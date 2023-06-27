#pragma once
#include "GcNGuiElement.h"

#pragma pack(16)
class cGcNGuiLayer : cGcNGuiElement
{
	char mapElements[0x18];
	char mapLayerElements[0x18];
	char maPinnedPositions[0x18];
	__declspec(align(16)) char mPreviousGraphicsStyle[0x90];
	void(__fastcall* mpRenderFunction)(void*);
	void* mpRenderFunctionData;
	void* mpLayerData;
	void* mpElementHashTable;
	unsigned __int64 muUniqueID;
	bool mbExpanded;
};

constexpr int size = sizeof(cGcNGuiLayer);

static_assert(sizeof(cGcNGuiLayer) == 0x160, "size of class is invalid");