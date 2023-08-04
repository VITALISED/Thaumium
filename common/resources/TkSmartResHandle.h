#pragma once

#include "../utilities/TkStrongType.h"

class cTkSmartResHandle
{
	TkStrongType<int, TkStrongTypeIDs::TkResHandleID> miInternalHandle;
};