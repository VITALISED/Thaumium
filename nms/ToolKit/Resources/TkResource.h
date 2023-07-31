#pragma once

#include <set>

#include "TkSmartResHandle.h"
#include "TkResourceDescriptor.h"
#include "../Utilities/TkString.h"
#include "../Utilities/TkStrongType.h"
#include "../Utilities/TkStrongTypeIDs.h"
#include "../Utilities/Memory/TkSTLAllocatorShim.h"

class cTkResource
{
public:
	int miType;
	cTkFixedString<256, char> msName;
	int mxFlags;
	int mAsyncOpHandle;
	TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mHandle;
	std::atomic<unsigned int> muRefCount;
	std::atomic<bool> mbLoaded;
	bool mbNoQuery;
	bool mbError;
	bool mbReplaceWithDefault;
	bool mbLazyDelete;
	bool mbPersistent;
	std::vector<TkStrongType<int, TkStrongTypeIDs::TkResHandleID>, TkSTLAllocatorShim<TkStrongType<int, TkStrongTypeIDs::TkResHandleID> > > mSubResources;
	std::set<cTkSmartResHandle> mOwnedResources;
	cTkResourceDescriptor mDescriptor;
	unsigned __int16 muHotRequestNumber;
};

constexpr int alignment = alignof(cTkResource);