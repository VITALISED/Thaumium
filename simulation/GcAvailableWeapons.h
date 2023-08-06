#pragma once

#include <vector>

#include "../common/utilities/allocators/TkSTLAllocator.h"
#include "../common/resources/TkSmartResHandle.h"

class cGcAvailableWeapons
{
	class cGcAvailableWeaponInfo
	{
		cTkSmartResHandle mWeaponResource;
		bool mbIsSecret;
	};

	std::vector<cGcAvailableWeapons::cGcAvailableWeaponInfo, TkSTLAllocatorShim<cGcAvailableWeapons::cGcAvailableWeaponInfo > > maAvailableWeapons;
};
