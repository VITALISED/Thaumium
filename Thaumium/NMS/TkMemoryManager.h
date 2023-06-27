#pragma once

class cTkMemoryManager
{
public:
	typedef void*(__fastcall* Malloc)(cTkMemoryManager* _this, int liSize, const char* lpacFile, int liLined, const char* lpacFunction, int liAlign, int liPool);
};