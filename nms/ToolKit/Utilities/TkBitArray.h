#pragma once

template<typename T, unsigned int size>
class cTkBitArray
{
	cTkBitArrayStorage<T, size> mStorage;
};

template <typename T, unsigned int size>
class cTkBitArrayStorage
{
	unsigned __int64 mArray[size / 64];
};