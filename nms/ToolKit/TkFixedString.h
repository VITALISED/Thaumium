#pragma once

template <unsigned int size, typename T>
class cTkFixedString
{
public: 
	cTkFixedString()
	{ };

	cTkFixedString(const char* buff)
	{
		strcpy_s(macBuffer, size, buff);
	}

	T macBuffer[size];
};