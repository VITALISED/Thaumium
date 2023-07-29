#pragma once
#include "../GcNGuiLayer.h"
#include "../nms/ToolKit/Utilities/TkString.h"

class cGcOptionsInteractionContext
{
public:
	/*cGcFrontendPage*/void* mpPage;
	/*cGcLayerInteractControl*/void* mpLayerInteractionControl;
	cGcNGuiLayer* mpPageLayer;
	char mCount[0x50];
	bool mbConstructed;

	bool Confirm(cGcNGuiLayer* lpLayer, bool lbRequireLongPress);
};