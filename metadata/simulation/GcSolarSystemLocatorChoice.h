#pragma once

#include "../../common/utilities/TkString.h"
#include "GcSolarSystemLocatorTypes.h"

enum eChoice : __int32
{
	EChoice_LookupName = 0x0,
	EChoice_AnyOfType = 0x1,
	EChoice_SpecificIndex = 0x2,
	EChoice_InFrontOfPlayer = 0x3,
	EChoice_NumTypes = 0x4,
};

class cGcSolarSystemLocatorChoice
{
	eChoice meChoice;
	cTkFixedString<32, char> macName;
	cGcSolarSystemLocatorTypes mType;
	int miIndex;
};
