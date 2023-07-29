#pragma once

#include <vector>
#include "../Simulation/TkSeed.h"
#include "../Metadata/TkID.h"
#include "../Utilities/Memory/TkSTLAllocatorShim.h"

class cTkResourceDescriptor
{
	std::vector<TkID<256>, TkSTLAllocatorShim<TkID<256> > > maDescriptors;
	cTkSeed mSeed;
	cTkSeed mSecondarySeed;
};