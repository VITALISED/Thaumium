#include "TkResourceManager.h"

cTkSmartResHandle* cTkResourceManager::AddResource(cTkSmartResHandle* result, int liType, const char* lsName, unsigned int lxFlags, bool lbUserCall, cTkResourceDescriptor* lpResourceDescriptor)
{
	this->mMutex.lock();

	if (!strlen(lsName))
		spdlog::error("lsName is null");

	cTkResource* ResourceA = this->FindResourceA(liType, (char*)lsName, lpResourceDescriptor, true, false);

	if (ResourceA)
	{
		if ((lxFlags & 0x1000000) == 0)
		{

		}

		//if (lpResourceDescriptor->mSeed.mbValid == ResourceA->mDescriptor.mSeed.mbValid)
		//{
		//	// 100% an inline call of something like IsValid()
		//	if (lpResourceDescriptor->mSecondarySeed.mbValid == ResourceA->mDescriptor.mSecondarySeed.mbValid
		//		&& (!lpResourceDescriptor->mSeed.mbValid || !ResourceA->mDescriptor.mSeed.mbValid ||
		//			lpResourceDescriptor->mSeed.mbValid)
		//}
	}

}

cTkResource* cTkResourceManager::FindResourceA(int liType, char* lsName, const cTkResourceDescriptor* lpResourceDescriptor, bool lbIgnoreDefaultFeedback, bool lbIgnoreKilled)
{
	int key = liType;
	cTkResource* DefaultResource;

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
		hash = DEFAULT_HASH;
	}

	this->mMutex.lock();

	cTkLinearHashTable<unsigned __int64, TkStrongType<int, TkStrongTypeIDs::TkResHandleID> >::cTkListNode* index =
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
		else {
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
	}
}