#include "TkResourceManager.h"

#define HashShitA 0x100000001B3i64
#define HashShitB 0xCBF29CE484222325ui64

cTkSmartResHandle* cTkResourceManager::AddResource(cTkSmartResHandle* result, int liType, const char* lsName, unsigned int lxFlags, bool lbUserCall, cTkResourceDescriptor* lpResourceDescriptor)
{
	this->mMutex.lock();

	if (!strlen(lsName))
		spdlog::error("lsName is null");

	cTkResource* ResourceA = this->FindResourceA(liType, (char*)lsName, lpResourceDescriptor, true, false);

}

cTkResource* cTkResourceManager::FindResourceA(int liType, char* lsName, const cTkResourceDescriptor* lpResourceDescriptor, bool lbIgnoreDefaultFeedback, bool lbIgnoreKilled)
{
	int key = liType;
	cTkResource* DefaultResource;

	if (!*lsName)
		return NULL;

	char message[256];
	strcpy_s(message, lsName);

	SpookyHash state;

	uint64_t hash1 = HASHBASE;
	uint64_t hash2[2] = {};

	hash2[0] = HASHBASE;
	if (strlen(message))
	{
		SpookyHash::Hash128(message, sizeof(message), &hash1, &hash2[0]);
	}

	cTkLinearHashTable<unsigned __int64, TkStrongType<int, TkStrongTypeIDs::TkResHandleID> > lookup = this->mLookup[key];

	unsigned __int64 cursedHashExpression = HashShitA * hash2[0] ^ HashShitA * hash2[0] ^
		HashShitA * hash2[0] ^ HashShitA * hash2[0] ^
		HashShitA * hash2[0] ^ HashShitA * hash2[0] ^
		HashShitA * hash2[0] ^ HashShitA * (unsigned char)hash1 ^ HashShitB;

	if (lookup.miSize <= 0 || lookup.mapBucketTable[cursedHashExpression & lookup.miTableSize - 1] == 0)
	{
		cTkLinearHashTable<unsigned __int64, TkStrongType<int, TkStrongTypeIDs::TkResHandleID> >::cTkListNode* node =
			lookup.mapBucketTable[cursedHashExpression & lookup.miTableSize - 1];

		while (node->mHash != cursedHashExpression || node->mValue.first != hash1)
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