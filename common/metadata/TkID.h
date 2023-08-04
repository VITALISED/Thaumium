#pragma once

template<int size>
union TkID
{
	TkID()
	{ }
	TkID(const char* lacString)
	{
		// uses hashes pretty sure, gonna have to figure out spookyhash later
		strcpy_s(mChars, size, lacString);
	}

	char mChars[size / 8];
	unsigned __int64 mUInt64[size / 64];
};