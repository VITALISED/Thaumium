#pragma once
#include "ITkNGuiDraggable.h"
#include "TkBBox2d.h"
#include "NGuiInputType.h"
#include "NGuiAnimationEvent.h"

class cGcNGuiLayer;

class cGcNGuiElement : ITkNGuiDraggable
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
	/*cTkNGuiTypeUndoable<cGcNGuiLayoutData>**/void* mpUndoMoveEvent;
	/*cTkNGuiTypeUndoable<cGcNGuiLayoutData>**/void* mpUndoResizeEvent;
	/*cTkNGuiTypeUndoable<cGcNGuiLayoutData>**/void* mpUndoLayoutEvent;
	cGcNGuiLayer* mpParent;
	/*cGcNGuiElementData*/void* mpElementData;
	eNGuiInputType meInputThisFrame;
	cGcNGuiElement::eLayoutChangeEvent meLayoutChangeEvent;
	eNGuiAnimationEvent meRequestAnim;
	cGcNGuiElement::sGcNGuiElementAnimSettings mAnim;
	bool mbSelectedToEdit;
};