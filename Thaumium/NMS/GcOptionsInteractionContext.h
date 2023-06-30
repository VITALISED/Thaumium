#pragma once
#include "GcNGuiLayer.h"

class cGcOptionsInteractionContext
{
	/*cGcFrontendPage*/void* mpPage;
	/*cGcLayerInteractControl*/void* mpLayerInteractionControl;
	cGcNGuiLayer* mpPageLayer;
	char mCount[0x50];
	bool mbConstructed;
};