#pragma once
#include "../GcNGuiLayer.h"

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