#pragma once
#include "../network/GcNetworkManager.h"
#include "../simulation/GcSimulation.h"

class cGcApplication
{
public:
	typedef cGcNetworkManager* (*GetNetworkManager)(cGcApplication* _this);
	typedef cGcSimulation* (*GetSimulation)(cGcApplication* thisptr);
};