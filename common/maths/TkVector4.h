#pragma once
#include <xmmintrin.h>

class cTkVector4
{
public:
	cTkVector4()
	{ }

	cTkVector4(float lfX, float lfY, float lfZ, float lfW)
	{
		this->mfX = lfX;
		this->mfY = lfY;
		this->mfZ = lfZ;
		this->mfW = lfW;
	}

	float mfX, mfY, mfZ, mfW;
};