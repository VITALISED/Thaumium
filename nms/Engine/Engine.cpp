#include "Engine.h"

cTkSmartResHandle* Engine::AddResource(
	cTkSmartResHandle* result,
	int liType,
	const char* lpcName,
	unsigned int liFlags,
	cTkResourceDescriptor* lAlternateMaterialId)
{
	if (!lpcName || !*lpcName)
	{
		spdlog::error("Trying to add resource file without filename");
	}

	cEgModules::mgpResourceManager
}
