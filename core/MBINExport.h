#pragma once
#include "../common//utilities/filesystem/TkFileSystem.h"

namespace NGuiMBINExport
{
	void Init();
	FIOS2HANDLE* FileSystemOpenHook(cTkFileSystem* thiscall, const char* lpacFileName, eFileOpenMode leMode);
}