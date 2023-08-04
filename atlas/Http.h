#pragma once

#include <vector>
#include <iostream>
#include <Havok/hknpShapeKeyMask.h>

#include "../network/GcURL.h"
#include "../simulation/GcPlayer.h"
#include "../common/utilities/TkArray.h"
#include "../common/utilities/allocators/TkSTLAllocator.h"

struct Http
{
	typedef hknpShapeKeyMask::Type::Enum Verb;

	struct KnownHeader
	{
		typedef WinHttpTask::State::Enum Enum;
	};

	struct Request
	{
		typedef cGcPlayer::eRocketBootsDoubleTapState PostDataType;

		cGcURL mURL;
		unsigned __int64 mu64UserData;
		cTkDynamicArray<char> mPostData;
		Http::Request::PostDataType mePostDataType;
		Http::Verb meVerb;
		std::vector<std::pair<Http::KnownHeader::Enum, std::string >, TkSTLAllocatorShim<std::pair<Http::KnownHeader::Enum, std::string > > > mCustomHeaders;
	};
};
