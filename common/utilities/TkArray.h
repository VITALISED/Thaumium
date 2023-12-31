#pragma once

template <typename T>
class cTkDynamicArray
{
public:
	union cTkDynamicArrayPointer
	{
		T* mpaArray;
		__int64 miOffset;
	};
	cTkDynamicArray<T>::cTkDynamicArrayPointer mArray;
	int miSize;
	bool mbAllocatedFromData;
	unsigned __int8 macMagicPad[3];
};

template <typename T, unsigned int size>
class cTkFixedArray
{
	T maArray[size];
};

template <typename T, unsigned int size>
class cTkBitArrayStorage
{
	unsigned __int64 mArray[size / 64];
};

template<typename T, unsigned int size>
class cTkBitArray
{
	cTkBitArrayStorage<T, size> mStorage;
};
