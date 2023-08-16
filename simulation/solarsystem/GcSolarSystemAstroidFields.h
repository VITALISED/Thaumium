#pragma once

#include "../pch.h"
#include "../common/maths/TkMatrix.h"
#include "../common/utilities/allocators/TkSTLAllocator.h"

class cGcSolarSystemAsteroidFields
{
	struct cGcSolarSystemAsteroidFields::AsteroidGenerators
	{
		std::vector<cGcAsteroidGeneratorRing, TkSTLAllocatorShim<cGcAsteroidGeneratorRing> > mRings;
		std::vector<cGcAsteroidGeneratorSurround, TkSTLAllocatorShim<cGcAsteroidGeneratorSurround> > mSurrounds;
		std::vector<cGcAsteroidGeneratorSlab, TkSTLAllocatorShim<cGcAsteroidGeneratorSlab> > mSlabs;
	};

	cTkMatrix34 mPlayerSpawnTM;
	cGcSolarSystemAsteroidFields::AsteroidGenerators mAsteroidGenerators;
	cGcAsteroidLayout mAsteroids;
};