#pragma once
#include "../../atlas/GcAtlasDownloadType.h"

enum eFrigateFlybyType
{
	EFrigateFlybyType_SingleShip = 0x0,
	EFrigateFlybyType_AmbientGroup = 0x1,
	EFrigateFlybyType_ScriptedGroup = 0x2,
	EFrigateFlybyType_DeepSpace = 0x3,
	EFrigateFlybyType_DeepSpaceCommon = 0x4,
	EFrigateFlybyType_NumTypes = 0x5,
	EFrigateFlybyType_Unspecified = 0xFFFFFFFF,
};

class cGcFrigateFlybyType
{
public:
	eFrigateFlybyType meFrigateFlybyType;

	void SetDefaults();
};