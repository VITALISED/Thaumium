#pragma once

#define TKIDSTR(lID, chars)	{														\
								for (int i = 0; i < 9; i++)							\
								{													\
									lID.mChars[i] = chars[i];						\
										if ((unsigned __int8)(chars - 97) <= 0x19u)	\
										lID.mChars[i] = *(char*)chars - 32;			\
								}													\
								lID.mChars[15] = 0;									\
							}

template<int size>
union TkID
{
	char mChars[size / 8];
	unsigned __int64 mUInt64[size / 64];
};