#include "GcApplication.h"

cGcNetworkManager *cGcApplication::GetNetworkManager()
{
    cGcApplication::_GetNetworkManager fpGetNetworkManager = (cGcApplication::_GetNetworkManager)OFFSET(0x1C2910);
}

cGcSimulation *cGcApplication::GetSimulation()
{
    cGcApplication::_GetSimulation fpGetNetworkManager = (cGcApplication::_GetSimulation)OFFSET(0x1C3760);
}