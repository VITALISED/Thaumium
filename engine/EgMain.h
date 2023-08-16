#pragma once

#include "../common/resources/TkResourceDescriptor.h"
#include "../common/resources/TkSmartResHandle.h"
#include "../pch.h"
#include "EgModules.h"

namespace Engine
{
	cTkSmartResHandle *AddResource(cTkSmartResHandle *result, int liType, const char *lpcName, unsigned int liFlags, cTkResourceDescriptor *lAlternateMaterialId);
}