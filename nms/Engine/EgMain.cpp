#include "EgMain.h"

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

	return cEgModules::mgpResourceManager->AddResource(result, liType, lpcName, liFlags, false, lAlternateMaterialId);
}
