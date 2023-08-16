#pragma once
#include "../network/GcNetworkManager.h"
#include "../simulation/GcSimulation.h"

class cGcApplication
{
public:
	typedef cGcNetworkManager* (*GetNetworkManager)(cGcApplication* self);
	typedef cGcSimulation* (*GetSimulation)(cGcApplication* self);
};