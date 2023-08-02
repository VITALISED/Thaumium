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

	unsigned __int64 hash1 = HASHBASE;
	unsigned __int64 hash2 = HASHBASE;

	if (strlen(message))
	{
		SpookyHash::Hash128(message, sizeof(message), &hash1, &hash2);
	}

	cTkLinearHashTable<unsigned __int64, TkStrongType<int, TkStrongTypeIDs::TkResHandleID> > lookup = this->mLookup[key];

	if (lookup.miSize <= 0 || lookup.mapBucketTable[SpookyHash::Rot64(hash2, 435) & lookup.tablesize()] == 0)
	{
		cTkLinearHashTable<unsigned __int64, TkStrongType<int, TkStrongTypeIDs::TkResHandleID> >::cTkListNode* node =
			lookup.mapBucketTable[SpookyHash::Rot64(hash2, 435) & lookup.size()];

		while (node->mHash != SpookyHash::Rot64(hash2, 435) || node->mValue.first != hash1)
		{
			node = node->mpNext;
			if (!node)
			{
				DefaultResource = NULL;
				this->mMutex.unlock();
				return DefaultResource;
			}
		}
	}
}