#pragma once

#include "../common/attachments/TkHandle.h"
#include "../common/maths/TkPhysRelVec3.h"
#include "../common/simulation/TkRigidBodyPtr.h"
#include "../common/system/TkIterationState.h"
#include "../common/system/thread/TkLockFreeQueue.h"
#include "../common/system/timer/TkClock.h"
#include "../common/utilities/TkString.h"
#include "../common/utilities/allocators/TkSTLAllocator.h"
#include "CentreJourneyDestination.h"
#include "GcAvailableWeapons.h"
#include "GcPlayerRespawn.h"
#include "GcSceneManager.h"
#include "GcSolarSystem.h"
#include "GcSolarSystemDirector.h"

class ALIGN(16) cGcSimulation
{
public:
	struct sGroupNodeActivation
	{
		bool mabGroupNodeActivation[13];
	};

	struct DestructionPair
	{
		cTkRigidBodyPtr mDestroyed;
		cTkRigidBodyPtr mDestroyer;
	};

	cTkInplaceLockFreeQueue<cGcSimulation::DestructionPair, 1024> gDestroyedInstanceQueue;
	cTkInplaceLockFreeQueue<cGcSimulation::DestructionPair, 1024> gDestroyedCreatureQueue;
	std::vector<TkHandle, TkSTLAllocatorShim<TkHandle>> maRemoveQueue;
	cTkFixedString<256, char> mCurrentScene;
	/*cGcScanManager*/ char mScanManager[0x2300];
	cGcAvailableWeapons mAvailableWeapons;
	cGcSceneManager mSceneManager;
	/*cGcParticleManager*/ char mParticleManager[0x851A0];
	/*cGcEnvironment*/ char mEnvironment[0xF40];
	/*cGcEcosystem*/ char mEcosystem[0x48660];
	/*cGcProjectileManager*/ char mProjectileManager[0x118340];
	/*cGcAISpaceshipManager*/ char mAISpaceshipManager[0x5CA10];
	/*cGcNPCManager*/ char mNPCManager[0xE0];
	/*cGcFullscreenEffectManager*/ char mFullscreenEffectManager[0x1D0];
	cGcSolarSystem *mpSolarSystem;
	cGcSolarSystemDirector *mpSolarSystemDirector;
	/*cGcSpaceshipWarp*/ char mWarp[0x590];
	cTkPhysRelVec3 mPortalMarkerPosition;
	eCentreJourneyDestination meRequestCentreJourney;
	/*cGcPlayerExperienceDirector*/ char mPlayerExperienceDirector[0x1590];
	/*cGcPlayer*/ char mPlayer[0x5D70];
	cGcPlayerRespawn mPlayerRespawn;
	TkHandle mSimulationRootNode;
	TkHandle maGroupNodes[13];
	std::vector<cGcSimulation::sGroupNodeActivation, TkSTLAllocatorShim<cGcSimulation::sGroupNodeActivation>> mGroupNodeActivationStack;
	TkIterationState<1> mPrepareIterationState;
	bool mbTransitionFromGalacticMap;
	bool mbRequestGalaxyMap;
	bool mbSimulationPrepared;
	bool mbSimulationInLoadPhase;
	unsigned __int64 mCurrentUA;
	unsigned __int64 mCurrentUDA[2];
	cTkClock mMissionClock;
};