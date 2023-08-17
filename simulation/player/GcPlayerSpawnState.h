#pragma once

#include "../../common/maths/TkVector4.h"

enum eLastKnownPlayerState : __int32
{
	ELastKnownPlayerState_OnFoot = 0x0,
	ELastKnownPlayerState_InShip = 0x1,
	ELastKnownPlayerState_InStation = 0x2,
	ELastKnownPlayerState_AboardFleet = 0x3,
	ELastKnownPlayerState_InNexus = 0x4,
	ELastKnownPlayerState_AbandonedFreighter = 0x5,
	ELastKnownPlayerState_InShipLanded = 0x6,
	ELastKnownPlayerState_NumTypes = 0x7,
};

class cGcPlayerSpawnStateData
{
	cTkVector4 mPlayerPositionInSystem;
	cTkVector4 mPlayerTransformAt;
	cTkVector4 mPlayerDeathRespawnPositionInSystem;
	cTkVector4 mPlayerDeathRespawnTransformAt;
	cTkVector4 mShipPositionInSystem;
	cTkVector4 mShipTransformAt;
	eLastKnownPlayerState meLastKnownPlayerState;
	cTkVector4 mFreighterPositionInSystem;
	cTkVector4 mFreighterTransformAt;
	cTkVector4 mFreighterTransformUp;
	cTkVector4 mAbandonedFreighterPositionInSystem;
	cTkVector4 mAbandonedFreighterTransformAt;
	cTkVector4 mAbandonedFreighterTransformUp;
};
