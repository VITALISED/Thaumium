#pragma once

#include "../pch.h"
#include "../nms/ToolKit/Graphics/NGui/TkNGuiDraggable.h"
#include "../nms/ToolKit/Maths/TkBBox2d.h"
#include "../nms/ToolKit/Graphics/NGui/TkNGuiTypeUndoable.h"
#include "../nms/ToolKit/Metadata/TkClassPointer.h"
#include "../nms/Metadata/Graphics/NGui/GcNGuiElementData.meta.h"
#include "../NGui/NGuiInputType.h"
#include "../NGui/NGuiAnimationEvent.h"
#include "NGuiEditorIcons.h"
#include "GcNGuiPreset.h"

class cGcNGuiLayer;

class cGcNGuiElement : public ITkNGuiDraggable
{
public:
	typedef bool(__fastcall* IsMouseInside)(cGcNGuiLayer* layer);

	enum eLayoutChangeEvent : __int8
	{
		ELayoutChange_Nothing = 0x0,
		ELayoutChange_PositionMode = 0x1,
		ELayoutChange_WidthMode = 0x2,
		ELayoutChange_HeightMode = 0x3,
		ELayoutChange_ConstrainMode = 0x4,
		ELayoutChange_Size = 0x5,
		ELayoutChange_Width = 0x6,
		ELayoutChange_Height = 0x7,
		ELayoutChange_Value = 0x8,
		ELayoutChange_ColourPreset = 0x9,
	};

	struct sGcNGuiElementAnimSettings
	{
		__int8 mbRequestAnimActivate : 1;
		__int8 mbRequestAnimReset : 1;
	};

	cTkBBox2d mContentBBox;
	cTkVector2 mvParallaxOffset;
	cTkNGuiTypeUndoable<cGcNGuiLayoutData>* mpUndoMoveEvent;
	cTkNGuiTypeUndoable<cGcNGuiLayoutData>* mpUndoResizeEvent;
	cTkNGuiTypeUndoable<cGcNGuiLayoutData>* mpUndoLayoutEvent;
	cGcNGuiLayer* mpParent;
	cGcNGuiElementData* mpElementData;
	eNGuiInputType meInputThisFrame;
	cGcNGuiElement::eLayoutChangeEvent meLayoutChangeEvent;
	eNGuiAnimationEvent meRequestAnim;
	cGcNGuiElement::sGcNGuiElementAnimSettings mAnim;
	bool mbSelectedToEdit;

	virtual void Render();
	virtual ~cGcNGuiElement()
	{
		delete this;
	}
	virtual void EditElement();
	virtual void EditPresets(cGcNGuiPreset* lpGuiPreset);
	virtual void RenderUIEditorToolbar(cGcNGuiPreset* lpGuiPreset); //probably debug build only. 
	virtual bool SelectableInEditor() = 0;
	virtual void SetNeedsUpdate() = 0;
	virtual void Deselect();
	virtual bool IsSelected();
	virtual void Resized();
	virtual void AttachMetadata(cTkClassPointer* lClass) = 0;
	virtual void DetachMetadata(cTkClassPointer* lClass) = 0;
	virtual inline bool IsLayer()
	{
		return (sizeof(*this) == 0x160);
	}
	virtual eNGuiEditorIcons GetSceneTreeIcon() = 0;
	virtual void GetSceneTreeText(cTkFixedString<128, char>* lOutResult) = 0;
	virtual void RenderAdditionalOverlayIcons(const cTkVector2* lOrigin, const cTkVector2* lSize) = 0;
	virtual void RenderTreeControls() = 0;

};