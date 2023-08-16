#pragma once

#include <Heridium/metadata/source/metadata/simulation/solarsystem/gcasteroidgeneratorassignment.meta.h>

#include "../pch.h"
#include "../common/maths/TkVector3.h"

class ALIGN(8) cGcAsteroidGeneratorRing
{
	cGcAsteroidGeneratorAssignment mAssignment;
	float mfLowerRadius;
	float mfUpperRadius;
	float mfPushRadius;
	int miOffBalance;
	cTkVector3 mRotation;
	float mfUSpread;
	float mfPushAmount;
	bool mbFlipPush;
};