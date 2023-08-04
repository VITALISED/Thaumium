#pragma once

#include <set>

#include "TkSmartResHandle.h"
#include "TkResourceDescriptor.h"
#include "../utilities/TkString.h"
#include "../utilities/TkStrongType.h"
#include "../utilities/allocators/TkSTLAllocator.h"

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

	virtual ~cTkResource();
	virtual bool IsLoaded();
	virtual void SetDescriptor(const cTkResourceDescriptor* lpDescriptor);
	virtual int GetDataSize();
	virtual bool OnResourceLoaded();
	virtual unsigned int GetDeletionFrameDelay();
	virtual cTkResource* Clone();
	virtual void CloneInternal(const cTkResource* lpResource);
	virtual void Release();
	virtual bool Equals(const char* lpacName, const cTkResourceDescriptor* lpDescriptor, int liType);
};
