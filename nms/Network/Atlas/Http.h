#pragma once

#include <vector>
#include <iostream>

#include "../nms/Havok/hknpShapeKeyMask.h"
#include "../nms/Network/GcURL.h"
#include "../nms/Simulation/GcPlayer.h"
#include "../nms/ToolKit/Utilities/TkArray.h"
#include "../nms/ToolKit/Utilities/Memory/TkSTLAllocatorShim.h"

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
