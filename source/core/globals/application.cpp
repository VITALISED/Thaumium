#include "globals.h"

// cGcApplication *Globals::gGcApplication;

void Globals::SetApplicationDefaults()
{
    Globals::gGcApplication = (cGcApplication *)OFFSET(0x463F810);
}