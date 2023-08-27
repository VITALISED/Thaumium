#pragma once

#include "../../../common/metadata/TkMetaData.h"
#include "../../../common/metadata/TkMetaDataXML.h"
#include "../../../common/utilities/containers/TkFlatMap.h"
#include "../../engine/EgModules.h"

class cGcApplication;

namespace Globals
{
    void SetEngineDefaults();
    void SetApplicationDefaults();
    void SetMetadataLookupDefaults();

    cGcApplication *GetGcApplication();

    static cGcApplication *gGcApplication;
    static cTkFlatMap<unsigned __int64, cTkMetaDataFunctionLookup> *mgpFunctionLookup;
    static cTkVector<cTkMetaDataXMLFunctionLookup> *mgpXMLWriteLookup;
    // we access cEgModules directly after initialising it, no need to define it here
}