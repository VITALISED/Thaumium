#pragma once
#include "../network/GcNetworkManager.h"
#include "../simulation/GcSimulation.h"

class cGcApplication
{
private:
	typedef cGcNetworkManager *(*_GetNetworkManager)(cGcApplication *self);
	typedef cGcSimulation *(*_GetSimulation)(cGcApplication *self);

public:
	cGcSimulation *GetSimulation();
	cGcNetworkManager *GetNetworkManager();
};