#pragma once
#include "GcNetworkManager.h"

class cGcApplication
{
public:
	typedef cGcNetworkManager* (__fastcall* GetNetworkManager)(cGcApplication* _this);
};