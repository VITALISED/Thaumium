#include "TkResourceManager.h"

cTkSmartResHandle *cTkResourceManager::AddResource(cTkSmartResHandle *result, int liType, const char *lsName, unsigned int lxFlags, bool lbUserCall, cTkResourceDescriptor *lpResourceDescriptor)
{
	// this->mMutex.lock();

	// if (!strlen(lsName))
	//	spdlog::error("lsName is null");

	// cTkResource* ResourceA = this->FindResourceA(liType, (char*)lsName, lpResourceDescriptor, true, false);

	// if (ResourceA)
	//{
	//	if ((lxFlags & 0x1000000) == 0)
	//	{

	//	}

	//	//if (lpResourceDescriptor->mSeed.mbValid == ResourceA->mDescriptor.mSeed.mbValid)
	//	//{
	//	//	// 100% an inline call of something like IsValid()
	//	//	if (lpResourceDescriptor->mSecondarySeed.mbValid == ResourceA->mDescriptor.mSecondarySeed.mbValid
	//	//		&& (!lpResourceDescriptor->mSeed.mbValid || !ResourceA->mDescriptor.mSeed.mbValid ||
	//	//			lpResourceDescriptor->mSeed.mbValid)
	//	//}
	//}
	MAKE_FUNCTION_TYPE(__redirType, cTkSmartResHandle *, cTkResourceManager *, cTkSmartResHandle *, int, const char *, unsigned int, bool, cTkResourceDescriptor *);
	DECLARE_METHOD_REDIR(SIGSCAN(44 89 44 24 18 48 89 54 24 10 55 53 57 41 54 41),
						 __redirType, cTkSmartResHandle * cTkResourceManager::AddResource,
						 this, result, liType, lsName, lxFlags, lbUserCall, lpResourceDescriptor);
}

cTkResource *cTkResourceManager::FindResourceA(int liType, char *lsName, const cTkResourceDescriptor *lpResourceDescriptor, bool lbIgnoreDefaultFeedback, bool lbIgnoreKilled)
{
	int key = liType;
	cTkResource *DefaultResource;

	if (!*lsName)
		return NULL;

	char message[256];
	strcpy_s(message, lsName);

	unsigned __int64 hash;

	if (strlen(message))
	{
		unsigned __int64 hash1 = HASH_SEED;
		unsigned __int64 hash2 = HASH_SEED;

		SpookyHash::Hash128(message, sizeof(message), &hash1, &hash2);
		hash = hash1;
	}
	else
	{
		hash = UNK_HASH1;
	}

	this->mMutex.lock();

	cTkLinearHashTable<unsigned __int64, TkStrongType<int, TkStrongTypeIDs::TkResHandleID>>::cTkListNode *index =
		this->mLookup[key].mapBucketTable[SpookyHash::Rot64(hash, 435) & this->mLookup[key].tablesize()];

	if (this->mLookup[key].miSize <= 0 || index == 0)
	{
		DefaultResource = NULL;
		this->mMutex.unlock();
		return DefaultResource;
	}

	while (index->mHash != SpookyHash::Rot64(hash, 435) || index->mValue.first != hash)
	{
		index = index->mpNext;
		if (!index)
		{
			DefaultResource = NULL;
			this->mMutex.unlock();
			return DefaultResource;
		}
	}

	for (;;)
	{
		if (!index->mValue.second.mValue || (index->mValue.second.mValue - 1) >= this->mResources.size())
		{
			DefaultResource = NULL;
		}
		else
		{
			DefaultResource = &this->mResources.front()[index->mValue.second.mValue - 1];
		}

		if (DefaultResource->mbReplaceWithDefault)
		{
			DefaultResource = this->GetDefaultResource(DefaultResource->miType, DefaultResource->mxFlags);
		}

		if (!DefaultResource || !DefaultResource->Equals(message, lpResourceDescriptor, key))
		{
			if (index->mpNext)
			{
				while (index->mpNext->mHash != index->mHash || index->mpNext->mValue.first != index->mValue.first)
				{
					index->mpNext = index->mpNext->mpNext;
					if (!index->mpNext)
					{
						break;
					}
				}
			}
			else
			{
				index->mpNext = NULL;
			}

			if (!index->mpNext)
			{
				DefaultResource = NULL;
				this->mMutex.unlock();
				return DefaultResource;
			}

			index = index->mpNext;
			continue;
		}
		break;
	}

	if (lbIgnoreDefaultFeedback || !DefaultResource->mbReplaceWithDefault)
	{
		if (!lbIgnoreKilled || this->IsResourceDeadInternal(DefaultResource))
		{
			this->mMutex.unlock();
			return DefaultResource;
		}

		// TODO: something goes here but it's complicated
	}

	DefaultResource = this->GetDefaultResource(key, DefaultResource->mxFlags);

	if (!DefaultResource)
	{
		spdlog::error("Need to replace resource with default, but there is no default");
	}

	this->mMutex.unlock();
	return DefaultResource;
}

cTkResource *cTkResourceManager::GetDefaultResource(unsigned int liType, unsigned int liFlags)
{
	MAKE_FUNCTION_TYPE(__redirType, cTkResource *, cTkResourceManager *, unsigned int, unsigned int);
	DECLARE_METHOD_REDIR(SIGSCAN(48 89 5C 24 20 44 89 44 24 18 89 54 24 10 55),
						 __redirType, cTkResource * cTkResourceManager::GetDefaultResource,
						 this, liType, liFlags);
}

bool cTkResourceManager::IsResourceDeadInternal(cTkResource *lpResource)
{
	MAKE_FUNCTION_TYPE(__redirType, bool, cTkResourceManager *, cTkResource *);
	DECLARE_METHOD_REDIR(SIGSCAN(4C 8B DC 49 89 53 10 55 49),
						 __redirType, bool cTkResourceManager::IsResourceDeadInternal,
						 this, lpResource);
}