#pragma once
#include "GcUIOptionListElement.h"
#include <vector>
#include "TkSTLAllocatorShim.h"

class cGcFrontendPageOptions
{
public:
	typedef cGcUIOptionListElement** (__fastcall* PrepareBootScreenNetworkOptions)();
};