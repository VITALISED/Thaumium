#pragma once

#include <utility>

#include "../../pch.h"

template <typename T, typename U>
class cTkLinearHashTable
{
public:
	class cTkListNode
	{
	public:
		std::pair<T, U> mValue;
		unsigned __int64 mHash;
		cTkLinearHashTable<T, U>::cTkListNode *mpNext;
		cTkLinearHashTable<T, U>::cTkListNode *mpPrev;
		bool mbUsed;
	};

	cTkLinearHashTable<T, U>::cTkListNode *mpNodes;
	cTkLinearHashTable<T, U>::cTkListNode **mapBucketTable;
	cTkLinearHashTable<T, U>::cTkListNode *mpFirstFreeNode;

	int miCapacity;
	int miSize;
	int miTableSize;

	size_t INLINE size()
	{
		return miSize - 1;
	}

	size_t INLINE tablesize()
	{
		return miTableSize - 1;
	}
};