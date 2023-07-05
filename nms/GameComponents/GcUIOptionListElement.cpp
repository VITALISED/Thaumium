#include "../pch.h"
#include "../util/memory.h"
#include "GcUIOptionListElement.h"

void cGcUIOptionListElement::SetEnabled(bool lbEnabled)
{
	this->mbEnabled = lbEnabled;
	cGcNGuiLayer::FindLayerRecursive findLayerRecursive = (cGcNGuiLayer::FindLayerRecursive)OFFSET(0x000000);
	TkID<128> lID;
	cGcNGuiLayer* LayerRecursive = findLayerRecursive(this->mpElement, &lID);

	TKIDSTR(lID, "BUTTONRIGHT");
	LayerRecursive = findLayerRecursive(this->mpElement, &lID);

	if (LayerRecursive)
	{
		TKIDSTR(lID, "DISABLED");
		findLayerRecursive(LayerRecursive, &lID)->mpElementData->mbIsHidden = lbEnabled;
	}

	TKIDSTR(lID, "BUTTONLEFT");
	LayerRecursive = findLayerRecursive(this->mpElement, &lID);

	if (LayerRecursive)
	{
		TKIDSTR(lID, "DISABLED");
		findLayerRecursive(LayerRecursive, &lID)->mpElementData->mbIsHidden = lbEnabled;
	}

	TKIDSTR(lID, "BUTTONMAIN");
	LayerRecursive = findLayerRecursive(this->mpElement, &lID);
	if (LayerRecursive)
	{
		TKIDSTR(lID, "DISABLED");
		findLayerRecursive(LayerRecursive, &lID)->mpElementData->mbIsHidden = lbEnabled;
	}
}