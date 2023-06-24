#pragma once
#include "GcNetworkMessageManager.h"

class __declspec(align(16)) cGcNetworkManager
{
public:
	int* mpConnection;
	cGcNetworkMessageManager mMessageManager;
	char mPlayerManager[0x5B70];
	int* mpMatchmaking;
	char mInteractionManager[0xA48];
	char mMonumentManager[0x468];
	int* mpVoiceChat;
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