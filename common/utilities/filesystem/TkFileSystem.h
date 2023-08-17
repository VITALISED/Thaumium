#pragma once

#include "FIOS2HANDLE.h"
#include "FileOpenMode.h"

class cTkFileSystem
{
public:
	typedef FIOS2HANDLE *(*Open)(cTkFileSystem *self, const char *lpacFileName, eFileOpenMode leMode);
	typedef void (*CreatePath)(cTkFileSystem *self, const char *lpacPath);
};