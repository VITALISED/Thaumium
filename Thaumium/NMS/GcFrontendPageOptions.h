#pragma once
#include "GcUIOptionListElement.h"

class cGcFrontendPageOptions
{
public:
	typedef cGcUIOptionListElement** (__fastcall* PrepareBootScreenNetworkOptions)();
};