#pragma once
#include "../nms/Network/GcNetworkManager.h"

class cGcApplication
{
public:
	typedef cGcNetworkManager* (__fastcall* GetNetworkManager)(cGcApplication* _this);
};