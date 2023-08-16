#pragma once

#include "../../application/GcApplication.h"
#include "../../engine/EgModules.h"

namespace Globals
{
    void SetEngineDefaults();
    void SetApplicationDefaults();

    cGcApplication* GetGcApplication();

    static cGcApplication* gGcApplication;
    // we access cEgModules directly after initialising it, no need to call it here
}