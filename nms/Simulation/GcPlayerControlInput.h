#pragma once

#include "../nms/ToolKit/Metadata/TkClassPointer.h"
#include "../nms/ToolKit/Utilities/TkArray.h"

class cGcPlayerControlInput
{
public:
	bool mbInterceptAllInputs;
	cTkDynamicArray</*cGcInputActions*/char[0x4]> maInterceptInputWhitelist;
	cTkDynamicArray</*cGcInputActions*/char[0x4]> maInterceptInputBlackList;
	cTkDynamicArray<cTkClassPointer> maInputs;
	void SetDefaults();
};
