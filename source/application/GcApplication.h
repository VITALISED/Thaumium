#pragma once

#include "../core/globals/globals.h"
#include "../network/GcNetworkManager.h"

class cGcApplication
{
private:
	typedef cGcNetworkManager *(*_GetNetworkManager)(cGcApplication *self);

public:
	cGcNetworkManager *GetNetworkManager();
};