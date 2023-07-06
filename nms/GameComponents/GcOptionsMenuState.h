#pragma once
#include <vector>

#include "GcUIOptionListElement.h"
#include "../ToolKit/TkSTLAllocatorShim.h"

#pragma pack(8)
class cGcOptionsMenuState
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
