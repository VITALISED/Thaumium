#pragma once
#include "../nms/ToolKit/TkFileSystem.h"


namespace NGuiMBINExport
{
	void Init();
	FIOS2HANDLE* FileSystemOpenHook(cTkFileSystem* thiscall, const char* lpacFileName, eFileOpenMode leMode);
}