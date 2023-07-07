#include "../pch.h"
#include "../util/memory.h"
#include "GcUIOptionListElement.h"

void cGcUIOptionListElement::SetEnabled(bool lbEnabled)
{
	this->mbEnabled = lbEnabled;
	TkID<128> lID;
	cGcNGuiLayer* LayerRecursive;

	TKIDSTR(lID, "BUTTONRIGHT");
	LayerRecursive = this->mpElement->FindLayerRecursive(&lID);

	if (LayerRecursive)
	{
		TKIDSTR(lID, "DISABLED");
		LayerRecursive->FindLayerRecursive(&lID)->mpElementData->mbIsHidden = lbEnabled;
	}

	TKIDSTR(lID, "BUTTONLEFT");
	LayerRecursive = this->mpElement->FindLayerRecursive(&lID);

	if (LayerRecursive)
	{
		TKIDSTR(lID, "DISABLED");
		LayerRecursive->FindLayerRecursive(&lID)->mpElementData->mbIsHidden = lbEnabled;
	}

	TKIDSTR(lID, "BUTTONMAIN");
	LayerRecursive = this->mpElement->FindLayerRecursive(&lID);
	if (LayerRecursive)
	{
		TKIDSTR(lID, "DISABLED");
		LayerRecursive->FindLayerRecursive(&lID)->mpElementData->mbIsHidden = lbEnabled;
	}
}