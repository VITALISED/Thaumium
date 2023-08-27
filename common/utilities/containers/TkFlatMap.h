#pragma once

#include "TkVector.h"
#include <utility>

// TODO: add sorting type
template <typename Key, typename T>
class cTkFlatMap
{
public:
    cTkVector<std::pair<Key, T>> mVector;
    bool mbDirty;
};