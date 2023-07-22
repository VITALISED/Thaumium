#pragma once

#include "../nms/GameComponents/GcAtlasTransportWinHttp.h"

namespace CurlHook
{
	void Init();
	__int64 RequestHttpAsyncHook(cGcAtlasTransportWinHttp* thiscall, const Http::Request* lRequest, const std::function<cTkVector3 __cdecl(cTkVector3 const&)>* lCallback);
}