#pragma once
#include "TkBitArrayStorage.h"

template<typename T, unsigned int size>
class cTkBitArray
{
	cTkBitArrayStorage<T, size> mStorage;
};
