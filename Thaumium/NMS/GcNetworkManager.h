#pragma once
#include "GcNetworkMessageManager.h"

#pragma pack(16)
class cGcNetworkManager
{
public:
	uintptr_t mpConnection;
	cGcNetworkMessageManager mMessageManager;
	char mPlayerManager[0x5B70];
	uintptr_t mpMatchmaking;
	char mInteractionManager[0xA48];
	char mMonumentManager[0x468];
	uintptr_t mpVoiceChat;
	char mTextChatManager[0x83B0];
	char mTerrainEditsManager[0x280];
	char mBaseBuildingManager[0x248];
	char mReplicatedEntityManager[0xF8];
	char mNetworkSychronizedClock[0x40];
	char mRpcManager[0x10];
	char mInteractionBufferManager[0x240];
	char mNetworkIdManager[0xC8];
	char mCreatureManager[0xE0];
	char mNetworkLockManager[0x2880];
	char mBandwidthMonitor[0xF9D0];
	char mPrivilegesManager[0x80];
	char mBaseImageManager[0x78];
	bool mbPrepared;
};