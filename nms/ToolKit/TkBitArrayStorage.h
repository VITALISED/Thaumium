#pragma once

template <typename T, unsigned int size>
class cTkBitArrayStorage
{
	unsigned __int64 mArray[size / 64];
};