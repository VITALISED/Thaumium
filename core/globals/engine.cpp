#include "globals.h"

cTkResourceManager* cEgModules::mgpResourceManager;

void Globals::SetEngineDefaults()
{
	mgpResourceManager = (cTkResourceManager*)OFFSET(0x4EB6AC8);
}