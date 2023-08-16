#pragma once

#include "../common/metadata/TkClassPointer.h"
#include "../common/utilities/TkArray.h"

class cGcPlayerControlInput
{
public:
	bool mbInterceptAllInputs;
	cTkDynamicArray</*cGcInputActions*/ char[0x4]> maInterceptInputWhitelist;
	cTkDynamicArray</*cGcInputActions*/ char[0x4]> maInterceptInputBlackList;
	cTkDynamicArray<cTkClassPointer> maInputs;
	void SetDefaults();
};
