#pragma once

#include "TkVector.h"
#include <utility>

// TODO: add sorting type
template <unsigned __int64 lui64Hash, typename T>
class cTkFlatMap<unsigned __int64, cTkMetaDataFunctionLookup, cTkKeyPairCompareLess<unsigned __int64, cTkMetaDataFunctionLookup>, -1>
{
public:
    cTkVector<std::pair<lui64Hash, T>> mVector;
    bool mbDirty;
};