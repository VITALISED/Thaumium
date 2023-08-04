#pragma once
#include "../network/GcNetworkManager.h"

class cGcApplication
{
public:
	typedef cGcNetworkManager* (__fastcall* GetNetworkManager)(cGcApplication* _this);
};