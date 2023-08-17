#pragma once

#include "../../core/globals/hash.h"
#include "../utilities/TkLinearHashTable.h"
#include "../utilities/TkStrongType.h"
#include "../utilities/allocators/TkSTLAllocator.h"
#include "../utilities/containers/TkVector.h"
#include "TkResource.h"
#include "TkResourceDescriptor.h"
#include "TkResourceRegistryEntry.h"

class cTkResourceManagerBase
{
public:
	virtual ~cTkResourceManagerBase() = 0;
};

class cTkResourceManager : public cTkResourceManagerBase
{
private:
	typedef cTkSmartResHandle *(*_AddResource)(cTkSmartResHandle *result, int liType, const char *lsName, unsigned int lxFlags, bool lbUserCall, cTkResourceDescriptor *lpResourceDescriptor);
	typedef cTkResource *(*_GetDefaultResource)(unsigned int liType, unsigned int liFlags);
	typedef bool (*_IsResourceDeadInternal)(cTkResource *lpResource);

public:
	class cTkKillResource
	{
		cTkResource *mpResource;
		unsigned int muKillFrame;
	};

	robin_hood::detail::Table<false, 80, int, cTkLinearHashTable<unsigned __int64, TkStrongType<int, TkStrongTypeIDs::TkResHandleID>>, robin_hood::hash<int, void>, std::equal_to<int>> mLookup;
	cTkVector<cTkResource *> mResources;
	cTkVector<TkStrongType<int, TkStrongTypeIDs::TkResHandleID>> mFreeResourceHandles;
	std::unordered_map<cTkResource *, cTkResourceManager::cTkKillResource, std::hash<cTkResource *>, std::equal_to<cTkResource *>, TkSTLAllocatorShim<std::pair<cTkResource *const, cTkResourceManager::cTkKillResource>>> mKillMap;
	robin_hood::detail::Table<false, 80, int, cTkResourceRegistryEntry, robin_hood::hash<int, void>, std::equal_to<int>> mRegistry;
	robin_hood::detail::Table<true, 80, int, void, robin_hood::hash<int, void>, std::equal_to<int>> mResourcesLoading;
	cTkVector<std::pair<cTkResource *, cTkResourceDescriptor const *>> mGeometryWaitingForStream;
	int miDebugResourceType;
	bool mbForceReload;
	bool mbIgnoreTimestamp;
	bool mbAllowLazyDeletions;
	std::recursive_mutex mMutex;
	__int64 miLastHotReloadTime;
	unsigned __int16 muHotReloadRequestNumber;

	// Considering we only ever access TkResourceManager from EgModules we probably won't need to ever implement this
	~cTkResourceManager(){};

	cTkSmartResHandle *AddResource(cTkSmartResHandle *result, int liType, const char *lsName, unsigned int lxFlags, bool lbUserCall, cTkResourceDescriptor *lpResourceDescriptor);
	cTkResource *FindResourceA(int liType, char *lsName, const cTkResourceDescriptor *lpResourceDescriptor, bool lbIgnoreDefaultFallback, bool lbIgnoreKilled);
	cTkResource *GetDefaultResource(unsigned int liType, unsigned int liFlags);
	bool IsResourceDeadInternal(cTkResource *lpResource);
};