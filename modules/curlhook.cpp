#include "../pch.h"
#include "curlhook.h"

cGcAtlasTransportWinHttp::RequestHttpAsync fpRequestHttpAsync = NULL;

void CurlHook::Init()
{
	ADDHOOK(OFFSET(0x2584C0), RequestHttpAsyncHook, reinterpret_cast<LPVOID*>(&fpRequestHttpAsync), cGcAtlasTransportWinHttp::RequestHttpAsync);
}

__int64 CurlHook::RequestHttpAsyncHook(cGcAtlasTransportWinHttp* thiscall, const Http::Request* lRequest, const std::function<cTkVector3 __cdecl(cTkVector3 const&)>* lCallback)
{
	cGcURL::ToString toString = (cGcURL::ToString)OFFSET(0x2FDD930);
	cTkFixedString<512, char>* output = new cTkFixedString<512, char>();
	const cGcURL* guh = &lRequest->mURL;

	toString((cGcURL*)guh, output, false);

	spdlog::debug("URL {}", output->macBuffer);

	return fpRequestHttpAsync(thiscall, lRequest, lCallback);
}
