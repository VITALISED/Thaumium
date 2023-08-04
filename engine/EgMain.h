#pragma once

#include "../pch.h"

#include "EgModules.h"

#include "../common/resources/TkSmartResHandle.h"
#include "../common/resources/TkResourceDescriptor.h"

namespace Engine
{
	cTkSmartResHandle* AddResource(cTkSmartResHandle* result, int liType, const char* lpcName, unsigned int liFlags, cTkResourceDescriptor* lAlternateMaterialId);
}