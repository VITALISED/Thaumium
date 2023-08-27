#pragma once

#include "../../common/maths/TkMatrix34.h"
#include "../../common/resources/TkHandle.h"
#include "../../common/utilities/TkStrongType.h"
#include "../../pch.h"

class cTkEngineUtils
{
private:
	typedef TkHandle *(*_AddNodes)(TkHandle *result, TkHandle lBaseNode, TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lResourceHandle, const cTkMatrix34 *lStartMatrix, TkHandle lbRelative);

public:
	static TkHandle *AddNodes(TkHandle *result,
							  TkHandle lBaseNode,
							  TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lResourceHandle,
							  const cTkMatrix34 *lStartMatrix,
							  TkHandle lbRelative)
	{
		cTkEngineUtils::_AddNodes fpAddNodes = (cTkEngineUtils::_AddNodes)SIGSCAN("48 8B C4 48 89 58 08 48 89 70 18 55 57 41 56 48 8D 68 88");
		return fpAddNodes(result, lBaseNode, lResourceHandle, lStartMatrix, lbRelative);
	}
};