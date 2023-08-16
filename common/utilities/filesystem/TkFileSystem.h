#pragma once

#include "FIOS2HANDLE.h"
#include "FileOpenMode.h"

class cTkFileSystem
{
public:
	typedef FIOS2HANDLE *(*Open)(cTkFileSystem *thiscall, const char *lpacFileName, eFileOpenMode leMode);
	typedef void (*CreatePath)(cTkFileSystem *thiscall, const char *lpacPath);
};