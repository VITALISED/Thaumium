#pragma once
#include "../framework.h"
#include <vector>
#include "GcUIOptionListElement.h"
#include "TkSTLAllocatorShim.h"

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

static_assert(sizeof(std::vector<cGcUIOptionListElement*, TkSTLAllocatorShim<cGcUIOptionListElement*> >) == 0x20, "invalid class size");