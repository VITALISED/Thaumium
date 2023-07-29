#pragma once

#include "../Utilities/TkStrongType.h"
#include "../Utilities/TkStrongTypeIDs.h"

class cTkSmartResHandle
{
	TkStrongType<int, TkStrongTypeIDs::TkResHandleID> miInternalHandle;
};