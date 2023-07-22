#pragma once

#include <vector>
#include <iostream>

#include "../GameComponents/GcURL.h"
#include "../ToolKit/TkDynamicArray.h"
#include "../ToolKit/TkSTLAllocatorShim.h"
#include "../GameComponents/GcPlayer.h"
#include "../Havok/hknpShapeKeyMask.h"

struct Http
{
	typedef hknpShapeKeyMask::Type::Enum Http::Verb;

	struct KnownHeader
	{
		typedef WinHttpTask::State::Enum Enum;
	};

	const struct Request
	{
		typedef cGcPlayer::eRocketBootsDoubleTapState Http::Request::PostDataType;

		cGcURL mURL;
		unsigned __int64 mu64UserData;
		cTkDynamicArray<char> mPostData;
		Http::Request::PostDataType mePostDataType;
		Http::Verb meVerb;
		std::vector<std::pair<Http::KnownHeader::Enum, std::string >, TkSTLAllocatorShim<std::pair<Http::KnownHeader::Enum, std::string > > > mCustomHeaders;
	};
};
