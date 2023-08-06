#pragma once

#include "../common/resources/TkHandle.h"
#include "../common/utilities/TkStrongType.h"
#include "../common/maths/TkMatrix.h"
#include "../pch.h"

class cTkEngineUtils
{
public:
	static TkHandle* AddNodes(TkHandle* result,
		TkHandle lBaseNode,
		TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lResourceHandle,
		const cTkMatrix34* lStartMatrix, 
		TkHandle lbRelative)
	{
		MAKE_FUNCTION_TYPE(__redirType, TkHandle*, TkHandle*, TkHandle, TkStrongType<int, TkStrongTypeIDs::TkResHandleID>, const cTkMatrix34*, TkHandle);
		DECLARE_METHOD_REDIR(SIGSCAN(48 8B C4 48 89 58 08 48 89 70 18 55 57 41 56 48 8D 68 88),
			__redirType, TkHandle* cTkEngineUtils::AddNodes,
			result, lBaseNode, lResourceHandle, lStartMatrix, lbRelative);
	}
};