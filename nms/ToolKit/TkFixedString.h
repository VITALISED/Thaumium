#pragma once

template <unsigned int size, typename T>
class cTkFixedString
{
public: 
	cTkFixedString()
	{ };

	cTkFixedString(const char* lpacBuffer)
	{
		this->Copy(lpacBuffer);
	}

	T macBuffer[size];

	void Copy(const char* lpacBuffer)
	{
		strcpy_s(macBuffer, size, lpacBuffer);
	}
};