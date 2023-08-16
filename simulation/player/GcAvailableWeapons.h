#pragma once

#include "../common/resources/TkSmartResHandle.h"
#include "../common/utilities/allocators/TkSTLAllocator.h"
#include <vector>

class cGcAvailableWeapons
{
	class cGcAvailableWeaponInfo
	{
		cTkSmartResHandle mWeaponResource;
		bool mbIsSecret;
	};

	std::vector<cGcAvailableWeapons::cGcAvailableWeaponInfo, TkSTLAllocatorShim<cGcAvailableWeapons::cGcAvailableWeaponInfo>> maAvailableWeapons;
};
