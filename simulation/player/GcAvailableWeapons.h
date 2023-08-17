#pragma once

#include "../../common/resources/TkSmartResHandle.h"
#include "../../common/utilities/containers/TkVector.h"

class cGcAvailableWeapons
{
	class cGcAvailableWeaponInfo
	{
		cTkSmartResHandle mWeaponResource;
		bool mbIsSecret;
	};

	cTkVector<cGcAvailableWeapons::cGcAvailableWeaponInfo> maAvailableWeapons;
};
