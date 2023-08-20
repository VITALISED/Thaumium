#pragma once

#include "../../../common/maths/TkMatrix34.h"
#include "../../../common/utilities/containers/TkVector.h"

#include <Heridium/heridium.h>

class cGcSolarSystemAsteroidFields
{
    class AsteroidGenerators
    {
        cTkVector<cGcAsteroidGeneratorRing> mRings;
        cTkVector<cGcAsteroidGeneratorSurround> mSurrounds;
        cTkVector<cGcAsteroidGeneratorSlab> mSlabs;
    };
}