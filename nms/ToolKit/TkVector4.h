#pragma once
#include <xmmintrin.h>

class cTkVector4
{
public:
	cTkVector4()
	{ }

	cTkVector4(float x, float y, float z, float w)
	{
		this->mfX = x;
		this->mfY = y;
		this->mfZ = z;
		this->mfW = w;
	}

	float mfX;
	float mfY;
	float mfW;
	float mfZ;
};