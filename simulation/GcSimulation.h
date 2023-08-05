#pragma once

#include "../common/resources/TkHandle.h"
#include "../common/utilities/TkString.h"
#include "../common/simulation/TkRigidBodyPtr.h"
#include "../common/utilities/allocators/TkSTLAllocator.h"
#include "GcSolarSystem.h"
#include "GcSolarSystemDirector.h"
#include "CentreJourneyDestination.h"
#include "../common/maths/TkPhysRelVec3.h"
#include "../common/system/timer/TkClock.h"
#include "../common/system/TkIterationState.h"
#include "GcPlayerRespawn.h"
#include "GcSceneManager.h"
#include "../common/system/thread/TkLockFreeQueue.h"

class ALIGN(16) cGcSimulation
{
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
	std::vector<TkHandle, TkSTLAllocatorShim<TkHandle> > maRemoveQueue;
	cTkFixedString<256, char> mCurrentScene;
	cGcScanManager mScanManager;
	cGcAvailableWeapons mAvailableWeapons;
	cGcSceneManager mSceneManager;
	cGcParticleManager mParticleManager;
	cGcEnvironment mEnvironment;
	cGcEcosystem mEcosystem;
	cGcProjectileManager mProjectileManager;
	cGcAISpaceshipManager mAISpaceshipManager;
	cGcNPCManager mNPCManager;
	cGcFullscreenEffectManager mFullscreenEffectManager;
	cGcSolarSystem* mpSolarSystem;
	cGcSolarSystemDirector* mpSolarSystemDirector;
	cGcSpaceshipWarp mWarp;
	cTkPhysRelVec3 mPortalMarkerPosition;
	eCentreJourneyDestination meRequestCentreJourney;
	cGcPlayerExperienceDirector mPlayerExperienceDirector;
	cGcPlayer mPlayer;
	cGcPlayerRespawn mPlayerRespawn;
	TkHandle mSimulationRootNode;
	TkHandle maGroupNodes[13];
	std::vector<cGcSimulation::sGroupNodeActivation, TkSTLAllocatorShim<cGcSimulation::sGroupNodeActivation> > mGroupNodeActivationStack;
	TkIterationState<1> mPrepareIterationState;
	bool mbTransitionFromGalacticMap;
	bool mbRequestGalaxyMap;
	bool mbSimulationPrepared;
	bool mbSimulationInLoadPhase;
	unsigned __int64 mCurrentUA;
	unsigned __int64 mCurrentUDA[2];
	cTkClock mMissionClock;
};