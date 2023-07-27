#pragma once
#include "../ToolKit/TkDynamicArray.h"

class cGcPlayerControlInput
{
public:
	bool mbInterceptAllInputs;
	cTkDynamicArray</*cGcInputActions*/char[0x4]> maInterceptInputWhitelist;
	cTkDynamicArray</*cGcInputActions*/char[0x4]> maInterceptInputBlackList;
	cTkDynamicArray</*cTkClassPointer*/char[0x50]> maInputs;
	void SetDefaults();
};
