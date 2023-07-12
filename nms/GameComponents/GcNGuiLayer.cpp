#include "GcNGuiLayer.h"
#include "../../util/memory.h"

typedef void(*__LoadFromMetadata)(cGcNGuiLayer* thiscall, const char* lpacFilename, bool lbUseCached);
typedef cGcNGuiText*(*__FindTextRecursive)(cGcNGuiLayer* thiscall, const TkID<128>* lID);
typedef cGcNGuiLayer* (*__FindLayerRecursive)(cGcNGuiLayer* thiscall, const TkID<128>* lID);

cGcNGuiLayer::cGcNGuiLayer()
{
	//TODO: set up class globals
	unsigned __int64* mguLayerIdCount = (unsigned __int64*)OFFSET(0x41F7C48);

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
	this->mpElementData = (cGcNGuiElementData*)malloc(sizeof(cGcNGuiElementData));
	this->mpElementData = &this->mpLayerData->mElementData;
	this->mpElementHashTable = new cTkLinearHashTable<cTkHashedNGuiElement, cGcNGuiElement*>();
	this->mpLayerData->mStyle.mDefault.mbSolidColour = false;
	this->mpLayerData->mStyle.mDefault.mbSolidColour = false;
	this->mpLayerData->mStyle.mActive.mbSolidColour = false;
	this->mpLayerData->mStyle.mHighlight.mbSolidColour = false;
	this->mbExpanded = false;
	this->muUniqueID = *mguLayerIdCount++;
	this->mpElementData->mLayout.mfHeight = 200;
	this->mpElementData->mLayout.mfWidth = 200;
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

void cGcNGuiLayer::DeallocateLayerChildrenRecursive()
{
	typedef void (*fptr)(cGcNGuiLayer*);
	fptr func = (fptr)OFFSET(0x1BBA90);
	func(this);
}

void cGcNGuiLayer::Render()
{
	typedef void (*fptr)(cGcNGuiLayer*);
	fptr func = (fptr)OFFSET(0x8543B0);
	func(this);
}

void cGcNGuiLayer::EditElement()
{
	typedef void (*fptr)(cGcNGuiLayer*);
	fptr func = (fptr)OFFSET(0x854AF0);
	func(this);
}

bool cGcNGuiLayer::SelectableInEditor()
{
	return this->mpLayerData->mStyle.mDefault.mbSolidColour;
}

void cGcNGuiLayer::SetNeedsUpdate()
{
	int size = this->mapElements.size();

	for (int i = 0; i < size; i++)
	{
		this->mapElements[i]->SetNeedsUpdate();
	}
}

void cGcNGuiLayer::Deselect()
{
	this->mbSelectedToEdit = 0;
	int size = this->mapElements.size();

	for (int i; i < size; i++)
	{
		this->mapElements[i]->Deselect();
	}
}

// uses weird lambda stuff that i dont want to implement.
void cGcNGuiLayer::Resized()
{
	typedef void (*fptr)(cGcNGuiLayer*);
	fptr func = (fptr)OFFSET(0x1CA410);
	func(this);
}

void cGcNGuiLayer::AttachMetadata(cTkClassPointer* lClass)
{
	typedef void (*fptr)(cGcNGuiLayer*, cTkClassPointer*);
	fptr func = (fptr)OFFSET(0x1B8B60);
	func(this, lClass);
}

void cGcNGuiLayer::DetachMetadata(cTkClassPointer* lClass)
{
	lClass->mClassData.miOffset = NULL;
	lClass->mClassName = cTkFixedString<63, char>("");
	lClass->mbClassFixed = NULL;
	lClass->mClassNameHash = NULL;
	this->DeallocateLayerChildrenRecursive();
}

eNGuiEditorIcons cGcNGuiLayer::GetSceneTreeIcon()
{
	if (this->mapElements.size())
	{
		return EIcon_folder3;
	}
	else {
		return EIcon_folder;
	}
}

void cGcNGuiLayer::GetSceneTreeText(cTkFixedString<128, char>* lOutResult)
{
	typedef void (*fptr)(cGcNGuiLayer*, cTkFixedString<128, char>*);
	fptr func = (fptr)OFFSET(0x854E00);
	func(this, lOutResult);
}

void cGcNGuiLayer::RenderAdditionalOverlayIcons(const cTkVector2* lOrigin, const cTkVector2* lSize)
{
	typedef void (*fptr)(cGcNGuiLayer*, const cTkVector2*, const cTkVector2*);
	fptr func = (fptr)OFFSET(0x855220);
	func(this, lOrigin, lSize);
}

cGcNGuiLayer* cGcNGuiLayer::GetSelected()
{
	if (this->IsSelected())
		return this;

	for (int i; i < this->mapElements.size(); i++)
	{
		if (this->mapElements[i]->IsLayer())
		{
			if (this->mapElements[i]->IsSelected())
			{
				return (cGcNGuiLayer*)this->mapElements[i];
			}
		}
		else
		{
			// I have no idea what the fuck ida thinks this is
			//result = (cGcNGuiLayer*)((__int64 (*)(void))v6[1].Render)();
			//if (result)
			//	return result;
			return NULL;
		}
	}

	return NULL;
}