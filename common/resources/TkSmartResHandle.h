#pragma once

#include "../utilities/TkStrongType.h"

class cTkSmartResHandle
{
public:
	TkStrongType<int, TkStrongTypeIDs::TkResHandleID> miInternalHandle;
};