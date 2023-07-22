#pragma once

#include <functional>
#include "../Atlas/Http.h"
#include "../ToolKit/TkVector3.h"

class cGcAtlasTransportWinHttp
{
public:
	typedef __int64(*RequestHttpAsync)(cGcAtlasTransportWinHttp* thiscall, const Http::Request* lRequest, const std::function<cTkVector3 __cdecl(cTkVector3 const&)>* lCallback);
};