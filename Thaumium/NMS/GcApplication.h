#pragma once
#include "NMS/GcNetworkManager.h"

class cGcApplication
{
public:
	typedef cGcNetworkManager* (__fastcall* GetNetworkManager)(cGcApplication* _this);
};