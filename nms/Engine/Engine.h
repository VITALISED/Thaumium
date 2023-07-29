#pragma once

#include "../pch.h"

#include "EgModules.h"

#include "../nms/ToolKit/Resources/TkSmartResHandle.h"
#include "../nms/ToolKit/Resources/TkResourceDescriptor.h"

namespace Engine
{
	cTkSmartResHandle* AddResource(cTkSmartResHandle* result, int liType, const char* lpcName, unsigned int liFlags, cTkResourceDescriptor* lAlternateMaterialId);
}