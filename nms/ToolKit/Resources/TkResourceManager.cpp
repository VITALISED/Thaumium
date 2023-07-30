#include "TkResourceManager.h"

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

	if (!*lsName)
		return NULL;

	char message[256];
	strcpy_s(message, lsName);

	uint64_t hash1 = HASHBASE;
	uint64_t hash2 = HASHBASE;
	uint64_t hashRes;
	if (strlen(message))
	{
		SpookyHash::Hash128(message, sizeof(message), &hash1, &hash2);
		hashRes = hash1;
	}
	else
	{
		hashRes = HASHFAILED;
	}

}