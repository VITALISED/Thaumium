#pragma once

#include "../../pch.h"
#include "TkArray.h"

template <unsigned int size, typename T>
class ALIGN(4) cTkFixedString
{
public:
	cTkFixedString(){};

	cTkFixedString(const char *lpacBuffer)
	{
		this->Copy(lpacBuffer);
	}

	void Copy(const char *lpacBuffer)
	{
		strcpy_s(macBuffer, size, lpacBuffer);
	}

	T macBuffer[size];
};

class cTkDynamicString : cTkDynamicArray<char>
{
};
