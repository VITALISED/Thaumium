#pragma once

#include <functional>
#include "../atlas/Http.h"
#include "../common/maths/TkVector3.h"

class cGcAtlasTransportWinHttp
{
public:
	typedef __int64(*RequestHttpAsync)(cGcAtlasTransportWinHttp* thiscall, const Http::Request* lRequest, const std::function<cTkVector3 __cdecl(cTkVector3 const&)>* lCallback);
};