#pragma once

#include "../atlas/WinHttpTask.h"
#include "../common/utilities/TkString.h"
#include "../common/utilities/containers/TkStackVector.h"

class cGcURL
{
public:
	typedef char (*_ToString)(cGcURL *self, cTkFixedString<512, char> *lURLStringOutput, bool lbJustPathAndQuery);

	struct Scheme
	{
		typedef WinHttpTask::State::Enum Enum;
	};

	cGcURL::Scheme::Enum meScheme;
	cTkFixedString<32, char> mSchemeText;
	cTkFixedString<128, char> mHostname;
	int miPort;
	cTkStackVector<cTkFixedString<160, char>> mPath;
	cTkStackVector<cTkFixedString<160, char>> mQuery;
};