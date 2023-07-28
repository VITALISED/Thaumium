#pragma once
#include <vector>

#include "GcUIOptionListElement.h"
#include "../nms/ToolKit/Utilities/Memory/TkSTLAllocatorShim.h"
#include "../pch.h"

class ALIGN(8) cGcOptionsMenuState
{
public:
	cGcOptionsMenuState(int type, std::vector<cGcUIOptionListElement*, TkSTLAllocatorShim<cGcUIOptionListElement*> > items)
	{
		mItems = items;
		meType = type;
	}
	std::vector<cGcUIOptionListElement*, TkSTLAllocatorShim<cGcUIOptionListElement*> > mItems;
	int meType;
};
