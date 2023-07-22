#pragma once

template <unsigned int size, typename T>
class __declspec(align(4)) cTkFixedString
{
public: 
	cTkFixedString()
	{ };

	cTkFixedString(const char* lpacBuffer)
	{
		this->Copy(lpacBuffer);
	}

	void Copy(const char* lpacBuffer)
	{
		strcpy_s(macBuffer, size, lpacBuffer);
	}

	T macBuffer[size];
};
