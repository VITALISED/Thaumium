#pragma once
#include "../graphics/TkColour.h"
#include "../common/utilities/TkString.h"
#include "../common/resources/TkHandle.h"
#include "../common/maths/TkMatrix.h"
#include "../common/resources/TkSmartResHandle.h"
#include "../common/system/TkIterationState.h"
#include "GcPlayerSpawnState.h"
#include "../common/maths/TkAABB.h"
#include "DiscoveryAutoSync.h"
#include "GcGalacticSolarSystemAddress.h"

const class cGcSolarSystem
{
	cGcGalacticSolarSystemAddress mQueuedQuickWarpAddress;
	bool mbTriggerQuickWarp;
	cGcSolarSystemData mSolarSystemData;
	cGcSolarSystemAsteroidFields mSolarSystemInfomap;
	cGcDiscoveryData mSolarDiscoveryData;
	ALIGN(16) cGcGalaxyAttributesAtAddress mGalaxyAttributes;
	std::array<cGcPlanet, 6> maPlanets;
	int miPrimaryPlanet;
	std::array<bool, 6> mabImGuiBrowsePlanets;
	ALIGN(8) cGcAsteroidManager mAsteroidManager;
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