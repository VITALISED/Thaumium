#pragma once

#include "../common/resources/TkHandle.h"
#include "../common/resources/TkSmartResHandle.h"
#include "../common/utilities/TkString.h"
#include "../common/utilities/allocators/TkSTLAllocator.h"
#include "../metadata/simulation/GcSceneSettings.meta.h"

struct cGcSceneManager
{
	cGcSceneSettings *mpSettings;
	cTkFixedString<256, char> mCurrentScene;
	TkHandle mSceneNode;
	TkHandle mSpawnNode;
	TkHandle mLightNode;
	std::vector<TkHandle, TkSTLAllocatorShim<TkHandle>> maPlanetSceneNodes;
	cTkSmartResHandle maTrailResources[5];
	cTkSmartResHandle mDefaultTrailRes;
	cTkSmartResHandle maShipFlares[5];
	cTkSmartResHandle mDefaultShipFlareRes;
	cTkSmartResHandle mContrailRes;
	cTkSmartResHandle mMechContrailRes;
	cTkSmartResHandle mMechFoortprintRes;
	cTkSmartResHandle mMissileTrailRes;
	cTkSmartResHandle mAtmosphereGlowRes;
	cTkSmartResHandle mAtmosphereSmokeRes;
	cTkSmartResHandle mLandingSmokeRes;
	cTkSmartResHandle mSpeedCool;
	cTkSmartResHandle mSpeedCoolReverse;
	cTkSmartResHandle mDeathDropRes;
	cTkSmartResHandle mDeathDropSpaceRes;
	cTkSmartResHandle mTeleportEndEffectRes;
	cTkSmartResHandle mTeleportTravelEffectRes;
	cTkSmartResHandle mControllerLeftRes;
	cTkSmartResHandle mControllerRightRes;
	cTkSmartResHandle mLightMaterial;
	bool mbPendingSolarSystemRegenerate;
};