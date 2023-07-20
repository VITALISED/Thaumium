#pragma once

#define TKIDSTR(lID, chars)	for (int i = 0; i < strlen(chars); i++)				\
								{													\
									lID.mChars[i] = chars[i];						\
									int val = 0x19;									\
									if((chars - 97) <= (const char*)&val)			\
										lID.mChars[i] = (char)(*chars - (char)32);	\
								}													\
								lID.mChars[15] = 0;									\



template<int size>
union TkID
{
	char mChars[size / 8];
	unsigned __int64 mUInt64[size / 64];
};