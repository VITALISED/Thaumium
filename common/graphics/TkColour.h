#pragma once
#include "../common/maths/TkVector4.h"

class cTkColour : public cTkVector4
{
public:
	cTkColour() : cTkVector4(){};

	cTkColour(float r, float g, float b, float a) : cTkVector4(r, g, b, a){};
};