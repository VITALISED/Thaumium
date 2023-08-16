#pragma once

#include "GcPlayerSpawnState.h"

class cGcPlayerRespawn
{
	cGcPlayerSpawnStateData mGeneratedPlayerSpawn;
	bool mbWasPlayerInShipWhenKilled;
	bool mbOverrideSpawnPlayerOnPlanet;
};
