#pragma once

template<int size>
union TkID
{
	char mChars[size / 8];
	unsigned __int64 mUInt64[size / 64];
};