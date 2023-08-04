#include "../pch.h"
#include "MBINExport.h"

cTkFileSystem::Open fpOpen = NULL;

void NGuiMBINExport::Init()
{
	ADDHOOK(OFFSET(0x2FF8A50), FileSystemOpenHook, reinterpret_cast<LPVOID*>(&fpOpen), cTkFileSystem::Open);
}

FIOS2HANDLE* NGuiMBINExport::FileSystemOpenHook(cTkFileSystem* thiscall, const char* lpacFileName, eFileOpenMode leMode)
{
	FIOS2HANDLE* result = fpOpen(thiscall, lpacFileName, leMode);

	if (leMode == EFOM_Write && result == NULL)
	{
		std::string fileName = lpacFileName;
		if (fileName.rfind(".", 0) == std::string::npos)
		{
			//invalid open call, happens in some places namely mxml writes which spit out mbin, we obviously want tasty mbins.
			fileName.insert(0, "../Exported/");
			size_t pos = fileName.find_last_of("\\/");
			if (pos != std::string::npos)
			{
				std::string path = fileName.substr(0, pos);
				cTkFileSystem::CreatePath createPath = (cTkFileSystem::CreatePath)OFFSET(0x2FF8A50);
				createPath(thiscall, path.c_str());
			}

			spdlog::debug(fileName.c_str());
			spdlog::debug(lpacFileName);
			return fpOpen(thiscall, fileName.c_str(), leMode);
		}
	}

	return fpOpen(thiscall, lpacFileName, leMode);
}