#pragma once

#include "../utilities/TkString.h"

class cTkClassPointer
{
public:
	union cTkClassPointerData
	{
		void *mpClass;
		__int64 miOffset;
	};

	cTkClassPointer::cTkClassPointerData mClassData;
	cTkFixedString<63, char> mClassName;
	bool mbClassFixed;
	unsigned __int64 mClassNameHash;
};