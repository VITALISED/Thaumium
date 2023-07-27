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
	void DeallocateLayerChildrenRecursive();
	void Render();
	int GetType()
	{
		return sizeof(*this); // honestly just a guess for now.
	}
	void EditElement();
	bool SelectableInEditor();
	void SetNeedsUpdate();
	void Deselect();
	void Resized();
	void AttachMetadata(cTkClassPointer* lClass);
	void DetachMetadata(cTkClassPointer* lClass);
	eNGuiEditorIcons GetSceneTreeIcon();
	void GetSceneTreeText(cTkFixedString<128, char>* lOutResult);
	void RenderAdditionalOverlayIcons(const cTkVector2* lOrigin, const cTkVector2* lSize);
	void RenderTreeControls()
	{ };
	cGcNGuiLayer* GetSelected();

	~cGcNGuiLayer()
	{
		delete this;
	}
};