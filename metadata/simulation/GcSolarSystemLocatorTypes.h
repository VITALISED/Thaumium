#pragma once

enum eLocatorType
{
	ELocatorType_Generic1 = 0x0,
	ELocatorType_Generic2 = 0x1,
	ELocatorType_Generic3 = 0x2,
	ELocatorType_Generic4 = 0x3,
	ELocatorType_NumTypes = 0x4,
};

class cGcSolarSystemLocatorTypes
{
	eLocatorType meLocatorType;
};