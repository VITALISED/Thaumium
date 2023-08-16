#pragma once

#include <atomic>

template <typename T>
class cTkLockFreeQueue
{
	std::atomic<int> miQueueMarkers;
	T *mpEntries;
	std::atomic<int> *maEntryValid;
	int miMaxNumEntries;
};

template <typename T, unsigned int entries>
class cTkInplaceLockFreeQueue : public cTkLockFreeQueue<T>
{
	T maEntryBuffer[entries + 1];
	std::atomic<int> maEntryValidBuffer[entries + 1];
};
