#pragma once

#include "../../common/attachments/TkHandle.h"
#include "../../common/graphics/TkColour.h"
#include "../../common/maths/TkAABB.h"
#include "../../common/maths/TkMatrix34.h"
#include "../../common/resources/TkSmartResHandle.h"
#include "../../common/system/TkIterationState.h"
#include "../../common/utilities/TkString.h"
#include "../DiscoveryAutoSync.h"
#include "../particles/HeavyAirType.h"
#include "../player/GcPlayerSpawnState.h"
#include "GalaxyStarAnomaly.h"
#include "GcGalacticSolarSystemAddress.h"

const class cGcSolarSystem
{
	cGcGalacticSolarSystemAddress mQueuedQuickWarpAddress;
	bool mbTriggerQuickWarp;
	cGcSolarSystemData mSolarSystemData;
	cGcSolarSystemAsteroidFields mSolarSystemInfomap;
	cGcDiscoveryData mSolarDiscoveryData;
	cGcGalaxyAttributesAtAddress mGalaxyAttributes;
	std::array<cGcPlanet, 6> maPlanets;
	int miPrimaryPlanet;
	std::array<bool, 6> mabImGuiBrowsePlanets;
	cGcAsteroidManager mAsteroidManager;
	cGcPlanetGenerator mPlanetGenerator;
	cGcSolarSystemGenerator mSolarSystemGenerator;
	TkHandle mPlanetRootNode;
	TkHandle mRootNode;
	TkHandle mSpaceStationNode;
	cTkMatrix34 mSpaceStationSpawnTM;
	cTkMatrix34 mSpaceStationInteriorTMInverse;
	cTkAABB mSpaceStationInteriorOBB;
	cTkAABB mSpaceStationOBB;
	bool mbSpaceStationSSREnabled;
	cGcScanEffectData mPreviewNexusScanData;
	cTkColour mPreviewNexusColour;
	float mfPreviewNexusFirstActiveTime;
	float mfPreviewNexusLastActiveTime;
	bool mbShowNexusExteriorPreview;
	TkHandle mPreviewNexusExteriorNode;
	TkHandle mNexusEntranceNode;
	TkHandle mNexusExteriorNode;
	TkHandle mNexusExteriorTeleportNode;
	cTkAABB mNexusExteriorOBB;
	cTkClassPoolHandle mNexusExteriorInvalidAsteroidArea;
	bool mbLoadedNexus;
	TkHandle mNexusLoadingTask;
	cGcWarpEffect mNexusExteriorWarpEffect;
	TkAddNodesHandle mAddNodesHandle;
	TkHandle mNexusNode;
	cTkMatrix34 mNexusSpawnTM;
	cTkMatrix34 mNexusEntranceTM;
	cTkMatrix34 mNexusTMInverse;
	cTkAABB mNexusOBB;
	TkHandle mSpaceStationEntranceNode;
	cTkMatrix34 mSpaceStationEntranceTM;
	float mfOrbitHeight;
	cTkSmartResHandle mSpaceStationRes;
	cTkSmartResHandle mNexusRes;
	cTkSmartResHandle mNexusExteriorRes;
	cTkSmartResHandle mAnomalyRes;
	cTkSmartResHandle mStartingSceneRes;
	cTkSmartResHandle mHeavyAirRes;
	TkHandle mAnomalyNode;
	cTkAABB mAnomalyOBB;
	cTkMatrix34 mAnomalySpawnTM;
	cTkMatrix34 mAnomalyInteriorTMInverse;
	cTkAABB mAnomalyInteriorOBB;
	eGalaxyStarAnomaly meAnomalyType;
	cGcPlayerSpawnStateData mGeneratedPlayerSpawn;
	unsigned __int64 mu64NextSeed;
	int miSpaceStationGenerationCounter;
	eHeavyAirType meHeavyAir;
	cTkFixedString<256, char> mFilename;
	cTkMatrix34 mLastKnownPlayerTransform;
	bool mbInOrbit;
	bool mbImGuiTerrainDataMinCollpased;
	bool mbImGuiTerrainDataMaxCollpased;
	bool mbImGuiTerrainDataCollpased;
	bool mbFirstBoot;
	bool mbLoadedFromSettings;
	bool mbAnomalyWarpingActive;
	TkIterationState<2> mPrepareIterationState;
	DiscoveryAutoSync mDiscoveryAutoSync;
	cTkVector3 mNGuiCameraPosition;
	cTkVector3 mNGuiPlanetPosition;
	cGcAsteroidLayout mDebugAsteroidGeneratorLayout;
	cGcGalacticSolarSystemAddress mRequestedQuickJump;
	int miPrevLoadBalancingTimeout;
	float mfPlanetPrepareTime;
};