#include "EgModules.h"

cTkResourceManager* cEgModules::mgpResourceManager;

void cEgModules::Initialise()
{
	mgpResourceManager = (cTkResourceManager*)OFFSET(0x4EB6AC8);
}