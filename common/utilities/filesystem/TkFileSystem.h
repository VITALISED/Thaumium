#pragma once

#include <libSceFios2/sceFios2.h>

enum eFileOpenMode : __int32
{
	EFOM_Read = 0x0,
	EFOM_Write = 0x1,
	EFOM_Append = 0x2,
};

class cTkFileSystem
{
public:
	typedef FIOS2HANDLE *(*Open)(cTkFileSystem *self, const char *lpacFileName, eFileOpenMode leMode);
	typedef void (*CreatePath)(cTkFileSystem *self, const char *lpacPath);
};