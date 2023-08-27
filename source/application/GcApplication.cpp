#include "GcApplication.h"

cGcNetworkManager *cGcApplication::GetNetworkManager()
{
    cGcApplication::_GetNetworkManager fpGetNetworkManager = (cGcApplication::_GetNetworkManager)OFFSET(0x1C2910);
    return fpGetNetworkManager(Globals::gGcApplication);
}